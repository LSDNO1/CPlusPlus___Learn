#include "stadfx.h"

#include <thread>
#include <mutex>

void dospoit(std::mutex& m,int& money)
{
    //尽可能是锁的粒度够小
    for(int i=0;i<100;i++)
    {
        m.lock();
        money+=1;
        m.unlock();
    }
}

void draw(std::mutex& m,int& money)
{
    for(int i=0;i<100;i++)
    {
        m.lock();
        money-=2;
        m.unlock();
    }
}


int main()
{
    std::mutex m;
    int money=2000;

    std::cout<<money<<std::endl;

    std::thread t1(dospoit,std::ref(m),std::ref(money));

    t1.join();
    std::cout<<money<<std::endl;

    std::thread t2(draw,std::ref(m),std::ref(money));

    t2.join();
    std::cout<<money<<std::endl;



    return 0;
}