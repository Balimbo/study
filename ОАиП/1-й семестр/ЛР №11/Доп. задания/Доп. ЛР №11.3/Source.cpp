// ������ ��� ������� �(n) � �(n).���������� � ��� ���������� ���������, ������� �������� t, � ������ �� ������ ������� ������, ������� ���������� �� ����������.
#include<iostream>;
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "ru");
	const int n = 10;
	int A[n], B[n], t, lessA = 0,lessB=0;
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

	cout << " ������� ����� t ", cin >> t;

	for (int i = 0; i < n; i++)
	{
		if (*(A + i) < t)
			lessA++;
		if (*(B + i) < t)
			lessB++;
	}

	cout << lessA << " - ���-�� ��������� ������� � ������� ����� t " << endl;
	cout << lessB << " - ���-�� ��������� ������� B ������� ����� t " << endl;

	if (lessA >= lessB)
	{
		for (int i = 0; i < n; i++)
			cout << *(A + i) << " ";
		cout << " - ������ A " << endl;

		for (int i = 0; i < n; i++)
			cout << *(B + i) << " ";
		cout << " - ������ B " << endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
			cout << *(B + i) << " ";
		cout << " - ������ B " << endl;

		for (int i = 0; i < n; i++)
			cout << *(A + i) << " ";
		cout << " - ������ A " << endl;
	}


	return 0;
}
