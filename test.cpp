// test.h : CTestuser ���ʵ��



// CTestuser ʵ��

// ���������� 2014��8��4��, 14:53

#include "stdafx.h"
#include "test.h"
IMPLEMENT_DYNAMIC(CTestuser, CRecordset)

CTestuser::CTestuser(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_UserAccount = L"";
	m_UserPasswd = L"";
	m_UserType = L"";
	m_nFields = 3;
	m_nDefaultType = snapshot;
}

CString CTestuser::GetDefaultConnect()
{
	return _T("DSN=MyDb;DBQ=C:\\USERS\\ADMINISTRATOR\\DESKTOP\\MedicSystem\\db\\mydb.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CTestuser::GetDefaultSQL()
{
	return _T("[user]");
}

void CTestuser::DoFieldExchange(CFieldExchange* pFX)
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
// CTestuser ���

#ifdef _DEBUG
void CTestuser::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTestuser::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


