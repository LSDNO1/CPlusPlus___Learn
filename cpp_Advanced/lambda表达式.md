# lambda表达式

**Lambda表达式是一种匿名函数，它可以在运行时动态地创建**

**它的主要作用是简化代码，使代码更加简洁、清晰**

```C++
#include "stadfx.h"

int main()
{
    int arr[]={1,2,3,4,5};
    int arr1[]={2,3,4,5,6};
    int result[5]={0};

    //泛型仿函数
    std::transform(arr,arr+5,arr1,result,std::plus<int>());

    //lambda表达式
    std::for_each(result,result+5,[](int a){std::cout<<a<<' ';});


    return 0;
}
```

