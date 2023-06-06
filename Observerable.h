//
// Created by WLSD on 2023/6/6.
//

#ifndef C___TEST_OBSERVERABLE_H
#define C___TEST_OBSERVERABLE_H


#include<list>
#include <string>
class Observer;//声明Observer类

//被观察者
class Observerable
{
public:
    Observerable();
    virtual ~Observerable();
    //注册观察者
    virtual void attach(Observer* Pob);
    //删除观察者
    virtual void Detach(Observer* Pob);
    //获得一些信息
    virtual void GetSomeChange(std::string s)
    {
        SetChange(s);
    };
    void ObserverCount()const;
protected:
    void SetChange(std::string s);//有变化，需要通知观察者
private:
    void Notfiy(void*pArg);//调用这个通知观察者
    bool _tmp;
    std::list<Observer*>_Obs;
};


#endif //C___TEST_OBSERVERABLE_H
