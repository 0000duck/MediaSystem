#pragma once


// CReportField �Ի���

class CReportField : public CDialog
{
	DECLARE_DYNAMIC(CReportField)

public:
	CReportField(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CReportField();

// �Ի�������
	enum { IDD = IDD_FIELDCHOOSER };
	CXTPReportSubListControl m_wndReportSubList;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnClose();
};
