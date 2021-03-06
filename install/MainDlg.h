// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream>

enum
{
	PERCENT_TIMER = 1,
};


class CMainDlg : public SHostWnd
{
public:
	CMainDlg();
	~CMainDlg();

	void OnClose();
	void OnViewFile();
	void OnInstall();
	void OnBtnTiyan();

	void OnBtnMsgBox();
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);
	void OnTimer(UINT_PTR idEvent);

protected:
	//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_install", OnInstall)
		EVENT_NAME_COMMAND(L"view_install", OnViewFile)
		EVENT_NAME_COMMAND(L"btn_tiyan", OnBtnTiyan)
		EVENT_MAP_END()
	//HostWnd真实窗口消息处理
	BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
	    MSG_WM_TIMER(OnTimer)  

		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

private:
	void InitUI();

private:
	SStatic *m_pWord;
	std::wstring m_strInstallPath;
	BOOL			m_bLayoutInited;
};
