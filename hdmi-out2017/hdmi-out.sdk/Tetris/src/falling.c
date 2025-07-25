#include "display_demo.h"
#include "display_ctrl/display_ctrl.h"
#include <stdio.h>
#include "define.h"
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
#include "xtime_l.h"
#include "sleep.h"
#include <time.h>
#include "color.h"
#include "falling.h"
#include "blocks.h"


DisplayCtrl dispCtrl;
XAxiVdma vdma;

// Each shape is defined in a 4x4 grid
const int SHAPE_DATA[7][4][4][4] = {
		{ // I-shape
		    { // 0� (Vertical - Default Spawn)
		        {1, 0, 0, 0},
		        {1, 0, 0, 0},
		        {1, 0, 0, 0},
		        {1, 0, 0, 0}
		    },
		    { // 90� (Horizontal)
		        {0, 0, 0, 0},
		        {1, 1, 1, 1},
		        {0, 0, 0, 0},
		        {0, 0, 0, 0}
		    },
		    { // 180� (Same as 0�)
		        {1, 0, 0, 0},
		        {1, 0, 0, 0},
		        {1, 0, 0, 0},
		        {1, 0, 0, 0}
		    },
		    { // 270� (Same as 90�)
		        {0, 0, 0, 0},
		        {1, 1, 1, 1},
		        {0, 0, 0, 0},
		        {0, 0, 0, 0}
		    }
		},

    { // O-shape (No rotation)
        { // 0�
            {1, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        { // 90� (Same as 0�)
            {1, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        { // 180� (Same as 0�)
            {1, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        { // 270� (Same as 0�)
            {1, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        }
    },
    { // T-shape
        { // 0�
            {0, 1, 0, 0},
            {1, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        { // 90�
            {1, 0, 0, 0},
            {1, 1, 0, 0},
            {1, 0, 0, 0},
            {0, 0, 0, 0}
        },
        { // 180�
            {0, 0, 0, 0},
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}
        },
        { // 270�
            {0, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}
        }
    },
    { // S-shape
        { // 0�
            {0, 1, 1, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        { // 90�
            {1, 0, 0, 0},
            {1, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}
        },
        { // 180� (Same as 0�)
            {0, 1, 1, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        { // 270� (Same as 90�)
            {1, 0, 0, 0},
            {1, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}
        }
    },
    { // Z-shape
        { // 0�
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        { // 90�
            {0, 1, 0, 0},
            {1, 1, 0, 0},
            {1, 0, 0, 0},
            {0, 0, 0, 0}
        },
        { // 180� (Same as 0�)
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        { // 270� (Same as 90�)
            {0, 1, 0, 0},
            {1, 1, 0, 0},
            {1, 0, 0, 0},
            {0, 0, 0, 0}
        }
    },
    { // L-shape
        { // 0�
            {1, 0, 0, 0},
            {1, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        { // 90�
            {0, 1, 1, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}
        },
        { // 180�
            {0, 0, 0, 0},
            {1, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}
        },
        { // 270�
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0}
        }
    },
    { // J-shape
        { // 0�
            {0, 0, 1, 0},
            {1, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        { // 90�
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
        { // 180�
            {0, 0, 0, 0},
            {1, 1, 1, 0},
            {1, 0, 0, 0},
            {0, 0, 0, 0}
        },
        { // 270�
            {1, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}
        }
    }
};


const int SHAPE_HEIGHT[7] = {1, 2, 2, 2, 2, 2, 2};

// Widths of shapes (default orientation)
const int SHAPE_WIDTH[7] = {4, 2, 3, 3, 3, 3, 3};
const int SHAPE_COLUMN_OFFSETS[7] = {
    0,  // I-shape
    0,  // O-shape
    0,  // T-shape
    0,  // S-shape
    0,  // Z-shape
    -1, // L-shape
    0   // J-shape
};

// RGB Colors for each shape
const int SHAPE_COLORS[7][3] = {
    {0, 225, 255},    // I - Blue
    {255, 255, 0},  // O - Yellow
    {128, 0, 128},  // T - Purple
    {0, 255, 0},    // S - Green
    {255, 0, 0},    // Z - Red
    {255, 165, 0},  // L - Orange
    {0, 0, 255}   // J - Light Blue
};
int blockBag[NUM_SHAPES];    // Primary shuffle bag
int secondaryBag[NUM_SHAPES]; // Secondary random bag
int bagIndex = NUM_SHAPES;   // Index for the current block in the primary bag

void ShuffleBag() {
    for (int i = 0; i < NUM_SHAPES; i++) {
        blockBag[i] = i;        // Fill primary bag with all shapes
        secondaryBag[i] = i;    // Fill secondary bag with all shapes
    }

    // Shuffle the primary bag
    for (int i = NUM_SHAPES - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = blockBag[i];
        blockBag[i] = blockBag[j];
        blockBag[j] = temp;
    }

    // Shuffle the secondary bag
    for (int i = NUM_SHAPES - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = secondaryBag[i];
        secondaryBag[i] = secondaryBag[j];
        secondaryBag[j] = temp;
    }

    bagIndex = 0; // Reset primary bag index

}

void SpawnNextBlock(u32 *blockX, u32 *blockY, int *currentShape, int *currentRotation) {
    // Shuffle the primary bag if all shapes have been used
    if (bagIndex >= NUM_SHAPES) {
        ShuffleBag();
    }

    // Decide whether to use the primary bag or secondary bag
    if (rand() % 3 == 0) { // 33% chance to use the secondary bag
        *currentShape = secondaryBag[rand() % NUM_SHAPES];
    } else {
        *currentShape = blockBag[bagIndex++];
    }

    // Randomize rotation
    *currentRotation = rand() % 4;

    // Reset block position
    *blockX = GRID_X_START + (GRID_WIDTH / 2) - BLOCK_SIZE;
    *blockY = GRID_Y_START;

    xil_printf("Spawned block: Shape = %d, Rotation = %d\r\n", *currentShape, *currentRotation);
}


void RandomizeBlock(int *shape, int *rotation) {
    *shape = rand() % NUM_SHAPES; // Randomize block shape
    *rotation = rand() % 4;       // Randomize block rotation (0-3)
}
int frontBuffer[GRID_ROWS][GRID_COLUMNS] = {0}; // Displayed grid
int backBuffer[GRID_ROWS][GRID_COLUMNS] = {0};  // Working grid

int blockLandedFlag = 0;


int GetLandingPosition(u32 blockX, u32 blockY, int currentShape, int currentRotation) {
    // Simulate the block falling
    while (CanMoveDown(blockX, blockY, currentShape, currentRotation)) {
        blockY += BLOCK_SIZE; // Move one step down
    }
    return blockY; // Return the last valid Y position
}
void DrawGhostBlock(u8 *frame, u32 blockX, u32 blockY, int currentShape, int currentRotation, u32 stride, u8 red, u8 green, u8 blue) {
    // Find the landing position
    u32 landingY = blockY;
    while (CanMoveDown(blockX, landingY, currentShape, currentRotation)) {
        landingY += BLOCK_SIZE;
    }

    // Draw only the edges of the ghost block at the landing position
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (SHAPE_DATA[currentShape][currentRotation][row][col] == 1) {
                u32 xStart = blockX + col * BLOCK_SIZE;
                u32 yStart = landingY + row * BLOCK_SIZE;

                // Top edge
                DrawToTheMonitor(frame, xStart, yStart, BLOCK_SIZE, 1, stride, red, green, blue);
                // Bottom edge
                DrawToTheMonitor(frame, xStart, yStart + BLOCK_SIZE - 1, BLOCK_SIZE, 1, stride, red, green, blue);
                // Left edge
                DrawToTheMonitor(frame, xStart, yStart, 1, BLOCK_SIZE, stride, red, green, blue);
                // Right edge
                DrawToTheMonitor(frame, xStart + BLOCK_SIZE - 1, yStart, 1, BLOCK_SIZE, stride, red, green, blue);
            }
        }
    }
}




int CanMoveDown(u32 blockX, u32 blockY, int currentShape, int currentRotation) {
    int colStart = (blockX - GRID_X_START) / BLOCK_SIZE;
    int rowStart = (blockY - GRID_Y_START) / BLOCK_SIZE;

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (SHAPE_DATA[currentShape][currentRotation][row][col] == 1) {
                int gridRow = rowStart + row + 1; // Check one row below
                int gridCol = colStart + col;

                // Check boundaries
                if (gridRow >= GRID_ROWS || gridCol < 0 || gridCol >= GRID_COLUMNS) {
                    blockLandedFlag = 1; // Block has landed
                    xil_printf("Block has landed: Hit boundary at (%d, %d)\r\n", gridRow, gridCol);
                    return 0; // Out of bounds
                }

                // Check for collision
                if (grid[gridRow][gridCol] == 1) {
                    blockLandedFlag = 1; // Block has landed
                    xil_printf("Block has landed: Collision at (%d, %d)\r\n", gridRow, gridCol);
                    return 0;
                }
            }
        }
    }

    blockLandedFlag = 0; // Reset flag if block can move down
    return 1; // Block can move down
}


void MarkBlockOnGrid(u32 blockX, u32 blockY, int currentRotation) {
    int colStart = (blockX - GRID_X_START) / BLOCK_SIZE;
    int rowStart = (blockY - GRID_Y_START) / BLOCK_SIZE;

   xil_printf(" ",
               currentShape, currentRotation, rowStart, colStart);

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (SHAPE_DATA[currentShape][currentRotation][row][col] == 1) {
                int gridRow = rowStart + row;
                int gridCol = colStart + col;

                xil_printf(" ",
                           gridRow, gridCol, currentShape, currentRotation);

                if (gridRow < 0 || gridRow >= GRID_ROWS || gridCol < 0 || gridCol >= GRID_COLUMNS) {
                } else {
                    grid[gridRow][gridCol] = 1;
                    gridColors[gridRow][gridCol][0] = SHAPE_COLORS[currentShape][0];
                    gridColors[gridRow][gridCol][1] = SHAPE_COLORS[currentShape][1];
                    gridColors[gridRow][gridCol][2] = SHAPE_COLORS[currentShape][2];
                }
            }
        }

    }
}



int CanMoveHorizontal(u32 blockX, u32 blockY, int currentShape, int currentRotation, int direction) {
    int colStart = (blockX - GRID_X_START) / BLOCK_SIZE;
    int rowStart = (blockY - GRID_Y_START) / BLOCK_SIZE;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (SHAPE_DATA[currentShape][currentRotation][i][j] == 1) {
                int newCol = colStart + j + direction;
                int newRow = rowStart + i;


                // Check boundary
                if (newCol < 0 || newCol >= GRID_COLUMNS) {
                    return 0; // Out of bounds
                }

                // Check collision
                if (grid[newRow][newCol] == 1) {
                    return 0; // Collision detected
                }
            }
        }
    }
    return 1; // No collision
}


int CanRotate(u32 blockX, u32 blockY, int currentShape, int nextRotation) {
    int colStart = (blockX - GRID_X_START) / BLOCK_SIZE;
    int rowStart = (blockY - GRID_Y_START) / BLOCK_SIZE;

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (SHAPE_DATA[currentShape][nextRotation][row][col] == 1) {
                int gridRow = rowStart + row;
                int gridCol = colStart + col;

                // Check boundaries
                if (gridRow >= GRID_ROWS || gridCol < 0 || gridCol >= GRID_COLUMNS) {
                    return 0; // Out of bounds
                }

                // Check collisions with existing blocks
                if (grid[gridRow][gridCol] == 1) {
                    return 0; // Collision detected
                }
            }
        }
    }

    return 1; // No collisions, rotation is valid
}
