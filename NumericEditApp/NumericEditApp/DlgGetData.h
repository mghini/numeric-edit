#pragma once


// CDlgGetData dialog

class CDlgGetData : public CDialog
{
	DECLARE_DYNAMIC(CDlgGetData)

public:
	CDlgGetData(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgGetData();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GETDATA };
#endif

public:
	double m_dInteger;
	CString m_sInteger;
	double m_dIntegerPositive;
	CString m_sIntegerPositive;
	double m_dIntegerRange;
	CString m_sIntegerRange;
	double m_dDecimal;
	CString m_sDecimal;
	double m_dDecimalPositive;
	CString m_sDecimalPositive;
	double m_dDecimalRange;
	CString m_sDecimalRange;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
