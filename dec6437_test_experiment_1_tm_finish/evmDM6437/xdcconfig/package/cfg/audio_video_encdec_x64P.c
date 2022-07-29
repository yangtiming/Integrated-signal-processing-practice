/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 */
#define __nested__
#define __config__
#ifndef xdc_std__include
#ifndef __nested__
#define __nested__
#include <xdc/std.h>
#undef __nested__
#else
#include <xdc/std.h>
#endif
#endif


/*
 * ======== module defines ========
 */

/*
 * ======== module includes ========
 */

/*
 * ======== internal module decls ========
 */

/*
 * ======== internal instance decls ========
 */

/*
 * ======== declarations ========
 */

/*
 * ======== module templates ========
 */

/* module ti.sdo.ce.osal.Global */



/*
 *  ======== Global Configuration ========
 *  Do not modify the following; it is automatically generated from the template
 *  Server.xdt in the ti.sdo.ce package and will be overwritten next time the
 *  executable is configured
 */


#include <ti/sdo/ce/osal/Log.h>


#include <ti/bios/include/log.h>

extern LOG_Obj ti_sdo_ce_osal_LOG_Buffer;
Log_Handle ti_sdo_ce_dvtLog = (Log_Handle)&ti_sdo_ce_osal_LOG_Buffer;


Int Memory_numHeaps = 2;

String Memory_heapNames[2];

/*
 *  BIOS heap segments.
 */
extern Int DDR2;
extern Int L1DSRAM;











/* MSGQ and POOL configuration on the DSP when DSPLINK is NOT used */

#include <ti/bios/include/std.h>
#include <ti/bios/include/msgq.h>
#include <ti/bios/include/pool.h>
#include <ti/bios/include/staticpool.h>

#define Global_NUMPROC         1
#define Global_NUMALLOCATORS   1
#define Global_NUMMSGQUEUES    64
#define Global_NUMMSGPOOLS     1

#define Global_MSGSIZE         1024
#define Global_POOLBUFSIZE     (64 * Global_MSGSIZE)

static MSGQ_TransportObj Global_transports[Global_NUMPROC] =
{
     MSGQ_NOTRANSPORT,    /* Represents the local processor */
};

static MSGQ_Obj Global_msgQueues[Global_NUMMSGQUEUES] ;

MSGQ_Config MSGQ_config = {
    Global_msgQueues,
    Global_transports,
    Global_NUMMSGQUEUES,
    Global_NUMPROC,
    0,
    MSGQ_INVALIDMSGQ,
    POOL_INVALIDID
};

static Char Global_poolBuf[Global_POOLBUFSIZE];

static STATICPOOL_Params Global_poolParams = {
    Global_poolBuf,
    sizeof (Global_poolBuf),
    Global_MSGSIZE,
};
static STATICPOOL_Obj Global_poolObj;

static POOL_Obj Global_pools[Global_NUMALLOCATORS] =
{
    {
        STATICPOOL_init,                /* Init Function */
        (POOL_Fxns *)&STATICPOOL_FXNS,  /* Pool interface functions */
        &Global_poolParams,             /* Pool params */
        &Global_poolObj                 /* Pool object: init'd in pool impl. */
    }
};

POOL_Config POOL_config = {
    Global_pools,
    Global_NUMALLOCATORS
};



/* Global_generatedInit() function, called by Global_init() */
Void Global_generatedInit()
{
    Memory_heapNames[DDR2] = "DDR2";
    Memory_heapNames[L1DSRAM] = "L1DSRAM";
}





/* configure GT: each runtime library defines _GT_params */
#include <ti/sdo/ce/trace/gt.h>
GT_Config *GT = &_GT_params;

/* Definition of the globally visible character buffer holding all trace data */
Char Global_traceBuffer[32768];
Int  Global_traceBufferSize = 32768;



/* module ti.sdo.fc.dman3.DMAN3 */


/* C code contribution from ti/sdo/fc/dman3/DMAN3.xdt */

#include <xdc/std.h>

#include <ti/sdo/fc/dman3/dman3.h>
#include <ti/sdo/fc/acpy3/acpy3.h>

#if 20 > DMAN3_MAXGROUPS
#error DMAN3 internal assertion:  const DMAN3.MAXGROUPS larger than header const
#endif

far Uns DMAN3_QDMA_CHANNELS[8] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7
};

extern Void  _DMAN3_initInternal();
extern Void  _DMAN3_initImpl(Void);
/* declaration of user-supplied DMAN3.scratchAllocFxn */
extern Bool DSKT2_allocScratch(IALG_Handle alg, Int mutexId,
            IALG_MemRec *memTab, Int numRecs);

/* declaration of user-supplied DMAN3.scratchFreeFxn */
extern Void DSKT2_freeScratch(Int mutexId, Void *addr, Uns size);


/*
 *  ======== DMAN3_init  ========
 */
Void DMAN3_init(Void)
{
    extern far DMAN3_Params DMAN3_PARAMS;

    /* BIOS heap labels */
    extern far Int DDR2;
    extern far Int DDR2;

    DMAN3_PARAMS.heapInternal = DDR2;
    DMAN3_PARAMS.heapExternal = DDR2;

    _DMAN3_initImpl();
}


/*
 *  ======== DMAN3_CE_init  ========
 *  Supplied to support legacy Codec Engine Frameworks. To be deprecated in the future.
 */
Void DMAN3_CE_init()
{
    DMAN3_init();
    ACPY3_init();
}

/*
 *  ======== DMAN3_CE_exit  ========
 *  Supplied to support legacy Codec Engine Frameworks. To be deprecated in the future.
 */
Void DMAN3_CE_exit()
{
    DMAN3_exit();
    ACPY3_exit();
}

/*
 *  ======== DMAN3_PARAMS ========
 *  Default module configuration structure for DMAN3 implementation.
 *  It is set at design time by the system integrator to adjust the behaviour
 *  of the module to be optimal for its execution environment.
 */
DMAN3_Params DMAN3_PARAMS = {

    /* qdmaPaRamBase: Physical base address for PARAM0 */
    (Uns *)0x1c04000,

    /* The maxPaRamEntries:  Total number of PARAM Table entries on the
     * hardware (eg, for IVA2 this is 128, for Himalaya, this is 256).
     */
    128,

    /*
     * paRamBaseIndex: (0>value>255) represents the first PARAM TABLE ENTRY
     * NUMBER that is assigned by configuration for exclusive DMAN3 allocation.
     */
    78,

    /*
     * numPaRamEntries:  number of PARAM Table entries starting at
     * DMAN3_PARAM_BASE_INDEX assigned by configuration for exclusive DMAN3
     * allocation.
     */
    48,

    /* maxQdmaChannels:  contains the total number of Physical QDMA channels
     * available on the hardware (eg, 8 for DaVinci, 4 for IVA2).
     */
    8,

    /*
     * numQdmaChannels: contains the number of Physical QDMA channels
     * that are assigned to DMAN3 via configuration.
     * qdmaChannels: array containing list of DMAN3_NUM_QDMA_CHANNELS
     * many Physical QDMA channels assigned to DMAN3 via configuration.
     */
    8,
    DMAN3_QDMA_CHANNELS,

    /*
     * tccAllocationMaskH and tccAllocationMaskL:  are 32-bit bitmasks
     * representing configuration provided list of TCCs for exclusive DMAN3
     * allocation.
     *
     * For example, for TCC's in the range 0-31 the Low Mask (tccAllocationMaskL)
     * is configured so that a '1' in bit position 'i' indicates the TCC 'i' is
     * assigned to DMAN3
     */
    0xffffffff,
    0x0,

     /*
      * heapInternal: BIOS Heap ID for dynamic allocation of DMAN3 objects
      * must be allocated in L1D Internal RAM.
      * heapExternal: BIOS Heap ID for dyn allocation of private DMAN3
      * data structures.
      *
      * A value of -1 indicates that the heap is NOT DEFINED.
      */
    -1, //DDR2,
    0,  //DDR2,

    /* numTccGroup[DMAN3_MAXGROUPS] */
    {
    8,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
    },

    /* numPaRamGroup[DMAN3_MAXGROUPS] */
    {
    48,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
    },

    /* idma3Internal */
    0,

    /* scratchAllocFxn */
    DSKT2_allocScratch,

    /* scratchFreeFxn */
    DSKT2_freeScratch,

    /* nullPaRamIndex */
    0,
};


/* module ti.sdo.fc.dskt2.DSKT2 */

/* C code contribution from ti/sdo/fc/DSKT2.xdt */

#include <xdc/std.h>
#include <ti/sdo/fc/dskt2/dskt2.h>

extern Void BCACHE_wbInv();

DSKT2_CacheWBInvFxn DSKT2_cacheWBInvFxn = (DSKT2_CacheWBInvFxn)BCACHE_wbInv;

Uns _DSKT2_ALLOW_EXTERNAL_SCRATCH = 1;

#if 8 > DSKT2_NUM_SCRATCH_GROUPS
#error too many values in DARAM_SCRATCH_SIZES array, please fix your .cfg
#endif

#if 8 > DSKT2_NUM_SCRATCH_GROUPS
#error too many values in SARAM_SCRATCH_SIZES array, please fix your .cfg
#endif

Uns _DSKT2_DARAM_SCRATCH_SIZES[ DSKT2_NUM_SCRATCH_GROUPS ] = {
    65536,
    1024,
    0,
    0,
    0,
    0,
    0,
    0
};

Uns _DSKT2_SARAM_SCRATCH_SIZES[ DSKT2_NUM_SCRATCH_GROUPS ] = {
    65536,
    1024,
    0,
    0,
    0,
    0,
    0,
    0
};


/* module xdc.cfg.Program */

/*
 *  ======== __ASM__ ========
 *  Define this program's package-path relative assembly directory
 */
__FAR__ char* __ASM__ = "@(#)__ASM__ = C:/dvsdk_1_01_00_15/examples/dec6437_test_experiment_1/evmDM6437/xdcconfig/package/cfg/audio_video_encdec_x64P";

/*
 *  ======== __ISA__ ========
 *  Define the ISA of this executable.  This symbol is used by platform
 *  specific "exec" commands that support more than one ISA; e.g., gdb
 */
__FAR__ char*  __ISA__ = "@(#)__ISA__ = 64P";

/*
 *  ======== __PLAT__ ========
 *  Define the name of the platform that can run this executable.  This
 *  symbol is used by platform independent "exec" commands
 */
__FAR__ char* __PLAT__ = "@(#)__PLAT__ = ti.platforms.evmDM6437";

/*
 *  ======== __TARG__ ========
 *  Define the name of the target used to build this executable.
 */
__FAR__ char* __TARG__ = "@(#)__TARG__ = ti.targets.C64P";


/*
 * ======== module configuration ========
 */

/*
 * ======== post initialization ========
 */

/*
 * ======== program globals ========
 */

/*
 * ======== package includes ========
 */

/* package xdc */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 1, 1, 0, 0
#define __xdc_PKGNAME xdc
#define __xdc_PKGPREFIX xdc_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else

#endif

/* package xdc.services.global */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 1, 0, 0
#define __xdc_PKGNAME xdc.services.global
#define __xdc_PKGPREFIX xdc_services_global_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else

#endif

/* package xdc.runtime */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 2, 0, 0, 0
#define __xdc_PKGNAME xdc.runtime
#define __xdc_PKGPREFIX xdc_runtime_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else
#ifdef xdc_runtime_Assert___used
/*
 *  ======== module Assert ========
 *  Do not modify this file; it is generated from the specification Assert.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_Assert__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Assert.h>
#undef __nested__
#else
#include <xdc/runtime/Assert.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Assert___LOGOBJ) && xdc_runtime_Assert___DGSINCL & 0x1
#define xdc_runtime_Assert___L_ENTRY 1
#else
#define xdc_runtime_Assert___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Assert___LOGOBJ) && xdc_runtime_Assert___DGSINCL & 0x2
#define xdc_runtime_Assert___L_EXIT 1
#else
#define xdc_runtime_Assert___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Assert___LOGOBJ) && xdc_runtime_Assert___DGSINCL & 0x4
#define xdc_runtime_Assert___L_LIFECYCLE 1
#else
#define xdc_runtime_Assert___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_Assert_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Assert_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Assert_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Assert_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Assert_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Assert_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Assert_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Assert_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Assert_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Assert_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Assert_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Assert_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Assert_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Assert_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Assert_Module_GateProxy_query

#if defined(xdc_runtime_Assert___EXPORT) && defined(__ti__)
#if xdc_runtime_Assert___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Assert_Module__startupDone__S);
#endif
#endif
__FAR__ xdc_runtime_Assert_Module__MTAB__C__qual xdc_runtime_Assert_MTab__ xdc_runtime_Assert_Module__MTAB__C = {
#if xdc_runtime_Assert___scope == -1
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_Assert___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_Assert_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Assert_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Assert_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Assert_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Assert_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Assert_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Assert_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Assert_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Assert_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Assert_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Assert_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Assert_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Assert_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Assert_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Assert_Module_GateProxy_query
#endif /* xdc_runtime_Assert___ROMPATCH */
#ifdef xdc_runtime_Assert___ROMPATCH
#endif /* xdc_runtime_Assert___ROMPATCH */

#if defined(xdc_runtime_Assert___EXPORT) && defined(__ti__)
#if xdc_runtime_Assert___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Assert_Module__startupDone__S);
#endif
#endif
#endif /* __isrom__ */

#if xdc_runtime_Assert___scope != -1
xdc_Bool xdc_runtime_Assert_Module__startupDone__S() {

    return 1;
}
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_Core___used
/*
 *  ======== module Core ========
 *  Do not modify this file; it is generated from the specification Core.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_Core__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Core.h>
#undef __nested__
#else
#include <xdc/runtime/Core.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Core___LOGOBJ) && xdc_runtime_Core___DGSINCL & 0x1
#define xdc_runtime_Core___L_ENTRY 1
#else
#define xdc_runtime_Core___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Core___LOGOBJ) && xdc_runtime_Core___DGSINCL & 0x2
#define xdc_runtime_Core___L_EXIT 1
#else
#define xdc_runtime_Core___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Core___LOGOBJ) && xdc_runtime_Core___DGSINCL & 0x4
#define xdc_runtime_Core___L_LIFECYCLE 1
#else
#define xdc_runtime_Core___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_Core_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Core_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Core_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Core_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Core_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Core_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Core_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Core_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Core_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Core_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Core_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Core_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Core_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Core_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Core_Module_GateProxy_query

#if defined(xdc_runtime_Core___EXPORT) && defined(__ti__)
#if xdc_runtime_Core___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Core_Module__startupDone__S);
#endif
#endif
__FAR__ xdc_runtime_Core_Module__MTAB__C__qual xdc_runtime_Core_MTab__ xdc_runtime_Core_Module__MTAB__C = {
#if xdc_runtime_Core___scope == -1
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_Core___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_Core_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Core_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Core_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Core_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Core_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Core_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Core_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Core_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Core_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Core_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Core_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Core_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Core_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Core_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Core_Module_GateProxy_query
#endif /* xdc_runtime_Core___ROMPATCH */
#ifdef xdc_runtime_Core___ROMPATCH
#endif /* xdc_runtime_Core___ROMPATCH */

#if defined(xdc_runtime_Core___EXPORT) && defined(__ti__)
#if xdc_runtime_Core___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Core_Module__startupDone__S);
#endif
#endif
#endif /* __isrom__ */

#if xdc_runtime_Core___scope != -1
xdc_Bool xdc_runtime_Core_Module__startupDone__S() {

    return 1;
}
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_Defaults___used
/*
 *  ======== module Defaults ========
 *  Do not modify this file; it is generated from the specification Defaults.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_Defaults__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Defaults.h>
#undef __nested__
#else
#include <xdc/runtime/Defaults.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Defaults___LOGOBJ) && xdc_runtime_Defaults___DGSINCL & 0x1
#define xdc_runtime_Defaults___L_ENTRY 1
#else
#define xdc_runtime_Defaults___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Defaults___LOGOBJ) && xdc_runtime_Defaults___DGSINCL & 0x2
#define xdc_runtime_Defaults___L_EXIT 1
#else
#define xdc_runtime_Defaults___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Defaults___LOGOBJ) && xdc_runtime_Defaults___DGSINCL & 0x4
#define xdc_runtime_Defaults___L_LIFECYCLE 1
#else
#define xdc_runtime_Defaults___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_Defaults_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Defaults_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Defaults_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Defaults_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Defaults_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Defaults_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Defaults_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Defaults_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Defaults_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Defaults_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Defaults_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Defaults_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Defaults_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Defaults_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Defaults_Module_GateProxy_query

#if defined(xdc_runtime_Defaults___EXPORT) && defined(__ti__)
#if xdc_runtime_Defaults___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Defaults_Module__startupDone__S);
#endif
#endif
__FAR__ xdc_runtime_Defaults_Module__MTAB__C__qual xdc_runtime_Defaults_MTab__ xdc_runtime_Defaults_Module__MTAB__C = {
#if xdc_runtime_Defaults___scope == -1
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_Defaults___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_Defaults_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Defaults_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Defaults_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Defaults_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Defaults_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Defaults_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Defaults_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Defaults_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Defaults_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Defaults_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Defaults_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Defaults_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Defaults_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Defaults_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Defaults_Module_GateProxy_query
#endif /* xdc_runtime_Defaults___ROMPATCH */
#ifdef xdc_runtime_Defaults___ROMPATCH
#endif /* xdc_runtime_Defaults___ROMPATCH */

#if defined(xdc_runtime_Defaults___EXPORT) && defined(__ti__)
#if xdc_runtime_Defaults___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Defaults_Module__startupDone__S);
#endif
#endif
#endif /* __isrom__ */

#if xdc_runtime_Defaults___scope != -1
xdc_Bool xdc_runtime_Defaults_Module__startupDone__S() {

    return 1;
}
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_Diags___used
/*
 *  ======== module Diags ========
 *  Do not modify this file; it is generated from the specification Diags.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_Diags__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Diags.h>
#undef __nested__
#else
#include <xdc/runtime/Diags.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Diags___LOGOBJ) && xdc_runtime_Diags___DGSINCL & 0x1
#define xdc_runtime_Diags___L_ENTRY 1
#else
#define xdc_runtime_Diags___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Diags___LOGOBJ) && xdc_runtime_Diags___DGSINCL & 0x2
#define xdc_runtime_Diags___L_EXIT 1
#else
#define xdc_runtime_Diags___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Diags___LOGOBJ) && xdc_runtime_Diags___DGSINCL & 0x4
#define xdc_runtime_Diags___L_LIFECYCLE 1
#else
#define xdc_runtime_Diags___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_Diags_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Diags_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Diags_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Diags_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Diags_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Diags_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Diags_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Diags_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Diags_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Diags_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Diags_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Diags_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Diags_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Diags_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Diags_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_Diags___scope == -1
#ifdef xdc_runtime_Diags_setMask__PATCH
#define __FN__ xdc_runtime_Diags_setMask__PATCH
#else
#define __FN__ xdc_runtime_Diags_setMask__R
#endif
#else
#define __FN__ xdc_runtime_Diags_setMask__F
#endif
xdc_Void xdc_runtime_Diags_setMask__E( xdc_String s ) {
#if xdc_runtime_Diags___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Diags_setMask__ENTRY_EVT, (xdc_IArg)s);
#endif
#if xdc_runtime_Diags___L_EXIT
    __FN__(s);
    xdc_runtime_Log_write1(xdc_runtime_Diags_setMask__EXIT_EVT, 0);
#else
    __FN__(s);
#endif
}

#if defined(xdc_runtime_Diags___EXPORT) && defined(__ti__)
#if xdc_runtime_Diags___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Diags_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_Diags_setMask__E);
#endif
__FAR__ xdc_runtime_Diags_Module__MTAB__C__qual xdc_runtime_Diags_MTab__ xdc_runtime_Diags_Module__MTAB__C = {
#if xdc_runtime_Diags___scope == -1
#if xdc_runtime_Diags___L_ENTRY || xdc_runtime_Diags___L_EXIT
    xdc_runtime_Diags_setMask__E,
#elif defined(xdc_runtime_Diags_setMask__PATCH)
    xdc_runtime_Diags_setMask__PATCH,
#else
    xdc_runtime_Diags_setMask__R,
#endif
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_Diags___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_Diags_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Diags_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Diags_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Diags_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Diags_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Diags_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Diags_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Diags_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Diags_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Diags_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Diags_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Diags_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Diags_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Diags_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Diags_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_Diags___scope == -1
#ifdef xdc_runtime_Diags_setMask__PATCH
#define __FN__ xdc_runtime_Diags_setMask__PATCH
#else
#define __FN__ xdc_runtime_Diags_setMask__R
#endif
#else
#define __FN__ xdc_runtime_Diags_setMask__F
#endif
xdc_Void xdc_runtime_Diags_setMask__E( xdc_String s ) {
#if xdc_runtime_Diags___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Diags_setMask__ENTRY_EVT, (xdc_IArg)s);
#endif
#if xdc_runtime_Diags___L_EXIT
    __FN__(s);
    xdc_runtime_Log_write1(xdc_runtime_Diags_setMask__EXIT_EVT, 0);
#else
    __FN__(s);
#endif
}
#endif /* xdc_runtime_Diags___ROMPATCH */
#ifdef xdc_runtime_Diags___ROMPATCH
xdc_Void xdc_runtime_Diags_setMask__E( xdc_String s ) {
    xdc_runtime_Diags_Module__MTAB__C.setMask(s);
}
#endif /* xdc_runtime_Diags___ROMPATCH */
xdc_Void xdc_runtime_Diags_setMask__R( xdc_String s ) {
    xdc_runtime_Diags_setMask__F(s);
}

#if defined(xdc_runtime_Diags___EXPORT) && defined(__ti__)
#if xdc_runtime_Diags___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Diags_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_Diags_setMask__R);
#endif
#endif /* __isrom__ */

#if xdc_runtime_Diags___scope != -1
xdc_Bool xdc_runtime_Diags_Module__startupDone__S() {

    return 1;
}
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_Error___used
/*
 *  ======== module Error ========
 *  Do not modify this file; it is generated from the specification Error.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Error___LOGOBJ) && xdc_runtime_Error___DGSINCL & 0x1
#define xdc_runtime_Error___L_ENTRY 1
#else
#define xdc_runtime_Error___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Error___LOGOBJ) && xdc_runtime_Error___DGSINCL & 0x2
#define xdc_runtime_Error___L_EXIT 1
#else
#define xdc_runtime_Error___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Error___LOGOBJ) && xdc_runtime_Error___DGSINCL & 0x4
#define xdc_runtime_Error___L_LIFECYCLE 1
#else
#define xdc_runtime_Error___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_Error_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Error_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Error_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Error_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Error_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Error_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Error_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Error_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Error_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Error_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Error_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Error_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Error_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Error_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Error_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_Error___scope == -1
#ifdef xdc_runtime_Error_check__PATCH
#define __FN__ xdc_runtime_Error_check__PATCH
#else
#define __FN__ xdc_runtime_Error_check__R
#endif
#else
#define __FN__ xdc_runtime_Error_check__F
#endif
xdc_Bool xdc_runtime_Error_check__E( xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Error___L_EXIT
    xdc_Bool __ret;
#else
#endif
#if xdc_runtime_Error___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Error_check__ENTRY_EVT, (xdc_IArg)eb);
#endif
#if xdc_runtime_Error___L_EXIT
    __ret = __FN__(eb);
    xdc_runtime_Log_write1(xdc_runtime_Error_check__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(eb);
#endif
}
#undef __FN__
#if xdc_runtime_Error___scope == -1
#ifdef xdc_runtime_Error_print__PATCH
#define __FN__ xdc_runtime_Error_print__PATCH
#else
#define __FN__ xdc_runtime_Error_print__R
#endif
#else
#define __FN__ xdc_runtime_Error_print__F
#endif
xdc_Void xdc_runtime_Error_print__E( xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Error___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Error_print__ENTRY_EVT, (xdc_IArg)eb);
#endif
#if xdc_runtime_Error___L_EXIT
    __FN__(eb);
    xdc_runtime_Log_write1(xdc_runtime_Error_print__EXIT_EVT, 0);
#else
    __FN__(eb);
#endif
}
#undef __FN__
#if xdc_runtime_Error___scope == -1
#ifdef xdc_runtime_Error_init__PATCH
#define __FN__ xdc_runtime_Error_init__PATCH
#else
#define __FN__ xdc_runtime_Error_init__R
#endif
#else
#define __FN__ xdc_runtime_Error_init__F
#endif
xdc_Void xdc_runtime_Error_init__E( xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Error___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Error_init__ENTRY_EVT, (xdc_IArg)eb);
#endif
#if xdc_runtime_Error___L_EXIT
    __FN__(eb);
    xdc_runtime_Log_write1(xdc_runtime_Error_init__EXIT_EVT, 0);
#else
    __FN__(eb);
#endif
}
#undef __FN__
#if xdc_runtime_Error___scope == -1
#ifdef xdc_runtime_Error_getData__PATCH
#define __FN__ xdc_runtime_Error_getData__PATCH
#else
#define __FN__ xdc_runtime_Error_getData__R
#endif
#else
#define __FN__ xdc_runtime_Error_getData__F
#endif
xdc_runtime_Error_Data* xdc_runtime_Error_getData__E( xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Error___L_EXIT
    xdc_runtime_Error_Data* __ret;
#else
#endif
#if xdc_runtime_Error___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Error_getData__ENTRY_EVT, (xdc_IArg)eb);
#endif
#if xdc_runtime_Error___L_EXIT
    __ret = __FN__(eb);
    xdc_runtime_Log_write1(xdc_runtime_Error_getData__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(eb);
#endif
}
#undef __FN__
#if xdc_runtime_Error___scope == -1
#ifdef xdc_runtime_Error_getCode__PATCH
#define __FN__ xdc_runtime_Error_getCode__PATCH
#else
#define __FN__ xdc_runtime_Error_getCode__R
#endif
#else
#define __FN__ xdc_runtime_Error_getCode__F
#endif
xdc_UInt16 xdc_runtime_Error_getCode__E( xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Error___L_EXIT
    xdc_UInt16 __ret;
#else
#endif
#if xdc_runtime_Error___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Error_getCode__ENTRY_EVT, (xdc_IArg)eb);
#endif
#if xdc_runtime_Error___L_EXIT
    __ret = __FN__(eb);
    xdc_runtime_Log_write1(xdc_runtime_Error_getCode__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(eb);
#endif
}
#undef __FN__
#if xdc_runtime_Error___scope == -1
#ifdef xdc_runtime_Error_getId__PATCH
#define __FN__ xdc_runtime_Error_getId__PATCH
#else
#define __FN__ xdc_runtime_Error_getId__R
#endif
#else
#define __FN__ xdc_runtime_Error_getId__F
#endif
xdc_runtime_Error_Id xdc_runtime_Error_getId__E( xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Error___L_EXIT
    xdc_runtime_Error_Id __ret;
#else
#endif
#if xdc_runtime_Error___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Error_getId__ENTRY_EVT, (xdc_IArg)eb);
#endif
#if xdc_runtime_Error___L_EXIT
    __ret = __FN__(eb);
    xdc_runtime_Log_write1(xdc_runtime_Error_getId__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(eb);
#endif
}
#undef __FN__
#if xdc_runtime_Error___scope == -1
#ifdef xdc_runtime_Error_getMsg__PATCH
#define __FN__ xdc_runtime_Error_getMsg__PATCH
#else
#define __FN__ xdc_runtime_Error_getMsg__R
#endif
#else
#define __FN__ xdc_runtime_Error_getMsg__F
#endif
xdc_String xdc_runtime_Error_getMsg__E( xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Error___L_EXIT
    xdc_String __ret;
#else
#endif
#if xdc_runtime_Error___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Error_getMsg__ENTRY_EVT, (xdc_IArg)eb);
#endif
#if xdc_runtime_Error___L_EXIT
    __ret = __FN__(eb);
    xdc_runtime_Log_write1(xdc_runtime_Error_getMsg__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(eb);
#endif
}
#undef __FN__
#if xdc_runtime_Error___scope == -1
#ifdef xdc_runtime_Error_getSite__PATCH
#define __FN__ xdc_runtime_Error_getSite__PATCH
#else
#define __FN__ xdc_runtime_Error_getSite__R
#endif
#else
#define __FN__ xdc_runtime_Error_getSite__F
#endif
xdc_runtime_Types_Site* xdc_runtime_Error_getSite__E( xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Error___L_EXIT
    xdc_runtime_Types_Site* __ret;
#else
#endif
#if xdc_runtime_Error___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Error_getSite__ENTRY_EVT, (xdc_IArg)eb);
#endif
#if xdc_runtime_Error___L_EXIT
    __ret = __FN__(eb);
    xdc_runtime_Log_write1(xdc_runtime_Error_getSite__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(eb);
#endif
}
#undef __FN__
#if xdc_runtime_Error___scope == -1
#ifdef xdc_runtime_Error_raiseX__PATCH
#define __FN__ xdc_runtime_Error_raiseX__PATCH
#else
#define __FN__ xdc_runtime_Error_raiseX__R
#endif
#else
#define __FN__ xdc_runtime_Error_raiseX__F
#endif
xdc_Void xdc_runtime_Error_raiseX__E( xdc_runtime_Error_Block* eb, xdc_runtime_Types_ModuleId mod, xdc_String file, xdc_Int line, xdc_runtime_Error_Id id, xdc_IArg arg1, xdc_IArg arg2 ) {
#if xdc_runtime_Error___L_ENTRY
    xdc_runtime_Log_write4(xdc_runtime_Error_raiseX__ENTRY_EVT, (xdc_IArg)eb, (xdc_IArg)mod, (xdc_IArg)file, (xdc_IArg)line);
#endif
#if xdc_runtime_Error___L_EXIT
    __FN__(eb, mod, file, line, id, arg1, arg2);
    xdc_runtime_Log_write1(xdc_runtime_Error_raiseX__EXIT_EVT, 0);
#else
    __FN__(eb, mod, file, line, id, arg1, arg2);
#endif
}

#if defined(xdc_runtime_Error___EXPORT) && defined(__ti__)
#if xdc_runtime_Error___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_check__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_print__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_init__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_getData__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_getCode__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_getId__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_getMsg__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_getSite__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_raiseX__E);
#endif
__FAR__ xdc_runtime_Error_Module__MTAB__C__qual xdc_runtime_Error_MTab__ xdc_runtime_Error_Module__MTAB__C = {
#if xdc_runtime_Error___scope == -1
#if xdc_runtime_Error___L_ENTRY || xdc_runtime_Error___L_EXIT
    xdc_runtime_Error_check__E,
#elif defined(xdc_runtime_Error_check__PATCH)
    xdc_runtime_Error_check__PATCH,
#else
    xdc_runtime_Error_check__R,
#endif
#if xdc_runtime_Error___L_ENTRY || xdc_runtime_Error___L_EXIT
    xdc_runtime_Error_print__E,
#elif defined(xdc_runtime_Error_print__PATCH)
    xdc_runtime_Error_print__PATCH,
#else
    xdc_runtime_Error_print__R,
#endif
#if xdc_runtime_Error___L_ENTRY || xdc_runtime_Error___L_EXIT
    xdc_runtime_Error_init__E,
#elif defined(xdc_runtime_Error_init__PATCH)
    xdc_runtime_Error_init__PATCH,
#else
    xdc_runtime_Error_init__R,
#endif
#if xdc_runtime_Error___L_ENTRY || xdc_runtime_Error___L_EXIT
    xdc_runtime_Error_getData__E,
#elif defined(xdc_runtime_Error_getData__PATCH)
    xdc_runtime_Error_getData__PATCH,
#else
    xdc_runtime_Error_getData__R,
#endif
#if xdc_runtime_Error___L_ENTRY || xdc_runtime_Error___L_EXIT
    xdc_runtime_Error_getCode__E,
#elif defined(xdc_runtime_Error_getCode__PATCH)
    xdc_runtime_Error_getCode__PATCH,
#else
    xdc_runtime_Error_getCode__R,
#endif
#if xdc_runtime_Error___L_ENTRY || xdc_runtime_Error___L_EXIT
    xdc_runtime_Error_getId__E,
#elif defined(xdc_runtime_Error_getId__PATCH)
    xdc_runtime_Error_getId__PATCH,
#else
    xdc_runtime_Error_getId__R,
#endif
#if xdc_runtime_Error___L_ENTRY || xdc_runtime_Error___L_EXIT
    xdc_runtime_Error_getMsg__E,
#elif defined(xdc_runtime_Error_getMsg__PATCH)
    xdc_runtime_Error_getMsg__PATCH,
#else
    xdc_runtime_Error_getMsg__R,
#endif
#if xdc_runtime_Error___L_ENTRY || xdc_runtime_Error___L_EXIT
    xdc_runtime_Error_getSite__E,
#elif defined(xdc_runtime_Error_getSite__PATCH)
    xdc_runtime_Error_getSite__PATCH,
#else
    xdc_runtime_Error_getSite__R,
#endif
#if xdc_runtime_Error___L_ENTRY || xdc_runtime_Error___L_EXIT
    xdc_runtime_Error_raiseX__E,
#elif defined(xdc_runtime_Error_raiseX__PATCH)
    xdc_runtime_Error_raiseX__PATCH,
#else
    xdc_runtime_Error_raiseX__R,
#endif
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_Error___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_Error_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Error_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Error_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Error_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Error_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Error_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Error_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Error_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Error_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Error_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Error_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Error_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Error_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Error_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Error_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_Error___scope == -1
#ifdef xdc_runtime_Error_check__PATCH
#define __FN__ xdc_runtime_Error_check__PATCH
#else
#define __FN__ xdc_runtime_Error_check__R
#endif
#else
#define __FN__ xdc_runtime_Error_check__F
#endif
xdc_Bool xdc_runtime_Error_check__E( xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Error___L_EXIT
    xdc_Bool __ret;
#else
#endif
#if xdc_runtime_Error___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Error_check__ENTRY_EVT, (xdc_IArg)eb);
#endif
#if xdc_runtime_Error___L_EXIT
    __ret = __FN__(eb);
    xdc_runtime_Log_write1(xdc_runtime_Error_check__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(eb);
#endif
}
#undef __FN__
#if xdc_runtime_Error___scope == -1
#ifdef xdc_runtime_Error_print__PATCH
#define __FN__ xdc_runtime_Error_print__PATCH
#else
#define __FN__ xdc_runtime_Error_print__R
#endif
#else
#define __FN__ xdc_runtime_Error_print__F
#endif
xdc_Void xdc_runtime_Error_print__E( xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Error___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Error_print__ENTRY_EVT, (xdc_IArg)eb);
#endif
#if xdc_runtime_Error___L_EXIT
    __FN__(eb);
    xdc_runtime_Log_write1(xdc_runtime_Error_print__EXIT_EVT, 0);
#else
    __FN__(eb);
#endif
}
#undef __FN__
#if xdc_runtime_Error___scope == -1
#ifdef xdc_runtime_Error_init__PATCH
#define __FN__ xdc_runtime_Error_init__PATCH
#else
#define __FN__ xdc_runtime_Error_init__R
#endif
#else
#define __FN__ xdc_runtime_Error_init__F
#endif
xdc_Void xdc_runtime_Error_init__E( xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Error___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Error_init__ENTRY_EVT, (xdc_IArg)eb);
#endif
#if xdc_runtime_Error___L_EXIT
    __FN__(eb);
    xdc_runtime_Log_write1(xdc_runtime_Error_init__EXIT_EVT, 0);
#else
    __FN__(eb);
#endif
}
#undef __FN__
#if xdc_runtime_Error___scope == -1
#ifdef xdc_runtime_Error_getData__PATCH
#define __FN__ xdc_runtime_Error_getData__PATCH
#else
#define __FN__ xdc_runtime_Error_getData__R
#endif
#else
#define __FN__ xdc_runtime_Error_getData__F
#endif
xdc_runtime_Error_Data* xdc_runtime_Error_getData__E( xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Error___L_EXIT
    xdc_runtime_Error_Data* __ret;
#else
#endif
#if xdc_runtime_Error___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Error_getData__ENTRY_EVT, (xdc_IArg)eb);
#endif
#if xdc_runtime_Error___L_EXIT
    __ret = __FN__(eb);
    xdc_runtime_Log_write1(xdc_runtime_Error_getData__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(eb);
#endif
}
#undef __FN__
#if xdc_runtime_Error___scope == -1
#ifdef xdc_runtime_Error_getCode__PATCH
#define __FN__ xdc_runtime_Error_getCode__PATCH
#else
#define __FN__ xdc_runtime_Error_getCode__R
#endif
#else
#define __FN__ xdc_runtime_Error_getCode__F
#endif
xdc_UInt16 xdc_runtime_Error_getCode__E( xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Error___L_EXIT
    xdc_UInt16 __ret;
#else
#endif
#if xdc_runtime_Error___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Error_getCode__ENTRY_EVT, (xdc_IArg)eb);
#endif
#if xdc_runtime_Error___L_EXIT
    __ret = __FN__(eb);
    xdc_runtime_Log_write1(xdc_runtime_Error_getCode__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(eb);
#endif
}
#undef __FN__
#if xdc_runtime_Error___scope == -1
#ifdef xdc_runtime_Error_getId__PATCH
#define __FN__ xdc_runtime_Error_getId__PATCH
#else
#define __FN__ xdc_runtime_Error_getId__R
#endif
#else
#define __FN__ xdc_runtime_Error_getId__F
#endif
xdc_runtime_Error_Id xdc_runtime_Error_getId__E( xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Error___L_EXIT
    xdc_runtime_Error_Id __ret;
#else
#endif
#if xdc_runtime_Error___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Error_getId__ENTRY_EVT, (xdc_IArg)eb);
#endif
#if xdc_runtime_Error___L_EXIT
    __ret = __FN__(eb);
    xdc_runtime_Log_write1(xdc_runtime_Error_getId__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(eb);
#endif
}
#undef __FN__
#if xdc_runtime_Error___scope == -1
#ifdef xdc_runtime_Error_getMsg__PATCH
#define __FN__ xdc_runtime_Error_getMsg__PATCH
#else
#define __FN__ xdc_runtime_Error_getMsg__R
#endif
#else
#define __FN__ xdc_runtime_Error_getMsg__F
#endif
xdc_String xdc_runtime_Error_getMsg__E( xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Error___L_EXIT
    xdc_String __ret;
#else
#endif
#if xdc_runtime_Error___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Error_getMsg__ENTRY_EVT, (xdc_IArg)eb);
#endif
#if xdc_runtime_Error___L_EXIT
    __ret = __FN__(eb);
    xdc_runtime_Log_write1(xdc_runtime_Error_getMsg__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(eb);
#endif
}
#undef __FN__
#if xdc_runtime_Error___scope == -1
#ifdef xdc_runtime_Error_getSite__PATCH
#define __FN__ xdc_runtime_Error_getSite__PATCH
#else
#define __FN__ xdc_runtime_Error_getSite__R
#endif
#else
#define __FN__ xdc_runtime_Error_getSite__F
#endif
xdc_runtime_Types_Site* xdc_runtime_Error_getSite__E( xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Error___L_EXIT
    xdc_runtime_Types_Site* __ret;
#else
#endif
#if xdc_runtime_Error___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Error_getSite__ENTRY_EVT, (xdc_IArg)eb);
#endif
#if xdc_runtime_Error___L_EXIT
    __ret = __FN__(eb);
    xdc_runtime_Log_write1(xdc_runtime_Error_getSite__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(eb);
#endif
}
#undef __FN__
#if xdc_runtime_Error___scope == -1
#ifdef xdc_runtime_Error_raiseX__PATCH
#define __FN__ xdc_runtime_Error_raiseX__PATCH
#else
#define __FN__ xdc_runtime_Error_raiseX__R
#endif
#else
#define __FN__ xdc_runtime_Error_raiseX__F
#endif
xdc_Void xdc_runtime_Error_raiseX__E( xdc_runtime_Error_Block* eb, xdc_runtime_Types_ModuleId mod, xdc_String file, xdc_Int line, xdc_runtime_Error_Id id, xdc_IArg arg1, xdc_IArg arg2 ) {
#if xdc_runtime_Error___L_ENTRY
    xdc_runtime_Log_write4(xdc_runtime_Error_raiseX__ENTRY_EVT, (xdc_IArg)eb, (xdc_IArg)mod, (xdc_IArg)file, (xdc_IArg)line);
#endif
#if xdc_runtime_Error___L_EXIT
    __FN__(eb, mod, file, line, id, arg1, arg2);
    xdc_runtime_Log_write1(xdc_runtime_Error_raiseX__EXIT_EVT, 0);
#else
    __FN__(eb, mod, file, line, id, arg1, arg2);
#endif
}
#endif /* xdc_runtime_Error___ROMPATCH */
#ifdef xdc_runtime_Error___ROMPATCH
xdc_Bool xdc_runtime_Error_check__E( xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_Error_Module__MTAB__C.check(eb);
}
xdc_Void xdc_runtime_Error_print__E( xdc_runtime_Error_Block* eb ) {
    xdc_runtime_Error_Module__MTAB__C.print(eb);
}
xdc_Void xdc_runtime_Error_init__E( xdc_runtime_Error_Block* eb ) {
    xdc_runtime_Error_Module__MTAB__C.init(eb);
}
xdc_runtime_Error_Data* xdc_runtime_Error_getData__E( xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_Error_Module__MTAB__C.getData(eb);
}
xdc_UInt16 xdc_runtime_Error_getCode__E( xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_Error_Module__MTAB__C.getCode(eb);
}
xdc_runtime_Error_Id xdc_runtime_Error_getId__E( xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_Error_Module__MTAB__C.getId(eb);
}
xdc_String xdc_runtime_Error_getMsg__E( xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_Error_Module__MTAB__C.getMsg(eb);
}
xdc_runtime_Types_Site* xdc_runtime_Error_getSite__E( xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_Error_Module__MTAB__C.getSite(eb);
}
xdc_Void xdc_runtime_Error_raiseX__E( xdc_runtime_Error_Block* eb, xdc_runtime_Types_ModuleId mod, xdc_String file, xdc_Int line, xdc_runtime_Error_Id id, xdc_IArg arg1, xdc_IArg arg2 ) {
    xdc_runtime_Error_Module__MTAB__C.raiseX(eb, mod, file, line, id, arg1, arg2);
}
#endif /* xdc_runtime_Error___ROMPATCH */
xdc_Bool xdc_runtime_Error_check__R( xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_Error_check__F(eb);
}
xdc_Void xdc_runtime_Error_print__R( xdc_runtime_Error_Block* eb ) {
    xdc_runtime_Error_print__F(eb);
}
xdc_Void xdc_runtime_Error_init__R( xdc_runtime_Error_Block* eb ) {
    xdc_runtime_Error_init__F(eb);
}
xdc_runtime_Error_Data* xdc_runtime_Error_getData__R( xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_Error_getData__F(eb);
}
xdc_UInt16 xdc_runtime_Error_getCode__R( xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_Error_getCode__F(eb);
}
xdc_runtime_Error_Id xdc_runtime_Error_getId__R( xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_Error_getId__F(eb);
}
xdc_String xdc_runtime_Error_getMsg__R( xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_Error_getMsg__F(eb);
}
xdc_runtime_Types_Site* xdc_runtime_Error_getSite__R( xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_Error_getSite__F(eb);
}
xdc_Void xdc_runtime_Error_raiseX__R( xdc_runtime_Error_Block* eb, xdc_runtime_Types_ModuleId mod, xdc_String file, xdc_Int line, xdc_runtime_Error_Id id, xdc_IArg arg1, xdc_IArg arg2 ) {
    xdc_runtime_Error_raiseX__F(eb, mod, file, line, id, arg1, arg2);
}

#if defined(xdc_runtime_Error___EXPORT) && defined(__ti__)
#if xdc_runtime_Error___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_check__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_print__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_init__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_getData__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_getCode__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_getId__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_getMsg__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_getSite__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_Error_raiseX__R);
#endif
#endif /* __isrom__ */

#if xdc_runtime_Error___scope != -1
xdc_Bool xdc_runtime_Error_Module__startupDone__S() {

    return 1;
}
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_Gate___used
/*
 *  ======== module Gate ========
 *  Do not modify this file; it is generated from the specification Gate.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_Gate__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Gate.h>
#undef __nested__
#else
#include <xdc/runtime/Gate.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Gate___LOGOBJ) && xdc_runtime_Gate___DGSINCL & 0x1
#define xdc_runtime_Gate___L_ENTRY 1
#else
#define xdc_runtime_Gate___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Gate___LOGOBJ) && xdc_runtime_Gate___DGSINCL & 0x2
#define xdc_runtime_Gate___L_EXIT 1
#else
#define xdc_runtime_Gate___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Gate___LOGOBJ) && xdc_runtime_Gate___DGSINCL & 0x4
#define xdc_runtime_Gate___L_LIFECYCLE 1
#else
#define xdc_runtime_Gate___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_Gate_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Gate_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Gate_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Gate_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Gate_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Gate_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Gate_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Gate_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Gate_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Gate_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Gate_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Gate_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Gate_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Gate_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Gate_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_Gate___scope == -1
#ifdef xdc_runtime_Gate_enterSystem__PATCH
#define __FN__ xdc_runtime_Gate_enterSystem__PATCH
#else
#define __FN__ xdc_runtime_Gate_enterSystem__R
#endif
#else
#define __FN__ xdc_runtime_Gate_enterSystem__F
#endif
xdc_IArg xdc_runtime_Gate_enterSystem__E( void ) {
#if xdc_runtime_Gate___L_EXIT
    xdc_IArg __ret;
#else
#endif
#if xdc_runtime_Gate___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_Gate_enterSystem__ENTRY_EVT);
#endif
#if xdc_runtime_Gate___L_EXIT
    __ret = __FN__();
    xdc_runtime_Log_write1(xdc_runtime_Gate_enterSystem__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_Gate___scope == -1
#ifdef xdc_runtime_Gate_leaveSystem__PATCH
#define __FN__ xdc_runtime_Gate_leaveSystem__PATCH
#else
#define __FN__ xdc_runtime_Gate_leaveSystem__R
#endif
#else
#define __FN__ xdc_runtime_Gate_leaveSystem__F
#endif
xdc_Void xdc_runtime_Gate_leaveSystem__E( xdc_IArg key ) {
#if xdc_runtime_Gate___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Gate_leaveSystem__ENTRY_EVT, (xdc_IArg)key);
#endif
#if xdc_runtime_Gate___L_EXIT
    __FN__(key);
    xdc_runtime_Log_write1(xdc_runtime_Gate_leaveSystem__EXIT_EVT, 0);
#else
    __FN__(key);
#endif
}

#if defined(xdc_runtime_Gate___EXPORT) && defined(__ti__)
#if xdc_runtime_Gate___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Gate_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_Gate_enterSystem__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_Gate_leaveSystem__E);
#endif
__FAR__ xdc_runtime_Gate_Module__MTAB__C__qual xdc_runtime_Gate_MTab__ xdc_runtime_Gate_Module__MTAB__C = {
#if xdc_runtime_Gate___scope == -1
#if xdc_runtime_Gate___L_ENTRY || xdc_runtime_Gate___L_EXIT
    xdc_runtime_Gate_enterSystem__E,
#elif defined(xdc_runtime_Gate_enterSystem__PATCH)
    xdc_runtime_Gate_enterSystem__PATCH,
#else
    xdc_runtime_Gate_enterSystem__R,
#endif
#if xdc_runtime_Gate___L_ENTRY || xdc_runtime_Gate___L_EXIT
    xdc_runtime_Gate_leaveSystem__E,
#elif defined(xdc_runtime_Gate_leaveSystem__PATCH)
    xdc_runtime_Gate_leaveSystem__PATCH,
#else
    xdc_runtime_Gate_leaveSystem__R,
#endif
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_Gate___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_Gate_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Gate_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Gate_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Gate_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Gate_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Gate_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Gate_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Gate_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Gate_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Gate_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Gate_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Gate_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Gate_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Gate_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Gate_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_Gate___scope == -1
#ifdef xdc_runtime_Gate_enterSystem__PATCH
#define __FN__ xdc_runtime_Gate_enterSystem__PATCH
#else
#define __FN__ xdc_runtime_Gate_enterSystem__R
#endif
#else
#define __FN__ xdc_runtime_Gate_enterSystem__F
#endif
xdc_IArg xdc_runtime_Gate_enterSystem__E( void ) {
#if xdc_runtime_Gate___L_EXIT
    xdc_IArg __ret;
#else
#endif
#if xdc_runtime_Gate___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_Gate_enterSystem__ENTRY_EVT);
#endif
#if xdc_runtime_Gate___L_EXIT
    __ret = __FN__();
    xdc_runtime_Log_write1(xdc_runtime_Gate_enterSystem__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_Gate___scope == -1
#ifdef xdc_runtime_Gate_leaveSystem__PATCH
#define __FN__ xdc_runtime_Gate_leaveSystem__PATCH
#else
#define __FN__ xdc_runtime_Gate_leaveSystem__R
#endif
#else
#define __FN__ xdc_runtime_Gate_leaveSystem__F
#endif
xdc_Void xdc_runtime_Gate_leaveSystem__E( xdc_IArg key ) {
#if xdc_runtime_Gate___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Gate_leaveSystem__ENTRY_EVT, (xdc_IArg)key);
#endif
#if xdc_runtime_Gate___L_EXIT
    __FN__(key);
    xdc_runtime_Log_write1(xdc_runtime_Gate_leaveSystem__EXIT_EVT, 0);
#else
    __FN__(key);
#endif
}
#endif /* xdc_runtime_Gate___ROMPATCH */
#ifdef xdc_runtime_Gate___ROMPATCH
xdc_IArg xdc_runtime_Gate_enterSystem__E( void ) {
    return xdc_runtime_Gate_Module__MTAB__C.enterSystem();
}
xdc_Void xdc_runtime_Gate_leaveSystem__E( xdc_IArg key ) {
    xdc_runtime_Gate_Module__MTAB__C.leaveSystem(key);
}
#endif /* xdc_runtime_Gate___ROMPATCH */
xdc_IArg xdc_runtime_Gate_enterSystem__R( void ) {
    return xdc_runtime_Gate_enterSystem__F();
}
xdc_Void xdc_runtime_Gate_leaveSystem__R( xdc_IArg key ) {
    xdc_runtime_Gate_leaveSystem__F(key);
}

#if defined(xdc_runtime_Gate___EXPORT) && defined(__ti__)
#if xdc_runtime_Gate___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Gate_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_Gate_enterSystem__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_Gate_leaveSystem__R);
#endif
#endif /* __isrom__ */

#if xdc_runtime_Gate___scope != -1
xdc_Bool xdc_runtime_Gate_Module__startupDone__S() {

    return 1;
}
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_GateNull___used
/*
 *  ======== module GateNull ========
 *  Do not modify this file; it is generated from the specification GateNull.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_GateNull__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/GateNull.h>
#undef __nested__
#else
#include <xdc/runtime/GateNull.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_GateNull___LOGOBJ) && xdc_runtime_GateNull___DGSINCL & 0x1
#define xdc_runtime_GateNull___L_ENTRY 1
#else
#define xdc_runtime_GateNull___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_GateNull___LOGOBJ) && xdc_runtime_GateNull___DGSINCL & 0x2
#define xdc_runtime_GateNull___L_EXIT 1
#else
#define xdc_runtime_GateNull___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_GateNull___LOGOBJ) && xdc_runtime_GateNull___DGSINCL & 0x4
#define xdc_runtime_GateNull___L_LIFECYCLE 1
#else
#define xdc_runtime_GateNull___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_GateNull_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_GateNull_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_GateNull_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_GateNull_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_GateNull_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_GateNull_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_GateNull_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_GateNull_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_GateNull_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_GateNull_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_GateNull_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_GateNull_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_GateNull_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_GateNull_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_GateNull_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_GateNull___scope == -1
#ifdef xdc_runtime_GateNull_query__PATCH
#define __FN__ xdc_runtime_GateNull_query__PATCH
#else
#define __FN__ xdc_runtime_GateNull_query__R
#endif
#else
#define __FN__ xdc_runtime_GateNull_query__F
#endif
xdc_Bool xdc_runtime_GateNull_query__E( xdc_Int qual ) {
#if xdc_runtime_GateNull___L_EXIT
    xdc_Bool __ret;
#else
#endif
#if xdc_runtime_GateNull___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_GateNull_query__ENTRY_EVT, (xdc_IArg)qual);
#endif
#if xdc_runtime_GateNull___L_EXIT
    __ret = __FN__(qual);
    xdc_runtime_Log_write1(xdc_runtime_GateNull_query__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(qual);
#endif
}
#undef __FN__
#if xdc_runtime_GateNull___scope == -1
#ifdef xdc_runtime_GateNull_enter__PATCH
#define __FN__ xdc_runtime_GateNull_enter__PATCH
#else
#define __FN__ xdc_runtime_GateNull_enter__R
#endif
#else
#define __FN__ xdc_runtime_GateNull_enter__F
#endif
xdc_IArg xdc_runtime_GateNull_enter__E( xdc_runtime_GateNull_Handle _this ) {
#if xdc_runtime_GateNull___L_EXIT
    xdc_IArg __ret;
#else
#endif
#if xdc_runtime_GateNull___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_GateNull_enter__ENTRY_EVT, (xdc_IArg)_this);
#endif
#if xdc_runtime_GateNull___L_EXIT
    __ret = __FN__((void*)_this);
    xdc_runtime_Log_write1(xdc_runtime_GateNull_enter__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__((void*)_this);
#endif
}
#undef __FN__
#if xdc_runtime_GateNull___scope == -1
#ifdef xdc_runtime_GateNull_leave__PATCH
#define __FN__ xdc_runtime_GateNull_leave__PATCH
#else
#define __FN__ xdc_runtime_GateNull_leave__R
#endif
#else
#define __FN__ xdc_runtime_GateNull_leave__F
#endif
xdc_Void xdc_runtime_GateNull_leave__E( xdc_runtime_GateNull_Handle _this, xdc_IArg key ) {
#if xdc_runtime_GateNull___L_ENTRY
    xdc_runtime_Log_write2(xdc_runtime_GateNull_leave__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)key);
#endif
#if xdc_runtime_GateNull___L_EXIT
    __FN__((void*)_this, key);
    xdc_runtime_Log_write1(xdc_runtime_GateNull_leave__EXIT_EVT, 0);
#else
    __FN__((void*)_this, key);
#endif
}
typedef struct { xdc_runtime_GateNull_Object2__ s0; char c; } xdc_runtime_GateNull___S1;
__FAR__ xdc_runtime_GateNull_Object__DESC__C__qual xdc_runtime_Core_ObjDesc xdc_runtime_GateNull_Object__DESC__C = {
#ifdef xdc_runtime_GateNull___FXNTAB
    (Ptr)&xdc_runtime_GateNull_Module__FXNS__C, /* fxnTab */
#else
    (Ptr)0, /* fxnTab */
#endif
    &xdc_runtime_GateNull_Module__root__V.hdr.link, /* modLink */
    sizeof(xdc_runtime_GateNull___S1) - sizeof(xdc_runtime_GateNull_Object2__), /* objAlign */
#ifdef xdc_runtime_GateNull___OBJHEAP
    xdc_runtime_GateNull___OBJHEAP, /* objHeap */
#else
    0, /* objHeap */
#endif
#ifdef xdc_runtime_GateNull___NAMEDINST
    offsetof(xdc_runtime_GateNull_Object__, __name), /* objName */
#else
    0, /* objName */
#endif
    sizeof(xdc_runtime_GateNull_Object2__), /* objSize */
    (Ptr)&xdc_runtime_GateNull_Object__PARAMS__C, /* prmsInit */
    sizeof(xdc_runtime_GateNull_Params), /* prmsSize */
};

#if defined(xdc_runtime_GateNull___EXPORT) && defined(__ti__)
#if xdc_runtime_GateNull___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_Module__startupDone__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_Handle__label__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_Object__create__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_Object__delete__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_Object__destruct__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_Object__get__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_Params__init__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_query__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_enter__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_leave__E);
#endif
#ifdef xdc_runtime_GateNull___FXNTAB
#if xdc_runtime_GateNull___scope == -1 || !defined(__xdc_runtime_IModule_Interface__BASE__CR)
#ifndef __xdc_runtime_IModule_Interface__BASE__C
#define __xdc_runtime_IModule_Interface__BASE__C
__FAR__ xdc_runtime_IModule_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_IModule_Interface__BASE__C = {0};
#endif
#endif
#if xdc_runtime_GateNull___scope == -1 || !defined(__xdc_runtime_IGateProvider_Interface__BASE__CR)
#ifndef __xdc_runtime_IGateProvider_Interface__BASE__C
#define __xdc_runtime_IGateProvider_Interface__BASE__C
__FAR__ xdc_runtime_IGateProvider_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_IGateProvider_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};
#endif
#endif

__FAR__ xdc_runtime_GateNull_Module__FXNS__C__qual xdc_runtime_GateNull_Fxns__ xdc_runtime_GateNull_Module__FXNS__C = {
    /* base__ */ (void*)&xdc_runtime_IGateProvider_Interface__BASE__C,
    &xdc_runtime_GateNull_Module__FXNS__C.__sfxns, /* __sysp */
    xdc_runtime_GateNull_query__E,
    xdc_runtime_GateNull_enter__E,
    xdc_runtime_GateNull_leave__E,
    {

#ifdef xdc_runtime_GateNull___OBJHEAP
        xdc_runtime_GateNull_Object__create__S,
#else
        /* create__ */ 0,
#endif
#ifdef xdc_runtime_GateNull___DELETE
        xdc_runtime_GateNull_Object__delete__S,
#else
        /* delete__ */ 0,
#endif
        xdc_runtime_GateNull_Handle__label__S,
        xdc_runtime_GateNull_Module__id__D,
    } /* __sfxns */
};
#endif
__FAR__ xdc_runtime_GateNull_Module__MTAB__C__qual xdc_runtime_GateNull_MTab__ xdc_runtime_GateNull_Module__MTAB__C = {
#if xdc_runtime_GateNull___scope == -1
#if xdc_runtime_GateNull___L_ENTRY || xdc_runtime_GateNull___L_EXIT
    xdc_runtime_GateNull_query__E,
#elif defined(xdc_runtime_GateNull_query__PATCH)
    xdc_runtime_GateNull_query__PATCH,
#else
    xdc_runtime_GateNull_query__R,
#endif
#if xdc_runtime_GateNull___L_ENTRY || xdc_runtime_GateNull___L_EXIT
    xdc_runtime_GateNull_enter__E,
#elif defined(xdc_runtime_GateNull_enter__PATCH)
    xdc_runtime_GateNull_enter__PATCH,
#else
    xdc_runtime_GateNull_enter__R,
#endif
#if xdc_runtime_GateNull___L_ENTRY || xdc_runtime_GateNull___L_EXIT
    xdc_runtime_GateNull_leave__E,
#elif defined(xdc_runtime_GateNull_leave__PATCH)
    xdc_runtime_GateNull_leave__PATCH,
#else
    xdc_runtime_GateNull_leave__R,
#endif
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_GateNull___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_GateNull_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_GateNull_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_GateNull_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_GateNull_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_GateNull_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_GateNull_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_GateNull_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_GateNull_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_GateNull_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_GateNull_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_GateNull_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_GateNull_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_GateNull_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_GateNull_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_GateNull_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_GateNull___scope == -1
#ifdef xdc_runtime_GateNull_query__PATCH
#define __FN__ xdc_runtime_GateNull_query__PATCH
#else
#define __FN__ xdc_runtime_GateNull_query__R
#endif
#else
#define __FN__ xdc_runtime_GateNull_query__F
#endif
xdc_Bool xdc_runtime_GateNull_query__E( xdc_Int qual ) {
#if xdc_runtime_GateNull___L_EXIT
    xdc_Bool __ret;
#else
#endif
#if xdc_runtime_GateNull___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_GateNull_query__ENTRY_EVT, (xdc_IArg)qual);
#endif
#if xdc_runtime_GateNull___L_EXIT
    __ret = __FN__(qual);
    xdc_runtime_Log_write1(xdc_runtime_GateNull_query__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(qual);
#endif
}
#undef __FN__
#if xdc_runtime_GateNull___scope == -1
#ifdef xdc_runtime_GateNull_enter__PATCH
#define __FN__ xdc_runtime_GateNull_enter__PATCH
#else
#define __FN__ xdc_runtime_GateNull_enter__R
#endif
#else
#define __FN__ xdc_runtime_GateNull_enter__F
#endif
xdc_IArg xdc_runtime_GateNull_enter__E( xdc_runtime_GateNull_Handle _this ) {
#if xdc_runtime_GateNull___L_EXIT
    xdc_IArg __ret;
#else
#endif
#if xdc_runtime_GateNull___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_GateNull_enter__ENTRY_EVT, (xdc_IArg)_this);
#endif
#if xdc_runtime_GateNull___L_EXIT
    __ret = __FN__((void*)_this);
    xdc_runtime_Log_write1(xdc_runtime_GateNull_enter__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__((void*)_this);
#endif
}
#undef __FN__
#if xdc_runtime_GateNull___scope == -1
#ifdef xdc_runtime_GateNull_leave__PATCH
#define __FN__ xdc_runtime_GateNull_leave__PATCH
#else
#define __FN__ xdc_runtime_GateNull_leave__R
#endif
#else
#define __FN__ xdc_runtime_GateNull_leave__F
#endif
xdc_Void xdc_runtime_GateNull_leave__E( xdc_runtime_GateNull_Handle _this, xdc_IArg key ) {
#if xdc_runtime_GateNull___L_ENTRY
    xdc_runtime_Log_write2(xdc_runtime_GateNull_leave__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)key);
#endif
#if xdc_runtime_GateNull___L_EXIT
    __FN__((void*)_this, key);
    xdc_runtime_Log_write1(xdc_runtime_GateNull_leave__EXIT_EVT, 0);
#else
    __FN__((void*)_this, key);
#endif
}
#endif /* xdc_runtime_GateNull___ROMPATCH */
#ifdef xdc_runtime_GateNull___ROMPATCH
xdc_Bool xdc_runtime_GateNull_query__E( xdc_Int qual ) {
    return xdc_runtime_GateNull_Module__MTAB__C.query(qual);
}
xdc_IArg xdc_runtime_GateNull_enter__E( xdc_runtime_GateNull_Handle _this ) {
    return xdc_runtime_GateNull_Module__MTAB__C.enter((void*)_this);
}
xdc_Void xdc_runtime_GateNull_leave__E( xdc_runtime_GateNull_Handle _this, xdc_IArg key ) {
    xdc_runtime_GateNull_Module__MTAB__C.leave((void*)_this, key);
}
#endif /* xdc_runtime_GateNull___ROMPATCH */
xdc_Bool xdc_runtime_GateNull_query__R( xdc_Int qual ) {
    return xdc_runtime_GateNull_query__F(qual);
}
xdc_IArg xdc_runtime_GateNull_enter__R( xdc_runtime_GateNull_Handle _this ) {
    return xdc_runtime_GateNull_enter__F((void*)_this);
}
xdc_Void xdc_runtime_GateNull_leave__R( xdc_runtime_GateNull_Handle _this, xdc_IArg key ) {
    xdc_runtime_GateNull_leave__F((void*)_this, key);
}

#if defined(xdc_runtime_GateNull___EXPORT) && defined(__ti__)
#if xdc_runtime_GateNull___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_Module__startupDone__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_Handle__label__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_Object__create__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_Object__delete__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_Object__destruct__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_Object__get__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_Params__init__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_query__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_enter__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_GateNull_leave__R);
#endif
#endif /* __isrom__ */

#if xdc_runtime_GateNull___scope != -1
xdc_Bool xdc_runtime_GateNull_Module__startupDone__S() {

    return 1;
}
xdc_runtime_Types_Label* xdc_runtime_GateNull_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab ) {
    lab->oaddr = obj;
    lab->modid = xdc_runtime_GateNull_Module__id__D;
#ifdef xdc_runtime_GateNull___NAMEDINST
    xdc_runtime_Core_assignLabel(lab, ((xdc_runtime_GateNull_Object__*)obj)->__name, 1);
#else
    xdc_runtime_Core_assignLabel(lab, 0, 0);
#endif
    return lab;
}
xdc_Void xdc_runtime_GateNull_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) {
#ifdef xdc_runtime_GateNull___OBJHEAP
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &xdc_runtime_GateNull_Object__PARAMS__C), psz, isz);
#endif
}
xdc_Ptr xdc_runtime_GateNull_Object__get__S( xdc_Ptr oa, xdc_Int i ) {
    if (oa) return ((xdc_runtime_GateNull_Object*)oa) + i;
    if (xdc_runtime_GateNull_Object__count__C == 0) return 0;
    return ((xdc_runtime_GateNull_Object*)xdc_runtime_GateNull_Object__table__C) + i;
}

#ifdef xdc_runtime_GateNull___OBJHEAP
extern xdc_Ptr xdc_runtime_GateNull_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __psz, xdc_runtime_Error_Block* __eb ) {
    xdc_runtime_GateNull_Params prms;
    xdc_runtime_GateNull_Object* obj;
    obj = xdc_runtime_Core_createObject__I(&xdc_runtime_GateNull_Object__DESC__C, __oa, __osz, &prms, __pa, __psz, __eb);
    if (!obj) return 0;
#ifdef xdc_runtime_GateNull___DELETE
#define xdc_runtime_GateNull___ISTAT 
#else
#define xdc_runtime_GateNull___ISTAT
#endif
#if xdc_runtime_GateNull___L_LIFECYCLE
#ifdef xdc_runtime_GateNull___NAMEDINST
    xdc_runtime_Log_write2(__oa ? xdc_runtime_Log_L_construct : xdc_runtime_Log_L_create, (xdc_IArg)obj, (xdc_IArg)(((xdc_runtime_GateNull_Object__*)obj)->__name));
#else
    xdc_runtime_Log_write2(__oa ? xdc_runtime_Log_L_construct : xdc_runtime_Log_L_create, (xdc_IArg)obj, 0);
#endif
#endif
    return obj;
}
#else
extern xdc_Ptr xdc_runtime_GateNull_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __sz, xdc_runtime_Error_Block* __eb ) {
    xdc_runtime_Error_raiseX(NULL, xdc_runtime_GateNull_Module__id__C, NULL, 0, xdc_runtime_Error_E_generic, (xdc_IArg)"create policy error", 0);
    return 0;
}
#endif

#ifdef xdc_runtime_GateNull___DELETE
extern xdc_Void xdc_runtime_GateNull_Object__destruct__S( xdc_Ptr obj ) {
#if xdc_runtime_GateNull___L_LIFECYCLE
    xdc_runtime_Log_write1(xdc_runtime_Log_L_destruct, (xdc_IArg)obj);
#endif
    xdc_runtime_Core_deleteObject__I(&xdc_runtime_GateNull_Object__DESC__C, obj, 0, -1, TRUE);
}
extern xdc_Void xdc_runtime_GateNull_Object__delete__S( xdc_Ptr instp ) {
#if xdc_runtime_GateNull___L_LIFECYCLE
    xdc_runtime_Log_write1(xdc_runtime_Log_L_delete, (xdc_IArg)(*((xdc_runtime_GateNull_Object**)instp)));
#endif
    xdc_runtime_Core_deleteObject__I(&xdc_runtime_GateNull_Object__DESC__C, *((xdc_runtime_GateNull_Object**)instp), 0, -1, FALSE);
    *((xdc_runtime_GateNull_Handle*)instp) = 0;
}
#else
extern xdc_Void xdc_runtime_GateNull_Object__destruct__S( xdc_Ptr obj ) {
    xdc_runtime_Error_raiseX(NULL, xdc_runtime_GateNull_Module__id__C, NULL, 0, xdc_runtime_Error_E_generic, (xdc_IArg)"delete policy error", 0);
}
extern xdc_Void xdc_runtime_GateNull_Object__delete__S( xdc_Ptr instp ) {
    xdc_runtime_Error_raiseX(NULL, xdc_runtime_GateNull_Module__id__C, NULL, 0, xdc_runtime_Error_E_generic, (xdc_IArg)"delete policy error", 0);
}
#endif
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_Log___used
/*
 *  ======== module Log ========
 *  Do not modify this file; it is generated from the specification Log.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_Log__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Log.h>
#undef __nested__
#else
#include <xdc/runtime/Log.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Log___LOGOBJ) && xdc_runtime_Log___DGSINCL & 0x1
#define xdc_runtime_Log___L_ENTRY 1
#else
#define xdc_runtime_Log___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Log___LOGOBJ) && xdc_runtime_Log___DGSINCL & 0x2
#define xdc_runtime_Log___L_EXIT 1
#else
#define xdc_runtime_Log___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Log___LOGOBJ) && xdc_runtime_Log___DGSINCL & 0x4
#define xdc_runtime_Log___L_LIFECYCLE 1
#else
#define xdc_runtime_Log___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_Log_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Log_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Log_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Log_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Log_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Log_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Log_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Log_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Log_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Log_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Log_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Log_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Log_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Log_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Log_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_Log___scope == -1
#ifdef xdc_runtime_Log_doPrint__PATCH
#define __FN__ xdc_runtime_Log_doPrint__PATCH
#else
#define __FN__ xdc_runtime_Log_doPrint__R
#endif
#else
#define __FN__ xdc_runtime_Log_doPrint__F
#endif
xdc_Void xdc_runtime_Log_doPrint__E( xdc_runtime_Log_EventRec* evrec ) {
#if xdc_runtime_Log___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Log_doPrint__ENTRY_EVT, (xdc_IArg)evrec);
#endif
#if xdc_runtime_Log___L_EXIT
    __FN__(evrec);
    xdc_runtime_Log_write1(xdc_runtime_Log_doPrint__EXIT_EVT, 0);
#else
    __FN__(evrec);
#endif
}

#if defined(xdc_runtime_Log___EXPORT) && defined(__ti__)
#if xdc_runtime_Log___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Log_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_Log_doPrint__E);
#endif
__FAR__ xdc_runtime_Log_Module__MTAB__C__qual xdc_runtime_Log_MTab__ xdc_runtime_Log_Module__MTAB__C = {
#if xdc_runtime_Log___scope == -1
#if xdc_runtime_Log___L_ENTRY || xdc_runtime_Log___L_EXIT
    xdc_runtime_Log_doPrint__E,
#elif defined(xdc_runtime_Log_doPrint__PATCH)
    xdc_runtime_Log_doPrint__PATCH,
#else
    xdc_runtime_Log_doPrint__R,
#endif
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_Log___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_Log_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Log_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Log_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Log_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Log_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Log_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Log_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Log_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Log_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Log_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Log_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Log_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Log_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Log_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Log_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_Log___scope == -1
#ifdef xdc_runtime_Log_doPrint__PATCH
#define __FN__ xdc_runtime_Log_doPrint__PATCH
#else
#define __FN__ xdc_runtime_Log_doPrint__R
#endif
#else
#define __FN__ xdc_runtime_Log_doPrint__F
#endif
xdc_Void xdc_runtime_Log_doPrint__E( xdc_runtime_Log_EventRec* evrec ) {
#if xdc_runtime_Log___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Log_doPrint__ENTRY_EVT, (xdc_IArg)evrec);
#endif
#if xdc_runtime_Log___L_EXIT
    __FN__(evrec);
    xdc_runtime_Log_write1(xdc_runtime_Log_doPrint__EXIT_EVT, 0);
#else
    __FN__(evrec);
#endif
}
#endif /* xdc_runtime_Log___ROMPATCH */
#ifdef xdc_runtime_Log___ROMPATCH
xdc_Void xdc_runtime_Log_doPrint__E( xdc_runtime_Log_EventRec* evrec ) {
    xdc_runtime_Log_Module__MTAB__C.doPrint(evrec);
}
#endif /* xdc_runtime_Log___ROMPATCH */
xdc_Void xdc_runtime_Log_doPrint__R( xdc_runtime_Log_EventRec* evrec ) {
    xdc_runtime_Log_doPrint__F(evrec);
}

#if defined(xdc_runtime_Log___EXPORT) && defined(__ti__)
#if xdc_runtime_Log___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Log_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_Log_doPrint__R);
#endif
#endif /* __isrom__ */

#if xdc_runtime_Log___scope != -1
xdc_Bool xdc_runtime_Log_Module__startupDone__S() {

    return 1;
}
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_LoggerBuf___used
/*
 *  ======== module LoggerBuf ========
 *  Do not modify this file; it is generated from the specification LoggerBuf.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_LoggerBuf__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/LoggerBuf.h>
#undef __nested__
#else
#include <xdc/runtime/LoggerBuf.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_LoggerBuf___LOGOBJ) && xdc_runtime_LoggerBuf___DGSINCL & 0x1
#define xdc_runtime_LoggerBuf___L_ENTRY 1
#else
#define xdc_runtime_LoggerBuf___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_LoggerBuf___LOGOBJ) && xdc_runtime_LoggerBuf___DGSINCL & 0x2
#define xdc_runtime_LoggerBuf___L_EXIT 1
#else
#define xdc_runtime_LoggerBuf___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_LoggerBuf___LOGOBJ) && xdc_runtime_LoggerBuf___DGSINCL & 0x4
#define xdc_runtime_LoggerBuf___L_LIFECYCLE 1
#else
#define xdc_runtime_LoggerBuf___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_LoggerBuf_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_LoggerBuf_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_LoggerBuf_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_LoggerBuf_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_LoggerBuf_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_LoggerBuf_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_LoggerBuf_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_LoggerBuf_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_LoggerBuf_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_LoggerBuf_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_LoggerBuf_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_LoggerBuf_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_LoggerBuf_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_LoggerBuf_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_LoggerBuf_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_LoggerBuf___scope == -1
#ifdef xdc_runtime_LoggerBuf_write4__PATCH
#define __FN__ xdc_runtime_LoggerBuf_write4__PATCH
#else
#define __FN__ xdc_runtime_LoggerBuf_write4__R
#endif
#else
#define __FN__ xdc_runtime_LoggerBuf_write4__F
#endif
xdc_Void xdc_runtime_LoggerBuf_write4__E( xdc_runtime_LoggerBuf_Handle _this, xdc_runtime_Types_EventId evt, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4 ) {
#if xdc_runtime_LoggerBuf___L_ENTRY
    xdc_runtime_Log_write6(xdc_runtime_LoggerBuf_write4__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)evt, (xdc_IArg)a1, (xdc_IArg)a2, (xdc_IArg)a3, (xdc_IArg)a4);
#endif
#if xdc_runtime_LoggerBuf___L_EXIT
    __FN__((void*)_this, evt, a1, a2, a3, a4);
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_write4__EXIT_EVT, 0);
#else
    __FN__((void*)_this, evt, a1, a2, a3, a4);
#endif
}
#undef __FN__
#if xdc_runtime_LoggerBuf___scope == -1
#ifdef xdc_runtime_LoggerBuf_write8__PATCH
#define __FN__ xdc_runtime_LoggerBuf_write8__PATCH
#else
#define __FN__ xdc_runtime_LoggerBuf_write8__R
#endif
#else
#define __FN__ xdc_runtime_LoggerBuf_write8__F
#endif
xdc_Void xdc_runtime_LoggerBuf_write8__E( xdc_runtime_LoggerBuf_Handle _this, xdc_runtime_Types_EventId evt, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4, xdc_IArg a5, xdc_IArg a6, xdc_IArg a7, xdc_IArg a8 ) {
#if xdc_runtime_LoggerBuf___L_ENTRY
    xdc_runtime_Log_write8(xdc_runtime_LoggerBuf_write8__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)evt, (xdc_IArg)a1, (xdc_IArg)a2, (xdc_IArg)a3, (xdc_IArg)a4, (xdc_IArg)a5, (xdc_IArg)a6);
#endif
#if xdc_runtime_LoggerBuf___L_EXIT
    __FN__((void*)_this, evt, a1, a2, a3, a4, a5, a6, a7, a8);
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_write8__EXIT_EVT, 0);
#else
    __FN__((void*)_this, evt, a1, a2, a3, a4, a5, a6, a7, a8);
#endif
}
#undef __FN__
#if xdc_runtime_LoggerBuf___scope == -1
#ifdef xdc_runtime_LoggerBuf_flushAll__PATCH
#define __FN__ xdc_runtime_LoggerBuf_flushAll__PATCH
#else
#define __FN__ xdc_runtime_LoggerBuf_flushAll__R
#endif
#else
#define __FN__ xdc_runtime_LoggerBuf_flushAll__F
#endif
xdc_Void xdc_runtime_LoggerBuf_flushAll__E( void ) {
#if xdc_runtime_LoggerBuf___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_LoggerBuf_flushAll__ENTRY_EVT);
#endif
#if xdc_runtime_LoggerBuf___L_EXIT
    __FN__();
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_flushAll__EXIT_EVT, 0);
#else
    __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_LoggerBuf___scope == -1
#ifdef xdc_runtime_LoggerBuf_flushAllInternal__PATCH
#define __FN__ xdc_runtime_LoggerBuf_flushAllInternal__PATCH
#else
#define __FN__ xdc_runtime_LoggerBuf_flushAllInternal__R
#endif
#else
#define __FN__ xdc_runtime_LoggerBuf_flushAllInternal__F
#endif
xdc_Void xdc_runtime_LoggerBuf_flushAllInternal__E( xdc_Int stat ) {
#if xdc_runtime_LoggerBuf___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_flushAllInternal__ENTRY_EVT, (xdc_IArg)stat);
#endif
#if xdc_runtime_LoggerBuf___L_EXIT
    __FN__(stat);
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_flushAllInternal__EXIT_EVT, 0);
#else
    __FN__(stat);
#endif
}
#undef __FN__
#if xdc_runtime_LoggerBuf___scope == -1
#ifdef xdc_runtime_LoggerBuf_enable__PATCH
#define __FN__ xdc_runtime_LoggerBuf_enable__PATCH
#else
#define __FN__ xdc_runtime_LoggerBuf_enable__R
#endif
#else
#define __FN__ xdc_runtime_LoggerBuf_enable__F
#endif
xdc_Void xdc_runtime_LoggerBuf_enable__E( xdc_runtime_LoggerBuf_Handle _this ) {
#if xdc_runtime_LoggerBuf___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_enable__ENTRY_EVT, (xdc_IArg)_this);
#endif
#if xdc_runtime_LoggerBuf___L_EXIT
    __FN__((void*)_this);
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_enable__EXIT_EVT, 0);
#else
    __FN__((void*)_this);
#endif
}
#undef __FN__
#if xdc_runtime_LoggerBuf___scope == -1
#ifdef xdc_runtime_LoggerBuf_disable__PATCH
#define __FN__ xdc_runtime_LoggerBuf_disable__PATCH
#else
#define __FN__ xdc_runtime_LoggerBuf_disable__R
#endif
#else
#define __FN__ xdc_runtime_LoggerBuf_disable__F
#endif
xdc_Void xdc_runtime_LoggerBuf_disable__E( xdc_runtime_LoggerBuf_Handle _this ) {
#if xdc_runtime_LoggerBuf___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_disable__ENTRY_EVT, (xdc_IArg)_this);
#endif
#if xdc_runtime_LoggerBuf___L_EXIT
    __FN__((void*)_this);
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_disable__EXIT_EVT, 0);
#else
    __FN__((void*)_this);
#endif
}
#undef __FN__
#if xdc_runtime_LoggerBuf___scope == -1
#ifdef xdc_runtime_LoggerBuf_reset__PATCH
#define __FN__ xdc_runtime_LoggerBuf_reset__PATCH
#else
#define __FN__ xdc_runtime_LoggerBuf_reset__R
#endif
#else
#define __FN__ xdc_runtime_LoggerBuf_reset__F
#endif
xdc_Void xdc_runtime_LoggerBuf_reset__E( xdc_runtime_LoggerBuf_Handle _this ) {
#if xdc_runtime_LoggerBuf___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_reset__ENTRY_EVT, (xdc_IArg)_this);
#endif
#if xdc_runtime_LoggerBuf___L_EXIT
    __FN__((void*)_this);
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_reset__EXIT_EVT, 0);
#else
    __FN__((void*)_this);
#endif
}
#undef __FN__
#if xdc_runtime_LoggerBuf___scope == -1
#ifdef xdc_runtime_LoggerBuf_flush__PATCH
#define __FN__ xdc_runtime_LoggerBuf_flush__PATCH
#else
#define __FN__ xdc_runtime_LoggerBuf_flush__R
#endif
#else
#define __FN__ xdc_runtime_LoggerBuf_flush__F
#endif
xdc_Void xdc_runtime_LoggerBuf_flush__E( xdc_runtime_LoggerBuf_Handle _this ) {
#if xdc_runtime_LoggerBuf___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_flush__ENTRY_EVT, (xdc_IArg)_this);
#endif
#if xdc_runtime_LoggerBuf___L_EXIT
    __FN__((void*)_this);
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_flush__EXIT_EVT, 0);
#else
    __FN__((void*)_this);
#endif
}
#undef __FN__
#if xdc_runtime_LoggerBuf___scope == -1
#ifdef xdc_runtime_LoggerBuf_getNextEntry__PATCH
#define __FN__ xdc_runtime_LoggerBuf_getNextEntry__PATCH
#else
#define __FN__ xdc_runtime_LoggerBuf_getNextEntry__R
#endif
#else
#define __FN__ xdc_runtime_LoggerBuf_getNextEntry__F
#endif
xdc_Int xdc_runtime_LoggerBuf_getNextEntry__E( xdc_runtime_LoggerBuf_Handle _this, xdc_runtime_Log_EventRec* evtRec ) {
#if xdc_runtime_LoggerBuf___L_EXIT
    xdc_Int __ret;
#else
#endif
#if xdc_runtime_LoggerBuf___L_ENTRY
    xdc_runtime_Log_write2(xdc_runtime_LoggerBuf_getNextEntry__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)evtRec);
#endif
#if xdc_runtime_LoggerBuf___L_EXIT
    __ret = __FN__((void*)_this, evtRec);
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_getNextEntry__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__((void*)_this, evtRec);
#endif
}
#if xdc_runtime_LoggerBuf___scope == -1
xdc_Int xdc_runtime_LoggerBuf_Module_startup__E( xdc_Int state ) { return xdc_runtime_LoggerBuf_Module_startup__R(state); }
#else
xdc_Int xdc_runtime_LoggerBuf_Module_startup__E( xdc_Int state ) { return xdc_runtime_LoggerBuf_Module_startup__F(state); }
#endif
typedef struct { xdc_runtime_LoggerBuf_Object2__ s0; char c; } xdc_runtime_LoggerBuf___S1;
__FAR__ xdc_runtime_LoggerBuf_Object__DESC__C__qual xdc_runtime_Core_ObjDesc xdc_runtime_LoggerBuf_Object__DESC__C = {
#ifdef xdc_runtime_LoggerBuf___FXNTAB
    (Ptr)&xdc_runtime_LoggerBuf_Module__FXNS__C, /* fxnTab */
#else
    (Ptr)0, /* fxnTab */
#endif
    &xdc_runtime_LoggerBuf_Module__root__V.hdr.link, /* modLink */
    sizeof(xdc_runtime_LoggerBuf___S1) - sizeof(xdc_runtime_LoggerBuf_Object2__), /* objAlign */
#ifdef xdc_runtime_LoggerBuf___OBJHEAP
    xdc_runtime_LoggerBuf___OBJHEAP, /* objHeap */
#else
    0, /* objHeap */
#endif
#ifdef xdc_runtime_LoggerBuf___NAMEDINST
    offsetof(xdc_runtime_LoggerBuf_Object__, __name), /* objName */
#else
    0, /* objName */
#endif
    sizeof(xdc_runtime_LoggerBuf_Object2__), /* objSize */
    (Ptr)&xdc_runtime_LoggerBuf_Object__PARAMS__C, /* prmsInit */
    sizeof(xdc_runtime_LoggerBuf_Params), /* prmsSize */
};

#if defined(xdc_runtime_LoggerBuf___EXPORT) && defined(__ti__)
#if xdc_runtime_LoggerBuf___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_Module__startupDone__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_Handle__label__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_Object__create__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_Object__delete__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_Object__destruct__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_Object__get__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_Params__init__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_Module_startup__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_write4__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_write8__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_flushAll__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_flushAllInternal__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_enable__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_disable__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_reset__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_flush__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_getNextEntry__E);
#endif
#ifdef xdc_runtime_LoggerBuf___FXNTAB
#if xdc_runtime_LoggerBuf___scope == -1 || !defined(__xdc_runtime_IModule_Interface__BASE__CR)
#ifndef __xdc_runtime_IModule_Interface__BASE__C
#define __xdc_runtime_IModule_Interface__BASE__C
__FAR__ xdc_runtime_IModule_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_IModule_Interface__BASE__C = {0};
#endif
#endif
#if xdc_runtime_LoggerBuf___scope == -1 || !defined(__xdc_runtime_ILogger_Interface__BASE__CR)
#ifndef __xdc_runtime_ILogger_Interface__BASE__C
#define __xdc_runtime_ILogger_Interface__BASE__C
__FAR__ xdc_runtime_ILogger_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_ILogger_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};
#endif
#endif

__FAR__ xdc_runtime_LoggerBuf_Module__FXNS__C__qual xdc_runtime_LoggerBuf_Fxns__ xdc_runtime_LoggerBuf_Module__FXNS__C = {
    /* base__ */ (void*)&xdc_runtime_ILogger_Interface__BASE__C,
    &xdc_runtime_LoggerBuf_Module__FXNS__C.__sfxns, /* __sysp */
    xdc_runtime_LoggerBuf_write4__E,
    xdc_runtime_LoggerBuf_write8__E,
    {

        /* create__ */ 0,
#ifdef xdc_runtime_LoggerBuf___DELETE
        xdc_runtime_LoggerBuf_Object__delete__S,
#else
        /* delete__ */ 0,
#endif
        xdc_runtime_LoggerBuf_Handle__label__S,
        xdc_runtime_LoggerBuf_Module__id__D,
    } /* __sfxns */
};
#endif
__FAR__ xdc_runtime_LoggerBuf_Module__MTAB__C__qual xdc_runtime_LoggerBuf_MTab__ xdc_runtime_LoggerBuf_Module__MTAB__C = {
#if xdc_runtime_LoggerBuf___scope == -1
#if xdc_runtime_LoggerBuf___L_ENTRY || xdc_runtime_LoggerBuf___L_EXIT
    xdc_runtime_LoggerBuf_write4__E,
#elif defined(xdc_runtime_LoggerBuf_write4__PATCH)
    xdc_runtime_LoggerBuf_write4__PATCH,
#else
    xdc_runtime_LoggerBuf_write4__R,
#endif
#if xdc_runtime_LoggerBuf___L_ENTRY || xdc_runtime_LoggerBuf___L_EXIT
    xdc_runtime_LoggerBuf_write8__E,
#elif defined(xdc_runtime_LoggerBuf_write8__PATCH)
    xdc_runtime_LoggerBuf_write8__PATCH,
#else
    xdc_runtime_LoggerBuf_write8__R,
#endif
#if xdc_runtime_LoggerBuf___L_ENTRY || xdc_runtime_LoggerBuf___L_EXIT
    xdc_runtime_LoggerBuf_flushAll__E,
#elif defined(xdc_runtime_LoggerBuf_flushAll__PATCH)
    xdc_runtime_LoggerBuf_flushAll__PATCH,
#else
    xdc_runtime_LoggerBuf_flushAll__R,
#endif
#if xdc_runtime_LoggerBuf___L_ENTRY || xdc_runtime_LoggerBuf___L_EXIT
    xdc_runtime_LoggerBuf_flushAllInternal__E,
#elif defined(xdc_runtime_LoggerBuf_flushAllInternal__PATCH)
    xdc_runtime_LoggerBuf_flushAllInternal__PATCH,
#else
    xdc_runtime_LoggerBuf_flushAllInternal__R,
#endif
#if xdc_runtime_LoggerBuf___L_ENTRY || xdc_runtime_LoggerBuf___L_EXIT
    xdc_runtime_LoggerBuf_enable__E,
#elif defined(xdc_runtime_LoggerBuf_enable__PATCH)
    xdc_runtime_LoggerBuf_enable__PATCH,
#else
    xdc_runtime_LoggerBuf_enable__R,
#endif
#if xdc_runtime_LoggerBuf___L_ENTRY || xdc_runtime_LoggerBuf___L_EXIT
    xdc_runtime_LoggerBuf_disable__E,
#elif defined(xdc_runtime_LoggerBuf_disable__PATCH)
    xdc_runtime_LoggerBuf_disable__PATCH,
#else
    xdc_runtime_LoggerBuf_disable__R,
#endif
#if xdc_runtime_LoggerBuf___L_ENTRY || xdc_runtime_LoggerBuf___L_EXIT
    xdc_runtime_LoggerBuf_reset__E,
#elif defined(xdc_runtime_LoggerBuf_reset__PATCH)
    xdc_runtime_LoggerBuf_reset__PATCH,
#else
    xdc_runtime_LoggerBuf_reset__R,
#endif
#if xdc_runtime_LoggerBuf___L_ENTRY || xdc_runtime_LoggerBuf___L_EXIT
    xdc_runtime_LoggerBuf_flush__E,
#elif defined(xdc_runtime_LoggerBuf_flush__PATCH)
    xdc_runtime_LoggerBuf_flush__PATCH,
#else
    xdc_runtime_LoggerBuf_flush__R,
#endif
#if xdc_runtime_LoggerBuf___L_ENTRY || xdc_runtime_LoggerBuf___L_EXIT
    xdc_runtime_LoggerBuf_getNextEntry__E,
#elif defined(xdc_runtime_LoggerBuf_getNextEntry__PATCH)
    xdc_runtime_LoggerBuf_getNextEntry__PATCH,
#else
    xdc_runtime_LoggerBuf_getNextEntry__R,
#endif
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_LoggerBuf___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_LoggerBuf_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_LoggerBuf_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_LoggerBuf_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_LoggerBuf_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_LoggerBuf_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_LoggerBuf_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_LoggerBuf_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_LoggerBuf_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_LoggerBuf_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_LoggerBuf_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_LoggerBuf_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_LoggerBuf_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_LoggerBuf_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_LoggerBuf_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_LoggerBuf_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_LoggerBuf___scope == -1
#ifdef xdc_runtime_LoggerBuf_write4__PATCH
#define __FN__ xdc_runtime_LoggerBuf_write4__PATCH
#else
#define __FN__ xdc_runtime_LoggerBuf_write4__R
#endif
#else
#define __FN__ xdc_runtime_LoggerBuf_write4__F
#endif
xdc_Void xdc_runtime_LoggerBuf_write4__E( xdc_runtime_LoggerBuf_Handle _this, xdc_runtime_Types_EventId evt, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4 ) {
#if xdc_runtime_LoggerBuf___L_ENTRY
    xdc_runtime_Log_write6(xdc_runtime_LoggerBuf_write4__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)evt, (xdc_IArg)a1, (xdc_IArg)a2, (xdc_IArg)a3, (xdc_IArg)a4);
#endif
#if xdc_runtime_LoggerBuf___L_EXIT
    __FN__((void*)_this, evt, a1, a2, a3, a4);
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_write4__EXIT_EVT, 0);
#else
    __FN__((void*)_this, evt, a1, a2, a3, a4);
#endif
}
#undef __FN__
#if xdc_runtime_LoggerBuf___scope == -1
#ifdef xdc_runtime_LoggerBuf_write8__PATCH
#define __FN__ xdc_runtime_LoggerBuf_write8__PATCH
#else
#define __FN__ xdc_runtime_LoggerBuf_write8__R
#endif
#else
#define __FN__ xdc_runtime_LoggerBuf_write8__F
#endif
xdc_Void xdc_runtime_LoggerBuf_write8__E( xdc_runtime_LoggerBuf_Handle _this, xdc_runtime_Types_EventId evt, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4, xdc_IArg a5, xdc_IArg a6, xdc_IArg a7, xdc_IArg a8 ) {
#if xdc_runtime_LoggerBuf___L_ENTRY
    xdc_runtime_Log_write8(xdc_runtime_LoggerBuf_write8__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)evt, (xdc_IArg)a1, (xdc_IArg)a2, (xdc_IArg)a3, (xdc_IArg)a4, (xdc_IArg)a5, (xdc_IArg)a6);
#endif
#if xdc_runtime_LoggerBuf___L_EXIT
    __FN__((void*)_this, evt, a1, a2, a3, a4, a5, a6, a7, a8);
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_write8__EXIT_EVT, 0);
#else
    __FN__((void*)_this, evt, a1, a2, a3, a4, a5, a6, a7, a8);
#endif
}
#undef __FN__
#if xdc_runtime_LoggerBuf___scope == -1
#ifdef xdc_runtime_LoggerBuf_flushAll__PATCH
#define __FN__ xdc_runtime_LoggerBuf_flushAll__PATCH
#else
#define __FN__ xdc_runtime_LoggerBuf_flushAll__R
#endif
#else
#define __FN__ xdc_runtime_LoggerBuf_flushAll__F
#endif
xdc_Void xdc_runtime_LoggerBuf_flushAll__E( void ) {
#if xdc_runtime_LoggerBuf___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_LoggerBuf_flushAll__ENTRY_EVT);
#endif
#if xdc_runtime_LoggerBuf___L_EXIT
    __FN__();
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_flushAll__EXIT_EVT, 0);
#else
    __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_LoggerBuf___scope == -1
#ifdef xdc_runtime_LoggerBuf_flushAllInternal__PATCH
#define __FN__ xdc_runtime_LoggerBuf_flushAllInternal__PATCH
#else
#define __FN__ xdc_runtime_LoggerBuf_flushAllInternal__R
#endif
#else
#define __FN__ xdc_runtime_LoggerBuf_flushAllInternal__F
#endif
xdc_Void xdc_runtime_LoggerBuf_flushAllInternal__E( xdc_Int stat ) {
#if xdc_runtime_LoggerBuf___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_flushAllInternal__ENTRY_EVT, (xdc_IArg)stat);
#endif
#if xdc_runtime_LoggerBuf___L_EXIT
    __FN__(stat);
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_flushAllInternal__EXIT_EVT, 0);
#else
    __FN__(stat);
#endif
}
#undef __FN__
#if xdc_runtime_LoggerBuf___scope == -1
#ifdef xdc_runtime_LoggerBuf_enable__PATCH
#define __FN__ xdc_runtime_LoggerBuf_enable__PATCH
#else
#define __FN__ xdc_runtime_LoggerBuf_enable__R
#endif
#else
#define __FN__ xdc_runtime_LoggerBuf_enable__F
#endif
xdc_Void xdc_runtime_LoggerBuf_enable__E( xdc_runtime_LoggerBuf_Handle _this ) {
#if xdc_runtime_LoggerBuf___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_enable__ENTRY_EVT, (xdc_IArg)_this);
#endif
#if xdc_runtime_LoggerBuf___L_EXIT
    __FN__((void*)_this);
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_enable__EXIT_EVT, 0);
#else
    __FN__((void*)_this);
#endif
}
#undef __FN__
#if xdc_runtime_LoggerBuf___scope == -1
#ifdef xdc_runtime_LoggerBuf_disable__PATCH
#define __FN__ xdc_runtime_LoggerBuf_disable__PATCH
#else
#define __FN__ xdc_runtime_LoggerBuf_disable__R
#endif
#else
#define __FN__ xdc_runtime_LoggerBuf_disable__F
#endif
xdc_Void xdc_runtime_LoggerBuf_disable__E( xdc_runtime_LoggerBuf_Handle _this ) {
#if xdc_runtime_LoggerBuf___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_disable__ENTRY_EVT, (xdc_IArg)_this);
#endif
#if xdc_runtime_LoggerBuf___L_EXIT
    __FN__((void*)_this);
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_disable__EXIT_EVT, 0);
#else
    __FN__((void*)_this);
#endif
}
#undef __FN__
#if xdc_runtime_LoggerBuf___scope == -1
#ifdef xdc_runtime_LoggerBuf_reset__PATCH
#define __FN__ xdc_runtime_LoggerBuf_reset__PATCH
#else
#define __FN__ xdc_runtime_LoggerBuf_reset__R
#endif
#else
#define __FN__ xdc_runtime_LoggerBuf_reset__F
#endif
xdc_Void xdc_runtime_LoggerBuf_reset__E( xdc_runtime_LoggerBuf_Handle _this ) {
#if xdc_runtime_LoggerBuf___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_reset__ENTRY_EVT, (xdc_IArg)_this);
#endif
#if xdc_runtime_LoggerBuf___L_EXIT
    __FN__((void*)_this);
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_reset__EXIT_EVT, 0);
#else
    __FN__((void*)_this);
#endif
}
#undef __FN__
#if xdc_runtime_LoggerBuf___scope == -1
#ifdef xdc_runtime_LoggerBuf_flush__PATCH
#define __FN__ xdc_runtime_LoggerBuf_flush__PATCH
#else
#define __FN__ xdc_runtime_LoggerBuf_flush__R
#endif
#else
#define __FN__ xdc_runtime_LoggerBuf_flush__F
#endif
xdc_Void xdc_runtime_LoggerBuf_flush__E( xdc_runtime_LoggerBuf_Handle _this ) {
#if xdc_runtime_LoggerBuf___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_flush__ENTRY_EVT, (xdc_IArg)_this);
#endif
#if xdc_runtime_LoggerBuf___L_EXIT
    __FN__((void*)_this);
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_flush__EXIT_EVT, 0);
#else
    __FN__((void*)_this);
#endif
}
#undef __FN__
#if xdc_runtime_LoggerBuf___scope == -1
#ifdef xdc_runtime_LoggerBuf_getNextEntry__PATCH
#define __FN__ xdc_runtime_LoggerBuf_getNextEntry__PATCH
#else
#define __FN__ xdc_runtime_LoggerBuf_getNextEntry__R
#endif
#else
#define __FN__ xdc_runtime_LoggerBuf_getNextEntry__F
#endif
xdc_Int xdc_runtime_LoggerBuf_getNextEntry__E( xdc_runtime_LoggerBuf_Handle _this, xdc_runtime_Log_EventRec* evtRec ) {
#if xdc_runtime_LoggerBuf___L_EXIT
    xdc_Int __ret;
#else
#endif
#if xdc_runtime_LoggerBuf___L_ENTRY
    xdc_runtime_Log_write2(xdc_runtime_LoggerBuf_getNextEntry__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)evtRec);
#endif
#if xdc_runtime_LoggerBuf___L_EXIT
    __ret = __FN__((void*)_this, evtRec);
    xdc_runtime_Log_write1(xdc_runtime_LoggerBuf_getNextEntry__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__((void*)_this, evtRec);
#endif
}
#if xdc_runtime_LoggerBuf___scope == -1
xdc_Int xdc_runtime_LoggerBuf_Module_startup__E( xdc_Int state ) { return xdc_runtime_LoggerBuf_Module_startup__R(state); }
#else
xdc_Int xdc_runtime_LoggerBuf_Module_startup__E( xdc_Int state ) { return xdc_runtime_LoggerBuf_Module_startup__F(state); }
#endif
#endif /* xdc_runtime_LoggerBuf___ROMPATCH */
#ifdef xdc_runtime_LoggerBuf___ROMPATCH
xdc_Void xdc_runtime_LoggerBuf_write4__E( xdc_runtime_LoggerBuf_Handle _this, xdc_runtime_Types_EventId evt, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4 ) {
    xdc_runtime_LoggerBuf_Module__MTAB__C.write4((void*)_this, evt, a1, a2, a3, a4);
}
xdc_Void xdc_runtime_LoggerBuf_write8__E( xdc_runtime_LoggerBuf_Handle _this, xdc_runtime_Types_EventId evt, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4, xdc_IArg a5, xdc_IArg a6, xdc_IArg a7, xdc_IArg a8 ) {
    xdc_runtime_LoggerBuf_Module__MTAB__C.write8((void*)_this, evt, a1, a2, a3, a4, a5, a6, a7, a8);
}
xdc_Void xdc_runtime_LoggerBuf_flushAll__E( void ) {
    xdc_runtime_LoggerBuf_Module__MTAB__C.flushAll();
}
xdc_Void xdc_runtime_LoggerBuf_flushAllInternal__E( xdc_Int stat ) {
    xdc_runtime_LoggerBuf_Module__MTAB__C.flushAllInternal(stat);
}
xdc_Void xdc_runtime_LoggerBuf_enable__E( xdc_runtime_LoggerBuf_Handle _this ) {
    xdc_runtime_LoggerBuf_Module__MTAB__C.enable((void*)_this);
}
xdc_Void xdc_runtime_LoggerBuf_disable__E( xdc_runtime_LoggerBuf_Handle _this ) {
    xdc_runtime_LoggerBuf_Module__MTAB__C.disable((void*)_this);
}
xdc_Void xdc_runtime_LoggerBuf_reset__E( xdc_runtime_LoggerBuf_Handle _this ) {
    xdc_runtime_LoggerBuf_Module__MTAB__C.reset((void*)_this);
}
xdc_Void xdc_runtime_LoggerBuf_flush__E( xdc_runtime_LoggerBuf_Handle _this ) {
    xdc_runtime_LoggerBuf_Module__MTAB__C.flush((void*)_this);
}
xdc_Int xdc_runtime_LoggerBuf_getNextEntry__E( xdc_runtime_LoggerBuf_Handle _this, xdc_runtime_Log_EventRec* evtRec ) {
    return xdc_runtime_LoggerBuf_Module__MTAB__C.getNextEntry((void*)_this, evtRec);
}
#if xdc_runtime_LoggerBuf___scope == -1
xdc_Int xdc_runtime_LoggerBuf_Module_startup__E( xdc_Int state ) { return xdc_runtime_LoggerBuf_Module_startup__R(state); }
#else
xdc_Int xdc_runtime_LoggerBuf_Module_startup__E( xdc_Int state ) { return xdc_runtime_LoggerBuf_Module_startup__F(state); }
#endif
#endif /* xdc_runtime_LoggerBuf___ROMPATCH */
xdc_Void xdc_runtime_LoggerBuf_write4__R( xdc_runtime_LoggerBuf_Handle _this, xdc_runtime_Types_EventId evt, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4 ) {
    xdc_runtime_LoggerBuf_write4__F((void*)_this, evt, a1, a2, a3, a4);
}
xdc_Void xdc_runtime_LoggerBuf_write8__R( xdc_runtime_LoggerBuf_Handle _this, xdc_runtime_Types_EventId evt, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4, xdc_IArg a5, xdc_IArg a6, xdc_IArg a7, xdc_IArg a8 ) {
    xdc_runtime_LoggerBuf_write8__F((void*)_this, evt, a1, a2, a3, a4, a5, a6, a7, a8);
}
xdc_Void xdc_runtime_LoggerBuf_flushAll__R( void ) {
    xdc_runtime_LoggerBuf_flushAll__F();
}
xdc_Void xdc_runtime_LoggerBuf_flushAllInternal__R( xdc_Int stat ) {
    xdc_runtime_LoggerBuf_flushAllInternal__F(stat);
}
xdc_Void xdc_runtime_LoggerBuf_enable__R( xdc_runtime_LoggerBuf_Handle _this ) {
    xdc_runtime_LoggerBuf_enable__F((void*)_this);
}
xdc_Void xdc_runtime_LoggerBuf_disable__R( xdc_runtime_LoggerBuf_Handle _this ) {
    xdc_runtime_LoggerBuf_disable__F((void*)_this);
}
xdc_Void xdc_runtime_LoggerBuf_reset__R( xdc_runtime_LoggerBuf_Handle _this ) {
    xdc_runtime_LoggerBuf_reset__F((void*)_this);
}
xdc_Void xdc_runtime_LoggerBuf_flush__R( xdc_runtime_LoggerBuf_Handle _this ) {
    xdc_runtime_LoggerBuf_flush__F((void*)_this);
}
xdc_Int xdc_runtime_LoggerBuf_getNextEntry__R( xdc_runtime_LoggerBuf_Handle _this, xdc_runtime_Log_EventRec* evtRec ) {
    return xdc_runtime_LoggerBuf_getNextEntry__F((void*)_this, evtRec);
}
xdc_Int xdc_runtime_LoggerBuf_Module_startup__R( xdc_Int state ) { return xdc_runtime_LoggerBuf_Module_startup__F(state); }

#if defined(xdc_runtime_LoggerBuf___EXPORT) && defined(__ti__)
#if xdc_runtime_LoggerBuf___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_Module__startupDone__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_Handle__label__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_Object__create__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_Object__delete__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_Object__destruct__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_Object__get__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_Params__init__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_Module_startup__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_write4__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_write8__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_flushAll__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_flushAllInternal__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_enable__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_disable__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_reset__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_flush__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerBuf_getNextEntry__R);
#endif
#endif /* __isrom__ */

#if xdc_runtime_LoggerBuf___scope != -1
xdc_Bool xdc_runtime_LoggerBuf_Module__startupDone__S() {

    return xdc_runtime_LoggerBuf_Module__startupDoneFxn__C();
}
xdc_runtime_Types_Label* xdc_runtime_LoggerBuf_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab ) {
    lab->oaddr = obj;
    lab->modid = xdc_runtime_LoggerBuf_Module__id__D;
#ifdef xdc_runtime_LoggerBuf___NAMEDINST
    xdc_runtime_Core_assignLabel(lab, ((xdc_runtime_LoggerBuf_Object__*)obj)->__name, 1);
#else
    xdc_runtime_Core_assignLabel(lab, 0, 0);
#endif
    return lab;
}
xdc_Void xdc_runtime_LoggerBuf_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) {
#ifdef xdc_runtime_LoggerBuf___OBJHEAP
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &xdc_runtime_LoggerBuf_Object__PARAMS__C), psz, isz);
#endif
}
xdc_Ptr xdc_runtime_LoggerBuf_Object__get__S( xdc_Ptr oa, xdc_Int i ) {
    if (oa) return ((xdc_runtime_LoggerBuf_Object*)oa) + i;
    if (xdc_runtime_LoggerBuf_Object__count__C == 0) return 0;
    return ((xdc_runtime_LoggerBuf_Object*)xdc_runtime_LoggerBuf_Object__table__C) + i;
}

#ifdef xdc_runtime_LoggerBuf___OBJHEAP
extern xdc_Ptr xdc_runtime_LoggerBuf_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __psz, xdc_runtime_Error_Block* __eb ) {
    xdc_runtime_LoggerBuf_Params prms;
    xdc_runtime_LoggerBuf_Object* obj;
#ifdef xdc_runtime_LoggerBuf___DELETE
    int iStat;
#endif
    obj = xdc_runtime_Core_createObject__I(&xdc_runtime_LoggerBuf_Object__DESC__C, __oa, __osz, &prms, __pa, __psz, __eb);
    if (!obj) return 0;
#ifdef xdc_runtime_LoggerBuf___DELETE
#define xdc_runtime_LoggerBuf___ISTAT iStat = 
#else
#define xdc_runtime_LoggerBuf___ISTAT
#endif
    xdc_runtime_LoggerBuf___ISTAT xdc_runtime_LoggerBuf_Instance_init__F(obj, &prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
#ifdef xdc_runtime_LoggerBuf___DELETE
        xdc_runtime_Core_deleteObject__I(&xdc_runtime_LoggerBuf_Object__DESC__C, obj, (xdc_Fxn)xdc_runtime_LoggerBuf_Instance_finalize__F, iStat, __oa != 0);
#endif
        return 0;
    }
#if xdc_runtime_LoggerBuf___L_LIFECYCLE
#ifdef xdc_runtime_LoggerBuf___NAMEDINST
    xdc_runtime_Log_write2(__oa ? xdc_runtime_Log_L_construct : xdc_runtime_Log_L_create, (xdc_IArg)obj, (xdc_IArg)(((xdc_runtime_LoggerBuf_Object__*)obj)->__name));
#else
    xdc_runtime_Log_write2(__oa ? xdc_runtime_Log_L_construct : xdc_runtime_Log_L_create, (xdc_IArg)obj, 0);
#endif
#endif
    return obj;
}
#else
extern xdc_Ptr xdc_runtime_LoggerBuf_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __sz, xdc_runtime_Error_Block* __eb ) {
    xdc_runtime_Error_raiseX(NULL, xdc_runtime_LoggerBuf_Module__id__C, NULL, 0, xdc_runtime_Error_E_generic, (xdc_IArg)"create policy error", 0);
    return 0;
}
#endif

#ifdef xdc_runtime_LoggerBuf___DELETE
extern xdc_Void xdc_runtime_LoggerBuf_Object__destruct__S( xdc_Ptr obj ) {
#if xdc_runtime_LoggerBuf___L_LIFECYCLE
    xdc_runtime_Log_write1(xdc_runtime_Log_L_destruct, (xdc_IArg)obj);
#endif
    xdc_runtime_Core_deleteObject__I(&xdc_runtime_LoggerBuf_Object__DESC__C, obj, (xdc_Fxn)xdc_runtime_LoggerBuf_Instance_finalize__F, 0, TRUE);
}
extern xdc_Void xdc_runtime_LoggerBuf_Object__delete__S( xdc_Ptr instp ) {
#if xdc_runtime_LoggerBuf___L_LIFECYCLE
    xdc_runtime_Log_write1(xdc_runtime_Log_L_delete, (xdc_IArg)(*((xdc_runtime_LoggerBuf_Object**)instp)));
#endif
    xdc_runtime_Core_deleteObject__I(&xdc_runtime_LoggerBuf_Object__DESC__C, *((xdc_runtime_LoggerBuf_Object**)instp), (xdc_Fxn)xdc_runtime_LoggerBuf_Instance_finalize__F, 0, FALSE);
    *((xdc_runtime_LoggerBuf_Handle*)instp) = 0;
}
#else
extern xdc_Void xdc_runtime_LoggerBuf_Object__destruct__S( xdc_Ptr obj ) {
    xdc_runtime_Error_raiseX(NULL, xdc_runtime_LoggerBuf_Module__id__C, NULL, 0, xdc_runtime_Error_E_generic, (xdc_IArg)"delete policy error", 0);
}
extern xdc_Void xdc_runtime_LoggerBuf_Object__delete__S( xdc_Ptr instp ) {
    xdc_runtime_Error_raiseX(NULL, xdc_runtime_LoggerBuf_Module__id__C, NULL, 0, xdc_runtime_Error_E_generic, (xdc_IArg)"delete policy error", 0);
}
#endif
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_LoggerSys___used
/*
 *  ======== module LoggerSys ========
 *  Do not modify this file; it is generated from the specification LoggerSys.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_LoggerSys__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/LoggerSys.h>
#undef __nested__
#else
#include <xdc/runtime/LoggerSys.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_LoggerSys___LOGOBJ) && xdc_runtime_LoggerSys___DGSINCL & 0x1
#define xdc_runtime_LoggerSys___L_ENTRY 1
#else
#define xdc_runtime_LoggerSys___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_LoggerSys___LOGOBJ) && xdc_runtime_LoggerSys___DGSINCL & 0x2
#define xdc_runtime_LoggerSys___L_EXIT 1
#else
#define xdc_runtime_LoggerSys___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_LoggerSys___LOGOBJ) && xdc_runtime_LoggerSys___DGSINCL & 0x4
#define xdc_runtime_LoggerSys___L_LIFECYCLE 1
#else
#define xdc_runtime_LoggerSys___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_LoggerSys_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_LoggerSys_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_LoggerSys_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_LoggerSys_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_LoggerSys_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_LoggerSys_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_LoggerSys_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_LoggerSys_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_LoggerSys_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_LoggerSys_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_LoggerSys_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_LoggerSys_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_LoggerSys_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_LoggerSys_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_LoggerSys_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_LoggerSys___scope == -1
#ifdef xdc_runtime_LoggerSys_write4__PATCH
#define __FN__ xdc_runtime_LoggerSys_write4__PATCH
#else
#define __FN__ xdc_runtime_LoggerSys_write4__R
#endif
#else
#define __FN__ xdc_runtime_LoggerSys_write4__F
#endif
xdc_Void xdc_runtime_LoggerSys_write4__E( xdc_runtime_LoggerSys_Handle _this, xdc_runtime_Types_EventId evt, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4 ) {
#if xdc_runtime_LoggerSys___L_ENTRY
    xdc_runtime_Log_write6(xdc_runtime_LoggerSys_write4__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)evt, (xdc_IArg)a1, (xdc_IArg)a2, (xdc_IArg)a3, (xdc_IArg)a4);
#endif
#if xdc_runtime_LoggerSys___L_EXIT
    __FN__((void*)_this, evt, a1, a2, a3, a4);
    xdc_runtime_Log_write1(xdc_runtime_LoggerSys_write4__EXIT_EVT, 0);
#else
    __FN__((void*)_this, evt, a1, a2, a3, a4);
#endif
}
#undef __FN__
#if xdc_runtime_LoggerSys___scope == -1
#ifdef xdc_runtime_LoggerSys_write8__PATCH
#define __FN__ xdc_runtime_LoggerSys_write8__PATCH
#else
#define __FN__ xdc_runtime_LoggerSys_write8__R
#endif
#else
#define __FN__ xdc_runtime_LoggerSys_write8__F
#endif
xdc_Void xdc_runtime_LoggerSys_write8__E( xdc_runtime_LoggerSys_Handle _this, xdc_runtime_Types_EventId evt, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4, xdc_IArg a5, xdc_IArg a6, xdc_IArg a7, xdc_IArg a8 ) {
#if xdc_runtime_LoggerSys___L_ENTRY
    xdc_runtime_Log_write8(xdc_runtime_LoggerSys_write8__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)evt, (xdc_IArg)a1, (xdc_IArg)a2, (xdc_IArg)a3, (xdc_IArg)a4, (xdc_IArg)a5, (xdc_IArg)a6);
#endif
#if xdc_runtime_LoggerSys___L_EXIT
    __FN__((void*)_this, evt, a1, a2, a3, a4, a5, a6, a7, a8);
    xdc_runtime_Log_write1(xdc_runtime_LoggerSys_write8__EXIT_EVT, 0);
#else
    __FN__((void*)_this, evt, a1, a2, a3, a4, a5, a6, a7, a8);
#endif
}
typedef struct { xdc_runtime_LoggerSys_Object2__ s0; char c; } xdc_runtime_LoggerSys___S1;
__FAR__ xdc_runtime_LoggerSys_Object__DESC__C__qual xdc_runtime_Core_ObjDesc xdc_runtime_LoggerSys_Object__DESC__C = {
#ifdef xdc_runtime_LoggerSys___FXNTAB
    (Ptr)&xdc_runtime_LoggerSys_Module__FXNS__C, /* fxnTab */
#else
    (Ptr)0, /* fxnTab */
#endif
    &xdc_runtime_LoggerSys_Module__root__V.hdr.link, /* modLink */
    sizeof(xdc_runtime_LoggerSys___S1) - sizeof(xdc_runtime_LoggerSys_Object2__), /* objAlign */
#ifdef xdc_runtime_LoggerSys___OBJHEAP
    xdc_runtime_LoggerSys___OBJHEAP, /* objHeap */
#else
    0, /* objHeap */
#endif
#ifdef xdc_runtime_LoggerSys___NAMEDINST
    offsetof(xdc_runtime_LoggerSys_Object__, __name), /* objName */
#else
    0, /* objName */
#endif
    sizeof(xdc_runtime_LoggerSys_Object2__), /* objSize */
    (Ptr)&xdc_runtime_LoggerSys_Object__PARAMS__C, /* prmsInit */
    sizeof(xdc_runtime_LoggerSys_Params), /* prmsSize */
};

#if defined(xdc_runtime_LoggerSys___EXPORT) && defined(__ti__)
#if xdc_runtime_LoggerSys___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerSys_Module__startupDone__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerSys_Handle__label__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerSys_Object__create__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerSys_Object__delete__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerSys_Object__destruct__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerSys_Object__get__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerSys_Params__init__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerSys_write4__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerSys_write8__E);
#endif
#ifdef xdc_runtime_LoggerSys___FXNTAB
#if xdc_runtime_LoggerSys___scope == -1 || !defined(__xdc_runtime_IModule_Interface__BASE__CR)
#ifndef __xdc_runtime_IModule_Interface__BASE__C
#define __xdc_runtime_IModule_Interface__BASE__C
__FAR__ xdc_runtime_IModule_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_IModule_Interface__BASE__C = {0};
#endif
#endif
#if xdc_runtime_LoggerSys___scope == -1 || !defined(__xdc_runtime_ILogger_Interface__BASE__CR)
#ifndef __xdc_runtime_ILogger_Interface__BASE__C
#define __xdc_runtime_ILogger_Interface__BASE__C
__FAR__ xdc_runtime_ILogger_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_ILogger_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};
#endif
#endif

__FAR__ xdc_runtime_LoggerSys_Module__FXNS__C__qual xdc_runtime_LoggerSys_Fxns__ xdc_runtime_LoggerSys_Module__FXNS__C = {
    /* base__ */ (void*)&xdc_runtime_ILogger_Interface__BASE__C,
    &xdc_runtime_LoggerSys_Module__FXNS__C.__sfxns, /* __sysp */
    xdc_runtime_LoggerSys_write4__E,
    xdc_runtime_LoggerSys_write8__E,
    {

#ifdef xdc_runtime_LoggerSys___OBJHEAP
        xdc_runtime_LoggerSys_Object__create__S,
#else
        /* create__ */ 0,
#endif
#ifdef xdc_runtime_LoggerSys___DELETE
        xdc_runtime_LoggerSys_Object__delete__S,
#else
        /* delete__ */ 0,
#endif
        xdc_runtime_LoggerSys_Handle__label__S,
        xdc_runtime_LoggerSys_Module__id__D,
    } /* __sfxns */
};
#endif
__FAR__ xdc_runtime_LoggerSys_Module__MTAB__C__qual xdc_runtime_LoggerSys_MTab__ xdc_runtime_LoggerSys_Module__MTAB__C = {
#if xdc_runtime_LoggerSys___scope == -1
#if xdc_runtime_LoggerSys___L_ENTRY || xdc_runtime_LoggerSys___L_EXIT
    xdc_runtime_LoggerSys_write4__E,
#elif defined(xdc_runtime_LoggerSys_write4__PATCH)
    xdc_runtime_LoggerSys_write4__PATCH,
#else
    xdc_runtime_LoggerSys_write4__R,
#endif
#if xdc_runtime_LoggerSys___L_ENTRY || xdc_runtime_LoggerSys___L_EXIT
    xdc_runtime_LoggerSys_write8__E,
#elif defined(xdc_runtime_LoggerSys_write8__PATCH)
    xdc_runtime_LoggerSys_write8__PATCH,
#else
    xdc_runtime_LoggerSys_write8__R,
#endif
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_LoggerSys___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_LoggerSys_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_LoggerSys_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_LoggerSys_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_LoggerSys_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_LoggerSys_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_LoggerSys_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_LoggerSys_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_LoggerSys_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_LoggerSys_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_LoggerSys_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_LoggerSys_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_LoggerSys_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_LoggerSys_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_LoggerSys_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_LoggerSys_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_LoggerSys___scope == -1
#ifdef xdc_runtime_LoggerSys_write4__PATCH
#define __FN__ xdc_runtime_LoggerSys_write4__PATCH
#else
#define __FN__ xdc_runtime_LoggerSys_write4__R
#endif
#else
#define __FN__ xdc_runtime_LoggerSys_write4__F
#endif
xdc_Void xdc_runtime_LoggerSys_write4__E( xdc_runtime_LoggerSys_Handle _this, xdc_runtime_Types_EventId evt, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4 ) {
#if xdc_runtime_LoggerSys___L_ENTRY
    xdc_runtime_Log_write6(xdc_runtime_LoggerSys_write4__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)evt, (xdc_IArg)a1, (xdc_IArg)a2, (xdc_IArg)a3, (xdc_IArg)a4);
#endif
#if xdc_runtime_LoggerSys___L_EXIT
    __FN__((void*)_this, evt, a1, a2, a3, a4);
    xdc_runtime_Log_write1(xdc_runtime_LoggerSys_write4__EXIT_EVT, 0);
#else
    __FN__((void*)_this, evt, a1, a2, a3, a4);
#endif
}
#undef __FN__
#if xdc_runtime_LoggerSys___scope == -1
#ifdef xdc_runtime_LoggerSys_write8__PATCH
#define __FN__ xdc_runtime_LoggerSys_write8__PATCH
#else
#define __FN__ xdc_runtime_LoggerSys_write8__R
#endif
#else
#define __FN__ xdc_runtime_LoggerSys_write8__F
#endif
xdc_Void xdc_runtime_LoggerSys_write8__E( xdc_runtime_LoggerSys_Handle _this, xdc_runtime_Types_EventId evt, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4, xdc_IArg a5, xdc_IArg a6, xdc_IArg a7, xdc_IArg a8 ) {
#if xdc_runtime_LoggerSys___L_ENTRY
    xdc_runtime_Log_write8(xdc_runtime_LoggerSys_write8__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)evt, (xdc_IArg)a1, (xdc_IArg)a2, (xdc_IArg)a3, (xdc_IArg)a4, (xdc_IArg)a5, (xdc_IArg)a6);
#endif
#if xdc_runtime_LoggerSys___L_EXIT
    __FN__((void*)_this, evt, a1, a2, a3, a4, a5, a6, a7, a8);
    xdc_runtime_Log_write1(xdc_runtime_LoggerSys_write8__EXIT_EVT, 0);
#else
    __FN__((void*)_this, evt, a1, a2, a3, a4, a5, a6, a7, a8);
#endif
}
#endif /* xdc_runtime_LoggerSys___ROMPATCH */
#ifdef xdc_runtime_LoggerSys___ROMPATCH
xdc_Void xdc_runtime_LoggerSys_write4__E( xdc_runtime_LoggerSys_Handle _this, xdc_runtime_Types_EventId evt, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4 ) {
    xdc_runtime_LoggerSys_Module__MTAB__C.write4((void*)_this, evt, a1, a2, a3, a4);
}
xdc_Void xdc_runtime_LoggerSys_write8__E( xdc_runtime_LoggerSys_Handle _this, xdc_runtime_Types_EventId evt, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4, xdc_IArg a5, xdc_IArg a6, xdc_IArg a7, xdc_IArg a8 ) {
    xdc_runtime_LoggerSys_Module__MTAB__C.write8((void*)_this, evt, a1, a2, a3, a4, a5, a6, a7, a8);
}
#endif /* xdc_runtime_LoggerSys___ROMPATCH */
xdc_Void xdc_runtime_LoggerSys_write4__R( xdc_runtime_LoggerSys_Handle _this, xdc_runtime_Types_EventId evt, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4 ) {
    xdc_runtime_LoggerSys_write4__F((void*)_this, evt, a1, a2, a3, a4);
}
xdc_Void xdc_runtime_LoggerSys_write8__R( xdc_runtime_LoggerSys_Handle _this, xdc_runtime_Types_EventId evt, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4, xdc_IArg a5, xdc_IArg a6, xdc_IArg a7, xdc_IArg a8 ) {
    xdc_runtime_LoggerSys_write8__F((void*)_this, evt, a1, a2, a3, a4, a5, a6, a7, a8);
}

#if defined(xdc_runtime_LoggerSys___EXPORT) && defined(__ti__)
#if xdc_runtime_LoggerSys___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerSys_Module__startupDone__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerSys_Handle__label__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerSys_Object__create__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerSys_Object__delete__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerSys_Object__destruct__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerSys_Object__get__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerSys_Params__init__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerSys_write4__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_LoggerSys_write8__R);
#endif
#endif /* __isrom__ */

#if xdc_runtime_LoggerSys___scope != -1
xdc_Bool xdc_runtime_LoggerSys_Module__startupDone__S() {

    return 1;
}
xdc_runtime_Types_Label* xdc_runtime_LoggerSys_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab ) {
    lab->oaddr = obj;
    lab->modid = xdc_runtime_LoggerSys_Module__id__D;
#ifdef xdc_runtime_LoggerSys___NAMEDINST
    xdc_runtime_Core_assignLabel(lab, ((xdc_runtime_LoggerSys_Object__*)obj)->__name, 1);
#else
    xdc_runtime_Core_assignLabel(lab, 0, 0);
#endif
    return lab;
}
xdc_Void xdc_runtime_LoggerSys_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) {
#ifdef xdc_runtime_LoggerSys___OBJHEAP
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &xdc_runtime_LoggerSys_Object__PARAMS__C), psz, isz);
#endif
}
xdc_Ptr xdc_runtime_LoggerSys_Object__get__S( xdc_Ptr oa, xdc_Int i ) {
    if (oa) return ((xdc_runtime_LoggerSys_Object*)oa) + i;
    if (xdc_runtime_LoggerSys_Object__count__C == 0) return 0;
    return ((xdc_runtime_LoggerSys_Object*)xdc_runtime_LoggerSys_Object__table__C) + i;
}

#ifdef xdc_runtime_LoggerSys___OBJHEAP
extern xdc_Ptr xdc_runtime_LoggerSys_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __psz, xdc_runtime_Error_Block* __eb ) {
    xdc_runtime_LoggerSys_Params prms;
    xdc_runtime_LoggerSys_Object* obj;
    obj = xdc_runtime_Core_createObject__I(&xdc_runtime_LoggerSys_Object__DESC__C, __oa, __osz, &prms, __pa, __psz, __eb);
    if (!obj) return 0;
#ifdef xdc_runtime_LoggerSys___DELETE
#define xdc_runtime_LoggerSys___ISTAT 
#else
#define xdc_runtime_LoggerSys___ISTAT
#endif
#if xdc_runtime_LoggerSys___L_LIFECYCLE
#ifdef xdc_runtime_LoggerSys___NAMEDINST
    xdc_runtime_Log_write2(__oa ? xdc_runtime_Log_L_construct : xdc_runtime_Log_L_create, (xdc_IArg)obj, (xdc_IArg)(((xdc_runtime_LoggerSys_Object__*)obj)->__name));
#else
    xdc_runtime_Log_write2(__oa ? xdc_runtime_Log_L_construct : xdc_runtime_Log_L_create, (xdc_IArg)obj, 0);
#endif
#endif
    return obj;
}
#else
extern xdc_Ptr xdc_runtime_LoggerSys_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __sz, xdc_runtime_Error_Block* __eb ) {
    xdc_runtime_Error_raiseX(NULL, xdc_runtime_LoggerSys_Module__id__C, NULL, 0, xdc_runtime_Error_E_generic, (xdc_IArg)"create policy error", 0);
    return 0;
}
#endif

#ifdef xdc_runtime_LoggerSys___DELETE
extern xdc_Void xdc_runtime_LoggerSys_Object__destruct__S( xdc_Ptr obj ) {
#if xdc_runtime_LoggerSys___L_LIFECYCLE
    xdc_runtime_Log_write1(xdc_runtime_Log_L_destruct, (xdc_IArg)obj);
#endif
    xdc_runtime_Core_deleteObject__I(&xdc_runtime_LoggerSys_Object__DESC__C, obj, 0, -1, TRUE);
}
extern xdc_Void xdc_runtime_LoggerSys_Object__delete__S( xdc_Ptr instp ) {
#if xdc_runtime_LoggerSys___L_LIFECYCLE
    xdc_runtime_Log_write1(xdc_runtime_Log_L_delete, (xdc_IArg)(*((xdc_runtime_LoggerSys_Object**)instp)));
#endif
    xdc_runtime_Core_deleteObject__I(&xdc_runtime_LoggerSys_Object__DESC__C, *((xdc_runtime_LoggerSys_Object**)instp), 0, -1, FALSE);
    *((xdc_runtime_LoggerSys_Handle*)instp) = 0;
}
#else
extern xdc_Void xdc_runtime_LoggerSys_Object__destruct__S( xdc_Ptr obj ) {
    xdc_runtime_Error_raiseX(NULL, xdc_runtime_LoggerSys_Module__id__C, NULL, 0, xdc_runtime_Error_E_generic, (xdc_IArg)"delete policy error", 0);
}
extern xdc_Void xdc_runtime_LoggerSys_Object__delete__S( xdc_Ptr instp ) {
    xdc_runtime_Error_raiseX(NULL, xdc_runtime_LoggerSys_Module__id__C, NULL, 0, xdc_runtime_Error_E_generic, (xdc_IArg)"delete policy error", 0);
}
#endif
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_Main___used
/*
 *  ======== module Main ========
 *  Do not modify this file; it is generated from the specification Main.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_Main__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Main.h>
#undef __nested__
#else
#include <xdc/runtime/Main.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Main___LOGOBJ) && xdc_runtime_Main___DGSINCL & 0x1
#define xdc_runtime_Main___L_ENTRY 1
#else
#define xdc_runtime_Main___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Main___LOGOBJ) && xdc_runtime_Main___DGSINCL & 0x2
#define xdc_runtime_Main___L_EXIT 1
#else
#define xdc_runtime_Main___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Main___LOGOBJ) && xdc_runtime_Main___DGSINCL & 0x4
#define xdc_runtime_Main___L_LIFECYCLE 1
#else
#define xdc_runtime_Main___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_Main_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Main_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Main_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Main_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Main_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Main_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Main_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Main_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Main_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Main_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Main_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Main_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Main_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Main_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Main_Module_GateProxy_query

#if defined(xdc_runtime_Main___EXPORT) && defined(__ti__)
#if xdc_runtime_Main___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Main_Module__startupDone__S);
#endif
#endif
__FAR__ xdc_runtime_Main_Module__MTAB__C__qual xdc_runtime_Main_MTab__ xdc_runtime_Main_Module__MTAB__C = {
#if xdc_runtime_Main___scope == -1
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_Main___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_Main_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Main_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Main_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Main_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Main_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Main_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Main_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Main_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Main_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Main_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Main_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Main_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Main_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Main_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Main_Module_GateProxy_query
#endif /* xdc_runtime_Main___ROMPATCH */
#ifdef xdc_runtime_Main___ROMPATCH
#endif /* xdc_runtime_Main___ROMPATCH */

#if defined(xdc_runtime_Main___EXPORT) && defined(__ti__)
#if xdc_runtime_Main___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Main_Module__startupDone__S);
#endif
#endif
#endif /* __isrom__ */

#if xdc_runtime_Main___scope != -1
xdc_Bool xdc_runtime_Main_Module__startupDone__S() {

    return 1;
}
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_Memory___used
/*
 *  ======== module Memory ========
 *  Do not modify this file; it is generated from the specification Memory.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Memory___LOGOBJ) && xdc_runtime_Memory___DGSINCL & 0x1
#define xdc_runtime_Memory___L_ENTRY 1
#else
#define xdc_runtime_Memory___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Memory___LOGOBJ) && xdc_runtime_Memory___DGSINCL & 0x2
#define xdc_runtime_Memory___L_EXIT 1
#else
#define xdc_runtime_Memory___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Memory___LOGOBJ) && xdc_runtime_Memory___DGSINCL & 0x4
#define xdc_runtime_Memory___L_LIFECYCLE 1
#else
#define xdc_runtime_Memory___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_Memory_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Memory_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Memory_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Memory_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Memory_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Memory_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Memory_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Memory_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Memory_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Memory_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Memory_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Memory_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Memory_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Memory_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Memory_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_Memory___scope == -1
#ifdef xdc_runtime_Memory_alloc__PATCH
#define __FN__ xdc_runtime_Memory_alloc__PATCH
#else
#define __FN__ xdc_runtime_Memory_alloc__R
#endif
#else
#define __FN__ xdc_runtime_Memory_alloc__F
#endif
xdc_Ptr xdc_runtime_Memory_alloc__E( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Memory___L_EXIT
    xdc_Ptr __ret;
#else
#endif
#if xdc_runtime_Memory___L_ENTRY
    xdc_runtime_Log_write4(xdc_runtime_Memory_alloc__ENTRY_EVT, (xdc_IArg)heap, (xdc_IArg)size, (xdc_IArg)align, (xdc_IArg)eb);
#endif
#if xdc_runtime_Memory___L_EXIT
    __ret = __FN__(heap, size, align, eb);
    xdc_runtime_Log_write1(xdc_runtime_Memory_alloc__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(heap, size, align, eb);
#endif
}
#undef __FN__
#if xdc_runtime_Memory___scope == -1
#ifdef xdc_runtime_Memory_calloc__PATCH
#define __FN__ xdc_runtime_Memory_calloc__PATCH
#else
#define __FN__ xdc_runtime_Memory_calloc__R
#endif
#else
#define __FN__ xdc_runtime_Memory_calloc__F
#endif
xdc_Ptr xdc_runtime_Memory_calloc__E( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Memory___L_EXIT
    xdc_Ptr __ret;
#else
#endif
#if xdc_runtime_Memory___L_ENTRY
    xdc_runtime_Log_write4(xdc_runtime_Memory_calloc__ENTRY_EVT, (xdc_IArg)heap, (xdc_IArg)size, (xdc_IArg)align, (xdc_IArg)eb);
#endif
#if xdc_runtime_Memory___L_EXIT
    __ret = __FN__(heap, size, align, eb);
    xdc_runtime_Log_write1(xdc_runtime_Memory_calloc__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(heap, size, align, eb);
#endif
}
#undef __FN__
#if xdc_runtime_Memory___scope == -1
#ifdef xdc_runtime_Memory_free__PATCH
#define __FN__ xdc_runtime_Memory_free__PATCH
#else
#define __FN__ xdc_runtime_Memory_free__R
#endif
#else
#define __FN__ xdc_runtime_Memory_free__F
#endif
xdc_Void xdc_runtime_Memory_free__E( xdc_runtime_IHeap_Handle heap, xdc_Ptr block, xdc_SizeT size ) {
#if xdc_runtime_Memory___L_ENTRY
    xdc_runtime_Log_write3(xdc_runtime_Memory_free__ENTRY_EVT, (xdc_IArg)heap, (xdc_IArg)block, (xdc_IArg)size);
#endif
#if xdc_runtime_Memory___L_EXIT
    __FN__(heap, block, size);
    xdc_runtime_Log_write1(xdc_runtime_Memory_free__EXIT_EVT, 0);
#else
    __FN__(heap, block, size);
#endif
}
#undef __FN__
#if xdc_runtime_Memory___scope == -1
#ifdef xdc_runtime_Memory_getStats__PATCH
#define __FN__ xdc_runtime_Memory_getStats__PATCH
#else
#define __FN__ xdc_runtime_Memory_getStats__R
#endif
#else
#define __FN__ xdc_runtime_Memory_getStats__F
#endif
xdc_Void xdc_runtime_Memory_getStats__E( xdc_runtime_IHeap_Handle heap, xdc_runtime_Memory_Stats* stats ) {
#if xdc_runtime_Memory___L_ENTRY
    xdc_runtime_Log_write2(xdc_runtime_Memory_getStats__ENTRY_EVT, (xdc_IArg)heap, (xdc_IArg)stats);
#endif
#if xdc_runtime_Memory___L_EXIT
    __FN__(heap, stats);
    xdc_runtime_Log_write1(xdc_runtime_Memory_getStats__EXIT_EVT, 0);
#else
    __FN__(heap, stats);
#endif
}
#undef __FN__
#if xdc_runtime_Memory___scope == -1
#ifdef xdc_runtime_Memory_getMaxDefaultTypeAlign__PATCH
#define __FN__ xdc_runtime_Memory_getMaxDefaultTypeAlign__PATCH
#else
#define __FN__ xdc_runtime_Memory_getMaxDefaultTypeAlign__R
#endif
#else
#define __FN__ xdc_runtime_Memory_getMaxDefaultTypeAlign__F
#endif
xdc_SizeT xdc_runtime_Memory_getMaxDefaultTypeAlign__E( void ) {
#if xdc_runtime_Memory___L_EXIT
    xdc_SizeT __ret;
#else
#endif
#if xdc_runtime_Memory___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_Memory_getMaxDefaultTypeAlign__ENTRY_EVT);
#endif
#if xdc_runtime_Memory___L_EXIT
    __ret = __FN__();
    xdc_runtime_Log_write1(xdc_runtime_Memory_getMaxDefaultTypeAlign__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_Memory___scope == -1
#ifdef xdc_runtime_Memory_valloc__PATCH
#define __FN__ xdc_runtime_Memory_valloc__PATCH
#else
#define __FN__ xdc_runtime_Memory_valloc__R
#endif
#else
#define __FN__ xdc_runtime_Memory_valloc__F
#endif
xdc_Ptr xdc_runtime_Memory_valloc__E( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_Char value, xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Memory___L_EXIT
    xdc_Ptr __ret;
#else
#endif
#if xdc_runtime_Memory___L_ENTRY
    xdc_runtime_Log_write5(xdc_runtime_Memory_valloc__ENTRY_EVT, (xdc_IArg)heap, (xdc_IArg)size, (xdc_IArg)align, (xdc_IArg)value, (xdc_IArg)eb);
#endif
#if xdc_runtime_Memory___L_EXIT
    __ret = __FN__(heap, size, align, value, eb);
    xdc_runtime_Log_write1(xdc_runtime_Memory_valloc__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(heap, size, align, value, eb);
#endif
}

#if defined(xdc_runtime_Memory___EXPORT) && defined(__ti__)
#if xdc_runtime_Memory___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Memory_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_Memory_alloc__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_Memory_calloc__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_Memory_free__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_Memory_getStats__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_Memory_getMaxDefaultTypeAlign__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_Memory_valloc__E);
#endif
__FAR__ xdc_runtime_Memory_Module__MTAB__C__qual xdc_runtime_Memory_MTab__ xdc_runtime_Memory_Module__MTAB__C = {
#if xdc_runtime_Memory___scope == -1
#if xdc_runtime_Memory___L_ENTRY || xdc_runtime_Memory___L_EXIT
    xdc_runtime_Memory_alloc__E,
#elif defined(xdc_runtime_Memory_alloc__PATCH)
    xdc_runtime_Memory_alloc__PATCH,
#else
    xdc_runtime_Memory_alloc__R,
#endif
#if xdc_runtime_Memory___L_ENTRY || xdc_runtime_Memory___L_EXIT
    xdc_runtime_Memory_calloc__E,
#elif defined(xdc_runtime_Memory_calloc__PATCH)
    xdc_runtime_Memory_calloc__PATCH,
#else
    xdc_runtime_Memory_calloc__R,
#endif
#if xdc_runtime_Memory___L_ENTRY || xdc_runtime_Memory___L_EXIT
    xdc_runtime_Memory_free__E,
#elif defined(xdc_runtime_Memory_free__PATCH)
    xdc_runtime_Memory_free__PATCH,
#else
    xdc_runtime_Memory_free__R,
#endif
#if xdc_runtime_Memory___L_ENTRY || xdc_runtime_Memory___L_EXIT
    xdc_runtime_Memory_getStats__E,
#elif defined(xdc_runtime_Memory_getStats__PATCH)
    xdc_runtime_Memory_getStats__PATCH,
#else
    xdc_runtime_Memory_getStats__R,
#endif
#if xdc_runtime_Memory___L_ENTRY || xdc_runtime_Memory___L_EXIT
    xdc_runtime_Memory_getMaxDefaultTypeAlign__E,
#elif defined(xdc_runtime_Memory_getMaxDefaultTypeAlign__PATCH)
    xdc_runtime_Memory_getMaxDefaultTypeAlign__PATCH,
#else
    xdc_runtime_Memory_getMaxDefaultTypeAlign__R,
#endif
#if xdc_runtime_Memory___L_ENTRY || xdc_runtime_Memory___L_EXIT
    xdc_runtime_Memory_valloc__E,
#elif defined(xdc_runtime_Memory_valloc__PATCH)
    xdc_runtime_Memory_valloc__PATCH,
#else
    xdc_runtime_Memory_valloc__R,
#endif
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_Memory___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_Memory_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Memory_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Memory_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Memory_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Memory_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Memory_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Memory_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Memory_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Memory_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Memory_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Memory_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Memory_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Memory_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Memory_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Memory_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_Memory___scope == -1
#ifdef xdc_runtime_Memory_alloc__PATCH
#define __FN__ xdc_runtime_Memory_alloc__PATCH
#else
#define __FN__ xdc_runtime_Memory_alloc__R
#endif
#else
#define __FN__ xdc_runtime_Memory_alloc__F
#endif
xdc_Ptr xdc_runtime_Memory_alloc__E( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Memory___L_EXIT
    xdc_Ptr __ret;
#else
#endif
#if xdc_runtime_Memory___L_ENTRY
    xdc_runtime_Log_write4(xdc_runtime_Memory_alloc__ENTRY_EVT, (xdc_IArg)heap, (xdc_IArg)size, (xdc_IArg)align, (xdc_IArg)eb);
#endif
#if xdc_runtime_Memory___L_EXIT
    __ret = __FN__(heap, size, align, eb);
    xdc_runtime_Log_write1(xdc_runtime_Memory_alloc__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(heap, size, align, eb);
#endif
}
#undef __FN__
#if xdc_runtime_Memory___scope == -1
#ifdef xdc_runtime_Memory_calloc__PATCH
#define __FN__ xdc_runtime_Memory_calloc__PATCH
#else
#define __FN__ xdc_runtime_Memory_calloc__R
#endif
#else
#define __FN__ xdc_runtime_Memory_calloc__F
#endif
xdc_Ptr xdc_runtime_Memory_calloc__E( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Memory___L_EXIT
    xdc_Ptr __ret;
#else
#endif
#if xdc_runtime_Memory___L_ENTRY
    xdc_runtime_Log_write4(xdc_runtime_Memory_calloc__ENTRY_EVT, (xdc_IArg)heap, (xdc_IArg)size, (xdc_IArg)align, (xdc_IArg)eb);
#endif
#if xdc_runtime_Memory___L_EXIT
    __ret = __FN__(heap, size, align, eb);
    xdc_runtime_Log_write1(xdc_runtime_Memory_calloc__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(heap, size, align, eb);
#endif
}
#undef __FN__
#if xdc_runtime_Memory___scope == -1
#ifdef xdc_runtime_Memory_free__PATCH
#define __FN__ xdc_runtime_Memory_free__PATCH
#else
#define __FN__ xdc_runtime_Memory_free__R
#endif
#else
#define __FN__ xdc_runtime_Memory_free__F
#endif
xdc_Void xdc_runtime_Memory_free__E( xdc_runtime_IHeap_Handle heap, xdc_Ptr block, xdc_SizeT size ) {
#if xdc_runtime_Memory___L_ENTRY
    xdc_runtime_Log_write3(xdc_runtime_Memory_free__ENTRY_EVT, (xdc_IArg)heap, (xdc_IArg)block, (xdc_IArg)size);
#endif
#if xdc_runtime_Memory___L_EXIT
    __FN__(heap, block, size);
    xdc_runtime_Log_write1(xdc_runtime_Memory_free__EXIT_EVT, 0);
#else
    __FN__(heap, block, size);
#endif
}
#undef __FN__
#if xdc_runtime_Memory___scope == -1
#ifdef xdc_runtime_Memory_getStats__PATCH
#define __FN__ xdc_runtime_Memory_getStats__PATCH
#else
#define __FN__ xdc_runtime_Memory_getStats__R
#endif
#else
#define __FN__ xdc_runtime_Memory_getStats__F
#endif
xdc_Void xdc_runtime_Memory_getStats__E( xdc_runtime_IHeap_Handle heap, xdc_runtime_Memory_Stats* stats ) {
#if xdc_runtime_Memory___L_ENTRY
    xdc_runtime_Log_write2(xdc_runtime_Memory_getStats__ENTRY_EVT, (xdc_IArg)heap, (xdc_IArg)stats);
#endif
#if xdc_runtime_Memory___L_EXIT
    __FN__(heap, stats);
    xdc_runtime_Log_write1(xdc_runtime_Memory_getStats__EXIT_EVT, 0);
#else
    __FN__(heap, stats);
#endif
}
#undef __FN__
#if xdc_runtime_Memory___scope == -1
#ifdef xdc_runtime_Memory_getMaxDefaultTypeAlign__PATCH
#define __FN__ xdc_runtime_Memory_getMaxDefaultTypeAlign__PATCH
#else
#define __FN__ xdc_runtime_Memory_getMaxDefaultTypeAlign__R
#endif
#else
#define __FN__ xdc_runtime_Memory_getMaxDefaultTypeAlign__F
#endif
xdc_SizeT xdc_runtime_Memory_getMaxDefaultTypeAlign__E( void ) {
#if xdc_runtime_Memory___L_EXIT
    xdc_SizeT __ret;
#else
#endif
#if xdc_runtime_Memory___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_Memory_getMaxDefaultTypeAlign__ENTRY_EVT);
#endif
#if xdc_runtime_Memory___L_EXIT
    __ret = __FN__();
    xdc_runtime_Log_write1(xdc_runtime_Memory_getMaxDefaultTypeAlign__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_Memory___scope == -1
#ifdef xdc_runtime_Memory_valloc__PATCH
#define __FN__ xdc_runtime_Memory_valloc__PATCH
#else
#define __FN__ xdc_runtime_Memory_valloc__R
#endif
#else
#define __FN__ xdc_runtime_Memory_valloc__F
#endif
xdc_Ptr xdc_runtime_Memory_valloc__E( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_Char value, xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_Memory___L_EXIT
    xdc_Ptr __ret;
#else
#endif
#if xdc_runtime_Memory___L_ENTRY
    xdc_runtime_Log_write5(xdc_runtime_Memory_valloc__ENTRY_EVT, (xdc_IArg)heap, (xdc_IArg)size, (xdc_IArg)align, (xdc_IArg)value, (xdc_IArg)eb);
#endif
#if xdc_runtime_Memory___L_EXIT
    __ret = __FN__(heap, size, align, value, eb);
    xdc_runtime_Log_write1(xdc_runtime_Memory_valloc__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(heap, size, align, value, eb);
#endif
}
#endif /* xdc_runtime_Memory___ROMPATCH */
#ifdef xdc_runtime_Memory___ROMPATCH
xdc_Ptr xdc_runtime_Memory_alloc__E( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_Memory_Module__MTAB__C.alloc(heap, size, align, eb);
}
xdc_Ptr xdc_runtime_Memory_calloc__E( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_Memory_Module__MTAB__C.calloc(heap, size, align, eb);
}
xdc_Void xdc_runtime_Memory_free__E( xdc_runtime_IHeap_Handle heap, xdc_Ptr block, xdc_SizeT size ) {
    xdc_runtime_Memory_Module__MTAB__C.free(heap, block, size);
}
xdc_Void xdc_runtime_Memory_getStats__E( xdc_runtime_IHeap_Handle heap, xdc_runtime_Memory_Stats* stats ) {
    xdc_runtime_Memory_Module__MTAB__C.getStats(heap, stats);
}
xdc_SizeT xdc_runtime_Memory_getMaxDefaultTypeAlign__E( void ) {
    return xdc_runtime_Memory_Module__MTAB__C.getMaxDefaultTypeAlign();
}
xdc_Ptr xdc_runtime_Memory_valloc__E( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_Char value, xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_Memory_Module__MTAB__C.valloc(heap, size, align, value, eb);
}
#endif /* xdc_runtime_Memory___ROMPATCH */
xdc_Ptr xdc_runtime_Memory_alloc__R( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_Memory_alloc__F(heap, size, align, eb);
}
xdc_Ptr xdc_runtime_Memory_calloc__R( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_Memory_calloc__F(heap, size, align, eb);
}
xdc_Void xdc_runtime_Memory_free__R( xdc_runtime_IHeap_Handle heap, xdc_Ptr block, xdc_SizeT size ) {
    xdc_runtime_Memory_free__F(heap, block, size);
}
xdc_Void xdc_runtime_Memory_getStats__R( xdc_runtime_IHeap_Handle heap, xdc_runtime_Memory_Stats* stats ) {
    xdc_runtime_Memory_getStats__F(heap, stats);
}
xdc_SizeT xdc_runtime_Memory_getMaxDefaultTypeAlign__R( void ) {
    return xdc_runtime_Memory_getMaxDefaultTypeAlign__F();
}
xdc_Ptr xdc_runtime_Memory_valloc__R( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_Char value, xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_Memory_valloc__F(heap, size, align, value, eb);
}

#if defined(xdc_runtime_Memory___EXPORT) && defined(__ti__)
#if xdc_runtime_Memory___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Memory_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_Memory_alloc__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_Memory_calloc__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_Memory_free__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_Memory_getStats__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_Memory_getMaxDefaultTypeAlign__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_Memory_valloc__R);
#endif
#endif /* __isrom__ */

#if xdc_runtime_Memory___scope != -1
xdc_Bool xdc_runtime_Memory_Module__startupDone__S() {

    return 1;
}
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_HeapMin___used
/*
 *  ======== module HeapMin ========
 *  Do not modify this file; it is generated from the specification HeapMin.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_HeapMin__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/HeapMin.h>
#undef __nested__
#else
#include <xdc/runtime/HeapMin.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_HeapMin___LOGOBJ) && xdc_runtime_HeapMin___DGSINCL & 0x1
#define xdc_runtime_HeapMin___L_ENTRY 1
#else
#define xdc_runtime_HeapMin___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_HeapMin___LOGOBJ) && xdc_runtime_HeapMin___DGSINCL & 0x2
#define xdc_runtime_HeapMin___L_EXIT 1
#else
#define xdc_runtime_HeapMin___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_HeapMin___LOGOBJ) && xdc_runtime_HeapMin___DGSINCL & 0x4
#define xdc_runtime_HeapMin___L_LIFECYCLE 1
#else
#define xdc_runtime_HeapMin___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_HeapMin_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_HeapMin_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_HeapMin_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_HeapMin_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_HeapMin_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_HeapMin_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_HeapMin_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_HeapMin_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_HeapMin_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_HeapMin_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_HeapMin_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_HeapMin_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_HeapMin_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_HeapMin_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_HeapMin_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_HeapMin___scope == -1
#ifdef xdc_runtime_HeapMin_alloc__PATCH
#define __FN__ xdc_runtime_HeapMin_alloc__PATCH
#else
#define __FN__ xdc_runtime_HeapMin_alloc__R
#endif
#else
#define __FN__ xdc_runtime_HeapMin_alloc__F
#endif
xdc_Ptr xdc_runtime_HeapMin_alloc__E( xdc_runtime_HeapMin_Handle _this, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_HeapMin___L_EXIT
    xdc_Ptr __ret;
#else
#endif
#if xdc_runtime_HeapMin___L_ENTRY
    xdc_runtime_Log_write4(xdc_runtime_HeapMin_alloc__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)size, (xdc_IArg)align, (xdc_IArg)eb);
#endif
#if xdc_runtime_HeapMin___L_EXIT
    __ret = __FN__((void*)_this, size, align, eb);
    xdc_runtime_Log_write1(xdc_runtime_HeapMin_alloc__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__((void*)_this, size, align, eb);
#endif
}
#undef __FN__
#if xdc_runtime_HeapMin___scope == -1
#ifdef xdc_runtime_HeapMin_isBlocking__PATCH
#define __FN__ xdc_runtime_HeapMin_isBlocking__PATCH
#else
#define __FN__ xdc_runtime_HeapMin_isBlocking__R
#endif
#else
#define __FN__ xdc_runtime_HeapMin_isBlocking__F
#endif
xdc_Bool xdc_runtime_HeapMin_isBlocking__E( xdc_runtime_HeapMin_Handle _this ) {
#if xdc_runtime_HeapMin___L_EXIT
    xdc_Bool __ret;
#else
#endif
#if xdc_runtime_HeapMin___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_HeapMin_isBlocking__ENTRY_EVT, (xdc_IArg)_this);
#endif
#if xdc_runtime_HeapMin___L_EXIT
    __ret = __FN__((void*)_this);
    xdc_runtime_Log_write1(xdc_runtime_HeapMin_isBlocking__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__((void*)_this);
#endif
}
#undef __FN__
#if xdc_runtime_HeapMin___scope == -1
#ifdef xdc_runtime_HeapMin_getStats__PATCH
#define __FN__ xdc_runtime_HeapMin_getStats__PATCH
#else
#define __FN__ xdc_runtime_HeapMin_getStats__R
#endif
#else
#define __FN__ xdc_runtime_HeapMin_getStats__F
#endif
xdc_Void xdc_runtime_HeapMin_getStats__E( xdc_runtime_HeapMin_Handle _this, xdc_runtime_Memory_Stats* stats ) {
#if xdc_runtime_HeapMin___L_ENTRY
    xdc_runtime_Log_write2(xdc_runtime_HeapMin_getStats__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)stats);
#endif
#if xdc_runtime_HeapMin___L_EXIT
    __FN__((void*)_this, stats);
    xdc_runtime_Log_write1(xdc_runtime_HeapMin_getStats__EXIT_EVT, 0);
#else
    __FN__((void*)_this, stats);
#endif
}
#undef __FN__
#if xdc_runtime_HeapMin___scope == -1
#ifdef xdc_runtime_HeapMin_free__PATCH
#define __FN__ xdc_runtime_HeapMin_free__PATCH
#else
#define __FN__ xdc_runtime_HeapMin_free__R
#endif
#else
#define __FN__ xdc_runtime_HeapMin_free__F
#endif
xdc_Void xdc_runtime_HeapMin_free__E( xdc_runtime_HeapMin_Handle _this, xdc_Ptr block, xdc_SizeT size ) {
#if xdc_runtime_HeapMin___L_ENTRY
    xdc_runtime_Log_write3(xdc_runtime_HeapMin_free__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)block, (xdc_IArg)size);
#endif
#if xdc_runtime_HeapMin___L_EXIT
    __FN__((void*)_this, block, size);
    xdc_runtime_Log_write1(xdc_runtime_HeapMin_free__EXIT_EVT, 0);
#else
    __FN__((void*)_this, block, size);
#endif
}
typedef struct { xdc_runtime_HeapMin_Object2__ s0; char c; } xdc_runtime_HeapMin___S1;
__FAR__ xdc_runtime_HeapMin_Object__DESC__C__qual xdc_runtime_Core_ObjDesc xdc_runtime_HeapMin_Object__DESC__C = {
#ifdef xdc_runtime_HeapMin___FXNTAB
    (Ptr)&xdc_runtime_HeapMin_Module__FXNS__C, /* fxnTab */
#else
    (Ptr)0, /* fxnTab */
#endif
    &xdc_runtime_HeapMin_Module__root__V.hdr.link, /* modLink */
    sizeof(xdc_runtime_HeapMin___S1) - sizeof(xdc_runtime_HeapMin_Object2__), /* objAlign */
#ifdef xdc_runtime_HeapMin___OBJHEAP
    xdc_runtime_HeapMin___OBJHEAP, /* objHeap */
#else
    0, /* objHeap */
#endif
#ifdef xdc_runtime_HeapMin___NAMEDINST
    offsetof(xdc_runtime_HeapMin_Object__, __name), /* objName */
#else
    0, /* objName */
#endif
    sizeof(xdc_runtime_HeapMin_Object2__), /* objSize */
    (Ptr)&xdc_runtime_HeapMin_Object__PARAMS__C, /* prmsInit */
    sizeof(xdc_runtime_HeapMin_Params), /* prmsSize */
};

#if defined(xdc_runtime_HeapMin___EXPORT) && defined(__ti__)
#if xdc_runtime_HeapMin___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_Module__startupDone__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_Handle__label__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_Object__create__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_Object__delete__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_Object__destruct__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_Object__get__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_Params__init__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_alloc__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_free__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_isBlocking__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_getStats__E);
#endif
#ifdef xdc_runtime_HeapMin___FXNTAB
#if xdc_runtime_HeapMin___scope == -1 || !defined(__xdc_runtime_IModule_Interface__BASE__CR)
#ifndef __xdc_runtime_IModule_Interface__BASE__C
#define __xdc_runtime_IModule_Interface__BASE__C
__FAR__ xdc_runtime_IModule_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_IModule_Interface__BASE__C = {0};
#endif
#endif
#if xdc_runtime_HeapMin___scope == -1 || !defined(__xdc_runtime_IHeap_Interface__BASE__CR)
#ifndef __xdc_runtime_IHeap_Interface__BASE__C
#define __xdc_runtime_IHeap_Interface__BASE__C
__FAR__ xdc_runtime_IHeap_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_IHeap_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};
#endif
#endif

__FAR__ xdc_runtime_HeapMin_Module__FXNS__C__qual xdc_runtime_HeapMin_Fxns__ xdc_runtime_HeapMin_Module__FXNS__C = {
    /* base__ */ (void*)&xdc_runtime_IHeap_Interface__BASE__C,
    &xdc_runtime_HeapMin_Module__FXNS__C.__sfxns, /* __sysp */
    xdc_runtime_HeapMin_alloc__E,
    xdc_runtime_HeapMin_free__E,
    xdc_runtime_HeapMin_isBlocking__E,
    xdc_runtime_HeapMin_getStats__E,
    {

#ifdef xdc_runtime_HeapMin___OBJHEAP
        xdc_runtime_HeapMin_Object__create__S,
#else
        /* create__ */ 0,
#endif
#ifdef xdc_runtime_HeapMin___DELETE
        xdc_runtime_HeapMin_Object__delete__S,
#else
        /* delete__ */ 0,
#endif
        xdc_runtime_HeapMin_Handle__label__S,
        xdc_runtime_HeapMin_Module__id__D,
    } /* __sfxns */
};
#endif
__FAR__ xdc_runtime_HeapMin_Module__MTAB__C__qual xdc_runtime_HeapMin_MTab__ xdc_runtime_HeapMin_Module__MTAB__C = {
#if xdc_runtime_HeapMin___scope == -1
#if xdc_runtime_HeapMin___L_ENTRY || xdc_runtime_HeapMin___L_EXIT
    xdc_runtime_HeapMin_alloc__E,
#elif defined(xdc_runtime_HeapMin_alloc__PATCH)
    xdc_runtime_HeapMin_alloc__PATCH,
#else
    xdc_runtime_HeapMin_alloc__R,
#endif
#if xdc_runtime_HeapMin___L_ENTRY || xdc_runtime_HeapMin___L_EXIT
    xdc_runtime_HeapMin_free__E,
#elif defined(xdc_runtime_HeapMin_free__PATCH)
    xdc_runtime_HeapMin_free__PATCH,
#else
    xdc_runtime_HeapMin_free__R,
#endif
#if xdc_runtime_HeapMin___L_ENTRY || xdc_runtime_HeapMin___L_EXIT
    xdc_runtime_HeapMin_isBlocking__E,
#elif defined(xdc_runtime_HeapMin_isBlocking__PATCH)
    xdc_runtime_HeapMin_isBlocking__PATCH,
#else
    xdc_runtime_HeapMin_isBlocking__R,
#endif
#if xdc_runtime_HeapMin___L_ENTRY || xdc_runtime_HeapMin___L_EXIT
    xdc_runtime_HeapMin_getStats__E,
#elif defined(xdc_runtime_HeapMin_getStats__PATCH)
    xdc_runtime_HeapMin_getStats__PATCH,
#else
    xdc_runtime_HeapMin_getStats__R,
#endif
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_HeapMin___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_HeapMin_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_HeapMin_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_HeapMin_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_HeapMin_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_HeapMin_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_HeapMin_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_HeapMin_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_HeapMin_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_HeapMin_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_HeapMin_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_HeapMin_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_HeapMin_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_HeapMin_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_HeapMin_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_HeapMin_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_HeapMin___scope == -1
#ifdef xdc_runtime_HeapMin_alloc__PATCH
#define __FN__ xdc_runtime_HeapMin_alloc__PATCH
#else
#define __FN__ xdc_runtime_HeapMin_alloc__R
#endif
#else
#define __FN__ xdc_runtime_HeapMin_alloc__F
#endif
xdc_Ptr xdc_runtime_HeapMin_alloc__E( xdc_runtime_HeapMin_Handle _this, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_HeapMin___L_EXIT
    xdc_Ptr __ret;
#else
#endif
#if xdc_runtime_HeapMin___L_ENTRY
    xdc_runtime_Log_write4(xdc_runtime_HeapMin_alloc__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)size, (xdc_IArg)align, (xdc_IArg)eb);
#endif
#if xdc_runtime_HeapMin___L_EXIT
    __ret = __FN__((void*)_this, size, align, eb);
    xdc_runtime_Log_write1(xdc_runtime_HeapMin_alloc__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__((void*)_this, size, align, eb);
#endif
}
#undef __FN__
#if xdc_runtime_HeapMin___scope == -1
#ifdef xdc_runtime_HeapMin_isBlocking__PATCH
#define __FN__ xdc_runtime_HeapMin_isBlocking__PATCH
#else
#define __FN__ xdc_runtime_HeapMin_isBlocking__R
#endif
#else
#define __FN__ xdc_runtime_HeapMin_isBlocking__F
#endif
xdc_Bool xdc_runtime_HeapMin_isBlocking__E( xdc_runtime_HeapMin_Handle _this ) {
#if xdc_runtime_HeapMin___L_EXIT
    xdc_Bool __ret;
#else
#endif
#if xdc_runtime_HeapMin___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_HeapMin_isBlocking__ENTRY_EVT, (xdc_IArg)_this);
#endif
#if xdc_runtime_HeapMin___L_EXIT
    __ret = __FN__((void*)_this);
    xdc_runtime_Log_write1(xdc_runtime_HeapMin_isBlocking__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__((void*)_this);
#endif
}
#undef __FN__
#if xdc_runtime_HeapMin___scope == -1
#ifdef xdc_runtime_HeapMin_getStats__PATCH
#define __FN__ xdc_runtime_HeapMin_getStats__PATCH
#else
#define __FN__ xdc_runtime_HeapMin_getStats__R
#endif
#else
#define __FN__ xdc_runtime_HeapMin_getStats__F
#endif
xdc_Void xdc_runtime_HeapMin_getStats__E( xdc_runtime_HeapMin_Handle _this, xdc_runtime_Memory_Stats* stats ) {
#if xdc_runtime_HeapMin___L_ENTRY
    xdc_runtime_Log_write2(xdc_runtime_HeapMin_getStats__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)stats);
#endif
#if xdc_runtime_HeapMin___L_EXIT
    __FN__((void*)_this, stats);
    xdc_runtime_Log_write1(xdc_runtime_HeapMin_getStats__EXIT_EVT, 0);
#else
    __FN__((void*)_this, stats);
#endif
}
#undef __FN__
#if xdc_runtime_HeapMin___scope == -1
#ifdef xdc_runtime_HeapMin_free__PATCH
#define __FN__ xdc_runtime_HeapMin_free__PATCH
#else
#define __FN__ xdc_runtime_HeapMin_free__R
#endif
#else
#define __FN__ xdc_runtime_HeapMin_free__F
#endif
xdc_Void xdc_runtime_HeapMin_free__E( xdc_runtime_HeapMin_Handle _this, xdc_Ptr block, xdc_SizeT size ) {
#if xdc_runtime_HeapMin___L_ENTRY
    xdc_runtime_Log_write3(xdc_runtime_HeapMin_free__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)block, (xdc_IArg)size);
#endif
#if xdc_runtime_HeapMin___L_EXIT
    __FN__((void*)_this, block, size);
    xdc_runtime_Log_write1(xdc_runtime_HeapMin_free__EXIT_EVT, 0);
#else
    __FN__((void*)_this, block, size);
#endif
}
#endif /* xdc_runtime_HeapMin___ROMPATCH */
#ifdef xdc_runtime_HeapMin___ROMPATCH
xdc_Ptr xdc_runtime_HeapMin_alloc__E( xdc_runtime_HeapMin_Handle _this, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_HeapMin_Module__MTAB__C.alloc((void*)_this, size, align, eb);
}
xdc_Bool xdc_runtime_HeapMin_isBlocking__E( xdc_runtime_HeapMin_Handle _this ) {
    return xdc_runtime_HeapMin_Module__MTAB__C.isBlocking((void*)_this);
}
xdc_Void xdc_runtime_HeapMin_getStats__E( xdc_runtime_HeapMin_Handle _this, xdc_runtime_Memory_Stats* stats ) {
    xdc_runtime_HeapMin_Module__MTAB__C.getStats((void*)_this, stats);
}
xdc_Void xdc_runtime_HeapMin_free__E( xdc_runtime_HeapMin_Handle _this, xdc_Ptr block, xdc_SizeT size ) {
    xdc_runtime_HeapMin_Module__MTAB__C.free((void*)_this, block, size);
}
#endif /* xdc_runtime_HeapMin___ROMPATCH */
xdc_Ptr xdc_runtime_HeapMin_alloc__R( xdc_runtime_HeapMin_Handle _this, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_HeapMin_alloc__F((void*)_this, size, align, eb);
}
xdc_Bool xdc_runtime_HeapMin_isBlocking__R( xdc_runtime_HeapMin_Handle _this ) {
    return xdc_runtime_HeapMin_isBlocking__F((void*)_this);
}
xdc_Void xdc_runtime_HeapMin_getStats__R( xdc_runtime_HeapMin_Handle _this, xdc_runtime_Memory_Stats* stats ) {
    xdc_runtime_HeapMin_getStats__F((void*)_this, stats);
}
xdc_Void xdc_runtime_HeapMin_free__R( xdc_runtime_HeapMin_Handle _this, xdc_Ptr block, xdc_SizeT size ) {
    xdc_runtime_HeapMin_free__F((void*)_this, block, size);
}

#if defined(xdc_runtime_HeapMin___EXPORT) && defined(__ti__)
#if xdc_runtime_HeapMin___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_Module__startupDone__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_Handle__label__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_Object__create__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_Object__delete__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_Object__destruct__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_Object__get__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_Params__init__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_alloc__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_free__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_isBlocking__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapMin_getStats__R);
#endif
#endif /* __isrom__ */

#if xdc_runtime_HeapMin___scope != -1
xdc_Bool xdc_runtime_HeapMin_Module__startupDone__S() {

    return 1;
}
xdc_runtime_Types_Label* xdc_runtime_HeapMin_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab ) {
    lab->oaddr = obj;
    lab->modid = xdc_runtime_HeapMin_Module__id__D;
#ifdef xdc_runtime_HeapMin___NAMEDINST
    xdc_runtime_Core_assignLabel(lab, ((xdc_runtime_HeapMin_Object__*)obj)->__name, 1);
#else
    xdc_runtime_Core_assignLabel(lab, 0, 0);
#endif
    return lab;
}
xdc_Void xdc_runtime_HeapMin_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) {
#ifdef xdc_runtime_HeapMin___OBJHEAP
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &xdc_runtime_HeapMin_Object__PARAMS__C), psz, isz);
#endif
}
xdc_Ptr xdc_runtime_HeapMin_Object__get__S( xdc_Ptr oa, xdc_Int i ) {
    if (oa) return ((xdc_runtime_HeapMin_Object*)oa) + i;
    if (xdc_runtime_HeapMin_Object__count__C == 0) return 0;
    return ((xdc_runtime_HeapMin_Object*)xdc_runtime_HeapMin_Object__table__C) + i;
}

#ifdef xdc_runtime_HeapMin___OBJHEAP
extern xdc_Ptr xdc_runtime_HeapMin_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __psz, xdc_runtime_Error_Block* __eb ) {
    xdc_runtime_HeapMin_Params prms;
    xdc_runtime_HeapMin_Object* obj;
    obj = xdc_runtime_Core_createObject__I(&xdc_runtime_HeapMin_Object__DESC__C, __oa, __osz, &prms, __pa, __psz, __eb);
    if (!obj) return 0;
#ifdef xdc_runtime_HeapMin___DELETE
#define xdc_runtime_HeapMin___ISTAT 
#else
#define xdc_runtime_HeapMin___ISTAT
#endif
    xdc_runtime_HeapMin___ISTAT xdc_runtime_HeapMin_Instance_init__F(obj, &prms);
#if xdc_runtime_HeapMin___L_LIFECYCLE
#ifdef xdc_runtime_HeapMin___NAMEDINST
    xdc_runtime_Log_write2(__oa ? xdc_runtime_Log_L_construct : xdc_runtime_Log_L_create, (xdc_IArg)obj, (xdc_IArg)(((xdc_runtime_HeapMin_Object__*)obj)->__name));
#else
    xdc_runtime_Log_write2(__oa ? xdc_runtime_Log_L_construct : xdc_runtime_Log_L_create, (xdc_IArg)obj, 0);
#endif
#endif
    return obj;
}
#else
extern xdc_Ptr xdc_runtime_HeapMin_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __sz, xdc_runtime_Error_Block* __eb ) {
    xdc_runtime_Error_raiseX(NULL, xdc_runtime_HeapMin_Module__id__C, NULL, 0, xdc_runtime_Error_E_generic, (xdc_IArg)"create policy error", 0);
    return 0;
}
#endif

#ifdef xdc_runtime_HeapMin___DELETE
extern xdc_Void xdc_runtime_HeapMin_Object__destruct__S( xdc_Ptr obj ) {
#if xdc_runtime_HeapMin___L_LIFECYCLE
    xdc_runtime_Log_write1(xdc_runtime_Log_L_destruct, (xdc_IArg)obj);
#endif
    xdc_runtime_Core_deleteObject__I(&xdc_runtime_HeapMin_Object__DESC__C, obj, 0, -1, TRUE);
}
extern xdc_Void xdc_runtime_HeapMin_Object__delete__S( xdc_Ptr instp ) {
#if xdc_runtime_HeapMin___L_LIFECYCLE
    xdc_runtime_Log_write1(xdc_runtime_Log_L_delete, (xdc_IArg)(*((xdc_runtime_HeapMin_Object**)instp)));
#endif
    xdc_runtime_Core_deleteObject__I(&xdc_runtime_HeapMin_Object__DESC__C, *((xdc_runtime_HeapMin_Object**)instp), 0, -1, FALSE);
    *((xdc_runtime_HeapMin_Handle*)instp) = 0;
}
#else
extern xdc_Void xdc_runtime_HeapMin_Object__destruct__S( xdc_Ptr obj ) {
    xdc_runtime_Error_raiseX(NULL, xdc_runtime_HeapMin_Module__id__C, NULL, 0, xdc_runtime_Error_E_generic, (xdc_IArg)"delete policy error", 0);
}
extern xdc_Void xdc_runtime_HeapMin_Object__delete__S( xdc_Ptr instp ) {
    xdc_runtime_Error_raiseX(NULL, xdc_runtime_HeapMin_Module__id__C, NULL, 0, xdc_runtime_Error_E_generic, (xdc_IArg)"delete policy error", 0);
}
#endif
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_HeapStd___used
/*
 *  ======== module HeapStd ========
 *  Do not modify this file; it is generated from the specification HeapStd.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_HeapStd__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/HeapStd.h>
#undef __nested__
#else
#include <xdc/runtime/HeapStd.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_HeapStd___LOGOBJ) && xdc_runtime_HeapStd___DGSINCL & 0x1
#define xdc_runtime_HeapStd___L_ENTRY 1
#else
#define xdc_runtime_HeapStd___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_HeapStd___LOGOBJ) && xdc_runtime_HeapStd___DGSINCL & 0x2
#define xdc_runtime_HeapStd___L_EXIT 1
#else
#define xdc_runtime_HeapStd___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_HeapStd___LOGOBJ) && xdc_runtime_HeapStd___DGSINCL & 0x4
#define xdc_runtime_HeapStd___L_LIFECYCLE 1
#else
#define xdc_runtime_HeapStd___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_HeapStd_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_HeapStd_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_HeapStd_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_HeapStd_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_HeapStd_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_HeapStd_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_HeapStd_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_HeapStd_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_HeapStd_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_HeapStd_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_HeapStd_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_HeapStd_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_HeapStd_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_HeapStd_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_HeapStd_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_HeapStd___scope == -1
#ifdef xdc_runtime_HeapStd_free__PATCH
#define __FN__ xdc_runtime_HeapStd_free__PATCH
#else
#define __FN__ xdc_runtime_HeapStd_free__R
#endif
#else
#define __FN__ xdc_runtime_HeapStd_free__F
#endif
xdc_Void xdc_runtime_HeapStd_free__E( xdc_runtime_HeapStd_Handle _this, xdc_Ptr block, xdc_SizeT size ) {
#if xdc_runtime_HeapStd___L_ENTRY
    xdc_runtime_Log_write3(xdc_runtime_HeapStd_free__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)block, (xdc_IArg)size);
#endif
#if xdc_runtime_HeapStd___L_EXIT
    __FN__((void*)_this, block, size);
    xdc_runtime_Log_write1(xdc_runtime_HeapStd_free__EXIT_EVT, 0);
#else
    __FN__((void*)_this, block, size);
#endif
}
#undef __FN__
#if xdc_runtime_HeapStd___scope == -1
#ifdef xdc_runtime_HeapStd_isBlocking__PATCH
#define __FN__ xdc_runtime_HeapStd_isBlocking__PATCH
#else
#define __FN__ xdc_runtime_HeapStd_isBlocking__R
#endif
#else
#define __FN__ xdc_runtime_HeapStd_isBlocking__F
#endif
xdc_Bool xdc_runtime_HeapStd_isBlocking__E( xdc_runtime_HeapStd_Handle _this ) {
#if xdc_runtime_HeapStd___L_EXIT
    xdc_Bool __ret;
#else
#endif
#if xdc_runtime_HeapStd___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_HeapStd_isBlocking__ENTRY_EVT, (xdc_IArg)_this);
#endif
#if xdc_runtime_HeapStd___L_EXIT
    __ret = __FN__((void*)_this);
    xdc_runtime_Log_write1(xdc_runtime_HeapStd_isBlocking__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__((void*)_this);
#endif
}
#undef __FN__
#if xdc_runtime_HeapStd___scope == -1
#ifdef xdc_runtime_HeapStd_getStats__PATCH
#define __FN__ xdc_runtime_HeapStd_getStats__PATCH
#else
#define __FN__ xdc_runtime_HeapStd_getStats__R
#endif
#else
#define __FN__ xdc_runtime_HeapStd_getStats__F
#endif
xdc_Void xdc_runtime_HeapStd_getStats__E( xdc_runtime_HeapStd_Handle _this, xdc_runtime_Memory_Stats* stats ) {
#if xdc_runtime_HeapStd___L_ENTRY
    xdc_runtime_Log_write2(xdc_runtime_HeapStd_getStats__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)stats);
#endif
#if xdc_runtime_HeapStd___L_EXIT
    __FN__((void*)_this, stats);
    xdc_runtime_Log_write1(xdc_runtime_HeapStd_getStats__EXIT_EVT, 0);
#else
    __FN__((void*)_this, stats);
#endif
}
#undef __FN__
#if xdc_runtime_HeapStd___scope == -1
#ifdef xdc_runtime_HeapStd_alloc__PATCH
#define __FN__ xdc_runtime_HeapStd_alloc__PATCH
#else
#define __FN__ xdc_runtime_HeapStd_alloc__R
#endif
#else
#define __FN__ xdc_runtime_HeapStd_alloc__F
#endif
xdc_Ptr xdc_runtime_HeapStd_alloc__E( xdc_runtime_HeapStd_Handle _this, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_HeapStd___L_EXIT
    xdc_Ptr __ret;
#else
#endif
#if xdc_runtime_HeapStd___L_ENTRY
    xdc_runtime_Log_write4(xdc_runtime_HeapStd_alloc__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)size, (xdc_IArg)align, (xdc_IArg)eb);
#endif
#if xdc_runtime_HeapStd___L_EXIT
    __ret = __FN__((void*)_this, size, align, eb);
    xdc_runtime_Log_write1(xdc_runtime_HeapStd_alloc__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__((void*)_this, size, align, eb);
#endif
}
typedef struct { xdc_runtime_HeapStd_Object2__ s0; char c; } xdc_runtime_HeapStd___S1;
__FAR__ xdc_runtime_HeapStd_Object__DESC__C__qual xdc_runtime_Core_ObjDesc xdc_runtime_HeapStd_Object__DESC__C = {
#ifdef xdc_runtime_HeapStd___FXNTAB
    (Ptr)&xdc_runtime_HeapStd_Module__FXNS__C, /* fxnTab */
#else
    (Ptr)0, /* fxnTab */
#endif
    &xdc_runtime_HeapStd_Module__root__V.hdr.link, /* modLink */
    sizeof(xdc_runtime_HeapStd___S1) - sizeof(xdc_runtime_HeapStd_Object2__), /* objAlign */
#ifdef xdc_runtime_HeapStd___OBJHEAP
    xdc_runtime_HeapStd___OBJHEAP, /* objHeap */
#else
    0, /* objHeap */
#endif
#ifdef xdc_runtime_HeapStd___NAMEDINST
    offsetof(xdc_runtime_HeapStd_Object__, __name), /* objName */
#else
    0, /* objName */
#endif
    sizeof(xdc_runtime_HeapStd_Object2__), /* objSize */
    (Ptr)&xdc_runtime_HeapStd_Object__PARAMS__C, /* prmsInit */
    sizeof(xdc_runtime_HeapStd_Params), /* prmsSize */
};

#if defined(xdc_runtime_HeapStd___EXPORT) && defined(__ti__)
#if xdc_runtime_HeapStd___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_Module__startupDone__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_Handle__label__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_Object__create__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_Object__delete__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_Object__destruct__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_Object__get__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_Params__init__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_alloc__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_free__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_isBlocking__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_getStats__E);
#endif
#ifdef xdc_runtime_HeapStd___FXNTAB
#if xdc_runtime_HeapStd___scope == -1 || !defined(__xdc_runtime_IModule_Interface__BASE__CR)
#ifndef __xdc_runtime_IModule_Interface__BASE__C
#define __xdc_runtime_IModule_Interface__BASE__C
__FAR__ xdc_runtime_IModule_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_IModule_Interface__BASE__C = {0};
#endif
#endif
#if xdc_runtime_HeapStd___scope == -1 || !defined(__xdc_runtime_IHeap_Interface__BASE__CR)
#ifndef __xdc_runtime_IHeap_Interface__BASE__C
#define __xdc_runtime_IHeap_Interface__BASE__C
__FAR__ xdc_runtime_IHeap_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_IHeap_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};
#endif
#endif

__FAR__ xdc_runtime_HeapStd_Module__FXNS__C__qual xdc_runtime_HeapStd_Fxns__ xdc_runtime_HeapStd_Module__FXNS__C = {
    /* base__ */ (void*)&xdc_runtime_IHeap_Interface__BASE__C,
    &xdc_runtime_HeapStd_Module__FXNS__C.__sfxns, /* __sysp */
    xdc_runtime_HeapStd_alloc__E,
    xdc_runtime_HeapStd_free__E,
    xdc_runtime_HeapStd_isBlocking__E,
    xdc_runtime_HeapStd_getStats__E,
    {

#ifdef xdc_runtime_HeapStd___OBJHEAP
        xdc_runtime_HeapStd_Object__create__S,
#else
        /* create__ */ 0,
#endif
#ifdef xdc_runtime_HeapStd___DELETE
        xdc_runtime_HeapStd_Object__delete__S,
#else
        /* delete__ */ 0,
#endif
        xdc_runtime_HeapStd_Handle__label__S,
        xdc_runtime_HeapStd_Module__id__D,
    } /* __sfxns */
};
#endif
__FAR__ xdc_runtime_HeapStd_Module__MTAB__C__qual xdc_runtime_HeapStd_MTab__ xdc_runtime_HeapStd_Module__MTAB__C = {
#if xdc_runtime_HeapStd___scope == -1
#if xdc_runtime_HeapStd___L_ENTRY || xdc_runtime_HeapStd___L_EXIT
    xdc_runtime_HeapStd_alloc__E,
#elif defined(xdc_runtime_HeapStd_alloc__PATCH)
    xdc_runtime_HeapStd_alloc__PATCH,
#else
    xdc_runtime_HeapStd_alloc__R,
#endif
#if xdc_runtime_HeapStd___L_ENTRY || xdc_runtime_HeapStd___L_EXIT
    xdc_runtime_HeapStd_free__E,
#elif defined(xdc_runtime_HeapStd_free__PATCH)
    xdc_runtime_HeapStd_free__PATCH,
#else
    xdc_runtime_HeapStd_free__R,
#endif
#if xdc_runtime_HeapStd___L_ENTRY || xdc_runtime_HeapStd___L_EXIT
    xdc_runtime_HeapStd_isBlocking__E,
#elif defined(xdc_runtime_HeapStd_isBlocking__PATCH)
    xdc_runtime_HeapStd_isBlocking__PATCH,
#else
    xdc_runtime_HeapStd_isBlocking__R,
#endif
#if xdc_runtime_HeapStd___L_ENTRY || xdc_runtime_HeapStd___L_EXIT
    xdc_runtime_HeapStd_getStats__E,
#elif defined(xdc_runtime_HeapStd_getStats__PATCH)
    xdc_runtime_HeapStd_getStats__PATCH,
#else
    xdc_runtime_HeapStd_getStats__R,
#endif
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_HeapStd___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_HeapStd_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_HeapStd_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_HeapStd_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_HeapStd_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_HeapStd_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_HeapStd_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_HeapStd_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_HeapStd_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_HeapStd_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_HeapStd_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_HeapStd_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_HeapStd_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_HeapStd_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_HeapStd_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_HeapStd_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_HeapStd___scope == -1
#ifdef xdc_runtime_HeapStd_free__PATCH
#define __FN__ xdc_runtime_HeapStd_free__PATCH
#else
#define __FN__ xdc_runtime_HeapStd_free__R
#endif
#else
#define __FN__ xdc_runtime_HeapStd_free__F
#endif
xdc_Void xdc_runtime_HeapStd_free__E( xdc_runtime_HeapStd_Handle _this, xdc_Ptr block, xdc_SizeT size ) {
#if xdc_runtime_HeapStd___L_ENTRY
    xdc_runtime_Log_write3(xdc_runtime_HeapStd_free__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)block, (xdc_IArg)size);
#endif
#if xdc_runtime_HeapStd___L_EXIT
    __FN__((void*)_this, block, size);
    xdc_runtime_Log_write1(xdc_runtime_HeapStd_free__EXIT_EVT, 0);
#else
    __FN__((void*)_this, block, size);
#endif
}
#undef __FN__
#if xdc_runtime_HeapStd___scope == -1
#ifdef xdc_runtime_HeapStd_isBlocking__PATCH
#define __FN__ xdc_runtime_HeapStd_isBlocking__PATCH
#else
#define __FN__ xdc_runtime_HeapStd_isBlocking__R
#endif
#else
#define __FN__ xdc_runtime_HeapStd_isBlocking__F
#endif
xdc_Bool xdc_runtime_HeapStd_isBlocking__E( xdc_runtime_HeapStd_Handle _this ) {
#if xdc_runtime_HeapStd___L_EXIT
    xdc_Bool __ret;
#else
#endif
#if xdc_runtime_HeapStd___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_HeapStd_isBlocking__ENTRY_EVT, (xdc_IArg)_this);
#endif
#if xdc_runtime_HeapStd___L_EXIT
    __ret = __FN__((void*)_this);
    xdc_runtime_Log_write1(xdc_runtime_HeapStd_isBlocking__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__((void*)_this);
#endif
}
#undef __FN__
#if xdc_runtime_HeapStd___scope == -1
#ifdef xdc_runtime_HeapStd_getStats__PATCH
#define __FN__ xdc_runtime_HeapStd_getStats__PATCH
#else
#define __FN__ xdc_runtime_HeapStd_getStats__R
#endif
#else
#define __FN__ xdc_runtime_HeapStd_getStats__F
#endif
xdc_Void xdc_runtime_HeapStd_getStats__E( xdc_runtime_HeapStd_Handle _this, xdc_runtime_Memory_Stats* stats ) {
#if xdc_runtime_HeapStd___L_ENTRY
    xdc_runtime_Log_write2(xdc_runtime_HeapStd_getStats__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)stats);
#endif
#if xdc_runtime_HeapStd___L_EXIT
    __FN__((void*)_this, stats);
    xdc_runtime_Log_write1(xdc_runtime_HeapStd_getStats__EXIT_EVT, 0);
#else
    __FN__((void*)_this, stats);
#endif
}
#undef __FN__
#if xdc_runtime_HeapStd___scope == -1
#ifdef xdc_runtime_HeapStd_alloc__PATCH
#define __FN__ xdc_runtime_HeapStd_alloc__PATCH
#else
#define __FN__ xdc_runtime_HeapStd_alloc__R
#endif
#else
#define __FN__ xdc_runtime_HeapStd_alloc__F
#endif
xdc_Ptr xdc_runtime_HeapStd_alloc__E( xdc_runtime_HeapStd_Handle _this, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {
#if xdc_runtime_HeapStd___L_EXIT
    xdc_Ptr __ret;
#else
#endif
#if xdc_runtime_HeapStd___L_ENTRY
    xdc_runtime_Log_write4(xdc_runtime_HeapStd_alloc__ENTRY_EVT, (xdc_IArg)_this, (xdc_IArg)size, (xdc_IArg)align, (xdc_IArg)eb);
#endif
#if xdc_runtime_HeapStd___L_EXIT
    __ret = __FN__((void*)_this, size, align, eb);
    xdc_runtime_Log_write1(xdc_runtime_HeapStd_alloc__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__((void*)_this, size, align, eb);
#endif
}
#endif /* xdc_runtime_HeapStd___ROMPATCH */
#ifdef xdc_runtime_HeapStd___ROMPATCH
xdc_Void xdc_runtime_HeapStd_free__E( xdc_runtime_HeapStd_Handle _this, xdc_Ptr block, xdc_SizeT size ) {
    xdc_runtime_HeapStd_Module__MTAB__C.free((void*)_this, block, size);
}
xdc_Bool xdc_runtime_HeapStd_isBlocking__E( xdc_runtime_HeapStd_Handle _this ) {
    return xdc_runtime_HeapStd_Module__MTAB__C.isBlocking((void*)_this);
}
xdc_Void xdc_runtime_HeapStd_getStats__E( xdc_runtime_HeapStd_Handle _this, xdc_runtime_Memory_Stats* stats ) {
    xdc_runtime_HeapStd_Module__MTAB__C.getStats((void*)_this, stats);
}
xdc_Ptr xdc_runtime_HeapStd_alloc__E( xdc_runtime_HeapStd_Handle _this, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_HeapStd_Module__MTAB__C.alloc((void*)_this, size, align, eb);
}
#endif /* xdc_runtime_HeapStd___ROMPATCH */
xdc_Void xdc_runtime_HeapStd_free__R( xdc_runtime_HeapStd_Handle _this, xdc_Ptr block, xdc_SizeT size ) {
    xdc_runtime_HeapStd_free__F((void*)_this, block, size);
}
xdc_Bool xdc_runtime_HeapStd_isBlocking__R( xdc_runtime_HeapStd_Handle _this ) {
    return xdc_runtime_HeapStd_isBlocking__F((void*)_this);
}
xdc_Void xdc_runtime_HeapStd_getStats__R( xdc_runtime_HeapStd_Handle _this, xdc_runtime_Memory_Stats* stats ) {
    xdc_runtime_HeapStd_getStats__F((void*)_this, stats);
}
xdc_Ptr xdc_runtime_HeapStd_alloc__R( xdc_runtime_HeapStd_Handle _this, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {
    return xdc_runtime_HeapStd_alloc__F((void*)_this, size, align, eb);
}

#if defined(xdc_runtime_HeapStd___EXPORT) && defined(__ti__)
#if xdc_runtime_HeapStd___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_Module__startupDone__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_Handle__label__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_Object__create__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_Object__delete__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_Object__destruct__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_Object__get__S);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_Params__init__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_alloc__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_free__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_isBlocking__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_HeapStd_getStats__R);
#endif
#endif /* __isrom__ */

#if xdc_runtime_HeapStd___scope != -1
xdc_Bool xdc_runtime_HeapStd_Module__startupDone__S() {

    return 1;
}
xdc_runtime_Types_Label* xdc_runtime_HeapStd_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab ) {
    lab->oaddr = obj;
    lab->modid = xdc_runtime_HeapStd_Module__id__D;
#ifdef xdc_runtime_HeapStd___NAMEDINST
    xdc_runtime_Core_assignLabel(lab, ((xdc_runtime_HeapStd_Object__*)obj)->__name, 1);
#else
    xdc_runtime_Core_assignLabel(lab, 0, 0);
#endif
    return lab;
}
xdc_Void xdc_runtime_HeapStd_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) {
#ifdef xdc_runtime_HeapStd___OBJHEAP
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &xdc_runtime_HeapStd_Object__PARAMS__C), psz, isz);
#endif
}
xdc_Ptr xdc_runtime_HeapStd_Object__get__S( xdc_Ptr oa, xdc_Int i ) {
    if (oa) return ((xdc_runtime_HeapStd_Object*)oa) + i;
    if (xdc_runtime_HeapStd_Object__count__C == 0) return 0;
    return ((xdc_runtime_HeapStd_Object*)xdc_runtime_HeapStd_Object__table__C) + i;
}

#ifdef xdc_runtime_HeapStd___OBJHEAP
extern xdc_Ptr xdc_runtime_HeapStd_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __psz, xdc_runtime_Error_Block* __eb ) {
    xdc_runtime_HeapStd_Params prms;
    xdc_runtime_HeapStd_Object* obj;
    obj = xdc_runtime_Core_createObject__I(&xdc_runtime_HeapStd_Object__DESC__C, __oa, __osz, &prms, __pa, __psz, __eb);
    if (!obj) return 0;
#ifdef xdc_runtime_HeapStd___DELETE
#define xdc_runtime_HeapStd___ISTAT 
#else
#define xdc_runtime_HeapStd___ISTAT
#endif
    xdc_runtime_HeapStd___ISTAT xdc_runtime_HeapStd_Instance_init__F(obj, &prms);
#if xdc_runtime_HeapStd___L_LIFECYCLE
#ifdef xdc_runtime_HeapStd___NAMEDINST
    xdc_runtime_Log_write2(__oa ? xdc_runtime_Log_L_construct : xdc_runtime_Log_L_create, (xdc_IArg)obj, (xdc_IArg)(((xdc_runtime_HeapStd_Object__*)obj)->__name));
#else
    xdc_runtime_Log_write2(__oa ? xdc_runtime_Log_L_construct : xdc_runtime_Log_L_create, (xdc_IArg)obj, 0);
#endif
#endif
    return obj;
}
#else
extern xdc_Ptr xdc_runtime_HeapStd_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __sz, xdc_runtime_Error_Block* __eb ) {
    xdc_runtime_Error_raiseX(NULL, xdc_runtime_HeapStd_Module__id__C, NULL, 0, xdc_runtime_Error_E_generic, (xdc_IArg)"create policy error", 0);
    return 0;
}
#endif

#ifdef xdc_runtime_HeapStd___DELETE
extern xdc_Void xdc_runtime_HeapStd_Object__destruct__S( xdc_Ptr obj ) {
#if xdc_runtime_HeapStd___L_LIFECYCLE
    xdc_runtime_Log_write1(xdc_runtime_Log_L_destruct, (xdc_IArg)obj);
#endif
    xdc_runtime_Core_deleteObject__I(&xdc_runtime_HeapStd_Object__DESC__C, obj, 0, -1, TRUE);
}
extern xdc_Void xdc_runtime_HeapStd_Object__delete__S( xdc_Ptr instp ) {
#if xdc_runtime_HeapStd___L_LIFECYCLE
    xdc_runtime_Log_write1(xdc_runtime_Log_L_delete, (xdc_IArg)(*((xdc_runtime_HeapStd_Object**)instp)));
#endif
    xdc_runtime_Core_deleteObject__I(&xdc_runtime_HeapStd_Object__DESC__C, *((xdc_runtime_HeapStd_Object**)instp), 0, -1, FALSE);
    *((xdc_runtime_HeapStd_Handle*)instp) = 0;
}
#else
extern xdc_Void xdc_runtime_HeapStd_Object__destruct__S( xdc_Ptr obj ) {
    xdc_runtime_Error_raiseX(NULL, xdc_runtime_HeapStd_Module__id__C, NULL, 0, xdc_runtime_Error_E_generic, (xdc_IArg)"delete policy error", 0);
}
extern xdc_Void xdc_runtime_HeapStd_Object__delete__S( xdc_Ptr instp ) {
    xdc_runtime_Error_raiseX(NULL, xdc_runtime_HeapStd_Module__id__C, NULL, 0, xdc_runtime_Error_E_generic, (xdc_IArg)"delete policy error", 0);
}
#endif
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_Startup___used
/*
 *  ======== module Startup ========
 *  Do not modify this file; it is generated from the specification Startup.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_Startup__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Startup.h>
#undef __nested__
#else
#include <xdc/runtime/Startup.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Startup___LOGOBJ) && xdc_runtime_Startup___DGSINCL & 0x1
#define xdc_runtime_Startup___L_ENTRY 1
#else
#define xdc_runtime_Startup___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Startup___LOGOBJ) && xdc_runtime_Startup___DGSINCL & 0x2
#define xdc_runtime_Startup___L_EXIT 1
#else
#define xdc_runtime_Startup___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Startup___LOGOBJ) && xdc_runtime_Startup___DGSINCL & 0x4
#define xdc_runtime_Startup___L_LIFECYCLE 1
#else
#define xdc_runtime_Startup___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_Startup_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Startup_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Startup_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Startup_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Startup_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Startup_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Startup_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Startup_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Startup_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Startup_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Startup_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Startup_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Startup_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Startup_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Startup_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_Startup___scope == -1
#ifdef xdc_runtime_Startup_exec__PATCH
#define __FN__ xdc_runtime_Startup_exec__PATCH
#else
#define __FN__ xdc_runtime_Startup_exec__R
#endif
#else
#define __FN__ xdc_runtime_Startup_exec__F
#endif
xdc_Void xdc_runtime_Startup_exec__E( void ) {
#if xdc_runtime_Startup___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_Startup_exec__ENTRY_EVT);
#endif
#if xdc_runtime_Startup___L_EXIT
    __FN__();
    xdc_runtime_Log_write1(xdc_runtime_Startup_exec__EXIT_EVT, 0);
#else
    __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_Startup___scope == -1
#ifdef xdc_runtime_Startup_rtsDone__PATCH
#define __FN__ xdc_runtime_Startup_rtsDone__PATCH
#else
#define __FN__ xdc_runtime_Startup_rtsDone__R
#endif
#else
#define __FN__ xdc_runtime_Startup_rtsDone__F
#endif
xdc_Bool xdc_runtime_Startup_rtsDone__E( void ) {
#if xdc_runtime_Startup___L_EXIT
    xdc_Bool __ret;
#else
#endif
#if xdc_runtime_Startup___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_Startup_rtsDone__ENTRY_EVT);
#endif
#if xdc_runtime_Startup___L_EXIT
    __ret = __FN__();
    xdc_runtime_Log_write1(xdc_runtime_Startup_rtsDone__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__();
#endif
}

#if defined(xdc_runtime_Startup___EXPORT) && defined(__ti__)
#if xdc_runtime_Startup___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Startup_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_Startup_exec__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_Startup_rtsDone__E);
#endif
__FAR__ xdc_runtime_Startup_Module__MTAB__C__qual xdc_runtime_Startup_MTab__ xdc_runtime_Startup_Module__MTAB__C = {
#if xdc_runtime_Startup___scope == -1
#if xdc_runtime_Startup___L_ENTRY || xdc_runtime_Startup___L_EXIT
    xdc_runtime_Startup_exec__E,
#elif defined(xdc_runtime_Startup_exec__PATCH)
    xdc_runtime_Startup_exec__PATCH,
#else
    xdc_runtime_Startup_exec__R,
#endif
#if xdc_runtime_Startup___L_ENTRY || xdc_runtime_Startup___L_EXIT
    xdc_runtime_Startup_rtsDone__E,
#elif defined(xdc_runtime_Startup_rtsDone__PATCH)
    xdc_runtime_Startup_rtsDone__PATCH,
#else
    xdc_runtime_Startup_rtsDone__R,
#endif
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_Startup___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_Startup_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Startup_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Startup_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Startup_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Startup_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Startup_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Startup_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Startup_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Startup_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Startup_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Startup_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Startup_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Startup_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Startup_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Startup_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_Startup___scope == -1
#ifdef xdc_runtime_Startup_exec__PATCH
#define __FN__ xdc_runtime_Startup_exec__PATCH
#else
#define __FN__ xdc_runtime_Startup_exec__R
#endif
#else
#define __FN__ xdc_runtime_Startup_exec__F
#endif
xdc_Void xdc_runtime_Startup_exec__E( void ) {
#if xdc_runtime_Startup___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_Startup_exec__ENTRY_EVT);
#endif
#if xdc_runtime_Startup___L_EXIT
    __FN__();
    xdc_runtime_Log_write1(xdc_runtime_Startup_exec__EXIT_EVT, 0);
#else
    __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_Startup___scope == -1
#ifdef xdc_runtime_Startup_rtsDone__PATCH
#define __FN__ xdc_runtime_Startup_rtsDone__PATCH
#else
#define __FN__ xdc_runtime_Startup_rtsDone__R
#endif
#else
#define __FN__ xdc_runtime_Startup_rtsDone__F
#endif
xdc_Bool xdc_runtime_Startup_rtsDone__E( void ) {
#if xdc_runtime_Startup___L_EXIT
    xdc_Bool __ret;
#else
#endif
#if xdc_runtime_Startup___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_Startup_rtsDone__ENTRY_EVT);
#endif
#if xdc_runtime_Startup___L_EXIT
    __ret = __FN__();
    xdc_runtime_Log_write1(xdc_runtime_Startup_rtsDone__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__();
#endif
}
#endif /* xdc_runtime_Startup___ROMPATCH */
#ifdef xdc_runtime_Startup___ROMPATCH
xdc_Void xdc_runtime_Startup_exec__E( void ) {
    xdc_runtime_Startup_Module__MTAB__C.exec();
}
xdc_Bool xdc_runtime_Startup_rtsDone__E( void ) {
    return xdc_runtime_Startup_Module__MTAB__C.rtsDone();
}
#endif /* xdc_runtime_Startup___ROMPATCH */
xdc_Void xdc_runtime_Startup_exec__R( void ) {
    xdc_runtime_Startup_exec__F();
}
xdc_Bool xdc_runtime_Startup_rtsDone__R( void ) {
    return xdc_runtime_Startup_rtsDone__F();
}

#if defined(xdc_runtime_Startup___EXPORT) && defined(__ti__)
#if xdc_runtime_Startup___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Startup_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_Startup_exec__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_Startup_rtsDone__R);
#endif
#endif /* __isrom__ */

#if xdc_runtime_Startup___scope != -1
xdc_Bool xdc_runtime_Startup_Module__startupDone__S() {

    return 1;
}
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_System___used
/*
 *  ======== module System ========
 *  Do not modify this file; it is generated from the specification System.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_System___LOGOBJ) && xdc_runtime_System___DGSINCL & 0x1
#define xdc_runtime_System___L_ENTRY 1
#else
#define xdc_runtime_System___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_System___LOGOBJ) && xdc_runtime_System___DGSINCL & 0x2
#define xdc_runtime_System___L_EXIT 1
#else
#define xdc_runtime_System___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_System___LOGOBJ) && xdc_runtime_System___DGSINCL & 0x4
#define xdc_runtime_System___L_LIFECYCLE 1
#else
#define xdc_runtime_System___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_System_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_System_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_System_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_System_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_System_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_System_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_System_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_System_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_System_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_System_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_System_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_System_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_System_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_System_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_System_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_abort__PATCH
#define __FN__ xdc_runtime_System_abort__PATCH
#else
#define __FN__ xdc_runtime_System_abort__R
#endif
#else
#define __FN__ xdc_runtime_System_abort__F
#endif
xdc_Void xdc_runtime_System_abort__E( xdc_String str ) {
#if xdc_runtime_System___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_System_abort__ENTRY_EVT, (xdc_IArg)str);
#endif
#if xdc_runtime_System___L_EXIT
    __FN__(str);
    xdc_runtime_Log_write1(xdc_runtime_System_abort__EXIT_EVT, 0);
#else
    __FN__(str);
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_atexit__PATCH
#define __FN__ xdc_runtime_System_atexit__PATCH
#else
#define __FN__ xdc_runtime_System_atexit__R
#endif
#else
#define __FN__ xdc_runtime_System_atexit__F
#endif
xdc_Bool xdc_runtime_System_atexit__E( xdc_runtime_System_AtexitHandler handler ) {
#if xdc_runtime_System___L_EXIT
    xdc_Bool __ret;
#else
#endif
#if xdc_runtime_System___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_System_atexit__ENTRY_EVT, (xdc_IArg)handler);
#endif
#if xdc_runtime_System___L_EXIT
    __ret = __FN__(handler);
    xdc_runtime_Log_write1(xdc_runtime_System_atexit__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(handler);
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_exit__PATCH
#define __FN__ xdc_runtime_System_exit__PATCH
#else
#define __FN__ xdc_runtime_System_exit__R
#endif
#else
#define __FN__ xdc_runtime_System_exit__F
#endif
xdc_Void xdc_runtime_System_exit__E( xdc_Int stat ) {
#if xdc_runtime_System___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_System_exit__ENTRY_EVT, (xdc_IArg)stat);
#endif
#if xdc_runtime_System___L_EXIT
    __FN__(stat);
    xdc_runtime_Log_write1(xdc_runtime_System_exit__EXIT_EVT, 0);
#else
    __FN__(stat);
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_putch__PATCH
#define __FN__ xdc_runtime_System_putch__PATCH
#else
#define __FN__ xdc_runtime_System_putch__R
#endif
#else
#define __FN__ xdc_runtime_System_putch__F
#endif
xdc_Void xdc_runtime_System_putch__E( xdc_Char ch ) {
#if xdc_runtime_System___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_System_putch__ENTRY_EVT, (xdc_IArg)ch);
#endif
#if xdc_runtime_System___L_EXIT
    __FN__(ch);
    xdc_runtime_Log_write1(xdc_runtime_System_putch__EXIT_EVT, 0);
#else
    __FN__(ch);
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_flush__PATCH
#define __FN__ xdc_runtime_System_flush__PATCH
#else
#define __FN__ xdc_runtime_System_flush__R
#endif
#else
#define __FN__ xdc_runtime_System_flush__F
#endif
xdc_Void xdc_runtime_System_flush__E( void ) {
#if xdc_runtime_System___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_System_flush__ENTRY_EVT);
#endif
#if xdc_runtime_System___L_EXIT
    __FN__();
    xdc_runtime_Log_write1(xdc_runtime_System_flush__EXIT_EVT, 0);
#else
    __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_printf__PATCH
#define __FN__ xdc_runtime_System_printf__PATCH
#else
#define __FN__ xdc_runtime_System_printf_va__R
#endif
#else
#define __FN__ xdc_runtime_System_printf_va__F
#endif
xdc_Int xdc_runtime_System_printf_va__E( xdc_String fmt, va_list __va ) {
#if xdc_runtime_System___L_EXIT
    xdc_Int __ret;
#else
#endif
#if xdc_runtime_System___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_System_printf__ENTRY_EVT, (xdc_IArg)fmt);
#endif
#if xdc_runtime_System___L_EXIT
    __ret = __FN__(fmt, __va);
    xdc_runtime_Log_write1(xdc_runtime_System_printf__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(fmt, __va);
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_printf__PATCH
#define __FN__ xdc_runtime_System_printf__PATCH
#else
#define __FN__ xdc_runtime_System_printf_va__R
#endif
#else
#define __FN__ xdc_runtime_System_printf_va__F
#endif
xdc_Int xdc_runtime_System_printf__E( xdc_String fmt, ... ) {
#if xdc_runtime_System___L_EXIT
    xdc_Int __ret;
#else
    xdc_Int __ret;
#endif
    va_list __va; va_start(__va, fmt);
#if xdc_runtime_System___L_EXIT
    __ret = __FN__(fmt, __va);
    va_end(__va);
    xdc_runtime_Log_write1(xdc_runtime_System_printf__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    __ret = __FN__(fmt, __va);
    va_end(__va);
    return __ret;
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_sprintf__PATCH
#define __FN__ xdc_runtime_System_sprintf__PATCH
#else
#define __FN__ xdc_runtime_System_sprintf_va__R
#endif
#else
#define __FN__ xdc_runtime_System_sprintf_va__F
#endif
xdc_Int xdc_runtime_System_sprintf_va__E( xdc_Char buf[], xdc_String fmt, va_list __va ) {
#if xdc_runtime_System___L_EXIT
    xdc_Int __ret;
#else
#endif
#if xdc_runtime_System___L_ENTRY
    xdc_runtime_Log_write2(xdc_runtime_System_sprintf__ENTRY_EVT, (xdc_IArg)buf, (xdc_IArg)fmt);
#endif
#if xdc_runtime_System___L_EXIT
    __ret = __FN__(buf, fmt, __va);
    xdc_runtime_Log_write1(xdc_runtime_System_sprintf__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(buf, fmt, __va);
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_sprintf__PATCH
#define __FN__ xdc_runtime_System_sprintf__PATCH
#else
#define __FN__ xdc_runtime_System_sprintf_va__R
#endif
#else
#define __FN__ xdc_runtime_System_sprintf_va__F
#endif
xdc_Int xdc_runtime_System_sprintf__E( xdc_Char buf[], xdc_String fmt, ... ) {
#if xdc_runtime_System___L_EXIT
    xdc_Int __ret;
#else
    xdc_Int __ret;
#endif
    va_list __va; va_start(__va, fmt);
#if xdc_runtime_System___L_EXIT
    __ret = __FN__(buf, fmt, __va);
    va_end(__va);
    xdc_runtime_Log_write1(xdc_runtime_System_sprintf__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    __ret = __FN__(buf, fmt, __va);
    va_end(__va);
    return __ret;
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_vprintf__PATCH
#define __FN__ xdc_runtime_System_vprintf__PATCH
#else
#define __FN__ xdc_runtime_System_vprintf__R
#endif
#else
#define __FN__ xdc_runtime_System_vprintf__F
#endif
xdc_Int xdc_runtime_System_vprintf__E( xdc_String fmt, xdc_VaList va ) {
#if xdc_runtime_System___L_EXIT
    xdc_Int __ret;
#else
#endif
#if xdc_runtime_System___L_ENTRY
    xdc_runtime_Log_write2(xdc_runtime_System_vprintf__ENTRY_EVT, (xdc_IArg)fmt, (xdc_IArg)va);
#endif
#if xdc_runtime_System___L_EXIT
    __ret = __FN__(fmt, va);
    xdc_runtime_Log_write1(xdc_runtime_System_vprintf__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(fmt, va);
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_vsprintf__PATCH
#define __FN__ xdc_runtime_System_vsprintf__PATCH
#else
#define __FN__ xdc_runtime_System_vsprintf__R
#endif
#else
#define __FN__ xdc_runtime_System_vsprintf__F
#endif
xdc_Int xdc_runtime_System_vsprintf__E( xdc_Char buf[], xdc_String fmt, xdc_VaList va ) {
#if xdc_runtime_System___L_EXIT
    xdc_Int __ret;
#else
#endif
#if xdc_runtime_System___L_ENTRY
    xdc_runtime_Log_write3(xdc_runtime_System_vsprintf__ENTRY_EVT, (xdc_IArg)buf, (xdc_IArg)fmt, (xdc_IArg)va);
#endif
#if xdc_runtime_System___L_EXIT
    __ret = __FN__(buf, fmt, va);
    xdc_runtime_Log_write1(xdc_runtime_System_vsprintf__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(buf, fmt, va);
#endif
}
#if xdc_runtime_System___scope == -1
xdc_Int xdc_runtime_System_Module_startup__E( xdc_Int state ) { return xdc_runtime_System_Module_startup__R(state); }
#else
xdc_Int xdc_runtime_System_Module_startup__E( xdc_Int state ) { return xdc_runtime_System_Module_startup__F(state); }
#endif

#if defined(xdc_runtime_System___EXPORT) && defined(__ti__)
#if xdc_runtime_System___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_System_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_System_Module_startup__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_System_abort__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_System_atexit__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_System_exit__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_System_putch__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_System_flush__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_System_printf__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_System_sprintf__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_System_vprintf__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_System_vsprintf__E);
#endif
__FAR__ xdc_runtime_System_Module__MTAB__C__qual xdc_runtime_System_MTab__ xdc_runtime_System_Module__MTAB__C = {
#if xdc_runtime_System___scope == -1
#if xdc_runtime_System___L_ENTRY || xdc_runtime_System___L_EXIT
    xdc_runtime_System_abort__E,
#elif defined(xdc_runtime_System_abort__PATCH)
    xdc_runtime_System_abort__PATCH,
#else
    xdc_runtime_System_abort__R,
#endif
#if xdc_runtime_System___L_ENTRY || xdc_runtime_System___L_EXIT
    xdc_runtime_System_atexit__E,
#elif defined(xdc_runtime_System_atexit__PATCH)
    xdc_runtime_System_atexit__PATCH,
#else
    xdc_runtime_System_atexit__R,
#endif
#if xdc_runtime_System___L_ENTRY || xdc_runtime_System___L_EXIT
    xdc_runtime_System_exit__E,
#elif defined(xdc_runtime_System_exit__PATCH)
    xdc_runtime_System_exit__PATCH,
#else
    xdc_runtime_System_exit__R,
#endif
#if xdc_runtime_System___L_ENTRY || xdc_runtime_System___L_EXIT
    xdc_runtime_System_putch__E,
#elif defined(xdc_runtime_System_putch__PATCH)
    xdc_runtime_System_putch__PATCH,
#else
    xdc_runtime_System_putch__R,
#endif
#if xdc_runtime_System___L_ENTRY || xdc_runtime_System___L_EXIT
    xdc_runtime_System_flush__E,
#elif defined(xdc_runtime_System_flush__PATCH)
    xdc_runtime_System_flush__PATCH,
#else
    xdc_runtime_System_flush__R,
#endif
#if xdc_runtime_System___L_ENTRY || xdc_runtime_System___L_EXIT
    xdc_runtime_System_printf_va__E,
#elif defined(xdc_runtime_System_printf__PATCH)
    xdc_runtime_System_printf__PATCH,
#else
    xdc_runtime_System_printf_va__R,
#endif
#if xdc_runtime_System___L_ENTRY || xdc_runtime_System___L_EXIT
    xdc_runtime_System_sprintf_va__E,
#elif defined(xdc_runtime_System_sprintf__PATCH)
    xdc_runtime_System_sprintf__PATCH,
#else
    xdc_runtime_System_sprintf_va__R,
#endif
#if xdc_runtime_System___L_ENTRY || xdc_runtime_System___L_EXIT
    xdc_runtime_System_vprintf__E,
#elif defined(xdc_runtime_System_vprintf__PATCH)
    xdc_runtime_System_vprintf__PATCH,
#else
    xdc_runtime_System_vprintf__R,
#endif
#if xdc_runtime_System___L_ENTRY || xdc_runtime_System___L_EXIT
    xdc_runtime_System_vsprintf__E,
#elif defined(xdc_runtime_System_vsprintf__PATCH)
    xdc_runtime_System_vsprintf__PATCH,
#else
    xdc_runtime_System_vsprintf__R,
#endif
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_System___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_System_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_System_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_System_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_System_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_System_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_System_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_System_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_System_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_System_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_System_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_System_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_System_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_System_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_System_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_System_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_abort__PATCH
#define __FN__ xdc_runtime_System_abort__PATCH
#else
#define __FN__ xdc_runtime_System_abort__R
#endif
#else
#define __FN__ xdc_runtime_System_abort__F
#endif
xdc_Void xdc_runtime_System_abort__E( xdc_String str ) {
#if xdc_runtime_System___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_System_abort__ENTRY_EVT, (xdc_IArg)str);
#endif
#if xdc_runtime_System___L_EXIT
    __FN__(str);
    xdc_runtime_Log_write1(xdc_runtime_System_abort__EXIT_EVT, 0);
#else
    __FN__(str);
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_atexit__PATCH
#define __FN__ xdc_runtime_System_atexit__PATCH
#else
#define __FN__ xdc_runtime_System_atexit__R
#endif
#else
#define __FN__ xdc_runtime_System_atexit__F
#endif
xdc_Bool xdc_runtime_System_atexit__E( xdc_runtime_System_AtexitHandler handler ) {
#if xdc_runtime_System___L_EXIT
    xdc_Bool __ret;
#else
#endif
#if xdc_runtime_System___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_System_atexit__ENTRY_EVT, (xdc_IArg)handler);
#endif
#if xdc_runtime_System___L_EXIT
    __ret = __FN__(handler);
    xdc_runtime_Log_write1(xdc_runtime_System_atexit__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(handler);
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_exit__PATCH
#define __FN__ xdc_runtime_System_exit__PATCH
#else
#define __FN__ xdc_runtime_System_exit__R
#endif
#else
#define __FN__ xdc_runtime_System_exit__F
#endif
xdc_Void xdc_runtime_System_exit__E( xdc_Int stat ) {
#if xdc_runtime_System___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_System_exit__ENTRY_EVT, (xdc_IArg)stat);
#endif
#if xdc_runtime_System___L_EXIT
    __FN__(stat);
    xdc_runtime_Log_write1(xdc_runtime_System_exit__EXIT_EVT, 0);
#else
    __FN__(stat);
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_putch__PATCH
#define __FN__ xdc_runtime_System_putch__PATCH
#else
#define __FN__ xdc_runtime_System_putch__R
#endif
#else
#define __FN__ xdc_runtime_System_putch__F
#endif
xdc_Void xdc_runtime_System_putch__E( xdc_Char ch ) {
#if xdc_runtime_System___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_System_putch__ENTRY_EVT, (xdc_IArg)ch);
#endif
#if xdc_runtime_System___L_EXIT
    __FN__(ch);
    xdc_runtime_Log_write1(xdc_runtime_System_putch__EXIT_EVT, 0);
#else
    __FN__(ch);
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_flush__PATCH
#define __FN__ xdc_runtime_System_flush__PATCH
#else
#define __FN__ xdc_runtime_System_flush__R
#endif
#else
#define __FN__ xdc_runtime_System_flush__F
#endif
xdc_Void xdc_runtime_System_flush__E( void ) {
#if xdc_runtime_System___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_System_flush__ENTRY_EVT);
#endif
#if xdc_runtime_System___L_EXIT
    __FN__();
    xdc_runtime_Log_write1(xdc_runtime_System_flush__EXIT_EVT, 0);
#else
    __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_printf__PATCH
#define __FN__ xdc_runtime_System_printf__PATCH
#else
#define __FN__ xdc_runtime_System_printf_va__R
#endif
#else
#define __FN__ xdc_runtime_System_printf_va__F
#endif
xdc_Int xdc_runtime_System_printf_va__E( xdc_String fmt, va_list __va ) {
#if xdc_runtime_System___L_EXIT
    xdc_Int __ret;
#else
#endif
#if xdc_runtime_System___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_System_printf__ENTRY_EVT, (xdc_IArg)fmt);
#endif
#if xdc_runtime_System___L_EXIT
    __ret = __FN__(fmt, __va);
    xdc_runtime_Log_write1(xdc_runtime_System_printf__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(fmt, __va);
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_printf__PATCH
#define __FN__ xdc_runtime_System_printf__PATCH
#else
#define __FN__ xdc_runtime_System_printf_va__R
#endif
#else
#define __FN__ xdc_runtime_System_printf_va__F
#endif
xdc_Int xdc_runtime_System_printf__E( xdc_String fmt, ... ) {
#if xdc_runtime_System___L_EXIT
    xdc_Int __ret;
#else
    xdc_Int __ret;
#endif
    va_list __va; va_start(__va, fmt);
#if xdc_runtime_System___L_EXIT
    __ret = __FN__(fmt, __va);
    va_end(__va);
    xdc_runtime_Log_write1(xdc_runtime_System_printf__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    __ret = __FN__(fmt, __va);
    va_end(__va);
    return __ret;
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_sprintf__PATCH
#define __FN__ xdc_runtime_System_sprintf__PATCH
#else
#define __FN__ xdc_runtime_System_sprintf_va__R
#endif
#else
#define __FN__ xdc_runtime_System_sprintf_va__F
#endif
xdc_Int xdc_runtime_System_sprintf_va__E( xdc_Char buf[], xdc_String fmt, va_list __va ) {
#if xdc_runtime_System___L_EXIT
    xdc_Int __ret;
#else
#endif
#if xdc_runtime_System___L_ENTRY
    xdc_runtime_Log_write2(xdc_runtime_System_sprintf__ENTRY_EVT, (xdc_IArg)buf, (xdc_IArg)fmt);
#endif
#if xdc_runtime_System___L_EXIT
    __ret = __FN__(buf, fmt, __va);
    xdc_runtime_Log_write1(xdc_runtime_System_sprintf__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(buf, fmt, __va);
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_sprintf__PATCH
#define __FN__ xdc_runtime_System_sprintf__PATCH
#else
#define __FN__ xdc_runtime_System_sprintf_va__R
#endif
#else
#define __FN__ xdc_runtime_System_sprintf_va__F
#endif
xdc_Int xdc_runtime_System_sprintf__E( xdc_Char buf[], xdc_String fmt, ... ) {
#if xdc_runtime_System___L_EXIT
    xdc_Int __ret;
#else
    xdc_Int __ret;
#endif
    va_list __va; va_start(__va, fmt);
#if xdc_runtime_System___L_EXIT
    __ret = __FN__(buf, fmt, __va);
    va_end(__va);
    xdc_runtime_Log_write1(xdc_runtime_System_sprintf__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    __ret = __FN__(buf, fmt, __va);
    va_end(__va);
    return __ret;
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_vprintf__PATCH
#define __FN__ xdc_runtime_System_vprintf__PATCH
#else
#define __FN__ xdc_runtime_System_vprintf__R
#endif
#else
#define __FN__ xdc_runtime_System_vprintf__F
#endif
xdc_Int xdc_runtime_System_vprintf__E( xdc_String fmt, xdc_VaList va ) {
#if xdc_runtime_System___L_EXIT
    xdc_Int __ret;
#else
#endif
#if xdc_runtime_System___L_ENTRY
    xdc_runtime_Log_write2(xdc_runtime_System_vprintf__ENTRY_EVT, (xdc_IArg)fmt, (xdc_IArg)va);
#endif
#if xdc_runtime_System___L_EXIT
    __ret = __FN__(fmt, va);
    xdc_runtime_Log_write1(xdc_runtime_System_vprintf__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(fmt, va);
#endif
}
#undef __FN__
#if xdc_runtime_System___scope == -1
#ifdef xdc_runtime_System_vsprintf__PATCH
#define __FN__ xdc_runtime_System_vsprintf__PATCH
#else
#define __FN__ xdc_runtime_System_vsprintf__R
#endif
#else
#define __FN__ xdc_runtime_System_vsprintf__F
#endif
xdc_Int xdc_runtime_System_vsprintf__E( xdc_Char buf[], xdc_String fmt, xdc_VaList va ) {
#if xdc_runtime_System___L_EXIT
    xdc_Int __ret;
#else
#endif
#if xdc_runtime_System___L_ENTRY
    xdc_runtime_Log_write3(xdc_runtime_System_vsprintf__ENTRY_EVT, (xdc_IArg)buf, (xdc_IArg)fmt, (xdc_IArg)va);
#endif
#if xdc_runtime_System___L_EXIT
    __ret = __FN__(buf, fmt, va);
    xdc_runtime_Log_write1(xdc_runtime_System_vsprintf__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(buf, fmt, va);
#endif
}
#if xdc_runtime_System___scope == -1
xdc_Int xdc_runtime_System_Module_startup__E( xdc_Int state ) { return xdc_runtime_System_Module_startup__R(state); }
#else
xdc_Int xdc_runtime_System_Module_startup__E( xdc_Int state ) { return xdc_runtime_System_Module_startup__F(state); }
#endif
#endif /* xdc_runtime_System___ROMPATCH */
#ifdef xdc_runtime_System___ROMPATCH
xdc_Void xdc_runtime_System_abort__E( xdc_String str ) {
    xdc_runtime_System_Module__MTAB__C.abort(str);
}
xdc_Bool xdc_runtime_System_atexit__E( xdc_runtime_System_AtexitHandler handler ) {
    return xdc_runtime_System_Module__MTAB__C.atexit(handler);
}
xdc_Void xdc_runtime_System_exit__E( xdc_Int stat ) {
    xdc_runtime_System_Module__MTAB__C.exit(stat);
}
xdc_Void xdc_runtime_System_putch__E( xdc_Char ch ) {
    xdc_runtime_System_Module__MTAB__C.putch(ch);
}
xdc_Void xdc_runtime_System_flush__E( void ) {
    xdc_runtime_System_Module__MTAB__C.flush();
}
xdc_Int xdc_runtime_System_printf_va__E( xdc_String fmt, va_list __va ) {
    return xdc_runtime_System_Module__MTAB__C.printf(fmt, __va);
}
xdc_Int xdc_runtime_System_printf__E( xdc_String fmt, ... ) {
    xdc_Int __ret;
    va_list __va; va_start(__va, fmt);
    __ret = xdc_runtime_System_Module__MTAB__C.printf(fmt, __va);
    va_end(__va);
    return __ret;
}
xdc_Int xdc_runtime_System_sprintf_va__E( xdc_Char buf[], xdc_String fmt, va_list __va ) {
    return xdc_runtime_System_Module__MTAB__C.sprintf(buf, fmt, __va);
}
xdc_Int xdc_runtime_System_sprintf__E( xdc_Char buf[], xdc_String fmt, ... ) {
    xdc_Int __ret;
    va_list __va; va_start(__va, fmt);
    __ret = xdc_runtime_System_Module__MTAB__C.sprintf(buf, fmt, __va);
    va_end(__va);
    return __ret;
}
xdc_Int xdc_runtime_System_vprintf__E( xdc_String fmt, xdc_VaList va ) {
    return xdc_runtime_System_Module__MTAB__C.vprintf(fmt, va);
}
xdc_Int xdc_runtime_System_vsprintf__E( xdc_Char buf[], xdc_String fmt, xdc_VaList va ) {
    return xdc_runtime_System_Module__MTAB__C.vsprintf(buf, fmt, va);
}
#if xdc_runtime_System___scope == -1
xdc_Int xdc_runtime_System_Module_startup__E( xdc_Int state ) { return xdc_runtime_System_Module_startup__R(state); }
#else
xdc_Int xdc_runtime_System_Module_startup__E( xdc_Int state ) { return xdc_runtime_System_Module_startup__F(state); }
#endif
#endif /* xdc_runtime_System___ROMPATCH */
xdc_Void xdc_runtime_System_abort__R( xdc_String str ) {
    xdc_runtime_System_abort__F(str);
}
xdc_Bool xdc_runtime_System_atexit__R( xdc_runtime_System_AtexitHandler handler ) {
    return xdc_runtime_System_atexit__F(handler);
}
xdc_Void xdc_runtime_System_exit__R( xdc_Int stat ) {
    xdc_runtime_System_exit__F(stat);
}
xdc_Void xdc_runtime_System_putch__R( xdc_Char ch ) {
    xdc_runtime_System_putch__F(ch);
}
xdc_Void xdc_runtime_System_flush__R( void ) {
    xdc_runtime_System_flush__F();
}
xdc_Int xdc_runtime_System_printf_va__R( xdc_String fmt, va_list __va ) {
    return xdc_runtime_System_printf_va__F(fmt, __va);
}
xdc_Int xdc_runtime_System_sprintf_va__R( xdc_Char buf[], xdc_String fmt, va_list __va ) {
    return xdc_runtime_System_sprintf_va__F(buf, fmt, __va);
}
xdc_Int xdc_runtime_System_vprintf__R( xdc_String fmt, xdc_VaList va ) {
    return xdc_runtime_System_vprintf__F(fmt, va);
}
xdc_Int xdc_runtime_System_vsprintf__R( xdc_Char buf[], xdc_String fmt, xdc_VaList va ) {
    return xdc_runtime_System_vsprintf__F(buf, fmt, va);
}
xdc_Int xdc_runtime_System_Module_startup__R( xdc_Int state ) { return xdc_runtime_System_Module_startup__F(state); }

#if defined(xdc_runtime_System___EXPORT) && defined(__ti__)
#if xdc_runtime_System___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_System_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_System_Module_startup__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_System_abort__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_System_atexit__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_System_exit__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_System_putch__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_System_flush__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_System_printf_va__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_System_sprintf_va__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_System_vprintf__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_System_vsprintf__R);
#endif
#endif /* __isrom__ */

#if xdc_runtime_System___scope != -1
xdc_Bool xdc_runtime_System_Module__startupDone__S() {

    return xdc_runtime_System_Module__startupDoneFxn__C();
}
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_SysStd___used
/*
 *  ======== module SysStd ========
 *  Do not modify this file; it is generated from the specification SysStd.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_SysStd__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/SysStd.h>
#undef __nested__
#else
#include <xdc/runtime/SysStd.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_SysStd___LOGOBJ) && xdc_runtime_SysStd___DGSINCL & 0x1
#define xdc_runtime_SysStd___L_ENTRY 1
#else
#define xdc_runtime_SysStd___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_SysStd___LOGOBJ) && xdc_runtime_SysStd___DGSINCL & 0x2
#define xdc_runtime_SysStd___L_EXIT 1
#else
#define xdc_runtime_SysStd___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_SysStd___LOGOBJ) && xdc_runtime_SysStd___DGSINCL & 0x4
#define xdc_runtime_SysStd___L_LIFECYCLE 1
#else
#define xdc_runtime_SysStd___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_SysStd_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_SysStd_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_SysStd_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_SysStd_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_SysStd_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_SysStd_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_SysStd_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_SysStd_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_SysStd_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_SysStd_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_SysStd_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_SysStd_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_SysStd_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_SysStd_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_SysStd_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_SysStd___scope == -1
#ifdef xdc_runtime_SysStd_abort__PATCH
#define __FN__ xdc_runtime_SysStd_abort__PATCH
#else
#define __FN__ xdc_runtime_SysStd_abort__R
#endif
#else
#define __FN__ xdc_runtime_SysStd_abort__F
#endif
xdc_Void xdc_runtime_SysStd_abort__E( xdc_String str ) {
#if xdc_runtime_SysStd___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_SysStd_abort__ENTRY_EVT, (xdc_IArg)str);
#endif
#if xdc_runtime_SysStd___L_EXIT
    __FN__(str);
    xdc_runtime_Log_write1(xdc_runtime_SysStd_abort__EXIT_EVT, 0);
#else
    __FN__(str);
#endif
}
#undef __FN__
#if xdc_runtime_SysStd___scope == -1
#ifdef xdc_runtime_SysStd_exit__PATCH
#define __FN__ xdc_runtime_SysStd_exit__PATCH
#else
#define __FN__ xdc_runtime_SysStd_exit__R
#endif
#else
#define __FN__ xdc_runtime_SysStd_exit__F
#endif
xdc_Void xdc_runtime_SysStd_exit__E( xdc_Int stat ) {
#if xdc_runtime_SysStd___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_SysStd_exit__ENTRY_EVT, (xdc_IArg)stat);
#endif
#if xdc_runtime_SysStd___L_EXIT
    __FN__(stat);
    xdc_runtime_Log_write1(xdc_runtime_SysStd_exit__EXIT_EVT, 0);
#else
    __FN__(stat);
#endif
}
#undef __FN__
#if xdc_runtime_SysStd___scope == -1
#ifdef xdc_runtime_SysStd_flush__PATCH
#define __FN__ xdc_runtime_SysStd_flush__PATCH
#else
#define __FN__ xdc_runtime_SysStd_flush__R
#endif
#else
#define __FN__ xdc_runtime_SysStd_flush__F
#endif
xdc_Void xdc_runtime_SysStd_flush__E( void ) {
#if xdc_runtime_SysStd___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_SysStd_flush__ENTRY_EVT);
#endif
#if xdc_runtime_SysStd___L_EXIT
    __FN__();
    xdc_runtime_Log_write1(xdc_runtime_SysStd_flush__EXIT_EVT, 0);
#else
    __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_SysStd___scope == -1
#ifdef xdc_runtime_SysStd_putch__PATCH
#define __FN__ xdc_runtime_SysStd_putch__PATCH
#else
#define __FN__ xdc_runtime_SysStd_putch__R
#endif
#else
#define __FN__ xdc_runtime_SysStd_putch__F
#endif
xdc_Void xdc_runtime_SysStd_putch__E( xdc_Char ch ) {
#if xdc_runtime_SysStd___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_SysStd_putch__ENTRY_EVT, (xdc_IArg)ch);
#endif
#if xdc_runtime_SysStd___L_EXIT
    __FN__(ch);
    xdc_runtime_Log_write1(xdc_runtime_SysStd_putch__EXIT_EVT, 0);
#else
    __FN__(ch);
#endif
}
#undef __FN__
#if xdc_runtime_SysStd___scope == -1
#ifdef xdc_runtime_SysStd_ready__PATCH
#define __FN__ xdc_runtime_SysStd_ready__PATCH
#else
#define __FN__ xdc_runtime_SysStd_ready__R
#endif
#else
#define __FN__ xdc_runtime_SysStd_ready__F
#endif
xdc_Bool xdc_runtime_SysStd_ready__E( void ) {
#if xdc_runtime_SysStd___L_EXIT
    xdc_Bool __ret;
#else
#endif
#if xdc_runtime_SysStd___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_SysStd_ready__ENTRY_EVT);
#endif
#if xdc_runtime_SysStd___L_EXIT
    __ret = __FN__();
    xdc_runtime_Log_write1(xdc_runtime_SysStd_ready__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__();
#endif
}

#if defined(xdc_runtime_SysStd___EXPORT) && defined(__ti__)
#if xdc_runtime_SysStd___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_SysStd_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_SysStd_abort__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_SysStd_exit__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_SysStd_flush__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_SysStd_putch__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_SysStd_ready__E);
#endif
#ifdef xdc_runtime_SysStd___FXNTAB
#if xdc_runtime_SysStd___scope == -1 || !defined(__xdc_runtime_IModule_Interface__BASE__CR)
#ifndef __xdc_runtime_IModule_Interface__BASE__C
#define __xdc_runtime_IModule_Interface__BASE__C
__FAR__ xdc_runtime_IModule_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_IModule_Interface__BASE__C = {0};
#endif
#endif
#if xdc_runtime_SysStd___scope == -1 || !defined(__xdc_runtime_ISystemSupport_Interface__BASE__CR)
#ifndef __xdc_runtime_ISystemSupport_Interface__BASE__C
#define __xdc_runtime_ISystemSupport_Interface__BASE__C
__FAR__ xdc_runtime_ISystemSupport_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_ISystemSupport_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};
#endif
#endif

__FAR__ xdc_runtime_SysStd_Module__FXNS__C__qual xdc_runtime_SysStd_Fxns__ xdc_runtime_SysStd_Module__FXNS__C = {
    /* base__ */ (void*)&xdc_runtime_ISystemSupport_Interface__BASE__C,
    &xdc_runtime_SysStd_Module__FXNS__C.__sfxns, /* __sysp */
    xdc_runtime_SysStd_abort__E,
    xdc_runtime_SysStd_exit__E,
    xdc_runtime_SysStd_flush__E,
    xdc_runtime_SysStd_putch__E,
    xdc_runtime_SysStd_ready__E,
    {

        /* create__ */ 0,
        /* delete__ */ 0,
        /* label__ */ 0,
        xdc_runtime_SysStd_Module__id__D,
    } /* __sfxns */
};
#endif
__FAR__ xdc_runtime_SysStd_Module__MTAB__C__qual xdc_runtime_SysStd_MTab__ xdc_runtime_SysStd_Module__MTAB__C = {
#if xdc_runtime_SysStd___scope == -1
#if xdc_runtime_SysStd___L_ENTRY || xdc_runtime_SysStd___L_EXIT
    xdc_runtime_SysStd_abort__E,
#elif defined(xdc_runtime_SysStd_abort__PATCH)
    xdc_runtime_SysStd_abort__PATCH,
#else
    xdc_runtime_SysStd_abort__R,
#endif
#if xdc_runtime_SysStd___L_ENTRY || xdc_runtime_SysStd___L_EXIT
    xdc_runtime_SysStd_exit__E,
#elif defined(xdc_runtime_SysStd_exit__PATCH)
    xdc_runtime_SysStd_exit__PATCH,
#else
    xdc_runtime_SysStd_exit__R,
#endif
#if xdc_runtime_SysStd___L_ENTRY || xdc_runtime_SysStd___L_EXIT
    xdc_runtime_SysStd_flush__E,
#elif defined(xdc_runtime_SysStd_flush__PATCH)
    xdc_runtime_SysStd_flush__PATCH,
#else
    xdc_runtime_SysStd_flush__R,
#endif
#if xdc_runtime_SysStd___L_ENTRY || xdc_runtime_SysStd___L_EXIT
    xdc_runtime_SysStd_putch__E,
#elif defined(xdc_runtime_SysStd_putch__PATCH)
    xdc_runtime_SysStd_putch__PATCH,
#else
    xdc_runtime_SysStd_putch__R,
#endif
#if xdc_runtime_SysStd___L_ENTRY || xdc_runtime_SysStd___L_EXIT
    xdc_runtime_SysStd_ready__E,
#elif defined(xdc_runtime_SysStd_ready__PATCH)
    xdc_runtime_SysStd_ready__PATCH,
#else
    xdc_runtime_SysStd_ready__R,
#endif
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_SysStd___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_SysStd_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_SysStd_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_SysStd_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_SysStd_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_SysStd_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_SysStd_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_SysStd_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_SysStd_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_SysStd_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_SysStd_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_SysStd_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_SysStd_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_SysStd_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_SysStd_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_SysStd_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_SysStd___scope == -1
#ifdef xdc_runtime_SysStd_abort__PATCH
#define __FN__ xdc_runtime_SysStd_abort__PATCH
#else
#define __FN__ xdc_runtime_SysStd_abort__R
#endif
#else
#define __FN__ xdc_runtime_SysStd_abort__F
#endif
xdc_Void xdc_runtime_SysStd_abort__E( xdc_String str ) {
#if xdc_runtime_SysStd___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_SysStd_abort__ENTRY_EVT, (xdc_IArg)str);
#endif
#if xdc_runtime_SysStd___L_EXIT
    __FN__(str);
    xdc_runtime_Log_write1(xdc_runtime_SysStd_abort__EXIT_EVT, 0);
#else
    __FN__(str);
#endif
}
#undef __FN__
#if xdc_runtime_SysStd___scope == -1
#ifdef xdc_runtime_SysStd_exit__PATCH
#define __FN__ xdc_runtime_SysStd_exit__PATCH
#else
#define __FN__ xdc_runtime_SysStd_exit__R
#endif
#else
#define __FN__ xdc_runtime_SysStd_exit__F
#endif
xdc_Void xdc_runtime_SysStd_exit__E( xdc_Int stat ) {
#if xdc_runtime_SysStd___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_SysStd_exit__ENTRY_EVT, (xdc_IArg)stat);
#endif
#if xdc_runtime_SysStd___L_EXIT
    __FN__(stat);
    xdc_runtime_Log_write1(xdc_runtime_SysStd_exit__EXIT_EVT, 0);
#else
    __FN__(stat);
#endif
}
#undef __FN__
#if xdc_runtime_SysStd___scope == -1
#ifdef xdc_runtime_SysStd_flush__PATCH
#define __FN__ xdc_runtime_SysStd_flush__PATCH
#else
#define __FN__ xdc_runtime_SysStd_flush__R
#endif
#else
#define __FN__ xdc_runtime_SysStd_flush__F
#endif
xdc_Void xdc_runtime_SysStd_flush__E( void ) {
#if xdc_runtime_SysStd___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_SysStd_flush__ENTRY_EVT);
#endif
#if xdc_runtime_SysStd___L_EXIT
    __FN__();
    xdc_runtime_Log_write1(xdc_runtime_SysStd_flush__EXIT_EVT, 0);
#else
    __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_SysStd___scope == -1
#ifdef xdc_runtime_SysStd_putch__PATCH
#define __FN__ xdc_runtime_SysStd_putch__PATCH
#else
#define __FN__ xdc_runtime_SysStd_putch__R
#endif
#else
#define __FN__ xdc_runtime_SysStd_putch__F
#endif
xdc_Void xdc_runtime_SysStd_putch__E( xdc_Char ch ) {
#if xdc_runtime_SysStd___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_SysStd_putch__ENTRY_EVT, (xdc_IArg)ch);
#endif
#if xdc_runtime_SysStd___L_EXIT
    __FN__(ch);
    xdc_runtime_Log_write1(xdc_runtime_SysStd_putch__EXIT_EVT, 0);
#else
    __FN__(ch);
#endif
}
#undef __FN__
#if xdc_runtime_SysStd___scope == -1
#ifdef xdc_runtime_SysStd_ready__PATCH
#define __FN__ xdc_runtime_SysStd_ready__PATCH
#else
#define __FN__ xdc_runtime_SysStd_ready__R
#endif
#else
#define __FN__ xdc_runtime_SysStd_ready__F
#endif
xdc_Bool xdc_runtime_SysStd_ready__E( void ) {
#if xdc_runtime_SysStd___L_EXIT
    xdc_Bool __ret;
#else
#endif
#if xdc_runtime_SysStd___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_SysStd_ready__ENTRY_EVT);
#endif
#if xdc_runtime_SysStd___L_EXIT
    __ret = __FN__();
    xdc_runtime_Log_write1(xdc_runtime_SysStd_ready__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__();
#endif
}
#endif /* xdc_runtime_SysStd___ROMPATCH */
#ifdef xdc_runtime_SysStd___ROMPATCH
xdc_Void xdc_runtime_SysStd_abort__E( xdc_String str ) {
    xdc_runtime_SysStd_Module__MTAB__C.abort(str);
}
xdc_Void xdc_runtime_SysStd_exit__E( xdc_Int stat ) {
    xdc_runtime_SysStd_Module__MTAB__C.exit(stat);
}
xdc_Void xdc_runtime_SysStd_flush__E( void ) {
    xdc_runtime_SysStd_Module__MTAB__C.flush();
}
xdc_Void xdc_runtime_SysStd_putch__E( xdc_Char ch ) {
    xdc_runtime_SysStd_Module__MTAB__C.putch(ch);
}
xdc_Bool xdc_runtime_SysStd_ready__E( void ) {
    return xdc_runtime_SysStd_Module__MTAB__C.ready();
}
#endif /* xdc_runtime_SysStd___ROMPATCH */
xdc_Void xdc_runtime_SysStd_abort__R( xdc_String str ) {
    xdc_runtime_SysStd_abort__F(str);
}
xdc_Void xdc_runtime_SysStd_exit__R( xdc_Int stat ) {
    xdc_runtime_SysStd_exit__F(stat);
}
xdc_Void xdc_runtime_SysStd_flush__R( void ) {
    xdc_runtime_SysStd_flush__F();
}
xdc_Void xdc_runtime_SysStd_putch__R( xdc_Char ch ) {
    xdc_runtime_SysStd_putch__F(ch);
}
xdc_Bool xdc_runtime_SysStd_ready__R( void ) {
    return xdc_runtime_SysStd_ready__F();
}

#if defined(xdc_runtime_SysStd___EXPORT) && defined(__ti__)
#if xdc_runtime_SysStd___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_SysStd_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_SysStd_abort__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_SysStd_exit__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_SysStd_flush__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_SysStd_putch__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_SysStd_ready__R);
#endif
#endif /* __isrom__ */

#if xdc_runtime_SysStd___scope != -1
xdc_Bool xdc_runtime_SysStd_Module__startupDone__S() {

    return 1;
}
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_SysMin___used
/*
 *  ======== module SysMin ========
 *  Do not modify this file; it is generated from the specification SysMin.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_SysMin__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/SysMin.h>
#undef __nested__
#else
#include <xdc/runtime/SysMin.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_SysMin___LOGOBJ) && xdc_runtime_SysMin___DGSINCL & 0x1
#define xdc_runtime_SysMin___L_ENTRY 1
#else
#define xdc_runtime_SysMin___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_SysMin___LOGOBJ) && xdc_runtime_SysMin___DGSINCL & 0x2
#define xdc_runtime_SysMin___L_EXIT 1
#else
#define xdc_runtime_SysMin___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_SysMin___LOGOBJ) && xdc_runtime_SysMin___DGSINCL & 0x4
#define xdc_runtime_SysMin___L_LIFECYCLE 1
#else
#define xdc_runtime_SysMin___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_SysMin_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_SysMin_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_SysMin_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_SysMin_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_SysMin_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_SysMin_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_SysMin_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_SysMin_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_SysMin_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_SysMin_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_SysMin_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_SysMin_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_SysMin_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_SysMin_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_SysMin_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_SysMin___scope == -1
#ifdef xdc_runtime_SysMin_abort__PATCH
#define __FN__ xdc_runtime_SysMin_abort__PATCH
#else
#define __FN__ xdc_runtime_SysMin_abort__R
#endif
#else
#define __FN__ xdc_runtime_SysMin_abort__F
#endif
xdc_Void xdc_runtime_SysMin_abort__E( xdc_String str ) {
#if xdc_runtime_SysMin___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_SysMin_abort__ENTRY_EVT, (xdc_IArg)str);
#endif
#if xdc_runtime_SysMin___L_EXIT
    __FN__(str);
    xdc_runtime_Log_write1(xdc_runtime_SysMin_abort__EXIT_EVT, 0);
#else
    __FN__(str);
#endif
}
#undef __FN__
#if xdc_runtime_SysMin___scope == -1
#ifdef xdc_runtime_SysMin_exit__PATCH
#define __FN__ xdc_runtime_SysMin_exit__PATCH
#else
#define __FN__ xdc_runtime_SysMin_exit__R
#endif
#else
#define __FN__ xdc_runtime_SysMin_exit__F
#endif
xdc_Void xdc_runtime_SysMin_exit__E( xdc_Int stat ) {
#if xdc_runtime_SysMin___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_SysMin_exit__ENTRY_EVT, (xdc_IArg)stat);
#endif
#if xdc_runtime_SysMin___L_EXIT
    __FN__(stat);
    xdc_runtime_Log_write1(xdc_runtime_SysMin_exit__EXIT_EVT, 0);
#else
    __FN__(stat);
#endif
}
#undef __FN__
#if xdc_runtime_SysMin___scope == -1
#ifdef xdc_runtime_SysMin_flush__PATCH
#define __FN__ xdc_runtime_SysMin_flush__PATCH
#else
#define __FN__ xdc_runtime_SysMin_flush__R
#endif
#else
#define __FN__ xdc_runtime_SysMin_flush__F
#endif
xdc_Void xdc_runtime_SysMin_flush__E( void ) {
#if xdc_runtime_SysMin___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_SysMin_flush__ENTRY_EVT);
#endif
#if xdc_runtime_SysMin___L_EXIT
    __FN__();
    xdc_runtime_Log_write1(xdc_runtime_SysMin_flush__EXIT_EVT, 0);
#else
    __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_SysMin___scope == -1
#ifdef xdc_runtime_SysMin_putch__PATCH
#define __FN__ xdc_runtime_SysMin_putch__PATCH
#else
#define __FN__ xdc_runtime_SysMin_putch__R
#endif
#else
#define __FN__ xdc_runtime_SysMin_putch__F
#endif
xdc_Void xdc_runtime_SysMin_putch__E( xdc_Char ch ) {
#if xdc_runtime_SysMin___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_SysMin_putch__ENTRY_EVT, (xdc_IArg)ch);
#endif
#if xdc_runtime_SysMin___L_EXIT
    __FN__(ch);
    xdc_runtime_Log_write1(xdc_runtime_SysMin_putch__EXIT_EVT, 0);
#else
    __FN__(ch);
#endif
}
#undef __FN__
#if xdc_runtime_SysMin___scope == -1
#ifdef xdc_runtime_SysMin_ready__PATCH
#define __FN__ xdc_runtime_SysMin_ready__PATCH
#else
#define __FN__ xdc_runtime_SysMin_ready__R
#endif
#else
#define __FN__ xdc_runtime_SysMin_ready__F
#endif
xdc_Bool xdc_runtime_SysMin_ready__E( void ) {
#if xdc_runtime_SysMin___L_EXIT
    xdc_Bool __ret;
#else
#endif
#if xdc_runtime_SysMin___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_SysMin_ready__ENTRY_EVT);
#endif
#if xdc_runtime_SysMin___L_EXIT
    __ret = __FN__();
    xdc_runtime_Log_write1(xdc_runtime_SysMin_ready__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__();
#endif
}

#if defined(xdc_runtime_SysMin___EXPORT) && defined(__ti__)
#if xdc_runtime_SysMin___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_SysMin_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_SysMin_abort__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_SysMin_exit__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_SysMin_flush__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_SysMin_putch__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_SysMin_ready__E);
#endif
#ifdef xdc_runtime_SysMin___FXNTAB
#if xdc_runtime_SysMin___scope == -1 || !defined(__xdc_runtime_IModule_Interface__BASE__CR)
#ifndef __xdc_runtime_IModule_Interface__BASE__C
#define __xdc_runtime_IModule_Interface__BASE__C
__FAR__ xdc_runtime_IModule_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_IModule_Interface__BASE__C = {0};
#endif
#endif
#if xdc_runtime_SysMin___scope == -1 || !defined(__xdc_runtime_ISystemSupport_Interface__BASE__CR)
#ifndef __xdc_runtime_ISystemSupport_Interface__BASE__C
#define __xdc_runtime_ISystemSupport_Interface__BASE__C
__FAR__ xdc_runtime_ISystemSupport_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_ISystemSupport_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};
#endif
#endif

__FAR__ xdc_runtime_SysMin_Module__FXNS__C__qual xdc_runtime_SysMin_Fxns__ xdc_runtime_SysMin_Module__FXNS__C = {
    /* base__ */ (void*)&xdc_runtime_ISystemSupport_Interface__BASE__C,
    &xdc_runtime_SysMin_Module__FXNS__C.__sfxns, /* __sysp */
    xdc_runtime_SysMin_abort__E,
    xdc_runtime_SysMin_exit__E,
    xdc_runtime_SysMin_flush__E,
    xdc_runtime_SysMin_putch__E,
    xdc_runtime_SysMin_ready__E,
    {

        /* create__ */ 0,
        /* delete__ */ 0,
        /* label__ */ 0,
        xdc_runtime_SysMin_Module__id__D,
    } /* __sfxns */
};
#endif
__FAR__ xdc_runtime_SysMin_Module__MTAB__C__qual xdc_runtime_SysMin_MTab__ xdc_runtime_SysMin_Module__MTAB__C = {
#if xdc_runtime_SysMin___scope == -1
#if xdc_runtime_SysMin___L_ENTRY || xdc_runtime_SysMin___L_EXIT
    xdc_runtime_SysMin_abort__E,
#elif defined(xdc_runtime_SysMin_abort__PATCH)
    xdc_runtime_SysMin_abort__PATCH,
#else
    xdc_runtime_SysMin_abort__R,
#endif
#if xdc_runtime_SysMin___L_ENTRY || xdc_runtime_SysMin___L_EXIT
    xdc_runtime_SysMin_exit__E,
#elif defined(xdc_runtime_SysMin_exit__PATCH)
    xdc_runtime_SysMin_exit__PATCH,
#else
    xdc_runtime_SysMin_exit__R,
#endif
#if xdc_runtime_SysMin___L_ENTRY || xdc_runtime_SysMin___L_EXIT
    xdc_runtime_SysMin_flush__E,
#elif defined(xdc_runtime_SysMin_flush__PATCH)
    xdc_runtime_SysMin_flush__PATCH,
#else
    xdc_runtime_SysMin_flush__R,
#endif
#if xdc_runtime_SysMin___L_ENTRY || xdc_runtime_SysMin___L_EXIT
    xdc_runtime_SysMin_putch__E,
#elif defined(xdc_runtime_SysMin_putch__PATCH)
    xdc_runtime_SysMin_putch__PATCH,
#else
    xdc_runtime_SysMin_putch__R,
#endif
#if xdc_runtime_SysMin___L_ENTRY || xdc_runtime_SysMin___L_EXIT
    xdc_runtime_SysMin_ready__E,
#elif defined(xdc_runtime_SysMin_ready__PATCH)
    xdc_runtime_SysMin_ready__PATCH,
#else
    xdc_runtime_SysMin_ready__R,
#endif
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_SysMin___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_SysMin_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_SysMin_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_SysMin_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_SysMin_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_SysMin_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_SysMin_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_SysMin_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_SysMin_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_SysMin_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_SysMin_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_SysMin_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_SysMin_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_SysMin_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_SysMin_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_SysMin_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_SysMin___scope == -1
#ifdef xdc_runtime_SysMin_abort__PATCH
#define __FN__ xdc_runtime_SysMin_abort__PATCH
#else
#define __FN__ xdc_runtime_SysMin_abort__R
#endif
#else
#define __FN__ xdc_runtime_SysMin_abort__F
#endif
xdc_Void xdc_runtime_SysMin_abort__E( xdc_String str ) {
#if xdc_runtime_SysMin___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_SysMin_abort__ENTRY_EVT, (xdc_IArg)str);
#endif
#if xdc_runtime_SysMin___L_EXIT
    __FN__(str);
    xdc_runtime_Log_write1(xdc_runtime_SysMin_abort__EXIT_EVT, 0);
#else
    __FN__(str);
#endif
}
#undef __FN__
#if xdc_runtime_SysMin___scope == -1
#ifdef xdc_runtime_SysMin_exit__PATCH
#define __FN__ xdc_runtime_SysMin_exit__PATCH
#else
#define __FN__ xdc_runtime_SysMin_exit__R
#endif
#else
#define __FN__ xdc_runtime_SysMin_exit__F
#endif
xdc_Void xdc_runtime_SysMin_exit__E( xdc_Int stat ) {
#if xdc_runtime_SysMin___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_SysMin_exit__ENTRY_EVT, (xdc_IArg)stat);
#endif
#if xdc_runtime_SysMin___L_EXIT
    __FN__(stat);
    xdc_runtime_Log_write1(xdc_runtime_SysMin_exit__EXIT_EVT, 0);
#else
    __FN__(stat);
#endif
}
#undef __FN__
#if xdc_runtime_SysMin___scope == -1
#ifdef xdc_runtime_SysMin_flush__PATCH
#define __FN__ xdc_runtime_SysMin_flush__PATCH
#else
#define __FN__ xdc_runtime_SysMin_flush__R
#endif
#else
#define __FN__ xdc_runtime_SysMin_flush__F
#endif
xdc_Void xdc_runtime_SysMin_flush__E( void ) {
#if xdc_runtime_SysMin___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_SysMin_flush__ENTRY_EVT);
#endif
#if xdc_runtime_SysMin___L_EXIT
    __FN__();
    xdc_runtime_Log_write1(xdc_runtime_SysMin_flush__EXIT_EVT, 0);
#else
    __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_SysMin___scope == -1
#ifdef xdc_runtime_SysMin_putch__PATCH
#define __FN__ xdc_runtime_SysMin_putch__PATCH
#else
#define __FN__ xdc_runtime_SysMin_putch__R
#endif
#else
#define __FN__ xdc_runtime_SysMin_putch__F
#endif
xdc_Void xdc_runtime_SysMin_putch__E( xdc_Char ch ) {
#if xdc_runtime_SysMin___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_SysMin_putch__ENTRY_EVT, (xdc_IArg)ch);
#endif
#if xdc_runtime_SysMin___L_EXIT
    __FN__(ch);
    xdc_runtime_Log_write1(xdc_runtime_SysMin_putch__EXIT_EVT, 0);
#else
    __FN__(ch);
#endif
}
#undef __FN__
#if xdc_runtime_SysMin___scope == -1
#ifdef xdc_runtime_SysMin_ready__PATCH
#define __FN__ xdc_runtime_SysMin_ready__PATCH
#else
#define __FN__ xdc_runtime_SysMin_ready__R
#endif
#else
#define __FN__ xdc_runtime_SysMin_ready__F
#endif
xdc_Bool xdc_runtime_SysMin_ready__E( void ) {
#if xdc_runtime_SysMin___L_EXIT
    xdc_Bool __ret;
#else
#endif
#if xdc_runtime_SysMin___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_SysMin_ready__ENTRY_EVT);
#endif
#if xdc_runtime_SysMin___L_EXIT
    __ret = __FN__();
    xdc_runtime_Log_write1(xdc_runtime_SysMin_ready__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__();
#endif
}
#endif /* xdc_runtime_SysMin___ROMPATCH */
#ifdef xdc_runtime_SysMin___ROMPATCH
xdc_Void xdc_runtime_SysMin_abort__E( xdc_String str ) {
    xdc_runtime_SysMin_Module__MTAB__C.abort(str);
}
xdc_Void xdc_runtime_SysMin_exit__E( xdc_Int stat ) {
    xdc_runtime_SysMin_Module__MTAB__C.exit(stat);
}
xdc_Void xdc_runtime_SysMin_flush__E( void ) {
    xdc_runtime_SysMin_Module__MTAB__C.flush();
}
xdc_Void xdc_runtime_SysMin_putch__E( xdc_Char ch ) {
    xdc_runtime_SysMin_Module__MTAB__C.putch(ch);
}
xdc_Bool xdc_runtime_SysMin_ready__E( void ) {
    return xdc_runtime_SysMin_Module__MTAB__C.ready();
}
#endif /* xdc_runtime_SysMin___ROMPATCH */
xdc_Void xdc_runtime_SysMin_abort__R( xdc_String str ) {
    xdc_runtime_SysMin_abort__F(str);
}
xdc_Void xdc_runtime_SysMin_exit__R( xdc_Int stat ) {
    xdc_runtime_SysMin_exit__F(stat);
}
xdc_Void xdc_runtime_SysMin_flush__R( void ) {
    xdc_runtime_SysMin_flush__F();
}
xdc_Void xdc_runtime_SysMin_putch__R( xdc_Char ch ) {
    xdc_runtime_SysMin_putch__F(ch);
}
xdc_Bool xdc_runtime_SysMin_ready__R( void ) {
    return xdc_runtime_SysMin_ready__F();
}

#if defined(xdc_runtime_SysMin___EXPORT) && defined(__ti__)
#if xdc_runtime_SysMin___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_SysMin_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_SysMin_abort__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_SysMin_exit__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_SysMin_flush__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_SysMin_putch__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_SysMin_ready__R);
#endif
#endif /* __isrom__ */

#if xdc_runtime_SysMin___scope != -1
xdc_Bool xdc_runtime_SysMin_Module__startupDone__S() {

    return 1;
}
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_Text___used
/*
 *  ======== module Text ========
 *  Do not modify this file; it is generated from the specification Text.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_Text__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Text.h>
#undef __nested__
#else
#include <xdc/runtime/Text.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Text___LOGOBJ) && xdc_runtime_Text___DGSINCL & 0x1
#define xdc_runtime_Text___L_ENTRY 1
#else
#define xdc_runtime_Text___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Text___LOGOBJ) && xdc_runtime_Text___DGSINCL & 0x2
#define xdc_runtime_Text___L_EXIT 1
#else
#define xdc_runtime_Text___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Text___LOGOBJ) && xdc_runtime_Text___DGSINCL & 0x4
#define xdc_runtime_Text___L_LIFECYCLE 1
#else
#define xdc_runtime_Text___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_Text_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Text_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Text_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Text_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Text_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Text_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Text_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Text_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Text_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Text_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Text_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Text_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Text_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Text_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Text_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_Text___scope == -1
#ifdef xdc_runtime_Text_cordText__PATCH
#define __FN__ xdc_runtime_Text_cordText__PATCH
#else
#define __FN__ xdc_runtime_Text_cordText__R
#endif
#else
#define __FN__ xdc_runtime_Text_cordText__F
#endif
xdc_String xdc_runtime_Text_cordText__E( xdc_runtime_Text_CordAddr cord ) {
#if xdc_runtime_Text___L_EXIT
    xdc_String __ret;
#else
#endif
#if xdc_runtime_Text___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Text_cordText__ENTRY_EVT, (xdc_IArg)cord);
#endif
#if xdc_runtime_Text___L_EXIT
    __ret = __FN__(cord);
    xdc_runtime_Log_write1(xdc_runtime_Text_cordText__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(cord);
#endif
}
#undef __FN__
#if xdc_runtime_Text___scope == -1
#ifdef xdc_runtime_Text_ropeText__PATCH
#define __FN__ xdc_runtime_Text_ropeText__PATCH
#else
#define __FN__ xdc_runtime_Text_ropeText__R
#endif
#else
#define __FN__ xdc_runtime_Text_ropeText__F
#endif
xdc_String xdc_runtime_Text_ropeText__E( xdc_runtime_Text_RopeId rope ) {
#if xdc_runtime_Text___L_EXIT
    xdc_String __ret;
#else
#endif
#if xdc_runtime_Text___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Text_ropeText__ENTRY_EVT, (xdc_IArg)rope);
#endif
#if xdc_runtime_Text___L_EXIT
    __ret = __FN__(rope);
    xdc_runtime_Log_write1(xdc_runtime_Text_ropeText__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(rope);
#endif
}
#undef __FN__
#if xdc_runtime_Text___scope == -1
#ifdef xdc_runtime_Text_matchRope__PATCH
#define __FN__ xdc_runtime_Text_matchRope__PATCH
#else
#define __FN__ xdc_runtime_Text_matchRope__R
#endif
#else
#define __FN__ xdc_runtime_Text_matchRope__F
#endif
xdc_Int xdc_runtime_Text_matchRope__E( xdc_runtime_Text_RopeId rope, xdc_String pat, xdc_Int* lenp ) {
#if xdc_runtime_Text___L_EXIT
    xdc_Int __ret;
#else
#endif
#if xdc_runtime_Text___L_ENTRY
    xdc_runtime_Log_write3(xdc_runtime_Text_matchRope__ENTRY_EVT, (xdc_IArg)rope, (xdc_IArg)pat, (xdc_IArg)lenp);
#endif
#if xdc_runtime_Text___L_EXIT
    __ret = __FN__(rope, pat, lenp);
    xdc_runtime_Log_write1(xdc_runtime_Text_matchRope__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(rope, pat, lenp);
#endif
}

#if defined(xdc_runtime_Text___EXPORT) && defined(__ti__)
#if xdc_runtime_Text___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Text_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_Text_cordText__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_Text_ropeText__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_Text_matchRope__E);
#endif
__FAR__ xdc_runtime_Text_Module__MTAB__C__qual xdc_runtime_Text_MTab__ xdc_runtime_Text_Module__MTAB__C = {
#if xdc_runtime_Text___scope == -1
#if xdc_runtime_Text___L_ENTRY || xdc_runtime_Text___L_EXIT
    xdc_runtime_Text_cordText__E,
#elif defined(xdc_runtime_Text_cordText__PATCH)
    xdc_runtime_Text_cordText__PATCH,
#else
    xdc_runtime_Text_cordText__R,
#endif
#if xdc_runtime_Text___L_ENTRY || xdc_runtime_Text___L_EXIT
    xdc_runtime_Text_ropeText__E,
#elif defined(xdc_runtime_Text_ropeText__PATCH)
    xdc_runtime_Text_ropeText__PATCH,
#else
    xdc_runtime_Text_ropeText__R,
#endif
#if xdc_runtime_Text___L_ENTRY || xdc_runtime_Text___L_EXIT
    xdc_runtime_Text_matchRope__E,
#elif defined(xdc_runtime_Text_matchRope__PATCH)
    xdc_runtime_Text_matchRope__PATCH,
#else
    xdc_runtime_Text_matchRope__R,
#endif
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_Text___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_Text_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Text_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Text_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Text_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Text_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Text_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Text_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Text_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Text_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Text_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Text_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Text_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Text_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Text_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Text_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_Text___scope == -1
#ifdef xdc_runtime_Text_cordText__PATCH
#define __FN__ xdc_runtime_Text_cordText__PATCH
#else
#define __FN__ xdc_runtime_Text_cordText__R
#endif
#else
#define __FN__ xdc_runtime_Text_cordText__F
#endif
xdc_String xdc_runtime_Text_cordText__E( xdc_runtime_Text_CordAddr cord ) {
#if xdc_runtime_Text___L_EXIT
    xdc_String __ret;
#else
#endif
#if xdc_runtime_Text___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Text_cordText__ENTRY_EVT, (xdc_IArg)cord);
#endif
#if xdc_runtime_Text___L_EXIT
    __ret = __FN__(cord);
    xdc_runtime_Log_write1(xdc_runtime_Text_cordText__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(cord);
#endif
}
#undef __FN__
#if xdc_runtime_Text___scope == -1
#ifdef xdc_runtime_Text_ropeText__PATCH
#define __FN__ xdc_runtime_Text_ropeText__PATCH
#else
#define __FN__ xdc_runtime_Text_ropeText__R
#endif
#else
#define __FN__ xdc_runtime_Text_ropeText__F
#endif
xdc_String xdc_runtime_Text_ropeText__E( xdc_runtime_Text_RopeId rope ) {
#if xdc_runtime_Text___L_EXIT
    xdc_String __ret;
#else
#endif
#if xdc_runtime_Text___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Text_ropeText__ENTRY_EVT, (xdc_IArg)rope);
#endif
#if xdc_runtime_Text___L_EXIT
    __ret = __FN__(rope);
    xdc_runtime_Log_write1(xdc_runtime_Text_ropeText__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(rope);
#endif
}
#undef __FN__
#if xdc_runtime_Text___scope == -1
#ifdef xdc_runtime_Text_matchRope__PATCH
#define __FN__ xdc_runtime_Text_matchRope__PATCH
#else
#define __FN__ xdc_runtime_Text_matchRope__R
#endif
#else
#define __FN__ xdc_runtime_Text_matchRope__F
#endif
xdc_Int xdc_runtime_Text_matchRope__E( xdc_runtime_Text_RopeId rope, xdc_String pat, xdc_Int* lenp ) {
#if xdc_runtime_Text___L_EXIT
    xdc_Int __ret;
#else
#endif
#if xdc_runtime_Text___L_ENTRY
    xdc_runtime_Log_write3(xdc_runtime_Text_matchRope__ENTRY_EVT, (xdc_IArg)rope, (xdc_IArg)pat, (xdc_IArg)lenp);
#endif
#if xdc_runtime_Text___L_EXIT
    __ret = __FN__(rope, pat, lenp);
    xdc_runtime_Log_write1(xdc_runtime_Text_matchRope__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__(rope, pat, lenp);
#endif
}
#endif /* xdc_runtime_Text___ROMPATCH */
#ifdef xdc_runtime_Text___ROMPATCH
xdc_String xdc_runtime_Text_cordText__E( xdc_runtime_Text_CordAddr cord ) {
    return xdc_runtime_Text_Module__MTAB__C.cordText(cord);
}
xdc_String xdc_runtime_Text_ropeText__E( xdc_runtime_Text_RopeId rope ) {
    return xdc_runtime_Text_Module__MTAB__C.ropeText(rope);
}
xdc_Int xdc_runtime_Text_matchRope__E( xdc_runtime_Text_RopeId rope, xdc_String pat, xdc_Int* lenp ) {
    return xdc_runtime_Text_Module__MTAB__C.matchRope(rope, pat, lenp);
}
#endif /* xdc_runtime_Text___ROMPATCH */
xdc_String xdc_runtime_Text_cordText__R( xdc_runtime_Text_CordAddr cord ) {
    return xdc_runtime_Text_cordText__F(cord);
}
xdc_String xdc_runtime_Text_ropeText__R( xdc_runtime_Text_RopeId rope ) {
    return xdc_runtime_Text_ropeText__F(rope);
}
xdc_Int xdc_runtime_Text_matchRope__R( xdc_runtime_Text_RopeId rope, xdc_String pat, xdc_Int* lenp ) {
    return xdc_runtime_Text_matchRope__F(rope, pat, lenp);
}

#if defined(xdc_runtime_Text___EXPORT) && defined(__ti__)
#if xdc_runtime_Text___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Text_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_Text_cordText__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_Text_ropeText__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_Text_matchRope__R);
#endif
#endif /* __isrom__ */

#if xdc_runtime_Text___scope != -1
xdc_Bool xdc_runtime_Text_Module__startupDone__S() {

    return 1;
}
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_Timestamp___used
/*
 *  ======== module Timestamp ========
 *  Do not modify this file; it is generated from the specification Timestamp.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_Timestamp__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Timestamp.h>
#undef __nested__
#else
#include <xdc/runtime/Timestamp.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Timestamp___LOGOBJ) && xdc_runtime_Timestamp___DGSINCL & 0x1
#define xdc_runtime_Timestamp___L_ENTRY 1
#else
#define xdc_runtime_Timestamp___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Timestamp___LOGOBJ) && xdc_runtime_Timestamp___DGSINCL & 0x2
#define xdc_runtime_Timestamp___L_EXIT 1
#else
#define xdc_runtime_Timestamp___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Timestamp___LOGOBJ) && xdc_runtime_Timestamp___DGSINCL & 0x4
#define xdc_runtime_Timestamp___L_LIFECYCLE 1
#else
#define xdc_runtime_Timestamp___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_Timestamp_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Timestamp_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Timestamp_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Timestamp_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Timestamp_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Timestamp_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Timestamp_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Timestamp_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Timestamp_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Timestamp_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Timestamp_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Timestamp_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Timestamp_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Timestamp_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Timestamp_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_Timestamp___scope == -1
#ifdef xdc_runtime_Timestamp_get32__PATCH
#define __FN__ xdc_runtime_Timestamp_get32__PATCH
#else
#define __FN__ xdc_runtime_Timestamp_get32__R
#endif
#else
#define __FN__ xdc_runtime_Timestamp_get32__F
#endif
xdc_Bits32 xdc_runtime_Timestamp_get32__E( void ) {
#if xdc_runtime_Timestamp___L_EXIT
    xdc_Bits32 __ret;
#else
#endif
#if xdc_runtime_Timestamp___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_Timestamp_get32__ENTRY_EVT);
#endif
#if xdc_runtime_Timestamp___L_EXIT
    __ret = __FN__();
    xdc_runtime_Log_write1(xdc_runtime_Timestamp_get32__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_Timestamp___scope == -1
#ifdef xdc_runtime_Timestamp_get64__PATCH
#define __FN__ xdc_runtime_Timestamp_get64__PATCH
#else
#define __FN__ xdc_runtime_Timestamp_get64__R
#endif
#else
#define __FN__ xdc_runtime_Timestamp_get64__F
#endif
xdc_Void xdc_runtime_Timestamp_get64__E( xdc_runtime_Types_Timestamp64* result ) {
#if xdc_runtime_Timestamp___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Timestamp_get64__ENTRY_EVT, (xdc_IArg)result);
#endif
#if xdc_runtime_Timestamp___L_EXIT
    __FN__(result);
    xdc_runtime_Log_write1(xdc_runtime_Timestamp_get64__EXIT_EVT, 0);
#else
    __FN__(result);
#endif
}
#undef __FN__
#if xdc_runtime_Timestamp___scope == -1
#ifdef xdc_runtime_Timestamp_getFreq__PATCH
#define __FN__ xdc_runtime_Timestamp_getFreq__PATCH
#else
#define __FN__ xdc_runtime_Timestamp_getFreq__R
#endif
#else
#define __FN__ xdc_runtime_Timestamp_getFreq__F
#endif
xdc_Void xdc_runtime_Timestamp_getFreq__E( xdc_runtime_Types_FreqHz* freq ) {
#if xdc_runtime_Timestamp___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Timestamp_getFreq__ENTRY_EVT, (xdc_IArg)freq);
#endif
#if xdc_runtime_Timestamp___L_EXIT
    __FN__(freq);
    xdc_runtime_Log_write1(xdc_runtime_Timestamp_getFreq__EXIT_EVT, 0);
#else
    __FN__(freq);
#endif
}

#if defined(xdc_runtime_Timestamp___EXPORT) && defined(__ti__)
#if xdc_runtime_Timestamp___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Timestamp_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_Timestamp_get32__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_Timestamp_get64__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_Timestamp_getFreq__E);
#endif
#ifdef xdc_runtime_Timestamp___FXNTAB
#if xdc_runtime_Timestamp___scope == -1 || !defined(__xdc_runtime_IModule_Interface__BASE__CR)
#ifndef __xdc_runtime_IModule_Interface__BASE__C
#define __xdc_runtime_IModule_Interface__BASE__C
__FAR__ xdc_runtime_IModule_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_IModule_Interface__BASE__C = {0};
#endif
#endif
#if xdc_runtime_Timestamp___scope == -1 || !defined(__xdc_runtime_ITimestampClient_Interface__BASE__CR)
#ifndef __xdc_runtime_ITimestampClient_Interface__BASE__C
#define __xdc_runtime_ITimestampClient_Interface__BASE__C
__FAR__ xdc_runtime_ITimestampClient_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_ITimestampClient_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};
#endif
#endif

__FAR__ xdc_runtime_Timestamp_Module__FXNS__C__qual xdc_runtime_Timestamp_Fxns__ xdc_runtime_Timestamp_Module__FXNS__C = {
    /* base__ */ (void*)&xdc_runtime_ITimestampClient_Interface__BASE__C,
    &xdc_runtime_Timestamp_Module__FXNS__C.__sfxns, /* __sysp */
    xdc_runtime_Timestamp_get32__E,
    xdc_runtime_Timestamp_get64__E,
    xdc_runtime_Timestamp_getFreq__E,
    {

        /* create__ */ 0,
        /* delete__ */ 0,
        /* label__ */ 0,
        xdc_runtime_Timestamp_Module__id__D,
    } /* __sfxns */
};
#endif
__FAR__ xdc_runtime_Timestamp_Module__MTAB__C__qual xdc_runtime_Timestamp_MTab__ xdc_runtime_Timestamp_Module__MTAB__C = {
#if xdc_runtime_Timestamp___scope == -1
#if xdc_runtime_Timestamp___L_ENTRY || xdc_runtime_Timestamp___L_EXIT
    xdc_runtime_Timestamp_get32__E,
#elif defined(xdc_runtime_Timestamp_get32__PATCH)
    xdc_runtime_Timestamp_get32__PATCH,
#else
    xdc_runtime_Timestamp_get32__R,
#endif
#if xdc_runtime_Timestamp___L_ENTRY || xdc_runtime_Timestamp___L_EXIT
    xdc_runtime_Timestamp_get64__E,
#elif defined(xdc_runtime_Timestamp_get64__PATCH)
    xdc_runtime_Timestamp_get64__PATCH,
#else
    xdc_runtime_Timestamp_get64__R,
#endif
#if xdc_runtime_Timestamp___L_ENTRY || xdc_runtime_Timestamp___L_EXIT
    xdc_runtime_Timestamp_getFreq__E,
#elif defined(xdc_runtime_Timestamp_getFreq__PATCH)
    xdc_runtime_Timestamp_getFreq__PATCH,
#else
    xdc_runtime_Timestamp_getFreq__R,
#endif
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_Timestamp___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_Timestamp_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Timestamp_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Timestamp_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Timestamp_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Timestamp_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Timestamp_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Timestamp_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Timestamp_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Timestamp_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Timestamp_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Timestamp_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Timestamp_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Timestamp_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Timestamp_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Timestamp_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_Timestamp___scope == -1
#ifdef xdc_runtime_Timestamp_get32__PATCH
#define __FN__ xdc_runtime_Timestamp_get32__PATCH
#else
#define __FN__ xdc_runtime_Timestamp_get32__R
#endif
#else
#define __FN__ xdc_runtime_Timestamp_get32__F
#endif
xdc_Bits32 xdc_runtime_Timestamp_get32__E( void ) {
#if xdc_runtime_Timestamp___L_EXIT
    xdc_Bits32 __ret;
#else
#endif
#if xdc_runtime_Timestamp___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_Timestamp_get32__ENTRY_EVT);
#endif
#if xdc_runtime_Timestamp___L_EXIT
    __ret = __FN__();
    xdc_runtime_Log_write1(xdc_runtime_Timestamp_get32__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_Timestamp___scope == -1
#ifdef xdc_runtime_Timestamp_get64__PATCH
#define __FN__ xdc_runtime_Timestamp_get64__PATCH
#else
#define __FN__ xdc_runtime_Timestamp_get64__R
#endif
#else
#define __FN__ xdc_runtime_Timestamp_get64__F
#endif
xdc_Void xdc_runtime_Timestamp_get64__E( xdc_runtime_Types_Timestamp64* result ) {
#if xdc_runtime_Timestamp___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Timestamp_get64__ENTRY_EVT, (xdc_IArg)result);
#endif
#if xdc_runtime_Timestamp___L_EXIT
    __FN__(result);
    xdc_runtime_Log_write1(xdc_runtime_Timestamp_get64__EXIT_EVT, 0);
#else
    __FN__(result);
#endif
}
#undef __FN__
#if xdc_runtime_Timestamp___scope == -1
#ifdef xdc_runtime_Timestamp_getFreq__PATCH
#define __FN__ xdc_runtime_Timestamp_getFreq__PATCH
#else
#define __FN__ xdc_runtime_Timestamp_getFreq__R
#endif
#else
#define __FN__ xdc_runtime_Timestamp_getFreq__F
#endif
xdc_Void xdc_runtime_Timestamp_getFreq__E( xdc_runtime_Types_FreqHz* freq ) {
#if xdc_runtime_Timestamp___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_Timestamp_getFreq__ENTRY_EVT, (xdc_IArg)freq);
#endif
#if xdc_runtime_Timestamp___L_EXIT
    __FN__(freq);
    xdc_runtime_Log_write1(xdc_runtime_Timestamp_getFreq__EXIT_EVT, 0);
#else
    __FN__(freq);
#endif
}
#endif /* xdc_runtime_Timestamp___ROMPATCH */
#ifdef xdc_runtime_Timestamp___ROMPATCH
xdc_Bits32 xdc_runtime_Timestamp_get32__E( void ) {
    return xdc_runtime_Timestamp_Module__MTAB__C.get32();
}
xdc_Void xdc_runtime_Timestamp_get64__E( xdc_runtime_Types_Timestamp64* result ) {
    xdc_runtime_Timestamp_Module__MTAB__C.get64(result);
}
xdc_Void xdc_runtime_Timestamp_getFreq__E( xdc_runtime_Types_FreqHz* freq ) {
    xdc_runtime_Timestamp_Module__MTAB__C.getFreq(freq);
}
#endif /* xdc_runtime_Timestamp___ROMPATCH */
xdc_Bits32 xdc_runtime_Timestamp_get32__R( void ) {
    return xdc_runtime_Timestamp_get32__F();
}
xdc_Void xdc_runtime_Timestamp_get64__R( xdc_runtime_Types_Timestamp64* result ) {
    xdc_runtime_Timestamp_get64__F(result);
}
xdc_Void xdc_runtime_Timestamp_getFreq__R( xdc_runtime_Types_FreqHz* freq ) {
    xdc_runtime_Timestamp_getFreq__F(freq);
}

#if defined(xdc_runtime_Timestamp___EXPORT) && defined(__ti__)
#if xdc_runtime_Timestamp___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Timestamp_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_Timestamp_get32__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_Timestamp_get64__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_Timestamp_getFreq__R);
#endif
#endif /* __isrom__ */

#if xdc_runtime_Timestamp___scope != -1
xdc_Bool xdc_runtime_Timestamp_Module__startupDone__S() {

    return 1;
}
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_TimestampNull___used
/*
 *  ======== module TimestampNull ========
 *  Do not modify this file; it is generated from the specification TimestampNull.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_TimestampNull__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/TimestampNull.h>
#undef __nested__
#else
#include <xdc/runtime/TimestampNull.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_TimestampNull___LOGOBJ) && xdc_runtime_TimestampNull___DGSINCL & 0x1
#define xdc_runtime_TimestampNull___L_ENTRY 1
#else
#define xdc_runtime_TimestampNull___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_TimestampNull___LOGOBJ) && xdc_runtime_TimestampNull___DGSINCL & 0x2
#define xdc_runtime_TimestampNull___L_EXIT 1
#else
#define xdc_runtime_TimestampNull___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_TimestampNull___LOGOBJ) && xdc_runtime_TimestampNull___DGSINCL & 0x4
#define xdc_runtime_TimestampNull___L_LIFECYCLE 1
#else
#define xdc_runtime_TimestampNull___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_TimestampNull_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_TimestampNull_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_TimestampNull_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_TimestampNull_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_TimestampNull_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_TimestampNull_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_TimestampNull_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_TimestampNull_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_TimestampNull_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_TimestampNull_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_TimestampNull_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_TimestampNull_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_TimestampNull_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_TimestampNull_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_TimestampNull_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_TimestampNull___scope == -1
#ifdef xdc_runtime_TimestampNull_get32__PATCH
#define __FN__ xdc_runtime_TimestampNull_get32__PATCH
#else
#define __FN__ xdc_runtime_TimestampNull_get32__R
#endif
#else
#define __FN__ xdc_runtime_TimestampNull_get32__F
#endif
xdc_Bits32 xdc_runtime_TimestampNull_get32__E( void ) {
#if xdc_runtime_TimestampNull___L_EXIT
    xdc_Bits32 __ret;
#else
#endif
#if xdc_runtime_TimestampNull___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_TimestampNull_get32__ENTRY_EVT);
#endif
#if xdc_runtime_TimestampNull___L_EXIT
    __ret = __FN__();
    xdc_runtime_Log_write1(xdc_runtime_TimestampNull_get32__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_TimestampNull___scope == -1
#ifdef xdc_runtime_TimestampNull_get64__PATCH
#define __FN__ xdc_runtime_TimestampNull_get64__PATCH
#else
#define __FN__ xdc_runtime_TimestampNull_get64__R
#endif
#else
#define __FN__ xdc_runtime_TimestampNull_get64__F
#endif
xdc_Void xdc_runtime_TimestampNull_get64__E( xdc_runtime_Types_Timestamp64* result ) {
#if xdc_runtime_TimestampNull___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_TimestampNull_get64__ENTRY_EVT, (xdc_IArg)result);
#endif
#if xdc_runtime_TimestampNull___L_EXIT
    __FN__(result);
    xdc_runtime_Log_write1(xdc_runtime_TimestampNull_get64__EXIT_EVT, 0);
#else
    __FN__(result);
#endif
}
#undef __FN__
#if xdc_runtime_TimestampNull___scope == -1
#ifdef xdc_runtime_TimestampNull_getFreq__PATCH
#define __FN__ xdc_runtime_TimestampNull_getFreq__PATCH
#else
#define __FN__ xdc_runtime_TimestampNull_getFreq__R
#endif
#else
#define __FN__ xdc_runtime_TimestampNull_getFreq__F
#endif
xdc_Void xdc_runtime_TimestampNull_getFreq__E( xdc_runtime_Types_FreqHz* freq ) {
#if xdc_runtime_TimestampNull___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_TimestampNull_getFreq__ENTRY_EVT, (xdc_IArg)freq);
#endif
#if xdc_runtime_TimestampNull___L_EXIT
    __FN__(freq);
    xdc_runtime_Log_write1(xdc_runtime_TimestampNull_getFreq__EXIT_EVT, 0);
#else
    __FN__(freq);
#endif
}

#if defined(xdc_runtime_TimestampNull___EXPORT) && defined(__ti__)
#if xdc_runtime_TimestampNull___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_TimestampNull_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_TimestampNull_get32__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_TimestampNull_get64__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_TimestampNull_getFreq__E);
#endif
#ifdef xdc_runtime_TimestampNull___FXNTAB
#if xdc_runtime_TimestampNull___scope == -1 || !defined(__xdc_runtime_IModule_Interface__BASE__CR)
#ifndef __xdc_runtime_IModule_Interface__BASE__C
#define __xdc_runtime_IModule_Interface__BASE__C
__FAR__ xdc_runtime_IModule_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_IModule_Interface__BASE__C = {0};
#endif
#endif
#if xdc_runtime_TimestampNull___scope == -1 || !defined(__xdc_runtime_ITimestampClient_Interface__BASE__CR)
#ifndef __xdc_runtime_ITimestampClient_Interface__BASE__C
#define __xdc_runtime_ITimestampClient_Interface__BASE__C
__FAR__ xdc_runtime_ITimestampClient_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_ITimestampClient_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};
#endif
#endif
#if xdc_runtime_TimestampNull___scope == -1 || !defined(__xdc_runtime_ITimestampProvider_Interface__BASE__CR)
#ifndef __xdc_runtime_ITimestampProvider_Interface__BASE__C
#define __xdc_runtime_ITimestampProvider_Interface__BASE__C
__FAR__ xdc_runtime_ITimestampProvider_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_ITimestampProvider_Interface__BASE__C = {(void*)&xdc_runtime_ITimestampClient_Interface__BASE__C};
#endif
#endif

__FAR__ xdc_runtime_TimestampNull_Module__FXNS__C__qual xdc_runtime_TimestampNull_Fxns__ xdc_runtime_TimestampNull_Module__FXNS__C = {
    /* base__ */ (void*)&xdc_runtime_ITimestampProvider_Interface__BASE__C,
    &xdc_runtime_TimestampNull_Module__FXNS__C.__sfxns, /* __sysp */
    xdc_runtime_TimestampNull_get32__E,
    xdc_runtime_TimestampNull_get64__E,
    xdc_runtime_TimestampNull_getFreq__E,
    {

        /* create__ */ 0,
        /* delete__ */ 0,
        /* label__ */ 0,
        xdc_runtime_TimestampNull_Module__id__D,
    } /* __sfxns */
};
#endif
__FAR__ xdc_runtime_TimestampNull_Module__MTAB__C__qual xdc_runtime_TimestampNull_MTab__ xdc_runtime_TimestampNull_Module__MTAB__C = {
#if xdc_runtime_TimestampNull___scope == -1
#if xdc_runtime_TimestampNull___L_ENTRY || xdc_runtime_TimestampNull___L_EXIT
    xdc_runtime_TimestampNull_get32__E,
#elif defined(xdc_runtime_TimestampNull_get32__PATCH)
    xdc_runtime_TimestampNull_get32__PATCH,
#else
    xdc_runtime_TimestampNull_get32__R,
#endif
#if xdc_runtime_TimestampNull___L_ENTRY || xdc_runtime_TimestampNull___L_EXIT
    xdc_runtime_TimestampNull_get64__E,
#elif defined(xdc_runtime_TimestampNull_get64__PATCH)
    xdc_runtime_TimestampNull_get64__PATCH,
#else
    xdc_runtime_TimestampNull_get64__R,
#endif
#if xdc_runtime_TimestampNull___L_ENTRY || xdc_runtime_TimestampNull___L_EXIT
    xdc_runtime_TimestampNull_getFreq__E,
#elif defined(xdc_runtime_TimestampNull_getFreq__PATCH)
    xdc_runtime_TimestampNull_getFreq__PATCH,
#else
    xdc_runtime_TimestampNull_getFreq__R,
#endif
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_TimestampNull___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_TimestampNull_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_TimestampNull_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_TimestampNull_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_TimestampNull_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_TimestampNull_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_TimestampNull_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_TimestampNull_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_TimestampNull_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_TimestampNull_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_TimestampNull_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_TimestampNull_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_TimestampNull_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_TimestampNull_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_TimestampNull_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_TimestampNull_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_TimestampNull___scope == -1
#ifdef xdc_runtime_TimestampNull_get32__PATCH
#define __FN__ xdc_runtime_TimestampNull_get32__PATCH
#else
#define __FN__ xdc_runtime_TimestampNull_get32__R
#endif
#else
#define __FN__ xdc_runtime_TimestampNull_get32__F
#endif
xdc_Bits32 xdc_runtime_TimestampNull_get32__E( void ) {
#if xdc_runtime_TimestampNull___L_EXIT
    xdc_Bits32 __ret;
#else
#endif
#if xdc_runtime_TimestampNull___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_TimestampNull_get32__ENTRY_EVT);
#endif
#if xdc_runtime_TimestampNull___L_EXIT
    __ret = __FN__();
    xdc_runtime_Log_write1(xdc_runtime_TimestampNull_get32__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_TimestampNull___scope == -1
#ifdef xdc_runtime_TimestampNull_get64__PATCH
#define __FN__ xdc_runtime_TimestampNull_get64__PATCH
#else
#define __FN__ xdc_runtime_TimestampNull_get64__R
#endif
#else
#define __FN__ xdc_runtime_TimestampNull_get64__F
#endif
xdc_Void xdc_runtime_TimestampNull_get64__E( xdc_runtime_Types_Timestamp64* result ) {
#if xdc_runtime_TimestampNull___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_TimestampNull_get64__ENTRY_EVT, (xdc_IArg)result);
#endif
#if xdc_runtime_TimestampNull___L_EXIT
    __FN__(result);
    xdc_runtime_Log_write1(xdc_runtime_TimestampNull_get64__EXIT_EVT, 0);
#else
    __FN__(result);
#endif
}
#undef __FN__
#if xdc_runtime_TimestampNull___scope == -1
#ifdef xdc_runtime_TimestampNull_getFreq__PATCH
#define __FN__ xdc_runtime_TimestampNull_getFreq__PATCH
#else
#define __FN__ xdc_runtime_TimestampNull_getFreq__R
#endif
#else
#define __FN__ xdc_runtime_TimestampNull_getFreq__F
#endif
xdc_Void xdc_runtime_TimestampNull_getFreq__E( xdc_runtime_Types_FreqHz* freq ) {
#if xdc_runtime_TimestampNull___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_TimestampNull_getFreq__ENTRY_EVT, (xdc_IArg)freq);
#endif
#if xdc_runtime_TimestampNull___L_EXIT
    __FN__(freq);
    xdc_runtime_Log_write1(xdc_runtime_TimestampNull_getFreq__EXIT_EVT, 0);
#else
    __FN__(freq);
#endif
}
#endif /* xdc_runtime_TimestampNull___ROMPATCH */
#ifdef xdc_runtime_TimestampNull___ROMPATCH
xdc_Bits32 xdc_runtime_TimestampNull_get32__E( void ) {
    return xdc_runtime_TimestampNull_Module__MTAB__C.get32();
}
xdc_Void xdc_runtime_TimestampNull_get64__E( xdc_runtime_Types_Timestamp64* result ) {
    xdc_runtime_TimestampNull_Module__MTAB__C.get64(result);
}
xdc_Void xdc_runtime_TimestampNull_getFreq__E( xdc_runtime_Types_FreqHz* freq ) {
    xdc_runtime_TimestampNull_Module__MTAB__C.getFreq(freq);
}
#endif /* xdc_runtime_TimestampNull___ROMPATCH */
xdc_Bits32 xdc_runtime_TimestampNull_get32__R( void ) {
    return xdc_runtime_TimestampNull_get32__F();
}
xdc_Void xdc_runtime_TimestampNull_get64__R( xdc_runtime_Types_Timestamp64* result ) {
    xdc_runtime_TimestampNull_get64__F(result);
}
xdc_Void xdc_runtime_TimestampNull_getFreq__R( xdc_runtime_Types_FreqHz* freq ) {
    xdc_runtime_TimestampNull_getFreq__F(freq);
}

#if defined(xdc_runtime_TimestampNull___EXPORT) && defined(__ti__)
#if xdc_runtime_TimestampNull___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_TimestampNull_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_TimestampNull_get32__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_TimestampNull_get64__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_TimestampNull_getFreq__R);
#endif
#endif /* __isrom__ */

#if xdc_runtime_TimestampNull___scope != -1
xdc_Bool xdc_runtime_TimestampNull_Module__startupDone__S() {

    return 1;
}
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_TimestampStd___used
/*
 *  ======== module TimestampStd ========
 *  Do not modify this file; it is generated from the specification TimestampStd.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_TimestampStd__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/TimestampStd.h>
#undef __nested__
#else
#include <xdc/runtime/TimestampStd.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_TimestampStd___LOGOBJ) && xdc_runtime_TimestampStd___DGSINCL & 0x1
#define xdc_runtime_TimestampStd___L_ENTRY 1
#else
#define xdc_runtime_TimestampStd___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_TimestampStd___LOGOBJ) && xdc_runtime_TimestampStd___DGSINCL & 0x2
#define xdc_runtime_TimestampStd___L_EXIT 1
#else
#define xdc_runtime_TimestampStd___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_TimestampStd___LOGOBJ) && xdc_runtime_TimestampStd___DGSINCL & 0x4
#define xdc_runtime_TimestampStd___L_LIFECYCLE 1
#else
#define xdc_runtime_TimestampStd___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_TimestampStd_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_TimestampStd_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_TimestampStd_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_TimestampStd_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_TimestampStd_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_TimestampStd_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_TimestampStd_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_TimestampStd_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_TimestampStd_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_TimestampStd_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_TimestampStd_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_TimestampStd_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_TimestampStd_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_TimestampStd_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_TimestampStd_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_TimestampStd___scope == -1
#ifdef xdc_runtime_TimestampStd_get32__PATCH
#define __FN__ xdc_runtime_TimestampStd_get32__PATCH
#else
#define __FN__ xdc_runtime_TimestampStd_get32__R
#endif
#else
#define __FN__ xdc_runtime_TimestampStd_get32__F
#endif
xdc_Bits32 xdc_runtime_TimestampStd_get32__E( void ) {
#if xdc_runtime_TimestampStd___L_EXIT
    xdc_Bits32 __ret;
#else
#endif
#if xdc_runtime_TimestampStd___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_TimestampStd_get32__ENTRY_EVT);
#endif
#if xdc_runtime_TimestampStd___L_EXIT
    __ret = __FN__();
    xdc_runtime_Log_write1(xdc_runtime_TimestampStd_get32__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_TimestampStd___scope == -1
#ifdef xdc_runtime_TimestampStd_get64__PATCH
#define __FN__ xdc_runtime_TimestampStd_get64__PATCH
#else
#define __FN__ xdc_runtime_TimestampStd_get64__R
#endif
#else
#define __FN__ xdc_runtime_TimestampStd_get64__F
#endif
xdc_Void xdc_runtime_TimestampStd_get64__E( xdc_runtime_Types_Timestamp64* result ) {
#if xdc_runtime_TimestampStd___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_TimestampStd_get64__ENTRY_EVT, (xdc_IArg)result);
#endif
#if xdc_runtime_TimestampStd___L_EXIT
    __FN__(result);
    xdc_runtime_Log_write1(xdc_runtime_TimestampStd_get64__EXIT_EVT, 0);
#else
    __FN__(result);
#endif
}
#undef __FN__
#if xdc_runtime_TimestampStd___scope == -1
#ifdef xdc_runtime_TimestampStd_getFreq__PATCH
#define __FN__ xdc_runtime_TimestampStd_getFreq__PATCH
#else
#define __FN__ xdc_runtime_TimestampStd_getFreq__R
#endif
#else
#define __FN__ xdc_runtime_TimestampStd_getFreq__F
#endif
xdc_Void xdc_runtime_TimestampStd_getFreq__E( xdc_runtime_Types_FreqHz* freq ) {
#if xdc_runtime_TimestampStd___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_TimestampStd_getFreq__ENTRY_EVT, (xdc_IArg)freq);
#endif
#if xdc_runtime_TimestampStd___L_EXIT
    __FN__(freq);
    xdc_runtime_Log_write1(xdc_runtime_TimestampStd_getFreq__EXIT_EVT, 0);
#else
    __FN__(freq);
#endif
}

#if defined(xdc_runtime_TimestampStd___EXPORT) && defined(__ti__)
#if xdc_runtime_TimestampStd___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_TimestampStd_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_TimestampStd_get32__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_TimestampStd_get64__E);
#pragma FUNC_EXT_CALLED(xdc_runtime_TimestampStd_getFreq__E);
#endif
#ifdef xdc_runtime_TimestampStd___FXNTAB
#if xdc_runtime_TimestampStd___scope == -1 || !defined(__xdc_runtime_IModule_Interface__BASE__CR)
#ifndef __xdc_runtime_IModule_Interface__BASE__C
#define __xdc_runtime_IModule_Interface__BASE__C
__FAR__ xdc_runtime_IModule_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_IModule_Interface__BASE__C = {0};
#endif
#endif
#if xdc_runtime_TimestampStd___scope == -1 || !defined(__xdc_runtime_ITimestampClient_Interface__BASE__CR)
#ifndef __xdc_runtime_ITimestampClient_Interface__BASE__C
#define __xdc_runtime_ITimestampClient_Interface__BASE__C
__FAR__ xdc_runtime_ITimestampClient_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_ITimestampClient_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};
#endif
#endif
#if xdc_runtime_TimestampStd___scope == -1 || !defined(__xdc_runtime_ITimestampProvider_Interface__BASE__CR)
#ifndef __xdc_runtime_ITimestampProvider_Interface__BASE__C
#define __xdc_runtime_ITimestampProvider_Interface__BASE__C
__FAR__ xdc_runtime_ITimestampProvider_Interface__BASE__C__qual xdc_runtime_Types_Base xdc_runtime_ITimestampProvider_Interface__BASE__C = {(void*)&xdc_runtime_ITimestampClient_Interface__BASE__C};
#endif
#endif

__FAR__ xdc_runtime_TimestampStd_Module__FXNS__C__qual xdc_runtime_TimestampStd_Fxns__ xdc_runtime_TimestampStd_Module__FXNS__C = {
    /* base__ */ (void*)&xdc_runtime_ITimestampProvider_Interface__BASE__C,
    &xdc_runtime_TimestampStd_Module__FXNS__C.__sfxns, /* __sysp */
    xdc_runtime_TimestampStd_get32__E,
    xdc_runtime_TimestampStd_get64__E,
    xdc_runtime_TimestampStd_getFreq__E,
    {

        /* create__ */ 0,
        /* delete__ */ 0,
        /* label__ */ 0,
        xdc_runtime_TimestampStd_Module__id__D,
    } /* __sfxns */
};
#endif
__FAR__ xdc_runtime_TimestampStd_Module__MTAB__C__qual xdc_runtime_TimestampStd_MTab__ xdc_runtime_TimestampStd_Module__MTAB__C = {
#if xdc_runtime_TimestampStd___scope == -1
#if xdc_runtime_TimestampStd___L_ENTRY || xdc_runtime_TimestampStd___L_EXIT
    xdc_runtime_TimestampStd_get32__E,
#elif defined(xdc_runtime_TimestampStd_get32__PATCH)
    xdc_runtime_TimestampStd_get32__PATCH,
#else
    xdc_runtime_TimestampStd_get32__R,
#endif
#if xdc_runtime_TimestampStd___L_ENTRY || xdc_runtime_TimestampStd___L_EXIT
    xdc_runtime_TimestampStd_get64__E,
#elif defined(xdc_runtime_TimestampStd_get64__PATCH)
    xdc_runtime_TimestampStd_get64__PATCH,
#else
    xdc_runtime_TimestampStd_get64__R,
#endif
#if xdc_runtime_TimestampStd___L_ENTRY || xdc_runtime_TimestampStd___L_EXIT
    xdc_runtime_TimestampStd_getFreq__E,
#elif defined(xdc_runtime_TimestampStd_getFreq__PATCH)
    xdc_runtime_TimestampStd_getFreq__PATCH,
#else
    xdc_runtime_TimestampStd_getFreq__R,
#endif
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_TimestampStd___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_TimestampStd_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_TimestampStd_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_TimestampStd_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_TimestampStd_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_TimestampStd_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_TimestampStd_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_TimestampStd_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_TimestampStd_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_TimestampStd_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_TimestampStd_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_TimestampStd_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_TimestampStd_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_TimestampStd_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_TimestampStd_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_TimestampStd_Module_GateProxy_query
#undef __FN__
#if xdc_runtime_TimestampStd___scope == -1
#ifdef xdc_runtime_TimestampStd_get32__PATCH
#define __FN__ xdc_runtime_TimestampStd_get32__PATCH
#else
#define __FN__ xdc_runtime_TimestampStd_get32__R
#endif
#else
#define __FN__ xdc_runtime_TimestampStd_get32__F
#endif
xdc_Bits32 xdc_runtime_TimestampStd_get32__E( void ) {
#if xdc_runtime_TimestampStd___L_EXIT
    xdc_Bits32 __ret;
#else
#endif
#if xdc_runtime_TimestampStd___L_ENTRY
    xdc_runtime_Log_write0(xdc_runtime_TimestampStd_get32__ENTRY_EVT);
#endif
#if xdc_runtime_TimestampStd___L_EXIT
    __ret = __FN__();
    xdc_runtime_Log_write1(xdc_runtime_TimestampStd_get32__EXIT_EVT, (xdc_IArg)__ret);
    return __ret;
#else
    return __FN__();
#endif
}
#undef __FN__
#if xdc_runtime_TimestampStd___scope == -1
#ifdef xdc_runtime_TimestampStd_get64__PATCH
#define __FN__ xdc_runtime_TimestampStd_get64__PATCH
#else
#define __FN__ xdc_runtime_TimestampStd_get64__R
#endif
#else
#define __FN__ xdc_runtime_TimestampStd_get64__F
#endif
xdc_Void xdc_runtime_TimestampStd_get64__E( xdc_runtime_Types_Timestamp64* result ) {
#if xdc_runtime_TimestampStd___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_TimestampStd_get64__ENTRY_EVT, (xdc_IArg)result);
#endif
#if xdc_runtime_TimestampStd___L_EXIT
    __FN__(result);
    xdc_runtime_Log_write1(xdc_runtime_TimestampStd_get64__EXIT_EVT, 0);
#else
    __FN__(result);
#endif
}
#undef __FN__
#if xdc_runtime_TimestampStd___scope == -1
#ifdef xdc_runtime_TimestampStd_getFreq__PATCH
#define __FN__ xdc_runtime_TimestampStd_getFreq__PATCH
#else
#define __FN__ xdc_runtime_TimestampStd_getFreq__R
#endif
#else
#define __FN__ xdc_runtime_TimestampStd_getFreq__F
#endif
xdc_Void xdc_runtime_TimestampStd_getFreq__E( xdc_runtime_Types_FreqHz* freq ) {
#if xdc_runtime_TimestampStd___L_ENTRY
    xdc_runtime_Log_write1(xdc_runtime_TimestampStd_getFreq__ENTRY_EVT, (xdc_IArg)freq);
#endif
#if xdc_runtime_TimestampStd___L_EXIT
    __FN__(freq);
    xdc_runtime_Log_write1(xdc_runtime_TimestampStd_getFreq__EXIT_EVT, 0);
#else
    __FN__(freq);
#endif
}
#endif /* xdc_runtime_TimestampStd___ROMPATCH */
#ifdef xdc_runtime_TimestampStd___ROMPATCH
xdc_Bits32 xdc_runtime_TimestampStd_get32__E( void ) {
    return xdc_runtime_TimestampStd_Module__MTAB__C.get32();
}
xdc_Void xdc_runtime_TimestampStd_get64__E( xdc_runtime_Types_Timestamp64* result ) {
    xdc_runtime_TimestampStd_Module__MTAB__C.get64(result);
}
xdc_Void xdc_runtime_TimestampStd_getFreq__E( xdc_runtime_Types_FreqHz* freq ) {
    xdc_runtime_TimestampStd_Module__MTAB__C.getFreq(freq);
}
#endif /* xdc_runtime_TimestampStd___ROMPATCH */
xdc_Bits32 xdc_runtime_TimestampStd_get32__R( void ) {
    return xdc_runtime_TimestampStd_get32__F();
}
xdc_Void xdc_runtime_TimestampStd_get64__R( xdc_runtime_Types_Timestamp64* result ) {
    xdc_runtime_TimestampStd_get64__F(result);
}
xdc_Void xdc_runtime_TimestampStd_getFreq__R( xdc_runtime_Types_FreqHz* freq ) {
    xdc_runtime_TimestampStd_getFreq__F(freq);
}

#if defined(xdc_runtime_TimestampStd___EXPORT) && defined(__ti__)
#if xdc_runtime_TimestampStd___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_TimestampStd_Module__startupDone__S);
#endif
#pragma FUNC_EXT_CALLED(xdc_runtime_TimestampStd_get32__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_TimestampStd_get64__R);
#pragma FUNC_EXT_CALLED(xdc_runtime_TimestampStd_getFreq__R);
#endif
#endif /* __isrom__ */

#if xdc_runtime_TimestampStd___scope != -1
xdc_Bool xdc_runtime_TimestampStd_Module__startupDone__S() {

    return 1;
}
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_Types___used
/*
 *  ======== module Types ========
 *  Do not modify this file; it is generated from the specification Types.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_Types__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Types.h>
#undef __nested__
#else
#include <xdc/runtime/Types.h>
#endif
#endif

#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Types___LOGOBJ) && xdc_runtime_Types___DGSINCL & 0x1
#define xdc_runtime_Types___L_ENTRY 1
#else
#define xdc_runtime_Types___L_ENTRY 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Types___LOGOBJ) && xdc_runtime_Types___DGSINCL & 0x2
#define xdc_runtime_Types___L_EXIT 1
#else
#define xdc_runtime_Types___L_EXIT 0
#endif
#if defined(xdc_runtime_Log__include) && defined(xdc_runtime_Types___LOGOBJ) && xdc_runtime_Types___DGSINCL & 0x4
#define xdc_runtime_Types___L_LIFECYCLE 1
#else
#define xdc_runtime_Types___L_LIFECYCLE 0
#endif
#ifndef __isrom__

#undef Module__MID
#define Module__MID xdc_runtime_Types_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Types_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Types_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Types_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Types_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Types_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Types_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Types_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Types_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Types_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Types_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Types_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Types_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Types_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Types_Module_GateProxy_query

#if defined(xdc_runtime_Types___EXPORT) && defined(__ti__)
#if xdc_runtime_Types___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Types_Module__startupDone__S);
#endif
#endif
__FAR__ xdc_runtime_Types_Module__MTAB__C__qual xdc_runtime_Types_MTab__ xdc_runtime_Types_Module__MTAB__C = {
#if xdc_runtime_Types___scope == -1
#endif
0
};

#else /* __isrom__ */

#ifndef xdc_runtime_Types___ROMPATCH
#undef Module__MID
#define Module__MID xdc_runtime_Types_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Types_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Types_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Types_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Types_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Types_Module__loggerObj__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Types_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Types_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Types_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Types_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Types_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Types_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Types_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Types_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Types_Module_GateProxy_query
#endif /* xdc_runtime_Types___ROMPATCH */
#ifdef xdc_runtime_Types___ROMPATCH
#endif /* xdc_runtime_Types___ROMPATCH */

#if defined(xdc_runtime_Types___EXPORT) && defined(__ti__)
#if xdc_runtime_Types___scope != -1
#pragma FUNC_EXT_CALLED(xdc_runtime_Types_Module__startupDone__S);
#endif
#endif
#endif /* __isrom__ */

#if xdc_runtime_Types___scope != -1
xdc_Bool xdc_runtime_Types_Module__startupDone__S() {

    return 1;
}
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_Gate_Module_GateProxy___used
/*
 *  ======== module Gate_Module_GateProxy ========
 *  Do not modify this file; it is generated from the specification Gate_Module_GateProxy.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_Gate_Module_GateProxy__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Gate_Module_GateProxy.h>
#undef __nested__
#else
#include <xdc/runtime/Gate_Module_GateProxy.h>
#endif
#endif

#ifndef __isrom__


#if defined(xdc_runtime_Gate_Module_GateProxy___DELEGATE)&& xdc_runtime_Gate_Module_GateProxy___scope != -1
#define xdc_runtime_Gate_Module_GateProxy___PROXYFXNS(__PRE)\
xdc_Bool xdc_runtime_Gate_Module_GateProxy_Module__startupDone__S() {\
    return __CONC__(__PRE,Module__startupDone__S)(); }\
xdc_Ptr xdc_runtime_Gate_Module_GateProxy_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __sz, xdc_runtime_Error_Block* __eb ) {\
    return __CONC__(__PRE,Object__create__S)(__oa, __osz, __aa, (xdc_Ptr)__pa, sizeof(xdc_runtime_IGateProvider_Params), __eb); }\
void xdc_runtime_Gate_Module_GateProxy_Object__delete__S( Ptr instp ) {\
    __CONC__(__PRE,Object__delete__S)(instp); }\
void xdc_runtime_Gate_Module_GateProxy_Params__init__S( xdc_Ptr dst, const xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) {\
    __CONC__(__PRE,Params__init__S)(dst, src, psz, isz); }\
xdc_runtime_Types_Label* xdc_runtime_Gate_Module_GateProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab ) {\
    return __CONC__(__PRE,Handle__label__S)(obj, lab); }\
xdc_Bool xdc_runtime_Gate_Module_GateProxy_query__E( xdc_Int qual ) {\
    return __CONC__(__PRE,query)(qual); }\
xdc_IArg xdc_runtime_Gate_Module_GateProxy_enter__E_D( xdc_runtime_Gate_Module_GateProxy_Handle _this ) {\
    return __CONC__(__PRE,enter)((__CONC__(__PRE,Handle))_this); }\
xdc_Void xdc_runtime_Gate_Module_GateProxy_leave__E_D( xdc_runtime_Gate_Module_GateProxy_Handle _this, xdc_IArg key ) {\
    __CONC__(__PRE,leave)((__CONC__(__PRE,Handle))_this, key); }\

xdc_runtime_Gate_Module_GateProxy___PROXYFXNS(xdc_runtime_Gate_Module_GateProxy___DELEGATE)
xdc_IArg xdc_runtime_Gate_Module_GateProxy_enter__E_D( xdc_runtime_Gate_Module_GateProxy_Handle _this );
xdc_IArg xdc_runtime_Gate_Module_GateProxy_enter__E( xdc_runtime_Gate_Module_GateProxy_Handle _this ) {
#ifdef xdc_runtime_Gate_Module_GateProxy___ABSTRACT
    return xdc_runtime_IGateProvider_enter((xdc_runtime_IGateProvider_Handle)_this); }
#else
    return xdc_runtime_Gate_Module_GateProxy_enter__E_D(_this); }
#endif
xdc_Void xdc_runtime_Gate_Module_GateProxy_leave__E_D( xdc_runtime_Gate_Module_GateProxy_Handle _this, xdc_IArg key );
xdc_Void xdc_runtime_Gate_Module_GateProxy_leave__E( xdc_runtime_Gate_Module_GateProxy_Handle _this, xdc_IArg key ) {
#ifdef xdc_runtime_Gate_Module_GateProxy___ABSTRACT
    xdc_runtime_IGateProvider_leave((xdc_runtime_IGateProvider_Handle)_this, key); }
#else
    xdc_runtime_Gate_Module_GateProxy_leave__E_D(_this, key); }
#endif
#endif


#else /* __isrom__ */


#if defined(xdc_runtime_Gate_Module_GateProxy___DELEGATE)
#define xdc_runtime_Gate_Module_GateProxy___PROXYFXNS(__PRE)\
xdc_Bool xdc_runtime_Gate_Module_GateProxy_Module__startupDone__S() {\
    return __CONC__(__PRE,Module__startupDone__S)(); }\
xdc_Ptr xdc_runtime_Gate_Module_GateProxy_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __sz, xdc_runtime_Error_Block* __eb ) {\
    return __CONC__(__PRE,Object__create__S)(__oa, __osz, __aa, (xdc_Ptr)__pa, sizeof(xdc_runtime_IGateProvider_Params), __eb); }\
void xdc_runtime_Gate_Module_GateProxy_Object__delete__S( Ptr instp ) {\
    __CONC__(__PRE,Object__delete__S)(instp); }\
void xdc_runtime_Gate_Module_GateProxy_Params__init__S( xdc_Ptr dst, const xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) {\
    __CONC__(__PRE,Params__init__S)(dst, src, psz, isz); }\
xdc_runtime_Types_Label* xdc_runtime_Gate_Module_GateProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab ) {\
    return __CONC__(__PRE,Handle__label__S)(obj, lab); }\
xdc_Bool xdc_runtime_Gate_Module_GateProxy_query__E( xdc_Int qual ) {\
    return __CONC__(__PRE,query)(qual); }\
xdc_IArg xdc_runtime_Gate_Module_GateProxy_enter__E_D( xdc_runtime_Gate_Module_GateProxy_Handle _this ) {\
    return __CONC__(__PRE,enter)((__CONC__(__PRE,Handle))_this); }\
xdc_Void xdc_runtime_Gate_Module_GateProxy_leave__E_D( xdc_runtime_Gate_Module_GateProxy_Handle _this, xdc_IArg key ) {\
    __CONC__(__PRE,leave)((__CONC__(__PRE,Handle))_this, key); }\

xdc_runtime_Gate_Module_GateProxy___PROXYFXNS(xdc_runtime_Gate_Module_GateProxy___DELEGATE)
xdc_IArg xdc_runtime_Gate_Module_GateProxy_enter__E_D( xdc_runtime_Gate_Module_GateProxy_Handle _this );
xdc_IArg xdc_runtime_Gate_Module_GateProxy_enter__E( xdc_runtime_Gate_Module_GateProxy_Handle _this ) {
#ifdef xdc_runtime_Gate_Module_GateProxy___ABSTRACT
    return xdc_runtime_IGateProvider_enter((xdc_runtime_IGateProvider_Handle)_this); }
#else
    return xdc_runtime_Gate_Module_GateProxy_enter__E_D(_this); }
#endif
xdc_Void xdc_runtime_Gate_Module_GateProxy_leave__E_D( xdc_runtime_Gate_Module_GateProxy_Handle _this, xdc_IArg key );
xdc_Void xdc_runtime_Gate_Module_GateProxy_leave__E( xdc_runtime_Gate_Module_GateProxy_Handle _this, xdc_IArg key ) {
#ifdef xdc_runtime_Gate_Module_GateProxy___ABSTRACT
    xdc_runtime_IGateProvider_leave((xdc_runtime_IGateProvider_Handle)_this, key); }
#else
    xdc_runtime_Gate_Module_GateProxy_leave__E_D(_this, key); }
#endif
#endif

#endif /* __isrom__ */

#if xdc_runtime_Gate_Module_GateProxy___scope != -1
xdc_Bool xdc_runtime_Gate_Module_GateProxy_Proxy__abstract__S()
#ifdef xdc_runtime_Gate_Module_GateProxy___ABSTRACT
    { return 1; }
#else
    { return 0; }
#endif
xdc_Ptr xdc_runtime_Gate_Module_GateProxy_Proxy__delegate__S() { return (xdc_Ptr)xdc_runtime_Gate_Module_GateProxy___DELEGATE_FXNS; }
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_LoggerBuf_Module_GateProxy___used
/*
 *  ======== module LoggerBuf_Module_GateProxy ========
 *  Do not modify this file; it is generated from the specification LoggerBuf_Module_GateProxy.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_LoggerBuf_Module_GateProxy__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/LoggerBuf_Module_GateProxy.h>
#undef __nested__
#else
#include <xdc/runtime/LoggerBuf_Module_GateProxy.h>
#endif
#endif

#ifndef __isrom__


#if defined(xdc_runtime_LoggerBuf_Module_GateProxy___DELEGATE)&& xdc_runtime_LoggerBuf_Module_GateProxy___scope != -1
#define xdc_runtime_LoggerBuf_Module_GateProxy___PROXYFXNS(__PRE)\
xdc_Bool xdc_runtime_LoggerBuf_Module_GateProxy_Module__startupDone__S() {\
    return __CONC__(__PRE,Module__startupDone__S)(); }\
xdc_Ptr xdc_runtime_LoggerBuf_Module_GateProxy_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __sz, xdc_runtime_Error_Block* __eb ) {\
    return __CONC__(__PRE,Object__create__S)(__oa, __osz, __aa, (xdc_Ptr)__pa, sizeof(xdc_runtime_IGateProvider_Params), __eb); }\
void xdc_runtime_LoggerBuf_Module_GateProxy_Object__delete__S( Ptr instp ) {\
    __CONC__(__PRE,Object__delete__S)(instp); }\
void xdc_runtime_LoggerBuf_Module_GateProxy_Params__init__S( xdc_Ptr dst, const xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) {\
    __CONC__(__PRE,Params__init__S)(dst, src, psz, isz); }\
xdc_runtime_Types_Label* xdc_runtime_LoggerBuf_Module_GateProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab ) {\
    return __CONC__(__PRE,Handle__label__S)(obj, lab); }\
xdc_Bool xdc_runtime_LoggerBuf_Module_GateProxy_query__E( xdc_Int qual ) {\
    return __CONC__(__PRE,query)(qual); }\
xdc_IArg xdc_runtime_LoggerBuf_Module_GateProxy_enter__E_D( xdc_runtime_LoggerBuf_Module_GateProxy_Handle _this ) {\
    return __CONC__(__PRE,enter)((__CONC__(__PRE,Handle))_this); }\
xdc_Void xdc_runtime_LoggerBuf_Module_GateProxy_leave__E_D( xdc_runtime_LoggerBuf_Module_GateProxy_Handle _this, xdc_IArg key ) {\
    __CONC__(__PRE,leave)((__CONC__(__PRE,Handle))_this, key); }\

xdc_runtime_LoggerBuf_Module_GateProxy___PROXYFXNS(xdc_runtime_LoggerBuf_Module_GateProxy___DELEGATE)
xdc_IArg xdc_runtime_LoggerBuf_Module_GateProxy_enter__E_D( xdc_runtime_LoggerBuf_Module_GateProxy_Handle _this );
xdc_IArg xdc_runtime_LoggerBuf_Module_GateProxy_enter__E( xdc_runtime_LoggerBuf_Module_GateProxy_Handle _this ) {
#ifdef xdc_runtime_LoggerBuf_Module_GateProxy___ABSTRACT
    return xdc_runtime_IGateProvider_enter((xdc_runtime_IGateProvider_Handle)_this); }
#else
    return xdc_runtime_LoggerBuf_Module_GateProxy_enter__E_D(_this); }
#endif
xdc_Void xdc_runtime_LoggerBuf_Module_GateProxy_leave__E_D( xdc_runtime_LoggerBuf_Module_GateProxy_Handle _this, xdc_IArg key );
xdc_Void xdc_runtime_LoggerBuf_Module_GateProxy_leave__E( xdc_runtime_LoggerBuf_Module_GateProxy_Handle _this, xdc_IArg key ) {
#ifdef xdc_runtime_LoggerBuf_Module_GateProxy___ABSTRACT
    xdc_runtime_IGateProvider_leave((xdc_runtime_IGateProvider_Handle)_this, key); }
#else
    xdc_runtime_LoggerBuf_Module_GateProxy_leave__E_D(_this, key); }
#endif
#endif


#else /* __isrom__ */


#if defined(xdc_runtime_LoggerBuf_Module_GateProxy___DELEGATE)
#define xdc_runtime_LoggerBuf_Module_GateProxy___PROXYFXNS(__PRE)\
xdc_Bool xdc_runtime_LoggerBuf_Module_GateProxy_Module__startupDone__S() {\
    return __CONC__(__PRE,Module__startupDone__S)(); }\
xdc_Ptr xdc_runtime_LoggerBuf_Module_GateProxy_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __sz, xdc_runtime_Error_Block* __eb ) {\
    return __CONC__(__PRE,Object__create__S)(__oa, __osz, __aa, (xdc_Ptr)__pa, sizeof(xdc_runtime_IGateProvider_Params), __eb); }\
void xdc_runtime_LoggerBuf_Module_GateProxy_Object__delete__S( Ptr instp ) {\
    __CONC__(__PRE,Object__delete__S)(instp); }\
void xdc_runtime_LoggerBuf_Module_GateProxy_Params__init__S( xdc_Ptr dst, const xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) {\
    __CONC__(__PRE,Params__init__S)(dst, src, psz, isz); }\
xdc_runtime_Types_Label* xdc_runtime_LoggerBuf_Module_GateProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab ) {\
    return __CONC__(__PRE,Handle__label__S)(obj, lab); }\
xdc_Bool xdc_runtime_LoggerBuf_Module_GateProxy_query__E( xdc_Int qual ) {\
    return __CONC__(__PRE,query)(qual); }\
xdc_IArg xdc_runtime_LoggerBuf_Module_GateProxy_enter__E_D( xdc_runtime_LoggerBuf_Module_GateProxy_Handle _this ) {\
    return __CONC__(__PRE,enter)((__CONC__(__PRE,Handle))_this); }\
xdc_Void xdc_runtime_LoggerBuf_Module_GateProxy_leave__E_D( xdc_runtime_LoggerBuf_Module_GateProxy_Handle _this, xdc_IArg key ) {\
    __CONC__(__PRE,leave)((__CONC__(__PRE,Handle))_this, key); }\

xdc_runtime_LoggerBuf_Module_GateProxy___PROXYFXNS(xdc_runtime_LoggerBuf_Module_GateProxy___DELEGATE)
xdc_IArg xdc_runtime_LoggerBuf_Module_GateProxy_enter__E_D( xdc_runtime_LoggerBuf_Module_GateProxy_Handle _this );
xdc_IArg xdc_runtime_LoggerBuf_Module_GateProxy_enter__E( xdc_runtime_LoggerBuf_Module_GateProxy_Handle _this ) {
#ifdef xdc_runtime_LoggerBuf_Module_GateProxy___ABSTRACT
    return xdc_runtime_IGateProvider_enter((xdc_runtime_IGateProvider_Handle)_this); }
#else
    return xdc_runtime_LoggerBuf_Module_GateProxy_enter__E_D(_this); }
#endif
xdc_Void xdc_runtime_LoggerBuf_Module_GateProxy_leave__E_D( xdc_runtime_LoggerBuf_Module_GateProxy_Handle _this, xdc_IArg key );
xdc_Void xdc_runtime_LoggerBuf_Module_GateProxy_leave__E( xdc_runtime_LoggerBuf_Module_GateProxy_Handle _this, xdc_IArg key ) {
#ifdef xdc_runtime_LoggerBuf_Module_GateProxy___ABSTRACT
    xdc_runtime_IGateProvider_leave((xdc_runtime_IGateProvider_Handle)_this, key); }
#else
    xdc_runtime_LoggerBuf_Module_GateProxy_leave__E_D(_this, key); }
#endif
#endif

#endif /* __isrom__ */

#if xdc_runtime_LoggerBuf_Module_GateProxy___scope != -1
xdc_Bool xdc_runtime_LoggerBuf_Module_GateProxy_Proxy__abstract__S()
#ifdef xdc_runtime_LoggerBuf_Module_GateProxy___ABSTRACT
    { return 1; }
#else
    { return 0; }
#endif
xdc_Ptr xdc_runtime_LoggerBuf_Module_GateProxy_Proxy__delegate__S() { return (xdc_Ptr)xdc_runtime_LoggerBuf_Module_GateProxy___DELEGATE_FXNS; }
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_LoggerSys_TimestampProxy___used
/*
 *  ======== module LoggerSys_TimestampProxy ========
 *  Do not modify this file; it is generated from the specification LoggerSys_TimestampProxy.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_LoggerSys_TimestampProxy__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/LoggerSys_TimestampProxy.h>
#undef __nested__
#else
#include <xdc/runtime/LoggerSys_TimestampProxy.h>
#endif
#endif

#ifndef __isrom__


#if defined(xdc_runtime_LoggerSys_TimestampProxy___DELEGATE)&& xdc_runtime_LoggerSys_TimestampProxy___scope != -1
#define xdc_runtime_LoggerSys_TimestampProxy___PROXYFXNS(__PRE)\
xdc_Bool xdc_runtime_LoggerSys_TimestampProxy_Module__startupDone__S() {\
    return __CONC__(__PRE,Module__startupDone__S)(); }\
xdc_Bits32 xdc_runtime_LoggerSys_TimestampProxy_get32__E( void ) {\
    return __CONC__(__PRE,get32)(); }\
xdc_Void xdc_runtime_LoggerSys_TimestampProxy_get64__E( xdc_runtime_Types_Timestamp64* result ) {\
    __CONC__(__PRE,get64)(result); }\
xdc_Void xdc_runtime_LoggerSys_TimestampProxy_getFreq__E( xdc_runtime_Types_FreqHz* freq ) {\
    __CONC__(__PRE,getFreq)(freq); }\

xdc_runtime_LoggerSys_TimestampProxy___PROXYFXNS(xdc_runtime_LoggerSys_TimestampProxy___DELEGATE)
#endif


#else /* __isrom__ */


#if defined(xdc_runtime_LoggerSys_TimestampProxy___DELEGATE)
#define xdc_runtime_LoggerSys_TimestampProxy___PROXYFXNS(__PRE)\
xdc_Bool xdc_runtime_LoggerSys_TimestampProxy_Module__startupDone__S() {\
    return __CONC__(__PRE,Module__startupDone__S)(); }\
xdc_Bits32 xdc_runtime_LoggerSys_TimestampProxy_get32__E( void ) {\
    return __CONC__(__PRE,get32)(); }\
xdc_Void xdc_runtime_LoggerSys_TimestampProxy_get64__E( xdc_runtime_Types_Timestamp64* result ) {\
    __CONC__(__PRE,get64)(result); }\
xdc_Void xdc_runtime_LoggerSys_TimestampProxy_getFreq__E( xdc_runtime_Types_FreqHz* freq ) {\
    __CONC__(__PRE,getFreq)(freq); }\

xdc_runtime_LoggerSys_TimestampProxy___PROXYFXNS(xdc_runtime_LoggerSys_TimestampProxy___DELEGATE)
#endif

#endif /* __isrom__ */

#if xdc_runtime_LoggerSys_TimestampProxy___scope != -1
xdc_Bool xdc_runtime_LoggerSys_TimestampProxy_Proxy__abstract__S()
#ifdef xdc_runtime_LoggerSys_TimestampProxy___ABSTRACT
    { return 1; }
#else
    { return 0; }
#endif
xdc_Ptr xdc_runtime_LoggerSys_TimestampProxy_Proxy__delegate__S() { return (xdc_Ptr)xdc_runtime_LoggerSys_TimestampProxy___DELEGATE_FXNS; }
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_Main_Module_GateProxy___used
/*
 *  ======== module Main_Module_GateProxy ========
 *  Do not modify this file; it is generated from the specification Main_Module_GateProxy.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_Main_Module_GateProxy__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Main_Module_GateProxy.h>
#undef __nested__
#else
#include <xdc/runtime/Main_Module_GateProxy.h>
#endif
#endif

#ifndef __isrom__


#if defined(xdc_runtime_Main_Module_GateProxy___DELEGATE)&& xdc_runtime_Main_Module_GateProxy___scope != -1
#define xdc_runtime_Main_Module_GateProxy___PROXYFXNS(__PRE)\
xdc_Bool xdc_runtime_Main_Module_GateProxy_Module__startupDone__S() {\
    return __CONC__(__PRE,Module__startupDone__S)(); }\
xdc_Ptr xdc_runtime_Main_Module_GateProxy_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __sz, xdc_runtime_Error_Block* __eb ) {\
    return __CONC__(__PRE,Object__create__S)(__oa, __osz, __aa, (xdc_Ptr)__pa, sizeof(xdc_runtime_IGateProvider_Params), __eb); }\
void xdc_runtime_Main_Module_GateProxy_Object__delete__S( Ptr instp ) {\
    __CONC__(__PRE,Object__delete__S)(instp); }\
void xdc_runtime_Main_Module_GateProxy_Params__init__S( xdc_Ptr dst, const xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) {\
    __CONC__(__PRE,Params__init__S)(dst, src, psz, isz); }\
xdc_runtime_Types_Label* xdc_runtime_Main_Module_GateProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab ) {\
    return __CONC__(__PRE,Handle__label__S)(obj, lab); }\
xdc_Bool xdc_runtime_Main_Module_GateProxy_query__E( xdc_Int qual ) {\
    return __CONC__(__PRE,query)(qual); }\
xdc_IArg xdc_runtime_Main_Module_GateProxy_enter__E_D( xdc_runtime_Main_Module_GateProxy_Handle _this ) {\
    return __CONC__(__PRE,enter)((__CONC__(__PRE,Handle))_this); }\
xdc_Void xdc_runtime_Main_Module_GateProxy_leave__E_D( xdc_runtime_Main_Module_GateProxy_Handle _this, xdc_IArg key ) {\
    __CONC__(__PRE,leave)((__CONC__(__PRE,Handle))_this, key); }\

xdc_runtime_Main_Module_GateProxy___PROXYFXNS(xdc_runtime_Main_Module_GateProxy___DELEGATE)
xdc_IArg xdc_runtime_Main_Module_GateProxy_enter__E_D( xdc_runtime_Main_Module_GateProxy_Handle _this );
xdc_IArg xdc_runtime_Main_Module_GateProxy_enter__E( xdc_runtime_Main_Module_GateProxy_Handle _this ) {
#ifdef xdc_runtime_Main_Module_GateProxy___ABSTRACT
    return xdc_runtime_IGateProvider_enter((xdc_runtime_IGateProvider_Handle)_this); }
#else
    return xdc_runtime_Main_Module_GateProxy_enter__E_D(_this); }
#endif
xdc_Void xdc_runtime_Main_Module_GateProxy_leave__E_D( xdc_runtime_Main_Module_GateProxy_Handle _this, xdc_IArg key );
xdc_Void xdc_runtime_Main_Module_GateProxy_leave__E( xdc_runtime_Main_Module_GateProxy_Handle _this, xdc_IArg key ) {
#ifdef xdc_runtime_Main_Module_GateProxy___ABSTRACT
    xdc_runtime_IGateProvider_leave((xdc_runtime_IGateProvider_Handle)_this, key); }
#else
    xdc_runtime_Main_Module_GateProxy_leave__E_D(_this, key); }
#endif
#endif


#else /* __isrom__ */


#if defined(xdc_runtime_Main_Module_GateProxy___DELEGATE)
#define xdc_runtime_Main_Module_GateProxy___PROXYFXNS(__PRE)\
xdc_Bool xdc_runtime_Main_Module_GateProxy_Module__startupDone__S() {\
    return __CONC__(__PRE,Module__startupDone__S)(); }\
xdc_Ptr xdc_runtime_Main_Module_GateProxy_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __sz, xdc_runtime_Error_Block* __eb ) {\
    return __CONC__(__PRE,Object__create__S)(__oa, __osz, __aa, (xdc_Ptr)__pa, sizeof(xdc_runtime_IGateProvider_Params), __eb); }\
void xdc_runtime_Main_Module_GateProxy_Object__delete__S( Ptr instp ) {\
    __CONC__(__PRE,Object__delete__S)(instp); }\
void xdc_runtime_Main_Module_GateProxy_Params__init__S( xdc_Ptr dst, const xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) {\
    __CONC__(__PRE,Params__init__S)(dst, src, psz, isz); }\
xdc_runtime_Types_Label* xdc_runtime_Main_Module_GateProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab ) {\
    return __CONC__(__PRE,Handle__label__S)(obj, lab); }\
xdc_Bool xdc_runtime_Main_Module_GateProxy_query__E( xdc_Int qual ) {\
    return __CONC__(__PRE,query)(qual); }\
xdc_IArg xdc_runtime_Main_Module_GateProxy_enter__E_D( xdc_runtime_Main_Module_GateProxy_Handle _this ) {\
    return __CONC__(__PRE,enter)((__CONC__(__PRE,Handle))_this); }\
xdc_Void xdc_runtime_Main_Module_GateProxy_leave__E_D( xdc_runtime_Main_Module_GateProxy_Handle _this, xdc_IArg key ) {\
    __CONC__(__PRE,leave)((__CONC__(__PRE,Handle))_this, key); }\

xdc_runtime_Main_Module_GateProxy___PROXYFXNS(xdc_runtime_Main_Module_GateProxy___DELEGATE)
xdc_IArg xdc_runtime_Main_Module_GateProxy_enter__E_D( xdc_runtime_Main_Module_GateProxy_Handle _this );
xdc_IArg xdc_runtime_Main_Module_GateProxy_enter__E( xdc_runtime_Main_Module_GateProxy_Handle _this ) {
#ifdef xdc_runtime_Main_Module_GateProxy___ABSTRACT
    return xdc_runtime_IGateProvider_enter((xdc_runtime_IGateProvider_Handle)_this); }
#else
    return xdc_runtime_Main_Module_GateProxy_enter__E_D(_this); }
#endif
xdc_Void xdc_runtime_Main_Module_GateProxy_leave__E_D( xdc_runtime_Main_Module_GateProxy_Handle _this, xdc_IArg key );
xdc_Void xdc_runtime_Main_Module_GateProxy_leave__E( xdc_runtime_Main_Module_GateProxy_Handle _this, xdc_IArg key ) {
#ifdef xdc_runtime_Main_Module_GateProxy___ABSTRACT
    xdc_runtime_IGateProvider_leave((xdc_runtime_IGateProvider_Handle)_this, key); }
#else
    xdc_runtime_Main_Module_GateProxy_leave__E_D(_this, key); }
#endif
#endif

#endif /* __isrom__ */

#if xdc_runtime_Main_Module_GateProxy___scope != -1
xdc_Bool xdc_runtime_Main_Module_GateProxy_Proxy__abstract__S()
#ifdef xdc_runtime_Main_Module_GateProxy___ABSTRACT
    { return 1; }
#else
    { return 0; }
#endif
xdc_Ptr xdc_runtime_Main_Module_GateProxy_Proxy__delegate__S() { return (xdc_Ptr)xdc_runtime_Main_Module_GateProxy___DELEGATE_FXNS; }
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_Memory_HeapProxy___used
/*
 *  ======== module Memory_HeapProxy ========
 *  Do not modify this file; it is generated from the specification Memory_HeapProxy.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_Memory_HeapProxy__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory_HeapProxy.h>
#undef __nested__
#else
#include <xdc/runtime/Memory_HeapProxy.h>
#endif
#endif

#ifndef __isrom__


#if defined(xdc_runtime_Memory_HeapProxy___DELEGATE)&& xdc_runtime_Memory_HeapProxy___scope != -1
#define xdc_runtime_Memory_HeapProxy___PROXYFXNS(__PRE)\
xdc_Bool xdc_runtime_Memory_HeapProxy_Module__startupDone__S() {\
    return __CONC__(__PRE,Module__startupDone__S)(); }\
xdc_Ptr xdc_runtime_Memory_HeapProxy_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __sz, xdc_runtime_Error_Block* __eb ) {\
    return __CONC__(__PRE,Object__create__S)(__oa, __osz, __aa, (xdc_Ptr)__pa, sizeof(xdc_runtime_IHeap_Params), __eb); }\
void xdc_runtime_Memory_HeapProxy_Object__delete__S( Ptr instp ) {\
    __CONC__(__PRE,Object__delete__S)(instp); }\
void xdc_runtime_Memory_HeapProxy_Params__init__S( xdc_Ptr dst, const xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) {\
    __CONC__(__PRE,Params__init__S)(dst, src, psz, isz); }\
xdc_runtime_Types_Label* xdc_runtime_Memory_HeapProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab ) {\
    return __CONC__(__PRE,Handle__label__S)(obj, lab); }\
xdc_Ptr xdc_runtime_Memory_HeapProxy_alloc__E_D( xdc_runtime_Memory_HeapProxy_Handle _this, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {\
    return __CONC__(__PRE,alloc)((__CONC__(__PRE,Handle))_this, size, align, eb); }\
xdc_Void xdc_runtime_Memory_HeapProxy_free__E_D( xdc_runtime_Memory_HeapProxy_Handle _this, xdc_Ptr block, xdc_SizeT size ) {\
    __CONC__(__PRE,free)((__CONC__(__PRE,Handle))_this, block, size); }\
xdc_Bool xdc_runtime_Memory_HeapProxy_isBlocking__E_D( xdc_runtime_Memory_HeapProxy_Handle _this ) {\
    return __CONC__(__PRE,isBlocking)((__CONC__(__PRE,Handle))_this); }\
xdc_Void xdc_runtime_Memory_HeapProxy_getStats__E_D( xdc_runtime_Memory_HeapProxy_Handle _this, xdc_runtime_Memory_Stats* stats ) {\
    __CONC__(__PRE,getStats)((__CONC__(__PRE,Handle))_this, stats); }\

xdc_runtime_Memory_HeapProxy___PROXYFXNS(xdc_runtime_Memory_HeapProxy___DELEGATE)
xdc_Ptr xdc_runtime_Memory_HeapProxy_alloc__E_D( xdc_runtime_Memory_HeapProxy_Handle _this, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb );
xdc_Ptr xdc_runtime_Memory_HeapProxy_alloc__E( xdc_runtime_Memory_HeapProxy_Handle _this, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {
#ifdef xdc_runtime_Memory_HeapProxy___ABSTRACT
    return xdc_runtime_IHeap_alloc((xdc_runtime_IHeap_Handle)_this, size, align, eb); }
#else
    return xdc_runtime_Memory_HeapProxy_alloc__E_D(_this, size, align, eb); }
#endif
xdc_Void xdc_runtime_Memory_HeapProxy_free__E_D( xdc_runtime_Memory_HeapProxy_Handle _this, xdc_Ptr block, xdc_SizeT size );
xdc_Void xdc_runtime_Memory_HeapProxy_free__E( xdc_runtime_Memory_HeapProxy_Handle _this, xdc_Ptr block, xdc_SizeT size ) {
#ifdef xdc_runtime_Memory_HeapProxy___ABSTRACT
    xdc_runtime_IHeap_free((xdc_runtime_IHeap_Handle)_this, block, size); }
#else
    xdc_runtime_Memory_HeapProxy_free__E_D(_this, block, size); }
#endif
xdc_Bool xdc_runtime_Memory_HeapProxy_isBlocking__E_D( xdc_runtime_Memory_HeapProxy_Handle _this );
xdc_Bool xdc_runtime_Memory_HeapProxy_isBlocking__E( xdc_runtime_Memory_HeapProxy_Handle _this ) {
#ifdef xdc_runtime_Memory_HeapProxy___ABSTRACT
    return xdc_runtime_IHeap_isBlocking((xdc_runtime_IHeap_Handle)_this); }
#else
    return xdc_runtime_Memory_HeapProxy_isBlocking__E_D(_this); }
#endif
xdc_Void xdc_runtime_Memory_HeapProxy_getStats__E_D( xdc_runtime_Memory_HeapProxy_Handle _this, xdc_runtime_Memory_Stats* stats );
xdc_Void xdc_runtime_Memory_HeapProxy_getStats__E( xdc_runtime_Memory_HeapProxy_Handle _this, xdc_runtime_Memory_Stats* stats ) {
#ifdef xdc_runtime_Memory_HeapProxy___ABSTRACT
    xdc_runtime_IHeap_getStats((xdc_runtime_IHeap_Handle)_this, stats); }
#else
    xdc_runtime_Memory_HeapProxy_getStats__E_D(_this, stats); }
#endif
#endif


#else /* __isrom__ */


#if defined(xdc_runtime_Memory_HeapProxy___DELEGATE)
#define xdc_runtime_Memory_HeapProxy___PROXYFXNS(__PRE)\
xdc_Bool xdc_runtime_Memory_HeapProxy_Module__startupDone__S() {\
    return __CONC__(__PRE,Module__startupDone__S)(); }\
xdc_Ptr xdc_runtime_Memory_HeapProxy_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __sz, xdc_runtime_Error_Block* __eb ) {\
    return __CONC__(__PRE,Object__create__S)(__oa, __osz, __aa, (xdc_Ptr)__pa, sizeof(xdc_runtime_IHeap_Params), __eb); }\
void xdc_runtime_Memory_HeapProxy_Object__delete__S( Ptr instp ) {\
    __CONC__(__PRE,Object__delete__S)(instp); }\
void xdc_runtime_Memory_HeapProxy_Params__init__S( xdc_Ptr dst, const xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) {\
    __CONC__(__PRE,Params__init__S)(dst, src, psz, isz); }\
xdc_runtime_Types_Label* xdc_runtime_Memory_HeapProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab ) {\
    return __CONC__(__PRE,Handle__label__S)(obj, lab); }\
xdc_Ptr xdc_runtime_Memory_HeapProxy_alloc__E_D( xdc_runtime_Memory_HeapProxy_Handle _this, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {\
    return __CONC__(__PRE,alloc)((__CONC__(__PRE,Handle))_this, size, align, eb); }\
xdc_Void xdc_runtime_Memory_HeapProxy_free__E_D( xdc_runtime_Memory_HeapProxy_Handle _this, xdc_Ptr block, xdc_SizeT size ) {\
    __CONC__(__PRE,free)((__CONC__(__PRE,Handle))_this, block, size); }\
xdc_Bool xdc_runtime_Memory_HeapProxy_isBlocking__E_D( xdc_runtime_Memory_HeapProxy_Handle _this ) {\
    return __CONC__(__PRE,isBlocking)((__CONC__(__PRE,Handle))_this); }\
xdc_Void xdc_runtime_Memory_HeapProxy_getStats__E_D( xdc_runtime_Memory_HeapProxy_Handle _this, xdc_runtime_Memory_Stats* stats ) {\
    __CONC__(__PRE,getStats)((__CONC__(__PRE,Handle))_this, stats); }\

xdc_runtime_Memory_HeapProxy___PROXYFXNS(xdc_runtime_Memory_HeapProxy___DELEGATE)
xdc_Ptr xdc_runtime_Memory_HeapProxy_alloc__E_D( xdc_runtime_Memory_HeapProxy_Handle _this, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb );
xdc_Ptr xdc_runtime_Memory_HeapProxy_alloc__E( xdc_runtime_Memory_HeapProxy_Handle _this, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) {
#ifdef xdc_runtime_Memory_HeapProxy___ABSTRACT
    return xdc_runtime_IHeap_alloc((xdc_runtime_IHeap_Handle)_this, size, align, eb); }
#else
    return xdc_runtime_Memory_HeapProxy_alloc__E_D(_this, size, align, eb); }
#endif
xdc_Void xdc_runtime_Memory_HeapProxy_free__E_D( xdc_runtime_Memory_HeapProxy_Handle _this, xdc_Ptr block, xdc_SizeT size );
xdc_Void xdc_runtime_Memory_HeapProxy_free__E( xdc_runtime_Memory_HeapProxy_Handle _this, xdc_Ptr block, xdc_SizeT size ) {
#ifdef xdc_runtime_Memory_HeapProxy___ABSTRACT
    xdc_runtime_IHeap_free((xdc_runtime_IHeap_Handle)_this, block, size); }
#else
    xdc_runtime_Memory_HeapProxy_free__E_D(_this, block, size); }
#endif
xdc_Bool xdc_runtime_Memory_HeapProxy_isBlocking__E_D( xdc_runtime_Memory_HeapProxy_Handle _this );
xdc_Bool xdc_runtime_Memory_HeapProxy_isBlocking__E( xdc_runtime_Memory_HeapProxy_Handle _this ) {
#ifdef xdc_runtime_Memory_HeapProxy___ABSTRACT
    return xdc_runtime_IHeap_isBlocking((xdc_runtime_IHeap_Handle)_this); }
#else
    return xdc_runtime_Memory_HeapProxy_isBlocking__E_D(_this); }
#endif
xdc_Void xdc_runtime_Memory_HeapProxy_getStats__E_D( xdc_runtime_Memory_HeapProxy_Handle _this, xdc_runtime_Memory_Stats* stats );
xdc_Void xdc_runtime_Memory_HeapProxy_getStats__E( xdc_runtime_Memory_HeapProxy_Handle _this, xdc_runtime_Memory_Stats* stats ) {
#ifdef xdc_runtime_Memory_HeapProxy___ABSTRACT
    xdc_runtime_IHeap_getStats((xdc_runtime_IHeap_Handle)_this, stats); }
#else
    xdc_runtime_Memory_HeapProxy_getStats__E_D(_this, stats); }
#endif
#endif

#endif /* __isrom__ */

#if xdc_runtime_Memory_HeapProxy___scope != -1
xdc_Bool xdc_runtime_Memory_HeapProxy_Proxy__abstract__S()
#ifdef xdc_runtime_Memory_HeapProxy___ABSTRACT
    { return 1; }
#else
    { return 0; }
#endif
xdc_Ptr xdc_runtime_Memory_HeapProxy_Proxy__delegate__S() { return (xdc_Ptr)xdc_runtime_Memory_HeapProxy___DELEGATE_FXNS; }
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_System_SupportProxy___used
/*
 *  ======== module System_SupportProxy ========
 *  Do not modify this file; it is generated from the specification System_SupportProxy.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_System_SupportProxy__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System_SupportProxy.h>
#undef __nested__
#else
#include <xdc/runtime/System_SupportProxy.h>
#endif
#endif

#ifndef __isrom__


#if defined(xdc_runtime_System_SupportProxy___DELEGATE)&& xdc_runtime_System_SupportProxy___scope != -1
#define xdc_runtime_System_SupportProxy___PROXYFXNS(__PRE)\
xdc_Bool xdc_runtime_System_SupportProxy_Module__startupDone__S() {\
    return __CONC__(__PRE,Module__startupDone__S)(); }\
xdc_Void xdc_runtime_System_SupportProxy_abort__E( xdc_String str ) {\
    __CONC__(__PRE,abort)(str); }\
xdc_Void xdc_runtime_System_SupportProxy_exit__E( xdc_Int stat ) {\
    __CONC__(__PRE,exit)(stat); }\
xdc_Void xdc_runtime_System_SupportProxy_flush__E( void ) {\
    __CONC__(__PRE,flush)(); }\
xdc_Void xdc_runtime_System_SupportProxy_putch__E( xdc_Char ch ) {\
    __CONC__(__PRE,putch)(ch); }\
xdc_Bool xdc_runtime_System_SupportProxy_ready__E( void ) {\
    return __CONC__(__PRE,ready)(); }\

xdc_runtime_System_SupportProxy___PROXYFXNS(xdc_runtime_System_SupportProxy___DELEGATE)
#endif


#else /* __isrom__ */


#if defined(xdc_runtime_System_SupportProxy___DELEGATE)
#define xdc_runtime_System_SupportProxy___PROXYFXNS(__PRE)\
xdc_Bool xdc_runtime_System_SupportProxy_Module__startupDone__S() {\
    return __CONC__(__PRE,Module__startupDone__S)(); }\
xdc_Void xdc_runtime_System_SupportProxy_abort__E( xdc_String str ) {\
    __CONC__(__PRE,abort)(str); }\
xdc_Void xdc_runtime_System_SupportProxy_exit__E( xdc_Int stat ) {\
    __CONC__(__PRE,exit)(stat); }\
xdc_Void xdc_runtime_System_SupportProxy_flush__E( void ) {\
    __CONC__(__PRE,flush)(); }\
xdc_Void xdc_runtime_System_SupportProxy_putch__E( xdc_Char ch ) {\
    __CONC__(__PRE,putch)(ch); }\
xdc_Bool xdc_runtime_System_SupportProxy_ready__E( void ) {\
    return __CONC__(__PRE,ready)(); }\

xdc_runtime_System_SupportProxy___PROXYFXNS(xdc_runtime_System_SupportProxy___DELEGATE)
#endif

#endif /* __isrom__ */

#if xdc_runtime_System_SupportProxy___scope != -1
xdc_Bool xdc_runtime_System_SupportProxy_Proxy__abstract__S()
#ifdef xdc_runtime_System_SupportProxy___ABSTRACT
    { return 1; }
#else
    { return 0; }
#endif
xdc_Ptr xdc_runtime_System_SupportProxy_Proxy__delegate__S() { return (xdc_Ptr)xdc_runtime_System_SupportProxy___DELEGATE_FXNS; }
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_System_Module_GateProxy___used
/*
 *  ======== module System_Module_GateProxy ========
 *  Do not modify this file; it is generated from the specification System_Module_GateProxy.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_System_Module_GateProxy__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System_Module_GateProxy.h>
#undef __nested__
#else
#include <xdc/runtime/System_Module_GateProxy.h>
#endif
#endif

#ifndef __isrom__


#if defined(xdc_runtime_System_Module_GateProxy___DELEGATE)&& xdc_runtime_System_Module_GateProxy___scope != -1
#define xdc_runtime_System_Module_GateProxy___PROXYFXNS(__PRE)\
xdc_Bool xdc_runtime_System_Module_GateProxy_Module__startupDone__S() {\
    return __CONC__(__PRE,Module__startupDone__S)(); }\
xdc_Ptr xdc_runtime_System_Module_GateProxy_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __sz, xdc_runtime_Error_Block* __eb ) {\
    return __CONC__(__PRE,Object__create__S)(__oa, __osz, __aa, (xdc_Ptr)__pa, sizeof(xdc_runtime_IGateProvider_Params), __eb); }\
void xdc_runtime_System_Module_GateProxy_Object__delete__S( Ptr instp ) {\
    __CONC__(__PRE,Object__delete__S)(instp); }\
void xdc_runtime_System_Module_GateProxy_Params__init__S( xdc_Ptr dst, const xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) {\
    __CONC__(__PRE,Params__init__S)(dst, src, psz, isz); }\
xdc_runtime_Types_Label* xdc_runtime_System_Module_GateProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab ) {\
    return __CONC__(__PRE,Handle__label__S)(obj, lab); }\
xdc_Bool xdc_runtime_System_Module_GateProxy_query__E( xdc_Int qual ) {\
    return __CONC__(__PRE,query)(qual); }\
xdc_IArg xdc_runtime_System_Module_GateProxy_enter__E_D( xdc_runtime_System_Module_GateProxy_Handle _this ) {\
    return __CONC__(__PRE,enter)((__CONC__(__PRE,Handle))_this); }\
xdc_Void xdc_runtime_System_Module_GateProxy_leave__E_D( xdc_runtime_System_Module_GateProxy_Handle _this, xdc_IArg key ) {\
    __CONC__(__PRE,leave)((__CONC__(__PRE,Handle))_this, key); }\

xdc_runtime_System_Module_GateProxy___PROXYFXNS(xdc_runtime_System_Module_GateProxy___DELEGATE)
xdc_IArg xdc_runtime_System_Module_GateProxy_enter__E_D( xdc_runtime_System_Module_GateProxy_Handle _this );
xdc_IArg xdc_runtime_System_Module_GateProxy_enter__E( xdc_runtime_System_Module_GateProxy_Handle _this ) {
#ifdef xdc_runtime_System_Module_GateProxy___ABSTRACT
    return xdc_runtime_IGateProvider_enter((xdc_runtime_IGateProvider_Handle)_this); }
#else
    return xdc_runtime_System_Module_GateProxy_enter__E_D(_this); }
#endif
xdc_Void xdc_runtime_System_Module_GateProxy_leave__E_D( xdc_runtime_System_Module_GateProxy_Handle _this, xdc_IArg key );
xdc_Void xdc_runtime_System_Module_GateProxy_leave__E( xdc_runtime_System_Module_GateProxy_Handle _this, xdc_IArg key ) {
#ifdef xdc_runtime_System_Module_GateProxy___ABSTRACT
    xdc_runtime_IGateProvider_leave((xdc_runtime_IGateProvider_Handle)_this, key); }
#else
    xdc_runtime_System_Module_GateProxy_leave__E_D(_this, key); }
#endif
#endif


#else /* __isrom__ */


#if defined(xdc_runtime_System_Module_GateProxy___DELEGATE)
#define xdc_runtime_System_Module_GateProxy___PROXYFXNS(__PRE)\
xdc_Bool xdc_runtime_System_Module_GateProxy_Module__startupDone__S() {\
    return __CONC__(__PRE,Module__startupDone__S)(); }\
xdc_Ptr xdc_runtime_System_Module_GateProxy_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, const xdc_Ptr __aa, const xdc_Ptr __pa, xdc_SizeT __sz, xdc_runtime_Error_Block* __eb ) {\
    return __CONC__(__PRE,Object__create__S)(__oa, __osz, __aa, (xdc_Ptr)__pa, sizeof(xdc_runtime_IGateProvider_Params), __eb); }\
void xdc_runtime_System_Module_GateProxy_Object__delete__S( Ptr instp ) {\
    __CONC__(__PRE,Object__delete__S)(instp); }\
void xdc_runtime_System_Module_GateProxy_Params__init__S( xdc_Ptr dst, const xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) {\
    __CONC__(__PRE,Params__init__S)(dst, src, psz, isz); }\
xdc_runtime_Types_Label* xdc_runtime_System_Module_GateProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab ) {\
    return __CONC__(__PRE,Handle__label__S)(obj, lab); }\
xdc_Bool xdc_runtime_System_Module_GateProxy_query__E( xdc_Int qual ) {\
    return __CONC__(__PRE,query)(qual); }\
xdc_IArg xdc_runtime_System_Module_GateProxy_enter__E_D( xdc_runtime_System_Module_GateProxy_Handle _this ) {\
    return __CONC__(__PRE,enter)((__CONC__(__PRE,Handle))_this); }\
xdc_Void xdc_runtime_System_Module_GateProxy_leave__E_D( xdc_runtime_System_Module_GateProxy_Handle _this, xdc_IArg key ) {\
    __CONC__(__PRE,leave)((__CONC__(__PRE,Handle))_this, key); }\

xdc_runtime_System_Module_GateProxy___PROXYFXNS(xdc_runtime_System_Module_GateProxy___DELEGATE)
xdc_IArg xdc_runtime_System_Module_GateProxy_enter__E_D( xdc_runtime_System_Module_GateProxy_Handle _this );
xdc_IArg xdc_runtime_System_Module_GateProxy_enter__E( xdc_runtime_System_Module_GateProxy_Handle _this ) {
#ifdef xdc_runtime_System_Module_GateProxy___ABSTRACT
    return xdc_runtime_IGateProvider_enter((xdc_runtime_IGateProvider_Handle)_this); }
#else
    return xdc_runtime_System_Module_GateProxy_enter__E_D(_this); }
#endif
xdc_Void xdc_runtime_System_Module_GateProxy_leave__E_D( xdc_runtime_System_Module_GateProxy_Handle _this, xdc_IArg key );
xdc_Void xdc_runtime_System_Module_GateProxy_leave__E( xdc_runtime_System_Module_GateProxy_Handle _this, xdc_IArg key ) {
#ifdef xdc_runtime_System_Module_GateProxy___ABSTRACT
    xdc_runtime_IGateProvider_leave((xdc_runtime_IGateProvider_Handle)_this, key); }
#else
    xdc_runtime_System_Module_GateProxy_leave__E_D(_this, key); }
#endif
#endif

#endif /* __isrom__ */

#if xdc_runtime_System_Module_GateProxy___scope != -1
xdc_Bool xdc_runtime_System_Module_GateProxy_Proxy__abstract__S()
#ifdef xdc_runtime_System_Module_GateProxy___ABSTRACT
    { return 1; }
#else
    { return 0; }
#endif
xdc_Ptr xdc_runtime_System_Module_GateProxy_Proxy__delegate__S() { return (xdc_Ptr)xdc_runtime_System_Module_GateProxy___DELEGATE_FXNS; }
#endif /* $__scope */

#endif /* $__used__ */

#ifdef xdc_runtime_Timestamp_SupportProxy___used
/*
 *  ======== module Timestamp_SupportProxy ========
 *  Do not modify this file; it is generated from the specification Timestamp_SupportProxy.xdc
 *  and any modifications risk being overwritten.
 */

#ifndef xdc_runtime_System__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/System.h>
#undef __nested__
#else
#include <xdc/runtime/System.h>
#endif
#endif

#ifndef xdc_runtime_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Memory.h>
#undef __nested__
#else
#include <xdc/runtime/Memory.h>
#endif
#endif

#ifndef xdc_runtime_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Error.h>
#undef __nested__
#else
#include <xdc/runtime/Error.h>
#endif
#endif

#ifndef xdc_runtime_Timestamp_SupportProxy__include
#ifndef __nested__
#define __nested__
#include <xdc/runtime/Timestamp_SupportProxy.h>
#undef __nested__
#else
#include <xdc/runtime/Timestamp_SupportProxy.h>
#endif
#endif

#ifndef __isrom__


#if defined(xdc_runtime_Timestamp_SupportProxy___DELEGATE)&& xdc_runtime_Timestamp_SupportProxy___scope != -1
#define xdc_runtime_Timestamp_SupportProxy___PROXYFXNS(__PRE)\
xdc_Bool xdc_runtime_Timestamp_SupportProxy_Module__startupDone__S() {\
    return __CONC__(__PRE,Module__startupDone__S)(); }\
xdc_Bits32 xdc_runtime_Timestamp_SupportProxy_get32__E( void ) {\
    return __CONC__(__PRE,get32)(); }\
xdc_Void xdc_runtime_Timestamp_SupportProxy_get64__E( xdc_runtime_Types_Timestamp64* result ) {\
    __CONC__(__PRE,get64)(result); }\
xdc_Void xdc_runtime_Timestamp_SupportProxy_getFreq__E( xdc_runtime_Types_FreqHz* freq ) {\
    __CONC__(__PRE,getFreq)(freq); }\

xdc_runtime_Timestamp_SupportProxy___PROXYFXNS(xdc_runtime_Timestamp_SupportProxy___DELEGATE)
#endif


#else /* __isrom__ */


#if defined(xdc_runtime_Timestamp_SupportProxy___DELEGATE)
#define xdc_runtime_Timestamp_SupportProxy___PROXYFXNS(__PRE)\
xdc_Bool xdc_runtime_Timestamp_SupportProxy_Module__startupDone__S() {\
    return __CONC__(__PRE,Module__startupDone__S)(); }\
xdc_Bits32 xdc_runtime_Timestamp_SupportProxy_get32__E( void ) {\
    return __CONC__(__PRE,get32)(); }\
xdc_Void xdc_runtime_Timestamp_SupportProxy_get64__E( xdc_runtime_Types_Timestamp64* result ) {\
    __CONC__(__PRE,get64)(result); }\
xdc_Void xdc_runtime_Timestamp_SupportProxy_getFreq__E( xdc_runtime_Types_FreqHz* freq ) {\
    __CONC__(__PRE,getFreq)(freq); }\

xdc_runtime_Timestamp_SupportProxy___PROXYFXNS(xdc_runtime_Timestamp_SupportProxy___DELEGATE)
#endif

#endif /* __isrom__ */

#if xdc_runtime_Timestamp_SupportProxy___scope != -1
xdc_Bool xdc_runtime_Timestamp_SupportProxy_Proxy__abstract__S()
#ifdef xdc_runtime_Timestamp_SupportProxy___ABSTRACT
    { return 1; }
#else
    { return 0; }
#endif
xdc_Ptr xdc_runtime_Timestamp_SupportProxy_Proxy__delegate__S() { return (xdc_Ptr)xdc_runtime_Timestamp_SupportProxy___DELEGATE_FXNS; }
#endif /* $__scope */

#endif /* $__used__ */


#endif

/* package xdc.platform */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 1, 0, 1, 0
#define __xdc_PKGNAME xdc.platform
#define __xdc_PKGPREFIX xdc_platform_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else

#endif

/* package xdc.cfg */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 1, 0, 1, 0
#define __xdc_PKGNAME xdc.cfg
#define __xdc_PKGPREFIX xdc_cfg_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else

#endif

/* package xdc.shelf */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 1, 0, 0, 0
#define __xdc_PKGNAME xdc.shelf
#define __xdc_PKGPREFIX xdc_shelf_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else

#endif

/* package xdc.services.spec */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 1, 0, 0, 0
#define __xdc_PKGNAME xdc.services.spec
#define __xdc_PKGPREFIX xdc_services_spec_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else

#endif

/* package xdc.services.intern.xsr */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 1, 0, 0
#define __xdc_PKGNAME xdc.services.intern.xsr
#define __xdc_PKGPREFIX xdc_services_intern_xsr_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else

#endif

/* package xdc.services.intern.gen */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 1, 0, 0, 0
#define __xdc_PKGNAME xdc.services.intern.gen
#define __xdc_PKGPREFIX xdc_services_intern_gen_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else

#endif

/* package xdc.services.intern.cmd */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 1, 0, 0, 0
#define __xdc_PKGNAME xdc.services.intern.cmd
#define __xdc_PKGPREFIX xdc_services_intern_cmd_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else

#endif

/* package ti.catalog.c6000 */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 1, 0, 0, 0
#define __xdc_PKGNAME ti.catalog.c6000
#define __xdc_PKGPREFIX ti_catalog_c6000_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else

#endif

/* package ti.platforms.evmDM6437 */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 1, 0, 0
#define __xdc_PKGNAME ti.platforms.evmDM6437
#define __xdc_PKGPREFIX ti_platforms_evmDM6437_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else

#endif

/* package ti.targets.rts6000 */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 1, 0, 0, 0
#define __xdc_PKGNAME ti.targets.rts6000
#define __xdc_PKGPREFIX ti_targets_rts6000_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else

#endif

/* package ti.psl */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 5, 0, 0, 0
#define __xdc_PKGNAME ti.psl
#define __xdc_PKGPREFIX ti_psl_
#ifdef __xdc_bld_pkg_c__
#include __xdc_bld_pkg_c__
#endif

#else
#include <string.h>

#ifndef xdc_rts_System__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/System.h>
#undef __nested__
#else
#include <xdc/rts/System.h>
#endif
#endif

#ifndef xdc_rts_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/Memory.h>
#undef __nested__
#else
#include <xdc/rts/Memory.h>
#endif
#endif

#ifndef xdc_rts_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/Error.h>
#undef __nested__
#else
#include <xdc/rts/Error.h>
#endif
#endif


#endif

/* package ti.rtdx */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS null
#define __xdc_PKGNAME ti.rtdx
#define __xdc_PKGPREFIX ti_rtdx_
#ifdef __xdc_bld_pkg_c__
#include __xdc_bld_pkg_c__
#endif

#else
#include <string.h>

#ifndef xdc_rts_System__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/System.h>
#undef __nested__
#else
#include <xdc/rts/System.h>
#endif
#endif

#ifndef xdc_rts_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/Memory.h>
#undef __nested__
#else
#include <xdc/rts/Memory.h>
#endif
#endif

#ifndef xdc_rts_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/Error.h>
#undef __nested__
#else
#include <xdc/rts/Error.h>
#endif
#endif


#endif

/* package xdc.bld */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 1, 0, 0, 0
#define __xdc_PKGNAME xdc.bld
#define __xdc_PKGPREFIX xdc_bld_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else

#endif

/* package ti.bios */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 5, 2, 3, 19
#define __xdc_PKGNAME ti.bios
#define __xdc_PKGPREFIX ti_bios_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else
#include <string.h>

#ifndef xdc_rts_System__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/System.h>
#undef __nested__
#else
#include <xdc/rts/System.h>
#endif
#endif

#ifndef xdc_rts_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/Memory.h>
#undef __nested__
#else
#include <xdc/rts/Memory.h>
#endif
#endif

#ifndef xdc_rts_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/Error.h>
#undef __nested__
#else
#include <xdc/rts/Error.h>
#endif
#endif


#endif

/* package ti.sdo.ce.trace */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 1, 0, 0
#define __xdc_PKGNAME ti.sdo.ce.trace
#define __xdc_PKGPREFIX ti_sdo_ce_trace_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else

#endif

/* package ti.sdo.fc.dskt2 */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 1, 0, 2
#define __xdc_PKGNAME ti.sdo.fc.dskt2
#define __xdc_PKGPREFIX ti_sdo_fc_dskt2_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else
#include <string.h>

#ifndef xdc_rts_System__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/System.h>
#undef __nested__
#else
#include <xdc/rts/System.h>
#endif
#endif

#ifndef xdc_rts_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/Memory.h>
#undef __nested__
#else
#include <xdc/rts/Memory.h>
#endif
#endif

#ifndef xdc_rts_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/Error.h>
#undef __nested__
#else
#include <xdc/rts/Error.h>
#endif
#endif


#endif

/* package ti.sdo.fc.dman3 */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 1, 0, 2, 0
#define __xdc_PKGNAME ti.sdo.fc.dman3
#define __xdc_PKGPREFIX ti_sdo_fc_dman3_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else
#include <string.h>

#ifndef xdc_rts_System__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/System.h>
#undef __nested__
#else
#include <xdc/rts/System.h>
#endif
#endif

#ifndef xdc_rts_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/Memory.h>
#undef __nested__
#else
#include <xdc/rts/Memory.h>
#endif
#endif

#ifndef xdc_rts_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/Error.h>
#undef __nested__
#else
#include <xdc/rts/Error.h>
#endif
#endif


#endif

/* package ti.bios.utils */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 2, 0, 0, 22
#define __xdc_PKGNAME ti.bios.utils
#define __xdc_PKGPREFIX ti_bios_utils_
#ifdef __xdc_bld_pkg_c__
#include __xdc_bld_pkg_c__
#endif

#else
#include <string.h>

#ifndef xdc_rts_System__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/System.h>
#undef __nested__
#else
#include <xdc/rts/System.h>
#endif
#endif

#ifndef xdc_rts_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/Memory.h>
#undef __nested__
#else
#include <xdc/rts/Memory.h>
#endif
#endif

#ifndef xdc_rts_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/Error.h>
#undef __nested__
#else
#include <xdc/rts/Error.h>
#endif
#endif


#endif

/* package ti.sdo.fc.acpy3 */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 1, 0, 1, 0
#define __xdc_PKGNAME ti.sdo.fc.acpy3
#define __xdc_PKGPREFIX ti_sdo_fc_acpy3_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else
#include <string.h>

#ifndef xdc_rts_System__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/System.h>
#undef __nested__
#else
#include <xdc/rts/System.h>
#endif
#endif

#ifndef xdc_rts_Memory__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/Memory.h>
#undef __nested__
#else
#include <xdc/rts/Memory.h>
#endif
#endif

#ifndef xdc_rts_Error__include
#ifndef __nested__
#define __nested__
#include <xdc/rts/Error.h>
#undef __nested__
#else
#include <xdc/rts/Error.h>
#endif
#endif


#endif

/* package ti.sdo.ce.osal */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS 2, 0, 0
#define __xdc_PKGNAME ti.sdo.ce.osal
#define __xdc_PKGPREFIX ti_sdo_ce_osal_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else

#endif

/* package xdcconfig */

#ifndef __config__
char __dummy__;
#define __xdc_PKGVERS null
#define __xdc_PKGNAME xdcconfig
#define __xdc_PKGPREFIX xdcconfig_
#ifdef __xdc_bld_pkg_c__
#define __stringify(a) #a
#define __local_include(a) __stringify(a)
#include __local_include(__xdc_bld_pkg_c__)
#endif

#else

#endif
