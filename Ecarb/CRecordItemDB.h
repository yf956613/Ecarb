#pragma once
#include "CRecordItem.h"
#include "CRecordDataDB.h"
class CRecordItemDB
{
private:
	CString m_strPathDB;
	void CreateTable();
	CRecordDataDB m_rddatadb;
public:
	CRecordItemDB();
	virtual ~CRecordItemDB();
	bool Insert(const CRecordItem & rditem);
	bool InsertFull(CRecordItem & rditem);
	bool Update(const CRecordItem & rditem);
	bool UpdateFull(CRecordItem & rditem);
	bool Delete(const CRecordItem & rditem);
	bool DeleteFull(CRecordItem & rditem);
	bool Select(const CString & strSql, std::vector<CRecordItem> & vec_rditem);//strSql��Ϊ��SELECT *ѡ��ȫ���в��ܷ��ض���
	bool SelectFull(const CString & strSql, std::vector<CRecordItem> & vec_rditem);//strSql��Ϊ��SELECT *ѡ��ȫ���в��ܷ��ض���
	static int GetNextInsertID();
};

