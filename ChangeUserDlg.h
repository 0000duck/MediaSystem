#pragma once

#include "Globol.h"

// CChangeUserDlg �Ի���

class CChangeUserDlg : public CDialog
{
	DECLARE_DYNAMIC(CChangeUserDlg)

public:
	CChangeUserDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangeUserDlg();

// �Ի�������
	enum { IDD = IDD_USER_CHANGE };
	CString m_strUserAccount;
	CString m_strPasswd;
	CString m_strUserType;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
};
