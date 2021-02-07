#include "stdafx.h"
#include "CubicSpline.h"
#include <cmath>

CubicSpline::CubicSpline(const double *x, const double *y, unsigned int n) : m_splines(NULL)
{
	x_BuildSpline(x, y, n);
}

CubicSpline::CubicSpline(CMatrix & x, CMatrix & y) : m_splines(NULL)
{
	unsigned int n = x.cols() * x.rows();

	double 
		*xTmp = new double[n],
		*yTmp = new double[n];

	for (unsigned int i = 0; i < n; ++i)
	{
		xTmp[i] = x(i);
		yTmp[i] = y(i);
	}

	x_BuildSpline(xTmp, yTmp, n);

	delete[] xTmp, yTmp;
}

CubicSpline::~CubicSpline()
{
	x_FreeMemory();
}

double CubicSpline::F(double x) const
{
	if (!m_splines)
		return std::numeric_limits<double>::quiet_NaN(); // ���� ������� ��� �� ��������� - ���������� NaN
 
	spline_tuple *s;
	if (x <= m_splines[0].x) // ���� x ������ ����� ����� x[0] - ���������� ������ ��-��� �������
		s = m_splines + 1;
	else if (x >= m_splines[m_n - 1].x) // ���� x ������ ����� ����� x[n - 1] - ���������� ��������� ��-��� �������
		s = m_splines + m_n - 1;
	else // ����� x ����� ����� ���������� ������� ����� - ���������� �������� ����� ������� ��-�� �������
	{
		unsigned int i = 0, j = m_n - 1;
		while (i + 1 < j)
		{
			unsigned int k = i + (j - i) / 2;
			if (x <= m_splines[k].x)
				j = k;
			else
				i = k;
		}
		s = m_splines + j;
	}
 
	double dx = (x - s->x);
	return s->a + (s->b + (s->c / 2. + s->d * dx / 6.) * dx) * dx; // ��������� �������� ������� � �������� ����� �� ����� ������� (� ��������, "�����" ���������� �������� �� ����� ������� ���, �� ���� �� ��� ��� ����, ��� �������)
}

void CubicSpline::BuildSpline(CMatrix & x, CMatrix & y, double xLeft, double xRight, double step)
{
	int k = (int)((xRight - xLeft) / step + 1);

	x.RedimMatrix(k);
	y.RedimMatrix(k);

	for (int i = 0; i < k; ++i)
	{
		x(i) = xLeft + i * step;
		y(i) = this->F(x(i));
	}
}

void CubicSpline::x_BuildSpline(const double *x, const double *y, unsigned int n)
{
	x_FreeMemory();
 
	m_n = n;
 
	// ������������� ������� ��������
	m_splines = new spline_tuple[n];
	for (unsigned int i = 0; i < n; ++i)
	{
		m_splines[i].x = x[i];
		m_splines[i].a = y[i];
	}
	m_splines[0].c = m_splines[n - 1].c = 0.;
 
	// ������� ���� ������������ ������������� �������� c[i] ������� �������� ��� ���������������� ������
	// ���������� ����������� ������������� - ������ ��� ������ ��������
	double *alpha = new double[n - 1];
	double *beta = new double[n - 1];
	alpha[0] = beta[0] = 0.;
	for (unsigned int i = 1; i < n - 1; ++i)
	{
		double h_i = x[i] - x[i - 1], h_i1 = x[i + 1] - x[i];
		double A = h_i;
		double C = 2. * (h_i + h_i1);
		double B = h_i1;
		double F = 6. * ((y[i + 1] - y[i]) / h_i1 - (y[i] - y[i - 1]) / h_i);
		double z = (A * alpha[i - 1] + C);
		alpha[i] = -B / z;
		beta[i] = (F - A * beta[i - 1]) / z;
	}
 
	// ���������� ������� - �������� ��� ������ ��������
	for (unsigned int i = n - 2; i > 0; --i)
		m_splines[i].c = alpha[i] * m_splines[i + 1].c + beta[i];
 
	// ������������ ������, ���������� ������������ ��������������
	delete[] beta;
	delete[] alpha;
 
	// �� ��������� ������������� c[i] ������� �������� b[i] � d[i]
	for (unsigned int i = n - 1; i > 0; --i)
	{
		double h_i = x[i] - x[i - 1];
		m_splines[i].d = (m_splines[i].c - m_splines[i - 1].c) / h_i;
		m_splines[i].b = h_i * (2. * m_splines[i].c + m_splines[i - 1].c) / 6. + (y[i] - y[i - 1]) / h_i;
	}
}

void CubicSpline::x_FreeMemory()
{
	if (m_splines)
	{
		delete[] m_splines;
		m_splines = NULL;
	}
}