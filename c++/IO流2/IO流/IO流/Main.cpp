#include <iostream>
#include <fstream>
using namespace std;

//ifstream ifile (ֻ�����ã�
//ofstream  ofile��ֻ����ã�
//fstream iofile��������������ã�

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
	void WriteText(const ServerInfo& info)
	{
		//����ᷢ��IO��д���α�c�������׾ͼ򵥶���
		//c���Ե��Ȱ�����itoa��д
		ofstream ofs(_configfile);
		ofs << info._ip << endl;
		ofs << info._port << endl;
		ofs << info._ip << endl;
		ofs << info._port << endl;
		ofs.close();
	}

	void ReadText(ServerInfo& info)
	{
		//����ᷢ��IO�������α�c�������׾ͼ򵥶���
		//c���Ե��ȶ��ַ��� ��atoi
		ifstream ifs(_configfile);
		ifs >> info._ip;
		ifs >> info._port;
		ifs.close();
	}

private:
	string _configfile;//�����ļ�
};
int main()
{	
	ConfigManager cfgMgr;
	ServerInfo wtinfo;
	ServerInfo rdinfo;
	strcpy(wtinfo._ip, "127.0.0.1");
	wtinfo._port = 80;


	//�����ƶ�д
	cfgMgr.WriteBin(wtinfo);
	cfgMgr.ReadBin(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;


	//�ı���д
	cfgMgr.WriteText(wtinfo);
	cfgMgr.ReadText(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	return 0;
}