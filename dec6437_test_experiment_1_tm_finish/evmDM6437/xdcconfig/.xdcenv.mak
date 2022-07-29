#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/dvsdk_1_01_00_15/codec_engine_1_20_02/packages;C:/dvsdk_1_01_00_15/codec_engine_1_20_02/examples;C:/dvsdk_1_01_00_15/framework_components_1_20_03/packages;C:/dvsdk_1_01_00_15/xdais_5_21/packages;C:/dvsdk_1_01_00_15/codecs_1_10/packages;C:/dvsdk_1_01_00_15/ndk_1_92_00_22_eval/packages;C:/dvsdk_1_01_00_15/biosutils_1_00_02/packages;C:/dvsdk_1_01_00_15/examples/common/evmDM6437;C:/CCStudio_v3.3/bios_5_31_07/packages;C:/dvsdk_1_01_00_15/xdc_2_95_02/packages;C:/dvsdk_1_01_00_15/examples/dec6437_test_experiment_1/evmDM6437
override XDCROOT = C:/dvsdk_1_01_00_15/xdc_2_95_02
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/dvsdk_1_01_00_15/codec_engine_1_20_02/packages;C:/dvsdk_1_01_00_15/codec_engine_1_20_02/examples;C:/dvsdk_1_01_00_15/framework_components_1_20_03/packages;C:/dvsdk_1_01_00_15/xdais_5_21/packages;C:/dvsdk_1_01_00_15/codecs_1_10/packages;C:/dvsdk_1_01_00_15/ndk_1_92_00_22_eval/packages;C:/dvsdk_1_01_00_15/biosutils_1_00_02/packages;C:/dvsdk_1_01_00_15/examples/common/evmDM6437;C:/CCStudio_v3.3/bios_5_31_07/packages;C:/dvsdk_1_01_00_15/xdc_2_95_02/packages;C:/dvsdk_1_01_00_15/examples/dec6437_test_experiment_1/evmDM6437;C:/dvsdk_1_01_00_15/xdc_2_95_02/packages;..
HOSTOS = Windows
endif
