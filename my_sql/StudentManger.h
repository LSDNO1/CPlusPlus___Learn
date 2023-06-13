//
// Created by WLSD on 2023/6/12.
//

#ifndef MY_SQL_STUDENTMANGER_H
#define MY_SQL_STUDENTMANGER_H

#include "stadfx.h"
#include <vector>

typedef struct Student
{
    std::string Sno;
    std::string Sname;
    std::string Birthday;
    std::string Ssex;
    int Sage;
    std::string Sdept;
    std::string Class;
}Student;

class StudentManger
{
    //StudentManger(Student& stu);
    StudentManger();
    ~StudentManger();
public:
    void Insert_Student(Student& stu);
    void Delete_Student(Student& stu);
    void Update_Student(Student& stu);
    void Get_Student(std::string condition="");
public:
    static StudentManger* GetInstace();
private:
    static StudentManger* ptr;
    MYSQL* con;
};


#endif //MY_SQL_STUDENTMANGER_H
