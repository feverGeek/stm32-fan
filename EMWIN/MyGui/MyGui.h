#ifndef __MYGUI_H
#define __MYGUI_H

/************ include  ****************/
#include "WM.h"
 
#include "FRAMEWIN.h"
#include "TEXT.h"
#include "BUTTON.h"
#include "SLIDER.h"
#include "SPINBOX.h"
#include "DROPDOWN.h"
#include "GUI.h"

#include "LED.h"
#include "motor.h"
#include "ds18b20.h"

#include <stdio.h>

/************ defines ******************/
#define ID_FRAMEWIN_0 (GUI_ID_USER + 0x00)
#define ID_TEXT_0 (GUI_ID_USER + 0x02)
#define ID_TEXT_1 (GUI_ID_USER + 0x03)
#define ID_TEXT_2 (GUI_ID_USER + 0x04)
#define ID_TEXT_3 (GUI_ID_USER + 0x05)
#define ID_TEXT_4 (GUI_ID_USER + 0x06)
#define ID_TEXT_5 (GUI_ID_USER + 0x08)
#define ID_TEXT_6 (GUI_ID_USER + 0x09)
#define ID_TEXT_7 (GUI_ID_USER + 0x0A)
#define ID_TEXT_8 (GUI_ID_USER + 0x0B)
#define ID_TEXT_9 (GUI_ID_USER + 0x0C)
#define ID_TEXT_10 (GUI_ID_USER + 0x0D)
#define ID_TEXT_11 (GUI_ID_USER + 0x0E)
#define ID_TEXT_12 (GUI_ID_USER + 0x0F)
#define ID_TEXT_13 (GUI_ID_USER + 0x10)
#define ID_TEXT_14 (GUI_ID_USER + 0x11)
#define ID_TEXT_15 (GUI_ID_USER + 0x12)
#define ID_TEXT_16 (GUI_ID_USER + 0x13)
#define ID_TEXT_17 (GUI_ID_USER + 0x14)
#define ID_TEXT_18 (GUI_ID_USER + 0x15)
#define ID_DROPDOWN_0 (GUI_ID_USER + 0x17)
#define ID_TEXT_19 (GUI_ID_USER + 0x18)
#define ID_TEXT_20 (GUI_ID_USER + 0x1B)
#define ID_TEXT_21 (GUI_ID_USER + 0x1C)
#define ID_TEXT_22 (GUI_ID_USER + 0x1E)
#define ID_SLIDER_0 (GUI_ID_USER + 0x1F)
#define ID_SLIDER_1 (GUI_ID_USER + 0x20)
#define ID_TEXT_23 (GUI_ID_USER + 0x21)
#define ID_TEXT_24 (GUI_ID_USER + 0x22)
#define ID_TEXT_25 (GUI_ID_USER + 0x23)
#define ID_TEXT_26 (GUI_ID_USER + 0x24)
#define ID_SPINBOX_0 (GUI_ID_USER + 0x28)
#define ID_SPINBOX_1 (GUI_ID_USER + 0x29)
#define ID_SPINBOX_2 (GUI_ID_USER + 0x2A)
#define ID_TEXT_27 (GUI_ID_USER + 0x2B)
#define ID_TEXT_28 (GUI_ID_USER + 0x2C)
#define ID_TEXT_29 (GUI_ID_USER + 0x2D)
#define ID_SPINBOX_3 (GUI_ID_USER + 0x2E)
#define ID_SPINBOX_4 (GUI_ID_USER + 0x2F)
#define ID_SPINBOX_5 (GUI_ID_USER + 0x30)
#define ID_TEXT_30 (GUI_ID_USER + 0x31)
#define ID_TEXT_31 (GUI_ID_USER + 0x32)
#define ID_TEXT_32 (GUI_ID_USER + 0x33)


void MainTask(void);
void MYGUI_Main(void);

#endif

