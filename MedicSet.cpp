// MedicSet.h : CMedicSet ���ʵ��



// CMedicSet ʵ��

// ���������� 2014��7��22��, 16:51

#include "stdafx.h"
#include "MedicSet.h"
IMPLEMENT_DYNAMIC(CMedicSet, CRecordset)

CMedicSet::CMedicSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_MedicID = _T("");
	m_MedicName = _T("");
	m_MedicType = _T("");
	m_ProduceDate;
	m_MedicNumber = 0;
	m_MedicPrice = 0.0;
	m_GuarantPeriod = 0;
	m_ProduceCompany = _T("");
	m_nFields = 8;
	m_nDefaultType = snapshot;
}

CString CMedicSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=MyDb");
}

CString CMedicSet::GetDefaultSQL()
{
	return _T("[medicine]");
}

void CMedicSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[MedicID]"), m_MedicID);
	RFX_Text(pFX, _T("[MedicName]"), m_MedicName);
	RFX_Text(pFX, _T("[MedicType]"), m_MedicType);
	RFX_Date(pFX, _T("[ProduceDate]"), m_ProduceDate);
	RFX_Int(pFX, _T("[MedicNumber]"), m_MedicNumber);
	RFX_Single(pFX, _T("[MedicPrice]"), m_MedicPrice);
	RFX_Int(pFX, _T("[GuarantPeriod]"), m_GuarantPeriod);
	RFX_Text(pFX, _T("[ProduceCompany]"), m_ProduceCompany);

}
/////////////////////////////////////////////////////////////////////////////
// CMedicSet ���

#ifdef _DEBUG
void CMedicSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMedicSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


