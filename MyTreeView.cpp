// MyTreeView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicSystem.h"
#include "MyTreeView.h"
#include "LogInDlg.h"
#include "Globol.h"
#include "RegisterUser.h"
// CMyTreeView

IMPLEMENT_DYNCREATE(CMyTreeView, CTreeView)

CMyTreeView::CMyTreeView()
{

}

CMyTreeView::~CMyTreeView()
{
}

BEGIN_MESSAGE_MAP(CMyTreeView, CTreeView)
	ON_WM_CREATE()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_POPU_ADD, &CMainFrame::OnRegisterUser)
	ON_COMMAND(ID_POPU_DEL, &CMainFrame::OnDelUser)
	ON_COMMAND(ID_POPU_SEEK, &CMainFrame::OnSeekUser)
	ON_COMMAND(ID_POPU_MOD, &CMainFrame::OnModUserPasswd)
	ON_COMMAND(ID_POPU_CHANGE,&CMainFrame::OnChangeUser)
	
END_MESSAGE_MAP()


// CMyTreeView ���

#ifdef _DEBUG
void CMyTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyTreeView ��Ϣ�������

int CMyTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO:  �ڴ������ר�õĴ�������
	return 0;
}

BOOL CMyTreeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ����ר�ô����/����û���
	cs.style |= TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT;//�������Ϳؼ�����ʽ
	return CTreeView::PreCreateWindow(cs);
}

void CMyTreeView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	m_TreeCtrl = &GetTreeCtrl();

	CBitmap bmp;
	bmp.LoadBitmap(IDB_USERS_LIST);

	m_imgList.Create(16, 16, ILC_COLORDDB|ILC_MASK|ILC_COLOR24, 3, 0);
	m_imgList.Add(&bmp,RGB(255,255,255));

	m_TreeCtrl->SetImageList(&m_imgList,TVSIL_NORMAL);
	m_TreeCtrl->SetLineColor(RGB(0,0,255));

	CString userTreeHeaders[3] = {_T("����Ա"),_T("��ҩԱ"),_T("ҽ��")};
	HTREEITEM rootItem;
	rootItem = m_TreeCtrl->InsertItem(_T("�û��б�"),2,2,TVI_ROOT);

	HTREEITEM userItem[3];
	for (int i = 0;i < 3;i++)
	{
		userItem[i] = m_TreeCtrl->InsertItem(userTreeHeaders[i],2,2,rootItem);
		m_TreeCtrl->SetItemData(userItem[i],i);
	}

	CUser *pUser = &((CMainFrame *)AfxGetMainWnd())->user;
	CUserSet *pUserSet = &((CMainFrame *)AfxGetMainWnd())->userSet;
	if (pUserSet->IsOpen())
	{
		pUserSet->Close();
	}
	pUserSet->Open();

	CLogInDlg loginDlg;
	loginDlg.DoModal();

	HTREEITEM thePoint;
	CString strFilter;
	for(int i=0;i<3;i++)
	{
		strFilter.Format(_T("UserType=\'%s\'"),userTreeHeaders[i]);
		pUserSet->m_strFilter = strFilter;
		//pUserSet->m_strFilter = (_T("UserType='"+userTreeHeaders[i]+"'");
		pUserSet->Requery();
		for(int j=0;;j++)
		{
			if(pUserSet->IsEOF())
			{
				break;
			}	
			if(pUserSet->m_UserAccount == pUser->GetAccount())
			{
				HTREEITEM userLog = m_TreeCtrl->InsertItem(pUserSet->m_UserAccount+_T("(��ǰ�û�)"),0,0,userItem[i]);
				m_TreeCtrl->SetItemData(userLog,j);
				thePoint=userLog;
			}
			else
			{
				HTREEITEM userOthers = m_TreeCtrl->InsertItem(pUserSet->m_UserAccount,1,1,userItem[i]);
				m_TreeCtrl->SetItemData(userOthers,j);
			}
			pUserSet->MoveNext();
		}
	}
	//m_TreeCtrl->Expand(rootItem,TVE_EXPAND);
	//m_TreeCtrl->Expand(userItem[0],TVE_EXPAND);
	//m_TreeCtrl->Expand(userItem[1],TVE_EXPAND);
	//m_TreeCtrl->Expand(userItem[2],TVE_EXPAND);
	m_TreeCtrl->Select(thePoint,TVGN_CARET);

	// TODO: �ڴ����ר�ô����/����û���
}

void CMyTreeView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CTreeView::OnRButtonDown(nFlags, point);
	CMainFrame *pMainFrm = (CMainFrame *)AfxGetMainWnd();
	CUser *pUser = &pMainFrm->user;
	CMenu menu,*pPopMenu;
	menu.LoadMenu(ID_MENU_POPU);
	pPopMenu = menu.GetSubMenu(0);

	if (pUser->GetType() != "����Ա")//���ǹ���Ա�͹ر���ز˵�
	{
		pPopMenu->EnableMenuItem(ID_POPU_ADD,MF_DISABLED);
		pPopMenu->EnableMenuItem(ID_POPU_DEL,MF_DISABLED);
		pPopMenu->EnableMenuItem(ID_POPU_SEEK,MF_DISABLED);
	}
	
	GetCursorPos(&point);
	pPopMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON, point.x, point.y, this);
	
}
