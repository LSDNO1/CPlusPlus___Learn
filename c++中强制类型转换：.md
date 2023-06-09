# c++中强制类型转换：

## const_cast

```C++
 	const int a=1;
    int *ptr=(int*)&a; //取出来的类型为const int*
    *ptr=2;
    std::cout<<a<<' '<<*ptr<<std::endl;

    int *ptrA=const_cast<int*>(&a);//去掉属性中const属性
    std::cout<<*ptrA<<std::endl;
    *ptrA=3;
    std::cout<<a<<' '<<*ptrA<<std::endl;
```

**强制类型转换和 const_cast 都是 C++ 中的类型转换操作符，但它们的作用和使用场景是不同的**。强制类型转换用于将一个数据类型转换为另一个数据类型，而 const_cast 用于移除指针或引用类型的 const或volatile限定符，以便可以修改被限定的变量。但是，使用const_cast来修改一个const` 变量的值是未定义的行为。



**c语言中直接强制类型转换并不会做任何检查，c++会做一定的模型检查，但是主要还得靠程序员自己**

## reinterpret_cast

```C++
int test()
{
    return 0;
}

int main()
{
    /*这行代码定义了一个名为FuncPtr的函数指针类型，该函数指针指向一个没有参数和返回值的函数。这个类型可以用来声明变量，这些变量可以存储指向这种类型函数的指针。例如，如果有一个函数void foo()，那么可以声明一个FuncPtr类型的指针变量FuncPtr ptr = &foo，然后通过ptr()来调用foo函数。*/
    
    typedef void(*FuncPtr)();
    FuncPtr funcPtr;
    funcPtr=reinterpret_cast<FuncPtr>(&test);
    //funcPtr=&test();

    return 0;
}

```

**重新解释类型，既不检查指向的内容，也不检查指针类型本身；但要求转换前后的类型所占内存大小一样，否则引发编译错误**

## static_cast

**用于基本类型转换，有继承关系类对象和类指针之间的转换，由程序员来确保转换是安全的，它不会产生动态转换的类型安全检查的开销**

```C++
	int a=1;
    double b=2.0;
    a=static_cast<int>(b);
    std::cout<<a<<std::endl;//2

    b=static_cast<double>(a);
    std::cout<<b<<std::endl;//2，丢失精度
```



## dynamic_cast

- dynamic_cast主要用于**“安全地向下转型”**

dynamic_cast用于类继承层次间的指针或引用转换。**主要还是用于执行“安全的向下转型（safe downcasting）”**，也即是基类对象的指针或引用转换为同一继承层次的其他指针或引用。至于**“先上转型”（即派生类指针或引用类型转换为其基类类型），本身就是安全的**，尽管可以使用dynamic_cast进行转换，但这是没必要的， 普通的转换已经可以达到目的，毕竟使用dynamic_cast是需要开销的。

 

### 向上转换：

```C++
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
    void Dun()
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
    void Fun()
    {
        std::cout<<"OK Derived"<<std::endl;
    }
private:
    int _x;
};

int main()
{
    Base* base;
    Derived* derived=new Derived();
    derived->Dun();
    //子类向父类转换本身就是安全的
    //可以但没必要，只会增加额外的开销
    //base=dynamic_cast<Base*>(derived);
    base=derived;
    //转换后，base调用的仍是子类虚函数
    base->T();
    base->Dun();

    //base->Fun();转换后，base无法调用子类的非虚函数

    return 0;
}

```

### 向下转换：

对于“向下转型”有两种情况。**一种是基类指针所指对象是派生类类型的，这种转换是安全的**；**另一种是基类指针所指对象为基类类型，在这种情况下dynamic_cast在运行时做检查，转换失败，返回结果为0；**

```C++
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
    //基类指针指向基类对象
    Base* base=new Base;
    Derived*derived;
    derived=dynamic_cast<Derived*>(base);
    if(derived== nullptr)
    {
        std::cout<<"derived is a nullptr!"<<std::endl;
    }
    derived->Fun();
    derived->Dun();


    return 0;
}

/*在这段代码中，`derived` 是一个指向 `Derived` 类型的指针，但是在 `dynamic_cast` 进行类型转换时，将 `Base*` 类型的指针 `base` 转换为 `Derived*` 类型的指针 `derived`。这里的转换是不安全的，因为实际上 `base` 指针指向的是 `Base` 类型的对象，并不是 `Derived` 类型的对象。

由于 `dynamic_cast` 进行了类型转换，将 `base` 指针转换为 `Derived*` 类型的指针 `derived`，编译器不会报错，但是运行时会进行类型检查。在这种情况下，由于实际的对象类型是 `Base`，而不是 `Derived`，所以 `dynamic_cast` 返回一个空指针 `nullptr`。

在接下来的代码中，尝试通过 `derived` 指针访问成员函数 `Fun()` 和 `Dun()`，这是一种未定义行为（undefined behavior）。当指针为 `nullptr` 时，对其进行解引用或调用成员函数会导致未定义行为。

因此，在这段代码中，尽管 `derived` 是一个空指针（nullptr），但是尝试通过它访问函数是一种未定义行为，结果是不可预测的。*/
```

```C++
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

```

