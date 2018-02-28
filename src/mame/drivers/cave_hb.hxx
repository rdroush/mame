// license:BSD-3-Clause
// copyright-holders:Robbbert

ROM_START( pwrinst2h )
	ROM_REGION( 0x200000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "pwrinst2h.u45", 0x000000, 0x80000, CRC(126af635) SHA1(83222ed11f4f8e7b8bb6b5bc78ff1ef59738124d) )
	ROM_LOAD16_BYTE( "pwrinst2h.u44", 0x000001, 0x80000, CRC(e4eff14d) SHA1(d60de745c79e53a909905e0769a776d2e2d96a02) )
	ROM_LOAD16_BYTE( "g02.u43", 0x100000, 0x80000, CRC(178e3d24) SHA1(926234f4196a5d5e3bd1438abbf73355f2c65b06) )
	ROM_LOAD16_BYTE( "g02.u42", 0x100001, 0x80000, CRC(a0b4ee99) SHA1(c6df4aa2543b04d8bda7683f503e5eb763e506af) )

	ROM_REGION16_BE( 0x100000, "user1", ROMREGION_ERASE00 )

	ROM_REGION( 0x20000, "audiocpu", 0 )
	ROM_LOAD( "g02.u3a", 0x00000, 0x20000, CRC(ebea5e1e) SHA1(4d3af9e5f29d0c1b26563f51250039c9e8bd3735) )

	ROM_REGION( 0x1C00000, "sprites0", 0 )
	ROM_LOAD( "g02.u61", 0x000000, 0x200000, CRC(91e30398) SHA1(2b59a5e40bed2a988382054fe30d92808dad3348) )
	ROM_LOAD( "g02.u62", 0x200000, 0x200000, CRC(d9455dd7) SHA1(afa69fe9a540cd78b8cfecf09cffa1401c01141a) )
	ROM_LOAD( "g02.u63", 0x400000, 0x200000, CRC(4d20560b) SHA1(ceaee8cf0b69cc366b95ddcb689a5594d79e5114) )
	ROM_LOAD( "g02.u64", 0x600000, 0x200000, CRC(b17b9b6e) SHA1(fc6213d8322cda4c7f653e2d7d6d314ce84c97b7) )
	ROM_LOAD( "g02.u65", 0x800000, 0x200000, CRC(08541878) SHA1(138cf077a49a26440a3da1bdc2c399a208359e57) )
	ROM_LOAD( "g02.u66", 0xa00000, 0x200000, CRC(becf2a36) SHA1(f8b386d0292b1dc745b7253a3df51d1aa8d5e9db) )
	ROM_LOAD( "g02.u67", 0xc00000, 0x200000, CRC(52fe2b8b) SHA1(dd50aa62f7db995e28f47de9b3fb749aeeaaa5b0) )

	ROM_REGION( 0x200000, "layer0", 0 )
	ROM_LOAD( "g02.u78", 0x000000, 0x200000, CRC(1eca63d2) SHA1(538942b43301f950e3d5139461331c54dc90129d) )

	ROM_REGION( 0x100000, "layer1", 0 )
	ROM_LOAD( "g02.u81", 0x000000, 0x100000, CRC(8a3ff685) SHA1(4a59ec50ec4470453374fe10f76d3e894494b49f) )

	ROM_REGION( 0x100000, "layer2", 0 )
	ROM_LOAD( "g02.u89", 0x000000, 0x100000, CRC(373e1f73) SHA1(ec1ae9fab37eee41be8e1bc6dad03809b62fdbce) )

	ROM_REGION( 0x080000, "layer3", 0 )
	ROM_LOAD( "g02.82a", 0x000000, 0x080000, CRC(4b3567d6) SHA1(d3e14783b312d2bea9722a8e3c22bcec81e26166) )

	ROM_REGION( 0x440000, "oki1", 0 )
	ROM_LOAD( "g02.u53", 0x040000, 0x200000, CRC(c4bdd9e0) SHA1(a938a831e789ddf6f3cc5f3e5f3877ec7bd62d4e) )
	ROM_LOAD( "g02.u54", 0x240000, 0x200000, CRC(1357d50e) SHA1(433766177ce9d6933f90de85ba91bfc6d8d5d664) )

	ROM_REGION( 0x440000, "oki2", 0 )
	ROM_LOAD( "g02.u55", 0x040000, 0x200000, CRC(2d102898) SHA1(bd81f4cd2ba100707db0c5bb1419f0b23c998574) )
	ROM_LOAD( "g02.u56", 0x240000, 0x200000, CRC(9ff50dda) SHA1(1121685e387c20e228032f2b0f5cbb606376fc15) )
ROM_END

ROM_START( pwrinst2z )
	ROM_REGION( 0x200000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "pwrinst2z.u45", 0x000000, 0x80000, CRC(7b66ff4f) SHA1(ffbc2616197f1fd67dfbb9993018fe51fb12e623) )
	ROM_IGNORE(0x3d4f47)
	ROM_LOAD16_BYTE( "pwrinst2z.u44", 0x000001, 0x80000, CRC(b2b19ac4) SHA1(5d846c9e8a69b754bd8e874c3df50a20c0ab009a) )
	ROM_IGNORE(0x3d4f48)
	ROM_LOAD16_BYTE( "g02.u43", 0x100000, 0x80000, CRC(178e3d24) SHA1(926234f4196a5d5e3bd1438abbf73355f2c65b06) )
	ROM_LOAD16_BYTE( "g02.u42", 0x100001, 0x80000, CRC(a0b4ee99) SHA1(c6df4aa2543b04d8bda7683f503e5eb763e506af) )

	ROM_REGION16_BE( 0x100000, "user1", ROMREGION_ERASE00 )

	ROM_REGION( 0x20000, "audiocpu", 0 )
	ROM_LOAD( "g02.u3a", 0x00000, 0x20000, CRC(ebea5e1e) SHA1(4d3af9e5f29d0c1b26563f51250039c9e8bd3735) )

	ROM_REGION( 0x1C00000, "sprites0", 0 )
	ROM_LOAD( "g02.u61", 0x000000, 0x200000, CRC(91e30398) SHA1(2b59a5e40bed2a988382054fe30d92808dad3348) )
	ROM_LOAD( "g02.u62", 0x200000, 0x200000, CRC(d9455dd7) SHA1(afa69fe9a540cd78b8cfecf09cffa1401c01141a) )
	ROM_LOAD( "g02.u63", 0x400000, 0x200000, CRC(4d20560b) SHA1(ceaee8cf0b69cc366b95ddcb689a5594d79e5114) )
	ROM_LOAD( "g02.u64", 0x600000, 0x200000, CRC(b17b9b6e) SHA1(fc6213d8322cda4c7f653e2d7d6d314ce84c97b7) )
	ROM_LOAD( "g02.u65", 0x800000, 0x200000, CRC(08541878) SHA1(138cf077a49a26440a3da1bdc2c399a208359e57) )
	ROM_LOAD( "g02.u66", 0xa00000, 0x200000, CRC(becf2a36) SHA1(f8b386d0292b1dc745b7253a3df51d1aa8d5e9db) )
	ROM_LOAD( "g02.u67", 0xc00000, 0x200000, CRC(52fe2b8b) SHA1(dd50aa62f7db995e28f47de9b3fb749aeeaaa5b0) )

	ROM_REGION( 0x200000, "layer0", 0 )
	ROM_LOAD( "g02.u78", 0x000000, 0x200000, CRC(1eca63d2) SHA1(538942b43301f950e3d5139461331c54dc90129d) )

	ROM_REGION( 0x100000, "layer1", 0 )
	ROM_LOAD( "g02.u81", 0x000000, 0x100000, CRC(8a3ff685) SHA1(4a59ec50ec4470453374fe10f76d3e894494b49f) )

	ROM_REGION( 0x100000, "layer2", 0 )
	ROM_LOAD( "g02.u89", 0x000000, 0x100000, CRC(373e1f73) SHA1(ec1ae9fab37eee41be8e1bc6dad03809b62fdbce) )

	ROM_REGION( 0x080000, "layer3", 0 )
	ROM_LOAD( "g02.82a", 0x000000, 0x080000, CRC(4b3567d6) SHA1(d3e14783b312d2bea9722a8e3c22bcec81e26166) )

	ROM_REGION( 0x440000, "oki1", 0 )
	ROM_LOAD( "g02.u53", 0x040000, 0x200000, CRC(c4bdd9e0) SHA1(a938a831e789ddf6f3cc5f3e5f3877ec7bd62d4e) )
	ROM_LOAD( "g02.u54", 0x240000, 0x200000, CRC(1357d50e) SHA1(433766177ce9d6933f90de85ba91bfc6d8d5d664) )

	ROM_REGION( 0x440000, "oki2", 0 )
	ROM_LOAD( "g02.u55", 0x040000, 0x200000, CRC(2d102898) SHA1(bd81f4cd2ba100707db0c5bb1419f0b23c998574) )
	ROM_LOAD( "g02.u56", 0x240000, 0x200000, CRC(9ff50dda) SHA1(1121685e387c20e228032f2b0f5cbb606376fc15) )
ROM_END

GAME( 2013, pwrinst2h, pwrinst2, pwrinst2, metmqstr, cave_state, pwrinst2j, ROT0, "TT", "Power Instinct 2 (hack)", MACHINE_SUPPORTS_SAVE )
GAME( 1995, pwrinst2z, pwrinst2, pwrinst2, metmqstr, cave_state, pwrinst2j, ROT0, "hack", "Power Instinct 2 (unknown hack)", MACHINE_SUPPORTS_SAVE )

// From PScave

 /****************************************************
                 Gaia Crusaders
*****************************************************/

ROM_START( gaias01 )
	ROM_REGION( 0x100000, "maincpu", 0 )        /* 68000 Code */
	ROM_LOAD16_BYTE( "prg1.127", 0x000000, 0x080000, CRC(47b904b2) SHA1(58b9b55f59cf00f70b690a0371096e86f4d723c2) )
	ROM_LOAD16_BYTE( "prg2hc01.128", 0x000001, 0x080000, CRC(442b047d) SHA1(752f33b631e40ccbab7670501926144841f0b6cd) )

	ROM_REGION( 0x1000000, "sprites0", 0 )  /* Sprites */
	ROM_LOAD( "obj1.736", 0x000000, 0x400000, CRC(f4f84e5d) SHA1(8f445dd7a5c8a996939c211e5aec5742121a6e7e) )
	ROM_LOAD( "obj2.738", 0x400000, 0x400000, CRC(15c2a9ce) SHA1(631eb2968395be86ef2403733e7d4ec769a013b9) )

	ROM_REGION( 0x400000, "layer0", 0 ) /* Layer 0 */
	ROM_LOAD( "bg1.989", 0x000000, 0x400000, CRC(013a693d) SHA1(2cc5be6f47c13febed942e1c3167946efedc5f9b) )

	ROM_REGION( 0x400000, "layer1", 0 ) /* Layer 1 */
	ROM_LOAD( "bg2.995", 0x000000, 0x400000, CRC(783cc62f) SHA1(8b6e4212688b53be5ecc29ff2d41fd43e7d0a420) )

	ROM_REGION( 0x400000, "layer2", 0 ) /* Layer 2 */
	ROM_LOAD( "bg3.998", 0x000000, 0x400000, CRC(bcd61d1c) SHA1(660a3b02a8c39e1117b00d0ad06f73221fef4ce8) )

	ROM_REGION( 0xc00000, "ymz", 0 )    /* Samples */
	ROM_LOAD( "snd1.447", 0x000000, 0x400000, CRC(92770a52) SHA1(81f6835e1b45eb0f367e4586fdda92466f02edb9) )
	ROM_LOAD( "snd2.454", 0x400000, 0x400000, CRC(329ae1cf) SHA1(0c5e5074a5d8f4fb85ab4893bc953f192dcb301a) )
	ROM_LOAD( "snd3.455", 0x800000, 0x400000, CRC(4048d64e) SHA1(5e4ec6d37e70484e2fcd04188385e79ef0b53026) )
ROM_END

 /****************************************************
                    Metamoqester
*****************************************************/

ROM_START( metmqstrs01 )
	ROM_REGION( 0x280000, "maincpu", 0 )        /* 68000 code */
	ROM_LOAD16_WORD_SWAP( "bp947hc01.u25", 0x000000, 0x80000, CRC(748cc514) SHA1(11d882e77a539407c314f087386e50d691a6bc0b) )
	ROM_LOAD16_WORD_SWAP( "bp947a.u28", 0x100000, 0x80000, CRC(8c55decf) SHA1(76c6ce4c8e621273258d31ceb9ec4442fcf1a393) )
	ROM_LOAD16_WORD_SWAP( "bp947a.u29", 0x200000, 0x80000, CRC(cf0f3f3b) SHA1(49a3c0e7536edd53bbf09353e43e9166d736b3f4) )

	ROM_REGION( 0x40000, "audiocpu", 0 )        /* Z80 code */
	ROM_LOAD( "bp947a.u20",  0x00000, 0x40000, CRC(a4a36170) SHA1(ae55094518bd968ea0d04613a133c1421e412012) )

	ROM_REGION( 0x800000 * 2, "sprites0", 0 )        /* Sprites: * 2 */
	ROM_LOAD( "bp947a.u49", 0x000000, 0x200000, CRC(09749531) SHA1(6deeed2712241611ec3202c49a66beed28698af8) )
	ROM_LOAD( "bp947a.u50", 0x200000, 0x200000, CRC(19cea8b2) SHA1(87fb29458074f0e4852237e0184b8b3b44b0eb29) )
	ROM_LOAD( "bp947a.u51", 0x400000, 0x200000, CRC(c19bed67) SHA1(ac664a15512c0e8c8b701833aede95f53cd46a45) )
	ROM_LOAD( "bp947a.u52", 0x600000, 0x200000, CRC(70c64875) SHA1(1c20ab100ccfdf42c97a25e4deb9041b83f5ca8d) )

	ROM_REGION( 0x100000, "layer0", 0 ) /* Layer 0 */
	ROM_LOAD( "bp947a.u48", 0x000000, 0x100000, CRC(04ff6a3d) SHA1(7187db436f7a2ab59a3f5c6ab297b3d740e20f1d) )  // FIRST AND SECOND HALF IDENTICAL
	ROM_CONTINUE(           0x000000, 0x100000             )

	ROM_REGION( 0x100000, "layer1", 0 ) /* Layer 1 */
	ROM_LOAD( "bp947hc01.u47", 0x000000, 0x100000, CRC(b479e5e1) SHA1(311abcdaf56c0e79f7e24e53c72d1242edbfb245) )  // FIRST AND SECOND HALF IDENTICAL
	ROM_CONTINUE(           0x000000, 0x100000             )

	ROM_REGION( 0x100000, "layer2", 0 ) /* Layer 2 */
	ROM_LOAD( "bp947a.u46", 0x000000, 0x100000, CRC(0f9c906e) SHA1(03872e8be28637df66373bddb04ed91de4f9db75) )  // FIRST AND SECOND HALF IDENTICAL
	ROM_CONTINUE(           0x000000, 0x100000             )

	ROM_REGION( 0x100000, "oki1", 0 )   /* OKIM6295 #1 Samples */
	ROM_LOAD( "bp947a.u42", 0x000000, 0x100000, CRC(2ce8ff2a) SHA1(8ef8c5b7d4a0e60c980c2962e75f7977faafa311) )  // FIRST AND SECOND HALF IDENTICAL
	ROM_CONTINUE(           0x000000, 0x100000             )

	ROM_REGION( 0x100000, "oki2", 0 )   /* OKIM6295 #2 Samples */
	ROM_LOAD( "bp947a.u37", 0x000000, 0x100000, CRC(c3077c8f) SHA1(0a76316a81b7de78279b859549eb5161a721ac71) )  // FIRST AND SECOND HALF IDENTICAL
	ROM_CONTINUE(           0x000000, 0x100000             )
ROM_END

 /****************************************************
                  Power Instinct 2
*****************************************************/

ROM_START( theroes01 )
	ROM_REGION( 0x100000, "maincpu", 0 )        /* 68000 Code */
	ROM_LOAD16_BYTE( "t-hero-epm1hc01.u0127", 0x000000, 0x080000, CRC(8d5961d1) SHA1(69cb82c3d269f641840f17fd7237d0744d01405e) )
	ROM_LOAD16_BYTE( "t-hero-epm0hc01.u0129", 0x000001, 0x080000, CRC(89dc3ad3) SHA1(8652f2b93d5b4fe1a4d88cb39c9821f0739bfeff) )

	ROM_REGION( 0x1000000, "sprites0", 0 )  /* Sprites */
	ROM_LOAD( "t-hero-obj1.u0736", 0x000000, 0x400000, CRC(35090f7c) SHA1(035e6c12a87d9c7241eea34fc7e2170bec842acc) )
	ROM_LOAD( "t-hero-obj2.u0738", 0x400000, 0x400000, CRC(71605108) SHA1(6070c26d8f22fafc81d97cacfef96ae652e355d0) )

	ROM_REGION( 0x400000, "layer0", 0 ) /* Layer 0 */
	ROM_LOAD( "t-hero-bg1.u0999", 0x000000, 0x400000, CRC(47b0fb40) SHA1(a7217b3d805b4255c589821cdadd9b190cada525) )

	ROM_REGION( 0x400000, "layer1", 0 ) /* Layer 1 */
	ROM_LOAD( "t-hero-bg2.u0995", 0x000000, 0x400000, CRC(b16237a1) SHA1(66aed2c5036492a17d20de90333e172a6f117851) )

	ROM_REGION( 0x400000, "layer2", 0 ) /* Layer 2 */
	ROM_LOAD( "t-hero-bg3.u0998", 0x000000, 0x400000, CRC(08eb5604) SHA1(3d32966708c73198272c40e6ddc680bf4c7919eb) )

	ROM_REGION( 0xc00000, "ymz", 0 )    /* Samples */
	ROM_LOAD( "crvsaders-snd1.u0447", 0x000000, 0x400000, CRC(92770a52) SHA1(81f6835e1b45eb0f367e4586fdda92466f02edb9) )
	ROM_LOAD( "crvsaders-snd2.u0454", 0x400000, 0x400000, CRC(329ae1cf) SHA1(0c5e5074a5d8f4fb85ab4893bc953f192dcb301a) )
	ROM_LOAD( "t-hero-snd3.u0455",    0x800000, 0x400000, CRC(52b0b2c0) SHA1(6e96698905391c21a4fedd60e2768734b58add4e) )
ROM_END

 /****************************************************
                  Power Instinct 2
*****************************************************/

ROM_START( pwrinst2s01 )
	ROM_REGION( 0xA00000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "g02hc01.u45", 0x000000, 0x454F47, CRC(7b66ff4f) SHA1(ffbc2616197f1fd67dfbb9993018fe51fb12e623) )
	ROM_LOAD16_BYTE( "g02hc01.u44", 0x000001, 0x454F48, CRC(b2b19ac4) SHA1(5d846c9e8a69b754bd8e874c3df50a20c0ab009a) )
	ROM_LOAD16_BYTE( "g02.u43", 0x100000, 0x80000, CRC(178e3d24) SHA1(926234f4196a5d5e3bd1438abbf73355f2c65b06) )
	ROM_LOAD16_BYTE( "g02.u42", 0x100001, 0x80000, CRC(a0b4ee99) SHA1(c6df4aa2543b04d8bda7683f503e5eb763e506af) )

	ROM_REGION16_BE( 0x100000, "user1", ROMREGION_ERASE00 )

	ROM_REGION( 0x20000, "audiocpu", 0 )
	ROM_LOAD( "g02.u3a", 0x00000, 0x20000, CRC(ebea5e1e) SHA1(4d3af9e5f29d0c1b26563f51250039c9e8bd3735) )

	ROM_REGION( 0x1C00000, "sprites0", 0 )
	ROM_LOAD( "g02.u61", 0x000000, 0x200000, CRC(91e30398) SHA1(2b59a5e40bed2a988382054fe30d92808dad3348) )
	ROM_LOAD( "g02.u62", 0x200000, 0x200000, CRC(d9455dd7) SHA1(afa69fe9a540cd78b8cfecf09cffa1401c01141a) )
	ROM_LOAD( "g02.u63", 0x400000, 0x200000, CRC(4d20560b) SHA1(ceaee8cf0b69cc366b95ddcb689a5594d79e5114) )
	ROM_LOAD( "g02.u64", 0x600000, 0x200000, CRC(b17b9b6e) SHA1(fc6213d8322cda4c7f653e2d7d6d314ce84c97b7) )
	ROM_LOAD( "g02.u65", 0x800000, 0x200000, CRC(08541878) SHA1(138cf077a49a26440a3da1bdc2c399a208359e57) )
	ROM_LOAD( "g02.u66", 0xa00000, 0x200000, CRC(becf2a36) SHA1(f8b386d0292b1dc745b7253a3df51d1aa8d5e9db) )
	ROM_LOAD( "g02.u67", 0xc00000, 0x200000, CRC(52fe2b8b) SHA1(dd50aa62f7db995e28f47de9b3fb749aeeaaa5b0) )

	ROM_REGION( 0x200000, "layer0", 0 )
	ROM_LOAD( "g02.u78", 0x000000, 0x200000, CRC(1eca63d2) SHA1(538942b43301f950e3d5139461331c54dc90129d) )

	ROM_REGION( 0x100000, "layer1", 0 )
	ROM_LOAD( "g02.u81", 0x000000, 0x100000, CRC(8a3ff685) SHA1(4a59ec50ec4470453374fe10f76d3e894494b49f) )

	ROM_REGION( 0x100000, "layer2", 0 )
	ROM_LOAD( "g02.u89", 0x000000, 0x100000, CRC(373e1f73) SHA1(ec1ae9fab37eee41be8e1bc6dad03809b62fdbce) )

	ROM_REGION( 0x080000, "layer3", 0 )
	ROM_LOAD( "g02.82a", 0x000000, 0x080000, CRC(4b3567d6) SHA1(d3e14783b312d2bea9722a8e3c22bcec81e26166) )

	ROM_REGION( 0x440000, "oki1", 0 )
	ROM_LOAD( "g02.u53", 0x040000, 0x200000, CRC(c4bdd9e0) SHA1(a938a831e789ddf6f3cc5f3e5f3877ec7bd62d4e) )
	ROM_LOAD( "g02.u54", 0x240000, 0x200000, CRC(1357d50e) SHA1(433766177ce9d6933f90de85ba91bfc6d8d5d664) )

	ROM_REGION( 0x440000, "oki2", 0 )
	ROM_LOAD( "g02.u55", 0x040000, 0x200000, CRC(2d102898) SHA1(bd81f4cd2ba100707db0c5bb1419f0b23c998574) )
	ROM_LOAD( "g02.u56", 0x240000, 0x200000, CRC(9ff50dda) SHA1(1121685e387c20e228032f2b0f5cbb606376fc15) )
ROM_END

 /****************************************************
                Gouketsuji Gaiden
*****************************************************/

ROM_START( plegendsjs01 )
	ROM_REGION( 0xA00000, "maincpu", 0 )        /* 68000 code */
	ROM_LOAD16_BYTE( "proghc01.u45", 0x000000, 0x454F5D, CRC(ab7d1e49) SHA1(2bab667194d69cbec20744fac693f3953cd28578) )
	ROM_LOAD16_BYTE( "proghc01.u44", 0x000001, 0x454F49, CRC(bad17718) SHA1(f44413152dcbf07fd93e7447827679faeb0ee651) )
	ROM_LOAD16_BYTE( "pr12.u2",  0x100000, 0x80000, CRC(0e202559) SHA1(217a8e47d5c679aff02ca43de1641230e4f78b01) ) /* Contains text in Japanese */
	ROM_LOAD16_BYTE( "pr12.u3",  0x100001, 0x80000, CRC(54742f21) SHA1(fae7bb7381478eb077f0409acd521f77417aa968) ) /* Contains text in Japanese */

	ROM_REGION16_BE( 0x100000, "user1", 0 ) /* 68000 extra data roms */
	ROM_LOAD16_BYTE( "d15.u4",  0x000000, 0x80000, CRC(6352cec0) SHA1(a54d55b8d642e438158268d0d41880b6589e48e2) )
	ROM_LOAD16_BYTE( "d17.u5",  0x000001, 0x80000, CRC(7af810d8) SHA1(5e24f78a228809a001f3f3372c1b32ea05070e17) )

	ROM_REGION( 0x20000, "audiocpu", 0 )        /* Z80 code */
	ROM_LOAD( "sound.u3", 0x00000, 0x20000, CRC(36f71520) SHA1(11d0a059ddba3e1aa4c54ccdde7b3f5c7bde482f) )

	ROM_REGION( 0x1000000 * 2, "sprites0", 0 )       /* Sprites: * 2 */
	ROM_LOAD( "g02.u61", 0x000000, 0x200000, CRC(91e30398) SHA1(2b59a5e40bed2a988382054fe30d92808dad3348) )
	ROM_LOAD( "g02.u62", 0x200000, 0x200000, CRC(d9455dd7) SHA1(afa69fe9a540cd78b8cfecf09cffa1401c01141a) )
	ROM_LOAD( "g02.u63", 0x400000, 0x200000, CRC(4d20560b) SHA1(ceaee8cf0b69cc366b95ddcb689a5594d79e5114) )
	ROM_LOAD( "g02.u64", 0x600000, 0x200000, CRC(b17b9b6e) SHA1(fc6213d8322cda4c7f653e2d7d6d314ce84c97b7) )
	ROM_LOAD( "g02.u65", 0x800000, 0x200000, CRC(08541878) SHA1(138cf077a49a26440a3da1bdc2c399a208359e57) )
	ROM_LOAD( "g02.u66", 0xa00000, 0x200000, CRC(becf2a36) SHA1(f8b386d0292b1dc745b7253a3df51d1aa8d5e9db) )
	ROM_LOAD( "atgs.u1", 0xc00000, 0x200000, CRC(aa6f34a9) SHA1(00de85de1b413bd2c46931c13365f8556b50b634) ) /* US version's rom labeled "sp6_u67-1" */
	ROM_LOAD( "atgs.u2", 0xe00000, 0x200000, CRC(553eda27) SHA1(5b9126f966f0c64b3ac7c06526064d71e4df60c5) ) /* US version's rom labeled "sp6_u67-2" */

	ROM_REGION( 0x200000, "layer0", 0 ) /* Layer 0 */
	ROM_LOAD( "atgs.u78", 0x000000, 0x200000, CRC(16710ecb) SHA1(6277f7f6095457df649932550b04242e5853ec5e) ) /* US version's rom labeled "bg0_u78" */

	ROM_REGION( 0x200000, "layer1", 0 ) /* Layer 1 */
	ROM_LOAD( "atgs.u81", 0x000000, 0x200000, CRC(cb2aca91) SHA1(869f0f2db35c45ec90b74d33d521cbb598e60a3f) ) /* US version's rom labeled "bg1_u81" */

	ROM_REGION( 0x200000, "layer2", 0 ) /* Layer 2 */
	ROM_LOAD( "atgs.u89", 0x000000, 0x200000, CRC(65f45a0f) SHA1(b7f4b56308dcdc144100d0a92d91255459a320a4) ) /* US version's rom labeled "bg2_u89" */

	ROM_REGION( 0x080000, "layer3", 0 ) /* Layer 3 */
	ROM_LOAD( "text.u82", 0x000000, 0x080000, CRC(f57333ea) SHA1(409d8005ffcf91943e4a743b2434ce425f5bdc36) ) /* US version's rom labeled "d20" */

	ROM_REGION( 0x440000, "oki1", 0 )   /* OKIM6295 #1 Samples */
	/* Leave the 0x40000 bytes addressable by the chip empty */
	ROM_LOAD( "g02.u53", 0x040000, 0x200000, CRC(c4bdd9e0) SHA1(a938a831e789ddf6f3cc5f3e5f3877ec7bd62d4e) )
	ROM_LOAD( "g02.u54", 0x240000, 0x200000, CRC(1357d50e) SHA1(433766177ce9d6933f90de85ba91bfc6d8d5d664) )

	ROM_REGION( 0x440000, "oki2", 0 )   /* OKIM6295 #2 Samples */
	/* Leave the 0x40000 bytes addressable by the chip empty */
	ROM_LOAD( "g02.u55", 0x040000, 0x200000, CRC(2d102898) SHA1(bd81f4cd2ba100707db0c5bb1419f0b23c998574) )
	ROM_LOAD( "g02.u56", 0x240000, 0x200000, CRC(9ff50dda) SHA1(1121685e387c20e228032f2b0f5cbb606376fc15) )
ROM_END

/*************************************
 *
 *  Game driver(s)
 *
 *************************************/
// Proyecto Shadows Mame Build Plus
/*    YEAR  NAME           PARENT    MACHINE     INPUT     INIT            MONITOR COMPANY         FULLNAME FLAGS */
// Gaia Crusaders
GAME( 1999, gaias01,       gaia,     gaia,       gaia,     cave_state,     gaia,     ROT0,         "Hacks",  "Gaia Crusaders (Enable Secret Character)", MACHINE_SUPPORTS_SAVE | MACHINE_IMPERFECT_SOUND )
// Metamoqester
GAME( 1995, metmqstrs01,   metmqstr, metmqstr,   metmqstr, cave_state,     metmqstr, ROT0,         "Hacks",  "Metamoqester (Translation-Korean)",   MACHINE_SUPPORTS_SAVE )
// Thunder Heroes
GAME( 2001, theroes01,     theroes,  gaia,       theroes,  cave_state,     gaia,      ROT0,        "Hacks",  "Thunder Heroes (Select Characters)", MACHINE_SUPPORTS_SAVE | MACHINE_IMPERFECT_SOUND )
// Power Instinct 2
GAME( 2017, pwrinst2s01,   pwrinst2, pwrinst2,   metmqstr, cave_state,     pwrinst2j,ROT0,         "Hacks",  "Power Instinct 2 (Description Of Unknown Origin 01)", MACHINE_SUPPORTS_SAVE )
// Gouketsuji Gaiden
GAME( 2017, plegendsjs01,  plegends, pwrinst2,   metmqstr, cave_state,     pwrinst2j,ROT0,         "Hacks",  "Gouketsuji Gaiden (Description Of Unknown Origin 01)", MACHINE_SUPPORTS_SAVE )
