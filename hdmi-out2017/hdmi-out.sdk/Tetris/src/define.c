#include "define.h"




// UART instance
XUartPs uartInstance;



// Til tetris


int btn1_last_state = 0, btn0_last_state = 0, btn3_last_state = 0, btn2_last_state = 0;
int simulationStarted = 0;
int isFalling = 0;

int renderState = 0;
int renderLandedBlocks = 1;

int blockLanded[GRID_ROWS][GRID_COLUMNS] = {0};
int hasBeenRendered[GRID_ROWS][GRID_COLUMNS] = {0};
int gameOver = 0; // 0 for active, 1 for game over
int score = 0; // Initialize score

int currentShape = 0; // Active shape
int nextShape = 0;    // Next shape to display in the "Next Box"

int shapeIndex = 0; // Initialize the shape index
int highScore = 0; // Stores the highest score achieved
// Initialize fall intervals
double normal_fall_interval = 0.6; // 600ms per move
double fast_fall_interval = 0.01;  // Adjust fast fall accordingly
double current_fall_interval;     // Dynamic fall interval

// Game speed for each level
double level1_fall_interval = 0.6; // Slowest speed (level 1)
double level2_fall_interval = 0.5; // Slightly faster (level 2)
double level3_fall_interval = 0.4; // Moderate speed (level 3)
double level4_fall_interval = 0.3; // Fast (level 4)
double level5_fall_interval = 0.2; // Fastest speed (level 5)
