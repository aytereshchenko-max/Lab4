#include <iostream>
#include <cmath>
using namespace std;

/* =====================================================
   =============== ЗАВДАННЯ 1 ==========================
   ===================================================== */

/* ---------- Proc9 ---------- */
void AddLeftDigit(int D, int &K) 
{
    if (K < 10)
        K = D * 10 + K;
    else if (K < 100)
        K = D * 100 + K;
    else
        K = D * 1000 + K;
}

/* ---------- Proc44 ---------- */
double TriangleAreaByPoints(double x1, double y1,
                            double x2, double y2,
                            double x3, double y3) 
{
    return 0.5 * fabs((x2 - x1) * (y3 - y1)
                    - (x3 - x1) * (y2 - y1));
}

/* ---------- Процедура Завдання 1 ---------- */
void task1() 
{
    cout << "\n--- Завдання 1 (Proc9 + Proc44) ---\n";

    // Proc9
    int K, D1, D2;
    cout << "Введіть K (0 < K < 1000): ";
    cin >> K;
    cout << "Введіть D1 (1..9): ";
    cin >> D1;
    cout << "Введіть D2 (1..9): ";
    cin >> D2;

    AddLeftDigit(D1, K);
    cout << "Після додавання D1: " << K << endl;

    AddLeftDigit(D2, K);
    cout << "Після додавання D2: " << K << endl;

    // Proc44
    double x1, y1, x2, y2, x3, y3;
    cout << "\nВведіть координати 3 трикутників:\n";

    for (int i = 1; i <= 3; i++) 
    {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        cout << "Площа трикутника " << i << ": "
             << TriangleAreaByPoints(x1, y1, x2, y2, x3, y3)
             << endl;
    }
}

/* =====================================================
   =============== ЗАВДАННЯ 2 ==========================
   ===================================================== */

/* --- 1. Ввід з перевіркою --- */
bool inputInteger16(int &x) 
{
    cout << "Введіть тризначне число: ";
    cin >> x;

    if (x < 100 || x > 999) 
    {
        cout << "Помилка! Число не є тризначним.\n";
        return false;
    }
    return true;
}

/* --- 2. Обчислення --- */
int calcInteger16(int x) 
{
    int a = x / 100;        // сотні
    int b = (x / 10) % 10;  // десятки
    int c = x % 10;         // одиниці
    return a * 100 + c * 10 + b;
}

/* --- 3. Виведення --- */
void printInteger16(int result) 
{
    cout << "Результат: " << result << endl;
}

/* ---------- Процедура Завдання 2 ---------- */
void task2() 
{
    cout << "\n--- Завдання 2 (Integer16) ---\n";

    int x;
    if (!inputInteger16(x)) 
    {
        cout << "Обчислення не виконано.\n";
        return;
    }

    int result = calcInteger16(x);
    printInteger16(result);
}

/* =====================================================
   =============== ЗАВДАННЯ 3 ==========================
   ===================================================== */

/* ---------- MAIN + МЕНЮ ---------- */
int main() 
{
    int choice;

    do 
    {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1 - Завдання 1 (Proc9, Proc44)\n";
        cout << "2 - Завдання 2 (Integer16)\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 0:
                cout << "Завершення програми.\n";
                break;
            default:
                cout << "Невірний вибір!\n";
        }

    } 
    while (choice != 0);

    return 0;
}
