// MedicTypeSeekDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicSystem.h"
#include "MedicTypeSeekDlg.h"
#include "Globol.h"

// CMedicTypeSeekDlg �Ի���

IMPLEMENT_DYNAMIC(CMedicTypeSeekDlg, CDialog)

CMedicTypeSeekDlg::CMedicTypeSeekDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMedicTypeSeekDlg::IDD, pParent)
{
	m_strContent = "";
}

CMedicTypeSeekDlg::~CMedicTypeSeekDlg()
{
}

void CMedicTypeSeekDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBString(pDX,IDC_EDIT1,m_strContent);
}


BEGIN_MESSAGE_MAP(CMedicTypeSeekDlg, CDialog)
END_MESSAGE_MAP()


// CMedicTypeSeekDlg ��Ϣ�������

void CMedicTypeSeekDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���


	UpdateData();
	if (m_strContent == "")
	{
		AfxMessageBox(_T("��ѡ��Ҫ���ҵ�ҩƷ����"));
	}
	else
	{
		CMedicSet *pMedicSet = &((CMainFrame *)AfxGetMainWnd())->medicSet;
		CMedic::MedicSearch(pMedicSet,m_strContent,2);
		CDialog::OnOK();
	}
	
}

//BOOL CMedicTypeSeekDlg::OnInitDialog()
//{
//	CDialog::OnInitDialog();
//
//	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
//	CMedicSet *pMedicSet = &((CMainFrame *)AfxGetMainWnd())->medicSet;
//	CComboBox *pCombo = (CComboBox *)GetDlgItem(IDC_EDIT1);
//	pMedicSet->m_strFilter = "";
//	pMedicSet
//	return TRUE;  // return TRUE unless you set the focus to a control
//	// �쳣: OCX ����ҳӦ���� FALSE
//}
