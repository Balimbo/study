#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	//2

	int p, q, n = 0;
	cout << "������� ����� �������� �� ������ ����" << endl;
	cin >> p;
	cout << "������� �������� ����� " << endl;
	cin >> q;
	while (p < 10000) {
		n++;
		p = p * 1.3;

		if (p > q) {
			cout << "������� ��������� ��������� ������ ����� " << n << " ����" << endl;
			cout << p << " ����� �������� � ����, ����� ����� ��������� ��������� ������ " << endl;
			break;
		}


	}
}