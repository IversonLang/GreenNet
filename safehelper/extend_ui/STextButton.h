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


    //SOUI�ؼ���Ϣӳ���
    SOUI_MSG_MAP_BEGIN()	
        MSG_WM_PAINT_EX(OnPaint)    //���ڻ�����Ϣ
	SOUI_MSG_MAP_END()

};

}