#pragma once
#include <core/Swnd.h>

namespace SOUI
{
	// ����ǽ
	class  SNumWall : public SWindow
	{
		SOUI_CLASS_NAME(SNumWall,L"numwall")
	public:
		SNumWall();
		~SNumWall();

		// ����������վ����
		BOOL SetHeadOffNum(int nCount);

	protected:
		void OnPaint(IRenderTarget *pRT);

		//SOUI�ؼ���Ϣӳ���
		SOUI_MSG_MAP_BEGIN()	
			MSG_WM_PAINT_EX(OnPaint)   
			SOUI_MSG_MAP_END()

		SOUI_ATTRS_BEGIN()
			ATTR_INT(L"count", m_nNumCount,TRUE)
			ATTR_INT(L"spacing",m_nSpacing,TRUE)
			ATTR_INT(L"wallwidth",m_nWallWidth,TRUE)
			SOUI_ATTRS_END()

	private:
		// �������ʱ����λ
		int CheckNumLen();

		// ��ȡ��ӦΪ����
		int GetLocNum(int nLoc);

	private:
		int m_nNumCount;              // ����ǽ����
		int m_nSpacing;               // ����ǽ���
		int m_nWallWidth;             // ����ǽ��

		int m_nNums;                  // ���ָ���
		int m_nHeadOffNum;            // ������վ����
		COLORREF m_crItemBg;          // ����ɫ
		COLORREF m_crNumBg1;         

		CAutoRefPtr<IFont>  m_hFont;  // ������ʽ
	};

}