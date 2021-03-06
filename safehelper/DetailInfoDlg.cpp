// MainDlg.cpp : implementation of the CDetailInfoDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DetailInfoDlg.h"
#include "helper/SAdapterBase.h"

#include <dwmapi.h>
#include "extend_ui/STextButton.h"
#pragma comment(lib,"dwmapi.lib")


class CTestAdapterFix : public SAdapterBase
{
public:
	CTestAdapterFix()
	{
		m_nSel = -1;
	}
	virtual int getCount()
	{
		return 500;
	}   

	virtual void getView(int position, SWindow * pItem,pugi::xml_node xmlTemplate)
	{
		if(pItem->GetChildrenCount()==0)
		{
			pItem->InitFromXml(xmlTemplate);
		}

		STextButton *pText1 = (STextButton *)pItem->FindChildByName(L"textbtn1");
		STextButton *pText2 = (STextButton *)pItem->FindChildByName(L"textbtn2");

		pItem->SetUserData(position);
		pItem->GetEventSet()->subscribeEvent(EVT_CMD, Subscriber(&CTestAdapterFix::OnButtonClick,this));

		pText1->SetUserData(position);
		pText1->GetEventSet()->subscribeEvent(EVT_CMD,Subscriber(&CTestAdapterFix::OnButtonClick2,this));

		pText2->SetUserData(position);
		pText2->GetEventSet()->subscribeEvent(EVT_CMD,Subscriber(&CTestAdapterFix::OnButtonClick3,this));

		if (position == m_nSel)
		{
			if (pText1 != NULL)
				pText1->SetWindowText(L"拉入黑名单");
			if (pText2 != NULL)
				pText2->SetWindowText(L"取消拦截");
		}
		else
		{
			if (pText1 != NULL)
				pText1->SetWindowText(L"");
			if (pText2 != NULL)
				pText2->SetWindowText(L"");	
		}			
	}

	bool OnButtonClick(EventArgs *pEvt)
	{		
		SWindow *pItem = sobj_cast<SWindow>(pEvt->sender);
		if (pItem == NULL)
			return false;

		m_nSel = pItem->GetUserData();
		notifyDataSetChanged();		

		return true;
	}


	bool OnButtonClick2(EventArgs *pEvt)
	{		
		MessageBox(0, L"拉入黑名单", 0, 0);

		return true;
	}

	bool OnButtonClick3(EventArgs *pEvt)
	{		
		MessageBox(0, L"取消拦截", 0, 0);

		return true;
	}

private:
	int m_nSel;
};


CDetailInfoDlg::CDetailInfoDlg(LPCTSTR chContent) : SHostWnd(_T("LAYOUT:XML_DETAILWND"))
{
	m_chContent = (LPTSTR)chContent;
	m_bLayoutInited = FALSE;
}

CDetailInfoDlg::~CDetailInfoDlg()
{
	
}

int CDetailInfoDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	SetMsgHandled(FALSE);
	return 0;
}
 
BOOL CDetailInfoDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_bLayoutInited = TRUE;

	SStatic *pWnd = (SStatic *)FindChildByName(L"text_content");
	if (pWnd != NULL)
	{
		pWnd->SetWindowText(m_chContent);
	}

	//行高可变的列表
	SListView *pLstViewFlex = FindChildByName2<SListView>("lv_test_fix");
	if(pLstViewFlex)
	{
		IAdapter *pAdapter = new CTestAdapterFix;
		pLstViewFlex->SetAdapter(pAdapter);
		pAdapter->Release();
	}

	return 0;
}


//TODO:消息映射
void CDetailInfoDlg::OnClose()
{
	:: DestroyWindow(m_hWnd);
}

void CDetailInfoDlg::OnMinimize()
{
	// SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}


