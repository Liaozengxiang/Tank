#ifndef ___GAME__APP__20150122___
#define ___GAME__APP__20150122___

#include "../Core/Application.h"

class CGameApp : public CApplication
{
public:
	CGameApp();
	virtual ~CGameApp();

protected:
	virtual void OnSetTitle(std::string &strAppTitle);
};

// ����ȫ��Ӧ�ó���ʵ������
extern CGameApp theApp;

#endif
