#include "GameApp.h"

// ����ȫ��ΨһӦ�ó���ʵ������
CGameApp theApp;

CGameApp::CGameApp()
{
}

CGameApp::~CGameApp()
{
}

void CGameApp::OnSetTitle(std::string &strAppTitle)
{
	strAppTitle = "̹�˴�ս�����";
}
