#include <iostream>
#include "..\Header files\DynamicArray.h"

void ResizeDynamicArray(DynamicArray* array, bool isUpCapacity)
{
	int newCapacity = isUpCapacity
		? array->Capacity * array->GrowthFactor
		: array->Capacity / array->GrowthFactor;

	int* newArray = new int[newCapacity]();
	for (int i = 0; i < array->Size; i++)
	{
		*(newArray + i) = *(array->Array + i);
	}
	array->Capacity = newCapacity;
	delete[] array->Array;
	array->Array = newArray;
}

void CheckingCapacityOfDynamicArray(DynamicArray* array, int newSize)
{
	if (array->Capacity < newSize)
	{
		ResizeDynamicArray(array, true);
	}
	else
	{
		while (array->Capacity / array->GrowthFactor >= newSize and
			array->Capacity % array->GrowthFactor == 0)
		{
			ResizeDynamicArray(array, false);
		}
	}
}

bool AddElement(DynamicArray* array, int index, int value)
{
	CheckingCapacityOfDynamicArray(array, array->Size + 1);

	if (index == array->Size)
	{
		*(array->Array + index) = value;
		array->Size++;
	}
	else if (index < array->Size&& index >= 0)
	{
		for (int i = array->Size; i > index; i--)
		{
			*(array->Array + i) = *(array->Array + i - 1);
		}
		*(array->Array + index) = value;
		array->Size++;
	}
	else
	{
		return false;
	}

	return true;
}

DynamicArray* CreateDynamicArray(int size, int capacity)
{
	random_device randomDevice;
	mt19937 gen(randomDevice());
	uniform_int_distribution<> distForInt(-100, 100);

	DynamicArray* dynamicArray = new DynamicArray();
	dynamicArray->Size = 0;
	dynamicArray->Capacity = capacity;
	dynamicArray->Array = new int[dynamicArray->Capacity]();
	for (int i = 0; i < size; i++)
	{
		AddElement(dynamicArray, i, distForInt(gen));
	}
	return dynamicArray;
}

bool RemoveByIndex(DynamicArray* array, int index)
{
	if (index >= array->Size || index < 0)
	{
		return false;
	}
	else
	{
		if (index == array->Size - 1)
		{
			*(array->Array + index) = 0;
			array->Size--;
		}
		else if (index < array->Size)
		{
			for (int i = index; i < array->Size - 1; i++)
			{
				*(array->Array + i) = *(array->Array + i + 1);
			}
			array->Size--;
		}

		CheckingCapacityOfDynamicArray(array, array->Size);

		return true;
	}
}

bool CheckingValueInArray(int* array, int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (*(array + i) == value)
		{
			return true;
		}
	}

	return false;
}

bool RemoveByValue(DynamicArray* array, int value)
{
	int i = 0;
	if (CheckingValueInArray(array->Array, array->Size, value))
	{
		while (CheckingValueInArray(array->Array, array->Size, value))
		{
			for (i; i < array->Size; i++)
			{
				if (*(array->Array + i) == value)
				{
					RemoveByIndex(array, i);
					break;
				}
			}
		}

		return true;
	}
	else
	{
		return false;
	}
}

int GetElement(DynamicArray* array, int index)
{
	return *(array->Array + index);
}

//! \brief Находит максимальный шаг для сортировки Шелла по формуле Кнута.
//! \param size Размер массива.
//! \param firstShellsNumber Первая переменная формулы Кнута для сортировки Шелла (обычно 3).
//! \param secondShellsNumber Вторая переменная формулы Кнута для сортировки Шелла (обычно 1).
//! \param step Шаг для сортировки Шелла.
//! \return Максимальный шаг для сортировки Шелла по формуле Кнута.
int StepForShellSort(int size, int firstShellsNumber, int secondShellsNumber, int step = 1)
{
	int newStep = firstShellsNumber * step + secondShellsNumber;
	if (newStep >= size)
	{
		return step;
	}
	else
	{
		StepForShellSort(size, firstShellsNumber, secondShellsNumber, newStep);
	}
}

void InsertionSort(int* array, int size)
{
	for (int i = 1; i < size; i++)
	{
		if (*(array + i) < *(array + i - 1))
		{
			int j = i;
			while (j != 0 && *(array + j) < *(array + j - 1))
			{
				swap(*(array + j), *(array + j - 1));
				j--;
			}
		}
	}
}

void SortArrayShell(DynamicArray* array)
{
	const int firstShellsNumber = 3;
	const int secondShellsNumber = 1;
	for (int step =
		StepForShellSort(array->Size, firstShellsNumber, secondShellsNumber);
		step > 1; step = (step - secondShellsNumber) / firstShellsNumber)
	{
		for (int i = 0; i < step; i++)
		{
			int size = (array->Size - (i + 1)) / step + 1;
			int* subArray = new int[size]();
			int number = 0;

			for (int j = i; j < array->Size; j += step)
			{
				*(subArray + number) = *(array->Array + j);
				number++;
			}

			InsertionSort(subArray, size);
			number = 0;

			for (int j = i; j < array->Size; j += step)
			{
				*(array->Array + j) = *(subArray + number);
				number++;
			}

			delete[] subArray;
		}
	}

	InsertionSort(array->Array, array->Size);
}

int LinearSearch(DynamicArray* array, int value)
{
	for (int i = 0; i < array->Size; i++)
	{
		if (*(array->Array + i) == value)
		{
			return i;
		}
	}

	return -1;
}

int BinarySearch(DynamicArray* array, int value)
{
	int downBord = 0;
	int upBord = array->Size - 1;

	while (downBord <= upBord)
	{
		int index = downBord + (upBord - downBord) / 2;

		if (*(array->Array + index) == value)
		{
			return index;
		}
		else if (*(array->Array + index) < value)
		{
			downBord = index + 1;
		}
		else
		{
			upBord = index - 1;
		}
	}

	return -1;
}