// ModifyPasswdDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicSystem.h"
#include "ModifyPasswdDlg.h"
#include "MainFrm.h"

// CModifyPasswdDlg �Ի���

IMPLEMENT_DYNAMIC(CModifyPasswdDlg, CDialog)

CModifyPasswdDlg::CModifyPasswdDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CModifyPasswdDlg::IDD, pParent)
{

}

CModifyPasswdDlg::~CModifyPasswdDlg()
{
}

void CModifyPasswdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX,IDC_EDIT1,m_strAccount);
	DDX_Text(pDX,IDC_EDIT2,m_strOldPasswd);
	DDX_Text(pDX,IDC_EDIT3,m_strPasswd);
	DDX_Text(pDX,IDC_EDIT4,m_strPasswd1);
}


BEGIN_MESSAGE_MAP(CModifyPasswdDlg, CDialog)
END_MESSAGE_MAP()


// CModifyPasswdDlg ��Ϣ�������

void CModifyPasswdDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	UpdateData();
	CMainFrame *pMainFrm = (CMainFrame *)AfxGetMainWnd();
	
	CUser* theUser = &pMainFrm->user;
	CUserSet* theUserSet = &pMainFrm->userSet;
	CString strSQL;
	strSQL.Format(_T("UserAccount=\'%s\'"),theUser->GetAccount());
	theUserSet->m_strFilter = strSQL;
	theUserSet->Requery();
	if(m_strOldPasswd==theUser->GetPasswd())
	{
		if((m_strPasswd==m_strPasswd1)&&(m_strPasswd != ""))
		{

			theUser->SetPasswd(m_strPasswd);
			theUser->ModifyPasswd(theUserSet);
			AfxMessageBox(_T("�޸�����ɹ�"));
			CDialog::OnOK();
		}
		else if(m_strPasswd == _T(""))
		{
			AfxMessageBox(_T("�����벻��Ϊ�գ�������"));
		}
		else
		{
			AfxMessageBox(_T("������������벻ƥ��"));
			m_strPasswd = _T("");
			m_strPasswd1 = _T("");
			UpdateData(FALSE);
		}
	}
	else
	{
		AfxMessageBox(_T("����ľ����벻��ȷ"));
		m_strOldPasswd = _T("");
		m_strPasswd = _T("");
		m_strPasswd1 = _T("");
		UpdateData(FALSE);
	}
}
