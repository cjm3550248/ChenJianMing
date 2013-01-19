; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyDouBanProjectDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MyDouBanProject.h"

ClassCount=3
Class1=CMyDouBanProjectApp
Class2=CMyDouBanProjectDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MYDOUBANPROJECT_DIALOG
Resource4=IDR_MENU

[CLS:CMyDouBanProjectApp]
Type=0
HeaderFile=MyDouBanProject.h
ImplementationFile=MyDouBanProject.cpp
Filter=N

[CLS:CMyDouBanProjectDlg]
Type=0
HeaderFile=MyDouBanProjectDlg.h
ImplementationFile=MyDouBanProjectDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_GO_DOUBAN

[CLS:CAboutDlg]
Type=0
HeaderFile=MyDouBanProjectDlg.h
ImplementationFile=MyDouBanProjectDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MYDOUBANPROJECT_DIALOG]
Type=1
Class=CMyDouBanProjectDlg
ControlCount=17
Control1=IDC_STATIC_QUERY,static,1342308352
Control2=IDC_EDIT_QUERY,edit,1350631552
Control3=IDC_COMBO_QUERY_WAY,combobox,1344340227
Control4=IDC_BTN_QUERY,button,1342242816
Control5=IDC_LIST_BOOK,SysListView32,1350633479
Control6=IDC_STATIC_TEXT1,static,1342308352
Control7=IDC_STATIC_RECORDS,static,1342308353
Control8=IDC_STATIC_TEXT2,static,1342308352
Control9=IDC_STATIC_PAGES,static,1342308353
Control10=IDC_STATIC_TEXT3,static,1342308352
Control11=IDC_BTN_FRONT,button,1342242816
Control12=IDC_BTN_NEXT,button,1342242816
Control13=IDC_STATIC_TEXT4,static,1342308352
Control14=IDC_STATIC_NOW,static,1342308353
Control15=IDC_STATIC_TEXT5,static,1342308352
Control16=IDC_STATIC_TEXT6,static,1342308352
Control17=IDC_EDIT_INTRODUCE,edit,1352728580

[MNU:IDR_MENU]
Type=1
Class=CMyDouBanProjectDlg
Command1=IDC_GO_DOUBAN
CommandCount=1

