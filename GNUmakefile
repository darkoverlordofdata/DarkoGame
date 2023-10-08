#
# use cmake to build for debugging
#
# use gmake to build the release app bundle
#
include $(GNUSTEP_MAKEFILES)/common.make

CC = clang
CXX = clang++


LIBRARY_NAME = libDarkoGameKit

_SYS := $(shell uname 2>/dev/null || echo Unknown)


libDarkoGameKit_HEADER_FILES_INSTALL_DIR = DarkoGameKit
libDarkoGameKit_HEADER_FILES_DIR = Source

libDarkoGameKit_HEADER_FILES = DarkoGameKit.h \
					DGKGame.h \
					tglm.h \
					OpenGL.h \
					content/DGKResourceManager.h \
					graphics/DGKShader.h \
					graphics/DGKSpriteRenderer.h \
					graphics/DGKTexture2D.h 



libDarkoGameKit_OBJC_FILES = Source/DGKGame.m \
					Source/OpenGL.m \
					Source/content/DGKResourceManager.m \
					Source/graphics/DGKShader.m \
					Source/graphics/DGKSpriteRenderer.m \
					Source/graphics/DGKTexture2D.m 



libDarkoGameKit_RESOURCE_FILES = DarkoGameKitInfo.plist \
							


OBJCFLAGS= 	-Wno-nullability-completeness \
			-std=c18 \
			

ifeq ($(_SYS),Linux)
OBJCFLAGS+=	-DOBJC_RUNTIME=21
endif

ifeq ($(_SYS),FreeBSD)
OBJCFLAGS+=	-DOBJC_RUNTIME=20
endif

CFLAGS= 	-std=c18

LDFLAGS=  -lgnustep-corebase



-include GNUmakefile.preamble

-include GNUmakefile.local

include $(GNUSTEP_MAKEFILES)/library.make

-include GNUmakefile.postamble



