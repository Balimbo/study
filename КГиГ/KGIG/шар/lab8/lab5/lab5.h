
// lab5.h : ������� ���� ��������� ��� ���������� lab5
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// Clab5App:
// � ���������� ������� ������ ��. lab5.cpp
//

class Clab5App : public CWinApp
{
public:
	Clab5App();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Clab5App theApp;
