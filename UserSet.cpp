// UserSet.h : CUserSet ���ʵ��



// CUserSet ʵ��

// ���������� 2014��7��21��, 9:11

#include "stdafx.h"
#include "UserSet.h"

IMPLEMENT_DYNAMIC(CUserSet, CRecordset)

CUserSet::CUserSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_UserAccount = _T("");
	m_UserPasswd = _T("");
	m_UserType = _T("");
	m_nFields = 3;
	m_nDefaultType = snapshot;
}


CString CUserSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=MyDb");
}

CString CUserSet::GetDefaultSQL()
{
	return _T("[user]");
}

void CUserSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[UserAccount]"), m_UserAccount);
	RFX_Text(pFX, _T("[UserPasswd]"), m_UserPasswd);
	RFX_Text(pFX, _T("[UserType]"), m_UserType);

}
/////////////////////////////////////////////////////////////////////////////
// CUserSet ���

#ifdef _DEBUG
void CUserSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CUserSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


