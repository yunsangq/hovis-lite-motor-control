
// hovisgogo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// ChovisgogoApp:
// �� Ŭ������ ������ ���ؼ��� hovisgogo.cpp�� �����Ͻʽÿ�.
//

class ChovisgogoApp : public CWinApp
{
public:
	ChovisgogoApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern ChovisgogoApp theApp;