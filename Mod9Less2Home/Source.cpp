#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <Windows.h>
#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int task;
	do
	{
		task = TaskNumb();
		switch (task)
		{
		case 1:
		{
			//1.	������ ������������ �����.������� ������ �� ���� �����, ���� �� ���������� ����� 10. ��������� ����� ������������� ��������� �������
			int arr[150], count = 0, length = 150, sum = 0;
			ArrFilling(arr, &length, ten, &count);
			length = count;
			int result = SumOfNegative(arr, &length, &sum);
			if (result == 1)
			{
				printf("����� ������������� ����� = %d\n", sum);
			}
			else
			{
				printf("� ������� ��� ������������� ����� ! \n");
			}
		} break;

		case 2:
		{
			/*2.	������ � StringGrid ������ �� 10 ����� �����.
			������� ��� ����� ������� � �� ������������� � �������������
			��������� ��������� �������.���������� ����� ��������� ������� �������.*/
			int arr[10], length = 10, countPositive = 0, countNegative = 0, sum1 = 0, sum2 = 0;
			int *arrPositive, *arrNegative;
			ArrFilling(arr, &length, all, &countPositive, &countNegative);
			if (countPositive > 0 && countNegative > 0)
			{
				arrPositive = (int*)calloc(countPositive, sizeof(int));
				arrNegative = (int*)calloc(countNegative, sizeof(int));
				if (arrPositive == NULL || arrNegative == NULL)
				{
					printf("\nERROR! There is no space for arr\n");
					EXIT_FAILURE;
				}
				ArrCopy(arr, arrPositive, length, positive);
				ArrCopy(arr, arrNegative, length, negative);
				free(arrPositive);
				free(arrNegative);
			}
			else
				printf("\nERROR\n");
		} break;

		case 3:
		{
			/*3.	������ ������ �� 9 ������������ �����.
			������� ����� ������ �� ��������� ���������, ������� �� ������ ������ 10.
			��������� ������� �������������� ��������� ������ �������*/
			int arr[9], length = 9, count = 0;
			ArrFilling(arr, &length, ten2, &count);
			if (count > 0)
			{
				int * arr2;
				arr2 = (int*)calloc(count, sizeof(int));
				if (arr2 == NULL)
				{
					printf("\nERROR! There is no space for arr\n");
					EXIT_FAILURE;
				}
				ArrCopy(arr, arr2, length, ten2);
				free(arr2);
			}
		} break;

		case 4:
		{
			//4.	������ ������������ �����.������� ������ �� ������������� �����.
			//����������, �������� �� ������ ������������� �� �����������.
			int length = LengthOfArr(), count = 0;
			int * arr;
			arr = (int*)calloc(length, sizeof(arr));
			if (arr == NULL)
			{
				printf("\nERROR! There is no space for arr\n");
				EXIT_FAILURE;
			}
			ArrFilling(arr, &length, all);
			ArrPrint(arr, &length);
			int n = 0 + rand() % 2;
			printf("\nn = %d\n", n);
			if (n > 0)
			{
				SortArrBubbleIncrease(arr, &length);
				//SortArrBubbleDecrease(arr, &length);
				printf("\n����� ����������:\n");
				ArrPrint(arr, &length);
			}

			int result = CheckArrIfItsSorted(arr, &length, up);
			if (result == 1)
				printf("������ ������������ �� �����������\n");
			else if (result == 0)
				printf("������ �� ������������\n");
			else
				printf("ERROR\n");
			free(arr);
		} break;

		case 5:
		{
			//5.	������ ����� �����.������� ������ �� ���� ����� �� ������� �������������� �����.
			//����������, �������� �� ������ ������������� �� ��������.
			int arr1[7], length = 7, count = 0;
			ArrFillingManual(arr1, &length, &count);
			if (count > 0)
			{
				int *arr2;
				arr2 = (int*)calloc(7 - count, sizeof(int));
				count = 0;
				if (arr2 == NULL)
				{
					printf("ERROR\n");
					EXIT_FAILURE;
				}
				ArrCopy2(arr1, arr2, &length, &count);
				printf("������ ������ �������\n");
				ArrPrint(arr2, &count);
				free(arr2);
			}
		} break;

		case 6:
		{
			/*6.	������ ������ �� 15 ������������ �����.
			������� ����� ������ �� ��������� ���������,
			� ������� �� �������� ��������, ���������� � ����������(-3, 7).
			*/
			int arr1[15], length = 15, count = 0;
			ArrFilling(arr1, &length, seven, &count);
			ArrPrint(arr1, &length);
			if (count > 0)
			{
				int *arr2;
				arr2 = (int*)calloc(length - count, sizeof(int));
				if (arr2 == NULL)
				{
					printf("ERROR\n");
					EXIT_FAILURE;
				}
				ArrCopy3(arr1, arr2, &length, &count);
				printf("NEW ARR\n");
				ArrPrint(arr2, &count);
				free(arr2);
			}
		} break;

		case 7:
		{
			//7.	������ ����� �����.������� ������ �� �����, ������� �� ������� �� 5. ���������� ����������� ������� �������.
			int length = LengthOfArr(), count = 0, min = 0;
			int * arr1;
			arr1 = (int*)calloc(length, sizeof(int));
			if (arr1 == NULL)
			{
				printf("ERROR\n");
				EXIT_FAILURE;
			}
			ArrFilling(arr1, &length, five, &count);
			ArrPrint(arr1, &length);
			printf("\n\n");
			if (count > 0)
			{
				int *arr2;
				arr2 = (int*)calloc(length - count, sizeof(int));
				if (arr2 == NULL)
				{
					printf("ERROR\n");
					EXIT_FAILURE;
				}
				ArrCopy4(arr1, arr2, &length, &count, &min);
				printf("\nNEW ARR\n");
				ArrPrint(arr2, &count);
				printf("\nMIN �������� ������� - %d\n", min);
				free(arr2);
			}
			else
				printf("��� ����� �� �������� �� 5 ��� �������\n");
			free(arr1);
		} break;

		case 8:
		{
			//8.	������ ������������ �����.������� ������ �� ���� �����, ���� �� ���������� ����� 33. ���������� ������������ ������� �������
			// ����� ����� �� 5� �������. ������ ��� ������ �������������, � ����� ����� 33. 
			//������������ ���������� ����� ��� � ����������� �� 7�� �������
			//������� ������� :)
		} break;

		case 9:
		{
			/*9.	������ ������ �� 9 ������������ �����.
			������� ����� ������ �� ��������� ���������, ������� �� ������ �� ������ 12.
			�������� ������� ����������� � ������������ �������� ������ �������*/
			int arr1[9], length = 9, count = 0;
			ArrFilling(arr1, &length, twelve, &count);
			ArrPrint(arr1, &length);
			printf("============\n");
			if (count > 0)
			{
				int * arr2, min = 0, max = 0, indexMax = 0, indexMin = 0;
				arr2 = (int*)calloc(count, sizeof(int));
				if (arr2 == NULL)
				{
					printf("ERROR\n");
					EXIT_FAILURE;
				}
				ArrCopy5(arr1, arr2, &length, &count);
				printf("============\nNEW ARR\n=========\n");
				ArrPrint(arr2, &count);
				MaxMeaning(arr2, &count, &max, &indexMax);
				MinMeaning(arr2, &count, &min, &indexMin);
				printf("\nMAX = %d, Index = %d\n", max, indexMax);
				printf("MIN = %d, Index - %d\n", min, indexMin);
				ChangeMaxAndMin(arr2, &count, &min, &indexMin, &max, &indexMax);
				printf("After changing placese:\n");
				ArrPrint(arr2, &count);
				free(arr2);
				//
			}
		} break;

		case 10:
		{
			/*10.	������ ������������ �����.������� ������ �� �����, ������� �������� � ��������[2, 13].
			����������, ���� �� � ������� �����, ������� 10.*/
			//����� ������ �� 6-�. ������� :)
			//���! ��������� �������:)
		} break;
		}
	} while (task > 0);
}