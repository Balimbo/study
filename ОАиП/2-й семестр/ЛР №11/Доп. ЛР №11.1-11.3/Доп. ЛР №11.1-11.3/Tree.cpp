#include "Tree.h"

int c = 0;         // ���������� ����
int counterLeaf = 0;

Tree* makeTree(Tree* Root)    //�������� ������
{
	int key; char s[5];
	cout << "����� ����� - ������������� �����\n\n";
	if (Root == NULL)	// ���� ������ �� �������
	{
		cout << "������� ���� �����: "; cin >> key;
		cout << "������� ����� �����: "; cin >> s;
		Root = list(key, s);	// ��������� ��������� �� ������
	}
	else
		cout << "������ ��� ����������" << endl;
	return Root;
}

Tree* list(int i, char* s)     //�������� ������ ��������
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	for (i = 0; i < 5; i++)
		*((t->text) + i) = *(s + i);
	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem(Tree* t, int key, char* s)  //���������� ������ ��������
{
	Tree* Prev = t;	     // Prev - ������� ����� �������
	int find = 0; // ������� ������
	if (!t)
	{
		cout << "������ �� ����������" << endl;
		return 0;
	}
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1;	   //����� ������ ���� ���������
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find)              //������� ����� � ������� Prev
	{
		t = list(key, s);           //��������� ����� ���� 
		if (key < Prev->key)  // � �������������� ���� 
			Prev->Left = t;    //������� �� ����� �����,
		else
			Prev->Right = t;   // ���� �� ������ 
	}
	return t;
}

Tree* delet(Tree* Root, int key)  //�������� �������� �� �����
{	// Del, Prev_Del - ��������� ������� � ��� ���������� ;
	// R, Prev_R - �������, �� ������� ���������� ���������, � ��� ��������; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//����� �������� � ��� �������� 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // ������� �� ������
	{
		puts("\n��� ������ �����");
		return Root;
	}
	if (Del->Right == NULL) // ����� �������� R ��� ������
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //����� ������ ������� �������� � ����� ���������
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // ������ ������� ��� ������ R � ��� �������� Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//�������� ����� � ������ ��� �� R
	else
		// ��������� R �������������� � �������� ���������� ����
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // �� ����� ����� 
		else
			Prev_Del->Right = R;	// �� ������ �����
	int tmp = Del->key;
	cout << "\n������ ������� � ������ " << tmp << endl;
	delete Del;
	return Root;
}

Tree* search(Tree* n, int key)  //����� �������� �� ����� 
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < (key, n->key))
			rc = search(n->Left, key);
		else
			if (key > (key, n->key))
				rc = search(n->Right, key);
	}
	else
		cout << "��� ������ ��������\n";
	return rc;
}

int count(Tree* t, char letter) //������� ���������� ����
{
	if (t)
	{
		count(t->Right, letter);
		if (*(t->text) == letter)
			c++;
		count(t->Left, letter);
	}
	return c;
}

void view(Tree* t, int level) //����� ������ 
{
	if (t)
	{
		view(t->Right, level + 1);	//����� ������� ���������
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->key;
		cout << tm << ' ';
		puts(t->text);
		view(t->Left, level + 1);	//����� ������ ���������
	}
}

void delAll(Tree* t) //������� ������
{
	if (t)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}

int countEven(Tree* t, int level)
{
	static int counter = 0;
	if (t)
	{
		countEven(t->Right, level + 1);
		if (t->key % 2 == 0)
			counter++;
		countEven(t->Left, level + 1);
	}
	return counter;


}

int countRight(Tree* t, int level)
{
	static int counter = 0;
	int temp;
	if (t)
	{
		counter++;
		cout << t << endl;
		countRight(t->Right, level + 1);
	}
	else
	{
		temp = counter;
		counter = 0;
		return temp;
	}
}

int countLeaf(Tree* t, int level)
{
	if (t)
	{
		countLeaf(t->Right, level + 1);
		if (t->Left == NULL && t->Right == NULL)
			counterLeaf++;
		countLeaf(t->Left, level + 1);
	}
	return counterLeaf;
}
