#if !defined(AFX_SETSIZEDLG_H__A9C2A88B_BFAD_47DA_B07A_0EA0DECACA3B__INCLUDED_)
#define AFX_SETSIZEDLG_H__A9C2A88B_BFAD_47DA_B07A_0EA0DECACA3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetSizeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetSizeDlg dialog

class CSetSizeDlg : public CDialog
{
// Construction
public:
	CSetSizeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetSizeDlg)
	enum { IDD = IDD_DIALOG1 };
	int		m_nx;
	int		m_ny;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetSizeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetSizeDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETSIZEDLG_H__A9C2A88B_BFAD_47DA_B07A_0EA0DECACA3B__INCLUDED_)
