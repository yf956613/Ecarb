#pragma once
#include "CWndInfo.h"
#include "CWndItemDB.h"
#include "ZSqlite3.h"
class CWndInfoDB
{
private:
	CString m_strPathDB;
	void CreateTable();
	CWndItemDB m_wnditemdb;
public:
	CWndInfoDB();
	virtual ~CWndInfoDB();
	bool Insert(const CWndInfo & wndinfo);
	bool InsertFull(CWndInfo & wndinfo);
	bool Update(const CWndInfo & wndinfo);
	bool UpdateFull(CWndInfo & wndinfo);
	bool Delete(const CWndInfo & wndinfo);
	bool DeleteFull(CWndInfo & wndinfo);
	bool Select(const CString & strSql, std::list<CWndInfo> & list_wndinfo);//strSql��Ϊ��SELECT *ѡ��ȫ���в��ܷ��ض���
	bool SelectFull(const CString & strSql, std::list<CWndInfo> & list_wndinfo);//strSql��Ϊ��SELECT *ѡ��ȫ���в��ܷ��ض���
	static int GetNextInsertID();
};

