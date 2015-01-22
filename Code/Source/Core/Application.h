/*
 * class CApplication
 * Copyright (C) 2015. All rights reserved.
 */

#ifndef ___APPLICATION__20150122___
#define ___APPLICATION__20150122___

#include "../hge181/include/hge.h"
#include "Object.h"
#include <string>

struct STARTUP_INFO
{
	int				nWidth;					// ���ڿ��
	int				nHeight;				// ���ڸ߶�
	bool			bWindowed;				// ������ʾ����ȫ����ʾ
	std::string		strTitle;				// Ӧ�ó������
	bool			bHideMouse;				// �Ƿ��������
	bool			bShowSplash;			// �Ƿ���ʾ hge �Ļ�ӭ����
	int				nFPS;					// ��Ϸ��ʾ֡Ƶ
	int				nIcon;					// Ӧ�ó���ͼ����Դ ID
};

class CApplication : public CObject
{
public:
	CApplication();
	virtual ~CApplication();

	bool Initialize();
	bool Start();

public:
	static HTEXTURE LoadTexture(const char *lpszImage);

protected:
	virtual bool OnInitInstance(STARTUP_INFO *pInfo);
	virtual void OnExitInstance();
	virtual bool OnInitResource();
	virtual void OnFrame(float fDelta);
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
	STARTUP_INFO			m_startupInfo;					// ��������
};

#endif
