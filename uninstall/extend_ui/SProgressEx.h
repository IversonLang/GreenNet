#pragma once
#include <core/Swnd.h>

namespace SOUI
{
	class  SProgressEx : public SWindow
	{
		SOUI_CLASS_NAME(SProgressEx, L"progressex")
public:
    /**
     * SProgressEx::SProgressEx
     * @brief    ���캯��
     *
     * Describe  ���캯��
     */
    SProgressEx();

    /**
     * SProgressEx::SetValue
     * @brief    ���ý���������ֵ
     * @param    int nValue  --  ����ֵ 
     * @return   ����ֵ�� TRUE -- ���óɹ�
     *
     * Describe  ���ý���������ֵ
     */  
    BOOL SetValue(int nValue);
    /**
     * SProgressEx::GetValue
     * @brief    ��ȡ����ֵ
     * @return   ����ֵ��int 
     *
     * Describe  ��ȡ����ֵ
     */  
    int GetValue(){return m_nValue;}

    /**
     * SProgressEx::SetRange
     * @param    int nMin  --  ������Сֵ 
     * @param    int nMax  --  �������ֵ      
     * @brief    ���ý���ֵ��С��ֵ
     *
     * Describe  ���ý���ֵ
     */  
    void SetRange(int nMin,int nMax);
    /**
     * SProgressEx::GetRange
     * @param    int nMin  --  ������Сֵ 
     * @param    int nMax  --  �������ֵ      
     * @brief    ��ȡ����ֵ��С��ֵ
     *
     * Describe  ��ȡ����ֵ
     */  
    void GetRange(int *pMin,int *pMax);
    /**
     * SProgressEx::IsVertical
     * @brief    �жϽ������Ƿ�Ϊ��ֱ״̬
     * @return   ����ֵ�� TRUE -- ��ֱ״̬
     *
     * Describe  ��ȡ����ֵ
     */  
    BOOL IsVertical(){return m_bVertical;}
protected:
    /**
     * SProgressEx::GetDesiredSize
     * @brief    ��ȡԤ�ڴ�С
     * @param    LPRECT pRcContainer  --  ���ݾ��ο� 
     * @return   ����ֵ CSize���� 
     *
     * Describe  ���ݾ��εĴ�С����ȡԤ�ڴ�С(�����е㲻��)
     */
    virtual CSize GetDesiredSize(LPCRECT pRcContainer);

    void OnPaint(IRenderTarget *pRT);
    int  OnCreate(void*);

    int m_nMinValue; /**< ������Сֵ */
    int m_nMaxValue; /**< �������ֵ */
    int m_nValue;    /**< ����ֵ */

    BOOL m_bShowPercent; /**< �Ƿ���ʾ�ٷֱ� */
    BOOL m_bVertical;    /**< �Ƿ���ֱ״̬ */

    ISkinObj *m_pSkinBg;   /**< ������Դ */
    ISkinObj *m_pSkinPos;  /**< ǰ����Դ */

    SOUI_MSG_MAP_BEGIN()
        MSG_WM_PAINT_EX(OnPaint)
        MSG_WM_CREATE(OnCreate)
    SOUI_MSG_MAP_END()

    SOUI_ATTRS_BEGIN()
        ATTR_SKIN(L"bkgndSkin", m_pSkinBg, TRUE)
        ATTR_SKIN(L"posSkin", m_pSkinPos, TRUE)
        ATTR_INT(L"min", m_nMinValue, FALSE)
        ATTR_INT(L"max", m_nMaxValue, FALSE)
        ATTR_INT(L"value", m_nValue, FALSE)
        ATTR_UINT(L"vertical", m_bVertical, FALSE)
        ATTR_UINT(L"showPercent", m_bShowPercent, FALSE)
    SOUI_ATTRS_END()

};

}