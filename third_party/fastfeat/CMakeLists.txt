#
# Copyright(c) 2019 Intel Corporation
# SPDX - License - Identifier: BSD - 2 - Clause - Patent
#
# third_party/fastfeat Directory CMakeLists.txt

# Include fastfeat subdirectory
include_directories(${PROJECT_SOURCE_DIR}/third_party/fastfeat/)
if(USE_MIMALLOC)
    include_directories(${PROJECT_SOURCE_DIR}/third_party/mimalloc/include/)
endif()

add_library(FASTFEAT OBJECT
    fast.h
    fast.c
    fast_9.c
    nonmax.c)
