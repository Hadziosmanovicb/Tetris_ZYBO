#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include "xgpio.h"
#include "xscugic.h"
#include "xil_exception.h"
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
// Declare GPIO instances
extern XGpio ledGpio;
extern XGpio btnGpio;
extern XGpio swGpio;

// Function prototypes
void initializeInterrupts(XScuGic *interruptController);
void BtnInterruptHandler(void *InstancePtr);
void SwInterruptHandler(void *InstancePtr);
// Function prototypes
int IntcInitFunction(u16 DeviceId, XGpio *GpioInstancePtr);
int InterruptSystemSetup(XScuGic *XScuGicInstancePtr);
void BTN_Intr_Handler(void *InstancePtr);  // Declaration of the interrupt handler

#endif
