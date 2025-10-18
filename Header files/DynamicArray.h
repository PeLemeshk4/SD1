#include <iostream>
#include <random>

using namespace std;

struct DynamicArray
{
	int Size = 0;
	int Capacity = 0;
	int* Array = nullptr;
	const int firstShellsNumber = 3;
	const int secondShellsNumber = 1;
};

void ResizeDynamicArray(DynamicArray* array, bool up);

void CheckingCapacityOfDynamicArray(DynamicArray* array, int size);

//! \brief Добавляет элемент в массив.
//! \param array Структура динамического массива.
//! \param index Индекс элемента, куда нужно добавить элемент.
//! \param value Значение элемента.
bool AddElement(DynamicArray* array, int index, int value);

DynamicArray* CreateDynamicArray(int size, int capacity);

//! \brief Удаляет элемент массива по передаваемому индексу.
//! \param array Структура динамического массива.
//! \param index Индекс элемента, который нужно удалить.
bool RemoveByIndex(DynamicArray* array, int index);

bool CheckingValueInArray(int* array, int size, int value);

//! \brief Удаляет значение элемента по его передаваемому значению.
//! \param array Структура динамического массива.
//! \param value Посылаемое значение, которое нужно удалить.
bool RemoveByValue(DynamicArray* array, int value);

//! \brief Возвращает элемент по индексу.
//! \param array Структура динамического массива.
//! \param index Индекс, по которому нужно получить значение.
//! \return Возвращает значение, которое находится под индексом.
int GetElement(DynamicArray* array, int index);

void InsertionSort(int* array, int size);

//! \brief Сортирует массив.
//! \param array Структура динамического массива.
void SortArray(DynamicArray* array);

//! \brief Линейный поиск индекса элемента по передаваемому значению.
//! \param array Структура динамического массива.
//! \param value Значение, индекс которого нужно найти.
int LinearSearch(DynamicArray* array, int value);

//! \brief Бинарный поиск индекса элемента по передаваемому значению.
//! \param array Структура динамического массива.
//! \param value Значение, индекс которого нужно найти.
int BinarySearch(DynamicArray* array, int value);