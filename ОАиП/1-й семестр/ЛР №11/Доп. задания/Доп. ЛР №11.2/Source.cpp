//���� ������� A � B, ��������� �� n ���������. ��������� ������ S, ������ ������� �������� ����� ����� ��������������� ��������� �������� A � B.
#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "ru");
	const int n = 10;
	int A[n], B[n], S[n];
	for (int i = 0; i < n; i++)
	{
		*(A + i) = 0 + rand() % 20;
		cout << *(A + i) << " ";
	}
	cout << " - ������ A " << endl;

	for (int i = 0; i < n; i++)
	{
		*(B + i) = 0 + rand() % 20;
		cout << *(B + i) << " ";
	}
	cout << " - ������ B " << endl;
	
	for (int i = 0; i < n; i++)
	{
		*(S + i) = *(A + i) + *(B + i);
		cout << *(S + i) << " ";

	}
	cout << " - ������ S " << endl;


	return 0;
}