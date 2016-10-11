// SYString.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CSYStringApp:
// See SYString.cpp for the implementation of this class
//

class CSYStringApp : public CWinApp
{
public:
	CSYStringApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CSYStringApp theApp;