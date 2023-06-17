# C++多线程

**C++多线程是指在C++程序中使用多个执行线程来同时执行不同的任务**。在单线程程序中，程序按照顺序执行，一次只能执行一个任务。而在多线程程序中，程序可以同时执行多个任务，每个任务在不同的线程中执行。**这样可以提高程序的并发性和效率**，特别是在处理大量数据或需要长时间计算的任务时，可以显著提高程序的执行速度。**C++11及以后的标准提供了多线程编程的支持，包括线程库、互斥锁、条件变量等**



**C++11及之后使用**



## 多线程不支持函数重载

```C++
#include "stadfx.h"

#include <thread>
#include <mutex>

std::mutex get_line;

void display1()
{
    get_line.lock();
    std::cout<<"Hello World!"<<std::endl;
    get_line.unlock();
}

void display2(const char* s)
{
    get_line.lock();
    std::cout<<s<<std::endl;
    get_line.unlock();
}

int main()
{
    std::thread t1(display1);
    t1.join();//就是程序必须跑完
    std::thread t2(display2,"hahaha");
    t2.join();

    std::cout<<"mian"<<std::endl;

    return 0;
}
```

在创建线程时，需要传递一个可调用对象作为参数，这个对象可以是函数、函数指针、成员函数、成员函数指针、Lambda表达式等。但是，**如果你想要传递一个重载函数，编译器无法确定应该调用哪个函数，因此无法将其作为参数传递给线程**。因此，如果想要在创建线程时传递一个函数，**需要确保该函数是唯一的，不与其他函数重载**。如果**需要传递重载函数，可以使用函数对象或Lambda表达式来代替重载函数**

重载函数只有在调用传参时才能确定用哪一个函数

## 简单的存取钱案例：

```C++
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

    t2.join();//完全完成一个线程之后再输出money的值
    std::cout<<money<<std::endl;



    return 0;
}
```

