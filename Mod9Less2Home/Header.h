#pragma once
#pragma once

enum TypeOfNumb
{
	positive, negative, all, ten, ten2, seven, five, twelve
};

enum UpOrDown
{
	up, down
};

int TaskNumb();
int LengthOfArr();
void ArrFilling(int * arr, int * length, TypeOfNumb numb, int * count);
int SumOfNegative(int * arr, int * length, int * sum);
void ArrFilling(int * arr, int * length, TypeOfNumb numb, int * countPositive, int * countNegative);
void ArrCopy(int * Source, int * Destination, int length, TypeOfNumb numb);
void SortArrBubbleIncrease(int * arr, int *length);
void SortArrBubbleDecrease(int * arr, int * length);
void ArrFilling(int * arr, int * length, TypeOfNumb numb);
void ArrPrint(int * arr, int * length);
int CheckArrIfItsSorted(int * arr, int * length, UpOrDown method);
void ArrFillingManual(int * arr, int * length, int * count);
void ArrCopy2(int * from, int * to, int * length, int * count);
void ArrCopy3(int * from, int * to, int*length, int*count);
void ArrCopy4(int * from, int * to, int*length, int*count, int * min);
void ArrCopy5(int * from, int * to, int*length, int*count);
void MaxMeaning(int *arr, int * length, int * max, int * indexMax);
void MinMeaning(int *arr, int * length, int * min, int * indexMin);
void ChangeMaxAndMin(int * arr, int *length, int * min, int *indexMin, int * max, int *indexMax);