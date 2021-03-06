// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainDlg.h"
#include "extend_ui/FileHelper.h"

#include <dwmapi.h>
#include <shlobj.h>
#include "extend_ui/SEdit2.h"
#pragma comment(lib,"dwmapi.lib")

#define PROC_FILE  "safehelper"	// 程序安装节点

CMainDlg::CMainDlg() : SHostWnd(_T("LAYOUT:XML_MAINWND"))
{
	m_bLayoutInited = FALSE;
	m_strInstallPath = L"";
	m_pWord = NULL;
}

CMainDlg::~CMainDlg()
{
}

int CMainDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	SetMsgHandled(FALSE);
	return 0;
}

BOOL CMainDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_bLayoutInited = TRUE;
	InitUI();
	return 0;
}

std::wstring s2ws(const char* s)
{
	int nStrLen = strlen(s);
	std::wstring ws;

	ws.resize(nStrLen);
	MultiByteToWideChar(CP_ACP,0,s,nStrLen,(WCHAR*)ws.c_str(),ws.size());
	return ws;
}

void CMainDlg::InitUI()
{
	// 这里只是做一个测试  到时候需要判断给定目录是否存在
	std::string strPath = "D:\\Program Files\\"PROC_FILE"\\";

	m_strInstallPath = s2ws(strPath.c_str());
	SEdit2 *pEdit = FindChildByName2<SEdit2>(L"edit_dir");
	if (pEdit != NULL)
	{
		pEdit->SetWindowText(m_strInstallPath.c_str());
	}
	m_pWord = (SStatic *)FindChildByName(L"percent_text");
}

void CMainDlg::OnClose()
{
	PostMessage(WM_QUIT);
}

void CMainDlg::OnViewFile()
{
	TCHAR szPathName[MAX_PATH]; 
	BROWSEINFO bInfo = {0};  
	LPITEMIDLIST lpDlist;  

	bInfo.hwndOwner = GetForegroundWindow();
	bInfo.lpszTitle = L"浏览文件夹```选择文件夹";
	bInfo.ulFlags=BIF_RETURNONLYFSDIRS |BIF_USENEWUI/*包含一个编辑框 用户可以手动填写路径 对话框可以调整大小之类的..*/|  
		BIF_UAHINT/*带TIPS提示*/ |BIF_NONEWFOLDERBUTTON /*不带新建文件夹按钮*/;  	
	lpDlist = SHBrowseForFolder(&bInfo);  
	if (lpDlist != NULL)
	{  
		SHGetPathFromIDList(lpDlist, szPathName); 
		SEdit2 *pEdit = FindChildByName2<SEdit2>(L"edit_dir");
		if (pEdit != NULL)
		{
			pEdit->SetWindowText(szPathName);
		}
	}
}

void CMainDlg::OnInstall()
{
	STabCtrl *pTabCtrl = FindChildByName2<STabCtrl>(L"tab_main");
	if (pTabCtrl) 
	{
		pTabCtrl->SetCurSel(L"install");
		CSimpleWnd::SetTimer(PERCENT_TIMER, 500);
	}
}

void CMainDlg::OnTimer( UINT_PTR idEvent )
{
	static int nPercent = 0;
	if (idEvent == PERCENT_TIMER)
	{	
		nPercent += 10;		
		char chValue[10];
		sprintf(chValue, "%d", nPercent);
		std::wstring wzPercent = s2ws(chValue);
		wzPercent += std::wstring(L"%");
		m_pWord->SetWindowTextW(wzPercent.c_str());
		if (nPercent == 100)
		{
			::KillTimer(m_hWnd, PERCENT_TIMER);
			STabCtrl *pTabCtrl = FindChildByName2<STabCtrl>(L"tab_main");
			if (pTabCtrl) 
			{
				pTabCtrl->SetCurSel(L"install_over");	
			}
		}
	}
	SetMsgHandled(FALSE);
}

void CMainDlg::OnBtnTiyan()
{
	MessageBox(0, L"立即体验", L"立即体验", 0);
	PostMessage(WM_QUIT);
}
