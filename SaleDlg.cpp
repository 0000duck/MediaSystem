// SaleDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicSystem.h"
#include "SaleDlg.h"

// CSaleDlg �Ի���

IMPLEMENT_DYNAMIC(CSaleMedicDlg, CDialog)

CSaleMedicDlg::CSaleMedicDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSaleMedicDlg::IDD, pParent)
{
	m_strMedicName = "";
	m_strMedicType = "";
	m_nMedicNumber = 0;
	m_vecSaleBills.clear();
	CMainFrame *pMainFrm = (CMainFrame *)AfxGetMainWnd();
	pSaleSet = &pMainFrm->saleSet;
	pMedicSet = &pMainFrm->medicSet;
}

CSaleMedicDlg::~CSaleMedicDlg()
{
}

void CSaleMedicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_LIST1,m_ListCtrl);
	DDX_Text(pDX,IDC_MEDIC_NAME,m_strMedicName);
	DDX_Text(pDX,IDC_MEDIC_TYPE,m_strMedicType);
	DDX_Text(pDX,IDC_MEDIC_NUMBER,m_nMedicNumber);
}


BEGIN_MESSAGE_MAP(CSaleMedicDlg, CDialog)
	ON_BN_CLICKED(IDC_SALE_ADD, &CSaleMedicDlg::OnBnClickedSaleAdd)
	ON_CBN_SELCHANGE(IDC_MEDIC_TYPE, &CSaleMedicDlg::OnCbnSelchangeMedicType)
	ON_BN_CLICKED(IDC_SALE_DEL, &CSaleMedicDlg::OnBnClickedSaleDel)
	ON_BN_CLICKED(IDOK, &CSaleMedicDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDUNDO, &CSaleMedicDlg::OnBnClickedUndo)
	ON_BN_CLICKED(IDCANCEL, &CSaleMedicDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CSaleDlg ��Ϣ�������

BOOL CSaleMedicDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_ListCtrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	CString strSale[] = {"ҩƷ���","ҩƷ����","��������","ҩƷ����","�ܽ��"};
	for (int i = 0;i < 5;i++)
	{
		m_ListCtrl.InsertColumn(i,strSale[i],LVCFMT_LEFT,86);
	}
	
	if (!pSaleSet->IsOpen())
	{
		pSaleSet->Open();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CSaleMedicDlg::OnCbnSelchangeMedicType()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	CComboBox *pName = (CComboBox *)GetDlgItem(IDC_MEDIC_NAME);
	pName->ResetContent();
	pMedicSet->m_strFilter = "MedicType= '"+m_strMedicType+"'";
	pMedicSet->Requery();
	while(!pMedicSet->IsEOF())
	{
		pName->AddString(pMedicSet->m_MedicName);
		pMedicSet->MoveNext();
	}
}


//��Ӱ�ť��Ӧ�¼�����
void CSaleMedicDlg::OnBnClickedSaleAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();

	if ("" == m_strMedicType)
	{
		AfxMessageBox("��ѡ��ҩƷ����");
		return;
	}
	if ("" == m_strMedicName)
	{
		AfxMessageBox("��ѡ��ҩƷ����");
		return;
	}

	CSale *bufSale;
	vector<CSale *>::iterator it = m_vecSaleBills.begin();
	for (;it != m_vecSaleBills.end();++it)
	{
		bufSale = *it;
		if (bufSale->m_MedicName == m_strMedicName)
		{
			AfxMessageBox("��ҩƷ���ڱ��γ��۵��У�����ɾ��");
			return;
		}
	}
	
	pMedicSet->m_strFilter = "MedicName='"+m_strMedicName+"'";
	pMedicSet->Requery();

	if (0 == m_nMedicNumber)
	{
		AfxMessageBox("��������ȷ�ĳ�������");
		return;
	}
	else if (m_nMedicNumber > pMedicSet->m_MedicNumber)
	{
		CString str;
		str.Format("����������㣬��ǰ����Ϊ%d",pMedicSet->m_MedicNumber);
		AfxMessageBox(str);
		return;
	}

	//�ж��Ƿ����
	CMedicManage medicManage;
	medicManage.SetMedicSet(pMedicSet);
	CTime OutTime = medicManage.GetOutDateTime();
	CTime CurTime = CTime::GetCurrentTime();
	if (OutTime < CurTime)
	{
		AfxMessageBox("��ѡ���ҩƷ�ѹ��ڣ�������ѡ��");
		return;
	}

	int number=m_ListCtrl.GetItemCount();
	CString str;
	str.Format("%d",m_nMedicNumber);
	m_ListCtrl.InsertItem(number,pMedicSet->m_MedicID);
	m_ListCtrl.SetItemText(number,1,pMedicSet->m_MedicName);
	m_ListCtrl.SetItemText(number,2,str);
	str.Format("%.2f",pMedicSet->m_MedicPrice);
	m_ListCtrl.SetItemText(number,3,str);
	str.Format("%.2f",pMedicSet->m_MedicPrice*m_nMedicNumber);
	m_ListCtrl.SetItemText(number,4,str);

	CSale *pSale = new CSale;
	pSale->m_MedicID = pMedicSet->m_MedicID;
	pSale->m_MedicName = pMedicSet->m_MedicName;
	pSale->m_MedicNumber = m_nMedicNumber;
	pSale->m_MedicPrice = pMedicSet->m_MedicPrice;
	pSale->m_TotalMoney = pMedicSet->m_MedicPrice*m_nMedicNumber;
	m_vecSaleBills.push_back(pSale);//���δ��������۵���������
	
	CComboBox *pType = (CComboBox *)GetDlgItem(IDC_MEDIC_TYPE);
	pType->SetCurSel(-1);
	CComboBox *pName = (CComboBox *)GetDlgItem(IDC_MEDIC_NAME);
	pName->SetCurSel(-1);
	pName->ResetContent();

	m_nMedicNumber = 0;
	UpdateData(FALSE);

}

//ɾ����ť��Ӧ�¼�����
void CSaleMedicDlg::OnBnClickedSaleDel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	if ("" == m_strMedicType)
	{
		AfxMessageBox("��ѡ��ҩƷ����");
		return;
	}
	if ("" == m_strMedicName)
	{
		AfxMessageBox("��ѡ��ҩƷ����");
		return;
	}

	CSale *bufSale;
	vector<CSale *>::iterator it = m_vecSaleBills.begin();
	for (;it != m_vecSaleBills.end();)
	{
		bufSale = *it;
		if (bufSale->m_MedicName == m_strMedicName)
		{
			it = m_vecSaleBills.erase(it);
			break;
		}
		else
			++it;
	}

	if (it == m_vecSaleBills.end())
	{
		AfxMessageBox("ѡ���ҩƷ���ڱ��γ��۵��У�������ѡ��");
		return;
	}

	CString str;
	str.Format("ɾ�����۵��е�ҩƷ%s�ɹ�",m_strMedicName);
	AfxMessageBox(str);

	int nCounts = m_ListCtrl.GetItemCount();
	for (int i = 0;i < nCounts;i++)
	{
		if (m_ListCtrl.GetItemText(i,1) == m_strMedicName)
		{
			m_ListCtrl.DeleteItem(i);
			//m_ListCtrl.RedrawItems(0,nCounts);
			break;
		}
	}
	
}

void CSaleMedicDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//OnOK();
	if (m_vecSaleBills.empty())
	{
		AfxMessageBox("��ǰδ����κ�ҩƷ");
		return;
	}

	CSale *bufSale;
	float fMoney = 0;
	vector<CSale *>::iterator it = m_vecSaleBills.begin();
	for (;it != m_vecSaleBills.end();it++)
	{
		bufSale = *it;
		pSaleSet->AddNew();
		pSaleSet->m_MedicID = bufSale->m_MedicID;
		pSaleSet->m_MedicName = bufSale->m_MedicName;
		pSaleSet->m_MedicNumber = bufSale->m_MedicNumber;
		pSaleSet->m_MedicPrice = bufSale->m_MedicPrice;
		pSaleSet->m_TotalMoney = bufSale->m_TotalMoney;
		if (pSaleSet->CanUpdate())
		{
			pSaleSet->Update();
		}
		fMoney += bufSale->m_TotalMoney;
	}

	CString str;
	str.Format("����ɹ�����֧��%.1fԪ",fMoney);
	AfxMessageBox(str);

	m_vecSaleBills.clear();
	m_ListCtrl.DeleteAllItems();
}

void CSaleMedicDlg::OnBnClickedUndo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_vecSaleBills.size())
	{
		if (AfxMessageBox("ȷ���������г��۵�ҩƷ��",MB_YESNO) == IDYES)
		{
			m_vecSaleBills.clear();
			m_ListCtrl.DeleteAllItems();
		}
	}
	else
		AfxMessageBox("��ǰδ����κ�ҩƷ");
	
}

void CSaleMedicDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_vecSaleBills.size())
	{
		AfxMessageBox("�˳�֮ǰ���Ƚ������");
		return;
	}
	OnCancel();
}
