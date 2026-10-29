#include <string> 
#include <iostream>
#include <cmath>
#include <locale.h>
using namespace std;

void kvad(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < m; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < n; i++)
        {
            cout << " * ";
        }
        cout << endl;
    }
}
void chess(int n, int m) {
   
    int totalSize = n * m;
    
    for (int i = 0; i < totalSize; i++) {
        for (int j = 0; j < totalSize; j++) {
            
            int x = i / m;
            int y = j / m;

            
            if ((x + y) % 2 == 0) {
                std::cout << '1';
            }
            else {
                std::cout << '0';
            }
        }
        cout << endl;
    }
}
long double fact(long double n)
{   
    long double res = 1;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res;
}
double stepen(int n, int m)
{
    long long res = 1;
    double resneg = 1;
    unsigned long long sq = n * n;
    long long cube = n * n * n;
    if (m > 0)
    {
        switch (m)
        {
        case 1:
            return n;
            break;
        case 2:
            return sq;
            break;
        case 3:
            return cube;
            break;
        case 4:
            return sq*sq;
            break;
        case 5:
            return sq*sq*n;
            break;
        }
        if ((m > 5) and (m % 2 == 0))
        {
            for (int i = 1; i <= (m / 2); i++)
            {
                res *= sq;
            }
        }
        if ((m > 5) and (m % 2 != 0) and (m % 3 ==0))
        {
            for (int i = 1; i <= (m / 3); i++)
            {
                res *= cube;
            }
        }
        else
        {
            if ((m > 5) and (m % 2 != 0) and (m % 3 !=0))
            {
                for (int i = 1; i <= (m / 3); i++)
                {
                    res *= cube;
                }
                if (m - ((m / 3) * 3) == 1)
                {
                    res *= n;
                }
                else
                {
                    res *= sq;
                }
                
            }
        }
        return res;
    }
    else
    {
        switch (m)
        {
        case -1:
            return 1.0/n;
            break;
        case -2:
            return 1.0/sq;
            break;
        case -3:
            return 1.0/cube;
            break;
        case -4:
            return 1.0/(sq*sq);
            break;
        case -5:
            return 1.0/(sq*sq*n);
            break;
        }
        if ((abs(m) > 5) and (abs(m) % 2 == 0))
        {
            for (int i = 1; i <= (abs(m) / 2); i++)
            {
                resneg *= sq;
            }
        }
        if ((abs(m) > 5) and (abs(m) % 2 != 0) and (abs(m) % 3 ==0))
        {
            for (int i = 1; i <= (m / 3); i++)
            {
                resneg *= cube;
            }
        }
        else
        {
            if ((abs(m) > 5) and (abs(m) % 2 != 0))
            {
                for (int i = 1; i <= (abs(m) / 3); i++)
                {
                    resneg *= cube;
                }
                if (abs(m) - (abs(m) / 3) * 3 == 1)
                {
                    resneg *= n;
                }
                else
                {
                    resneg *= sq;
                }
            }
        }
        return 1.0/resneg;
    }   
}
void sign(int n)
{
    if (n > 0)
    {
        cout << "+";
        return;
    }
    if (n < 0)
    {
        cout << '-';
        return;
    }
    cout << " ";
}
void number(int n)
{
    switch (abs(n))
    {
    case 0:
        cout << "ноль";
        break;
    case 1:
        cout << "один";
        break;
    case 2:
        cout << "два";
        break;
    case 3:
        cout << "три";
        break;
    case 4:
        cout << "четыри";
        break;
    case 5:
        cout << "пять";
        break;
    case 6:
        cout << "шесть";
        break;
    case 7:
        cout << "семь";
        break;
    case 8:
        cout << "восемь";
        break;
    case 9:
        cout << "девять";
        break;
    case 10:
        cout << "десять";
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    chess(10, 10);
    long double n, m;
    cin >> n >> m;
    cout << fact(n) << " " << fact(m);
    cout << (fact(n) * fact(m)) / fact(n + m);
    int r, t;
    cin >> r>> t;
    cout << stepen(r, t) << " " << pow(r,t) << 1.0/(-81);
    int x;
    cin >> x;
    sign(x);
    number(x);
    
}


