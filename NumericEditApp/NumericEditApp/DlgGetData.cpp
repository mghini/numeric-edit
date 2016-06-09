// DlgGetData.cpp : implementation file
//

#include "stdafx.h"
#include "NumericEditApp.h"
#include "DlgGetData.h"
#include "afxdialogex.h"


// CDlgGetData dialog

IMPLEMENT_DYNAMIC(CDlgGetData, CDialog)

CDlgGetData::CDlgGetData(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_GETDATA, pParent)
{

}

CDlgGetData::~CDlgGetData()
{
}

void CDlgGetData::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgGetData, CDialog)
END_MESSAGE_MAP()


// CDlgGetData message handlers


BOOL CDlgGetData::OnInitDialog()
{
	CDialog::OnInitDialog();

	CString text;
	text.Format(_T("%d"), (int)m_dInteger);
	GetDlgItem(IDC_STATIC1)->SetWindowText(text);
	GetDlgItem(IDC_STATIC2)->SetWindowText(m_sInteger);

	text.Format(_T("%d"), (int)m_dIntegerPositive);
	GetDlgItem(IDC_STATIC3)->SetWindowText(text);
	GetDlgItem(IDC_STATIC4)->SetWindowText(m_sIntegerPositive);

	text.Format(_T("%d"), (int)m_dIntegerRange);
	GetDlgItem(IDC_STATIC5)->SetWindowText(text);
	GetDlgItem(IDC_STATIC6)->SetWindowText(m_sIntegerRange);

	text.Format(_T("%g"), m_dDecimal);
	GetDlgItem(IDC_STATIC7)->SetWindowText(text);
	GetDlgItem(IDC_STATIC8)->SetWindowText(m_sDecimal);

	text.Format(_T("%g"), m_dDecimalPositive);
	GetDlgItem(IDC_STATIC9)->SetWindowText(text);
	GetDlgItem(IDC_STATIC10)->SetWindowText(m_sDecimalPositive);

	text.Format(_T("%g"), m_dDecimalRange);
	GetDlgItem(IDC_STATIC11)->SetWindowText(text);
	GetDlgItem(IDC_STATIC12)->SetWindowText(m_sDecimalRange);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
