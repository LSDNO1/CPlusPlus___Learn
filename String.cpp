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

