#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#

unexport MAKEFILE_LIST
override PKGDIR = xdcconfig
XDCINCS = -I. -I$(strip $(subst ;, -I,$(subst $(space),\$(space),$(XPKGPATH))))
XDCPKGS = $(call pkgsearch,ti/bios/include )
XDCINCS += $(if $(XDCPKGS),-I$(subst $(space), -I,$(XDCPKGS)))
IMPORTPATH += $(if $(XDCPKGS),;$(subst $(space),;,$(XDCPKGS)))
XDCCFGDIR = package/cfg/

#
# The following dependencies ensure package.mak is rebuilt
# in the event that some included BOM script changes.
#
ifneq (clean,$(MAKECMDGOALS))
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/services/global/package/xdc.services.global.sch:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/services/global/package/xdc.services.global.sch
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/Executable.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/Executable.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/tools/configuro/template/custom.mak.exe.xdt:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/tools/configuro/template/custom.mak.exe.xdt
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/services/global/Clock.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/services/global/Clock.xs
package.mak: config.bld
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/om2.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/om2.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/Repository.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/Repository.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/ITargetFilter.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/ITargetFilter.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/IPackage.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/IPackage.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/Script.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/Script.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/recap.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/recap.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/Utils.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/Utils.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/services/io/package.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/services/io/package.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/BuildEnvironment.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/BuildEnvironment.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/services/intern/cmd/package/xdc.services.intern.cmd.sch:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/services/intern/cmd/package/xdc.services.intern.cmd.sch
C:/dvsdk_1_01_00_15/xdc_2_95_02/include/utils.tci:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/include/utils.tci
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/ti/targets/package/ti.targets.sch:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/ti/targets/package/ti.targets.sch
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/Library.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/Library.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/_gen.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/_gen.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/xmlgen.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/xmlgen.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/tools/configuro/template/compiler.opt.xdt:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/tools/configuro/template/compiler.opt.xdt
package.mak: package.bld
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/template.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/template.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/ITarget.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/ITarget.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/services/io/package/xdc.services.io.sch:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/services/io/package/xdc.services.io.sch
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/package.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/package.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/package/xdc.bld.sch:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/package/xdc.bld.sch
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/package/xdc.sch:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/package/xdc.sch
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/services/intern/gen/package/xdc.services.intern.gen.sch:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/services/intern/gen/package/xdc.services.intern.gen.sch
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/services/intern/xsr/package/xdc.services.intern.xsr.sch:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/services/intern/xsr/package/xdc.services.intern.xsr.sch
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/tools/configuro/template/package.xs.xdt:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/tools/configuro/template/package.xs.xdt
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/xdc.tci:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/xdc.tci
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/package.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/package.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/ti/targets/ITarget.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/ti/targets/ITarget.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/services/spec/package/xdc.services.spec.sch:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/services/spec/package/xdc.services.spec.sch
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/shelf/package/xdc.shelf.sch:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/shelf/package/xdc.shelf.sch
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/ti/targets/package.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/ti/targets/package.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/services/io/File.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/services/io/File.xs
C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/PackageContents.xs:
package.mak: C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/xdc/bld/PackageContents.xs
endif

ti.targets.C64P.rootDir ?= C:/CCStudio_v3.3/C6000/cgtools
ti.targets.packageBase ?= C:/dvsdk_1_01_00_15/xdc_2_95_02/packages/ti/targets/
.PRECIOUS: $(XDCCFGDIR)/%.o64P
.PHONY: all,64P .dlls,64P .executables,64P test,64P
all,64P: .executables,64P
.executables,64P: .libraries,64P
.executables,64P: .dlls,64P
.dlls,64P: .libraries,64P
.libraries,64P: .interfaces
	@$(RM) $@
	@$(TOUCH) "$@"

.help::
	@$(ECHO) xdc test,64P
	@$(ECHO) xdc .executables,64P
	@$(ECHO) xdc .libraries,64P
	@$(ECHO) xdc .dlls,64P


all: .executables 
.executables: .libraries .dlls
.libraries: .interfaces

PKGCFGS := $(wildcard package.xs) package/build.cfg
.interfaces: package/package.xdc.xml package/package.defs.h package.xdc $(PKGCFGS)

-include package/package.xdc.dep
package/%.xdc.xml package/%.xdc.inc package/%_xdcconfig.c package/%.defs.h: %.xdc $(PKGCFGS)
	@$(MSG) generating interfaces for package xdcconfig" (because $@ is older than $(firstword $?))" ...
	$(XSRUN) -f xdc/services/intern/cmd/build.xs -m package/package.xdc.dep -i package/package.xdc.inc package.xdc

.executables,64P .executables: audio_video_encdec.x64P

package/cfg/audio_video_encdec_x64Pcfg_c.c package/cfg/audio_video_encdec_x64Pcfg.s62 package/cfg/audio_video_encdec_x64Pcfg.cmd: override _PROG_NAME := audio_video_encdec.x64P
-include package/cfg/audio_video_encdec_x64P.mak
ifneq (clean,$(MAKECMDGOALS))
-include package/cfg/audio_video_encdec_x64P.dep
endif
package/cfg/audio_video_encdec_x64Pcfg.o64P package/cfg/audio_video_encdec_x64Pcfg_c.o64P package/cfg/audio_video_encdec_x64P.o64P : | package/cfg/audio_video_encdec_x64P.xdl
audio_video_encdec.x64P: package/cfg/audio_video_encdec_x64Pcfg.cmd
audio_video_encdec.x64P:
	$(RM) $@
	@$(MSG) lnk64P $@ ...
	$(RM) $(XDCCFGDIR)/$@.map
	$(ti.targets.C64P.rootDir)/bin/lnk6x -w -q -u _c_int00  -q -o $@ package/cfg/audio_video_encdec_x64Pcfg.o64P package/cfg/audio_video_encdec_x64Pcfg_c.o64P package/cfg/audio_video_encdec_x64P.o64P  package/cfg/audio_video_encdec_x64P.xdl  -c -m $(XDCCFGDIR)/$@.map -l $(ti.targets.C64P.rootDir)/lib/rts64plus.lib
	
audio_video_encdec.x64P:C_DIR=
audio_video_encdec.x64P: PATH:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)
audio_video_encdec.x64P: Path:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)


ifeq (,$(wildcard .libraries,64P))
audio_video_encdec.x64P package/cfg/audio_video_encdec_x64P.c: .libraries,64P
endif

package/cfg/audio_video_encdec_x64P.c package/cfg/audio_video_encdec_x64P.h package/cfg/audio_video_encdec_x64P.xdl: override _PROG_NAME := audio_video_encdec.x64P
package/cfg/audio_video_encdec_x64P.c: package/cfg/audio_video_encdec_x64P.cfg
audio_video_encdec.test test,64P test: audio_video_encdec.x64P.test

audio_video_encdec.x64P.test:: audio_video_encdec.x64P
ifeq (,$(_TESTLEVEL))
	@$(MAKE) -R -r --no-print-directory -f $(XDCROOT)/packages/xdc/bld/xdc.mak _TESTLEVEL=1 audio_video_encdec.x64P.test
else
	@$(MSG) running $<  ...
	$(call EXEC.audio_video_encdec.x64P, ) 
endif


clean:: clean,64P
	-$(RM) package/cfg/audio_video_encdec_x64P.cfg
	-$(RM) package/cfg/audio_video_encdec_x64P.dep
	-$(RM) package/cfg/audio_video_encdec_x64P.c
	-$(RM) package/cfg/audio_video_encdec_x64P.xdc.inc

clean,64P::
	-$(RM) audio_video_encdec.x64P
	-$(RM) .tmp,audio_video_encdec.x64P,*

clean:: 
	-$(RM) package/cfg/audio_video_encdec_x64P.pjt
%,copy:
	@$(if $<,,$(MSG) don\'t know how to build $*; exit 1)
	@$(MSG) cp $< $@
	$(RM) $@
	$(CP) $< $@
audio_video_encdec_x64P.o64P,copy : package/cfg/audio_video_encdec_x64P.o64P
audio_video_encdec_x64P.s64P,copy : package/cfg/audio_video_encdec_x64P.s64P
audio_video_encdec_x64Pcfg.o64P,copy : package/cfg/audio_video_encdec_x64Pcfg.o64P
audio_video_encdec_x64Pcfg_c.s64P,copy : package/cfg/audio_video_encdec_x64Pcfg_c.s64P
audio_video_encdec_x64Pcfg_c.o64P,copy : package/cfg/audio_video_encdec_x64Pcfg_c.o64P

$(XDCCFGDIR)%cfg.s62 $(XDCCFGDIR)%cfg_c.c $(XDCCFGDIR)%cfg.cmd $(XDCCFGDIR)%.c $(XDCCFGDIR)%.h $(XDCCFGDIR)%.xdl: $(XDCCFGDIR)%.cfg .interfaces $(XDCROOT)/packages/xdc/cfg/Main.xs
	@$(MSG) "configuring $(_PROG_NAME) from $< ..."
	$(CONFIG) $(_PROG_TCOPTS) xdc.cfg $(_PROG_NAME) $(XDCCFGDIR)$*.cfg $(XDCCFGDIR)$*

.PHONY: release,xdcconfig
xdcconfig.tar: package/package.xdc.xml
xdcconfig.tar: package/package.ext.xml
xdcconfig.tar: package/package.xdc.inc
xdcconfig.tar: package/package.bld.xml
xdcconfig.tar: package/package.rel.dot
ifneq (clean,$(MAKECMDGOALS))
-include package/rel/xdcconfig.tar.dep
endif
package/rel/xdcconfig/xdcconfig/package/package.rel.xml:

xdcconfig.tar: package/rel/xdcconfig.xdc.inc package/rel/xdcconfig/xdcconfig/package/package.rel.xml
	@$(MSG) making release file $@ "(because of $(firstword $?))" ...
	-$(RM) $@
	$(call MKREL,package/rel/xdcconfig.xdc.inc,package/rel/xdcconfig.tar.dep)


release release,xdcconfig: all xdcconfig.tar
clean:: .clean
	-$(RM) xdcconfig.tar
	-$(RM) package/rel/xdcconfig.xdc.inc
	-$(RM) package/rel/xdcconfig.tar.dep

clean:: .clean
	-$(RM) .libraries .libraries,*
clean:: 
	-$(RM) .dlls .dlls,*
#
# The following clean rule removes user specified
# generated files or directories.
#

ifneq (clean,$(MAKECMDGOALS))
ifeq (,$(wildcard package))
    $(shell $(MKDIR) package)
endif
ifeq (,$(wildcard package/external))
    $(shell $(MKDIR) package/external)
endif
ifeq (,$(wildcard package/lib))
    $(shell $(MKDIR) package/lib)
endif
ifeq (,$(wildcard package/cfg))
    $(shell $(MKDIR) package/cfg)
endif
ifeq (,$(wildcard package/rel))
    $(shell $(MKDIR) package/rel)
endif
ifeq (,$(wildcard package/internal))
    $(shell $(MKDIR) package/internal)
endif
endif
clean::
	-$(RMDIR) package

include custom.mak
clean:: 
	-$(RM) package/xdcconfig.pjt