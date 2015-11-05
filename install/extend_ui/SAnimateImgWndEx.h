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
		* @brief    ���캯��
		*
		* Describe  ���캯��
		*/
		SAnimateImgWndEx();

		/**
		* SAnimateImgWnd::~SAnimateImgWnd
		* @brief    ��������
		*
		* Describe  ��������
		*/    
		virtual ~SAnimateImgWndEx() {}

		/**
		* SAnimateImgWnd::Start
		* @brief    ��������
		*
		* Describe  ��������
		*/  
		void Start();
		/**
		* SAnimateImgWnd::Stop
		* @brief    ֹͣ����
		*
		* Describe  ֹͣ����
		*/  
		void Stop();

		/**
		* SAnimateImgWnd::IsPlaying
		* @brief    �ж϶�������״̬
		* @return   ����ֵ�Ƕ���״̬ TRUE -- ������
		*
		* Describe  �ж϶�������״̬
		*/  
		BOOL IsPlaying(){return m_bPlaying;}
	protected:
		/**
		* SAnimateImgWnd::GetDesiredSize
		* @brief    ��ȡԤ�ڴ�С
		* @param    LPRECT pRcContainer  --  ���ݾ��ο� 
		* @return   ����ֵ CSize���� 
		*
		* Describe  ���ݾ��εĴ�С����ȡԤ�ڴ�С(�����е㲻��)
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
		ISkinObj *m_pSkin;        /**< ��ʱ���� */
		int           m_nSpeed;       /**< �ٶ� */
		int           m_iCurFrame;    /**< ��ǰ֡ */
		BOOL          m_bAutoStart;   /**< �Ƿ��Զ����� */
		BOOL          m_bPlaying;     /**< �Ƿ������� */
		int           m_iTimeFrame;   /**< OnNextFrame��ִ�д��� */
	};
}
