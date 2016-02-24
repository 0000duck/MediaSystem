// MedicNameSeekDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicSystem.h"
#include "MedicNameSeekDlg.h"
#include "Globol.h"

// CMedicNameSeekDlg �Ի���

IMPLEMENT_DYNAMIC(CMedicNameSeekDlg, CDialog)

CMedicNameSeekDlg::CMedicNameSeekDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMedicNameSeekDlg::IDD, pParent)
{

}

CMedicNameSeekDlg::~CMedicNameSeekDlg()
{
}

void CMedicNameSeekDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX,IDC_EDIT1,m_strContent);
}


BEGIN_MESSAGE_MAP(CMedicNameSeekDlg, CDialog)
END_MESSAGE_MAP()


// CMedicNameSeekDlg ��Ϣ�������

void CMedicNameSeekDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	UpdateData();
	if (m_strContent == "")
	{
		AfxMessageBox(_T("������Ҫ���ҵ�ҩƷ����"));
	}
	else
	{		
		CMedicSet *pMedicSet = &((CMainFrame *)AfxGetMainWnd())->medicSet;
		CMedic::MedicSearch(pMedicSet,m_strContent,1);
		CDialog::OnOK();
	}
}
