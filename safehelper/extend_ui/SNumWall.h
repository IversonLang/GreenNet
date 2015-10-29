#pragma once
#include <core/Swnd.h>

namespace SOUI
{
	// 数字墙
	class  SNumWall : public SWindow
	{
		SOUI_CLASS_NAME(SNumWall,L"numwall")
	public:
		SNumWall();
		~SNumWall();

		// 设置拦截网站个数
		BOOL SetHeadOffNum(int nCount);

	protected:
		void OnPaint(IRenderTarget *pRT);

		//SOUI控件消息映射表
		SOUI_MSG_MAP_BEGIN()	
			MSG_WM_PAINT_EX(OnPaint)   
			SOUI_MSG_MAP_END()

		SOUI_ATTRS_BEGIN()
			ATTR_INT(L"count", m_nNumCount,TRUE)
			ATTR_INT(L"spacing",m_nSpacing,TRUE)
			ATTR_INT(L"wallwidth",m_nWallWidth,TRUE)
			SOUI_ATTRS_END()

	private:
		// 检查数字时多少位
		int CheckNumLen();

		// 获取对应为数字
		int GetLocNum(int nLoc);

	private:
		int m_nNumCount;              // 数字墙个数
		int m_nSpacing;               // 数字墙间距
		int m_nWallWidth;             // 数字墙宽

		int m_nNums;                  // 数字个数
		int m_nHeadOffNum;            // 拦截网站个数
		COLORREF m_crItemBg;          // 背景色
		COLORREF m_crNumBg1;         

		CAutoRefPtr<IFont>  m_hFont;  // 字体样式
	};

}