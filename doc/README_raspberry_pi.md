# XTRABYTES Raspberry Pi Wallet

## Intro

XTRABYTES is a free open source peer-to-peer electronic cash system that is
completely decentralized, without the need for a central server or trusted
parties.  Users hold the crypto keys to their own money and transact directly
with each other, with the help of a P2P network to check for double-spending.
XTRABYTES has created something called Proof of Signature which ensure that 
100% of all blocks will be signed by the system when they occur. The blocks 
are signed by the network of Master Nodes after verifying the transactions in 
the block. There are a total of 650 million XBY and there will never be more.

## Setup

### How to compile the XTRABYTES wallet for Raspberry Pi

If you have just received your Pi and need help setting up an environment to run XTRABYTES on, follow the below 2 steps:

1. Download NOOBS distribution from https://www.raspberrypi.org/downloads/noobs/ and extract to your desktop.
2. Copy the files to your microsd card. Eject the microsd card and put it into your pi and power it up. When it comes up, choose "Raspbian with PIXEL" and click Install.
3. After following the instructions and booting up, go to Raspberry -> Accessories -> terminal. 

Now that your PI has been installed with an OS, or you already have an OS, 
load up the terminal and run the following commands:

```
pi@raspnode~$ sudo apt-get update; sudo apt-get upgrade -y; sudo apt-get install -y autoconf libevent-dev libtool libssl-dev libboost-all-dev libminiupnpc-dev git qt4-dev-tools libprotobuf-dev protobuf-compiler libqrencode-dev libdb++-dev

pi@raspnode~$ cd

pi@raspnode~$ git clone https://github.com/borzalom/XtraBYtes.git

pi@raspnode~$ sudo nano /etc/dphys-swapfile
```

Change line:
```
CONF_SWAPSIZE=100
```

to

```
CONF_SWAPSIZE=512
```

Then press: 
Ctrl-X
y
enter

```
pi@raspnode~$ sudo /etc/init.d/dphys-swapfile restart
```

Then go into your XTRABYTES source directory

```
pi@raspnode~$ cd ~/XtraBYtes/src

pi@raspnode~$ mkdir obj

pi@raspnode~$ chmod -R 777 ~/XtraBYtes

pi@raspnode~$ make -f makefile.unix
```

Now your node is built. Run it!

```
pi@raspnode~$  ./xtrabytesd &
```

It will ask you to do some things with your xtrabytes.conf. 

just copy and paste what the command says, changing the rpcuser and rpcpassword to anything you want. Start the node again:

```
pi@raspnode~$  ./xtrabytesd &
```

Then wait a few mins, and test that it's working:

```
pi@raspnode~$  ./xtrabytesd getinfo
```

## Info

XTRABYTES Core downloads and stores the entire history of XTRABYTES transactions;
depending on the speed of your computer and network connection, the synchronization
process can take anywhere from 15 minutes to a few hours or more.

Join Slack for more help and information. Please visit our bitcointalk ANN at https://bitcointalk.org/index.php?topic=1864397.0 and request an invitation. Send a DM to either: fishfishfish313, BRYAN_K, rule144, cefinnell01 or CCRevolution (in the forum) and we will manually add you to the Slack. Thank you!

## XTRABYTES social links:

**BITCOINTALK FORUM** - https://bitcointalk.org/index.php?topic=1864397.0 <br />
**FACEBOOK** - https://www.facebook.com/XTRABYTESOfficial/ <br />
**TWITTER** - https://twitter.com/xtrabytes <br />
**REDDIT** - https://www.reddit.com/r/xtrabytes <br />
**YOUTUBE** - https://www.youtube.com/c/XTRABYTESOFFICIAL <br />
**STEEM** - https://steemit.com/@xtrabytes <br />
**MEDIUM** - https://medium.com/@XTRABYTES <br />
**INSTAGRAM** - https://www.instagram.com/xtrabytes <br />
**VIMEO** - https://vimeo.com/xtrabytes <br />

***

Version: 1.01
