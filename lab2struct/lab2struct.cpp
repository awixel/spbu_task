

#include <iostream>
#include <locale.h>
using namespace std;
struct house
{
    string street{ "a" };
    unsigned int number{ 0 };
    double sqr{ 0 };
    double value{ 0 };
    void print()
    {
        cout << street << " " << number << " " << sqr << " " << value;
    }
    void set_n(int n)
    {
        if (n > 0)
        {
            number = n;
        }
    }
    void set_sqr(double n)
    {
        if (n > 0)
        {
            sqr = n;
        }
    }
    void set_value(double n)
    {
        if (n > 0)
        {
            value = n;
        }
    }
    double rentcounter()
    {
        return sqr* value;
    }
    
};
int main()
{
    setlocale(LC_ALL, "Russian");
    house one,two;
    int c;
    double r, t;
    cin >> one.street >> c >> r >> t;
    one.set_n(c);
    one.set_sqr(r);
    one.set_value(t);
    two.street= "Кремлевская" ;
    two.number = 18;
    two.sqr = 200;
    two.value = 10000;
    if (one.rentcounter() == two.rentcounter())
    {
        cout << "равны";
    }
    else
    {
        (one.rentcounter() < two.rentcounter()) ? one.print() : two.print();
    }
    


}


