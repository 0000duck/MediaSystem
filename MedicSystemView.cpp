// MedicSystemView.cpp : CMedicSystemView ���ʵ��
//

#include "stdafx.h"
#include "MedicSystem.h"

#include "MedicSystemDoc.h"
#include "MedicSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMedicSystemView

IMPLEMENT_DYNCREATE(CMedicSystemView, CView)

BEGIN_MESSAGE_MAP(CMedicSystemView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMedicSystemView ����/����

CMedicSystemView::CMedicSystemView()
{
	// TODO: �ڴ˴���ӹ������

	XTPSkinManager()->LoadSkin(_T("Styles/WinXP.Royale.cjstyles"));
}

CMedicSystemView::~CMedicSystemView()
{
}

BOOL CMedicSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMedicSystemView ����

void CMedicSystemView::OnDraw(CDC* pDC)
{
	CMedicSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP3);
	dcCompatible.SelectObject(&bmp);
	CRect rect;
	GetClientRect(&rect);
	BITMAP bitmap;
	bmp.GetBitmap(&bitmap);
	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&dcCompatible,0,0,SRCCOPY);
//  	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&dcCompatible,
//  		0,0,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMedicSystemView ��ӡ

BOOL CMedicSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMedicSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMedicSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMedicSystemView ���

#ifdef _DEBUG
void CMedicSystemView::AssertValid() const
{
	CView::AssertValid();
}

void CMedicSystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMedicSystemDoc* CMedicSystemView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMedicSystemDoc)));
	return (CMedicSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CMedicSystemView ��Ϣ�������
