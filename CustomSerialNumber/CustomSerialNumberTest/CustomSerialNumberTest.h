
// CustomSerialNumberTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCustomSerialNumberTestApp: 
// �йش����ʵ�֣������ CustomSerialNumberTest.cpp
//

class CCustomSerialNumberTestApp : public CWinApp
{
public:
	CCustomSerialNumberTestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCustomSerialNumberTestApp theApp;