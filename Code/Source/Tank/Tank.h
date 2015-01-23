#ifndef ___TANK__20150122___
#define ___TANK__20150122___

#include "../Core/Sprite.h"
#include "../Core/Moveable.h"
#include "../Bullet/Bullet.h"
#include <vector>

class CTank : public CMoveable
{
public:
	CTank(const char *lpszTankImage, int x, int y, int nWidth, int nHeight, int nSpeed, const RECT *pMoveableRect);
	virtual ~CTank();

protected:
	virtual void OnFrame(float fDelta);
	virtual void OnRender();
	virtual void OnKey(int nKey);

protected:
	HTEXTURE							m_hTexture;				// ̹�˵��������д�������Ϊ: ̹�����ϡ�̹�����ҡ�̹�����¡�̹������
	std::vector<CSprite *>				m_vecSprite[2];			// 4 �������̹�˾���
	int									m_nShowIndex;			// ��ǰ��ʾ���ǵڼ��飬�� 0-1 �任
	CBullet*							m_pBullets[2];
};

#endif
