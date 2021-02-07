#pragma once
#include "CRectD.h"
#include "CMyPen.h"
#include "CMatrix.h"

class CPlot2D
{
public:
	CMatrix m_X;       // ������ ��� �������� x ���������
	CMatrix m_Y;       // ������ ��� �������� y ���������
	CMatrix m_K;       // ������� ��� ��������� ��������� �� ������� � �������
	CRect  m_Rw;       // �������� ������� � ����
	CRectD m_Rs;       // �������� ������� � ������������
	CMyPen m_PenLine;  // ���� ��� ��������� �����
	CMyPen m_PenAxis;  // ���� ��� ��������� ���� ���������
public:
	CPlot2D() { m_K.RedimMatrix(3,3); }
	void SetParams(CMatrix & x, CMatrix & y, CRect & rw);
	void SetWindowRect(CRect & rw);
	void SetPenLine(CMyPen & pLine);
	void SetPenAxis(CMyPen & pAxis);
	void Draw(CDC & dc, bool isDrawRect = true, bool isDrawGraph = true);
	void Draw1(CDC & dc, bool isDrawRect = true, bool isDrawGraph = true);
	static void SetMyMode(CDC & dc, CRectD & rs, CRect & rw);
};