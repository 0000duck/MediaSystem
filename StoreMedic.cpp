// StoreMedic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicSystem.h"
#include "StoreMedic.h"
#include "Globol.h"

// CStoreMedic �Ի���

IMPLEMENT_DYNAMIC(CStoreMedicDlg, CDialog)

CStoreMedicDlg::CStoreMedicDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStoreMedicDlg::IDD, pParent),m_bFlag(FALSE),m_bNumber(FALSE)
{
	
}

CStoreMedicDlg::~CStoreMedicDlg()
{
}

void CStoreMedicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_EDIT_DATE,m_wndDateTime);
	DDX_Text(pDX,IDC_EDIT_ID,m_strMedicID);
	DDX_Text(pDX,IDC_EDIT_NAME,m_strMedicName);
	DDX_CBString(pDX,IDC_EDIT_TYPE,m_strMedicType);
	DDX_Text(pDX,IDC_EDIT_NUMBER,m_strMedicNumber);
	DDX_Text(pDX,IDC_EDIT_KEEP,m_strGuarantPeriod);
	DDX_Text(pDX,IDC_EDIT_PRICE,m_strMedicPrice);
	DDX_Text(pDX,IDC_EDIT_COMPANY,m_strProduceCompany);

}


BEGIN_MESSAGE_MAP(CStoreMedicDlg, CDialog)
	ON_EN_KILLFOCUS(IDC_EDIT_ID, &CStoreMedicDlg::OnEnKillfocusEditId)
	ON_EN_KILLFOCUS(IDC_EDIT_NAME, &CStoreMedicDlg::OnEnKillfocusEditName)
END_MESSAGE_MAP()


// CStoreMedic ��Ϣ�������

BOOL CStoreMedicDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	COleDateTime OleTiem;
	OleTiem.SetDate(2010,1,1);
	m_wndDateTime.SetTime(OleTiem);


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CStoreMedicDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	CMedicManage manageMedic;
	CMedic medic;
	CMainFrame *pMain = (CMainFrame *)AfxGetMainWnd();
	CMedicSet *pMedicSet = &pMain->medicSet;
	manageMedic.SetMedicSet(pMedicSet);
	manageMedic.SetMedic(&medic);

	UpdateData();

	if (m_bNumber)//ֻ��Ӵ���ҩƷ������
	{
		medic.m_strMedicNumber = _ttoi(m_strMedicNumber);
		if(manageMedic.Storage(m_bNumber))
		{
			AfxMessageBox("ҩƷ��ӳɹ�");
			m_bFlag = TRUE;
		}
	}
	else//����µ�ҩƷ
	{
		if(m_strMedicName=="")
		{
			AfxMessageBox("������ҩƷ����");
			return;
		}
		if(m_strMedicType=="")
		{
			AfxMessageBox("��ѡ��ҩƷ���");
			return;
		}
		if (m_strMedicNumber == "")
		{
			AfxMessageBox("������ҩƷ����");
			return;
		}
		if (m_strMedicPrice == "")
		{
			AfxMessageBox("������ҩƷ����");
			return;
		}
		if (m_strGuarantPeriod == "")
		{
			AfxMessageBox("������ҩƷ������");
			return;
		}

		medic.m_strMedicID = m_strMedicID;
		medic.m_strMedicName = m_strMedicName;
		medic.m_strMedicType = m_strMedicType;
		medic.m_strMedicNumber = _ttoi(m_strMedicNumber);
		medic.m_strMedicPrice = _tstof(m_strMedicPrice);
		medic.m_strGuarantPeriod = _ttoi(m_strGuarantPeriod);
		medic.m_ProduceCompany = m_strProduceCompany;

		CTime produceTime;
		m_wndDateTime.GetTime(produceTime);
		medic.m_strProduceDate = produceTime;
		if (manageMedic.Storage(m_bNumber))
		{
			AfxMessageBox("ҩƷ��ӳɹ�");
			m_bFlag = TRUE;
		}
	}
	
	if (m_bNumber)
	{
		((CEdit *)GetDlgItem(IDC_EDIT_NAME))->EnableWindow(TRUE);
		((CEdit *)GetDlgItem(IDC_EDIT_TYPE))->EnableWindow(TRUE);
		((CEdit *)GetDlgItem(IDC_EDIT_KEEP))->EnableWindow(TRUE);
		((CEdit *)GetDlgItem(IDC_EDIT_PRICE))->EnableWindow(TRUE);
		((CEdit *)GetDlgItem(IDC_EDIT_COMPANY))->EnableWindow(TRUE);
		((CDateTimeCtrl *)GetDlgItem(IDC_EDIT_DATE))->EnableWindow(TRUE);
		m_bNumber = FALSE;
	}

	m_strMedicID = "";
	m_strMedicName = "";
	m_strMedicNumber = "";
	m_strMedicPrice = "";
	m_strGuarantPeriod = "";
	m_strProduceCompany = "";
	((CEdit *)GetDlgItem(IDC_EDIT_NAME))->SetFocus();

	UpdateData(FALSE);
}


void CStoreMedicDlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���
	if (!m_bFlag)
	{
		CDialog::OnCancel();
		return;
	}
	
	CMainFrame *pMain = (CMainFrame *)AfxGetMainWnd();
	CMedicSet *pMedicSet = &pMain->medicSet;
	pMedicSet->m_strFilter = _T("");
	pMedicSet->Requery();

	CMedic::RefreshReport(pMedicSet);

	CDialog::OnCancel();
}


void CStoreMedicDlg::OnEnKillfocusEditId()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	CMainFrame *pMain = (CMainFrame *)AfxGetMainWnd();
	CMedicSet *pMedicSet = &pMain->medicSet;
	pMedicSet->m_strFilter="MedicID='"+m_strMedicID+"'";
	pMedicSet->Requery();
	if (pMedicSet->GetRecordCount())
	{
		BOOL Ret = AfxMessageBox("�ñ�ŵ�ҩƷ�Ѵ��ڣ��Ƿ�����������",MB_OKCANCEL);
		if (Ret == IDCANCEL)
		{
			m_strMedicID = "";
			UpdateData(FALSE);
		}
		else
		{
			((CEdit *)GetDlgItem(IDC_EDIT_NAME))->EnableWindow(FALSE);
			((CEdit *)GetDlgItem(IDC_EDIT_TYPE))->EnableWindow(FALSE);
			((CEdit *)GetDlgItem(IDC_EDIT_KEEP))->EnableWindow(FALSE);
			((CEdit *)GetDlgItem(IDC_EDIT_PRICE))->EnableWindow(FALSE);
			((CEdit *)GetDlgItem(IDC_EDIT_COMPANY))->EnableWindow(FALSE);
			((CDateTimeCtrl *)GetDlgItem(IDC_EDIT_DATE))->EnableWindow(FALSE);
			m_bNumber = TRUE;
		}		
	}

}

void CStoreMedicDlg::OnEnKillfocusEditName()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	CMainFrame *pMain = (CMainFrame *)AfxGetMainWnd();
	CMedicSet *pMedicSet = &pMain->medicSet;
	pMedicSet->m_strFilter="MedicName='"+m_strMedicName+"'";
	pMedicSet->Requery();
	if (pMedicSet->GetRecordCount())
	{
		AfxMessageBox("ҩƷ�����Ѵ��ڣ�����������");
		m_strMedicName = "";
		UpdateData(FALSE);

		CEdit *pName = (CEdit *)GetDlgItem(IDC_EDIT_NAME);
		pName->SetFocus();
	}

}
