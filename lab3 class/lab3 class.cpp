#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <cmath>
using namespace std;
class raz
{
    int p{ 1 }, q{ 1 };
public:
    raz() = default;
    raz(int w, int e)
    {
        set_p(w);
        set_q(e);
    }
    raz(int r, int w, int e)
    {
        set_p(r * e + w);
        set_q(e);
    } 
    raz(const raz& other) : p(other.p), q(other.q) {};

    int get_p()
    {
        return p;
    }
    int get_q()
    {
        return q;
    }
    void set_p(int x)
    {
        p = x;
    }
    void set_q(int x)
    {
        if (x != 0)
        {
            q = x;
        }
        else
        {
            cout << "знаменатель не может быть 0";
            exit(0);
        }
    }
    int whole()
    {
        return p / q;
    }
    int chisl()
    {
        return abs(p - (p / q) * q);
    }
    void sokr()
    {
        int nod=1;
        for (int i = 2; i <= abs(p); i++)
        {
            if ((abs(p) % i == 0) and (abs(q) % i == 0))
            {
                nod = i;
            }
        }
        p = p / nod;
        q = q / nod;
    }
    void in(int& f, int& g)
    {
        set_p(f);
        set_q(g);

    }
    void out()
    {
        sokr();
        char c;
        if (((p > 0) and (q > 0)) or ((p < 0) and (q < 0)))
        {
            c = ' ';
        }
        else
        {
            c = '-';
        }
        if (p == 0)
        {
            cout << 0 << endl;
            return;
        }
        if(abs(p)< abs(q))
        {
            cout << c <<abs(p) << "/" << abs(q) << endl;
            return;
        }
        if (p % q == 0)
        {
            cout << p / q << endl;
            return;
        }
        
        else
        {
            cout << whole() << " " << chisl() << "/" << abs(q) << endl;
        }
    }
    
    friend raz operator+(const raz& other, const raz& second) {
        return raz(second.p * other.q + other.p * second.q, second.q * other.q);
    }
    friend raz operator-(const raz& first, const raz& other) {
        return raz(first.p * other.q - other.p * first.q, first.q * other.q);
    }
    friend raz operator*(const raz& other, const raz& first)  {

        return raz(first.p * other.p, first.q * other.q);
    }
    friend raz operator/(const raz& first,const raz& other) {
        if (other.p !=0)
        {
            return raz(first.p * other.q, first.q * other.p);
        }
        else
        {
            exit(0);
        } 
    }
    friend bool operator==(raz& f,raz& other)
    {
        if ((f.p == other.p) and (f.q == other.q))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    friend bool operator!=(const raz& f, const raz& other)
    {
        if ((f.p == other.p) and (f.q == other.q))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    friend bool operator>(const raz& f, const raz& other)
    {
        if ((f.p * other.q) > (other.p * f.q))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    friend bool operator<(raz& f, raz& other)
    {
        if ((f.p*other.q) < (other.p*f.q))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    setlocale(LC_ALL, "Russian");
    /*int a, b, c,d; блок проверок функций, можно убрать
    raz one, two;
    cout << "введите числитель и знаменатель первой дроби" << endl;
    cin >> a >> b;
    one.in(a, b);
    cout << "введите числитель и знаменатель второй дроби" << endl;
    cin >> b >> c;
    two.set_p(b);
    two.set_q(c);
    one.sokr();
    two.sokr();     1
    one.out();
    two.out();
    cout << one.get_p() << " " << two.get_p() << " числитель" << endl;
    cout << one.get_q() << " " << two.get_q() << " знаменатель" << endl;
    (one.get_p() > two.get_p()) ? one.out() : two.out();
    /*cout << one.chisl() << " " << one.whole();*/
   /* raz o{ 4, 3 };
    raz d{5, 1, 7}; 
    raz t{o};
    o.out();
    d.out();
    t.out();
    o.set_p(5);
    o.set_q(o.get_q() * 3);
    d.set_p(d.get_p() - 2);
    t.set_p(t.get_p() + 10);
    t.set_q(t.get_q() *10);
    o.out();
    d.out();
    t.out();*/
   /* raz d(2, 3);
    raz f(1, 2);
    raz rt = d / f;
    bool r = d < f;
    rt.out();
    cout << r;
    */
    raz mas[5];
    raz sum{1,1};
    raz odin{ 1,1 };
    raz multy = { 1,1 };
    raz min{ INT_MAX , 1}, max{ INT_MIN,1};
    for (int i = 0; i < 5; i++)
    {
        int a, b; cin >> a >> b;
        mas[i].in(a, b);
        sum = sum + mas[i];
        multy = multy * mas[i];
        if (mas[i] > max)
        {
            max = raz(mas[i]);
        }
        if (mas[i] < min)
        {
            min= raz(mas[i]);
        }
    }
    sum = sum - odin;
    sum.out();
    multy.out();
    min.out();
    max.out();
}


