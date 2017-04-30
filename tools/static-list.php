<?php
/*
    RPC-based STaTiC list generator
    (c) 2017 Zoltan Szabo <info@borzalom.hu>

    Licensed under GPL
*/

$rpcUser = 'REPLACE!!!';
$rpcPass = 'REPLACE!!!';
$rpcHost = '127.0.0.1';
$rpcPort = 34001;

$abort = false;
$resume = "resume-data.tmp";

if( !isset($argv[1]) )
    die( "Usage: php {$argv[0]} <output filename>\n" );

function handleInt()
{
    global $abort;
    $abort = true;
}

pcntl_signal( SIGINT, 'handleInt' );

require_once( 'easybitcoin.php' );
$rpc = new Bitcoin( $rpcUser, $rpcPass, $rpcHost, $rpcPort );
$numBlocks = $rpc->getinfo()['blocks'];
if( $rpc->status !== 200 && $rpc->error !== '' )
    die( "Failed to connect. Check your coin's .conf file and your RPC parameters.\n" );

$i = $txTotal = 0;
if( file_exists($resume) )
{
    $staticlister = unserialize( file_get_contents($resume) );
    if( $staticlister['staticlister'] === true )
        if( $numBlocks > $staticlister['last'] )
        {
            $i = $staticlister['last'];
            $txTotal = $staticlister['txTotal'];
            $registrations = $staticlister['registrations'];
            echo "resuming from block $i - ";
        }
        else
        {
            $rpc = null;
            die( "no new blocks, list is up to date\n" );
        }
}

$next = $rpc->getblockhash( $i + 1 );
echo "$numBlocks blocks ... ";
while( ++$i <= $numBlocks && $abort === false )
{
    if( $i % 1000 == 0 )
        echo "$i (tx# $txTotal)   ";

    $block = $rpc->getblock( $next );
    foreach( $block['tx'] as $txid )
    {
        $txTotal++;
        $tx = $rpc->getrawtransaction( $txid, 1 );
        if ($tx['vout'][0]['scriptPubKey']['type']=="staticreg") {
             $registrations[$txid]=$tx['vout'][0]['scriptPubKey']['asm'];
        }

    }
    if( ($next = @$block['nextblockhash']) === null )
        $abort = true;

    pcntl_signal_dispatch();
}
$rpc = null;

// save progress
file_put_contents( $resume, serialize(['staticlister'=>true,
                                       'registrations'=>$registrations,
                                       'txTotal'=>$txTotal,
                                       'last'=>$i-1]) );

$i = 0;
while( (list($key, $value) = each($registrations)) ) {
    $values=explode(' ',$value);
    $data = hex2bin($values[1]);
    $datas = explode('|',$data);
    @$output .= 'STaTiC registration ID:'.$key."\n";
    @$output .= 'STaTiC name ID:'.$datas[0]."\n";
    @$output .= 'STaTiC human readable name:'.$datas[1]."\n";
    @$output .= 'STaTiC public key:'.$datas[2]."\n";
    @$output .= 'STaTiC spendable address:'.$datas[3]."\n\n\n";

}
    file_put_contents( $argv[1], $output );

echo ( $abort ? 'aborted -' : 'done!' ) . " $txTotal transactions through " . count( $registrations ) . " unique registrations counted\n";

