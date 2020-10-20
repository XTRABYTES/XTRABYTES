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
	( 475000, uint256("0xdfdbc0047d7eeb1449217e60c13cf31ba10c2278130a7c799b631c8fc3a0fdc7"))
	( 500000, uint256("0xa8947c6363d2bfad5f1593b951e2726b9c53d12a4624807909871cc69803841e"))
	( 510000, uint256("0xf36129b3c2c3789b7b019337a87e5a1fcbbccc4796a38bc05081ad604a7b52d2"))
	( 520000, uint256("0x7abd950a20124f2cd487a44294fb8c87a2c82f2eb315bfa6f8ee1d0bba5d5804"))
	( 530000, uint256("0x8890a0b235019519c2fc5ae42291c8ddd3d0fb4af35a926d3323cdc552d1c4b7"))
	( 540000, uint256("0x4b9ba8211fd52289ccf557e3ec96c5cda46aabd71977104c4a032fb123ff653f"))
	( 550000, uint256("0x4f71895a5f5dc642822292b8bec337ad936f84606354b544e2bf717bff530140"))
	( 560000, uint256("0x24ff6de459dc8855989a3dce5a50e5a277a0e86b87c7de7af6ee63ce1938175f"))
	( 570000, uint256("0x18cc10c296d5d5efcef9d37c29579d564d4d3a80265ff66fa602bd17256de4e0"))
	( 580000, uint256("0xea336c44206fb41c8da4d318d7e9a688e038f82e582ebfa25ecb37048df8fe44"))
	( 590000, uint256("0xe6e6cde148e63518300868b278cedce48737b76c932767e7f742355c1f3433d9"))
	( 600000, uint256("0x1292d1e19de3d902a9ac0d5cb4cd7f536a0260e0028287ce7951a926740f5c8a"))
	( 625000, uint256("0x7603df9f1d6397ebe7ea57ddf2ccee39ba353653b431d04b5c6410f733822953"))
	( 630000, uint256("0x683e7480645b81c289ef83123ce16284875bd3372b5d30b2ca4fcb9e4878a9dc"))
	( 635000, uint256("0xc18d5973f53f8f4736c9b19b556575e05e24027077af09b929b56e8a9b03e11d"))
	( 640000, uint256("0xdca91b391f67196ee2d5ea3c44a40f4af665be0dc32cbd12d984136e0bc3c0e9"))
	( 645000, uint256("0xb62ac07cc8b461a8f2844682896decc6e71b8aeb4c525c2f8ec253c73c4aefe9"))
	( 650000, uint256("0x3e2b53ef57f0a55b193681df4e155981bc927ac25e75ea1343ea8c0e3a8ca643"))
	( 655000, uint256("0x8c3f5378f8a55c75aceacbe6d84b1765549d6ef5e6bf04c9adccf4bf88a08153"))
	( 660000, uint256("0x5cde4554bd5e8822171d626b46100fa83b28e4df555d18b6fee827f3a65623a1"))
	( 665000, uint256("0xafd655e86ed2c8db07b9e3620f397388726094a54ad889c5fc75e24d9e0416c9"))  
	( 670000, uint256("0xe32b621d82ed7a0a3a54c6747e049a0c897d711da55f44f0d5d53ed66bdccf51"))  
	( 675000, uint256("0x6086cd8b2112812614152a28a49d625e0094cfc0d698c44523d9157f58c87264")) 
	( 680000, uint256("0x7fb32f57bceb0282f28c42af28d26dbcba395a6e28f9db3b96e8e4c769af0687"))    
	( 685000, uint256("0x249fa7f8167bec6d579dca42288fb46d09ecc6fd3b9975eb1cd1c77f52c22b2d"))    
	( 690000, uint256("0x3fe5c1e8dcad071d7d8e7819d6c14c87f1d5fec1bb99d7e82a217be70f2becff")) 
	( 700000, uint256("0xad10502cd1ea84ce6821ee3fee19df367510329d713f73cf2bbb5a836f7fdb6f"))
	( 710000, uint256("0x64ac01fd1e58c8389144b10b92de3c010901570c478ac79babe34b2748f5b2cf"))
	( 720000, uint256("0x4e3374e80d75bfed71f2996e90255874787e08224ef22dde3bff3e11ff8ae4a8"))
	( 730000, uint256("0xfc6447207f1a757cad632c12ebcc928b0e1adc6d5fa82521c4539248f0a9da5e"))
	( 740000, uint256("0xde873540df5b1cde584b795898d1144313ed0e24cd702ee17731c9e364fc55da"))
	( 750000, uint256("0x611aea027f61693b68193f099a6d6a198af9c227d3e1c762972a9330dfd50c59"))
	( 760000, uint256("0x4fbc9b24f9040565a8fe5253cebb0c39c1c592c765cbee63537df348377033a3"))
	( 770000, uint256("0xf64e3e5ead075d2607b5b6c25f5a41e0b1f4ad3910b0f0af2c70ecb8858dc0e0"))
	( 780000, uint256("0x4bbe81688f9a0ee0a4f9d5c8b22a803403cc856093d77bcd0cc42143378dff25"))
	( 790000, uint256("0x26a52e1aeb2ad7256b26ea53e87bbd9132a19c80008674506d44c8dd10042575"))
	( 800000, uint256("0x65bee26066f3dae9452ce469da518ff3b30a00b36e2ff23cffaaf6e3011471cf"))
	( 810000, uint256("0xb6831a874fdd12d9bef8660e3304ed4f2963fd591fc0649022c33ef71b22c416"))
	( 820000, uint256("0x39d8665c6452caebea654efafab57d30d542a53b802b44f2656b069f25e21f66"))
	( 830000, uint256("0xcde88b2e337a2efdb8f6ee6de7fa88693fcd534e645cbec4839516a01897e3ae"))
	( 840000, uint256("0xe3d0253a9afee8b3ef02cf9d270fbd227521a3e83364170f3a477a1998805bd5"))
	( 850000, uint256("0x744366897140a81cc1e318fe7c57c7b5cdfbe8c3247514e9bf5dd1b90cc08c63"))
	( 860000, uint256("0x8882b74e52a0e98ebb50971fb4288b57dd933cd8352027efb8f3ae0e40a9ca2d"))
	( 870000, uint256("0x505bab607b0a57be0e9ade9ceb4d4aff8b51e15b150c5ff280ad15f3630dd8a6"))
	( 875000, uint256("0x1ea866fb79d6b21c3c06f920ba2bcf1cc3024a23985784ea57b44e70b612e0cf"))
	( 880000, uint256("0x644ddd98cd7b4b43513601ba944d4a4bd7724c7ba96657f2c96e9d2f1abb1e45"))
	( 885000, uint256("0x137d507059f774778a38b2dbcb53b33161571fb11c2a434e3844c1d68cd480e1"))
	( 890000, uint256("0xb9118251d62215e01b3910bdea317221f03253f944d4e768a5dcce2a49140845"))
	( 895000, uint256("0xb0b42786ce27d5284b8e09099e8c86ce084ec73cecbaf6941c9ea516f4063153"))
	( 900000, uint256("0xf5a103912d676f5437de96033df3617258296cbb4113c8f989095c4412bf6c4a"))
	( 905000, uint256("0x20fd06da384396d6d201ecebc769e42e1e0dece8feb057c04290af7140983b4b"))
	( 910000, uint256("0xdf01a96e026f9b35505c9995ba704548d29be4695003f5378666646fe130a6f2"))
	( 915000, uint256("0x4dc0086794b4a230ca438c2d7464e3afc1ba58de279176442481c872960dfe1c"))
	( 920000, uint256("0xdcd8804fecb63782d2264681d94e084164e686b19e089d27d46a4e1171f623ec"))
	( 925000, uint256("0xad182f18e8a9fa049fae43d421dfd45e150a421f48596b9349f511ef2391d549"))
	( 930000, uint256("0xa3f5519de4bc0291752f5b299895ccc5b7479c56ac59dac9859caab9c54861ce"))
	( 935000, uint256("0x0cec0b8a655e50cae5cb50133c69fdfc2e259dad7e130acbb14e61d190346567"))
	( 940000, uint256("0xafa64417494e8fd7c0962408ab371edebabbd393345d559cd3dbe2ad398248ad"))
	( 945000, uint256("0x89c780640d8caccba343717e159de1031064077981e56e57ada2e5a4acdbf19b"))
	( 950000, uint256("0x9e371bebddb2910bdc7fb3408904c0f7ad6c5dc0000435309bf5f9316c6c2b90"))
	( 955000, uint256("0xf3aa5309c8b41a293cd973904a21d2fbc0be34ef315c86ba0b931f80a232285b"))
	( 960000, uint256("0x9e33cb90fe9fb203870ba808179291e617e7958f86480da2045354432d0758fb"))
	( 965000, uint256("0x991f6935fc3084e1de88dd48cac0bc560e9147092be52140bdb73aea487f18b1"))
	( 970000, uint256("0xe1a38adc3d09a0e7063e90cbd432c558c0e1e45a171efd59471dbe2aec319ea3"))
	( 973000, uint256("0x2c6375a8f0aa989a1f646cb15521bf4385941a1801878da12f3beba6772888c0"))
	( 975000, uint256("0xb1419dacabf9f768fd93aad05be2916ebeee914894d664288f61a95f83cb62fa"))
	( 979000, uint256("0xa349b8b630985f9ad7f0498e4f62c9dcc9fbcb07c6817bc251504f64d81afa9f"))
	( 982000, uint256("0xd0d880fcc3a72774946e6d853c33bbb784f3ab7ffdb6aa9307bc38628aca0823"))
	( 984000, uint256("0x3d1e1b798760fedd55117c821804004d95d8034be434ac24abbe8c125e1f31ba"))
	( 988000, uint256("0xcda66ec65a82ee3a240c075ea0f32807ceedd79ce747a7f7e85945e5638d9082"))
	( 990000, uint256("0x359ac829349bfcfcf647f05bb112b63bdad489aa2d46f8e9e92bb2f5d7041645"))
	( 993000, uint256("0x381935f111b0dfa2d2d96c4cdb1fc37d3399abeba78b94c51e9fbc2c3ff50957"))
	( 995000, uint256("0x9c7a8f36002871dd82c880b2ed6ce1a90bd300d3c419c42570dc613469c101ec"))
	( 997000, uint256("0x6b3f8dbdd79dcb7bd27c635550315e769dab5492f4579aa8ec0180eb23c442ad"))
	( 999000, uint256("0x98f6b1629a37cb87a8d748b46a9f56e3ec6c736a61c1879aaa6452d261062a45"))
	( 1000000, uint256("0xf3bdba3002baa19df228c520a85b6ea22d0286d83e2cd20f04b5166719425827"))
	( 1003000, uint256("0xcff9423f5ad15effffc07a20570981ca9a450a205781fbdbfad37cae4d3b480c"))
	( 1008000, uint256("0xdafa8b7fb84efe0bd5eb88d4e1c736ae3e424a764c962be92e1b8605c1a6e985"))
	( 1010000, uint256("0xaff8bed1b22769ef71aada0a6d0a66ee90b88477f3e38784f9f60472d17d377f"))
	( 1013000, uint256("0x48ab01d25f6e0fcd37f4e06d425e5f7a14e6e8a3c7b377b5b295e1d7bea34f37"))
	( 1015000, uint256("0x35ae802af130eec3d7f481f0ad36e912cc6c035aee3b1ec7d77f06b5041b55c6"))
	( 1020000, uint256("0xffc2ee21669ddbb1a6712d78bf0baa22a214dbe8deec5c4040cb763866944e8f"))
	( 1025000, uint256("0x8bdf73663a710106b596f695240be83c66e9f3027b2e15f37a05695f3063fde7"))
	( 1030000, uint256("0x5aaf22e25a703a6fd59f0c50bddd0fe3a41b97cbb91eb32a1ba8b17fc6e5aefa"))
	( 1035000, uint256("0x642d4eb08f79cfe23d1d2fd97d8179a5b47812c1834d2198ad14b3615577a8fc"))
	( 1040000, uint256("0x997750c224dd30bf62eb6cfd06d4beb9c944dc123c92e55cd63debdee9bb58b4"))
	( 1045000, uint256("0xa36db7be048e6936527b0ce1f8953b82db5cfb795d06688477f534e2142e4ad6"))
	( 1050000, uint256("0x6623ae76d1d36fd46e8953b48c37ad4c6ce793b4629328cb9188ef1787640f26"))
	( 1055000, uint256("0x40ad89f36c68e2d3bf5c960433f8666d20331af3547b80461805e49a07253571"))
	( 1060000, uint256("0x9140e17fe87a0befd7c682538794fee500ae13051ca6d841d8788f63b93b2c37"))
	( 1065000, uint256("0xfdb9df427911a6a86177e7c10d6476c604e1e9f9ebf1596086b6381cfc31886c"))
	( 1073000, uint256("0x2d6dc37feffcd6b3c9a9a5705745fd4ddb6deb6df6b91349cbca33067d37e129"))
	( 1075000, uint256("0x3318aec4980dc9ab489117fa165330991e6a26b17b4250285f47bba3e42899f5"))
	( 1078000, uint256("0x57d2ecc4099c9ebbe3be7fd6773180506c9d8759e4da6876937aae8907d8bc5b"))
	( 1080000, uint256("0x45fbce191b5c33632f72b6a32a7fddf8bbd8244ebab717f4b5306bf1bfc5e522"))
	( 1081000, uint256("0x38841df8fb31610e4339aa7dc36881d3a395fb34889f747c6090074f722b95b3"))
	( 1082000, uint256("0x6b66bab128f1817026854f4b392e929aa76d93ba77d3c2da0ae21851a5ff4af0"))
	( 1085000, uint256("0x24ddde476d20ab06a9217c0ff61ca167cfd79d31b7833aaf4daa62b096435672"))
	( 1086000, uint256("0x173dc698e841a9a4f50b229b24a168dc9bad72b40932cb76e10d8be4c0e441bf"))
	( 1088771, uint256("0xc318e19a88294712aa430cb6b1c51e2bdd5d947233d367b8c0794413fe6a7eb3"))

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
