#include "AASystemRED.h"

#include "AA_Camera.h"

void AASystemRED::Initialize()
{
	AA_CCamera* Cam = (AA_CCamera*)FMemory::Malloc(sizeof(AA_CCamera));
	if (Cam)
	{
		Cam->m_FOVLeftPlane.X = 0;
		Cam->m_FOVLeftPlane.Z = 0;
		Cam->m_FOVLeftPlane.W = 1;
		Cam->m_FOVRightPlane.Y = 0;
		Cam->m_FOVRightPlane.W = 1;
		Cam->m_FOVTopPlane.Y = 0;
		Cam->m_FOVTopPlane.W = 1;
		Cam->m_FOVBottomPlane.Y = 0;
		Cam->m_FOVBottomPlane.W = 1;
		Cam->m_BasePos.X = 0;
		Cam->m_Pos.X = 0;
		Cam->m_BasePos.Z = 0;
		Cam->m_Pos.Z = 0;
		Cam->m_BaseAt.X = 0;
		Cam->m_At.X = 0;
		Cam->m_BaseAt.Z = 1;
		Cam->m_At.Z = 1;
		Cam->m_BaseAt.Y = 1;
		Cam->m_At.Y = 1;
		Cam->m_FOV = 1.5707964;
		Cam->m_FrontClip = 3;
		Cam->m_BackClip = 5000;
	}
	m_CameraManager.m_Instances[m_CameraManager.m_InstancesNum++] = Cam;
}

void AASystemRED::StaticInitialize()
{
	if (!GAASystemRed)
	{
		AASystemRED* inst = (AASystemRED*)FMemory::Malloc(sizeof(AASystemRED));
		if (inst)
		{
			inst->m_bInitialized = false;
			inst->m_CameraManager.m_InstancesNum = 0;
			memset(inst->m_CameraManager.m_Instances, 0, sizeof(inst->m_CameraManager.m_Instances));
		}
		inst->Initialize();
		GAASystemRed = inst;
	}
}
