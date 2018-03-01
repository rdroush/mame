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
               Street Fighter
*****************************************/

ROM_START( sfs01 )
	ROM_REGION( 0x60000, "maincpu", 0 )
	ROM_LOAD16_BYTE("sfd-19hc01.2a", 0x00000, 0x10000, CRC(9bcaeada) SHA1(6d5228697b49aae797e089c14b2f79c30572cbaf) )
	ROM_LOAD16_BYTE("sfd-22hc01.2c", 0x00001, 0x10000, CRC(001cffb9) SHA1(c6f83793ac2c2058ddaf40abfcc7d7da22b3cdb7) )
	ROM_LOAD16_BYTE("sfd-20hc01.3a", 0x20000, 0x10000, CRC(2a2abcf9) SHA1(2eeb7aa32b0b32e6a4397156ab5cc9a022b11cbe) )
	ROM_LOAD16_BYTE("sfd-23hc01.3c", 0x20001, 0x10000, CRC(67303dea) SHA1(a53cbd45e2be3ef8f85f7f38ba30a0db2a6f83d9) )
	ROM_LOAD16_BYTE("sfd-21hc01.4a", 0x40000, 0x10000, CRC(7a3e0c4e) SHA1(a9cf0b0de93a328e071f997b10bc399471321c62) )
	ROM_LOAD16_BYTE("sfd-24hc01.4c", 0x40001, 0x10000, CRC(a8ad79f5) SHA1(559612a1ce84754054c6f0d7866778c98abe9fef) )

	ROM_REGION( 0x10000, "audiocpu", 0 )    /* 64k for the music CPU */
	ROM_LOAD( "sf-02.7k", 0x0000, 0x8000, CRC(4a9ac534) SHA1(933645f8db4756aa2a35a843c3ac6f93cb8d565d) )

	ROM_REGION( 0x40000, "audio2", 0 )  /* 256k for the samples CPU */
	ROM_LOAD( "sfu-00hc01.1h",0x00000, 0x20000, CRC(4b733845) SHA1(f7ff46e02f8ce6682d6e573588271bae2edfa90f) )
	ROM_LOAD( "sf-01.1k", 0x20000, 0x20000, CRC(86e0f0d5) SHA1(7cef8056f83dac15f1b47d7be705d26170858337) )

	ROM_REGION( 0x080000, "gfx1", 0 )
	ROM_LOAD( "sf-39.2k", 0x000000, 0x020000, CRC(cee3d292) SHA1(a8c22f1dc81976e8dd5d6c70361c61fa3f9f89d6) ) /* Background b planes 0-1*/
	ROM_LOAD( "sf-38.1k", 0x020000, 0x020000, CRC(2ea99676) SHA1(5f3eb77e75f0ee27fb8fc7bab2819b3fdd480206) )
	ROM_LOAD( "sf-41.4k", 0x040000, 0x020000, CRC(e0280495) SHA1(e52c79feed590535b9a0b71ccadd0ed27d04ff45) ) /* planes 2-3 */
	ROM_LOAD( "sf-40.3k", 0x060000, 0x020000, CRC(c70b30de) SHA1(26112ee1720b6ad0e2e29e2d25ee2ec76fca0e3a) )

	ROM_REGION( 0x100000, "gfx2", 0 )
	ROM_LOAD( "sf-25.1d", 0x000000, 0x020000, CRC(7f23042e) SHA1(a355fd7047fb1a71ab5cd08e1afd82c2558494c1) ) /* Background m planes 0-1 */
	ROM_LOAD( "sf-28.1e", 0x020000, 0x020000, CRC(92f8b91c) SHA1(6d958bc45131810d7b0af02be939ce37a39c35e8) )
	ROM_LOAD( "sf-30.1g", 0x040000, 0x020000, CRC(b1399856) SHA1(7c956d49b2e73291182ea1ec4cebd3411d1322a1) )
	ROM_LOAD( "sf-34.1h", 0x060000, 0x020000, CRC(96b6ae2e) SHA1(700e050463b7a29a1eb08007a2add045afdcd8a0) )
	ROM_LOAD( "sf-26.2d", 0x080000, 0x020000, CRC(54ede9f5) SHA1(c2cb354a6b32047759945fa3ecafc70ba7d1dda1) ) /* planes 2-3 */
	ROM_LOAD( "sf-29.2e", 0x0a0000, 0x020000, CRC(f0649a67) SHA1(eeda256527f7a2ee2d5e0688c505a01de548bc54) )
	ROM_LOAD( "sf-31.2g", 0x0c0000, 0x020000, CRC(8f4dd71a) SHA1(28b82c540df04c91a2dd6cbbc9a95bbebda6643b) )
	ROM_LOAD( "sf-35.2h", 0x0e0000, 0x020000, CRC(70c00fb4) SHA1(7c5504a5aedd3be7b663c5090eb22243e3fa669b) )

	ROM_REGION( 0x1c0000, "gfx3", 0 )
	/* Sprites planes 1-2 */
	ROM_LOAD( "sf-15.1m", 0x000000, 0x020000, CRC(fc0113db) SHA1(7c19603129be5f6e1ccd07fd8b7ee1cbf86468db) )
	ROM_LOAD( "sf-16.2m", 0x020000, 0x020000, CRC(82e4a6d3) SHA1(5ec519c2740c66f5da27ced1db99e19fe38fdad7) )
	ROM_LOAD( "sf-11.1k", 0x040000, 0x020000, CRC(e112df1b) SHA1(3f9856f69b457d79fe085bf51dfb2efcd98f883d) )
	ROM_LOAD( "sf-12.2k", 0x060000, 0x020000, CRC(42d52299) SHA1(6560c38f5fd5a47db7728cc7df83d2169157174f) )
	ROM_LOAD( "sf-07.1h", 0x080000, 0x020000, CRC(49f340d9) SHA1(65822efefa198791a632ef851a5ce06a71b4ed0f) )
	ROM_LOAD( "sf-08.2h", 0x0a0000, 0x020000, CRC(95ece9b1) SHA1(f0a15fce5cd9617fa5d4dd43bd5b6ea190dace85) )
	ROM_LOAD( "sf-03.1f", 0x0c0000, 0x020000, CRC(5ca05781) SHA1(004f5ad34798471b39bd4612c797f0913ed0fb4a) )
	/* Sprites planes 2-3 */
	ROM_LOAD( "sf-17.3m", 0x0e0000, 0x020000, CRC(69fac48e) SHA1(c9272217256c73cb8ddb4fbbfb5905ce1122c746) )
	ROM_LOAD( "sf-18.4m", 0x100000, 0x020000, CRC(71cfd18d) SHA1(4c17e2124f3456d6b13ede8ad3ae916b53f9bb7e) )
	ROM_LOAD( "sf-13.3k", 0x120000, 0x020000, CRC(fa2eb24b) SHA1(96f3bd54c340771577cc232ebde93965421f2557) )
	ROM_LOAD( "sf-14.4k", 0x140000, 0x020000, CRC(ad955c95) SHA1(549d6a5125432aa45d03f15e76f6c2c8ab2e05a3) )
	ROM_LOAD( "sf-09.3h", 0x160000, 0x020000, CRC(41b73a31) SHA1(aaa7a53e29fe23a1ca8ec4430f7efcbd774a8cbf) )
	ROM_LOAD( "sf-10.4h", 0x180000, 0x020000, CRC(91c41c50) SHA1(b03fb9b3c553fb4aae45ad6997eeb7bb95fdcce3) )
	ROM_LOAD( "sf-05.3f", 0x1a0000, 0x020000, CRC(538c7cbe) SHA1(f030a9562fbb93d1534b91343ca3f429cdbd0136) )

	ROM_REGION( 0x004000, "gfx4", 0 )
	ROM_LOAD( "sf-27.4d", 0x000000, 0x004000, CRC(2b09b36d) SHA1(9fe1dd3a9396fbb06f30247cfe526653553beca1) ) /* Characters planes 1-2 */

	ROM_REGION( 0x40000, "gfx5", 0 )    /* background tilemaps */
	ROM_LOAD( "sf-37.4h", 0x000000, 0x010000, CRC(23d09d3d) SHA1(a0c71abc49c5fe59487a63b502e3d03021bfef13) )
	ROM_LOAD( "sf-36.3h", 0x010000, 0x010000, CRC(ea16df6c) SHA1(68709a314b775c500817fc17d40a80204b2ae06c) )
	ROM_LOAD( "sf-32.3g", 0x020000, 0x010000, CRC(72df2bd9) SHA1(9a0da618139673738b6b3302207255e44c5491a2) )
	ROM_LOAD( "sf-33.4g", 0x030000, 0x010000, CRC(3e99d3d5) SHA1(9168a977e80f8c23c6126b9e64eb176290cf941a) )

	ROM_REGION( 0x0320, "proms", 0 )
	ROM_LOAD( "mb7114h.12k",  0x0000, 0x0100, CRC(75af3553) SHA1(14da009592877a6097b34ea844fa897ceda7465e) ) /* unknown */
	ROM_LOAD( "mb7114h.11h",  0x0100, 0x0100, CRC(c0e56586) SHA1(2abf93aef48af34f869b30f63c130513a97f86a3) ) /* unknown */
	ROM_LOAD( "mb7114h.12j",  0x0200, 0x0100, CRC(4c734b64) SHA1(7a122b643bad3e3586821980efff023a63e5a029) ) /* unknown */
	ROM_LOAD( "mmi-7603.13h", 0x0300, 0x0020, CRC(06bcda53) SHA1(fa69b77697bb12aa6012d82ef5b504d3a1d20232) ) /* unknown */
ROM_END

/*************************************
 *
 *  Game driver(s)
 *
 *************************************/
// Proyecto Shadows Mame Build Plus
/*    YEAR  NAME            PARENT    MACHINE        INPUT       INIT             MONITOR COMPANY                 FULLNAME FLAGS */
// 1943 Kai: Midway Kaisen
GAME( 1987, sfs01,   sf,  sfus, sfus, sf_state, 0, ROT0, "Hacks", "Street Fighter (US, set 1(PLus))", MACHINE_SUPPORTS_SAVE )
