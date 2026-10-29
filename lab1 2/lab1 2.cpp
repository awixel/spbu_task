#include <iostream>
#include <cmath>


using namespace std;
double sum(double a, double b)
{
    return a + b;
}
double pro(double a, double b)
{
    return a * b;
}
double min(double a, double b)
{
    return a - b;
}
double del(double a, double b)
{
    return a / b;
}
double rast(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

}
double polp(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return (rast(x1, y1, x2, y2) + rast(x1, y1, x3, y3) + rast(x3, y3, x2, y2)) / 2;
}
double sqr(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double p = polp(x1, y1, x2, y2, x3, y3);
    double a = rast(x1, y1, x2, y2);
    double b = rast(x1, y1, x3, y3);
    double c = rast(x3, y3, x2, y2);
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double fi(double x)
{
    double p = 3.1415;
    if (x < 0)
    {
        return 7.0 / 3;
    }
    if ((x >= 0) and (x <= 2*p))
    {
        return pow(x, 2) - 3;
    }
    else
    {
        return (1 + pow(x, 3)) / 2 * x;
    }
}
int main()
{
    double first();
    {
        double a, b;
        cin >> a >> b;
        cout << sum(pro(5, (sum(min(a, 2), b))), pro(1000, a));
    }
    double sec();
    {
        double x1=-1, y1=-1, x2=-5, y2=-1, x3=-5, y3=-5,x4=-1,y4=-5, truesqr = INT_MIN;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        cout << rast(x1, y1, x2, y2) << " rast p2p " << endl;
        cout << rast(x1, y1, 0, 0) << " rast do 0 " << rast(x2, y2, 0, 0) << endl;
        cout << sqr(x1, y1, x2, y2, x3, y3) << " " << x1 << "," << y1 << "|" << x2 << "," << y2 << "|" << x3 << "," << y3 << endl;
        double var1 = sqr(x3,y3, x1, y1, x2, y2) + sqr(x4, y4, x1, y1, x3, y3);
        double var2 = sqr(x4, y4, x1, y1, x2, y2) + sqr(x4, y4, x1, y1, x3, y3);
        double var3 = sqr(x3, y3, x1, y1, x2, y2) + sqr(x4, y4, x2, y3, x3, y3);
        ((var1 > var2) and (var1 > var3)) ? truesqr = var1 : truesqr = 0;
        ((var2 > var1) and (var2 > var3)) ? truesqr = var2 : truesqr = 0;
        ((var3 > var2) and (var3 > var1)) ? truesqr = var3 : truesqr = 0;
        double plo = sqr(x1,y1,x2,y2,x3,y3) + sqr(x1, y1, x4, y4, x3, y3);
        cout << plo << " square" << endl;
        cout << x1 << "," << y1 << "|" << x2 << "," << y2 << "|" << x3 << "," << y3 << "|" << x4 << "," << y4 << endl;
    }
    
        double e, r, maxi = -10000000;
        int c = 0;
        double x[7];
        double y[7];
        cin >> e >> r;
        cout << 12.5 + fi(2) - fi(4) * fi(10) + fi(e) - fi(r) + fi(e * r);
        for (int i = 0; i < 7; i++)
        {
            cin >> x[i];
            y[i] = fi(x[i]);
            cout << x[i] << " " << y[i] << endl;
            if (y[i] < 0)
            {
                c++;
            }
            if (y[i] > maxi)
            {
                maxi = y[i];
            }

        }
        cout << c << " " <<maxi;
    
    
}
