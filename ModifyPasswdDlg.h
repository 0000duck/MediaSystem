#pragma once


// CModifyPasswdDlg �Ի���

class CModifyPasswdDlg : public CDialog
{
	DECLARE_DYNAMIC(CModifyPasswdDlg)

public:
	CModifyPasswdDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CModifyPasswdDlg();

// �Ի�������
	enum { IDD = IDD_USER_MODPW };
	CString m_strAccount;
	CString m_strOldPasswd;
	CString m_strPasswd;
	CString m_strPasswd1;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
};
