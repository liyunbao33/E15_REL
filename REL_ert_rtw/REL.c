/*
 * File: REL.c
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.195
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Sep  1 20:22:52 2023
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

/* Named constants for Chart: '<S3>/FLDoorRelease' */
#define REL_IN_DOOR_LOCK               ((uint8_T)1U)
#define REL_IN_DOOR_UNLOCK             ((uint8_T)2U)
#define REL_IN_FAIL_UNLOCK             ((uint8_T)1U)
#define REL_IN_Initial                 ((uint8_T)1U)
#define REL_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define REL_IN_RELEASE                 ((uint8_T)3U)
#define REL_IN_REQ_UNLOCK              ((uint8_T)2U)
#define REL_IN_SUCESS_UNLOCK           ((uint8_T)3U)
#define REL_IN_TRIGGER                 ((uint8_T)2U)

/* Named constants for Chart: '<S3>/FLDoorReleaseDriver' */
#define REL_IN_CHECKING                ((uint8_T)1U)
#define REL_IN_ELECTRIC_DOOR           ((uint8_T)1U)
#define REL_IN_ERROR                   ((uint8_T)1U)
#define REL_IN_ERROR1                  ((uint8_T)2U)
#define REL_IN_ICE_BREAK               ((uint8_T)3U)
#define REL_IN_IDLE                    ((uint8_T)1U)
#define REL_IN_IDLE_f                  ((uint8_T)4U)
#define REL_IN_INITIAL                 ((uint8_T)2U)
#define REL_IN_LAST_CHECK              ((uint8_T)5U)
#define REL_IN_LAST_CHECK_a            ((uint8_T)2U)
#define REL_IN_NON_ELECTRIC_DOOR       ((uint8_T)2U)
#define REL_IN_NORMAL                  ((uint8_T)1U)
#define REL_IN_NO_ACTIVE_CHILD_e       ((uint8_T)0U)
#define REL_IN_RELEASE_i               ((uint8_T)2U)
#define REL_IN_RESET                   ((uint8_T)3U)
#define REL_IN_STARTUP_SETTING         ((uint8_T)2U)
#define REL_IN_STEP2_OPEN              ((uint8_T)4U)
#define REL_IN_WAITING                 ((uint8_T)6U)
#define REL_IN_WAITING_o               ((uint8_T)3U)

/* Named constants for Chart: '<S3>/FLSwitchStatus' */
#define REL_IN_Initial_l               ((uint8_T)1U)
#define REL_IN_ONCE                    ((uint8_T)2U)
#define REL_IN_Press                   ((uint8_T)2U)
#define REL_IN_Release                 ((uint8_T)3U)
#define REL_IN_TWICE                   ((uint8_T)3U)

/* Named constants for Chart: '<S3>/RLSwitchStatus' */
#define REL_IN_Initial_p               ((uint8_T)1U)
#define REL_IN_ONCE_l                  ((uint8_T)2U)
#define REL_IN_Press_g                 ((uint8_T)2U)
#define REL_IN_Release_g               ((uint8_T)3U)
#define REL_IN_TWICE_h                 ((uint8_T)3U)

/* Named constants for Chart: '<S3>/DrvDoorUnlockAutoOpen' */
#define REL_IN_CFG_SETTING             ((uint8_T)1U)
#define REL_IN_Initial_m               ((uint8_T)2U)

/* Named constants for Chart: '<S3>/HandleButtonState' */
#define REL_IN_Initial_i               ((uint8_T)1U)
#define REL_IN_ONCE_k                  ((uint8_T)2U)

/* Named constants for Chart: '<S3>/Unlock_Request' */
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
static void REL_ELECTRIC_DOOR(Boolean rtu_SI_b_DoorOpenSts, Boolean
  rtu_SI_b_DCUCinchHomeSwt, boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorMode, boolean_T *rty_SO_b_Error,
  DW_FLDoorReleaseDriver_REL_T *localDW);

/* Forward declaration for local functions */
static void REL_InitialSet(void);

/*
 * Output and update for atomic system:
 *    '<S3>/FLDoorRatSts'
 *    '<S3>/FRDoorRatSts'
 *    '<S3>/RLDoorRatSts'
 *    '<S3>/RRDoorRatSts'
 */
void REL_FLDoorRatSts(Boolean rtu_SI_b_DoorOpen, uint8_T *rty_SO_e_DoorRatSts)
{
  Boolean aVarTruthTableCondition_1_tmp;
  boolean_T tmp;

  /*  condition 1 */
  aVarTruthTableCondition_1_tmp = !rtu_SI_b_DoorOpen;

  /*  condition 2 */
  tmp = !aVarTruthTableCondition_1_tmp;
  if (tmp) {
    /*  All Lock */
    *rty_SO_e_DoorRatSts = 1U;
  } else if (tmp && aVarTruthTableCondition_1_tmp) {
    /*  Half Lock */
    *rty_SO_e_DoorRatSts = 2U;
  } else if (aVarTruthTableCondition_1_tmp) {
    /*  All Unlock */
    *rty_SO_e_DoorRatSts = 3U;
  } else {
    /*  Default */
    /*  Invalid */
    *rty_SO_e_DoorRatSts = 0U;
  }
}

/*
 * System initialize for atomic system:
 *    '<S3>/FLDoorRelease'
 *    '<S3>/FRDoorRelease'
 *    '<S3>/RLDoorRelease'
 *    '<S3>/RRDoorRelease'
 */
void REL_FLDoorRelease_Init(boolean_T *rty_SO_b_DoorRlsReq, boolean_T
  *rty_SO_b_UnlockReq)
{
  *rty_SO_b_DoorRlsReq = false;
  *rty_SO_b_UnlockReq = false;
}

/*
 * Output and update for atomic system:
 *    '<S3>/FLDoorRelease'
 *    '<S3>/FRDoorRelease'
 *    '<S3>/RLDoorRelease'
 *    '<S3>/RRDoorRelease'
 */
void REL_FLDoorRelease(boolean_T rtu_SI_b_POW_OFF, UInt8 rtu_SI_e_EspVehSpd,
  Boolean rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8
  rtu_SI_e_DoorLockSts, uint8_T rtu_SI_e_DoorRatSts, boolean_T rtu_SI_b_DoorInSW,
  Boolean rtu_SI_b_CentSingleDoorSW, Boolean rtu_SI_b_CentAllDoorSW, boolean_T
  *rty_SO_b_DoorRlsReq, boolean_T *rty_SO_b_UnlockReq, DW_FLDoorRelease_REL_T
  *localDW)
{
  if (localDW->temporalCounter_i1 < 127U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->temporalCounter_i2 < 127U) {
    localDW->temporalCounter_i2++;
  }

  if (localDW->temporalCounter_i3 < 127U) {
    localDW->temporalCounter_i3++;
  }

  if (localDW->temporalCounter_i4 < 127U) {
    localDW->temporalCounter_i4++;
  }

  localDW->SI_b_CentSingleDoorSW_prev = localDW->SI_b_CentSingleDoorSW_start;
  localDW->SI_b_CentSingleDoorSW_start = rtu_SI_b_CentSingleDoorSW;
  localDW->SI_b_CentAllDoorSW_prev = localDW->SI_b_CentAllDoorSW_start;
  localDW->SI_b_CentAllDoorSW_start = rtu_SI_b_CentAllDoorSW;
  localDW->SI_e_VcuGearPosn_prev = localDW->SI_e_VcuGearPosn_start;
  localDW->SI_e_VcuGearPosn_start = rtu_SI_e_VcuGearPosn;
  localDW->SI_b_DoorInSW_prev = localDW->SI_b_DoorInSW_start;
  localDW->SI_b_DoorInSW_start = rtu_SI_b_DoorInSW;

  /* Chart: '<S3>/FLDoorRelease' */
  if (localDW->is_active_c5_DoorRelease == 0U) {
    localDW->SI_b_CentSingleDoorSW_prev = rtu_SI_b_CentSingleDoorSW;
    localDW->SI_b_CentAllDoorSW_prev = rtu_SI_b_CentAllDoorSW;
    localDW->SI_e_VcuGearPosn_prev = rtu_SI_e_VcuGearPosn;
    localDW->SI_b_DoorInSW_prev = rtu_SI_b_DoorInSW;
    localDW->is_active_c5_DoorRelease = 1U;
    localDW->is_DoorCentral = REL_IN_Initial;
    localDW->is_DoorIn = REL_IN_Initial;
    *rty_SO_b_DoorRlsReq = false;
    *rty_SO_b_UnlockReq = false;
  } else {
    if (localDW->is_DoorCentral == REL_IN_Initial) {
      if ((!rtu_SI_b_POW_OFF) && (rtu_SI_e_DoorRatSts != 3) &&
          (((rtu_SI_e_EspVehSpd <= 0) && (!rtu_SI_b_EspVehSpdVld)) ||
           (rtu_SI_e_VcuGearPosn == 1)) &&
          (((localDW->SI_b_CentSingleDoorSW_prev !=
             localDW->SI_b_CentSingleDoorSW_start) &&
            localDW->SI_b_CentSingleDoorSW_start) ||
           ((localDW->SI_b_CentAllDoorSW_prev !=
             localDW->SI_b_CentAllDoorSW_start) &&
            localDW->SI_b_CentAllDoorSW_start))) {
        localDW->is_DoorCentral = REL_IN_TRIGGER;
        localDW->temporalCounter_i2 = 0U;
        if (rtu_SI_e_DoorLockSts == 0) {
          localDW->is_TRIGGER = REL_IN_DOOR_LOCK;
          localDW->is_DOOR_LOCK = REL_IN_REQ_UNLOCK;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_UnlockReq = true;
        } else {
          localDW->is_TRIGGER = REL_IN_DOOR_UNLOCK;
        }
      }

      /* case IN_TRIGGER: */
    } else if (((localDW->SI_e_VcuGearPosn_prev !=
                 localDW->SI_e_VcuGearPosn_start) &&
                (localDW->SI_e_VcuGearPosn_prev == 1)) || ((rtu_SI_e_EspVehSpd >=
      5) && (!rtu_SI_b_EspVehSpdVld)) || ((localDW->temporalCounter_i2 >= 105) &&
                (rtu_SI_e_DoorLockSts == 0))) {
      localDW->is_DOOR_LOCK = REL_IN_NO_ACTIVE_CHILD;
      localDW->is_TRIGGER = REL_IN_NO_ACTIVE_CHILD;
      localDW->is_DoorCentral = REL_IN_Initial;
      *rty_SO_b_DoorRlsReq = false;
      *rty_SO_b_UnlockReq = false;
    } else {
      switch (localDW->is_TRIGGER) {
       case REL_IN_DOOR_LOCK:
        if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
          localDW->is_DOOR_LOCK = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_TRIGGER = REL_IN_RELEASE;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_DoorRlsReq = true;
        } else {
          switch (localDW->is_DOOR_LOCK) {
           case REL_IN_FAIL_UNLOCK:
            break;

           case REL_IN_REQ_UNLOCK:
            if (rtu_SI_e_DoorLockSts == 1) {
              localDW->is_DOOR_LOCK = REL_IN_SUCESS_UNLOCK;
            } else if ((localDW->temporalCounter_i1 >= 100) &&
                       (rtu_SI_e_DoorLockSts == 0)) {
              localDW->is_DOOR_LOCK = REL_IN_FAIL_UNLOCK;
            }
            break;

           default:
            /* case IN_SUCESS_UNLOCK: */
            break;
          }
        }
        break;

       case REL_IN_DOOR_UNLOCK:
        if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
          localDW->is_TRIGGER = REL_IN_RELEASE;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_DoorRlsReq = true;
        }
        break;

       default:
        /* case IN_RELEASE: */
        if (localDW->temporalCounter_i1 >= 5) {
          localDW->is_TRIGGER = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_DoorCentral = REL_IN_Initial;
          *rty_SO_b_DoorRlsReq = false;
          *rty_SO_b_UnlockReq = false;
        }
        break;
      }
    }

    if (localDW->is_DoorIn == REL_IN_Initial) {
      if ((((rtu_SI_e_EspVehSpd <= 0) && (!rtu_SI_b_EspVehSpdVld)) ||
           (rtu_SI_e_VcuGearPosn == 1)) && ((localDW->SI_b_DoorInSW_prev !=
            localDW->SI_b_DoorInSW_start) && localDW->SI_b_DoorInSW_start)) {
        localDW->is_DoorIn = REL_IN_TRIGGER;
        localDW->temporalCounter_i4 = 0U;
        if (rtu_SI_e_DoorLockSts == 0) {
          localDW->is_TRIGGER_m = REL_IN_DOOR_LOCK;
          localDW->is_DOOR_LOCK_e = REL_IN_REQ_UNLOCK;
          localDW->temporalCounter_i3 = 0U;
          *rty_SO_b_UnlockReq = true;
        } else {
          localDW->is_TRIGGER_m = REL_IN_DOOR_UNLOCK;
        }
      }

      /* case IN_TRIGGER: */
    } else if (((localDW->SI_e_VcuGearPosn_prev !=
                 localDW->SI_e_VcuGearPosn_start) &&
                (localDW->SI_e_VcuGearPosn_prev == 1)) || ((rtu_SI_e_EspVehSpd >=
      5) && (!rtu_SI_b_EspVehSpdVld)) || ((localDW->temporalCounter_i4 >= 105) &&
                (rtu_SI_e_DoorLockSts == 0)) || ((rtu_SI_e_DoorLockSts == 1) &&
                (rtu_SI_e_DoorRatSts == 3))) {
      localDW->is_DOOR_LOCK_e = REL_IN_NO_ACTIVE_CHILD;
      localDW->is_TRIGGER_m = REL_IN_NO_ACTIVE_CHILD;
      localDW->is_DoorIn = REL_IN_Initial;
      *rty_SO_b_DoorRlsReq = false;
      *rty_SO_b_UnlockReq = false;
    } else {
      switch (localDW->is_TRIGGER_m) {
       case REL_IN_DOOR_LOCK:
        if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
          localDW->is_DOOR_LOCK_e = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_TRIGGER_m = REL_IN_RELEASE;
          localDW->temporalCounter_i3 = 0U;
          *rty_SO_b_DoorRlsReq = true;
        } else {
          switch (localDW->is_DOOR_LOCK_e) {
           case REL_IN_FAIL_UNLOCK:
            break;

           case REL_IN_REQ_UNLOCK:
            if (rtu_SI_e_DoorLockSts == 1) {
              localDW->is_DOOR_LOCK_e = REL_IN_SUCESS_UNLOCK;
            } else if ((localDW->temporalCounter_i3 >= 100) &&
                       (rtu_SI_e_DoorLockSts == 0)) {
              localDW->is_DOOR_LOCK_e = REL_IN_FAIL_UNLOCK;
            }
            break;

           default:
            /* case IN_SUCESS_UNLOCK: */
            break;
          }
        }
        break;

       case REL_IN_DOOR_UNLOCK:
        if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
          localDW->is_TRIGGER_m = REL_IN_RELEASE;
          localDW->temporalCounter_i3 = 0U;
          *rty_SO_b_DoorRlsReq = true;
        }
        break;

       default:
        /* case IN_RELEASE: */
        if (localDW->temporalCounter_i3 >= 5) {
          localDW->is_TRIGGER_m = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_DoorIn = REL_IN_Initial;
          *rty_SO_b_DoorRlsReq = false;
          *rty_SO_b_UnlockReq = false;
        }
        break;
      }
    }
  }

  /* End of Chart: '<S3>/FLDoorRelease' */
}

/* Function for Chart: '<S3>/FLDoorReleaseDriver' */
static void REL_ELECTRIC_DOOR(Boolean rtu_SI_b_DoorOpenSts, Boolean
  rtu_SI_b_DCUCinchHomeSwt, boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorMode, boolean_T *rty_SO_b_Error,
  DW_FLDoorReleaseDriver_REL_T *localDW)
{
  if (localDW->is_MAIN_PROGRESS == REL_IN_IDLE) {
    *rty_SO_e_MotorMode = 0U;
    if ((localDW->SI_b_TriggerRelease_prev != localDW->SI_b_TriggerRelease_start)
        && localDW->SI_b_TriggerRelease_start) {
      localDW->is_MAIN_PROGRESS = REL_IN_RELEASE_i;
      localDW->SL_e_CheckCycle = 0U;
      localDW->is_RELEASE = REL_IN_INITIAL;
      localDW->temporalCounter_i1 = 0U;
      *rty_SO_b_MotorA = true;
      *rty_SO_b_MotorB = false;
      *rty_SO_e_MotorMode = 1U;

      /* MotorA=Release Side */
    }
  } else {
    /* case IN_RELEASE: */
    switch (localDW->is_RELEASE) {
     case REL_IN_CHECKING:
      {
        *rty_SO_e_MotorMode = 0U;
        if ((localDW->temporalCounter_i1 >= 5) && rtu_SI_b_DoorOpenSts) {
          localDW->is_RELEASE = REL_IN_STEP2_OPEN;
          localDW->is_STEP2_OPEN = REL_IN_IDLE_f;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorMode = 0U;
        } else {
          Boolean tmp_0;
          tmp_0 = !rtu_SI_b_DoorOpenSts;
          if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
              (localDW->SL_e_CheckCycle < 2)) {
            localDW->is_RELEASE = REL_IN_INITIAL;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = true;
            *rty_SO_b_MotorB = false;
            *rty_SO_e_MotorMode = 1U;

            /* MotorA=Release Side */
          } else if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                     (localDW->SL_e_CheckCycle >= 2)) {
            localDW->is_RELEASE = REL_IN_RESET;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = true;
            *rty_SO_e_MotorMode = 2U;
          }
        }
      }
      break;

     case REL_IN_INITIAL:
      {
        *rty_SO_e_MotorMode = 1U;
        if (localDW->temporalCounter_i1 >= 30) {
          int32_T tmp;
          localDW->is_RELEASE = REL_IN_CHECKING;
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

     case REL_IN_RESET:
      *rty_SO_e_MotorMode = 2U;
      if (localDW->temporalCounter_i1 >= 30) {
        localDW->is_RELEASE = REL_IN_NO_ACTIVE_CHILD_e;
        localDW->is_MAIN_PROGRESS = REL_IN_IDLE;
        *rty_SO_b_MotorA = false;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorMode = 0U;
        *rty_SO_b_Error = false;
      }
      break;

     default:
      /* case IN_STEP2_OPEN: */
      switch (localDW->is_STEP2_OPEN) {
       case REL_IN_ERROR:
        if (localDW->temporalCounter_i1 >= 5) {
          localDW->is_STEP2_OPEN = REL_IN_NO_ACTIVE_CHILD_e;
          localDW->is_RELEASE = REL_IN_RESET;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorMode = 2U;
        }
        break;

       case REL_IN_ERROR1:
        if (localDW->temporalCounter_i1 >= 5) {
          localDW->is_STEP2_OPEN = REL_IN_NO_ACTIVE_CHILD_e;
          localDW->is_RELEASE = REL_IN_RESET;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorMode = 2U;
        }
        break;

       case REL_IN_ICE_BREAK:
        if ((localDW->temporalCounter_i1 < 600) &&
            ((localDW->SI_b_DCUCinchHomeSwt_prev !=
              localDW->SI_b_DCUCinchHomeSwt_start) &&
             (!localDW->SI_b_DCUCinchHomeSwt_start))) {
          localDW->is_STEP2_OPEN = REL_IN_NO_ACTIVE_CHILD_e;
          localDW->is_RELEASE = REL_IN_RESET;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorMode = 2U;
        } else if ((localDW->temporalCounter_i1 >= 600) &&
                   rtu_SI_b_DCUCinchHomeSwt) {
          localDW->is_STEP2_OPEN = REL_IN_ERROR1;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_Error = true;
        }
        break;

       case REL_IN_IDLE_f:
        *rty_SO_e_MotorMode = 0U;
        if (rtu_SI_b_DoorOpenSts) {
          localDW->is_STEP2_OPEN = REL_IN_WAITING;
          localDW->temporalCounter_i1 = 0U;
        } else if ((localDW->temporalCounter_i1 < 270) &&
                   ((localDW->SI_b_DoorOpenSts_prev !=
                     localDW->SI_b_DoorOpenSts_start) &&
                    localDW->SI_b_DoorOpenSts_start)) {
          localDW->is_STEP2_OPEN = REL_IN_NO_ACTIVE_CHILD_e;
          localDW->is_RELEASE = REL_IN_RESET;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorMode = 2U;
        } else if (localDW->temporalCounter_i1 >= 300) {
          localDW->is_STEP2_OPEN = REL_IN_LAST_CHECK;
        }
        break;

       case REL_IN_LAST_CHECK:
        if (!rtu_SI_b_DCUCinchHomeSwt) {
          localDW->is_STEP2_OPEN = REL_IN_ERROR;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_Error = true;
        } else {
          localDW->is_STEP2_OPEN = REL_IN_ICE_BREAK;
          localDW->temporalCounter_i1 = 0U;
        }
        break;

       default:
        /* case IN_WAITING: */
        if (localDW->temporalCounter_i1 >= 5) {
          localDW->is_STEP2_OPEN = REL_IN_NO_ACTIVE_CHILD_e;
          localDW->is_RELEASE = REL_IN_RESET;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorMode = 2U;
        }
        break;
      }
      break;
    }
  }
}

/*
 * System initialize for atomic system:
 *    '<S3>/FLDoorReleaseDriver'
 *    '<S3>/FRDoorReleaseDriver'
 *    '<S3>/RLDoorReleaseDriver'
 *    '<S3>/RLDoorReleaseDriver1'
 */
void REL_FLDoorReleaseDriver_Init(boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorMode, boolean_T *rty_SO_b_Error)
{
  *rty_SO_b_MotorA = false;
  *rty_SO_b_MotorB = false;
  *rty_SO_e_MotorMode = 0U;
  *rty_SO_b_Error = false;
}

/*
 * Output and update for atomic system:
 *    '<S3>/FLDoorReleaseDriver'
 *    '<S3>/FRDoorReleaseDriver'
 *    '<S3>/RLDoorReleaseDriver'
 *    '<S3>/RLDoorReleaseDriver1'
 */
void REL_FLDoorReleaseDriver(boolean_T rtu_SI_b_TriggerRelease, Boolean
  rtu_SI_b_DoorOpenSts, Boolean rtu_SI_b_DCUCinchHomeSwt, Boolean
  rtu_SI_b_ElectricDoorCfg, boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorMode, boolean_T *rty_SO_b_Error,
  DW_FLDoorReleaseDriver_REL_T *localDW)
{
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  localDW->SI_b_DoorOpenSts_prev = localDW->SI_b_DoorOpenSts_start;
  localDW->SI_b_DoorOpenSts_start = rtu_SI_b_DoorOpenSts;
  localDW->SI_b_DCUCinchHomeSwt_prev = localDW->SI_b_DCUCinchHomeSwt_start;
  localDW->SI_b_DCUCinchHomeSwt_start = rtu_SI_b_DCUCinchHomeSwt;
  localDW->SI_b_TriggerRelease_prev = localDW->SI_b_TriggerRelease_start;
  localDW->SI_b_TriggerRelease_start = rtu_SI_b_TriggerRelease;

  /* Chart: '<S3>/FLDoorReleaseDriver' */
  if (localDW->is_active_c19_REL == 0U) {
    localDW->SI_b_DoorOpenSts_prev = rtu_SI_b_DoorOpenSts;
    localDW->SI_b_DCUCinchHomeSwt_prev = rtu_SI_b_DCUCinchHomeSwt;
    localDW->SI_b_TriggerRelease_prev = rtu_SI_b_TriggerRelease;
    localDW->is_active_c19_REL = 1U;
    localDW->is_c19_REL = REL_IN_STARTUP_SETTING;
    localDW->temporalCounter_i1 = 0U;
    *rty_SO_b_MotorA = false;
    *rty_SO_b_MotorB = true;
    *rty_SO_e_MotorMode = 2U;
  } else if (localDW->is_c19_REL == REL_IN_NORMAL) {
    if (localDW->is_NORMAL == REL_IN_ELECTRIC_DOOR) {
      REL_ELECTRIC_DOOR(rtu_SI_b_DoorOpenSts, rtu_SI_b_DCUCinchHomeSwt,
                        rty_SO_b_MotorA, rty_SO_b_MotorB, rty_SO_e_MotorMode,
                        rty_SO_b_Error, localDW);

      /* case IN_NON_ELECTRIC_DOOR: */
    } else if (localDW->is_MAIN_PROGRESS_k == REL_IN_IDLE) {
      *rty_SO_e_MotorMode = 0U;
      if ((localDW->SI_b_TriggerRelease_prev !=
           localDW->SI_b_TriggerRelease_start) &&
          localDW->SI_b_TriggerRelease_start) {
        localDW->is_MAIN_PROGRESS_k = REL_IN_RELEASE_i;
        localDW->SL_e_CheckCycle = 0U;
        localDW->is_RELEASE_h = REL_IN_INITIAL;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_MotorA = true;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorMode = 1U;

        /* MotorA=Release Side */
      }
    } else {
      /* case IN_RELEASE: */
      switch (localDW->is_RELEASE_h) {
       case REL_IN_CHECKING:
        {
          *rty_SO_e_MotorMode = 0U;
          if ((localDW->temporalCounter_i1 >= 5) && rtu_SI_b_DoorOpenSts) {
            localDW->is_RELEASE_h = REL_IN_STEP2_OPEN;
            localDW->is_STEP2_OPEN_j = REL_IN_IDLE;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = false;
            *rty_SO_e_MotorMode = 0U;
          } else {
            Boolean tmp_0;
            tmp_0 = !rtu_SI_b_DoorOpenSts;
            if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                (localDW->SL_e_CheckCycle < 2)) {
              localDW->is_RELEASE_h = REL_IN_INITIAL;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_b_MotorA = true;
              *rty_SO_b_MotorB = false;
              *rty_SO_e_MotorMode = 1U;

              /* MotorA=Release Side */
            } else if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                       (localDW->SL_e_CheckCycle >= 2)) {
              localDW->is_RELEASE_h = REL_IN_RESET;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_b_MotorA = false;
              *rty_SO_b_MotorB = true;
              *rty_SO_e_MotorMode = 2U;
            }
          }
        }
        break;

       case REL_IN_INITIAL:
        {
          *rty_SO_e_MotorMode = 1U;
          if (localDW->temporalCounter_i1 >= 30) {
            int32_T tmp;
            localDW->is_RELEASE_h = REL_IN_CHECKING;
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

       case REL_IN_RESET:
        *rty_SO_e_MotorMode = 2U;
        if (localDW->temporalCounter_i1 >= 30) {
          localDW->is_RELEASE_h = REL_IN_NO_ACTIVE_CHILD_e;
          localDW->is_MAIN_PROGRESS_k = REL_IN_IDLE;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorMode = 0U;
        }
        break;

       default:
        /* case IN_STEP2_OPEN: */
        switch (localDW->is_STEP2_OPEN_j) {
         case REL_IN_IDLE:
          *rty_SO_e_MotorMode = 0U;
          if (rtu_SI_b_DoorOpenSts) {
            localDW->is_STEP2_OPEN_j = REL_IN_WAITING_o;
            localDW->temporalCounter_i1 = 0U;
          } else if ((localDW->temporalCounter_i1 < 270) &&
                     ((localDW->SI_b_DoorOpenSts_prev !=
                       localDW->SI_b_DoorOpenSts_start) &&
                      localDW->SI_b_DoorOpenSts_start)) {
            localDW->is_STEP2_OPEN_j = REL_IN_NO_ACTIVE_CHILD_e;
            localDW->is_RELEASE_h = REL_IN_RESET;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = true;
            *rty_SO_e_MotorMode = 2U;
          } else if (localDW->temporalCounter_i1 >= 300) {
            localDW->is_STEP2_OPEN_j = REL_IN_LAST_CHECK_a;
          }
          break;

         case REL_IN_LAST_CHECK_a:
          localDW->is_STEP2_OPEN_j = REL_IN_NO_ACTIVE_CHILD_e;
          localDW->is_RELEASE_h = REL_IN_RESET;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorMode = 2U;
          break;

         default:
          /* case IN_WAITING: */
          if (localDW->temporalCounter_i1 >= 5) {
            localDW->is_STEP2_OPEN_j = REL_IN_NO_ACTIVE_CHILD_e;
            localDW->is_RELEASE_h = REL_IN_RESET;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = true;
            *rty_SO_e_MotorMode = 2U;
          }
          break;
        }
        break;
      }
    }
  } else {
    /* case IN_STARTUP_SETTING: */
    *rty_SO_e_MotorMode = 2U;
    if (localDW->temporalCounter_i1 >= 30) {
      localDW->is_c19_REL = REL_IN_NORMAL;
      if (rtu_SI_b_ElectricDoorCfg) {
        localDW->is_NORMAL = REL_IN_ELECTRIC_DOOR;
        localDW->is_MAIN_PROGRESS = REL_IN_IDLE;
        *rty_SO_b_MotorA = false;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorMode = 0U;
        *rty_SO_b_Error = false;
      } else {
        localDW->is_NORMAL = REL_IN_NON_ELECTRIC_DOOR;
        localDW->is_MAIN_PROGRESS_k = REL_IN_IDLE;
        *rty_SO_b_MotorA = false;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorMode = 0U;
      }
    }
  }

  /* End of Chart: '<S3>/FLDoorReleaseDriver' */
}

/*
 * System initialize for atomic system:
 *    '<S3>/FLSwitchStatus'
 *    '<S3>/FRSwitchStatus'
 */
void REL_FLSwitchStatus_Init(boolean_T *rty_SO_b_DoorInSwSts, boolean_T
  *rty_SO_b_DoorOutSwSts, boolean_T *rty_SO_b_DoorHandSwSts)
{
  *rty_SO_b_DoorInSwSts = false;
  *rty_SO_b_DoorOutSwSts = false;
  *rty_SO_b_DoorHandSwSts = false;
}

/*
 * Output and update for atomic system:
 *    '<S3>/FLSwitchStatus'
 *    '<S3>/FRSwitchStatus'
 */
void REL_FLSwitchStatus(Boolean rtu_SI_b_DoorInSW, Boolean rtu_SI_b_DoorOutSW,
  Boolean rtu_SI_b_DoorHandSW, uint8_T rtu_SI_e_DoublePressTime, uint8_T
  rtu_SI_e_SinglePressTime, boolean_T rtu_SI_b_ChildLckSts, boolean_T
  *rty_SO_b_DoorInSwSts, boolean_T *rty_SO_b_DoorOutSwSts, boolean_T
  *rty_SO_b_DoorHandSwSts, DW_FLSwitchStatus_REL_T *localDW)
{
  if (localDW->temporalCounter_i1 < 255U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->temporalCounter_i2 < 255U) {
    localDW->temporalCounter_i2++;
  }

  localDW->SI_b_DoorInSW_prev = localDW->SI_b_DoorInSW_start;
  localDW->SI_b_DoorInSW_start = rtu_SI_b_DoorInSW;
  localDW->SI_b_DoorHandSW_prev = localDW->SI_b_DoorHandSW_start;
  localDW->SI_b_DoorHandSW_start = rtu_SI_b_DoorHandSW;

  /* Chart: '<S3>/FLSwitchStatus' */
  if (localDW->is_active_c5_SwitchStatus == 0U) {
    localDW->SI_b_DoorInSW_prev = rtu_SI_b_DoorInSW;
    localDW->SI_b_DoorHandSW_prev = rtu_SI_b_DoorHandSW;
    localDW->is_active_c5_SwitchStatus = 1U;
    localDW->is_DoorInSW = REL_IN_Initial_l;
    *rty_SO_b_DoorInSwSts = false;
    *rty_SO_b_DoorOutSwSts = rtu_SI_b_DoorOutSW;
    localDW->is_DoorHandSW = REL_IN_Initial_l;
    *rty_SO_b_DoorHandSwSts = false;
  } else {
    switch (localDW->is_DoorInSW) {
     case REL_IN_Initial_l:
      if ((localDW->SI_b_DoorInSW_prev != localDW->SI_b_DoorInSW_start) &&
          localDW->SI_b_DoorInSW_start && (!rtu_SI_b_ChildLckSts)) {
        localDW->is_DoorInSW = REL_IN_ONCE;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     case REL_IN_ONCE:
      if ((localDW->SI_b_DoorInSW_prev != localDW->SI_b_DoorInSW_start) &&
          localDW->SI_b_DoorInSW_start && (!rtu_SI_b_ChildLckSts)) {
        localDW->is_DoorInSW = REL_IN_TWICE;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_DoorInSwSts = true;
      } else if ((localDW->temporalCounter_i1 >= rtu_SI_e_DoublePressTime) ||
                 rtu_SI_b_ChildLckSts) {
        localDW->is_DoorInSW = REL_IN_Initial_l;
        *rty_SO_b_DoorInSwSts = false;
      }
      break;

     default:
      /* case IN_TWICE: */
      if (localDW->temporalCounter_i1 >= 3) {
        localDW->is_DoorInSW = REL_IN_Initial_l;
        *rty_SO_b_DoorInSwSts = false;
      }
      break;
    }

    *rty_SO_b_DoorOutSwSts = rtu_SI_b_DoorOutSW;
    switch (localDW->is_DoorHandSW) {
     case REL_IN_Initial_l:
      if ((localDW->SI_b_DoorHandSW_prev != localDW->SI_b_DoorHandSW_start) &&
          localDW->SI_b_DoorHandSW_start) {
        localDW->is_DoorHandSW = REL_IN_Press;
        localDW->temporalCounter_i2 = 0U;
      }
      break;

     case REL_IN_Press:
      if ((localDW->SI_b_DoorInSW_prev != localDW->SI_b_DoorInSW_start) &&
          (!localDW->SI_b_DoorInSW_start)) {
        localDW->is_DoorHandSW = REL_IN_Release;
        localDW->temporalCounter_i2 = 0U;
        *rty_SO_b_DoorHandSwSts = true;
      } else if (localDW->temporalCounter_i2 >= rtu_SI_e_SinglePressTime) {
        localDW->is_DoorHandSW = REL_IN_Initial_l;
        *rty_SO_b_DoorHandSwSts = false;
      }
      break;

     default:
      /* case IN_Release: */
      if (localDW->temporalCounter_i2 >= 3) {
        localDW->is_DoorHandSW = REL_IN_Initial_l;
        *rty_SO_b_DoorHandSwSts = false;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/FLSwitchStatus' */
}

/*
 * System initialize for atomic system:
 *    '<S3>/RLSwitchStatus'
 *    '<S3>/RRSwitchStatus'
 */
void REL_RLSwitchStatus_Init(boolean_T *rty_SO_b_DoorInSwSts, boolean_T
  *rty_SO_b_DoorOutSwSts, boolean_T *rty_SO_b_DoorHandSwSts)
{
  *rty_SO_b_DoorInSwSts = false;
  *rty_SO_b_DoorOutSwSts = false;
  *rty_SO_b_DoorHandSwSts = false;
}

/*
 * Output and update for atomic system:
 *    '<S3>/RLSwitchStatus'
 *    '<S3>/RRSwitchStatus'
 */
void REL_RLSwitchStatus(Boolean rtu_SI_b_DoorInSW, Boolean rtu_SI_b_DoorOutSW,
  Boolean rtu_SI_b_DoorHandSW, uint8_T rtu_SI_e_DoublePressTime, uint8_T
  rtu_SI_e_SinglePressTime, Boolean rtu_SI_b_ChildLckSts, boolean_T
  *rty_SO_b_DoorInSwSts, boolean_T *rty_SO_b_DoorOutSwSts, boolean_T
  *rty_SO_b_DoorHandSwSts, DW_RLSwitchStatus_REL_T *localDW)
{
  if (localDW->temporalCounter_i1 < 255U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->temporalCounter_i2 < 255U) {
    localDW->temporalCounter_i2++;
  }

  localDW->SI_b_DoorInSW_prev = localDW->SI_b_DoorInSW_start;
  localDW->SI_b_DoorInSW_start = rtu_SI_b_DoorInSW;
  localDW->SI_b_DoorHandSW_prev = localDW->SI_b_DoorHandSW_start;
  localDW->SI_b_DoorHandSW_start = rtu_SI_b_DoorHandSW;

  /* Chart: '<S3>/RLSwitchStatus' */
  if (localDW->is_active_c5_SwitchStatus == 0U) {
    localDW->SI_b_DoorInSW_prev = rtu_SI_b_DoorInSW;
    localDW->SI_b_DoorHandSW_prev = rtu_SI_b_DoorHandSW;
    localDW->is_active_c5_SwitchStatus = 1U;
    localDW->is_DoorInSW = REL_IN_Initial_p;
    *rty_SO_b_DoorInSwSts = false;
    *rty_SO_b_DoorOutSwSts = rtu_SI_b_DoorOutSW;
    localDW->is_DoorHandSW = REL_IN_Initial_p;
    *rty_SO_b_DoorHandSwSts = false;
  } else {
    switch (localDW->is_DoorInSW) {
     case REL_IN_Initial_p:
      if ((localDW->SI_b_DoorInSW_prev != localDW->SI_b_DoorInSW_start) &&
          localDW->SI_b_DoorInSW_start && (!rtu_SI_b_ChildLckSts)) {
        localDW->is_DoorInSW = REL_IN_ONCE_l;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     case REL_IN_ONCE_l:
      if ((localDW->SI_b_DoorInSW_prev != localDW->SI_b_DoorInSW_start) &&
          localDW->SI_b_DoorInSW_start && (!rtu_SI_b_ChildLckSts)) {
        localDW->is_DoorInSW = REL_IN_TWICE_h;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_DoorInSwSts = true;
      } else if ((localDW->temporalCounter_i1 >= rtu_SI_e_DoublePressTime) ||
                 rtu_SI_b_ChildLckSts) {
        localDW->is_DoorInSW = REL_IN_Initial_p;
        *rty_SO_b_DoorInSwSts = false;
      }
      break;

     default:
      /* case IN_TWICE: */
      if (localDW->temporalCounter_i1 >= 3) {
        localDW->is_DoorInSW = REL_IN_Initial_p;
        *rty_SO_b_DoorInSwSts = false;
      }
      break;
    }

    *rty_SO_b_DoorOutSwSts = rtu_SI_b_DoorOutSW;
    switch (localDW->is_DoorHandSW) {
     case REL_IN_Initial_p:
      if ((localDW->SI_b_DoorHandSW_prev != localDW->SI_b_DoorHandSW_start) &&
          localDW->SI_b_DoorHandSW_start) {
        localDW->is_DoorHandSW = REL_IN_Press_g;
        localDW->temporalCounter_i2 = 0U;
      }
      break;

     case REL_IN_Press_g:
      if ((localDW->SI_b_DoorInSW_prev != localDW->SI_b_DoorInSW_start) &&
          (!localDW->SI_b_DoorInSW_start)) {
        localDW->is_DoorHandSW = REL_IN_Release_g;
        localDW->temporalCounter_i2 = 0U;
        *rty_SO_b_DoorHandSwSts = true;
      } else if (localDW->temporalCounter_i2 >= rtu_SI_e_SinglePressTime) {
        localDW->is_DoorHandSW = REL_IN_Initial_p;
        *rty_SO_b_DoorHandSwSts = false;
      }
      break;

     default:
      /* case IN_Release: */
      if (localDW->temporalCounter_i2 >= 3) {
        localDW->is_DoorHandSW = REL_IN_Initial_p;
        *rty_SO_b_DoorHandSwSts = false;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/RLSwitchStatus' */
}

/* Function for Chart: '<S3>/DrvDoorUnlockAutoOpen' */
static void REL_InitialSet(void)
{
  /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' incorporates:
   *  Inport: '<Root>/VeINP_EPRM_BdcDrvrDoorLockSetSts_sig_VeINP_EPRM_BdcDrvrDoorLockSetSts_sig'
   */
  REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = (REL_U.VeINP_EPRM_BdcDrvrDoorLockSetSt
    == 1);
}

/* Model step function for TID1 */
void REL_Step(void)                    /* Explicit Task: REL_Step */
{
  boolean_T SO_b_DoorHandSwSts_e;
  boolean_T SO_b_DoorHandSwSts_p;
  boolean_T rtb_SO_b_DoorOutSwSts_l;

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/DrvDoorUnlockAutoOpen' incorporates:
   *  Inport: '<Root>/VeINP_CAN_CdcDrvrDoorLockSet_sig_VeINP_CAN_CdcDrvrDoorLockSet_sig'
   *  Inport: '<Root>/VeINP_EPRM_BdcDrvrDoorLockSetSts_sig_VeINP_EPRM_BdcDrvrDoorLockSetSts_sig'
   */
  if (REL_DW.temporalCounter_i1_c < 127U) {
    REL_DW.temporalCounter_i1_c++;
  }

  if (REL_DW.is_active_c1_REL == 0U) {
    REL_DW.is_active_c1_REL = 1U;
    REL_DW.is_c1_REL = REL_IN_Initial_m;
    REL_DW.temporalCounter_i1_c = 0U;
    REL_InitialSet();
  } else if (REL_DW.is_c1_REL == REL_IN_CFG_SETTING) {
    if (REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si == 1) {
      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = true;

      /* Outport: '<Root>/VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg_VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg' */
      REL_Y.VbOUT_REL_BcmAutoHeadLiSetStsTo = true;
    } else {
      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = false;

      /* Outport: '<Root>/VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg_VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg' */
      REL_Y.VbOUT_REL_BcmAutoHeadLiSetStsTo = false;
    }

    /* case IN_Initial: */
  } else if (REL_DW.temporalCounter_i1_c >= 100) {
    REL_DW.is_c1_REL = REL_IN_CFG_SETTING;
  }

  /* End of Chart: '<S3>/DrvDoorUnlockAutoOpen' */

  /* Outport: '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorOutButton_flg_VbINP_HWA_FLDoorOutButton_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_FLDoorOutButton_flg_VbINP_HWA_FLDoorOutButton_flg_read'
   */
  REL_Y.VbOUT_REL_BcmDrvrDoorHandleReq_ = REL_U.VbINP_HWA_FLDoorOutButton_flg_V;

  /* Chart: '<S3>/FLSwitchStatus' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant4'
   *  Constant: '<S3>/Constant5'
   *  Inport: '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg'
   *  Inport: '<Root>/VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg'
   *  Outport: '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg'
   */
  REL_FLSwitchStatus(REL_U.VbINP_HWA_FLDoorButton_flg_VbIN,
                     REL_Y.VbOUT_REL_BcmDrvrDoorHandleReq_,
                     REL_U.VbINP_HWA_FLDoorHandleSW_flg_Vb, 200, 100, false,
                     &REL_B.SO_b_DoorInSwSts_p, &rtb_SO_b_DoorOutSwSts_l,
                     &SO_b_DoorHandSwSts_p, &REL_DW.sf_FLSwitchStatus);

  /* Truth Table: '<S3>/FLDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V);

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   *  Inport: '<Root>/VeOUT_PDU_BcmPowerStatusFeedback_sig_VeOUT_PDU_BcmPowerStatusFeedback_sig'
   */
  rtb_SO_b_DoorOutSwSts_l = (REL_U.VeOUT_PDU_BcmPowerStatusFeedbac == 0);

  /* Chart: '<S3>/FLDoorRelease' incorporates:
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig'
   */
  REL_FLDoorRelease(rtb_SO_b_DoorOutSwSts_l,
                    REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                    REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN,
                    REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP,
                    REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si,
                    REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V,
                    REL_B.SO_b_DoorInSwSts_p,
                    REL_U.VbINP_CAN_CdcDrvrDoorButtonSts_,
                    REL_U.VbINP_CAN_CdcAllDoorOpenButtonS,
                    &REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU,
                    &REL_B.SO_b_UnlockReq_k, &REL_DW.sf_FLDoorRelease);

  /* Chart: '<S3>/FLDoorReleaseDriver' incorporates:
   *  Inport: '<Root>/VbINP_CAN_FLDCUCinchHomeSwitch_flg_VbINP_CAN_FLDCUCinchHomeSwitch_flg'
   *  Inport: '<Root>/VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg'
   *  Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig'
   */
  REL_FLDoorReleaseDriver(REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU,
    REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_, REL_U.VbINP_CAN_FLDCUCinchHomeSwitch_,
    REL_U.VbINP_CFG_ElectricalDoorCfg_flg,
    &REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU,
    &REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU,
    &REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve, &SO_b_DoorHandSwSts_p,
    &REL_DW.sf_FLDoorReleaseDriver);

  /* Outport: '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg_read'
   */
  REL_Y.VbOUT_REL_BcmPassDoorHandleReq_ = REL_U.VbINP_HWA_FRDoorOutButton_flg_V;

  /* Chart: '<S3>/FRSwitchStatus' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant5'
   *  Constant: '<S3>/Constant6'
   *  Inport: '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg'
   *  Inport: '<Root>/VbINP_HWA_FRDoorHandleSW_flg_VbINP_HWA_FRDoorHandleSW_flg'
   *  Outport: '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg'
   */
  REL_FLSwitchStatus(REL_U.VbINP_HWA_FRDoorButton_flg_VbIN,
                     REL_Y.VbOUT_REL_BcmPassDoorHandleReq_,
                     REL_U.VbINP_HWA_FRDoorHandleSW_flg_Vb, 200, 100, false,
                     &REL_B.SO_b_DoorInSwSts_j, &SO_b_DoorHandSwSts_p,
                     &SO_b_DoorHandSwSts_e, &REL_DW.sf_FRSwitchStatus);

  /* Truth Table: '<S3>/FRDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_FRDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V);

  /* Chart: '<S3>/FRDoorRelease' incorporates:
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig'
   */
  REL_FLDoorRelease(rtb_SO_b_DoorOutSwSts_l,
                    REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                    REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN,
                    REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP,
                    REL_U.VeOUT_DLK_BCMPassengerDoorLockS,
                    REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V,
                    REL_B.SO_b_DoorInSwSts_j,
                    REL_U.VbINP_CAN_CdcPassDoorButtonSts_,
                    REL_U.VbINP_CAN_CdcAllDoorOpenButtonS,
                    &REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU,
                    &REL_B.SO_b_UnlockReq_g, &REL_DW.sf_FRDoorRelease);

  /* Chart: '<S3>/FRDoorReleaseDriver' incorporates:
   *  Inport: '<Root>/VbINP_CAN_FRDCUCinchHomeSwitch_flg_VbINP_CAN_FRDCUCinchHomeSwitch_flg'
   *  Inport: '<Root>/VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg'
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   *  Outport: '<Root>/VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg'
   *  Outport: '<Root>/VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg'
   *  Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig'
   */
  REL_FLDoorReleaseDriver(REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU,
    REL_U.VbINP_HWA_FRDoorAjar_flg_VbINP_, REL_U.VbINP_CAN_FRDCUCinchHomeSwitch_,
    REL_U.VbINP_CFG_ElectricalDoorCfg_flg,
    &REL_Y.VbOUT_REL_FRDoorMotorA_flg_VbOU,
    &REL_Y.VbOUT_REL_FRDoorMotorB_flg_VbOU,
    &REL_Y.VeOUT_REL_FRDoorMotorSts_sig_Ve, &SO_b_DoorHandSwSts_p,
    &REL_DW.sf_FRDoorReleaseDriver);

  /* Chart: '<S3>/HandleButtonState' incorporates:
   *  Inport: '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg'
   */
  if (REL_DW.temporalCounter_i1 < 16383U) {
    REL_DW.temporalCounter_i1++;
  }

  SO_b_DoorHandSwSts_p = REL_DW.SI_b_CrashOutpSts_start;
  REL_DW.SI_b_CrashOutpSts_start = REL_U.VbOUT_SP_CrashOutpSts_flg_VbOUT;
  if (REL_DW.is_active_c24_REL == 0U) {
    REL_DW.is_active_c24_REL = 1U;
    REL_DW.is_c24_REL = REL_IN_Initial_i;

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
  } else if (REL_DW.is_c24_REL == REL_IN_Initial_i) {
    if ((SO_b_DoorHandSwSts_p != REL_DW.SI_b_CrashOutpSts_start) &&
        REL_DW.SI_b_CrashOutpSts_start) {
      REL_DW.is_c24_REL = REL_IN_ONCE_k;
      REL_DW.temporalCounter_i1 = 0U;

      /* Outport: '<Root>/VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg' */
      REL_Y.VbOUT_REL_FLDoorHndlBtnSig_flg_ = false;

      /* Outport: '<Root>/VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg' */
      REL_Y.VbOUT_REL_FRDoorHndlBtnSig_flg_ = false;

      /* Outport: '<Root>/VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg' */
      REL_Y.VbOUT_REL_RLDoorHndlBtnSig_flg_ = false;

      /* Outport: '<Root>/VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg' */
      REL_Y.VbOUT_REL_RRDoorHndlBtnSig_flg_ = false;
    } else {
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

    /* case IN_ONCE: */
  } else if (REL_DW.temporalCounter_i1 >= 10000) {
    REL_DW.is_c24_REL = REL_IN_Initial_i;

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

  /* End of Chart: '<S3>/HandleButtonState' */

  /* Outport: '<Root>/VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg_read'
   */
  REL_Y.VbOUT_REL_BcmLeReDoorHandleReq_ = REL_U.VbINP_HWA_RLDoorOutButton_flg_V;

  /* Chart: '<S3>/RLSwitchStatus' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant5'
   *  Inport: '<Root>/VbINP_HWA_LRChildLckSt_flg_VbINP_HWA_LRChildLckSt_flg'
   *  Inport: '<Root>/VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg'
   *  Inport: '<Root>/VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg'
   *  Outport: '<Root>/VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg'
   */
  REL_RLSwitchStatus(REL_U.VbINP_HWA_RLDoorButton_flg_VbIN,
                     REL_Y.VbOUT_REL_BcmLeReDoorHandleReq_,
                     REL_U.VbINP_HWA_RLDoorHandleSW_flg_Vb, 200, 100,
                     REL_U.VbINP_HWA_LRChildLckSt_flg_VbIN,
                     &REL_B.SO_b_DoorInSwSts_n, &SO_b_DoorHandSwSts_p,
                     &SO_b_DoorHandSwSts_e, &REL_DW.sf_RLSwitchStatus);

  /* Truth Table: '<S3>/RLDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLRDoorRatSts_sig_VeOUT_REL_BdcLRDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_RLDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcLRDoorRatSts_sig_V);

  /* Chart: '<S3>/RLDoorRelease' incorporates:
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcLeReDoorButtonSts_flg_VbINP_CAN_CdcLeReDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLRDoorRatSts_sig_VeOUT_REL_BdcLRDoorRatSts_sig'
   */
  REL_FLDoorRelease(rtb_SO_b_DoorOutSwSts_l,
                    REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                    REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN,
                    REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP,
                    REL_U.VeOUT_DLK_BCMPassengerDoorLockS,
                    REL_Y.VeOUT_REL_BdcLRDoorRatSts_sig_V,
                    REL_B.SO_b_DoorInSwSts_n,
                    REL_U.VbINP_CAN_CdcLeReDoorButtonSts_,
                    REL_U.VbINP_CAN_CdcAllDoorOpenButtonS,
                    &REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU,
                    &REL_B.SO_b_UnlockReq_d, &REL_DW.sf_RLDoorRelease);

  /* Outport: '<Root>/VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg_read'
   */
  REL_Y.VbOUT_REL_BcmBcmRiReDoorHandleR = REL_U.VbINP_HWA_RRDoorOutButton_flg_V;

  /* Chart: '<S3>/RRSwitchStatus' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant5'
   *  Inport: '<Root>/VbINP_HWA_RRChildLckSt_flg_VbINP_HWA_RRChildLckSt_flg'
   *  Inport: '<Root>/VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg'
   *  Inport: '<Root>/VbINP_HWA_RRDoorHandleSW_flg_VbINP_HWA_RRDoorHandleSW_flg'
   *  Outport: '<Root>/VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg'
   */
  REL_RLSwitchStatus(REL_U.VbINP_HWA_RRDoorButton_flg_VbIN,
                     REL_Y.VbOUT_REL_BcmBcmRiReDoorHandleR,
                     REL_U.VbINP_HWA_RRDoorHandleSW_flg_Vb, 200, 100,
                     REL_U.VbINP_HWA_RRChildLckSt_flg_VbIN,
                     &REL_B.SO_b_DoorInSwSts, &SO_b_DoorHandSwSts_p,
                     &SO_b_DoorHandSwSts_e, &REL_DW.sf_RRSwitchStatus);

  /* Truth Table: '<S3>/RRDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcRRDoorRatSts_sig_VeOUT_REL_BdcRRDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_RRDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcRRDoorRatSts_sig_V);

  /* Chart: '<S3>/RRDoorRelease' incorporates:
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcRiReDoorButtonSts_flg_VbINP_CAN_CdcRiReDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcRRDoorRatSts_sig_VeOUT_REL_BdcRRDoorRatSts_sig'
   */
  REL_FLDoorRelease(rtb_SO_b_DoorOutSwSts_l,
                    REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                    REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN,
                    REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP,
                    REL_U.VeOUT_DLK_BCMPassengerDoorLockS,
                    REL_Y.VeOUT_REL_BdcRRDoorRatSts_sig_V,
                    REL_B.SO_b_DoorInSwSts,
                    REL_U.VbINP_CAN_CdcRiReDoorButtonSts_,
                    REL_U.VbINP_CAN_CdcAllDoorOpenButtonS,
                    &REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU,
                    &REL_B.SO_b_UnlockReq, &REL_DW.sf_RRDoorRelease);

  /* Logic: '<S3>/Logical Operator' */
  rtb_SO_b_DoorOutSwSts_l = (REL_B.SO_b_UnlockReq_g || REL_B.SO_b_UnlockReq_d ||
    REL_B.SO_b_UnlockReq);

  /* Chart: '<S3>/RLDoorReleaseDriver' incorporates:
   *  Inport: '<Root>/VbINP_CAN_RLDCUCinchHomeSwitch_flg_VbINP_CAN_RLDCUCinchHomeSwitch_flg'
   *  Inport: '<Root>/VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg'
   *  Inport: '<Root>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig'
   */
  REL_FLDoorReleaseDriver(REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU,
    REL_U.VbINP_HWA_RLDoorAjar_flg_VbINP_, REL_U.VbINP_CAN_RLDCUCinchHomeSwitch_,
    REL_U.VbINP_CFG_ElectricalDoorCfg_flg,
    &REL_Y.VbOUT_REL_RLDoorMotorA_flg_VbOU,
    &REL_Y.VbOUT_REL_RLDoorMotorB_flg_VbOU,
    &REL_Y.VeOUT_REL_RLDoorMotorSts_sig_Ve, &SO_b_DoorHandSwSts_p,
    &REL_DW.sf_RLDoorReleaseDriver);

  /* Chart: '<S3>/RLDoorReleaseDriver1' incorporates:
   *  Inport: '<Root>/VbINP_CAN_RRDCUCinchHomeSwitch_flg_VbINP_CAN_RRDCUCinchHomeSwitch_flg'
   *  Inport: '<Root>/VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg'
   *  Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_RRDoorMotorSts_sig_VeOUT_REL_RRDoorMotorSts_sig'
   */
  REL_FLDoorReleaseDriver(REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU,
    REL_U.VbINP_HWA_RRDoorAjar_flg_VbINP_, REL_U.VbINP_CAN_RRDCUCinchHomeSwitch_,
    REL_U.VbINP_CFG_ElectricalDoorCfg_flg,
    &REL_Y.VbOUT_REL_RRDoorMotorA_flg_VbOU,
    &REL_Y.VbOUT_REL_RRDoorMotorB_flg_VbOU,
    &REL_Y.VeOUT_REL_RRDoorMotorSts_sig_Ve, &SO_b_DoorHandSwSts_p,
    &REL_DW.sf_RLDoorReleaseDriver1);

  /* Chart: '<S3>/Unlock_Request' */
  SO_b_DoorHandSwSts_p = REL_DW.SI_b_DrvUnlockReq_start;
  REL_DW.SI_b_DrvUnlockReq_start = REL_B.SO_b_UnlockReq_k;
  SO_b_DoorHandSwSts_e = REL_DW.SI_b_PassUnlockReq_start;
  REL_DW.SI_b_PassUnlockReq_start = rtb_SO_b_DoorOutSwSts_l;
  if (REL_DW.is_active_c6_REL == 0U) {
    REL_DW.is_active_c6_REL = 1U;
    REL_DW.is_c6_REL = REL_IN_Initial_i;

    /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
    REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 0U;
  } else if (REL_DW.is_c6_REL == REL_IN_Initial_i) {
    if (((SO_b_DoorHandSwSts_p != REL_DW.SI_b_DrvUnlockReq_start) &&
         REL_DW.SI_b_DrvUnlockReq_start) || ((SO_b_DoorHandSwSts_e !=
          REL_DW.SI_b_PassUnlockReq_start) && REL_DW.SI_b_PassUnlockReq_start))
    {
      REL_DW.is_c6_REL = REL_IN_REQ_SENT;
    }
  } else {
    /* case IN_REQ_SENT: */
    SO_b_DoorHandSwSts_p = !rtb_SO_b_DoorOutSwSts_l;
    SO_b_DoorHandSwSts_e = !REL_B.SO_b_UnlockReq_k;
    if (SO_b_DoorHandSwSts_e && SO_b_DoorHandSwSts_p) {
      REL_DW.is_c6_REL = REL_IN_Initial_i;

      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 0U;
    } else if (REL_B.SO_b_UnlockReq_k && rtb_SO_b_DoorOutSwSts_l) {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 3U;
    } else if (REL_B.SO_b_UnlockReq_k && SO_b_DoorHandSwSts_p) {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 1U;
    } else if (SO_b_DoorHandSwSts_e && rtb_SO_b_DoorOutSwSts_l) {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 2U;
    } else {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 0U;
    }
  }

  /* End of Chart: '<S3>/Unlock_Request' */

  /* Outport: '<Root>/VeOUT_REL_BcmPassDoorSwtSts_sig_VeOUT_REL_BcmPassDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Inport: '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg'
   */
  REL_Y.VeOUT_REL_BcmPassDoorSwtSts_sig = REL_U.VbINP_HWA_FRDoorButton_flg_VbIN;

  /* Outport: '<Root>/VeOUT_REL_BcmLeReDoorSwtSts_sig_VeOUT_REL_BcmLeReDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  Inport: '<Root>/VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg'
   */
  REL_Y.VeOUT_REL_BcmLeReDoorSwtSts_sig = REL_U.VbINP_HWA_RLDoorButton_flg_VbIN;

  /* Outport: '<Root>/VeOUT_REL_BcmRiReDoorSwtSts_sig_VeOUT_REL_BcmRiReDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  Inport: '<Root>/VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg'
   */
  REL_Y.VeOUT_REL_BcmRiReDoorSwtSts_sig = REL_U.VbINP_HWA_RRDoorButton_flg_VbIN;

  /* Outport: '<Root>/VeOUT_REL_BcmDrvrDoorSwtSts_sig_VeOUT_REL_BcmDrvrDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   *  Inport: '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg'
   */
  REL_Y.VeOUT_REL_BcmDrvrDoorSwtSts_sig = REL_U.VbINP_HWA_FLDoorButton_flg_VbIN;

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
    boolean_T SO_b_DoorHandSwSts_p;
    boolean_T SO_b_Error_d;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
     *  SubSystem: '<Root>/REL_Step_sys'
     */

    /* SystemInitialize for Chart: '<S3>/FLDoorRelease' incorporates:
     *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
     */
    REL_FLDoorRelease_Init(&REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU,
      &REL_B.SO_b_UnlockReq_k);

    /* SystemInitialize for Chart: '<S3>/FLDoorReleaseDriver' incorporates:
     *  Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg'
     *  Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg'
     *  Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig'
     */
    REL_FLDoorReleaseDriver_Init(&REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU,
      &REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU,
      &REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve, &SO_b_Error_d);

    /* SystemInitialize for Chart: '<S3>/FLSwitchStatus' */
    REL_FLSwitchStatus_Init(&REL_B.SO_b_DoorInSwSts_p, &SO_b_Error_d,
      &SO_b_DoorHandSwSts_p);

    /* SystemInitialize for Chart: '<S3>/FRDoorRelease' incorporates:
     *  Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg'
     */
    REL_FLDoorRelease_Init(&REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU,
      &REL_B.SO_b_UnlockReq_g);

    /* SystemInitialize for Chart: '<S3>/FRDoorReleaseDriver' incorporates:
     *  Outport: '<Root>/VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg'
     *  Outport: '<Root>/VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg'
     *  Outport: '<Root>/VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig'
     */
    REL_FLDoorReleaseDriver_Init(&REL_Y.VbOUT_REL_FRDoorMotorA_flg_VbOU,
      &REL_Y.VbOUT_REL_FRDoorMotorB_flg_VbOU,
      &REL_Y.VeOUT_REL_FRDoorMotorSts_sig_Ve, &SO_b_Error_d);

    /* SystemInitialize for Chart: '<S3>/FRSwitchStatus' */
    REL_FLSwitchStatus_Init(&REL_B.SO_b_DoorInSwSts_j, &SO_b_Error_d,
      &SO_b_DoorHandSwSts_p);

    /* SystemInitialize for Chart: '<S3>/RLDoorRelease' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg'
     */
    REL_FLDoorRelease_Init(&REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU,
      &REL_B.SO_b_UnlockReq_d);

    /* SystemInitialize for Chart: '<S3>/RLDoorReleaseDriver' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg'
     *  Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg'
     *  Outport: '<Root>/VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig'
     */
    REL_FLDoorReleaseDriver_Init(&REL_Y.VbOUT_REL_RLDoorMotorA_flg_VbOU,
      &REL_Y.VbOUT_REL_RLDoorMotorB_flg_VbOU,
      &REL_Y.VeOUT_REL_RLDoorMotorSts_sig_Ve, &SO_b_Error_d);

    /* SystemInitialize for Chart: '<S3>/RLDoorReleaseDriver1' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg'
     *  Outport: '<Root>/VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg'
     *  Outport: '<Root>/VeOUT_REL_RRDoorMotorSts_sig_VeOUT_REL_RRDoorMotorSts_sig'
     */
    REL_FLDoorReleaseDriver_Init(&REL_Y.VbOUT_REL_RRDoorMotorA_flg_VbOU,
      &REL_Y.VbOUT_REL_RRDoorMotorB_flg_VbOU,
      &REL_Y.VeOUT_REL_RRDoorMotorSts_sig_Ve, &SO_b_Error_d);

    /* SystemInitialize for Chart: '<S3>/RLSwitchStatus' */
    REL_RLSwitchStatus_Init(&REL_B.SO_b_DoorInSwSts_n, &SO_b_Error_d,
      &SO_b_DoorHandSwSts_p);

    /* SystemInitialize for Chart: '<S3>/RRDoorRelease' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg'
     */
    REL_FLDoorRelease_Init(&REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU,
      &REL_B.SO_b_UnlockReq);

    /* SystemInitialize for Chart: '<S3>/RRSwitchStatus' */
    REL_RLSwitchStatus_Init(&REL_B.SO_b_DoorInSwSts, &SO_b_Error_d,
      &SO_b_DoorHandSwSts_p);

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
