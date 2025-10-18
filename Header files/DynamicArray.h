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

//! \brief ��������� ������� � ������.
//! \param array ��������� ������������� �������.
//! \param index ������ ��������, ���� ����� �������� �������.
//! \param value �������� ��������.
bool AddElement(DynamicArray* array, int index, int value);

DynamicArray* CreateDynamicArray(int size, int capacity);

//! \brief ������� ������� ������� �� ������������� �������.
//! \param array ��������� ������������� �������.
//! \param index ������ ��������, ������� ����� �������.
bool RemoveByIndex(DynamicArray* array, int index);

bool CheckingValueInArray(int* array, int size, int value);

//! \brief ������� �������� �������� �� ��� ������������� ��������.
//! \param array ��������� ������������� �������.
//! \param value ���������� ��������, ������� ����� �������.
bool RemoveByValue(DynamicArray* array, int value);

//! \brief ���������� ������� �� �������.
//! \param array ��������� ������������� �������.
//! \param index ������, �� �������� ����� �������� ��������.
//! \return ���������� ��������, ������� ��������� ��� ��������.
int GetElement(DynamicArray* array, int index);

void InsertionSort(int* array, int size);

//! \brief ��������� ������.
//! \param array ��������� ������������� �������.
void SortArray(DynamicArray* array);

//! \brief �������� ����� ������� �������� �� ������������� ��������.
//! \param array ��������� ������������� �������.
//! \param value ��������, ������ �������� ����� �����.
int LinearSearch(DynamicArray* array, int value);

//! \brief �������� ����� ������� �������� �� ������������� ��������.
//! \param array ��������� ������������� �������.
//! \param value ��������, ������ �������� ����� �����.
int BinarySearch(DynamicArray* array, int value);