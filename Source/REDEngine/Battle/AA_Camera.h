#pragma once

struct AA_Matrix : FMatrix {};
struct AA_Vector3 : FVector4 {};
struct AA_Vector4 : FVector {};

class AA_CCamera
{
public:
	__declspec(align(16)) AA_Matrix m_ViewMatrix;
	AA_Matrix m_ProjMatrix;
	AA_Matrix m_ViewProjMatrix;
	AA_Matrix m_InvViewProjMatrix;
	AA_Vector4 m_FOVLeftPlane;
	AA_Vector4 m_FOVRightPlane;
	AA_Vector4 m_FOVTopPlane;
	AA_Vector4 m_FOVBottomPlane;
	AA_Matrix m_ViewProjMatrixFinal;
	AA_Vector3 m_Pos;
	AA_Vector3 m_Up;
	AA_Vector3 m_At;
	AA_Vector3 m_BasePos;
	AA_Vector3 m_BaseUp;
	AA_Vector3 m_BaseAt;
	float m_FOV;
	float m_FrontClip;
	float m_BackClip;
	float m_AspectRatio;
};
