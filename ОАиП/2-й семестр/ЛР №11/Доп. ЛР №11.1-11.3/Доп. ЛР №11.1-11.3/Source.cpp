#include "Tree.h"

int menu();

int main()
{
	setlocale(0, "rus");
	int key, n;
	Tree* rc; char s[5], letter;
	Tree* Root = NULL;
	for (;;)
	{
		
		switch (menu())
		{
		case 1:  Root = makeTree(Root);	break;
		case 2:  cout << "\n������� ����: "; cin >> key;
			cout << "������� �����: "; cin >> s;
			insertElem(Root, key, s); break;
		case 3:  cout << "\n������� ����: ";  cin >> key;
			rc = search(Root, key);
			cout << "��������� �����= ";
			puts(rc->text); break;
		case 4:  cout << "\n������� ��������� ����: "; cin >> key;
			Root = delet(Root, key);  break;
		case 5:
			if (Root->key >= 0)
			{
				cout << "������ ��������� �� 90 ����. �����" << endl;
				view(Root, 0);
			}
			else
				cout << "������ ������\n";
			break;
		case 6:  cout << "\n������� �����: "; cin >> letter;
			n = count(Root, letter);
			cout << "���������� ����, ������������ � ����� " << letter;
			cout << " ����� " << n << endl; break;
		case 7:  delAll(Root);
			Root = NULL;
			cout << "������ �������" << endl;
			break;
		case 8:
			cout << endl << "���������� ����� � ������� ������� �����: " << countEven(Root, 0) << endl << endl;
			break;
		case 9:
			cout << endl << "���������� ����� � ������ �����: " << countRight(Root, 0) << endl << endl;
			break;
		case 10:
			cout << endl << "���������� ������� � ������: " << countLeaf(Root, 0) << endl << endl;
			break;
		case 11:
			exit(0);
			break;
		default:
			cout << "������� ������������ ������!" << endl;
			break;
		}
	}
	return 0;
}

int menu()
{
	int choice;
	cout << "1 - �������� ������\n";
	cout << "2 - ���������� ��������\n";
	cout << "3 - ����� �� �����\n";
	cout << "4 - �������� ��������\n";
	cout << "5 - ����� ������\n";
	cout << "6 - ������� ���������� ����\n";
	cout << "7 - ������� ������\n";
	cout << "8 - ������� ����� � ������� �������\n";
	cout << "9 - ������� ����� � ������ �����\n";
	cout << "10 - ������� ���������� ������� ������\n";
	cout << "11 - �����\n";
	cout << "$ ", cin >> choice;
	cout << "\n";
	return choice;
}