//
// Created by WLSD on 2023/6/12.
//

#include "stadfx.h"

const char* host = "127.0.0.1";
const char* user = "root";
const char* pw = "123456";
const int port = 3306;
const char* datebase_name = "student";

StudentManger* StudentManger::ptr = nullptr;

StudentManger* StudentManger::GetInstace()
{
    if (!ptr)
    {
        ptr = new StudentManger;
    }
    return ptr;
}

StudentManger::StudentManger()
{
    con = mysql_init(NULL);
    mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");
    if (!mysql_real_connect(con, host, user, pw, datebase_name, port, NULL, 0))
    {
        fprintf(stderr, "Failed to connect to database: %s\n", mysql_error(con));
        exit(1);
    };
}

StudentManger::~StudentManger()
{
    mysql_close(con);
}

void StudentManger::Insert_Student(Student& stu)
{
    char sql[1024];
    sprintf(sql, "insert into Student (Sno,Sname,Birthday,Ssex,Sage,Sdept,class) values('%s','%s','%s','%s',%d,'%s','%s')",
            stu.Sno.c_str(), stu.Sname.c_str(), stu.Birthday.c_str(), stu.Ssex.c_str(), stu.Sage, stu.Sdept.c_str(), stu.Class.c_str());
    if (mysql_query(con, sql))
    {
        fprintf(stderr, "Failed to insert into database: %s\n", mysql_error(con));
        exit(1);
    }
}

void StudentManger::Delete_Student(Student& stu)
{
    char sql[1024];
    sprintf(sql,"delete from Student where Sno=%s",stu.Sno.c_str());
    if(mysql_query(con,sql))
    {
        fprintf(stderr, "Failed to delete database: %s\n", mysql_error(con));
        exit(1);
    }
}

//区分大小写
/*void StudentManger::Update_Student(Student& stu)
{
    char sql[1024];
    sprintf(sql,"update student set Sname=%s where Sno=%s",stu.Sname.c_str(),stu.Sno.c_str());
    if(mysql_query(con,sql))
    {
        fprintf(stderr, "Failed to update database: %s\n", mysql_error(con));
        exit(1);
    }
}*/

void StudentManger::Update_Student(Student& stu)
{
    char sql[1024];
    sprintf(sql, "UPDATE student SET Sname='%s' WHERE Sno='%s'", stu.Sname.c_str(), stu.Sno.c_str());
    if (mysql_query(con, sql))
    {
        fprintf(stderr, "Failed to update database: %s\n", mysql_error(con));
        exit(1);
    }
}

void StudentManger::Get_Student(std::string condition)
{
    std::vector<Student>StudentList;
    char sql[1024];
    sprintf(sql,"SELECT * FROM student %s",condition.c_str());
    if(mysql_query(con,sql))
    {
        fprintf(stderr, "Failed to update database: %s\n", mysql_error(con));
        exit(1);
    }
    MYSQL_RES* res= mysql_store_result(con);
    MYSQL_ROW row;
    while((row= mysql_fetch_row(res)))
    {
        Student stu;
        stu.Sno=row[0];
        stu.Sname=row[1];
        stu.Birthday=row[2];
        stu.Ssex=row[3];
        stu.Sage= atoi(row[4]);
        stu.Sdept=row[5];
        stu.Class=row[6];
        StudentList.push_back(stu);
    }

    for(auto &tmp:StudentList)
    {
        std::cout<<tmp.Sno<<' '<<tmp.Sname<<' '<<tmp.Birthday<<std::endl;
    }
}
