// SeekUser.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicSystem.h"
#include "SeekUser.h"

// CSeekUser �Ի���

IMPLEMENT_DYNAMIC(CSeekUserDlg, CDialog)

CSeekUserDlg::CSeekUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSeekUserDlg::IDD, pParent)
{
	m_strAccount = _T("");
	m_strUsertype = _T("");
	m_ntypeRadio = -1;
}

CSeekUserDlg::~CSeekUserDlg()
{
}

void CSeekUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_SEEK_LIST,m_UserList);
	DDX_Text(pDX,IDC_SEEK_EDIT,m_strAccount);
	DDX_CBString(pDX,IDC_SEEK_COMBO,m_strUsertype);
	DDX_Radio(pDX,IDC_SEEK_RADIO1,m_ntypeRadio);
}


BEGIN_MESSAGE_MAP(CSeekUserDlg, CDialog)
END_MESSAGE_MAP()


// CSeekUser ��Ϣ�������

BOOL CSeekUserDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_ntypeRadio=0;
	UpdateData(FALSE);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CMainFrame *pMainFrm = (CMainFrame *)AfxGetMainWnd();
	pUserSet = &pMainFrm->userSet;
	pUserSet->m_strFilter="";
	pUserSet->Requery();

	CString userColumn[]={_T("ID"),_T("�û��˺�"),_T("�û�����"),_T("�û���ɫ")};
	for(int i=0;i<4;i++)
	{
		m_UserList.InsertColumn(i,userColumn[i],LVCFMT_LEFT,102,i);
	}

	//CString ID;
	//for(int j=0;;j++)
	//{
	//	if(pUserSet->IsEOF())
	//	{
	//		break;
	//	}
	//	ID.Format(_T("%d"),j+1);
	//	m_UserList.InsertItem(j,ID);
	//	m_UserList.SetItemText(j,1,pUserSet->m_UserAccount);
	//	m_UserList.SetItemText(j,2,pUserSet->m_UserPasswd);
	//	m_UserList.SetItemText(j,3,pUserSet->m_UserType);
	//	pUserSet->MoveNext();
	//}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CSeekUserDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	UpdateData(TRUE);
	CMainFrame *pMainFrm = (CMainFrame *)AfxGetMainWnd();
	CUser* theUser=&pMainFrm->user;

	CString str;
	if(m_ntypeRadio==0)
	{
		str = m_strUsertype;
	}
	else
	{
		str=m_strAccount;
	}

	if(!theUser->SeekUserInfo(m_ntypeRadio,str,pUserSet))
		return;
	
	m_UserList.DeleteAllItems();

	CString ID;
	for(int j=0;;j++)
	{
		if(pUserSet->IsEOF())
		{
			break;
		}
		ID.Format(_T("%d"),j+1);
		m_UserList.InsertItem(j,ID);
		m_UserList.SetItemText(j,1,pUserSet->m_UserAccount);
		m_UserList.SetItemText(j,2,"******");
		m_UserList.SetItemText(j,3,pUserSet->m_UserType);
		pUserSet->MoveNext();
	}
	//CDialog::OnOK();
}
