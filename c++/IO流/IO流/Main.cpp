#include <iostream>
#include <fstream>
using namespace std;
//使用文件IO流用文本及二进制方式演示读写
//配置文件
struct ServerInfo
{
	char _ip[32];//ip
	int _port;//端口
};
struct ConfigManager
{

public:
	ConfigManager(const char* configfile = "bitserver.config")
		:_configfile(configfile)
	{}
	void WriteBin(const ServerInfo& info)
	{
		//这里注意用二进制的方式打开
		ofstream ofs(_configfile, ifstream::in | ifstream::binary);
		ofs.write((const char*)&info, sizeof(ServerInfo));
		ofs.close();
	}
	void ReadBin(ServerInfo& info)
	{
		//这里注意使用二进制方式打开读
		ifstream ifs(_configfile, ifstream::out | ifstream::binary);
		ifs.read((char*)&info, sizeof(ServerInfo));
		ifs.close();
	}

private:
	string _configfile;//配置文件
};
int main()
{	
	return 0;
}