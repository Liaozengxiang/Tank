/*
 * class CApplication
 * Copyright (C) 2015. All rights reserved.
 */

#ifndef ___APPLICATION__20150122___
#define ___APPLICATION__20150122___

#include "../hge181/include/hge.h"
#include "Object.h"
#include <string>

class CApplication : public CObject
{
public:
	CApplication();
	virtual ~CApplication();

	bool Initialize();
	bool Start();

protected:
	virtual bool InitInstance();
	virtual void ExitInstance();
	virtual void OnSetTitle(std::string &strAppTitle);
	virtual void OnRender();

protected:
	static CApplication* GetInstance() { return m_pInstance; }
	static bool FrameFunc();
	static bool RenderFunc();
	static bool ExitFunc();

protected:
	bool InitHGE();

protected:
	static CApplication*	m_pInstance;					// ȫ��ΨһӦ�ó���ʵ��ָ��
	HGE*					m_pHGE;							// hge ����ָ��
	std::string				m_strAppTitle;					// Ӧ�ó������
};

#endif
