#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int proverka(char s[])
{
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] < '0' || s[i] > '9')
			return 1;
	}
	return 0;
}

void getArr(int n, int m, int* arr[])
{
	while (true)
	{
		char c[100];
		int k;

		printf("\nНажмите соответствующие цифры, чтобы выбрать нужное действие:\n");
		printf(" 1)заполнение массива случайными числами\n");
		printf(" 2)заполнение массива вручную\n");
		gets_s(c);

		if (!proverka(c))
		{
			k = atoi(c);
			if (k > 0 && k < 3)
			{
				if (k == 1)
				{
					for (int i = 0; i < n; i++)
						for (int j = 0; j < m; j++)
							arr[i][j] = rand() % 5 + 1;
					printf("\nМассив заполнен...\n");
					return;
				}
				else
				{
					char cc[100];

					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
						{
							printf("Введите оценку %d студента по %d предмету: ", i + 1, j + 1);
							gets_s(cc);

							if (!proverka(cc) && atoi(cc) < 6 && atoi(cc) > 0)
								arr[i][j] = atoi(cc);
							else
							{
								printf("\nВведённое значение неверно, попробуйте ещё раз...\n\n");
								j--;
							}
						}
					}
					printf("\nМассив заполнен...\n");
					return;
				}
			}
			else printf("\nВведённое значение неверно, попробуйте ещё раз...\n\n");
		}
		else printf("\nВведённое значение неверно, попробуйте ещё раз...\n\n");
	}

}
void solution(int n, int m, int* arr[], int r)
{
	if (arr[0][0] == 0)
	{
		printf("Массив пуст, пожалуйста, заполните его...\n");
		return;
	}

	int sum = 0, res = -1, id = 0;
	int *arg = new int[n]();
	int *arg2 = new int[n]();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arg[i] += arr[i][j];
			arg2[i] = arg[i];
		}
	}

	printf("Самые успешные студенты: ");

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arg2[j] > arg2[i])
			{
				int t;
				t = arg2[i];
				arg2[i] = arg2[j];
				arg2[j] = t;
			}
		}
	}
	sum = arg2[r - 1];
	for (int i = 0; i < n; i++)
	{
		if (arg[i] >= sum)
			printf("\n%d-й (%d баллов)", i + 1, arg[i]);
	}
}

void printArr(int n, int m, int* arr[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{

	srand(time(0));
	setlocale(LC_ALL, "RUS");

	char s[100];

	while (true)
	{
		printf("Введите количество студентов: ");
		gets_s(s);
		if (proverka(s) || atoi(s) == 0)
			printf("Введённое значение некорректно.\n");
		else
			break;
	}

	int n = atoi(s);

	while (true)
	{
		printf("Введите количество предметов: ");
		gets_s(s);
		if (proverka(s) || atoi(s) == 0)
			printf("Введённое значение некорректно.\n");
		else
			break;
	}

	int m = atoi(s);

	while (true)
	{
		printf("Введите количество самых успешных студентов: ");
		gets_s(s);
		if (proverka(s) || atoi(s) == 0 || atoi(s) > n)
			printf("Введённое значение некорректно.\n");
		else
			break;
	}

	int r = atoi(s);

	int **arr = new int*[n];

	for (int i = 0; i < n; i++)
		arr[i] = new int[m]();

	while (true)
	{
		int k;
		char c[100];

		printf("\n-------------------------------МЕНЮ-------------------------------\n");
		printf("Нажмите цифру от 1 до 4, чтобы выбрать соответствующий пункт меню:\n");
		printf(" 1)ввод элементов массива\n");
		printf(" 2)обработка массива\n");
		printf(" 3)вывод массива на экран\n");
		printf(" 4)выход\n");
		printf("------------------------------------------------------------------\n");
		gets_s(c);

		if (!proverka(c))
		{
			k = atoi(c);
			if (k > 0 && k < 5)
			{
				if (k == 1)
					getArr(n, m, arr);
				else if (k == 2)
					solution(n, m, arr, r);
				else if (k == 3)
					printArr(n, m, arr);
				else if (k == 4)
				{
					delete[] arr;
					return 0;
				}
			}
			else printf("\nВведённое значение неверно, попробуйте ещё раз...\n\n");
		}
		else printf("\nВведённое значение неверно, попробуйте ещё раз...\n\n");

	}
}