// MyDrawView.cpp : implementation of the CMyDrawView class
//

#include "stdafx.h"
#include "MyDraw.h"

#include "MyDrawDoc.h"
#include "MyDrawView.h"
#include "SetSizeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView

IMPLEMENT_DYNCREATE(CMyDrawView, CView)

BEGIN_MESSAGE_MAP(CMyDrawView, CView)
	//{{AFX_MSG_MAP(CMyDrawView)
	ON_WM_LBUTTONUP()
	ON_COMMAND(IDD_SetColor, OnSetColor)
	ON_COMMAND(IDD_SetSize, OnSetSize)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView construction/destruction

CMyDrawView::CMyDrawView()
{
	// TODO: add construction code here

}

CMyDrawView::~CMyDrawView()
{
}

BOOL CMyDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView drawing

void CMyDrawView::OnDraw(CDC* pDC)
{
	CMyDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
//CMyDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	vector<CPoint>::iterator it;
	pDC->TextOut(350,5,"***绘制圆形、矩形、三角形及输出文本by曹晓峰***");

	CBrush brush(pDoc->m_clr);
	CBrush *poldBrush=pDC->SelectObject(&brush);
	for(it=pDoc->m_vPnt.begin();it!=pDoc->m_vPnt.end();it++)
	{
	//绘制矩形
	pDC->Rectangle(it->x-pDoc->m_nx,it->y-pDoc->m_ny,it->x+pDoc->m_nx,it->y+pDoc->m_ny);
	pDC->SelectObject(poldBrush);
	//绘制椭圆形
	pDC->Ellipse(it->x-pDoc->m_nx,it->y-pDoc->m_ny,it->x+pDoc->m_nx,it->y+pDoc->m_ny);
	pDC->SelectObject(poldBrush);
	//绘制三角形
	pDC->SelectObject(brush);
	pDC->BeginPath();
	pDC->MoveTo(it->x,it->y-pDoc->m_ny);
	pDC->LineTo(it->x+0.7*pDoc->m_nx,it->y+0.7*pDoc->m_ny);
	pDC->LineTo(it->x-0.7*pDoc->m_nx,it->y+0.7*pDoc->m_ny);
	pDC->LineTo(it->x,it->y-pDoc->m_ny);
	pDC->EndPath();
	pDC->FillPath();
	}
	pDC->SelectObject(poldBrush);

}

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView printing

BOOL CMyDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView diagnostics

#ifdef _DEBUG
void CMyDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CMyDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDrawDoc* CMyDrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDrawDoc)));
	return (CMyDrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView message handlers

void CMyDrawView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMyDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->m_vPnt.push_back(point);
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}

void CMyDrawView::OnSetColor() 
{
	// TODO: Add your command handler code here
	CMyDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CColorDialog dlg;
	if(dlg.DoModal()==IDOK)
		pDoc->m_clr=dlg.GetColor();
	
}

void CMyDrawView::OnSetSize() 
{
	// TODO: Add your command handler code here
	CMyDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CSetSizeDlg dlg;
	dlg.m_nx=pDoc->m_nx;
	dlg.m_ny=pDoc->m_ny;
	if(dlg.DoModal()==IDOK)
	{
		pDoc->m_nx=dlg.m_nx;
		pDoc->m_ny=dlg.m_ny;

	}
	
}
