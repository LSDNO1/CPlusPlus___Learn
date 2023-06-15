#include "stadfx.h"

//自定义函数
bool Mysort(int a,int b)
{
    return a>b;
};

void Display(int a)
{
    std::cout<<a<<' ';
};

//泛型函数
template<class T>
bool MysortT(T const& a,T const& b)
{
    return a>b;
};

template<class T>
void DisplayT(T const& a)
{
    std::cout<<a<<' ';
};

//仿函数
struct MysortS
{
    bool operator()(int a,int b)
    {
        return a>b;
    }
};

struct DisplayS
{
    void operator()(int a)
    {
        std::cout<<a<<' ';
    }
};

//泛型编程
template<class T>
struct MysortST
{
    bool operator()(T const& a,T const& b)
    {
        return a>b;
    }
};

template<class T>
struct DisplayST
{
    void operator()(T const &a)
    {
        std::cout<<a<<' ';
    }
};

int main()
{
    int arr1[]={0,1,2,3,4};
    std::sort(arr1,arr1+4, Mysort);
    std::for_each(arr1,arr1+4, Display);

    std::cout<<std::endl;

    int arr2[]={0,1,2,3,4};
    std::sort(arr2,arr2+4, MysortT<int>);
    std::for_each(arr2,arr2+4, DisplayT<int>);

    std::cout<<std::endl;

    int arr3[]={0,1,2,3,4};
    std::sort(arr3,arr3+4, MysortS());
    std::for_each(arr3,arr3+4, DisplayS());

    std::cout<<std::endl;

    int arr4[]={0,1,2,3,4};
    std::sort(arr4,arr4+4, MysortST<int>());
    std::for_each(arr4,arr4+4, DisplayST<int>());

    std::cout<<std::endl;

    return 0;
}
