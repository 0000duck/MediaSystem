
#pragma once

#include "UserSet.h"

// CRegisterUser �Ի���

class CRegisterUserDlg : public CDialog
{
	DECLARE_DYNAMIC(CRegisterUserDlg)

public:
	CRegisterUserDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRegisterUserDlg();

// �Ի�������
	enum { IDD = IDD_USER_ADD };
	CUserSet *pUserSet;
private:
	CListCtrl	m_UserList;
	CString	m_UserAccount;
	CString	m_UserPasswd;
	CString	m_UserPasswd2;
	CString	m_UserType;
	BOOL Flag;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
protected:
	virtual void OnCancel();
	virtual void OnOK();
public:
	afx_msg void OnEnKillfocusRegisterAccount();
public:
	afx_msg void OnClose();
};
