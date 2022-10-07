#pragma once

class AA_CCamera;

template <typename T, int i>
class AA_ManagerBase
{
public:
	T* m_Instances[16];
	unsigned int m_InstancesNum;
};

class AA_CCameraManager : public AA_ManagerBase<AA_CCamera,16>
{
};
