/*
 * File: REL.c
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.95
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Sep 14 11:01:08 2023
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
#define REL_IN_Idle                    ((uint8_T)1U)
#define REL_IN_Initial                 ((uint8_T)3U)
#define REL_IN_LastCheck               ((uint8_T)2U)
#define REL_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define REL_IN_Normal                  ((uint8_T)1U)
#define REL_IN_PowerOn                 ((uint8_T)2U)
#define REL_IN_Release                 ((uint8_T)2U)
#define REL_IN_Reset                   ((uint8_T)4U)
#define REL_IN_Step2_Open              ((uint8_T)5U)

/* Named constants for Chart: '<S3>/RLDoorRlsReq' */
#define REL_IN_DoorLock                ((uint8_T)1U)
#define REL_IN_DoorUnlock              ((uint8_T)2U)
#define REL_IN_DoorUnlock_e            ((uint8_T)1U)
#define REL_IN_Error                   ((uint8_T)3U)
#define REL_IN_Idle_a                  ((uint8_T)1U)
#define REL_IN_NO_ACTIVE_CHILD_a       ((uint8_T)0U)
#define REL_IN_Once                    ((uint8_T)2U)
#define REL_IN_Press                   ((uint8_T)2U)
#define REL_IN_RELEASE                 ((uint8_T)4U)
#define REL_IN_Release_l               ((uint8_T)4U)
#define REL_IN_Release_lv              ((uint8_T)2U)
#define REL_IN_Release_lvk             ((uint8_T)3U)
#define REL_IN_Trigger                 ((uint8_T)2U)
#define REL_IN_Twice                   ((uint8_T)3U)

/* Named constants for Chart: '<S3>/DoorSwSts' */
#define REL_IN_Crash                   ((uint8_T)1U)
#define REL_IN_NoCrash                 ((uint8_T)2U)

/* Named constants for Chart: '<S3>/FLDoorRlsReq' */
#define REL_IN_DoorLock_b              ((uint8_T)1U)
#define REL_IN_DoorUnlock_h            ((uint8_T)2U)
#define REL_IN_DoorUnlock_hd           ((uint8_T)1U)
#define REL_IN_Error_f                 ((uint8_T)3U)
#define REL_IN_Idle_n                  ((uint8_T)1U)
#define REL_IN_Once_a                  ((uint8_T)2U)
#define REL_IN_Press_f                 ((uint8_T)2U)
#define REL_IN_RELEASE_j               ((uint8_T)4U)
#define REL_IN_Release_h               ((uint8_T)4U)
#define REL_IN_Release_ht              ((uint8_T)2U)
#define REL_IN_Release_htd             ((uint8_T)3U)
#define REL_IN_Trigger_h               ((uint8_T)2U)
#define REL_IN_Twice_m                 ((uint8_T)3U)

/* Named constants for Chart: '<S3>/Unlock_Request' */
#define REL_IN_Initial_d               ((uint8_T)1U)
#define REL_IN_REQ_SENT                ((uint8_T)2U)

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
static void REL_DoorInBtn(UInt8 rtu_SI_e_EspVehSpd, Boolean
  rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8 rtu_SI_e_DoorLockSts,
  uint8_T rtu_SI_e_DoorRatSts, Boolean rtu_SI_b_ChildLckSts, boolean_T
  *rty_SO_b_DoorRlsReq, boolean_T *rty_SO_b_UnlockReq, uint8_T
  *rty_SO_e_DoorRlsDelayTime, DW_RLDoorRlsReq_REL_T *localDW);
static void REL_DoorHndBtn(UInt8 rtu_SI_e_EspVehSpd, Boolean
  rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8 rtu_SI_e_DoorLockSts,
  uint8_T rtu_SI_e_DoorRatSts, boolean_T *rty_SO_b_DoorRlsReq, boolean_T
  *rty_SO_b_UnlockReq, uint8_T *rty_SO_e_DoorRlsDelayTime, DW_RLDoorRlsReq_REL_T
  *localDW);

/* Forward declaration for local functions */
static void REL_enter_atomic_NoCrash(boolean_T *SL_b_FRDoorInBtnSts, boolean_T
  *SL_b_RLDoorInBtnSts, boolean_T *SL_b_RRDoorInBtnSts, boolean_T
  *SL_b_FLDoorInBtnSts);
static void REL_DoorInBtn_i(const boolean_T *SI_b_DoorInBtnSts_prev_a, const
  boolean_T *SL_b_DoorInBtnValid_prev_h);
static void REL_DoorHndBtn_l(const boolean_T *SI_b_DoorHndBtnSts_prev_p, const
  boolean_T *SL_b_DoorHndBtnValid_prev_n);
static void REL_DoorInBtn_i5(const boolean_T *SI_b_DoorInBtnSts_prev, const
  boolean_T *SL_b_DoorInBtnValid_prev);
static void REL_DoorHndBtn_n(const boolean_T *SI_b_DoorHndBtnSts_prev, const
  boolean_T *SL_b_DoorHndBtnValid_prev);

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

/*
 * System initialize for atomic system:
 *    '<S3>/FLDoorRlsDriver'
 *    '<S3>/FRDoorRlsDriver'
 *    '<S3>/RLDoorRlsDriver'
 *    '<S3>/RRDoorRlsDriver'
 */
void REL_FLDoorRlsDriver_Init(boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorMode, boolean_T *rty_SO_b_Error,
  uint8_T *rty_SO_e_MotorPwm)
{
  *rty_SO_b_MotorA = false;
  *rty_SO_b_MotorB = false;
  *rty_SO_e_MotorMode = 0U;
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
  rtu_SI_b_DoorAjar, uint8_T rtu_SI_e_DoorRlsDelayTime, boolean_T
  *rty_SO_b_MotorA, boolean_T *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorMode,
  uint8_T *rty_SO_e_MotorPwm, DW_FLDoorRlsDriver_REL_T *localDW)
{
  if (localDW->temporalCounter_i1 < 511U) {
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
    *rty_SO_e_MotorMode = 2U;
    *rty_SO_e_MotorPwm = 100U;
  } else if (localDW->is_c19_DoorRlsDriver == REL_IN_Normal) {
    if (localDW->is_MainProgress == REL_IN_Idle) {
      if ((localDW->SO_b_DoorRlsReq_prev != localDW->SO_b_DoorRlsReq_start) &&
          localDW->SO_b_DoorRlsReq_start) {
        localDW->is_MainProgress = REL_IN_Release;
        localDW->SL_e_CheckCycle = 0U;
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
            *rty_SO_e_MotorMode = 0U;
          } else {
            Boolean tmp_0;
            tmp_0 = !rtu_SI_b_DoorAjar;
            if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                (localDW->SL_e_CheckCycle < 2)) {
              *rty_SO_e_MotorPwm = 80U;
              localDW->is_Release = REL_IN_Initial;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_b_MotorA = true;
              *rty_SO_b_MotorB = false;
              *rty_SO_e_MotorMode = 1U;
            } else if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                       (localDW->SL_e_CheckCycle >= 2)) {
              localDW->is_Release = REL_IN_Reset;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_b_MotorA = false;
              *rty_SO_b_MotorB = true;
              *rty_SO_e_MotorMode = 2U;
              *rty_SO_e_MotorPwm = 70U;
            }
          }
        }
        break;

       case REL_IN_Delay:
        if (localDW->temporalCounter_i1 >= rtu_SI_e_DoorRlsDelayTime) {
          localDW->is_Release = REL_IN_Initial;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = true;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorMode = 1U;
        }
        break;

       case REL_IN_Initial:
        {
          if (localDW->temporalCounter_i1 >= 30) {
            int32_T tmp;
            localDW->is_Release = REL_IN_Checking;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = false;
            *rty_SO_e_MotorMode = 0U;
            tmp = localDW->SL_e_CheckCycle + 1;
            if (localDW->SL_e_CheckCycle + 1 > 255) {
              tmp = 255;
            }

            localDW->SL_e_CheckCycle = (uint8_T)tmp;
          }
        }
        break;

       case REL_IN_Reset:
        if (localDW->temporalCounter_i1 >= 30) {
          localDW->is_Release = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_MainProgress = REL_IN_Idle;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorMode = 0U;
          *rty_SO_e_MotorPwm = 0U;
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
            *rty_SO_e_MotorMode = 2U;
            *rty_SO_e_MotorPwm = 70U;
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
          *rty_SO_e_MotorMode = 2U;
          *rty_SO_e_MotorPwm = 70U;
        }
        break;
      }
    }

    /* case IN_PowerOn: */
  } else if (localDW->temporalCounter_i1 >= 30) {
    localDW->is_c19_DoorRlsDriver = REL_IN_Normal;
    localDW->is_MainProgress = REL_IN_Idle;
    *rty_SO_b_MotorA = false;
    *rty_SO_b_MotorB = false;
    *rty_SO_e_MotorMode = 0U;
    *rty_SO_e_MotorPwm = 0U;
  }

  /* End of Chart: '<S3>/FLDoorRlsDriver' */
}

/* Function for Chart: '<S3>/RLDoorRlsReq' */
static void REL_DoorInBtn(UInt8 rtu_SI_e_EspVehSpd, Boolean
  rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8 rtu_SI_e_DoorLockSts,
  uint8_T rtu_SI_e_DoorRatSts, Boolean rtu_SI_b_ChildLckSts, boolean_T
  *rty_SO_b_DoorRlsReq, boolean_T *rty_SO_b_UnlockReq, uint8_T
  *rty_SO_e_DoorRlsDelayTime, DW_RLDoorRlsReq_REL_T *localDW)
{
  switch (localDW->is_SwValid) {
   case REL_IN_Idle_a:
    if ((localDW->SI_b_DoorInBtnSts_prev != localDW->SI_b_DoorInBtnSts_start) &&
        localDW->SI_b_DoorInBtnSts_start && (!rtu_SI_b_ChildLckSts)) {
      localDW->is_SwValid = REL_IN_Once;
      localDW->temporalCounter_i1 = 0U;
    }
    break;

   case REL_IN_Once:
    if ((localDW->SI_b_DoorInBtnSts_prev != localDW->SI_b_DoorInBtnSts_start) &&
        localDW->SI_b_DoorInBtnSts_start && (!rtu_SI_b_ChildLckSts)) {
      localDW->is_SwValid = REL_IN_Twice;
      localDW->temporalCounter_i1 = 0U;
      localDW->SL_b_DoorInBtnValid = true;
    } else if ((localDW->temporalCounter_i1 >= 200) || rtu_SI_b_ChildLckSts) {
      localDW->is_SwValid = REL_IN_Idle_a;
      localDW->SL_b_DoorInBtnValid = false;
    }
    break;

   default:
    /* case IN_Twice: */
    if (localDW->temporalCounter_i1 >= 3) {
      localDW->is_SwValid = REL_IN_Idle_a;
      localDW->SL_b_DoorInBtnValid = false;
    }
    break;
  }

  if (localDW->is_RlsReq == REL_IN_Idle_a) {
    if ((((rtu_SI_e_EspVehSpd <= 0) && (!rtu_SI_b_EspVehSpdVld)) ||
         (rtu_SI_e_VcuGearPosn == 1)) && ((localDW->SL_b_DoorInBtnValid_prev !=
          localDW->SL_b_DoorInBtnValid_start) &&
         localDW->SL_b_DoorInBtnValid_start)) {
      localDW->is_RlsReq = REL_IN_Trigger;
      switch (rtu_SI_e_DoorLockSts) {
       case 0:
        localDW->is_Trigger = REL_IN_DoorLock;
        localDW->temporalCounter_i2 = 0U;
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
              (rtu_SI_e_VcuGearPosn != 1)) || ((rtu_SI_e_DoorLockSts == 1) &&
              (rtu_SI_e_DoorRatSts == 3))) {
    localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_a;
    localDW->is_RlsReq = REL_IN_Idle_a;
    *rty_SO_b_DoorRlsReq = false;
    *rty_SO_b_UnlockReq = false;
  } else {
    switch (localDW->is_Trigger) {
     case REL_IN_DoorLock:
      if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
        localDW->is_Trigger = REL_IN_Release_l;
        localDW->temporalCounter_i2 = 0U;
        *rty_SO_b_DoorRlsReq = true;
        *rty_SO_e_DoorRlsDelayTime = 20U;
      } else if (localDW->temporalCounter_i2 >= 100) {
        localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_a;
        localDW->is_RlsReq = REL_IN_Idle_a;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
      }
      break;

     case REL_IN_DoorUnlock:
      if (rtu_SI_e_DoorRatSts != 3) {
        localDW->is_Trigger = REL_IN_Release_l;
        localDW->temporalCounter_i2 = 0U;
        *rty_SO_b_DoorRlsReq = true;
        *rty_SO_e_DoorRlsDelayTime = 20U;
      }
      break;

     case REL_IN_Error:
      localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_a;
      localDW->is_RlsReq = REL_IN_Idle_a;
      *rty_SO_b_DoorRlsReq = false;
      *rty_SO_b_UnlockReq = false;
      break;

     default:
      /* case IN_Release: */
      if (localDW->temporalCounter_i2 >= 5) {
        localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_a;
        localDW->is_RlsReq = REL_IN_Idle_a;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/RLDoorRlsReq' */
static void REL_DoorHndBtn(UInt8 rtu_SI_e_EspVehSpd, Boolean
  rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8 rtu_SI_e_DoorLockSts,
  uint8_T rtu_SI_e_DoorRatSts, boolean_T *rty_SO_b_DoorRlsReq, boolean_T
  *rty_SO_b_UnlockReq, uint8_T *rty_SO_e_DoorRlsDelayTime, DW_RLDoorRlsReq_REL_T
  *localDW)
{
  if (localDW->is_RlsReq_h == REL_IN_Idle_a) {
    if ((((rtu_SI_e_EspVehSpd <= 0) && (!rtu_SI_b_EspVehSpdVld)) ||
         (rtu_SI_e_VcuGearPosn == 1)) && ((localDW->SL_b_DoorHndBtnValid_prev !=
          localDW->SL_b_DoorHndBtnValid_start) &&
         localDW->SL_b_DoorHndBtnValid_start)) {
      localDW->is_RlsReq_h = REL_IN_Trigger;
      switch (rtu_SI_e_DoorLockSts) {
       case 0:
        localDW->is_Trigger_k = REL_IN_DoorLock;
        localDW->temporalCounter_i5 = 0U;
        *rty_SO_b_UnlockReq = true;
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
    localDW->is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_a;
    localDW->is_RlsReq_h = REL_IN_Idle_a;
    *rty_SO_b_DoorRlsReq = false;
    *rty_SO_b_UnlockReq = false;
  } else {
    switch (localDW->is_Trigger_k) {
     case REL_IN_DoorLock:
      if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
        localDW->is_Trigger_k = REL_IN_RELEASE;
        localDW->temporalCounter_i5 = 0U;
        *rty_SO_b_DoorRlsReq = true;
        *rty_SO_e_DoorRlsDelayTime = 0U;
      } else if (localDW->temporalCounter_i5 >= 100) {
        localDW->is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_a;
        localDW->is_RlsReq_h = REL_IN_Idle_a;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
      }
      break;

     case REL_IN_DoorUnlock:
      if (rtu_SI_e_DoorRatSts != 3) {
        localDW->is_Trigger_k = REL_IN_RELEASE;
        localDW->temporalCounter_i5 = 0U;
        *rty_SO_b_DoorRlsReq = true;
        *rty_SO_e_DoorRlsDelayTime = 0U;
      }
      break;

     case REL_IN_Error:
      break;

     default:
      /* case IN_RELEASE: */
      if (localDW->temporalCounter_i5 >= 5) {
        localDW->is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_a;
        localDW->is_RlsReq_h = REL_IN_Idle_a;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
      }
      break;
    }
  }

  switch (localDW->is_SwValid_i) {
   case REL_IN_Idle_a:
    if ((localDW->SI_b_DoorHndBtnSts_prev != localDW->SI_b_DoorHndBtnSts_start) &&
        localDW->SI_b_DoorHndBtnSts_start) {
      localDW->is_SwValid_i = REL_IN_Press;
      localDW->temporalCounter_i4 = 0U;
    }
    break;

   case REL_IN_Press:
    if ((localDW->SI_b_DoorHndBtnSts_prev != localDW->SI_b_DoorHndBtnSts_start) &&
        (!localDW->SI_b_DoorHndBtnSts_start)) {
      localDW->is_SwValid_i = REL_IN_Release_lvk;
      localDW->temporalCounter_i4 = 0U;
      localDW->SL_b_DoorHndBtnValid = true;
    } else if (localDW->temporalCounter_i4 >= 100) {
      localDW->is_SwValid_i = REL_IN_Idle_a;
      localDW->SL_b_DoorHndBtnValid = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (localDW->temporalCounter_i4 >= 3) {
      localDW->is_SwValid_i = REL_IN_Idle_a;
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
void REL_RLDoorRlsReq_Init(boolean_T *rty_SO_b_DoorRlsReq, boolean_T
  *rty_SO_b_UnlockReq, uint8_T *rty_SO_e_DoorRlsDelayTime)
{
  *rty_SO_b_DoorRlsReq = false;
  *rty_SO_b_UnlockReq = false;
  *rty_SO_e_DoorRlsDelayTime = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S3>/RLDoorRlsReq'
 *    '<S3>/RRDoorRlsReq'
 */
void REL_RLDoorRlsReq(boolean_T rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd, Boolean
                      rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8
                      rtu_SI_e_DoorLockSts, uint8_T rtu_SI_e_DoorRatSts,
                      boolean_T rtu_SI_b_DoorInBtnSts, boolean_T
                      rtu_SI_b_DoorHndPullSts, boolean_T rtu_SI_b_DoorHndBtnSts,
                      UInt8 rtu_SI_e_DoorHandPosSts, Boolean
                      rtu_SI_b_CentSingleDoorBtnSts, Boolean
                      rtu_SI_b_CentAllDoorBtnSts, Boolean rtu_SI_b_ChildLckSts,
                      boolean_T *rty_SO_b_DoorRlsReq, boolean_T
                      *rty_SO_b_UnlockReq, uint8_T *rty_SO_e_DoorRlsDelayTime,
                      DW_RLDoorRlsReq_REL_T *localDW)
{
  if (localDW->temporalCounter_i1 < 255U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->temporalCounter_i2 < 127U) {
    localDW->temporalCounter_i2++;
  }

  if (localDW->temporalCounter_i3 < 7U) {
    localDW->temporalCounter_i3++;
  }

  if (localDW->temporalCounter_i4 < 127U) {
    localDW->temporalCounter_i4++;
  }

  if (localDW->temporalCounter_i5 < 127U) {
    localDW->temporalCounter_i5++;
  }

  if (localDW->temporalCounter_i6 < 127U) {
    localDW->temporalCounter_i6++;
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

  /* Chart: '<S3>/RLDoorRlsReq' */
  if (localDW->is_active_c5_DoorRlsReq == 0U) {
    localDW->SI_b_DoorInBtnSts_prev = rtu_SI_b_DoorInBtnSts;
    localDW->SI_b_DoorHndBtnSts_prev = rtu_SI_b_DoorHndBtnSts;
    localDW->is_active_c5_DoorRlsReq = 1U;
    localDW->is_SwValid = REL_IN_Idle_a;
    localDW->SL_b_DoorInBtnValid = false;
    localDW->is_RlsReq = REL_IN_Idle_a;
    localDW->is_DoorCentral = REL_IN_Idle_a;
    localDW->SL_b_CentSingleDoorBtnValid = rtu_SI_b_CentSingleDoorBtnSts;
    localDW->SL_b_CentAllDoorBtnValid = rtu_SI_b_CentAllDoorBtnSts;
    localDW->SL_b_DoorHndPullValid = rtu_SI_b_DoorHndPullSts;
    localDW->is_RlsReq_l = REL_IN_Idle_a;
    localDW->is_RlsReq_h = REL_IN_Idle_a;
    *rty_SO_b_DoorRlsReq = false;
    *rty_SO_b_UnlockReq = false;
    localDW->is_SwValid_i = REL_IN_Idle_a;
    localDW->SL_b_DoorHndBtnValid = false;
  } else {
    REL_DoorInBtn(rtu_SI_e_EspVehSpd, rtu_SI_b_EspVehSpdVld,
                  rtu_SI_e_VcuGearPosn, rtu_SI_e_DoorLockSts,
                  rtu_SI_e_DoorRatSts, rtu_SI_b_ChildLckSts, rty_SO_b_DoorRlsReq,
                  rty_SO_b_UnlockReq, rty_SO_e_DoorRlsDelayTime, localDW);
    if (localDW->is_DoorCentral == REL_IN_Idle_a) {
      if ((!rtu_SI_b_OFF) && (((rtu_SI_e_EspVehSpd <= 0) &&
            (!rtu_SI_b_EspVehSpdVld)) || (rtu_SI_e_VcuGearPosn == 1)) &&
          (((localDW->SL_b_CentSingleDoorBtnValid_pre !=
             localDW->SL_b_CentSingleDoorBtnValid_sta) &&
            localDW->SL_b_CentSingleDoorBtnValid_sta) ||
           ((localDW->SL_b_CentAllDoorBtnValid_prev !=
             localDW->SL_b_CentAllDoorBtnValid_start) &&
            localDW->SL_b_CentAllDoorBtnValid_start))) {
        localDW->is_DoorCentral = REL_IN_Trigger;
        switch (rtu_SI_e_DoorLockSts) {
         case 0:
          localDW->is_Trigger_b = REL_IN_DoorLock;
          localDW->temporalCounter_i6 = 0U;
          *rty_SO_b_UnlockReq = true;
          break;

         case 1:
          localDW->is_Trigger_b = REL_IN_DoorUnlock;
          break;

         default:
          localDW->is_Trigger_b = REL_IN_Error;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (rtu_SI_b_OFF || ((rtu_SI_e_EspVehSpd >= 1) &&
                (!rtu_SI_b_EspVehSpdVld) && (rtu_SI_e_VcuGearPosn != 1)) ||
               ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts == 3))) {
      localDW->is_Trigger_b = REL_IN_NO_ACTIVE_CHILD_a;
      localDW->is_DoorCentral = REL_IN_Idle_a;
      *rty_SO_b_DoorRlsReq = false;
      *rty_SO_b_UnlockReq = false;
    } else {
      switch (localDW->is_Trigger_b) {
       case REL_IN_DoorLock:
        if (localDW->temporalCounter_i6 >= 100) {
          localDW->is_Trigger_b = REL_IN_NO_ACTIVE_CHILD_a;
          localDW->is_DoorCentral = REL_IN_Idle_a;
          *rty_SO_b_DoorRlsReq = false;
          *rty_SO_b_UnlockReq = false;
        } else if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
          localDW->is_Trigger_b = REL_IN_RELEASE;
          localDW->temporalCounter_i6 = 0U;
          *rty_SO_b_DoorRlsReq = true;
          *rty_SO_e_DoorRlsDelayTime = 0U;
        }
        break;

       case REL_IN_DoorUnlock:
        if (rtu_SI_e_DoorRatSts != 3) {
          localDW->is_Trigger_b = REL_IN_RELEASE;
          localDW->temporalCounter_i6 = 0U;
          *rty_SO_b_DoorRlsReq = true;
          *rty_SO_e_DoorRlsDelayTime = 0U;
        }
        break;

       case REL_IN_Error:
        localDW->is_Trigger_b = REL_IN_NO_ACTIVE_CHILD_a;
        localDW->is_DoorCentral = REL_IN_Idle_a;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
        break;

       default:
        /* case IN_RELEASE: */
        if (localDW->temporalCounter_i6 >= 5) {
          localDW->is_Trigger_b = REL_IN_NO_ACTIVE_CHILD_a;
          localDW->is_DoorCentral = REL_IN_Idle_a;
          *rty_SO_b_DoorRlsReq = false;
          *rty_SO_b_UnlockReq = false;
        }
        break;
      }
    }

    localDW->SL_b_CentSingleDoorBtnValid = rtu_SI_b_CentSingleDoorBtnSts;
    localDW->SL_b_CentAllDoorBtnValid = rtu_SI_b_CentAllDoorBtnSts;
    localDW->SL_b_DoorHndPullValid = rtu_SI_b_DoorHndPullSts;
    if (localDW->is_RlsReq_l == REL_IN_Idle_a) {
      if ((!rtu_SI_b_OFF) && (((rtu_SI_e_EspVehSpd <= 0) &&
            (!rtu_SI_b_EspVehSpdVld)) || (rtu_SI_e_VcuGearPosn == 1)) &&
          (rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorHandPosSts == 1) &&
          ((localDW->SL_b_DoorHndPullValid_prev !=
            localDW->SL_b_DoorHndPullValid_start) &&
           localDW->SL_b_DoorHndPullValid_start)) {
        localDW->is_RlsReq_l = REL_IN_Trigger;
        localDW->is_Trigger_l = REL_IN_DoorUnlock_e;
      }

      /* case IN_Trigger: */
    } else if (rtu_SI_b_OFF || ((rtu_SI_e_EspVehSpd >= 1) &&
                (!rtu_SI_b_EspVehSpdVld) && (rtu_SI_e_VcuGearPosn != 1)) ||
               (rtu_SI_e_DoorLockSts != 1) || (rtu_SI_e_DoorHandPosSts != 1) ||
               (rtu_SI_e_DoorRatSts == 3)) {
      localDW->is_Trigger_l = REL_IN_NO_ACTIVE_CHILD_a;
      localDW->is_RlsReq_l = REL_IN_Idle_a;
      *rty_SO_b_DoorRlsReq = false;
      *rty_SO_b_UnlockReq = false;
    } else if (localDW->is_Trigger_l == REL_IN_DoorUnlock_e) {
      if (rtu_SI_e_DoorRatSts != 3) {
        localDW->is_Trigger_l = REL_IN_Release_lv;
        localDW->temporalCounter_i3 = 0U;
        *rty_SO_b_DoorRlsReq = true;
        *rty_SO_e_DoorRlsDelayTime = 4U;
      }

      /* case IN_Release: */
    } else if (localDW->temporalCounter_i3 >= 5) {
      localDW->is_Trigger_l = REL_IN_NO_ACTIVE_CHILD_a;
      localDW->is_RlsReq_l = REL_IN_Idle_a;
      *rty_SO_b_DoorRlsReq = false;
      *rty_SO_b_UnlockReq = false;
    }

    REL_DoorHndBtn(rtu_SI_e_EspVehSpd, rtu_SI_b_EspVehSpdVld,
                   rtu_SI_e_VcuGearPosn, rtu_SI_e_DoorLockSts,
                   rtu_SI_e_DoorRatSts, rty_SO_b_DoorRlsReq, rty_SO_b_UnlockReq,
                   rty_SO_e_DoorRlsDelayTime, localDW);
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

/* Function for Chart: '<S3>/FLDoorRlsReq' */
static void REL_DoorInBtn_i(const boolean_T *SI_b_DoorInBtnSts_prev_a, const
  boolean_T *SL_b_DoorInBtnValid_prev_h)
{
  switch (REL_DW.is_SwValid_a) {
   case REL_IN_Idle_n:
    if ((*SI_b_DoorInBtnSts_prev_a != REL_DW.SI_b_DoorInBtnSts_start_n) &&
        REL_DW.SI_b_DoorInBtnSts_start_n) {
      REL_DW.is_SwValid_a = REL_IN_Once_a;
      REL_DW.temporalCounter_i1_h = 0U;
    }
    break;

   case REL_IN_Once_a:
    if ((*SI_b_DoorInBtnSts_prev_a != REL_DW.SI_b_DoorInBtnSts_start_n) &&
        REL_DW.SI_b_DoorInBtnSts_start_n) {
      REL_DW.is_SwValid_a = REL_IN_Twice_m;
      REL_DW.temporalCounter_i1_h = 0U;
      REL_DW.SL_b_DoorInBtnValid_f = true;
    } else if (REL_DW.temporalCounter_i1_h >= 200) {
      REL_DW.is_SwValid_a = REL_IN_Idle_n;
      REL_DW.SL_b_DoorInBtnValid_f = false;
    }
    break;

   default:
    /* case IN_Twice: */
    if (REL_DW.temporalCounter_i1_h >= 3) {
      REL_DW.is_SwValid_a = REL_IN_Idle_n;
      REL_DW.SL_b_DoorInBtnValid_f = false;
    }
    break;
  }

  if (REL_DW.is_RlsReq_f == REL_IN_Idle_n) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     */
    if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
        ((*SL_b_DoorInBtnValid_prev_h != REL_DW.SL_b_DoorInBtnValid_start_l) &&
         REL_DW.SL_b_DoorInBtnValid_start_l)) {
      REL_DW.is_RlsReq_f = REL_IN_Trigger_h;

      /* Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig' */
      switch (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si) {
       case 0:
        REL_DW.is_Trigger_b = REL_IN_DoorLock_b;
        REL_DW.temporalCounter_i2_c = 0U;
        REL_B.SO_b_UnlockReq_m = true;
        break;

       case 1:
        REL_DW.is_Trigger_b = REL_IN_DoorUnlock_h;
        break;

       default:
        REL_DW.is_Trigger_b = REL_IN_Error_f;
        break;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     *  Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig'
     *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
     *  Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig'
     */
    /* case IN_Trigger: */
  } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
              (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP != 1)) ||
             ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
              (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V == 3))) {
    REL_DW.is_Trigger_b = 0;
    REL_DW.is_RlsReq_f = REL_IN_Idle_n;
    REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_m = false;
  } else {
    switch (REL_DW.is_Trigger_b) {
     case REL_IN_DoorLock_b:
      if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
          (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
        REL_DW.is_Trigger_b = REL_IN_Release_h;
        REL_DW.temporalCounter_i2_c = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_g = 20U;
      } else if (REL_DW.temporalCounter_i2_c >= 100) {
        REL_DW.is_Trigger_b = 0;
        REL_DW.is_RlsReq_f = REL_IN_Idle_n;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_m = false;
      }
      break;

     case REL_IN_DoorUnlock_h:
      if (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3) {
        REL_DW.is_Trigger_b = REL_IN_Release_h;
        REL_DW.temporalCounter_i2_c = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_g = 20U;
      }
      break;

     case REL_IN_Error_f:
      REL_DW.is_Trigger_b = 0;
      REL_DW.is_RlsReq_f = REL_IN_Idle_n;
      REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
      REL_B.SO_b_UnlockReq_m = false;
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i2_c >= 5) {
        REL_DW.is_Trigger_b = 0;
        REL_DW.is_RlsReq_f = REL_IN_Idle_n;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_m = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/FLDoorRlsReq' */
static void REL_DoorHndBtn_l(const boolean_T *SI_b_DoorHndBtnSts_prev_p, const
  boolean_T *SL_b_DoorHndBtnValid_prev_n)
{
  if (REL_DW.is_RlsReq_m == REL_IN_Idle_n) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     */
    if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
        ((*SL_b_DoorHndBtnValid_prev_n != REL_DW.SL_b_DoorHndBtnValid_start_k) &&
         REL_DW.SL_b_DoorHndBtnValid_start_k)) {
      REL_DW.is_RlsReq_m = REL_IN_Trigger_h;

      /* Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig' */
      switch (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si) {
       case 0:
        REL_DW.is_Trigger_k = REL_IN_DoorLock_b;
        REL_DW.temporalCounter_i5_c = 0U;
        REL_B.SO_b_UnlockReq_m = true;
        break;

       case 1:
        REL_DW.is_Trigger_k = REL_IN_DoorUnlock_h;
        break;

       default:
        REL_DW.is_Trigger_k = REL_IN_Error_f;
        break;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     *  Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig'
     *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
     *  Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig'
     */
    /* case IN_Trigger: */
  } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
              (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP != 1)) ||
             ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
              (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V == 3))) {
    REL_DW.is_Trigger_k = 0;
    REL_DW.is_RlsReq_m = REL_IN_Idle_n;
    REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_m = false;
  } else {
    switch (REL_DW.is_Trigger_k) {
     case REL_IN_DoorLock_b:
      if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
          (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
        REL_DW.is_Trigger_k = REL_IN_RELEASE_j;
        REL_DW.temporalCounter_i5_c = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_g = 0U;
      } else if (REL_DW.temporalCounter_i5_c >= 100) {
        REL_DW.is_Trigger_k = 0;
        REL_DW.is_RlsReq_m = REL_IN_Idle_n;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_m = false;
      }
      break;

     case REL_IN_DoorUnlock_h:
      if (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3) {
        REL_DW.is_Trigger_k = REL_IN_RELEASE_j;
        REL_DW.temporalCounter_i5_c = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_g = 0U;
      }
      break;

     case REL_IN_Error_f:
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i5_c >= 5) {
        REL_DW.is_Trigger_k = 0;
        REL_DW.is_RlsReq_m = REL_IN_Idle_n;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_m = false;
      }
      break;
    }
  }

  switch (REL_DW.is_SwValid_d) {
   case REL_IN_Idle_n:
    if ((*SI_b_DoorHndBtnSts_prev_p != REL_DW.SI_b_DoorHndBtnSts_start_e) &&
        REL_DW.SI_b_DoorHndBtnSts_start_e) {
      REL_DW.is_SwValid_d = REL_IN_Press_f;
      REL_DW.temporalCounter_i4_i = 0U;
    }
    break;

   case REL_IN_Press_f:
    if ((*SI_b_DoorHndBtnSts_prev_p != REL_DW.SI_b_DoorHndBtnSts_start_e) &&
        (!REL_DW.SI_b_DoorHndBtnSts_start_e)) {
      REL_DW.is_SwValid_d = REL_IN_Release_htd;
      REL_DW.temporalCounter_i4_i = 0U;
      REL_DW.SL_b_DoorHndBtnValid_c = true;
    } else if (REL_DW.temporalCounter_i4_i >= 100) {
      REL_DW.is_SwValid_d = REL_IN_Idle_n;
      REL_DW.SL_b_DoorHndBtnValid_c = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (REL_DW.temporalCounter_i4_i >= 3) {
      REL_DW.is_SwValid_d = REL_IN_Idle_n;
      REL_DW.SL_b_DoorHndBtnValid_c = false;
    }
    break;
  }
}

/* Function for Chart: '<S3>/FRDoorRlsReq' */
static void REL_DoorInBtn_i5(const boolean_T *SI_b_DoorInBtnSts_prev, const
  boolean_T *SL_b_DoorInBtnValid_prev)
{
  switch (REL_DW.is_SwValid) {
   case REL_IN_Idle_n:
    if ((*SI_b_DoorInBtnSts_prev != REL_DW.SI_b_DoorInBtnSts_start) &&
        REL_DW.SI_b_DoorInBtnSts_start) {
      REL_DW.is_SwValid = REL_IN_Once_a;
      REL_DW.temporalCounter_i1_f = 0U;
    }
    break;

   case REL_IN_Once_a:
    if ((*SI_b_DoorInBtnSts_prev != REL_DW.SI_b_DoorInBtnSts_start) &&
        REL_DW.SI_b_DoorInBtnSts_start) {
      REL_DW.is_SwValid = REL_IN_Twice_m;
      REL_DW.temporalCounter_i1_f = 0U;
      REL_DW.SL_b_DoorInBtnValid = true;
    } else if (REL_DW.temporalCounter_i1_f >= 200) {
      REL_DW.is_SwValid = REL_IN_Idle_n;
      REL_DW.SL_b_DoorInBtnValid = false;
    }
    break;

   default:
    /* case IN_Twice: */
    if (REL_DW.temporalCounter_i1_f >= 3) {
      REL_DW.is_SwValid = REL_IN_Idle_n;
      REL_DW.SL_b_DoorInBtnValid = false;
    }
    break;
  }

  if (REL_DW.is_RlsReq == REL_IN_Idle_n) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     */
    if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
        ((*SL_b_DoorInBtnValid_prev != REL_DW.SL_b_DoorInBtnValid_start) &&
         REL_DW.SL_b_DoorInBtnValid_start)) {
      REL_DW.is_RlsReq = REL_IN_Trigger_h;

      /* Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig' */
      switch (REL_U.VeOUT_DLK_BCMPassengerDoorLockS) {
       case 0:
        REL_DW.is_Trigger = REL_IN_DoorLock_b;
        REL_DW.temporalCounter_i2 = 0U;
        REL_B.SO_b_UnlockReq_b = true;
        break;

       case 1:
        REL_DW.is_Trigger = REL_IN_DoorUnlock_h;
        break;

       default:
        REL_DW.is_Trigger = REL_IN_Error_f;
        break;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
     *  Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg'
     *  Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig'
     */
    /* case IN_Trigger: */
  } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
              (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP != 1)) ||
             ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
              (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V == 3))) {
    REL_DW.is_Trigger = 0;
    REL_DW.is_RlsReq = REL_IN_Idle_n;
    REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_b = false;
  } else {
    switch (REL_DW.is_Trigger) {
     case REL_IN_DoorLock_b:
      if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
          (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
        REL_DW.is_Trigger = REL_IN_Release_h;
        REL_DW.temporalCounter_i2 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_e = 20U;
      } else if (REL_DW.temporalCounter_i2 >= 100) {
        REL_DW.is_Trigger = 0;
        REL_DW.is_RlsReq = REL_IN_Idle_n;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_b = false;
      }
      break;

     case REL_IN_DoorUnlock_h:
      if (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3) {
        REL_DW.is_Trigger = REL_IN_Release_h;
        REL_DW.temporalCounter_i2 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_e = 20U;
      }
      break;

     case REL_IN_Error_f:
      REL_DW.is_Trigger = 0;
      REL_DW.is_RlsReq = REL_IN_Idle_n;
      REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
      REL_B.SO_b_UnlockReq_b = false;
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i2 >= 5) {
        REL_DW.is_Trigger = 0;
        REL_DW.is_RlsReq = REL_IN_Idle_n;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_b = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/FRDoorRlsReq' */
static void REL_DoorHndBtn_n(const boolean_T *SI_b_DoorHndBtnSts_prev, const
  boolean_T *SL_b_DoorHndBtnValid_prev)
{
  if (REL_DW.is_RlsReq_j == REL_IN_Idle_n) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     */
    if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
        ((*SL_b_DoorHndBtnValid_prev != REL_DW.SL_b_DoorHndBtnValid_start) &&
         REL_DW.SL_b_DoorHndBtnValid_start)) {
      REL_DW.is_RlsReq_j = REL_IN_Trigger_h;

      /* Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig' */
      switch (REL_U.VeOUT_DLK_BCMPassengerDoorLockS) {
       case 0:
        REL_DW.is_Trigger_d = REL_IN_DoorLock_b;
        REL_DW.temporalCounter_i5 = 0U;
        REL_B.SO_b_UnlockReq_b = true;
        break;

       case 1:
        REL_DW.is_Trigger_d = REL_IN_DoorUnlock_h;
        break;

       default:
        REL_DW.is_Trigger_d = REL_IN_Error_f;
        break;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
     *  Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg'
     *  Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig'
     */
    /* case IN_Trigger: */
  } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
              (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP != 1)) ||
             ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
              (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V == 3))) {
    REL_DW.is_Trigger_d = 0;
    REL_DW.is_RlsReq_j = REL_IN_Idle_n;
    REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_b = false;
  } else {
    switch (REL_DW.is_Trigger_d) {
     case REL_IN_DoorLock_b:
      if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
          (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
        REL_DW.is_Trigger_d = REL_IN_RELEASE_j;
        REL_DW.temporalCounter_i5 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_e = 0U;
      } else if (REL_DW.temporalCounter_i5 >= 100) {
        REL_DW.is_Trigger_d = 0;
        REL_DW.is_RlsReq_j = REL_IN_Idle_n;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_b = false;
      }
      break;

     case REL_IN_DoorUnlock_h:
      if (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3) {
        REL_DW.is_Trigger_d = REL_IN_RELEASE_j;
        REL_DW.temporalCounter_i5 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_e = 0U;
      }
      break;

     case REL_IN_Error_f:
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i5 >= 5) {
        REL_DW.is_Trigger_d = 0;
        REL_DW.is_RlsReq_j = REL_IN_Idle_n;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_b = false;
      }
      break;
    }
  }

  switch (REL_DW.is_SwValid_i) {
   case REL_IN_Idle_n:
    if ((*SI_b_DoorHndBtnSts_prev != REL_DW.SI_b_DoorHndBtnSts_start) &&
        REL_DW.SI_b_DoorHndBtnSts_start) {
      REL_DW.is_SwValid_i = REL_IN_Press_f;
      REL_DW.temporalCounter_i4 = 0U;
    }
    break;

   case REL_IN_Press_f:
    if ((*SI_b_DoorHndBtnSts_prev != REL_DW.SI_b_DoorHndBtnSts_start) &&
        (!REL_DW.SI_b_DoorHndBtnSts_start)) {
      REL_DW.is_SwValid_i = REL_IN_Release_htd;
      REL_DW.temporalCounter_i4 = 0U;
      REL_DW.SL_b_DoorHndBtnValid = true;
    } else if (REL_DW.temporalCounter_i4 >= 100) {
      REL_DW.is_SwValid_i = REL_IN_Idle_n;
      REL_DW.SL_b_DoorHndBtnValid = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (REL_DW.temporalCounter_i4 >= 3) {
      REL_DW.is_SwValid_i = REL_IN_Idle_n;
      REL_DW.SL_b_DoorHndBtnValid = false;
    }
    break;
  }
}

/* Model step function for TID1 */
void REL_Step(void)                    /* Explicit Task: REL_Step */
{
  uint8_T SO_e_MotorPwm_h;
  boolean_T Compare;
  boolean_T SI_b_CrashSts_prev;
  boolean_T SI_b_DoorHndBtnSts_prev_p;
  boolean_T SI_b_DoorInBtnSts_prev_a;
  boolean_T SL_b_CentAllDoorBtnValid_prev_j;
  boolean_T SL_b_CentSingleDoorBtnValid_p_a;
  boolean_T SL_b_DoorHndBtnValid_prev_n;
  boolean_T SL_b_DoorHndPullValid_prev_g;
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

  /* Chart: '<S3>/DoorLockSetSts' incorporates:
   *  Inport: '<Root>/VeINP_CAN_CdcDrvrDoorLockSet_sig_VeINP_CAN_CdcDrvrDoorLockSet_sig'
   *  Inport: '<Root>/VeINP_EPRM_BdcDrvrDoorLockSetSts_sig_VeINP_EPRM_BdcDrvrDoorLockSetSts_sig'
   */
  if (REL_DW.is_active_c1_REL == 0U) {
    REL_DW.is_active_c1_REL = 1U;

    /*  DoorLockSet  */
    REL_DW.SL_e_DoorLockSetBackup = 0U;
    if (REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si == 1) {
      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = true;

      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_m = true;
      REL_DW.SL_e_DoorLockSetBackup = 1U;
    } else if (REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si == 2) {
      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = false;

      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_m = false;
      REL_DW.SL_e_DoorLockSetBackup = 2U;
    } else {
      switch (REL_U.VeINP_EPRM_BdcDrvrDoorLockSetSt) {
       case 1:
        /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
        REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = true;

        /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
        REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_m = true;
        break;

       case 0:
        /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
        REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = false;

        /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
        REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_m = false;
        break;
      }
    }
  } else if ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si == 1) ||
             ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si == 0) &&
              (REL_DW.SL_e_DoorLockSetBackup == 1))) {
    /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
    REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = true;

    /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
    REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_m = true;
    REL_DW.SL_e_DoorLockSetBackup = 1U;
  } else if ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si == 2) ||
             ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si == 0) &&
              (REL_DW.SL_e_DoorLockSetBackup == 2))) {
    /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
    REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = false;

    /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
    REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_m = false;
    REL_DW.SL_e_DoorLockSetBackup = 2U;
  } else {
    switch (REL_U.VeINP_EPRM_BdcDrvrDoorLockSetSt) {
     case 1:
      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = true;

      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_m = true;
      break;

     case 0:
      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = false;

      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_m = false;
      break;
    }
  }

  /* End of Chart: '<S3>/DoorLockSetSts' */

  /* Truth Table: '<S3>/FLDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V);

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Constant: '<S12>/Constant'
   *  Inport: '<Root>/VeOUT_PDU_BcmPowerStatusFeedback_sig_VeOUT_PDU_BcmPowerStatusFeedback_sig'
   */
  Compare = (REL_U.VeOUT_PDU_BcmPowerStatusFeedbac == 0);

  /* Chart: '<S3>/FLDoorRlsReq' incorporates:
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DHM_BDCDrvrDoorHndSts_sig_VeOUT_DHM_BDCDrvrDoorHndSts_sig'
   *  Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig'
   */
  if (REL_DW.temporalCounter_i1_h < 255U) {
    REL_DW.temporalCounter_i1_h++;
  }

  if (REL_DW.temporalCounter_i2_c < 127U) {
    REL_DW.temporalCounter_i2_c++;
  }

  if (REL_DW.temporalCounter_i3_l < 7U) {
    REL_DW.temporalCounter_i3_l++;
  }

  if (REL_DW.temporalCounter_i4_i < 127U) {
    REL_DW.temporalCounter_i4_i++;
  }

  if (REL_DW.temporalCounter_i5_c < 127U) {
    REL_DW.temporalCounter_i5_c++;
  }

  if (REL_DW.temporalCounter_i6_e < 127U) {
    REL_DW.temporalCounter_i6_e++;
  }

  SI_b_DoorInBtnSts_prev_a = REL_DW.SI_b_DoorInBtnSts_start_n;
  REL_DW.SI_b_DoorInBtnSts_start_n = SL_b_FLDoorInBtnSts;
  SL_b_FLDoorInBtnSts = REL_DW.SL_b_DoorInBtnValid_start_l;
  REL_DW.SL_b_DoorInBtnValid_start_l = REL_DW.SL_b_DoorInBtnValid_f;
  SL_b_DoorHndPullValid_prev_g = REL_DW.SL_b_DoorHndPullValid_start_m;
  REL_DW.SL_b_DoorHndPullValid_start_m = REL_DW.SL_b_DoorHndPullValid_p;
  SI_b_DoorHndBtnSts_prev_p = REL_DW.SI_b_DoorHndBtnSts_start_e;
  REL_DW.SI_b_DoorHndBtnSts_start_e = REL_Y.VbOUT_REL_FLDoorHndlBtnSig_flg_;
  SL_b_DoorHndBtnValid_prev_n = REL_DW.SL_b_DoorHndBtnValid_start_k;
  REL_DW.SL_b_DoorHndBtnValid_start_k = REL_DW.SL_b_DoorHndBtnValid_c;
  SL_b_CentSingleDoorBtnValid_p_a = REL_DW.SL_b_CentSingleDoorBtnValid_s_n;
  REL_DW.SL_b_CentSingleDoorBtnValid_s_n = REL_DW.SL_b_CentSingleDoorBtnValid_h;
  SL_b_CentAllDoorBtnValid_prev_j = REL_DW.SL_b_CentAllDoorBtnValid_star_k;
  REL_DW.SL_b_CentAllDoorBtnValid_star_k = REL_DW.SL_b_CentAllDoorBtnValid_d;
  if (REL_DW.is_active_c5_DoorRlsReq_m == 0U) {
    REL_DW.is_active_c5_DoorRlsReq_m = 1U;
    REL_DW.is_SwValid_a = REL_IN_Idle_n;
    REL_DW.SL_b_DoorInBtnValid_f = false;
    REL_DW.is_RlsReq_f = REL_IN_Idle_n;
    REL_DW.is_DoorCentral_f = REL_IN_Idle_n;
    REL_DW.SL_b_CentSingleDoorBtnValid_h = REL_U.VbINP_CAN_CdcDrvrDoorButtonSts_;
    REL_DW.SL_b_CentAllDoorBtnValid_d = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
    REL_DW.SL_b_DoorHndPullValid_p = REL_Y.VbOUT_REL_BcmDrvrDoorHandleReq_;
    REL_DW.is_RlsReq_n = REL_IN_Idle_n;
    REL_DW.is_RlsReq_m = REL_IN_Idle_n;

    /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' incorporates:
     *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
     *  Inport: '<Root>/VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg'
     *  Outport: '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg'
     */
    REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_m = false;
    REL_DW.is_SwValid_d = REL_IN_Idle_n;
    REL_DW.SL_b_DoorHndBtnValid_c = false;
  } else {
    REL_DoorInBtn_i(&SI_b_DoorInBtnSts_prev_a, &SL_b_FLDoorInBtnSts);
    if (REL_DW.is_DoorCentral_f == REL_IN_Idle_n) {
      if ((!Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
          (((SL_b_CentSingleDoorBtnValid_p_a !=
             REL_DW.SL_b_CentSingleDoorBtnValid_s_n) &&
            REL_DW.SL_b_CentSingleDoorBtnValid_s_n) ||
           ((SL_b_CentAllDoorBtnValid_prev_j !=
             REL_DW.SL_b_CentAllDoorBtnValid_star_k) &&
            REL_DW.SL_b_CentAllDoorBtnValid_star_k))) {
        REL_DW.is_DoorCentral_f = REL_IN_Trigger_h;
        switch (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si) {
         case 0:
          REL_DW.is_Trigger_j = REL_IN_DoorLock_b;
          REL_DW.temporalCounter_i6_e = 0U;
          REL_B.SO_b_UnlockReq_m = true;
          break;

         case 1:
          REL_DW.is_Trigger_j = REL_IN_DoorUnlock_h;
          break;

         default:
          REL_DW.is_Trigger_j = REL_IN_Error_f;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (Compare || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                           (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP != 1)) ||
               ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
                (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V == 3))) {
      REL_DW.is_Trigger_j = 0;
      REL_DW.is_DoorCentral_f = REL_IN_Idle_n;

      /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
      REL_B.SO_b_UnlockReq_m = false;
    } else {
      switch (REL_DW.is_Trigger_j) {
       case REL_IN_DoorLock_b:
        if (REL_DW.temporalCounter_i6_e >= 100) {
          REL_DW.is_Trigger_j = 0;
          REL_DW.is_DoorCentral_f = REL_IN_Idle_n;

          /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
          REL_B.SO_b_UnlockReq_m = false;
        } else if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
                   (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
          REL_DW.is_Trigger_j = REL_IN_RELEASE_j;
          REL_DW.temporalCounter_i6_e = 0U;

          /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
          REL_B.SO_e_DoorRlsDelayTime_g = 0U;
        }
        break;

       case REL_IN_DoorUnlock_h:
        if (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3) {
          REL_DW.is_Trigger_j = REL_IN_RELEASE_j;
          REL_DW.temporalCounter_i6_e = 0U;

          /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
          REL_B.SO_e_DoorRlsDelayTime_g = 0U;
        }
        break;

       case REL_IN_Error_f:
        REL_DW.is_Trigger_j = 0;
        REL_DW.is_DoorCentral_f = REL_IN_Idle_n;

        /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_m = false;
        break;

       default:
        /* case IN_RELEASE: */
        if (REL_DW.temporalCounter_i6_e >= 5) {
          REL_DW.is_Trigger_j = 0;
          REL_DW.is_DoorCentral_f = REL_IN_Idle_n;

          /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
          REL_B.SO_b_UnlockReq_m = false;
        }
        break;
      }
    }

    REL_DW.SL_b_CentSingleDoorBtnValid_h = REL_U.VbINP_CAN_CdcDrvrDoorButtonSts_;
    REL_DW.SL_b_CentAllDoorBtnValid_d = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
    REL_DW.SL_b_DoorHndPullValid_p = REL_Y.VbOUT_REL_BcmDrvrDoorHandleReq_;
    if (REL_DW.is_RlsReq_n == REL_IN_Idle_n) {
      if ((!Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
          (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
          (REL_U.VeOUT_DHM_BDCDrvrDoorHndSts_sig == 1) &&
          ((SL_b_DoorHndPullValid_prev_g != REL_DW.SL_b_DoorHndPullValid_start_m)
           && REL_DW.SL_b_DoorHndPullValid_start_m)) {
        REL_DW.is_RlsReq_n = REL_IN_Trigger_h;
        REL_DW.is_Trigger_gs = REL_IN_DoorUnlock_hd;
      }

      /* case IN_Trigger: */
    } else if (Compare || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                           (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP != 1)) ||
               (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si != 1) ||
               (REL_U.VeOUT_DHM_BDCDrvrDoorHndSts_sig != 1) ||
               (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V == 3)) {
      REL_DW.is_Trigger_gs = 0;
      REL_DW.is_RlsReq_n = REL_IN_Idle_n;

      /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
      REL_B.SO_b_UnlockReq_m = false;
    } else if (REL_DW.is_Trigger_gs == REL_IN_DoorUnlock_hd) {
      if (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3) {
        REL_DW.is_Trigger_gs = REL_IN_Release_ht;
        REL_DW.temporalCounter_i3_l = 0U;

        /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_g = 4U;
      }

      /* case IN_Release: */
    } else if (REL_DW.temporalCounter_i3_l >= 5) {
      REL_DW.is_Trigger_gs = 0;
      REL_DW.is_RlsReq_n = REL_IN_Idle_n;

      /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
      REL_B.SO_b_UnlockReq_m = false;
    }

    REL_DoorHndBtn_l(&SI_b_DoorHndBtnSts_prev_p, &SL_b_DoorHndBtnValid_prev_n);
  }

  /* End of Chart: '<S3>/FLDoorRlsReq' */

  /* Chart: '<S3>/FLDoorRlsDriver' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig'
   */
  REL_FLDoorRlsDriver(REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU,
                      REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_,
                      REL_B.SO_e_DoorRlsDelayTime_g,
                      &REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU,
                      &REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU,
                      &REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve, &SO_e_MotorPwm_h,
                      &REL_DW.sf_FLDoorRlsDriver);

  /* Truth Table: '<S3>/FRDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_FRDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V);

  /* Chart: '<S3>/FRDoorRlsReq' incorporates:
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DHM_BDCPassDoorHndSts_sig_VeOUT_DHM_BDCPassDoorHndSts_sig'
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg'
   *  Outport: '<Root>/VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig'
   */
  if (REL_DW.temporalCounter_i1_f < 255U) {
    REL_DW.temporalCounter_i1_f++;
  }

  if (REL_DW.temporalCounter_i2 < 127U) {
    REL_DW.temporalCounter_i2++;
  }

  if (REL_DW.temporalCounter_i3 < 7U) {
    REL_DW.temporalCounter_i3++;
  }

  if (REL_DW.temporalCounter_i4 < 127U) {
    REL_DW.temporalCounter_i4++;
  }

  if (REL_DW.temporalCounter_i5 < 127U) {
    REL_DW.temporalCounter_i5++;
  }

  if (REL_DW.temporalCounter_i6 < 127U) {
    REL_DW.temporalCounter_i6++;
  }

  SI_b_DoorInBtnSts_prev_a = REL_DW.SI_b_DoorInBtnSts_start;
  REL_DW.SI_b_DoorInBtnSts_start = SL_b_FRDoorInBtnSts;
  SL_b_FRDoorInBtnSts = REL_DW.SL_b_DoorInBtnValid_start;
  REL_DW.SL_b_DoorInBtnValid_start = REL_DW.SL_b_DoorInBtnValid;
  SL_b_FLDoorInBtnSts = REL_DW.SL_b_DoorHndPullValid_start;
  REL_DW.SL_b_DoorHndPullValid_start = REL_DW.SL_b_DoorHndPullValid;
  SL_b_DoorHndPullValid_prev_g = REL_DW.SI_b_DoorHndBtnSts_start;
  REL_DW.SI_b_DoorHndBtnSts_start = REL_Y.VbOUT_REL_FRDoorHndlBtnSig_flg_;
  SI_b_DoorHndBtnSts_prev_p = REL_DW.SL_b_DoorHndBtnValid_start;
  REL_DW.SL_b_DoorHndBtnValid_start = REL_DW.SL_b_DoorHndBtnValid;
  SL_b_DoorHndBtnValid_prev_n = REL_DW.SL_b_CentSingleDoorBtnValid_sta;
  REL_DW.SL_b_CentSingleDoorBtnValid_sta = REL_DW.SL_b_CentSingleDoorBtnValid;
  SL_b_CentSingleDoorBtnValid_p_a = REL_DW.SL_b_CentAllDoorBtnValid_start;
  REL_DW.SL_b_CentAllDoorBtnValid_start = REL_DW.SL_b_CentAllDoorBtnValid;
  if (REL_DW.is_active_c5_DoorRlsReq == 0U) {
    REL_DW.is_active_c5_DoorRlsReq = 1U;
    REL_DW.is_SwValid = REL_IN_Idle_n;
    REL_DW.SL_b_DoorInBtnValid = false;
    REL_DW.is_RlsReq = REL_IN_Idle_n;
    REL_DW.is_DoorCentral = REL_IN_Idle_n;
    REL_DW.SL_b_CentSingleDoorBtnValid = REL_U.VbINP_CAN_CdcPassDoorButtonSts_;
    REL_DW.SL_b_CentAllDoorBtnValid = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
    REL_DW.SL_b_DoorHndPullValid = REL_Y.VbOUT_REL_BcmPassDoorHandleReq_;
    REL_DW.is_RlsReq_c = REL_IN_Idle_n;
    REL_DW.is_RlsReq_j = REL_IN_Idle_n;

    /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' incorporates:
     *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
     *  Inport: '<Root>/VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg'
     *  Outport: '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg'
     */
    REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_b = false;
    REL_DW.is_SwValid_i = REL_IN_Idle_n;
    REL_DW.SL_b_DoorHndBtnValid = false;
  } else {
    REL_DoorInBtn_i5(&SI_b_DoorInBtnSts_prev_a, &SL_b_FRDoorInBtnSts);
    if (REL_DW.is_DoorCentral == REL_IN_Idle_n) {
      if ((!Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
          (((SL_b_DoorHndBtnValid_prev_n !=
             REL_DW.SL_b_CentSingleDoorBtnValid_sta) &&
            REL_DW.SL_b_CentSingleDoorBtnValid_sta) ||
           ((SL_b_CentSingleDoorBtnValid_p_a !=
             REL_DW.SL_b_CentAllDoorBtnValid_start) &&
            REL_DW.SL_b_CentAllDoorBtnValid_start))) {
        REL_DW.is_DoorCentral = REL_IN_Trigger_h;
        switch (REL_U.VeOUT_DLK_BCMPassengerDoorLockS) {
         case 0:
          REL_DW.is_Trigger_g = REL_IN_DoorLock_b;
          REL_DW.temporalCounter_i6 = 0U;
          REL_B.SO_b_UnlockReq_b = true;
          break;

         case 1:
          REL_DW.is_Trigger_g = REL_IN_DoorUnlock_h;
          break;

         default:
          REL_DW.is_Trigger_g = REL_IN_Error_f;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (Compare || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                           (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP != 1)) ||
               ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
                (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V == 3))) {
      REL_DW.is_Trigger_g = 0;
      REL_DW.is_DoorCentral = REL_IN_Idle_n;

      /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
      REL_B.SO_b_UnlockReq_b = false;
    } else {
      switch (REL_DW.is_Trigger_g) {
       case REL_IN_DoorLock_b:
        if (REL_DW.temporalCounter_i6 >= 100) {
          REL_DW.is_Trigger_g = 0;
          REL_DW.is_DoorCentral = REL_IN_Idle_n;

          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
          REL_B.SO_b_UnlockReq_b = false;
        } else if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
                   (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
          REL_DW.is_Trigger_g = REL_IN_RELEASE_j;
          REL_DW.temporalCounter_i6 = 0U;

          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
          REL_B.SO_e_DoorRlsDelayTime_e = 0U;
        }
        break;

       case REL_IN_DoorUnlock_h:
        if (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3) {
          REL_DW.is_Trigger_g = REL_IN_RELEASE_j;
          REL_DW.temporalCounter_i6 = 0U;

          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
          REL_B.SO_e_DoorRlsDelayTime_e = 0U;
        }
        break;

       case REL_IN_Error_f:
        REL_DW.is_Trigger_g = 0;
        REL_DW.is_DoorCentral = REL_IN_Idle_n;

        /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_b = false;
        break;

       default:
        /* case IN_RELEASE: */
        if (REL_DW.temporalCounter_i6 >= 5) {
          REL_DW.is_Trigger_g = 0;
          REL_DW.is_DoorCentral = REL_IN_Idle_n;

          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
          REL_B.SO_b_UnlockReq_b = false;
        }
        break;
      }
    }

    REL_DW.SL_b_CentSingleDoorBtnValid = REL_U.VbINP_CAN_CdcPassDoorButtonSts_;
    REL_DW.SL_b_CentAllDoorBtnValid = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
    REL_DW.SL_b_DoorHndPullValid = REL_Y.VbOUT_REL_BcmPassDoorHandleReq_;
    if (REL_DW.is_RlsReq_c == REL_IN_Idle_n) {
      if ((!Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
          (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
          (REL_U.VeOUT_DHM_BDCPassDoorHndSts_sig == 1) && ((SL_b_FLDoorInBtnSts
            != REL_DW.SL_b_DoorHndPullValid_start) &&
           REL_DW.SL_b_DoorHndPullValid_start)) {
        REL_DW.is_RlsReq_c = REL_IN_Trigger_h;
        REL_DW.is_Trigger_i = REL_IN_DoorUnlock_hd;
      }

      /* case IN_Trigger: */
    } else if (Compare || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                           (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP != 1)) ||
               (REL_U.VeOUT_DLK_BCMPassengerDoorLockS != 1) ||
               (REL_U.VeOUT_DHM_BDCPassDoorHndSts_sig != 1) ||
               (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V == 3)) {
      REL_DW.is_Trigger_i = 0;
      REL_DW.is_RlsReq_c = REL_IN_Idle_n;

      /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
      REL_B.SO_b_UnlockReq_b = false;
    } else if (REL_DW.is_Trigger_i == REL_IN_DoorUnlock_hd) {
      if (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3) {
        REL_DW.is_Trigger_i = REL_IN_Release_ht;
        REL_DW.temporalCounter_i3 = 0U;

        /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_e = 4U;
      }

      /* case IN_Release: */
    } else if (REL_DW.temporalCounter_i3 >= 5) {
      REL_DW.is_Trigger_i = 0;
      REL_DW.is_RlsReq_c = REL_IN_Idle_n;

      /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
      REL_B.SO_b_UnlockReq_b = false;
    }

    REL_DoorHndBtn_n(&SL_b_DoorHndPullValid_prev_g, &SI_b_DoorHndBtnSts_prev_p);
  }

  /* End of Chart: '<S3>/FRDoorRlsReq' */

  /* Chart: '<S3>/FRDoorRlsDriver' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   *  Outport: '<Root>/VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg'
   *  Outport: '<Root>/VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg'
   *  Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig'
   */
  REL_FLDoorRlsDriver(REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU,
                      REL_U.VbINP_HWA_FRDoorAjar_flg_VbINP_,
                      REL_B.SO_e_DoorRlsDelayTime_e,
                      &REL_Y.VbOUT_REL_FRDoorMotorA_flg_VbOU,
                      &REL_Y.VbOUT_REL_FRDoorMotorB_flg_VbOU,
                      &REL_Y.VeOUT_REL_FRDoorMotorSts_sig_Ve, &SO_e_MotorPwm_h,
                      &REL_DW.sf_FRDoorRlsDriver);

  /* Truth Table: '<S3>/RLDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLRDoorRatSts_sig_VeOUT_REL_BdcLRDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_RLDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcLRDoorRatSts_sig_V);

  /* Chart: '<S3>/RLDoorRlsReq' incorporates:
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcLeReDoorButtonSts_flg_VbINP_CAN_CdcLeReDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbINP_HWA_LRChildLckSt_flg_VbINP_HWA_LRChildLckSt_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DHM_BDCLeReDoorHndSts_sig_VeOUT_DHM_BDCLeReDoorHndSts_sig'
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLRDoorRatSts_sig_VeOUT_REL_BdcLRDoorRatSts_sig'
   */
  REL_RLDoorRlsReq(Compare, REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                   REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN,
                   REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP,
                   REL_U.VeOUT_DLK_BCMPassengerDoorLockS,
                   REL_Y.VeOUT_REL_BdcLRDoorRatSts_sig_V, SI_b_CrashSts_prev,
                   REL_Y.VbOUT_REL_BcmLeReDoorHandleReq_,
                   REL_Y.VbOUT_REL_RLDoorHndlBtnSig_flg_,
                   REL_U.VeOUT_DHM_BDCLeReDoorHndSts_sig,
                   REL_U.VbINP_CAN_CdcLeReDoorButtonSts_,
                   REL_U.VbINP_CAN_CdcAllDoorOpenButtonS,
                   REL_U.VbINP_HWA_LRChildLckSt_flg_VbIN,
                   &REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU,
                   &REL_B.SO_b_UnlockReq_h, &REL_B.SO_e_DoorRlsDelayTime_o,
                   &REL_DW.sf_RLDoorRlsReq);

  /* Truth Table: '<S3>/RRDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcRRDoorRatSts_sig_VeOUT_REL_BdcRRDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_RRDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcRRDoorRatSts_sig_V);

  /* Chart: '<S3>/RRDoorRlsReq' incorporates:
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcRiReDoorButtonSts_flg_VbINP_CAN_CdcRiReDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbINP_HWA_RRChildLckSt_flg_VbINP_HWA_RRChildLckSt_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DHM_BDCRiReDoorHndSts_sig_VeOUT_DHM_BDCRiReDoorHndSts_sig'
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcRRDoorRatSts_sig_VeOUT_REL_BdcRRDoorRatSts_sig'
   */
  REL_RLDoorRlsReq(Compare, REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                   REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN,
                   REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP,
                   REL_U.VeOUT_DLK_BCMPassengerDoorLockS,
                   REL_Y.VeOUT_REL_BdcRRDoorRatSts_sig_V, SL_b_RRDoorInBtnSts,
                   REL_Y.VbOUT_REL_BcmBcmRiReDoorHandleR,
                   REL_Y.VbOUT_REL_RRDoorHndlBtnSig_flg_,
                   REL_U.VeOUT_DHM_BDCRiReDoorHndSts_sig,
                   REL_U.VbINP_CAN_CdcRiReDoorButtonSts_,
                   REL_U.VbINP_CAN_CdcAllDoorOpenButtonS,
                   REL_U.VbINP_HWA_RRChildLckSt_flg_VbIN,
                   &REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU, &REL_B.SO_b_UnlockReq,
                   &REL_B.SO_e_DoorRlsDelayTime, &REL_DW.sf_RRDoorRlsReq);

  /* Logic: '<S3>/Logical Operator' */
  SI_b_CrashSts_prev = (REL_B.SO_b_UnlockReq_b || REL_B.SO_b_UnlockReq_h ||
                        REL_B.SO_b_UnlockReq);

  /* Chart: '<S3>/RLDoorRlsDriver' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig'
   */
  REL_FLDoorRlsDriver(REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU,
                      REL_U.VbINP_HWA_RLDoorAjar_flg_VbINP_,
                      REL_B.SO_e_DoorRlsDelayTime_o,
                      &REL_Y.VbOUT_REL_RLDoorMotorA_flg_VbOU,
                      &REL_Y.VbOUT_REL_RLDoorMotorB_flg_VbOU,
                      &REL_Y.VeOUT_REL_RLDoorMotorSts_sig_Ve, &SO_e_MotorPwm_h,
                      &REL_DW.sf_RLDoorRlsDriver);

  /* Chart: '<S3>/RRDoorRlsDriver' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_RRDoorMotorSts_sig_VeOUT_REL_RRDoorMotorSts_sig'
   */
  REL_FLDoorRlsDriver(REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU,
                      REL_U.VbINP_HWA_RRDoorAjar_flg_VbINP_,
                      REL_B.SO_e_DoorRlsDelayTime,
                      &REL_Y.VbOUT_REL_RRDoorMotorA_flg_VbOU,
                      &REL_Y.VbOUT_REL_RRDoorMotorB_flg_VbOU,
                      &REL_Y.VeOUT_REL_RRDoorMotorSts_sig_Ve, &SO_e_MotorPwm_h,
                      &REL_DW.sf_RRDoorRlsDriver);

  /* Chart: '<S3>/Unlock_Request' */
  SL_b_RRDoorInBtnSts = REL_DW.SI_b_DrvUnlockReq_start;
  REL_DW.SI_b_DrvUnlockReq_start = REL_B.SO_b_UnlockReq_m;
  Compare = REL_DW.SI_b_PassUnlockReq_start;
  REL_DW.SI_b_PassUnlockReq_start = SI_b_CrashSts_prev;
  if (REL_DW.is_active_c6_REL == 0U) {
    REL_DW.is_active_c6_REL = 1U;
    REL_DW.is_c6_REL = REL_IN_Initial_d;

    /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
    REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 0U;
  } else if (REL_DW.is_c6_REL == REL_IN_Initial_d) {
    if (((SL_b_RRDoorInBtnSts != REL_DW.SI_b_DrvUnlockReq_start) &&
         REL_DW.SI_b_DrvUnlockReq_start) || ((Compare !=
          REL_DW.SI_b_PassUnlockReq_start) && REL_DW.SI_b_PassUnlockReq_start))
    {
      REL_DW.is_c6_REL = REL_IN_REQ_SENT;
    }
  } else {
    /* case IN_REQ_SENT: */
    SL_b_RRDoorInBtnSts = !SI_b_CrashSts_prev;
    Compare = !REL_B.SO_b_UnlockReq_m;
    if (Compare && SL_b_RRDoorInBtnSts) {
      REL_DW.is_c6_REL = REL_IN_Initial_d;

      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 0U;
    } else if (REL_B.SO_b_UnlockReq_m && SI_b_CrashSts_prev) {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 3U;
    } else if (REL_B.SO_b_UnlockReq_m && SL_b_RRDoorInBtnSts) {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 1U;
    } else if (Compare && SI_b_CrashSts_prev) {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 2U;
    } else {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 0U;
    }
  }

  /* End of Chart: '<S3>/Unlock_Request' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockOpenReq_flg_VbOUT_REL_BdcDrvrDoorLockOpenReq_flg' incorporates:
   *  Constant: '<S3>/Constant3'
   */
  REL_Y.VbOUT_REL_BdcDrvrDoorLockOpenRe = false;
}

/* Model initialize function */
void REL_initialize(void)
{
  {
    uint8_T SO_e_MotorPwm_h;
    boolean_T SO_b_Error_d;

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
      &REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve, &SO_b_Error_d, &SO_e_MotorPwm_h);

    /* SystemInitialize for Chart: '<S3>/FRDoorRlsDriver' incorporates:
     *  Outport: '<Root>/VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg'
     *  Outport: '<Root>/VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg'
     *  Outport: '<Root>/VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig'
     */
    REL_FLDoorRlsDriver_Init(&REL_Y.VbOUT_REL_FRDoorMotorA_flg_VbOU,
      &REL_Y.VbOUT_REL_FRDoorMotorB_flg_VbOU,
      &REL_Y.VeOUT_REL_FRDoorMotorSts_sig_Ve, &SO_b_Error_d, &SO_e_MotorPwm_h);

    /* SystemInitialize for Chart: '<S3>/RLDoorRlsDriver' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg'
     *  Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg'
     *  Outport: '<Root>/VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig'
     */
    REL_FLDoorRlsDriver_Init(&REL_Y.VbOUT_REL_RLDoorMotorA_flg_VbOU,
      &REL_Y.VbOUT_REL_RLDoorMotorB_flg_VbOU,
      &REL_Y.VeOUT_REL_RLDoorMotorSts_sig_Ve, &SO_b_Error_d, &SO_e_MotorPwm_h);

    /* SystemInitialize for Chart: '<S3>/RLDoorRlsReq' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg'
     */
    REL_RLDoorRlsReq_Init(&REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU,
                          &REL_B.SO_b_UnlockReq_h,
                          &REL_B.SO_e_DoorRlsDelayTime_o);

    /* SystemInitialize for Chart: '<S3>/RRDoorRlsDriver' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg'
     *  Outport: '<Root>/VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg'
     *  Outport: '<Root>/VeOUT_REL_RRDoorMotorSts_sig_VeOUT_REL_RRDoorMotorSts_sig'
     */
    REL_FLDoorRlsDriver_Init(&REL_Y.VbOUT_REL_RRDoorMotorA_flg_VbOU,
      &REL_Y.VbOUT_REL_RRDoorMotorB_flg_VbOU,
      &REL_Y.VeOUT_REL_RRDoorMotorSts_sig_Ve, &SO_b_Error_d, &SO_e_MotorPwm_h);

    /* SystemInitialize for Chart: '<S3>/RRDoorRlsReq' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg'
     */
    REL_RLDoorRlsReq_Init(&REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU,
                          &REL_B.SO_b_UnlockReq, &REL_B.SO_e_DoorRlsDelayTime);

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
