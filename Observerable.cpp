//
// Created by WLSD on 2023/6/6.
//

#include "stadfx.h"


Observerable::Observerable()
{
    _tmp=false;
}

Observerable::~Observerable()
{

}

//注册观察者
void Observerable::attach(Observer *Pob)
{
    if(Pob== nullptr)
    {
        return ;
    }
    //遍历查看是否有重复
    auto it=_Obs.begin();

    for(;it!=_Obs.end();it++)
    {
        if(*it==Pob)
            return ;
    }
    _Obs.push_back(Pob);
}

//删除观察者
void Observerable::Detach(Observer *Pob)
{
    if((Pob== nullptr)||(_Obs.empty()))
    {
        return ;
    }

    auto it=Pob;
    _Obs.remove(it);

}

void Observerable::SetChange(std::string s)
{
    _tmp=true;
    Notfiy((void*)s.c_str());
}

void Observerable::Notfiy(void *pArg)
{
    if(_tmp== false)
        return ;
    //遍历列表查看
    auto it=_Obs.begin();
    for(;it!=_Obs.end();it++)
    {
        (*it)->update((void*)pArg);
    }
}

void Observerable::ObserverCount() const
{
    std::cout<<_Obs.size()<<std::endl;
}









