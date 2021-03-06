// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once

class CBlacklistDlg : public SHostWnd
{
public:
	CBlacklistDlg(LPCTSTR chContent);
	~CBlacklistDlg();

	void OnClose();
	void OnBtnAdd();

	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);


protected:
	//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_detail_close", OnClose)
		EVENT_NAME_COMMAND(L"blacklist_add_text", OnBtnAdd)
		EVENT_MAP_END()
	//HostWnd真实窗口消息处理
	BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)


		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
private:
	BOOL			m_bLayoutInited;
	LPTSTR m_chContent;
};
