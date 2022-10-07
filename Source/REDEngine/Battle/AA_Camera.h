#pragma once

struct AA_Matrix : FMatrix {};
struct AA_Vector3 : FVector {};
struct AA_Vector4 : FVector4 {};

void AAVector3_Normalize(AA_Vector3* out, const AA_Vector3* in);
void AAMatrix_Mult(AA_Matrix *out, const AA_Matrix *in1, const AA_Matrix *in2);

class AA_CCamera
{
public:
	virtual ~AA_CCamera() = default;
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

	void CreateVec3Dir(AA_Vector3* out);
	void PlaneFromPoint(AA_Vector3* pP0, AA_Vector3* pP1, AA_Vector3* pP2, AA_Vector4* pPlane);
	virtual void Update() = 0;
};

class AAUE_CCamera : public AA_CCamera
{
	virtual void Update() override;
};