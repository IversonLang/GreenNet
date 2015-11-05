#include "stdafx.h"
#include "SAnimateImgWndEx.h"

namespace SOUI
{

	SAnimateImgWndEx::SAnimateImgWndEx()
		:m_pSkin(NULL)
		,m_iCurFrame(0)
		,m_nSpeed(50)
		,m_bAutoStart(TRUE)
		,m_bPlaying(FALSE)
		,m_iTimeFrame(0)
	{
		m_bMsgTransparent=TRUE;
	}

	void SAnimateImgWndEx::OnPaint(IRenderTarget *pRT)
	{
		if (m_pSkin)
			m_pSkin->Draw(pRT, GetWindowRect(), m_iCurFrame);
	}


	void SAnimateImgWndEx::Start()
	{
		if(!m_bPlaying)
		{
			if(IsVisible(TRUE)) GetContainer()->RegisterTimelineHandler(this);
			m_bPlaying=TRUE;
		}
	}

	void SAnimateImgWndEx::Stop()
	{
		if(m_bPlaying)
		{
			if(IsVisible(TRUE)) GetContainer()->UnregisterTimelineHandler(this);
			m_bPlaying=FALSE;
		}
	}

	void SAnimateImgWndEx::OnDestroy()
	{
		Stop();
	}

	CSize SAnimateImgWndEx::GetDesiredSize(LPCRECT pRcContainer)
	{
		CSize szRet;
		if(m_pSkin) szRet=m_pSkin->GetSkinSize();
		return szRet;
	}

	void SAnimateImgWndEx::OnShowWindow( BOOL bShow, UINT nStatus )
	{
		__super::OnShowWindow(bShow,nStatus);
		if(!bShow)
		{
			if(IsPlaying()) GetContainer()->UnregisterTimelineHandler(this);
		}else
		{
			if(IsPlaying()) GetContainer()->RegisterTimelineHandler(this);
			else if(m_bAutoStart) Start();
		}
	}

	void SAnimateImgWndEx::OnNextFrame()
	{
		if(!m_pSkin) GetContainer()->UnregisterTimelineHandler(this);
		else
		{
			if(m_iTimeFrame > (m_nSpeed/10)) m_iTimeFrame=0;
			if(m_iTimeFrame==0)
			{
				int nStates=m_pSkin->GetStates();
				m_iCurFrame++;
				m_iCurFrame%=nStates;
				Invalidate();
			}
			m_iTimeFrame++;
		}
	}
}