#pragma once


// CObjectDlg dialog

class CObjectDlg : public CDialog
{
	DECLARE_DYNAMIC(CObjectDlg)

public:
	CObjectDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CObjectDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OBJECT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_object;
	int m_x_obj;
	int m_y_obj;
	int m_x_obj_2;
	int m_y_obj_2;
};
