//14
//���� ��� ������� x � y.����� ���������� ���������� ��������� � ���� ��������, �.�.���������� ��� x[i] = y[j] ��� ��������� i � j.

#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "ru");
	const int n = 10;
	int x[n], y[n], equal = 0;
	for (int i = 0; i < n; i++)
	{
		*(x + i) = 0 + rand() % 20;
		cout << *(x + i) << " ";
	}
	cout << " - ������ �" << endl;

	for (int i = 0; i < n; i++)
	{
		*(y + i) = 0 + rand() % 20;
		cout << *(y + i) << " ";
	}
	cout << " - ������ y" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (*(x + i) == *(y + j))
				equal++;

		}

	}
	cout << "����� ������ ��������� ���� �������� ����� " << equal << endl;
	



	return 0;
}