# 对象函数及虚函数的内存

**在一个类的内存中，虚函数指针（4/8字节）和一般成员变量**

**例如：**

```C++
class Shape
{
public:
    virtual double Area() const =0;
    virtual void Show()=0;
    void display();
private:
    int _color;
};

class Circle:public Shape
{
public:
    Circle(double m);
    virtual void Show();
    virtual double Area() const ;
private:
    double _radius;
};

```

**其中sizeof(C1)为24**

解释：

**因为在C1对象成员中，包括了父类的私有变量、虚函数指针和本身的私有成员变量**（字节自动对齐，所以8+（4）+8+8）



## 一般成员函数：

### 存储位置：

在C++中，**一般成员函数的代码并不会被储存在类对象中，而是被储存在程序的代码段中**。这意味着，论有多少个类对象被创建，它们都会共享相同的成员函数代码。**这样可以节省内存空间，并且使得更加高效。**



### 如何找到对象的私有成员变量：

**当一个成员函数被调用时，它会自动传递一个指向本对象的指针，也就是this指针。**通过this指针，成员函数可以访问本对象的私有成员变量。this指针指向调用该成员函数的对象因此可以使用this指针来访问该对象的成员变量和成员函数





