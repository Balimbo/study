#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	//4
	int n;
	float p, sum = 0, s;
	cout << "������� ���������� ���; n = ";
	cin >> n;
	cout << "������� ������� ���������� p = ";
	cin >> p;
	p = p / 100;
	for (int i = 1; i <= n; i++) {
		cout << "��������� ������������ �� " << i << " ��� = ";
		cin >> s;
		sum += s;
		sum *= p;
	}
	cout << "����� ��������� ������������ ������������ = " << sum;
}