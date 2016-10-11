#include "StdAfx.h"
#include "StringManager.h"
#include <sstream>
#include <algorithm>

StringManager* StringManager::m_instance = NULL;
//=================================================================================================================================
StringManager* StringManager::Instance()
{
	if (m_instance == NULL) {
		m_instance = new StringManager(); 
	}
	return m_instance;
}

StringManager::StringManager(void)
{
	Test();
}

StringManager::~StringManager(void)
{
	
}

void StringManager::Test()
{
	std::wstring context = _T("this is a test1, this is a test2,");
	std::wstring get1 = GetMidWithTagString(context, _T("is a "), _T(","));
	std::wstring get2 = GetMidWithTagString(context, _T("is a "), _T(","), 2);

	if (get1.compare(L"test1") == 0)
	{
		OutputDebugString(L"Success:get1\n");
	}

	if (get2.compare(L"test2") == 0)
	{
		OutputDebugString(L"Success:get2\n");
	}


	std::wstring fileName = GetPathLastComponent(_T("C:\\123\\456\\789.txt"));
	OutputDebugString(fileName.c_str());
}


/**************************
* FUNCTION:Split
* DESCRIPTION:Split
* PARAMETERS:none
* RETURNED:none
* CREATED:
* BY:sawyer
* COMMENTS:2016.06.29
**************************/
std::vector<std::string> StringManager::SplitA(const std::string &s, char delim)
{
	std::vector<std::string> elems;
	std::stringstream ss(s);
	std::string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}


/**************************
* FUNCTION:GetMidWithTagString
* DESCRIPTION:GetMidWithTagString
* PARAMETERS:none
* RETURNED:none
* CREATED:
* BY:sawyer
* COMMENTS:2016.05.09
**************************/
std::wstring StringManager::GetMidWithTagString(std::wstring context, std::wstring begin, std::wstring end, int count)
{
	int tmp = 0;
	int pos1 = 0;

	for (int i = 0; i<count; i++)
	{
		tmp = context.find(begin, pos1) + begin.length();
		if (tmp == -1) return L"";
		if (tmp < pos1) return L"";
		pos1 = tmp;
	}

	int pos2 = context.find(end, pos1);

	if (pos2 == -1) {
		return L"";
	}

	if (pos1 == pos2) {
		return L"";
	}

	if (pos1 > pos2) {
		return L"";
	}

	return context.substr(pos1, pos2 - pos1);			
}

/**************************
* FUNCTION:GetPathLastComponent
* DESCRIPTION:GetPathLastComponent
* PARAMETERS:none
* RETURNED:none
* CREATED:
* BY:sawyer
* COMMENTS:2016.05.09
**************************/
std::wstring StringManager::GetPathLastComponent(const std::wstring &fileName)
{
	size_t last = fileName.find_last_of(L"/\\");
	if (last != std::string::npos)
		return fileName.substr(last+1);
	return L"";
}
/**************************
* FUNCTION:UnicodeToAnsi
* DESCRIPTION:UnicodeToAnsi
* PARAMETERS:none
* RETURNED:none
* CREATED:
* BY:sawyer
* COMMENTS:2011.09.29
**************************/
////////////////////////////////////////////////////////////////
//	char *pAniFilename = NULL;
//	StringManager::Instance()->WCharTochar(appPath.c_str(), &pAniFilename);
//  delete pAniFilename;
void StringManager::UnicodeToAnsi(const wchar_t *source, char **dest)
{
	*dest = (char *)new char[2 * wcslen(source) + 1] ;
	memset(*dest, 0, 2 * wcslen(source) + 1);

	int nLen = (int)wcslen(source) + 1;
	WideCharToMultiByte(CP_ACP, 0, source, nLen, *dest, 2*nLen, NULL, NULL);
	//OutputDebugStringA((*dest));
}

/**************************
* FUNCTION:AnsiToUnicode
* DESCRIPTION:AnsiToUnicode
* PARAMETERS:none
* RETURNED:none
* CREATED:
* BY:sawyer
* COMMENTS:2012.10.05
**************************/
////////////////////////////////////////////////////////////////
//	wchar_t *pUniFilename = NULL;
//	StringManager::Instance()->CharTowchar("test", &pUniFilename);
//  delete pUniFilename;
void StringManager::AnsiToUnicode(const char *source, wchar_t **dest)
{
	// ANSI(char) to Unicode(WCHAR)
	int nIndex = MultiByteToWideChar(CP_ACP, 0, source, -1, NULL, 0);
	*dest = new wchar_t[nIndex + 1];
	MultiByteToWideChar(CP_ACP, 0, source, -1, *dest, nIndex);
}
