struct Stack
{
	
	int data; //�������������� �������
	Stack* head;
	//������� �����
	Stack* next;
	//��������� �� ��������� �������

};
void show(Stack* myStk); //��������
int pop(Stack* myStk); //��������
void push(int x, Stack* myStk); //��������#pragma once
void delete3(Stack* myStk);