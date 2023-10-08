cmake_minimum_required ( VERSION 3.16 )
###################################################################################
#
#   Build DarkoGameKit
#
###################################################################################
###################################################################################
#
#   Experimental cmake build for CMake Tools tooling
#
###################################################################################
project(DarkoGameKit VERSION 0.0.1 DESCRIPTION "DarkoGameKit")
enable_language( OBJC )
#
# enable features
#
set ( CMAKE_EXPORT_COMPILE_COMMANDS ON )
include ( CMakeToolsHelpers OPTIONAL )

set ( LIB_HEADER_FILES
    Source/DarkoGameKit.h 
    Source/DGKGame.h 
    Source/tglm.h 
    Source/OpenGL.h 
    Source/content/DGKResourceManager.h 
    Source/graphics/DGKShader.h 
    Source/graphics/DGKSpriteRenderer.h 
    Source/graphics/DGKTexture2D.h 
)

#
#   application source
#
set ( LIB_SOURCE_FILES
    Source/DGKGame.m 
    Source/OpenGL.m 
    Source/content/DGKResourceManager.m 
    Source/graphics/DGKShader.m 
    Source/graphics/DGKSpriteRenderer.m 
    Source/graphics/DGKTexture2D.m 
)


#
#   application includes
#
set ( INCLUDES "${INCLUDES};/usr/include" )
set ( INCLUDES "${INCLUDES};/usr/GNUstep/Local/Library/Headers" )
set ( INCLUDES "${INCLUDES};/usr/local/include" )
set ( INCLUDES "${INCLUDES};/usr/local/GNUstep/System/Library/Headers" )
#   compiler options
#

set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -O2" )
set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -pipe" )
set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -std=c18" )
set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -Wall" )
set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -Wno-psabi" )
set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -Wno-import" )
set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -Wno-nullability-completeness" )

IF(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
	set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -fobjc-runtime=gnustep-2.0" )
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -fobjc-runtime=gnustep-2.1" )
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -fblocks" )
# set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -fobjc-arc" )
set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -fexceptions" )
set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -fobjc-exceptions" )
set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -fPIC" )
set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -fstack-protector-strong" )
set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -fno-strict-aliasing" )
set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -fconstant-string-class=NSConstantString" )

IF(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
	set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -DOBJC_RUNTIME=20" )
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -DOBJC_RUNTIME=21" )
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -DGNUSTEP" )
set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -DGNUSTEP_BASE_LIBRARY=1" )
set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -DGNU_GUI_LIBRARY=1" )
set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -DGNUSTEP_RUNTIME=1" )
set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -D_NONFRAGILE_ABI=1" )
set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -D_NATIVE_OBJC_EXCEPTIONS" )
set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -DGSWARN" )
set ( CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -DGSDIAGNOSE" )


# Libs: 
link_directories ( "/usr/lib" )
link_directories ( "/usr/GNUstep/Local/Library/Libraries" )
link_directories ( "/usr/local/lib" )
link_directories ( "/usr/local/GNUstep/System/Library/Libraries" )

# definitions 
include_directories ( AFTER ${INCLUDES} )

#
#   compile ccode & link executable
#
add_library(
  ${PROJECT_NAME} SHARED
  ${LIB_SOURCE_FILES}
  ${LIB_HEADER_FILES}

)


target_link_libraries ( ${PROJECT_NAME} m objc gnustep-corebase gnustep-base pthread  )


