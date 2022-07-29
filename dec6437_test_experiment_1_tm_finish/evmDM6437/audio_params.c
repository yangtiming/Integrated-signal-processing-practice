/*
 * ======== audio_params.c ========
 *
 */

#include <psp_audio.h>

PSP_audio_cfg   audio_cfg = {
        PSP_AUDIO_AIC_MASTER,   /* AIC Mode */
        99000000,               /* Input Frequency to McBSP or McASP module */
        SamprateIn8kOut8k,//8000,                   /* Sampling Rate */
        20,//50,                     /* Input Gain */
        99,                    		 /* no used */
        PSP_AUDIO_LINE_IN,      /* Input Select */
        PSP_AUDIO_LINE_OUT      /* Output Select */
};



