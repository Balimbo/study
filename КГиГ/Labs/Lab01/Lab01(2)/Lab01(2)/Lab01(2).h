
// Lab01(2).h : ������� ���� ��������� ��� ���������� Lab01(2)
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CLab012App:
// � ���������� ������� ������ ��. Lab01(2).cpp
//

class CLab012App : public CWinApp
{
public:
	CLab012App();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLab012App theApp;
