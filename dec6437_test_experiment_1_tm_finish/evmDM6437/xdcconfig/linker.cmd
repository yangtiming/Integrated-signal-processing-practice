/*
 * Do not modify this file; it is automatically generated from the template
 * linkcmd.xdt in the ti.targets package and will be overwritten.
 */

/*
 * put '"'s around paths because, without this, the linker
 * considers '-' as minus operator, not a file name character.
 */



-l"C:\dvsdk_1_01_00_15\examples\dec6437_test_experiment_1\evmDM6437\xdcconfig\package\cfg\audio_video_encdec_x64P.o64P"
-l"C:\dvsdk_1_01_00_15\examples\dec6437_test_experiment_1\evmDM6437\xdcconfig\package\cfg\audio_video_encdec_x64Pcfg.o64P"
-l"C:\dvsdk_1_01_00_15\examples\dec6437_test_experiment_1\evmDM6437\xdcconfig\package\cfg\audio_video_encdec_x64Pcfg_c.o64P"
-l"C:\dvsdk_1_01_00_15\codec_engine_1_20_02\packages\ti\sdo\ce\osal\lib\osal_bios.a64P"
-l"C:\dvsdk_1_01_00_15\framework_components_1_20_03\packages\ti\sdo\fc\acpy3\acpy3.a64P"
-l"C:\dvsdk_1_01_00_15\biosutils_1_00_02\packages\ti\bios\utils\lib\utils.a64P"
-l"C:\dvsdk_1_01_00_15\framework_components_1_20_03\packages\ti\sdo\fc\dman3\dman3Cfg.a64P"
-l"C:\dvsdk_1_01_00_15\framework_components_1_20_03\packages\ti\sdo\fc\dskt2\dskt2.a64P"
-l"C:\dvsdk_1_01_00_15\codec_engine_1_20_02\packages\ti\sdo\ce\trace\lib\gt.a64P"
-l"C:\dvsdk_1_01_00_15\xdc_2_95_02\packages\ti\targets\rts6000\lib\ti.targets.rts6000.a64P"

--args 0x200



/*
 * Linker command file contributions from all loaded packages:
 */
/* Content from xdc (null): */

/* Content from xdc.services.global (null): */

/* Content from xdc.runtime (null): */

/* Content from xdc.platform (null): */

/* Content from xdc.cfg (null): */

/* Content from xdc.shelf (null): */

/* Content from xdc.services.spec (null): */

/* Content from xdc.services.intern.xsr (null): */

/* Content from xdc.services.intern.gen (null): */

/* Content from xdc.services.intern.cmd (null): */

/* Content from ti.catalog.c6000 (null): */

/* Content from ti.platforms.evmDM6437 (null): */

/* Content from ti.targets.rts6000 (null): */

/* Content from ti.psl (ti/psl/psl.xdt): */

/* define the library search paths */
-i"C:\CCStudio_v3.3\bios_5_31_07\packages\ti\psl\lib/"

/* Content from ti.rtdx (ti/rtdx/rtdx.xdt): */

/* define the library search paths */
-i"C:\CCStudio_v3.3\bios_5_31_07\packages\ti\rtdx\lib/c6000"

/* Content from xdc.bld (null): */

/* Content from ti.bios (ti/bios/bios.xdt): */
/* define the library search paths */
-i"C:\CCStudio_v3.3\bios_5_31_07\packages\ti\bios/lib"
-i"C:/CCStudio_v3.3/C6000/cgtools/lib"

/* include the bios generated linker command file */
"C:/dvsdk_1_01_00_15/examples/dec6437_test_experiment_1/evmDM6437/xdcconfig/package/cfg/audio_video_encdec_x64Pcfg.cmd"

/* Content from ti.sdo.ce.trace (null): */

/* Content from ti.sdo.fc.dskt2 (ti/sdo/fc/dskt2/DSKT2.link.xdt): */



__DSKT_DARAM0 = _L1DSRAM;
__DSKT_DARAM1 = _L1DSRAM;
__DSKT_DARAM2 = _L1DSRAM;
__DSKT_SARAM0 = _L1DSRAM;
__DSKT_SARAM1 = _L1DSRAM;
__DSKT_SARAM2 = _L1DSRAM;
__DSKT_ESDATA = _DDR2;
__DSKT_IPROG  = _L1DSRAM;
__DSKT_EPROG  = _DDR2;
__DSKT2_HEAP  = _DDR2;

/* Content from ti.sdo.fc.dman3 (ti/sdo/fc/dman3/DMAN3.link.xdt): */

_DMAN3_EDMA3BASE = 0x1c00000;

/* Content from ti.bios.utils (null): */

/* Content from ti.sdo.fc.acpy3 (null): */

/* Content from ti.sdo.ce.osal (ti/sdo/ce/osal/link.xdt): */
/*
 *  ======== Global Configuration ========
 *  Do not modify this file; it is automatically generated from the template
 *  Server.xdt in the ti.sdo.ce package and will be overwritten next time the
 *  executable is configured
 */
_Memory_SEGID = DDR2; /* default memory segment for Memory_alloc */


/* Content from xdcconfig (null): */

