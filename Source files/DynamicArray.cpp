#include <iostream>
#include "C:\Users\User\Desktop\Структурка\Лаба 1\Header files\DynamicArray.h"

void ResizeDynamicArray(DynamicArray* array, bool up)
{
	int newCapacity;

	if (up)
	{
		newCapacity = array->Capacity * 2;
	}
	else
	{
		newCapacity = array->Capacity / 2;
	}

	int* newArray = new int[newCapacity]();
	for (int i = 0; i < array->Size; i++)
	{
		*(newArray + i) = *(array->Array + i);
	}
	array->Capacity = newCapacity;
	delete[] array->Array;
	array->Array = newArray;
}

void CheckingCapacityOfDynamicArray(DynamicArray* array, int size)
{
	if (array->Capacity < size)
	{
		ResizeDynamicArray(array, true);
	}
	else
	{
		while (array->Capacity / 2 >= size and array->Capacity % 2 == 0)
		{
			ResizeDynamicArray(array, false);
		}
	}
}

//! \brief Добавляет элемент в массив.
//! \param array Структура динамического массива.
//! \param index Индекс элемента, куда нужно добавить элемент.
//! \param value Значение элемента.
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

//! \brief Удаляет элемент массива по передаваемому индексу.
//! \param array Структура динамического массива.
//! \param index Индекс элемента, который нужно удалить.
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
			*(array->Array + index) = NULL;
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

//! \brief Удаляет значение элемента по его передаваемому значению.
//! \param array Структура динамического массива.
//! \param value Посылаемое значение, которое нужно удалить.
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

//! \brief Возвращает элемент по индексу.
//! \param array Структура динамического массива.
//! \param index Индекс, по которому нужно получить значение.
//! \return Возвращает значение, которое находится под индексом.
int GetElement(DynamicArray* array, int index)
{
	return *(array->Array + index);
}

int StepForShellSort(int size, int step = 1, int firstShellsNumber = 3, int secondShellsNumber = 1)
{
	int newStep = firstShellsNumber * step + secondShellsNumber;
	if (newStep >= size)
	{
		return step;
	}
	else
	{
		StepForShellSort(size, newStep);
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

//! \brief Сортирует массив.
//! \param array Структура динамического массива.
void SortArray(DynamicArray* array)
{
	for (int step = StepForShellSort(array->Size); step > 1;
		step = (step - array->secondShellsNumber) / array->firstShellsNumber)
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

//! \brief Линейный поиск индекса элемента по передаваемому значению.
//! \param array Структура динамического массива.
//! \param value Значение, индекс которого нужно найти.
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

//! \brief Бинарный поиск индекса элемента по передаваемому значению.
//! \param array Структура динамического массива.
//! \param value Значение, индекс которого нужно найти.
int BinarySearch(DynamicArray* array, int value)
{
	int downBord = 0;
	int upBord = array->Size - 1;
	int index;

	while (downBord <= upBord)
	{
		index = downBord + (upBord - downBord) / 2;

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