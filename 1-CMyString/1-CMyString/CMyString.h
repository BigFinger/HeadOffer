#pragma once

class CMyString{
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	~CMyString();

	CMyString& operator = (const CMyString& copy);
	char* getData();
private:
	char* m_pData;
};