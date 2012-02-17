AM_CFLAGS = -Wundef \
        -Wstrict-prototypes \
        -Wno-trigraphs \
        -g -O0 \
        -fno-inline \
        -fno-short-enums \
        -fpic

AM_CPPFLAGS = -I.

c_sources = alsa_mixer.c \
            alsa_pcm.c \
            alsa_ucm.c

h_sources = alsa_ucm.h \
            msm8960_use_cases.h \
            alsa_audio.h

library_includedir = $(pkgincludedir)
library_include_HEADERS = $(h_sources)

lib_LTLIBRARIES = libalsa_intf.la
libalsa_intf_la_CC = @CC@
libalsa_intf_la_SOURCES = $(c_sources) $(h_sources)
libalsa_intfdir = $(prefix)/snd_soc_msm
dist_libalsa_intf_DATA    = snd_soc_msm/DL_REC \
                            snd_soc_msm/DL_REC_2x \
                            snd_soc_msm/DL_REC_2x_Fusion3 \
                            snd_soc_msm/DL_REC_Sitar \
                            snd_soc_msm/FM_A2DP_REC \
                            snd_soc_msm/FM_A2DP_REC_2x \
                            snd_soc_msm/FM_A2DP_REC_2x_Fusion3 \
                            snd_soc_msm/FM_A2DP_REC_Sitar \
                            snd_soc_msm/FM_Digital_Radio \
                            snd_soc_msm/FM_Digital_Radio_2x \
                            snd_soc_msm/FM_Digital_Radio_2x_Fusion3 \
                            snd_soc_msm/FM_Digital_Radio_Sitar \
                            snd_soc_msm/FM_REC \
                            snd_soc_msm/FM_REC_2x \
                            snd_soc_msm/FM_REC_2x_Fusion3 \
                            snd_soc_msm/FM_REC_Sitar \
                            snd_soc_msm/HiFi \
                            snd_soc_msm/HiFi_2x \
                            snd_soc_msm/HiFi_2x_Fusion3 \
                            snd_soc_msm/HiFi_Low_Power \
                            snd_soc_msm/HiFi_Low_Power_2x \
                            snd_soc_msm/HiFi_Low_Power_2x_Fusion3 \
                            snd_soc_msm/HiFi_Low_Power_Sitar \
                            snd_soc_msm/HiFi_Rec \
                            snd_soc_msm/HiFi_Rec_2x \
                            snd_soc_msm/HiFi_Rec_2x_Fusion3 \
                            snd_soc_msm/HiFi_Rec_Sitar \
                            snd_soc_msm/HiFi_Sitar \
                            snd_soc_msm/HiFi_Tunnel \
                            snd_soc_msm/HiFi_Tunnel_2x \
                            snd_soc_msm/snd_soc_msm \
                            snd_soc_msm/snd_soc_msm_2x \
                            snd_soc_msm/snd_soc_msm_2x_Fusion3 \
                            snd_soc_msm/snd_soc_msm_Sitar \
                            snd_soc_msm/UL_DL_REC \
                            snd_soc_msm/UL_DL_REC_2x \
                            snd_soc_msm/UL_DL_REC_2x_Fusion3 \
                            snd_soc_msm/UL_DL_REC_Sitar \
                            snd_soc_msm/Voice_Call \
                            snd_soc_msm/Voice_Call_2x \
                            snd_soc_msm/Voice_Call_2x_Fusion3 \
                            snd_soc_msm/Voice_Call_IP \
                            snd_soc_msm/Voice_Call_IP_2x \
                            snd_soc_msm/Voice_Call_IP_2x_Fusion3 \
                            snd_soc_msm/Voice_Call_IP_Sitar \
                            snd_soc_msm/Voice_Call_Sitar
libalsa_intf_la_CFLAGS = $(AM_CFLAGS) -DUSE_GLIB @GLIB_CFLAGS@
libalsa_intf_la_CPPFLAGS = $(AM_CPPFLAGS) -DUSE_GLIB @GLIB_CFLAGS@
libalsa_intf_la_LDFLAGS = -lm -lpthread @GLIB_LIBS@ -shared -version-info 1:0:0

requiredlibs = libalsa_intf.la

bin_PROGRAMS = aplay amix arec

aplay_SOURCES = aplay.c
aplay_LDADD = -lpthread $(requiredlibs)

amix_SOURCES = amix.c
amix_LDADD = -lpthread $(requiredlibs)

arec_SOURCES = arec.c
arec_LDADD = -lpthread $(requiredlibs)
