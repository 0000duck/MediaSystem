// MedicSystemDoc.h : CMedicSystemDoc ��Ľӿ�
//
#include "User.h"
#include "UserSet.h"
#include "MedicSet.h"
#pragma once


class CMedicSystemDoc : public CDocument
{
protected: // �������л�����
	CMedicSystemDoc();
	DECLARE_DYNCREATE(CMedicSystemDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CMedicSystemDoc();
	CUser user;
	CUserSet userSet;
	CMedicSet medicSet;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


