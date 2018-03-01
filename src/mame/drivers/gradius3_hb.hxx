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
 
  /****************************************
                Gradius III
*****************************************/

ROM_START( gradius3s01 )
	ROM_REGION( 0x40000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "945_s13hc01.f15", 0x00000, 0x20000, CRC(c8a35884) SHA1(9622eb9b6dc0c8fbe8273070dfd400beb680abed) )
	ROM_LOAD16_BYTE( "945_s12hc01.e15", 0x00001, 0x20000, CRC(00260508) SHA1(fdc1d29b7bcacef33d283912c493ab0d90215e72) )

	ROM_REGION( 0x100000, "sub", 0 )
	ROM_LOAD16_BYTE( "945_m09.r17",  0x000000, 0x20000, CRC(b4a6df25) SHA1(85533cf140d28f6f81c0b49b8061bda0924a613a) )
	ROM_LOAD16_BYTE( "945_m08.n17",  0x000001, 0x20000, CRC(74e981d2) SHA1(e7b47a2da01ff73293d2100c48fdf00b33125af5) )
	ROM_LOAD16_BYTE( "945_l06b.r11", 0x040000, 0x20000, CRC(83772304) SHA1(a90c75a3de670b6ec5e0fc201876d463b4a76766) )
	ROM_LOAD16_BYTE( "945_l06a.n11", 0x040001, 0x20000, CRC(e1fd75b6) SHA1(6160d80a2f1bf550e85d6253cf521a96f5a644cc) )
	ROM_LOAD16_BYTE( "945_l07c.r15", 0x080000, 0x20000, CRC(c1e399b6) SHA1(e95bd478dd3beea0175bf9ee4cededb111c4ace1) )
	ROM_LOAD16_BYTE( "945_l07a.n15", 0x080001, 0x20000, CRC(96222d04) SHA1(b55700f683a556b0e73dbac9c7b4ce485420d21c) )
	ROM_LOAD16_BYTE( "945_l07d.r13", 0x0c0000, 0x20000, CRC(4c16d4bd) SHA1(01dcf169b78a1e495214b10181401d1920b0c924) )
	ROM_LOAD16_BYTE( "945_l07b.n13", 0x0c0001, 0x20000, CRC(5e209d01) SHA1(0efa1bbfdc7e2ba1e0bb96245e2bfe961258b446) )

	ROM_REGION( 0x10000, "audiocpu", 0 )
	ROM_LOAD( "945_m05.d9", 0x00000, 0x10000, CRC(c8c45365) SHA1(b9a7b736b52bca42c7b8c8ed64c8df73e0116158) )

	ROM_REGION( 0x200000, "k051960", 0 )   /* graphics (addressable by the main CPU) */
	ROM_LOAD32_WORD( "945_a02.l3",  0x000000, 0x80000, CRC(4dfffd74) SHA1(588210bac27448240ef08961f70b714b69cb3ffd) )
	ROM_LOAD32_WORD( "945_a01.h3",  0x000002, 0x80000, CRC(339d6dd2) SHA1(6a52b826aba92c75fc6a5926184948735dc20812) )
	ROM_LOAD32_BYTE( "945_l04a.k6", 0x100000, 0x20000, CRC(884e21ee) SHA1(ce86dd3a06775e5b1aa09db010dcb674e67828e7) )
	ROM_LOAD32_BYTE( "945_l04c.m6", 0x100001, 0x20000, CRC(45bcd921) SHA1(e51a8a71362a6fb55124aa1dce74519c0a3c6e3f) )
	ROM_LOAD32_BYTE( "945_l03a.e6", 0x100002, 0x20000, CRC(a67ef087) SHA1(fd63474f3bbde5dfc53ed4c1db25d6411a8b54d2) )
	ROM_LOAD32_BYTE( "945_l03c.h6", 0x100003, 0x20000, CRC(a56be17a) SHA1(1d387736144c30fcb5de54235331ab1ff70c356e) )
	ROM_LOAD32_BYTE( "945_l04b.k8", 0x180000, 0x20000, CRC(843bc67d) SHA1(cdf8421083f24ab27867ed5d08d8949da192b2b9) )
	ROM_LOAD32_BYTE( "945_l04d.m8", 0x180001, 0x20000, CRC(0a98d08e) SHA1(1e0ca51a2d45c01fa3f11950ddd387f41ddae691) )
	ROM_LOAD32_BYTE( "945_l03b.e8", 0x180002, 0x20000, CRC(933e68b9) SHA1(f3a39446ca77d17fdbd938bd5f718ae9d5570879) )
	ROM_LOAD32_BYTE( "945_l03d.h8", 0x180003, 0x20000, CRC(f375e87b) SHA1(6427b966795c907c8e516244872fe52217da62c4) )

	ROM_REGION( 0x0100, "proms", 0 )
	ROM_LOAD( "945l14.j28", 0x0000, 0x0100, CRC(c778c189) SHA1(847eaf379ba075c25911c6f83dd63ff390534f60) )  /* priority encoder (not used) */

	ROM_REGION( 0x80000, "k007232", 0 ) /* 007232 samples */
	ROM_LOAD( "945_a10.b15",  0x00000, 0x40000, CRC(1d083e10) SHA1(b116f133a7647ef7a6c373aff00e9622d9954b61) )
	ROM_LOAD( "945_l11a.c18", 0x40000, 0x20000, CRC(6043f4eb) SHA1(1c2e9ace1cfdde504b7b6158e3c3f54dc5ae33d4) )
	ROM_LOAD( "945_l11b.c20", 0x60000, 0x20000, CRC(89ea3baf) SHA1(8edcbaa7969185cfac48c02559826d1b8b081f3f) )
ROM_END

/*************************************
 *
 *  Game driver(s)
 *
 *************************************/
// Proyecto Shadows Mame Build Plus
/*    YEAR  NAME            PARENT    MACHINE        INPUT       INIT             MONITOR COMPANY                 FULLNAME FLAGS */
// Gradius III
GAME( 1989, gradius3s01, gradius3, gradius3, gradius3, gradius3_state, 0, ROT0, "Konami", "Gradius III (Japan, Secret fighters)", MACHINE_SUPPORTS_SAVE )
