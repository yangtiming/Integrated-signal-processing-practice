## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: linker.cmd

linker.cmd: \
  package/cfg/audio_video_encdec_x64P.o64P \
  package/cfg/audio_video_encdec_x64Pcfg.o64P \
  package/cfg/audio_video_encdec_x64Pcfg_c.o64P \
  package/cfg/audio_video_encdec_x64P.xdl
	$(SED) 's"^\"\(package/cfg/audio_video_encdec_x64Pcfg.cmd\)\"$""\"C:/dvsdk_1_01_00_15/examples/dec6437_test_experiment_1/evmDM6437/xdcconfig/\1\""' package/cfg/audio_video_encdec_x64P.xdl > $@
