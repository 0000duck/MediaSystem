// MedicSystem.h : MedicSystem Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMedicSystemApp:
// �йش����ʵ�֣������ MedicSystem.cpp
//

class CMedicSystemApp : public CWinApp
{
public:
	CMedicSystemApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMedicSystemApp theApp;