#pragma once
#include "CPage.h"
#include "CWndInfoDB.h"
#include "ZSqlite3.h"
class CPageDB
{
private:
	CString m_strPathDB;
	void CreateTable();
	CWndInfoDB m_wndinfodb;
public:
	CPageDB();
	virtual ~CPageDB();
	bool Insert(const CPage & page);
	bool InsertFull(CPage & page);
	bool Update(const CPage & page);
	bool UpdateFull(CPage & page);
	bool Delete(const CPage & page);
	bool DeleteFull(CPage & page);
	bool Select(const CString & strSql, std::list<CPage> & list_page);//strSql��Ϊ��SELECT *ѡ��ȫ���в��ܷ��ض���
	bool SelectFull(const CString & strSql, std::list<CPage> & list_page);//strSql��Ϊ��SELECT *ѡ��ȫ���в��ܷ��ض���
	static int GetNextInsertID();
};

