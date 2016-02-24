// SaleSet.h : CSaleSet ���ʵ��



// CSaleSet ʵ��

// ���������� 2014��8��13��, 16:43

#include "stdafx.h"
#include "SaleSet.h"
IMPLEMENT_DYNAMIC(CSaleSet, CRecordset)

CSaleSet::CSaleSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_MedicID = L"";
	m_MedicName = L"";
	m_MedicPrice = 0.0;
	m_MedicNumber = 0;
	m_TotalMoney = 0.0;
	m_nFields = 5;
	m_nDefaultType = snapshot;
}

CString CSaleSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=MyDb");
}

CString CSaleSet::GetDefaultSQL()
{
	return _T("[saleTable]");
}

void CSaleSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[MedicID]"), m_MedicID);
	RFX_Text(pFX, _T("[MedicName]"), m_MedicName);
	RFX_Single(pFX, _T("[MedicPrice]"), m_MedicPrice);
	RFX_Int(pFX, _T("[MedicNumber]"), m_MedicNumber);
	RFX_Single(pFX, _T("[TotalMoney]"), m_TotalMoney);

}
/////////////////////////////////////////////////////////////////////////////
// CSaleSet ���

#ifdef _DEBUG
void CSaleSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSaleSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


