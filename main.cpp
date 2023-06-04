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
