// license:BSD-3-Clause
// copyright-holders:Frank Palazzolo
/****************************************************************************

    Sega "Space Tactics" Driver

    Frank Palazzolo (palazzol@home.com)

****************************************************************************/


#include "machine/74259.h"

class stactics_state : public driver_device
{
public:
	stactics_state(const machine_config &mconfig, device_type type, const char *tag)
		: driver_device(mconfig, type, tag),
		m_maincpu(*this, "maincpu"),
		m_outlatch(*this, "outlatch"),
		m_display_buffer(*this, "display_buffer"),
		m_videoram_b(*this, "videoram_b"),
		m_videoram_d(*this, "videoram_d"),
		m_videoram_e(*this, "videoram_e"),
		m_videoram_f(*this, "videoram_f") { }

	required_device<cpu_device> m_maincpu;
	required_device<ls259_device> m_outlatch;

	required_shared_ptr<uint8_t> m_display_buffer;
	required_shared_ptr<uint8_t> m_videoram_b;
	required_shared_ptr<uint8_t> m_videoram_d;
	required_shared_ptr<uint8_t> m_videoram_e;
	required_shared_ptr<uint8_t> m_videoram_f;

	/* machine state */
	int    m_vert_pos;
	int    m_horiz_pos;
	bool   m_motor_on;

	/* video state */
	uint8_t  m_y_scroll_d;
	uint8_t  m_y_scroll_e;
	uint8_t  m_y_scroll_f;
	uint8_t  m_frame_count;
	uint8_t  m_shot_standby;
	uint8_t  m_shot_arrive;
	uint16_t m_beam_state;
	uint16_t m_old_beam_state;
	uint16_t m_beam_states_per_frame;
	uint8_t  m_palette_bank;

	DECLARE_READ8_MEMBER(vert_pos_r);
	DECLARE_READ8_MEMBER(horiz_pos_r);
	DECLARE_WRITE_LINE_MEMBER(coin_lockout_1_w);
	DECLARE_WRITE_LINE_MEMBER(coin_lockout_2_w);
	DECLARE_WRITE_LINE_MEMBER(palette_bank_w);
	DECLARE_WRITE8_MEMBER(scroll_ram_w);
	DECLARE_WRITE8_MEMBER(speed_latch_w);
	DECLARE_WRITE8_MEMBER(shot_trigger_w);
	DECLARE_WRITE8_MEMBER(shot_flag_clear_w);
	DECLARE_WRITE_LINE_MEMBER(motor_w);

	DECLARE_CUSTOM_INPUT_MEMBER(get_frame_count_d3);
	DECLARE_CUSTOM_INPUT_MEMBER(get_shot_standby);
	DECLARE_CUSTOM_INPUT_MEMBER(get_not_shot_arrive);
	DECLARE_CUSTOM_INPUT_MEMBER(get_motor_not_ready);
	DECLARE_CUSTOM_INPUT_MEMBER(get_rng);
	INTERRUPT_GEN_MEMBER(interrupt);

	DECLARE_WRITE_LINE_MEMBER(barrier_lamp_w);
	DECLARE_WRITE_LINE_MEMBER(start_lamp_w);
	DECLARE_WRITE_LINE_MEMBER(base_1_lamp_w);
	DECLARE_WRITE_LINE_MEMBER(base_2_lamp_w);
	DECLARE_WRITE_LINE_MEMBER(base_3_lamp_w);
	DECLARE_WRITE_LINE_MEMBER(base_4_lamp_w);
	DECLARE_WRITE_LINE_MEMBER(base_5_lamp_w);

	virtual void machine_start() override;
	virtual void video_start() override;
	DECLARE_PALETTE_INIT(stactics);

	uint32_t screen_update(screen_device &screen, bitmap_ind16 &bitmap, const rectangle &cliprect);
	void update_beam();
	inline int get_pixel_on_plane(uint8_t *videoram, uint8_t y, uint8_t x, uint8_t y_scroll);
	void draw_background(bitmap_ind16 &bitmap, const rectangle &cliprect);
	void set_indicator_leds(int data, const char *output_name, int base_index);
	void update_artwork();
	void move_motor();
	void stactics(machine_config &config);
	void stactics_video(machine_config &config);
	void main_map(address_map &map);
};
