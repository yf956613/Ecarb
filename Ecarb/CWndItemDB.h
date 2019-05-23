#pragma once
#include "CWndItem.h"
#include "ZSqlite3.h"
#include <list>
class CWndItemDB
{
private:
	CString m_strPathDB;
	void CreateTable();
public:
	CWndItemDB();
	virtual ~CWndItemDB();
	bool Insert(const CWndItem & wnditem);
	bool Update(const CWndItem & wnditem);
	bool Delete(const CWndItem & wnditem);
	bool Select(const CString & strSql, std::list<CWndItem> & list_wnditem);//strSql��Ϊ��SELECT *ѡ��ȫ���в��ܷ��ض���
	static int GetNextInsertID();
};

