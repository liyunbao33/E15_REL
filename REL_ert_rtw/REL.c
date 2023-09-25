/*
 * File: REL.c
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.59
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Sep 25 09:33:03 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "REL.h"
#include "Rte_Type.h"
#include "rtwtypes.h"
#include "REL_private.h"

/* Named constants for Chart: '<S3>/FLDoorRlsDriver' */
#define REL_IN_Checking                ((uint8_T)1U)
#define REL_IN_Delay                   ((uint8_T)2U)
#define REL_IN_ElectricDoor            ((uint8_T)1U)
#define REL_IN_Fail                    ((uint8_T)1U)
#define REL_IN_Fail1                   ((uint8_T)2U)
#define REL_IN_Ice_Break               ((uint8_T)3U)
#define REL_IN_Idle                    ((uint8_T)1U)
#define REL_IN_Idle_m                  ((uint8_T)4U)
#define REL_IN_LastCheck               ((uint8_T)2U)
#define REL_IN_LastCheck_o             ((uint8_T)5U)
#define REL_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define REL_IN_NonElectricDoor         ((uint8_T)2U)
#define REL_IN_Normal                  ((uint8_T)1U)
#define REL_IN_PowerOn                 ((uint8_T)2U)
#define REL_IN_Release                 ((uint8_T)2U)
#define REL_IN_Reset                   ((uint8_T)3U)
#define REL_IN_Step1_Ajar              ((uint8_T)4U)
#define REL_IN_Step2_Open              ((uint8_T)5U)
#define REL_IN_Success                 ((uint8_T)6U)

/* Named constants for Chart: '<S3>/RLDoorRlsReq' */
#define REL_IN_DoorLock                ((uint8_T)1U)
#define REL_IN_DoorUnlock              ((uint8_T)2U)
#define REL_IN_Error                   ((uint8_T)3U)
#define REL_IN_Idle_i                  ((uint8_T)1U)
#define REL_IN_NO_ACTIVE_CHILD_d       ((uint8_T)0U)
#define REL_IN_Once                    ((uint8_T)2U)
#define REL_IN_Press                   ((uint8_T)2U)
#define REL_IN_Release_o               ((uint8_T)4U)
#define REL_IN_Release_oa              ((uint8_T)3U)
#define REL_IN_Trigger                 ((uint8_T)2U)
#define REL_IN_Twice                   ((uint8_T)3U)
#define REL_IN_UnlockFail              ((uint8_T)1U)
#define REL_IN_UnlockReq               ((uint8_T)2U)
#define REL_IN_UnlockSucess            ((uint8_T)3U)

/* Named constants for Chart: '<S3>/DoorSwSts' */
#define REL_IN_Crash                   ((uint8_T)1U)
#define REL_IN_NoCrash                 ((uint8_T)2U)

/* Named constants for Chart: '<S3>/FLDoorRlsReq' */
#define REL_IN_DoorLock_f              ((uint8_T)1U)
#define REL_IN_DoorUnlock_g            ((uint8_T)2U)
#define REL_IN_Error_a                 ((uint8_T)3U)
#define REL_IN_Idle_p                  ((uint8_T)1U)
#define REL_IN_Once_o                  ((uint8_T)2U)
#define REL_IN_Press_f                 ((uint8_T)2U)
#define REL_IN_Release_n               ((uint8_T)4U)
#define REL_IN_Release_ni              ((uint8_T)3U)
#define REL_IN_Trigger_h               ((uint8_T)2U)
#define REL_IN_Twice_i                 ((uint8_T)3U)
#define REL_IN_UnlockFail_i            ((uint8_T)1U)
#define REL_IN_UnlockReq_k             ((uint8_T)2U)
#define REL_IN_UnlockSucess_a          ((uint8_T)3U)

/* Block signals (default storage) */
B_REL_T REL_B;

/* Block states (default storage) */
DW_REL_T REL_DW;

/* External inputs (root inport signals with default storage) */
ExtU_REL_T REL_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_REL_T REL_Y;

/* Real-time model */
static RT_MODEL_REL_T REL_M_;
RT_MODEL_REL_T *const REL_M = &REL_M_;

/* Forward declaration for local functions */
static void REL_Normal(Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_CinchHome,
  uint8_T rtu_SI_e_DoorRlsDelayTime, boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorCmd, boolean_T *rty_SO_b_Error,
  uint8_T *rty_SO_e_MotorPwm, DW_FLDoorRlsDriver_REL_T *localDW);

/* Forward declaration for local functions */
static void REL_enter_atomic_NoCrash(boolean_T *SL_b_FRDoorInBtnSts, boolean_T
  *SL_b_RLDoorInBtnSts, boolean_T *SL_b_RRDoorInBtnSts, boolean_T
  *SL_b_FLDoorInBtnSts);

/*
 * Output and update for atomic system:
 *    '<S3>/FLDoorRatSts'
 *    '<S3>/FRDoorRatSts'
 *    '<S3>/RLDoorRatSts'
 *    '<S3>/RRDoorRatSts'
 */
void REL_FLDoorRatSts(Boolean rtu_SI_b_DoorOpen, uint8_T *rty_SO_e_DoorRatSts)
{
  /*  condition 1 */
  /*  condition 2 */
  if (!rtu_SI_b_DoorOpen) {
    /*  All Lock */
    *rty_SO_e_DoorRatSts = 1U;
  } else {
    /*  All Unlock */
    *rty_SO_e_DoorRatSts = 3U;
  }
}

/* Function for Chart: '<S3>/FLDoorRlsDriver' */
static void REL_Normal(Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_CinchHome,
  uint8_T rtu_SI_e_DoorRlsDelayTime, boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorCmd, boolean_T *rty_SO_b_Error,
  uint8_T *rty_SO_e_MotorPwm, DW_FLDoorRlsDriver_REL_T *localDW)
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
            *rty_SO_e_MotorCmd = 0U;
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
              *rty_SO_e_MotorCmd = 1U;
            } else if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                       (localDW->SL_e_CycleCount >= 2)) {
              localDW->is_Release_a = REL_IN_Reset;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_b_MotorA = false;
              *rty_SO_b_MotorB = true;
              *rty_SO_e_MotorCmd = 2U;
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
          *rty_SO_e_MotorCmd = 1U;
        }
        break;

       case REL_IN_Reset:
        if (localDW->temporalCounter_i1 >= 30) {
          localDW->is_Release_a = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_MainProgress_c = REL_IN_Idle;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorCmd = 0U;
          *rty_SO_e_MotorPwm = 0U;
        }
        break;

       case REL_IN_Step1_Ajar:
        {
          if (localDW->temporalCounter_i1 >= 30) {
            int32_T tmp;
            localDW->is_Release_a = REL_IN_Checking;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = false;
            *rty_SO_e_MotorCmd = 0U;
            tmp = localDW->SL_e_CycleCount + 1;
            if (localDW->SL_e_CycleCount + 1 > 255) {
              tmp = 255;
            }

            localDW->SL_e_CycleCount = (uint8_T)tmp;
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
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 100U;
          break;

         case REL_IN_Fail1:
          localDW->is_Step2_Open_i = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_Release_a = REL_IN_Reset;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorCmd = 2U;
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
            *rty_SO_e_MotorCmd = 2U;
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
          *rty_SO_e_MotorCmd = 2U;
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
          *rty_SO_e_MotorCmd = 0U;
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
            *rty_SO_e_MotorCmd = 1U;
          } else if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                     (localDW->SL_e_CycleCount >= 2)) {
            localDW->is_Release = REL_IN_Reset;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = true;
            *rty_SO_e_MotorCmd = 2U;
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
        *rty_SO_e_MotorCmd = 1U;
      }
      break;

     case REL_IN_Reset:
      if (localDW->temporalCounter_i1 >= 30) {
        localDW->is_Release = REL_IN_NO_ACTIVE_CHILD;
        localDW->is_MainProgress = REL_IN_Idle;
        *rty_SO_b_MotorA = false;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
      }
      break;

     case REL_IN_Step1_Ajar:
      {
        if (localDW->temporalCounter_i1 >= 30) {
          int32_T tmp;
          localDW->is_Release = REL_IN_Checking;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorCmd = 0U;
          tmp = localDW->SL_e_CycleCount + 1;
          if (localDW->SL_e_CycleCount + 1 > 255) {
            tmp = 255;
          }

          localDW->SL_e_CycleCount = (uint8_T)tmp;
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
          *rty_SO_e_MotorCmd = 2U;
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
        *rty_SO_e_MotorCmd = 2U;
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
void REL_FLDoorRlsDriver_Init(boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorCmd, boolean_T *rty_SO_b_Error,
  uint8_T *rty_SO_e_MotorPwm)
{
  *rty_SO_b_MotorA = false;
  *rty_SO_b_MotorB = false;
  *rty_SO_e_MotorCmd = 0U;
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
void REL_FLDoorRlsDriver(boolean_T rtu_SO_b_DoorRlsReq, Boolean
  rtu_SI_b_DoorAjar, Boolean rtu_SI_b_CinchHome, Boolean rtu_SI_b_ElecDoorCfg,
  uint8_T rtu_SI_e_DoorRlsDelayTime, boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorCmd, boolean_T *rty_SO_b_Error,
  uint8_T *rty_SO_e_MotorPwm, DW_FLDoorRlsDriver_REL_T *localDW)
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
    *rty_SO_e_MotorCmd = 2U;
    *rty_SO_e_MotorPwm = 100U;
  } else if (localDW->is_c19_DoorRlsDriver == REL_IN_Normal) {
    REL_Normal(rtu_SI_b_DoorAjar, rtu_SI_b_CinchHome, rtu_SI_e_DoorRlsDelayTime,
               rty_SO_b_MotorA, rty_SO_b_MotorB, rty_SO_e_MotorCmd,
               rty_SO_b_Error, rty_SO_e_MotorPwm, localDW);

    /* case IN_PowerOn: */
  } else if (localDW->temporalCounter_i1 >= 30) {
    *rty_SO_b_MotorA = false;
    *rty_SO_b_MotorB = false;
    *rty_SO_e_MotorCmd = 0U;
    *rty_SO_e_MotorPwm = 100U;
    localDW->is_c19_DoorRlsDriver = REL_IN_Normal;
    if (!rtu_SI_b_ElecDoorCfg) {
      localDW->is_Normal = REL_IN_NonElectricDoor;
      localDW->is_MainProgress = REL_IN_Idle;
      *rty_SO_b_MotorA = false;
      *rty_SO_b_MotorB = false;
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_e_MotorPwm = 0U;
    } else {
      localDW->is_Normal = REL_IN_ElectricDoor;
      localDW->is_MainProgress_c = REL_IN_Idle;
      *rty_SO_b_MotorA = false;
      *rty_SO_b_MotorB = false;
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_e_MotorPwm = 0U;
    }
  }

  /* End of Chart: '<S3>/FLDoorRlsDriver' */
}

/*
 * System initialize for atomic system:
 *    '<S3>/RLDoorRlsReq'
 *    '<S3>/RRDoorRlsReq'
 */
void REL_RLDoorRlsReq_Init(boolean_T *rty_SO_b_DoorRlsReq, uint8_T
  *rty_SO_e_DoorRlsDelayTime, boolean_T *rty_SO_b_UnlockReq, boolean_T
  *rty_SO_b_PEUnlockReq)
{
  *rty_SO_b_DoorRlsReq = false;
  *rty_SO_e_DoorRlsDelayTime = 0U;
  *rty_SO_b_UnlockReq = false;
  *rty_SO_b_PEUnlockReq = false;
}

/*
 * Output and update for atomic system:
 *    '<S3>/RLDoorRlsReq'
 *    '<S3>/RRDoorRlsReq'
 */
void REL_RLDoorRlsReq(UInt8 rtu_SI_e_EspVehSpd, Boolean rtu_SI_b_EspVehSpdVld,
                      UInt8 rtu_SI_e_VcuGearPosn, UInt8 rtu_SI_e_DoorLockSts,
                      uint8_T rtu_SI_e_DoorRatSts, boolean_T
                      rtu_SI_b_DoorInBtnSts, boolean_T rtu_SI_b_DoorHndBtnSts,
                      Boolean rtu_SI_b_ChildLckSts, boolean_T
                      *rty_SO_b_DoorRlsReq, uint8_T *rty_SO_e_DoorRlsDelayTime,
                      boolean_T *rty_SO_b_UnlockReq, boolean_T
                      *rty_SO_b_PEUnlockReq, DW_RLDoorRlsReq_REL_T *localDW)
{
  if (localDW->temporalCounter_i1 < 63U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->temporalCounter_i2 < 63U) {
    localDW->temporalCounter_i2++;
  }

  if (localDW->temporalCounter_i3 < 255U) {
    localDW->temporalCounter_i3++;
  }

  if (localDW->temporalCounter_i4 < 127U) {
    localDW->temporalCounter_i4++;
  }

  localDW->SI_b_DoorInBtnSts_prev = localDW->SI_b_DoorInBtnSts_start;
  localDW->SI_b_DoorInBtnSts_start = rtu_SI_b_DoorInBtnSts;
  localDW->SL_b_DoorInBtnValid_prev = localDW->SL_b_DoorInBtnValid_start;
  localDW->SL_b_DoorInBtnValid_start = localDW->SL_b_DoorInBtnValid;
  localDW->SI_b_DoorHndBtnSts_prev = localDW->SI_b_DoorHndBtnSts_start;
  localDW->SI_b_DoorHndBtnSts_start = rtu_SI_b_DoorHndBtnSts;
  localDW->SL_b_DoorHndBtnValid_prev = localDW->SL_b_DoorHndBtnValid_start;
  localDW->SL_b_DoorHndBtnValid_start = localDW->SL_b_DoorHndBtnValid;

  /* Chart: '<S3>/RLDoorRlsReq' */
  if (localDW->is_active_c5_DoorRlsReq == 0U) {
    localDW->SI_b_DoorInBtnSts_prev = rtu_SI_b_DoorInBtnSts;
    localDW->SI_b_DoorHndBtnSts_prev = rtu_SI_b_DoorHndBtnSts;
    localDW->is_active_c5_DoorRlsReq = 1U;
    localDW->is_SwValid = REL_IN_Idle_i;
    localDW->SL_b_DoorInBtnValid = false;
    localDW->is_RlsReq = REL_IN_Idle_i;
    localDW->is_RlsReq_c = REL_IN_Idle_i;
    localDW->is_SwValid_n = REL_IN_Idle_i;
    localDW->SL_b_DoorHndBtnValid = false;
  } else {
    switch (localDW->is_SwValid) {
     case REL_IN_Idle_i:
      if ((localDW->SI_b_DoorInBtnSts_prev != localDW->SI_b_DoorInBtnSts_start) &&
          localDW->SI_b_DoorInBtnSts_start) {
        localDW->is_SwValid = REL_IN_Once;
        localDW->temporalCounter_i3 = 0U;
      }
      break;

     case REL_IN_Once:
      if ((localDW->SI_b_DoorInBtnSts_prev != localDW->SI_b_DoorInBtnSts_start) &&
          localDW->SI_b_DoorInBtnSts_start) {
        localDW->is_SwValid = REL_IN_Twice;
        localDW->temporalCounter_i3 = 0U;
        localDW->SL_b_DoorInBtnValid = true;
      } else if (localDW->temporalCounter_i3 >= 200) {
        localDW->is_SwValid = REL_IN_Idle_i;
        localDW->SL_b_DoorInBtnValid = false;
      }
      break;

     default:
      /* case IN_Twice: */
      if (localDW->temporalCounter_i3 >= 3) {
        localDW->is_SwValid = REL_IN_Idle_i;
        localDW->SL_b_DoorInBtnValid = false;
      }
      break;
    }

    if (localDW->is_RlsReq == REL_IN_Idle_i) {
      if ((((rtu_SI_e_EspVehSpd <= 0) && (!rtu_SI_b_EspVehSpdVld)) ||
           (rtu_SI_e_VcuGearPosn == 1)) && (!rtu_SI_b_ChildLckSts) &&
          ((localDW->SL_b_DoorInBtnValid_prev !=
            localDW->SL_b_DoorInBtnValid_start) &&
           localDW->SL_b_DoorInBtnValid_start)) {
        localDW->is_RlsReq = REL_IN_Trigger;
        switch (rtu_SI_e_DoorLockSts) {
         case 0:
          localDW->is_Trigger = REL_IN_DoorLock;
          localDW->is_DoorLock = REL_IN_UnlockReq;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_UnlockReq = true;
          break;

         case 1:
          localDW->is_Trigger = REL_IN_DoorUnlock;
          break;

         default:
          localDW->is_Trigger = REL_IN_Error;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (((rtu_SI_e_EspVehSpd >= 1) && (!rtu_SI_b_EspVehSpdVld) &&
                (rtu_SI_e_VcuGearPosn != 1)) || rtu_SI_b_ChildLckSts ||
               ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts == 3))) {
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
          if (rtu_SI_e_DoorLockSts == 1) {
            localDW->is_DoorLock = REL_IN_UnlockSucess;
          } else if ((localDW->temporalCounter_i1 >= 50) &&
                     (rtu_SI_e_DoorLockSts == 0)) {
            localDW->is_DoorLock = REL_IN_UnlockFail;
          } else {
            *rty_SO_b_UnlockReq = ((localDW->temporalCounter_i1 != 5) &&
              (*rty_SO_b_UnlockReq));
          }
          break;

         default:
          /* case IN_UnlockSucess: */
          if (rtu_SI_e_DoorRatSts != 3) {
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
        if (rtu_SI_e_DoorRatSts != 3) {
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

    if (localDW->is_RlsReq_c == REL_IN_Idle_i) {
      if ((((rtu_SI_e_EspVehSpd <= 0) && (!rtu_SI_b_EspVehSpdVld)) ||
           (rtu_SI_e_VcuGearPosn == 1)) && ((localDW->SL_b_DoorHndBtnValid_prev
            != localDW->SL_b_DoorHndBtnValid_start) &&
           localDW->SL_b_DoorHndBtnValid_start)) {
        localDW->is_RlsReq_c = REL_IN_Trigger;
        switch (rtu_SI_e_DoorLockSts) {
         case 0:
          localDW->is_Trigger_k = REL_IN_DoorLock;
          localDW->is_DoorLock_d = REL_IN_UnlockReq;
          localDW->temporalCounter_i2 = 0U;
          *rty_SO_b_PEUnlockReq = true;
          break;

         case 1:
          localDW->is_Trigger_k = REL_IN_DoorUnlock;
          break;

         default:
          localDW->is_Trigger_k = REL_IN_Error;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (((rtu_SI_e_EspVehSpd >= 1) && (!rtu_SI_b_EspVehSpdVld) &&
                (rtu_SI_e_VcuGearPosn != 1)) || ((rtu_SI_e_DoorLockSts == 1) &&
                (rtu_SI_e_DoorRatSts == 3))) {
      localDW->is_DoorLock_d = REL_IN_NO_ACTIVE_CHILD_d;
      localDW->is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_d;
      localDW->is_RlsReq_c = REL_IN_Idle_i;
    } else {
      switch (localDW->is_Trigger_k) {
       case REL_IN_DoorLock:
        switch (localDW->is_DoorLock_d) {
         case REL_IN_UnlockFail:
          localDW->is_DoorLock_d = REL_IN_NO_ACTIVE_CHILD_d;
          localDW->is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_d;
          localDW->is_RlsReq_c = REL_IN_Idle_i;
          break;

         case REL_IN_UnlockReq:
          if (rtu_SI_e_DoorLockSts == 1) {
            localDW->is_DoorLock_d = REL_IN_UnlockSucess;
          } else if ((localDW->temporalCounter_i2 >= 50) &&
                     (rtu_SI_e_DoorLockSts == 0)) {
            localDW->is_DoorLock_d = REL_IN_UnlockFail;
          } else {
            *rty_SO_b_PEUnlockReq = ((localDW->temporalCounter_i2 != 5) &&
              (*rty_SO_b_PEUnlockReq));
          }
          break;

         default:
          /* case IN_UnlockSucess: */
          if (rtu_SI_e_DoorRatSts != 3) {
            localDW->is_DoorLock_d = REL_IN_NO_ACTIVE_CHILD_d;
            localDW->is_Trigger_k = REL_IN_Release_o;
            localDW->temporalCounter_i2 = 0U;
            *rty_SO_b_DoorRlsReq = true;
          }
          break;
        }
        break;

       case REL_IN_DoorUnlock:
        if (rtu_SI_e_DoorRatSts != 3) {
          localDW->is_Trigger_k = REL_IN_Release_o;
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
          localDW->is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_d;
          localDW->is_RlsReq_c = REL_IN_Idle_i;
        }
        break;
      }
    }

    switch (localDW->is_SwValid_n) {
     case REL_IN_Idle_i:
      if ((localDW->SI_b_DoorHndBtnSts_prev != localDW->SI_b_DoorHndBtnSts_start)
          && localDW->SI_b_DoorHndBtnSts_start) {
        localDW->is_SwValid_n = REL_IN_Press;
        localDW->temporalCounter_i4 = 0U;
      }
      break;

     case REL_IN_Press:
      if ((localDW->SI_b_DoorHndBtnSts_prev != localDW->SI_b_DoorHndBtnSts_start)
          && (!localDW->SI_b_DoorHndBtnSts_start)) {
        localDW->is_SwValid_n = REL_IN_Release_oa;
        localDW->temporalCounter_i4 = 0U;
        localDW->SL_b_DoorHndBtnValid = true;
      } else if (localDW->temporalCounter_i4 >= 100) {
        localDW->is_SwValid_n = REL_IN_Idle_i;
        localDW->SL_b_DoorHndBtnValid = false;
      }
      break;

     default:
      /* case IN_Release: */
      if (localDW->temporalCounter_i4 >= 3) {
        localDW->is_SwValid_n = REL_IN_Idle_i;
        localDW->SL_b_DoorHndBtnValid = false;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/RLDoorRlsReq' */
}

/* Function for Chart: '<S3>/DoorSwSts' */
static void REL_enter_atomic_NoCrash(boolean_T *SL_b_FRDoorInBtnSts, boolean_T
  *SL_b_RLDoorInBtnSts, boolean_T *SL_b_RRDoorInBtnSts, boolean_T
  *SL_b_FLDoorInBtnSts)
{
  /* Inport: '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg' */
  *SL_b_FLDoorInBtnSts = REL_U.VbINP_HWA_FLDoorButton_flg_VbIN;

  /* Inport: '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg' */
  *SL_b_FRDoorInBtnSts = REL_U.VbINP_HWA_FRDoorButton_flg_VbIN;

  /* Inport: '<Root>/VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg' */
  *SL_b_RLDoorInBtnSts = REL_U.VbINP_HWA_RLDoorButton_flg_VbIN;

  /* Inport: '<Root>/VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg' */
  *SL_b_RRDoorInBtnSts = REL_U.VbINP_HWA_RRDoorButton_flg_VbIN;

  /* Outport: '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorOutButton_flg_VbINP_HWA_FLDoorOutButton_flg'
   */
  REL_Y.VbOUT_REL_BcmDrvrDoorHandleReq_ = REL_U.VbINP_HWA_FLDoorOutButton_flg_V;

  /* Outport: '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg'
   */
  REL_Y.VbOUT_REL_BcmPassDoorHandleReq_ = REL_U.VbINP_HWA_FRDoorOutButton_flg_V;

  /* Outport: '<Root>/VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg'
   */
  REL_Y.VbOUT_REL_BcmLeReDoorHandleReq_ = REL_U.VbINP_HWA_RLDoorOutButton_flg_V;

  /* Outport: '<Root>/VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg'
   */
  REL_Y.VbOUT_REL_BcmBcmRiReDoorHandleR = REL_U.VbINP_HWA_RRDoorOutButton_flg_V;

  /* Outport: '<Root>/VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg'
   */
  REL_Y.VbOUT_REL_FLDoorHndlBtnSig_flg_ = REL_U.VbINP_HWA_FLDoorHandleSW_flg_Vb;

  /* Outport: '<Root>/VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorHandleSW_flg_VbINP_HWA_FRDoorHandleSW_flg'
   */
  REL_Y.VbOUT_REL_FRDoorHndlBtnSig_flg_ = REL_U.VbINP_HWA_FRDoorHandleSW_flg_Vb;

  /* Outport: '<Root>/VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg'
   */
  REL_Y.VbOUT_REL_RLDoorHndlBtnSig_flg_ = REL_U.VbINP_HWA_RLDoorHandleSW_flg_Vb;

  /* Outport: '<Root>/VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorHandleSW_flg_VbINP_HWA_RRDoorHandleSW_flg'
   */
  REL_Y.VbOUT_REL_RRDoorHndlBtnSig_flg_ = REL_U.VbINP_HWA_RRDoorHandleSW_flg_Vb;
}

/* Model step function for TID1 */
void REL_Step(void)                    /* Explicit Task: REL_Step */
{
  uint8_T SO_e_MotorPwm_o;
  boolean_T SI_b_CrashSts_prev;
  boolean_T SI_b_DoorHndBtnSts_prev_c;
  boolean_T SI_b_DoorInBtnSts_prev_n;
  boolean_T SL_b_DoorHndBtnValid_prev_a;
  boolean_T SL_b_FLDoorInBtnSts;
  boolean_T SL_b_FRDoorInBtnSts;
  boolean_T SL_b_RRDoorInBtnSts;

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/DoorSwSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg'
   *  Inport: '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg'
   *  Inport: '<Root>/VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg'
   *  Inport: '<Root>/VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg'
   *  Inport: '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg'
   */
  if (REL_DW.temporalCounter_i1 < 1023U) {
    REL_DW.temporalCounter_i1++;
  }

  SI_b_CrashSts_prev = REL_DW.SI_b_CrashSts_start;
  REL_DW.SI_b_CrashSts_start = REL_U.VbOUT_SP_CrashOutpSts_flg_VbOUT;
  if (REL_DW.is_active_c23_REL == 0U) {
    REL_DW.is_active_c23_REL = 1U;
    REL_DW.is_c23_REL = REL_IN_NoCrash;
    REL_enter_atomic_NoCrash(&SL_b_FRDoorInBtnSts, &SI_b_CrashSts_prev,
      &SL_b_RRDoorInBtnSts, &SL_b_FLDoorInBtnSts);
  } else if (REL_DW.is_c23_REL == REL_IN_Crash) {
    if (REL_DW.temporalCounter_i1 >= 1000) {
      REL_DW.is_c23_REL = REL_IN_NoCrash;
      REL_enter_atomic_NoCrash(&SL_b_FRDoorInBtnSts, &SI_b_CrashSts_prev,
        &SL_b_RRDoorInBtnSts, &SL_b_FLDoorInBtnSts);
    } else {
      SL_b_FLDoorInBtnSts = false;
      SL_b_FRDoorInBtnSts = false;
      SI_b_CrashSts_prev = false;
      SL_b_RRDoorInBtnSts = false;

      /* Outport: '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg' */
      REL_Y.VbOUT_REL_BcmDrvrDoorHandleReq_ = false;

      /* Outport: '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg' */
      REL_Y.VbOUT_REL_BcmPassDoorHandleReq_ = false;

      /* Outport: '<Root>/VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg' */
      REL_Y.VbOUT_REL_BcmLeReDoorHandleReq_ = false;

      /* Outport: '<Root>/VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg' */
      REL_Y.VbOUT_REL_BcmBcmRiReDoorHandleR = false;

      /* Outport: '<Root>/VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg' */
      REL_Y.VbOUT_REL_FLDoorHndlBtnSig_flg_ = false;

      /* Outport: '<Root>/VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg' */
      REL_Y.VbOUT_REL_FRDoorHndlBtnSig_flg_ = false;

      /* Outport: '<Root>/VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg' */
      REL_Y.VbOUT_REL_RLDoorHndlBtnSig_flg_ = false;

      /* Outport: '<Root>/VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg' */
      REL_Y.VbOUT_REL_RRDoorHndlBtnSig_flg_ = false;
    }

    /* case IN_NoCrash: */
  } else if ((SI_b_CrashSts_prev != REL_DW.SI_b_CrashSts_start) &&
             REL_DW.SI_b_CrashSts_start) {
    REL_DW.is_c23_REL = REL_IN_Crash;
    REL_DW.temporalCounter_i1 = 0U;
    SL_b_FLDoorInBtnSts = false;
    SL_b_FRDoorInBtnSts = false;
    SI_b_CrashSts_prev = false;
    SL_b_RRDoorInBtnSts = false;

    /* Outport: '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg' */
    REL_Y.VbOUT_REL_BcmDrvrDoorHandleReq_ = false;

    /* Outport: '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg' */
    REL_Y.VbOUT_REL_BcmPassDoorHandleReq_ = false;

    /* Outport: '<Root>/VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg' */
    REL_Y.VbOUT_REL_BcmLeReDoorHandleReq_ = false;

    /* Outport: '<Root>/VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg' */
    REL_Y.VbOUT_REL_BcmBcmRiReDoorHandleR = false;

    /* Outport: '<Root>/VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg' */
    REL_Y.VbOUT_REL_FLDoorHndlBtnSig_flg_ = false;

    /* Outport: '<Root>/VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg' */
    REL_Y.VbOUT_REL_FRDoorHndlBtnSig_flg_ = false;

    /* Outport: '<Root>/VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg' */
    REL_Y.VbOUT_REL_RLDoorHndlBtnSig_flg_ = false;

    /* Outport: '<Root>/VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg' */
    REL_Y.VbOUT_REL_RRDoorHndlBtnSig_flg_ = false;
  } else {
    SL_b_FLDoorInBtnSts = REL_U.VbINP_HWA_FLDoorButton_flg_VbIN;
    SL_b_FRDoorInBtnSts = REL_U.VbINP_HWA_FRDoorButton_flg_VbIN;
    SI_b_CrashSts_prev = REL_U.VbINP_HWA_RLDoorButton_flg_VbIN;
    SL_b_RRDoorInBtnSts = REL_U.VbINP_HWA_RRDoorButton_flg_VbIN;

    /* Outport: '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg'
     *  Inport: '<Root>/VbINP_HWA_FLDoorOutButton_flg_VbINP_HWA_FLDoorOutButton_flg'
     *  Inport: '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg'
     *  Inport: '<Root>/VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg'
     *  Inport: '<Root>/VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg'
     */
    REL_Y.VbOUT_REL_BcmDrvrDoorHandleReq_ =
      REL_U.VbINP_HWA_FLDoorOutButton_flg_V;

    /* Outport: '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg'
     */
    REL_Y.VbOUT_REL_BcmPassDoorHandleReq_ =
      REL_U.VbINP_HWA_FRDoorOutButton_flg_V;

    /* Outport: '<Root>/VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg'
     */
    REL_Y.VbOUT_REL_BcmLeReDoorHandleReq_ =
      REL_U.VbINP_HWA_RLDoorOutButton_flg_V;

    /* Outport: '<Root>/VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg'
     */
    REL_Y.VbOUT_REL_BcmBcmRiReDoorHandleR =
      REL_U.VbINP_HWA_RRDoorOutButton_flg_V;

    /* Outport: '<Root>/VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg'
     */
    REL_Y.VbOUT_REL_FLDoorHndlBtnSig_flg_ =
      REL_U.VbINP_HWA_FLDoorHandleSW_flg_Vb;

    /* Outport: '<Root>/VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_FRDoorHandleSW_flg_VbINP_HWA_FRDoorHandleSW_flg'
     */
    REL_Y.VbOUT_REL_FRDoorHndlBtnSig_flg_ =
      REL_U.VbINP_HWA_FRDoorHandleSW_flg_Vb;

    /* Outport: '<Root>/VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg'
     */
    REL_Y.VbOUT_REL_RLDoorHndlBtnSig_flg_ =
      REL_U.VbINP_HWA_RLDoorHandleSW_flg_Vb;

    /* Outport: '<Root>/VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_RRDoorHandleSW_flg_VbINP_HWA_RRDoorHandleSW_flg'
     */
    REL_Y.VbOUT_REL_RRDoorHndlBtnSig_flg_ =
      REL_U.VbINP_HWA_RRDoorHandleSW_flg_Vb;
  }

  /* End of Chart: '<S3>/DoorSwSts' */

  /* Outport: '<Root>/VeOUT_REL_BcmPassDoorSwtSts_sig_VeOUT_REL_BcmPassDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  REL_Y.VeOUT_REL_BcmPassDoorSwtSts_sig = SL_b_FRDoorInBtnSts;

  /* Outport: '<Root>/VeOUT_REL_BcmLeReDoorSwtSts_sig_VeOUT_REL_BcmLeReDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  REL_Y.VeOUT_REL_BcmLeReDoorSwtSts_sig = SI_b_CrashSts_prev;

  /* Outport: '<Root>/VeOUT_REL_BcmRiReDoorSwtSts_sig_VeOUT_REL_BcmRiReDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  REL_Y.VeOUT_REL_BcmRiReDoorSwtSts_sig = SL_b_RRDoorInBtnSts;

  /* Outport: '<Root>/VeOUT_REL_BcmDrvrDoorSwtSts_sig_VeOUT_REL_BcmDrvrDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   */
  REL_Y.VeOUT_REL_BcmDrvrDoorSwtSts_sig = SL_b_FLDoorInBtnSts;

  /* Chart: '<S3>/DoorAutoRlsSts' incorporates:
   *  Inport: '<Root>/VeINP_CAN_CdcDrvrDoorLockSet_sig_VeINP_CAN_CdcDrvrDoorLockSet_sig'
   *  Inport: '<Root>/VeINP_EPRM_BdcDrvrDoorLockSetSts_sig_VeINP_EPRM_BdcDrvrDoorLockSetSts_sig'
   */
  if (REL_DW.is_active_c1_REL == 0U) {
    REL_DW.is_active_c1_REL = 1U;

    /*  DoorLockSet  */
    if ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si == 1) ||
        ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si != 2) &&
         (REL_DW.SL_e_DoorAutoRlsSetBackup == 1))) {
      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = true;

      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_j = true;
      REL_DW.SL_e_DoorAutoRlsSetBackup = 1U;
    } else if ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si == 2) ||
               ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si != 1) &&
                (REL_DW.SL_e_DoorAutoRlsSetBackup == 2))) {
      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = false;

      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_j = false;
      REL_DW.SL_e_DoorAutoRlsSetBackup = 2U;
    } else {
      switch (REL_U.VeINP_EPRM_BdcDrvrDoorLockSetSt) {
       case 1:
        /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
        REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = true;

        /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
        REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_j = true;
        break;

       case 0:
        /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
        REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = false;

        /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
        REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_j = false;
        break;
      }
    }
  } else if ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si == 1) ||
             ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si != 2) &&
              (REL_DW.SL_e_DoorAutoRlsSetBackup == 1))) {
    /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
    REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = true;

    /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
    REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_j = true;
    REL_DW.SL_e_DoorAutoRlsSetBackup = 1U;
  } else if ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si == 2) ||
             ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si != 1) &&
              (REL_DW.SL_e_DoorAutoRlsSetBackup == 2))) {
    /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
    REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = false;

    /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
    REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_j = false;
    REL_DW.SL_e_DoorAutoRlsSetBackup = 2U;
  } else {
    switch (REL_U.VeINP_EPRM_BdcDrvrDoorLockSetSt) {
     case 1:
      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = true;

      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_j = true;
      break;

     case 0:
      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = false;

      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_j = false;
      break;
    }
  }

  /* End of Chart: '<S3>/DoorAutoRlsSts' */

  /* Truth Table: '<S3>/FLDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V);

  /* Chart: '<S3>/FLDoorRlsReq' incorporates:
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig'
   */
  if (REL_DW.temporalCounter_i1_j < 63U) {
    REL_DW.temporalCounter_i1_j++;
  }

  if (REL_DW.temporalCounter_i2_c < 63U) {
    REL_DW.temporalCounter_i2_c++;
  }

  if (REL_DW.temporalCounter_i3_b < 255U) {
    REL_DW.temporalCounter_i3_b++;
  }

  if (REL_DW.temporalCounter_i4_h < 127U) {
    REL_DW.temporalCounter_i4_h++;
  }

  SI_b_DoorInBtnSts_prev_n = REL_DW.SI_b_DoorInBtnSts_start_d;
  REL_DW.SI_b_DoorInBtnSts_start_d = SL_b_FLDoorInBtnSts;
  SL_b_FLDoorInBtnSts = REL_DW.SL_b_DoorInBtnValid_start_p;
  REL_DW.SL_b_DoorInBtnValid_start_p = REL_DW.SL_b_DoorInBtnValid_g;
  SI_b_DoorHndBtnSts_prev_c = REL_DW.SI_b_DoorHndBtnSts_start_l;
  REL_DW.SI_b_DoorHndBtnSts_start_l = REL_Y.VbOUT_REL_FLDoorHndlBtnSig_flg_;
  SL_b_DoorHndBtnValid_prev_a = REL_DW.SL_b_DoorHndBtnValid_start_l;
  REL_DW.SL_b_DoorHndBtnValid_start_l = REL_DW.SL_b_DoorHndBtnValid_a;
  if (REL_DW.is_active_c5_DoorRlsReq_b == 0U) {
    REL_DW.is_active_c5_DoorRlsReq_b = 1U;
    REL_DW.is_SwValid_c = REL_IN_Idle_p;
    REL_DW.SL_b_DoorInBtnValid_g = false;
    REL_DW.is_RlsReq_k = REL_IN_Idle_p;
    REL_DW.is_RlsReq_p = REL_IN_Idle_p;
    REL_DW.is_SwValid_eo = REL_IN_Idle_p;
    REL_DW.SL_b_DoorHndBtnValid_a = false;
  } else {
    switch (REL_DW.is_SwValid_c) {
     case REL_IN_Idle_p:
      if ((SI_b_DoorInBtnSts_prev_n != REL_DW.SI_b_DoorInBtnSts_start_d) &&
          REL_DW.SI_b_DoorInBtnSts_start_d) {
        REL_DW.is_SwValid_c = REL_IN_Once_o;
        REL_DW.temporalCounter_i3_b = 0U;
      }
      break;

     case REL_IN_Once_o:
      if ((SI_b_DoorInBtnSts_prev_n != REL_DW.SI_b_DoorInBtnSts_start_d) &&
          REL_DW.SI_b_DoorInBtnSts_start_d) {
        REL_DW.is_SwValid_c = REL_IN_Twice_i;
        REL_DW.temporalCounter_i3_b = 0U;
        REL_DW.SL_b_DoorInBtnValid_g = true;
      } else if (REL_DW.temporalCounter_i3_b >= 200) {
        REL_DW.is_SwValid_c = REL_IN_Idle_p;
        REL_DW.SL_b_DoorInBtnValid_g = false;
      }
      break;

     default:
      /* case IN_Twice: */
      if (REL_DW.temporalCounter_i3_b >= 3) {
        REL_DW.is_SwValid_c = REL_IN_Idle_p;
        REL_DW.SL_b_DoorInBtnValid_g = false;
      }
      break;
    }

    if (REL_DW.is_RlsReq_k == REL_IN_Idle_p) {
      if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
            (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
           (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
          ((SL_b_FLDoorInBtnSts != REL_DW.SL_b_DoorInBtnValid_start_p) &&
           REL_DW.SL_b_DoorInBtnValid_start_p)) {
        REL_DW.is_RlsReq_k = REL_IN_Trigger_h;
        switch (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si) {
         case 0:
          REL_DW.is_Trigger_d = REL_IN_DoorLock_f;
          REL_DW.is_DoorLock_k = REL_IN_UnlockReq_k;
          REL_DW.temporalCounter_i1_j = 0U;
          REL_B.SO_b_UnlockReq_k = true;
          break;

         case 1:
          REL_DW.is_Trigger_d = REL_IN_DoorUnlock_g;
          break;

         default:
          REL_DW.is_Trigger_d = REL_IN_Error_a;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP != 1)) ||
               ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
                (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V == 3))) {
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
          if (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) {
            REL_DW.is_DoorLock_k = REL_IN_UnlockSucess_a;
          } else if ((REL_DW.temporalCounter_i1_j >= 50) &&
                     (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) {
            REL_DW.is_DoorLock_k = REL_IN_UnlockFail_i;
          } else {
            REL_B.SO_b_UnlockReq_k = ((REL_DW.temporalCounter_i1_j != 5) &&
              REL_B.SO_b_UnlockReq_k);
          }
          break;

         default:
          /* case IN_UnlockSucess: */
          if (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3) {
            REL_DW.is_DoorLock_k = 0;
            REL_DW.is_Trigger_d = REL_IN_Release_n;
            REL_DW.temporalCounter_i1_j = 0U;

            /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
            REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
            REL_B.SO_e_DoorRlsDelayTime_m = 20U;
          }
          break;
        }
        break;

       case REL_IN_DoorUnlock_g:
        if (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3) {
          REL_DW.is_Trigger_d = REL_IN_Release_n;
          REL_DW.temporalCounter_i1_j = 0U;

          /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
          REL_B.SO_e_DoorRlsDelayTime_m = 20U;
        }
        break;

       case REL_IN_Error_a:
        REL_DW.is_Trigger_d = 0;
        REL_DW.is_RlsReq_k = REL_IN_Idle_p;
        break;

       default:
        /* case IN_Release: */
        if (REL_DW.temporalCounter_i1_j >= 5) {
          /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
          REL_B.SO_e_DoorRlsDelayTime_m = 0U;
          REL_DW.is_Trigger_d = 0;
          REL_DW.is_RlsReq_k = REL_IN_Idle_p;
        }
        break;
      }
    }

    if (REL_DW.is_RlsReq_p == REL_IN_Idle_p) {
      if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
            (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
           (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
          ((SL_b_DoorHndBtnValid_prev_a != REL_DW.SL_b_DoorHndBtnValid_start_l) &&
           REL_DW.SL_b_DoorHndBtnValid_start_l)) {
        REL_DW.is_RlsReq_p = REL_IN_Trigger_h;
        switch (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si) {
         case 0:
          REL_DW.is_Trigger_h = REL_IN_DoorLock_f;
          REL_DW.is_DoorLock_a = REL_IN_UnlockReq_k;
          REL_DW.temporalCounter_i2_c = 0U;
          REL_B.SO_b_PEUnlockReq_g = true;
          break;

         case 1:
          REL_DW.is_Trigger_h = REL_IN_DoorUnlock_g;
          break;

         default:
          REL_DW.is_Trigger_h = REL_IN_Error_a;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP != 1)) ||
               ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
                (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V == 3))) {
      REL_DW.is_DoorLock_a = 0;
      REL_DW.is_Trigger_h = 0;
      REL_DW.is_RlsReq_p = REL_IN_Idle_p;
    } else {
      switch (REL_DW.is_Trigger_h) {
       case REL_IN_DoorLock_f:
        switch (REL_DW.is_DoorLock_a) {
         case REL_IN_UnlockFail_i:
          REL_DW.is_DoorLock_a = 0;
          REL_DW.is_Trigger_h = 0;
          REL_DW.is_RlsReq_p = REL_IN_Idle_p;
          break;

         case REL_IN_UnlockReq_k:
          if (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) {
            REL_DW.is_DoorLock_a = REL_IN_UnlockSucess_a;
          } else if ((REL_DW.temporalCounter_i2_c >= 50) &&
                     (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) {
            REL_DW.is_DoorLock_a = REL_IN_UnlockFail_i;
          } else {
            REL_B.SO_b_PEUnlockReq_g = ((REL_DW.temporalCounter_i2_c != 5) &&
              REL_B.SO_b_PEUnlockReq_g);
          }
          break;

         default:
          /* case IN_UnlockSucess: */
          if (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3) {
            REL_DW.is_DoorLock_a = 0;
            REL_DW.is_Trigger_h = REL_IN_Release_n;
            REL_DW.temporalCounter_i2_c = 0U;

            /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
            REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
          }
          break;
        }
        break;

       case REL_IN_DoorUnlock_g:
        if (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3) {
          REL_DW.is_Trigger_h = REL_IN_Release_n;
          REL_DW.temporalCounter_i2_c = 0U;

          /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
        }
        break;

       case REL_IN_Error_a:
        break;

       default:
        /* case IN_Release: */
        if (REL_DW.temporalCounter_i2_c >= 5) {
          /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
          REL_DW.is_Trigger_h = 0;
          REL_DW.is_RlsReq_p = REL_IN_Idle_p;
        }
        break;
      }
    }

    switch (REL_DW.is_SwValid_eo) {
     case REL_IN_Idle_p:
      if ((SI_b_DoorHndBtnSts_prev_c != REL_DW.SI_b_DoorHndBtnSts_start_l) &&
          REL_DW.SI_b_DoorHndBtnSts_start_l) {
        REL_DW.is_SwValid_eo = REL_IN_Press_f;
        REL_DW.temporalCounter_i4_h = 0U;
      }
      break;

     case REL_IN_Press_f:
      if ((SI_b_DoorHndBtnSts_prev_c != REL_DW.SI_b_DoorHndBtnSts_start_l) &&
          (!REL_DW.SI_b_DoorHndBtnSts_start_l)) {
        REL_DW.is_SwValid_eo = REL_IN_Release_ni;
        REL_DW.temporalCounter_i4_h = 0U;
        REL_DW.SL_b_DoorHndBtnValid_a = true;
      } else if (REL_DW.temporalCounter_i4_h >= 100) {
        REL_DW.is_SwValid_eo = REL_IN_Idle_p;
        REL_DW.SL_b_DoorHndBtnValid_a = false;
      }
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i4_h >= 3) {
        REL_DW.is_SwValid_eo = REL_IN_Idle_p;
        REL_DW.SL_b_DoorHndBtnValid_a = false;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/FLDoorRlsReq' */

  /* Chart: '<S3>/FLDoorRlsDriver' incorporates:
   *  Inport: '<Root>/VbINP_CAN_FLDCUCinchHomeSwitch_flg_VbINP_CAN_FLDCUCinchHomeSwitch_flg'
   *  Inport: '<Root>/VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg'
   *  Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig'
   */
  REL_FLDoorRlsDriver(REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU,
                      REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_,
                      REL_U.VbINP_CAN_FLDCUCinchHomeSwitch_,
                      REL_U.VbINP_CFG_ElectricalDoorCfg_flg,
                      REL_B.SO_e_DoorRlsDelayTime_m,
                      &REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU,
                      &REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU,
                      &REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve,
                      &SI_b_DoorInBtnSts_prev_n, &SO_e_MotorPwm_o,
                      &REL_DW.sf_FLDoorRlsDriver);

  /* Truth Table: '<S3>/FRDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_FRDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V);

  /* Chart: '<S3>/FRDoorRlsReq' incorporates:
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig'
   */
  if (REL_DW.temporalCounter_i1_a < 63U) {
    REL_DW.temporalCounter_i1_a++;
  }

  if (REL_DW.temporalCounter_i2 < 63U) {
    REL_DW.temporalCounter_i2++;
  }

  if (REL_DW.temporalCounter_i3 < 255U) {
    REL_DW.temporalCounter_i3++;
  }

  if (REL_DW.temporalCounter_i4 < 127U) {
    REL_DW.temporalCounter_i4++;
  }

  SI_b_DoorInBtnSts_prev_n = REL_DW.SI_b_DoorInBtnSts_start;
  REL_DW.SI_b_DoorInBtnSts_start = SL_b_FRDoorInBtnSts;
  SL_b_FRDoorInBtnSts = REL_DW.SL_b_DoorInBtnValid_start;
  REL_DW.SL_b_DoorInBtnValid_start = REL_DW.SL_b_DoorInBtnValid;
  SL_b_FLDoorInBtnSts = REL_DW.SI_b_DoorHndBtnSts_start;
  REL_DW.SI_b_DoorHndBtnSts_start = REL_Y.VbOUT_REL_FRDoorHndlBtnSig_flg_;
  SI_b_DoorHndBtnSts_prev_c = REL_DW.SL_b_DoorHndBtnValid_start;
  REL_DW.SL_b_DoorHndBtnValid_start = REL_DW.SL_b_DoorHndBtnValid;
  if (REL_DW.is_active_c5_DoorRlsReq == 0U) {
    REL_DW.is_active_c5_DoorRlsReq = 1U;
    REL_DW.is_SwValid = REL_IN_Idle_p;
    REL_DW.SL_b_DoorInBtnValid = false;
    REL_DW.is_RlsReq = REL_IN_Idle_p;
    REL_DW.is_RlsReq_d = REL_IN_Idle_p;
    REL_DW.is_SwValid_e = REL_IN_Idle_p;
    REL_DW.SL_b_DoorHndBtnValid = false;
  } else {
    switch (REL_DW.is_SwValid) {
     case REL_IN_Idle_p:
      if ((SI_b_DoorInBtnSts_prev_n != REL_DW.SI_b_DoorInBtnSts_start) &&
          REL_DW.SI_b_DoorInBtnSts_start) {
        REL_DW.is_SwValid = REL_IN_Once_o;
        REL_DW.temporalCounter_i3 = 0U;
      }
      break;

     case REL_IN_Once_o:
      if ((SI_b_DoorInBtnSts_prev_n != REL_DW.SI_b_DoorInBtnSts_start) &&
          REL_DW.SI_b_DoorInBtnSts_start) {
        REL_DW.is_SwValid = REL_IN_Twice_i;
        REL_DW.temporalCounter_i3 = 0U;
        REL_DW.SL_b_DoorInBtnValid = true;
      } else if (REL_DW.temporalCounter_i3 >= 200) {
        REL_DW.is_SwValid = REL_IN_Idle_p;
        REL_DW.SL_b_DoorInBtnValid = false;
      }
      break;

     default:
      /* case IN_Twice: */
      if (REL_DW.temporalCounter_i3 >= 3) {
        REL_DW.is_SwValid = REL_IN_Idle_p;
        REL_DW.SL_b_DoorInBtnValid = false;
      }
      break;
    }

    if (REL_DW.is_RlsReq == REL_IN_Idle_p) {
      if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
            (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
           (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
          ((SL_b_FRDoorInBtnSts != REL_DW.SL_b_DoorInBtnValid_start) &&
           REL_DW.SL_b_DoorInBtnValid_start)) {
        REL_DW.is_RlsReq = REL_IN_Trigger_h;
        switch (REL_U.VeOUT_DLK_BCMPassengerDoorLockS) {
         case 0:
          REL_DW.is_Trigger = REL_IN_DoorLock_f;
          REL_DW.is_DoorLock = REL_IN_UnlockReq_k;
          REL_DW.temporalCounter_i1_a = 0U;
          REL_B.SO_b_UnlockReq_c = true;
          break;

         case 1:
          REL_DW.is_Trigger = REL_IN_DoorUnlock_g;
          break;

         default:
          REL_DW.is_Trigger = REL_IN_Error_a;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP != 1)) ||
               ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
                (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V == 3))) {
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
          if (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) {
            REL_DW.is_DoorLock = REL_IN_UnlockSucess_a;
          } else if ((REL_DW.temporalCounter_i1_a >= 50) &&
                     (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0)) {
            REL_DW.is_DoorLock = REL_IN_UnlockFail_i;
          } else {
            REL_B.SO_b_UnlockReq_c = ((REL_DW.temporalCounter_i1_a != 5) &&
              REL_B.SO_b_UnlockReq_c);
          }
          break;

         default:
          /* case IN_UnlockSucess: */
          if (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3) {
            REL_DW.is_DoorLock = 0;
            REL_DW.is_Trigger = REL_IN_Release_n;
            REL_DW.temporalCounter_i1_a = 0U;

            /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
            REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
            REL_B.SO_e_DoorRlsDelayTime_k = 20U;
          }
          break;
        }
        break;

       case REL_IN_DoorUnlock_g:
        if (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3) {
          REL_DW.is_Trigger = REL_IN_Release_n;
          REL_DW.temporalCounter_i1_a = 0U;

          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
          REL_B.SO_e_DoorRlsDelayTime_k = 20U;
        }
        break;

       case REL_IN_Error_a:
        REL_DW.is_Trigger = 0;
        REL_DW.is_RlsReq = REL_IN_Idle_p;
        break;

       default:
        /* case IN_Release: */
        if (REL_DW.temporalCounter_i1_a >= 5) {
          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
          REL_B.SO_e_DoorRlsDelayTime_k = 0U;
          REL_DW.is_Trigger = 0;
          REL_DW.is_RlsReq = REL_IN_Idle_p;
        }
        break;
      }
    }

    if (REL_DW.is_RlsReq_d == REL_IN_Idle_p) {
      if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
            (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
           (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
          ((SI_b_DoorHndBtnSts_prev_c != REL_DW.SL_b_DoorHndBtnValid_start) &&
           REL_DW.SL_b_DoorHndBtnValid_start)) {
        REL_DW.is_RlsReq_d = REL_IN_Trigger_h;
        switch (REL_U.VeOUT_DLK_BCMPassengerDoorLockS) {
         case 0:
          REL_DW.is_Trigger_a = REL_IN_DoorLock_f;
          REL_DW.is_DoorLock_m = REL_IN_UnlockReq_k;
          REL_DW.temporalCounter_i2 = 0U;
          REL_B.SO_b_PEUnlockReq_e = true;
          break;

         case 1:
          REL_DW.is_Trigger_a = REL_IN_DoorUnlock_g;
          break;

         default:
          REL_DW.is_Trigger_a = REL_IN_Error_a;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP != 1)) ||
               ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
                (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V == 3))) {
      REL_DW.is_DoorLock_m = 0;
      REL_DW.is_Trigger_a = 0;
      REL_DW.is_RlsReq_d = REL_IN_Idle_p;
    } else {
      switch (REL_DW.is_Trigger_a) {
       case REL_IN_DoorLock_f:
        switch (REL_DW.is_DoorLock_m) {
         case REL_IN_UnlockFail_i:
          REL_DW.is_DoorLock_m = 0;
          REL_DW.is_Trigger_a = 0;
          REL_DW.is_RlsReq_d = REL_IN_Idle_p;
          break;

         case REL_IN_UnlockReq_k:
          if (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) {
            REL_DW.is_DoorLock_m = REL_IN_UnlockSucess_a;
          } else if ((REL_DW.temporalCounter_i2 >= 50) &&
                     (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0)) {
            REL_DW.is_DoorLock_m = REL_IN_UnlockFail_i;
          } else {
            REL_B.SO_b_PEUnlockReq_e = ((REL_DW.temporalCounter_i2 != 5) &&
              REL_B.SO_b_PEUnlockReq_e);
          }
          break;

         default:
          /* case IN_UnlockSucess: */
          if (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3) {
            REL_DW.is_DoorLock_m = 0;
            REL_DW.is_Trigger_a = REL_IN_Release_n;
            REL_DW.temporalCounter_i2 = 0U;

            /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
            REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
          }
          break;
        }
        break;

       case REL_IN_DoorUnlock_g:
        if (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3) {
          REL_DW.is_Trigger_a = REL_IN_Release_n;
          REL_DW.temporalCounter_i2 = 0U;

          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
        }
        break;

       case REL_IN_Error_a:
        break;

       default:
        /* case IN_Release: */
        if (REL_DW.temporalCounter_i2 >= 5) {
          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
          REL_DW.is_Trigger_a = 0;
          REL_DW.is_RlsReq_d = REL_IN_Idle_p;
        }
        break;
      }
    }

    switch (REL_DW.is_SwValid_e) {
     case REL_IN_Idle_p:
      if ((SL_b_FLDoorInBtnSts != REL_DW.SI_b_DoorHndBtnSts_start) &&
          REL_DW.SI_b_DoorHndBtnSts_start) {
        REL_DW.is_SwValid_e = REL_IN_Press_f;
        REL_DW.temporalCounter_i4 = 0U;
      }
      break;

     case REL_IN_Press_f:
      if ((SL_b_FLDoorInBtnSts != REL_DW.SI_b_DoorHndBtnSts_start) &&
          (!REL_DW.SI_b_DoorHndBtnSts_start)) {
        REL_DW.is_SwValid_e = REL_IN_Release_ni;
        REL_DW.temporalCounter_i4 = 0U;
        REL_DW.SL_b_DoorHndBtnValid = true;
      } else if (REL_DW.temporalCounter_i4 >= 100) {
        REL_DW.is_SwValid_e = REL_IN_Idle_p;
        REL_DW.SL_b_DoorHndBtnValid = false;
      }
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i4 >= 3) {
        REL_DW.is_SwValid_e = REL_IN_Idle_p;
        REL_DW.SL_b_DoorHndBtnValid = false;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/FRDoorRlsReq' */

  /* Chart: '<S3>/FRDoorRlsDriver' incorporates:
   *  Inport: '<Root>/VbINP_CAN_FRDCUCinchHomeSwitch_flg_VbINP_CAN_FRDCUCinchHomeSwitch_flg'
   *  Inport: '<Root>/VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg'
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   *  Outport: '<Root>/VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg'
   *  Outport: '<Root>/VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg'
   *  Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig'
   */
  REL_FLDoorRlsDriver(REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU,
                      REL_U.VbINP_HWA_FRDoorAjar_flg_VbINP_,
                      REL_U.VbINP_CAN_FRDCUCinchHomeSwitch_,
                      REL_U.VbINP_CFG_ElectricalDoorCfg_flg,
                      REL_B.SO_e_DoorRlsDelayTime_k,
                      &REL_Y.VbOUT_REL_FRDoorMotorA_flg_VbOU,
                      &REL_Y.VbOUT_REL_FRDoorMotorB_flg_VbOU,
                      &REL_Y.VeOUT_REL_FRDoorMotorSts_sig_Ve,
                      &SL_b_FRDoorInBtnSts, &SO_e_MotorPwm_o,
                      &REL_DW.sf_FRDoorRlsDriver);

  /* Truth Table: '<S3>/RLDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLRDoorRatSts_sig_VeOUT_REL_BdcLRDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_RLDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcLRDoorRatSts_sig_V);

  /* Chart: '<S3>/RLDoorRlsReq' incorporates:
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbINP_HWA_LRChildLckSt_flg_VbINP_HWA_LRChildLckSt_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLRDoorRatSts_sig_VeOUT_REL_BdcLRDoorRatSts_sig'
   */
  REL_RLDoorRlsReq(REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                   REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN,
                   REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP,
                   REL_U.VeOUT_DLK_BCMPassengerDoorLockS,
                   REL_Y.VeOUT_REL_BdcLRDoorRatSts_sig_V, SI_b_CrashSts_prev,
                   REL_Y.VbOUT_REL_RLDoorHndlBtnSig_flg_,
                   REL_U.VbINP_HWA_LRChildLckSt_flg_VbIN,
                   &REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU,
                   &REL_B.SO_e_DoorRlsDelayTime_e, &REL_B.SO_b_UnlockReq_m,
                   &REL_B.SO_b_PEUnlockReq_i, &REL_DW.sf_RLDoorRlsReq);

  /* Truth Table: '<S3>/RRDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcRRDoorRatSts_sig_VeOUT_REL_BdcRRDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_RRDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcRRDoorRatSts_sig_V);

  /* Chart: '<S3>/RRDoorRlsReq' incorporates:
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbINP_HWA_RRChildLckSt_flg_VbINP_HWA_RRChildLckSt_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcRRDoorRatSts_sig_VeOUT_REL_BdcRRDoorRatSts_sig'
   */
  REL_RLDoorRlsReq(REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                   REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN,
                   REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP,
                   REL_U.VeOUT_DLK_BCMPassengerDoorLockS,
                   REL_Y.VeOUT_REL_BdcRRDoorRatSts_sig_V, SL_b_RRDoorInBtnSts,
                   REL_Y.VbOUT_REL_RRDoorHndlBtnSig_flg_,
                   REL_U.VbINP_HWA_RRChildLckSt_flg_VbIN,
                   &REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU,
                   &REL_B.SO_e_DoorRlsDelayTime, &REL_B.SO_b_UnlockReq,
                   &REL_B.SO_b_PEUnlockReq, &REL_DW.sf_RRDoorRlsReq);

  /* Logic: '<S3>/Logical Operator' */
  SI_b_CrashSts_prev = (REL_B.SO_b_UnlockReq_c || REL_B.SO_b_UnlockReq_m ||
                        REL_B.SO_b_UnlockReq);

  /* Logic: '<S3>/Logical Operator1' */
  SL_b_RRDoorInBtnSts = (REL_B.SO_b_PEUnlockReq_g || REL_B.SO_b_PEUnlockReq_e ||
    REL_B.SO_b_PEUnlockReq_i || REL_B.SO_b_PEUnlockReq);

  /* Chart: '<S3>/RLDoorRlsDriver' incorporates:
   *  Inport: '<Root>/VbINP_CAN_RLDCUCinchHomeSwitch_flg_VbINP_CAN_RLDCUCinchHomeSwitch_flg'
   *  Inport: '<Root>/VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg'
   *  Inport: '<Root>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig'
   */
  REL_FLDoorRlsDriver(REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU,
                      REL_U.VbINP_HWA_RLDoorAjar_flg_VbINP_,
                      REL_U.VbINP_CAN_RLDCUCinchHomeSwitch_,
                      REL_U.VbINP_CFG_ElectricalDoorCfg_flg,
                      REL_B.SO_e_DoorRlsDelayTime_e,
                      &REL_Y.VbOUT_REL_RLDoorMotorA_flg_VbOU,
                      &REL_Y.VbOUT_REL_RLDoorMotorB_flg_VbOU,
                      &REL_Y.VeOUT_REL_RLDoorMotorSts_sig_Ve,
                      &SL_b_FRDoorInBtnSts, &SO_e_MotorPwm_o,
                      &REL_DW.sf_RLDoorRlsDriver);

  /* Chart: '<S3>/RRDoorRlsDriver' incorporates:
   *  Inport: '<Root>/VbINP_CAN_RRDCUCinchHomeSwitch_flg_VbINP_CAN_RRDCUCinchHomeSwitch_flg'
   *  Inport: '<Root>/VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg'
   *  Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_RRDoorMotorSts_sig_VeOUT_REL_RRDoorMotorSts_sig'
   */
  REL_FLDoorRlsDriver(REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU,
                      REL_U.VbINP_HWA_RRDoorAjar_flg_VbINP_,
                      REL_U.VbINP_CAN_RRDCUCinchHomeSwitch_,
                      REL_U.VbINP_CFG_ElectricalDoorCfg_flg,
                      REL_B.SO_e_DoorRlsDelayTime,
                      &REL_Y.VbOUT_REL_RRDoorMotorA_flg_VbOU,
                      &REL_Y.VbOUT_REL_RRDoorMotorB_flg_VbOU,
                      &REL_Y.VeOUT_REL_RRDoorMotorSts_sig_Ve,
                      &SL_b_FRDoorInBtnSts, &SO_e_MotorPwm_o,
                      &REL_DW.sf_RRDoorRlsDriver);

  /* Chart: '<S3>/Unlock_Request' */
  if (REL_DW.is_active_c6_REL == 0U) {
    REL_DW.is_active_c6_REL = 1U;
    if ((REL_B.SO_b_UnlockReq_k && SI_b_CrashSts_prev) || SL_b_RRDoorInBtnSts) {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 3U;

      /*   */
    } else if ((!REL_B.SO_b_UnlockReq_k) && SI_b_CrashSts_prev) {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 2U;
    } else {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      /*   */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = (UInt8)(REL_B.SO_b_UnlockReq_k &&
        (!SI_b_CrashSts_prev));
    }
  } else if ((REL_B.SO_b_UnlockReq_k && SI_b_CrashSts_prev) ||
             SL_b_RRDoorInBtnSts) {
    /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
    REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 3U;

    /*   */
  } else if ((!REL_B.SO_b_UnlockReq_k) && SI_b_CrashSts_prev) {
    /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
    REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 2U;
  } else {
    /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
    /*   */
    REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = (UInt8)(REL_B.SO_b_UnlockReq_k &&
      (!SI_b_CrashSts_prev));
  }

  /* End of Chart: '<S3>/Unlock_Request' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */
}

/* Model initialize function */
void REL_initialize(void)
{
  {
    uint8_T SO_e_MotorPwm_o;
    boolean_T SO_b_Error_c;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
     *  SubSystem: '<Root>/REL_Step_sys'
     */

    /* SystemInitialize for Chart: '<S3>/FLDoorRlsDriver' incorporates:
     *  Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg'
     *  Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg'
     *  Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig'
     */
    REL_FLDoorRlsDriver_Init(&REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU,
      &REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU,
      &REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve, &SO_b_Error_c, &SO_e_MotorPwm_o);

    /* SystemInitialize for Chart: '<S3>/FRDoorRlsDriver' incorporates:
     *  Outport: '<Root>/VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg'
     *  Outport: '<Root>/VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg'
     *  Outport: '<Root>/VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig'
     */
    REL_FLDoorRlsDriver_Init(&REL_Y.VbOUT_REL_FRDoorMotorA_flg_VbOU,
      &REL_Y.VbOUT_REL_FRDoorMotorB_flg_VbOU,
      &REL_Y.VeOUT_REL_FRDoorMotorSts_sig_Ve, &SO_b_Error_c, &SO_e_MotorPwm_o);

    /* SystemInitialize for Chart: '<S3>/RLDoorRlsDriver' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg'
     *  Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg'
     *  Outport: '<Root>/VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig'
     */
    REL_FLDoorRlsDriver_Init(&REL_Y.VbOUT_REL_RLDoorMotorA_flg_VbOU,
      &REL_Y.VbOUT_REL_RLDoorMotorB_flg_VbOU,
      &REL_Y.VeOUT_REL_RLDoorMotorSts_sig_Ve, &SO_b_Error_c, &SO_e_MotorPwm_o);

    /* SystemInitialize for Chart: '<S3>/RLDoorRlsReq' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg'
     */
    REL_RLDoorRlsReq_Init(&REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU,
                          &REL_B.SO_e_DoorRlsDelayTime_e,
                          &REL_B.SO_b_UnlockReq_m, &REL_B.SO_b_PEUnlockReq_i);

    /* SystemInitialize for Chart: '<S3>/RRDoorRlsDriver' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg'
     *  Outport: '<Root>/VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg'
     *  Outport: '<Root>/VeOUT_REL_RRDoorMotorSts_sig_VeOUT_REL_RRDoorMotorSts_sig'
     */
    REL_FLDoorRlsDriver_Init(&REL_Y.VbOUT_REL_RRDoorMotorA_flg_VbOU,
      &REL_Y.VbOUT_REL_RRDoorMotorB_flg_VbOU,
      &REL_Y.VeOUT_REL_RRDoorMotorSts_sig_Ve, &SO_b_Error_c, &SO_e_MotorPwm_o);

    /* SystemInitialize for Chart: '<S3>/RRDoorRlsReq' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg'
     */
    REL_RLDoorRlsReq_Init(&REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU,
                          &REL_B.SO_e_DoorRlsDelayTime, &REL_B.SO_b_UnlockReq,
                          &REL_B.SO_b_PEUnlockReq);

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */
  }
}

/* Model terminate function */
void REL_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
