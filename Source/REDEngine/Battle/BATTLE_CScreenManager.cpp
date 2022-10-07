#include "BATTLE_CScreenManager.h"

#include "Constants.h"
#include "OBJ_CCharBase.h"

BATTLE_CScreenManager::BATTLE_CScreenManager()
{
  m_hLinkCamera.value = 0;
  m_ScreenCameraControl.m_Target.X = 0;
  m_ScreenCameraControl.m_Target.Z = 1;
  m_ScreenCameraControl.m_Param.Y = 0.0;
  m_ScreenCameraControl.m_Param.Z = 1;
  m_ScreenCameraControl.m_Vel.Y = 0;
  m_ScreenCameraControl.m_Hold = 10;
  m_ScreenCameraControl.m_FixZ = 1;
  m_ScreenCameraControl.m_Level = 1;
  m_ScreenCameraControl.m_Friction = 1;
  m_ObjBox.left = 0;
  m_ObjBox.right = 0;
  m_ObjBox.higherBottom = 0;
  m_ObjLeft = 0;
  m_ObjTop = 0;
  m_ObjLenX = 0;
  m_ScreenWorldCenterX = 0;
  m_ScreenWorldLeft = 0;
  m_TargetCenterX = 0;
  m_TargetWidth = 1280;
  m_VelCenterY = 0;
  m_SetPosX = 0;
  m_SetPosW = 0;
  m_ObjectScale = 0;
  m_ScreenY = 0;
  m_ScreenXLeft = 0;
  m_MoveX = 0;
  m_LinkMagn = 1.0;
  m_LinkMagnRecip = 1;
  m_TargetOffsetAirYMax = 180;
  m_TargetOffsetAirYAdd = 3;
  m_TargetOffsetAirYPos = 400;
  m_TargetOffsetAirYDist = 570;
  m_TargetOffsetLandYMax = 350;
  m_TargetOffsetLandYAdd = 6;
  m_TargetOffsetY = 350;
  m_ZoomMoveY = 0.0;
  m_ZoomOutBeginDistX = 1280;
  m_ZoomOutBeginDistY = 600;
  m_MaxZoomOutWidth = 1536;
  m_bTouchWorldSide = 0;
  m_ScreenWorldWidth = 1280;
  m_ShakeX = 0;
  m_ShakeTime = 0;
  m_ScreenCenterXNoShake = 0;
  m_ScreenCollisionRight = 0;
  m_LastFlag = 0;
  m_Stable = 0;
  m_pCamera = 0;
  m_WorldLeftSide = -1600;
  m_WorldRightSide = 1600;
  m_WorldTopSide = 5400;
  m_ppObject[0] = 0;
  m_ppObject[1] = 0;
  m_ppObject[2] = 0;
  m_ppObject[3] = 0;
  m_ppObject[4] = 0;
  m_ppObject[5] = 0;
  m_TargetObjectNum = 0;
  m_WorldSideMoveValue = 0;
  m_WorldSideMoveDir = 0;
  m_WorldSideMoveDeg = 0.0;
  m_OffsetMatrix.M[0][0] = 1;
  m_OffsetMatrix.M[1][0] = 0.0;
  m_OffsetMatrix.M[1][1] = 1;
  m_OffsetMatrix.M[2][1] = 0.0;
  m_OffsetMatrix.M[2][2] = 1;
  m_OffsetMatrix.M[3][0] = 0;
  m_OffsetMatrix.M[3][2] = 0.0;
  m_OffsetMatrix.M[3][3] = 1.0;
  m_PrevCameraMatrix.M[0][0] = 1;
  m_PrevCameraMatrix.M[1][0] = 0.0;
  m_PrevCameraMatrix.M[1][1] = 1;
  m_PrevCameraMatrix.M[2][1] = 0.0;
  m_PrevCameraMatrix.M[2][2] = 1;
  m_PrevCameraMatrix.M[3][0] = 0;
  m_PrevCameraMatrix.M[3][2] = 0.0;
  m_PrevCameraMatrix.M[3][3] = 1.0;
}

void BATTLE_CScreenManager::UpdateScreenPosition(bool bQuick)
{
  int v2 = 1280;
  m_MaxZoomOutWidth = 1536;
  m_ZoomOutBeginDistX = 1280;
  m_ZoomOutBeginDistY = 600;
  if (DBM_VAL_CONST_TABLE[DBM_CameraBehavior] == 1)
  {
    m_MaxZoomOutWidth = 1689;
    m_ZoomOutBeginDistX = 1280;
  }
  else
  {
    m_MaxZoomOutWidth = m_MaxZoomOutWidth * DBM_VAL_CONST_TABLE[DBM_ScreenZoomSizeScale] / 1000;
    m_ZoomOutBeginDistY = m_ZoomOutBeginDistY * DBM_VAL_CONST_TABLE[DBM_ScreenZoomStartDistYScale] / 1000;
    m_ZoomOutBeginDistX = m_ZoomOutBeginDistX * DBM_VAL_CONST_TABLE[DBM_ScreenZoomStartDistXScale] / 1000;
  }
  if (m_bStopScreenPositionUpdate)
    return;
  
}

void BATTLE_CScreenManager::SetScreenCornerObject(bool bQuick)
{
  if (!m_TargetObjectNum)
  {
    
  }
  for (int i = 0; i < m_TargetObjectNum; i++)
  {
    OBJ_CBase* v7 = m_ppObject[i];
    OBJ_CBase** v8 = &m_ppObject[i];
    char v9 = m_TargetObjectFlag[i] & 1;
    if (!v7)
    {
      
    }
    if (v9)
    {
      //if (v7.IsDead())
      v7 = *v8;
      OBJ_CCharBase* m_Ptr = (OBJ_CCharBase *)(*v8)->m_pParentPly.m_Ptr;
      if ( !m_Ptr->m_EntryBattleDoing )
      {
      }
      if ( !m_Ptr->m_EntryBattle || !m_Ptr->m_Entry )
      {
        
      }
    }
    
  }
}
