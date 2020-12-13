#pragma once
#include <iostream>

struct List {
	List* prev = NULL;	// ��������� �� ���������� �������
	List* next = NULL;	// ��������� �� ��������� �������
	int data;			// ������
	bool isFirst = false;

private:
	void pushAfter(int data);

public:
	void pushBack(int data);	// ������ ������ � ����� ������
	void print();				// ����� ������ � �������
	void looping();				// ������������ ������
	void remove();				// �������� �������� ������
};