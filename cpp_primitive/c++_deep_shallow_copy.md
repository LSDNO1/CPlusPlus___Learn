# C++学习

## C++高级语法

### 浅拷贝与深拷贝

#### 浅拷贝

**只拷贝指针地址，C++默认拷贝构造函数与赋值运算符重载都是浅拷贝；**

#### 深拷贝

**重新分配堆内存，拷贝指针指向内容。浪费空间，但不会导致多次释**

![image-20230603215120383](C:\Users\WLSD\AppData\Roaming\Typora\typora-user-images\image-20230603215120383.png)



```C++
//main.cpp

#include "stadfx.h"

int main() {
    String s("abc");
    std::cout<<s<<std::endl;

    String s1=s;//自动调用构造函数而非赋值函数
    std::cout<<s1<<std::endl;

    String s2;
    std::cout<<s2<<std::endl;
    s2=s1;
    std::cout<<s2<<std::endl;

    //移动构造函数
    String s3(std::move(s1));
    std::cout<<s3<<std::endl;

    String s4;
    s4=std::move(s3);//移动赋值函数
    std::cout<<s4<<std::endl;
    return 0;
}

//String.h
//
// Created by WLSD on 2023/6/3.
//

#ifndef C___TEST_STRING_H
#define C___TEST_STRING_H


class String {
public:
    //普通构造函数
    explicit String(const char* str= nullptr);
    //拷贝构造函数
    String(const String& other);
    //析构函数
    ~String();
    //输出字符串
    friend std::ostream& operator<<(std::ostream& os,const String& c);
    //赋值函数
    String& operator=(const String&other);
    //移动构造函数
    String(String&& other)noexcept;
    //移动赋值函数
    String& operator=(String&& other)noexcept;
private:
    char*m_date;
};


#endif //C___TEST_STRING_H

//String.cpp
//
// Created by WLSD on 2023/6/3.
//

#include "stadfx.h"

//普通构造函数，单参数构造函数显示调用
String::String(const char *str)
{
    if(str== nullptr)
    {
        m_date=new char[1];
        *m_date='\0';
        //exit(-1);
    }
    else
    {
        int len=strlen(str);
        m_date=new char[len+1];
        if(m_date!= nullptr)
            strcpy(m_date,str);
        //exit(1);
    }
}

//析构函数
String::~String()
{
    delete[] m_date;
    m_date= nullptr;
}

//拷贝构造函数
String::String(const String &other)//深拷贝
{
    if(m_date==other.m_date)
        exit(-1);
    if(other.m_date== nullptr)
    {
        m_date=new char[1];
        *m_date='\0';
        //exit(1);
    }
    else
    {
        int len= strlen(other.m_date);
        m_date=new char[len+1];
        if(m_date!= nullptr)
            strcpy(m_date,other.m_date);
        //exit(-1);
    }

}
//输出函数重载
std::ostream& operator<<(std::ostream& os,const String& c)
{
    os<<c.m_date;
    return os;
}
//赋值函数
String& String::operator=(const String &other)
{
    /*if(m_date==other.m_date)
        return *this;
    */
    if(this==&other)
        return *this;
    else
    {
        if(other.m_date== nullptr)
        {
            delete[]m_date;
            m_date=new char[1];
            *m_date='\0';
        }
        else
        {
            delete[]m_date;
            int len= strlen(other.m_date);
            m_date=new char[len+1];
            if(m_date!= nullptr)
                strcpy(m_date,other.m_date);
        }
    }
    return *this;
}
//移动构造函数
String::String(String &&other)noexcept
{
    if(other.m_date!= nullptr)
    {
        m_date=other.m_date;
        other.m_date= nullptr;
    }
}
//移动赋值函数
String& String::operator=(String&& other)noexcept//&&为右值操作，表示可以转移资源
{
    if(this==&other)
        return *this;
    else
    {
        delete[] m_date;
        m_date=other.m_date;
        other.m_date= nullptr;
    }
    return *this;
}

//stadfx.h
//
// Created by WLSD on 2023/6/3.
//

#ifndef C___TEST_STADFX_H
#define C___TEST_STADFX_H

#include<iostream>
#include<string>
#include"String.h"
#include <cstring>
#include<ostream>

#endif //C___TEST_STADFX_H


```

**在这之中String&& other，表示为右值引用，在C++中表明可以资源转移，特定形式**






