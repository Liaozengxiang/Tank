#include <windows.h>
#include "../hge181/include/hge.h"

// Lib �������·�����Թ���Ϊ���·�����в��ҵ�
#pragma comment(lib, "../Source/hge181/lib/vc/hge.lib")

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	HGE *pHGE = hgeCreate(HGE_VERSION);

	return 0;
}
