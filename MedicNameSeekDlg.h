#pragma once


// CMedicNameSeekDlg �Ի���

class CMedicNameSeekDlg : public CDialog
{
	DECLARE_DYNAMIC(CMedicNameSeekDlg)

public:
	CMedicNameSeekDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMedicNameSeekDlg();

// �Ի�������
	enum { IDD = IDD_MEDIC_SEEK_NAME };
	CString m_strContent;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
};
