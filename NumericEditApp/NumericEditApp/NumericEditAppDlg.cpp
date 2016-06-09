
// NumericEditAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NumericEditApp.h"
#include "NumericEditAppDlg.h"
#include "afxdialogex.h"
#include "DlgGetData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CNumericEditAppDlg dialog



CNumericEditAppDlg::CNumericEditAppDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_NUMERICEDITAPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNumericEditAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNumericEditAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CNumericEditAppDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CNumericEditAppDlg message handlers

BOOL CNumericEditAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	// NumericEdit: Attach edit controls
	m_Integer.AttachEdit(IDC_EDIT1, this);
	m_IntegerPositive.AttachEdit(IDC_EDIT2, this);
	m_IntegerRange.AttachEdit(IDC_EDIT3, this);
	m_Decimal.AttachEdit(IDC_EDIT4, this);
	m_DecimalPositive.AttachEdit(IDC_EDIT5, this);
	m_DecimalRange.AttachEdit(IDC_EDIT6, this);

	// NumericEdit: Configure edits
	// integer value
	m_Integer.SetDecimalInput(FALSE);
	m_Integer.SetDefaultValue(10);
	m_Integer.SetData(360); // set initial value

	// integer positive value
	m_IntegerPositive.SetDecimalInput(FALSE);
	m_IntegerPositive.SetNegativeInput(FALSE);
	m_IntegerPositive.SetDefaultValue(-5);
	m_IntegerPositive.SetData(0); // set initial value

	// integer with range value (-100 to 100)
	m_IntegerRange.SetDecimalInput(FALSE);
	m_IntegerRange.SetDefaultValue(50);
	m_IntegerRange.SetMinValue(-100);
	m_IntegerRange.SetMaxValue(100);
	m_IntegerRange.SetData(10.99); // set initial value

	// decimal value
	m_Decimal.SetData(0); // set initial value

	// decimal positive value
	m_DecimalPositive.SetNegativeInput(FALSE);
	m_DecimalPositive.SetData(1.25); // set initial value

	// decimal with range value (-10.50 to 500.0)
	m_DecimalRange.SetMinValue(-10.50);
	m_DecimalRange.SetMaxValue(500.0);
	m_DecimalRange.SetData(5.67); // set initial value

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNumericEditAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNumericEditAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CNumericEditAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CNumericEditAppDlg::OnBnClickedOk()
{
	CDlgGetData dlgGetData;

	m_Integer.GetData(dlgGetData.m_dInteger);
	m_Integer.GetWindowText(dlgGetData.m_sInteger);

	m_IntegerPositive.GetData(dlgGetData.m_dIntegerPositive);
	m_IntegerPositive.GetWindowText(dlgGetData.m_sIntegerPositive);

	m_IntegerRange.GetData(dlgGetData.m_dIntegerRange);
	m_IntegerRange.GetWindowText(dlgGetData.m_sIntegerRange);

	m_Decimal.GetData(dlgGetData.m_dDecimal);
	m_Decimal.GetWindowText(dlgGetData.m_sDecimal);

	m_DecimalPositive.GetData(dlgGetData.m_dDecimalPositive);
	m_DecimalPositive.GetWindowText(dlgGetData.m_sDecimalPositive);

	m_DecimalRange.GetData(dlgGetData.m_dDecimalRange);
	m_DecimalRange.GetWindowText(dlgGetData.m_sDecimalRange);

	dlgGetData.DoModal();
}
