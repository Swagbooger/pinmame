// license:LGPL
// copyright-holders:Nuke.YKT

/* Nuked OPM
 * Copyright (C) 2020 Nuke.YKT
 *
 * This file is part of Nuked OPM.
 *
 * Nuked OPM is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 2.1
 * of the License, or (at your option) any later version.
 *
 * Nuked OPM is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Nuked OPM. If not, see <https://www.gnu.org/licenses/>.
 *
 *  Nuked OPM emulator.
 *  Thanks:
 *      siliconpr0n.org(digshadow, John McMaster):
 *          YM2151 and other FM chip decaps and die shots.
 *
 * version: 0.9.2 beta
 */
#ifndef _OPM_H_
#define _OPM_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef PINMAME
#include "memory.h"

// from VGM port
#define OPN_WRITEBUF_SIZE 2048
#define OPN_WRITEBUF_DELAY 36

typedef struct {
    uint64_t time;
    uint8_t port;
    uint8_t data;
} opm_writebuf;
#endif

typedef struct {
    uint8_t cycles;
    bool ic;
    bool ic2;
    // IO
    uint8_t write_data;
    bool write_a;
    bool write_a_en;
    bool write_d;
    bool write_d_en;
    bool write_busy;
    uint8_t write_busy_cnt;
    uint8_t mode_address;
    bool io_ct1;
    bool io_ct2;

    // LFO
    uint8_t lfo_am_lock;
    uint8_t lfo_pm_lock;
    uint8_t lfo_counter1;
    uint8_t lfo_counter1_of1;
    bool lfo_counter1_of2;
    uint16_t lfo_counter2;
    bool lfo_counter2_load;
    bool lfo_counter2_of;
    bool lfo_counter2_of_lock;
    bool lfo_counter2_of_lock2;
    bool lfo_counter3_clock;
    uint16_t lfo_counter3;
    bool lfo_counter3_step;
    bool lfo_frq_update;
    bool lfo_clock;
    bool lfo_clock_lock;
    bool lfo_clock_test;
    bool lfo_test;
    uint32_t lfo_val;
    bool lfo_val_carry;
    uint32_t lfo_out1;
    uint32_t lfo_out2;
    uint32_t lfo_out2_b;
    bool lfo_mult_carry;
    bool lfo_trig_sign;
    bool lfo_saw_sign;
    uint8_t lfo_bit_counter;

    // Env Gen
    uint8_t eg_state[32];
    uint16_t eg_level[32];
    uint8_t eg_rate[2];
    uint8_t eg_sl[2];
    uint8_t eg_tl[3];
    bool eg_zr[2];
    uint8_t eg_timershift_lock;
    uint8_t eg_timer_lock;
    bool eg_inchi;
    uint8_t eg_shift;
    uint8_t eg_clock;
    uint8_t eg_clockcnt;
    //uint8_t eg_clockquotinent;
    uint8_t eg_inc;
    uint8_t eg_ratemax[2];
    bool eg_instantattack;
    bool eg_inclinear;
    bool eg_incattack;
    bool eg_mute;
    uint16_t eg_outtemp[2];
    uint16_t eg_out[2];
    uint16_t eg_am;
    //uint8_t eg_ams[2];
    bool eg_timercarry;
    uint32_t eg_timer;
    uint32_t eg_timer2;
    bool eg_timerbstop;
    uint32_t eg_serial;
    bool eg_serial_bit;
    bool eg_test;


    // Phase Gen
    uint16_t pg_fnum[32];
    uint8_t pg_kcode[32];
    uint32_t pg_inc[32];
    uint32_t pg_phase[32];
    bool pg_reset[32];
    bool pg_reset_latch[32];
    uint16_t pg_serial;

    // Operator
    uint16_t op_phase_in;
    uint16_t op_mod_in;
    uint16_t op_phase;
    uint16_t op_logsin[3];
    uint16_t op_atten;
    uint16_t op_exp[2];
    uint8_t op_pow[2];
    uint32_t op_sign;
    int16_t op_out[6];
    uint32_t op_connect;
    uint8_t op_counter;
    bool op_fbupdate;
    uint8_t op_fbshift;
    bool op_c1update;
    bool op_modtable[5];
    int16_t op_m1[8][2];
    int16_t op_c1[8];
    int16_t op_mod[3];
    int16_t op_fb[2];
    bool op_mixl;
    bool op_mixr;

    // Mixer

    int32_t mix[2];
    int32_t mix2[2];
    int32_t mix_op;
    uint32_t mix_serial[2];
    uint32_t mix_bits;
    uint8_t mix_top_bits_lock;
    bool mix_sign_lock;
    bool mix_sign_lock2;
    uint8_t mix_exp_lock;
    bool mix_clamp_low[2];
    bool mix_clamp_high[2];
    uint8_t mix_out_bit;

    // Output
    bool smp_so;
    bool smp_sh1;
    bool smp_sh2;

    // Noise
    uint32_t noise_lfsr;
    uint32_t noise_timer;
    bool noise_timer_of;
    bool noise_update;
    bool noise_temp;

    // Register set
    bool mode_test[8];
    bool mode_kon_operator[4];
    uint8_t mode_kon_channel;

    uint8_t reg_address;
    bool reg_address_ready;
    uint8_t reg_data;
    bool reg_data_ready;

    uint8_t ch_rl[8];
    uint8_t ch_fb[8];
    uint8_t ch_connect[8];
    uint8_t ch_kc[8];
    uint8_t ch_kf[8];
    uint8_t ch_pms[8];
    uint8_t ch_ams[8];

    uint8_t sl_dt1[32];
    uint8_t sl_mul[32];
    uint8_t sl_tl[32];
    uint8_t sl_ks[32];
    uint8_t sl_ar[32];
    bool sl_am_e[32];
    uint8_t sl_d1r[32];
    uint8_t sl_dt2[32];
    uint8_t sl_d2r[32];
    uint8_t sl_d1l[32];
    uint8_t sl_rr[32];

    bool noise_en;
    uint8_t noise_freq;


    // Timer
    uint16_t timer_a_reg;
    uint8_t timer_b_reg;
    bool timer_a_temp;
    bool timer_a_do_reset, timer_a_do_load;
    bool timer_a_inc;
    uint16_t timer_a_val;
    bool timer_a_of;
    bool timer_a_load;
    bool timer_a_status;

    uint8_t timer_b_sub;
    bool timer_b_sub_of;
    bool timer_b_inc;
    uint8_t timer_b_val;
    bool timer_b_of;
    bool timer_b_do_reset, timer_b_do_load;
    bool timer_b_temp;
    bool timer_b_status;
    bool timer_irq;

    uint8_t lfo_freq_hi;
    uint8_t lfo_freq_lo;
    uint8_t lfo_pmd;
    uint8_t lfo_amd;
    uint8_t lfo_wave;

    bool timer_irqa, timer_irqb;
    bool timer_loada, timer_loadb;
    bool timer_reseta, timer_resetb;
    bool mode_csm;

    bool nc_active, nc_active_lock, nc_sign, nc_sign_lock, nc_sign_lock2;
    //uint8_t nc_bit;
    uint16_t nc_out;
    int16_t op_mix;

    bool kon_csm, kon_csm_lock;
    //uint8_t kon_do;
    bool kon_chanmatch;
    bool kon[32];
    bool kon2[32];
    bool mode_kon[32];

    // DAC
    bool dac_osh1, dac_osh2;
    uint16_t dac_bits;
    int16_t dac_output[2];

#ifdef PINMAME
    // from VGM port
    uint64_t writebuf_samplecnt;
    uint32_t writebuf_cur;
    uint32_t writebuf_last;
    uint64_t writebuf_lasttime;
    opm_writebuf writebuf[OPN_WRITEBUF_SIZE];

    // PinMAME specific
    void(*irqhandler)(int irq);		/* IRQ function handler */
    mem_write_handler porthandler;	/* port write function handler */

    unsigned short vgm_idx;
#endif
} opm_t;

void OPM_Clock(opm_t *chip, int16_t *output, bool *sh1, bool *sh2, bool *so);
void OPM_Write(opm_t *chip, uint8_t port, uint8_t data);
uint8_t OPM_Read(const opm_t *chip, uint8_t port);
bool OPM_ReadIRQ(const opm_t *chip);
bool OPM_ReadCT1(const opm_t *chip);
bool OPM_ReadCT2(const opm_t *chip);
void OPM_SetIC(opm_t *chip, bool ic);
void OPM_Reset(opm_t *chip, double clock);
#ifdef PINMAME
void OPM_FlushBuffer(opm_t *chip);
void OPM_WriteBuffered(opm_t *chip, uint8_t port, uint8_t data);
void OPM_GenerateStream(opm_t *chip, float **sndptr, uint32_t numsamples);
void OPM_SetPortWriteHandler(opm_t *chip, mem_write_handler handler);
void OPM_SetIrqHandler(opm_t *chip, void(*handler)(int irq));
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif
