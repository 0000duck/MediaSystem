// DelUser.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicSystem.h"
#include "DelUser.h"
#include "MainFrm.h"
#include "MyTreeView.h"
// CDelUser �Ի���

IMPLEMENT_DYNAMIC(CDelUserDlg, CDialog)

CDelUserDlg::CDelUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDelUserDlg::IDD, pParent)
{
	Flag = FALSE;
}

CDelUserDlg::~CDelUserDlg()
{
}

void CDelUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_COMBO1,m_wndUserType);
	DDX_Control(pDX,IDC_LIST1,m_UserList);
	DDX_Text(pDX,IDC_EDIT1,m_strUserAccount);
}


BEGIN_MESSAGE_MAP(CDelUserDlg, CDialog)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CDelUserDlg::OnNMClickList1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDelUserDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CDelUser ��Ϣ�������

BOOL CDelUserDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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
		m_UserList.SetItemText(j,2,pUserSet->m_UserPasswd);
		m_UserList.SetItemText(j,3,pUserSet->m_UserType);
		pUserSet->MoveNext();
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CDelUserDlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//AfxMessageBox("sfsfddsf");
	*pResult = 0;
}

void CDelUserDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	int Item=m_wndUserType.GetCurSel();
	CString str;
	m_wndUserType.GetLBText(Item,str);
	if(str == "���н�ɫ")
	{
		pUserSet->m_strFilter="";
	}
	else
	{
		pUserSet->m_strFilter = "UserType='"+str+"'";
	}
	pUserSet->Requery();
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
		m_UserList.SetItemText(j,2,pUserSet->m_UserPasswd);
		m_UserList.SetItemText(j,3,pUserSet->m_UserType);
		pUserSet->MoveNext();
	}
}
void CDelUserDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	UpdateData();
	if(m_strUserAccount == "")
	{
		AfxMessageBox("������Ҫɾ�����û��˺�");
	}
	else
	{
		int result=AfxMessageBox("ȷʵҪɾ�����û���?",MB_OKCANCEL);
		if(result==IDOK)
		{
			CString copyFilter = pUserSet->m_strFilter;
			CUser* user = new CUser;
			user->SetAccount(m_strUserAccount);
		
			if (user->DeleteUser(pUserSet))
			{
				pUserSet->m_strFilter=copyFilter;
				pUserSet->Requery();
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
					m_UserList.SetItemText(j,2,pUserSet->m_UserPasswd);
					m_UserList.SetItemText(j,3,pUserSet->m_UserType);
					pUserSet->MoveNext();
					
				}
					m_strUserAccount="";
					UpdateData(FALSE);
					AfxMessageBox("ɾ���û��ɹ�");
					Flag = TRUE;
			}
		}
	}
}


void CDelUserDlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���

	if (!Flag)
	{
		CDialog::OnCancel();
		return;
	}
	
	CMainFrame *pMainFrm = (CMainFrame *)AfxGetMainWnd();
	CUserSet* pUserSet = &pMainFrm->userSet;
	CUser* pUser = &pMainFrm->user;

	CMyTreeView* pTreeView = (CMyTreeView *)(pMainFrm->m_wndSplitterWnd).GetPane(0,0);

	CTreeCtrl* m_theTreeCtrl=pTreeView->m_TreeCtrl;
	m_theTreeCtrl->DeleteAllItems();

	HTREEITEM rootItem;
	rootItem = m_theTreeCtrl->InsertItem(_T("�û��б�"),2,2,TVI_ROOT);

	CString userTreeHeader[3]={"����Ա","��ҩԱ","ҽ��"};
	HTREEITEM userItem[3];
	for(int i=0;i<3;i++)
	{
		userItem[i] = m_theTreeCtrl->InsertItem(userTreeHeader[i],2,2,rootItem);
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

	CDialog::OnCancel();
}
