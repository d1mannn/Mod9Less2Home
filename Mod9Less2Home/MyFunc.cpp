#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <Windows.h>
#include "Header.h"

int TaskNumb()
{
	setlocale(LC_ALL, "Rus");
	int task;
	printf("¬ведите номер задани€ - ");
	scanf_s("%d", &task);
	return task;
}

int LengthOfArr()
{
	setlocale(LC_ALL, "Rus");
	int length;
	printf("¬ведите размерность массива - ");
	scanf_s("%d", &length);
	return length;
}

void ArrFilling(int * arr, int * length, TypeOfNumb numb, int * count)
{
	srand(time(NULL));
	switch (numb)
	{
	case positive:
	{
		for (int i = 0; i < *length; i++)
		{
			arr[i] = 1 + rand() % 500;
		}
	}
	break;
	case negative:
	{
		for (int i = 0; i < *length; i++)
		{
			arr[i] = -500 + rand() % 450;
		}
	}
	break;
	case all:
	{
		for (int i = 0; i < *length; i++)
		{
			arr[i] = -150 + rand() % 300;
		}
	}
	break;
	case ten:
	{
		int i = 0;
		do
		{
			arr[i] = arr[i] = -30 + rand() % 60;
			printf("arr[%d] = %d\n", i, arr[i]);
			i++;
			*count = *count + 1;
		} while (arr[i - 1] != 10);
	} break;

	case ten2:
	{
		for (int i = 0; i < *length; i++)
		{
			arr[i] = arr[i] = -30 + rand() % 60;
			if (arr[i] > 10)
				*count = *count + 1;
		}

	} break;

	case seven:
	{
		for (int i = 0; i < *length; i++)
		{
			arr[i] = -30 + rand() % 60;
			if (arr[i] >= -3 && arr[i] <= 7)
				(*count)++;
		}
	} break;

	case five:
	{
		for (int i = 0; i < *length; i++)
		{
			arr[i] = -30 + rand() % 60;
			if (arr[i] % 5 == 0)
				(*count)++;
		}
	} break;

	case twelve:
	{
		for (int i = 0; i < *length; i++)
		{
			arr[i] = -30 + rand() % 60;
			if (arr[i] <= 12)
				(*count)++;
		}
	} break;
	default:
	{
		printf("ERROR\n");
	}
	break;
	}
}

void ArrFilling(int * arr, int * length, TypeOfNumb numb)
{
	srand(time(NULL));
	switch (numb)
	{
	case positive:
	{
		for (int i = 0; i < *length; i++)
		{
			arr[i] = 1 + rand() % 500;
		}
	}
	break;
	case negative:
	{
		for (int i = 0; i < *length; i++)
		{
			arr[i] = -500 + rand() % 450;
		}
	}
	break;
	case all:
	{
		for (int i = 0; i < *length; i++)
		{
			arr[i] = -150 + rand() % 300;
		}
	}
	break;

	default:
	{
		printf("ERROR\n");
	}
	break;
	}
}

int SumOfNegative(int * arr, int * length, int * sum)
{
	for (int i = 0; i < *length; i++)
	{
		if (arr[i] < 0)
			*sum = *sum + arr[i];
	}
	if (*sum != 0)
		return 1;
	else
		return 0;
}

void ArrFilling(int * arr, int * length, TypeOfNumb numb, int * countPositive, int * countNegative)
{
	srand(time(NULL));
	switch (numb)
	{
	case positive:
	{
		for (int i = 0; i < *length; i++)
		{
			arr[i] = 1 + rand() % 500;
		}
	}
	break;
	case negative:
	{
		for (int i = 0; i < *length; i++)
		{
			arr[i] = -500 + rand() % 450;
		}
	}
	break;
	case all:
	{
		for (int i = 0; i < *length; i++)
		{
			arr[i] = -150 + rand() % 300;
			if (arr[i] > 0)
				*countPositive = *countPositive + 1;
			if (arr[i] < 0)
				*countNegative = *countNegative + 1;
		}
	}
	break;

	default:
	{
		printf("ERROR\n");
	}
	break;
	}
}

void ArrCopy(int * Source, int * Destination, int length, TypeOfNumb numb)
{
	int count = 0;
	switch (numb)
	{
	case positive:
	{
		printf("\nPositive numbers - \n");
		for (int i = 0; i < length; i++)
		{
			if (Source[i] > 0)
			{
				Destination[count] = Source[i];
				printf("%d\n", Destination[count]);
				count++;
			}
		}
	}
	break;
	case negative:
	{
		printf("\nNegative numbers - \n");
		for (int i = 0; i < length; i++)
		{
			if (Source[i] < 0)
			{
				Destination[count] = Source[i];
				printf("%d\n", Destination[count]);
				count++;
			}
		}
	}
	break;

	case ten2:
	{
		printf("\nNumbers > 10:\n");
		for (int i = 0; i < length; i++)
		{
			if (Source[i] > 10)
			{
				Destination[count] = Source[i];
				printf("%d\n", Destination[count]);
				count++;
			}
		}
		if (count == 0)
		{
			printf("There are no numbers > 10\n");
		}
	} break;

	default:
	{
		printf("ERROR\n");
	}
	break;
	}
}

void SortArrBubbleIncrease(int * arr, int *length)
{
	int temp = 0;
	for (int i = 0; i < *length; i++)
	{
		for (int j = *length - 1; j > i; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}

void SortArrBubbleDecrease(int * arr, int * length)
{
	int temp = 0;
	for (int i = 0; i < *length; i++)
	{
		for (int j = *length - 1; j > i; j--)
		{
			if (arr[j - 1] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}

void ArrPrint(int * arr, int * length)
{
	for (int i = 0; i < *length; i++)
	{
		printf("Index [%d] - %d\n", i, arr[i]);
	}
}

int CheckArrIfItsSorted(int * arr, int * length, UpOrDown method)
{
	int count = 0;
	switch (method)
	{
	case up:
	{
		for (int i = 0; i < *length - 1; i++)
		{
			if (arr[i] < arr[i + 1])
				count++;
		}
		if (count == *length - 1)
			return 1;
		else
			return 0;
	}
	break;
	case down:
	{
		for (int i = 0; i < *length - 1; i++)
		{
			if (arr[i] > arr[i + 1])
				count++;
		}
		if (count == *length - 1)
			return 1;
		else
			return 0;
	}
	break;
	default:
	{
		printf("OOOOPS\nSMTH WENT WRONG\n");
		return 2;
	}
	break;
	}
}

void ArrFillingManual(int * arr, int * length, int * count)
{
	for (int i = 0; i < *length; i++)
	{
		printf("¬ведите значение дл€ %dго индекса - ", i + 1);
		scanf_s("%d", &arr[i]);
		if (arr[i] < 0)
			*count = *count + 1;
	}
}

void ArrCopy2(int * from, int * to, int * length, int * count)
{
	for (int i = 0; i < *length; i++)
	{
		if (from[i] > 0)
		{
			to[*count] = from[i];
			*count = *count + 1;
		}
		if (from[i] < 0)
			break;
	}
}

void ArrCopy3(int * from, int * to, int*length, int*count)
{
	*count = 0;
	for (int i = 0; i < *length; i++)
	{
		if (!(from[i] >= -3 && from[i] <= 7))
		{
			to[*count] = from[i];
			(*count)++;
		}
	}
}

void ArrCopy4(int * from, int * to, int*length, int*count, int * min)
{
	*count = 0;
	for (int i = 0; i < *length; i++)
	{
		if (from[i] % 5 != 0)
		{
			to[*count] = from[i];
			if (*count == 0)
				*min = to[*count];
			if (*min > to[*count])
				*min = to[*count];
			(*count)++;
		}
	}
}
void ArrCopy5(int * from, int * to, int*length, int*count)
{
	*count = 0;
	for (int i = 0; i < *length; i++)
	{
		if (from[i] <= 12)
		{
			to[*count] = from[i];
			(*count)++;
		}
	}
}

void MaxMeaning(int *arr, int * length, int * max, int * indexMax)
{
	*max = arr[0];
	for (int i = 0; i < *length; i++)
	{
		if (arr[i] > *max)
		{
			*max = arr[i];
			*indexMax = i;
		}
	}
}
void MinMeaning(int *arr, int * length, int * min, int * indexMin)
{
	*min = arr[0];
	for (int i = 0; i < *length; i++)
	{
		if (arr[i] < *min)
		{
			*min = arr[i];
			*indexMin = i;
		}
	}
}

void ChangeMaxAndMin(int * arr, int *length, int * min, int *indexMin, int * max, int *indexMax)
{
	for (int i = 0; i < *length; i++)
	{
		if (i == *indexMax)
			arr[i] = *min;
		if (i == *indexMin)
			arr[i] = *max;
	}
}