#ifndef ___GAME__APP__20150122___
#define ___GAME__APP__20150122___

#include "../Core/Application.h"

class CGameApp : public CApplication
{
public:
	CGameApp();
	virtual ~CGameApp();

protected:
	virtual bool OnInitInstance(STARTUP_INFO *pInfo);
	virtual bool OnInitResource();
};

// ����ȫ��Ӧ�ó���ʵ������
extern CGameApp theApp;

#endif
