#pragma once
#include "core/SWnd.h"
#include "core/Accelerator.h"
namespace SOUI
{
	class SAnimateImgWndEx : public SWindow, public ITimelineHandler
	{
		SOUI_CLASS_NAME({, L"animateimgex")
	public:    
		/**
		* SAnimateImgWnd::SAnimateImgWnd
		* @brief    构造函数
		*
		* Describe  构造函数
		*/
		SAnimateImgWndEx();

		/**
		* SAnimateImgWnd::~SAnimateImgWnd
		* @brief    析构函数
		*
		* Describe  析构函数
		*/    
		virtual ~SAnimateImgWndEx() {}

		/**
		* SAnimateImgWnd::Start
		* @brief    启动动画
		*
		* Describe  启动动画
		*/  
		void Start();
		/**
		* SAnimateImgWnd::Stop
		* @brief    停止动画
		*
		* Describe  停止动画
		*/  
		void Stop();

		/**
		* SAnimateImgWnd::IsPlaying
		* @brief    判断动画运行状态
		* @return   返回值是动画状态 TRUE -- 运行中
		*
		* Describe  判断动画运行状态
		*/  
		BOOL IsPlaying(){return m_bPlaying;}
	protected:
		/**
		* SAnimateImgWnd::GetDesiredSize
		* @brief    获取预期大小
		* @param    LPRECT pRcContainer  --  内容矩形框 
		* @return   返回值 CSize对象 
		*
		* Describe  根据矩形的大小，获取预期大小(解释有点不对)
		*/
		virtual CSize GetDesiredSize(LPCRECT pRcContainer);
		virtual void OnNextFrame();

		void OnPaint(IRenderTarget *pRT);

		void OnShowWindow(BOOL bShow, UINT nStatus);
		void OnDestroy();

		SOUI_MSG_MAP_BEGIN()
			MSG_WM_PAINT_EX(OnPaint)
			MSG_WM_DESTROY(OnDestroy)
			MSG_WM_SHOWWINDOW(OnShowWindow)
			SOUI_MSG_MAP_END()

			SOUI_ATTRS_BEGIN()
			ATTR_SKIN(L"skin", m_pSkin, TRUE)
			ATTR_UINT(L"speed", m_nSpeed, FALSE)
			ATTR_UINT(L"autoStart", m_bAutoStart, FALSE)
			SOUI_ATTRS_END()

	protected:
		ISkinObj *m_pSkin;        /**< 暂时不祥 */
		int           m_nSpeed;       /**< 速度 */
		int           m_iCurFrame;    /**< 当前帧 */
		BOOL          m_bAutoStart;   /**< 是否自动启动 */
		BOOL          m_bPlaying;     /**< 是否运行中 */
		int           m_iTimeFrame;   /**< OnNextFrame的执行次数 */
	};
}
