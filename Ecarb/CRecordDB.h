#pragma once
#include "CRecord.h"
#include "CRecordItemDB.h"
class CRecordDB
{
private:
	CString m_strPathDB;
	void CreateTable();
	CRecordItemDB m_rditemdb;
public:
	CRecordDB();
	virtual ~CRecordDB();
	bool Insert(const CRecord & record);
	bool InsertFull(CRecord & record);
	bool Update(const CRecord & record);
	bool UpdateFull(CRecord & record);
	bool Delete(const CRecord & record);
	bool DeleteFull(CRecord & record);
	bool Select(const CString & strSql, std::vector<CRecord> & vec_record);//strSql��Ϊ��SELECT *ѡ��ȫ���в��ܷ��ض���
	bool SelectFull(const CString & strSql, std::vector<CRecord> & vec_record);//strSql��Ϊ��SELECT *ѡ��ȫ���в��ܷ��ض���
	static int GetNextInsertID();
};

