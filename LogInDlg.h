#pragma once


// CLogInDlg �Ի���

class CLogInDlg : public CDialog
{
	DECLARE_DYNAMIC(CLogInDlg)

public:
	CLogInDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLogInDlg();

// �Ի�������
	enum { IDD = IDD_USER_LOGIN };
	CString m_userAccount;
	CString m_userPasswd;
	CString m_userType;
	CString m_PreUserAccount;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnOK();
public:
	afx_msg void OnEnKillfocusEditAccount();
};
