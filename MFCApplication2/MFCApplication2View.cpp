
// MFCApplication2View.cpp : implementation of the CMFCApplication2View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication2.h"
#endif

#include "MFCApplication2Doc.h"
#include "MFCApplication2View.h"
#include "Options.h"
#include "ObjectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2View

IMPLEMENT_DYNCREATE(CMFCApplication2View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication2View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_TOOLS_OPTIONS, &CMFCApplication2View::OnToolsOptions)
	ON_COMMAND(ID_TOOLS_DRAWOBJECT, &CMFCApplication2View::OnToolsDrawobject)
END_MESSAGE_MAP()

// CMFCApplication2View construction/destruction

CMFCApplication2View::CMFCApplication2View()
{
	// TODO: add construction code here

}

CMFCApplication2View::~CMFCApplication2View()
{
}

BOOL CMFCApplication2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApplication2View drawing

void CMFCApplication2View::OnDraw(CDC* pDC)
{
	CMFCApplication2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect clientRect;
	GetClientRect(clientRect);
	if (m_bgColor == 0) 
		pDC->FillSolidRect(clientRect, RGB(150, 0, 0));
	else if(m_bgColor == 1)
		pDC->FillSolidRect(clientRect, RGB(0, 0, 150));
	pDC->TextOutW(m_x, m_y, m_text);

	if ((m_object == 0) && flag)
		pDC->Ellipse(m_x_obj, m_y_obj, m_x_obj_2, m_y_obj_2);
	else if ((m_object == 1) && flag)
		pDC->Rectangle(m_x_obj, m_y_obj, m_x_obj_2, m_y_obj_2);
}

void CMFCApplication2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication2View diagnostics

#ifdef _DEBUG
void CMFCApplication2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication2Doc* CMFCApplication2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication2Doc)));
	return (CMFCApplication2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication2View message handlers


void CMFCApplication2View::OnToolsOptions()
{
	COptions dlgOptions;

	/*dlgOptions.m_text = m_text;
	dlgOptions.m_bgColor = m_bgColor;
	dlgOptions.m_x = m_x;
	dlgOptions.m_y = m_y;*/

	if (dlgOptions.DoModal() == IDOK) {
		flag = false;
		m_text = dlgOptions.m_text;
		m_bgColor = dlgOptions.m_bgColor;
		m_x = dlgOptions.m_x;
		m_y = dlgOptions.m_y;
	}
	Invalidate();
	UpdateWindow();
}


void CMFCApplication2View::OnToolsDrawobject()
{
	CObjectDlg dlgObject;
	if (dlgObject.DoModal() == IDOK) {
		flag = true;
		m_bgColor = -1;
		m_text.Empty();
		m_object = dlgObject.m_object;
		m_x_obj = dlgObject.m_x_obj;
		m_y_obj = dlgObject.m_y_obj;
		m_x_obj_2 = dlgObject.m_x_obj_2;
		m_y_obj_2 = dlgObject.m_x_obj_2;
	}
	Invalidate();
	UpdateWindow();
}
