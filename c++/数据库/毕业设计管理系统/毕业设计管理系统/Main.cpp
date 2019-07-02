#define _CRT_SECURE_NO_WARNINGS

#include <iostream>  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include<string>

//��������ͷ�ļ���˳���ܵߵ�  
#include "winsock2.h"  
#include "windows.h"  
#include "mysql.h"  

using namespace std;

class mysql{
public:
	mysql()
	{
		_host= "localhost";    //MySQL������IP��ַ�����Ǳ��ؿ���д��localhost����127.0.0.1  
		_user= "root";         //MySQL���û���  
		_pswd= "mysql";         //����  
		_table= "testmyb";        //���ݿ�����  
		_port = 3306;           //MySQL����˿ںţ�Ĭ����3306  
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
		mysql_query(&_ms, "SET NAMES GBK");//���ñ����ʽ�������޷���cmd����ʾ����
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
		mysql_query(&_ms, "SET NAMES GBK");//���ñ����ʽ�������޷���cmd����ʾ����

	}
	~mysql(){
		mysql_close(&_ms);//�ر�mysql����
		mysql_library_end();//�ر�mysql��
		cout << "bye��" << endl;

	}
	bool operate()
	{
		cout << "����������>";
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
			_result = mysql_store_result(&_ms); //�����ѯ����
			//************************��ӡ
			if (_result)
			{
				int i, j;
				cout << "number of result: " << (unsigned long)mysql_num_rows(_result) << endl;

				for (i = 0; _fd = mysql_fetch_field(_result); i++)//��ȡ����  
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


				while (_sql_row = mysql_fetch_row(_result))//��ȡ���������  
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
		//ע���������ݿ�Ҫ��ʱ������Դ  
		if (_result != NULL) mysql_free_result(_result);	//�ͷŽ����Դ  
		return true;
	}

private:
	MYSQL _ms;//����mysql���󣬶������ݿ����Ӿ��
	MYSQL_RES *_result;//��ѯ����� ��Ų�ѯ���
	MYSQL_ROW _sql_row;//���һ�в�ѯ������ַ�������  
	MYSQL_FIELD *_fd; // �����ֶ���Ϣ�Ľṹ

	char _column[32][32];

	const char *_host ;    //MySQL������IP��ַ�����Ǳ��ؿ���д��localhost����127.0.0.1  
	const char *_user;         //MySQL���û���  
	const char *_pswd ;         //����  
	const char *_table ;        //���ݿ�����  
	unsigned int _port;           //MySQL����˿ںţ�Ĭ����3306   
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
			break;           //�˳�  exit-myb
		}
	}
	return 0;
}




#if 0
//��ʼ��
void MySqlInit(MYSQL* ms)
{
	mysql_library_init(0, NULL, NULL);
	mysql_init(ms);
}
//����
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
//����
int operate(MYSQL* ms)
{
	string s;
	MYSQL_RES *result;
	MYSQL_FIELD *fd;
	MYSQL_ROW sql_row;				//���һ�в�ѯ������ַ�������  
	mysql_query(ms, "SET NAMES GBK");				//���ñ����ʽ,������cmd���޷���ʾ����  

	char column[32][32];
	printf("�������������>");
	getline(cin, s);
	int res;
	if ("exit-myb"==s)
	{
		return 0;
	}
	res = mysql_query(ms,s.c_str());
	if (!res)
	{
		result = mysql_store_result(ms);			//�����ѯ�������ݵ�result  

		if (result)
		{
			int i, j;
			cout << "number of result: " << (unsigned long)mysql_num_rows(result) << endl;

			for (i = 0; fd = mysql_fetch_field(result); i++)//��ȡ����  
			{
				strcpy(column[i], fd->name);
			}
			j = mysql_num_fields(result);
			for (i = 0; i<j; i++)
			{
				printf("%s\t", column[i]);
			}
			printf("\n");


			while (sql_row = mysql_fetch_row(result))//��ȡ���������  
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
	//ע���������ݿ�Ҫ��ʱ������Դ  
	if (result != NULL) mysql_free_result(result);	//�ͷŽ����Դ  
	

	return 1;
}



int main()
{
	MYSQL ms;
	MySqlInit(&ms);
	const char host[] = "localhost";    //MySQL������IP��ַ�����Ǳ��ؿ���д��localhost����127.0.0.1  
	const char user[] = "root";         //MySQL���û���  
	const char pswd[] = "mysql";         //����  
	const char table[] = "testmyb";        //���ݿ�����  
	unsigned int port = 3306;           //MySQL����˿ںţ�Ĭ����3306  
	Connect(&ms, host, user, pswd, table, port);
	int flag = 1;
	while (flag)
	{
		flag=operate(&ms);

	}

	mysql_close(&ms);							//�ر�MySQL����  
	mysql_library_end();	//�ر�MySQL��  
}

#endif



#if 0
int main()
{
	const char host[] = "localhost";    //MySQL������IP��ַ�����Ǳ��ؿ���д��localhost����127.0.0.1  
	const char user[] = "root";         //MySQL���û���  
	const char pswd[] = "mysql";         //����  
	const char table[] = "testmyb";        //���ݿ�����  
	unsigned int port = 3306;           //MySQL����˿ںţ�Ĭ����3306    

	MYSQL myCont;					//����MYSQL���󣬶������ݿ����Ӿ��  
	MYSQL_RES *result;				//��ѯ���������Ų�ѯ���  
	MYSQL_ROW sql_row;				//���һ�в�ѯ������ַ�������  
	MYSQL_FIELD *fd;				//�����ֶ���Ϣ�Ľṹ
	char column[32][32];
	int res;
	mysql_library_init(0, NULL, NULL);	//��ʼ��MySQL��  
	mysql_init(&myCont);				//��ʼ�����Ӵ������ 


	if (mysql_real_connect(&myCont, host, user, pswd, table, port, NULL, 0))
	{														//ͨ������mysql_real_connect()���ӵ�������  
		cout << "connect succeed!" << endl;
		mysql_query(&myCont, "SET NAMES GBK");				//���ñ����ʽ,������cmd���޷���ʾ����  

	/*	//�������
		int x = mysql_query(&myCont, "insert into xx(a,b) values('qq','ll')");
		if (!x)
		{
		printf("����ɹ�\n");
		}
		else
		{
		printf("����ʧ��\n");
		printf("%s\n", mysql_error(&myCont));
		}*/
		//////////////////////////////
		

		res = mysql_query(&myCont, "select * from xx");//ִ�в�ѯ��䣬mysql_query�����ѯ�ɹ����㣻�������һ�����󣬷��㡣

		if (!res)
		{
			result = mysql_store_result(&myCont);			//�����ѯ�������ݵ�result  

			if (result)
			{
				int i, j;
				cout << "number of result: " << (unsigned long)mysql_num_rows(result) << endl;

				for (i = 0; fd = mysql_fetch_field(result); i++)//��ȡ����  
				{
					strcpy(column[i], fd->name);
				}
				j = mysql_num_fields(result);
				for (i = 0; i<j; i++)
				{
					printf("%s\t", column[i]);
				}
				printf("\n");


				while (sql_row = mysql_fetch_row(result))//��ȡ���������  
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

		////ɾ������
		//int y = mysql_query(&myCont, "delete from tt8 where a='����' ");
		//if (!y)
		//{
		//	printf("ɾ���ɹ�\n");
		//}
		//else{
		//	printf("ɾ��ʧ��:%s", mysql_error(&myCont));
		//}

		//printf("\n");
		////����
		//int z = mysql_query(&myCont, "update tt8 set b='ţ��' where a='�й�'");
		//if (!z)
		//{
		//	printf("���³ɹ���\n");
		//}
		//else
		//{
		//	printf("����ʧ��%s:", mysql_error(&myCont));
		//}

		//������ʦ��Ϣ��
		/*int s = mysql_query(&myCont, "create table Teacher(Sno char(9) primary key,Sname char(9));");
		if (!s)
		{
		printf("����������Ϣ��ɹ�\n");
		}
		else
		{
		printf("����ʧ��%s\n",mysql_error(&myCont));
		}*/



	}
	else
	{
		cout << "connect failed!" << endl;
	}



	//ע���������ݿ�Ҫ��ʱ������Դ  
	if (result != NULL) mysql_free_result(result);	//�ͷŽ����Դ  
	mysql_close(&myCont);							//�ر�MySQL����  
	mysql_library_end();							//�ر�MySQL��  
	system("pause");
	return 0;
}
#endif