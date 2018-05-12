// Copyright (c) 2009-2012 The Bitcoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "txdb.h"
#include "main.h"
#include "uint256.h"
#include <iostream>

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        ( 0,      hashGenesisBlock )
        ( 1000, uint256("0x99a05c08441b3e09cc7490ed3cc8fa8f36e36b393de7d11b85c9f2388736b4f4"))
        ( 10000, uint256("0xb15cb418bb9c8768de2d5354188655ac659f9ad4315127a776e3242937f79dce"))
        ( 20000, uint256("0x8acebee1d415b9e9e7e39caac053df36f49a8c50dcc657750fa6d78d20dcc620"))
        ( 30000, uint256("0xc7552f9bcb7647f52a0ee933e4262c257c81ec3347e4c638f708cf937dbb1b18"))
        ( 40000, uint256("0xc69f2b4a9d743f3a579b76f77edb66583bde3604b1d7decbd824fa34a25526d9"))
        ( 50000, uint256("0x000000189e3e39f27e139939e2fd35e00bd348261a79866cf1c9cd98e5614588"))
        ( 60000, uint256("0x946c6e9135ff40bf58190e7bcf8d0b77e62744fe33f1f62936411a7c6b1d4f6b"))
        ( 70000, uint256("0xa95f55c912a4949af61b49d3dabf7736289487975ffeab66740b9362bd6a0dcb"))
        ( 80000, uint256("0x5b59e0cfb4e2a6e57700cedd7074beafc6e276dc71fc8e430ae2d0ea1b608761"))
        ( 90000, uint256("0x000000027013c46c6dd814d08cf2bae162c6da887fd5f107c2ff85cdcc63d260"))
        ( 100000, uint256("0xde272a70c6ffe7bab5dc1334c22d10203d05d76e051c9083ce447d7883ff6b69"))
        ( 110000, uint256("0x401de5999f6537d99dc9a23ed9dfa13a1dc54d2dab3bd94d9cd3a6ad7d50fbb3"))
        ( 120000, uint256("0x81fa27355fbb09a037b2edfe5b2695f4d3613dff6b328b75812f4b9aa758b2ba"))
        ( 130000, uint256("0x00000009181d9638c1632cbbafa9752f63ce492c28eeb298a9a028227c26183a"))
        ( 140000, uint256("0x0000001935dc6b6233c5671d74d870d09857bd3c4b8fd75e9ddb471ce468d9a5"))
        ( 145000, uint256("0xfd4c03f829f0df672ca9e0cbe140ef061339902c09c4a024a4e9d8a7979ea507"))
        ( 150000, uint256("0x0000000d9612866bcc11ed2e235d54f855f9bdfe8fcb04941f863b5bde77e30e"))
        ( 155000, uint256("0x000000e0af895947c33b8d921b4d493e3b593f2efc761e56289d0712270200d9"))
        ( 160000, uint256("0x0000004f6b567a222cd72fe866ff1c47d0b1d6c75fabe75c9eaf4dd2523a1767"))
        ( 165000, uint256("0x74d8fdfe2544236c96c9c00fb38990adc4783db3502cd53051d16b5bf39dc843"))
        ( 170000, uint256("0xacb53988e11338b4e4a18a84c40b60d075fedba54690c10f3d633b41e15707e4"))
        ( 175000, uint256("0xadb4e2ee98127d185ec6e8e9762fc030e33ff579b16d1e146eac57bc31a1f57a"))
        ( 180000, uint256("0x9d71ec6abbd54a9e1afb59a5830f489c3a677b647c50a8f812d9db3542ec21b5"))
        ( 185000, uint256("0x000000110d6a79f759b08665e756262aa5579192a248b3fa394fff1ac8344594"))
        ( 190000, uint256("0x000000300dfe30b61c19177be4cd7e1328885305a00feb3228bf6cf54794c272"))
        ( 195000, uint256("0x000000094915d73f4bc5599b91f4f75550fad18fe9fadf3106372fb36244a292"))
        ( 200000, uint256("0x00000185df4088e6d5d5c93d3f60becb698f1b59a03abf1975331894836c9c16"))
        ( 205000, uint256("0xfa05ba6b8b7e6e2073b30d95553a247bcbc03361baa09894aeb652145b610106"))
        ( 210000, uint256("0x000000620009a8d04932a763492247f380f25842c006316fff82a12b8a02c26b"))
        ( 215000, uint256("0x16c47164616f8d0638055014eb5ab5773c41ccebde513191f3a144ef6446505f"))
        ( 220000, uint256("0x0000007e5c4f365d6672fc11accdd5c5336f0f7f54b5a0debed0997b5ee865d0"))
        ( 225000, uint256("0xe88f1c7b1a356c573001d06003ecbbf7b55f9cdbe27da8745e6fc535acadc33f"))
        ( 230000, uint256("0x000000c2ec4d46dac80bcc0e0468ffca51519d39a9fce25ede1d294454860e58"))
        ( 235000, uint256("0x00000100897964f53363ad6ca9c9469f3f770f7354a8d1203d7c308ee3170240"))
        ( 240000, uint256("0x00000019c611b121b03c0be97db5da8786c538d1d9aae11d69e31b145558590e"))
        ( 245000, uint256("0x4b7be43bbee53dd899796fa8197fd8fad68d5654e6c1e341eb1888d5a5a3e2b1"))
        ( 250000, uint256("0xdd27255ecdeb570cd984e40c15ba09bb6b25f5d0e29667e646822096a6437c97"))
        ( 255000, uint256("0xd31745f858eab209843be97ee9da20ef8cf0d6597918fec39bee7a30768b485b"))
        ( 260000, uint256("0x42e375d5af9944d1e38bd0fedf04d49d1e6d75b4b5a175a8f4adec3bfbe0c179"))
        ( 265000, uint256("0x671b86258f19a95e19ae2b6132c87ba50ca4752b754a48676add5ce82887e244"))
        ( 270000, uint256("0x00000071dfaf8eee6aa0d580b3cfc060501abfd30e6f61348a9d79f038b4ced7"))
	( 275000, uint256("0x8798fe172046e0853f781c7f4c8057eb5bedcac602b41404f03bfd091b7aeff4"))
	( 280000, uint256("0x5db4e15bd4c7e5cd159881d8f5bd15827cc81d76a1bb59f3ff52f6a659e9fcfd"))
	( 285000, uint256("0x0000005a7fa0a7af5cbf330dcfca03e64e9c860552df43f28893f99c8ad4a50e"))
	( 290000, uint256("0xd1a753ee566a0aafd4c29d592e79b7d124a6c885b516bb53e0ff8bdaff9a1f5e"))
	( 295000, uint256("0x00000063ec606f077d0ba888d1a4d41ad603f0ead910c3b2e6b8b61a6f6a742a"))
	( 300000, uint256("0x30ac21a622c427f8c655a3cff1af47951a47e192d774b920d9e2f8c5ef477a71"))
	( 305000, uint256("0x000000fd4bf9ea5f145a98fee2255dfb218d36ae9acf1f5dff1948e04cfd6075"))
	( 310000, uint256("0x00000071a4c14a75506d7f2786ad261396aec984d3eaae7db21f13deb52210b0"))
	( 315000, uint256("0x0000007974a98993b63bc1f5fac3de3fdd9accf09b0f884edf0513125d171723"))
	( 320000, uint256("0x00000019970732bdaba774a9d69aa4f04e2c9f9fa24504bca8c02d98687997e5"))
	( 325000, uint256("0x0000004a1c7013e78fa442f83a2dfb67a79d952ae61e19eb93b4799e2981560a"))
	( 330000, uint256("0x000001a97aa6bad892dddd2016d35aafc98237beb5dc8832ee381389ace5030f"))
	( 335000, uint256("0x24cf15d9a135a6b04fd7861237edcddaaf085958a93f7f7f94ac54673184f34c"))
	( 340000, uint256("0xbb9ac41e73a0bddc826c47344f7114042f9cccbc069803801e6e3b098808ec15"))
	( 345000, uint256("0x9c69cc868d65bc2c0a29fc68590a685fe9147f869534f103536d7b671fc03fb0"))
	( 350000, uint256("0x0000000f28f47a6fb0e4a219cd67789ff65f6a46b3eea93db4372be9c70122d8"))
	( 355000, uint256("0x4e5330597de78029db99ce3f5a1dbf50949e950e52217e5774020a62a2ca42ea"))
	( 360000, uint256("0x231626a4c6006033f0725aaa4b48d49d8f9b8ac7702175b9cc65deae8eb85a94"))
	( 370000, uint256("0xfacd2565e35b51d9c54d0cf886ac6d50f3f7a73303d4d1338303f5a2ea487e27"))
	( 380000, uint256("0x149f5db7364ec8c461b6b70c6b72cdc4f4b8df37327ccad529a445567c5ea944"))
	( 400000, uint256("0x30d0dfc9dcce01897208831b6f84443059222a1b853799c19069d943fe4141b5"))
	( 425000, uint256("0xfa57423c0d857985ba4fad7e956d1563659a2010181899c5ee6a9480665a8837"))
	( 450000, uint256("0xa26bda44979e2e8dfa192709e1e24614fcc7f0f0dae436aa8da2ed30db6620ec"))		
	( 454474, uint256("0xcc27e580c1f762ccf3f61edf11868e7f1dc207e8b89536022e79ecde131e46ba"))

    ;

    // TestNet has no checkpoints
    static MapCheckpoints mapCheckpointsTestnet =
        boost::assign::map_list_of
        ( 0, hashGenesisBlockTestNet )
        ;

    bool CheckHardened(int nHeight, const uint256& hash)
    {
        MapCheckpoints& checkpoints = (fTestNet ? mapCheckpointsTestnet : mapCheckpoints);

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        // if (hash != i->second) {
        //   std::cout << hash.ToString();
        //   assert(0);
        // }
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        MapCheckpoints& checkpoints = (fTestNet ? mapCheckpointsTestnet : mapCheckpoints);

        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        MapCheckpoints& checkpoints = (fTestNet ? mapCheckpointsTestnet : mapCheckpoints);

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }

    // ppcoin: synchronized checkpoint (centrally broadcasted)
    uint256 hashSyncCheckpoint = 0;
    uint256 hashPendingCheckpoint = 0;
    CSyncCheckpoint checkpointMessage;
    CSyncCheckpoint checkpointMessagePending;
    uint256 hashInvalidCheckpoint = 0;
    CCriticalSection cs_hashSyncCheckpoint;

    // ppcoin: get last synchronized checkpoint
    CBlockIndex* GetLastSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        if (!mapBlockIndex.count(hashSyncCheckpoint))
            error("GetSyncCheckpoint: block index missing for current sync-checkpoint %s", hashSyncCheckpoint.ToString().c_str());
        else
            return mapBlockIndex[hashSyncCheckpoint];
        return NULL;
    }

    // ppcoin: only descendant of current sync-checkpoint is allowed
    bool ValidateSyncCheckpoint(uint256 hashCheckpoint)
    {
        if (!mapBlockIndex.count(hashSyncCheckpoint))
            return error("ValidateSyncCheckpoint: block index missing for current sync-checkpoint %s", hashSyncCheckpoint.ToString().c_str());
        if (!mapBlockIndex.count(hashCheckpoint))
            return error("ValidateSyncCheckpoint: block index missing for received sync-checkpoint %s", hashCheckpoint.ToString().c_str());

        CBlockIndex* pindexSyncCheckpoint = mapBlockIndex[hashSyncCheckpoint];
        CBlockIndex* pindexCheckpointRecv = mapBlockIndex[hashCheckpoint];

        if (pindexCheckpointRecv->nHeight <= pindexSyncCheckpoint->nHeight)
        {
            // Received an older checkpoint, trace back from current checkpoint
            // to the same height of the received checkpoint to verify
            // that current checkpoint should be a descendant block
            CBlockIndex* pindex = pindexSyncCheckpoint;
            while (pindex->nHeight > pindexCheckpointRecv->nHeight)
                if (!(pindex = pindex->pprev))
                    return error("ValidateSyncCheckpoint: pprev null - block index structure failure");
            if (pindex->GetBlockHash() != hashCheckpoint)
            {
                hashInvalidCheckpoint = hashCheckpoint;
                return error("ValidateSyncCheckpoint: new sync-checkpoint %s is conflicting with current sync-checkpoint %s", hashCheckpoint.ToString().c_str(), hashSyncCheckpoint.ToString().c_str());
            }
            return false; // ignore older checkpoint
        }

        // Received checkpoint should be a descendant block of the current
        // checkpoint. Trace back to the same height of current checkpoint
        // to verify.
        CBlockIndex* pindex = pindexCheckpointRecv;
        while (pindex->nHeight > pindexSyncCheckpoint->nHeight)
            if (!(pindex = pindex->pprev))
                return error("ValidateSyncCheckpoint: pprev2 null - block index structure failure");
        if (pindex->GetBlockHash() != hashSyncCheckpoint)
        {
            hashInvalidCheckpoint = hashCheckpoint;
            return error("ValidateSyncCheckpoint: new sync-checkpoint %s is not a descendant of current sync-checkpoint %s", hashCheckpoint.ToString().c_str(), hashSyncCheckpoint.ToString().c_str());
        }
        return true;
    }

    bool WriteSyncCheckpoint(const uint256& hashCheckpoint)
    {
        CTxDB txdb;
        txdb.TxnBegin();
        if (!txdb.WriteSyncCheckpoint(hashCheckpoint))
        {
            txdb.TxnAbort();
            return error("WriteSyncCheckpoint(): failed to write to db sync checkpoint %s", hashCheckpoint.ToString().c_str());
        }
        if (!txdb.TxnCommit())
            return error("WriteSyncCheckpoint(): failed to commit to db sync checkpoint %s", hashCheckpoint.ToString().c_str());

        Checkpoints::hashSyncCheckpoint = hashCheckpoint;
        return true;
    }

    bool AcceptPendingSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        if (hashPendingCheckpoint != 0 && mapBlockIndex.count(hashPendingCheckpoint))
        {
            if (!ValidateSyncCheckpoint(hashPendingCheckpoint))
            {
                hashPendingCheckpoint = 0;
                checkpointMessagePending.SetNull();
                return false;
            }

            CTxDB txdb;
            CBlockIndex* pindexCheckpoint = mapBlockIndex[hashPendingCheckpoint];
            if (!pindexCheckpoint->IsInMainChain())
            {
                CBlock block;
                if (!block.ReadFromDisk(pindexCheckpoint))
                    return error("AcceptPendingSyncCheckpoint: ReadFromDisk failed for sync checkpoint %s", hashPendingCheckpoint.ToString().c_str());
                if (!block.SetBestChain(txdb, pindexCheckpoint))
                {
                    hashInvalidCheckpoint = hashPendingCheckpoint;
                    return error("AcceptPendingSyncCheckpoint: SetBestChain failed for sync checkpoint %s", hashPendingCheckpoint.ToString().c_str());
                }
            }

            if (!WriteSyncCheckpoint(hashPendingCheckpoint))
                return error("AcceptPendingSyncCheckpoint(): failed to write sync checkpoint %s", hashPendingCheckpoint.ToString().c_str());
            hashPendingCheckpoint = 0;
            checkpointMessage = checkpointMessagePending;
            checkpointMessagePending.SetNull();
            printf("AcceptPendingSyncCheckpoint : sync-checkpoint at %s\n", hashSyncCheckpoint.ToString().c_str());
            // relay the checkpoint
            if (!checkpointMessage.IsNull())
            {
                BOOST_FOREACH(CNode* pnode, vNodes)
                    checkpointMessage.RelayTo(pnode);
            }
            return true;
        }
        return false;
    }

    // Automatically select a suitable sync-checkpoint 
    uint256 AutoSelectSyncCheckpoint()
    {
        const CBlockIndex *pindex = pindexBest;
        // Search backward for a block within max span and maturity window
        while (pindex->pprev && (pindex->GetBlockTime() + CHECKPOINT_MAX_SPAN > pindexBest->GetBlockTime() || pindex->nHeight + 8 > pindexBest->nHeight))
            pindex = pindex->pprev;
        return pindex->GetBlockHash();
    }

    // Check against synchronized checkpoint
    bool CheckSync(const uint256& hashBlock, const CBlockIndex* pindexPrev)
    {
        if (fTestNet) return true; // Testnet has no checkpoints
        int nHeight = pindexPrev->nHeight + 1;

        LOCK(cs_hashSyncCheckpoint);
        // sync-checkpoint should always be accepted block
        assert(mapBlockIndex.count(hashSyncCheckpoint));
        const CBlockIndex* pindexSync = mapBlockIndex[hashSyncCheckpoint];

        if (nHeight > pindexSync->nHeight)
        {
            // trace back to same height as sync-checkpoint
            const CBlockIndex* pindex = pindexPrev;
            while (pindex->nHeight > pindexSync->nHeight)
                if (!(pindex = pindex->pprev))
                    return error("CheckSync: pprev null - block index structure failure");
            if (pindex->nHeight < pindexSync->nHeight || pindex->GetBlockHash() != hashSyncCheckpoint)
                return false; // only descendant of sync-checkpoint can pass check
        }
        if (nHeight == pindexSync->nHeight && hashBlock != hashSyncCheckpoint)
            return false; // same height with sync-checkpoint
        if (nHeight < pindexSync->nHeight && !mapBlockIndex.count(hashBlock))
            return false; // lower height than sync-checkpoint
        return true;
    }

    bool WantedByPendingSyncCheckpoint(uint256 hashBlock)
    {
        LOCK(cs_hashSyncCheckpoint);
        if (hashPendingCheckpoint == 0)
            return false;
        if (hashBlock == hashPendingCheckpoint)
            return true;
        if (mapOrphanBlocks.count(hashPendingCheckpoint) 
            && hashBlock == WantedByOrphan(mapOrphanBlocks[hashPendingCheckpoint]))
            return true;
        return false;
    }

    // ppcoin: reset synchronized checkpoint to last hardened checkpoint
    bool ResetSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        const uint256& hash = mapCheckpoints.rbegin()->second;
        if (mapBlockIndex.count(hash) && !mapBlockIndex[hash]->IsInMainChain())
        {
            // checkpoint block accepted but not yet in main chain
            printf("ResetSyncCheckpoint: SetBestChain to hardened checkpoint %s\n", hash.ToString().c_str());
            CTxDB txdb;
            CBlock block;
            if (!block.ReadFromDisk(mapBlockIndex[hash]))
                return error("ResetSyncCheckpoint: ReadFromDisk failed for hardened checkpoint %s", hash.ToString().c_str());
            if (!block.SetBestChain(txdb, mapBlockIndex[hash]))
            {
                return error("ResetSyncCheckpoint: SetBestChain failed for hardened checkpoint %s", hash.ToString().c_str());
            }
        }
        else if(!mapBlockIndex.count(hash))
        {
            // checkpoint block not yet accepted
            hashPendingCheckpoint = hash;
            checkpointMessagePending.SetNull();
            printf("ResetSyncCheckpoint: pending for sync-checkpoint %s\n", hashPendingCheckpoint.ToString().c_str());
        }

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            if (mapBlockIndex.count(hash) && mapBlockIndex[hash]->IsInMainChain())
            {
                if (!WriteSyncCheckpoint(hash))
                    return error("ResetSyncCheckpoint: failed to write sync checkpoint %s", hash.ToString().c_str());
                printf("ResetSyncCheckpoint: sync-checkpoint reset to %s\n", hashSyncCheckpoint.ToString().c_str());
                return true;
            }
        }

        return false;
    }

    void AskForPendingSyncCheckpoint(CNode* pfrom)
    {
        LOCK(cs_hashSyncCheckpoint);
        if (pfrom && hashPendingCheckpoint != 0 && (!mapBlockIndex.count(hashPendingCheckpoint)) && (!mapOrphanBlocks.count(hashPendingCheckpoint)))
            pfrom->AskFor(CInv(MSG_BLOCK, hashPendingCheckpoint));
    }

    bool SetCheckpointPrivKey(std::string strPrivKey)
    {
        // Test signing a sync-checkpoint with genesis block
        CSyncCheckpoint checkpoint;
        checkpoint.hashCheckpoint = !fTestNet ? hashGenesisBlock : hashGenesisBlockTestNet;
        CDataStream sMsg(SER_NETWORK, PROTOCOL_VERSION);
        sMsg << (CUnsignedSyncCheckpoint)checkpoint;
        checkpoint.vchMsg = std::vector<unsigned char>(sMsg.begin(), sMsg.end());

        std::vector<unsigned char> vchPrivKey = ParseHex(strPrivKey);
        CKey key;
        key.SetPrivKey(CPrivKey(vchPrivKey.begin(), vchPrivKey.end())); // if key is not correct openssl may crash
        if (!key.Sign(Hash(checkpoint.vchMsg.begin(), checkpoint.vchMsg.end()), checkpoint.vchSig))
            return false;

        // Test signing successful, proceed
        CSyncCheckpoint::strMasterPrivKey = strPrivKey;
        return true;
    }

    bool SendSyncCheckpoint(uint256 hashCheckpoint)
    {
        CSyncCheckpoint checkpoint;
        checkpoint.hashCheckpoint = hashCheckpoint;
        CDataStream sMsg(SER_NETWORK, PROTOCOL_VERSION);
        sMsg << (CUnsignedSyncCheckpoint)checkpoint;
        checkpoint.vchMsg = std::vector<unsigned char>(sMsg.begin(), sMsg.end());

        if (CSyncCheckpoint::strMasterPrivKey.empty())
            return error("SendSyncCheckpoint: Checkpoint master key unavailable.");
        std::vector<unsigned char> vchPrivKey = ParseHex(CSyncCheckpoint::strMasterPrivKey);
        CKey key;
        key.SetPrivKey(CPrivKey(vchPrivKey.begin(), vchPrivKey.end())); // if key is not correct openssl may crash
        if (!key.Sign(Hash(checkpoint.vchMsg.begin(), checkpoint.vchMsg.end()), checkpoint.vchSig))
            return error("SendSyncCheckpoint: Unable to sign checkpoint, check private key?");

        if(!checkpoint.ProcessSyncCheckpoint(NULL))
        {
            printf("WARNING: SendSyncCheckpoint: Failed to process checkpoint.\n");
            return false;
        }

        // Relay checkpoint
        {
            LOCK(cs_vNodes);
            BOOST_FOREACH(CNode* pnode, vNodes)
                checkpoint.RelayTo(pnode);
        }
        return true;
    }

    // Is the sync-checkpoint outside maturity window?
    bool IsMatureSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        // sync-checkpoint should always be accepted block
        assert(mapBlockIndex.count(hashSyncCheckpoint));
        const CBlockIndex* pindexSync = mapBlockIndex[hashSyncCheckpoint];
        return (nBestHeight >= pindexSync->nHeight + nCoinbaseMaturity ||
                pindexSync->GetBlockTime() + nStakeMinAge < GetAdjustedTime());
    }
}

// ppcoin: sync-checkpoint master key
const std::string CSyncCheckpoint::strMasterPubKey = "049F2C10997604217E7238A4C5CF2843570ADA001D1A247B228A7C5583ACD0F762A3130D0C4331EB262E3D0EB516AE6F7B0B1ADA43275013F8552A83A7C621B1D9";

std::string CSyncCheckpoint::strMasterPrivKey = "";

// ppcoin: verify signature of sync-checkpoint message
bool CSyncCheckpoint::CheckSignature()
{
    CKey key;
    if (!key.SetPubKey(ParseHex(CSyncCheckpoint::strMasterPubKey)))
        return error("CSyncCheckpoint::CheckSignature() : SetPubKey failed");
    if (!key.Verify(Hash(vchMsg.begin(), vchMsg.end()), vchSig))
        return error("CSyncCheckpoint::CheckSignature() : verify signature failed");

    // Now unserialize the data
    CDataStream sMsg(vchMsg, SER_NETWORK, PROTOCOL_VERSION);
    sMsg >> *(CUnsignedSyncCheckpoint*)this;
    return true;
}

// ppcoin: process synchronized checkpoint
bool CSyncCheckpoint::ProcessSyncCheckpoint(CNode* pfrom)
{
    if (!CheckSignature())
        return false;

    LOCK(Checkpoints::cs_hashSyncCheckpoint);
    if (!mapBlockIndex.count(hashCheckpoint))
    {
        // We haven't received the checkpoint chain, keep the checkpoint as pending
        Checkpoints::hashPendingCheckpoint = hashCheckpoint;
        Checkpoints::checkpointMessagePending = *this;
        printf("ProcessSyncCheckpoint: pending for sync-checkpoint %s\n", hashCheckpoint.ToString().c_str());
        // Ask this guy to fill in what we're missing
        if (pfrom)
        {
            pfrom->PushGetBlocks(pindexBest, hashCheckpoint);
            // ask directly as well in case rejected earlier by duplicate
            // proof-of-stake because getblocks may not get it this time
            pfrom->AskFor(CInv(MSG_BLOCK, mapOrphanBlocks.count(hashCheckpoint)? WantedByOrphan(mapOrphanBlocks[hashCheckpoint]) : hashCheckpoint));
        }
        return false;
    }

    if (!Checkpoints::ValidateSyncCheckpoint(hashCheckpoint))
        return false;

    CTxDB txdb;
    CBlockIndex* pindexCheckpoint = mapBlockIndex[hashCheckpoint];
    if (!pindexCheckpoint->IsInMainChain())
    {
        // checkpoint chain received but not yet main chain
        CBlock block;
        if (!block.ReadFromDisk(pindexCheckpoint))
            return error("ProcessSyncCheckpoint: ReadFromDisk failed for sync checkpoint %s", hashCheckpoint.ToString().c_str());
        if (!block.SetBestChain(txdb, pindexCheckpoint))
        {
            Checkpoints::hashInvalidCheckpoint = hashCheckpoint;
            return error("ProcessSyncCheckpoint: SetBestChain failed for sync checkpoint %s", hashCheckpoint.ToString().c_str());
        }
    }

    if (!Checkpoints::WriteSyncCheckpoint(hashCheckpoint))
        return error("ProcessSyncCheckpoint(): failed to write sync checkpoint %s", hashCheckpoint.ToString().c_str());
    Checkpoints::checkpointMessage = *this;
    Checkpoints::hashPendingCheckpoint = 0;
    Checkpoints::checkpointMessagePending.SetNull();
    printf("ProcessSyncCheckpoint: sync-checkpoint at %s\n", hashCheckpoint.ToString().c_str());
    return true;
}
