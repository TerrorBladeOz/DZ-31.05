// 4 и 5 задания в других файлах
#include <iostream>
#include <windows.h>

using namespace std;

bool year(int y)
{
    bool r = false;
    if (y % 4 == 0)
        r = true;
    if (y % 100 == 0)
        r = false;
    if (y % 400 == 0)
        r = true;
    return r;
}

int date(int d, int m, int y)
{
    int k = d;
    switch (m - 1)
    {
    case 12: k += 31;
    case 11: k += 30;
    case 10: k += 31;
    case  9: k += 30;
    case  8: k += 31;
    case  7: k += 31;
    case  6: k += 30;
    case  5: k += 31;
    case  4: k += 30;
    case  3: k += 31;
    case  2: if (year(y)) k += 29; else k += 28;
    case  1: k += 31;
    }
    k += (y - 1) * 365 + ((y - 1) / 4);
    return k;
}

int dif(int d1, int d2, int m1, int m2, int y1, int y2)
{
    int k = date(d1, m1, y1) - date(d2, m2, y2);
    return k;
}

void average(int n)
{
    double sum = 0 , ave = 0;
    int* dig = new int[n];
    cout << "Введите " << n << " чисел для заполнения массива: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> dig[i];
    }

    cout << "\nМассив >>> { ";

    for (int i = 0; i < n; i++)
    {
        cout << dig[i] << ", ";
    }
    cout << "}\n";

    for (int i = 0; i < n; i++)
    {
        sum = sum + dig[i];
    }
    ave = sum / n;
    cout << "Среднее арифметическое массива равно = " << ave;
}

void pl(int* dig,int n)
{
    int in = 0, inn = 0, iin = 0;
    for (int i = 0; i < n; i++)
    {
        if (dig[i] == 0){ in++; }
        else if (dig[i] < 0) { iin++; }
        else if (dig[i] > 0) { inn++; }
    }
    cout << "В данном массиве " << in << " элементов равных нулю\n";
    cout << "В данном массиве " << iin << " элементов больше нуля\n";
    cout << "В данном массиве " << inn << " элементов меньше нуля\n";
}

int mod(int  a, int  b)
{
    if (!b) return a;
    return mod(b, a % b);
}

void a1()
{
   
    int d1, d2, m1, m2, y1, y2;
    cout << "Введите первый день: ";
    cin >> d2;
    cout << "Введите первый месяц: ";
    cin >> m2;
    cout << "Введите первый год: ";
    cin >> y2;
    cout << "Введите второй день: ";
    cin >> d1;
    cout << "Введите второй месяц: ";
    cin >> m1;
    cout << "Введите второй год: ";
    cin >> y1;
    cout << "Разность в днях: " << dif(d1, d2, m1, m2, y1, y2) << " дней.\n";
}

void a2()
{
    
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    average(n); 
}

void a3()
{
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    int* dig = new int[n];
    cout << "Массив >>> { ";
    for (int i = 0; i < n; i++)
    {
        dig[i] = rand() % 11 - 5;
        cout << dig[i] << ", ";
    }
    cout << "}\n";
    pl(dig,n);
    cout << "\n";
}

void a4()
{
    int a, b;
    cout << "Введите первое число: "; cin >> a;
    while (a < 0)
    {
        cout <<"\nЧисло должно быть положительным, повторите попытку: "; cin >> a;
    }
    cout << "Введите второе число: "; cin >> b;

    cout << "Наибольший делитель "<< mod(a, b)<<endl;

}

void main()
{
    setlocale(LC_ALL, "rus");
    int f;
    do {
        cout << "1 - 4 >>> "; cin >> f;
        switch (f)
        {
        case 1:
            a1();
            break;
        case 2:
            a2();
            break;
        case 3:
            a3();
            break;
        case 4:
            a4();
            break;
        }
    } while (f != 0);
}
