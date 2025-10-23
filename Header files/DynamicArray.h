#include <iostream>
#include <random>

using namespace std;

//TODO: comments +
// ��������� ������������� �������.
struct DynamicArray
{
	//TODO: comments +
	// ������ �������.
	int Size = 0;
	//TODO: comments +
	// ����������� �������.
	int Capacity = 0;
	int* Array = nullptr;
	//TODO: refactor +
	const int growthFactor = 2;
};

//TODO: comments +
//! \brief �������� ����������� �������.
//! \param array ��������� ������������� �������.
//! \param isUpCapacity �������� �� ���������� ��� ���������� �����������.
void ResizeDynamicArray(DynamicArray* array, bool isUpCapacity);

//TODO: comments +
//! \brief ��������� �� ���������� �� ������.
//! \param array ��������� ������������� �������.
//! \param size ������� ������ �������.
void CheckingCapacityOfDynamicArray(DynamicArray* array, int newSize);

//! \brief ��������� ������� � ������.
//! \param array ��������� ������������� �������.
//! \param index ������ ��������, ���� ����� �������� �������.
//! \param value �������� ��������.
//! \return ���������� true, ���� (0 <= index <= array->Size), ����� false.
bool AddElement(DynamicArray* array, int index, int value);

//TODO: comments +
//! \brief �������� ��������� ������������� �������.
//! \param size ������ �������.
//! \param capacity ����������� �������.
//! \return ���������� ��������� ��������� ������������� �������.
DynamicArray* CreateDynamicArray(int size, int capacity);

//! \brief ������� ������� ������� �� ������������� �������.
//! \param array ��������� ������������� �������.
//! \param index ������ ��������, ������� ����� �������.
//! \return ���������� true, ���� (0 <= index < array->Size), ����� false.
bool RemoveByIndex(DynamicArray* array, int index);

//TODO: comments +
//! \brief ��������� ������� �������� � �������.
//! \param array ��������� ������������� �������.
//! \param size ������ �������.
//! \param value ������� �������� ��������.
//! \return ���������� true, ���� value ���� � �������, ����� false.
bool CheckingValueInArray(int* array, int size, int value);

//! \brief ������� �������� �������� �� ��� ������������� ��������.
//! \param array ��������� ������������� �������.
//! \param value ���������� ��������, ������� ����� �������.
//! \return ���������� true, ���� ��� ����� ���� �� 1 ������� � �������, ����� false.
bool RemoveByValue(DynamicArray* array, int value);

//! \brief ���������� ������� �� �������.
//! \param array ��������� ������������� �������.
//! \param index ������, �� �������� ����� �������� ��������.
//! \return ���������� ��������, ������� ��������� ��� ��������.
int GetElement(DynamicArray* array, int index);

//TODO: comments +
//! \brief ��������� ������ ����������� ��������.
//! \param array ��������� ������������� �������.
//! \param size ������ �������.
void InsertionSort(int* array, int size);

//! \brief ��������� ������ ����������� �����.
//! \param array ��������� ������������� �������.
void SortArrayShell(DynamicArray* array);

//! \brief �������� ����� ������� �������� �� ������������� ��������.
//! \param array ��������� ������������� �������.
//! \param value ��������, ������ �������� ����� �����.
//! \return ���������� ������ ���������� �������� �� ��������� value ��� -1, ���� �� �������.
int LinearSearch(DynamicArray* array, int value);

//! \brief �������� ����� ������� �������� �� ������������� ��������.
//! \param array ��������� ������������� �������.
//! \param value ��������, ������ �������� ����� �����.
//! \return ���������� ������ ���������� �������� �� ��������� value ��� -1, ���� �� �������.
int BinarySearch(DynamicArray* array, int value);