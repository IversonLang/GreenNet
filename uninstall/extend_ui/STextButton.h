#pragma once
#include <core/Swnd.h>

namespace SOUI
{
class  STextButton : public SButton
{
	SOUI_CLASS_NAME(STextButton,L"textbtn")
public:
	STextButton();
	~STextButton();
protected:
    void OnPaint(IRenderTarget *pRT);


    //SOUI控件消息映射表
    SOUI_MSG_MAP_BEGIN()	
        MSG_WM_PAINT_EX(OnPaint)    //窗口绘制消息
	SOUI_MSG_MAP_END()

};

}