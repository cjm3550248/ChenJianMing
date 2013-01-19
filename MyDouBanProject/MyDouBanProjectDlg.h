// MyDouBanProjectDlg.h : header file
//

#if !defined(AFX_MYDOUBANPROJECTDLG_H__57C80002_D4E1_49B8_9B03_05C123CB103C__INCLUDED_)
#define AFX_MYDOUBANPROJECTDLG_H__57C80002_D4E1_49B8_9B03_05C123CB103C__INCLUDED_

#include "common.h"
#include "MyDouBan.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDouBanProjectDlg dialog

class CMyDouBanProjectDlg : public CDialog
{
// Construction
public:
	CMyDouBanProjectDlg(CWnd* pParent = NULL);	// standard constructor

	//��ʼ��
	void Initial();
	//
	void GetAndShow();


// Dialog Data
	//{{AFX_DATA(CMyDouBanProjectDlg)
	enum { IDD = IDD_MYDOUBANPROJECT_DIALOG };
	CComboBox	m_ComboBoxWay;
	CListCtrl	m_BookList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDouBanProjectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDouBanProjectDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnQuery();
	afx_msg void OnChangeEditQuery();
	afx_msg void OnBtnFront();
	afx_msg void OnBtnNext();
	afx_msg void OnClickListBook(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclickListBook(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListBook(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnGoDouban();
	afx_msg void OnKeydownListBook(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	MyDouBan m_DouBan;
	int m_iStart;	//��ʼλ��
	CString m_strQuery;	//��ѯ����
	int m_nType;	//��ѯ��ʽ
//	int m_iAllRecord;	//��ǰ��ѯ�������еļ�¼��
	int m_iAllPage;		//����ҳ��

	JSON_INFO m_JsonInfo;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYDOUBANPROJECTDLG_H__57C80002_D4E1_49B8_9B03_05C123CB103C__INCLUDED_)
