// MedicSet.h : CMedicSet ������

#pragma once

// ���������� 2014��7��22��, 16:51

class CMedicSet : public CRecordset
{
public:
	CMedicSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMedicSet)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	CString	m_MedicID;
	CString	m_MedicName;
	CString	m_MedicType;
	CTime	m_ProduceDate;
	int	m_MedicNumber;
	float	m_MedicPrice;
	int	m_GuarantPeriod;
	CString	m_ProduceCompany;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


