
// ChildView.h : ��������� ������ CChildView
//


#pragma once


// ���� CChildView

class CChildView : public CWnd
{
// ��������
public:
	CChildView();

	vector<CMatrix> arr;
	CMatrix V = CMatrix(3);;
	ControllerCMatrix controller;
// ��������
public:

// ��������
public:

// ���������������
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ����������
public:
	virtual ~CChildView();

	// ��������� ������� ����� ���������
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTestMatrix();
	afx_msg void OnTestFunctions();
};

