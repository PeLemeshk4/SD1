#include <iostream>
#include <string>
#include "..\Header files\DynamicArray.h"
#include <chrono>

using namespace std;

/*
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
*/

//! \brief Выводит инструкции в консоль из manuals по индексам из manualsIndexes.
//! \param manuals Список со всеми инструкциями.
//! \param manualsIndexes Список с индексами для списка с инструкциями.
//! \param length Длина массива manualsIndexes.
string WriteManual(string* manuals, int* manualsIndexes, int length)
{
    string message = "\nManual:\n";

    for (int i = 0; i < length; i++)
    {
        message += to_string(i) + ". " + manuals[*(manualsIndexes + i)];
    }
    return message;
}

//! \brief Выводит в консоль массив из структуры.
//! \param dynamicArray Структура динамического массива.
string WriteArray(DynamicArray*& dynamicArray)
{
    int i;
    string message = "Array: ";
    for (i = 0; i < dynamicArray->Size; i++)
    {
        message += to_string(*(dynamicArray->Array + i)) + ' ';
    }
    message += '\n';
    return message;
}

//! \brief Выводит сообщение в консоль и записывает введённое значение в переменную.
//! \param message Сообщение, которое выведется в консоль.
//! \param varriable Переменная в которую впишется введённое значение из консоли.
int InputWithMessage(string message)
{
    int varriable;
    cout << message;
    cin >> varriable;
    return varriable;
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
string OutputWithCondition(bool condition, string trueMessage, string falseMessage)
{
    if (condition)
    {
        return trueMessage;
    }
    else
    {
        return falseMessage;
    }
}

//! \brief Выполняет запрос по выбранной инструкции.
//! \param choice Выбранная инструкция из выведенных.
//! \param manualsIndexes Список с индексами выведенных инструкций.
//! \param size Количество выведенных инструкций.
//! \param dynamicArray Структура динамического массива.
//! \param manuals Массив со всеми инструкциями.
void RequestExecution(int choice, int* manualsIndexes, int size, 
    DynamicArray*& dynamicArray, string* manuals)
{
    if (ValueIsBorded(choice, 0, size - 1))
    {
        cout << endl;
        switch (manualsIndexes[choice])
        {
            case 0:
            {
                int size = InputWithMessage("Enter size of array: ");
                int capacity = InputWithMessage("Enter capacity of array: ");

                dynamicArray = CreateDynamicArray(size, capacity);

                cout << WriteArray(dynamicArray);

                break;
            }
            case 1:
            {
                cout << WriteArray(dynamicArray);

                break;
            }
            case 2:
            {
                int index = InputWithMessage("Enter index for new element(0-" +
                    to_string(dynamicArray->Size) + "): ");

                int value = InputWithMessage("Enter value for new element: ");

                cout << OutputWithCondition(
                    AddElement(dynamicArray, index, value),
                    "Element was added\n", "Incorrect index\n");

                break;
            }
            case 3:
            {
                int subManualsIndexes[] = {10, 11};
                int numberOfManuals = sizeof(subManualsIndexes) /
                                      sizeof(subManualsIndexes[0]);
                int choice = InputWithMessage(
                    WriteManual(manuals, subManualsIndexes, numberOfManuals));

                cout << endl;
                switch (subManualsIndexes[choice])
                {
                    case 10:
                    {
                        int index = InputWithMessage(
                            "Enter index of element for remove(0-" +
                            to_string(dynamicArray->Size - 1) + "): ");

                        cout << OutputWithCondition(
                            RemoveByIndex(dynamicArray, index),
                            "Element was removed\n", "Incorrect index\n");

                        break;
                    }
                    case 11:
                    {
                        int value = InputWithMessage("Enter the value for remove: ");

                        cout << OutputWithCondition(
                            RemoveByValue(dynamicArray, value),
                            "Element was removed\n", 
                            "Elements with this value was not found\n");

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
                int index = InputWithMessage(
                    "Enter the index of element(0-" +
                    to_string(dynamicArray->Size - 1) + "): ");

                cout << OutputWithCondition(
                    ValueIsBorded(index, 0, dynamicArray->Size - 1),
                    to_string(GetElement(dynamicArray, index)) + '\n',
                    "Incorrect index\n");

                break;
            }
            case 7:
            {
                SortArrayShell(dynamicArray);
                cout << WriteArray(dynamicArray);

                break;
            }
            case 8:
            {
                int subManualsIndexes[] = {12, 13};
                int numberOfManuals = sizeof(subManualsIndexes) /
                                      sizeof(subManualsIndexes[0]);

                int choice = InputWithMessage(
                    WriteManual(manuals, subManualsIndexes, numberOfManuals));

                cout << endl;
                if (ValueIsBorded(choice, 0, numberOfManuals - 1))
                {
                    int value;
                    int index;

                    switch (subManualsIndexes[choice])
                    {
                        case 12:
                        {
                            value = InputWithMessage("Enter value for search: ");
                            index = LinearSearch(dynamicArray, value);

                            break;
                        }
                        case 13:
                        {
                            value = InputWithMessage("Enter value for search: ");
                            index = BinarySearch(dynamicArray, value);

                            break;
                        }
                    }

                    string trueMessage = "Your value(" + to_string(value) +
                        ") has index " + to_string(index) + '\n';

                    cout << OutputWithCondition(
                        ValueIsBorded(index, 0, dynamicArray->Size - 1),
                        trueMessage, "Not found\n");
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

//! \brief Операция для замера времени.
//! \param operationNumber Номер выбранной операции.
//! \param manuals Список со всеми операциями.
//! \param n Размер массива.
//! \param iterationsCount Количество выполнений этой операции.
void Task3Request(int operationNumber, string* manuals, int n, int iterationsCount)
{
    DynamicArray* array = CreateDynamicArray(n, n + 1);
    switch (operationNumber)
    {
        case 0:
        {
            auto start = chrono::high_resolution_clock::now();
            for (int i = 0; i < iterationsCount; i++)
            {
                GetElement(array, n / 2);
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
            double timeOfOperation = static_cast<double>(duration.count()) / iterationsCount;
            cout << timeOfOperation << '\n';
            break;
        }
        case 1:
        {
            auto start = chrono::high_resolution_clock::now();
            for (int i = 0; i < iterationsCount; i++)
            {
                AddElement(array, 0, 10);
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
            double timeOfOperation = static_cast<double>(duration.count()) / iterationsCount;
            cout << timeOfOperation << '\n';
            break;
        }
        case 2:
        {
            double measurementsSum = 0;
            for (int i = 0; i < iterationsCount; i++)
            {
                auto start = chrono::high_resolution_clock::now();
                AddElement(array, n / 2, 10);
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
                measurementsSum += static_cast<double>(duration.count());
            }
            double timeOfOperation = measurementsSum / iterationsCount;
            cout << timeOfOperation << '\n';
            break;
        }
        case 3:
        {
            auto start = chrono::high_resolution_clock::now();
            for (int i = 0; i < iterationsCount; i++)
            {
                RemoveByIndex(array, 0);
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
            double timeOfOperation = static_cast<double>(duration.count()) / iterationsCount;
            cout << timeOfOperation << '\n';
            break;
        }
        case 4:
        {
            double measurementsSum = 0;
            for (int i = 0; i < iterationsCount; i++)
            {
                auto start = chrono::high_resolution_clock::now();
                RemoveByIndex(array, n / 2);
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
                measurementsSum += static_cast<double>(duration.count());
            }
            double timeOfOperation = measurementsSum / iterationsCount;
            cout << timeOfOperation << '\n';
            break;
        }
        case 5:
        {
            exit(0);

            break;
        }
    }
}

int main()
{
    cout << "\tStructure of data #1:\n";
    int number = InputWithMessage("Enter the number of task(1-3): ");

    switch (number)
    {
        case 1:
        {/*
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
            */
            break;
        }
        case 2:
        {
            string manuals[] = 
            { 
                "Create dynamic array\n", "Write array\n", "Add element\n",
                "Remove element\n", "Get size\n", "Get capacity\n", 
                "Get element\n", "Sort array\n", "Search element\n", 
                "Exit\n", "Remove by index\n", "Remove by value\n", 
                "Linear search\n", "Binary search(for sorted array)\n", "Delete dynamic array\n" 
            };
            DynamicArray* dynamicArray = nullptr;

            while (true)
            {
                int size = dynamicArray != nullptr
                    ? 10
                    : 2;
                int* manualsIndexes = dynamicArray == nullptr
                    ? new int[size] { 0, 9 }
                    : new int[size] { 1, 2, 3, 4, 5, 6, 7, 8, 14, 9 };

                //TODO: duplication+
                int choice = InputWithMessage(
                    WriteManual(manuals, manualsIndexes, size));
                    RequestExecution(choice, manualsIndexes, size,
                    dynamicArray, manuals);

                delete[] manualsIndexes;
            }
        }
        case 3:
        {
            string manuals[] = { "Index access.\n", "Insert at the beginning.\n",
                "Insert in the middle.\n", "Delete from the beginning.\n",
                "Delete from the middle.\n", "Exit.\n" };
            int size = 6;
            int* manualsIndexes = new int[size] { 0, 1, 2, 3, 4, 5 };
            int iterationsCount = 1000;
            while (true)
            {
                int operationNumber = InputWithMessage(WriteManual(manuals, manualsIndexes, size));
                cout << endl;
                if (operationNumber >= 0 && operationNumber < size)
                {
                    int operationIndex = manualsIndexes[operationNumber];
                    for (int n = 1000; n <= 1000000; n *= 10)
                    {
                        Task3Request(operationIndex, manuals, n, iterationsCount);
                    }                                 
                }
                else
                {
                    cout << "Incorrect choice.\n";
                }
            }
            break;
        }
        default:
        {
            cout << "Incorrect choice.\n";
            break;
        }
    }
}