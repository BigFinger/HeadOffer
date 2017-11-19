#include <string.h>
#include "CMyString.h"

CMyString::CMyString(char* pData /* = NULL */){
	if (pData == NULL)
	{
		this->m_pData = pData;
	}
	else if (pData != this->m_pData)
	{
		size_t length = strlen(pData);
		this->m_pData = new char[length];
		strcpy(this->m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str){
	if (str.m_pData == NULL)
	{
		this->m_pData = NULL;
	}
	else
	{
		size_t length = strlen(str.m_pData);
		this->m_pData = new char[length];
		strcpy(this->m_pData, str.m_pData);
	}
}

CMyString::~CMyString(){

}

CMyString& CMyString::operator = (const CMyString& copy){
	/* 一般C++做法 */
	if (this == &copy)
	{
		return *this;
	}

	if (this->m_pData != NULL)
	{
		delete m_pData;
		m_pData = NULL;
	}

	if (copy.m_pData == NULL)
	{
		this->m_pData = NULL;
	}
	else
	{
		size_t length = strlen(copy.m_pData);
		this->m_pData = new char[length];
		strcpy(this->m_pData, copy.m_pData);
	}

	/* 考虑异常安全性做法 */
	if (this != &copy)
	{
		CMyString strtmp(copy);
		char* p = strtmp.m_pData;
		strtmp.m_pData = this->m_pData;
		this->m_pData = p;
	}
	return *this;
}

char* CMyString::getData(){
	return m_pData;
}