/*
 * File: REL.c
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.139
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Sep 25 16:10:50 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "REL.h"
#include "rtwtypes.h"
#include "REL_types.h"
#include "Rte_Type.h"
#include "REL_private.h"

/* Named constants for Chart: '<S3>/FLDoorRlsDriver' */
#define REL_IN_Checking                ((uint8)1U)
#define REL_IN_Delay                   ((uint8)2U)
#define REL_IN_ElectricDoor            ((uint8)1U)
#define REL_IN_Fail                    ((uint8)1U)
#define REL_IN_Fail1                   ((uint8)2U)
#define REL_IN_Ice_Break               ((uint8)3U)
#define REL_IN_Idle                    ((uint8)1U)
#define REL_IN_Idle_m                  ((uint8)4U)
#define REL_IN_LastCheck               ((uint8)2U)
#define REL_IN_LastCheck_o             ((uint8)5U)
#define REL_IN_NO_ACTIVE_CHILD         ((uint8)0U)
#define REL_IN_NonElectricDoor         ((uint8)2U)
#define REL_IN_Normal                  ((uint8)1U)
#define REL_IN_PowerOn                 ((uint8)2U)
#define REL_IN_Release                 ((uint8)2U)
#define REL_IN_Reset                   ((uint8)3U)
#define REL_IN_Step1_Ajar              ((uint8)4U)
#define REL_IN_Step2_Open              ((uint8)5U)
#define REL_IN_Success                 ((uint8)6U)

/* Named constants for Chart: '<S3>/RLDoorRlsReq' */
#define REL_IN_DoorLock                ((uint8)1U)
#define REL_IN_DoorUnlock              ((uint8)2U)
#define REL_IN_DoorUnlock_i            ((uint8)1U)
#define REL_IN_Error                   ((uint8)3U)
#define REL_IN_Idle_i                  ((uint8)1U)
#define REL_IN_NO_ACTIVE_CHILD_d       ((uint8)0U)
#define REL_IN_Once                    ((uint8)2U)
#define REL_IN_Press                   ((uint8)2U)
#define REL_IN_RELEASE                 ((uint8)4U)
#define REL_IN_Release_o               ((uint8)4U)
#define REL_IN_Release_oa              ((uint8)2U)
#define REL_IN_Release_oat             ((uint8)3U)
#define REL_IN_Trigger                 ((uint8)2U)
#define REL_IN_Twice                   ((uint8)3U)
#define REL_IN_UnlockFail              ((uint8)1U)
#define REL_IN_UnlockReq               ((uint8)2U)
#define REL_IN_UnlockSuccess           ((uint8)3U)
#define REL_IN_UnlockSucess            ((uint8)3U)

/* Named constants for Chart: '<S3>/DoorSwSts' */
#define REL_IN_Crash                   ((uint8)1U)
#define REL_IN_NoCrash                 ((uint8)2U)

/* Named constants for Chart: '<S3>/FLDoorRlsReq' */
#define REL_IN_DoorLock_f              ((uint8)1U)
#define REL_IN_DoorUnlock_g            ((uint8)2U)
#define REL_IN_DoorUnlock_gp           ((uint8)1U)
#define REL_IN_Error_a                 ((uint8)3U)
#define REL_IN_Idle_p                  ((uint8)1U)
#define REL_IN_Once_o                  ((uint8)2U)
#define REL_IN_Press_f                 ((uint8)2U)
#define REL_IN_RELEASE_g               ((uint8)4U)
#define REL_IN_Release_n               ((uint8)4U)
#define REL_IN_Release_ni              ((uint8)2U)
#define REL_IN_Release_niu             ((uint8)3U)
#define REL_IN_Trigger_h               ((uint8)2U)
#define REL_IN_Twice_i                 ((uint8)3U)
#define REL_IN_UnlockFail_i            ((uint8)1U)
#define REL_IN_UnlockReq_k             ((uint8)2U)
#define REL_IN_UnlockSuccess_p         ((uint8)3U)
#define REL_IN_UnlockSucess_a          ((uint8)3U)

/* Block signals (default storage) */
B_REL_T REL_B;

/* Block states (default storage) */
DW_REL_T REL_DW;

/* Forward declaration for local functions */
static void REL_Normal(Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_CinchHome,
  uint8 rtu_SI_e_DoorRlsDelayTime, boolean *rty_SO_b_MotorA, boolean
  *rty_SO_b_MotorB, Mot_Cmd_E *rty_SO_e_MotorCmd, boolean *rty_SO_b_Error, uint8
  *rty_SO_e_MotorPwm, DW_FLDoorRlsDriver_REL_T *localDW);

/* Forward declaration for local functions */
static void REL_DoorInBtn(UInt8 rtu_SI_e_EspVehSpd, Boolean
  rtu_SI_b_EspVehSpdVld, Gear_Posn_E rtu_SI_m_VcuGearPosn, Door_Sts_E
  rtu_SI_m_DoorLockSts, Rat_Sts_E rtu_SI_m_DoorRatSts, Boolean
  rtu_SI_b_ChildLckSts, boolean *rty_SO_b_DoorRlsReq, uint8
  *rty_SO_e_DoorRlsDelayTime, Unlock_Req_E *rty_SO_m_UnlockReq,
  DW_RLDoorRlsReq_REL_T *localDW);
static void REL_DoorHndBtn(UInt8 rtu_SI_e_EspVehSpd, Boolean
  rtu_SI_b_EspVehSpdVld, Gear_Posn_E rtu_SI_m_VcuGearPosn, Door_Sts_E
  rtu_SI_m_DoorLockSts, Rat_Sts_E rtu_SI_m_DoorRatSts, boolean
  *rty_SO_b_DoorRlsReq, Unlock_Req_E *rty_SO_m_UnlockReq, DW_RLDoorRlsReq_REL_T *
  localDW);

/* Forward declaration for local functions */
static void REL_enter_atomic_NoCrash(boolean *SL_b_FLDoorHndPullSts, boolean
  *SL_b_FRDoorHndPullSts, boolean *SL_b_FLDoorHndBtnSts);
static float64 REL_GetDoorRatSts(float64 ajar, float64 open);
static uint8 REL_safe_cast_to_Rat_Sts_E(uint8 input);
static void REL_DoorInBtn_n(const Rat_Sts_E *SO_m_FRDoorRatSts);
static void REL_DoorHndBtn_c(const Rat_Sts_E *SO_m_FRDoorRatSts);
static void REL_DoorInBtn_e(const Rat_Sts_E *SO_m_FLDoorRatSts, const Door_Sts_E
  *DataTypeConversion12);
static void REL_DoorHndBtn_k(const Rat_Sts_E *SO_m_FLDoorRatSts, const
  Door_Sts_E *DataTypeConversion12);
static float64 REL_GetDrvUnlockReq(void);
static float64 REL_GetPassUnlockReq(void);

/* Function for Chart: '<S3>/FLDoorRlsDriver' */
static void REL_Normal(Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_CinchHome,
  uint8 rtu_SI_e_DoorRlsDelayTime, boolean *rty_SO_b_MotorA, boolean
  *rty_SO_b_MotorB, Mot_Cmd_E *rty_SO_e_MotorCmd, boolean *rty_SO_b_Error, uint8
  *rty_SO_e_MotorPwm, DW_FLDoorRlsDriver_REL_T *localDW)
{
  if (localDW->is_Normal == REL_IN_ElectricDoor) {
    if (localDW->is_MainProgress_c == REL_IN_Idle) {
      if ((localDW->SO_b_DoorRlsReq_prev != localDW->SO_b_DoorRlsReq_start) &&
          localDW->SO_b_DoorRlsReq_start) {
        localDW->SL_e_DoorRlsDelayTime = rtu_SI_e_DoorRlsDelayTime;
        localDW->is_MainProgress_c = REL_IN_Release;
        localDW->SL_e_CycleCount = 0U;
        *rty_SO_e_MotorPwm = 100U;
        localDW->is_Release_a = REL_IN_Delay;
        localDW->temporalCounter_i1 = 0U;
      }
    } else {
      /* case IN_Release: */
      switch (localDW->is_Release_a) {
       case REL_IN_Checking:
        {
          if ((localDW->temporalCounter_i1 >= 5) && rtu_SI_b_DoorAjar) {
            localDW->is_Release_a = REL_IN_Step2_Open;
            localDW->is_Step2_Open_i = REL_IN_Idle_m;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = false;
            *rty_SO_e_MotorCmd = Stop;
          } else {
            Boolean tmp_0;
            tmp_0 = !rtu_SI_b_DoorAjar;
            if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                (localDW->SL_e_CycleCount < 2)) {
              *rty_SO_e_MotorPwm = 100U;
              localDW->is_Release_a = REL_IN_Step1_Ajar;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_b_MotorA = true;
              *rty_SO_b_MotorB = false;
              *rty_SO_e_MotorCmd = Rls;
            } else if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                       (localDW->SL_e_CycleCount >= 2)) {
              localDW->is_Release_a = REL_IN_Reset;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_b_MotorA = false;
              *rty_SO_b_MotorB = true;
              *rty_SO_e_MotorCmd = Reset;
              *rty_SO_e_MotorPwm = 100U;
            }
          }
        }
        break;

       case REL_IN_Delay:
        if (localDW->temporalCounter_i1 >= localDW->SL_e_DoorRlsDelayTime) {
          localDW->is_Release_a = REL_IN_Step1_Ajar;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = true;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorCmd = Rls;
        }
        break;

       case REL_IN_Reset:
        if (localDW->temporalCounter_i1 >= 30) {
          localDW->is_Release_a = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_MainProgress_c = REL_IN_Idle;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorCmd = Stop;
          *rty_SO_e_MotorPwm = 0U;
        }
        break;

       case REL_IN_Step1_Ajar:
        {
          if (localDW->temporalCounter_i1 >= 30) {
            sint32 tmp;
            localDW->is_Release_a = REL_IN_Checking;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = false;
            *rty_SO_e_MotorCmd = Stop;
            tmp = localDW->SL_e_CycleCount + 1;
            if (localDW->SL_e_CycleCount + 1 > 255) {
              tmp = 255;
            }

            localDW->SL_e_CycleCount = (uint8)tmp;
          }
        }
        break;

       default:
        /* case IN_Step2_Open: */
        switch (localDW->is_Step2_Open_i) {
         case REL_IN_Fail:
          localDW->is_Step2_Open_i = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_Release_a = REL_IN_Reset;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorCmd = Reset;
          *rty_SO_e_MotorPwm = 100U;
          break;

         case REL_IN_Fail1:
          localDW->is_Step2_Open_i = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_Release_a = REL_IN_Reset;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorCmd = Reset;
          *rty_SO_e_MotorPwm = 100U;
          break;

         case REL_IN_Ice_Break:
          if ((localDW->temporalCounter_i1 < 600) && (!rtu_SI_b_CinchHome)) {
            localDW->is_Step2_Open_i = REL_IN_Success;
            *rty_SO_b_Error = false;
          } else if ((localDW->temporalCounter_i1 >= 600) && rtu_SI_b_CinchHome)
          {
            localDW->is_Step2_Open_i = REL_IN_Fail1;
            *rty_SO_b_Error = true;
          }
          break;

         case REL_IN_Idle_m:
          if ((localDW->temporalCounter_i1 < 270) && rtu_SI_b_DoorAjar) {
            localDW->is_Step2_Open_i = REL_IN_NO_ACTIVE_CHILD;
            localDW->is_Release_a = REL_IN_Reset;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = true;
            *rty_SO_e_MotorCmd = Reset;
            *rty_SO_e_MotorPwm = 100U;
          } else if (localDW->temporalCounter_i1 >= 300) {
            localDW->is_Step2_Open_i = REL_IN_LastCheck_o;
          }
          break;

         case REL_IN_LastCheck_o:
          if (!rtu_SI_b_CinchHome) {
            localDW->is_Step2_Open_i = REL_IN_Fail;
            *rty_SO_b_Error = true;
          } else {
            localDW->is_Step2_Open_i = REL_IN_Ice_Break;
            localDW->temporalCounter_i1 = 0U;
          }
          break;

         default:
          /* case IN_Success: */
          localDW->is_Step2_Open_i = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_Release_a = REL_IN_Reset;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorCmd = Reset;
          *rty_SO_e_MotorPwm = 100U;
          break;
        }
        break;
      }
    }

    /* case IN_NonElectricDoor: */
  } else if (localDW->is_MainProgress == REL_IN_Idle) {
    if ((localDW->SO_b_DoorRlsReq_prev != localDW->SO_b_DoorRlsReq_start) &&
        localDW->SO_b_DoorRlsReq_start) {
      localDW->SL_e_DoorRlsDelayTime = rtu_SI_e_DoorRlsDelayTime;
      localDW->is_MainProgress = REL_IN_Release;
      localDW->SL_e_CycleCount = 0U;
      *rty_SO_e_MotorPwm = 100U;
      localDW->is_Release = REL_IN_Delay;
      localDW->temporalCounter_i1 = 0U;
    }
  } else {
    /* case IN_Release: */
    switch (localDW->is_Release) {
     case REL_IN_Checking:
      {
        if ((localDW->temporalCounter_i1 >= 5) && rtu_SI_b_DoorAjar) {
          localDW->is_Release = REL_IN_Step2_Open;
          localDW->is_Step2_Open = REL_IN_Idle;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorCmd = Stop;
        } else {
          Boolean tmp_0;
          tmp_0 = !rtu_SI_b_DoorAjar;
          if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
              (localDW->SL_e_CycleCount < 2)) {
            *rty_SO_e_MotorPwm = 100U;
            localDW->is_Release = REL_IN_Step1_Ajar;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = true;
            *rty_SO_b_MotorB = false;
            *rty_SO_e_MotorCmd = Rls;
          } else if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                     (localDW->SL_e_CycleCount >= 2)) {
            localDW->is_Release = REL_IN_Reset;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = true;
            *rty_SO_e_MotorCmd = Reset;
            *rty_SO_e_MotorPwm = 100U;
          }
        }
      }
      break;

     case REL_IN_Delay:
      if (localDW->temporalCounter_i1 >= localDW->SL_e_DoorRlsDelayTime) {
        localDW->is_Release = REL_IN_Step1_Ajar;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_MotorA = true;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorCmd = Rls;
      }
      break;

     case REL_IN_Reset:
      if (localDW->temporalCounter_i1 >= 30) {
        localDW->is_Release = REL_IN_NO_ACTIVE_CHILD;
        localDW->is_MainProgress = REL_IN_Idle;
        *rty_SO_b_MotorA = false;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorCmd = Stop;
        *rty_SO_e_MotorPwm = 0U;
      }
      break;

     case REL_IN_Step1_Ajar:
      {
        if (localDW->temporalCounter_i1 >= 30) {
          sint32 tmp;
          localDW->is_Release = REL_IN_Checking;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorCmd = Stop;
          tmp = localDW->SL_e_CycleCount + 1;
          if (localDW->SL_e_CycleCount + 1 > 255) {
            tmp = 255;
          }

          localDW->SL_e_CycleCount = (uint8)tmp;
        }
      }
      break;

     default:
      /* case IN_Step2_Open: */
      if (localDW->is_Step2_Open == REL_IN_Idle) {
        if ((localDW->temporalCounter_i1 < 270) && rtu_SI_b_DoorAjar) {
          localDW->is_Step2_Open = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_Release = REL_IN_Reset;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorCmd = Reset;
          *rty_SO_e_MotorPwm = 100U;
        } else if (localDW->temporalCounter_i1 >= 300) {
          localDW->is_Step2_Open = REL_IN_LastCheck;
        }
      } else {
        /* case IN_LastCheck: */
        localDW->is_Step2_Open = REL_IN_NO_ACTIVE_CHILD;
        localDW->is_Release = REL_IN_Reset;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_MotorA = false;
        *rty_SO_b_MotorB = true;
        *rty_SO_e_MotorCmd = Reset;
        *rty_SO_e_MotorPwm = 100U;
      }
      break;
    }
  }
}

/*
 * System initialize for atomic system:
 *    '<S3>/FLDoorRlsDriver'
 *    '<S3>/FRDoorRlsDriver'
 *    '<S3>/RLDoorRlsDriver'
 *    '<S3>/RRDoorRlsDriver'
 */
void REL_FLDoorRlsDriver_Init(boolean *rty_SO_b_MotorA, boolean *rty_SO_b_MotorB,
  Mot_Cmd_E *rty_SO_e_MotorCmd, boolean *rty_SO_b_Error, uint8
  *rty_SO_e_MotorPwm)
{
  *rty_SO_b_MotorA = false;
  *rty_SO_b_MotorB = false;
  *rty_SO_e_MotorCmd = Stop;
  *rty_SO_b_Error = false;
  *rty_SO_e_MotorPwm = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S3>/FLDoorRlsDriver'
 *    '<S3>/FRDoorRlsDriver'
 *    '<S3>/RLDoorRlsDriver'
 *    '<S3>/RRDoorRlsDriver'
 */
void REL_FLDoorRlsDriver(boolean rtu_SO_b_DoorRlsReq, Boolean rtu_SI_b_DoorAjar,
  Boolean rtu_SI_b_CinchHome, Boolean rtu_SI_b_ElecDoorCfg, uint8
  rtu_SI_e_DoorRlsDelayTime, boolean *rty_SO_b_MotorA, boolean *rty_SO_b_MotorB,
  Mot_Cmd_E *rty_SO_e_MotorCmd, boolean *rty_SO_b_Error, uint8
  *rty_SO_e_MotorPwm, DW_FLDoorRlsDriver_REL_T *localDW)
{
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  localDW->SO_b_DoorRlsReq_prev = localDW->SO_b_DoorRlsReq_start;
  localDW->SO_b_DoorRlsReq_start = rtu_SO_b_DoorRlsReq;

  /* Chart: '<S3>/FLDoorRlsDriver' */
  if (localDW->is_active_c19_DoorRlsDriver == 0U) {
    localDW->SO_b_DoorRlsReq_prev = rtu_SO_b_DoorRlsReq;
    localDW->is_active_c19_DoorRlsDriver = 1U;
    localDW->is_c19_DoorRlsDriver = REL_IN_PowerOn;
    localDW->temporalCounter_i1 = 0U;
    *rty_SO_b_MotorA = false;
    *rty_SO_b_MotorB = true;
    *rty_SO_e_MotorCmd = Reset;
    *rty_SO_e_MotorPwm = 100U;
  } else if (localDW->is_c19_DoorRlsDriver == REL_IN_Normal) {
    REL_Normal(rtu_SI_b_DoorAjar, rtu_SI_b_CinchHome, rtu_SI_e_DoorRlsDelayTime,
               rty_SO_b_MotorA, rty_SO_b_MotorB, rty_SO_e_MotorCmd,
               rty_SO_b_Error, rty_SO_e_MotorPwm, localDW);

    /* case IN_PowerOn: */
  } else if (localDW->temporalCounter_i1 >= 30) {
    *rty_SO_b_MotorA = false;
    *rty_SO_b_MotorB = false;
    *rty_SO_e_MotorCmd = Stop;
    *rty_SO_e_MotorPwm = 100U;
    localDW->is_c19_DoorRlsDriver = REL_IN_Normal;
    if (!rtu_SI_b_ElecDoorCfg) {
      localDW->is_Normal = REL_IN_NonElectricDoor;
      localDW->is_MainProgress = REL_IN_Idle;
      *rty_SO_b_MotorA = false;
      *rty_SO_b_MotorB = false;
      *rty_SO_e_MotorCmd = Stop;
      *rty_SO_e_MotorPwm = 0U;
    } else {
      localDW->is_Normal = REL_IN_ElectricDoor;
      localDW->is_MainProgress_c = REL_IN_Idle;
      *rty_SO_b_MotorA = false;
      *rty_SO_b_MotorB = false;
      *rty_SO_e_MotorCmd = Stop;
      *rty_SO_e_MotorPwm = 0U;
    }
  }

  /* End of Chart: '<S3>/FLDoorRlsDriver' */
}

/* Function for Chart: '<S3>/RLDoorRlsReq' */
static void REL_DoorInBtn(UInt8 rtu_SI_e_EspVehSpd, Boolean
  rtu_SI_b_EspVehSpdVld, Gear_Posn_E rtu_SI_m_VcuGearPosn, Door_Sts_E
  rtu_SI_m_DoorLockSts, Rat_Sts_E rtu_SI_m_DoorRatSts, Boolean
  rtu_SI_b_ChildLckSts, boolean *rty_SO_b_DoorRlsReq, uint8
  *rty_SO_e_DoorRlsDelayTime, Unlock_Req_E *rty_SO_m_UnlockReq,
  DW_RLDoorRlsReq_REL_T *localDW)
{
  switch (localDW->is_SwValid) {
   case REL_IN_Idle_i:
    if ((localDW->SI_b_DoorInBtnSts_prev != localDW->SI_b_DoorInBtnSts_start) &&
        localDW->SI_b_DoorInBtnSts_start) {
      localDW->is_SwValid = REL_IN_Once;
      localDW->temporalCounter_i4 = 0U;
    }
    break;

   case REL_IN_Once:
    if ((localDW->SI_b_DoorInBtnSts_prev != localDW->SI_b_DoorInBtnSts_start) &&
        localDW->SI_b_DoorInBtnSts_start) {
      localDW->is_SwValid = REL_IN_Twice;
      localDW->temporalCounter_i4 = 0U;
      localDW->SL_b_DoorInBtnValid = true;
    } else if (localDW->temporalCounter_i4 >= 200) {
      localDW->is_SwValid = REL_IN_Idle_i;
      localDW->SL_b_DoorInBtnValid = false;
    }
    break;

   default:
    /* case IN_Twice: */
    if (localDW->temporalCounter_i4 >= 3) {
      localDW->is_SwValid = REL_IN_Idle_i;
      localDW->SL_b_DoorInBtnValid = false;
    }
    break;
  }

  if (localDW->is_RlsReq == REL_IN_Idle_i) {
    if ((((rtu_SI_e_EspVehSpd <= 0) && (!rtu_SI_b_EspVehSpdVld)) ||
         (rtu_SI_m_VcuGearPosn == Gear_P)) && (!rtu_SI_b_ChildLckSts) &&
        ((localDW->SL_b_DoorInBtnValid_prev !=
          localDW->SL_b_DoorInBtnValid_start) &&
         localDW->SL_b_DoorInBtnValid_start)) {
      localDW->is_RlsReq = REL_IN_Trigger;
      switch (rtu_SI_m_DoorLockSts) {
       case Door_Lock:
        localDW->is_Trigger = REL_IN_DoorLock;
        localDW->is_DoorLock = REL_IN_UnlockReq;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_m_UnlockReq = Unlock_Req;
        break;

       case Door_Unlock:
        localDW->is_Trigger = REL_IN_DoorUnlock;
        break;

       default:
        localDW->is_Trigger = REL_IN_Error;
        break;
      }
    }

    /* case IN_Trigger: */
  } else if (((rtu_SI_e_EspVehSpd >= 1) && (!rtu_SI_b_EspVehSpdVld) &&
              (rtu_SI_m_VcuGearPosn != Gear_P)) || rtu_SI_b_ChildLckSts ||
             ((rtu_SI_m_DoorLockSts == Door_Unlock) && (rtu_SI_m_DoorRatSts ==
               Rat_Unlock))) {
    localDW->is_DoorLock = REL_IN_NO_ACTIVE_CHILD_d;
    localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_d;
    localDW->is_RlsReq = REL_IN_Idle_i;
  } else {
    switch (localDW->is_Trigger) {
     case REL_IN_DoorLock:
      switch (localDW->is_DoorLock) {
       case REL_IN_UnlockFail:
        localDW->is_DoorLock = REL_IN_NO_ACTIVE_CHILD_d;
        localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_d;
        localDW->is_RlsReq = REL_IN_Idle_i;
        break;

       case REL_IN_UnlockReq:
        if (rtu_SI_m_DoorLockSts == Door_Unlock) {
          localDW->is_DoorLock = REL_IN_UnlockSuccess;
        } else if ((localDW->temporalCounter_i1 >= 50) && (rtu_SI_m_DoorLockSts ==
                    Door_Lock)) {
          localDW->is_DoorLock = REL_IN_UnlockFail;
        } else if (localDW->temporalCounter_i1 == 5) {
          *rty_SO_m_UnlockReq = Unlock_Idle;
        }
        break;

       default:
        /* case IN_UnlockSuccess: */
        if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
          localDW->is_DoorLock = REL_IN_NO_ACTIVE_CHILD_d;
          localDW->is_Trigger = REL_IN_Release_o;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_DoorRlsReq = true;
          *rty_SO_e_DoorRlsDelayTime = 20U;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock:
      if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
        localDW->is_Trigger = REL_IN_Release_o;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_DoorRlsReq = true;
        *rty_SO_e_DoorRlsDelayTime = 20U;
      }
      break;

     case REL_IN_Error:
      localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_d;
      localDW->is_RlsReq = REL_IN_Idle_i;
      break;

     default:
      /* case IN_Release: */
      if (localDW->temporalCounter_i1 >= 5) {
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_e_DoorRlsDelayTime = 0U;
        localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_d;
        localDW->is_RlsReq = REL_IN_Idle_i;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/RLDoorRlsReq' */
static void REL_DoorHndBtn(UInt8 rtu_SI_e_EspVehSpd, Boolean
  rtu_SI_b_EspVehSpdVld, Gear_Posn_E rtu_SI_m_VcuGearPosn, Door_Sts_E
  rtu_SI_m_DoorLockSts, Rat_Sts_E rtu_SI_m_DoorRatSts, boolean
  *rty_SO_b_DoorRlsReq, Unlock_Req_E *rty_SO_m_UnlockReq, DW_RLDoorRlsReq_REL_T *
  localDW)
{
  if (localDW->is_RlsReq_e == REL_IN_Idle_i) {
    if ((((rtu_SI_e_EspVehSpd <= 0) && (!rtu_SI_b_EspVehSpdVld)) ||
         (rtu_SI_m_VcuGearPosn == Gear_P)) &&
        ((localDW->SL_b_DoorHndBtnValid_prev !=
          localDW->SL_b_DoorHndBtnValid_start) &&
         localDW->SL_b_DoorHndBtnValid_start)) {
      localDW->is_RlsReq_e = REL_IN_Trigger;
      switch (rtu_SI_m_DoorLockSts) {
       case Door_Lock:
        localDW->is_Trigger_c = REL_IN_DoorLock;
        localDW->is_DoorLock_n = REL_IN_UnlockReq;
        localDW->temporalCounter_i2 = 0U;
        *rty_SO_m_UnlockReq = Unlock_PE;
        break;

       case Door_Unlock:
        localDW->is_Trigger_c = REL_IN_DoorUnlock;
        break;

       default:
        localDW->is_Trigger_c = REL_IN_Error;
        break;
      }
    }

    /* case IN_Trigger: */
  } else if (((rtu_SI_e_EspVehSpd >= 1) && (!rtu_SI_b_EspVehSpdVld) &&
              (rtu_SI_m_VcuGearPosn != Gear_P)) || ((rtu_SI_m_DoorLockSts ==
               Door_Unlock) && (rtu_SI_m_DoorRatSts == Rat_Unlock))) {
    localDW->is_DoorLock_n = REL_IN_NO_ACTIVE_CHILD_d;
    localDW->is_Trigger_c = REL_IN_NO_ACTIVE_CHILD_d;
    localDW->is_RlsReq_e = REL_IN_Idle_i;
  } else {
    switch (localDW->is_Trigger_c) {
     case REL_IN_DoorLock:
      switch (localDW->is_DoorLock_n) {
       case REL_IN_UnlockFail:
        localDW->is_DoorLock_n = REL_IN_NO_ACTIVE_CHILD_d;
        localDW->is_Trigger_c = REL_IN_NO_ACTIVE_CHILD_d;
        localDW->is_RlsReq_e = REL_IN_Idle_i;
        break;

       case REL_IN_UnlockReq:
        if (rtu_SI_m_DoorLockSts == Door_Unlock) {
          localDW->is_DoorLock_n = REL_IN_UnlockSuccess;
        } else if ((localDW->temporalCounter_i2 >= 50) && (rtu_SI_m_DoorLockSts ==
                    Door_Lock)) {
          localDW->is_DoorLock_n = REL_IN_UnlockFail;
        } else if (localDW->temporalCounter_i2 == 5) {
          *rty_SO_m_UnlockReq = Unlock_Idle;
        }
        break;

       default:
        /* case IN_UnlockSuccess: */
        if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
          localDW->is_DoorLock_n = REL_IN_NO_ACTIVE_CHILD_d;
          localDW->is_Trigger_c = REL_IN_Release_o;
          localDW->temporalCounter_i2 = 0U;
          *rty_SO_b_DoorRlsReq = true;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock:
      if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
        localDW->is_Trigger_c = REL_IN_Release_o;
        localDW->temporalCounter_i2 = 0U;
        *rty_SO_b_DoorRlsReq = true;
      }
      break;

     case REL_IN_Error:
      break;

     default:
      /* case IN_Release: */
      if (localDW->temporalCounter_i2 >= 5) {
        *rty_SO_b_DoorRlsReq = false;
        localDW->is_Trigger_c = REL_IN_NO_ACTIVE_CHILD_d;
        localDW->is_RlsReq_e = REL_IN_Idle_i;
      }
      break;
    }
  }

  switch (localDW->is_SwValid_f) {
   case REL_IN_Idle_i:
    if ((localDW->SI_b_DoorHndBtnSts_prev != localDW->SI_b_DoorHndBtnSts_start) &&
        localDW->SI_b_DoorHndBtnSts_start) {
      localDW->is_SwValid_f = REL_IN_Press;
      localDW->temporalCounter_i6 = 0U;
    }
    break;

   case REL_IN_Press:
    if ((localDW->SI_b_DoorHndBtnSts_prev != localDW->SI_b_DoorHndBtnSts_start) &&
        (!localDW->SI_b_DoorHndBtnSts_start)) {
      localDW->is_SwValid_f = REL_IN_Release_oat;
      localDW->temporalCounter_i6 = 0U;
      localDW->SL_b_DoorHndBtnValid = true;
    } else if (localDW->temporalCounter_i6 >= 100) {
      localDW->is_SwValid_f = REL_IN_Idle_i;
      localDW->SL_b_DoorHndBtnValid = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (localDW->temporalCounter_i6 >= 3) {
      localDW->is_SwValid_f = REL_IN_Idle_i;
      localDW->SL_b_DoorHndBtnValid = false;
    }
    break;
  }
}

/*
 * System initialize for atomic system:
 *    '<S3>/RLDoorRlsReq'
 *    '<S3>/RRDoorRlsReq'
 */
void REL_RLDoorRlsReq_Init(boolean *rty_SO_b_DoorRlsReq, uint8
  *rty_SO_e_DoorRlsDelayTime, Unlock_Req_E *rty_SO_m_UnlockReq)
{
  *rty_SO_b_DoorRlsReq = false;
  *rty_SO_e_DoorRlsDelayTime = 0U;
  *rty_SO_m_UnlockReq = Unlock_Idle;
}

/*
 * Output and update for atomic system:
 *    '<S3>/RLDoorRlsReq'
 *    '<S3>/RRDoorRlsReq'
 */
void REL_RLDoorRlsReq(boolean rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd, Boolean
                      rtu_SI_b_EspVehSpdVld, Gear_Posn_E rtu_SI_m_VcuGearPosn,
                      Door_Sts_E rtu_SI_m_DoorLockSts, Rat_Sts_E
                      rtu_SI_m_DoorRatSts, boolean rtu_SI_b_DoorInBtnSts,
                      boolean rtu_SI_b_DoorHndPullSts, boolean
                      rtu_SI_b_DoorHndBtnSts, HndPos_Sts_E
                      rtu_SI_m_DoorHandPosSts, Boolean
                      rtu_SI_b_CentSingleDoorBtnSts, Boolean
                      rtu_SI_b_CentAllDoorBtnSts, Boolean rtu_SI_b_ChildLckSts,
                      boolean rtu_SI_b_DoorAutoRlsSetSts, boolean
                      rtu_SI_b_DoorAutoRlsReq, boolean *rty_SO_b_DoorRlsReq,
                      uint8 *rty_SO_e_DoorRlsDelayTime, Unlock_Req_E
                      *rty_SO_m_UnlockReq, DW_RLDoorRlsReq_REL_T *localDW)
{
  if (localDW->temporalCounter_i1 < 63U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->temporalCounter_i2 < 63U) {
    localDW->temporalCounter_i2++;
  }

  if (localDW->temporalCounter_i3 < 63U) {
    localDW->temporalCounter_i3++;
  }

  if (localDW->temporalCounter_i4 < 255U) {
    localDW->temporalCounter_i4++;
  }

  if (localDW->temporalCounter_i5 < 7U) {
    localDW->temporalCounter_i5++;
  }

  if (localDW->temporalCounter_i6 < 127U) {
    localDW->temporalCounter_i6++;
  }

  if (localDW->temporalCounter_i7 < 7U) {
    localDW->temporalCounter_i7++;
  }

  localDW->SI_b_DoorInBtnSts_prev = localDW->SI_b_DoorInBtnSts_start;
  localDW->SI_b_DoorInBtnSts_start = rtu_SI_b_DoorInBtnSts;
  localDW->SL_b_DoorInBtnValid_prev = localDW->SL_b_DoorInBtnValid_start;
  localDW->SL_b_DoorInBtnValid_start = localDW->SL_b_DoorInBtnValid;
  localDW->SL_b_DoorHndPullValid_prev = localDW->SL_b_DoorHndPullValid_start;
  localDW->SL_b_DoorHndPullValid_start = localDW->SL_b_DoorHndPullValid;
  localDW->SI_b_DoorHndBtnSts_prev = localDW->SI_b_DoorHndBtnSts_start;
  localDW->SI_b_DoorHndBtnSts_start = rtu_SI_b_DoorHndBtnSts;
  localDW->SL_b_DoorHndBtnValid_prev = localDW->SL_b_DoorHndBtnValid_start;
  localDW->SL_b_DoorHndBtnValid_start = localDW->SL_b_DoorHndBtnValid;
  localDW->SL_b_CentSingleDoorBtnValid_pre =
    localDW->SL_b_CentSingleDoorBtnValid_sta;
  localDW->SL_b_CentSingleDoorBtnValid_sta =
    localDW->SL_b_CentSingleDoorBtnValid;
  localDW->SL_b_CentAllDoorBtnValid_prev =
    localDW->SL_b_CentAllDoorBtnValid_start;
  localDW->SL_b_CentAllDoorBtnValid_start = localDW->SL_b_CentAllDoorBtnValid;
  localDW->SI_b_DoorAutoRlsReq_prev = localDW->SI_b_DoorAutoRlsReq_start;
  localDW->SI_b_DoorAutoRlsReq_start = rtu_SI_b_DoorAutoRlsReq;

  /* Chart: '<S3>/RLDoorRlsReq' */
  if (localDW->is_active_c5_DoorRlsReq == 0U) {
    localDW->SI_b_DoorInBtnSts_prev = rtu_SI_b_DoorInBtnSts;
    localDW->SI_b_DoorHndBtnSts_prev = rtu_SI_b_DoorHndBtnSts;
    localDW->SI_b_DoorAutoRlsReq_prev = rtu_SI_b_DoorAutoRlsReq;
    localDW->is_active_c5_DoorRlsReq = 1U;
    localDW->is_SwValid = REL_IN_Idle_i;
    localDW->SL_b_DoorInBtnValid = false;
    localDW->is_RlsReq = REL_IN_Idle_i;
    localDW->SL_b_DoorHndPullValid = rtu_SI_b_DoorHndPullSts;
    localDW->is_RlsReq_i = REL_IN_Idle_i;
    localDW->is_RlsReq_e = REL_IN_Idle_i;
    localDW->is_SwValid_f = REL_IN_Idle_i;
    localDW->SL_b_DoorHndBtnValid = false;
    localDW->is_DoorCentral = REL_IN_Idle_i;
    localDW->SL_b_CentSingleDoorBtnValid = rtu_SI_b_CentSingleDoorBtnSts;
    localDW->SL_b_CentAllDoorBtnValid = rtu_SI_b_CentAllDoorBtnSts;
    localDW->is_RlsReq_h = REL_IN_Idle_i;
  } else {
    REL_DoorInBtn(rtu_SI_e_EspVehSpd, rtu_SI_b_EspVehSpdVld,
                  rtu_SI_m_VcuGearPosn, rtu_SI_m_DoorLockSts,
                  rtu_SI_m_DoorRatSts, rtu_SI_b_ChildLckSts, rty_SO_b_DoorRlsReq,
                  rty_SO_e_DoorRlsDelayTime, rty_SO_m_UnlockReq, localDW);
    localDW->SL_b_DoorHndPullValid = rtu_SI_b_DoorHndPullSts;
    if (localDW->is_RlsReq_i == REL_IN_Idle_i) {
      if ((!rtu_SI_b_OFF) && (((rtu_SI_e_EspVehSpd <= 0) &&
            (!rtu_SI_b_EspVehSpdVld)) || (rtu_SI_m_VcuGearPosn == Gear_P)) &&
          (rtu_SI_m_DoorLockSts == Door_Unlock) && (rtu_SI_m_DoorHandPosSts ==
           Hnd_Unfold) && ((localDW->SL_b_DoorHndPullValid_prev !=
                            localDW->SL_b_DoorHndPullValid_start) &&
                           localDW->SL_b_DoorHndPullValid_start)) {
        localDW->is_RlsReq_i = REL_IN_Trigger;
        localDW->is_Trigger_g = REL_IN_DoorUnlock_i;
      }

      /* case IN_Trigger: */
    } else if (rtu_SI_b_OFF || ((rtu_SI_e_EspVehSpd >= 1) &&
                (!rtu_SI_b_EspVehSpdVld) && (rtu_SI_m_VcuGearPosn != Gear_P)) ||
               (rtu_SI_m_DoorLockSts != Door_Unlock) || (rtu_SI_m_DoorHandPosSts
                != Hnd_Unfold) || (rtu_SI_m_DoorRatSts == Rat_Unlock)) {
      localDW->is_Trigger_g = REL_IN_NO_ACTIVE_CHILD_d;
      localDW->is_RlsReq_i = REL_IN_Idle_i;
    } else if (localDW->is_Trigger_g == REL_IN_DoorUnlock_i) {
      if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
        localDW->is_Trigger_g = REL_IN_Release_oa;
        localDW->temporalCounter_i5 = 0U;
        *rty_SO_b_DoorRlsReq = true;
        *rty_SO_e_DoorRlsDelayTime = 4U;
      }

      /* case IN_Release: */
    } else if (localDW->temporalCounter_i5 >= 5) {
      *rty_SO_b_DoorRlsReq = false;
      *rty_SO_e_DoorRlsDelayTime = 0U;
      localDW->is_Trigger_g = REL_IN_NO_ACTIVE_CHILD_d;
      localDW->is_RlsReq_i = REL_IN_Idle_i;
    }

    REL_DoorHndBtn(rtu_SI_e_EspVehSpd, rtu_SI_b_EspVehSpdVld,
                   rtu_SI_m_VcuGearPosn, rtu_SI_m_DoorLockSts,
                   rtu_SI_m_DoorRatSts, rty_SO_b_DoorRlsReq, rty_SO_m_UnlockReq,
                   localDW);
    if (localDW->is_DoorCentral == REL_IN_Idle_i) {
      if ((!rtu_SI_b_OFF) && (((rtu_SI_e_EspVehSpd <= 0) &&
            (!rtu_SI_b_EspVehSpdVld)) || (rtu_SI_m_VcuGearPosn == Gear_P)) &&
          (((localDW->SL_b_CentSingleDoorBtnValid_pre !=
             localDW->SL_b_CentSingleDoorBtnValid_sta) &&
            localDW->SL_b_CentSingleDoorBtnValid_sta) ||
           ((localDW->SL_b_CentAllDoorBtnValid_prev !=
             localDW->SL_b_CentAllDoorBtnValid_start) &&
            localDW->SL_b_CentAllDoorBtnValid_start))) {
        localDW->is_DoorCentral = REL_IN_Trigger;
        switch (rtu_SI_m_DoorLockSts) {
         case Door_Lock:
          localDW->is_Trigger_f = REL_IN_DoorLock;
          localDW->is_DoorLock_o = REL_IN_UnlockReq;
          localDW->temporalCounter_i3 = 0U;
          *rty_SO_m_UnlockReq = Unlock_Req;
          break;

         case Door_Unlock:
          localDW->is_Trigger_f = REL_IN_DoorUnlock;
          break;

         default:
          localDW->is_Trigger_f = REL_IN_Error;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (rtu_SI_b_OFF || ((rtu_SI_e_EspVehSpd >= 1) &&
                (!rtu_SI_b_EspVehSpdVld) && (rtu_SI_m_VcuGearPosn != Gear_P)) ||
               ((rtu_SI_m_DoorLockSts == Door_Unlock) && (rtu_SI_m_DoorRatSts ==
      Rat_Unlock))) {
      localDW->is_DoorLock_o = REL_IN_NO_ACTIVE_CHILD_d;
      localDW->is_Trigger_f = REL_IN_NO_ACTIVE_CHILD_d;
      localDW->is_DoorCentral = REL_IN_Idle_i;
    } else {
      switch (localDW->is_Trigger_f) {
       case REL_IN_DoorLock:
        switch (localDW->is_DoorLock_o) {
         case REL_IN_UnlockFail:
          localDW->is_DoorLock_o = REL_IN_NO_ACTIVE_CHILD_d;
          localDW->is_Trigger_f = REL_IN_NO_ACTIVE_CHILD_d;
          localDW->is_DoorCentral = REL_IN_Idle_i;
          break;

         case REL_IN_UnlockReq:
          if (rtu_SI_m_DoorLockSts == Door_Unlock) {
            localDW->is_DoorLock_o = REL_IN_UnlockSucess;
          } else if ((localDW->temporalCounter_i3 >= 50) &&
                     (rtu_SI_m_DoorLockSts == Door_Lock)) {
            localDW->is_DoorLock_o = REL_IN_UnlockFail;
          } else if (localDW->temporalCounter_i3 == 5) {
            *rty_SO_m_UnlockReq = Unlock_Idle;
          }
          break;

         default:
          /* case IN_UnlockSucess: */
          if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
            localDW->is_DoorLock_o = REL_IN_NO_ACTIVE_CHILD_d;
            localDW->is_Trigger_f = REL_IN_RELEASE;
            localDW->temporalCounter_i3 = 0U;
            *rty_SO_b_DoorRlsReq = true;
          }
          break;
        }
        break;

       case REL_IN_DoorUnlock:
        if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
          localDW->is_Trigger_f = REL_IN_RELEASE;
          localDW->temporalCounter_i3 = 0U;
          *rty_SO_b_DoorRlsReq = true;
        }
        break;

       case REL_IN_Error:
        localDW->is_Trigger_f = REL_IN_NO_ACTIVE_CHILD_d;
        localDW->is_DoorCentral = REL_IN_Idle_i;
        break;

       default:
        /* case IN_RELEASE: */
        if (localDW->temporalCounter_i3 >= 5) {
          *rty_SO_b_DoorRlsReq = false;
          localDW->is_Trigger_f = REL_IN_NO_ACTIVE_CHILD_d;
          localDW->is_DoorCentral = REL_IN_Idle_i;
        }
        break;
      }
    }

    localDW->SL_b_CentSingleDoorBtnValid = rtu_SI_b_CentSingleDoorBtnSts;
    localDW->SL_b_CentAllDoorBtnValid = rtu_SI_b_CentAllDoorBtnSts;
    if (localDW->is_RlsReq_h == REL_IN_Idle_i) {
      if ((!rtu_SI_b_OFF) && (((rtu_SI_e_EspVehSpd <= 0) &&
            (!rtu_SI_b_EspVehSpdVld)) || (rtu_SI_m_VcuGearPosn == Gear_P)) &&
          rtu_SI_b_DoorAutoRlsSetSts && (rtu_SI_m_DoorLockSts == Door_Unlock) &&
          ((localDW->SI_b_DoorAutoRlsReq_prev !=
            localDW->SI_b_DoorAutoRlsReq_start) &&
           localDW->SI_b_DoorAutoRlsReq_start)) {
        localDW->is_RlsReq_h = REL_IN_Trigger;
        localDW->is_Trigger_l = REL_IN_DoorUnlock_i;
      }

      /* case IN_Trigger: */
    } else if (rtu_SI_b_OFF || ((rtu_SI_e_EspVehSpd >= 1) &&
                (!rtu_SI_b_EspVehSpdVld) && (rtu_SI_m_VcuGearPosn != Gear_P)) ||
               (!rtu_SI_b_DoorAutoRlsSetSts) || (rtu_SI_m_DoorLockSts !=
                Door_Unlock) || (rtu_SI_m_DoorRatSts == Rat_Unlock)) {
      localDW->is_Trigger_l = REL_IN_NO_ACTIVE_CHILD_d;
      localDW->is_RlsReq_h = REL_IN_Idle_i;
    } else if (localDW->is_Trigger_l == REL_IN_DoorUnlock_i) {
      if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
        localDW->is_Trigger_l = REL_IN_Release_oa;
        localDW->temporalCounter_i7 = 0U;
        *rty_SO_b_DoorRlsReq = true;
      }

      /* case IN_Release: */
    } else if (localDW->temporalCounter_i7 >= 5) {
      *rty_SO_b_DoorRlsReq = false;
      localDW->is_Trigger_l = REL_IN_NO_ACTIVE_CHILD_d;
      localDW->is_RlsReq_h = REL_IN_Idle_i;
    }
  }

  /* End of Chart: '<S3>/RLDoorRlsReq' */
}

/* Function for Chart: '<S3>/DoorSwSts' */
static void REL_enter_atomic_NoCrash(boolean *SL_b_FLDoorHndPullSts, boolean
  *SL_b_FRDoorHndPullSts, boolean *SL_b_FLDoorHndBtnSts)
{
  /* Inport: '<Root>/VbINP_HWA_RRDoorHandleSW_flg_VbINP_HWA_RRDoorHandleSW_flg' */
  (void)Rte_Read_VbINP_HWA_RRDoorHandleSW_flg_VbINP_HWA_RRDoorHandleSW_flg
    (&REL_B.SL_b_RRDoorHndBtnSts);

  /* Inport: '<Root>/VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg' */
  (void)Rte_Read_VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg
    (&REL_B.SL_b_RLDoorHndBtnSts);

  /* Inport: '<Root>/VbINP_HWA_FRDoorHandleSW_flg_VbINP_HWA_FRDoorHandleSW_flg' */
  (void)Rte_Read_VbINP_HWA_FRDoorHandleSW_flg_VbINP_HWA_FRDoorHandleSW_flg
    (&REL_B.SL_b_FRDoorHndBtnSts);

  /* Inport: '<Root>/VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg' */
  (void)Rte_Read_VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg
    (SL_b_FLDoorHndBtnSts);

  /* Inport: '<Root>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg' */
  (void)Rte_Read_VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg
    (&REL_B.SL_b_RRDoorHndPullSts);

  /* Inport: '<Root>/VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg' */
  (void)Rte_Read_VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg
    (&REL_B.SL_b_RLDoorHndPullSts);

  /* Inport: '<Root>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg' */
  (void)Rte_Read_VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg
    (SL_b_FRDoorHndPullSts);

  /* Inport: '<Root>/VbINP_HWA_FLDoorOutButton_flg_VbINP_HWA_FLDoorOutButton_flg' */
  (void)Rte_Read_VbINP_HWA_FLDoorOutButton_flg_VbINP_HWA_FLDoorOutButton_flg
    (SL_b_FLDoorHndPullSts);

  /* Inport: '<Root>/VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg' */
  (void)Rte_Read_VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg
    (&REL_B.SL_b_RRDoorInBtnSts);

  /* Inport: '<Root>/VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg' */
  (void)Rte_Read_VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg
    (&REL_B.SL_b_RLDoorInBtnSts);

  /* Inport: '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg' */
  (void)Rte_Read_VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg
    (&REL_B.SL_b_FRDoorInBtnSts);

  /* Inport: '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg' */
  (void)Rte_Read_VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg
    (&REL_B.SL_b_FLDoorInBtnSts);
}

/* Function for Chart: '<S3>/DoorRatSts' */
static float64 REL_GetDoorRatSts(float64 ajar, float64 open)
{
  float64 status;
  if ((ajar == 0.0) && (open == 0.0)) {
    status = 1.0;
  } else if ((ajar == 1.0) && (open == 0.0)) {
    status = 2.0;
  } else if ((ajar == 1.0) && (open == 1.0)) {
    status = 3.0;
  } else {
    status = 0.0;
  }

  return status;
}

static uint8 REL_safe_cast_to_Rat_Sts_E(uint8 input)
{
  uint8 output;

  /* Initialize output value to default value for Rat_Sts_E (Rat_Invalid) */
  output = 0U;
  if (input <= 3) {
    /* Set output value to input value if it is a member of Rat_Sts_E */
    output = input;
  }

  return output;
}

/* Function for Chart: '<S3>/FRDoorRlsReq' */
static void REL_DoorInBtn_n(const Rat_Sts_E *SO_m_FRDoorRatSts)
{
  switch (REL_DW.is_SwValid) {
   case REL_IN_Idle_p:
    if ((REL_DW.SI_b_DoorInBtnSts_prev != REL_DW.SI_b_DoorInBtnSts_start) &&
        REL_DW.SI_b_DoorInBtnSts_start) {
      REL_DW.is_SwValid = REL_IN_Once_o;
      REL_DW.temporalCounter_i4 = 0U;
    }
    break;

   case REL_IN_Once_o:
    if ((REL_DW.SI_b_DoorInBtnSts_prev != REL_DW.SI_b_DoorInBtnSts_start) &&
        REL_DW.SI_b_DoorInBtnSts_start) {
      REL_DW.is_SwValid = REL_IN_Twice_i;
      REL_DW.temporalCounter_i4 = 0U;
      REL_DW.SL_b_DoorInBtnValid = true;
    } else if (REL_DW.temporalCounter_i4 >= 200) {
      REL_DW.is_SwValid = REL_IN_Idle_p;
      REL_DW.SL_b_DoorInBtnValid = false;
    }
    break;

   default:
    /* case IN_Twice: */
    if (REL_DW.temporalCounter_i4 >= 3) {
      REL_DW.is_SwValid = REL_IN_Idle_p;
      REL_DW.SL_b_DoorInBtnValid = false;
    }
    break;
  }

  if (REL_DW.is_RlsReq == REL_IN_Idle_p) {
    /* DataTypeConversion: '<S3>/Data Type Conversion14' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion13'
     */
    if ((((REL_B.TmpSignalConversionAtVeOUT_SP_E <= 0) &&
          (!REL_B.TmpSignalConversionAtVbINP_CAN_)) ||
         (REL_B.DataTypeConversion14 == Gear_P)) &&
        ((REL_DW.SL_b_DoorInBtnValid_prev != REL_DW.SL_b_DoorInBtnValid_start) &&
         REL_DW.SL_b_DoorInBtnValid_start)) {
      REL_DW.is_RlsReq = REL_IN_Trigger_h;
      switch (REL_B.DataTypeConversion13) {
       case Door_Lock:
        REL_DW.is_Trigger = REL_IN_DoorLock_f;
        REL_DW.is_DoorLock = REL_IN_UnlockReq_k;
        REL_DW.temporalCounter_i1_e = 0U;
        REL_B.SO_m_UnlockReq_d = Unlock_Req;
        break;

       case Door_Unlock:
        REL_DW.is_Trigger = REL_IN_DoorUnlock_g;
        break;

       default:
        REL_DW.is_Trigger = REL_IN_Error_a;
        break;
      }
    }

    /* DataTypeConversion: '<S3>/Data Type Conversion14' */
    /* case IN_Trigger: */
  } else if (((REL_B.TmpSignalConversionAtVeOUT_SP_E >= 1) &&
              (!REL_B.TmpSignalConversionAtVbINP_CAN_) &&
              (REL_B.DataTypeConversion14 != Gear_P)) ||
             ((REL_B.DataTypeConversion13 == Door_Unlock) && (*SO_m_FRDoorRatSts
    == Rat_Unlock))) {
    REL_DW.is_DoorLock = 0;
    REL_DW.is_Trigger = 0;
    REL_DW.is_RlsReq = REL_IN_Idle_p;
  } else {
    switch (REL_DW.is_Trigger) {
     case REL_IN_DoorLock_f:
      switch (REL_DW.is_DoorLock) {
       case REL_IN_UnlockFail_i:
        REL_DW.is_DoorLock = 0;
        REL_DW.is_Trigger = 0;
        REL_DW.is_RlsReq = REL_IN_Idle_p;
        break;

       case REL_IN_UnlockReq_k:
        if (REL_B.DataTypeConversion13 == Door_Unlock) {
          REL_DW.is_DoorLock = REL_IN_UnlockSuccess_p;
        } else if ((REL_DW.temporalCounter_i1_e >= 50) &&
                   (REL_B.DataTypeConversion13 == Door_Lock)) {
          REL_DW.is_DoorLock = REL_IN_UnlockFail_i;
        } else if (REL_DW.temporalCounter_i1_e == 5) {
          REL_B.SO_m_UnlockReq_d = Unlock_Idle;
        }
        break;

       default:
        /* case IN_UnlockSuccess: */
        if (*SO_m_FRDoorRatSts != Rat_Unlock) {
          REL_DW.is_DoorLock = 0;
          REL_DW.is_Trigger = REL_IN_Release_n;
          REL_DW.temporalCounter_i1_e = 0U;
          REL_B.SO_b_DoorRlsReq_l = true;
          REL_B.SO_e_DoorRlsDelayTime_k = 20U;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock_g:
      if (*SO_m_FRDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger = REL_IN_Release_n;
        REL_DW.temporalCounter_i1_e = 0U;
        REL_B.SO_b_DoorRlsReq_l = true;
        REL_B.SO_e_DoorRlsDelayTime_k = 20U;
      }
      break;

     case REL_IN_Error_a:
      REL_DW.is_Trigger = 0;
      REL_DW.is_RlsReq = REL_IN_Idle_p;
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i1_e >= 5) {
        REL_B.SO_b_DoorRlsReq_l = false;
        REL_B.SO_e_DoorRlsDelayTime_k = 0U;
        REL_DW.is_Trigger = 0;
        REL_DW.is_RlsReq = REL_IN_Idle_p;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/FRDoorRlsReq' */
static void REL_DoorHndBtn_c(const Rat_Sts_E *SO_m_FRDoorRatSts)
{
  if (REL_DW.is_RlsReq_n == REL_IN_Idle_p) {
    /* DataTypeConversion: '<S3>/Data Type Conversion14' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion13'
     */
    if ((((REL_B.TmpSignalConversionAtVeOUT_SP_E <= 0) &&
          (!REL_B.TmpSignalConversionAtVbINP_CAN_)) ||
         (REL_B.DataTypeConversion14 == Gear_P)) &&
        ((REL_DW.SL_b_DoorHndBtnValid_prev != REL_DW.SL_b_DoorHndBtnValid_start)
         && REL_DW.SL_b_DoorHndBtnValid_start)) {
      REL_DW.is_RlsReq_n = REL_IN_Trigger_h;
      switch (REL_B.DataTypeConversion13) {
       case Door_Lock:
        REL_DW.is_Trigger_f = REL_IN_DoorLock_f;
        REL_DW.is_DoorLock_m = REL_IN_UnlockReq_k;
        REL_DW.temporalCounter_i2 = 0U;
        REL_B.SO_m_UnlockReq_d = Unlock_PE;
        break;

       case Door_Unlock:
        REL_DW.is_Trigger_f = REL_IN_DoorUnlock_g;
        break;

       default:
        REL_DW.is_Trigger_f = REL_IN_Error_a;
        break;
      }
    }

    /* DataTypeConversion: '<S3>/Data Type Conversion14' */
    /* case IN_Trigger: */
  } else if (((REL_B.TmpSignalConversionAtVeOUT_SP_E >= 1) &&
              (!REL_B.TmpSignalConversionAtVbINP_CAN_) &&
              (REL_B.DataTypeConversion14 != Gear_P)) ||
             ((REL_B.DataTypeConversion13 == Door_Unlock) && (*SO_m_FRDoorRatSts
    == Rat_Unlock))) {
    REL_DW.is_DoorLock_m = 0;
    REL_DW.is_Trigger_f = 0;
    REL_DW.is_RlsReq_n = REL_IN_Idle_p;
  } else {
    switch (REL_DW.is_Trigger_f) {
     case REL_IN_DoorLock_f:
      switch (REL_DW.is_DoorLock_m) {
       case REL_IN_UnlockFail_i:
        REL_DW.is_DoorLock_m = 0;
        REL_DW.is_Trigger_f = 0;
        REL_DW.is_RlsReq_n = REL_IN_Idle_p;
        break;

       case REL_IN_UnlockReq_k:
        if (REL_B.DataTypeConversion13 == Door_Unlock) {
          REL_DW.is_DoorLock_m = REL_IN_UnlockSuccess_p;
        } else if ((REL_DW.temporalCounter_i2 >= 50) &&
                   (REL_B.DataTypeConversion13 == Door_Lock)) {
          REL_DW.is_DoorLock_m = REL_IN_UnlockFail_i;
        } else if (REL_DW.temporalCounter_i2 == 5) {
          REL_B.SO_m_UnlockReq_d = Unlock_Idle;
        }
        break;

       default:
        /* case IN_UnlockSuccess: */
        if (*SO_m_FRDoorRatSts != Rat_Unlock) {
          REL_DW.is_DoorLock_m = 0;
          REL_DW.is_Trigger_f = REL_IN_Release_n;
          REL_DW.temporalCounter_i2 = 0U;
          REL_B.SO_b_DoorRlsReq_l = true;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock_g:
      if (*SO_m_FRDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_f = REL_IN_Release_n;
        REL_DW.temporalCounter_i2 = 0U;
        REL_B.SO_b_DoorRlsReq_l = true;
      }
      break;

     case REL_IN_Error_a:
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i2 >= 5) {
        REL_B.SO_b_DoorRlsReq_l = false;
        REL_DW.is_Trigger_f = 0;
        REL_DW.is_RlsReq_n = REL_IN_Idle_p;
      }
      break;
    }
  }

  switch (REL_DW.is_SwValid_k) {
   case REL_IN_Idle_p:
    if ((REL_DW.SI_b_DoorHndBtnSts_prev != REL_DW.SI_b_DoorHndBtnSts_start) &&
        REL_DW.SI_b_DoorHndBtnSts_start) {
      REL_DW.is_SwValid_k = REL_IN_Press_f;
      REL_DW.temporalCounter_i6 = 0U;
    }
    break;

   case REL_IN_Press_f:
    if ((REL_DW.SI_b_DoorHndBtnSts_prev != REL_DW.SI_b_DoorHndBtnSts_start) && (
         !REL_DW.SI_b_DoorHndBtnSts_start)) {
      REL_DW.is_SwValid_k = REL_IN_Release_niu;
      REL_DW.temporalCounter_i6 = 0U;
      REL_DW.SL_b_DoorHndBtnValid = true;
    } else if (REL_DW.temporalCounter_i6 >= 100) {
      REL_DW.is_SwValid_k = REL_IN_Idle_p;
      REL_DW.SL_b_DoorHndBtnValid = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (REL_DW.temporalCounter_i6 >= 3) {
      REL_DW.is_SwValid_k = REL_IN_Idle_p;
      REL_DW.SL_b_DoorHndBtnValid = false;
    }
    break;
  }
}

/* Function for Chart: '<S3>/FLDoorRlsReq' */
static void REL_DoorInBtn_e(const Rat_Sts_E *SO_m_FLDoorRatSts, const Door_Sts_E
  *DataTypeConversion12)
{
  switch (REL_DW.is_SwValid_c) {
   case REL_IN_Idle_p:
    if ((REL_DW.SI_b_DoorInBtnSts_prev_j != REL_DW.SI_b_DoorInBtnSts_start_a) &&
        REL_DW.SI_b_DoorInBtnSts_start_a) {
      REL_DW.is_SwValid_c = REL_IN_Once_o;
      REL_DW.temporalCounter_i4_k = 0U;
    }
    break;

   case REL_IN_Once_o:
    if ((REL_DW.SI_b_DoorInBtnSts_prev_j != REL_DW.SI_b_DoorInBtnSts_start_a) &&
        REL_DW.SI_b_DoorInBtnSts_start_a) {
      REL_DW.is_SwValid_c = REL_IN_Twice_i;
      REL_DW.temporalCounter_i4_k = 0U;
      REL_DW.SL_b_DoorInBtnValid_b = true;
    } else if (REL_DW.temporalCounter_i4_k >= 200) {
      REL_DW.is_SwValid_c = REL_IN_Idle_p;
      REL_DW.SL_b_DoorInBtnValid_b = false;
    }
    break;

   default:
    /* case IN_Twice: */
    if (REL_DW.temporalCounter_i4_k >= 3) {
      REL_DW.is_SwValid_c = REL_IN_Idle_p;
      REL_DW.SL_b_DoorInBtnValid_b = false;
    }
    break;
  }

  if (REL_DW.is_RlsReq_k == REL_IN_Idle_p) {
    /* DataTypeConversion: '<S3>/Data Type Conversion14' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion12'
     */
    if ((((REL_B.TmpSignalConversionAtVeOUT_SP_E <= 0) &&
          (!REL_B.TmpSignalConversionAtVbINP_CAN_)) ||
         (REL_B.DataTypeConversion14 == Gear_P)) &&
        ((REL_DW.SL_b_DoorInBtnValid_prev_e !=
          REL_DW.SL_b_DoorInBtnValid_start_g) &&
         REL_DW.SL_b_DoorInBtnValid_start_g)) {
      REL_DW.is_RlsReq_k = REL_IN_Trigger_h;
      switch (*DataTypeConversion12) {
       case Door_Lock:
        REL_DW.is_Trigger_d = REL_IN_DoorLock_f;
        REL_DW.is_DoorLock_k = REL_IN_UnlockReq_k;
        REL_DW.temporalCounter_i1_h = 0U;
        REL_B.SO_m_UnlockReq_k = Unlock_Req;
        break;

       case Door_Unlock:
        REL_DW.is_Trigger_d = REL_IN_DoorUnlock_g;
        break;

       default:
        REL_DW.is_Trigger_d = REL_IN_Error_a;
        break;
      }
    }

    /* DataTypeConversion: '<S3>/Data Type Conversion14' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion12'
     */
    /* case IN_Trigger: */
  } else if (((REL_B.TmpSignalConversionAtVeOUT_SP_E >= 1) &&
              (!REL_B.TmpSignalConversionAtVbINP_CAN_) &&
              (REL_B.DataTypeConversion14 != Gear_P)) || ((*DataTypeConversion12
    == Door_Unlock) && (*SO_m_FLDoorRatSts == Rat_Unlock))) {
    REL_DW.is_DoorLock_k = 0;
    REL_DW.is_Trigger_d = 0;
    REL_DW.is_RlsReq_k = REL_IN_Idle_p;
  } else {
    switch (REL_DW.is_Trigger_d) {
     case REL_IN_DoorLock_f:
      switch (REL_DW.is_DoorLock_k) {
       case REL_IN_UnlockFail_i:
        REL_DW.is_DoorLock_k = 0;
        REL_DW.is_Trigger_d = 0;
        REL_DW.is_RlsReq_k = REL_IN_Idle_p;
        break;

       case REL_IN_UnlockReq_k:
        if (*DataTypeConversion12 == Door_Unlock) {
          REL_DW.is_DoorLock_k = REL_IN_UnlockSuccess_p;
        } else if ((REL_DW.temporalCounter_i1_h >= 50) && (*DataTypeConversion12
                    == Door_Lock)) {
          REL_DW.is_DoorLock_k = REL_IN_UnlockFail_i;
        } else if (REL_DW.temporalCounter_i1_h == 5) {
          REL_B.SO_m_UnlockReq_k = Unlock_Idle;
        }
        break;

       default:
        /* case IN_UnlockSuccess: */
        if (*SO_m_FLDoorRatSts != Rat_Unlock) {
          REL_DW.is_DoorLock_k = 0;
          REL_DW.is_Trigger_d = REL_IN_Release_n;
          REL_DW.temporalCounter_i1_h = 0U;
          REL_B.SO_b_DoorRlsReq_jt = true;
          REL_B.SO_e_DoorRlsDelayTime_m = 20U;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock_g:
      if (*SO_m_FLDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_d = REL_IN_Release_n;
        REL_DW.temporalCounter_i1_h = 0U;
        REL_B.SO_b_DoorRlsReq_jt = true;
        REL_B.SO_e_DoorRlsDelayTime_m = 20U;
      }
      break;

     case REL_IN_Error_a:
      REL_DW.is_Trigger_d = 0;
      REL_DW.is_RlsReq_k = REL_IN_Idle_p;
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i1_h >= 5) {
        REL_B.SO_b_DoorRlsReq_jt = false;
        REL_B.SO_e_DoorRlsDelayTime_m = 0U;
        REL_DW.is_Trigger_d = 0;
        REL_DW.is_RlsReq_k = REL_IN_Idle_p;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/FLDoorRlsReq' */
static void REL_DoorHndBtn_k(const Rat_Sts_E *SO_m_FLDoorRatSts, const
  Door_Sts_E *DataTypeConversion12)
{
  if (REL_DW.is_RlsReq_o == REL_IN_Idle_p) {
    /* DataTypeConversion: '<S3>/Data Type Conversion14' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion12'
     */
    if ((((REL_B.TmpSignalConversionAtVeOUT_SP_E <= 0) &&
          (!REL_B.TmpSignalConversionAtVbINP_CAN_)) ||
         (REL_B.DataTypeConversion14 == Gear_P)) &&
        ((REL_DW.SL_b_DoorHndBtnValid_prev_m !=
          REL_DW.SL_b_DoorHndBtnValid_start_h) &&
         REL_DW.SL_b_DoorHndBtnValid_start_h)) {
      REL_DW.is_RlsReq_o = REL_IN_Trigger_h;
      switch (*DataTypeConversion12) {
       case Door_Lock:
        REL_DW.is_Trigger_h = REL_IN_DoorLock_f;
        REL_DW.is_DoorLock_h = REL_IN_UnlockReq_k;
        REL_DW.temporalCounter_i2_d = 0U;
        REL_B.SO_m_UnlockReq_k = Unlock_PE;
        break;

       case Door_Unlock:
        REL_DW.is_Trigger_h = REL_IN_DoorUnlock_g;
        break;

       default:
        REL_DW.is_Trigger_h = REL_IN_Error_a;
        break;
      }
    }

    /* DataTypeConversion: '<S3>/Data Type Conversion14' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion12'
     */
    /* case IN_Trigger: */
  } else if (((REL_B.TmpSignalConversionAtVeOUT_SP_E >= 1) &&
              (!REL_B.TmpSignalConversionAtVbINP_CAN_) &&
              (REL_B.DataTypeConversion14 != Gear_P)) || ((*DataTypeConversion12
    == Door_Unlock) && (*SO_m_FLDoorRatSts == Rat_Unlock))) {
    REL_DW.is_DoorLock_h = 0;
    REL_DW.is_Trigger_h = 0;
    REL_DW.is_RlsReq_o = REL_IN_Idle_p;
  } else {
    switch (REL_DW.is_Trigger_h) {
     case REL_IN_DoorLock_f:
      switch (REL_DW.is_DoorLock_h) {
       case REL_IN_UnlockFail_i:
        REL_DW.is_DoorLock_h = 0;
        REL_DW.is_Trigger_h = 0;
        REL_DW.is_RlsReq_o = REL_IN_Idle_p;
        break;

       case REL_IN_UnlockReq_k:
        if (*DataTypeConversion12 == Door_Unlock) {
          REL_DW.is_DoorLock_h = REL_IN_UnlockSuccess_p;
        } else if ((REL_DW.temporalCounter_i2_d >= 50) && (*DataTypeConversion12
                    == Door_Lock)) {
          REL_DW.is_DoorLock_h = REL_IN_UnlockFail_i;
        } else if (REL_DW.temporalCounter_i2_d == 5) {
          REL_B.SO_m_UnlockReq_k = Unlock_Idle;
        }
        break;

       default:
        /* case IN_UnlockSuccess: */
        if (*SO_m_FLDoorRatSts != Rat_Unlock) {
          REL_DW.is_DoorLock_h = 0;
          REL_DW.is_Trigger_h = REL_IN_Release_n;
          REL_DW.temporalCounter_i2_d = 0U;
          REL_B.SO_b_DoorRlsReq_jt = true;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock_g:
      if (*SO_m_FLDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_h = REL_IN_Release_n;
        REL_DW.temporalCounter_i2_d = 0U;
        REL_B.SO_b_DoorRlsReq_jt = true;
      }
      break;

     case REL_IN_Error_a:
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i2_d >= 5) {
        REL_B.SO_b_DoorRlsReq_jt = false;
        REL_DW.is_Trigger_h = 0;
        REL_DW.is_RlsReq_o = REL_IN_Idle_p;
      }
      break;
    }
  }

  switch (REL_DW.is_SwValid_d) {
   case REL_IN_Idle_p:
    if ((REL_DW.SI_b_DoorHndBtnSts_prev_f != REL_DW.SI_b_DoorHndBtnSts_start_m) &&
        REL_DW.SI_b_DoorHndBtnSts_start_m) {
      REL_DW.is_SwValid_d = REL_IN_Press_f;
      REL_DW.temporalCounter_i6_i = 0U;
    }
    break;

   case REL_IN_Press_f:
    if ((REL_DW.SI_b_DoorHndBtnSts_prev_f != REL_DW.SI_b_DoorHndBtnSts_start_m) &&
        (!REL_DW.SI_b_DoorHndBtnSts_start_m)) {
      REL_DW.is_SwValid_d = REL_IN_Release_niu;
      REL_DW.temporalCounter_i6_i = 0U;
      REL_DW.SL_b_DoorHndBtnValid_i = true;
    } else if (REL_DW.temporalCounter_i6_i >= 100) {
      REL_DW.is_SwValid_d = REL_IN_Idle_p;
      REL_DW.SL_b_DoorHndBtnValid_i = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (REL_DW.temporalCounter_i6_i >= 3) {
      REL_DW.is_SwValid_d = REL_IN_Idle_p;
      REL_DW.SL_b_DoorHndBtnValid_i = false;
    }
    break;
  }
}

/* Function for Chart: '<S3>/Unlock_Request' */
static float64 REL_GetDrvUnlockReq(void)
{
  float64 req;
  switch (REL_B.SO_m_UnlockReq_k) {
   case Unlock_PE:
    req = 2.0;
    break;

   case Unlock_Req:
    req = 1.0;
    break;

   default:
    req = 0.0;
    break;
  }

  return req;
}

/* Function for Chart: '<S3>/Unlock_Request' */
static float64 REL_GetPassUnlockReq(void)
{
  float64 req;
  if ((REL_B.SO_m_UnlockReq_d == Unlock_PE) || (REL_B.SO_m_UnlockReq_e ==
       Unlock_PE) || (REL_B.SO_m_UnlockReq == Unlock_PE)) {
    req = 2.0;
  } else {
    req = ((REL_B.SO_m_UnlockReq_d == Unlock_Req) || (REL_B.SO_m_UnlockReq_e ==
            Unlock_Req) || (REL_B.SO_m_UnlockReq == Unlock_Req));
  }

  return req;
}

/* Model step function for TID1 */
void REL_Step(void)                    /* Explicit Task: REL_Step */
{
  Rat_Sts_E SO_m_FLDoorRatSts;
  Rat_Sts_E SO_m_FRDoorRatSts;
  UInt8 tmpRead;
  UInt8 tmpRead_0;
  UInt8 tmpRead_1;
  UInt8 tmpRead_2;
  UInt8 tmpRead_8;
  UInt8 tmpRead_9;
  uint8 SO_e_MotorPwm;
  uint8 SO_e_MotorPwm_g;
  uint8 SO_e_MotorPwm_h;
  uint8 SO_e_MotorPwm_o;
  Boolean tmpRead_3;
  Boolean tmpRead_4;
  Boolean tmpRead_5;
  Boolean tmpRead_6;
  Boolean tmpRead_7;
  Boolean tmpRead_a;
  boolean SL_b_FLDoorHndBtnSts;
  boolean SL_b_FLDoorHndPullSts;
  boolean SL_b_FRDoorHndPullSts;
  boolean SO_b_Error;
  boolean SO_b_Error_b;
  boolean SO_b_Error_c;
  boolean SO_b_Error_d;

  /* Inport: '<Root>/VbOUT_DLK_BdcDrvrDoorLockOpenReq_flg_VbOUT_DLK_BdcDrvrDoorLockOpenReq_flg' */
  (void)
    Rte_Read_VbOUT_DLK_BdcDrvrDoorLockOpenReq_flg_VbOUT_DLK_BdcDrvrDoorLockOpenReq_flg
    (&SO_b_Error_c);

  /* Inport: '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg' */
  (void)Rte_Read_VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg(&tmpRead_a);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* DataStoreWrite: '<S3>/Data Store Write' incorporates:
   *  Constant: '<S3>/Constant'
   */
  REL_DW.E15_REL = 5.0;

  /* Chart: '<S3>/DoorSwSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg'
   *  Inport: '<Root>/VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg'
   *  Inport: '<Root>/VbINP_HWA_FLDoorOutButton_flg_VbINP_HWA_FLDoorOutButton_flg'
   *  Inport: '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg'
   *  Inport: '<Root>/VbINP_HWA_FRDoorHandleSW_flg_VbINP_HWA_FRDoorHandleSW_flg'
   *  Inport: '<Root>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg'
   *  Inport: '<Root>/VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg'
   *  Inport: '<Root>/VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg'
   *  Inport: '<Root>/VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg'
   *  Inport: '<Root>/VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg'
   *  Inport: '<Root>/VbINP_HWA_RRDoorHandleSW_flg_VbINP_HWA_RRDoorHandleSW_flg'
   *  Inport: '<Root>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg'
   */
  if (REL_DW.temporalCounter_i1 < 1023U) {
    REL_DW.temporalCounter_i1++;
  }

  REL_DW.SI_b_CrashSts_prev = REL_DW.SI_b_CrashSts_start;
  REL_DW.SI_b_CrashSts_start = tmpRead_a;
  if (REL_DW.is_active_c23_REL == 0U) {
    REL_DW.SI_b_CrashSts_prev = tmpRead_a;
    REL_DW.is_active_c23_REL = 1U;
    REL_DW.is_c23_REL = REL_IN_NoCrash;
    REL_enter_atomic_NoCrash(&SL_b_FLDoorHndPullSts, &SL_b_FRDoorHndPullSts,
      &SL_b_FLDoorHndBtnSts);
  } else if (REL_DW.is_c23_REL == REL_IN_Crash) {
    if (REL_DW.temporalCounter_i1 >= 1000) {
      REL_DW.is_c23_REL = REL_IN_NoCrash;
      REL_enter_atomic_NoCrash(&SL_b_FLDoorHndPullSts, &SL_b_FRDoorHndPullSts,
        &SL_b_FLDoorHndBtnSts);
    } else {
      REL_B.SL_b_FLDoorInBtnSts = false;
      REL_B.SL_b_FRDoorInBtnSts = false;
      REL_B.SL_b_RLDoorInBtnSts = false;
      REL_B.SL_b_RRDoorInBtnSts = false;
      SL_b_FLDoorHndPullSts = false;
      SL_b_FRDoorHndPullSts = false;
      REL_B.SL_b_RLDoorHndPullSts = false;
      REL_B.SL_b_RRDoorHndPullSts = false;
      SL_b_FLDoorHndBtnSts = false;
      REL_B.SL_b_FRDoorHndBtnSts = false;
      REL_B.SL_b_RLDoorHndBtnSts = false;
      REL_B.SL_b_RRDoorHndBtnSts = false;
    }

    /* case IN_NoCrash: */
  } else if ((REL_DW.SI_b_CrashSts_prev != REL_DW.SI_b_CrashSts_start) &&
             REL_DW.SI_b_CrashSts_start) {
    REL_DW.is_c23_REL = REL_IN_Crash;
    REL_DW.temporalCounter_i1 = 0U;
    REL_B.SL_b_FLDoorInBtnSts = false;
    REL_B.SL_b_FRDoorInBtnSts = false;
    REL_B.SL_b_RLDoorInBtnSts = false;
    REL_B.SL_b_RRDoorInBtnSts = false;
    SL_b_FLDoorHndPullSts = false;
    SL_b_FRDoorHndPullSts = false;
    REL_B.SL_b_RLDoorHndPullSts = false;
    REL_B.SL_b_RRDoorHndPullSts = false;
    SL_b_FLDoorHndBtnSts = false;
    REL_B.SL_b_FRDoorHndBtnSts = false;
    REL_B.SL_b_RLDoorHndBtnSts = false;
    REL_B.SL_b_RRDoorHndBtnSts = false;
  } else {
    (void)Rte_Read_VbINP_HWA_RRDoorHandleSW_flg_VbINP_HWA_RRDoorHandleSW_flg
      (&REL_B.SL_b_RRDoorHndBtnSts);
    (void)Rte_Read_VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg
      (&REL_B.SL_b_RLDoorHndBtnSts);
    (void)Rte_Read_VbINP_HWA_FRDoorHandleSW_flg_VbINP_HWA_FRDoorHandleSW_flg
      (&REL_B.SL_b_FRDoorHndBtnSts);
    (void)Rte_Read_VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg
      (&SL_b_FLDoorHndBtnSts);
    (void)Rte_Read_VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg
      (&REL_B.SL_b_RRDoorHndPullSts);
    (void)Rte_Read_VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg
      (&REL_B.SL_b_RLDoorHndPullSts);
    (void)Rte_Read_VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg
      (&SL_b_FRDoorHndPullSts);
    (void)Rte_Read_VbINP_HWA_FLDoorOutButton_flg_VbINP_HWA_FLDoorOutButton_flg
      (&SL_b_FLDoorHndPullSts);
    (void)Rte_Read_VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg
      (&REL_B.SL_b_RRDoorInBtnSts);
    (void)Rte_Read_VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg
      (&REL_B.SL_b_RLDoorInBtnSts);
    (void)Rte_Read_VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg
      (&REL_B.SL_b_FRDoorInBtnSts);
    (void)Rte_Read_VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg
      (&REL_B.SL_b_FLDoorInBtnSts);
  }

  /* End of Chart: '<S3>/DoorSwSts' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig' */
  (void)
    Rte_Read_VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig
    (&SO_e_MotorPwm_h);

  /* Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig' */
  (void)Rte_Read_VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig(&tmpRead_2);

  /* Inport: '<Root>/VeOUT_PDU_BcmPowerStatusFeedback_sig_VeOUT_PDU_BcmPowerStatusFeedback_sig' */
  (void)
    Rte_Read_VeOUT_PDU_BcmPowerStatusFeedback_sig_VeOUT_PDU_BcmPowerStatusFeedback_sig
    (&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* RelationalOperator: '<S11>/Compare' incorporates:
   *  Constant: '<S11>/Constant'
   */
  REL_B.Compare = (tmpRead == 0);

  /* SignalConversion generated from: '<S2>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh_read' incorporates:
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   */
  (void)Rte_Read_VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh
    (&REL_B.TmpSignalConversionAtVeOUT_SP_E);

  /* SignalConversion generated from: '<S2>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   */
  (void)Rte_Read_VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg
    (&REL_B.TmpSignalConversionAtVbINP_CAN_);

  /* DataTypeConversion: '<S3>/Data Type Conversion14' */
  REL_B.DataTypeConversion14 = tmpRead_2;

  /* DataTypeConversion: '<S3>/Data Type Conversion13' */
  REL_B.DataTypeConversion13 = SO_e_MotorPwm_h;

  /* SignalConversion generated from: '<S2>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg'
   */
  (void)Rte_Read_VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg
    (&REL_B.TmpSignalConversionAtVbINP_HWA_);

  /* SignalConversion generated from: '<S2>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   */
  (void)Rte_Read_VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg
    (&REL_B.TmpSignalConversionAtVbINP_HW_g);

  /* SignalConversion generated from: '<S2>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg'
   */
  (void)Rte_Read_VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg
    (&REL_B.TmpSignalConversionAtVbINP_HW_f);

  /* SignalConversion generated from: '<S2>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg'
   */
  (void)Rte_Read_VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg
    (&REL_B.TmpSignalConversionAtVbINP_H_gz);

  /* Chart: '<S3>/DoorRatSts' */
  if (REL_DW.is_active_c3_REL == 0U) {
    float64 tmp;
    REL_DW.is_active_c3_REL = 1U;
    tmp = REL_GetDoorRatSts((float64)REL_B.TmpSignalConversionAtVbINP_HWA_,
      (float64)REL_B.TmpSignalConversionAtVbINP_HWA_);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8)(sint32)tmp);
      } else {
        SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((float64)REL_B.TmpSignalConversionAtVbINP_HW_f,
      (float64)REL_B.TmpSignalConversionAtVbINP_HW_g);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8)(sint32)tmp);
      } else {
        SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((float64)REL_B.TmpSignalConversionAtVbINP_H_gz,
      (float64)REL_B.TmpSignalConversionAtVbINP_HW_g);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        REL_B.SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8)(sint32)tmp);
      } else {
        REL_B.SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      REL_B.SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((float64)REL_B.TmpSignalConversionAtVbINP_H_gz,
      (float64)REL_B.TmpSignalConversionAtVbINP_HW_f);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        REL_B.SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8)(sint32)tmp);
      } else {
        REL_B.SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      REL_B.SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }
  } else {
    float64 tmp;
    tmp = REL_GetDoorRatSts((float64)REL_B.TmpSignalConversionAtVbINP_HWA_,
      (float64)REL_B.TmpSignalConversionAtVbINP_HWA_);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8)(sint32)tmp);
      } else {
        SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((float64)REL_B.TmpSignalConversionAtVbINP_HW_f,
      (float64)REL_B.TmpSignalConversionAtVbINP_HW_g);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8)(sint32)tmp);
      } else {
        SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((float64)REL_B.TmpSignalConversionAtVbINP_H_gz,
      (float64)REL_B.TmpSignalConversionAtVbINP_HW_g);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        REL_B.SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8)(sint32)tmp);
      } else {
        REL_B.SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      REL_B.SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((float64)REL_B.TmpSignalConversionAtVbINP_H_gz,
      (float64)REL_B.TmpSignalConversionAtVbINP_HW_f);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        REL_B.SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8)(sint32)tmp);
      } else {
        REL_B.SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      REL_B.SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }
  }

  /* End of Chart: '<S3>/DoorRatSts' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VeOUT_DHM_BDCRiReDoorHndSts_sig_VeOUT_DHM_BDCRiReDoorHndSts_sig' */
  (void)Rte_Read_VeOUT_DHM_BDCRiReDoorHndSts_sig_VeOUT_DHM_BDCRiReDoorHndSts_sig
    (&SO_e_MotorPwm);

  /* Inport: '<Root>/VeOUT_DHM_BDCLeReDoorHndSts_sig_VeOUT_DHM_BDCLeReDoorHndSts_sig' */
  (void)Rte_Read_VeOUT_DHM_BDCLeReDoorHndSts_sig_VeOUT_DHM_BDCLeReDoorHndSts_sig
    (&tmpRead_9);

  /* Inport: '<Root>/VeOUT_DHM_BDCPassDoorHndSts_sig_VeOUT_DHM_BDCPassDoorHndSts_sig' */
  (void)Rte_Read_VeOUT_DHM_BDCPassDoorHndSts_sig_VeOUT_DHM_BDCPassDoorHndSts_sig
    (&SO_e_MotorPwm_g);

  /* Inport: '<Root>/VeOUT_DHM_BDCDrvrDoorHndSts_sig_VeOUT_DHM_BDCDrvrDoorHndSts_sig' */
  (void)Rte_Read_VeOUT_DHM_BDCDrvrDoorHndSts_sig_VeOUT_DHM_BDCDrvrDoorHndSts_sig
    (&tmpRead_8);

  /* Inport: '<Root>/VbINP_CAN_RRDCUCinchHomeSwitch_flg_VbINP_CAN_RRDCUCinchHomeSwitch_flg' */
  (void)
    Rte_Read_VbINP_CAN_RRDCUCinchHomeSwitch_flg_VbINP_CAN_RRDCUCinchHomeSwitch_flg
    (&SO_b_Error_d);

  /* Inport: '<Root>/VbINP_CAN_RLDCUCinchHomeSwitch_flg_VbINP_CAN_RLDCUCinchHomeSwitch_flg' */
  (void)
    Rte_Read_VbINP_CAN_RLDCUCinchHomeSwitch_flg_VbINP_CAN_RLDCUCinchHomeSwitch_flg
    (&SO_b_Error);

  /* Inport: '<Root>/VbINP_CAN_CdcRiReDoorButtonSts_flg_VbINP_CAN_CdcRiReDoorButtonSts_flg' */
  (void)
    Rte_Read_VbINP_CAN_CdcRiReDoorButtonSts_flg_VbINP_CAN_CdcRiReDoorButtonSts_flg
    (&tmpRead_5);

  /* Inport: '<Root>/VbINP_CAN_CdcLeReDoorButtonSts_flg_VbINP_CAN_CdcLeReDoorButtonSts_flg' */
  (void)
    Rte_Read_VbINP_CAN_CdcLeReDoorButtonSts_flg_VbINP_CAN_CdcLeReDoorButtonSts_flg
    (&SO_b_Error_b);

  /* Inport: '<Root>/VbINP_HWA_RRChildLckSt_flg_VbINP_HWA_RRChildLckSt_flg' */
  (void)Rte_Read_VbINP_HWA_RRChildLckSt_flg_VbINP_HWA_RRChildLckSt_flg
    (&tmpRead_4);

  /* Inport: '<Root>/VbINP_HWA_LRChildLckSt_flg_VbINP_HWA_LRChildLckSt_flg' */
  (void)Rte_Read_VbINP_HWA_LRChildLckSt_flg_VbINP_HWA_LRChildLckSt_flg
    (&tmpRead_3);

  /* Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig' */
  (void)
    Rte_Read_VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig
    (&tmpRead_1);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* DataTypeConversion: '<S3>/Data Type Conversion17' */
  REL_B.DataTypeConversion17 = tmpRead_9;

  /* SignalConversion generated from: '<S2>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   */
  (void)
    Rte_Read_VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg
    (&REL_B.TmpSignalConversionAtVbINP_CA_f);

  /* Chart: '<S3>/RLDoorRlsReq' incorporates:
   *  Constant: '<S3>/Constant10'
   *  Constant: '<S3>/Constant6'
   */
  REL_RLDoorRlsReq(REL_B.Compare, REL_B.TmpSignalConversionAtVeOUT_SP_E,
                   REL_B.TmpSignalConversionAtVbINP_CAN_,
                   REL_B.DataTypeConversion14, REL_B.DataTypeConversion13,
                   REL_B.SO_m_RLDoorRatSts, REL_B.SL_b_RLDoorInBtnSts,
                   REL_B.SL_b_RLDoorHndPullSts, REL_B.SL_b_RLDoorHndBtnSts,
                   REL_B.DataTypeConversion17, SO_b_Error_b,
                   REL_B.TmpSignalConversionAtVbINP_CA_f, tmpRead_3, false,
                   false, &REL_B.SO_b_DoorRlsReq_j,
                   &REL_B.SO_e_DoorRlsDelayTime_e, &REL_B.SO_m_UnlockReq_e,
                   &REL_DW.sf_RLDoorRlsReq);

  /* SignalConversion generated from: '<S2>/VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg'
   */
  (void)Rte_Read_VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg
    (&REL_B.TmpSignalConversionAtVbINP_CFG_);

  /* Chart: '<S3>/RLDoorRlsDriver' */
  REL_FLDoorRlsDriver(REL_B.SO_b_DoorRlsReq_j,
                      REL_B.TmpSignalConversionAtVbINP_HW_f, SO_b_Error,
                      REL_B.TmpSignalConversionAtVbINP_CFG_,
                      REL_B.SO_e_DoorRlsDelayTime_e, &REL_B.SO_b_MotorA_f,
                      &REL_B.SO_b_MotorB_f, &REL_B.SO_e_MotorCmd_c,
                      &SO_b_Error_b, &SO_e_MotorPwm_h,
                      &REL_DW.sf_RLDoorRlsDriver);

  /* DataTypeConversion: '<S3>/Data Type Conversion18' */
  REL_B.DataTypeConversion18 = SO_e_MotorPwm;

  /* Chart: '<S3>/RRDoorRlsReq' incorporates:
   *  Constant: '<S3>/Constant11'
   *  Constant: '<S3>/Constant12'
   */
  REL_RLDoorRlsReq(REL_B.Compare, REL_B.TmpSignalConversionAtVeOUT_SP_E,
                   REL_B.TmpSignalConversionAtVbINP_CAN_,
                   REL_B.DataTypeConversion14, REL_B.DataTypeConversion13,
                   REL_B.SO_m_RRDoorRatSts, REL_B.SL_b_RRDoorInBtnSts,
                   REL_B.SL_b_RRDoorHndPullSts, REL_B.SL_b_RRDoorHndBtnSts,
                   REL_B.DataTypeConversion18, tmpRead_5,
                   REL_B.TmpSignalConversionAtVbINP_CA_f, tmpRead_4, false,
                   false, &REL_B.SO_b_DoorRlsReq, &REL_B.SO_e_DoorRlsDelayTime,
                   &REL_B.SO_m_UnlockReq, &REL_DW.sf_RRDoorRlsReq);

  /* Chart: '<S3>/RRDoorRlsDriver' */
  REL_FLDoorRlsDriver(REL_B.SO_b_DoorRlsReq,
                      REL_B.TmpSignalConversionAtVbINP_H_gz, SO_b_Error_d,
                      REL_B.TmpSignalConversionAtVbINP_CFG_,
                      REL_B.SO_e_DoorRlsDelayTime, &REL_B.SO_b_MotorA,
                      &REL_B.SO_b_MotorB, &REL_B.SO_e_MotorCmd, &SO_b_Error,
                      &SO_e_MotorPwm, &REL_DW.sf_RRDoorRlsDriver);

  /* Chart: '<S3>/FRDoorRlsReq' incorporates:
   *  Constant: '<S3>/Constant4'
   */
  if (REL_DW.temporalCounter_i1_e < 63U) {
    REL_DW.temporalCounter_i1_e++;
  }

  if (REL_DW.temporalCounter_i2 < 63U) {
    REL_DW.temporalCounter_i2++;
  }

  if (REL_DW.temporalCounter_i3 < 63U) {
    REL_DW.temporalCounter_i3++;
  }

  if (REL_DW.temporalCounter_i4 < 255U) {
    REL_DW.temporalCounter_i4++;
  }

  if (REL_DW.temporalCounter_i5 < 7U) {
    REL_DW.temporalCounter_i5++;
  }

  if (REL_DW.temporalCounter_i6 < 127U) {
    REL_DW.temporalCounter_i6++;
  }

  if (REL_DW.temporalCounter_i7 < 7U) {
    REL_DW.temporalCounter_i7++;
  }

  REL_DW.SI_b_DoorInBtnSts_prev = REL_DW.SI_b_DoorInBtnSts_start;
  REL_DW.SI_b_DoorInBtnSts_start = REL_B.SL_b_FRDoorInBtnSts;
  REL_DW.SL_b_DoorInBtnValid_prev = REL_DW.SL_b_DoorInBtnValid_start;
  REL_DW.SL_b_DoorInBtnValid_start = REL_DW.SL_b_DoorInBtnValid;
  REL_DW.SL_b_DoorHndPullValid_prev = REL_DW.SL_b_DoorHndPullValid_start;
  REL_DW.SL_b_DoorHndPullValid_start = REL_DW.SL_b_DoorHndPullValid;
  REL_DW.SI_b_DoorHndBtnSts_prev = REL_DW.SI_b_DoorHndBtnSts_start;
  REL_DW.SI_b_DoorHndBtnSts_start = REL_B.SL_b_FRDoorHndBtnSts;
  REL_DW.SL_b_DoorHndBtnValid_prev = REL_DW.SL_b_DoorHndBtnValid_start;
  REL_DW.SL_b_DoorHndBtnValid_start = REL_DW.SL_b_DoorHndBtnValid;
  REL_DW.SL_b_CentSingleDoorBtnValid_pre =
    REL_DW.SL_b_CentSingleDoorBtnValid_sta;
  REL_DW.SL_b_CentSingleDoorBtnValid_sta = REL_DW.SL_b_CentSingleDoorBtnValid;
  REL_DW.SL_b_CentAllDoorBtnValid_prev = REL_DW.SL_b_CentAllDoorBtnValid_start;
  REL_DW.SL_b_CentAllDoorBtnValid_start = REL_DW.SL_b_CentAllDoorBtnValid;
  REL_DW.SI_b_DoorAutoRlsReq_prev = REL_DW.SI_b_DoorAutoRlsReq_start;
  REL_DW.SI_b_DoorAutoRlsReq_start = false;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg' */
  (void)
    Rte_Read_VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg
    (&REL_DW.SL_b_CentSingleDoorBtnValid);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/FRDoorRlsReq' incorporates:
   *  Constant: '<S3>/Constant4'
   *  DataTypeConversion: '<S3>/Data Type Conversion13'
   *  DataTypeConversion: '<S3>/Data Type Conversion14'
   *  DataTypeConversion: '<S3>/Data Type Conversion16'
   */
  if (REL_DW.is_active_c5_DoorRlsReq == 0U) {
    REL_DW.SI_b_DoorInBtnSts_prev = REL_B.SL_b_FRDoorInBtnSts;
    REL_DW.SI_b_DoorHndBtnSts_prev = REL_B.SL_b_FRDoorHndBtnSts;
    REL_DW.SI_b_DoorAutoRlsReq_prev = false;
    REL_DW.is_active_c5_DoorRlsReq = 1U;
    REL_DW.is_SwValid = REL_IN_Idle_p;
    REL_DW.SL_b_DoorInBtnValid = false;
    REL_DW.is_RlsReq = REL_IN_Idle_p;
    REL_DW.SL_b_DoorHndPullValid = SL_b_FRDoorHndPullSts;
    REL_DW.is_RlsReq_c = REL_IN_Idle_p;
    REL_DW.is_RlsReq_n = REL_IN_Idle_p;
    REL_DW.is_SwValid_k = REL_IN_Idle_p;
    REL_DW.SL_b_DoorHndBtnValid = false;
    REL_DW.is_DoorCentral = REL_IN_Idle_p;
    REL_DW.SL_b_CentAllDoorBtnValid = REL_B.TmpSignalConversionAtVbINP_CA_f;
    REL_DW.is_RlsReq_p = REL_IN_Idle_p;
  } else {
    REL_DoorInBtn_n(&SO_m_FRDoorRatSts);
    REL_DW.SL_b_DoorHndPullValid = SL_b_FRDoorHndPullSts;
    if (REL_DW.is_RlsReq_c == REL_IN_Idle_p) {
      if ((!REL_B.Compare) && (((REL_B.TmpSignalConversionAtVeOUT_SP_E <= 0) &&
            (!REL_B.TmpSignalConversionAtVbINP_CAN_)) ||
           (REL_B.DataTypeConversion14 == Gear_P)) &&
          (REL_B.DataTypeConversion13 == Door_Unlock) && (SO_e_MotorPwm_g ==
           Hnd_Unfold) && ((REL_DW.SL_b_DoorHndPullValid_prev !=
                            REL_DW.SL_b_DoorHndPullValid_start) &&
                           REL_DW.SL_b_DoorHndPullValid_start)) {
        REL_DW.is_RlsReq_c = REL_IN_Trigger_h;
        REL_DW.is_Trigger_i = REL_IN_DoorUnlock_gp;
      }

      /* case IN_Trigger: */
    } else if (REL_B.Compare || ((REL_B.TmpSignalConversionAtVeOUT_SP_E >= 1) &&
                (!REL_B.TmpSignalConversionAtVbINP_CAN_) &&
                (REL_B.DataTypeConversion14 != Gear_P)) ||
               (REL_B.DataTypeConversion13 != Door_Unlock) || (SO_e_MotorPwm_g
                != Hnd_Unfold) || (SO_m_FRDoorRatSts == Rat_Unlock)) {
      REL_DW.is_Trigger_i = 0;
      REL_DW.is_RlsReq_c = REL_IN_Idle_p;
    } else if (REL_DW.is_Trigger_i == REL_IN_DoorUnlock_gp) {
      if (SO_m_FRDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_i = REL_IN_Release_ni;
        REL_DW.temporalCounter_i5 = 0U;
        REL_B.SO_b_DoorRlsReq_l = true;
        REL_B.SO_e_DoorRlsDelayTime_k = 4U;
      }

      /* case IN_Release: */
    } else if (REL_DW.temporalCounter_i5 >= 5) {
      REL_B.SO_b_DoorRlsReq_l = false;
      REL_B.SO_e_DoorRlsDelayTime_k = 0U;
      REL_DW.is_Trigger_i = 0;
      REL_DW.is_RlsReq_c = REL_IN_Idle_p;
    }

    REL_DoorHndBtn_c(&SO_m_FRDoorRatSts);
    if (REL_DW.is_DoorCentral == REL_IN_Idle_p) {
      if ((!REL_B.Compare) && (((REL_B.TmpSignalConversionAtVeOUT_SP_E <= 0) &&
            (!REL_B.TmpSignalConversionAtVbINP_CAN_)) ||
           (REL_B.DataTypeConversion14 == Gear_P)) &&
          (((REL_DW.SL_b_CentSingleDoorBtnValid_pre !=
             REL_DW.SL_b_CentSingleDoorBtnValid_sta) &&
            REL_DW.SL_b_CentSingleDoorBtnValid_sta) ||
           ((REL_DW.SL_b_CentAllDoorBtnValid_prev !=
             REL_DW.SL_b_CentAllDoorBtnValid_start) &&
            REL_DW.SL_b_CentAllDoorBtnValid_start))) {
        REL_DW.is_DoorCentral = REL_IN_Trigger_h;
        switch (REL_B.DataTypeConversion13) {
         case Door_Lock:
          REL_DW.is_Trigger_b = REL_IN_DoorLock_f;
          REL_DW.is_DoorLock_m3 = REL_IN_UnlockReq_k;
          REL_DW.temporalCounter_i3 = 0U;
          REL_B.SO_m_UnlockReq_d = Unlock_Req;
          break;

         case Door_Unlock:
          REL_DW.is_Trigger_b = REL_IN_DoorUnlock_g;
          break;

         default:
          REL_DW.is_Trigger_b = REL_IN_Error_a;
          break;
        }
      }
    } else {
      Door_Sts_E tmp_0;

      /* case IN_Trigger: */
      tmp_0 = REL_B.DataTypeConversion13;
      if (REL_B.Compare || ((REL_B.TmpSignalConversionAtVeOUT_SP_E >= 1) &&
                            (!REL_B.TmpSignalConversionAtVbINP_CAN_) &&
                            (REL_B.DataTypeConversion14 != Gear_P)) || ((tmp_0 ==
            Door_Unlock) && (SO_m_FRDoorRatSts == Rat_Unlock))) {
        REL_DW.is_DoorLock_m3 = 0;
        REL_DW.is_Trigger_b = 0;
        REL_DW.is_DoorCentral = REL_IN_Idle_p;
      } else {
        switch (REL_DW.is_Trigger_b) {
         case REL_IN_DoorLock_f:
          switch (REL_DW.is_DoorLock_m3) {
           case REL_IN_UnlockFail_i:
            REL_DW.is_DoorLock_m3 = 0;
            REL_DW.is_Trigger_b = 0;
            REL_DW.is_DoorCentral = REL_IN_Idle_p;
            break;

           case REL_IN_UnlockReq_k:
            if (tmp_0 == Door_Unlock) {
              REL_DW.is_DoorLock_m3 = REL_IN_UnlockSucess_a;
            } else if ((REL_DW.temporalCounter_i3 >= 50) && (tmp_0 == Door_Lock))
            {
              REL_DW.is_DoorLock_m3 = REL_IN_UnlockFail_i;
            } else if (REL_DW.temporalCounter_i3 == 5) {
              REL_B.SO_m_UnlockReq_d = Unlock_Idle;
            }
            break;

           default:
            /* case IN_UnlockSucess: */
            if (SO_m_FRDoorRatSts != Rat_Unlock) {
              REL_DW.is_DoorLock_m3 = 0;
              REL_DW.is_Trigger_b = REL_IN_RELEASE_g;
              REL_DW.temporalCounter_i3 = 0U;
              REL_B.SO_b_DoorRlsReq_l = true;
            }
            break;
          }
          break;

         case REL_IN_DoorUnlock_g:
          if (SO_m_FRDoorRatSts != Rat_Unlock) {
            REL_DW.is_Trigger_b = REL_IN_RELEASE_g;
            REL_DW.temporalCounter_i3 = 0U;
            REL_B.SO_b_DoorRlsReq_l = true;
          }
          break;

         case REL_IN_Error_a:
          REL_DW.is_Trigger_b = 0;
          REL_DW.is_DoorCentral = REL_IN_Idle_p;
          break;

         default:
          /* case IN_RELEASE: */
          if (REL_DW.temporalCounter_i3 >= 5) {
            REL_B.SO_b_DoorRlsReq_l = false;
            REL_DW.is_Trigger_b = 0;
            REL_DW.is_DoorCentral = REL_IN_Idle_p;
          }
          break;
        }
      }
    }

    REL_DW.SL_b_CentAllDoorBtnValid = REL_B.TmpSignalConversionAtVbINP_CA_f;
    if (REL_DW.is_RlsReq_p != REL_IN_Idle_p) {
      /* case IN_Trigger: */
      REL_DW.is_Trigger_e = 0;
      REL_DW.is_RlsReq_p = REL_IN_Idle_p;
    }
  }

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VbINP_CAN_FRDCUCinchHomeSwitch_flg_VbINP_CAN_FRDCUCinchHomeSwitch_flg' */
  (void)
    Rte_Read_VbINP_CAN_FRDCUCinchHomeSwitch_flg_VbINP_CAN_FRDCUCinchHomeSwitch_flg
    (&tmpRead_7);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/FRDoorRlsDriver' */
  REL_FLDoorRlsDriver(REL_B.SO_b_DoorRlsReq_l,
                      REL_B.TmpSignalConversionAtVbINP_HW_g, tmpRead_7,
                      REL_B.TmpSignalConversionAtVbINP_CFG_,
                      REL_B.SO_e_DoorRlsDelayTime_k, &REL_B.SO_b_MotorA_fc,
                      &REL_B.SO_b_MotorB_b, &REL_B.SO_e_MotorCmd_e,
                      &SO_b_Error_d, &SO_e_MotorPwm_g,
                      &REL_DW.sf_FRDoorRlsDriver);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VeINP_CAN_CdcDrvrDoorLockSet_sig_VeINP_CAN_CdcDrvrDoorLockSet_sig' */
  (void)
    Rte_Read_VeINP_CAN_CdcDrvrDoorLockSet_sig_VeINP_CAN_CdcDrvrDoorLockSet_sig
    (&SO_e_MotorPwm_o);

  /* Inport: '<Root>/VeINP_EPRM_BdcDrvrDoorLockSetSts_sig_VeINP_EPRM_BdcDrvrDoorLockSetSts_sig' */
  (void)
    Rte_Read_VeINP_EPRM_BdcDrvrDoorLockSetSts_sig_VeINP_EPRM_BdcDrvrDoorLockSetSts_sig
    (&tmpRead_0);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/DoorAutoRlsSts' */
  if (REL_DW.is_active_c1_REL == 0U) {
    REL_DW.is_active_c1_REL = 1U;

    /*  DoorLockSet  */
    if ((SO_e_MotorPwm_o == 1) || ((SO_e_MotorPwm_o != 2) &&
         (REL_DW.SL_e_DoorAutoRlsSetBackup == 1))) {
      REL_B.SO_b_DoorAutoRlsSetSts = true;
      REL_B.SO_b_DoorAutoRlsSetStsToEE = true;
      REL_DW.SL_e_DoorAutoRlsSetBackup = 1U;
    } else if ((SO_e_MotorPwm_o == 2) || ((SO_e_MotorPwm_o != 1) &&
                (REL_DW.SL_e_DoorAutoRlsSetBackup == 2))) {
      REL_B.SO_b_DoorAutoRlsSetSts = false;
      REL_B.SO_b_DoorAutoRlsSetStsToEE = false;
      REL_DW.SL_e_DoorAutoRlsSetBackup = 2U;
    } else {
      switch (tmpRead_0) {
       case 1:
        REL_B.SO_b_DoorAutoRlsSetSts = true;
        REL_B.SO_b_DoorAutoRlsSetStsToEE = true;
        break;

       case 0:
        REL_B.SO_b_DoorAutoRlsSetSts = false;
        REL_B.SO_b_DoorAutoRlsSetStsToEE = false;
        break;
      }
    }
  } else if ((SO_e_MotorPwm_o == 1) || ((SO_e_MotorPwm_o != 2) &&
              (REL_DW.SL_e_DoorAutoRlsSetBackup == 1))) {
    REL_B.SO_b_DoorAutoRlsSetSts = true;
    REL_B.SO_b_DoorAutoRlsSetStsToEE = true;
    REL_DW.SL_e_DoorAutoRlsSetBackup = 1U;
  } else if ((SO_e_MotorPwm_o == 2) || ((SO_e_MotorPwm_o != 1) &&
              (REL_DW.SL_e_DoorAutoRlsSetBackup == 2))) {
    REL_B.SO_b_DoorAutoRlsSetSts = false;
    REL_B.SO_b_DoorAutoRlsSetStsToEE = false;
    REL_DW.SL_e_DoorAutoRlsSetBackup = 2U;
  } else {
    switch (tmpRead_0) {
     case 1:
      REL_B.SO_b_DoorAutoRlsSetSts = true;
      REL_B.SO_b_DoorAutoRlsSetStsToEE = true;
      break;

     case 0:
      REL_B.SO_b_DoorAutoRlsSetSts = false;
      REL_B.SO_b_DoorAutoRlsSetStsToEE = false;
      break;
    }
  }

  /* End of Chart: '<S3>/DoorAutoRlsSts' */

  /* Chart: '<S3>/FLDoorRlsReq' */
  if (REL_DW.temporalCounter_i1_h < 63U) {
    REL_DW.temporalCounter_i1_h++;
  }

  if (REL_DW.temporalCounter_i2_d < 63U) {
    REL_DW.temporalCounter_i2_d++;
  }

  if (REL_DW.temporalCounter_i3_b < 63U) {
    REL_DW.temporalCounter_i3_b++;
  }

  if (REL_DW.temporalCounter_i4_k < 255U) {
    REL_DW.temporalCounter_i4_k++;
  }

  if (REL_DW.temporalCounter_i5_h < 7U) {
    REL_DW.temporalCounter_i5_h++;
  }

  if (REL_DW.temporalCounter_i6_i < 127U) {
    REL_DW.temporalCounter_i6_i++;
  }

  if (REL_DW.temporalCounter_i7_l < 7U) {
    REL_DW.temporalCounter_i7_l++;
  }

  REL_DW.SI_b_DoorInBtnSts_prev_j = REL_DW.SI_b_DoorInBtnSts_start_a;
  REL_DW.SI_b_DoorInBtnSts_start_a = REL_B.SL_b_FLDoorInBtnSts;
  REL_DW.SL_b_DoorInBtnValid_prev_e = REL_DW.SL_b_DoorInBtnValid_start_g;
  REL_DW.SL_b_DoorInBtnValid_start_g = REL_DW.SL_b_DoorInBtnValid_b;
  REL_DW.SL_b_DoorHndPullValid_prev_d = REL_DW.SL_b_DoorHndPullValid_start_g;
  REL_DW.SL_b_DoorHndPullValid_start_g = REL_DW.SL_b_DoorHndPullValid_h;
  REL_DW.SI_b_DoorHndBtnSts_prev_f = REL_DW.SI_b_DoorHndBtnSts_start_m;
  REL_DW.SI_b_DoorHndBtnSts_start_m = SL_b_FLDoorHndBtnSts;
  REL_DW.SL_b_DoorHndBtnValid_prev_m = REL_DW.SL_b_DoorHndBtnValid_start_h;
  REL_DW.SL_b_DoorHndBtnValid_start_h = REL_DW.SL_b_DoorHndBtnValid_i;
  REL_DW.SL_b_CentSingleDoorBtnValid_p_e =
    REL_DW.SL_b_CentSingleDoorBtnValid_s_a;
  REL_DW.SL_b_CentSingleDoorBtnValid_s_a = REL_DW.SL_b_CentSingleDoorBtnValid_p;
  REL_DW.SL_b_CentAllDoorBtnValid_prev_c =
    REL_DW.SL_b_CentAllDoorBtnValid_star_m;
  REL_DW.SL_b_CentAllDoorBtnValid_star_m = REL_DW.SL_b_CentAllDoorBtnValid_h;
  REL_DW.SI_b_DoorAutoRlsReq_prev_b = REL_DW.SI_b_DoorAutoRlsReq_start_k;
  REL_DW.SI_b_DoorAutoRlsReq_start_k = SO_b_Error_c;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg' */
  (void)
    Rte_Read_VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg
    (&REL_DW.SL_b_CentSingleDoorBtnValid_p);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/FLDoorRlsReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion12'
   *  DataTypeConversion: '<S3>/Data Type Conversion14'
   *  DataTypeConversion: '<S3>/Data Type Conversion15'
   */
  if (REL_DW.is_active_c5_DoorRlsReq_b == 0U) {
    REL_DW.SI_b_DoorInBtnSts_prev_j = REL_B.SL_b_FLDoorInBtnSts;
    REL_DW.SI_b_DoorHndBtnSts_prev_f = SL_b_FLDoorHndBtnSts;
    REL_DW.SI_b_DoorAutoRlsReq_prev_b = SO_b_Error_c;
    REL_DW.is_active_c5_DoorRlsReq_b = 1U;
    REL_DW.is_SwValid_c = REL_IN_Idle_p;
    REL_DW.SL_b_DoorInBtnValid_b = false;
    REL_DW.is_RlsReq_k = REL_IN_Idle_p;
    REL_DW.SL_b_DoorHndPullValid_h = SL_b_FLDoorHndPullSts;
    REL_DW.is_RlsReq_ku = REL_IN_Idle_p;
    REL_DW.is_RlsReq_o = REL_IN_Idle_p;
    REL_DW.is_SwValid_d = REL_IN_Idle_p;
    REL_DW.SL_b_DoorHndBtnValid_i = false;
    REL_DW.is_DoorCentral_m = REL_IN_Idle_p;
    REL_DW.SL_b_CentAllDoorBtnValid_h = REL_B.TmpSignalConversionAtVbINP_CA_f;
    REL_DW.is_RlsReq_na = REL_IN_Idle_p;
  } else {
    REL_DoorInBtn_e(&SO_m_FLDoorRatSts, &tmpRead_1);
    REL_DW.SL_b_DoorHndPullValid_h = SL_b_FLDoorHndPullSts;
    if (REL_DW.is_RlsReq_ku == REL_IN_Idle_p) {
      if ((!REL_B.Compare) && (((REL_B.TmpSignalConversionAtVeOUT_SP_E <= 0) &&
            (!REL_B.TmpSignalConversionAtVbINP_CAN_)) ||
           (REL_B.DataTypeConversion14 == Gear_P)) && (tmpRead_1 == Door_Unlock)
          && (tmpRead_8 == Hnd_Unfold) && ((REL_DW.SL_b_DoorHndPullValid_prev_d
            != REL_DW.SL_b_DoorHndPullValid_start_g) &&
           REL_DW.SL_b_DoorHndPullValid_start_g)) {
        REL_DW.is_RlsReq_ku = REL_IN_Trigger_h;
        REL_DW.is_Trigger_o = REL_IN_DoorUnlock_gp;
      }

      /* case IN_Trigger: */
    } else if (REL_B.Compare || ((REL_B.TmpSignalConversionAtVeOUT_SP_E >= 1) &&
                (!REL_B.TmpSignalConversionAtVbINP_CAN_) &&
                (REL_B.DataTypeConversion14 != Gear_P)) || (tmpRead_1 !=
                Door_Unlock) || (tmpRead_8 != Hnd_Unfold) || (SO_m_FLDoorRatSts ==
                Rat_Unlock)) {
      REL_DW.is_Trigger_o = 0;
      REL_DW.is_RlsReq_ku = REL_IN_Idle_p;
    } else if (REL_DW.is_Trigger_o == REL_IN_DoorUnlock_gp) {
      if (SO_m_FLDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_o = REL_IN_Release_ni;
        REL_DW.temporalCounter_i5_h = 0U;
        REL_B.SO_b_DoorRlsReq_jt = true;
        REL_B.SO_e_DoorRlsDelayTime_m = 4U;
      }

      /* case IN_Release: */
    } else if (REL_DW.temporalCounter_i5_h >= 5) {
      REL_B.SO_b_DoorRlsReq_jt = false;
      REL_B.SO_e_DoorRlsDelayTime_m = 0U;
      REL_DW.is_Trigger_o = 0;
      REL_DW.is_RlsReq_ku = REL_IN_Idle_p;
    }

    REL_DoorHndBtn_k(&SO_m_FLDoorRatSts, &tmpRead_1);
    if (REL_DW.is_DoorCentral_m == REL_IN_Idle_p) {
      if ((!REL_B.Compare) && (((REL_B.TmpSignalConversionAtVeOUT_SP_E <= 0) &&
            (!REL_B.TmpSignalConversionAtVbINP_CAN_)) ||
           (REL_B.DataTypeConversion14 == Gear_P)) &&
          (((REL_DW.SL_b_CentSingleDoorBtnValid_p_e !=
             REL_DW.SL_b_CentSingleDoorBtnValid_s_a) &&
            REL_DW.SL_b_CentSingleDoorBtnValid_s_a) ||
           ((REL_DW.SL_b_CentAllDoorBtnValid_prev_c !=
             REL_DW.SL_b_CentAllDoorBtnValid_star_m) &&
            REL_DW.SL_b_CentAllDoorBtnValid_star_m))) {
        REL_DW.is_DoorCentral_m = REL_IN_Trigger_h;
        switch (tmpRead_1) {
         case Door_Lock:
          REL_DW.is_Trigger_do = REL_IN_DoorLock_f;
          REL_DW.is_DoorLock_c = REL_IN_UnlockReq_k;
          REL_DW.temporalCounter_i3_b = 0U;
          REL_B.SO_m_UnlockReq_k = Unlock_Req;
          break;

         case Door_Unlock:
          REL_DW.is_Trigger_do = REL_IN_DoorUnlock_g;
          break;

         default:
          REL_DW.is_Trigger_do = REL_IN_Error_a;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (REL_B.Compare || ((REL_B.TmpSignalConversionAtVeOUT_SP_E >= 1) &&
                (!REL_B.TmpSignalConversionAtVbINP_CAN_) &&
                (REL_B.DataTypeConversion14 != Gear_P)) || ((tmpRead_1 ==
                 Door_Unlock) && (SO_m_FLDoorRatSts == Rat_Unlock))) {
      REL_DW.is_DoorLock_c = 0;
      REL_DW.is_Trigger_do = 0;
      REL_DW.is_DoorCentral_m = REL_IN_Idle_p;
    } else {
      switch (REL_DW.is_Trigger_do) {
       case REL_IN_DoorLock_f:
        switch (REL_DW.is_DoorLock_c) {
         case REL_IN_UnlockFail_i:
          REL_DW.is_DoorLock_c = 0;
          REL_DW.is_Trigger_do = 0;
          REL_DW.is_DoorCentral_m = REL_IN_Idle_p;
          break;

         case REL_IN_UnlockReq_k:
          if (tmpRead_1 == Door_Unlock) {
            REL_DW.is_DoorLock_c = REL_IN_UnlockSucess_a;
          } else if ((REL_DW.temporalCounter_i3_b >= 50) && (tmpRead_1 ==
                      Door_Lock)) {
            REL_DW.is_DoorLock_c = REL_IN_UnlockFail_i;
          } else if (REL_DW.temporalCounter_i3_b == 5) {
            REL_B.SO_m_UnlockReq_k = Unlock_Idle;
          }
          break;

         default:
          /* case IN_UnlockSucess: */
          if (SO_m_FLDoorRatSts != Rat_Unlock) {
            REL_DW.is_DoorLock_c = 0;
            REL_DW.is_Trigger_do = REL_IN_RELEASE_g;
            REL_DW.temporalCounter_i3_b = 0U;
            REL_B.SO_b_DoorRlsReq_jt = true;
          }
          break;
        }
        break;

       case REL_IN_DoorUnlock_g:
        if (SO_m_FLDoorRatSts != Rat_Unlock) {
          REL_DW.is_Trigger_do = REL_IN_RELEASE_g;
          REL_DW.temporalCounter_i3_b = 0U;
          REL_B.SO_b_DoorRlsReq_jt = true;
        }
        break;

       case REL_IN_Error_a:
        REL_DW.is_Trigger_do = 0;
        REL_DW.is_DoorCentral_m = REL_IN_Idle_p;
        break;

       default:
        /* case IN_RELEASE: */
        if (REL_DW.temporalCounter_i3_b >= 5) {
          REL_B.SO_b_DoorRlsReq_jt = false;
          REL_DW.is_Trigger_do = 0;
          REL_DW.is_DoorCentral_m = REL_IN_Idle_p;
        }
        break;
      }
    }

    REL_DW.SL_b_CentAllDoorBtnValid_h = REL_B.TmpSignalConversionAtVbINP_CA_f;
    if (REL_DW.is_RlsReq_na == REL_IN_Idle_p) {
      if ((!REL_B.Compare) && (((REL_B.TmpSignalConversionAtVeOUT_SP_E <= 0) &&
            (!REL_B.TmpSignalConversionAtVbINP_CAN_)) ||
           (REL_B.DataTypeConversion14 == Gear_P)) &&
          REL_B.SO_b_DoorAutoRlsSetSts && (tmpRead_1 == Door_Unlock) &&
          ((REL_DW.SI_b_DoorAutoRlsReq_prev_b !=
            REL_DW.SI_b_DoorAutoRlsReq_start_k) &&
           REL_DW.SI_b_DoorAutoRlsReq_start_k)) {
        REL_DW.is_RlsReq_na = REL_IN_Trigger_h;
        REL_DW.is_Trigger_fu = REL_IN_DoorUnlock_gp;
      }

      /* case IN_Trigger: */
    } else if (REL_B.Compare || ((REL_B.TmpSignalConversionAtVeOUT_SP_E >= 1) &&
                (!REL_B.TmpSignalConversionAtVbINP_CAN_) &&
                (REL_B.DataTypeConversion14 != Gear_P)) ||
               (!REL_B.SO_b_DoorAutoRlsSetSts) || (tmpRead_1 != Door_Unlock) ||
               (SO_m_FLDoorRatSts == Rat_Unlock)) {
      REL_DW.is_Trigger_fu = 0;
      REL_DW.is_RlsReq_na = REL_IN_Idle_p;
    } else if (REL_DW.is_Trigger_fu == REL_IN_DoorUnlock_gp) {
      if (SO_m_FLDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_fu = REL_IN_Release_ni;
        REL_DW.temporalCounter_i7_l = 0U;
        REL_B.SO_b_DoorRlsReq_jt = true;
      }

      /* case IN_Release: */
    } else if (REL_DW.temporalCounter_i7_l >= 5) {
      REL_B.SO_b_DoorRlsReq_jt = false;
      REL_DW.is_Trigger_fu = 0;
      REL_DW.is_RlsReq_na = REL_IN_Idle_p;
    }
  }

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VbINP_CAN_FLDCUCinchHomeSwitch_flg_VbINP_CAN_FLDCUCinchHomeSwitch_flg' */
  (void)
    Rte_Read_VbINP_CAN_FLDCUCinchHomeSwitch_flg_VbINP_CAN_FLDCUCinchHomeSwitch_flg
    (&tmpRead_6);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/FLDoorRlsDriver' */
  REL_FLDoorRlsDriver(REL_B.SO_b_DoorRlsReq_jt,
                      REL_B.TmpSignalConversionAtVbINP_HWA_, tmpRead_6,
                      REL_B.TmpSignalConversionAtVbINP_CFG_,
                      REL_B.SO_e_DoorRlsDelayTime_m, &REL_B.SO_b_MotorA_b,
                      &REL_B.SO_b_MotorB_m, &REL_B.SO_e_MotorCmd_l,
                      &SO_b_Error_c, &SO_e_MotorPwm_o,
                      &REL_DW.sf_FLDoorRlsDriver);

  /* Chart: '<S3>/Unlock_Request' */
  if (REL_DW.is_active_c6_REL == 0U) {
    REL_DW.is_active_c6_REL = 1U;
    if (((REL_GetDrvUnlockReq() == 1.0) && (REL_GetPassUnlockReq() == 1.0)) ||
        (REL_GetDrvUnlockReq() == 2.0) || (REL_GetPassUnlockReq() == 2.0)) {
      SO_e_MotorPwm_o = 3U;

      /*   */
    } else if ((REL_GetDrvUnlockReq() == 0.0) && (REL_GetPassUnlockReq() == 1.0))
    {
      SO_e_MotorPwm_o = 2U;
    } else {
      /*   */
      SO_e_MotorPwm_o = (uint8)((REL_GetDrvUnlockReq() == 1.0) &&
        (REL_GetPassUnlockReq() == 0.0));
    }
  } else if (((REL_GetDrvUnlockReq() == 1.0) && (REL_GetPassUnlockReq() == 1.0))
             || (REL_GetDrvUnlockReq() == 2.0) || (REL_GetPassUnlockReq() == 2.0))
  {
    SO_e_MotorPwm_o = 3U;

    /*   */
  } else if ((REL_GetDrvUnlockReq() == 0.0) && (REL_GetPassUnlockReq() == 1.0))
  {
    SO_e_MotorPwm_o = 2U;
  } else {
    /*   */
    SO_e_MotorPwm_o = (uint8)((REL_GetDrvUnlockReq() == 1.0) &&
      (REL_GetPassUnlockReq() == 0.0));
  }

  /* End of Chart: '<S3>/Unlock_Request' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
  (void)
    Rte_Write_VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg
    (REL_B.SO_b_DoorAutoRlsSetSts);

  /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
  (void)
    Rte_Write_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg
    (REL_B.SO_b_DoorAutoRlsSetStsToEE);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Outport: '<Root>/VeOUT_REL_BcmDrvrDoorSwtSts_sig_VeOUT_REL_BcmDrvrDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   */
  (void)
    Rte_Write_VeOUT_REL_BcmDrvrDoorSwtSts_sig_VeOUT_REL_BcmDrvrDoorSwtSts_sig
    (REL_B.SL_b_FLDoorInBtnSts);

  /* Outport: '<Root>/VeOUT_REL_BcmPassDoorSwtSts_sig_VeOUT_REL_BcmPassDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  (void)
    Rte_Write_VeOUT_REL_BcmPassDoorSwtSts_sig_VeOUT_REL_BcmPassDoorSwtSts_sig
    (REL_B.SL_b_FRDoorInBtnSts);

  /* Outport: '<Root>/VeOUT_REL_BcmLeReDoorSwtSts_sig_VeOUT_REL_BcmLeReDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  (void)
    Rte_Write_VeOUT_REL_BcmLeReDoorSwtSts_sig_VeOUT_REL_BcmLeReDoorSwtSts_sig
    (REL_B.SL_b_RLDoorInBtnSts);

  /* Outport: '<Root>/VeOUT_REL_BcmRiReDoorSwtSts_sig_VeOUT_REL_BcmRiReDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  (void)
    Rte_Write_VeOUT_REL_BcmRiReDoorSwtSts_sig_VeOUT_REL_BcmRiReDoorSwtSts_sig
    (REL_B.SL_b_RRDoorInBtnSts);

  /* Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   */
  (void)Rte_Write_VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig
    (SO_m_FLDoorRatSts);

  /* Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion5'
   */
  (void)Rte_Write_VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig
    (SO_m_FRDoorRatSts);

  /* Outport: '<Root>/VeOUT_REL_BdcLRDoorRatSts_sig_VeOUT_REL_BdcLRDoorRatSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion6'
   */
  (void)Rte_Write_VeOUT_REL_BdcLRDoorRatSts_sig_VeOUT_REL_BdcLRDoorRatSts_sig
    (REL_B.SO_m_RLDoorRatSts);

  /* Outport: '<Root>/VeOUT_REL_BdcRRDoorRatSts_sig_VeOUT_REL_BdcRRDoorRatSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   */
  (void)Rte_Write_VeOUT_REL_BdcRRDoorRatSts_sig_VeOUT_REL_BdcRRDoorRatSts_sig
    (REL_B.SO_m_RRDoorRatSts);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Outport: '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg' */
  (void)
    Rte_Write_VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg
    (SL_b_FLDoorHndPullSts);

  /* Outport: '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg' */
  (void)
    Rte_Write_VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg
    (SL_b_FRDoorHndPullSts);

  /* Outport: '<Root>/VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg' */
  (void)
    Rte_Write_VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg
    (REL_B.SL_b_RLDoorHndPullSts);

  /* Outport: '<Root>/VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg' */
  (void)
    Rte_Write_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg
    (REL_B.SL_b_RRDoorHndPullSts);

  /* Outport: '<Root>/VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg' */
  (void)Rte_Write_VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg
    (SL_b_FLDoorHndBtnSts);

  /* Outport: '<Root>/VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg' */
  (void)Rte_Write_VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg
    (REL_B.SL_b_FRDoorHndBtnSts);

  /* Outport: '<Root>/VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg' */
  (void)Rte_Write_VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg
    (REL_B.SL_b_RLDoorHndBtnSts);

  /* Outport: '<Root>/VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg' */
  (void)Rte_Write_VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg
    (REL_B.SL_b_RRDoorHndBtnSts);

  /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
  (void)Rte_Write_VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg
    (REL_B.SO_b_MotorA_b);

  /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
  (void)Rte_Write_VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg
    (REL_B.SO_b_MotorB_m);

  /* Outport: '<Root>/VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg' */
  (void)Rte_Write_VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg
    (REL_B.SO_b_MotorA_fc);

  /* Outport: '<Root>/VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg' */
  (void)Rte_Write_VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg
    (REL_B.SO_b_MotorB_b);

  /* Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg' */
  (void)Rte_Write_VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg
    (REL_B.SO_b_MotorA_f);

  /* Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg' */
  (void)Rte_Write_VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg
    (REL_B.SO_b_MotorB_f);

  /* Outport: '<Root>/VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg' */
  (void)Rte_Write_VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg
    (REL_B.SO_b_MotorA);

  /* Outport: '<Root>/VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg' */
  (void)Rte_Write_VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg
    (REL_B.SO_b_MotorB);

  /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
  (void)Rte_Write_VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig
    (SO_e_MotorPwm_o);

  /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
  (void)Rte_Write_VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg
    (REL_B.SO_b_DoorRlsReq_jt);

  /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
  (void)Rte_Write_VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg
    (REL_B.SO_b_DoorRlsReq_l);

  /* Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg' */
  (void)Rte_Write_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg
    (REL_B.SO_b_DoorRlsReq_j);

  /* Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg' */
  (void)Rte_Write_VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg
    (REL_B.SO_b_DoorRlsReq);

  /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
  (void)Rte_Write_VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig(0U);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Outport: '<Root>/VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion9'
   */
  (void)Rte_Write_VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig
    (REL_B.SO_e_MotorCmd_e);

  /* Outport: '<Root>/VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion10'
   */
  (void)Rte_Write_VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig
    (REL_B.SO_e_MotorCmd_c);

  /* Outport: '<Root>/VeOUT_REL_RRDoorMotorSts_sig_VeOUT_REL_RRDoorMotorSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion11'
   */
  (void)Rte_Write_VeOUT_REL_RRDoorMotorSts_sig_VeOUT_REL_RRDoorMotorSts_sig
    (REL_B.SO_e_MotorCmd);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */
}

/* Model initialize function */
void REL_Init(void)
{
  {
    uint8 SO_e_MotorPwm_o;
    boolean SO_b_Error_c;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
     *  SubSystem: '<Root>/REL_Step_sys'
     */

    /* SystemInitialize for Chart: '<S3>/FLDoorRlsDriver' */
    REL_FLDoorRlsDriver_Init(&REL_B.SO_b_MotorA_b, &REL_B.SO_b_MotorB_m,
      &REL_B.SO_e_MotorCmd_l, &SO_b_Error_c, &SO_e_MotorPwm_o);

    /* SystemInitialize for Chart: '<S3>/FRDoorRlsDriver' */
    REL_FLDoorRlsDriver_Init(&REL_B.SO_b_MotorA_fc, &REL_B.SO_b_MotorB_b,
      &REL_B.SO_e_MotorCmd_e, &SO_b_Error_c, &SO_e_MotorPwm_o);

    /* SystemInitialize for Chart: '<S3>/RLDoorRlsDriver' */
    REL_FLDoorRlsDriver_Init(&REL_B.SO_b_MotorA_f, &REL_B.SO_b_MotorB_f,
      &REL_B.SO_e_MotorCmd_c, &SO_b_Error_c, &SO_e_MotorPwm_o);

    /* SystemInitialize for Chart: '<S3>/RLDoorRlsReq' */
    REL_RLDoorRlsReq_Init(&REL_B.SO_b_DoorRlsReq_j,
                          &REL_B.SO_e_DoorRlsDelayTime_e,
                          &REL_B.SO_m_UnlockReq_e);

    /* SystemInitialize for Chart: '<S3>/RRDoorRlsDriver' */
    REL_FLDoorRlsDriver_Init(&REL_B.SO_b_MotorA, &REL_B.SO_b_MotorB,
      &REL_B.SO_e_MotorCmd, &SO_b_Error_c, &SO_e_MotorPwm_o);

    /* SystemInitialize for Chart: '<S3>/RRDoorRlsReq' */
    REL_RLDoorRlsReq_Init(&REL_B.SO_b_DoorRlsReq, &REL_B.SO_e_DoorRlsDelayTime,
                          &REL_B.SO_m_UnlockReq);

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
    (void)Rte_Write_VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg
      (REL_B.SO_b_MotorA_b);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
    (void)Rte_Write_VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg
      (REL_B.SO_b_MotorB_m);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg' */
    (void)Rte_Write_VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg
      (REL_B.SO_b_MotorA_fc);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg' */
    (void)Rte_Write_VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg
      (REL_B.SO_b_MotorB_b);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg' */
    (void)Rte_Write_VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg
      (REL_B.SO_b_MotorA_f);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg' */
    (void)Rte_Write_VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg
      (REL_B.SO_b_MotorB_f);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg' */
    (void)Rte_Write_VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg
      (REL_B.SO_b_MotorA);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg' */
    (void)Rte_Write_VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg
      (REL_B.SO_b_MotorB);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg' */
    (void)Rte_Write_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg
      (REL_B.SO_b_DoorRlsReq_j);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg' */
    (void)Rte_Write_VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg
      (REL_B.SO_b_DoorRlsReq);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
