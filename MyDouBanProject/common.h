#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <list>

#ifdef _DEBUG
#define	WRITE_LOG	true
#else
#define WRITE_LOG	false
#endif

#define SEARCH_KEY	0x0001
#define SEARCH_TAG	0x0002

using std::string;
using std::fstream;
using std::ios;
using std::list;
using std::wstring;


//************************************
// Method:    ChenJianMinGetJSON
// FullName:  ChenJianMinGetJSON
// Access:    public 
// Returns:   BOOL	�Ƿ��ѯ�ɹ�
// Qualifier:	
// Parameter: CString & strPageFile	��ż���������ַ���
// Parameter: CString strKey	����������
// Parameter: int nType		��ѯ�ķ�ʽ����Ϊ���ؼ��ֺͰ���ǩ��ѯ
// Parameter: int nStart	��ʼ��ѯ�ļ�¼��
// Description:		�Ӷ������ϻ�ȡ��Ŀ��ѯ��Json
//************************************
BOOL ChenJianMinGetJSON(CString &strPageFile, CString strKey, int nType=SEARCH_KEY, int nStart=0);

//************************************
// Method:    ApiWriteLog
// FullName:  ApiWriteLog
// Access:    public 
// Returns:   void
// Description:					д����־
// Parameter: string strLog		��־��Ϣ
// Parameter: bool bAppend		�Ƿ���׷�ӵ���ʽд����־
//************************************
void ApiWriteLog(string strLog, bool bAppend=TRUE);

//************************************
// Method:    ApiSplitToArray
// FullName:  ApiSplitToArray
// Access:    public 
// Returns:   int	�ָ�Ϊ�˶��ٸ����ַ���
// Qualifier:
// Parameter: CStringArray & strArray	������Ž�����ַ�������
// Parameter: const CString & strInput	���ָ����ַ���
// Parameter: string strKey	�����ָ���ǵ��ַ���
// Parameter: BOOL bClear	ʹ��ǰ�Ƿ����������Ž��������
// Parameter: int iNum	�ִ�����С����
// Description:		��CString��ĳ���ַ����ָ�Ϊ����ִ�������������ַ���������
//************************************
int ApiSplitToArray(CStringArray &strArray, const CString &strInput, string strKey, BOOL bClear, int iNum);

//************************************
// Method:    ApiGetDetailTime
// FullName:  ApiGetDetailTime
// Access:    public 
// Returns:   CString			���ص���ϸʱ��
// Description:					��ȡ��ǰ����ϸʱ�䣬���ַ�������ʽ����
//************************************
CString ApiGetDetailTime();
