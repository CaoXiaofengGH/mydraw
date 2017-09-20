// SetSizeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyDraw.h"
#include "SetSizeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetSizeDlg dialog


CSetSizeDlg::CSetSizeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetSizeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetSizeDlg)
	m_nx = 0;
	m_ny = 0;
	//}}AFX_DATA_INIT
}


void CSetSizeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetSizeDlg)
	DDX_Text(pDX, IDC_EDIT_X, m_nx);
	DDX_Text(pDX, IDC_EDIT_Y, m_ny);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetSizeDlg, CDialog)
	//{{AFX_MSG_MAP(CSetSizeDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetSizeDlg message handlers
