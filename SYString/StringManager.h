#pragma once

#include <string>
#include <vector>
class StringManager
{
public:
	//creat
	static StringManager* Instance(void);
	~StringManager(void);
	//method
	std::vector<std::string> SplitA(const std::string &s, char delim);
	
	std::wstring GetMidWithTagString(std::wstring context, std::wstring begin, std::wstring end, int count = 1);
	std::wstring GetPathLastComponent(const std::wstring &fileName);
	void UnicodeToAnsi(const wchar_t *source, char **dest);
	void AnsiToUnicode(const char *source, wchar_t **dest);
private:
	StringManager(void);
	//method
	void Test();
private:	
	//creat
	static StringManager* m_instance;	
	//var


};
