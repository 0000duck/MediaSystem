#pragma once


// CMedicIDSeekDlg �Ի���

class CMedicIDSeekDlg : public CDialog
{
	DECLARE_DYNAMIC(CMedicIDSeekDlg)

public:
	CMedicIDSeekDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMedicIDSeekDlg();

// �Ի�������
	enum { IDD = IDD_MEDIC_SEEK_ID };
	CString m_strContent;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
};
