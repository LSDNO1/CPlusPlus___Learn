//
// Created by WLSD on 2023/6/5.
//

#ifndef C___TEST_SHAPE_H
#define C___TEST_SHAPE_H

//抽象类，不具有具体对象
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

class Square:public Shape
{
public:
    Square(double m);
    virtual double Area()const;
    virtual void Show();
private:
    double _len;
};

#endif //C___TEST_SHAPE_H
