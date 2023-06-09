#include "stadfx.h"

class Base
{
public:
    Base():_m(0){;}
    ~Base(){;}
    virtual void T()
    {
        std::cout<<"Get Base"<<std::endl;
    }
    void Fun()
    {
        std::cout<<"OK Base"<<std::endl;
    }
private:
    int _m;
};

class Derived:public Base
{
public:
    Derived():_x(0){;}
    ~Derived(){;}
    virtual void T()
    {
        std::cout<<"Get Derived!"<<std::endl;
    }
    void Dun()
    {
        std::cout<<"OK Derived"<<std::endl;
    }
private:
    int _x;
};

int main()
{
    //父类指向子类对象
    Base*base =new Derived;
    base->T();
    base->Fun();

    Derived* Dptr=dynamic_cast<Derived*>(base);

    Dptr->Dun();
    Dptr->Fun();
    Dptr->T();


    return 0;
}
