
// FLV_UI_Parse.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CFLV_UI_ParseApp: 
// �йش����ʵ�֣������ FLV_UI_Parse.cpp
//

class CFLV_UI_ParseApp : public CWinApp
{
public:
	CFLV_UI_ParseApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFLV_UI_ParseApp theApp;