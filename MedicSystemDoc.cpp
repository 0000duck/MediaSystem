// MedicSystemDoc.cpp : CMedicSystemDoc ���ʵ��
//

#include "stdafx.h"
#include "MedicSystem.h"

#include "MedicSystemDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMedicSystemDoc

IMPLEMENT_DYNCREATE(CMedicSystemDoc, CDocument)

BEGIN_MESSAGE_MAP(CMedicSystemDoc, CDocument)
END_MESSAGE_MAP()


// CMedicSystemDoc ����/����

CMedicSystemDoc::CMedicSystemDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMedicSystemDoc::~CMedicSystemDoc()
{
}

BOOL CMedicSystemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	
	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMedicSystemDoc ���л�

void CMedicSystemDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CMedicSystemDoc ���

#ifdef _DEBUG
void CMedicSystemDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMedicSystemDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMedicSystemDoc ����
