#include "display_demo.h"
#include "display_ctrl/display_ctrl.h"
#include <stdio.h>
#include "define.h"
#include "xuartps.h"
#include "math.h"
#include <ctype.h>
#include <stdlib.h>
#include "xil_types.h"
#include "xil_cache.h"
#include "timer_ps/timer_ps.h"
#include "xparameters.h"
#include "xparameters.h"
#include "xgpio.h"
#include "xscugic.h"
#include "xil_exception.h"
#include "xil_printf.h"
#include "interrupts.h"
#include "hardware_init.h"
#include "define.h"
#include <stdio.h>
#include "xtime_l.h"
#include "display_demo.h"
#include "display_demo.h"
#include "display_ctrl/display_ctrl.h"
#include <stdio.h>
#include "xuartps.h"
#include "math.h"
#include <ctype.h>
#include <stdlib.h>
#include "xil_types.h"
#include "xil_cache.h"
#include "timer_ps/timer_ps.h"
#include "xparameters.h"
#include "sleep.h"
#include <time.h>
#include "xtime_l.h"
#include "color.h"
#include "display_demo.h"
#include "falling.h"
#include "blocks.h"
#include "grid.h"
DisplayCtrl dispCtrl;
XAxiVdma vdma;

// Snap a position to the nearest grid line
u32 SnapToGrid(u32 position, u32 gridStart, u32 blockSize) {
    return gridStart + ((position - gridStart) / blockSize) * blockSize;
}
// Define shape types




void RedrawGridBlocks() {
    for (int row = 0; row < GRID_ROWS; row++) {
        for (int col = 0; col < GRID_COLUMNS; col++) {
            if (grid[row][col] == 1) {
                DrawBlock(dispCtrl.framePtr[dispCtrl.curFrame],
                          GRID_X_START + col * BLOCK_SIZE,
                          GRID_Y_START + row * BLOCK_SIZE,
                          BLOCK_SIZE, dispCtrl.stride,
                          gridColors[row][col][0],  // Red
                          gridColors[row][col][1],  // Green
                          gridColors[row][col][2]   // Blue
                );
            } else {
                // Clear empty cells
                DrawToTheMonitor(dispCtrl.framePtr[dispCtrl.curFrame],
                              GRID_X_START + col * BLOCK_SIZE,
                              GRID_Y_START + row * BLOCK_SIZE,
                              BLOCK_SIZE, BLOCK_SIZE, dispCtrl.stride, 0, 0, 0);
            }
        }
    }
}


void DrawGrid(u8 *frame, u32 xStart, u32 yStart, u32 width, u32 height, u32 stride, u32 blockSize) {
    // Draw vertical grid lines
    for (u32 x = xStart; x <= xStart + width; x += blockSize) {
        DrawToTheMonitor(frame, x, yStart, 1, height, stride, 200, 200, 200); // Light gray lines
    }

    // Draw horizontal grid lines
    for (u32 y = yStart; y <= yStart + height; y += blockSize) {
        DrawToTheMonitor(frame, xStart, y, width, 1, stride, 200, 200, 200); // Light gray lines
    }
}
void ShiftRowsDown(int startRow) {
    for (int row = startRow; row > 0; row--) {
        for (int col = 0; col < GRID_COLUMNS; col++) {
            grid[row][col] = grid[row - 1][col];
            gridColors[row][col][0] = gridColors[row - 1][col][0];
            gridColors[row][col][1] = gridColors[row - 1][col][1];
            gridColors[row][col][2] = gridColors[row - 1][col][2];
        }
    }

    // Clear the top row
    for (int col = 0; col < GRID_COLUMNS; col++) {
        grid[0][col] = 0;
        gridColors[0][col][0] = 0;
        gridColors[0][col][1] = 0;
        gridColors[0][col][2] = 0;
    }
}


void ClearFullRows() {
    for (int row = 0; row < GRID_ROWS; row++) {
        int isFull = 1;

        for (int col = 0; col < GRID_COLUMNS; col++) {
            if (grid[row][col] == 0) {
                isFull = 0;
                break;
            }
        }

        if (isFull) {
            ShiftRowsDown(row);
            score += 100; // Increment score for cleared row
        }
    }
}



