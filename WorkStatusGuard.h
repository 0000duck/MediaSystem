#pragma once





// CWorkStatusGuard
class CWorkStatusGuard : public CWnd
{
	DECLARE_DYNAMIC(CWorkStatusGuard)

public:
	CWorkStatusGuard(LPCTSTR pszMessage, CWnd * pParentWnd = NULL);
	virtual ~CWorkStatusGuard();

	// ��������
	BOOL Create(CWnd* pParent);

	// ����Ҫ��ʾ����Ϣ
	void ShowNewMessages(LPCTSTR strMsg);

	// ��ʾ/���ش���
	void Show();
	void Hide();
	// ���ƺ���
	void Render();
	CEvent m_stopEvent;
	BOOL m_bStop;
public:
	const static TCHAR ZEMR_WAITING_TIP[];

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnPaint();

	// ע�ᴰ����
	virtual BOOL RegisterWindowClass(HINSTANCE hInstance = NULL);

	

	// �����߳�
	void RenderWindow();

	CRect GetDesktopWorkAreaRect();
	static DWORD WINAPI ThreadProc (PVOID pParam);
private:
	CString m_strMsg;
	CImageList m_imgList;

	int m_nIconIdx;

	const static COLORREF BGCLR = RGB(150, 200, 150);
	const static int MIN_WIDTH = 300;
	const static int MIN_HEIGHT = 64;
	const static int MARGIN_HOR = 15;
	const static int ICON_SIZE = 50;
	const static int TIME_WIDTH = 50;
	const static int TIME_HEIGHT = 21;

	
	CFont m_captionFont;
	BOOL m_bIsRanderThreadStart;
	CWnd* m_pParentWnd;
	DWORD m_dwTimeStart;
public:
//	afx_msg void OnNcPaint();
//	afx_msg void OnNcPaint();
};

//class  CAutoWorkStatusGuard
//{
//public:
//	CAutoWorkStatusGuard(CWorkStatusGuard *pWorkGuard, LPCTSTR lpMsg)
//	{
//		m_pWorkStatusGuard = pWorkGuard;
//		if(m_pWorkStatusGuard != NULL && lpMsg != NULL)
//		{
//			m_pWorkStatusGuard->ShowNewMessages(lpMsg);
//			m_pWorkStatusGuard->Show();
//		}
//	}
//	~CAutoWorkStatusGuard()
//	{
//		if(m_pWorkStatusGuard != NULL)
//			m_pWorkStatusGuard->Hide();
//	}	
//
//private:
//	CWorkStatusGuard *m_pWorkStatusGuard;
//};
