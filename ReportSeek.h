#pragma once


// CReportSeek �Ի���

class CReportSeekDlg : public CDialog
{
	DECLARE_DYNAMIC(CReportSeekDlg)

public:
	CReportSeekDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CReportSeekDlg();
// �Ի�������
	enum { IDD =  NULL};
	//CString m_strFilter;
	CXTPReportFilterEditControl m_wndFilterEditCtrl;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	//virtual void OnOK();
	virtual void OnCancel();
public:
	virtual BOOL OnInitDialog();
};
