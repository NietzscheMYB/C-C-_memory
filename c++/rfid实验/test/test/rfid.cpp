#include "stdafx.h"
#include"REX2_API.h"       //REX2 API 标题
#pragma comment(lib,"REX2_API.lib")       //链接库信息


void Register(){
	//连接到目标readerObj的HBE-RFID-REXII 13.56Mhz阅读器寄存器设定为ISO14443A模式

	REX2Reader readerObj;
	TCHAR szPort[] = _T("\\\\.\\COM4");
	if (REX2_Open(&readerObj, szPort, 9600) == FALSE)
	{
		_tprintf(_T("HBE-RFID-REX2 13.56Mhz Reader Open Failed.\r\n"));
	}
	int nResult = REX2_RegisterISO14443A(&readerObj);
	if (nResult == REX2_ERROR_OK)
	{
		_tprintf(_T("Register ISO14443A Success.\r\n"));
	}
	else
	{
		_tprintf(_T("Register ISO 14443A Failed. Error Code : %X\r\n"), nResult);
	}

	if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
}
void REQA(){

	//(1)存储REQA的应答一ATQA的变量数组(2Bytes)
	//(2)向作为目标readerObj连接的阅读器发送REQA命令并将其应答存储到数组atqa中
	//(3)根据成功或者失败，输出其应答。成功时，输出从标签得到应答的ATQA


	REX2Reader readerObj;
	int nResult;

	TCHAR szPort[] = _T("\\\\.\\COM4");
	if (REX2_Open(&readerObj, szPort, 9600) == FALSE)
	{
		_tprintf(_T("HBE-RFID-REX2 13.56Mhz Reader Open Failed.\r\n"));
	}

	nResult = REX2_RegisterISO14443A(&readerObj);
	if (nResult != REX2_ERROR_OK)
	{
		_tprintf(_T("Register ISO 14443A Failed. Error Code : %X\r\n"), nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
	}

	BYTE atqa[2];
	nResult = REX2_ISO14443A_REQA(&readerObj, atqa);
	if (nResult == REX2_ERROR_OK)
	{
		_tprintf(_T("ISO14443A REQA Success. ATQA = %02X%02X\r\n"), atqa[0], atqa[1]);
	}
	else
	{
		_tprintf(_T("ISO14443A REQA Failed!! Error Code : %X\r\n"), nResult);
	}

	if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
}
void Cascade(){
	//(1)存储要运行的cascade层并声明要存储读出的UID的struct REX2UID变量uid和要存储SAK, BCC的BYTE型变量
	//	(2)向阅读器目标readerObj中发送cascade命令
	//	(3)输出读出的UID和BCC, SAK


	REX2Reader readerObj;
	int nResult;

	TCHAR szPort[] = _T("\\\\.\\COM4");
	if (REX2_Open(&readerObj, szPort, 9600) == FALSE)
	{
		_tprintf(_T("HBE-RFID-REX2 13.56Mhz Reader Open Failed.\r\n"));
	}

	nResult = REX2_RegisterISO14443A(&readerObj);
	if (nResult != REX2_ERROR_OK)
	{
		_tprintf(_T("Register ISO 14443A Failed. Error Code : %X\r\n"), nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
	}

	BYTE atqa[2];
	nResult = REX2_ISO14443A_REQA(&readerObj, atqa);
	if (nResult == REX2_ERROR_OK)
	{
		_tprintf(_T("ISO14443A REQA Success. ATQA = %02X%02X\r\n"), atqa[0], atqa[1]);
	}
	else
	{
		_tprintf(_T("ISO14443A REQA Failed!! Error Code : %X\r\n"), nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
	}

	BYTE cascadeLevel = 1; // level
	BYTE bcc, sak;
	REX2UID uid;
	nResult = REX2_ISO14443A_Cascade(&readerObj, cascadeLevel, &uid, &bcc, &sak);
	if (nResult != REX2_ERROR_OK)
	{
		_tprintf(_T("ISO14443A Cascade Level %d Failed. Error Code: %X\r\n"), cascadeLevel, nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
	}

	_tprintf(_T("ISO14443A Cascade Level %d Success. UID="), cascadeLevel);
	for (BYTE i = 0; i<uid.length; i++)
	{
		_tprintf(_T(" %02X"), uid.data[i]);
	}
	_tprintf(_T(", BCC=%02X, SAK=%02X\r\n"), bcc, sak);

	if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
}
void HLTA(){
	//HLTA是停止运行中的ISO14443A标签的命令
	//	(1)通过REQA命令确认标签的存在
	//	(2)为了下达HLTA命令，通过cascade命令确认标签的UID并成为select状态
	//	(3)下达HLTA认命令使标签halt


	REX2Reader readerObj;
	int nResult;

	TCHAR szPort[] = _T("\\\\.\\COM4");
	if (REX2_Open(&readerObj, szPort, 9600) == FALSE)
	{
		_tprintf(_T("HBE-RFID-REX2 13.56Mhz Reader Open Failed.\r\n"));

	}

	nResult = REX2_RegisterISO14443A(&readerObj);
	if (nResult != REX2_ERROR_OK)
	{
		_tprintf(_T("Register ISO 14443A Failed. Error Code : %X\r\n"), nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
	}

	BYTE atqa[2];
	nResult = REX2_ISO14443A_REQA(&readerObj, atqa);
	if (nResult == REX2_ERROR_OK)
	{
		_tprintf(_T("ISO14443A REQA Success. ATQA = %02X%02X\r\n"), atqa[0], atqa[1]);
	}
	else
	{
		_tprintf(_T("ISO14443A REQA Failed!! Error Code : %X\r\n"), nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
	}

	BYTE cascadeLevel = 1; // level
	BYTE bcc, sak;
	REX2UID uid;
	nResult = REX2_ISO14443A_Cascade(&readerObj, cascadeLevel, &uid, &bcc, &sak);
	if (nResult != REX2_ERROR_OK)
	{
		_tprintf(_T("ISO14443A Cascade Level %d Failed. Error Code: %X\r\n"), cascadeLevel, nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
	}

	_tprintf(_T("ISO14443A Cascade Level %d Success. UID="), cascadeLevel);
	for (BYTE i = 0; i<uid.length; i++)
	{
		_tprintf(_T(" %02X"), uid.data[i]);
	}
	_tprintf(_T(", BCC=%02X, SAK=%02X\r\n"), bcc, sak);


	nResult = REX2_ISO14443A_HLTA(&readerObj);
	if (nResult == REX2_ERROR_OK)
	{
		_tprintf(_T("ISO14443A HLTA Success.\r\n"));
	}
	else
	{
		_tprintf(_T("ISO14443A HLTA Failed!!\r\n"), nResult);
	}

	if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
}
void WUPA(){

	//WUPA是激活通过HLTA命令被Halt的标签的命令
	//	(1)发送WUPA命令并收到ATQA值
	//	(2)输出其结果


	REX2Reader readerObj;
	int nResult;

	TCHAR szPort[] = _T("\\\\.\\COM4");

	if (REX2_Open(&readerObj, szPort, 9600) == FALSE)
	{
		_tprintf(_T("HBE-RFID-REX2 13.56Mhz Reader Open Failed.\r\n"));
	}

	nResult = REX2_RegisterISO14443A(&readerObj);
	if (nResult != REX2_ERROR_OK)
	{
		_tprintf(_T("Register ISO 14443A Failed. Error Code : %X\r\n"), nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
	}

	BYTE atqa[2];
	nResult = REX2_ISO14443A_WUPA(&readerObj, atqa);
	if (nResult == REX2_ERROR_OK)
	{
		_tprintf(_T("ISO14443A WUPA Success. ATQA = %02X%02X\r\n"), atqa[0], atqa[1]);
	}
	else
	{
		_tprintf(_T("ISO14443A WUPA Failed!!\r\n"), nResult);
	}

	if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
}
void ISO14443A_UID(){

	//(1)向阅读器ISO14443A UID下达命令
	//	(2)输出作为应答到来的UID


	REX2Reader readerObj;
	int nResult;

	TCHAR szPort[] = _T("\\\\.\\COM4");
	if (REX2_Open(&readerObj, szPort, 9600) == FALSE)
	{
		_tprintf(_T("HBE-RFID-REX2 13.56Mhz Reader Open Failed.\r\n"));
	}

	BYTE uidCnt = 3;
	REX2UID uids[10];
	nResult = REX2_ISO14443A_UID(&readerObj, uids, &uidCnt);
	if (nResult != REX2_ERROR_OK) {
		_tprintf(_T("ISO14443A UID Failed!! Error Code : %02X\r\n"), nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
	}
	_tprintf(_T("ISO14443A UID Success.\r\n"));

	for (BYTE i = 0; i<uidCnt; i++)
	{
		_tprintf(_T("UID %d = "), i + 1);
		for (BYTE j = 0; j<uids[i].length; j++)
		{
			_tprintf(_T("%02X "), uids[i].data[j]);
		}
		_tprintf(_T("\r\n"));
	}

	if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
}
void Register15693(){
	REX2Reader readerObj;

	TCHAR szPort[] = _T("\\\\.\\COM4");
	if (REX2_Open(&readerObj, szPort, 9600) == TRUE)
	{
		_tprintf(_T("HBE-RFID-REX2 13.56Mhz Reader Open Success.\r\n"));
	}

	int nResult = REX2_RegisterISO15693(&readerObj);

	if (nResult == REX2_ERROR_OK)
	{
		_tprintf(_T("Register ISO15693 Success.\r\n"));
	}
	else
	{
		_tprintf(_T("Register ISO15693 Failed. Error Code : %X\r\n"), nResult);
	}

	if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
}
void Inventory(){
	//(1)要存储读出的标签的UID的变量
	//	(2)向当前作为目标readerObj连接的阅读器下达Inventory命令，阅读器作为应答读取1个区域中的ISO15693标签的UID返还，在此函数调用中向uid变量返还读出的标签的UID
	//	(3)输出如标签长度的(18015693的情况为8bytes)UID



	int nResult;
	REX2Reader readerObj;
	TCHAR szPort[] = _T("\\\\.\\COM4");

	if (REX2_Open(&readerObj, szPort, 9600) == FALSE)
	{
		_tprintf(_T("HBE-RFID-REX2 13.56Mhz Reader Open Failed.\r\n"));
	}

	nResult = REX2_RegisterISO15693(&readerObj);
	if (nResult != REX2_ERROR_OK)
	{
		_tprintf(_T("Register ISO15693 Failed. Error Code : %X\r\n"), nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
	}

	REX2UID uid;
	nResult = REX2_ISO15693_Inventory(&readerObj, &uid);
	if (nResult != REX2_ERROR_OK) {
		_tprintf(_T("ISO15693 Inventory Failed!! Error Code : %02X\r\n"), nResult);
	}

	_tprintf(_T("ISO15693 Inventory Success. UID="));
	for (BYTE i = 0; i<uid.length; i++)
	{
		_tprintf(_T(" %02X"), uid.data[i]);
	}
	_tprintf(_T("\r\n"));

	if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);

}
void ReadSingleBlock(){

	//(1)将要读出数据的地址byAddr和要存储读出的数据的BYTE数组data作为因子下达Read Single Block命令
	//	(2)向数组data中输出读出的数据

	int nResult;
	REX2Reader readerObj;
	TCHAR szPort[] = _T("\\\\.\\COM4");
	if (REX2_Open(&readerObj, szPort, 9600) == FALSE)
	{
		_tprintf(_T("HBE-RFID-REX2 13.56Mhz Reader Open Failed.\r\n"));
	}

	nResult = REX2_RegisterISO15693(&readerObj);
	if (nResult != REX2_ERROR_OK)
	{
		_tprintf(_T("Register ISO15693 Failed. Error Code : %X\r\n"), nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
	}
	BYTE byAddr = 1; // block 
	BYTE data[4];
	nResult = REX2_ISO15693_ReadSingleBlock(&readerObj, byAddr, data);
	if (nResult != REX2_ERROR_OK)
	{
		_tprintf(_T("ISO15693 Read Single Block Failed!! Error Code : %02X\r\n"), nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
	}

	_tprintf(_T("ISO15693 Read Single Block Success. Block %d's data ="), byAddr);
	for (BYTE i = 0; i<4; i++)
	{
		_tprintf(_T(" %02X"), data[i]);
	}
	_tprintf(_T("\r\n"));

	if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
}
void WriteSingleBlock(){
	//(1)声明包含标签中要记录的数据的BYTE数组writeData
	//	(2)向标签的byAddr块中记录writeData数组中包含的内容
	//	(3)通过Read Single Block命令读取输出标签的byAddr块的内容，可以确认在(2)中执行过的内容是否正常


	int nResult;
	REX2Reader readerObj;
	TCHAR szPort[] = _T("\\\\.\\COM4");
	if (REX2_Open(&readerObj, szPort, 9600) == FALSE)
	{
		_tprintf(_T("HBE-RFID-REX2 13.56Mhz Reader Open Failed.\r\n"));
	}

	nResult = REX2_RegisterISO15693(&readerObj);
	if (nResult != REX2_ERROR_OK)
	{
		_tprintf(_T("Register ISO15693 Failed. Error Code : %X\r\n"), nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
	}

	BYTE byAddr = 1; // block 
	BYTE writeData[] = { 0xAA, 0xBB, 0xCC, 0xDD };

	nResult = REX2_ISO15693_WriteSingleBlock(&readerObj, byAddr, writeData);
	if (nResult == REX2_ERROR_OK)
	{
		_tprintf(_T("ISO15693 Write Single Block Success! \n"), nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);

	}

	BYTE readData[4];
	nResult = REX2_ISO15693_ReadSingleBlock(&readerObj, byAddr, readData);
	if (nResult != REX2_ERROR_OK)
	{
		_tprintf(_T("ISO15693 Read Single Block Failed!! Error Code : %02X\r\n"), nResult);
	}

	_tprintf(_T("ISO15693 Read Single Block Success. Block %d's data ="), byAddr);
	for (BYTE i = 0; i<4; i++)
	{
		_tprintf(_T(" %02X"), readData[i]);
	}
	_tprintf(_T("\r\n"));

	if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);

}
void ReadMultipleBlocks(){

	//(1)指定要读出数据的空间和要读出的地址，块个数，
	//	A.data：要存储读出的数据的数组变量
	//	B.byAddr：要读出数据的开始地址
	//	C.byNumOfBlock：要读出的块的数
	//	(2)向作为readerObj连接的阅读器以(1)中说明的变量为因子下达Read Multiple Blocks命令
	//	(3)输出读出的数据

	int nResult;
	REX2Reader readerObj;
	TCHAR szPort[] = _T("\\\\.\\COM4");
	if (REX2_Open(&readerObj, szPort, 9600) == FALSE)
	{
		_tprintf(_T("HBE-RFID-REX2 13.56Mhz Reader Open Failed.\r\n"));
	}

	nResult = REX2_RegisterISO15693(&readerObj);
	if (nResult != REX2_ERROR_OK)
	{
		_tprintf(_T("Register ISO15693 Failed. Error Code : %X\r\n"), nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
	}

	BYTE data[16]; // 4(per block) * 4(blocks)
	BYTE byAddr = 0;
	BYTE byNumOfBlock = 4;

	nResult = REX2_ISO15693_ReadMultiBlock(&readerObj, byAddr, byNumOfBlock, data);
	if (nResult != REX2_ERROR_OK)
	{
		_tprintf(_T("ISO15693 Read Multiple Blocks Failed!! Error Code : %02X\r\n"), nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
	}

	_tprintf(_T("ISO15693 Read Multiple Blocks Success. %d to %d block's data ="), byAddr, byNumOfBlock);
	for (BYTE i = 0; i<(4 * byNumOfBlock); i++)
	{
		_tprintf(_T(" %02X"), data[i]);
	}
	_tprintf(_T("\r\n"));

	if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);

}
void StayQuite(){

	//(1)阅读器为了读出要下达Stay Quiet命令的标签的UID, 下达Inventory命令
	//	(2)向标签下达Stay Quiet命令，使成为quiet状念


	int nResult;
	REX2Reader readerObj;
	TCHAR szPort[] = _T("\\\\.\\COM4");
	if (REX2_Open(&readerObj, szPort, 9600) == FALSE)
	{
		_tprintf(_T("HBE-RFID-REX2 13.56Mhz Reader Open Failed.\r\n"));
	}

	nResult = REX2_RegisterISO15693(&readerObj);
	if (nResult != REX2_ERROR_OK)
	{
		_tprintf(_T("Register ISO15693 Failed. Error Code : %X\r\n"), nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
	}

	REX2UID uid;
	nResult = REX2_ISO15693_Inventory(&readerObj, &uid);
	if (nResult != REX2_ERROR_OK) {
		_tprintf(_T("ISO15693 Inventory Failed!! Error Code : %02X\r\n"), nResult);

	}

	_tprintf(_T("ISO15693 Inventory Success. UID="));
	for (BYTE i = 0; i<uid.length; i++)
	{
		_tprintf(_T(" %02X"), uid.data[i]);
	}
	_tprintf(_T("\r\n"));

	nResult = REX2_ISO15693_StayQuiet(&readerObj);
	if (nResult == REX2_ERROR_OK)
	{
		_tprintf(_T("ISO15693 Stay Quiet Success.\r\n"));
	}
	else
	{
		_tprintf(_T("ISO15693 Stay Quiet Failed!! Error Code : %02X\r\n"), nResult);
	}

	if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
}
void ResetToReady(){

	/*向标签发送Reset To Ready命令*/
	int nResult;
	REX2Reader readerObj;
	TCHAR szPort[] = _T("\\\\.\\COM4");
	if (REX2_Open(&readerObj, szPort, 9600) == FALSE)
	{
		_tprintf(_T("HBE-RFID-REX2 13.56Mhz Reader Open Failed.\r\n"));
	}

	nResult = REX2_RegisterISO15693(&readerObj);
	if (nResult != REX2_ERROR_OK)
	{
		_tprintf(_T("Register ISO15693 Failed. Error Code : %X\r\n"), nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
	}

	nResult = REX2_ISO15693_ResetToReady(&readerObj);
	if (nResult == REX2_ERROR_OK)
	{
		_tprintf(_T("ISO15693 Reset To Ready Success.\r\n"));
	}
	else
	{
		_tprintf(_T("ISO15693 Reset To Ready Failed!! Error Code : %02X\r\n"), nResult);
	}

	if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
}
void ISO15693_UID(){

//	(1)声明要存储读出的标签的UID的个数的uidCnt变量和要存储标签的REX2UID型变量数组uids
//		(2)以(1)中声明的变量为因子下达ISO15693 UID命令
//		(3)如uidCnt一样输出读出的标签UID。各UID的长度被记录到了REX2UID型变量的成员中length中


	int nResult;
	REX2Reader readerObj;
	TCHAR szPort[] = _T("\\\\.\\COM3");
	if (REX2_Open(&readerObj, szPort, 9600) == FALSE)
	{
		_tprintf(_T("HBE-RFID-REX2 13.56Mhz Reader Open Failed.\r\n"));
	}

	BYTE uidCnt;
	REX2UID uids[10];
	nResult = REX2_ISO15693_UID(&readerObj, uids, &uidCnt);
	if (nResult != REX2_ERROR_OK) {
		_tprintf(_T("ISO15693 UID Failed!! Error Code : %02X\r\n"), nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
	}

	_tprintf(_T("ISO15693 UID Success.\r\n"));
	for (BYTE i = 0; i<uidCnt; i++)
	{
		_tprintf(_T("UID %d = "), i + 1);
		for (BYTE j = 0; j<uids[i].length; j++)
		{
			_tprintf(_T("%02X "), uids[i].data[j]);
		}
		_tprintf(_T("\r\n"));
	}

	if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);

}
void ISO14443A(){
	REX2Reader readerObj;
	TCHAR szPort[] = _T("\\\\.\\COM4");

	if (REX2_Open(&readerObj, szPort, 9600) == TRUE)
	{
		_tprintf(_T("HBE-RFID-REX2 13.56Mhz Reader Open Sccess.\r\n"));
	}

	int nResult = REX2_RegisterISO14443A(&readerObj);

	if (nResult == REX2_ERROR_OK)
	{
		_tprintf(_T("Register ISO14443A Success.\r\n"));
	}
	else
	{
		_tprintf(_T("Register ISO 14443A Failed. Error Code : %X\r\n"), nResult);
	}
	BYTE atqa[2];
	nResult = REX2_ISO14443A_REQA(&readerObj, atqa);
	if (nResult == REX2_ERROR_OK)
	{
		_tprintf(_T("ISO14443A REQA Success. ATQA = %02X%02X\r\n"), atqa[0], atqa[1]);
	}
	else
	{
		_tprintf(_T("ISO14443A REQA Failed!! Error Code : %X\r\n"), nResult);
	}
	BYTE cascadeLevel = 1; // level
	BYTE bcc, sak;
	REX2UID uid;
	nResult = REX2_ISO14443A_Cascade(&readerObj, cascadeLevel, &uid, &bcc, &sak);
	if (nResult != REX2_ERROR_OK)
	{
		_tprintf(_T("ISO14443A Cascade Level %d Failed. Error Code: %X\r\n"), cascadeLevel, nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
	}

	_tprintf(_T("ISO14443A Cascade Level %d Success. UID="), cascadeLevel);
	for (BYTE i = 0; i<uid.length; i++)
	{
		_tprintf(_T(" %02X"), uid.data[i]);
	}
	_tprintf(_T(", BCC=%02X, SAK=%02X\r\n"), bcc, sak);

	nResult = REX2_ISO14443A_HLTA(&readerObj);
	if (nResult == REX2_ERROR_OK)
	{
		_tprintf(_T("ISO14443A HLTA Success.\r\n"));
	}
	else
	{
		_tprintf(_T("ISO14443A HLTA Failed!!\r\n"), nResult);
	}

	nResult = REX2_ISO14443A_WUPA(&readerObj, atqa);
	if (nResult == REX2_ERROR_OK)
	{
		_tprintf(_T("ISO14443A WUPA Success. ATQA = %02X%02X\r\n"), atqa[0], atqa[1]);
	}
	else
	{
		_tprintf(_T("ISO14443A WUPA Failed!!\r\n"), nResult);
	}

	if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);
}

void ISO15693(){
	REX2Reader readerObj;
	TCHAR szPort[] = _T("\\\\.\\COM4");
	if (REX2_Open(&readerObj, szPort, 9600) == TRUE)
	{
		_tprintf(_T("HBE-RFID-REX2 13.56Mhz Reader Open Success.\r\n"));
	}

	int nResult = REX2_RegisterISO15693(&readerObj);

	if (nResult == REX2_ERROR_OK)
	{
		_tprintf(_T("Register ISO15693 Success.\r\n"));
	}
	else
	{
		_tprintf(_T("Register ISO15693 Failed. Error Code : %X\r\n"), nResult);
	}

	REX2UID uid;
	nResult = REX2_ISO15693_Inventory(&readerObj, &uid);
	if (nResult != REX2_ERROR_OK) {
		_tprintf(_T("ISO15693 Inventory Failed!! Error Code : %02X\r\n"), nResult);
	}

	_tprintf(_T("ISO15693 Inventory Success. UID="));
	for (BYTE i = 0; i<uid.length; i++)
	{
		_tprintf(_T(" %02X"), uid.data[i]);
	}
	_tprintf(_T("\r\n"));

	nResult = REX2_ISO15693_StayQuiet(&readerObj);
	if (nResult == REX2_ERROR_OK)
	{
		_tprintf(_T("ISO15693 Stay Quiet Success.\r\n"));
	}
	else
	{
		_tprintf(_T("ISO15693 Stay Quiet Failed!! Error Code : %02X\r\n"), nResult);
	}

	nResult = REX2_ISO15693_ResetToReady(&readerObj);
	if (nResult == REX2_ERROR_OK)
	{
		_tprintf(_T("ISO15693 Reset To Ready Success.\r\n"));
	}
	else
	{
		_tprintf(_T("ISO15693 Reset To Ready Failed!! Error Code : %02X\r\n"), nResult);
	}
	BYTE byAddr = 1; // block 
	BYTE data[4];
	nResult = REX2_ISO15693_ReadSingleBlock(&readerObj, byAddr, data);
	if (nResult != REX2_ERROR_OK)
	{
		_tprintf(_T("ISO15693 Read Single Block Failed!! Error Code : %02X\r\n"), nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);

	}

	_tprintf(_T("ISO15693 Read Single Block Success. Block %d's data ="), byAddr);
	for (BYTE i = 0; i<4; i++)
	{
		_tprintf(_T(" %02X"), data[i]);
	}
	_tprintf(_T("\r\n"));

	byAddr = 1; // block 
	BYTE writeData[] = { 0xAA, 0xBB, 0xCC, 0xDD };

	nResult = REX2_ISO15693_WriteSingleBlock(&readerObj, byAddr, writeData);
	if (nResult == REX2_ERROR_OK)
	{
		_tprintf(_T("ISO15693 Write Single Block Success! \n"), nResult);
		if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);

	}

	BYTE readData[4];
	nResult = REX2_ISO15693_ReadSingleBlock(&readerObj, byAddr, readData);

	_tprintf(_T("ISO15693 Read Single Block Success. Block %d's data ="), byAddr);
	for (BYTE i = 0; i<4; i++)
	{
		_tprintf(_T(" %02X"), readData[i]);
	}
	_tprintf(_T("\r\n"));

	BYTE data1[16]; // 4(per block) * 4(blocks)
	byAddr = 0;
	BYTE byNumOfBlock = 4;

	nResult = REX2_ISO15693_ReadMultiBlock(&readerObj, byAddr, byNumOfBlock, data1);

	_tprintf(_T("ISO15693 Read Multiple Blocks Success. %d to %d block's data ="), byAddr, byNumOfBlock);
	for (BYTE i = 0; i<(4 * byNumOfBlock); i++)
	{
		_tprintf(_T(" %02X"), data1[i]);
	}
	_tprintf(_T("\r\n"));

	if (REX2_IsOpen(&readerObj)) REX2_Close(&readerObj);


}
int _tmain(int argc, _TCHAR* argv[])
{
	/*****14443A******/
	//Register();
	//REQA();
	//Cascade();
	//HLTA();
	//WUPA();
	//ISO14443A();
	//ISO14443A_UID();
	/****15693****/
	// Register15693();
	//Inventory();
	//ReadSingleBlock();
	//WriteSingleBlock();
	//ReadMultipleBlocks();
	//StayQuite();
	//Inventory();
	//ResetToReady();
	//ISO15693_UID();
	ISO15693();
	return 0;
}
