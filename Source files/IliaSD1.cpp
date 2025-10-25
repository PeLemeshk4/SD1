#include <iostream>
#include <string>
#include "..\Header files\DynamicArray.h"
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


//TODO: comments +
//! \brief Выводит инструкции в консоль из manuals по индексам из manualsIndexes.
//! \param manuals Список со всеми инструкциями.
//! \param manualsIndexes Список с индексами для списка с инструкциями.
//! \param length Длина массива manualsIndexes.
void WriteManual(string* manuals, int* manualsIndexes, int length)
{
    cout << "Manual:\n";

    for (int i = 0; i < length; i++)
    {
        cout << i << ". " << manuals[*(manualsIndexes + i)];
    }
}

//TODO: comments +
//! \brief Выводит в консоль массив из структуры.
//! \param dynamicArray Структура динамического массива.
void WriteArray(DynamicArray*& dynamicArray)
{
    int i;
    cout << "Array: ";
    for (i = 0; i < dynamicArray->Size; i++)
    {
        cout << *(dynamicArray->Array + i) << ' ';
    }
}

//! \brief Выводит сообщение в консоль и записывает введённое значение в переменную.
//! \param message Сообщение, которое выведется в консоль.
//! \param varriable Переменная в которую впишется введённое значение из консоли.
void InputWithMessage(string message, int& varriable)
{
    cout << message;
    cin >> varriable;
}

//! \brief Проверяет входит ли значение в заданную область.
//! \param min Нижняя граница.
//! \param max Верхняя граница.
//! \note Границы входя в область.
//! \return Если входит в область, то true, иначе false.
bool ValueIsBorded(int value, int min, int max)
{
    if (value >= min && value <= max)
    {
        return true;
    }

    return false;
}

//! \brief Выводит одно из собщений в консоль по условию.
//! \param condition Условие.
//! \param trueMessage Сообщение, если true.
//! \param falseMessage Сообщение, если false.
void OutputWithCondition(bool condition, string trueMessage, string falseMessage)
{
    if (condition)
    {
        cout << trueMessage;
    }
    else
    {
        cout << falseMessage;
    }
}

//TODO: comments +
//! \brief Выполняет запрос по выбранной инструкции.
//! \param choice Выбранная инструкция из выведенных.
//! \param manualsIndexes Список с индексами выведенных инструкций.
//! \param size Количество выведенных инструкций.
//! \param dynamicArray Структура динамического массива.
//! \param manuals Массив со всеми инструкциями.
void RequestExecution(int choice, int* manualsIndexes, int size, DynamicArray*& dynamicArray, string* manuals)
{
    if (ValueIsBorded(choice, 0, size - 1))
    {
        cout << endl;
        // TODO: Убрать указатель у простых типов данных +
        switch (manualsIndexes[choice])
        {
            case 0:
            {
                //TODO: RSDN +
                int size;
                InputWithMessage("Enter size of array: ", size);

                //TODO: duplication +
                int capacity;
                InputWithMessage("Enter capacity of array: ", capacity);

                dynamicArray = CreateDynamicArray(size, capacity);

                WriteArray(dynamicArray);
                cout << endl;

                break;
            }
            case 1:
            {
                WriteArray(dynamicArray);
                cout << endl;

                break;
            }
            case 2:
            {
                //TODO: duplication +

                int index;
                InputWithMessage("Enter index for new element(0-" +
                    to_string(dynamicArray->Size) + "): ", index);

                if (index > dynamicArray->Size || index < 0)
                {
                    cout << "Incorrect index\n";

                    break;
                }

                int value;
                InputWithMessage("Enter value for new element: ", value);

                AddElement(dynamicArray, index, value);
                cout << "Element was added\n";

                break;
            }
            case 3:
            {
                int subManualsIndexes[] = {10, 11};
                int numberOfManuals = sizeof(subManualsIndexes) /
                                      sizeof(subManualsIndexes[0]);
                WriteManual(manuals, subManualsIndexes, numberOfManuals);
                int choice;
                cin >> choice;

                cout << endl;
                switch (subManualsIndexes[choice])
                {
                    case 10:
                    {
                        int index;
                        InputWithMessage("Enter index of element for remove(0-" +
                            to_string(dynamicArray->Size - 1) + "): ", index);

                        if (RemoveByIndex(dynamicArray, index))
                        {
                            cout << "Element was removed\n";
                        }
                        else
                        {
                            cout << "Incorrect index\n";
                        }

                        break;
                    }
                    case 11:
                    {
                        int value;
                        InputWithMessage("Enter the value for remove: ", value);

                        if (RemoveByValue(dynamicArray, value))
                        {
                            cout << "Element was removed\n";
                        }
                        else
                        {
                            cout << "Elements with this value was not found\n";
                        }

                        break;
                    }
                    default:
                    {
                        cout << "Incorrect choice\n";
                    }
                }

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
                InputWithMessage("Enter the index of element(0-" + to_string(dynamicArray->Size - 1) + "): ", index);

                if (ValueIsBorded(index, 0, dynamicArray->Size - 1))
                {
                    cout << GetElement(dynamicArray, index) << endl;
                }
                else
                {
                    cout << "Incorrect index\n";
                }

                break;
            }
            case 7:
            {
                SortArrayShell(dynamicArray);
                WriteArray(dynamicArray);
                cout << endl;

                break;
            }
            case 8:
            {
                //TODO: refactor +              
                int subManualsIndexes[] = {12, 13};
                int numberOfManuals = sizeof(subManualsIndexes) /
                                      sizeof(subManualsIndexes[0]);
                WriteManual(manuals, subManualsIndexes, numberOfManuals);
                int choice;
                cin >> choice;

                cout << endl;
                if (ValueIsBorded(choice, 0, numberOfManuals - 1))
                {
                    int value;
                    int index;

                    switch (subManualsIndexes[choice])
                    {
                        case 12:
                        {
                            //TODO: duplication +
                            InputWithMessage("Enter value for search: ", value);
                            index = LinearSearch(dynamicArray, value);

                            break;
                        }
                        case 13:
                        {
                            //TODO: duplication +
                            InputWithMessage("Enter value for search: ", value);
                            index = BinarySearch(dynamicArray, value);

                            break;
                        }
                    }

                    string trueMessage = "Your value(" + to_string(value) + ") has index " + to_string(index) + '\n';
                    OutputWithCondition(ValueIsBorded(index, 0, dynamicArray->Size - 1), trueMessage, "Not found\n");
                }
                else
                {
                    cout << "Incorrect choice\n";
                }

                break;
            }
            case 9:
            {
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

    //TODO: switch-case +
    switch (number)
    {
        case 1:
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

            break;
        }
        case 2:
        {
            string manuals[] = { "Create dynamic array\n", "Write array\n", "Add element\n",
                     "Remove element\n", "Get size\n", "Get capacity\n", "Get element\n",
                     "Sort array\n", "Search element\n", "Exit\n", "Remove by index\n",
                     "Remove by value\n", "Linear search\n",
                     "Binary search(for sorted array)\n", "Delete dynamic array\n" };
            //TODO: глобальная область видимости - зло +
            DynamicArray* dynamicArray = nullptr;

            while (true)
            {
                int* manualsIndexes;
                int size;
                if (dynamicArray == nullptr)
                {
                    size = 2;
                    manualsIndexes = new int[size] {0, 9};       
                }
                else
                {
                    size = 10;
                    manualsIndexes = new int[size] {1, 2, 3, 4, 5, 6, 7, 8, 14, 9};
                }
                WriteManual(manuals, manualsIndexes, size);

                int choice;
                cin >> choice;
                RequestExecution(choice, manualsIndexes, size, dynamicArray, manuals);

                delete[] manualsIndexes;

                break;
            }
        }
    }
}