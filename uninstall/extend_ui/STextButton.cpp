#include "stdafx.h"
#include "STextButton.h"

namespace SOUI
{

STextButton::STextButton()
{

}

STextButton::~STextButton()
{

}

void STextButton::OnPaint( IRenderTarget *pRT )
{
	SPainter painter;

	BeforePaint(pRT, painter);

	CRect rcText;
	GetTextRect(rcText);
	DrawText(pRT,m_strText, m_strText.GetLength(), rcText, GetTextAlign());

	//draw focus rect
	if(IsFocused())
	{
		DrawFocus(pRT);
	}

	AfterPaint(pRT, painter);
}


}