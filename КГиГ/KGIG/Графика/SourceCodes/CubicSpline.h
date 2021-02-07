#pragma once
#include "CMatrix.h"
#include <limits>

class CubicSpline
{
private:
	struct spline_tuple // ���������, ����������� ������ �� ������ �������� �����
	{
		double a, b, c, d, x;
	};
 
	spline_tuple *m_splines; // ������
	unsigned int m_n;        // ���������� ����� �����

public:
	CubicSpline(const double *x, const double *y, unsigned int n);
	CubicSpline(CMatrix & x, CMatrix & y);
	~CubicSpline();

	double F(double x) const; // ����������������� ������� y = f(x)
	void BuildSpline(CMatrix & x, CMatrix & y, double xFrom, double xTo, double step);

private:

	void x_BuildSpline(  // ���������� �������
		const double *x,     // ���� �����, ������ ���� ����������� �� �����������, ������� ���� ���������
		const double *y,     // �������� ������� � ����� �����
		unsigned int n       // ���������� ����� �����
	);
	void x_FreeMemory();
};