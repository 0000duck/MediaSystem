#pragma once


// CMedicTypeSeekDlg �Ի���

class CMedicTypeSeekDlg : public CDialog
{
	DECLARE_DYNAMIC(CMedicTypeSeekDlg)

public:
	CMedicTypeSeekDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMedicTypeSeekDlg();

// �Ի�������
	enum { IDD = IDD_MEDIC_SEEK_TYPE };
	CString m_strContent;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
public:
//	virtual BOOL OnInitDialog();
};
