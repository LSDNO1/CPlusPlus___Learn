//
// Created by WLSD on 2023/6/5.
//

#ifndef C___TEST_SINGLETON_H
#define C___TEST_SINGLETON_H


class Singleton
{
public:
    //只有static 函数才能被static 变量访问
    //const Singleton* 意味着返回的指针常量不可修改
    static const Singleton* getInstance();
    static void Dosometing();
    //将构造函数设置为私有函数，防止被调用产生新的对象
    void play();
private:
    Singleton();
    ~Singleton();
    void display();
    static Singleton*This;//只在Singleton中可见，但是生命周期是全局
};


#endif //C___TEST_SINGLETON_H
