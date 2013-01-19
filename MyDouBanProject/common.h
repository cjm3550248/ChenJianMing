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
// Returns:   BOOL	是否查询成功
// Qualifier:	
// Parameter: CString & strPageFile	存放检索结果的字符串
// Parameter: CString strKey	检索的条件
// Parameter: int nType		查询的方式，分为按关键字和按标签查询
// Parameter: int nStart	开始查询的记录数
// Description:		从豆瓣网上获取书目查询的Json
//************************************
BOOL ChenJianMinGetJSON(CString &strPageFile, CString strKey, int nType=SEARCH_KEY, int nStart=0);

//************************************
// Method:    ApiWriteLog
// FullName:  ApiWriteLog
// Access:    public 
// Returns:   void
// Description:					写入日志
// Parameter: string strLog		日志信息
// Parameter: bool bAppend		是否以追加的形式写入日志
//************************************
void ApiWriteLog(string strLog, bool bAppend=TRUE);

//************************************
// Method:    ApiSplitToArray
// FullName:  ApiSplitToArray
// Access:    public 
// Returns:   int	分割为了多少个子字符串
// Qualifier:
// Parameter: CStringArray & strArray	用来存放结果的字符串数组
// Parameter: const CString & strInput	被分隔的字符串
// Parameter: string strKey	用做分隔标记的字符串
// Parameter: BOOL bClear	使用前是否清除用来存放结果的数组
// Parameter: int iNum	字串的最小长度
// Description:		把CString以某个字符串分割为多个字串并将结果存入字符串数组中
//************************************
int ApiSplitToArray(CStringArray &strArray, const CString &strInput, string strKey, BOOL bClear, int iNum);

//************************************
// Method:    ApiGetDetailTime
// FullName:  ApiGetDetailTime
// Access:    public 
// Returns:   CString			返回的详细时间
// Description:					获取当前的详细时间，以字符串的形式返回
//************************************
CString ApiGetDetailTime();
