
// WorkWithBMP.h : ������� ���� ��������� ��� ���������� WorkWithBMP
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CWorkWithBMPApp:
// � ���������� ������� ������ ��. WorkWithBMP.cpp
//

class CWorkWithBMPApp : public CWinAppEx
{
public:
	CWorkWithBMPApp();


// ���������������
public:
	virtual BOOL InitInstance();

// ����������

public:
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWorkWithBMPApp theApp;
