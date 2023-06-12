//
// Created by WLSD on 2023/6/5.
//

#include "stadfx.h"

Singleton* Singleton::This= nullptr;
const Singleton* Singleton::getInstance()
{
    if(!This)
    {
        This=new Singleton;
    }
    return This;
}

void Singleton::Dosometing()
{
    std::cout<<"Do Everything!"<<std::endl;
}

Singleton::Singleton()
{
    std::cout<<"OK"<<std::endl;
}

Singleton::~Singleton()
{

}

void Singleton::display()
{
    std::cout<<"YES"<<std::endl;
}

void Singleton::play()
{
    This->display();
}