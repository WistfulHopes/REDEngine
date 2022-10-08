#pragma once
#include "AA_ManagerBase.h"

class AASystemRED
{
public:
	bool m_bInitialized;
	AA_CCameraManager m_CameraManager;

	void Initialize();
	static void StaticInitialize();
};

inline AASystemRED* GAASystemRed;