// ObjectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "ObjectDlg.h"
#include "afxdialogex.h"


// CObjectDlg dialog

IMPLEMENT_DYNAMIC(CObjectDlg, CDialog)

CObjectDlg::CObjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_OBJECT, pParent)
	, m_object(0)
	, m_x_obj(0)
	, m_y_obj(0)
	, m_x_obj_2(0)
	, m_y_obj_2(0)
{

}

CObjectDlg::~CObjectDlg()
{
}

void CObjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_object);
	DDX_Text(pDX, IDC_EDIT_X_OBJ, m_x_obj);
	DDV_MinMaxInt(pDX, m_x_obj, 0, 9999999);
	DDX_Text(pDX, IDC_EDIT_Y_OBJ, m_y_obj);
	DDV_MinMaxInt(pDX, m_y_obj, 0, 9999999);
	DDX_Text(pDX, IDC_EDIT_X_OBJ_2, m_x_obj_2);
	DDV_MinMaxInt(pDX, m_x_obj_2, 0, 999999);
	DDX_Text(pDX, IDC_EDIT_Y_OBJ_2, m_y_obj_2);
	DDV_MinMaxInt(pDX, m_y_obj_2, 0, 999999);
}


BEGIN_MESSAGE_MAP(CObjectDlg, CDialog)
END_MESSAGE_MAP()


// CObjectDlg message handlers
