// MyDouBanProject.h : main header file for the MYDOUBANPROJECT application
//

#if !defined(AFX_MYDOUBANPROJECT_H__148C3482_5194_4672_AD21_7A3365A2C89F__INCLUDED_)
#define AFX_MYDOUBANPROJECT_H__148C3482_5194_4672_AD21_7A3365A2C89F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyDouBanProjectApp:
// See MyDouBanProject.cpp for the implementation of this class
//

class CMyDouBanProjectApp : public CWinApp
{
public:
	CMyDouBanProjectApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDouBanProjectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyDouBanProjectApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYDOUBANPROJECT_H__148C3482_5194_4672_AD21_7A3365A2C89F__INCLUDED_)
