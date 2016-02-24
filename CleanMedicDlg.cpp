// CleanMedicDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicSystem.h"
#include "CleanMedicDlg.h"
#include "Globol.h"

// CCleanMedicDlg �Ի���

IMPLEMENT_DYNAMIC(CCleanMedicDlg, CDialog)

CCleanMedicDlg::CCleanMedicDlg(CWnd* pParent /*=NULL*/)
: CDialog(CCleanMedicDlg::IDD, pParent),m_nCleanType(-1),m_bFlag(FALSE)
{

}

CCleanMedicDlg::~CCleanMedicDlg()
{
}

void CCleanMedicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_LIST1,m_ListCtrl);
	DDX_Radio(pDX,IDC_RADIO_ZERO,m_nCleanType);
}


BEGIN_MESSAGE_MAP(CCleanMedicDlg, CDialog)
	ON_BN_CLICKED(IDC_RADIO_ZERO, &CCleanMedicDlg::OnBnClickedRadioZero)
	ON_BN_CLICKED(IDC_RADIO_OUTDATE, &CCleanMedicDlg::OnBnClickedRadioOutdate)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CCleanMedicDlg ��Ϣ�������

BOOL CCleanMedicDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CMedicManage manageMedic;
	CString header[]={"ҩƷ���","ҩƷ����","�������","�Ƿ����"};
	for(int i=0;i<4;i++)
	{
		m_ListCtrl.InsertColumn(i,header[i],LVCFMT_LEFT,90);
	}
	CMainFrame* pMainFrm = (CMainFrame*)AfxGetMainWnd();
	pMedicSet = &pMainFrm->medicSet;
	pMedicSet->m_strFilter = _T("");
	pMedicSet->Requery();
	for(int i = 0;;i++)
	{
		if(pMedicSet->IsEOF())
		{
			break;
		}
		m_ListCtrl.InsertItem(i,pMedicSet->m_MedicID);
		m_ListCtrl.SetItemText(i,1,pMedicSet->m_MedicName);
		CString str;
		str.Format("%d",pMedicSet->m_MedicNumber);
		m_ListCtrl.SetItemText(i,2,str);
		manageMedic.SetMedicSet(pMedicSet);
		CTime timeAfter=manageMedic.GetOutDateTime();
		CTime timeNow=CTime::GetCurrentTime();
		CString strfool;
		if(timeAfter>timeNow)
		{
			strfool="��";
		}
		else
		{
			strfool="��";
		}
		m_ListCtrl.SetItemText(i,3,strfool);
		pMedicSet->MoveNext();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CCleanMedicDlg::OnBnClickedRadioZero()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	pMedicSet->m_strFilter = _T("MedicNumber=0");
	pMedicSet->Requery();
	CMedicManage manageMedic;
	m_ListCtrl.DeleteAllItems();
	for(int i = 0;;i++)
	{
		if(pMedicSet->IsEOF())
		{
			break;
		}
		m_ListCtrl.InsertItem(i,pMedicSet->m_MedicID);
		m_ListCtrl.SetItemText(i,1,pMedicSet->m_MedicName);
		CString str;
		str.Format("%d",pMedicSet->m_MedicNumber);
		m_ListCtrl.SetItemText(i,2,str);
		manageMedic.SetMedicSet(pMedicSet);
		CTime timeAfter=manageMedic.GetOutDateTime();
		CTime timeNow=CTime::GetCurrentTime();
		CString strFlag;
		if(timeAfter > timeNow)
		{
			strFlag="��";
		}
		else
		{
			strFlag="��";
		}
		m_ListCtrl.SetItemText(i,3,strFlag);
		pMedicSet->MoveNext();
	}
}

void CCleanMedicDlg::OnBnClickedRadioOutdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMedicManage manageMedic;
	pMedicSet->m_strFilter = "";
	pMedicSet->Requery();
	m_ListCtrl.DeleteAllItems();
	for(int i=0;;i++)
	{
		if(pMedicSet->IsEOF())
		{
			break;
		}
		manageMedic.SetMedicSet(pMedicSet);
		CTime OutTime = manageMedic.GetOutDateTime();
		CTime CurTime = CTime::GetCurrentTime();
		if(OutTime < CurTime)
		{
			m_ListCtrl.InsertItem(i,pMedicSet->m_MedicID);
			m_ListCtrl.SetItemText(i,1,pMedicSet->m_MedicName);
			CString str;
			str.Format("%d",pMedicSet->m_MedicNumber);
			m_ListCtrl.SetItemText(i,2,str);
			m_ListCtrl.SetItemText(i,3,"��");
		}
		else
		{
			i=i-1;
		}
		pMedicSet->MoveNext();
	}
}


void CCleanMedicDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	UpdateData();
	if (m_nCleanType == -1)
	{
		AfxMessageBox("��ѡ��Ҫ���������");
		return;
	}
	CMedicManage manageMedic;
	manageMedic.SetMedicSet(pMedicSet);
	if(m_nCleanType == 0)
	{
		if(manageMedic.DelMedicZeroNumber())
		{
			m_bFlag = TRUE;
			AfxMessageBox("����Ϊ0��ҩƷ�������");
		}
		else
			AfxMessageBox("����Ϊ0��ҩƷ������");
	}
	else
	{
		if(manageMedic.DelMedicOutDate())
		{
			m_bFlag = TRUE;
			AfxMessageBox("���ڵ�ҩƷ�������");
		}
		else
			AfxMessageBox("���޹��ڵ�ҩƷ������");	
	}
	
	pMedicSet->m_strFilter = "";
	pMedicSet->Requery();
	m_ListCtrl.DeleteAllItems();
	for(int i=0;;i++)
	{
		if(pMedicSet->IsEOF())
		{
			break;
		}
		m_ListCtrl.InsertItem(i,pMedicSet->m_MedicID);
		m_ListCtrl.SetItemText(i,1,pMedicSet->m_MedicName);
		CString str;
		str.Format("%d",pMedicSet->m_MedicNumber);
		m_ListCtrl.SetItemText(i,2,str);
		manageMedic.SetMedicSet(pMedicSet);
		CTime timeAfter=manageMedic.GetOutDateTime();
		CTime timeNow=CTime::GetCurrentTime();
		CString strFlag;
		if(timeAfter > timeNow)
		{
			strFlag="��";
		}
		else
		{
			strFlag="��";
		}
		m_ListCtrl.SetItemText(i,3,strFlag);
		pMedicSet->MoveNext();
	}

	m_nCleanType = -1;
	UpdateData(FALSE);
}


void CCleanMedicDlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���
	if (!m_bFlag)
	{
		CDialog::OnCancel();
		return;
	}
	
	CMainFrame *pMainFrm = (CMainFrame *)AfxGetMainWnd();
	CMedicSet *pMedicSet = &pMainFrm->medicSet;
	pMedicSet->m_strFilter = "";
	pMedicSet->Requery();

	CMedic::RefreshReport(pMedicSet);

	CDialog::OnCancel();
}


void CCleanMedicDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CCleanMedicDlg::OnCancel();
}
