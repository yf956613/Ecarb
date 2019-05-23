/*
** Version  1.0.0.9
** Date     2019.05.16
** Author   zax
** Copyright (C) Since 2009 Zaxai.Com All Rights Reserved
*/
#pragma once
class ZSerialPort
{
private:
	HANDLE m_hCom;
	OVERLAPPED m_olSend;
	OVERLAPPED m_olRecv;
	ZSerialPort(const ZSerialPort & zsp) = delete;
	ZSerialPort & operator = (const ZSerialPort & zsp) = delete;
public:
	enum ERRORINFO
	{
		ERROR_OK = 0,//�ɹ�
		ERROR_INVALIDPORT,//��Ч�˿�
		ERROR_PORTSTATE,//�����˿�DCB����
		ERROR_BUFFERSIZE,//��������������
		ERROR_TIMEOUTS,//������ʱ����
		ERROR_PURGE,//��ջ���������
		ERROR_SEND,//���ͳ���
		ERROR_RECV,//���ճ���
		ERROR_OTHER,//��������
		ERROR_BUFFERSTATE,//�鿴������״̬����
		ERROR_SEND_TIMEOUT,//���ͳ�ʱ
		ERROR_SEND_STOP,//����ֹͣ
		ERROR_RECV_TIMEOUT,//���ճ�ʱ
		ERROR_RECV_STOP//����ֹͣ
	};
	ZSerialPort(void);
	ZSerialPort(ZSerialPort && zsp);
	ZSerialPort & operator=(ZSerialPort && zsp);
	virtual ~ZSerialPort(void);
	virtual bool OpenPort(CString strPort);//ʹ���첽����
	virtual void ClosePort(void);
	int GetPortState(DCB & dcb);
	int SetPortState(DCB & dcb);
	int SetPortState( DWORD dwBaudRate, BYTE cParity, BYTE cByteSize, BYTE cStopBits);
	int SetPortState(const CString & strBaudRate,const CString & strParity,const CString & strByteSize,const CString & strStopBits);
	int SetBufferSize( DWORD dwInBuffer,  DWORD dwOutBuffer);
	int GetPortTimeOut(COMMTIMEOUTS  & timeout);
	int SetPortTimeOut(COMMTIMEOUTS  & timeout);
	int SetPortTimeOut( DWORD dwReadIntTmout, DWORD dwReadTolTmoutMul, DWORD dwReadTolTmoutCst, DWORD dwWriteTolTmoutMul, DWORD dwWriteTolTmoutCst);
	int SetPortTimeOut(const CString & strReadIntTmout,const CString & strReadTolTmoutMul,const CString & strReadTolTmoutCst,const CString & strWriteTolTmoutMul,const CString & strWriteTolTmoutCst);
	int PurgePort(void);
	int SendToPort(const BYTE * p_cSendData,DWORD dwSendLen,DWORD * p_dwActSendLen=nullptr);
	int SendToPort( CString strSendData);
	bool CStringToByteArrBy2(const CString & str,BYTE * p_cArray,int nMaxOutBuffer);
	int RecvFromPort(BYTE * p_cRecvData,int nMaxOutBuffer,DWORD * p_dwActRecvLen = nullptr);
	int RecvFromPort(CString & strRecvData,int nMaxOutBuffer);
	void ByteArrToCStringAsHex(const BYTE * p_cArray,DWORD dwArrayLen,CString & str);
	int ClearPortError(DWORD & dwInQue,DWORD & dwOutQue, DWORD & dwErrors);
	DWORD GetErrorInfo(void);
};

