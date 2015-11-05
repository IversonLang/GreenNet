#include "stdafx.h"
#include "SProgressEx.h"

namespace SOUI
{

	SProgressEx::SProgressEx()
		: m_nMinValue(0)
		, m_nMaxValue(100)
		, m_nValue(0)
		, m_bShowPercent(FALSE)
		, m_pSkinBg(NULL)
		, m_pSkinPos(NULL)
		, m_bVertical(FALSE)
	{

	}


	CSize SProgressEx::GetDesiredSize(LPCRECT pRcContainer)
	{
		CSize szRet;
		SIZE sizeBg = m_pSkinBg->GetSkinSize();
		if(IsVertical())
		{
			szRet.cx = sizeBg.cx + 2 * m_style.m_nMarginX;
			if(m_layout.IsSpecifySize(PD_Y))
				szRet.cy=m_layout.GetSpecifySize(PD_Y);
			else
				szRet.cy = sizeBg.cy +2 * m_style.m_nMarginY;
		}else
		{
			szRet.cy = sizeBg.cy + 2 * m_style.m_nMarginY;
			if(m_layout.IsSpecifySize(PD_X))
				szRet.cx=m_layout.GetSpecifySize(PD_X);
			else
				szRet.cx = sizeBg.cx +2 * m_style.m_nMarginX;
		}
		return szRet;
	}

	void SProgressEx::OnPaint(IRenderTarget *pRT)
	{
		SPainter painter;

		BeforePaint(pRT, painter);

		SASSERT(m_pSkinBg && m_pSkinPos);

		CRect rcClient;
		GetClientRect(&rcClient);
		m_pSkinBg->Draw(pRT, rcClient, WndState_Normal);
		CRect rcValue=rcClient;

		if(IsVertical())
		{
			rcValue.bottom=rcValue.top+(int)(((__int64)rcValue.Height())*(m_nValue-m_nMinValue)/(__int64)(m_nMaxValue-m_nMinValue));
		}
		else
		{
			rcValue.right=rcValue.left+(int)(((__int64)rcValue.Width())*(m_nValue-m_nMinValue)/(__int64)(m_nMaxValue-m_nMinValue));
		}
		if(m_nValue>m_nMinValue)
		{
			m_pSkinPos->Draw(pRT, rcValue, WndState_Normal);
		}


		if (m_bShowPercent && !IsVertical())
		{
			SStringT strPercent;
			strPercent.Format(_T("%d%%"), (int)((m_nValue-m_nMinValue) * 100/(m_nMaxValue-m_nMinValue)));
			pRT->DrawText(strPercent, strPercent.GetLength(), GetWindowRect(), DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		}
		AfterPaint(pRT, painter);
	}

	int SProgressEx::OnCreate( void* )
	{
		if(!m_pSkinBg)  m_pSkinBg=GETBUILTINSKIN(IsVertical()?SKIN_SYS_VERT_PROG_BKGND:SKIN_SYS_PROG_BKGND);
		if(!m_pSkinPos) m_pSkinPos=GETBUILTINSKIN(IsVertical()?SKIN_SYS_VERT_PROG_BAR:SKIN_SYS_PROG_BAR);
		SASSERT(m_pSkinBg && m_pSkinPos);
		return (m_pSkinBg && m_pSkinPos)?0:-1;
	}

	BOOL SProgressEx::SetValue(int dwValue)
	{
		if(dwValue<m_nMinValue) dwValue =m_nMinValue;
		if(dwValue>m_nMaxValue) dwValue =m_nMaxValue;
		m_nValue=dwValue;

		Invalidate();
		return TRUE;
	}

	void SProgressEx::SetRange( int nMin,int nMax )
	{
		SASSERT(nMax>nMin);
		m_nMaxValue=nMax;
		m_nMinValue=nMin;
		if(m_nValue>m_nMaxValue) m_nValue=m_nMaxValue;
		if(m_nValue<nMin) m_nValue=m_nMinValue;
		Invalidate();
	}

	void SProgressEx::GetRange( int *pMin,int *pMax )
	{
		if(pMin) *pMin=m_nMinValue;
		if(pMax) *pMax=m_nMaxValue;
	}

}