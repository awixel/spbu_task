#include <iostream>
#include <random>
#include<locale.h> 
#include <cstdlib>
#include <windows.h>
using namespace std;
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distrib(1, 100);

int Truerand()
{
    return distrib(gen);
}

class Bichara
{
    string name = "base";
    double damage{ 10 };
    double health{100};
    double protection{ 1 };
    double crit{10};
    unsigned short lifestatus{1};
    unsigned short critstatus{0};
    double miss{10};
    double critChance{ 20 };
public:
    Bichara(double damage = 20, int health = 100, double protection = 20,
        double crit = 20, double miss = 20, unsigned short lifestatus = 1,
        unsigned short critstatus = 0, string name = "bichara") :name{name}, damage(damage), health(health),
        protection(protection), crit(crit), miss(miss) {}
    double getHealth() const
    {
        return health;
    }
    double getcritChance()
    {
        return critChance;
    }
    void setcritChance(double a)
    {
        critChance = a;
    }
    double getProtection() const
    {
        return protection;
    }
    double getCrit()
    {
        return crit;
    }
    double getMiss()
    {
        return miss;
    }
    string getname()
    {
        return name;
    }
    void setname(string a)
    {
        name = a;
    }
    unsigned short getcritstat()
    {
        return critstatus;
    }
    void setcritstat(unsigned short a)
    {
        critstatus = a;
    }
    void setDamage(double newDamage)
    {
        damage = newDamage;
    }
    void setHealth(double newHealth)
    {
        if (newHealth < 0)
        {
            health = 0;
        }
        else
        {
            health = newHealth;
        }
    }
    void setProtection(double newProtection)
    {
        protection = newProtection;
    }
    void setCrit(double Crit)
    {
        crit = Crit;
    }
    void setMiss(double Miss)
    {
        miss = Miss;
    }
    void setlifestatus(unsigned short a)
    {
        lifestatus = a;
    }
    unsigned int getlifestatus()
    {
        return lifestatus;
    }
    void out()
    {
        cout << damage << " " << health << " " << protection << " " << crit;
    }
    virtual void in(double damage, int health, double protection, double crit)
    {
        this->damage = damage;
        this->health = health;
        this->protection = protection;
        this->crit = crit;
    }
    virtual void atack(Bichara* a)
    {
        if (Truerand() > miss)
        {
            a->setHealth(a->getHealth() - Critdam() * (1 - a->getProtection() / 100));
            if (getcritstat() == 1)
            {
                cout << "CRITICAL DAMAGE!" << endl;
                Sleep(2000);
                setCrit(20);
                setcritstat(0);
            }
            else
            {
                setCrit(getCrit() + 1.5);
            }
        }
        else
        {
            cout << " MISS! " << endl;
            Sleep(2000);
            return;
        }
        
    }
    virtual double Critdam()
    {
        if (Truerand() <= critChance)
        {
            setcritstat(1);
            return damage + crit;
        }
        else
        {
            return damage;
        }
    }
    void interout()
    {
        cout << getHealth() << " " << getname();
   /*     if (getcritstat() == 1)
        {
            cout << " промах ";
        }*/
    }
    void chekHealth()
    {
        if (health == 0)
        {
            setlifestatus(0);
        }
        else
        {
            return;
        }
    }
};
class Warrior: public Bichara
{
    
public:
    int counter{ 0 };
    Warrior() : Bichara(30, 100, 40, 10,10,1,0,"Warrior") {}
    void atack(Bichara* a) override
    {
        if (counter < 3)
        {
            Bichara::atack(a);
            counter++;
        }
        else
        {
            setcritChance(60);
            Bichara::atack(a);
            counter = 0;
        }
    }
};
class Healer : public Bichara
{
    double heal = 25;
public:
    Healer() : Bichara(0,100, 20, 40,0,1,0,"Healer") {}
    double Critdam() override
    {
        if (Truerand() <= getcritChance())
        {
            setcritstat(1);
            return heal + getCrit();
        }
        else
        {
            return heal;
        }
    }
    void atack(Bichara* a) override
    {
        a->setHealth(Critdam() + a->getHealth());
        if (getcritstat() == 0)
        {
            setcritChance(getcritChance() + 1.5);
        }
        else
        {
            setcritstat(0);
            setcritChance(20);
            cout << " CRIT HEAL! " << endl;
            Sleep(2000);
        }
        if (a->getHealth() > 100)
        {
            a->setHealth(100);
        }
    }
};
class Wizard : public Bichara
{
public:
    Wizard() : Bichara(30, 100, 10, 40, 30, 1, 0, "Wizard") {}
    void atack(Bichara* a)override
    {
        if (Truerand() > getMiss())
        {
            a->setHealth(a->getHealth() - Critdam() * (1 - a->getProtection() / 100));
            a->setProtection(a->getProtection() - 5);
            if (getcritstat() == 1)
            {
                setCrit(20);
                setcritstat(0);
                cout << " CRITICAL DAMAGE! " << endl;
                Sleep(2000);
            }
            else
            {
                setCrit(getCrit() + 1.5);
            }
        }
        else
        {
            cout << " MISS ! " << endl;
            Sleep(2000);
            return;
        }
    }
};

void WOWout(Bichara** team1, Bichara** team2, int size, int roundcount)
{
    if (roundcount % 2 == 1)
    {
        cout << "team 1      <- ход команды      team2" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << " "; team1[i]->interout();
            cout << "            ";
            team2[i]->interout(); cout << " " << i + 1;
            cout << endl;
        }
    }
    else
    {
        cout << "team 1      ход команды ->     team2" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << " "; team1[i]->interout();
            cout << "            ";
            team2[i]->interout(); cout << " " << i + 1;
            cout << endl;
        }
    }
    
}
void playout(Bichara** team1, Bichara** team2,int size, int roundcount = 1)
{
    int operate1 = 1, operate2, sumdeath1 = 0, sumdeath2 = 0;
    while (true)
    {
        int  sumdeath1 = 0, sumdeath2 = 0;
        WOWout(team1, team2, size, roundcount);
        if (roundcount % 2 == 1)
        {
            cout << "выберите героя для действия " << endl; cin >> operate1;
            if (team1[operate1 - 1]->getlifestatus() == 0)
            {
                cout << "союзный герой мертв"<< endl;
                Sleep(2000);
            }
            else
            {
                if (team1[operate1 - 1]->getname() == "Healer")
                {
                    cout << "выберите cоюзного героя для лечения" << endl; cin >> operate2;
                    if (team1[operate2 - 1]->getHealth() == 100 or team1[operate2 - 1]->getHealth() == 0)
                    {
                        cout << "персонажа нельзя вылечить  " << endl;
                        Sleep(2000);
                    }
                    else
                    {
                        team1[operate1 - 1]->atack(team1[operate2 - 1]);
                    }
                }
                else
                {
                    cout << "выберите героя для атаки" << endl; cin >> operate2;
                    if (team2[operate2 - 1]->getlifestatus() == 0)
                    {
                        cout << "вражеский герой уже мертв";
                        Sleep(2000);
                    }
                    else
                    {
                        team1[operate1 - 1]->atack(team2[operate2 - 1]);
                        if (team2[operate2 - 1]->getHealth() < 1)
                        {
                            team2[operate2 - 1]->setlifestatus(0);
                        }
                    }
                }
                for (int i = 0; i < size; i++) /*проверка на мертвых*/
                {
                    if (team1[i]->getlifestatus() == 0)
                    {
                        sumdeath1 += 1;
                    }
                    if (team2[i]->getlifestatus() == 0)
                    {
                        sumdeath2 += 1;
                    }

                }
                system("cls");
            }
            if (sumdeath1 == 3 or sumdeath2 == 3)
            {
                break;
            }
        }
        else
        {
            cout <<endl << "выберите героя для действия " << endl; cin >> operate1;
            if (team2[operate1 - 1]->getlifestatus() == 0)
            {
                cout << "союзный герой мертв" << endl;
                Sleep(2000);
            }
            else
            {
                if (team2[operate1 - 1]->getname() == "Healer")
                {
                    cout <<endl <<  "выберите cоюзного героя для лечения" << endl; cin >> operate2;
                    if (team2[operate2 - 1]->getHealth() == 100 or team2[operate2 - 1]->getHealth() == 0)
                    {
                        cout <<endl <<  " персонажа нельзя вылечить  " << endl;
                        Sleep(2000);
                    }
                    else
                    {
                        team2[operate1 - 1]->atack(team2[operate2 - 1]);
                    }
                }
                else
                {
                    cout << endl << "выберите героя для атаки" << endl; cin >> operate2;
                    if (team1[operate2 - 1]->getlifestatus() == 0)
                    {
                        cout << endl <<  "вражеский герой уже мертв";
                        Sleep(2000);
                    }
                    else
                    {
                        team2[operate1 - 1]->atack(team1[operate2 - 1]);
                        if (team1[operate2 - 1]->getHealth() < 1)
                        {
                            team1[operate2 - 1]->setlifestatus(0);
                        }
                    }
                }
                for (int i = 0; i < size; i++) /*проверка на мертвых*/
                {
                    if (team1[i]->getlifestatus() == 0)
                    {
                        sumdeath1 += 1;
                    }
                    if (team2[i]->getlifestatus() == 0)
                    {
                        sumdeath2 += 1;
                    }

                }
                system("cls");
            }
            if (sumdeath1 == 3 or sumdeath2 == 3)
            {
                break;
            }
        }
        roundcount++;
    }
    cout << "игра окончена  " << endl;
    (sumdeath1 > sumdeath2) ? cout << "команда 2 победила" << endl : cout << "команда 1 победила" << endl;
    WOWout(team1, team2, size, roundcount);
}
int main()
{
    setlocale(LC_ALL, "Russian");
    Bichara b1,b2,b3,b4,b5,b6;
    Warrior wa1, wa2,wa3,wa4,wa5,wa6;
    Healer  h2,h3,h5,h6;
    Wizard wi1,wi2,wi3,wi4,wi5,wi6;
    short ans;
    Bichara* team1[3] = {};
    Bichara* team2[3] = {};
     /*сделать нормальный вывод*/
    cout << "1 - бичара (может только атаковать) \n2 - воин (каждая третья атака имеет повышенный шанс крита) \n3 - хилер (может только лечить) \n4 - маг (каждая атака уменьшает броню врага на 5 единиц)" << endl;
    error1:
    for (int i = 0; i < 3; i++)
    {
        cout << "команда 1: выберете героя под номером  " << i + 1 << endl;
        cin >> ans;
        if (i == 0)
        {
            switch (ans)
            {
            case 1:
                team1[i] = &b1;
                break;
            case 2:
                team1[i] = &wa1;
                break;
            case 3:
                cout << "он не может быть выбран первым слотом \n";
                goto error1;
                break;
            case 4:
                team1[i] = &wi1;
                break;

            default:
                team1[i] = &b1;
            }
        }
        if (i == 1)
        {
            switch (ans)
            {
            case 1:
                team1[i] = &b2;
                break;
            case 2:
                team1[i] = &wa2;
                break;
            case 3:
                team1[i] = &h2;
                break;
            case 4:
                team1[i] = &wi2;
                break;
            default:
                team1[i] = &b2;
            }
        }
        if (i == 2)
        {
            switch (ans)
            {
            case 1:
                team1[i] = &b3;
                break;
            case 2:
                team1[i] = &wa3;
                break;
            case 3:
                team1[i] = &h3;
                break;
            case 4:
                team1[i] = &wi3;
                break;
            default:
                team1[i] = &b3;
            }
        }
    }
    error2:
    for (int i = 0; i < 3; i++)
    {
        cout << "команда 2: выберете героя под номером  " << i + 1 << endl;
        cin >> ans;
        if (i == 0)
        {
            switch (ans)
            {
            case 1:
                team2[i] = &b4;
                break;
            case 2:
                team2[i] = &wa4;
                break;
            case 3:
                cout << "он не может быть выбран первым слотом \n";
                goto error2;
                break;
            case 4:
                team2[i] = &wi4;
                break;
            default:
                team1[i] = &b4;
            }
        }
        if (i == 1)
        {
            switch (ans)
            {
            case 1:
                team2[i] = &b5;
                break;
            case 2:
                team2[i] = &wa5;
                break;
            case 3:
                team2[i] = &h5;
                break;
            case 4:
                team2[i] = &wi5;
                break;
            default:
                team1[i] = &b5;
            }
        }
        if (i == 2)
        {
            switch (ans)
            {
            case 1:
                team2[i] = &b6;
                break;
            case 2:
                team2[i] = &wa6;
                break;
            case 3:
                team2[i] = &h6;
                break;
            case 4:
                team2[i] = &wi6;
                break;
            default:
                team1[i] = &b6;
            }
        }
    }
    system("cls");
    playout(team1, team2, 3);
}  
