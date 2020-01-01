#include "stdafx.h"
#include"REX2_API.h"       //REX2 API ����
#pragma comment(lib,"REX2_API.lib")       //���ӿ���Ϣ


void Register(){
	//���ӵ�Ŀ��readerObj��HBE-RFID-REXII 13.56Mhz�Ķ����Ĵ����趨ΪISO14443Aģʽ

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

	//(1)�洢REQA��Ӧ��һATQA�ı�������(2Bytes)
	//(2)����ΪĿ��readerObj���ӵ��Ķ�������REQA�������Ӧ��洢������atqa��
	//(3)���ݳɹ�����ʧ�ܣ������Ӧ�𡣳ɹ�ʱ������ӱ�ǩ�õ�Ӧ���ATQA


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
	//(1)�洢Ҫ���е�cascade�㲢����Ҫ�洢������UID��struct REX2UID����uid��Ҫ�洢SAK, BCC��BYTE�ͱ���
	//	(2)���Ķ���Ŀ��readerObj�з���cascade����
	//	(3)���������UID��BCC, SAK


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
	//HLTA��ֹͣ�����е�ISO14443A��ǩ������
	//	(1)ͨ��REQA����ȷ�ϱ�ǩ�Ĵ���
	//	(2)Ϊ���´�HLTA���ͨ��cascade����ȷ�ϱ�ǩ��UID����Ϊselect״̬
	//	(3)�´�HLTA������ʹ��ǩhalt


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

	//WUPA�Ǽ���ͨ��HLTA���Halt�ı�ǩ������
	//	(1)����WUPA����յ�ATQAֵ
	//	(2)�������


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

	//(1)���Ķ���ISO14443A UID�´�����
	//	(2)�����ΪӦ������UID


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
	//(1)Ҫ�洢�����ı�ǩ��UID�ı���
	//	(2)��ǰ��ΪĿ��readerObj���ӵ��Ķ����´�Inventory����Ķ�����ΪӦ���ȡ1�������е�ISO15693��ǩ��UID�������ڴ˺�����������uid�������������ı�ǩ��UID
	//	(3)������ǩ���ȵ�(18015693�����Ϊ8bytes)UID



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

	//(1)��Ҫ�������ݵĵ�ַbyAddr��Ҫ�洢���������ݵ�BYTE����data��Ϊ�����´�Read Single Block����
	//	(2)������data���������������

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
	//(1)����������ǩ��Ҫ��¼�����ݵ�BYTE����writeData
	//	(2)���ǩ��byAddr���м�¼writeData�����а���������
	//	(3)ͨ��Read Single Block�����ȡ�����ǩ��byAddr������ݣ�����ȷ����(2)��ִ�й��������Ƿ�����


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

	//(1)ָ��Ҫ�������ݵĿռ��Ҫ�����ĵ�ַ���������
	//	A.data��Ҫ�洢���������ݵ��������
	//	B.byAddr��Ҫ�������ݵĿ�ʼ��ַ
	//	C.byNumOfBlock��Ҫ�����Ŀ����
	//	(2)����ΪreaderObj���ӵ��Ķ�����(1)��˵���ı���Ϊ�����´�Read Multiple Blocks����
	//	(3)�������������

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

	//(1)�Ķ���Ϊ�˶���Ҫ�´�Stay Quiet����ı�ǩ��UID, �´�Inventory����
	//	(2)���ǩ�´�Stay Quiet���ʹ��Ϊquiet״��


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

	/*���ǩ����Reset To Ready����*/
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

//	(1)����Ҫ�洢�����ı�ǩ��UID�ĸ�����uidCnt������Ҫ�洢��ǩ��REX2UID�ͱ�������uids
//		(2)��(1)�������ı���Ϊ�����´�ISO15693 UID����
//		(3)��uidCntһ����������ı�ǩUID����UID�ĳ��ȱ���¼����REX2UID�ͱ����ĳ�Ա��length��


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
