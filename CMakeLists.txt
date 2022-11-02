#
#  Copyright (c) 2021, The OpenThread Authors.
#  All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions are met:
#  1. Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#  2. Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#  3. Neither the name of the copyright holder nor the
#     names of its contributors may be used to endorse or promote products
#     derived from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
#  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
#  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
#  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
#  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
#  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
#  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
#  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
#  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
#  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#  POSSIBILITY OF SUCH DAMAGE.
#


# ==============================================================================
# CMake project definitions
# ==============================================================================
cmake_minimum_required(VERSION 3.16.0)
project(libOpenThread VERSION 1.0.0)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# ==============================================================================
# OpenThread
# ==============================================================================

# Package Version
set(OT_PACKAGE_VERSION "" CACHE STRING "OpenThread Package Version")
if(OT_PACKAGE_VERSION STREQUAL "")
    execute_process(
    COMMAND git rev-parse --short HEAD
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/openthread
    OUTPUT_VARIABLE OT_PACKAGE_VERSION OUTPUT_STRIP_TRAILING_WHITESPACE
)
    message(STATUS "Setting default OpenThread package version: ${OT_PACKAGE_VERSION}")
endif()
message(STATUS "OpenThread Package Version: ${OT_PACKAGE_VERSION}")


set(OT_PLATFORM "external" CACHE STRING "disable example platforms" FORCE)


# ==============================================================================
# mbedtls
# ==============================================================================
# set(OT_EXTERNAL_MBEDTLS "openthread-efr32-soc-mbedtls" CACHE STRING "use silabs mbedtls" FORCE)
# set(OT_BUILTIN_MBEDTLS_MANAGEMENT OFF CACHE BOOL "disable builtin mbedtls management" FORCE)
# set(OT_MBEDTLS ${OT_EXTERNAL_MBEDTLS})


# ==============================================================================
# OT_CONFIG
# ==============================================================================
if(NOT OT_CONFIG)
    set(OT_CONFIG "openthread-core-qca4024-config.h")
endif()

list(APPEND OT_PLATFORM_DEFINES
    "OPENTHREAD_CORE_CONFIG_PLATFORM_CHECK_FILE=\"openthread-core-qca4024-config.h\""
)

list(APPEND OT_PLATFORM_DEFINES "OPENTHREAD_PROJECT_CORE_CONFIG_FILE=\"${OT_CONFIG}\"")

list(APPEND OT_PUBLIC_INCLUDES ${PROJECT_SOURCE_DIR}/include)


# ==============================================================================
# build type
# ==============================================================================
set(CMAKE_BUILD_TYPE "Debug")


# NOTE: The "openthread" subdirectory needs to be added after all OT_* variables are defined
add_subdirectory(openthread)

# target_compile_options(ot-config INTERFACE
#     -Wno-shadow
#     -Wno-pedantic
# )
