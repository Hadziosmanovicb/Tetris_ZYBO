#include "display_demo.h"
#include "display_ctrl/display_ctrl.h"
#include <stdio.h>
#include "xuartps.h"
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include "xil_types.h"
#include "xil_cache.h"
#include "timer_ps/timer_ps.h"
#include "xparameters.h"
#include "xgpio.h"
#include "xscugic.h"
#include "xil_exception.h"
#include "xil_printf.h"
#include "interrupts.h"
#include "hardware_init.h"
#include "define.h"
#include "xtime_l.h"
#include "sleep.h"
#include <time.h>




void DemoFillWhite(u8 *frame, u32 width, u32 height, u32 stride) {
    u32 xcoi, ycoi;
    u32 iPixelAddr;

    for (ycoi = 0; ycoi < height; ycoi++) {
        for (xcoi = 0; xcoi < (width * 4); xcoi += 4) {
            iPixelAddr = xcoi + (ycoi * stride);
            frame[iPixelAddr] = 255;       // Red
            frame[iPixelAddr + 1] = 255;   // Green
            frame[iPixelAddr + 2] = 255;   // Blue
        }
    }

    Xil_DCacheFlushRange((unsigned int)frame, stride * height);
}
void DemoFillBlack(u8 *frame, u32 width, u32 height, u32 stride)
{
    u32 xcoi, ycoi;
    u32 iPixelAddr;

    for (ycoi = 0; ycoi < height; ycoi++) {
        for (xcoi = 0; xcoi < (width * 4); xcoi += 4) {
            iPixelAddr = xcoi + (ycoi * stride);
            frame[iPixelAddr] = 0;   // Red
            frame[iPixelAddr + 1] = 0; // Green
            frame[iPixelAddr + 2] = 0; // Blue
        }
    }

    Xil_DCacheFlushRange((unsigned int)frame, stride * height);
}

void DemoFillDarkBlue(u8 *frame, u32 width, u32 height, u32 stride)
{
    u32 xcoi, ycoi;
    u32 iPixelAddr;

    for (ycoi = 0; ycoi < height; ycoi++)
    {
        for (xcoi = 0; xcoi < (width * 4); xcoi += 4)
        {
            iPixelAddr = xcoi + (ycoi * stride);
            frame[iPixelAddr] = 139;  // Blue (in BGR format)
            frame[iPixelAddr + 1] = 0; // Green
            frame[iPixelAddr + 2] = 0; // Red
        }
    }

    Xil_DCacheFlushRange((unsigned int)frame, stride * height);
}

