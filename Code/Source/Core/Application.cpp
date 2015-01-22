#include "Application.h"

// Lib �������·�����Թ���Ϊ���·�����в��ҵ�
#pragma comment(lib, "../Source/hge181/lib/vc/hge.lib")

CApplication* CApplication::m_pInstance = NULL;

CApplication::CApplication()
{
	m_pHGE = NULL;
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
	if (!InitHGE())
	{
		return false;
	}

	if (!InitInstance())
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

	OnSetTitle(m_strAppTitle);

	m_pHGE->System_SetState(HGE_FRAMEFUNC, FrameFunc);						// ֡����
	m_pHGE->System_SetState(HGE_RENDERFUNC, RenderFunc);					// ��Ⱦ����
	m_pHGE->System_SetState(HGE_EXITFUNC, ExitFunc);						// �˳�����
	m_pHGE->System_SetState(HGE_WINDOWED, true);							// ����ģʽ
	m_pHGE->System_SetState(HGE_SCREENWIDTH, 800);							// ���ڿ��
	m_pHGE->System_SetState(HGE_SCREENHEIGHT, 600);							// ���ڸ߶�
	m_pHGE->System_SetState(HGE_TITLE, m_strAppTitle.c_str());				// ���ڱ���
	m_pHGE->System_SetState(HGE_HIDEMOUSE, false);							// �������
//	m_pHGE->System_SetState(HGE_SHOWSPLASH, false);							// ����ʾ��������
	m_pHGE->System_SetState(HGE_DONTSUSPEND, true);							// ʧȥ����ʱ���򲻹���
	m_pHGE->System_SetState(HGE_FPS, 60);

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
	m_pInstance->ExitInstance();
	return true;
}

bool CApplication::InitInstance()
{
	return true;
}

void CApplication::OnSetTitle(std::string &strAppTitle)
{
	strAppTitle = "�ޱ���";
}

void CApplication::ExitInstance()
{
	m_pHGE->System_Shutdown();
}

void CApplication::OnRender()
{
	m_pHGE->Gfx_BeginScene();
	m_pHGE->Gfx_Clear(0);

	CObject::OnRender();
	m_pHGE->Gfx_EndScene();
}
