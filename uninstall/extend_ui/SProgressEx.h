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
     * @brief    构造函数
     *
     * Describe  构造函数
     */
    SProgressEx();

    /**
     * SProgressEx::SetValue
     * @brief    设置进度条进度值
     * @param    int nValue  --  进度值 
     * @return   返回值是 TRUE -- 设置成功
     *
     * Describe  设置进度条进度值
     */  
    BOOL SetValue(int nValue);
    /**
     * SProgressEx::GetValue
     * @brief    获取进度值
     * @return   返回值是int 
     *
     * Describe  获取进度值
     */  
    int GetValue(){return m_nValue;}

    /**
     * SProgressEx::SetRange
     * @param    int nMin  --  进度最小值 
     * @param    int nMax  --  进度最大值      
     * @brief    设置进度值最小大值
     *
     * Describe  设置进度值
     */  
    void SetRange(int nMin,int nMax);
    /**
     * SProgressEx::GetRange
     * @param    int nMin  --  进度最小值 
     * @param    int nMax  --  进度最大值      
     * @brief    获取进度值最小大值
     *
     * Describe  获取进度值
     */  
    void GetRange(int *pMin,int *pMax);
    /**
     * SProgressEx::IsVertical
     * @brief    判断进度条是否为竖直状态
     * @return   返回值是 TRUE -- 竖直状态
     *
     * Describe  获取进度值
     */  
    BOOL IsVertical(){return m_bVertical;}
protected:
    /**
     * SProgressEx::GetDesiredSize
     * @brief    获取预期大小
     * @param    LPRECT pRcContainer  --  内容矩形框 
     * @return   返回值 CSize对象 
     *
     * Describe  根据矩形的大小，获取预期大小(解释有点不对)
     */
    virtual CSize GetDesiredSize(LPCRECT pRcContainer);

    void OnPaint(IRenderTarget *pRT);
    int  OnCreate(void*);

    int m_nMinValue; /**< 进度最小值 */
    int m_nMaxValue; /**< 进度最大值 */
    int m_nValue;    /**< 进度值 */

    BOOL m_bShowPercent; /**< 是否显示百分比 */
    BOOL m_bVertical;    /**< 是否竖直状态 */

    ISkinObj *m_pSkinBg;   /**< 背景资源 */
    ISkinObj *m_pSkinPos;  /**< 前景资源 */

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