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
