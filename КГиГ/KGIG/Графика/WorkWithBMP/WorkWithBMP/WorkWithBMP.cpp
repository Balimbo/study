
// WorkWithBMP.cpp : ���������� ��������� ������� ��� ����������.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "WorkWithBMP.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWorkWithBMPApp

BEGIN_MESSAGE_MAP(CWorkWithBMPApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CWorkWithBMPApp::OnAppAbout)
END_MESSAGE_MAP()


// �������� CWorkWithBMPApp

CWorkWithBMPApp::CWorkWithBMPApp()
{

	m_bHiColorIcons = TRUE;

	// TODO: �������� ��� ��������,
	// ��������� ���� ������ ��� ������������� � InitInstance
}

// ������������ ������ CWorkWithBMPApp

CWorkWithBMPApp theApp;


// ������������� CWorkWithBMPApp

BOOL CWorkWithBMPApp::InitInstance()
{
	CWinAppEx::InitInstance();

	// ����������� �������������
	// ���� ��� ����������� �� ������������ � ���������� ��������� ������
	// ��������� ������������ �����, ���������� ������� �� ����������
	// ���������� ��������� �������������, ������� �� ���������
	// �������� ������ �������, � ������� �������� ���������
	// TODO: ������� �������� ��� ������ �� ���-������ ����������,
	// �������� �� �������� �����������
	SetRegistryKey(_T("��������� ����������, ��������� � ������� ������� ����������"));

	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// ����� ������� ������� ����, ���� ��� ������� ����� ������ ����
	// �����, � ����� ������ ��� ��� ������ ��������� ���� ����������
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// �������� � ��������� ����� � ��� ���������
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);






	// ���� � ������ ���� ���� ���� ����������������, ������� ���������� � �������� ���
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	// ����� DragAcceptFiles ������ ��� ������� ��������
	//  � ���������� SDI ��� ������ ��������� ����� ProcessShellCommand
	return TRUE;
}


// ����������� ��������� CWorkWithBMPApp




// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ������ ����������� ����
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// ������� ���������� ��� ������� �������
void CWorkWithBMPApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CWorkWithBMPApp ��������� ������� �������� � ����������

void CWorkWithBMPApp::PreLoadState()
{
}

void CWorkWithBMPApp::LoadCustomState()
{
}

void CWorkWithBMPApp::SaveCustomState()
{
}

// ����������� ��������� CWorkWithBMPApp



