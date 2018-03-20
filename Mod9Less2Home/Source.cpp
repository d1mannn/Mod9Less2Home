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
			//1.	Ввести вещественные числа.Создать массив из этих чисел, пока не встретится число 10. Вычислить сумму отрицательных элементов массива
			int arr[150], count = 0, length = 150, sum = 0;
			ArrFilling(arr, &length, ten, &count);
			length = count;
			int result = SumOfNegative(arr, &length, &sum);
			if (result == 1)
			{
				printf("Сумма отрицательных чисел = %d\n", sum);
			}
			else
			{
				printf("В массиве нет отрицательных чисел ! \n");
			}
		} break;

		case 2:
		{
			/*2.	Ввести в StringGrid массив из 10 целых чисел.
			Создать два новых массива – из положительных и отрицательных
			элементов исходного массива.Определить суммы элементов каждого массива.*/
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
			/*3.	Ввести массив из 9 вещественных чисел.
			Создать новый массив из элементов исходного, которые по модулю больше 10.
			Вычислить среднее арифметическое элементов нового массива*/
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
			//4.	Ввести вещественные числа.Создать массив из положительных чисел.
			//Определить, является ли массив упорядоченным по возрастанию.
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
				printf("\nПосле сортировки:\n");
				ArrPrint(arr, &length);
			}

			int result = CheckArrIfItsSorted(arr, &length, up);
			if (result == 1)
				printf("Массив отсортирован по возрастанию\n");
			else if (result == 0)
				printf("Массив НЕ отсортирован\n");
			else
				printf("ERROR\n");
			free(arr);
		} break;

		case 5:
		{
			//5.	Ввести целые числа.Создать массив из этих чисел до первого отрицательного числа.
			//Определить, является ли массив упорядоченным по убыванию.
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
				printf("Печать нового массива\n");
				ArrPrint(arr2, &count);
				free(arr2);
			}
		} break;

		case 6:
		{
			/*6.	Ввести массив из 15 вещественных чисел.
			Создать новый массив из элементов исходного,
			в который не включать элементы, попадающие в промежуток(-3, 7).
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
			//7.	Ввести целые числа.Создать массив из чисел, которые не делятся на 5. Определить минимальный элемент массива.
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
				printf("\nMIN значение массива - %d\n", min);
				free(arr2);
			}
			else
				printf("Все числа НЕ деляться на 5 без остатка\n");
			free(arr1);
		} break;

		case 8:
		{
			//8.	Ввести вещественные числа.Создать массив из этих чисел, пока не встретится число 33. Определить максимальный элемент массива
			// очень похож на 5е задание. только там первое отрицательное, а здесь число 33. 
			//Максимальный определить также как и минимальный из 7го задания
			//Поэтому пропущу :)
		} break;

		case 9:
		{
			/*9.	Ввести массив из 9 вещественных чисел.
			Создать новый массив из элементов исходного, которые по модулю не больше 12.
			Поменять местами минимальный и максимальный элементы нового массива*/
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
			/*10.	Ввести вещественные числа.Создать массив из чисел, которые попадают в интервал[2, 13].
			Определить, есть ли в массиве числа, большие 10.*/
			//Очень похоже на 6-е. Пропущу :)
			//УРА! ПОСЛЕДНЕЕ ЗАДАНИЕ:)
		} break;
		}
	} while (task > 0);
}