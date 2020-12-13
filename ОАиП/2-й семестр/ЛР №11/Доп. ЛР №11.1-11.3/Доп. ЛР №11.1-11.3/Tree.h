#pragma once
#include <iostream>
using namespace std;
struct Tree
{
	int key;			// ����
	char text[5];		// ������
	Tree* Left, * Right;
};

Tree* makeTree(Tree* Root);								// �������� ������
Tree* list(int i, char* s);								// �������� ������ ��������
Tree* insertElem(Tree* Root, int key, char* s);			// ���������� ������ ��������
Tree* search(Tree* n, int key);							// ����� �������� �� ����� 
Tree* delet(Tree* Root, int key);						// �������� �������� �� �����
void view(Tree* t, int level);							// ����� ������ 
int count(Tree* t, char letter);						// ������� ���������� ����
void delAll(Tree* t);									// ������� ������

int countEven(Tree* t, int level);						// ������� �12
int countRight(Tree* t, int level);						// ������� �15
int countLeaf(Tree* t, int level);						// ������� �7
