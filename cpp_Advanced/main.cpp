#include "stadfx.h"

int main()
{
    int arr[]={1,2,3,4,5};
    int arr1[]={2,3,4,5,6};
    int result[5]={0};

    /*//���ͷº���
    std::transform(arr,arr+5,arr1,result,std::plus<int>());

    //lambda���ʽ
    std::for_each(result,result+5,[](int a){std::cout<<a<<' ';});*/

    std::cout<<sizeof(arr)<<std::endl;//5

    return 0;
}