// MedicSystemView.h : CMedicSystemView ��Ľӿ�
//


#pragma once


class CMedicSystemView : public CView
{
protected: // �������л�����
	CMedicSystemView();
	DECLARE_DYNCREATE(CMedicSystemView)

// ����
public:
	CMedicSystemDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMedicSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MedicSystemView.cpp �еĵ��԰汾
inline CMedicSystemDoc* CMedicSystemView::GetDocument() const
   { return reinterpret_cast<CMedicSystemDoc*>(m_pDocument); }
#endif

