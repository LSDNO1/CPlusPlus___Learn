//
// Created by WLSD on 2023/6/5.
//

#include "stadfx.h"

void Shape::display()
{
    std::cout<<Area()<<std::endl;
}

//初始化
Circle::Circle(double m):_radius(m){};
//.....对比两种构造函数区别
/*Circle::Circle(double m)
{
    _radius=m;
}*/

//重写Area函数的实现
double Circle::Area()const
{
    return 3.14*_radius*_radius;
}
//Square类

Square::Square(double m):_len(m){}

double Square::Area() const
{
    return _len*_len;
}

void Circle::Show()
{
    std::cout<<"Circle"<<std::endl;
}

void Square::Show()
{
    std::cout<<"Square"<<std::endl;
}