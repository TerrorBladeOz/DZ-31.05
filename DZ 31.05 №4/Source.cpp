#include <iostream>
#include <ctime>
#include <cstring>
#include<stdio.h>

using namespace std;

void az() 
{
    for (char c = 'A'; c <= 'Z'; c++)putchar(c); getchar();
}
int** in(int r, int c) 
{
    int** mas = new int* [r];
    for (int i = 0; i < r; i++)
        mas[i] = new int[c] {0};
    return mas;
}
double** dou(double r, double c) 
{ 
    double** mas = new double* [r];
    for (int i = 0; i < r; i++)
        mas[i] = new double[c] {0};
    return mas;
}
char** charing(int r, int c) 
{ 
    char** mas = new char* [r];
    for (int i = 0; i < r; i++)
        mas[i] = new char[c] {0};
    return mas;
}
void sint(int** arr, int n, int m, int a = -10, int b = 100) 
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i][j] = a + rand() % (b - a + 1);
}
void sdou(double** arr, int n, int m, int a = -10, int b = 100) 
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i][j] = a + rand() % (b - a + 1) / static_cast<double>(rand() % 10 + 1);
}
void schar(char** arr, int n, int m) 
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i][j] = 97 + rand() % 26;
}
void pint(int** arr, int n, int m) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << ", ";
        cout << endl;
    }
}
void pdou(double** arr, int n, int m) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << ", ";
        cout << endl;
    }
}
void pchar(char** arr, int n, int m) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << ", ";
        cout << endl;
    }
}
void sortint(int** arr, int n, int m) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            int in = j;
            int min = arr[i][j];
            for (int p = j; p < m; p++)
            {
                if (min > arr[i][p])
                {
                    in = p;
                    min = arr[i][p];
                }
            }
            swap(arr[i][j], arr[i][in]);
        }
    }
}
void sortdouble(double** arr, int n, int m) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            int in = j;
            double min = arr[i][j];
            for (int p = j; p < m; p++)
            {
                if (min > arr[i][p])
                {
                    in = p;
                    min = arr[i][p];
                }
            }
            swap(arr[i][j], arr[i][in]);
        }
    }
}
void sortchar(char** arr, int n, int m) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            int in = j;
            int min = arr[i][j];
            for (int p = j; p < m; p++)
            {
                if (min > arr[i][p])
                {
                    in = p;
                    min = arr[i][p];
                }
            }
            swap(arr[i][j], arr[i][in]);
        }
    }
}
int mindiagonalint(int** arr, int n) 
{
    int min = arr[0][0];
    for (int i = 1; i < n; i++)
        if (min > arr[i][i]) min = arr[i][i];
    return min;
}
double mindiagonaldouble(double** arr, int n) 
{
    double min = arr[0][0];
    for (int i = 1; i < n; i++)
        if (min > arr[i][i]) min = arr[i][i];
    return min;
}
char mindiagonalchar(char** arr, int n)
{
    int min = arr[0][0];
    for (int i = 1; i < n; i++)
        if (min > arr[i][i]) min = arr[i][i];
    return min;
}
int maxdiagonalint(int** arr, int n) 
{
    int max = arr[0][0];
    for (int i = 1; i < n; i++)
        if (max < arr[i][i]) max = arr[i][i];
    return max;
}
double maxdiagonaldouble(double** arr, int n) 
{
    double max = arr[0][0];
    for (int i = 1; i < n; i++)
        if (max < arr[i][i]) max = arr[i][i];
    return max;
}
char maxdiagonalchar(char** arr, int n) 
{
    int max = arr[0][0];
    for (int i = 1; i < n; i++)
        if (max < arr[i][i]) max = arr[i][i];
    return max;
}
void delint(int** arr, int n) // удаление двумерного динамического массива - int
{
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
}
void deldouble(double** arr, int n) // удаление двумерного динамического массива - double
{
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
}
void delchar(char** arr, int n) 
{
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
}
void runint()
{
    cout << "INT>>>\n";
    int n = 4, m = n;
    int** arr = in(n, m);
    srand(time(0));
    sint(arr, n, m);
    cout << "Массив : \n{\n";
    pint(arr, n, m);
    cout << "}\n";
    sortint(arr, n, m);
    cout << "Отсортированный массив: \n";
    cout << "{\n";
    pint(arr, n, m);
    cout << "}\n";
    cout << "Минимальный элемент по диагонали в матрице; " << mindiagonalint(arr, n) << endl;
    cout << "Максимальный элемент по диагонали в матрице; " << maxdiagonalint(arr, n) << endl;
    delint(arr, n);
}
void rundouble()
{
    cout << "DOUBLE>>>\n";
    int n = 4, m = n;
    double** arr = dou(n, m);
    srand(time(0));
    sdou(arr, n, m);
    cout << "Массив : \n{\n";
    pdou(arr, n, m);
    cout << "}\n";
    sortdouble(arr, n, m);
    cout << "Отсортированный массив: \n";
    cout << "{\n";
    pdou(arr, n, m);
    cout << "}\n";
    cout << "Минимальный элемент по диагонали в матрице; " << mindiagonaldouble(arr, n) << endl;
    cout << "Максимальный элемент по диагонали в матрице; " << maxdiagonaldouble(arr, n) << endl;
    deldouble(arr, n);
}
void runchar()
{
    cout << "Английский алфавит "; az(); cout << endl;
    cout << "CHAR>>>\n";
    int n = 4, m = n;
    char** arr = charing(n, m);
    srand(time(0));
    schar(arr, n, m);
    cout << "Массив : \n{\n";
    pchar(arr, n, m);
    cout << "}\n";
    sortchar(arr, n, m);
    cout << "Отсортированный массив: \n";
    cout << "{\n";
    pchar(arr, n, m);
    cout << "}\n";
    cout << "Минимальный элемент по диагонали в матрице; " << mindiagonalchar(arr, n) << endl;
    cout << "Максимальный элемент по диагонали в матрице; " << maxdiagonalchar(arr, n) << endl;
    delchar(arr, n);
}
int main()
{
    setlocale(LC_ALL, "rus");
    int f;
    cout << "Введите тип 1 - int, 2 - double, 3 - char: "; cin >> f;
    switch (f)
    {
    case 1:
        runint();
        break;
    case 2:
        rundouble();
        break;
    case 3:
        runchar();
        break;
    }
    
}