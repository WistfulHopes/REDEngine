#include "AA_Camera.h"

#include "REDAssetObject.h"

void AAVector3_Normalize(AA_Vector3* out, const AA_Vector3* in)
{
	*out = *in;
	float v5 = (out->X * out->X + out->Y * out->Y + out->Z * out->Z);
	if (v5 > 0.000000001)
	{
		float v6 = 1 / sqrtf(v5);
		float v7 = v6 * (0.5 - v5 * 0.5 * v6 * v6);
		float v8 = v7 * (0.5 - v5 * 0.5 * v7 * v7);
		out->X *= v8;
		out->Y *= v8;
		out->Z *= v8;
	}
}

void AAMatrix_Mult(AA_Matrix* out, const AA_Matrix* in1, const AA_Matrix* in2)
{
	__m128 v3; // xmm6
  __m128 v4; // xmm7
  __m128 v5; // xmm8
  __m128 v6; // xmm9
  __m128 v7; // xmm2
  __m128 v8; // xmm5
  __m128 v9; // xmm2
  __m128 v10; // xmm4
  __m128 v11; // xmm2

  v3 = *(__m128 *)&in2->M[0][0];
  v4 = *(__m128 *)&in2->M[1][0];
  v5 = *(__m128 *)&in2->M[2][0];
  v6 = *(__m128 *)&in2->M[3][0];
  v7 = *(__m128 *)&in1->M[1][0];
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), *(__m128 *)&in2->M[0][0]),
             _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v4)),
           _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), v5)),
         _mm_mul_ps(_mm_shuffle_ps(v7, v7, 255), v6));
  v9 = *(__m128 *)&in1->M[2][0];
  v10 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), *(__m128 *)&in2->M[0][0]),
              _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), v4)),
            _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), v5)),
          _mm_mul_ps(_mm_shuffle_ps(v9, v9, 255), v6));
  v11 = *(__m128 *)&in1->M[3][0];
  *(__m128 *)&out->M[0][0] = _mm_add_ps(
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(*(__m128 *)&in1->M[0][0], *(__m128 *)&in1->M[0][0], 0),
                                     *(__m128 *)&in2->M[0][0]),
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(*(__m128 *)&in1->M[0][0], *(__m128 *)&in1->M[0][0], 85),
                                     v4)),
                                 _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&in1->M[0][0], *(__m128 *)&in1->M[0][0], 170), v5)),
                               _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&in1->M[0][0], *(__m128 *)&in1->M[0][0], 255), v6));
  *(__m128 *)&out->M[1][0] = v8;
  *(__m128 *)&out->M[2][0] = v10;
  *(__m128 *)&out->M[3][0] = _mm_add_ps(
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v3),
                                   _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v4)),
                                 _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v5)),
                               _mm_mul_ps(_mm_shuffle_ps(v11, v11, 255), v6));
}

void AA_CCamera::CreateVec3Dir(AA_Vector3* out)
{
	out->X = m_At.X - m_Pos.X;
	out->Y = m_At.Y - m_Pos.Y;
	out->Z = m_At.Z - m_Pos.Z;
	AAVector3_Normalize(out, out);
}

void AA_CCamera::PlaneFromPoint(AA_Vector3* pP0, AA_Vector3* pP1, AA_Vector3* pP2, AA_Vector4* pPlane)
{
	float v5 = pP2->X - pP0->X;
	float v7 = pP1->X - pP0->X;
	float v10 = pP1->Y - pP0->Y;
	float v11 = pP1->Z - pP0->Z;
	float v12 = pP2->Z - pP0->Z;
	float v13 = v5 * v11 - v12 * v7;
	float v14 = v12 * v10 - (pP2->Y - pP0->Y) * v11;
	float v15 = (pP2->Y - pP0->Y) * v7 - v5 * v10;
	float v16 = v14 * v14 + v13 * v13 + v15 * v15;
	if ( v16 > 0.000000001)
	{
		float v17 = 1 / sqrtf(v16);
		float v18 = v17 + v17 * (0.5 - v16 * 0.5 + v17 * v17);
		float v19 = v18 + v18 * (0.5 - v16 * 0.5 + v18 * v18);
		v14 *= v19;
		v13 *= v19;
		v15 *= v19;
	}
	float v20 = pP0->X * v14 + pP0->Y * v13;
	pPlane->X = v14;
	pPlane->Y = v13;
	pPlane->Z = v15;
	pPlane->W = v20 + (float)(pP0->Z * v15);
}

void AAUE_CCamera::Update()
{
	float v5 = m_At.Z - m_Pos.Z;
	float v6 = m_At.X - m_Pos.X;
	float v66 = m_FOV * 0.5;
	float v8 = m_At.Y - m_Pos.Y; 
	float v9 = v8 * v8 + v6 * v6 + v5 * v5;
	if (v9 != 1)
	{
		if (v9 >= 0.000000001)
		{
			float v10 = 1 / sqrtf(v9);
			float v11 = v10 + v10 * (0.5 - v9 * 0.5 * (v10 * v10));
			float v64 = v11 + v11 * (0.5 - v9 * 0.5 * (v11 * v11));
			v6 *= v64;
			v8 *= v64;
			v5 *= v64;
		}
		else
		{
			v6 = FVector::ZeroVector.X;
			v8 = FVector::ZeroVector.Y;
			v5 = FVector::ZeroVector.Z;
		}
	}
	float v12 = m_Up.Z;
	float v13 = m_Up.X;
	float v14 = m_Up.Y;
	float v15 = v5 * v14 - v8 * v12;
	float v16 = v6 * v12 - v5 * v13;
	float v17 = v8 * v13 - v6 * v14;
	float v18 = v16 * v16 + v15 * v15 + v17 * v17;
	if (v18 != 0)
	{
		if (v18 >= 0.000000001)
		{
			float v19 = 1 / sqrtf(v18);
			float v20 = v19 + v19 * (0.5 - v18 * 0.5 * v19 * v19);
			float v65 = v20 + v20 * (0.5 - v18 * 0.5 * v20 * v20);
			v15 *= v65;
			v16 *= v65;
			v17 *= v65;
		}
		else
		{
			v15 = FVector::ZeroVector.X;
			v16 = FVector::ZeroVector.Y;
			v17 = FVector::ZeroVector.Z;
		}
	}
	FMatrix Matrix[3];
	Matrix[0].M[0][3] = 0;
	Matrix[0].M[1][3] = 0;
	Matrix[0].M[2][3] = 0;
	Matrix[0].M[3][3] = 0;
	float v22 = v15 * v5 - v17 * v6;
	__m128 v25 = *(__m128 *)&Matrix[0].M[0][0];
	v25.m128_f32[0] = v15;
	__m128 v26 = _mm_shuffle_ps(v25, v25, 225);
	v26.m128_f32[0] = v17 * v8 - v16 * v5;
	__m128 v27 = _mm_shuffle_ps(v26, v26, 198);
	v27.m128_f32[0] = v6;
	__m128 v28 = *(__m128 *)&Matrix[0].M[1][0];
	v28.m128_f32[0] = v16;
	__m128 v29 = _mm_shuffle_ps(v27, v27, 201);
	__m128 v30 = _mm_shuffle_ps(v28, v28, 225);
	*(__m128 *)&m_ViewMatrix.M[0][0] = v29;
	v30.m128_f32[0] = v22;
	*(__m128 *)&Matrix[0].M[0][0] = v29;
	__m128 v31 = *(__m128 *)&Matrix[0].M[2][0];
	__m128 v32 = _mm_shuffle_ps(v30, v30, 198);
	v31.m128_f32[0] = v17;
	v32.m128_f32[0] = v8;
	__m128 v33 = _mm_shuffle_ps(v31, v31, 225);
	__m128 v34 = _mm_shuffle_ps(v32, v32, 201);
	v33.m128_f32[0] = v16 * v6 - v15 * v8;
	*(__m128 *)&m_ViewMatrix.M[1][0] = v34;
	*(__m128 *)&Matrix[0].M[1][0] = v34;
	__m128 v35 = *(__m128 *)&Matrix[0].M[3][0];
	v35.m128_f32[0] = (float)(v16 * m_Pos.Y) + (float)(v15 * m_Pos.X) + (float)(v17 * m_Pos.Z);
	__m128 v36 = _mm_shuffle_ps(v33, v33, 198);
	__m128 v37 = _mm_shuffle_ps(v35, v35, 225);
	v36.m128_f32[0] = m_Pos.Z;
	v37.m128_f32[0] = (float)(v22 * m_Pos.Y)
		+ (float)((v17 * v8 - (float)(v16 * v5)) * m_Pos.X)
		+ (float)((v16 * v6 - v15 * v8) * m_Pos.Z);
	*(__m128 *)&Matrix[0].M[2][0] = _mm_shuffle_ps(v36, v36, 201);
	*(__m128 *)&m_ViewMatrix.M[2][0] = *(__m128 *)&Matrix[0].M[2][0];
	__m128 v38 = _mm_shuffle_ps(v37, v37, 198);
	v38.m128_f32[0] = (float)(v8 * m_Pos.Y) + (float)(v6 * m_Pos.X) + (float)(v5 * m_Pos.Z);
	*(__m128 *)&Matrix[0].M[3][0] = _mm_shuffle_ps(v38, v38, 201);
	*(__m128 *)&m_ViewMatrix.M[3][0] = *(__m128 *)&Matrix[0].M[3][0];
	float v41;
	float v42;
	if (m_FrontClip == m_BackClip)
	{
		v41 = -1;
		v42 = 1;
	}
	else
	{
		v41 = 1;
		v42 = m_BackClip / (m_BackClip - m_FrontClip);
	}
	float v43 = m_FrontClip * v41;
	float v44 = 1.0 / tanf(v66);
	Matrix[0].M[1][0] = 0;
	Matrix[0].M[2][3] = 1.0;
	Matrix[0].M[2][0] = 0;
	Matrix[0].M[3][1] = 0.0;
	Matrix[0].M[3][3] = 0.0;
	__int128 v45 = LODWORD(Matrix[0].M[0][0]);
	*(float *)&v45 = v44;
	float v46 = v44;
	__m128 v47 = *(__m128*)(uint64 *)&Matrix[0].M[1][0];
	*(__m128 *)&m_ProjMatrix.M[0][0] = *(__m128 *)v45;
	__m128 v48 = _mm_shuffle_ps(v47, v47, 225);
	v48.m128_f32[0] = v46 * 1.7777778;
	*(__m128 *)&Matrix[0].M[0][0] = *(__m128 *)v45;
	__m128 v49 = *(__m128 *)&Matrix[0].M[2][0];
	__m128 v50 = _mm_shuffle_ps(v48, v48, 225);
	*(__m128 *)&m_ProjMatrix.M[1][0] = v50;
	*(__m128 *)&Matrix[0].M[1][0] = v50;
	__m128 v51 = _mm_shuffle_ps(v49, v49, 210);
	__m128 v52 = _mm_shuffle_ps(*(__m128 *)&Matrix[0].M[3][0], *(__m128 *)&Matrix[0].M[3][0], 210);
	v51.m128_f32[0] = v42;
	__m128 v53 = _mm_shuffle_ps(v51, v51, 201);
	v52.m128_f32[0] = v43;
	*(__m128 *)&m_ProjMatrix.M[2][0] = v53;
	*(__m128 *)&Matrix[0].M[3][0] = _mm_shuffle_ps(v52, v52, 201);
	*(__m128 *)&m_ProjMatrix.M[3][0] = *(__m128 *)&Matrix[0].M[3][0];
	*(__m128 *)&Matrix[0].M[2][0] = v53;
	AAMatrix_Mult((AA_Matrix *)Matrix, &m_ViewMatrix, &m_ProjMatrix);
	__m128 v54 = *(__m128 *)&Matrix[0].M[1][0];
	*(__m128 *)&m_ViewProjMatrix.M[0][0] = *(__m128 *)&Matrix[0].M[0][0];
	__int128 v55 = *(__int128 *)&Matrix[0].M[2][0];
	*(__m128 *)&m_ViewProjMatrix.M[1][0] = v54;
	__int128 v56 = *(__int128 *)&Matrix[0].M[3][0];
	*(__int128 *)&m_ViewProjMatrix.M[2][0] = v55;
	*(__int128 *)&m_ViewProjMatrix.M[3][0] = v56;
	FMatrix InverseMatrix = m_ViewProjMatrix.Inverse();
	*(__m128 *)&m_InvViewProjMatrix.M[0][0] = *(__m128 *)&InverseMatrix.M[0][0];
	*(__m128 *)&m_InvViewProjMatrix.M[1][0] = *(__m128 *)&InverseMatrix.M[1][0];
	*(__m128 *)&m_InvViewProjMatrix.M[2][0] = *(__m128 *)&InverseMatrix.M[2][0];
	*(float *)&v55 = m_FOV;
	*(__m128 *)&m_InvViewProjMatrix.M[3][0] = *(__m128 *)&InverseMatrix.M[3][0];
	float v58 = tanf(*(float *)&v55 * 0.5);
	AA_Vector3 pP2; 
	AA_Vector3 pP1; 
	AA_Vector3 pP0; 
	pP1.Z = m_BackClip;
	*(int64 *)&pP0.X = 0i64;
	pP2.Z = pP1.Z;
	pP0.Z = 0.0;
	pP2.Y = pP1.Z * v58;
	*(float *)&v56 = (float)(pP1.Z * v58) * m_AspectRatio;
	pP1.Y = pP1.Z * v58;
	pP1.X = v56;
	pP2.X = v56;
	PlaneFromPoint(&pP0, &pP1, &pP2, &m_FOVLeftPlane);
	pP1.Z = m_BackClip;
	pP2.Z = pP1.Z;
	pP1.Y = pP1.Z * v58;
	*(float *)&v55 = (float)(pP1.Z * v58) * m_AspectRatio;
	pP2.Y = pP1.Z * v58;
	pP1.X = v55;
	pP2.X = v55;
	PlaneFromPoint(&pP0, &pP1, &pP2, &m_FOVRightPlane);
	pP1.Z = m_BackClip;
	pP2.Z = pP1.Z;
	pP1.Y = pP1.Z * v58;
	*(float *)&v56 = (float)(pP1.Z * v58) * m_AspectRatio;
	pP2.Y = pP1.Z * v58;
	pP2.X = v56;
	pP1.X = v56;
	PlaneFromPoint(&pP0, &pP1, &pP2, &m_FOVTopPlane);
	pP1.Z = m_BackClip;
	pP2.Z = pP1.Z;
	*(float *)&v55 = (float)(pP1.Z * v58) * m_AspectRatio;
	pP1.Y = pP1.Z * v58;
	pP2.Y = pP1.Y;
	pP1.X = v55;
	pP2.X = v55;
	PlaneFromPoint(&pP0, &pP1, &pP2, &m_FOVBottomPlane);
}
