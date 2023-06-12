#include <iostream>
#include <mysql.h>

typedef struct SC
{
    std::string sno;
    std::string cno;
    int grade;
}SC;

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    conn = mysql_init(NULL);

    //连接到数据库 第一个参数是前面的对象第4行生成的对象名 host 为主机地址 本机就是localhost user为数据库用户名称 passwd为密码
    //db为数据库名称 port为端口 默认是3306 后两位参数不需要修改
    if (!mysql_real_connect(conn, "localhost", "root", "123456", "student", 3306, NULL, 0)) {
        std::cout << "Error: " << mysql_error(conn) << std::endl;
        return 1;
    }
    // 设置字符集--注意与数据库字符集相同 我用的utf8
    if (mysql_set_character_set(conn, "utf8")) {
        std::cout << "Error: " << mysql_error(conn) << std::endl;
        return 1;
    }

    SC sc1{"20041000","1",95};

    char sql[1024];
    sprintf(sql,"insert into SC (Sno,Cno,Grade) values(%s,%s,%d)",sc1.sno.c_str(),sc1.cno.c_str(),sc1.grade);
    if(mysql_query(conn,sql))
    {
        std::cout << "Error: " << mysql_error(conn) << std::endl;
        return -1;
    }


    mysql_close(conn);

    return 0;
}