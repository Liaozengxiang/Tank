#ifndef ___MOVEABLE__20150123___
#define ___MOVEABLE__20150123___

#include "Object.h"

class CMoveable : public CObject
{
public:
	enum EDirection	{ UP, RIGHT, DOWN, LEFT };

public:
	CMoveable(int nSpeed, EDirection eDirection, const RECT *pMoveableRect);
	virtual ~CMoveable();

public:
	void AcceptDirection(EDirection eDirection);

protected:
	int					m_nSpeed;						// ÿ�ΰ����˶�������
	EDirection			m_eDirection;					// ��ǰ�˶��ķ���
	RECT				m_moveableRect;
};

#endif
