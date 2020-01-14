/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.44                          *
*        Compiled Nov 10 2017, 08:53:57                              *
*        (c) 2017 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

#include "ButtonDLG.h"
#include "./led/bsp_led.h"
#include "./beep/bsp_beep.h" 

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0 (GUI_ID_USER + 0x00)
#define ID_BUTTON_0 (GUI_ID_USER + 0x01)
#define ID_BUTTON_1 (GUI_ID_USER + 0x02)
#define ID_BUTTON_2 (GUI_ID_USER + 0x03)
#define ID_BUTTON_3 (GUI_ID_USER + 0x04)

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
extern GUI_CONST_STORAGE GUI_BITMAP bmBUTTON_OFF;
extern GUI_CONST_STORAGE GUI_BITMAP bmBUTTON_ON;

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 800, 480, 0x64, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button0", ID_BUTTON_0, 10, 30, 160, 48, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button1", ID_BUTTON_1, 10, 138, 160, 48, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button2", ID_BUTTON_2, 50, 246, 80, 80, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "", ID_BUTTON_3, 244, 30, 165, 48, 0, 0x0, 0 },
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/**
  * @brief Button1控件回调函数
  * @note 无
  * @param pMsg：消息指针：消息指针
  * @retval 无
  */
static void _cbButton1(WM_MESSAGE* pMsg)
{
	GUI_RECT Rect;

	switch (pMsg->MsgId)
	{
	case WM_PAINT:
		WM_GetClientRect(&Rect);
		if (BUTTON_IsPressed(pMsg->hWin))
		{
			GUI_SetColor(GUI_GRAY_C8);
			GUI_FillRoundedRect(Rect.x0, Rect.y0, Rect.x1, Rect.y1, 10);
			GUI_SetBkColor(GUI_GRAY_C8);
			GUI_SetColor(0xA0ECECEC);
			GUI_DrawRoundedRect(Rect.x0, Rect.y0, Rect.x1, Rect.y1, 10);
		}
		else
		{
			GUI_SetColor(GUI_WHITE);
			GUI_FillRoundedRect(Rect.x0, Rect.y0, Rect.x1, Rect.y1, 10);
			GUI_SetBkColor(GUI_WHITE);
			GUI_SetColor(0xA0ECECEC);
			GUI_DrawRoundedRect(Rect.x0, Rect.y0, Rect.x1, Rect.y1, 10);
		}
		GUI_SetColor(GUI_BLACK);
		GUI_SetFont(&GUI_Font20B_ASCII);
		GUI_DispStringInRect("Button1", &Rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
		break;

	default:
		BUTTON_Callback(pMsg);
	}
}

/**
  * @brief Button2控件回调函数
  * @note 无
  * @param pMsg：消息指针：消息指针
  * @retval 无
  */
static void _cbButton2(WM_MESSAGE* pMsg)
{
	GUI_RECT Rect;

	switch (pMsg->MsgId)
	{
	case WM_PAINT:
		WM_GetClientRect(&Rect);
		if (BUTTON_IsPressed(pMsg->hWin))
		{
			GUI_SetColor(GUI_RED);
			GUI_SetBkColor(GUI_RED);
			GUI_FillEllipse(Rect.x1 / 2, Rect.y1 / 2, Rect.x1 / 2, Rect.y1 / 2);

			GUI_SetColor(GUI_BLACK);
			GUI_DrawEllipse(Rect.x1 / 2, Rect.y1 / 2, Rect.x1 / 2, Rect.y1 / 2);
		}
		else
		{
			GUI_SetColor(GUI_BLUE);
			GUI_SetBkColor(GUI_BLUE);
			GUI_FillEllipse(Rect.x1 / 2, Rect.y1 / 2, Rect.x1 / 2, Rect.y1 / 2);

			GUI_SetColor(GUI_BLACK);
			GUI_DrawEllipse(Rect.x1 / 2, Rect.y1 / 2, Rect.x1 / 2, Rect.y1 / 2);
		}
		GUI_SetFont(&GUI_Font20B_ASCII);
		GUI_SetColor(GUI_WHITE);
		GUI_DispStringInRect("Button2", &Rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
		break;
	default:
		BUTTON_Callback(pMsg);
	}
}

/**
  * @brief 对话框回调函数
  * @note 无
  * @param pMsg：消息指针：消息指针
  * @retval 无
  */
static void _cbDialog(WM_MESSAGE* pMsg) {
	WM_HWIN hItem;
	int     NCode;
	int     Id;
	static  U8  button_3_flag = 0;

	switch (pMsg->MsgId) {
	case WM_INIT_DIALOG:
		/* 初始化Framewin控件 */
		hItem = pMsg->hWin;
		FRAMEWIN_SetText(hItem, "STemWIN@EmbedFire STM32F429");
		FRAMEWIN_SetFont(hItem, GUI_FONT_32_ASCII);
		FRAMEWIN_SetTitleHeight(hItem, 32);
  	/* 初始化Button0 */
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
    BUTTON_SetFont(hItem, GUI_FONT_20B_1);
		/* 初始化Button1 */
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
		WM_SetCallback(hItem, _cbButton1);
		/* 初始化Button2 */
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
		WM_SetCallback(hItem, _cbButton2);
		/* 初始化Button3 */
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
		BUTTON_SetBitmap(hItem, BUTTON_BI_UNPRESSED, &bmBUTTON_OFF);
		break;
	case WM_NOTIFY_PARENT:
		Id = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch (Id) {
		case ID_BUTTON_0: // Notifications sent by 'Button0'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
        LED1_TOGGLE;
				break;
			}
			break;
		case ID_BUTTON_1: // Notifications sent by 'Button1'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
        LED2_TOGGLE;
				break;
			}
			break;
		case ID_BUTTON_2: // Notifications sent by 'Button2'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
        BEEP_ON;
				break;
			case WM_NOTIFICATION_RELEASED:
        BEEP_OFF;
				break;
			}
			break;
		case ID_BUTTON_3: // Notifications sent by 'Button3'
			/* 获取控件句柄 */
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
				/* Button3已被释放 */
				button_3_flag = ~button_3_flag;
				if (button_3_flag != 0)
				{
					BUTTON_SetBitmap(hItem, BUTTON_BI_UNPRESSED, &bmBUTTON_ON);
				}
				else
					BUTTON_SetBitmap(hItem, BUTTON_BI_UNPRESSED, &bmBUTTON_OFF);
				break;
			}
			break;
		}
		break;
	default:
		WM_DefaultProc(pMsg);
		break;
	}
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/

 /**
  * @brief 以对话框方式间接创建控件
  * @note 无
  * @param 无
  * @retval hWin：资源表中第一个控件的句柄
  */
WM_HWIN CreateFramewin(void);
WM_HWIN CreateFramewin(void) {
	WM_HWIN hWin;

	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}

/**
  * @brief GUI主任务
  * @note 无
  * @param 无
  * @retval 无
  */
void MainTask(void)
{
	/* 创建对话框 */
	CreateFramewin();
  
	while (1)
	{
		GUI_Delay(200);
	}
}

/*************************** End of file ****************************/
