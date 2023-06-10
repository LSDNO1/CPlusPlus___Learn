#include "stadfx.h"

class LeagcyRectangle
{
public:
    LeagcyRectangle(double x1,double x2,double y1,double y2)
    {
        _x1=x1,_x2=x2,_y1=y1,_y2=y2;
    }
    void LeagcyDrow()
    {
        std::cout<<"LeagcyDrow!"<<std::endl;
    }
private:
    double _x1,_x2,_y1,_y2;
};

//����ӿ����ڶԽ��ⲿ��������ʵ�����ڲ���ĶԽ�
class Rectangle
{
public:
    virtual void Drow()=0;
};

//��һ�������������ؼ̳У����ؼ̳����׳�����ʯ�̳д���
class RectangleAdapter:public Rectangle,public LeagcyRectangle
{
public:
    RectangleAdapter(double x,double y,double m,double n): LeagcyRectangle(x,y, m,n){
        std::cout<<"LeagcyRectangle OK!"<<std::endl;
    };
    virtual void Drow()
    {
        std::cout<<"Use LeagcyDrow!"<<std::endl;
        LeagcyDrow();
    }
};

//�ڶ�������������Ϸ�ʽ��Adpater����������
class RectangleAdapter2:public Rectangle
{
public:
    RectangleAdapter2(double x1,double x2,double y1,double y2):_LR(x1,x2,y1,y2){;}
    virtual void Drow()
    {
        std::cout<<"Use LeagcyDrow! 2"<<std::endl;
        _LR.LeagcyDrow();
    }
private:
    LeagcyRectangle _LR;
};

int main()
{
    RectangleAdapter Adpter(1.0,2.0,3.0,4.0);
    //����ָ��->����ָ��
    Rectangle* ptr=&Adpter;
    ptr->Drow();

    std::cout<<std::endl;

    RectangleAdapter2 Adpter2(1.0,2.0,3.0,4.0);
    //����ָ��->����ָ��
    Rectangle* ptr2=&Adpter2;
    ptr2->Drow();
    return 0;
}