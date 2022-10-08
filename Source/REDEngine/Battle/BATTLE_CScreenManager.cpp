#include "BATTLE_CScreenManager.h"

#include "AASystemRED.h"
#include "Constants.h"
#include "OBJ_CCharBase.h"
#include "REDEngine/GameState/REDGameState_Battle.h"
#include "REDEngine/red/btl.h"

bool BATTLE_ScreenCameraControl::Update()
{
  AREDGameState_Battle* GameState = Cast<AREDGameState_Battle>(GWorld->GetGameState());
  BATTLE_CScreenManager* ScreenManager = GameState->ScreenManager.Get();
  float X;
  float Y;
  float Z = ScreenManager->m_ScreenWorldWidth * 0.00078125;
  if (m_Hold)
  {
    X = m_Target.X;
    Y = m_Target.Y;
    Z = m_Target.Z;
    m_FixX = false;
    m_FixZ = false;
  }
  else
  {
    X = ScreenManager->m_ScreenWorldCenterX * ScreenManager->m_LinkMagn;
    Y = ScreenManager->m_ScreenWorldCenterY * ScreenManager->m_LinkMagn + Z * 135;
  }
  float v28 = m_Param.X;
  float v29 = m_Param.Z;
  int level;
  if (m_Hold)
    level = m_Level;
  else
    level = 30;
  float v14 = 1 / level;
  m_Vel.X += (X - m_Param.X) * v14;
  m_Vel.Y += (Y - m_Param.Y) * v14;
  m_Vel.Z += (Z - m_Param.Z) * v14;
  m_Param.X += m_Vel.X;
  m_Param.Y += m_Vel.Y;
  m_Param.Z += m_Vel.Z;
  m_Vel.X *= 0.75;
  m_Vel.Y *= 0.75;
  m_Vel.Z *= 0.75;
  bool v20 = X < v28;
  if (X > v28)
  {
    if (X < m_Param.X)
    {
      m_Param.X = X;
      m_Vel.X = 0;
    }
    else
    {
      v20 = X < v28;
      if (v20 && X >= m_Param.X || m_FixX)
      {
        m_Param.X = X;
        m_Vel.X = 0;
      }
    }
  }
  else
  {
    if (v20 && X >= m_Param.X || m_FixX)
    {
      m_Param.X = X;
      m_Vel.X = 0;
    }
  }
  float p_Y = m_Param.Y;
  int v22 = Y < v28 + 1;
  int V23;
  if (Y > v22)
  {
    if (Y < p_Y)
    {
      V23 = p_Y = Y;
      m_Vel.Y = 0;
    }
    else
    {
      v22 = Y < v28 + 1;
      if (v22 && Y > p_Y)
      {
        p_Y = Y;
        m_Vel.Y = 0;
      }
      V23 = p_Y;
      if (Y == p_Y || m_FixY)
      {
        V23 = p_Y = Y;
        m_Vel.Y = 0;
      }
    }
  }
  else
  {
    if (v22 && Y > p_Y)
    {
      p_Y = Y;
      m_Vel.Y = 0;
    }
    V23 = p_Y;
    if (Y == p_Y || m_FixY)
    {
      V23 = p_Y = Y;
      m_Vel.Y = 0;
    }
  }
  int v25;
  int v26;
  float p_Z = m_Param.Z;
  if ( Z > v29 && Z < p_Z || (v25 = V23, Z < v29) && Z > p_Z || (v26 = p_Z, Z == p_Z) || m_FixZ )
  {
    v25 = V23;
    m_Vel.Z = 0.0;
    v26 = Z;
  }
  if (!m_Hold)
  {
    if (X == m_Param.X)
    {
      m_FixX = true;
    }
    if (Y == v25)
    {
      m_FixY = true;
    }
    if (Y == v26)
    {
      m_FixZ = true;
    }
  }
  if (!m_Repeat)
    m_Hold = false;
  return m_FixX && m_FixY && m_FixZ;
}

BATTLE_CScreenManager::BATTLE_CScreenManager()
{
  m_hLinkCamera.value = 0;
  m_ScreenCameraControl.m_Target.X = 0;
  m_ScreenCameraControl.m_Target.Z = 1;
  m_ScreenCameraControl.m_Param.Y = 0.0;
  m_ScreenCameraControl.m_Param.Z = 1;
  m_ScreenCameraControl.m_Vel.Y = 0;
  m_ScreenCameraControl.m_Hold = true;
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

void BATTLE_CScreenManager::ResetScreenManager()
{
  if (GAASystemRed->m_CameraManager.m_Instances[0])
  {
    m_pCamera = GAASystemRed->m_CameraManager.m_Instances[0];
    m_pCamera->m_FOV = 1.134464;
    m_pCamera->m_BackClip = -50000.0;
    m_pCamera->m_BasePos.X = 0.0;
    m_pCamera->m_Pos.X = 0.0;
    m_pCamera->m_BasePos.Y = 135.0;
    m_pCamera->m_Pos.Y = 135.0;
    m_pCamera->m_BasePos.Z = 460.0;
    m_pCamera->m_Pos.Z = 460.0;
    m_pCamera->m_BaseAt.X = 0.0;
    m_pCamera->m_At.X = 0.0;
    m_pCamera->m_BaseAt.Y = 135;
    m_pCamera->m_At.Y = 135;
    m_pCamera->m_AspectRatio = 1.7777778;
  }
  AA_Vector3 pos0;
  AA_Vector3 pos1;
  pos0.X = 1;
  pos1.Y = 1;
  pos0.Z = 0;
  if (m_pCamera)
  {
    m_pCamera->Update();
    m_LinkMagn = CalcBattleCameraLinkMagn(m_pCamera, &pos0, &pos1);
    m_LinkMagnRecip = 1.0 / m_LinkMagn;
  }
  m_bStopScreenPositionUpdate = false;
  m_ScreenCenterXNoShake = 0;
  m_TargetCenterX = 0;
  m_ScreenWorldCenterX = 0;
  m_TargetWidth = 1280;
  m_ScreenWorldWidth = 1280;
  m_VelCenterY = 0;
  m_DelayW = 0;
  m_ShakeTime = 0;
  m_ScreenX = 0;
  m_ScreenW = 1280;
  m_ScreenCameraControl.m_Target.X = 0;
  m_ScreenCameraControl.m_Target.Z = 1;
  m_ScreenCameraControl.m_Target.Y = 0;
  m_ScreenCameraControl.m_Param.Z = 1;
  m_ScreenCameraControl.m_Vel.Y = 0;
  m_ScreenCameraControl.m_Hold = false;
  m_ScreenCameraControl.m_FixZ = true;
  m_ScreenCameraControl.m_Level = 1;
  m_ScreenCameraControl.m_Friction = 1;
  if (m_pCamera)
  {
    m_pCamera->m_Pos.X = m_pCamera->m_BasePos.X;
    m_pCamera->m_Pos.Y = m_pCamera->m_BasePos.Y;
    m_pCamera->m_Pos.Z = m_pCamera->m_BasePos.Z;
    m_pCamera->m_At.X = m_pCamera->m_BaseAt.X;
    m_pCamera->m_At.Y = m_pCamera->m_BaseAt.Y;
    m_pCamera->m_At.Z = m_pCamera->m_BaseAt.Z;
    m_pCamera->m_Up.X = m_pCamera->m_BaseUp.X;
    m_pCamera->m_Up.Y = m_pCamera->m_BaseUp.Y;
    m_pCamera->m_Up.Z = m_pCamera->m_BaseUp.Z;
    m_pCamera->Update();
  }
  m_WorldLeftSide = -1600;
  m_WorldRightSide = 1600;
  m_WorldTopSide = 5400;
  m_Flag = 0;
}

void BATTLE_CScreenManager::UpdateScreenPosition(bool bQuick)
{
  int v2 = 1280;
  m_MaxZoomOutWidth = 1536;
  m_ZoomOutBeginDistX = 1280;
  m_ZoomOutBeginDistY = 600;
  if constexpr (DBM_VAL_CONST_TABLE[DBM_CameraBehavior] == 1)
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
  SetScreenCornerObject(bQuick);
  bool v8 = (m_Flag & 1) == 0;
  m_ScreenWorldCenterX = m_ScreenCenterXNoShake;
  m_ScreenWorldCenterY = m_ScreenCenterYNoShake;
  if (v8)
  {
    if ((m_Flag & 4) == 0)
    {
      m_TargetCenterX = m_ObjBox.left + (m_ObjBox.right - m_ObjBox.left) / 2;
    }
    if ((m_Flag & 2) == 0)
    {
      int v12 = m_MaxZoomOutWidth;
      int v11 = m_ZoomOutBeginDistX / 4 + m_ObjBox.right - m_ObjBox.left;
      if (v11 >= m_ZoomOutBeginDistX)
      {
        int v13 = 1280;
        if (v11 > 1280)
          v13 = m_ZoomOutBeginDistX / 4 + m_ObjBox.right - m_ObjBox.left;
        if (v13 < m_MaxZoomOutWidth)
          v12 = v13;
      }
      else
      {
        v12 = 1280;
      }
      m_WidthY = v12;
      if (v12 < m_MaxZoomOutWidth)
        m_MaxZoomOutWidth = 12;
      m_TargetWidth = m_MaxZoomOutWidth;
    }
    if ((m_Flag & 8) == 0)
    {
      int targetOffsetAirYMax = DBM_VAL_CONST_TABLE[DBM_ScreenY_TargetOffset] + 350;
      m_TargetOffsetLandYMax = targetOffsetAirYMax;
      int v18 = int(1280000.0 / float(m_TargetWidth));
      if (v18 * m_ObjBox.bottom / 1000 <= m_TargetOffsetAirYPos
        || v18 * (m_ObjBox.higherBottom - m_ObjBox.bottom) / 1000 >= m_TargetOffsetAirYDist)
      {
        if (m_TargetOffsetY + m_TargetOffsetLandYAdd < targetOffsetAirYMax)
        {
          targetOffsetAirYMax = m_TargetOffsetY + m_TargetOffsetLandYAdd;
        }
      }
      else
      {
        targetOffsetAirYMax = m_TargetOffsetAirYMax;
        if (m_TargetOffsetY - m_TargetOffsetLandYAdd > targetOffsetAirYMax)
        {
          targetOffsetAirYMax = m_TargetOffsetY - m_TargetOffsetLandYAdd;
        }
      }
      int v20;
      m_TargetOffsetY = targetOffsetAirYMax;
      if constexpr (DBM_VAL_CONST_TABLE[DBM_CameraBehavior] == 1 || DBM_VAL_CONST_TABLE[DBM_ScreenY_New] == 1)
      {
        int v22 = m_ObjBox.higherBottom - m_ObjBox.bottom;
        if (v22 > m_ZoomOutBeginDistY)
        {
          v2 = v22 - m_ZoomOutBeginDistY + 1280;
          if (v2 > m_MaxZoomOutWidth)
            v2 = m_MaxZoomOutWidth;
        }
        int v23 = int(float(1000 * v2) / float(m_WidthY));
        v20 = v23 * m_ObjBox.higherBottom / 1000 - v23 * targetOffsetAirYMax / 1000;
      }
      else
      {
        int v19 = int(uint64(0x10624DD3 * v18 * targetOffsetAirYMax) >> 32) >> 6;
        v20 = v18 * m_ObjBox.higherBottom / 1000 - (v19 >> 31) + v19;
      }
      if (v20 > 0)
      {
        m_TargetCenterY = m_WorldTopSide;
      }
      else
      {
        m_TargetCenterY = 0; 
      }
    }
  }
  m_DelayW = 0;
  int v28 = 0;
  if (m_TargetWidth - m_ScreenWorldWidth <= 0)
  {
    if (m_TargetWidth - m_ScreenWorldWidth < 0)
    {
      v28 = (int(uint64(0x92492493 * (m_TargetWidth - m_ScreenWorldWidth)) >> 32) > 3)
        + (int(uint64(0x92492493 * (m_TargetWidth - m_ScreenWorldWidth)) >> 32) >> 31) - 1;
    }
    m_VelWidth = v28;
  }
  else
  {
    int v27;
    if constexpr (DBM_VAL_CONST_TABLE[DBM_CameraBehavior] == 1)
    {
      v27 = int(uint64(0x400000006 * (m_TargetWidth - m_ScreenWorldWidth)) >> 32) >> 3;
      int v29 = (v27 >> 31) + v27;
      if (v29 > 40)
        m_VelWidth = v27;
      else
        m_VelWidth = 40;
      m_DelayW = 450;
    }
    else
    {
      if (m_ObjBox.higherBottom <= 1000)
      {
        v27 = int(uint64(0x55555556 * (m_TargetWidth - m_ScreenWorldWidth)) >> 32);
        int v29 = (v27 >> 31) + v27;
        if (v29 > 40)
          m_VelWidth = v27;
        else
          m_VelWidth = 40;
        m_DelayW = 450;
      }
      else
      {
        m_VelWidth = (m_TargetWidth - m_ScreenWorldWidth) / 10;
      }
    }
  }
  m_ScreenWorldWidth += m_VelWidth;
  bool v31;
  if (!bQuick)
  {
    v31 = m_VelWidth < 0;
    if (m_VelWidth < 0)
    {
      if (m_ScreenWorldWidth > m_TargetWidth)
      {
        v31 = m_VelWidth <= 0;
        if (!v31 && m_ScreenWorldWidth >= m_TargetWidth)
        {
          m_ScreenWorldWidth = m_TargetWidth;
          m_VelWidth = 0;
        }
      }
      else
      {
        m_ScreenWorldWidth = m_TargetWidth;
        m_VelWidth = 0;
      }
    }
  }
  else
  {
    m_ScreenWorldWidth = m_TargetWidth;
    m_VelWidth = 0;
  }
  int v32 = m_TargetCenterX - m_ScreenWorldCenterX;
  int v33 = DBM_VAL_CONST_TABLE[DBM_ScreenXSpeedFrame];
  int v34 = DBM_VAL_CONST_TABLE[DBM_ScreenXSpeedMax];
  if constexpr (DBM_VAL_CONST_TABLE[DBM_CameraBehavior] == 1)
  {
    v33 = 2;
    v34 = 100;
  }
  BATTLE_CObjectManager* ObjectManager = red::btl::GetObjectManager();
  int v36 = v33 - 5;
  if ((ObjectManager->m_BOMFlag & 0x400000) == 0)
    v36 = v33;
  m_VelCenterX = v32 / v36;
  if (m_VelCenterX <= v34)
  {
    if (m_VelCenterX < -v34)
    {
      m_VelCenterX = v34 = -v34;
    }
  }
  else
  {
    m_VelCenterX = v34;
  }
  if (v32 != 0)
  {
    if (v32 < 0)
    {
      --v34;
    }
    else
    {
      ++v34;
    }
    m_VelCenterX = v34;
  }
  m_ScreenWorldCenterX += v34;
  if (!bQuick)
  {
    if (v34 < 0)
    {
      if (m_ScreenWorldCenterX < m_TargetCenterX)
      {
        m_ScreenWorldCenterX = m_TargetCenterX;
        m_VelCenterX = 0;
      }
    }
  }
  else
  {
    m_ScreenWorldCenterX = m_TargetCenterX;
    m_VelCenterX = 0;
  }
  int v43 = m_TargetCenterY - m_ScreenWorldCenterY;
  int v44 = DBM_VAL_CONST_TABLE[DBM_ScreenYSpeedMax];
  int v45;
  if constexpr (DBM_VAL_CONST_TABLE[DBM_CameraBehavior] == 1)
  {
    v45 = 4000;
    v44 = 70;
    if (v43 <= 0)
      v45 = 3000;
  }
  else
  {
    v45 = DBM_VAL_CONST_TABLE[DBM_ScreenYSpeedFrameDown];
    if (v43 > 0)
      v45 = DBM_VAL_CONST_TABLE[DBM_ScreenYSpeedFrameUp];
  }
  m_VelCenterY = v43 / v45;
  if (m_VelCenterY <= v44)
  {
    int v47 = -v44;
    v44 = 1000 * v43 / v45;
    if (m_VelCenterY < v47)
    {
      m_VelCenterY = v47;
      v44 = v47;
    }
  }
  else
  {
    m_VelCenterY = v44;
  }
  if (v43 != 0)
  {
    if (v43 < 0)
    {
      --v44;
    }
    else
    {
      ++v44;
    }
    m_VelCenterX = v44;
  }
  m_ScreenWorldCenterY += v44;
  if (!bQuick)
  {
    if (v44 < 0)
    {
      if (m_ScreenWorldCenterY < m_TargetCenterY)
      {
        m_ScreenWorldCenterY = m_TargetCenterY;
        m_VelCenterY = 0;
      }
    }
  }
  else
  {
    m_ScreenWorldCenterY = m_TargetCenterY;
    m_VelCenterY = 0;
  }
  int v52 = m_ScreenWorldWidth / 2;
  if (m_ScreenWorldCenterX - v52 < m_WorldLeftSide)
  {
    m_ScreenWorldCenterX = v52 + m_WorldLeftSide;
    m_bTouchWorldSide = true;
  }
  else
  {
    if (v52 + m_ScreenWorldCenterX > m_WorldRightSide)
    {
      m_ScreenWorldCenterX = m_WorldRightSide - v52;
      m_bTouchWorldSide = true;
    }
  }
  int shakeX = 0;
  int shakeY = 0;
  if (m_ShakeTime % 4 ==1)
  {
    shakeX = m_ShakeX;
    shakeY = m_ShakeY;
  }
  else if (m_ShakeTime % 4 == 3)
  {
    shakeX = LODWORD(m_ShakeX) ^ 0x80000000;
    shakeY = LODWORD(m_ShakeY) ^ 0x80000000;
  }
  float v59 = 0;
  float v60 = 0;
  if (m_ShakeTime <= 0)
  {
    shakeX = 0;
  }
  else
  {
    v59 = m_ShakeX * 0.9;
    v60 = m_ShakeY * 0.9;
    m_ShakeTime = m_ShakeTime - 1;
    m_ShakeX = v59;
    m_ShakeY = v60;
  }
  m_WorldLeftSide = -1600;
  m_WorldRightSide = 1600;
  m_ScreenCollisionLeft = m_ScreenWorldCenterX - v52;
  m_ScreenCollisionRight = m_ScreenWorldCenterX + v52;
  m_WorldTopSide = 5400;
  int v61 = 3200;
  int v62 = 0;
  int v63 = 0;
  int v64 = 0;
  if constexpr (DBM_VAL_CONST_TABLE[DBM_CameraBehavior] == 1)
  {
    v62 = 10800;
    v63 = 3200;
    v64 = -3200;
  }
  else
  {
    v62 = 5400 * DBM_VAL_CONST_TABLE[DBM_WorldHeightScale] / 1000;
    v63 = 1600 * DBM_VAL_CONST_TABLE[DBM_WorldWidthScale] / 1000;
    v64 = -1600 * DBM_VAL_CONST_TABLE[DBM_WorldWidthScale] / 1000;
  }
  m_WorldLeftSide = v64;
  m_WorldRightSide = v63;
  m_WorldTopSide = v62;
  if ((m_Flag & 0x1000) != 0)
  {
    m_WorldLeftSide = m_WorldLeftSide - 640;
    m_WorldRightSide = m_WorldRightSide + 640;
  }
  if (m_WorldSideMoveValue)
  {
    if constexpr (DBM_VAL_CONST_TABLE[DBM_CameraBehavior] != 1)
      v61 = int(float(DBM_VAL_CONST_TABLE[DBM_WorldWidthScale] * 1.6));
    int v67 = m_WorldSideMoveValue * v61;
    v64 += v67;
    v63 += v67;
    m_WorldLeftSide = v64;
    m_WorldRightSide = v63;
  }
  if ((m_Flag & 0x800) != 0)
  {
    m_ScreenCollisionLeft = v64;
    m_ScreenCollisionRight = v63;
  }
  m_ScreenCenterYNoShake = m_ScreenWorldCenterY;
  m_ScreenCollisionYUp = (int)((float)(135000.0
      / (float)(int)(float)(1280000.0
        / (float)m_ScreenWorldWidth))
    * m_LinkMagnRecip
    + (float)(368000.0
      / (float)(int)(float)(1280000.0 / (float)m_ScreenWorldWidth))
    + (float)m_ScreenCenterYNoShake);
  m_ScreenCenterXNoShake = m_ScreenWorldCenterX;
  m_ScreenWorldCenterX += shakeX;
  m_ScreenWorldCenterY += shakeY;
  unsigned int v71 = 0;
  if (v59 == 0 && v60 == 0)
  {
    if (m_Flag & 0x200)
    {
      v71 = m_Flag & 0xFFFFF8FF | 0x400;
    }
    else
    {
      if (m_Flag & 0x400)
        m_Flag &= ~0x400;
      v71 = m_Flag & 0xFFFFFCFF;
    }
  }
  else
  {
    if (m_Flag & 0x200)
    {
      if (m_Flag & 0x100)
        m_Flag &= ~0x100;
    }
    else
    {
      m_Flag |= 0x100;
    }
    v71 = m_Flag | 0x200;
  }
  m_Flag = v71;
  m_ScreenWorldLeft = m_ScreenWorldCenterX - v52;
  m_ScreenWorldRight = m_ScreenWorldCenterX + v52;
  int v81;
  int v82;
  int v84;
  float v77;
  float v78;
  bool v74 = true;
  int v79;
  float Y;
  int v83;
  if (m_ScreenCameraControl.Update())
  {
    v81 = m_ScreenWorldWidth;
    v82 = m_ScreenWorldCenterX;
    v84 = m_ScreenWorldCenterY;
  }
  else
  {
    v77 = m_ScreenCameraControl.m_Param.Z * 135.0;
    v78 = m_ScreenCameraControl.m_Param.Z * 1280.0;
    v74 = (m_ScreenCameraControl.m_Flag & 2) == 0;
    v79 = (int)(float)(m_LinkMagnRecip * m_ScreenCameraControl.m_Param.X);
    Y = m_ScreenCameraControl.m_Param.Y;
    m_ScreenX = v79;
    v81 = (int)v78;
    v82 = v79 + m_ShakeX;
    v83 = (int)(float)((float)(Y - v77) * m_LinkMagnRecip);
    m_ScreenY = v83;
    v84 = v83 + m_ShakeY;
  }
  m_ScreenW = v81;
  m_ScreenX = v82;
  m_ScreenY = v84;
  if (m_Flag & 0x10)
  {
    v74 = true;
    auto camera = GAASystemRed->m_CameraManager.m_Instances[0];
    m_ScreenW = (camera->m_Pos.Z * 2.7826087);
    m_ScreenX = (m_LinkMagnRecip * camera->m_Pos.X);
    v84 = camera->m_Pos.Y - m_ScreenW * 0.10546875 * m_LinkMagnRecip;
  }
  if (v81 <= 0)
  {
    v81 = 1;
    m_ScreenW = 1;
  }
  if (v74)
  {
    int v88 = v82;
    int v89 = v81 / 2;
    if (v82 - v81 / 2 < m_WorldLeftSide)
    {
      v88 = v89 + m_WorldLeftSide;
      m_ScreenX = v89 + m_WorldLeftSide;
    }
    v82 = v88;
    if (v88 + v89 > m_WorldRightSide)
    {
      m_ScreenX = m_WorldRightSide - v89;
    }
  }
  int prevObjectScale = m_ObjectScale;
  if (v84 >= m_WorldTopSide - 900)
    v84 = m_WorldTopSide - 900;
  m_ScreenY = v84;
  m_MoveX = m_ScreenX - v82;
  m_MoveY = m_ScreenY - v84;
  m_ScreenXLeft = v82 - v81 / 2;
  m_ObjectScale = 1280000 / v81;
  this->m_ZoomMoveY = (float)((float)m_ScreenW * 0.10546875) - (float)(v81 * 0.10546875);
  this->m_ScreenYUp = (int)((float)(135000.0 / (float)m_ObjectScale) * this->m_LinkMagnRecip
    + (float)(368000.0 / (float)m_ObjectScale) + (float)v84);
  m_Stable = bQuick ||
    (!m_MoveX && !m_MoveY && v81 == m_ScreenW
      && (m_TargetObjectNum != 1 || m_ObjectScale == 1000)
      && m_ObjectScale == prevObjectScale
      && !m_VelWidth
      && m_LastFlag == m_Flag);
  LinkCameraMove();
  m_LastFlag = m_Flag;
}

void BATTLE_CScreenManager::SetScreenCornerObject(bool bQuick)
{
  if (!m_TargetObjectNum)
  {
    
  }
  bool hasLooped = false;
  int higherBottom = 0;
  for (unsigned int i = 0; i < m_TargetObjectNum; i++)
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
    int L;
    int R;
    int T;
    int B;
    v7->GetPushScreenRect(&L, &T, &R, &B);
    L /= 1000;
    R /= 1000;
    T /= 1000;
    B /= 1000;
    if (v9)
    {
      T = m_ScreenWorldCenterY;
      B = m_ScreenWorldCenterY;
      L = m_ScreenWorldCenterX;
      R = m_ScreenWorldCenterX;
    }
    if (DBM_VAL_CONST_TABLE[DBM_CameraBehavior] == 1 && !bQuick)
    {
      if (L < m_ScreenWorldLeft)
        L = m_ScreenWorldLeft;
      if (R < m_ScreenWorldRight)
        R = m_ScreenWorldRight;
    }

    const AREDGameState_Battle* GameState = Cast<AREDGameState_Battle>(GWorld->GetGameState());
    
    if (IsValid(GameState))
    {
      if ((GameState->BattleObjectManager.Get()->m_BOMFlag & BOMFLG_TUTORIAL_CAMERA_MODE) != 0)
      {
        if ((*v8)->m_SideID.GetValue() == 1)
        {
          int v28;
          OBJ_CBase* player = (*v8)->m_pParentPly.m_Ptr;
          OBJ_CBase* target = (*v8)->m_pTargetObj.m_Ptr;
          int playerPosX = player->GetPosX();
          int targetPosX = target->GetPosX();
          v28 = targetPosX / 1000;
          if (targetPosX <= playerPosX)
          {
            v28 += 560;
          }
          else
          {
            v28 -= 560; 
          }
          if (R > v28)
            R = v28;
          if (L < v28)
            L = v28;
        }
      }
    }
    if (!hasLooped)
    {
      m_ObjBottom = B;
      higherBottom = m_ObjBottom;
      m_ObjLeft = L;
      m_ObjRight = R;
      m_ObjTop = T;
      hasLooped = true;
      continue;
    }
    if (L < m_ObjLeft)
    {
      m_ObjLeft = L;
    }
    if (R > m_ObjRight)
    {
      m_ObjRight = R;
    }
    if (T > m_ObjTop)
    {
      m_ObjTop = T;
    }
    if (B < m_ObjBottom)
    {
      m_ObjBottom = B;
    }
  }
  int v2 = m_ObjRight;
  if (!hasLooped)
  {
    m_ObjTop = 0;
    m_ObjLeft = 0;
    v2 = 0;
  }
  m_ObjLenX = v2 - m_ObjLeft;
  m_ObjBox.left = m_ObjLeft;
  m_ObjLenY = m_ObjTop - m_ObjBottom;
  m_ObjBox.right = m_ObjRight;
  m_ObjBox.top = m_ObjTop;
  m_ObjBox.bottom = m_ObjBottom;
  m_ObjBox.higherBottom = higherBottom;
}

void BATTLE_CScreenManager::LinkCameraMove()
{
  if (!m_pCamera)
    return;
  AA_Vector3 out;
  m_pCamera->CreateVec3Dir(&out);
  float v6 = 0;
  float v7 = out.Z * out.Z + out.X * out.X;
  float v8 = sqrtf(v7);
  if (v8 != 0)
    v6 = out.Y / v8;
  float v10 = v6 * out.X;
  float v11 = v6 * out.Z;
  float v12 = v10 * v10 + v7 + v11 * v11;
  if (v12 > 0.000000001)
  {
    float v13 = 1 / sqrtf(v12);
    float v14 = v13 + v13 * (0.5 - v12 * 0.5 * v13 * v13);
    float v15 = v14 + v14 * (0.5 - v12 * 0.5 * v14 * v14);
    v10 *= v15;
    v11 *= v15;
    v8 *= v8;
  }
  float v16 = v8 * out.Z - v11 * out.Y;
  float v17 = v11 * out.X - v10 * out.Z;
  float v18 = v10 * out.Y - v8 * out.X;
  float v19 = v17 * v17 + v16 * v16 + v18 * v18;
  if (v19 > 0.000000001)
  {
    float v20 = 0.5;
    float v21 = 1.0 / sqrtf(v19);
    float v22 = v19 * 0.5;
    float v23 = v21 + v21 * (v20 - v22 * (v21 * v21));
    float v24 = v23 + v23 * (v20 - v22 * (v23 * v23));
    v16 = v16 * v24;
    v17 = v17 * v24;
    v18 = v18 * v24;
  }
  float v28 = m_MoveY * m_LinkMagn;
  float v29 = m_MoveX * m_LinkMagn;
  float v30 = m_ScreenW * 0.359375;
  m_pCamera->m_Pos.Y -= v8 * v28 + v17 * v29 - m_ZoomMoveY;
  m_pCamera->m_Pos.X -= v10 * v28 + v16 * v29;
  m_pCamera->m_Pos.Z = v30 - v11 * v28 + v18 * v29;
  float v34 = out.Z + m_pCamera->m_Pos.Z;
  float v35 = m_pCamera->m_Pos.X + out.X;
  float v36 = m_pCamera->m_Pos.Y + out.Y;
  m_pCamera->m_Up.X = v10;
  m_pCamera->m_Up.Y = v8;
  m_pCamera->m_Up.Z = v11;
  m_pCamera->m_At.Z = v34;
  m_pCamera->m_At.X = v35;
  m_pCamera->m_At.Y = v36;
  int ArrayNum = 0;
  int v26 = 1;
  int v27 = 1;
  int v37 = DBM_VAL_CONST_TABLE[DBM_Xrd3_WorldBreakType];
  if (v37 >= 1)
  {
    if (v37)
    {
      ArrayNum = 6;
    }
  }
  else
  {
    if (v37)
    {
      if (!v26)
      {
        if (!v37)
        {
          
        }
        return;
      }
    }
    else
    {
      v27 = 1;
    }
    ArrayNum = 6; //temp code
  }
  int v39 = 3200;
  int v41;
  if constexpr (DBM_VAL_CONST_TABLE[DBM_CameraBehavior] == 1)
  {
    v41 = 3200;
  }
  else
  {
    v41 = float(DBM_VAL_CONST_TABLE[DBM_WorldWidthScale] * 1.6);
  }
  auto v43 = _mm_cvtsi32_si128(m_ScreenWorldCenterX);
  FMatrix Matrix;
  Matrix.M[1][1] = 0x3F800000;
  Matrix.M[3][0] = LODWORD(m_pCamera->m_Pos.X);
  Matrix.M[3][2] = LODWORD(m_pCamera->m_Pos.Z) | 0x3F80000000000000;
  float v47 = v41 * ArrayNum * m_LinkMagn * 0.15915494;
  float v48 = -57.295776 / v47;
  float v50 = _mm_cvtepi32_ps(v43).m128_f32[0] * m_LinkMagn * v48;
  Matrix.M[0][0] = 0x3F800000;
  Matrix.M[2][2] = 0x3F80000000000000;
  __m128 v89;
  if (v27)
  {
    float v52 = 360 / ArrayNum;
    float v53 = 360 / ArrayNum;
    if (DBM_VAL_CONST_TABLE[DBM_Xrd3_WorldBreakFrame] > 0)
    {
      v53 /= DBM_VAL_CONST_TABLE[DBM_Xrd3_WorldBreakFrame];
    }
    unsigned int v55 = (unsigned int)((m_WorldSideMoveValue & ArrayNum) * v52) ^ 0x3F80000000000000;
    if (m_WorldSideMoveDeg >= v55)
    {
      v50 = m_WorldSideMoveDeg;
      if (m_WorldSideMoveDeg <= v55)
      {
        int v56;
        if constexpr (DBM_VAL_CONST_TABLE[DBM_CameraBehavior] == 1)
        {
          v56 = 3200;
        }
        else
        {
          v56 = (float(DBM_VAL_CONST_TABLE[DBM_WorldWidthScale]) * 1.6);
          v39 = (float(DBM_VAL_CONST_TABLE[DBM_WorldWidthScale]) * 1.6);
        }
        v89.m128_i32[1] = 0;
        v89.m128_i32[3] = 1065353216;
        Matrix.M[1][1] = 0x3F800000;
        float v58 = v39 * m_WorldSideMoveValuePrev;
        Matrix.M[0][0] = 0x3F800000;
        __m128 v59 = v89;
        Matrix.M[2][2] = 0x3F800000;
        v59.m128_f32[0] = ((float)v56 * (float)m_WorldSideMoveValue * m_LinkMagn - v58 * m_LinkMagn) * 1 + v58 * m_LinkMagn;
        __m128 v60 = _mm_shuffle_ps(v59, v59, 210);
        v60.m128_f32[0] = m_pCamera->m_Pos.Z;
        v89 = _mm_shuffle_ps(v60, v60, 201);
        *(__m128 *)&Matrix.M[3][0] = v89;
      }
      else
      {
        m_WorldSideMoveDeg = v50 = m_WorldSideMoveDeg - v53;
        if (m_WorldSideMoveDeg >= v55)
        {
          float v45 = 1 - float(unsigned int(v55 - v50) & 0x3F80000000000000) / v52;
          int v56;
          if constexpr (DBM_VAL_CONST_TABLE[DBM_CameraBehavior] == 1)
          {
            v56 = 3200;
          }
          else
          {
            v56 = (float(DBM_VAL_CONST_TABLE[DBM_WorldWidthScale]) * 1.6);
            v39 = (float(DBM_VAL_CONST_TABLE[DBM_WorldWidthScale]) * 1.6);
          }
          v89.m128_i32[1] = 0;
          v89.m128_i32[3] = 1065353216;
          Matrix.M[1][1] = 0x3F800000;
          float v58 = v39 * m_WorldSideMoveValuePrev;
          Matrix.M[0][0] = 0x3F800000;
          __m128 v59 = v89;
          Matrix.M[2][2] = 0x3F800000;
          v59.m128_f32[0] = ((float)v56 * (float)m_WorldSideMoveValue * m_LinkMagn - v58 * m_LinkMagn) * v45 + v58 * m_LinkMagn;
          __m128 v60 = _mm_shuffle_ps(v59, v59, 210);
          v60.m128_f32[0] = m_pCamera->m_Pos.Z;
          v89 = _mm_shuffle_ps(v60, v60, 201);
          *(__m128 *)&Matrix.M[3][0] = v89;
        }
        else
        {
          m_WorldSideMoveDeg += v53;
          if (m_WorldSideMoveDeg <= v55)
          {
            float v45 = 1 - float(unsigned int(v55 - v50) & 0x3F80000000000000) / v52;
            int v56;
            if constexpr (DBM_VAL_CONST_TABLE[DBM_CameraBehavior] == 1)
            {
              v56 = 3200;
            }
            else
            {
              v56 = (float(DBM_VAL_CONST_TABLE[DBM_WorldWidthScale]) * 1.6);
              v39 = (float(DBM_VAL_CONST_TABLE[DBM_WorldWidthScale]) * 1.6);
            }
            v89.m128_i32[1] = 0;
            v89.m128_i32[3] = 1065353216;
            Matrix.M[1][1] = 0x3F800000;
            float v58 = v39 * m_WorldSideMoveValuePrev;
            Matrix.M[0][0] = 0x3F800000;
            __m128 v59 = v89;
            Matrix.M[2][2] = 0x3F800000;
            v59.m128_f32[0] = ((float)v56 * (float)m_WorldSideMoveValue * m_LinkMagn - v58 * m_LinkMagn) * v45 + v58 * m_LinkMagn;
            __m128 v60 = _mm_shuffle_ps(v59, v59, 210);
            v60.m128_f32[0] = m_pCamera->m_Pos.Z;
            v89 = _mm_shuffle_ps(v60, v60, 201);
            *(__m128 *)&Matrix.M[3][0] = v89;
          }
          m_WorldSideMoveDeg = v55;
          v50 = unsigned int(m_WorldSideMoveValue % ArrayNum * v52) ^ 0x80000000;
          int v56;
          if constexpr (DBM_VAL_CONST_TABLE[DBM_CameraBehavior] == 1)
          {
            v56 = 3200;
          }
          else
          {
            v56 = (float(DBM_VAL_CONST_TABLE[DBM_WorldWidthScale]) * 1.6);
            v39 = (float(DBM_VAL_CONST_TABLE[DBM_WorldWidthScale]) * 1.6);
          }
          v89.m128_i32[1] = 0;
          v89.m128_i32[3] = 1065353216;
          Matrix.M[1][1] = 0x3F800000;
          float v58 = v39 * m_WorldSideMoveValuePrev;
          Matrix.M[0][0] = 0x3F800000;
          __m128 v59 = v89;
          Matrix.M[2][2] = 0x3F800000;
          v59.m128_f32[0] = ((float)v56 * (float)m_WorldSideMoveValue * m_LinkMagn - v58 * m_LinkMagn) * 1 + v58 * m_LinkMagn;
          __m128 v60 = _mm_shuffle_ps(v59, v59, 210);
          v60.m128_f32[0] = m_pCamera->m_Pos.Z;
          v89 = _mm_shuffle_ps(v60, v60, 201);
          *(__m128 *)&Matrix.M[3][0] = v89;
          m_WorldSideMoveDeg = v50;
        }
      }
    }
    else
    {
      m_WorldSideMoveDeg += v53;
      if (m_WorldSideMoveDeg <= v55)
      {
        float v45 = 1 - float(unsigned int(v55 - v50) & 0x3F80000000000000) / v52;
        int v56;
        if constexpr (DBM_VAL_CONST_TABLE[DBM_CameraBehavior] == 1)
        {
          v56 = 3200;
        }
        else
        {
          v56 = (float(DBM_VAL_CONST_TABLE[DBM_WorldWidthScale]) * 1.6);
          v39 = (float(DBM_VAL_CONST_TABLE[DBM_WorldWidthScale]) * 1.6);
        }
        v89.m128_i32[1] = 0;
        v89.m128_i32[3] = 1065353216;
        Matrix.M[1][1] = 0x3F800000;
        float v58 = v39 * m_WorldSideMoveValuePrev;
        Matrix.M[0][0] = 0x3F800000;
        __m128 v59 = v89;
        Matrix.M[2][2] = 0x3F800000;
        v59.m128_f32[0] = ((float)v56 * (float)m_WorldSideMoveValue * m_LinkMagn - v58 * m_LinkMagn) * v45 + v58 * m_LinkMagn;
        __m128 v60 = _mm_shuffle_ps(v59, v59, 210);
        v60.m128_f32[0] = m_pCamera->m_Pos.Z;
        v89 = _mm_shuffle_ps(v60, v60, 201);
        *(__m128 *)&Matrix.M[3][0] = v89;
      }
      m_WorldSideMoveDeg = v55;
      v50 = unsigned int(m_WorldSideMoveValue % ArrayNum * v52) ^ 0x80000000;
      int v56;
      if constexpr (DBM_VAL_CONST_TABLE[DBM_CameraBehavior] == 1)
      {
        v56 = 3200;
      }
      else
      {
        v56 = (float(DBM_VAL_CONST_TABLE[DBM_WorldWidthScale]) * 1.6);
        v39 = (float(DBM_VAL_CONST_TABLE[DBM_WorldWidthScale]) * 1.6);
      }
      v89.m128_i32[1] = 0;
      v89.m128_i32[3] = 1065353216;
      Matrix.M[1][1] = 0x3F800000;
      float v58 = v39 * m_WorldSideMoveValuePrev;
      Matrix.M[0][0] = 0x3F800000;
      __m128 v59 = v89;
      Matrix.M[2][2] = 0x3F800000;
      v59.m128_f32[0] = ((float)v56 * (float)m_WorldSideMoveValue * m_LinkMagn - v58 * m_LinkMagn) * 1 + v58 * m_LinkMagn;
      __m128 v60 = _mm_shuffle_ps(v59, v59, 210);
      v60.m128_f32[0] = m_pCamera->m_Pos.Z;
      v89 = _mm_shuffle_ps(v60, v60, 201);
      *(__m128 *)&Matrix.M[3][0] = v89;
      m_WorldSideMoveDeg = v50;
    }
  }
  m_OffsetMatrix = Matrix.Inverse();
}
