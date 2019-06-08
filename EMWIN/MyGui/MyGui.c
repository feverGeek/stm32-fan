#include "MyGui.h"


/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 480, 800, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "time", ID_TEXT_0, 30, 10, 51, 24, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "text_year", ID_TEXT_1, 92, 10, 47, 24, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "text_month", ID_TEXT_2, 150, 10, 32, 24, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "text_day", ID_TEXT_3, 200, 10, 32, 24, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "text_week", ID_TEXT_4, 300, 10, 121, 24, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_5, 140, 10, 16, 24, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_6, 180, 10, 16, 24, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "text_h", ID_TEXT_7, 40, 45, 30, 22, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_8, 65, 45, 10, 22, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "text_min", ID_TEXT_9, 75, 45, 30, 22, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_10, 100, 45, 10, 22, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "text_sec", ID_TEXT_11, 110, 45, 30, 22, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "temprt", ID_TEXT_12, 235, 45, 123, 27, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "text_temprt", ID_TEXT_13, 360, 45, 30, 21, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_14, 390, 45, 29, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_15, 30, 100, 168, 27, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "text_speed", ID_TEXT_16, 210, 100, 55, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_17, 276, 100, 60, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_18, 30, 175, 58, 20, 0, 0x64, 0 },
  { DROPDOWN_CreateIndirect, "Dropdown", ID_DROPDOWN_0, 96, 170, 180, 29, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_19, 30, 225, 229, 24, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_20, 356, 225, 28, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_21, 30, 275, 173, 24, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_22, 356, 275, 68, 20, 0, 0x64, 0 },
  { SLIDER_CreateIndirect, "Slider_speed", ID_SLIDER_0, 34, 300, 350, 20, 0, 0x0, 0 },
  { SLIDER_CreateIndirect, "Slider_temprt", ID_SLIDER_1, 37, 250, 350, 20, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "text_temprt2", ID_TEXT_23, 316, 225, 34, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "text_speed2", ID_TEXT_24, 294, 275, 58, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_25, 30, 345, 80, 24, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_26, 30, 430, 102, 24, 0, 0x64, 0 },
  { SPINBOX_CreateIndirect, "SpinboxBoot_h", ID_SPINBOX_0, 35, 380, 80, 30, 0, 0x0, 0 },
  { SPINBOX_CreateIndirect, "SpinboxBoot_min", ID_SPINBOX_1, 150, 380, 80, 30, 0, 0x0, 0 },
  { SPINBOX_CreateIndirect, "SpinboxBoot_sec", ID_SPINBOX_2, 285, 380, 80, 30, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_27, 123, 385, 22, 21, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_28, 236, 385, 40, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_29, 380, 385, 80, 20, 0, 0x64, 0 },
  { SPINBOX_CreateIndirect, "SpinboxSd_h", ID_SPINBOX_3, 35, 460, 80, 30, 0, 0x0, 0 },
  { SPINBOX_CreateIndirect, "SpinboxSd_min", ID_SPINBOX_4, 150, 460, 80, 30, 0, 0x0, 0 },
  { SPINBOX_CreateIndirect, "SpinboxSd_sec", ID_SPINBOX_5, 285, 460, 80, 30, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_30, 123, 465, 21, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_31, 236, 465, 43, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_32, 380, 465, 80, 20, 0, 0x64, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};



/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
	WM_HWIN hItem;
	int     NCode;
	int     Id;
	u32     speed;
	short   temprt;
	u8      buf[10];
	u8      Value;
 
	
	switch (pMsg->MsgId) {
		case WM_INIT_DIALOG:
			TEXT_SetDefaultFont(GUI_FONT_24_ASCII);
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);  TEXT_SetText(hItem, "Time:");	 
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);  TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_TOP);  TEXT_SetFont(hItem, GUI_FONT_24_ASCII);  TEXT_SetText(hItem, "2019");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);  TEXT_SetText(hItem, "12");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);  TEXT_SetText(hItem, "31");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);  TEXT_SetText(hItem, "Wednesday");   
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_5);  TEXT_SetText(hItem, "/");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_6);  TEXT_SetText(hItem, "/");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_7);  TEXT_SetText(hItem, "24");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_8);  TEXT_SetText(hItem, ":");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_9);  TEXT_SetText(hItem, "60");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_10);  TEXT_SetText(hItem, ":");     
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_11);  TEXT_SetText(hItem, "60");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_12);  TEXT_SetText(hItem, "Temperature:");   
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_13);  TEXT_SetText(hItem, "21");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_14);  TEXT_SetText(hItem, "C");   
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_15);  TEXT_SetText(hItem, "Rotational Speed:");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_16);  TEXT_SetText(hItem, "2000");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_17);  TEXT_SetText(hItem, "r/min");    
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_18);  TEXT_SetText(hItem, "Mode:");    
			hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0);
			DROPDOWN_AddString(hItem, "dingshikaiguan");
			DROPDOWN_AddString(hItem, "ziranfeng");
			DROPDOWN_AddString(hItem, "shuimianfeng");
			DROPDOWN_AddString(hItem, "dingshikaiguan");
			DROPDOWN_SetFont(hItem, GUI_FONT_24_ASCII);
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_19);  TEXT_SetText(hItem, "Temperature adjustment:");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_20);  TEXT_SetText(hItem, "C");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_21);  TEXT_SetText(hItem, "Speed regulation:");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_22);  TEXT_SetText(hItem, "r/min");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_23);  TEXT_SetText(hItem, "0");     
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_24);  TEXT_SetText(hItem, "0000");     
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_25);  TEXT_SetText(hItem, "Boot:");    
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_26);  TEXT_SetText(hItem, "ShutDown:");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_SPINBOX_0);  SPINBOX_SetFont(hItem, GUI_FONT_24_ASCII);
			hItem = WM_GetDialogItem(pMsg->hWin, ID_SPINBOX_1);  SPINBOX_SetFont(hItem, GUI_FONT_24_ASCII);
			hItem = WM_GetDialogItem(pMsg->hWin, ID_SPINBOX_2);  SPINBOX_SetFont(hItem, GUI_FONT_24_ASCII);
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_27);  TEXT_SetText(hItem, "h");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_28);  TEXT_SetText(hItem, "min");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_29);  TEXT_SetText(hItem, "sec");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_SPINBOX_3);  SPINBOX_SetFont(hItem, GUI_FONT_24_ASCII);
			hItem = WM_GetDialogItem(pMsg->hWin, ID_SPINBOX_4);  SPINBOX_SetFont(hItem, GUI_FONT_24_ASCII);
			hItem = WM_GetDialogItem(pMsg->hWin, ID_SPINBOX_5);  SPINBOX_SetFont(hItem, GUI_FONT_24_ASCII);
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_30);  TEXT_SetText(hItem, "h");
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_31);  TEXT_SetText(hItem, "min");  
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_32);  TEXT_SetText(hItem, "sec");  
			break;
		
		case WM_NOTIFY_PARENT:
			Id    = WM_GetId(pMsg->hWinSrc);
			NCode = pMsg->Data.v;
			switch(Id) {
				case ID_DROPDOWN_0: // Notifications sent by 'Dropdown'
					switch(NCode) {
						case WM_NOTIFICATION_CLICKED:break;
						case WM_NOTIFICATION_RELEASED:break;
						case WM_NOTIFICATION_SEL_CHANGED:break;
					}
					break;
				case ID_SLIDER_0: // Notifications sent by 'Slider_speed'
					switch(NCode) {
						case WM_NOTIFICATION_CLICKED:break;
						case WM_NOTIFICATION_RELEASED:break;
						case WM_NOTIFICATION_VALUE_CHANGED:break;
					}
					break;
				case ID_SLIDER_1: // Notifications sent by 'Slider_temprt'
					switch(NCode) {
						case WM_NOTIFICATION_CLICKED:break;
						case WM_NOTIFICATION_RELEASED:break;
						case WM_NOTIFICATION_VALUE_CHANGED:break;
					}
					break;
				case ID_SPINBOX_0: // Notifications sent by 'SpinboxBoot_h'
					switch(NCode) {
						//case WM_NOTIFICATION_CLICKED:break;
						case WM_NOTIFICATION_RELEASED:
							Value = SPINBOX_GetValue(ID_SPINBOX_0);
							Value += 1;
							SPINBOX_SetStep(ID_SPINBOX_0, Value);
							break;
						//case WM_NOTIFICATION_MOVED_OUT:break;
						//case WM_NOTIFICATION_VALUE_CHANGED:break;
					}
					break;
				case ID_SPINBOX_1: // Notifications sent by 'SpinboxBoot_min'
					switch(NCode) {
						case WM_NOTIFICATION_CLICKED:break;
						case WM_NOTIFICATION_RELEASED:break;
						case WM_NOTIFICATION_MOVED_OUT:break;
						case WM_NOTIFICATION_VALUE_CHANGED:break;
					}
					break;
				case ID_SPINBOX_2: // Notifications sent by 'SpinboxBoot_sec'
					switch(NCode) {
						case WM_NOTIFICATION_CLICKED:break;
						case WM_NOTIFICATION_RELEASED:break;
						case WM_NOTIFICATION_MOVED_OUT:break;
						case WM_NOTIFICATION_VALUE_CHANGED: break;
					}
					break;
				case ID_SPINBOX_3: // Notifications sent by 'SpinboxSd_h'
					switch(NCode) {
						case WM_NOTIFICATION_CLICKED:break;
						case WM_NOTIFICATION_RELEASED:break;
						case WM_NOTIFICATION_MOVED_OUT: break;
						case WM_NOTIFICATION_VALUE_CHANGED:	break;
					}
					break;
				case ID_SPINBOX_4: // Notifications sent by 'SpinboxSd_min'
					switch(NCode) {
						case WM_NOTIFICATION_CLICKED:break;
						case WM_NOTIFICATION_RELEASED:break;
						case WM_NOTIFICATION_MOVED_OUT:break;
						case WM_NOTIFICATION_VALUE_CHANGED:break;
					}
					break;
				case ID_SPINBOX_5: // Notifications sent by 'SpinboxSd_sec'
					switch(NCode) {
						case WM_NOTIFICATION_CLICKED: break;
						case WM_NOTIFICATION_RELEASED:break;
						case WM_NOTIFICATION_MOVED_OUT:break;
						case WM_NOTIFICATION_VALUE_CHANGED:break;
					}
					break;
			}
			break;
		default:
			WM_DefaultProc(pMsg);
			
			/* 实时显示转速 */
			speed = MOTOR_Speed();
			sprintf((char*)buf, "%d", speed);
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_16);
			TEXT_SetText(hItem, (char*)buf);
		
			/* 实时显示温度	*/
			temprt = DS18B20_Get_Temp();
			sprintf((char*)buf, "%d", temprt);
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_13);
			TEXT_SetText(hItem, (char*)buf);
			break;
	}
}



void _Main(void)
{
	int xSize = LCD_GetXSize();
	int ySize = LCD_GetYSize();
	WM_HWIN hWin;
	
	WM_SelectWindow(WM_HBKWIN);
	GUI_Clear();
	// Monday，Tuesday、Wednesday、Thursday、Friday、Saturday 、Sunday
	hWin = GUI_CreateDialogBox(_aDialogCreate, 
								GUI_COUNTOF(_aDialogCreate), 
								&_cbDialog, 
								WM_HBKWIN,
								0, 0);
}



void MYGUI_Main(void)
{
	/* 皮肤设置 */
    FRAMEWIN_SKINFLEX_PROPS Framewin_Props;
	BUTTON_SetReactOnLevel();
	FRAMEWIN_GetSkinFlexProps(&Framewin_Props, FRAMEWIN_SKINFLEX_PI_ACTIVE);
	Framewin_Props.Radius = 0;
	FRAMEWIN_SetSkinFlexProps(&Framewin_Props, FRAMEWIN_SKINFLEX_PI_ACTIVE);
	FRAMEWIN_GetSkinFlexProps(&Framewin_Props, FRAMEWIN_SKINFLEX_PI_INACTIVE);
	Framewin_Props.Radius = 0;
	FRAMEWIN_SetSkinFlexProps(&Framewin_Props, FRAMEWIN_SKINFLEX_PI_INACTIVE);
	FRAMEWIN_SetDefaultSkin(FRAMEWIN_SKIN_FLEX);
	BUTTON_SetDefaultSkin(BUTTON_SKIN_FLEX);
	SCROLLBAR_SetDefaultSkin(SCROLLBAR_SKIN_FLEX);
	SLIDER_SetDefaultSkin(SLIDER_SKIN_FLEX);
	 
	while(1)
	{
		_Main();
	}
    
}


void MainTask(void) {
	
    WM_SetCreateFlags(WM_CF_MEMDEV);
    GUI_Init();
	GUI_SetDefaultFont(GUI_FONT_24_ASCII);
    MYGUI_Main();
}

