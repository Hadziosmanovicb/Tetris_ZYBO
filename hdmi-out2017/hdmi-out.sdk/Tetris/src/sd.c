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
#include "sleep.h" // Include for delay function
#include <time.h>
#include "xtime_l.h"
#include "color.h"
#include <stdlib.h> // For rand()
#include <time.h>   // For seeding randomness
#include "falling.h"
#include "grid.h"
#include <stdlib.h> // For rand()
#include <time.h>   // For seeding randomness
#include "xtime_l.h"
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
#include "ff.h"
#include <string.h>
#include "hardware_init.h"
#include "sd.h"
static FATFS fatfs;
static FIL fil;
static char FileName[] = "start3.ppm";
u8 imageBuffer[10*1024*1024] __attribute__ ((aligned(32)));

#define MAX_IMAGE_SIZE (640 * 480 * 4) // Maximum resolution
static u8 rgbaData[MAX_IMAGE_SIZE];   // Static buffer for RGBA data

int LoadAndDisplayImage(u8 *framePtr, int targetWidth, int targetHeight, const char *fileName) {
    FRESULT Res;
    UINT NumBytesRead;
    TCHAR *Path = "0:/";

    /* Mount file system */
    Res = f_mount(&fatfs, Path, 0);
    if (Res != FR_OK) {
        xil_printf("Error mounting filesystem: %d\r\n", Res);
        return XST_FAILURE;
    }

    /* Open image file */
    Res = f_open(&fil, fileName, FA_READ);
    if (Res != FR_OK) {
        xil_printf("Error opening file: %d\r\n", Res);
        return XST_FAILURE;
    }

    /* Read image data */
    Res = f_read(&fil, imageBuffer, sizeof(imageBuffer), &NumBytesRead);
    if (Res != FR_OK) {
        xil_printf("Error reading file: %d\r\n", Res);
        f_close(&fil);
        return XST_FAILURE;
    }

    /* Close file */
    f_close(&fil);

    /* Parse PPM Header */
    char *pixelStart = (char *)imageBuffer;
    xil_printf("Parsing PPM Header...\r\n");
    while (*pixelStart != '\n') pixelStart++;  // Skip "P6" line
    pixelStart++;

    while (*pixelStart == '#') {  // Skip comments
        while (*pixelStart != '\n') pixelStart++;
        pixelStart++;
    }

    int inputWidth = 0, inputHeight = 0;
    sscanf(pixelStart, "%d %d", &inputWidth, &inputHeight);
    xil_printf("Input Dimensions: %d x %d\r\n", inputWidth, inputHeight);

    while (*pixelStart != '\n') pixelStart++;  // Skip dimensions line
    pixelStart++;
    while (*pixelStart != '\n') pixelStart++;  // Skip max color value line
    pixelStart++;

    /* Convert to RGBA */
    static u8 rgbaData[MAX_IMAGE_SIZE];
    for (int i = 0; i < inputWidth * inputHeight; i++) {
        int srcOffset = i * 3;
        int destOffset = i * 4;

        u8 red = pixelStart[srcOffset];
        u8 green = pixelStart[srcOffset + 1];
        u8 blue = pixelStart[srcOffset + 2];

        rgbaData[destOffset] = red;        // Red
        rgbaData[destOffset + 1] = green; // Green
        rgbaData[destOffset + 2] = blue;  // Blue
        rgbaData[destOffset + 3] = 255;   // Alpha
    }

    /* Render to framebuffer */
    xil_printf("Rendering to framebuffer...\r\n");
    for (int y = 0; y < targetHeight; y++) {
        for (int x = 0; x < targetWidth; x++) {
            int src_x = (x * inputWidth) / targetWidth;
            int src_y = (y * inputHeight) / targetHeight;
            int srcIndex = (src_y * inputWidth + src_x) * 4;

            int destIndex = ((y * DEMO_STRIDE) + (x * 4));

            framePtr[destIndex] = rgbaData[srcIndex + 2];     // Blue
            framePtr[destIndex + 1] = rgbaData[srcIndex + 1]; // Green
            framePtr[destIndex + 2] = rgbaData[srcIndex];     // Red
            framePtr[destIndex + 3] = rgbaData[srcIndex + 3]; // Alpha
        }
    }

    xil_printf("Image rendered successfully.\r\n");
    return XST_SUCCESS;
}
