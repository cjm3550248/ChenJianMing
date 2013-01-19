// MyDouBanProjectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyDouBanProject.h"
#include "MyDouBanProjectDlg.h"

#include "StringUtil.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDouBanProjectDlg dialog

CMyDouBanProjectDlg::CMyDouBanProjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDouBanProjectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDouBanProjectDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_iStart = 0;	//起始位置
	m_strQuery = _T("");	//查询内容
	m_nType = SEARCH_KEY;	//查询方式
}

void CMyDouBanProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDouBanProjectDlg)
	DDX_Control(pDX, IDC_COMBO_QUERY_WAY, m_ComboBoxWay);
	DDX_Control(pDX, IDC_LIST_BOOK, m_BookList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDouBanProjectDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDouBanProjectDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_QUERY, OnBtnQuery)
	ON_EN_CHANGE(IDC_EDIT_QUERY, OnChangeEditQuery)
	ON_BN_CLICKED(IDC_BTN_FRONT, OnBtnFront)
	ON_BN_CLICKED(IDC_BTN_NEXT, OnBtnNext)
	ON_NOTIFY(NM_CLICK, IDC_LIST_BOOK, OnClickListBook)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_BOOK, OnRclickListBook)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_BOOK, OnDblclkListBook)
	ON_COMMAND(IDC_GO_DOUBAN, OnGoDouban)
	ON_WM_KEYDOWN()
	ON_WM_CANCELMODE()
	ON_WM_CAPTURECHANGED()
	ON_NOTIFY(LVN_KEYDOWN, IDC_LIST_BOOK, OnKeydownListBook)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDouBanProjectDlg message handlers

BOOL CMyDouBanProjectDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	Initial();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDouBanProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDouBanProjectDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDouBanProjectDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDouBanProjectDlg::OnBtnQuery() 
{
	// TODO: Add your control notification handler code here
	m_iStart = 0;
	if (m_ComboBoxWay.GetCurSel() == 0)	//选中0，即为"key"关键字查询
	{
		m_nType = SEARCH_KEY;	//关键字	key查询
	}
	else if (m_ComboBoxWay.GetCurSel() == 1)//选中1，即为"tag"标签查询
	{
		m_nType = SEARCH_TAG;	//标签		tag查询
	}

	((CEdit *)GetDlgItem(IDC_EDIT_QUERY))->GetWindowText(m_strQuery);
	if ( m_strQuery.IsEmpty() )	//为空
	{
		AfxMessageBox(_T("请输入查询内容"));
		return;
	}

	GetAndShow();
		
}

void CMyDouBanProjectDlg::Initial()
{
	//添加列名
	m_BookList.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
	m_BookList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_FLATSB|LVS_EX_TWOCLICKACTIVATE |LVS_EX_GRIDLINES);
	m_BookList.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 75);
	m_BookList.InsertColumn(1, _T("书名"), LVCFMT_LEFT, 121);
	m_BookList.InsertColumn(2, _T("作者"), LVCFMT_LEFT, 90);
	m_BookList.InsertColumn(3, _T("出版社"), LVCFMT_LEFT, 85);
	m_BookList.InsertColumn(4, _T("出版时间"), LVCFMT_LEFT, 75);

	m_ComboBoxWay.InsertString(0, _T("Key"));
	m_ComboBoxWay.InsertString(1, _T("Tag"));
	m_ComboBoxWay.SetCurSel(0);

	((CEdit *)GetDlgItem(IDC_EDIT_INTRODUCE))->SetReadOnly(TRUE);	

}

void CMyDouBanProjectDlg::OnChangeEditQuery() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here

	
	
}


//IDC_BTN_FRONT
void CMyDouBanProjectDlg::OnBtnFront() 
{
	// TODO: Add your control notification handler code here
	if (m_iStart>0)
	{
		m_iStart--;
		GetAndShow();
	}

	
	
}
//IDC_BTN_NEXT
void CMyDouBanProjectDlg::OnBtnNext() 
{
	// TODO: Add your control notification handler code here
	if (m_iStart<m_iAllPage)
	{
		m_iStart++;
		GetAndShow();
	}

	
	
}

void CMyDouBanProjectDlg::GetAndShow()
{
	m_BookList.DeleteAllItems();
	((CEdit *)GetDlgItem(IDC_EDIT_INTRODUCE))->SetWindowText(_T(""));

	CString strResult;
	if ( !ChenJianMinGetJSON(strResult, m_strQuery, m_nType, m_iStart*20) )	//获取失败
	{
	//	AfxMessageBox(_T("获取失败"));
		return;	
	}

	//解析
	m_JsonInfo.m_lsBooks.clear();	//清空已经存在的
	if (!m_DouBan.ChenJianMinGetJSONParse(strResult, m_JsonInfo))	//解析失败
	{
		//		AfxMessageBox(_T("解析失败"));
		return;		
	}

	//获取成功，则显示
	std::list<BOOK> myList = m_JsonInfo.m_lsBooks;
	for (list<BOOK>::reverse_iterator it = myList.rbegin(); it!=myList.rend(); it++)
	{
		m_BookList.InsertItem(m_BookList.GetItemCount(), _T(""));
		int i = m_BookList.GetItemCount()-1;

		CString strTemp;		
		unsigned long lId = (*it).m_ulID;	//ID
		strTemp.Format(_T("%d"), lId);
		m_BookList.SetItemText(i, 0, strTemp);
		
		strTemp = (*it).m_strTitle.c_str();		//书名
		m_BookList.SetItemText(i, 1, strTemp);

		strTemp = (*it).m_strAuthor.c_str();	//作者
		m_BookList.SetItemText(i, 2, strTemp);

		strTemp = (*it).m_strPublisher.c_str();		//出版社
		m_BookList.SetItemText(i, 3, strTemp);

		strTemp = (*it).m_strPubdate.c_str();		//出版时间
		m_BookList.SetItemText(i, 4, strTemp);

//		this->UpdateData(FALSE);
		

	}

//	m_BookList.GetFocus();
	m_BookList.SetItemState(0,LVNI_FOCUSED | LVIS_SELECTED, LVNI_FOCUSED | LVIS_SELECTED); 
//	BOOL bTest = m_BookList.SetItemState(0, LVIS_SELECTED ,LVIS_SELECTED);	//默认选中第一行 
	POSITION position = m_BookList.GetFirstSelectedItemPosition();
	if (position != NULL)		//选中，
	{
		//得到选中项
		int i = m_BookList.GetNextSelectedItem(position);	
		//根据选中项显示简介
		int iCount = 0;
		for (list<BOOK>::reverse_iterator it2 = myList.rbegin(); it2!=myList.rend(); it2++)
		{
			if (i == iCount)
			{
				CString strTemp = (*it2).m_strSummary.c_str();
				strTemp = strTemp.Right(strTemp.GetLength()-1);
				((CEdit*)GetDlgItem(IDC_EDIT_INTRODUCE))->SetWindowText(strTemp);
			}
			iCount++;
			
		}
	}	


	int iAllRecord = m_JsonInfo.m_nTotal;

	CString strShow;
	strShow.Format(_T("%d"), iAllRecord);
	((CEdit*)GetDlgItem(IDC_STATIC_RECORDS))->SetWindowText(strShow);

	int iAllPage = iAllRecord/20;
	if ((iAllRecord%20))	//非倍数——取余不为0
	{
		iAllPage ++;
	}
	m_iAllPage = iAllPage;
	strShow.Format(_T("%d"), iAllPage);
	((CEdit*)GetDlgItem(IDC_STATIC_PAGES))->SetWindowText(strShow);
	
	strShow.Format(_T("%d"), m_iStart);
	((CEdit*)GetDlgItem(IDC_STATIC_NOW))->SetWindowText(strShow);

	
}

//	列表单击	IDC_LIST_BOOK
void CMyDouBanProjectDlg::OnClickListBook(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

//	UINT uC = pNMHDR->code;HWND h = pNMHDR->hwndFrom;UINT uId = pNMHDR->idFrom;
	
	POSITION position = m_BookList.GetFirstSelectedItemPosition();
	if (position == NULL)		//没有选中，
	{
		return;
	}	
	//得到选中项
	int i = m_BookList.GetNextSelectedItem(position);
	//根据选中项显示简介
	std::list<BOOK> myList = m_JsonInfo.m_lsBooks;
	int iCount = 0;
	for (list<BOOK>::reverse_iterator it = myList.rbegin(); it!=myList.rend(); it++)
	{
		if (i == iCount)
		{
			CString strTemp = (*it).m_strSummary.c_str();
			strTemp = strTemp.Right(strTemp.GetLength()-1);
			((CEdit*)GetDlgItem(IDC_EDIT_INTRODUCE))->SetWindowText(strTemp);
		}
		iCount++;
		
	}

	*pResult = 0;
}

void CMyDouBanProjectDlg::OnRclickListBook(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	POSITION position = m_BookList.GetFirstSelectedItemPosition();
	if (position == NULL)
	{
		*pResult = 0;
		return;		
	}

    CMenu menu;
	CPoint point;
	GetCursorPos(&point);	
    menu.LoadMenu(IDR_MENU);	//载入菜单资源
	
    ASSERT(menu.GetSafeHmenu());
    CMenu* pSubMenu = menu.GetSubMenu(0);	
    ASSERT(pSubMenu);	
    pSubMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_LEFTBUTTON|TPM_RIGHTBUTTON,point.x,point.y,this);	//显示浮动菜单
	
    menu.Detach();
	
	*pResult = 0;
}

void CMyDouBanProjectDlg::OnDblclkListBook(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	OnClickListBook( pNMHDR, pResult);

	*pResult = 0;
}


void CMyDouBanProjectDlg::OnGoDouban() 
{
	// TODO: Add your command handler code here
	//获取选中项
	POSITION position = m_BookList.GetFirstSelectedItemPosition();
	if (NULL == position)
	{
		AfxMessageBox(_T("请先选中要清理的行"));
		return;
	}
	int index = m_BookList.GetNextSelectedItem(position);

	CString strId = m_BookList.GetItemText(index, 0);
	CString strUrl = _T("http://book.douban.com/subject/")+strId;
	ShellExecute(NULL, _T("open"), strUrl, NULL, NULL, SW_SHOW);
		
}


void CMyDouBanProjectDlg::OnKeydownListBook(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_KEYDOWN* pLVKeyDow = (LV_KEYDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	POSITION position = m_BookList.GetFirstSelectedItemPosition();
	if (position == NULL)		//没有选中，
	{
		return;
	}	
	//得到选中项
	int i = m_BookList.GetNextSelectedItem(position);

	switch(pLVKeyDow->wVKey)
	{
	case VK_UP:
		i--;
		break;
	case VK_DOWN:
		i++;
		break;
	default:
		break;
	}

	//根据选中项显示简介
	std::list<BOOK> myList = m_JsonInfo.m_lsBooks;
	int iCount = 0;
	for (list<BOOK>::reverse_iterator it = myList.rbegin(); it!=myList.rend(); it++)
	{
		if (i == iCount)
		{
			CString strTemp = (*it).m_strSummary.c_str();
			strTemp = strTemp.Right(strTemp.GetLength()-1);
			((CEdit*)GetDlgItem(IDC_EDIT_INTRODUCE))->SetWindowText(strTemp);
		}
		iCount++;
		
	}
	
	*pResult = 0;
}



