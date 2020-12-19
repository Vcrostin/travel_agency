
// MFC_travel.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCtravelApp:
// Сведения о реализации этого класса: MFC_travel.cpp
//

class CMFCtravelApp : public CWinApp
{
public:
	CMFCtravelApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCtravelApp theApp;



