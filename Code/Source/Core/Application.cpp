#include "Application.h"

// Lib �������·�����Թ���Ϊ���·�����в��ҵ�
#pragma comment(lib, "../Source/hge181/lib/vc/hge.lib")

CApplication* CApplication::m_pInstance = NULL;

CApplication::CApplication()
{
	m_pHGE      = NULL;
	m_pInstance = this;
}

CApplication::~CApplication()
{
	if (m_pHGE != NULL)
	{
		m_pHGE->Release();
		m_pHGE = NULL;
	}
}

bool CApplication::Initialize()
{
	m_startupInfo.bHideMouse  = false;
	m_startupInfo.bShowSplash = true;
	m_startupInfo.bWindowed   = true;
	m_startupInfo.nFPS        = 60;
	m_startupInfo.nWidth      = 800;
	m_startupInfo.nHeight     = 600;
	m_startupInfo.strTitle    = "�ޱ���";
	m_startupInfo.nIcon       = 0;

	if (!OnInitInstance(&m_startupInfo))
	{
		return false;
	}

	if (!InitHGE())
	{
		return false;
	}

	if (!OnInitResource())
	{
		return false;
	}

	return true;
}

bool CApplication::Start()
{
	return m_pHGE->System_Start();
}

bool CApplication::InitHGE()
{
	m_pHGE = hgeCreate(HGE_VERSION);
	if (NULL == m_pHGE)
	{
		return false;
	}

	m_pHGE->System_SetState(HGE_FRAMEFUNC, FrameFunc);							// ֡����
	m_pHGE->System_SetState(HGE_RENDERFUNC, RenderFunc);						// ��Ⱦ����
	m_pHGE->System_SetState(HGE_EXITFUNC, ExitFunc);							// �˳�����
	m_pHGE->System_SetState(HGE_WINDOWED, m_startupInfo.bWindowed);				// ����ģʽ
	m_pHGE->System_SetState(HGE_SCREENWIDTH, m_startupInfo.nWidth);				// ���ڿ��
	m_pHGE->System_SetState(HGE_SCREENHEIGHT, m_startupInfo.nHeight);			// ���ڸ߶�
	m_pHGE->System_SetState(HGE_TITLE, m_startupInfo.strTitle.c_str());			// ���ڱ���
	m_pHGE->System_SetState(HGE_HIDEMOUSE, m_startupInfo.bHideMouse);			// �������
	m_pHGE->System_SetState(HGE_SHOWSPLASH, m_startupInfo.bShowSplash);			// ����ʾ��������
	m_pHGE->System_SetState(HGE_DONTSUSPEND, true);								// ʧȥ����ʱ���򲻹���
	m_pHGE->System_SetState(HGE_FPS, m_startupInfo.nFPS);						// ������Ϸ֡Ƶ
	m_pHGE->System_SetState(HGE_ICON, MAKEINTRESOURCE(m_startupInfo.nIcon));	// ����Ӧ�ó���ͼ��

	if (!m_pHGE->System_Initiate())
	{
		MessageBox(NULL, m_pHGE->System_GetErrorMessage(), "Error", MB_OK|MB_ICONERROR|MB_APPLMODAL);
		return false;
	}

	return true;
}

bool CApplication::FrameFunc()
{
	m_pInstance->OnFrame(m_pInstance->m_pHGE->Timer_GetDelta());
	return false;
}

bool CApplication::RenderFunc()
{
	m_pInstance->OnRender();
	return false;
}

bool CApplication::ExitFunc()
{
	m_pInstance->OnExitInstance();
	return true;
}

bool CApplication::OnInitInstance(STARTUP_INFO *pInfo)
{
	return true;
}

void CApplication::OnExitInstance()
{
	m_pHGE->System_Shutdown();
}

bool CApplication::OnInitResource()
{
	return true;
}

void CApplication::OnRender()
{
	m_pHGE->Gfx_BeginScene();
	m_pHGE->Gfx_Clear(0);

	CObject::OnRender();
	m_pHGE->Gfx_EndScene();
}
