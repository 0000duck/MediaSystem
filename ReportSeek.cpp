// ReportSeek.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicSystem.h"
#include "ReportSeek.h"
#include "Globol.h"

// CReportSeek �Ի���

IMPLEMENT_DYNAMIC(CReportSeekDlg, CDialog)

CReportSeekDlg::CReportSeekDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReportSeekDlg::IDD, pParent)
{

}

CReportSeekDlg::~CReportSeekDlg()
{
}

void CReportSeekDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Text(pDX,IDC_EDIT_FILTER,m_strFilter);
	DDX_Control(pDX,IDC_EDIT_FILTER,m_wndFilterEditCtrl);
}


BEGIN_MESSAGE_MAP(CReportSeekDlg, CDialog)
END_MESSAGE_MAP()


// CReportSeek ��Ϣ�������

//void CReportSeekDlg::OnOK()
//{
//	// TODO: �ڴ����ר�ô����/����û���
//	UpdateData(TRUE);
//	CMainFrame *pMainFrm = (CMainFrame *)AfxGetMainWnd();
//	pMainFrm->m_wndReportCtrl->SetFilterText(m_strFilter);
//	pMainFrm->m_wndReportCtrl->Populate();
//	pMainFrm->m_wndReportCtrl->SetFilterText("");
//	//CDialog::OnOK();
//}

void CReportSeekDlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���
	CWnd::DestroyWindow();
	CMainFrame *pMainFrm = (CMainFrame *)AfxGetMainWnd();
	pMainFrm->m_wndReportCtrl->SetFilterText("");
	pMainFrm->pSeek = NULL;
}

BOOL CReportSeekDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CMainFrame *pMainFrm = (CMainFrame *)AfxGetMainWnd();
	CXTPReportControl *pReportCtrl = pMainFrm->m_wndReportCtrl;
	pReportCtrl->GetReportHeader()->SetFilterEditCtrl(&m_wndFilterEditCtrl);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
