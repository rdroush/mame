// Proyecto De Inicio:"2016/2017"
// Derechos Del Autor:Gaston90

/***************************************
	Proyecto Shadows Mame Build Plus
***************************************/

/******************************************************************************************
   Muchos Roms De Mi Proyecto Shadow Se Estar� Deshabilitado. Por
   Los Motivo Es Que Se Empez� Agregar En El HBMame Oficial, Lo Cual Me Ver�
   Obligado Deshabilitando Porque Si No Se Estar�a Duplicado Archivo De Roms.
******************************************************************************************/

/*****************************************
 *
 *         ROM Definici�n(s)
 *
 ****************************************/
 
  /**************************************************
   Sengoku Blade: Sengoku Ace Episode II / Tengai 
***************************************************/

ROM_START( tengais01 )

	ROM_REGION( 0x100000, "maincpu", 0 )        /* Main CPU Code */
	ROM_LOAD32_WORD_SWAP( "5-u40hc01.bin", 0x000000, 0x080000, CRC(aae15ef1) SHA1(e5d056eb0ef26a697544cbeacb5f993217fdbd0a) ) // 1&0
	ROM_LOAD32_WORD_SWAP( "4-u41hc01.bin", 0x000002, 0x080000, CRC(e8863874) SHA1(f6ac25170516658c368fb86b2b653e3356b42f19) ) // 3&2

	ROM_REGION( 0x020000, "audiocpu", 0 )       /* Sound CPU Code */
	ROM_LOAD( "1-u63.bin", 0x00000, 0x20000, CRC(2025e387) SHA1(334b0eb3b416d46ccaadff3eee6f1abba63285fb) )

	ROM_REGION( 0x000100, "cpu2", 0 )       /* MCU */
	ROM_LOAD( "4-u59.bin", 0x00000, 0x00100, NO_DUMP )

	ROM_REGION( 0x600000, "gfx1", 0 )   /* Sprites */
	ROM_LOAD16_WORD_SWAP( "u20.bin",  0x000000, 0x200000, CRC(ed42ef73) SHA1(74693fcc83a2654ddb18fd513d528033863d6116) )
	ROM_LOAD16_WORD_SWAP( "u22.bin",  0x200000, 0x200000, CRC(8d21caee) SHA1(2a68af8b2be2158dcb152c434e91a75871478d41) )
	ROM_LOAD16_WORD_SWAP( "u21.bin",  0x400000, 0x200000, CRC(efe34eed) SHA1(7891495b443a5acc7b2f17fe694584f6cb0afacc) )

	ROM_REGION( 0x400000, "gfx2", 0 )   /* Layer 0 + 1 */
	ROM_LOAD16_WORD_SWAP( "u34.bin",  0x000000, 0x400000, CRC(2a2e2eeb) SHA1(f1d99353c0affc5c908985e6f2a5724e5223cccc) ) /* four banks of 0x100000 */

	ROM_REGION( 0x400000, "ymf", 0 )    /* Samples */
	ROM_LOAD( "u61.bin",  0x000000, 0x200000, CRC(a63633c5) SHA1(89e75a40518926ebcc7d88dea86c01ba0bb496e5) )    // 8 bit signed pcm (16KHz)
	ROM_LOAD( "u62.bin",  0x200000, 0x200000, CRC(3ad0c357) SHA1(35f78cfa2eafa93ab96b24e336f569ee84af06b6) )

	ROM_REGION( 0x040000, "spritelut", 0 )  /* Sprites LUT */
	ROM_LOAD( "u1.bin",  0x000000, 0x040000, CRC(681d7d55) SHA1(b0b28471440d747adbc4d22d1918f89f6ede1615) )

ROM_END

ROM_START( tengaijs01 )

	ROM_REGION( 0x100000, "maincpu", 0 )        /* Main CPU Code */
	ROM_LOAD32_WORD_SWAP( "2-u40hc01.bin", 0x000000, 0x080000, CRC(eed548eb) SHA1(afe46cd87d75e94c5f22cc4304d5e4ba4ac501e8) ) // 1&0
	ROM_LOAD32_WORD_SWAP( "3-u41hc01.bin", 0x000002, 0x080000, CRC(d6b62117) SHA1(9e4b457794b3d43e3133667d574c490c3e037a97) ) // 3&2

	ROM_REGION( 0x020000, "audiocpu", 0 )       /* Sound CPU Code */
	ROM_LOAD( "1-u63.bin", 0x00000, 0x20000, CRC(2025e387) SHA1(334b0eb3b416d46ccaadff3eee6f1abba63285fb) )

	ROM_REGION( 0x000100, "cpu2", 0 )       /* MCU */
	ROM_LOAD( "4-u59.bin", 0x00000, 0x00100, NO_DUMP )

	ROM_REGION( 0x600000, "gfx1", 0 )   /* Sprites */
	ROM_LOAD16_WORD_SWAP( "u20.bin",  0x000000, 0x200000, CRC(ed42ef73) SHA1(74693fcc83a2654ddb18fd513d528033863d6116) )
	ROM_LOAD16_WORD_SWAP( "u22.bin",  0x200000, 0x200000, CRC(8d21caee) SHA1(2a68af8b2be2158dcb152c434e91a75871478d41) )
	ROM_LOAD16_WORD_SWAP( "u21.bin",  0x400000, 0x200000, CRC(efe34eed) SHA1(7891495b443a5acc7b2f17fe694584f6cb0afacc) )

	ROM_REGION( 0x400000, "gfx2", 0 )   /* Layer 0 + 1 */
	ROM_LOAD16_WORD_SWAP( "u34.bin",  0x000000, 0x400000, CRC(2a2e2eeb) SHA1(f1d99353c0affc5c908985e6f2a5724e5223cccc) ) /* four banks of 0x100000 */

	ROM_REGION( 0x400000, "ymf", 0 )    /* Samples */
	ROM_LOAD( "u61.bin",  0x000000, 0x200000, CRC(a63633c5) SHA1(89e75a40518926ebcc7d88dea86c01ba0bb496e5) )    // 8 bit signed pcm (16KHz)
	ROM_LOAD( "u62.bin",  0x200000, 0x200000, CRC(3ad0c357) SHA1(35f78cfa2eafa93ab96b24e336f569ee84af06b6) )

	ROM_REGION( 0x040000, "spritelut", 0 )  /* Sprites LUT */
	ROM_LOAD( "u1.bin",  0x000000, 0x040000, CRC(681d7d55) SHA1(b0b28471440d747adbc4d22d1918f89f6ede1615) )

ROM_END

/*************************************
 *
 *  Game driver(s)
 *
 *************************************/
// Proyecto Shadows Mame Build Plus
/*    YEAR  NAME            PARENT    MACHINE        INPUT       INIT             MONITOR COMPANY                 FULLNAME FLAGS */
// 1943 Kai: Midway Kaisen
GAME( 1996, tengais01,    tengai,   s1945,    tengai,   psikyo_state, tengai,   ROT0,   "Hacks",  "Tengai (Ex Super version)",                                 MACHINE_SUPPORTS_SAVE )
GAME( 1996, tengaijs01,   tengai,   s1945,    tengaij,  psikyo_state, tengai,   ROT0,   "Hacks",  "Sengoku Blade: Sengoku Ace Episode II / Tengai (Ex Super version)", MACHINE_SUPPORTS_SAVE ) 
