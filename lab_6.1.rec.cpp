#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Рекурсивна функція формування масиву за допомогою генератора випадкових чисел
void Create(int* p, const int size, const int Low, const int High, int i)
{
    p[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(p, size, Low, High, i + 1);
}

// Рекурсивна функція виведення масиву в рядок
void Print(const int* p, const int size, int i)
{
    cout << setw(4) << p[i];
    if (i < size - 1)
        Print(p, size, i + 1);
    else
        cout << endl;
}

// Рекурсивна функція обчислення кількості елементів, що задовольняють критерію (від'ємні парні)
int Count(const int* p, const int size, int i)
{
    if (i < size)
    {
        if (p[i] < 0 && p[i] % 2 == 0)
            return 1 + Count(p, size, i + 1);
        else
            return Count(p, size, i + 1);
    }
    else
        return 0;
}

// Рекурсивна функція обчислення суми елементів, що задовольняють критерію (від'ємні парні)
int Sum(const int* p, const int size, int i)
{
    if (i < size)
    {
        if (p[i] < 0 && p[i] % 2 == 0)
            return p[i] + Sum(p, size, i + 1);
        else
            return Sum(p, size, i + 1);
    }
    else
        return 0;
}

// Рекурсивна функція заміни нулями елементів, що задовольняють критерію
void UpdateArray(int* p, const int size, int i)
{
    if (i < size)
    {
        if (p[i] < 0 && p[i] % 2 == 0)
        {
            p[i] = 0;
        }
        UpdateArray(p, size, i + 1);
    }
}

int main()
{
    // Ініціалізація генератора випадкових чисел
    srand((unsigned)time(NULL));

    const int SIZE = 20;
    const int Low = -20;
    const int High = 34;

    int p[SIZE];

    // Формування та виведення початкового масиву (з індексу 0)
    Create(p, SIZE, Low, High, 0);
    cout << "Initial array:" << endl;
    Print(p, SIZE, 0);
    cout << endl;

    // Рекурсивне обчислення кількості та суми
    int c = Count(p, SIZE, 0);
    int s = Sum(p, SIZE, 0);

    cout << "Count = " << c << endl;
    cout << "Sum = " << s << endl;
    cout << endl;

    // Рекурсивна модифікація масиву (заміна нулями) та виведення результату
    UpdateArray(p, SIZE, 0);
    cout << "Modified array:" << endl;
    Print(p, SIZE, 0);
    cout << endl;

    return 0;
}
