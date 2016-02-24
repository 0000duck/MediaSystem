// ReportField.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicSystem.h"
#include "ReportField.h"
#include "Globol.h"

// CReportField �Ի���

IMPLEMENT_DYNAMIC(CReportField, CDialog)

CReportField::CReportField(CWnd* pParent /*=NULL*/)
	: CDialog(CReportField::IDD, pParent)
{

}

CReportField::~CReportField()
{
}

void CReportField::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_LIST1,m_wndReportSubList);
}


BEGIN_MESSAGE_MAP(CReportField, CDialog)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CReportField ��Ϣ�������

BOOL CReportField::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CMainFrame *pMainFrm = (CMainFrame *)AfxGetMainWnd();
	CXTPReportControl *pReportCtrl = pMainFrm->m_wndReportCtrl;
	pReportCtrl->GetReportHeader()->SetSubListCtrl(&m_wndReportSubList);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CReportField::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	this->ShowWindow(SW_HIDE);
	//CDialog::OnClose();
}
