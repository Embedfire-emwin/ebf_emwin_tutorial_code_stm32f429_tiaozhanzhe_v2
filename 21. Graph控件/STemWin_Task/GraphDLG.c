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

#include "GraphDLG.h"
#include "stdlib.h"
#include "./adc/bsp_adc.h"
#include "./usart/bsp_debug_usart.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0 (GUI_ID_USER + 0x00)
#define ID_GRAPH_0 (GUI_ID_USER + 0x01)

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
/*数据对象句柄*/
GRAPH_DATA_Handle Graphdata;

extern __IO uint16_t ADC_ConvertedValue;

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 800, 480, 0, 0x0, 0 },
  { GRAPH_CreateIndirect, "Graph", ID_GRAPH_0, 60, 10, 645, 425, 0, 0x0, 0 },
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

/**
  * @brief 对话框回调函数
  * @note 无
  * @param pMsg：消息指针
  * @retval 无
  */
static void _cbDialog(WM_MESSAGE* pMsg) {
	WM_HWIN hItem;
  GRAPH_SCALE_Handle hScaleV;

	switch (pMsg->MsgId) {
	case WM_INIT_DIALOG:
		/* 初始化Framewin控件 */
		hItem = pMsg->hWin;
		FRAMEWIN_SetText(hItem, "STemWIN@EmbedFire STM32F429");
		FRAMEWIN_SetFont(hItem, GUI_FONT_20_1);
		/* 初始化Graph控件 */
		hItem = WM_GetDialogItem(pMsg->hWin, ID_GRAPH_0);
    GRAPH_SetColor(hItem, GUI_WHITE, GRAPH_CI_BK);
    GRAPH_SetColor(hItem, GUI_BLACK, GRAPH_CI_GRID);
		GRAPH_SetBorder(hItem, 30, 10, 10, 10);
	  GRAPH_SetGridDistX(hItem, 50);
	  GRAPH_SetGridDistY(hItem, 50);
	  GRAPH_SetLineStyleH(hItem, GUI_LS_DOT);
	  GRAPH_SetLineStyleV(hItem, GUI_LS_DOT);
	  GRAPH_SetGridVis(hItem, 1);
	  /* 创建垂直刻度对象 */
	  hScaleV = GRAPH_SCALE_Create(15, GUI_TA_HCENTER | GUI_TA_LEFT,
	                               GRAPH_SCALE_CF_VERTICAL, 50);
	  GRAPH_AttachScale(hItem, hScaleV);
	  GRAPH_SCALE_SetFactor(hScaleV, 10);
	  /* 创建数据对象 */
	  Graphdata = GRAPH_DATA_YT_Create(GUI_RED, 600, 0, 0);
	  GRAPH_AttachData(hItem, Graphdata);
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
	/* 创建窗口 */
	CreateFramewin();
	
	while(1)
	{
		/* 向GRAPH数据对象添加数据 */
		GRAPH_DATA_YT_AddValue(Graphdata, ADC_ConvertedValue/10);
		GUI_Delay(30);
	}
}

/*************************** End of file ****************************/
