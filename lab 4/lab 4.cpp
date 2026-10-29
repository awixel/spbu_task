//
//#include <iostream>
//#include <cmath>
//using namespace std;
//struct date
//{
//    unsigned int day;
//    unsigned int month;
//    unsigned int year;
//    date() : day(1), month(1), year(0) {}
//    date(int d, int m, int y) : day(d), month(m), year(y) {}
//};
//class Person 
//{
//    string name;
//    string surname;
//    char sex;
//    date d;
//public:
//    Person() = default;
//    Person(string n, string sn, char s, int day, int month, int year): name(n), surname(sn), sex(s), d(day, month, year) {
//    }
//    string getName() const {
//        return name;
//    }
//    string getSurname() const {
//        return surname;
//    }
//    char getSex() const {
//        return sex;
//    }
//    date getDate() const {
//        return d;
//    }   
//    void setName( string n) {
//        name = n;
//    }
//    void setSurname(string sn) {
//        surname = sn;
//    }
//    void setSex(char s) {
//        if (s == 'm' or s == 'f') {
//            sex = s;
//        }
//        else {
//            cout << "Ошибка: пол должен быть 'M' или 'F'" << endl;
//            sex = 'M'; 
//        }
//    }
//    void setDate(unsigned int day, unsigned int month, unsigned int year) {
//        if ((day < 32) and (month < 13))
//        {
//            d.day = day;
//            d.month = month;
//            d.year = year;
//        }
//        
//    }
//    void in(string n, string sn, char s, int day, int month, int year)
//    {
//        name = n;
//        surname = sn;
//        sex = s;
//        d.day = day;
//        d.month = month;
//        d.year = year;
//    }
//    virtual void out()
//    {
//        cout << name << " " << surname << ' ' << sex << ' ' << d.day << " " << d.month << " " << d.year << endl;
//    }
//    friend ostream& operator<<(ostream& os, const Person one) {
//        os << one.name << " " << one.surname << ' ' << one.sex << " " << one.d.year << ' ' << one.d.month << ' ' << one.d.day << endl;
//        return os;
//    }
//    friend bool operator>(const Person& one, const Person& two)
//    {
//        int alldayone = (2026 - one.d.year) * 365 + one.d.month * 30 + one.d.day;
//        int alldaytwo = (2026 - two.d.year) * 365 + two.d.month * 30 + two.d.day;
//        if (alldayone > alldaytwo)
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//    friend bool operator<(const Person& one, const Person& two)
//    {
//        int alldayone = (2026 - one.d.year) * 365 + one.d.month * 30 + one.d.day;
//        int alldaytwo = (2026 - two.d.year) * 365 + two.d.month * 30 + two.d.day;
//        if (alldayone < alldaytwo)
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//};
//class employee : public Person
//{
//    double salary;
//    double percent;
//public:
//    employee() : Person(), salary(0.0), percent(0.0){}
//    double getSalary() const {
//        return salary;
//    }
//    double getPercent() const {
//        return percent;
//    }
//    void setSalary(double sal) 
//    {
//        if (sal >= 0) 
//        {
//            salary = sal;
//        }
//        else {
//            cout << "Ошибка: зарплата не может быть отрицательной" << endl;
//        }
//    }
//    void setPercent(double perc) 
//    {
//        if (perc >= 0 and perc <= 100) 
//        {  // Процент обычно от 0 до 100
//            percent = perc;
//        }
//        else {
//            cout << "Ошибка: процент должен быть от 0 до 100" << endl;
//        }
//    }
//    void in(string n, string sn, char s, int day, int month, int year, double sal, double per)
//    {
//        Person::in(n, sn, s, day, month, year);
//        salary = sal;
//        percent = per;
//    }
//    void out() override 
//    {
//        Person::out();
//        cout << salary << " " << percent << endl;
//    }
//    virtual double salprem()
//    {
//        return salary + salary * (percent/100);
//    }
//    double nalog()
//    {
//        return salary * 13/100;
//    }
//    double fulsal()
//    {
//        return salprem() - nalog();
//    }
//};
//class emphour : public employee
//{
//    int hour;
//public:
//    double salprem() override
//    {
//        return getSalary() * hour  + getSalary() * hour * (getPercent() / 100);
//    }
//};
//int main()
//{
//    /*int n; cin >> n;
//    Person* mas = new Person[n];*/
//    /*string name, surname;
//    char sex;
//    int d, m, y;
//    double sal, per;
//    employee one;*/
//    /*int c = 1;
//    Person o("fds", "ds", 'f', 3, 12, 1900);
//    Person k("qwe", "we", 'm', 3, 4, 1999);
//    for (int i = 0; i < n; i++)
//    {
//        cin >> name >> surname >> sex >> y >> m >> d;
//        mas[i].in(name, surname, sex, y, m, d);
//    }
//    int f = 0;
//    while (f < n - 1)
//    {
//        f = 0;
//        for (int i = 1; i < n; i++)
//        {
//            if (mas[i] < mas[i - 1])
//            {
//                swap(mas[i], mas[i - 1]);
//
//            }
//            else
//            {
//                f++;
//            }
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        cout << mas[i];
//    }
//
//    delete[] mas;*/
//    /*cin >> name >> surname >> sex >> y >> m >> d >> sal >> per;
//    one.in(name, surname, sex, d,m,y,sal,per);
//    one.out();
//    cout << one.fulsal() << " " << one.nalog() << " " << one.salprem();*/
//}

