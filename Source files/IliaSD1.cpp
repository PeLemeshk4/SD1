#include <iostream>
#include "C:\Users\User\Desktop\Структурка\Лаба 1\Header files\DynamicArray.h"
#include <chrono>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

// 6 вариант
cpp_int Factorial(int n)   //  Рекурсивная функция выполняется n раз => M(n) = O(n)
{
    if (n == 0) // O(1)
    {
        return 1; // O(1)
    }
    else
    {
        return n * Factorial(n - 1); // O(1 + (n-1)) == O(n)
    }
}
// T(n) = O(n)
// M(n) = O(n)

string manuals[] = { "Create dynamic array\n", "Write array\n", "Add element\n",
                     "Remove element\n", "Get size\n", "Get capacity\n", "Get element\n",
                     "Sort array\n", "Search element\n", "Exit\n", "Remove by index\n",
                     "Remove by value\n", "Linear search\n",
                     "Binary search(for sorted array)\n", "Delete dynamic array\n" };

DynamicArray* dynamicArray;

void WriteManual(int* manualsIndexes, int length)
{
    cout << "Manual:\n";

    for (int i = 0; i < length; i++)
    {
        cout << i << ". " << manuals[*(manualsIndexes + i)];
    }
}

void WriteArray()
{
    int i;
    cout << "Array: ";
    for (i = 0; i < dynamicArray->Size; i++)
    {
        cout << *(dynamicArray->Array + i) << ' ';
    }
}

void RequestExecution(int choice, int* manualsIndexes, int size)
{
    if (choice < size)
    {
        cout << endl;
        // TODO: Убрать указатель у простых типов данных
        switch (manualsIndexes[choice])
        {
            case 0:
            {
                int size;
                int capacity;

                cout << "Enter size of array: ";
                cin >> size;
                cout << "Enter capacity of array: ";
                cin >> capacity;

                dynamicArray = CreateDynamicArray(size, capacity);

                WriteArray();
                cout << endl;

                break;
            }
            case 1:
            {
                WriteArray();
                cout << endl;

                break;
            }
            case 2:
            {
                int index;
                int value;

                cout << "Enter index for new element(0-" << dynamicArray->Size << "): ";
                cin >> index;
                cout << "Enter value for new element: ";
                cin >> value;

                if (AddElement(dynamicArray, index, value))
                {
                    cout << "Element was added" << endl;
                }
                else
                {
                    cout << "Incorrect index" << endl;
                }

                break;
            }
            case 3:
            {
                int choice;
                int* subManualsIndexes = new int[2] { 10, 11 };
                int indexOrValue;

                WriteManual(subManualsIndexes, 2);
                cin >> choice;
                cout << endl;

                switch (subManualsIndexes[choice])
                {
                    case 10:
                    {
                        cout << "Enter index of element for remove(0-" << dynamicArray->Size - 1 << "): ";
                        cin >> indexOrValue;
                        if (RemoveByIndex(dynamicArray, indexOrValue))
                        {
                            cout << "Element was removed" << endl;
                        }
                        else
                        {
                            cout << "Incorrect index" << endl;
                        }

                        break;
                    }
                    case 11:
                    {
                        cout << "Enter the value for remove: ";
                        cin >> indexOrValue;
                        if (RemoveByValue(dynamicArray, indexOrValue))
                        {
                            cout << "Element was removed" << endl;
                        }
                        else
                        {
                            cout << "Elements with this value was not found" << endl;
                        }                     

                        break;
                    }
                    default:
                    {
                        cout << "Incorrect choice" << endl;
                    }
                }

                delete[] subManualsIndexes;

                break;
            }
            case 4:
            {
                cout << "Size: " << dynamicArray->Size << endl;

                break;
            }
            case 5:
            {
                cout << "Capacity: " << dynamicArray->Capacity << endl;

                break;
            }
            case 6:
            {
                int index;
                cout << "Enter the index of element(0-" << dynamicArray->Size - 1 << "): ";
                cin >> index;

                if (index < dynamicArray->Size && index >= 0)
                {
                    cout << GetElement(dynamicArray, index) << endl;
                }
                else
                {
                    cout << "Incorrect index" << endl;
                }

                break;
            }
            case 7:
            {
                SortArray(dynamicArray);
                WriteArray();
                cout << endl;

                break;
            }
            case 8:
            {
                int choice;
                int value;
                int index = -2;
                int* subManualsIndexes = new int[2] { 12, 13 };

                WriteManual(subManualsIndexes, 2);
                cin >> choice;
                cout << endl;

                switch (subManualsIndexes[choice])
                {
                    delete[] subManualsIndexes;

                    case 12:
                    {
                        cout << "Enter value for search: ";
                        cin >> value;
                        index = LinearSearch(dynamicArray, value);

                        break;
                    }
                    case 13:
                    {
                        cout << "Enter value for search: ";
                        cin >> value;
                        index = BinarySearch(dynamicArray, value);

                        break;
                    }
                    default:
                    {
                        cout << "Incorrect choice" << endl;

                        break;
                    }
                }
                if (index >= 0)
                {
                    cout << "Your value(" << value << ") has index " << index << endl;
                }
                else if (index == -1)
                {
                    cout << "Not found" << endl;
                }

                break;
            }
            case 9:
            {
                delete[] manualsIndexes;
                if (dynamicArray != nullptr)
                {
                    delete[] dynamicArray->Array;
                    delete dynamicArray;
                }
                exit(0);

                break;
            }
            case 14:
            {
                delete[] dynamicArray->Array;
                delete dynamicArray;
                dynamicArray = nullptr;

                cout << "Array was deleted" << endl;

                break;
            }
        }
    }
    else
    {
        cout << "\nIncorrect choice\n";
    }
    cout << endl;
}

int main()
{
    int number;

    cout << "Structure of data #1:\n";
    cout << "Enter the number of task(1-2): ";
    cin >> number;

    if (number == 1)
    {
        int n;
        cpp_int factorial;

        cout << "Enter value for factorial: ";
        cin >> n;

        if (n >= 0 && n <= 2500)
        {
            auto start = chrono::high_resolution_clock::now();
            factorial = Factorial(n);
            auto end = chrono::high_resolution_clock::now();

            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

            cout << factorial << " " << duration.count() << " microseconds" << endl;
        }
        else
        {
            cout << "Incorrect value";
        }
    }
    else if (number == 2)
    {
        while (true)
        {
            int choice;
            if (dynamicArray == nullptr)
            {
                int* manualsIndexes = new int[2] { 0, 9 };

                WriteManual(manualsIndexes, 2);
                cin >> choice;

                RequestExecution(choice, manualsIndexes, 2);

                delete[] manualsIndexes;
            }
            else
            {
                int* manualsIndexes = new int[10] { 1, 2, 3, 4, 5, 6, 7, 8, 14, 9 };

                WriteManual(manualsIndexes, 10);
                cin >> choice;

                RequestExecution(choice, manualsIndexes, 10);

                delete[] manualsIndexes;
            }
        }
    }
}