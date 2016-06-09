
// NumericEditAppDlg.h : header file
//

#pragma once

#include "numericedit.h"


// CNumericEditAppDlg dialog
class CNumericEditAppDlg : public CDialogEx
{
// Construction
public:
	CNumericEditAppDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NUMERICEDITAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// NumericEdit controls
	CNumericEdit m_Integer;
	CNumericEdit m_IntegerPositive;
	CNumericEdit m_IntegerRange;

	CNumericEdit m_Decimal;
	CNumericEdit m_DecimalPositive;
	CNumericEdit m_DecimalRange;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
