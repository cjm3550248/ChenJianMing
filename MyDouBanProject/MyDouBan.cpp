// MyDouBan.cpp: implementation of the MyDouBan class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyDouBanProject.h"
#include "MyDouBan.h"
#include <shlwapi.h>
#include "StringUtil.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

tBOOK::tBOOK()
{
	m_ulID = 0;
}

MyDouBan::MyDouBan()
{

}

MyDouBan::~MyDouBan()
{

}

bool MyDouBan::ChenJianMinGetJSONParse( const CString &strJson, JSON_INFO &tJsonInfo )
{
	string strJ = (LPCTSTR)strJson;
	
	size_t index = 0;
	
	strJ = strJ.substr(1, strJ.length()-2);
	
	//��ѯ �˴η��ص�ͼ������
	strJ = strJ.substr(8);
	index = strJ.find(',');
	string strValue = strJ.substr(0, index);
	strJ = strJ.substr(index);
	
	tJsonInfo.m_nCount = atoi(strValue.c_str());
	
	//��ѯ ��������ȫ������е�ƫ��ֵ
	strJ = strJ.substr(9);
	index = strJ.find(',');
	strValue = strJ.substr(0, index);
	strJ = strJ.substr(index);
	tJsonInfo.m_nOffset = atoi(strValue.c_str());
	
	//��ѯ ȫ����Ŀ����
	strJ = strJ.substr(9);
	index = strJ.find(',');
	strValue = strJ.substr(0, index);
	strJ = strJ.substr(index);
	tJsonInfo.m_nTotal = atoi(strValue.c_str());
	
	//���û�л�ȡ����Ŀ����ֱ�ӷ���
	if (0 == tJsonInfo.m_nCount ||
		0 == tJsonInfo.m_nTotal)
	{
		return true;
	}
	
	//����ʾ��Ŀ��Json�ַ�����ÿ����ָ�ַ���������
	strJ = strJ.substr(11, strJ.length()-12);
	CStringArray sarrBooks;
	ApiSplitToArray(sarrBooks, strJ.c_str(), "\"rating\":", TRUE, 1);
	int iCount = sarrBooks.GetSize();
	if (0 == iCount)
	{
		return false;
	}
	
	for (int i=0; i<iCount; ++i)
	{
		BOOK book;
		if (GetBookInfo(sarrBooks.GetAt(i), book))
		{
			tJsonInfo.m_lsBooks.push_front(book);
		}
	}
	return true;	
}

bool MyDouBan::GetBookInfo( const CString &strBook, BOOK &book )
{
	string strB = (LPCTSTR)strBook;
	CStringUtil strUtil;
	wstring wstrB = strUtil.utf82ws(strB);
	CString strTemp(wstrB.c_str());
	strB = (LPCTSTR)strTemp;
	
	//��ѯ��Ŀ����ʱ��
	size_t index = strB.find("\"pubdate\":\"");
	if (-1 == index) return false;
	strB = strB.substr(index+11);
	index = strB.find("\",");
	book.m_strPubdate = strB.substr(0, index);
	strB = strB.substr(index+1);
	
	//��ѯ��Ŀ��id
	index = strB.find("\"id\":\"");
	if (-1 == index) return false;
	strB = strB.substr(index+6);
	index = strB.find(",");
	string strValue = strB.substr(0, index);
	book.m_ulID = atol(strValue.c_str());
	strB = strB.substr(index+1);
	
	//��ѯ��Ŀ������
	index = strB.find("\"title\":\"");
	if (-1 == index) return false;
	strB = strB.substr(index+9);
	index = strB.find("\",");
	book.m_strTitle = strB.substr(0, index);
	strB = strB.substr(index+1);
	
	//��ѯ��Ŀ�ĳ�����
	index = strB.find("\"publisher\":\"");
	if (-1 == index) return false;
	strB = strB.substr(index+13);
	index = strB.find("\",");
	book.m_strPublisher = strB.substr(0, index);
	strB = strB.substr(index+1);
	
	//��ѯ��Ŀ������
	index = strB.find("\"author\":");
	if (-1 == index) return false;
	strB = strB.substr(index+9);
	index = strB.find(",\"summary\":");
	strValue = strB.substr(0, index);
	strValue = strValue.substr(2, strValue.length()-4);
	CStringArray sarrAuthor;
	ApiSplitToArray(sarrAuthor, strValue.c_str(), "\",\"", TRUE, 1);
	if (sarrAuthor.GetSize() <= 0)
	{
		return false;
	}
	for (int i=0; i<sarrAuthor.GetSize(); ++i )
	{
		if (book.m_strAuthor.empty())
		{
			book.m_strAuthor = (LPCTSTR)sarrAuthor.GetAt(i);
		}
		else
		{
			book.m_strAuthor = book.m_strAuthor + ", " + (LPCTSTR)sarrAuthor.GetAt(i);
		}
	}
	strB = strB.substr(index+1);
	
	//��ѯ��Ŀ�ļ��
	index = strB.find("\"summary\":\"");
	if (-1 == index) return false;
	strB = strB.substr(index+10);
	index = strB.rfind("\"}");
	if (index != -1)
	{
		book.m_strSummary = strB.substr(0, index);
	}
	else
	{
		book.m_strSummary = strB.substr(0);
	}
	strB = strB.substr(index+1);
	
	return true;	
}
