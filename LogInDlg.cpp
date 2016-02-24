// LogInDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicSystem.h"
#include "LogInDlg.h"
#include "MainFrm.h"

// CLogInDlg �Ի���

IMPLEMENT_DYNAMIC(CLogInDlg, CDialog)

CLogInDlg::CLogInDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLogInDlg::IDD, pParent)
{
	m_userAccount = _T("admin");
	m_userPasswd = _T("admin");
	m_userType = _T("����Ա");
	m_PreUserAccount = _T("");
}

CLogInDlg::~CLogInDlg()
{
}

void CLogInDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX,IDC_EDIT_ACCOUNT,m_userAccount);
	DDX_Text(pDX,IDC_EDIT_PASSWD,m_userPasswd);
	DDX_CBString(pDX,IDC_COMBO_TYPE,m_userType);
}


BEGIN_MESSAGE_MAP(CLogInDlg, CDialog)
	ON_EN_KILLFOCUS(IDC_EDIT_ACCOUNT, &CLogInDlg::OnEnKillfocusEditAccount)
END_MESSAGE_MAP()


// CLogInDlg ��Ϣ�������

BOOL CLogInDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ

	::SetWindowPos(this->m_hWnd,HWND_BOTTOM,0,0,460,300,SWP_NOZORDER);//���öԻ����С��λ��
	CenterWindow();

	AnimateWindow(500,AW_VER_POSITIVE | AW_HOR_POSITIVE);
	/*HINSTANCE instance = LoadLibrary(_T("User32.DLL");
	typedef BOOL(WINAPI myFun(HWND,DWORD,WORD));
	myFun *Animate;
	Animate = (myFun *)::GetProcAddress(instance,_T("AnimateWindow");
	Animate(this->m_hWnd,2000,AW_CENTER);
	FreeLibrary(instance);*/

	//CButton *pLogIn = (CButton *)GetDlgItem(IDOK);
	//m_btnOK.SetBitmap(CSize(20,20),IDB_HEAD);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CLogInDlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���
	ExitProcess(1);
}

void CLogInDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	
	UpdateData(TRUE);//���¿ؼ�������ݵ���Ա������
	CMainFrame *pMainWnd = (CMainFrame *)AfxGetMainWnd();
	CUser *pUser = &pMainWnd->user;
	pUser->SetAllMembers(m_userAccount,m_userPasswd,m_userType);
	CUserSet *pUserSet = &pMainWnd->userSet;
	BOOL flag = pUser->LogIn(pUserSet);
	if (flag)
	{
		CDialog::OnOK();
	}
	else
	{
		AfxMessageBox(_T("��¼��Ϣ��������������"));
		m_userAccount = _T("");
		m_userPasswd = _T("");
		UpdateData(FALSE);//���³�Ա���������ݵ��ؼ���
		
 	    (CEdit *)GetDlgItem(IDC_EDIT_ACCOUNT)->SetFocus();
	}
}

void CLogInDlg::OnEnKillfocusEditAccount()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (GetFocus() == GetDlgItem(IDCANCEL) || m_PreUserAccount == m_userAccount
		 || "" == m_userAccount )
	{
		return;
	}
	CMainFrame *pMainWnd = (CMainFrame *)AfxGetMainWnd();
	CUserSet *pUserSet = &pMainWnd->userSet;
	pUserSet->m_strFilter = "UserAccount='"+m_userAccount+"'";
	pUserSet->Requery();
	if (!pUserSet->GetRecordCount())
	{
		AfxMessageBox("��Ч���û�����");
		(CEdit *)GetDlgItem(IDC_EDIT_ACCOUNT)->SetFocus();
		m_PreUserAccount = m_userAccount;
	}
}
