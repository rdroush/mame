// license:BSD-3-Clause
// copyright-holders:Robbbert

ROM_START( 1943h )
	ROM_REGION( 0x30000, "maincpu", 0 )
	ROM_LOAD( "bme01addontext.12d", 0x00000, 0x08000, CRC(36ab7c07) SHA1(baa9342c6c509b96e3c28a79284300707461a0fc) )
	ROM_LOAD( "bme02.13d", 0x10000, 0x10000, CRC(073fc57c) SHA1(6824fa387badd3c420f5c9e2b68159ac8a3aaec7) )
	ROM_LOAD( "bme03.14d", 0x20000, 0x10000, CRC(835822c2) SHA1(2c2fad13f062069efa7721abb9d807fb5a7625b4) )

	ROM_REGION( 0x10000, "audiocpu", 0 )
	ROM_LOAD( "bm05.4k", 0x00000, 0x8000, CRC(ee2bd2d7) SHA1(4d2d019a9f8452fbbb247e893280568a2e86073e) )

	ROM_REGION( 0x10000, "mcu", 0 )
	ROM_LOAD( "bm.7k", 0x00000, 0x10000 , NO_DUMP )

	ROM_REGION( 0x8000, "gfx1", 0 )
	ROM_LOAD( "bm04.5h", 0x00000, 0x8000, CRC(46cb9d3d) SHA1(96fd0e714b91fe13a2ca0d185ada9e4b4baa0c0b) )

	ROM_REGION( 0x40000, "gfx2", 0 )
	ROM_LOAD( "bm15.10f", 0x00000, 0x8000, CRC(6b1a0443) SHA1(32337c840ccd6815fd5844c194365c58d708f6dc) )
	ROM_LOAD( "bm16.11f", 0x08000, 0x8000, CRC(23c908c2) SHA1(42b83ff5781be9181802a21ff1b23c17ab1bc5a2) )
	ROM_LOAD( "bm17.12f", 0x10000, 0x8000, CRC(46bcdd07) SHA1(38feda668be25d1adc04aa36afc73b07c1545f89) )
	ROM_LOAD( "bm18.14f", 0x18000, 0x8000, CRC(e6ae7ba0) SHA1(959c306dc28b9be2adc54b3d46312d26764c7b8b) )
	ROM_LOAD( "bm19.10j", 0x20000, 0x8000, CRC(868ababc) SHA1(1c7be905f53c63bad25fbbd9b3cf82d2c7749bc3) )
	ROM_LOAD( "bm20.11j", 0x28000, 0x8000, CRC(0917e5d4) SHA1(62dd277bc1fa54cfe168ae2380bc147bd17f4205) )
	ROM_LOAD( "bm21.12j", 0x30000, 0x8000, CRC(9bfb0d89) SHA1(f1bae7ec46edcf46c7af84c054e89b322f8c8972) )
	ROM_LOAD( "bm22.14j", 0x38000, 0x8000, CRC(04f3c274) SHA1(932780c04abe285e1ec67b726b145175f73eafe0) )

	ROM_REGION( 0x10000, "gfx3", 0 )
	ROM_LOAD( "bm24.14k", 0x00000, 0x8000, CRC(11134036) SHA1(88da112ab9fc7e0d8f0e901f273715b950ae588c) )
	ROM_LOAD( "bm25.14l", 0x08000, 0x8000, CRC(092cf9c1) SHA1(19fe3c714b1d52cbb21dea25cdee5af841f525db) )

	ROM_REGION( 0x40000, "gfx4", 0 )
	ROM_LOAD( "bm06.10a", 0x00000, 0x8000, CRC(97acc8af) SHA1(c9fa07cb61f6905408b355edabfe453fb652ff0d) )
	ROM_LOAD( "bm07.11a", 0x08000, 0x8000, CRC(d78f7197) SHA1(6367c7e80e80d4a0d33d7840b5c843c63c80123e) )
	ROM_LOAD( "bm08.12a", 0x10000, 0x8000, CRC(1a626608) SHA1(755c27a07728fd686168e9d9e4dee3d8f274892a) )
	ROM_LOAD( "bm09.14a", 0x18000, 0x8000, CRC(92408400) SHA1(3ab299bad1ba115efead53ebd92254abe7a092ba) )
	ROM_LOAD( "bm10.10c", 0x20000, 0x8000, CRC(8438a44a) SHA1(873629b00cf3f6d8976a7fdafe63cd16e47b7491) )
	ROM_LOAD( "bm11.11c", 0x28000, 0x8000, CRC(6c69351d) SHA1(c213d5c3e76a5749bc32539604716dcef6dcb694) )
	ROM_LOAD( "bm12.12c", 0x30000, 0x8000, CRC(5e7efdb7) SHA1(fef271a38dc1a9e45a0c6e27e28e713c77c8f8c9) )
	ROM_LOAD( "bm13.14c", 0x38000, 0x8000, CRC(1143829a) SHA1(2b3a65e354a205c05a87f783e9938b64bc62396f) )

	ROM_REGION( 0x10000, "gfx5", 0 )
	ROM_LOAD( "bm14.5f", 0x0000, 0x8000, CRC(4d3c6401) SHA1(ce4f6dbf8fa030ad45cbb5afd58df27fed2d4618) )
	ROM_LOAD( "bm23.8k", 0x8000, 0x8000, CRC(a52aecbd) SHA1(45b0283d84d394c16c35802463ca95d70d1062d4) )

	ROM_REGION( 0x0c00, "proms", 0 )
	ROM_LOAD( "bm1.12a",  0x0000, 0x0100, CRC(74421f18) SHA1(5b8b59f6f4e5ad358611de50608f47f41a5b0e51) )
	ROM_LOAD( "bm2.13a",  0x0100, 0x0100, CRC(ac27541f) SHA1(1796c4c9041dfe28e6319576f21df1dbcb8d12bf) )
	ROM_LOAD( "bm3.14a",  0x0200, 0x0100, CRC(251fb6ff) SHA1(d1118159b3d429d841e4efa938728ebedadd7ec5) )
	ROM_LOAD( "bm5.7f",   0x0300, 0x0100, CRC(206713d0) SHA1(fa609f6d675af18c379838583505724d28bcff0e) )
	ROM_LOAD( "bm10.7l",  0x0400, 0x0100, CRC(33c2491c) SHA1(13da924e4b182759c4aae49034f3a7cbe556ea65) )
	ROM_LOAD( "bm9.6l",   0x0500, 0x0100, CRC(aeea4af7) SHA1(98f4570ee061e9aa58d8ed2d2f8ae59ce2ec5795) )
	ROM_LOAD( "bm12.12m", 0x0600, 0x0100, CRC(c18aa136) SHA1(684f04d9a5b94ae1db5fb95763e65271f4cf8e01) )
	ROM_LOAD( "bm11.12l", 0x0700, 0x0100, CRC(405aae37) SHA1(94a06f81b775c4e49d57d42fc064d3072a253bbd) )
	ROM_LOAD( "bm8.8c",   0x0800, 0x0100, CRC(c2010a9e) SHA1(be9852500209066e2f0ff2770e0c217d1636a0b5) )
	ROM_LOAD( "bm7.7c",   0x0900, 0x0100, CRC(b56f30c3) SHA1(9f5e6db464d21457a33ec8bdfdff069632b791db) )
	ROM_LOAD( "bm4.12c",  0x0a00, 0x0100, CRC(91a8a2e1) SHA1(9583c87eff876f04bc2ccf7218cd8081f1bcdb94) )
	ROM_LOAD( "bm6.4b",   0x0b00, 0x0100, CRC(0eaf5158) SHA1(bafd4108708f66cd7b280e47152b108f3e254fc9) )
ROM_END

GAME( 1987, 1943h, 1943,  _1943, 1943, _1943_state, 1943, ROT270, "Capcom", "1943: The Battle of Midway (US, Rev C) (hacked)", MACHINE_SUPPORTS_SAVE )


//PSmame


ROM_START( 1943kais01 )
	ROM_REGION( 0x30000, "maincpu", 0 )
	ROM_LOAD( "bmk01.12dhc01", 0x00000, 0x08000, CRC(03036734) SHA1(cdde7a2ebe4be0d99de2d2dc39625e7d3976ee9b) )
	ROM_LOAD( "bmk02.13d", 0x10000, 0x10000, CRC(2ebbc8c5) SHA1(3be5ad061411642723e3f2bcb7b3c3caa11ee15f) )
	ROM_LOAD( "bmk03.14d", 0x20000, 0x10000, CRC(475a6ac5) SHA1(fa07a855ba9173b6f81641c806ec7d938b0c282e) )

	ROM_REGION( 0x10000, "audiocpu", 0 )
	ROM_LOAD( "bmk05.4k", 0x00000, 0x8000, CRC(25f37957) SHA1(1e50c2a920eb3b5c881843686db857e9fee5ba1d) )

	ROM_REGION( 0x10000, "mcu", 0 )
	ROM_LOAD( "bm.7k", 0x00000, 0x10000 , NO_DUMP )

	ROM_REGION( 0x8000, "gfx1", 0 )
	ROM_LOAD( "bmk04.5h", 0x00000, 0x8000, CRC(884a8692) SHA1(027aa8c868dc07ccd9e27705031107881aef4b91) )

	ROM_REGION( 0x40000, "gfx2", 0 )
	ROM_LOAD( "bm15.10f",  0x00000, 0x8000, CRC(6b1a0443) SHA1(32337c840ccd6815fd5844c194365c58d708f6dc) )
	ROM_LOAD( "bmk16.11f", 0x08000, 0x8000, CRC(9416fe0d) SHA1(92fbc8fffa4497747ab80abe20eef361f6525114) )
	ROM_LOAD( "bmk17.12f", 0x10000, 0x8000, CRC(3d5acab9) SHA1(887d45b648fda952ae2137579f383ab8ede1facd) )
	ROM_LOAD( "bmk18.14f", 0x18000, 0x8000, CRC(7b62da1d) SHA1(1926109a2ab2f550ca87b0d2af73abd2b4a7498d) )
	ROM_LOAD( "bm19.10j",  0x20000, 0x8000, CRC(868ababc) SHA1(1c7be905f53c63bad25fbbd9b3cf82d2c7749bc3) )
	ROM_LOAD( "bmk20.11j", 0x28000, 0x8000, CRC(b90364c1) SHA1(104bc02237eeead84c7f35462186d0a1af8761bc) )
	ROM_LOAD( "bmk21.12j", 0x30000, 0x8000, CRC(8c7fe74a) SHA1(8846b57d7f47c10ab1f505c359ecf36dcbacb011) )
	ROM_LOAD( "bmk22.14j", 0x38000, 0x8000, CRC(d5ef8a0e) SHA1(2e42b1fbbfe823a33740a56d1334657db56d24d2) )

	ROM_REGION( 0x10000, "gfx3", 0 )
	ROM_LOAD( "bmk24.14k", 0x00000, 0x8000, CRC(bf186ef2) SHA1(cacbb8a61f8a64c3ba4ffde5ca6f07fe120b9a7e) )
	ROM_LOAD( "bmk25.14l", 0x08000, 0x8000, CRC(a755faf1) SHA1(8ee286d6ad7454ae34971f5891ddba4b76c244b0) )

	ROM_REGION( 0x40000, "gfx4", 0 )
	ROM_LOAD( "bmk06.10a", 0x00000, 0x8000, CRC(5f7e38b3) SHA1(33f69ebe91a0ee45d9107171fed26da475aaab3a) )
	ROM_LOAD( "bmk07.11a", 0x08000, 0x8000, CRC(ff3751fd) SHA1(bc942ddd46e7b147115e8ac22d24c2d018a7c373) )
	ROM_LOAD( "bmk08.12a", 0x10000, 0x8000, CRC(159d51bd) SHA1(746aa49b18aff0eaf2fb875c573d455416d45a1d) )
	ROM_LOAD( "bmk09.14a", 0x18000, 0x8000, CRC(8683e3d2) SHA1(591dc4811b226fe11cd5441ecb51aa3e95e68ac5) )
	ROM_LOAD( "bmk10.10c", 0x20000, 0x8000, CRC(1e0d9571) SHA1(44ea9603020e9ab717e3e506f7ecf288506c0502) )
	ROM_LOAD( "bmk11.11c", 0x28000, 0x8000, CRC(f1fc5ee1) SHA1(4ffc8e57734d3b59df695b86070511f1c447b992) )
	ROM_LOAD( "bmk12.12c", 0x30000, 0x8000, CRC(0f50c001) SHA1(0e6367d3f0ba39a00ee0fa6e42ae9d43d12da23d) )
	ROM_LOAD( "bmk13.14c", 0x38000, 0x8000, CRC(fd1acf8e) SHA1(88477ff1e5fbbca251d8cd4f241b42618ba64a80) )

	ROM_REGION( 0x10000, "gfx5", 0 )    /* tilemaps */
	ROM_LOAD( "bmk14.5f", 0x0000, 0x8000, CRC(cf0f5a53) SHA1(dc50f3f937f52910dbd0cedbc232acfed0aa6a42) )
	ROM_LOAD( "bmk23.8k", 0x8000, 0x8000, CRC(17f77ef9) SHA1(8ebb4b440042436ec2db52bad808cced832db77c) )

	ROM_REGION( 0x0c00, "proms", 0 )
	ROM_LOAD( "bmk1.12a",  0x0000, 0x0100, CRC(e001ea33) SHA1(4204bdf87820ac84bab2a1b5571a2ee28c4cdfc5) )
	ROM_LOAD( "bmk2.13a",  0x0100, 0x0100, CRC(af34d91a) SHA1(94bc6514c980fdd1cb013ff0819d6f32464c581c) )
	ROM_LOAD( "bmk3.14a",  0x0200, 0x0100, CRC(43e9f6ef) SHA1(e1f58368fe0bd9b53f6c286ce5009b218a5197dc) )
	ROM_LOAD( "bmk5.7f",   0x0300, 0x0100, CRC(41878934) SHA1(8f28210ab1d409c89600169a136b74a706001cdf) )
	ROM_LOAD( "bmk10.7l",  0x0400, 0x0100, CRC(de44b748) SHA1(0694fb19d98ccda728424436fc7350da7b5bd05e) )
	ROM_LOAD( "bmk9.6l",   0x0500, 0x0100, CRC(59ea57c0) SHA1(f961c7e9981cc819c2adf4efdc977841d284a3a2) )
	ROM_LOAD( "bmk12.12m", 0x0600, 0x0100, CRC(8765f8b0) SHA1(f32bab8e3587434b864fe97da9423f2335ccba2e) )
	ROM_LOAD( "bmk11.12l", 0x0700, 0x0100, CRC(87a8854e) SHA1(0cbc601b736d566d625867d65e0f7b2abb535c65) )
	ROM_LOAD( "bmk8.8c",   0x0800, 0x0100, CRC(dad17e2d) SHA1(fdb18ddc7574153bb7e27ba08b04b9dc87061c02) )
	ROM_LOAD( "bmk7.7c",   0x0900, 0x0100, CRC(76307f8d) SHA1(8d655e2a5c50541795316d924b2f18b55f4b9571) )
	ROM_LOAD( "bm4.12c",   0x0a00, 0x0100, CRC(91a8a2e1) SHA1(9583c87eff876f04bc2ccf7218cd8081f1bcdb94) )
	ROM_LOAD( "bm6.4b",    0x0b00, 0x0100, CRC(0eaf5158) SHA1(bafd4108708f66cd7b280e47152b108f3e254fc9) )
ROM_END

/*************************************
 *
 *  Game driver(s)
 *
 *************************************/
// Proyecto Shadows Mame Build Plus
/*    YEAR  NAME            PARENT    MACHINE        INPUT       INIT             MONITOR COMPANY                 FULLNAME FLAGS */
// 1943 Kai: Midway Kaisen
GAME( 1987, 1943kais01,   1943kai,    _1943,   1943, _1943_state,  1943, ROT270,  "Hacks",  "1943 Kai: Midway Kaisen (Japan)(Ex Super Version)", MACHINE_SUPPORTS_SAVE )
