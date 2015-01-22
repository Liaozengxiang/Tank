#include "GameApp.h"
#include "../Core/Sprite.h"

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

bool CGameApp::InitInstance()
{
	HTEXTURE hTex = m_pHGE->Texture_Load("Resource/Image/Splash.bmp");
	CSprite *pSpr = new CSprite(hTex, 0, 0, 376, 222);

	AddChild(pSpr);
	pSpr->MoveTo((800 - pSpr->GetWidth()) / 2, (600 - pSpr->GetHeight()) / 2);

	return true;
}
