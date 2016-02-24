// ChangeUserDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicSystem.h"
#include "ChangeUserDlg.h"


// CChangeUserDlg �Ի���

IMPLEMENT_DYNAMIC(CChangeUserDlg, CDialog)

CChangeUserDlg::CChangeUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChangeUserDlg::IDD, pParent)
{
	m_strUserAccount = _T("");
	m_strPasswd = _T("");
	m_strUserType = _T("");
}

CChangeUserDlg::~CChangeUserDlg()
{
}

void CChangeUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX,IDC_EDIT_ACCOUNT,m_strUserAccount);
	DDX_Text(pDX,IDC_EDIT_PASSWD,m_strPasswd);
	DDX_CBString(pDX,IDC_COMBO_TYPE,m_strUserType);
}


BEGIN_MESSAGE_MAP(CChangeUserDlg, CDialog)
END_MESSAGE_MAP()


// CChangeUserDlg ��Ϣ�������


void CChangeUserDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	UpdateData();

	CMainFrame *pMainFrm = (CMainFrame *)AfxGetMainWnd();
	CUser* pUser = &pMainFrm->user;
	CUserSet* pUserSet = &pMainFrm->userSet;

	pUserSet->m_strFilter = "UserAccount='"+m_strUserAccount+"' and UserPasswd='"
		+m_strPasswd+"' and UserType='"+m_strUserType+"'";
	pUserSet->Requery();

	if(pUserSet->GetRecordCount())
	{	
		pUser->SetAllMembers(m_strUserAccount,m_strPasswd,m_strUserType);
		AfxMessageBox("�����û��ɹ�");
		
		CMyTreeView* pTreeView = (CMyTreeView *)(pMainFrm->m_wndSplitterWnd).GetPane(0,0);

		CTreeCtrl* m_theTreeCtrl = pTreeView->m_TreeCtrl;
		m_theTreeCtrl->DeleteAllItems();

		HTREEITEM rootItem;
		rootItem = m_theTreeCtrl->InsertItem(_T("�û��б�"),2,2,TVI_ROOT);

		CString userTreeHeader[3]={"����Ա","��ҩԱ","ҽ��"};
		HTREEITEM userItem[3];
		for(int i=0;i<3;i++)
		{
			userItem[i]=m_theTreeCtrl->InsertItem(userTreeHeader[i],2,2,rootItem);
			m_theTreeCtrl->SetItemData(userItem[i],(DWORD)i);
		}

		HTREEITEM thePoint;
		for(int i=0;i<3;i++)
		{
			pUserSet->m_strFilter = "UserType='"+userTreeHeader[i]+"'";
			pUserSet->Requery();
			for(int j=0;;j++)
			{
				if(pUserSet->IsEOF())
				{
					break;
				}	
				if(pUserSet->m_UserAccount == pUser->GetAccount())
				{
					HTREEITEM userSpecifics = m_theTreeCtrl->InsertItem(pUserSet->m_UserAccount+"(��ǰ�û�)",0,0,userItem[i]);
					m_theTreeCtrl->SetItemData(userSpecifics,(DWORD)j);
					thePoint = userSpecifics;
				}
				else
				{
					HTREEITEM userSpecifics = m_theTreeCtrl->InsertItem(pUserSet->m_UserAccount,1,1,userItem[i]);
					m_theTreeCtrl->SetItemData(userSpecifics,(DWORD)j);
				}
				pUserSet->MoveNext();
			}
		}
		m_theTreeCtrl->Select(thePoint,TVGN_CARET);
		CDialog::OnOK();
	}
	else
	{
		
		AfxMessageBox("�������û���Ϣ��������������");
		m_strPasswd = _T("");
		UpdateData(FALSE);
	}
	//CDialog::OnOK();
}
