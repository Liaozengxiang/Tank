#ifndef ___FLYABLE__20150123___
#define ___FLYABLE__20150123___

#include "Object.h"

class CFlyable : public CObject
{
public:
	enum EDirection	{ UP, RIGHT, DOWN, LEFT };
	
public:
	CFlyable(int nSpeed, EDirection eDirection, const RECT *pFlyableRect);
	virtual ~CFlyable();
	
public:
	void SetDirection(EDirection eDirection);
	
public:
	virtual void OnFrame(float fDelta);
	
protected:
	int					m_nSpeed;						// ÿ���˶������ʣ���λΪ pixel/s
	EDirection			m_eDirection;					// ��ǰ�˶��ķ���
	RECT				m_flyableRect;
};

#endif
