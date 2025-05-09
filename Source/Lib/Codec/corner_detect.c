/*
 * Copyright (c) 2016, Alliance for Open Media. All rights reserved
 *
 * This source code is subject to the terms of the BSD 2 Clause License and
 * the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
 * was not distributed with this source code in the LICENSE file, you can
 * obtain it at https://www.aomedia.org/license/software-license. If the Alliance for Open
 * Media Patent License 1.0 was not distributed with this source code in the
 * PATENTS file, you can obtain it at https://www.aomedia.org/license/patent-license.
 */

#include <stdlib.h>
#include "fast.h"

#include "corner_detect.h"

#if SVT_USE_MIMALLOC
#include "mimalloc-override.h"
#endif

// Fast_9 wrapper
#define FAST_BARRIER 18
int svt_av1_fast_corner_detect(unsigned char *buf, int width, int height, int stride, int *points, int max_points) {
    int       num_points;
    xy *const frm_corners_xy = svt_aom_fast9_detect_nonmax(buf, width, height, stride, FAST_BARRIER, &num_points);
    num_points               = (num_points <= max_points ? num_points : max_points);
    if (num_points > 0 && frm_corners_xy) {
        svt_memcpy(points, frm_corners_xy, sizeof(*frm_corners_xy) * num_points);
        free(frm_corners_xy);
        return num_points;
    }
    free(frm_corners_xy);
    return 0;
}
