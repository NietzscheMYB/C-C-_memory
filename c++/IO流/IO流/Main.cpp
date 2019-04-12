#include <iostream>
#include <fstream>
using namespace std;
//ʹ���ļ�IO�����ı��������Ʒ�ʽ��ʾ��д
//�����ļ�
struct ServerInfo
{
	char _ip[32];//ip
	int _port;//�˿�
};
struct ConfigManager
{

public:
	ConfigManager(const char* configfile = "bitserver.config")
		:_configfile(configfile)
	{}
	void WriteBin(const ServerInfo& info)
	{
		//����ע���ö����Ƶķ�ʽ��
		ofstream ofs(_configfile, ifstream::in | ifstream::binary);
		ofs.write((const char*)&info, sizeof(ServerInfo));
		ofs.close();
	}
	void ReadBin(ServerInfo& info)
	{
		//����ע��ʹ�ö����Ʒ�ʽ�򿪶�
		ifstream ifs(_configfile, ifstream::out | ifstream::binary);
		ifs.read((char*)&info, sizeof(ServerInfo));
		ifs.close();
	}

private:
	string _configfile;//�����ļ�
};
int main()
{	
	return 0;
}