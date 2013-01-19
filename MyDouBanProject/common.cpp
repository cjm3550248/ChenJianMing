#include "StdAfx.h"
#include "common.h"
#include <afxinet.h>

#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>

#include <assert.h>
#include <comutil.h>

BOOL ChenJianMinGetJSON(CString &strPageFile, CString strKey, int nType/*=SEARCH_KEY*/, int nStart/*=0*/)
{	
	CString strAllUrl;
	
	if (strKey.IsEmpty())
	{
		return false;
	}
	//���ݲ���������������
	strAllUrl = _T("https://api.douban.com/v2/book/");
	switch(nType)
	{
	case SEARCH_KEY:
		strAllUrl += _T("search?q=");
		break;
	case SEARCH_TAG:
		strAllUrl += _T("search?tag=");
		break;
	default:
		return FALSE;
	}
	
	//������ѯ�ַ���
	strAllUrl += strKey;
	CString strStart;
	strStart.Format("&start=%d", nStart);
	strAllUrl += strStart;
	
	CString strParty;
	BOOL b_Err = TRUE;
	CInternetSession Session(NULL, 0);
	CHttpFile* HttpFile = NULL;
	DWORD dwStatus;
//	BOOL bResult = TRUE;
	BOOL bResult = FALSE;
	
	while (b_Err)	//�����쳣ʱ��������ȡ
	{
		try
		{
			b_Err = FALSE;
			strPageFile = "";	//�������
			HttpFile = (CHttpFile*)Session.OpenURL(strAllUrl);
			
			if (HttpFile->QueryInfoStatusCode(dwStatus))
			{
				if ((200 == dwStatus) || (500 == dwStatus))	//ȡ������
				{
					strParty = "";
					while (HttpFile->ReadString(strParty))
					{
						strPageFile += strParty;
					}
					if (strParty.GetLength() > 0)
					{
						strPageFile += strParty;
					}
					bResult = TRUE;
				}
			}
			
			HttpFile->Close();
			Session.Close();  
		}
		catch (...)	//������ǽ�����ˣ��ͻᱨ�쳣
		{
			HttpFile = NULL;
			return FALSE;
		}
	}
	HttpFile = NULL;
	
	return bResult;
}

void ApiWriteLog( string strLog, bool bAppend/*=TRUE*/ )
{
	if (WRITE_LOG)
	{
		if (strLog.length() == 0)
		{
			return;
		}
		fstream fout;
		string strFile = _T("debug.log");
		
		if(bAppend)
			fout.open(strFile.c_str(), ios::out|ios::app);
		else
			fout.open(strFile.c_str(), ios::out|ios::trunc);
		
		if (!fout.is_open())
		{
			return;
		}
		
		string strTime = (LPCTSTR)ApiGetDetailTime();
		if (strTime.length() == 0)
		{
			return;
		}
		
		strLog = strTime + _T("\t") + strLog;
		fout<<strLog<<"\n";
		fout.close();
		fout.clear();
	}
}

int ApiSplitToArray( CStringArray &strArray, const CString &strInput, string strKey, BOOL bClear, int iNum )
{
	if (bClear)
	{
		strArray.RemoveAll();	//��վ�����
	}
	if ((strKey.length() == 0) && (strInput.GetLength() >= iNum))
	{
		strArray.Add(strInput);
		return 1;
	}
	if (-1 == strInput.Find(strKey.c_str()) && strInput.GetLength()>=iNum)
	{
		strArray.Add(strInput);
		return 1;
	}
	string strLeave = strInput;
	string strTemp;
	int i_index = 0;
	int iCount = 0;
	
	if (0 == iNum)
	{
		iNum = 2;
	}
	
	while ((i_index = (int)strLeave.find(strKey)) != -1)
	{
		strTemp = strLeave.substr(0, i_index);
		if (strTemp.length() >= iNum)
		{
			strArray.Add(strTemp.c_str());
			iCount++;
		}
		if (strLeave.length() >= (i_index + strKey.length()))
		{
			strLeave = strLeave.substr(i_index + strKey.length(), strLeave.length() - i_index - strKey.length());
		}
		else
		{
			break;
		}
	}
	if (strLeave.length() >= iNum)
	{
		strArray.Add(strLeave.c_str());
		iCount++;
	}
	return iCount;
}

CString ApiGetDetailTime()
{
	//��ȡ��ǰʱ��
	CTime curTime = CTime::GetCurrentTime();
	
	//��ʽ����ǰʱ��ΪYYYY-MM-DD hh:mm:ss�ĸ�ʽ
	CString strRet = curTime.Format("%Y-%m-%d %H:%M:%S");
	
	return strRet;
}