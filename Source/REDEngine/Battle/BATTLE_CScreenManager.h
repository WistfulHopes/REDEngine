#pragma once
#include "OBJ_CBase.h"
#include "AA_Camera.h"

struct BATTLE_ScreenCameraControl
{
	AA_Vector3 m_Target;
	AA_Vector3 m_Param;
	AA_Vector3 m_Vel;
	bool m_Hold;
	bool m_Repeat;
	bool m_FixX;
	bool m_FixY;
	bool m_FixZ;
	unsigned int m_Level;
	float m_Friction;
	unsigned int m_Flag;

	bool Update();
};

class BATTLE_CScreenManager
{
public:
	struct OBJ_BOX
	{
		int left;
		int top;
		int right;
		int bottom;
		int higherBottom;
	};
	BATTLE_CScreenManager();
	
	OBJ_CBase *m_ppObject[6];
	unsigned int m_TargetObjectFlag[6];
	unsigned int m_TargetObjectNum;
	AA_CCamera *m_pCamera;
	int m_ObjLeft;
	int m_ObjRight;
	int m_ObjTop;
	int m_ObjBottom;
	int m_ObjLenX;
	int m_ObjLenY;
	int m_ZoomOutBeginDistX;
	int m_ZoomOutBeginDistY;
	int m_MaxZoomOutWidth;
	int m_TargetOffsetY;
	int m_TargetOffsetAirYMax;
	int m_TargetOffsetAirYAdd;
	int m_TargetOffsetAirYPos;
	int m_TargetOffsetAirYDist;
	int m_WidthY;
	int m_TargetOffsetLandYMax;
	int m_TargetOffsetLandYAdd;
	int m_ScreenWorldLeft;
	int m_ScreenWorldRight;
	int m_ScreenWorldCenterX;
	int m_ScreenWorldCenterY;
	int m_ScreenWorldWidth;
	int m_TargetCenterX;
	int m_TargetCenterY;
	int m_TargetWidth;
	int m_VelCenterX;
	int m_VelCenterY;
	int m_VelWidth;
	int m_SetPosX;
	int m_SetPosY;
	int m_SetPosW;
	int m_DelayW;
	unsigned int m_ObjectScale;
	int m_ScreenX;
	int m_ScreenY;
	int m_ScreenW;
	int m_ScreenXLeft;
	int m_ScreenYUp;
	int m_MoveX;
	int m_MoveY;
	float m_ZoomMoveY;
	AA_Handle m_hLinkCamera;
	float m_LinkMagn;
	float m_LinkMagnRecip;
	unsigned int m_Flag;
	unsigned int m_LastFlag;
	float m_ShakeX;
	float m_ShakeY;
	int m_ShakeTime;
	int m_ScreenCollisionLeft;
	int m_ScreenCollisionRight;
	int m_ScreenCollisionYUp;
	int m_ScreenCenterXNoShake;
	int m_ScreenCenterYNoShake;
	int m_WorldLeftSide;
	int m_WorldRightSide;
	int m_WorldTopSide;
	BATTLE_ScreenCameraControl m_ScreenCameraControl;
	unsigned int m_FilterControl;
	bool m_Stable;
	bool m_bStopScreenPositionUpdate;
	bool m_bStopZoomCamera;
	bool m_bTouchWorldSide;
	int m_WorldSideMoveValue;
	int m_WorldSideMoveValuePrev;
	int m_WorldSideMoveDir;
	int m_WorldSideMoveResetDir;
	float m_WorldSideMoveDeg;
	FMatrix m_OffsetMatrix;
	FMatrix m_PrevCameraMatrix;
	OBJ_BOX m_ObjBox;

	void ResetScreenManager();
	void UpdateScreenPosition(bool bQuick);
	void SetScreenCornerObject(bool bQuick);
	void LinkCameraMove();
};
