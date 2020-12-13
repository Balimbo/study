
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>
using namespace std;

int b;
// �������� ������� � ������ �� � ���� "Matrix.txt" 
int CreateF1()
{
	errno_t err,err2;
	int matrix[255][255], matrix2[255];
	FILE* fp;
	err = fopen_s(&fp, "Matrix.txt", "w");
	if (err != 0)
	{
		perror("���������� ������� ����\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < b; j++)
		{
			matrix[i][j] = rand() % 20;
			fprintf(fp, "%d\t", *(*(matrix + i) + j));

		}
		fprintf(fp, "\n");
	}
	fclose(fp);
	FILE* fn;
	err2 = fopen_s(&fn, "Matrix2.txt", "w");
	
	if (err2 != 0)
	{
		perror("���������� ������� ����2\n");
		return EXIT_FAILURE;
	}
	
	for (int i = 0; i < b; i++)
	{
		
			matrix2[i]= rand() % 20;
			fprintf(fn, "%d\t", *(matrix2 + i));

		
		fprintf(fn, "\n");
		
	
	}
	printf("%s", "������� �������� � ���� 'Matrix.txt'\n");
	fclose(fn);


}

//������ ������� �� ����� "Matrix.txt" � ���� "Result.txt" 
int RecordF1()
{
	errno_t errM;
	errno_t errR;
	int arr[255][255] = { 0 }, arr2[255] = { 0 }, arr3[255] = { 0 };
	int k = 0;

	FILE* fr;
	FILE* fm;

	errM = fopen_s(&fm, "Matrix.txt", "r");
	if (errM != 0)
	{
		perror("���������� ������� ����3\n");
		return EXIT_FAILURE;
	}

	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < b; j++)
			fscanf_s(fm, "%d", &arr[i][j]);

	}
	fclose(fm);

	
	FILE* fn;

	errM = fopen_s(&fn, "Matrix2.txt", "r");
	if (errM != 0)
	{
		perror("���������� ������� ����5\n");
		return EXIT_FAILURE;
	}

	for (int i = 0; i < b; i++){
			fscanf_s(fn, "%d", &arr2[i]);
	}
	fclose(fn);
	FILE* fb;
	errR = fopen_s(&fb, "Result.txt", "w");
	if (errR != 0)
	{
		perror("���������� ������� ����\n");
		return EXIT_FAILURE;
	}
	
	int n = 0;
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < b; j++){
			arr3[n] += (arr[i][j]) * (arr2[j]);
		}
		n++;
	}

	for (int i = 0; i < b; i++)
	{
		fprintf(fb, "%d\t", arr3[i]);
	}

	printf("%s", "��������� ��������� ������ ������� � ���� 'Result.txt'\n");
	fclose(fb);


}


	//������� 2
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>
using namespace std;


// �������� ������� � ������ �� � ���� "Matrix.txt" 
int CreateF2()
{
	errno_t err, err2;
	int matrix[255];
	FILE* fp;
	err = fopen_s(&fp, "Matrix.txt", "w");
	if (err != 0)
	{
		perror("���������� ������� ����\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < b; i++)
	{

		matrix[i] = rand() % 20;
		fprintf(fp, "%d\t", *(matrix + i));
		cout << matrix[i] << ' ';

		fprintf(fp, "\n");
	}
	fclose(fp);
}

int RecordF2()
{
	errno_t errM;
	errno_t errR;
	int arr[255] = { 0 };
	int k = 0;

	FILE* fr;
	FILE* fm;
	FILE* fn;

	errM = fopen_s(&fn, "Matrix.txt", "r");
	if (errM != 0)
	{
		perror("���������� ������� ����5\n");
		return EXIT_FAILURE;
	}

	for (int i = 0; i < b; i++) {
		fscanf_s(fn, "%d", &arr[i]);
	}
	fclose(fn);



	FILE* fb;
	errR = fopen_s(&fb, "Result.txt", "w");
	if (errR != 0)
	{
		perror("���������� ������� ����\n");
		return EXIT_FAILURE;
	}

	int r = b;
	for (int i = 1; i <= r; i++)
	{
		int k = r;
		while (--k >= i && (i % 2))
			arr[k + 1] = arr[k];

		if (i % 2)
		{
			arr[i] = -1; r++;
		}
	}
	cout << "\n";
	int t = -1, j = r, i = 0;
	while (j >= 0 && t <= r)
		arr[t += 2] = arr[j -= 2];
	for (i = 0; i < b; i++) cout << arr[i] << " ";

	for (int i = 0; i < b; i++)
	{
		fprintf(fb, "%d\t", arr[i]);
	}

	printf("%s", "\n��������� ��������� ������ ������� � ���� 'Result.txt'");
	fclose(fb);


}

int main() {
	int n;
	setlocale(LC_ALL, "");
	cout << "������� ����� �������: ",cin >> n;
	switch (n) {
		case 1:
				cout << "������� ������ �������: ", cin >> b;
				CreateF1();
				RecordF1();
				break;

		case 2:
			cout << "������� ������ �������: ", cin >> b;
			CreateF2();
			RecordF2();
			break;
		default: cout << "��������, ������ ������� � ���� ���( ";
			break;
	}

	
}
