#pragma once

#include "Globol.h"

// CSeekUser �Ի���

class CSeekUserDlg : public CDialog
{
	DECLARE_DYNAMIC(CSeekUserDlg)

public:
	CSeekUserDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSeekUserDlg();

// �Ի�������
	enum { IDD = IDD_USER_SEEK };
	CUserSet	*pUserSet;
	CListCtrl	m_UserList;
	CString		m_strAccount;
	CString		m_strUsertype;
	int			m_ntypeRadio;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
protected:
	virtual void OnOK();
};
