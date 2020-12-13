#include <iostream>
#include "myStack.h"
using namespace std;
void push(int x, Stack* myStk)   //���������� �������� � � ����	
{
	Stack* e = new Stack;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� v 
	e->next = myStk->head;   //������� ������� �� ��������� ������� 
	myStk->head = e;         //����� ������� �� ������� ������
}
int pop(Stack* myStk)   //���������� (��������) �������� �� �����
{
	if (myStk->head == NULL)
	{
		cout << "���� ����!" << endl;
		return -1;               //���� ���� ���� - ������� -1 
	}
	else
	{
		Stack* e = myStk->head;				//� - ���������� ��� �������� ������ ��������
		int a = myStk->head->data;			//������ ����� �� ���� data � ���������� a 
		myStk->head = myStk->head->next;	//������� �������
		delete e;							//�������� ��������� ����������
		return a;							//������� �������� ���������� ��������
	}
}
void show(Stack* myStk)    //����� �����
{
	Stack* e = myStk->head;    //����������� ��������� �� ������� �����
	int a;
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (e != NULL)
	{
		a = e->data;
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}

void clear(Stack* stk) {
	Stack* tmp = stk->head;
	while (tmp != NULL)
	{
		stk = tmp->next;
		delete[] tmp;
		tmp = stk;
	}
}

void del(Stack* myStk) {
	Stack* e = myStk->head;    //����������� ��������� �� ������� �����
	int a;
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (e != NULL)
	{
		a = e->data;
		if (a < 0 && e->head != NULL)
		{
			e->head->next = e->next;//������ �������
			delete[] e;
			cout << "������� ������� ������!" << endl;
			break;
		}
		else if (a < 0 && e->head == NULL)
		{
			myStk = e->next;
			e->next->head == NULL;
			delete[] e;
		}
		e = e->next;
	}
	cout << endl;
}
