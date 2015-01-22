#ifndef ___TANK__20150122___
#define ___TANK__20150122___

#include "../Core/Sprite.h"
#include <vector>

namespace TANK_DIRECTION
{
	enum ETankDirection { UP, RIGHT, DOWN, LEFT };
}

class CTank : public CObject
{
public:
	CTank(const char *lpszTankImage, int x, int y, int nWidth, int nHeight);
	virtual ~CTank();

public:
	void ChangeDirection(TANK_DIRECTION::ETankDirection eDirection);

protected:
	virtual void OnFrame(float fDelta);
	virtual void OnRender();
	virtual void OnKey(int nKey);

protected:
	HTEXTURE							m_hTexture;				// ̹�˵�������������Ϊ: ̹�����ϡ�̹�����ҡ�̹�����¡�̹������
	TANK_DIRECTION::ETankDirection		m_eDirection;			// ̹��Ŀǰ�ķ���
	std::vector<CSprite *>				m_vecSprite;			// 4 �������̹�˾���
};

#endif
