#define _CRT_SECURE_NO_WARNINGS

#include <iostream>  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include<string>

//下面两个头文件的顺序不能颠倒  
#include "winsock2.h"  
#include "windows.h"  
#include "mysql.h"  

using namespace std;

class mysql{
public:
	mysql()
	{
		_host= "localhost";    //MySQL服务器IP地址；若是本地可填写“localhost”或127.0.0.1  
		_user= "root";         //MySQL的用户名  
		_pswd= "mysql";         //密码  
		_table= "testmyb";        //数据库名称  
		_port = 3306;           //MySQL服务端口号，默认是3306  
		mysql_library_init(0, NULL, NULL);
		mysql_init(&_ms);
		if (mysql_real_connect(&_ms, _host, _user, _pswd, _table, _port, NULL, 0))
		{
			cout << "connect succeed!" << endl;
		}
		else
		{
			cout << "connect failed!" << endl;
		}
		mysql_query(&_ms, "SET NAMES GBK");//设置编码格式，否则无法在cmd上显示中文
	}
	mysql(char* host, char* user, char *pswd, char *table, unsigned int port)
		:_host(host),
		_user(user),
		_pswd(pswd),
		_table(table),
		_port(port)
	{
		mysql_library_init(0, NULL, NULL);
		mysql_init(&_ms);
		if (mysql_real_connect(&_ms, _host, _user, _pswd, _table, _port, NULL, 0))
		{
			cout << "connect succeed!"<< endl;
		}
		else
		{
			cout << "connect failed!" << endl;
		}
		mysql_query(&_ms, "SET NAMES GBK");//设置编码格式，否则无法在cmd上显示中文

	}
	~mysql(){
		mysql_close(&_ms);//关闭mysql连接
		mysql_library_end();//关闭mysql库
		cout << "bye！" << endl;

	}
	bool operate()
	{
		cout << "请输入命令>";
		string s;
		getline(cin, s);
		if ("exit-myb" == s)
		{
			return false;
		}
		int res = 0;
		res = mysql_query(&_ms, s.c_str());
		if (!res)
		{
			_result = mysql_store_result(&_ms); //保存查询数据
			//************************打印
			if (_result)
			{
				int i, j;
				cout << "number of result: " << (unsigned long)mysql_num_rows(_result) << endl;

				for (i = 0; _fd = mysql_fetch_field(_result); i++)//获取列名  
				{
					strcpy(_column[i], _fd->name);
				}
				j = mysql_num_fields(_result);
				for (i = 0; i<j; i++)
				{
					printf("%s\t", _column[i]);
				}
				//printf("|");
				printf("\n");


				while (_sql_row = mysql_fetch_row(_result))//获取具体的数据  
				{
					for (i = 0; i<j; i++)
					{
						printf("%s\t", _sql_row[i]);
					}
					//printf("|");
					printf("\n");
				}

			}
			/////****************
		}
		else{
			cout << "query sql failed!" << endl;
			printf("\n%s\n", mysql_error(&_ms));
			return true;
		}
		//注意用完数据库要及时回收资源  
		if (_result != NULL) mysql_free_result(_result);	//释放结果资源  
		return true;
	}

private:
	MYSQL _ms;//创建mysql对象，定义数据库连接句柄
	MYSQL_RES *_result;//查询结果集 存放查询结果
	MYSQL_ROW _sql_row;//存放一行查询结果的字符串数组  
	MYSQL_FIELD *_fd; // 包含字段信息的结构

	char _column[32][32];

	const char *_host ;    //MySQL服务器IP地址；若是本地可填写“localhost”或127.0.0.1  
	const char *_user;         //MySQL的用户名  
	const char *_pswd ;         //密码  
	const char *_table ;        //数据库名称  
	unsigned int _port;           //MySQL服务端口号，默认是3306   
};

int main()
{

	mysql x;

	while (1)
	{
		if (x.operate())
			continue;
		else
		{
			break;           //退出  exit-myb
		}
	}
	return 0;
}




#if 0
//初始化
void MySqlInit(MYSQL* ms)
{
	mysql_library_init(0, NULL, NULL);
	mysql_init(ms);
}
//连接
int Connect(MYSQL* ms,const char *host,const char *user,const char *pswd,const char *table, unsigned int port)
{
	if (mysql_real_connect(ms, host, user, pswd, table, port, NULL, 0))
	{
		printf("connect succeed!\n");
		return 1;
	}
	else{
		return 0;
	}
}
//操作
int operate(MYSQL* ms)
{
	string s;
	MYSQL_RES *result;
	MYSQL_FIELD *fd;
	MYSQL_ROW sql_row;				//存放一行查询结果的字符串数组  
	mysql_query(ms, "SET NAMES GBK");				//设置编码格式,否则在cmd下无法显示中文  

	char column[32][32];
	printf("请输入操作命令>");
	getline(cin, s);
	int res;
	if ("exit-myb"==s)
	{
		return 0;
	}
	res = mysql_query(ms,s.c_str());
	if (!res)
	{
		result = mysql_store_result(ms);			//保存查询到的数据到result  

		if (result)
		{
			int i, j;
			cout << "number of result: " << (unsigned long)mysql_num_rows(result) << endl;

			for (i = 0; fd = mysql_fetch_field(result); i++)//获取列名  
			{
				strcpy(column[i], fd->name);
			}
			j = mysql_num_fields(result);
			for (i = 0; i<j; i++)
			{
				printf("%s\t", column[i]);
			}
			printf("\n");


			while (sql_row = mysql_fetch_row(result))//获取具体的数据  
			{
				for (i = 0; i<j; i++)
				{
					printf("%s\t", sql_row[i]);
				}
				printf("\n");
			}
		}
	}

	else
	{
		cout << "query sql failed!" << endl;
		printf("\n%s\n", mysql_error(ms));
		return 1;
	}
	//注意用完数据库要及时回收资源  
	if (result != NULL) mysql_free_result(result);	//释放结果资源  
	

	return 1;
}



int main()
{
	MYSQL ms;
	MySqlInit(&ms);
	const char host[] = "localhost";    //MySQL服务器IP地址；若是本地可填写“localhost”或127.0.0.1  
	const char user[] = "root";         //MySQL的用户名  
	const char pswd[] = "mysql";         //密码  
	const char table[] = "testmyb";        //数据库名称  
	unsigned int port = 3306;           //MySQL服务端口号，默认是3306  
	Connect(&ms, host, user, pswd, table, port);
	int flag = 1;
	while (flag)
	{
		flag=operate(&ms);

	}

	mysql_close(&ms);							//关闭MySQL连接  
	mysql_library_end();	//关闭MySQL库  
}

#endif



#if 0
int main()
{
	const char host[] = "localhost";    //MySQL服务器IP地址；若是本地可填写“localhost”或127.0.0.1  
	const char user[] = "root";         //MySQL的用户名  
	const char pswd[] = "mysql";         //密码  
	const char table[] = "testmyb";        //数据库名称  
	unsigned int port = 3306;           //MySQL服务端口号，默认是3306    

	MYSQL myCont;					//创建MYSQL对象，定义数据库连接句柄  
	MYSQL_RES *result;				//查询结果集，存放查询结果  
	MYSQL_ROW sql_row;				//存放一行查询结果的字符串数组  
	MYSQL_FIELD *fd;				//包含字段信息的结构
	char column[32][32];
	int res;
	mysql_library_init(0, NULL, NULL);	//初始化MySQL库  
	mysql_init(&myCont);				//初始化连接处理程序 


	if (mysql_real_connect(&myCont, host, user, pswd, table, port, NULL, 0))
	{														//通过调用mysql_real_connect()连接到服务器  
		cout << "connect succeed!" << endl;
		mysql_query(&myCont, "SET NAMES GBK");				//设置编码格式,否则在cmd下无法显示中文  

	/*	//插入测试
		int x = mysql_query(&myCont, "insert into xx(a,b) values('qq','ll')");
		if (!x)
		{
		printf("插入成功\n");
		}
		else
		{
		printf("插入失败\n");
		printf("%s\n", mysql_error(&myCont));
		}*/
		//////////////////////////////
		

		res = mysql_query(&myCont, "select * from xx");//执行查询语句，mysql_query如果查询成功，零；如果出现一个错误，非零。

		if (!res)
		{
			result = mysql_store_result(&myCont);			//保存查询到的数据到result  

			if (result)
			{
				int i, j;
				cout << "number of result: " << (unsigned long)mysql_num_rows(result) << endl;

				for (i = 0; fd = mysql_fetch_field(result); i++)//获取列名  
				{
					strcpy(column[i], fd->name);
				}
				j = mysql_num_fields(result);
				for (i = 0; i<j; i++)
				{
					printf("%s\t", column[i]);
				}
				printf("\n");


				while (sql_row = mysql_fetch_row(result))//获取具体的数据  
				{
					for (i = 0; i<j; i++)
					{
						printf("%s\t", sql_row[i]);
					}
					printf("\n");
				}
			}
		}

		else
		{
			cout << "query sql failed!" << endl;
		}


		//printf("\n");

		////删除测试
		//int y = mysql_query(&myCont, "delete from tt8 where a='美国' ");
		//if (!y)
		//{
		//	printf("删除成功\n");
		//}
		//else{
		//	printf("删除失败:%s", mysql_error(&myCont));
		//}

		//printf("\n");
		////更新
		//int z = mysql_query(&myCont, "update tt8 set b='牛逼' where a='中国'");
		//if (!z)
		//{
		//	printf("更新成功！\n");
		//}
		//else
		//{
		//	printf("更新失败%s:", mysql_error(&myCont));
		//}

		//创建教师信息表
		/*int s = mysql_query(&myCont, "create table Teacher(Sno char(9) primary key,Sname char(9));");
		if (!s)
		{
		printf("创建教室信息表成功\n");
		}
		else
		{
		printf("创建失败%s\n",mysql_error(&myCont));
		}*/



	}
	else
	{
		cout << "connect failed!" << endl;
	}



	//注意用完数据库要及时回收资源  
	if (result != NULL) mysql_free_result(result);	//释放结果资源  
	mysql_close(&myCont);							//关闭MySQL连接  
	mysql_library_end();							//关闭MySQL库  
	system("pause");
	return 0;
}
#endif