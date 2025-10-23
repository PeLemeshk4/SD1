#include <iostream>
#include <random>

using namespace std;

//TODO: comments +
// Структура динамического массива.
struct DynamicArray
{
	//TODO: comments +
	// Размер массива.
	int Size = 0;
	//TODO: comments +
	// Вместимость массива.
	int Capacity = 0;
	int* Array = nullptr;
	//TODO: refactor +
	const int growthFactor = 2;
};

//TODO: comments +
//! \brief Изменяет вместимость массива.
//! \param array Структура динамического массива.
//! \param isUpCapacity Указание на увеличение или уменьшение вместимости.
void ResizeDynamicArray(DynamicArray* array, bool isUpCapacity);

//TODO: comments +
//! \brief Проверяет не переполнен ли массив.
//! \param array Структура динамического массива.
//! \param size Будущий размер массива.
void CheckingCapacityOfDynamicArray(DynamicArray* array, int newSize);

//! \brief Добавляет элемент в массив.
//! \param array Структура динамического массива.
//! \param index Индекс элемента, куда нужно добавить элемент.
//! \param value Значение элемента.
//! \return Возвращает true, если (0 <= index <= array->Size), иначе false.
bool AddElement(DynamicArray* array, int index, int value);

//TODO: comments +
//! \brief Создание структуры динамического массива.
//! \param size Размер массива.
//! \param capacity Вместимость массива.
//! \return Возвращает созданную структуру динамического массива.
DynamicArray* CreateDynamicArray(int size, int capacity);

//! \brief Удаляет элемент массива по передаваемому индексу.
//! \param array Структура динамического массива.
//! \param index Индекс элемента, который нужно удалить.
//! \return Возвращает true, если (0 <= index < array->Size), иначе false.
bool RemoveByIndex(DynamicArray* array, int index);

//TODO: comments +
//! \brief Проверяет наличие значения в массиве.
//! \param array Структура динамического массива.
//! \param size Размер массива.
//! \param value Искомое значение элемента.
//! \return Возвращает true, если value есть в массиве, иначе false.
bool CheckingValueInArray(int* array, int size, int value);

//! \brief Удаляет значение элемента по его передаваемому значению.
//! \param array Структура динамического массива.
//! \param value Посылаемое значение, которое нужно удалить.
//! \return Возвращает true, если был удалён хотя бы 1 элемент в массиве, иначе false.
bool RemoveByValue(DynamicArray* array, int value);

//! \brief Возвращает элемент по индексу.
//! \param array Структура динамического массива.
//! \param index Индекс, по которому нужно получить значение.
//! \return Возвращает значение, которое находится под индексом.
int GetElement(DynamicArray* array, int index);

//TODO: comments +
//! \brief Сортирует массив сортировкой вствками.
//! \param array Структура динамического массива.
//! \param size Размер массива.
void InsertionSort(int* array, int size);

//! \brief Сортирует массив сортировкой Шелла.
//! \param array Структура динамического массива.
void SortArrayShell(DynamicArray* array);

//! \brief Линейный поиск индекса элемента по передаваемому значению.
//! \param array Структура динамического массива.
//! \param value Значение, индекс которого нужно найти.
//! \return Возвращает индекс найденного элемента со значением value или -1, если не нашлось.
int LinearSearch(DynamicArray* array, int value);

//! \brief Бинарный поиск индекса элемента по передаваемому значению.
//! \param array Структура динамического массива.
//! \param value Значение, индекс которого нужно найти.
//! \return Возвращает индекс найденного элемента со значением value или -1, если не нашлось.
int BinarySearch(DynamicArray* array, int value);