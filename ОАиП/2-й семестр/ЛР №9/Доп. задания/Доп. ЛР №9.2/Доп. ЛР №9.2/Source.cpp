#include "List.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	Object List = Create();   // �������� ������
	Example(&List);

	do
	{
		switch (menu())
		{
		case 1:
			List.sortCourse();
			List.PrintList(print);
			break;
		case 2:
			List.sortSurname();
			List.PrintList(print);
			break;
		case 3:
			List.findAverage();
			break;
		case 4:
			List.findOldest();
			List.findYoungest();
			break;
		case 5:
			List.findBest();
			break;
		case 6: return 0;
		default: cout << "�� ����� ������������ ������!" << endl;
		}
	} while (1);

	return 0;
}

int menu()
{
	int ans;
	cout << "\n1. ������������� ��������� �� �����" << endl;
	cout << "2. ������������ ��������� �� �������" << endl;
	cout << "3. ����� ������� ���� ������ ������ �� ������� ��������" << endl;
	cout << "4. ����� ������ �������� � ������ �������� ���������" << endl;
	cout << "5. ����� ������� � ����� ������ ������������ �������� ������ ������" << endl;
	cout << "6. �����" << endl;
	cout << "$ ";
	cin >> ans;
	system("cls");
	return ans;
}

void Example(Object* List)
{
	static Student Student1 = { "����������", "�����", 2001, 1, 1, 4, 7, 6, 7, 9 };
	static Student Student2 = { "������", "��������", 2002, 2, 2, 4, 9, 4, 9, 8 };
	static Student Student3 = { "���������", "������", 2002, 3, 1, 6, 4, 4, 9, 4 };
	static Student Student4 = { "������", "�����", 2001, 2, 2, 4, 7, 4, 7, 5 };
	static Student Student5 = { "���������", "���", 2002, 3, 1, 9, 4, 4, 6, 7 };
	static Student Student6 = { "�������", "������", 2000, 1, 2, 9, 7, 8, 8, 4 };
	static Student Student7 = { "��������", "����", 2002, 2, 1, 5, 8, 4, 9, 9 };
	static Student Student8 = { "��������", "�����", 2002, 1, 2, 9, 5, 4, 9, 9 };
	static Student Student9 = { "���������", "�����", 2002, 3, 1, 4, 8, 4, 4, 9 };
	static Student Student10 = { "������", "�������", 2001, 3, 2, 5, 8, 4, 4, 4 };
	static Student Student11 = { "������", "������", 2002, 2, 1, 9, 4, 4, 7, 7 };
	static Student Student12 = { "������", "���", 2001, 1, 2, 9, 5, 4, 5, 4 };
	static Student Student13 = { "����������", "�����", 2002, 2, 1, 4, 4, 5, 4, 6 };
	static Student Student14 = { "��������", "������", 2001, 1, 2, 4, 6, 9, 5, 6 };
	static Student Student15 = { "��������", "��������", 2002, 3, 1, 9, 9, 6, 9, 8 };
	static Student Student16 = { "���������", "�������", 2003, 2, 2, 6, 7, 9, 4, 8 };
	static Student Student17 = { "����������", "�������", 2001, 3, 1, 4, 4, 4, 4, 4 };
	static Student Student18 = { "�������", "�����", 2001, 1, 2, 4, 9, 5, 4, 6 };
	static Student Student19 = { "�����", "���������", 2002, 1, 1, 8, 8, 7, 7, 4 };
	static Student Student20 = { "������", "�����", 2002, 2, 2, 5, 4, 5, 4, 4 };

	List->Insert(&Student1);
	List->Insert(&Student2);
	List->Insert(&Student3);
	List->Insert(&Student4);
	List->Insert(&Student5);
	List->Insert(&Student6);
	List->Insert(&Student7);
	List->Insert(&Student8);
	List->Insert(&Student9);
	List->Insert(&Student10);
	List->Insert(&Student11);
	List->Insert(&Student12);
	List->Insert(&Student13);
	List->Insert(&Student14);
	List->Insert(&Student15);
	List->Insert(&Student16);
	List->Insert(&Student17);
	List->Insert(&Student18);
	List->Insert(&Student19);
	List->Insert(&Student20);
}