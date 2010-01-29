/* audiotest_def.h - native audio test application header
 *
 * Based on native pcm test application platform/system/extras/sound/playwav.c
 *
 * Copyright (C) 2008 The Android Open Source Project
 * Copyright (c) 2009-2010, Code Aurora Forum. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef AUDIOTEST_DEFS_H
#define AUDIOTEST_DEFS_H

#include <pthread.h>
#if defined(QC_PROP) && defined(AUDIOV2)
#include "control.h"
#else
	#define msm_mixer_count() (-EPERM)
	#define msm_mixer_open(name, card) (-EPERM)
	#define msm_mixer_close() (-EPERM)
	#define msm_get_device(name) (-EPERM)
	#define msm_en_device(dev_id, set) (-EPERM)
	#define msm_route_stream(dir, dec_id, dev_id, set) (-EPERM)
	#define msm_route_voice(tx, rx, set) (-EPERM)
	#define msm_set_volume(dec_id, vol) (-EPERM)
	#define msm_get_device_class(device_id) (-EPERM)
	#define msm_get_device_capability(device_id) (-EPERM)
	#define msm_get_device_list(name) (-EPERM)
#endif

#define AUDIOTEST_TEST_MOD_PCM_DEC    0
#define AUDIOTEST_TEST_MOD_PCM_ENC    1
#define AUDIOTEST_TEST_MOD_MP3_DEC    2
#define AUDIOTEST_TEST_MOD_AAC_DEC    3
#define AUDIOTEST_TEST_MOD_AAC_ENC    4
#define AUDIOTEST_TEST_MOD_AMRNB_DEC  5
#define AUDIOTEST_TEST_MOD_AMRNB_ENC  6
#define AUDIOTEST_TEST_MOD_QCP_DEC    7
#define AUDIOTEST_TEST_MOD_IMAGE_SWAP 8 /*NOT USED ANYMORE */
#define AUDIOTEST_TEST_MOD_WMA_DEC    9
#define AUDIOTEST_TEST_MOD_VOICEMEMO  10
#define AUDIOTEST_TEST_MOD_PROFILE    11
#define AUDIOTEST_TEST_MOD_AMRWB_DEC    12
#define AUDIOTEST_TEST_MOD_WMAPRO_DEC 13
#define AUDIOTEST_TEST_MOD_ADPCM_DEC  14
#define AUDIOTEST_TEST_MOD_VOICE_ENC  15
#define AUDIOTEST_TEST_MOD_DEVMGR     16
/* If added new module, need to update this number */
#define AUDIOTEST_MAX_TEST_MOD 17

#define false 0
#define true (!false)

struct audtest_aac_config_type {
  unsigned short format_type;
  unsigned short object_type;
  unsigned short sbr_flag;
  unsigned short sbr_ps_flag;
};

union audtest_fmt_config_type {
  struct audtest_aac_config_type aac;
};

struct audtest_config {
  const char     *file_name;
  unsigned       sample_rate;
  unsigned short channel_mode;
  unsigned short rec_codec_type; /* Recording type */
  union audtest_fmt_config_type 
                 fmt_config;
  void           *private_data; /* given to individual test module 
                                   to store its private data */
};

struct audio_pvt_data {
  int afd;
  int mode; /* tunnel, non-tunnel */
  int recsize;
  int flush_enable;
  int start_ptr;
  int suspend;
  int frame_count;
  int quit;	
  unsigned avail;
  unsigned org_avail;
  int datareqthr;
  int channels;
  int bps;
  int freq;
  int encopt;
  int bits;
  char *recbuf;
  char *next;
  char *org_next;
  const char *outfile;
  int outport_flush_enable;
  int formattag;	/* WMAPRO specific parameters */
  int channelmask;
  int bitspersample;
  int asfpacketlength;
  int advancedencodeopt;
  int advancedencodeopt2;
};

struct audiotest_thread_context {
	int                     cxt_id;	/* specify by the client */
	pthread_t               thread;
	struct audtest_config   config;
	unsigned char           type;
	unsigned int            used; 
};

/* Function prototype that each test module would 
   provide for playback control commands  */
typedef int (*pb_control_func)(void* private_data);

/* Function prototype that each test module would
   provide for parsing of test case and paramter */
typedef int (*case_hd_func)(void);   

typedef void (*case_help_menu)(void);

typedef void (*case_deinit)(void);
/* Thread context management functions  */
struct audiotest_thread_context* get_free_context(void);
void free_context(struct audiotest_thread_context *context);
#ifdef AUDIOV2
extern int enable_device_tx(const char *device_name);
extern int disable_device_tx(int device_id);
extern int enable_device_rx(const char *device_name);
extern int disable_device_rx(int device_id);
#endif
#endif /* AUDIOTEST_DEFS_H */
