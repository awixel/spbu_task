#include <iostream>
#include <cmath>
using namespace std;
class point
{
	double x;
	double y;
public:
	point() = default;
	point(double x,double y): x{x}, y{y} {}
	double getx()
	{
		return x;
	}
	double gety()
	{
		return y;
	}
	void setx(double x)
	{
		this->x = x;
	}
	void sety(double y)
	{
		this->y = y;
	}
	void out()
	{
		cout << x << " " << y << endl;
	}
	void in(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	double dist(point two)
	{
		return sqrt(pow(x - two.x,2) + pow(y - two.y, 2));
	}
};
class cil
{
	double p = 3.1415;
protected:
	point center;
	point okr;
	double high;
public:
	cil(point c, point x, double h) : center{ c }, okr{ x}, high{ h } {
	};
	point getokr()
	{
		return okr;
	}
	double getHigh()
	{
		return high;
	}
	point getCenter()
	{
		;
	}
	void setokr(double x, double y)
	{
		okr.setx(x);
		okr.sety(y);
	}

	void setHigh(double High)
	{
		this->high = High;
	}

	void setCenter(point Center)
	{
		this->center = Center;
	}
	void out()
	{
		cout << center.getx() << " " << center.gety() << " " << okr.getx() << " "  << okr.gety()<<" " << high << endl;
	} 
	virtual void in(point c, point x, double h)
	{
		cil(c, x, h);
	}
	
	virtual double Sosn()
	{
		return p * center.dist(okr) * center.dist(okr);
	}
	virtual double Losn()
	{
		return p * 2 * center.dist(okr);
	}
	double v()
	{
		return Sosn() * high;
	}
	double Sbok()
	{
		return Losn() * high;
	}
};
class prism : public cil
{
public:
	double side1 = center.dist(okr);
	double side2 = center.dist(third);
	double side3 = okr.dist(third);
	prism() = default;
	prism(point c, point x, double h, point th) : cil(c, x, h), third(th) {}
	point getT()
	{
		return third;
	}
	void setT(double x, double y)
	{
		third.setx(x);
		third.sety(y);
	}
	void in(point c, point x, double h, point th)
	{
		this->center.in(c.getx(), c.gety());
		this->okr.in(x.getx(), x.gety());
		third.in(th.getx(), th.gety());
		setHigh(h);
	}
	double Sosn() override
	{
		return triS();
	}
	double Losn()
	{
		return side1 + side2 + side3;
	}
protected:
	point third;
	double triS()
	{

		double polp = (side1 + side2 + side3) / 2;
		return sqrt(polp * (polp - side1) * (polp - side2) * (polp - side3));
	}
};
class prism4 : public prism
{
	point fourth; 
	double side1 = center.dist(okr);
	double side2 = center.dist(third);
	double side3 = okr.dist(fourth);
	double side4 = fourth.dist(getT());
public:
	prism4(point c, point x, double h, point th, point fourth) : prism(c, x, h, th), fourth(fourth) {}
	point getF()
	{
		return fourth;
	}
	void setF(double x, double y)
	{
		fourth.setx(x);
		fourth.sety(y);
	}
	double Losn() override
	{
		
		return side1 + side2 + side3 + side4;
	}
	double Sosn() override
	{
		return side1 * side2 * getHigh();
	}
};
int main()
{
	
	point c, okr, th, fo;
	double h,x,y,q,w, r,t, i,u;
	cin >> x >> y >> q >> w >>r >> t>> i >> u >> h;
	c.in(x, y);
	okr.in(q, w);
	th.in(r,t);
	fo.in(i, u);
	prism4 fig(c, okr, h, th, fo);
	cout << fig.v() << " " << fig.Sbok();
}