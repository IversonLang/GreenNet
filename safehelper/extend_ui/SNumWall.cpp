#include "stdafx.h"
#include "SNumWall.h"
#include <math.h>

namespace SOUI
{

	SNumWall::SNumWall()
		:m_nNumCount(6),
		m_nSpacing(2),
		m_nWallWidth(18),
		m_nHeadOffNum(1234),
		m_nNums(0),
		m_crItemBg(0xffffffff),
		m_crNumBg1(0xa6a6a6ff)
	{
		FONTSTYLE fntStyle(0);
		fntStyle.byCharset = DEFAULT_CHARSET;
		fntStyle.fBold = 1;
		fntStyle.cSize = 3;     
		m_hFont = SFontPool::getSingleton().GetFont(fntStyle);
	}

	SNumWall::~SNumWall()
	{

	}

	void SNumWall::OnPaint( IRenderTarget *pRT )
	{
		// __super::OnPaint(pRT);

		SPainter painter;
		BeforePaint(pRT, painter);
		CRect rcWnd = GetWindowRect();
		int nLeft = rcWnd.left;

		CheckNumLen();

		for (int i=m_nNumCount; i>=1; i--)
		{
			// 绘制背景
			CRect rcItem(nLeft, rcWnd.top, nLeft+m_nWallWidth, rcWnd.bottom);
			CAutoRefPtr<IBrush> brush,oldBrush;
			pRT->CreateSolidColorBrush(m_crItemBg, &brush);			
			pRT->SelectObject(brush,(IRenderObj**)&oldBrush);
			pRT->FillRectangle(rcItem);
			pRT->SelectObject(oldBrush);

			// 获取对应数字
			int nNum = GetLocNum(i);
			SStringT strNum = L"0";
			if (nNum != 0)
			{
				TCHAR chNum[10];
				wsprintf(chNum, L"%d", nNum);
				strNum = chNum;
			}

			// 绘制字体
			COLORREF oldColor;
			COLORREF crTxt1 = RGBA(0x62,0xaa,0x01,255);
			COLORREF crTxt2 = RGBA(0xa6,0xa6,0xa6,255);
			if (m_nNums >= i)
				oldColor = pRT->SetTextColor(crTxt1);
			else
				oldColor = pRT->SetTextColor(crTxt2);

			CAutoRefPtr<IFont> oldFont;
			pRT->SelectObject(m_hFont,(IRenderObj**)&oldFont);
			pRT->DrawText(strNum, 1, rcItem,DT_VCENTER|DT_CENTER);
			pRT->SelectObject(oldFont);
			pRT->SetTextColor(oldColor);

			nLeft += (m_nSpacing + m_nWallWidth);
		}

		AfterPaint(pRT, painter);
	}

	BOOL SNumWall::SetHeadOffNum( int nCount )
	{
		if (nCount < 0)
			return FALSE;

		m_nHeadOffNum = nCount;
		Invalidate();
		return TRUE;
	}

	int SNumWall::CheckNumLen()
	{
		int nNum = m_nHeadOffNum;
		if (0 > nNum && nNum < 10)
		{
			m_nNums = 1;
			return 0;
		}
		else if (nNum <= 0)
		{
			m_nNums = 0;
			return 0;
		}
			
		m_nNums = 1;
		while (nNum >= 10)
		{
			m_nNums++;
			nNum = nNum / 10;
		}
		return 0;
	}

	int SNumWall::GetLocNum( int nLoc )
	{
		static int nsNum = m_nHeadOffNum;
		int nRe = 0;
		if (m_nNums < nLoc)
		{
			nsNum = m_nHeadOffNum;
			return nRe;
		}
		
		int nNum = pow(10.0, nLoc-1);
		nRe = nsNum / nNum;
		
		if (nLoc != 1)
			nsNum = nsNum - (nRe * nNum);
		else
			nsNum = m_nHeadOffNum;

		return nRe;
	}

	

}

