// license:BSD-3-Clause
// copyright-holders:AJR
/****************************************************************************

    Skeleton driver for ADM-31 terminal.

    The ADM-31 and ADM-42 Data Display Terminals were Lear Siegler, Inc.'s
    first microprocessor-based video terminals, introduced in 1978 as the
    respective successors to their earlier ADM-1A and ADM-2 "smart"
    terminals. The original ADM-31 model was apparently rebranded in 1980
    as the ADM-31 Intermediate Terminal, and the ADM-32 was released a few
    months later.

    While the ADM-31 and ADM-32 only support 2 pages of display memory, the
    ADM-42 could be upgraded to 8. Enhancements over the ADM-31 offered by
    both the ADM-42 and ADM-32 include a status line, a larger monitor and
    a detachable keyboard. Several other expansion options were offered for
    the ADM-42, including synchronous serial and parallel printer ports.

****************************************************************************/

#include "emu.h"
//#include "bus/rs232/rs232.h"
#include "cpu/m6800/m6800.h"
#include "machine/com8116.h"
#include "machine/input_merger.h"
#include "machine/6821pia.h"
#include "machine/6850acia.h"
#include "video/tms9927.h"
#include "screen.h"

class adm31_state : public driver_device
{
public:
	adm31_state(const machine_config &mconfig, device_type type, const char *tag)
		: driver_device(mconfig, type, tag)
		, m_maincpu(*this, "maincpu")
		, m_acia(*this, "acia%u", 1U)
		, m_brg(*this, "brg")
		, m_vtac(*this, "vtac")
		, m_chargen(*this, "chargen")
		, m_keys(*this, "R%u", 0U)
		, m_baud(*this, "BAUD")
		, m_caps_lamp(*this, "caps_lamp")
	{
	}

	void adm31(machine_config &mconfig);

protected:
	virtual void machine_start() override;
	virtual void machine_reset() override;

private:
	u32 screen_update(screen_device &screen, bitmap_rgb32 &bitmap, const rectangle &cliprect);

	void kbd_scan_w(u8 data);
	u8 kbd_scan_r();
	void kbd_status_w(u8 data);

	void mem_map(address_map &map);

	required_device<cpu_device> m_maincpu;
	required_device_array<acia6850_device, 2> m_acia;
	required_device<com8116_device> m_brg;
	required_device<crt5027_device> m_vtac;
	required_region_ptr<u8> m_chargen;
	optional_ioport_array<16> m_keys;
	required_ioport m_baud;
	output_finder<> m_caps_lamp;

	u8 m_kbd_scan;
};


void adm31_state::machine_start()
{
	m_caps_lamp.resolve();

	save_item(NAME(m_kbd_scan));
}

void adm31_state::machine_reset()
{
	// Baud rate switches read by CPU on ADM-42, but not on ADM-31?
	m_brg->stt_str_w(m_baud->read());
}


u32 adm31_state::screen_update(screen_device &screen, bitmap_rgb32 &bitmap, const rectangle &cliprect)
{
	return 0;
}


void adm31_state::kbd_scan_w(u8 data)
{
	m_kbd_scan = data & 0x7f;
}

u8 adm31_state::kbd_scan_r()
{
	return m_kbd_scan | (BIT(m_keys[(m_kbd_scan & 0x78) >> 3].read_safe(0xff), m_kbd_scan & 0x07) ? 0x00 : 0x80);
}

void adm31_state::kbd_status_w(u8 data)
{
	m_caps_lamp = BIT(data, 0);
}

void adm31_state::mem_map(address_map &map)
{
	map(0x0000, 0x03ff).ram();
	map(0x7000, 0x7000).nopw();
	map(0x7800, 0x7803).rw("pia", FUNC(pia6821_device::read), FUNC(pia6821_device::write));
	map(0x7900, 0x7900).portr("S5");
	map(0x7a00, 0x7a01).rw(m_acia[0], FUNC(acia6850_device::read), FUNC(acia6850_device::write));
	map(0x7c00, 0x7c01).rw(m_acia[1], FUNC(acia6850_device::read), FUNC(acia6850_device::write));
	map(0x7d00, 0x7d00).portr("S6");
	map(0x7e00, 0x7e00).portr("S4");
	map(0x7f00, 0x7f0f).rw(m_vtac, FUNC(crt5027_device::read), FUNC(crt5027_device::write));
	map(0x8000, 0x8fff).ram();
	map(0xe000, 0xffff).rom().region("program", 0);
}


static INPUT_PORTS_START(adm31)
	PORT_START("R0")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Key D1")
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Key D7")
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Key C5")
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Key D2")
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Key D4/F4")
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Key D9/F9")
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('2') PORT_CHAR('"') PORT_CODE(KEYCODE_2)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Esc") PORT_CHAR(0x1b) PORT_CODE(KEYCODE_F7)

	PORT_START("R1")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Rub") PORT_CHAR(0x7f) PORT_CODE(KEYCODE_F8)
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Key 9E/9F")
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Key D0/F0")
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Key B4/B6")
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Key 92/93")
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('1') PORT_CHAR('!') PORT_CODE(KEYCODE_1)
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('q') PORT_CHAR('Q') PORT_CODE(KEYCODE_Q)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Cap Lock") PORT_CHAR(UCHAR_MAMEKEY(CAPSLOCK)) PORT_CODE(KEYCODE_CAPSLOCK)

	PORT_START("R2")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('3') PORT_CHAR('#') PORT_CODE(KEYCODE_3)
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('4') PORT_CHAR('$') PORT_CODE(KEYCODE_4)
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('5') PORT_CHAR('%') PORT_CODE(KEYCODE_5)
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('6') PORT_CHAR('&') PORT_CODE(KEYCODE_6)
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('7') PORT_CHAR('\'') PORT_CODE(KEYCODE_7)
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('8') PORT_CHAR('(') PORT_CODE(KEYCODE_8)
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('9') PORT_CHAR(')') PORT_CODE(KEYCODE_9)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('0') PORT_CHAR('_') PORT_CODE(KEYCODE_0)

	PORT_START("R3")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('-') PORT_CHAR('=') PORT_CODE(KEYCODE_MINUS)
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('^') PORT_CHAR('~') PORT_CODE(KEYCODE_EQUALS)
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('\\') PORT_CHAR('|') PORT_CODE(KEYCODE_BACKSLASH)
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Tab  Back Tab") PORT_CHAR(0x09) PORT_CODE(KEYCODE_BACKSPACE)
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(UCHAR_MAMEKEY(7_PAD)) PORT_CODE(KEYCODE_7_PAD)
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(UCHAR_MAMEKEY(8_PAD)) PORT_CODE(KEYCODE_8_PAD)
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(UCHAR_MAMEKEY(9_PAD)) PORT_CODE(KEYCODE_9_PAD)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(UCHAR_MAMEKEY(MINUS_PAD)) PORT_CODE(KEYCODE_MINUS_PAD)

	PORT_START("R4")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('w') PORT_CHAR('W') PORT_CODE(KEYCODE_W)
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('e') PORT_CHAR('E') PORT_CODE(KEYCODE_E)
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('r') PORT_CHAR('R') PORT_CODE(KEYCODE_R)
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('t') PORT_CHAR('T') PORT_CODE(KEYCODE_T)
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('y') PORT_CHAR('Y') PORT_CODE(KEYCODE_Y)
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('u') PORT_CHAR('U') PORT_CODE(KEYCODE_U)
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('i') PORT_CHAR('I') PORT_CODE(KEYCODE_I)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('o') PORT_CHAR('O') PORT_CODE(KEYCODE_O)

	PORT_START("R5")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('p') PORT_CHAR('P') PORT_CODE(KEYCODE_P)
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('[') PORT_CHAR('{') PORT_CODE(KEYCODE_OPENBRACE)
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(']') PORT_CHAR('}') PORT_CODE(KEYCODE_CLOSEBRACE)
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Return") PORT_CHAR(0x0d) PORT_CODE(KEYCODE_ENTER)
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(UCHAR_MAMEKEY(4_PAD)) PORT_CODE(KEYCODE_4_PAD)
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(UCHAR_MAMEKEY(5_PAD)) PORT_CODE(KEYCODE_5_PAD)
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(UCHAR_MAMEKEY(6_PAD)) PORT_CODE(KEYCODE_6_PAD)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(UCHAR_MAMEKEY(TAB_PAD)) PORT_CODE(KEYCODE_PLUS_PAD)

	PORT_START("R6")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('a') PORT_CHAR('A') PORT_CODE(KEYCODE_A)
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('s') PORT_CHAR('S') PORT_CODE(KEYCODE_S)
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('d') PORT_CHAR('D') PORT_CODE(KEYCODE_D)
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('f') PORT_CHAR('F') PORT_CODE(KEYCODE_F)
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('g') PORT_CHAR('G') PORT_CODE(KEYCODE_G)
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('h') PORT_CHAR('H') PORT_CODE(KEYCODE_H)
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('j') PORT_CHAR('J') PORT_CODE(KEYCODE_J)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('k') PORT_CHAR('K') PORT_CODE(KEYCODE_K)

	PORT_START("R7")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('l') PORT_CHAR('L') PORT_CODE(KEYCODE_L)
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(';') PORT_CHAR('+') PORT_CODE(KEYCODE_COLON)
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(':') PORT_CHAR('*') PORT_CODE(KEYCODE_QUOTE)
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('@') PORT_CHAR('`') PORT_CODE(KEYCODE_TILDE)
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Line Feed") PORT_CHAR(0x0a) PORT_CODE(KEYCODE_RCONTROL)
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(UCHAR_MAMEKEY(2_PAD)) PORT_CODE(KEYCODE_2_PAD)
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(UCHAR_MAMEKEY(3_PAD)) PORT_CODE(KEYCODE_3_PAD)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(UCHAR_MAMEKEY(1_PAD)) PORT_CODE(KEYCODE_1_PAD)

	PORT_START("R8")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Clear") PORT_CODE(KEYCODE_LALT)
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('z') PORT_CHAR('Z') PORT_CODE(KEYCODE_Z)
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('x') PORT_CHAR('X') PORT_CODE(KEYCODE_X)
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('c') PORT_CHAR('C') PORT_CODE(KEYCODE_C)
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('v') PORT_CHAR('V') PORT_CODE(KEYCODE_V)
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('b') PORT_CHAR('B') PORT_CODE(KEYCODE_B)
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('n') PORT_CHAR('N') PORT_CODE(KEYCODE_N)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('m') PORT_CHAR('M') PORT_CODE(KEYCODE_M)

	PORT_START("R9")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(',') PORT_CHAR('<') PORT_CODE(KEYCODE_COMMA)
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('.') PORT_CHAR('>') PORT_CODE(KEYCODE_STOP)
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR('/') PORT_CHAR('?') PORT_CODE(KEYCODE_SLASH)
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(' ') PORT_CODE(KEYCODE_SPACE)
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("New Line  New Page") PORT_CODE(KEYCODE_END)
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(UCHAR_MAMEKEY(0_PAD)) PORT_CODE(KEYCODE_0_PAD)
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(UCHAR_MAMEKEY(DEL_PAD)) PORT_CODE(KEYCODE_DEL_PAD)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Keypad Return") PORT_CHAR(UCHAR_MAMEKEY(ENTER_PAD)) PORT_CODE(KEYCODE_ENTER_PAD)

	PORT_START("R10")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Key 9D/94")
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(UCHAR_MAMEKEY(HOME)) PORT_CODE(KEYCODE_HOME)
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(UCHAR_MAMEKEY(DOWN)) PORT_CODE(KEYCODE_DOWN)
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(UCHAR_MAMEKEY(UP)) PORT_CODE(KEYCODE_UP)
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(UCHAR_MAMEKEY(LEFT)) PORT_CODE(KEYCODE_LEFT)
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(UCHAR_MAMEKEY(RIGHT)) PORT_CODE(KEYCODE_RIGHT)
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Key E3/40")
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CHAR(UCHAR_MAMEKEY(COMMA_PAD)) PORT_CODE(KEYCODE_COMMA_PAD)

	PORT_START("SHIFT")
	PORT_BIT(0x02, IP_ACTIVE_HIGH, IPT_UNKNOWN)
	PORT_BIT(0x20, IP_ACTIVE_HIGH, IPT_UNKNOWN)
	PORT_BIT(0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD) PORT_NAME("Ctrl") PORT_CHAR(UCHAR_SHIFT_2) PORT_CODE(KEYCODE_LCONTROL)
	PORT_BIT(0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD) PORT_NAME("Shift") PORT_CHAR(UCHAR_SHIFT_1) PORT_CODE(KEYCODE_LSHIFT) PORT_CODE(KEYCODE_RSHIFT)
	PORT_BIT(0x1d, IP_ACTIVE_LOW, IPT_UNUSED)

	PORT_START("S4")
	PORT_DIPNAME(0x01, 0x00, "Break Key") PORT_DIPLOCATION("S4:1")
	PORT_DIPSETTING(0x01, "Disable")
	PORT_DIPSETTING(0x00, "Enable")
	PORT_DIPNAME(0x02, 0x02, "Refresh Rate") PORT_DIPLOCATION("S4:2")
	PORT_DIPSETTING(0x00, "50 Hz")
	PORT_DIPSETTING(0x02, "60 Hz")
	PORT_DIPNAME(0x1c, 0x14, "Modem Port") PORT_DIPLOCATION("S4:3,4,5")
	PORT_DIPSETTING(0x00, "7 DB, EP, 2 SB")
	PORT_DIPSETTING(0x04, "7 DB, OP, 2 SB")
	PORT_DIPSETTING(0x08, "7 DB, EP, 1 SB")
	PORT_DIPSETTING(0x0c, "7 DB, OP, 1 SB")
	PORT_DIPSETTING(0x10, "8 DB, NP, 2 SB")
	PORT_DIPSETTING(0x14, "8 DB, NP, 1 SB")
	PORT_DIPSETTING(0x18, "8 DB, EP, 1 SB")
	PORT_DIPSETTING(0x00, "8 DB, OP, 1 SB")
	PORT_DIPNAME(0x20, 0x00, DEF_STR(Unused)) PORT_DIPLOCATION("S4:6")
	PORT_DIPSETTING(0x20, DEF_STR(Off))
	PORT_DIPSETTING(0x00, DEF_STR(On))
	PORT_DIPNAME(0x40, 0x00, "Transmission") PORT_DIPLOCATION("S4:7")
	PORT_DIPSETTING(0x00, "Block Mode")
	PORT_DIPSETTING(0x40, "Conversation Mode")
	PORT_DIPNAME(0x80, 0x00, "Duplex") PORT_DIPLOCATION("S4:8")
	PORT_DIPSETTING(0x00, "Full Duplex")
	PORT_DIPSETTING(0x80, "Half Duplex")

	PORT_START("S5")
	PORT_DIPNAME(0x01, 0x00, DEF_STR(Unused)) PORT_DIPLOCATION("S5:1")
	PORT_DIPSETTING(0x01, DEF_STR(Off))
	PORT_DIPSETTING(0x00, DEF_STR(On))
	PORT_DIPNAME(0x02, 0x00, DEF_STR(Unused)) PORT_DIPLOCATION("S5:2")
	PORT_DIPSETTING(0x02, DEF_STR(Off))
	PORT_DIPSETTING(0x00, DEF_STR(On))
	PORT_DIPNAME(0x1c, 0x14, "Printer Port") PORT_DIPLOCATION("S5:3,4,5")
	PORT_DIPSETTING(0x00, "7 DB, EP, 2 SB")
	PORT_DIPSETTING(0x04, "7 DB, OP, 2 SB")
	PORT_DIPSETTING(0x08, "7 DB, EP, 1 SB")
	PORT_DIPSETTING(0x0c, "7 DB, OP, 1 SB")
	PORT_DIPSETTING(0x10, "8 DB, NP, 2 SB")
	PORT_DIPSETTING(0x14, "8 DB, NP, 1 SB")
	PORT_DIPSETTING(0x18, "8 DB, EP, 1 SB")
	PORT_DIPSETTING(0x00, "8 DB, OP, 1 SB")
	PORT_DIPNAME(0x20, 0x00, DEF_STR(Unused)) PORT_DIPLOCATION("S5:6")
	PORT_DIPSETTING(0x20, DEF_STR(Off))
	PORT_DIPSETTING(0x00, DEF_STR(On))
	PORT_DIPNAME(0x40, 0x00, DEF_STR(Unused)) PORT_DIPLOCATION("S5:7")
	PORT_DIPSETTING(0x40, DEF_STR(Off))
	PORT_DIPSETTING(0x00, DEF_STR(On))
	PORT_DIPNAME(0x80, 0x00, "Printer Port Buffer") PORT_DIPLOCATION("S5:8")
	PORT_DIPSETTING(0x80, "Disable")
	PORT_DIPSETTING(0x00, "Enable")

	PORT_START("S6")
	PORT_DIPNAME(0x7f, 0x00, "Polling Address") PORT_DIPLOCATION("S6:1,2,3,4,5,6,7")
	PORT_DIPSETTING(0x00, "00")
	PORT_DIPSETTING(0x01, "01")
	PORT_DIPSETTING(0x02, "02")
	PORT_DIPSETTING(0x03, "03")
	PORT_DIPSETTING(0x04, "04")
	PORT_DIPSETTING(0x05, "05")
	PORT_DIPSETTING(0x06, "06")
	PORT_DIPSETTING(0x07, "07")
	PORT_DIPSETTING(0x08, "08")
	PORT_DIPSETTING(0x09, "09")
	PORT_DIPSETTING(0x0a, "0A")
	PORT_DIPSETTING(0x0b, "0B")
	PORT_DIPSETTING(0x0c, "0C")
	PORT_DIPSETTING(0x0d, "0D")
	PORT_DIPSETTING(0x0e, "0E")
	PORT_DIPSETTING(0x0f, "0F")
	PORT_DIPSETTING(0x10, "10")
	PORT_DIPSETTING(0x11, "11")
	PORT_DIPSETTING(0x12, "12")
	PORT_DIPSETTING(0x13, "13")
	PORT_DIPSETTING(0x14, "14")
	PORT_DIPSETTING(0x15, "15")
	PORT_DIPSETTING(0x16, "16")
	PORT_DIPSETTING(0x17, "17")
	PORT_DIPSETTING(0x18, "18")
	PORT_DIPSETTING(0x19, "19")
	PORT_DIPSETTING(0x1a, "1A")
	PORT_DIPSETTING(0x1b, "1B")
	PORT_DIPSETTING(0x1c, "1C")
	PORT_DIPSETTING(0x1d, "1D")
	PORT_DIPSETTING(0x1e, "1E")
	PORT_DIPSETTING(0x1f, "1F")
	PORT_DIPSETTING(0x20, "20")
	PORT_DIPSETTING(0x21, "21")
	PORT_DIPSETTING(0x22, "22")
	PORT_DIPSETTING(0x23, "23")
	PORT_DIPSETTING(0x24, "24")
	PORT_DIPSETTING(0x25, "25")
	PORT_DIPSETTING(0x26, "26")
	PORT_DIPSETTING(0x27, "27")
	PORT_DIPSETTING(0x28, "28")
	PORT_DIPSETTING(0x29, "29")
	PORT_DIPSETTING(0x2a, "2A")
	PORT_DIPSETTING(0x2b, "2B")
	PORT_DIPSETTING(0x2c, "2C")
	PORT_DIPSETTING(0x2d, "2D")
	PORT_DIPSETTING(0x2e, "2E")
	PORT_DIPSETTING(0x2f, "2F")
	PORT_DIPSETTING(0x30, "30")
	PORT_DIPSETTING(0x31, "31")
	PORT_DIPSETTING(0x32, "32")
	PORT_DIPSETTING(0x33, "33")
	PORT_DIPSETTING(0x34, "34")
	PORT_DIPSETTING(0x35, "35")
	PORT_DIPSETTING(0x36, "36")
	PORT_DIPSETTING(0x37, "37")
	PORT_DIPSETTING(0x38, "38")
	PORT_DIPSETTING(0x39, "39")
	PORT_DIPSETTING(0x3a, "3A")
	PORT_DIPSETTING(0x3b, "3B")
	PORT_DIPSETTING(0x3c, "3C")
	PORT_DIPSETTING(0x3d, "3D")
	PORT_DIPSETTING(0x3e, "3E")
	PORT_DIPSETTING(0x3f, "3F")
	PORT_DIPSETTING(0x40, "40")
	PORT_DIPSETTING(0x41, "41")
	PORT_DIPSETTING(0x42, "42")
	PORT_DIPSETTING(0x43, "43")
	PORT_DIPSETTING(0x44, "44")
	PORT_DIPSETTING(0x45, "45")
	PORT_DIPSETTING(0x46, "46")
	PORT_DIPSETTING(0x47, "47")
	PORT_DIPSETTING(0x48, "48")
	PORT_DIPSETTING(0x49, "49")
	PORT_DIPSETTING(0x4a, "4A")
	PORT_DIPSETTING(0x4b, "4B")
	PORT_DIPSETTING(0x4c, "4C")
	PORT_DIPSETTING(0x4d, "4D")
	PORT_DIPSETTING(0x4e, "4E")
	PORT_DIPSETTING(0x4f, "4F")
	PORT_DIPSETTING(0x50, "50")
	PORT_DIPSETTING(0x51, "51")
	PORT_DIPSETTING(0x52, "52")
	PORT_DIPSETTING(0x53, "53")
	PORT_DIPSETTING(0x54, "54")
	PORT_DIPSETTING(0x55, "55")
	PORT_DIPSETTING(0x56, "56")
	PORT_DIPSETTING(0x57, "57")
	PORT_DIPSETTING(0x58, "58")
	PORT_DIPSETTING(0x59, "59")
	PORT_DIPSETTING(0x5a, "5A")
	PORT_DIPSETTING(0x5b, "5B")
	PORT_DIPSETTING(0x5c, "5C")
	PORT_DIPSETTING(0x5d, "5D")
	PORT_DIPSETTING(0x5e, "5E")
	PORT_DIPSETTING(0x5f, "5F")
	PORT_DIPSETTING(0x60, "60")
	PORT_DIPSETTING(0x61, "61")
	PORT_DIPSETTING(0x62, "62")
	PORT_DIPSETTING(0x63, "63")
	PORT_DIPSETTING(0x64, "64")
	PORT_DIPSETTING(0x65, "65")
	PORT_DIPSETTING(0x66, "66")
	PORT_DIPSETTING(0x67, "67")
	PORT_DIPSETTING(0x68, "68")
	PORT_DIPSETTING(0x69, "69")
	PORT_DIPSETTING(0x6a, "6A")
	PORT_DIPSETTING(0x6b, "6B")
	PORT_DIPSETTING(0x6c, "6C")
	PORT_DIPSETTING(0x6d, "6D")
	PORT_DIPSETTING(0x6e, "6E")
	PORT_DIPSETTING(0x6f, "6F")
	PORT_DIPSETTING(0x70, "70")
	PORT_DIPSETTING(0x71, "71")
	PORT_DIPSETTING(0x72, "72")
	PORT_DIPSETTING(0x73, "73")
	PORT_DIPSETTING(0x74, "74")
	PORT_DIPSETTING(0x75, "75")
	PORT_DIPSETTING(0x76, "76")
	PORT_DIPSETTING(0x77, "77")
	PORT_DIPSETTING(0x78, "78")
	PORT_DIPSETTING(0x79, "79")
	PORT_DIPSETTING(0x7a, "7A")
	PORT_DIPSETTING(0x7b, "7B")
	PORT_DIPSETTING(0x7c, "7C")
	PORT_DIPSETTING(0x7d, "7D")
	PORT_DIPSETTING(0x7e, "7E")
	PORT_DIPSETTING(0x7f, "7F")
	PORT_DIPNAME(0x80, 0x80, "Polling Option") PORT_DIPLOCATION("S6:8")
	PORT_DIPSETTING(0x80, "Disable")
	PORT_DIPSETTING(0x00, "Enable")

	PORT_START("BAUD")
	PORT_DIPNAME(0x0f, 0x0e, "Modem Baud Rate") PORT_DIPLOCATION("BS1:1,2,3,4")
	PORT_DIPSETTING(0x00, "50")
	PORT_DIPSETTING(0x01, "75")
	PORT_DIPSETTING(0x02, "110")
	PORT_DIPSETTING(0x03, "134.5")
	PORT_DIPSETTING(0x04, "150")
	PORT_DIPSETTING(0x05, "300")
	PORT_DIPSETTING(0x06, "600")
	PORT_DIPSETTING(0x07, "1200")
	PORT_DIPSETTING(0x08, "1800")
	PORT_DIPSETTING(0x09, "2000")
	PORT_DIPSETTING(0x0a, "2400")
	PORT_DIPSETTING(0x0b, "3600")
	PORT_DIPSETTING(0x0c, "4800")
	PORT_DIPSETTING(0x0d, "7200")
	PORT_DIPSETTING(0x0e, "9600")
	PORT_DIPNAME(0xf0, 0x70, "Printer Baud Rate") PORT_DIPLOCATION("BS2:1,2,3,4")
	PORT_DIPSETTING(0x00, "50")
	PORT_DIPSETTING(0x10, "75")
	PORT_DIPSETTING(0x20, "110")
	PORT_DIPSETTING(0x30, "134.5")
	PORT_DIPSETTING(0x40, "150")
	PORT_DIPSETTING(0x50, "300")
	PORT_DIPSETTING(0x60, "600")
	PORT_DIPSETTING(0x70, "1200")
	PORT_DIPSETTING(0x80, "1800")
	PORT_DIPSETTING(0x90, "2000")
	PORT_DIPSETTING(0xa0, "2400")
	PORT_DIPSETTING(0xb0, "3600")
	PORT_DIPSETTING(0xc0, "4800")
	PORT_DIPSETTING(0xd0, "7200")
	PORT_DIPSETTING(0xe0, "9600")
INPUT_PORTS_END

void adm31_state::adm31(machine_config &config)
{
	M6800(config, m_maincpu, 19.584_MHz_XTAL / 20);
	m_maincpu->set_addrmap(AS_PROGRAM, &adm31_state::mem_map);

	INPUT_MERGER_ANY_HIGH(config, "mainirq").output_handler().set_inputline(m_maincpu, M6800_IRQ_LINE);

	pia6821_device &pia(PIA6821(config, "pia"));
	pia.writepa_handler().set(FUNC(adm31_state::kbd_scan_w));
	pia.readpa_handler().set(FUNC(adm31_state::kbd_scan_r));
	pia.writepb_handler().set(FUNC(adm31_state::kbd_status_w));
	pia.readpb_handler().set_ioport("SHIFT");

	ACIA6850(config, m_acia[0]);
	m_acia[0]->irq_handler().set("mainirq", FUNC(input_merger_device::in_w<0>));

	ACIA6850(config, m_acia[1]);
	m_acia[0]->irq_handler().set("mainirq", FUNC(input_merger_device::in_w<1>));

	COM8116(config, m_brg, 5.0688_MHz_XTAL);
	m_brg->fr_handler().set(m_acia[0], FUNC(acia6850_device::write_rxc));
	m_brg->fr_handler().append(m_acia[0], FUNC(acia6850_device::write_txc));
	m_brg->ft_handler().set(m_acia[1], FUNC(acia6850_device::write_rxc));
	m_brg->ft_handler().append(m_acia[1], FUNC(acia6850_device::write_txc));

	screen_device &screen(SCREEN(config, "screen", SCREEN_TYPE_RASTER));
	screen.set_raw(19.584_MHz_XTAL, 1020, 0, 800, 320, 0, 288);
	screen.set_screen_update(FUNC(adm31_state::screen_update));

	CRT5027(config, m_vtac, 19.584_MHz_XTAL / 10);
	m_vtac->set_screen("screen");
	m_vtac->set_char_width(10);
}


ROM_START(adm31)
	ROM_REGION(0x2000, "program", 0)
	ROM_LOAD("adm-31-u62.bin", 0x0000, 0x0800, CRC(57e557a5) SHA1(cb3021ab570c279cbaa673b5de8fa1ca9eb48188))
	ROM_LOAD("adm-31-u63.bin", 0x0800, 0x0800, CRC(1268a59c) SHA1(f0cd8562e0d5faebf84d8decaa848ff28f2ac637))
	ROM_LOAD("adm-31-u64.bin", 0x1000, 0x0800, CRC(8939fa00) SHA1(00f6a8a49e51a9501cd9d1e2aae366fb070a5a1d))
	ROM_LOAD("adm-31-u65.bin", 0x1800, 0x0800, CRC(53e4e2f1) SHA1(bf30241815c790de3354e1acfe84e760c889cbb1))

	ROM_REGION(0x0800, "chargen", 0)
	ROM_LOAD("chargen.bin", 0x0000, 0x0800, NO_DUMP)
ROM_END


COMP(1978, adm31, 0, 0, adm31, adm31, adm31_state, empty_init, "Lear Siegler", "ADM-31 Data Display Terminal", MACHINE_IS_SKELETON)
