// MedicIDSeekDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicSystem.h"
#include "MedicIDSeekDlg.h"
#include "Globol.h"

// CMedicIDSeekDlg �Ի���

IMPLEMENT_DYNAMIC(CMedicIDSeekDlg, CDialog)

CMedicIDSeekDlg::CMedicIDSeekDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMedicIDSeekDlg::IDD, pParent)
{

}

CMedicIDSeekDlg::~CMedicIDSeekDlg()
{
}

void CMedicIDSeekDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX,IDC_EDIT1,m_strContent);
}


BEGIN_MESSAGE_MAP(CMedicIDSeekDlg, CDialog)
END_MESSAGE_MAP()


// CMedicIDSeekDlg ��Ϣ�������

void CMedicIDSeekDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	
	UpdateData();
	if (m_strContent == "")
	{
		AfxMessageBox("������Ҫ���ҵ�ҩƷ���");
	}
	else
	{
		CMedicSet *pMedicSet = &((CMainFrame *)AfxGetMainWnd())->medicSet;
		CMedic::MedicSearch(pMedicSet,m_strContent,0);
		CDialog::OnOK();
	}
	
}
