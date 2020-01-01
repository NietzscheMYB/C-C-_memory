#ifndef REX2API_H
#define REX2API_H

#include <windows.h>

/*************************************************************/
#define WM_REX2_SERIAL_TX				WM_USER+1
#define WM_REX2_SERIAL_RX				WM_USER+2

#define WM_REX2_UID_ALL				WM_USER+3
#define WM_REX2_UID_ISO14443A		WM_USER+4
#define WM_REX2_UID_ISO15693		WM_USER+5
#define WM_REX2_LOOP_STOPED			WM_USER+6

#define REX2_CARDTYPE_ISO14443A			0x02
#define REX2_CARDTYPE_ISO14443B			0x03
#define REX2_CARDTYPE_ISO15693			0x04
#define REX2_CARDTYPE_FELICA			0x09

#define REX2_UID_LENGTH_ISO14443A		4
#define REX2_UID_LENGTH_ISO14443B		4
#define REX2_UID_LENGTH_ISO15693		8
#define REX2_UID_LENGTH_FELICA			16
/*************************************************************/

// error table
#define REX2_ERROR_OK					0x0000 // no error
#define REX2_ERROR_UNKNOWN				0x0001

#define REX2_ACK						0xA5
#define REX2_NACK						0xBC
#define REX2_ERROR_MISMATCH				0x0011

#define REX2_ERROR_WRONG_PARAM			0x0012

#define REX2_ERROR_UART_RECEIVE_FAIL	0x1001
#define REX2_ERROR_UART_SEND_FAIL		0x1002
#define REX2_ERROR_UART_NOT_VALID		0x1003
#define REX2_ERROR_UART_NOT_OPENED		0x1004
#define REX2_ERROR_UART_TIMEOUT			0x1005
#define REX2_ERROR_UART_STX_ERROR		0x1006

//
#define REX2_ERROR_REG_INTERFACE_PARALLEL 0x1101
#define REX2_ERROR_REG_INTERFACE_SPI 0x1102
#define REX2_ERROR_REG_WRITE 0x1103
#define REX2_ERROR_REG_READ 0x1104
#define REX2_ERROR_ALL_UID 0x1105 //
// - cmd fail
#define REX2_ERROR_ISO14443A_REGISTER 0x1201
#define REX2_ERROR_ISO14443A_REQA 0x1202
#define REX2_ERROR_ISO14443A_CASCADE 0x1203
//#define REX2_ERROR_ISO14443A_CASCADE_LEVEL1 0x1103
//#define REX2_ERROR_ISO14443A_CASCADE_LEVEL2 0x1104
//#define REX2_ERROR_ISO14443A_CASCADE_LEVEL3 0x1105
#define REX2_ERROR_ISO14443A_HLTA 0x1206
#define REX2_ERROR_ISO14443A_WUPA 0x1207
#define REX2_ERROR_ISO14443A_UID 0x1208
#define REX2_ERROR_ISO14443A_LOOP 0x1209

#define REX2_ERROR_ISO15693_REGISTER 0x1301
#define REX2_ERROR_ISO15693_INVENTORY 0x1302
#define REX2_ERROR_ISO15693_STAYQUIET 0x1303
#define REX2_ERROR_ISO15693_BLOCK 0x1304
#define REX2_ERROR_ISO15693_UID 0x1305
#define REX2_ERROR_ISO15693_LOOP 0x1306
#define REX2_ERROR_ISO15693_RESETTOREADY 0x1307
/*************************************************************/

// stx, etx
#define REX2_FRAME_STX	0xAA
#define REX2_FRAME_ETX	0xFF
/*************************************************************/

//addr 
#define REX2_ADDR_REX 0x28

// protocol
// - register?? default??
#define REX2_PROTOCOL_REGISTER 0x01
// - iso14443a
#define REX2_PROTOCOL_ISO14443A 0x02
// - iso15693
#define REX2_PROTOCOL_ISO15693 0x04

//Command
// - default
#define REX2_CMD_REG_INTERFACE_PARALLEL 0x01
#define REX2_CMD_REG_INTERFACE_SPI 0x02
#define REX2_CMD_REG_WRITE 0x03
#define REX2_CMD_REG_READ 0x04
#define REX2_CMD_ALL_UID 0x05 //
// - 14443a
#define REX2_CMD_ISO14443A_REGISTER 0x01
#define REX2_CMD_ISO14443A_REQA 0x02
#define REX2_CMD_ISO14443A_CASCADE_LEVEL1 0x03
#define REX2_CMD_ISO14443A_CASCADE_LEVEL2 0x04
#define REX2_CMD_ISO14443A_CASCADE_LEVEL3 0x05
#define REX2_CMD_ISO14443A_HLTA 0x06
#define REX2_CMD_ISO14443A_WUPA 0x07
#define REX2_CMD_ISO14443A_UID 0x08
#define REX2_CMD_ISO14443A_LOOP 0x09
// - 15693
#define REX2_CMD_ISO15693_REGISTER 0x01
#define REX2_CMD_ISO15693_INVENTORY 0x02
#define REX2_CMD_ISO15693_STAYQUIET 0x03
#define REX2_CMD_ISO15693_FUNCTION 0x04
#define REX2_CMD_ISO15693_UID 0x05
#define REX2_CMD_ISO15693_LOOP 0x06

#define REX2_CMD_SUB1_ISO15693_ETC 0x02

#define REX2_CMD_SUB2_ISO15693_RESET_TO_READY 0x26


#define REX2_CMD_SUB2_ISO15693_BLOCK_SINGLE_READ 0x20
#define REX2_CMD_SUB2_ISO15693_BLOCK_SINGLE_WRITE 0x21
#define REX2_CMD_SUB2_ISO15693_BLOCK_MULTI_READ 0x23

// response
#define REX2_ACK 0xA5
#define REX2_NACK 0xBC

/***************************************************************************************************/
#define MAX_BUF_SIZE 640
#define FRAME_SIZE(x) ((*x).length+5) // STX, ETX 길이 제외
/***************************************************************************************************/

typedef struct _REX2Reader
{
	HANDLE serialObj;
	HWND msgHwnd;
	BOOL bLoop;
	HANDLE hThread;
	TCHAR szPort[10];
	int nBaudRate;
} REX2Reader;

typedef struct _REX2Frame
{
	BYTE protocol;
	BYTE command;
	BYTE length;
	BYTE data[32];
} REX2Frame;

typedef struct _REX2UID
{
	BYTE data[10];
	BYTE length;
} REX2UID;

#ifdef __REX2DLL__
#define DLL_EXP __declspec(dllexport)
#else
#define DLL_EXP __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

DLL_EXP BOOL SerialSetProperty(const REX2Reader *obj, const DWORD baudRate, const BYTE parity, const BYTE byteSize, const BYTE stopBits);
//DLL_EXP size_t SerialRead(const REX2Reader *obj, BYTE* buf, const size_t bufSize);
DLL_EXP size_t SerialWrite(const REX2Reader *obj, const BYTE* buf, const size_t bufSize);
DLL_EXP BOOL REX2_IsOpen(const REX2Reader *obj);
DLL_EXP void REX2_SetMsgHwnd(const REX2Reader *obj, const HWND hwnd);
DLL_EXP BOOL REX2_Open(const REX2Reader *obj, const TCHAR *szPort, const int nBaudRate);
DLL_EXP void REX2_Close(const REX2Reader *obj);
DLL_EXP BYTE REX2_Checksum(const BYTE* buf, BYTE length, BOOL bIsSend=FALSE);
DLL_EXP BOOL REX2_IsValidFrame(const BYTE* buf, const BYTE length);
DLL_EXP int REX2_Read(const REX2Reader *obj, REX2Frame* rcvFrames);
DLL_EXP int REX2_Write(const REX2Reader *obj, const REX2Frame* frame);
DLL_EXP int REX2_WriteAndRead(const REX2Reader *obj, const REX2Frame* pSendFrame, REX2Frame* pRecvFrames, BYTE* pRecvFrameCnt);
DLL_EXP int REX2_RegisterWrite(const REX2Reader *obj, const BYTE addr, const BYTE value);
DLL_EXP int REX2_RegisterRead(const REX2Reader *obj, const BYTE addr, BYTE* value);
DLL_EXP int REX2_AllUID_Loop(const REX2Reader *obj);
DLL_EXP int REX2_RegisterISO14443A(const REX2Reader *obj);
DLL_EXP int REX2_ISO14443A_REQA(const REX2Reader *obj,	BYTE* atqa);
DLL_EXP int REX2_ISO14443A_Cascade(const REX2Reader *obj, const BYTE level, REX2UID* uid, BYTE* bcc, BYTE* sak);
DLL_EXP int REX2_ISO14443A_HLTA(const REX2Reader *obj);
DLL_EXP int REX2_ISO14443A_WUPA(const REX2Reader *obj, BYTE* atqa);
DLL_EXP int REX2_ISO14443A_UID(const REX2Reader *obj, REX2UID* uids, BYTE* uidCnt);
DLL_EXP int REX2_ISO14443A_Loop(const REX2Reader *obj);
DLL_EXP int REX2_RegisterISO15693(const REX2Reader *obj);
DLL_EXP int REX2_ISO15693_Inventory(const REX2Reader *obj, REX2UID* uid);
DLL_EXP int REX2_ISO15693_StayQuiet(const REX2Reader *obj);
DLL_EXP int REX2_ISO15693_ResetToReady(const REX2Reader *obj);
DLL_EXP int REX2_ISO15693_ReadSingleBlock(const REX2Reader *obj, const BYTE blockAddr, BYTE* data);
DLL_EXP int REX2_ISO15693_WriteSingleBlock(const REX2Reader *obj, const BYTE blockAddr, const BYTE* data);
DLL_EXP int REX2_ISO15693_ReadMultiBlock(const REX2Reader *obj, const BYTE blockAddr, const BYTE numOfBlock, BYTE* value);
DLL_EXP int REX2_ISO15693_UID(const REX2Reader *obj, REX2UID* uids, BYTE* uidCnt);
DLL_EXP int REX2_ISO15693_Loop(const REX2Reader *obj);
DLL_EXP void REX2_StopLoop(const REX2Reader *obj);

#ifdef __cplusplus
}
#endif

#endif // REX2API_H