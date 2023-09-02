/*
 * File: REL.c
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Aug 28 16:23:44 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "REL.h"
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "REL_private.h"

/* Named constants for Chart: '<S3>/FLCenDoorRat' */
#define REL_IN_DOOR_LOCK               ((uint8)1U)
#define REL_IN_DOOR_UNLOCK             ((uint8)2U)
#define REL_IN_FAIL_UNLOCK             ((uint8)1U)
#define REL_IN_Initial                 ((uint8)1U)
#define REL_IN_NO_ACTIVE_CHILD         ((uint8)0U)
#define REL_IN_RELEASE                 ((uint8)3U)
#define REL_IN_REQ_UNLOCK              ((uint8)2U)
#define REL_IN_SUCESS_UNLOCK           ((uint8)3U)
#define REL_IN_TRIGGER                 ((uint8)2U)

/* Named constants for Chart: '<S3>/FLDoorReleaseDriver' */
#define REL_IN_CHECKING                ((uint8)1U)
#define REL_IN_ELECTRIC_DOOR           ((uint8)1U)
#define REL_IN_ERROR                   ((uint8)1U)
#define REL_IN_ERROR1                  ((uint8)2U)
#define REL_IN_ICE_BREAK               ((uint8)3U)
#define REL_IN_IDLE                    ((uint8)1U)
#define REL_IN_IDLE_f                  ((uint8)4U)
#define REL_IN_INITIAL                 ((uint8)2U)
#define REL_IN_LAST_CHECK              ((uint8)5U)
#define REL_IN_LAST_CHECK_a            ((uint8)2U)
#define REL_IN_NON_ELECTRIC_DOOR       ((uint8)2U)
#define REL_IN_NORMAL                  ((uint8)1U)
#define REL_IN_NO_ACTIVE_CHILD_e       ((uint8)0U)
#define REL_IN_RELEASE_i               ((uint8)2U)
#define REL_IN_RESET                   ((uint8)3U)
#define REL_IN_STARTUP_SETTING         ((uint8)2U)
#define REL_IN_STEP2_OPEN              ((uint8)4U)
#define REL_IN_WAITING                 ((uint8)6U)
#define REL_IN_WAITING_o               ((uint8)3U)

/* Named constants for Chart: '<S3>/DrvDoorUnlockAutoOpen' */
#define REL_IN_CFG_SETTING             ((uint8)1U)
#define REL_IN_Initial_m               ((uint8)2U)
#define REL_IN_NO_ACTIVE_CHILD_h       ((uint8)0U)

/* Named constants for Chart: '<S3>/FLElecDoorRat' */
#define REL_IN_Initial_a               ((uint8)1U)
#define REL_IN_RELEASE_a               ((uint8)2U)

/* Named constants for Chart: '<S3>/FLInnDoorRat' */
#define REL_IN_DOOR_LOCK_f             ((uint8)1U)
#define REL_IN_DOOR_UNLOCK_i           ((uint8)2U)
#define REL_IN_FAIL_UNLOCK_m           ((uint8)1U)
#define REL_IN_RELEASE_b               ((uint8)3U)
#define REL_IN_REQ_UNLOCK_g            ((uint8)2U)
#define REL_IN_SUCESS_UNLOCK_j         ((uint8)3U)
#define REL_IN_TRIGGER_g               ((uint8)2U)

/* Named constants for Chart: '<S3>/HandleButtonState' */
#define REL_IN_ONCE                    ((uint8)2U)

/* Named constants for Chart: '<S3>/InnerButtonDrv' */
#define REL_IN_TWICE                   ((uint8)3U)

/* Named constants for Chart: '<S3>/InnerButtonPass' */
#define REL_IN_IDLE_e                  ((uint8)1U)
#define REL_IN_SEND_OUT                ((uint8)2U)

/* Named constants for Chart: '<S3>/Request_DLK_Unlock' */
#define REL_IN_REQ_SENT                ((uint8)2U)

/* Block signals (default storage) */
B_REL_T REL_B;

/* Block states (default storage) */
DW_REL_T REL_DW;

/* Forward declaration for local functions */
static void REL_ELECTRIC_DOOR(Boolean rtu_SI_b_DoorOpenSts, Boolean
  rtu_SI_b_DCUCinchHomeSwt, boolean *rty_SO_b_MotorA, boolean *rty_SO_b_MotorB,
  uint8 *rty_SO_e_MotorMode, boolean *rty_SO_b_Error,
  DW_FLDoorReleaseDriver_REL_T *localDW);

/* Forward declaration for local functions */
static void REL_InitialSet(void);

/*
 * System initialize for atomic system:
 *    '<S3>/FLCenDoorRat'
 *    '<S3>/FRCenDoorRat'
 *    '<S3>/RLCenDoorRat'
 *    '<S3>/RRCenDoorRat'
 */
void REL_FLCenDoorRat_Init(boolean *rty_SO_b_DoorRatRelaseReq, boolean
  *rty_SO_DLKUnlockReq)
{
  *rty_SO_b_DoorRatRelaseReq = false;
  *rty_SO_DLKUnlockReq = false;
}

/*
 * Output and update for atomic system:
 *    '<S3>/FLCenDoorRat'
 *    '<S3>/FRCenDoorRat'
 *    '<S3>/RLCenDoorRat'
 *    '<S3>/RRCenDoorRat'
 */
void REL_FLCenDoorRat(boolean rtu_SI_b_OFF, UInt8 rtu_SI_e_DoorLockSts, UInt8
                      rtu_SI_e_EspVehSpd, Boolean rtu_SI_b_EspVehSpdVld, uint8
                      rtu_SI_e_DoorRatSts, UInt8 rtu_SI_e_VcuGearPosn, Boolean
                      rtu_SI_b_CdcDoorButtonSts, Boolean
                      rtu_SI_b_Cdc4DoorOpenButtonSts, boolean
                      *rty_SO_b_DoorRatRelaseReq, boolean *rty_SO_DLKUnlockReq,
                      DW_FLCenDoorRat_REL_T *localDW)
{
  if (localDW->temporalCounter_i1 < 127U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->temporalCounter_i2 < 127U) {
    localDW->temporalCounter_i2++;
  }

  localDW->SI_b_CdcDoorButtonSts_prev = localDW->SI_b_CdcDoorButtonSts_start;
  localDW->SI_b_CdcDoorButtonSts_start = rtu_SI_b_CdcDoorButtonSts;
  localDW->SI_b_Cdc4DoorOpenButtonSts_prev =
    localDW->SI_b_Cdc4DoorOpenButtonSts_star;
  localDW->SI_b_Cdc4DoorOpenButtonSts_star = rtu_SI_b_Cdc4DoorOpenButtonSts;
  localDW->SI_e_VcuGearPosn_prev = localDW->SI_e_VcuGearPosn_start;
  localDW->SI_e_VcuGearPosn_start = rtu_SI_e_VcuGearPosn;

  /* Chart: '<S3>/FLCenDoorRat' */
  if (localDW->is_active_c11_REL == 0U) {
    localDW->SI_b_CdcDoorButtonSts_prev = rtu_SI_b_CdcDoorButtonSts;
    localDW->SI_b_Cdc4DoorOpenButtonSts_prev = rtu_SI_b_Cdc4DoorOpenButtonSts;
    localDW->SI_e_VcuGearPosn_prev = rtu_SI_e_VcuGearPosn;
    localDW->is_active_c11_REL = 1U;
    localDW->is_c11_REL = REL_IN_Initial;
    *rty_SO_b_DoorRatRelaseReq = false;
    *rty_SO_DLKUnlockReq = false;
  } else if (localDW->is_c11_REL == REL_IN_Initial) {
    if ((!rtu_SI_b_OFF) && (rtu_SI_e_DoorRatSts != 3) && (((rtu_SI_e_EspVehSpd <=
           0) && (!rtu_SI_b_EspVehSpdVld)) || (rtu_SI_e_VcuGearPosn == 1)) &&
        (((localDW->SI_b_CdcDoorButtonSts_prev !=
           localDW->SI_b_CdcDoorButtonSts_start) &&
          localDW->SI_b_CdcDoorButtonSts_start) ||
         ((localDW->SI_b_Cdc4DoorOpenButtonSts_prev !=
           localDW->SI_b_Cdc4DoorOpenButtonSts_star) &&
          localDW->SI_b_Cdc4DoorOpenButtonSts_star))) {
      localDW->is_c11_REL = REL_IN_TRIGGER;
      localDW->temporalCounter_i2 = 0U;
      if (rtu_SI_e_DoorLockSts == 0) {
        localDW->is_TRIGGER = REL_IN_DOOR_LOCK;
        localDW->is_DOOR_LOCK = REL_IN_REQ_UNLOCK;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_DLKUnlockReq = true;
      } else {
        localDW->is_TRIGGER = REL_IN_DOOR_UNLOCK;
      }
    }

    /* case IN_TRIGGER: */
  } else if (((localDW->SI_e_VcuGearPosn_prev != localDW->SI_e_VcuGearPosn_start)
              && (localDW->SI_e_VcuGearPosn_prev == 1)) || ((rtu_SI_e_EspVehSpd >=
    5) && (!rtu_SI_b_EspVehSpdVld)) || ((localDW->temporalCounter_i2 >= 105) &&
              (rtu_SI_e_DoorLockSts == 0))) {
    localDW->is_DOOR_LOCK = REL_IN_NO_ACTIVE_CHILD;
    localDW->is_TRIGGER = REL_IN_NO_ACTIVE_CHILD;
    localDW->is_c11_REL = REL_IN_Initial;
    *rty_SO_b_DoorRatRelaseReq = false;
    *rty_SO_DLKUnlockReq = false;
  } else {
    switch (localDW->is_TRIGGER) {
     case REL_IN_DOOR_LOCK:
      if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
        localDW->is_DOOR_LOCK = REL_IN_NO_ACTIVE_CHILD;
        localDW->is_TRIGGER = REL_IN_RELEASE;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_DoorRatRelaseReq = true;
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
        *rty_SO_b_DoorRatRelaseReq = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (localDW->temporalCounter_i1 >= 5) {
        localDW->is_TRIGGER = REL_IN_NO_ACTIVE_CHILD;
        localDW->is_c11_REL = REL_IN_Initial;
        *rty_SO_b_DoorRatRelaseReq = false;
        *rty_SO_DLKUnlockReq = false;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/FLCenDoorRat' */
}

/*
 * Output and update for atomic system:
 *    '<S3>/FLDoorRatSts'
 *    '<S3>/FRDoorRatSts'
 *    '<S3>/RLDoorRatSts'
 *    '<S3>/RRDoorRatSts'
 */
void REL_FLDoorRatSts(Boolean rtu_SI_b_DoorAjarSwt, uint8 *rty_SO_e_DoorRatSts)
{
  Boolean aVarTruthTableCondition_1_tmp;
  boolean tmp;

  /*  Example condition 1 */
  aVarTruthTableCondition_1_tmp = !rtu_SI_b_DoorAjarSwt;

  /*  Example condition 2 */
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

/* Function for Chart: '<S3>/FLDoorReleaseDriver' */
static void REL_ELECTRIC_DOOR(Boolean rtu_SI_b_DoorOpenSts, Boolean
  rtu_SI_b_DCUCinchHomeSwt, boolean *rty_SO_b_MotorA, boolean *rty_SO_b_MotorB,
  uint8 *rty_SO_e_MotorMode, boolean *rty_SO_b_Error,
  DW_FLDoorReleaseDriver_REL_T *localDW)
{
  if (localDW->is_MAIN_PROGRESS == REL_IN_IDLE) {
    *rty_SO_e_MotorMode = 0U;
    if ((localDW->SI_b_DCUCinchHomeSwt_prev !=
         localDW->SI_b_DCUCinchHomeSwt_start) &&
        localDW->SI_b_DCUCinchHomeSwt_start) {
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
          sint32 tmp;
          localDW->is_RELEASE = REL_IN_CHECKING;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorMode = 0U;
          tmp = localDW->SL_e_CheckCycle + 1;
          if (localDW->SL_e_CheckCycle + 1 > 255) {
            tmp = 255;
          }

          localDW->SL_e_CheckCycle = (uint8)tmp;
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
            ((localDW->SI_b_DoorOpenSts_prev != localDW->SI_b_DoorOpenSts_start)
             && (!localDW->SI_b_DoorOpenSts_start))) {
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
                   ((localDW->SI_b_TriggerRelease_prev !=
                     localDW->SI_b_TriggerRelease_start) &&
                    localDW->SI_b_TriggerRelease_start)) {
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
void REL_FLDoorReleaseDriver_Init(boolean *rty_SO_b_MotorA, boolean
  *rty_SO_b_MotorB, uint8 *rty_SO_e_MotorMode, boolean *rty_SO_b_Error)
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
void REL_FLDoorReleaseDriver(boolean rtu_SI_b_TriggerRelease, Boolean
  rtu_SI_b_DoorOpenSts, Boolean rtu_SI_b_DCUCinchHomeSwt, Boolean
  rtu_SI_b_ElectricDoorCfg, boolean *rty_SO_b_MotorA, boolean *rty_SO_b_MotorB,
  uint8 *rty_SO_e_MotorMode, boolean *rty_SO_b_Error,
  DW_FLDoorReleaseDriver_REL_T *localDW)
{
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  localDW->SI_b_TriggerRelease_prev = localDW->SI_b_TriggerRelease_start;
  localDW->SI_b_TriggerRelease_start = rtu_SI_b_DoorOpenSts;
  localDW->SI_b_DoorOpenSts_prev = localDW->SI_b_DoorOpenSts_start;
  localDW->SI_b_DoorOpenSts_start = rtu_SI_b_DCUCinchHomeSwt;
  localDW->SI_b_DCUCinchHomeSwt_prev = localDW->SI_b_DCUCinchHomeSwt_start;
  localDW->SI_b_DCUCinchHomeSwt_start = rtu_SI_b_TriggerRelease;

  /* Chart: '<S3>/FLDoorReleaseDriver' */
  if (localDW->is_active_c19_REL == 0U) {
    localDW->SI_b_TriggerRelease_prev = rtu_SI_b_DoorOpenSts;
    localDW->SI_b_DoorOpenSts_prev = rtu_SI_b_DCUCinchHomeSwt;
    localDW->SI_b_DCUCinchHomeSwt_prev = rtu_SI_b_TriggerRelease;
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
      if ((localDW->SI_b_DCUCinchHomeSwt_prev !=
           localDW->SI_b_DCUCinchHomeSwt_start) &&
          localDW->SI_b_DCUCinchHomeSwt_start) {
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
            sint32 tmp;
            localDW->is_RELEASE_h = REL_IN_CHECKING;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = false;
            *rty_SO_e_MotorMode = 0U;
            tmp = localDW->SL_e_CheckCycle + 1;
            if (localDW->SL_e_CheckCycle + 1 > 255) {
              tmp = 255;
            }

            localDW->SL_e_CheckCycle = (uint8)tmp;
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
                     ((localDW->SI_b_TriggerRelease_prev !=
                       localDW->SI_b_TriggerRelease_start) &&
                      localDW->SI_b_TriggerRelease_start)) {
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

/* Function for Chart: '<S3>/DrvDoorUnlockAutoOpen' */
static void REL_InitialSet(void)
{
  UInt8 tmpRead;

  /* Inport: '<Root>/VeINP_EPRM_BdcDrvrDoorLockSetSts_sig_VeINP_EPRM_BdcDrvrDoorLockSetSts_sig' */
  (void)
    Rte_Read_VeINP_EPRM_BdcDrvrDoorLockSetSts_sig_VeINP_EPRM_BdcDrvrDoorLockSetSts_sig
    (&tmpRead);
  REL_B.SO_b_BdcDrvrDoorLockSetSts = (tmpRead == 1);
}

/* Model step function for TID1 */
void REL_Step(void)                    /* Explicit Task: REL_Step */
{
  /* local block i/o variables */
  UInt8 rtb_TmpSignalConversionAtVeOU_l;
  UInt8 rtb_TmpSignalConversionAtVeOU_i;
  UInt8 rtb_TmpSignalConversionAtVeINP_;
  UInt8 rtb_TmpSignalConversionAtVeOU_n;
  Boolean rtb_TmpSignalConversionAtVbINP_;
  Boolean rtb_TmpSignalConversionAtVbIN_f;
  UInt8 rtb_TmpSignalConversionAtVeOUT_;
  UInt8 tmpRead;
  UInt8 tmpRead_i;
  UInt8 tmpRead_j;
  UInt8 tmpRead_k;
  UInt8 tmpRead_l;
  Boolean rtb_TmpSignalConversionAtVbOUT_;
  Boolean tmpRead_0;
  Boolean tmpRead_1;
  Boolean tmpRead_2;
  Boolean tmpRead_3;
  Boolean tmpRead_4;
  Boolean tmpRead_5;
  Boolean tmpRead_6;
  Boolean tmpRead_7;
  Boolean tmpRead_8;
  Boolean tmpRead_9;
  Boolean tmpRead_a;
  Boolean tmpRead_b;
  Boolean tmpRead_c;
  Boolean tmpRead_d;
  Boolean tmpRead_e;
  Boolean tmpRead_f;
  Boolean tmpRead_g;
  Boolean tmpRead_h;
  boolean SO_b_Error;
  boolean SO_b_Error_d;
  boolean SO_b_Error_j;
  boolean rtb_Compare;
  boolean rtb_LogicalOperator5;

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
    (void)
      Rte_Read_VeINP_EPRM_BdcDrvrDoorLockSetSts_sig_VeINP_EPRM_BdcDrvrDoorLockSetSts_sig
      (&tmpRead);
    REL_DW.is_active_c1_REL = 1U;
    REL_DW.is_c1_REL = REL_IN_Initial_m;
    REL_DW.temporalCounter_i1_c = 0U;
    REL_InitialSet();
  } else if (REL_DW.is_c1_REL == REL_IN_CFG_SETTING) {
    (void)
      Rte_Read_VeINP_CAN_CdcDrvrDoorLockSet_sig_VeINP_CAN_CdcDrvrDoorLockSet_sig
      (&tmpRead);
    if (tmpRead == 1) {
      REL_B.SO_b_BdcDrvrDoorLockSetSts = true;
      REL_B.SO_b_E2BdcDrvrDoorLockSetSts = true;
    } else {
      REL_B.SO_b_BdcDrvrDoorLockSetSts = false;
      REL_B.SO_b_E2BdcDrvrDoorLockSetSts = false;
    }

    /* case IN_Initial: */
  } else if (REL_DW.temporalCounter_i1_c >= 100) {
    REL_DW.is_c1_REL = REL_IN_CFG_SETTING;
  }

  /* End of Chart: '<S3>/DrvDoorUnlockAutoOpen' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg' */
  (void)
    Rte_Read_VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg
    (&tmpRead_c);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* SignalConversion generated from: '<S2>/VeOUT_PDU_BcmPowerStatusFeedback_sig_VeOUT_PDU_BcmPowerStatusFeedback_sig_read' incorporates:
   *  Inport: '<Root>/VeOUT_PDU_BcmPowerStatusFeedback_sig_VeOUT_PDU_BcmPowerStatusFeedback_sig'
   */
  (void)
    Rte_Read_VeOUT_PDU_BcmPowerStatusFeedback_sig_VeOUT_PDU_BcmPowerStatusFeedback_sig
    (&rtb_TmpSignalConversionAtVeOUT_);

  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<S19>/Constant'
   */
  rtb_Compare = (rtb_TmpSignalConversionAtVeOUT_ == 0);

  /* SignalConversion generated from: '<S2>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig_read' incorporates:
   *  Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig'
   */
  (void)
    Rte_Read_VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig
    (&rtb_TmpSignalConversionAtVeOU_l);

  /* SignalConversion generated from: '<S2>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh_read' incorporates:
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   */
  (void)Rte_Read_VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh
    (&rtb_TmpSignalConversionAtVeOU_i);

  /* SignalConversion generated from: '<S2>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   */
  (void)Rte_Read_VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg
    (&rtb_TmpSignalConversionAtVbINP_);

  /* SignalConversion generated from: '<S2>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg'
   */
  (void)Rte_Read_VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg
    (&REL_B.TmpSignalConversionAtVbINP_HWA_);

  /* Truth Table: '<S3>/FLDoorRatSts' */
  REL_FLDoorRatSts(REL_B.TmpSignalConversionAtVbINP_HWA_,
                   &REL_B.SO_e_DoorRatSts_i);

  /* SignalConversion generated from: '<S2>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig_read' incorporates:
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   */
  (void)Rte_Read_VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig
    (&rtb_TmpSignalConversionAtVeINP_);

  /* SignalConversion generated from: '<S2>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   */
  (void)
    Rte_Read_VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg
    (&rtb_TmpSignalConversionAtVbIN_f);

  /* Chart: '<S3>/FLCenDoorRat' */
  REL_FLCenDoorRat(rtb_Compare, rtb_TmpSignalConversionAtVeOU_l,
                   rtb_TmpSignalConversionAtVeOU_i,
                   rtb_TmpSignalConversionAtVbINP_, REL_B.SO_e_DoorRatSts_i,
                   rtb_TmpSignalConversionAtVeINP_, tmpRead_c,
                   rtb_TmpSignalConversionAtVbIN_f,
                   &REL_B.SO_b_DoorRatRelaseReq_i, &REL_B.SO_DLKUnlockReq_d,
                   &REL_DW.sf_FLCenDoorRat);

  /* SignalConversion generated from: '<S2>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg_read' incorporates:
   *  Inport: '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg'
   */
  (void)Rte_Read_VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg
    (&rtb_TmpSignalConversionAtVbOUT_);

  /* Chart: '<S3>/InnerButtonState' */
  if (REL_DW.temporalCounter_i1 < 16383U) {
    REL_DW.temporalCounter_i1++;
  }

  REL_DW.SI_b_CrashOutpSts_prev = REL_DW.SI_b_CrashOutpSts_start;
  REL_DW.SI_b_CrashOutpSts_start = rtb_TmpSignalConversionAtVbOUT_;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg' */
  (void)Rte_Read_VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg
    (&SO_b_Error_d);

  /* Inport: '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg' */
  (void)Rte_Read_VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg
    (&tmpRead_0);

  /* Inport: '<Root>/VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg' */
  (void)Rte_Read_VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg
    (&tmpRead_1);

  /* Inport: '<Root>/VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg' */
  (void)Rte_Read_VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg
    (&tmpRead_2);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/InnerButtonState' */
  if (REL_DW.is_active_c23_REL == 0U) {
    REL_DW.SI_b_CrashOutpSts_prev = rtb_TmpSignalConversionAtVbOUT_;
    REL_DW.is_active_c23_REL = 1U;
    REL_DW.is_c23_REL = REL_IN_Initial_a;
    REL_B.SO_b_FLDoorInnerSwtSts = SO_b_Error_d;
    REL_B.SO_b_FRDoorInnerSwtSts = tmpRead_0;
    REL_B.SO_b_RLDoorInnerSwtSts = tmpRead_1;
    REL_B.SO_b_RRDoorInnerSwtSts = tmpRead_2;
  } else if (REL_DW.is_c23_REL == REL_IN_Initial_a) {
    if ((REL_DW.SI_b_CrashOutpSts_prev != REL_DW.SI_b_CrashOutpSts_start) &&
        REL_DW.SI_b_CrashOutpSts_start) {
      REL_DW.is_c23_REL = REL_IN_ONCE;
      REL_DW.temporalCounter_i1 = 0U;
      REL_B.SO_b_FLDoorInnerSwtSts = 0U;
      REL_B.SO_b_FRDoorInnerSwtSts = 0U;
      REL_B.SO_b_RLDoorInnerSwtSts = 0U;
      REL_B.SO_b_RRDoorInnerSwtSts = 0U;
    } else {
      REL_B.SO_b_FLDoorInnerSwtSts = SO_b_Error_d;
      REL_B.SO_b_FRDoorInnerSwtSts = tmpRead_0;
      REL_B.SO_b_RLDoorInnerSwtSts = tmpRead_1;
      REL_B.SO_b_RRDoorInnerSwtSts = tmpRead_2;
    }

    /* case IN_ONCE: */
  } else if (REL_DW.temporalCounter_i1 >= 10000) {
    REL_DW.is_c23_REL = REL_IN_Initial_a;
    REL_B.SO_b_FLDoorInnerSwtSts = SO_b_Error_d;
    REL_B.SO_b_FRDoorInnerSwtSts = tmpRead_0;
    REL_B.SO_b_RLDoorInnerSwtSts = tmpRead_1;
    REL_B.SO_b_RRDoorInnerSwtSts = tmpRead_2;
  }

  /* Chart: '<S3>/InnerButtonDrv' incorporates:
   *  Constant: '<S3>/Constant'
   */
  if (REL_DW.temporalCounter_i1_lm < 255U) {
    REL_DW.temporalCounter_i1_lm++;
  }

  REL_DW.SI_b_FLDoorButton_prev = REL_DW.SI_b_FLDoorButton_start;
  REL_DW.SI_b_FLDoorButton_start = REL_B.SO_b_FLDoorInnerSwtSts;
  if (REL_DW.is_active_c2_REL == 0U) {
    REL_DW.SI_b_FLDoorButton_prev = REL_B.SO_b_FLDoorInnerSwtSts;
    REL_DW.is_active_c2_REL = 1U;
    REL_DW.is_c2_REL = REL_IN_Initial_a;
    REL_B.SO_b_DoublePressSucc_e = false;
  } else {
    switch (REL_DW.is_c2_REL) {
     case REL_IN_Initial_a:
      if ((REL_DW.SI_b_FLDoorButton_prev != REL_DW.SI_b_FLDoorButton_start) &&
          (REL_DW.SI_b_FLDoorButton_start == 1)) {
        REL_DW.is_c2_REL = REL_IN_ONCE;
        REL_DW.temporalCounter_i1_lm = 0U;
      }
      break;

     case REL_IN_ONCE:
      if ((REL_DW.temporalCounter_i1_lm < 200) &&
          ((REL_DW.SI_b_FLDoorButton_prev != REL_DW.SI_b_FLDoorButton_start) &&
           (REL_DW.SI_b_FLDoorButton_start == 1))) {
        REL_DW.is_c2_REL = REL_IN_TWICE;
        REL_DW.temporalCounter_i1_lm = 0U;
        REL_B.SO_b_DoublePressSucc_e = true;
      } else if (REL_DW.temporalCounter_i1_lm >= 200) {
        REL_DW.is_c2_REL = REL_IN_Initial_a;
        REL_B.SO_b_DoublePressSucc_e = false;
      }
      break;

     default:
      /* case IN_TWICE: */
      if (REL_DW.temporalCounter_i1_lm >= 3) {
        REL_DW.is_c2_REL = REL_IN_Initial_a;
        REL_B.SO_b_DoublePressSucc_e = false;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/InnerButtonDrv' */

  /* Chart: '<S3>/FLInnDoorRat' */
  if (REL_DW.temporalCounter_i1_gl < 127U) {
    REL_DW.temporalCounter_i1_gl++;
  }

  if (REL_DW.temporalCounter_i2_f < 127U) {
    REL_DW.temporalCounter_i2_f++;
  }

  REL_DW.SI_b_DoublePressSucc_prev_h = REL_DW.SI_b_DoublePressSucc_start_j;
  REL_DW.SI_b_DoublePressSucc_start_j = REL_B.SO_b_DoublePressSucc_e;
  REL_DW.SI_e_VcuGearPosn_prev_o = REL_DW.SI_e_VcuGearPosn_start_e;
  REL_DW.SI_e_VcuGearPosn_start_e = rtb_TmpSignalConversionAtVeINP_;
  if (REL_DW.is_active_c13_REL == 0U) {
    REL_DW.SI_b_DoublePressSucc_prev_h = REL_B.SO_b_DoublePressSucc_e;
    REL_DW.SI_e_VcuGearPosn_prev_o = rtb_TmpSignalConversionAtVeINP_;
    REL_DW.is_active_c13_REL = 1U;
    REL_DW.is_c13_REL = REL_IN_Initial_a;
    REL_B.SO_b_DoorRatRelaseReq_e = false;
    REL_B.SO_DLKUnlockReq_ay = false;
  } else if (REL_DW.is_c13_REL == REL_IN_Initial_a) {
    if ((((rtb_TmpSignalConversionAtVeOU_i <= 0) &&
          (!rtb_TmpSignalConversionAtVbINP_)) ||
         (rtb_TmpSignalConversionAtVeINP_ == 1)) &&
        ((REL_DW.SI_b_DoublePressSucc_prev_h !=
          REL_DW.SI_b_DoublePressSucc_start_j) &&
         REL_DW.SI_b_DoublePressSucc_start_j)) {
      REL_DW.is_c13_REL = REL_IN_TRIGGER_g;
      REL_DW.temporalCounter_i2_f = 0U;
      if (rtb_TmpSignalConversionAtVeOU_l == 0) {
        REL_DW.is_TRIGGER_o = REL_IN_DOOR_LOCK_f;
        REL_DW.is_DOOR_LOCK_e = REL_IN_REQ_UNLOCK_g;
        REL_DW.temporalCounter_i1_gl = 0U;
        REL_B.SO_DLKUnlockReq_ay = true;
      } else {
        REL_DW.is_TRIGGER_o = REL_IN_DOOR_UNLOCK_i;
      }
    }

    /* case IN_TRIGGER: */
  } else if (((REL_DW.SI_e_VcuGearPosn_prev_o != REL_DW.SI_e_VcuGearPosn_start_e)
              && (REL_DW.SI_e_VcuGearPosn_prev_o == 1)) ||
             ((rtb_TmpSignalConversionAtVeOU_i >= 5) &&
              (!rtb_TmpSignalConversionAtVbINP_)) ||
             ((REL_DW.temporalCounter_i2_f >= 105) &&
              (rtb_TmpSignalConversionAtVeOU_l == 0)) ||
             ((rtb_TmpSignalConversionAtVeOU_l == 1) && (REL_B.SO_e_DoorRatSts_i
    == 3))) {
    REL_DW.is_DOOR_LOCK_e = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_TRIGGER_o = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_c13_REL = REL_IN_Initial_a;
    REL_B.SO_b_DoorRatRelaseReq_e = false;
    REL_B.SO_DLKUnlockReq_ay = false;
  } else {
    switch (REL_DW.is_TRIGGER_o) {
     case REL_IN_DOOR_LOCK_f:
      if ((rtb_TmpSignalConversionAtVeOU_l == 1) && (REL_B.SO_e_DoorRatSts_i !=
           3)) {
        REL_DW.is_DOOR_LOCK_e = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_TRIGGER_o = REL_IN_RELEASE_b;
        REL_DW.temporalCounter_i1_gl = 0U;
        REL_B.SO_b_DoorRatRelaseReq_e = true;
      } else {
        switch (REL_DW.is_DOOR_LOCK_e) {
         case REL_IN_FAIL_UNLOCK_m:
          break;

         case REL_IN_REQ_UNLOCK_g:
          if (rtb_TmpSignalConversionAtVeOU_l == 1) {
            REL_DW.is_DOOR_LOCK_e = REL_IN_SUCESS_UNLOCK_j;
          } else if ((REL_DW.temporalCounter_i1_gl >= 100) &&
                     (rtb_TmpSignalConversionAtVeOU_l == 0)) {
            REL_DW.is_DOOR_LOCK_e = REL_IN_FAIL_UNLOCK_m;
          }
          break;

         default:
          /* case IN_SUCESS_UNLOCK: */
          break;
        }
      }
      break;

     case REL_IN_DOOR_UNLOCK_i:
      if ((rtb_TmpSignalConversionAtVeOU_l == 1) && (REL_B.SO_e_DoorRatSts_i !=
           3)) {
        REL_DW.is_TRIGGER_o = REL_IN_RELEASE_b;
        REL_DW.temporalCounter_i1_gl = 0U;
        REL_B.SO_b_DoorRatRelaseReq_e = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i1_gl >= 5) {
        REL_DW.is_TRIGGER_o = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_c13_REL = REL_IN_Initial_a;
        REL_B.SO_b_DoorRatRelaseReq_e = false;
        REL_B.SO_DLKUnlockReq_ay = false;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/FLInnDoorRat' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VbINP_HWA_FLDoorOutButton_flg_VbINP_HWA_FLDoorOutButton_flg' */
  (void)Rte_Read_VbINP_HWA_FLDoorOutButton_flg_VbINP_HWA_FLDoorOutButton_flg
    (&tmpRead_5);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/FLElecDoorRat' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/VeOUT_DHM_BDCDrvrDoorHndSts_sig_VeOUT_DHM_BDCDrvrDoorHndSts_sig'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_FLDoorOutButton_flg_VbINP_HWA_FLDoorOutButton_flg_read'
   */
  if (REL_DW.temporalCounter_i1_b < 7U) {
    REL_DW.temporalCounter_i1_b++;
  }

  REL_DW.SI_b_DoorHandleSW_prev_ko = REL_DW.SI_b_DoorHandleSW_start_d;
  REL_DW.SI_b_DoorHandleSW_start_d = tmpRead_5;
  REL_DW.SI_e_BTDoorOpenReq_prev_e = REL_DW.SI_e_BTDoorOpenReq_start_d;
  REL_DW.SI_e_BTDoorOpenReq_start_d = 0U;
  if (REL_DW.is_active_c10_REL == 0U) {
    REL_DW.SI_b_DoorHandleSW_prev_ko = tmpRead_5;
    REL_DW.SI_e_BTDoorOpenReq_prev_e = 0U;
    REL_DW.is_active_c10_REL = 1U;
    REL_DW.is_c10_REL = REL_IN_Initial_a;
    REL_B.SO_b_DoorRatRelaseReq_k = false;
  } else if (REL_DW.is_c10_REL == REL_IN_Initial_a) {
    (void)
      Rte_Read_VeOUT_DHM_BDCDrvrDoorHndSts_sig_VeOUT_DHM_BDCDrvrDoorHndSts_sig
      (&tmpRead_i);
    if ((!rtb_Compare) && (rtb_TmpSignalConversionAtVeOU_l == 1) &&
        (REL_B.SO_e_DoorRatSts_i != 3) && (((rtb_TmpSignalConversionAtVeOU_i <=
           0) && (!rtb_TmpSignalConversionAtVbINP_)) ||
         (rtb_TmpSignalConversionAtVeINP_ == 1)) && ((tmpRead_i == 1) &&
         ((REL_DW.SI_b_DoorHandleSW_prev_ko != REL_DW.SI_b_DoorHandleSW_start_d)
          && REL_DW.SI_b_DoorHandleSW_start_d))) {
      REL_DW.is_c10_REL = REL_IN_RELEASE_a;
      REL_DW.temporalCounter_i1_b = 0U;
      REL_B.SO_b_DoorRatRelaseReq_k = true;
    }

    /* case IN_RELEASE: */
  } else if (REL_DW.temporalCounter_i1_b >= 5) {
    REL_DW.is_c10_REL = REL_IN_Initial_a;
    REL_B.SO_b_DoorRatRelaseReq_k = false;
  }

  /* End of Chart: '<S3>/FLElecDoorRat' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VbINP_CAN_FLDCUCinchHomeSwitch_flg_VbINP_CAN_FLDCUCinchHomeSwitch_flg' */
  (void)
    Rte_Read_VbINP_CAN_FLDCUCinchHomeSwitch_flg_VbINP_CAN_FLDCUCinchHomeSwitch_flg
    (&SO_b_Error_j);

  /* Inport: '<Root>/VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg' */
  (void)
    Rte_Read_VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg
    (&tmpRead_d);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Logic: '<S3>/Logical Operator2' */
  REL_B.LogicalOperator2 = (REL_B.SO_b_DoorRatRelaseReq_e ||
    REL_B.SO_b_DoorRatRelaseReq_k || REL_B.SO_b_DoorRatRelaseReq_i);

  /* SignalConversion generated from: '<S2>/VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg'
   */
  (void)Rte_Read_VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg
    (&REL_B.TmpSignalConversionAtVbINP_CFG_);

  /* Chart: '<S3>/FLDoorReleaseDriver' */
  REL_FLDoorReleaseDriver(REL_B.LogicalOperator2,
    REL_B.TmpSignalConversionAtVbINP_HWA_, SO_b_Error_j,
    REL_B.TmpSignalConversionAtVbINP_CFG_, &REL_B.SO_b_MotorA_m,
    &REL_B.SO_b_MotorB_d, &REL_B.SO_e_MotorMode_h, &SO_b_Error_d,
    &REL_DW.sf_FLDoorReleaseDriver);

  /* SignalConversion generated from: '<S2>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig_read' incorporates:
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   */
  (void)
    Rte_Read_VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig
    (&rtb_TmpSignalConversionAtVeOU_n);

  /* SignalConversion generated from: '<S2>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   */
  (void)Rte_Read_VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg
    (&REL_B.TmpSignalConversionAtVbINP_HW_g);

  /* Truth Table: '<S3>/FRDoorRatSts' */
  REL_FLDoorRatSts(REL_B.TmpSignalConversionAtVbINP_HW_g,
                   &REL_B.SO_e_DoorRatSts_d);

  /* Chart: '<S3>/FRCenDoorRat' */
  REL_FLCenDoorRat(rtb_Compare, rtb_TmpSignalConversionAtVeOU_n,
                   rtb_TmpSignalConversionAtVeOU_i,
                   rtb_TmpSignalConversionAtVbINP_, REL_B.SO_e_DoorRatSts_d,
                   rtb_TmpSignalConversionAtVeINP_, tmpRead_d,
                   rtb_TmpSignalConversionAtVbIN_f,
                   &REL_B.SO_b_DoorRatRelaseReq_o, &REL_B.SO_DLKUnlockReq_c,
                   &REL_DW.sf_FRCenDoorRat);

  /* Chart: '<S3>/InnerButtonPass' incorporates:
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/VbINP_HWA_LRChildLckSt_flg_VbINP_HWA_LRChildLckSt_flg'
   *  Inport: '<Root>/VbINP_HWA_RRChildLckSt_flg_VbINP_HWA_RRChildLckSt_flg'
   */
  if (REL_DW.temporalCounter_i1_j < 255U) {
    REL_DW.temporalCounter_i1_j++;
  }

  if (REL_DW.temporalCounter_i2_d < 255U) {
    REL_DW.temporalCounter_i2_d++;
  }

  if (REL_DW.temporalCounter_i3 < 255U) {
    REL_DW.temporalCounter_i3++;
  }

  REL_DW.SL_b_FRDoorInnerSwtSts_prev = REL_DW.SL_b_FRDoorInnerSwtSts_start;
  REL_DW.SL_b_FRDoorInnerSwtSts_start = REL_B.SO_b_FRDoorInnerSwtSts;
  REL_DW.SL_b_RLDoorInnerSwtSts_prev = REL_DW.SL_b_RLDoorInnerSwtSts_start;
  REL_DW.SL_b_RLDoorInnerSwtSts_start = REL_B.SO_b_RLDoorInnerSwtSts;
  REL_DW.SL_b_RRDoorInnerSwtSts_prev = REL_DW.SL_b_RRDoorInnerSwtSts_start;
  REL_DW.SL_b_RRDoorInnerSwtSts_start = REL_B.SO_b_RRDoorInnerSwtSts;
  if (REL_DW.is_active_c4_REL == 0U) {
    REL_DW.SL_b_FRDoorInnerSwtSts_prev = REL_B.SO_b_FRDoorInnerSwtSts;
    REL_DW.SL_b_RLDoorInnerSwtSts_prev = REL_B.SO_b_RLDoorInnerSwtSts;
    REL_DW.SL_b_RRDoorInnerSwtSts_prev = REL_B.SO_b_RRDoorInnerSwtSts;
    REL_DW.is_active_c4_REL = 1U;
    REL_DW.is_FR_BUTTON = REL_IN_Initial_a;
    REL_DW.SL_b_FRDBLPressSucc = false;
    REL_DW.is_RL_BUTTON = REL_IN_Initial_a;
    REL_DW.SL_b_RLDBLPressSucc = false;
    REL_DW.is_RR_BUTTON = REL_IN_Initial_a;
    REL_DW.SL_b_RRDBLPressSucc = false;
    REL_DW.is_OUTPUT = REL_IN_IDLE_e;
    REL_B.SO_b_DoublePressSucc = false;
  } else {
    switch (REL_DW.is_FR_BUTTON) {
     case REL_IN_Initial_a:
      if ((REL_DW.SL_b_FRDoorInnerSwtSts_prev !=
           REL_DW.SL_b_FRDoorInnerSwtSts_start) &&
          (REL_DW.SL_b_FRDoorInnerSwtSts_start == 1)) {
        REL_DW.is_FR_BUTTON = REL_IN_ONCE;
        REL_DW.temporalCounter_i1_j = 0U;
      }
      break;

     case REL_IN_ONCE:
      if ((REL_DW.temporalCounter_i1_j < 200) &&
          ((REL_DW.SL_b_FRDoorInnerSwtSts_prev !=
            REL_DW.SL_b_FRDoorInnerSwtSts_start) &&
           (REL_DW.SL_b_FRDoorInnerSwtSts_start == 1))) {
        REL_DW.is_FR_BUTTON = REL_IN_TWICE;
        REL_DW.temporalCounter_i1_j = 0U;
        REL_DW.SL_b_FRDBLPressSucc = true;
      } else if (REL_DW.temporalCounter_i1_j >= 200) {
        REL_DW.is_FR_BUTTON = REL_IN_Initial_a;
        REL_DW.SL_b_FRDBLPressSucc = false;
      }
      break;

     default:
      /* case IN_TWICE: */
      if (REL_DW.temporalCounter_i1_j >= 3) {
        REL_DW.is_FR_BUTTON = REL_IN_Initial_a;
        REL_DW.SL_b_FRDBLPressSucc = false;
      }
      break;
    }

    (void)Rte_Read_VbINP_HWA_LRChildLckSt_flg_VbINP_HWA_LRChildLckSt_flg
      (&tmpRead_3);
    switch (REL_DW.is_RL_BUTTON) {
     case REL_IN_Initial_a:
      if ((REL_DW.SL_b_RLDoorInnerSwtSts_prev !=
           REL_DW.SL_b_RLDoorInnerSwtSts_start) &&
          (REL_DW.SL_b_RLDoorInnerSwtSts_start == 1) && (!tmpRead_3)) {
        REL_DW.is_RL_BUTTON = REL_IN_ONCE;
        REL_DW.temporalCounter_i2_d = 0U;
      }
      break;

     case REL_IN_ONCE:
      SO_b_Error_j = !tmpRead_3;
      if ((REL_DW.temporalCounter_i2_d < 200) && SO_b_Error_j &&
          ((REL_DW.SL_b_RLDoorInnerSwtSts_prev !=
            REL_DW.SL_b_RLDoorInnerSwtSts_start) &&
           (REL_DW.SL_b_RLDoorInnerSwtSts_start == 1))) {
        REL_DW.is_RL_BUTTON = REL_IN_TWICE;
        REL_DW.temporalCounter_i2_d = 0U;
        REL_DW.SL_b_RLDBLPressSucc = true;
      } else if ((REL_DW.temporalCounter_i2_d >= 200) || SO_b_Error_j) {
        REL_DW.is_RL_BUTTON = REL_IN_Initial_a;
        REL_DW.SL_b_RLDBLPressSucc = false;
      }
      break;

     default:
      /* case IN_TWICE: */
      if (REL_DW.temporalCounter_i2_d >= 3) {
        REL_DW.is_RL_BUTTON = REL_IN_Initial_a;
        REL_DW.SL_b_RLDBLPressSucc = false;
      }
      break;
    }

    (void)Rte_Read_VbINP_HWA_RRChildLckSt_flg_VbINP_HWA_RRChildLckSt_flg
      (&tmpRead_4);
    switch (REL_DW.is_RR_BUTTON) {
     case REL_IN_Initial_a:
      if ((REL_DW.SL_b_RRDoorInnerSwtSts_prev !=
           REL_DW.SL_b_RRDoorInnerSwtSts_start) &&
          (REL_DW.SL_b_RRDoorInnerSwtSts_start == 1) && (!tmpRead_4)) {
        REL_DW.is_RR_BUTTON = REL_IN_ONCE;
        REL_DW.temporalCounter_i3 = 0U;
      }
      break;

     case REL_IN_ONCE:
      if ((REL_DW.temporalCounter_i3 < 200) && (!tmpRead_4) &&
          ((REL_DW.SL_b_RRDoorInnerSwtSts_prev !=
            REL_DW.SL_b_RRDoorInnerSwtSts_start) &&
           (REL_DW.SL_b_RRDoorInnerSwtSts_start == 1))) {
        REL_DW.is_RR_BUTTON = REL_IN_TWICE;
        REL_DW.temporalCounter_i3 = 0U;
        REL_DW.SL_b_RRDBLPressSucc = true;
      } else if ((REL_DW.temporalCounter_i3 >= 200) || tmpRead_4) {
        REL_DW.is_RR_BUTTON = REL_IN_Initial_a;
        REL_DW.SL_b_RRDBLPressSucc = false;
      }
      break;

     default:
      /* case IN_TWICE: */
      if (REL_DW.temporalCounter_i3 >= 3) {
        REL_DW.is_RR_BUTTON = REL_IN_Initial_a;
        REL_DW.SL_b_RRDBLPressSucc = false;
      }
      break;
    }

    if (REL_DW.is_OUTPUT == REL_IN_IDLE_e) {
      if (REL_DW.SL_b_FRDBLPressSucc || REL_DW.SL_b_RLDBLPressSucc ||
          REL_DW.SL_b_RRDBLPressSucc) {
        REL_DW.is_OUTPUT = REL_IN_SEND_OUT;
        REL_B.SO_b_DoublePressSucc = true;
      }

      /* case IN_SEND_OUT: */
    } else if ((!REL_DW.SL_b_FRDBLPressSucc) && (!REL_DW.SL_b_RLDBLPressSucc) &&
               (!REL_DW.SL_b_RRDBLPressSucc)) {
      REL_DW.is_OUTPUT = REL_IN_IDLE_e;
      REL_B.SO_b_DoublePressSucc = false;
    }
  }

  /* End of Chart: '<S3>/InnerButtonPass' */

  /* SignalConversion generated from: '<S2>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg'
   */
  (void)Rte_Read_VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg
    (&REL_B.TmpSignalConversionAtVbINP_H_gz);

  /* Truth Table: '<S3>/RRDoorRatSts' */
  REL_FLDoorRatSts(REL_B.TmpSignalConversionAtVbINP_H_gz, &REL_B.SO_e_DoorRatSts);

  /* SignalConversion generated from: '<S2>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg'
   */
  (void)Rte_Read_VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg
    (&REL_B.TmpSignalConversionAtVbINP_HW_f);

  /* Truth Table: '<S3>/RLDoorRatSts' */
  REL_FLDoorRatSts(REL_B.TmpSignalConversionAtVbINP_HW_f,
                   &REL_B.SO_e_DoorRatSts_g);

  /* Chart: '<S3>/PassInnDoorRat' */
  if (REL_DW.temporalCounter_i1_n < 127U) {
    REL_DW.temporalCounter_i1_n++;
  }

  if (REL_DW.temporalCounter_i2 < 127U) {
    REL_DW.temporalCounter_i2++;
  }

  REL_DW.SI_b_DoublePressSucc_prev = REL_DW.SI_b_DoublePressSucc_start;
  REL_DW.SI_b_DoublePressSucc_start = REL_B.SO_b_DoublePressSucc;
  REL_DW.SI_e_VcuGearPosn_prev = REL_DW.SI_e_VcuGearPosn_start;
  REL_DW.SI_e_VcuGearPosn_start = rtb_TmpSignalConversionAtVeINP_;
  if (REL_DW.is_active_c3_REL == 0U) {
    REL_DW.SI_b_DoublePressSucc_prev = REL_B.SO_b_DoublePressSucc;
    REL_DW.SI_e_VcuGearPosn_prev = rtb_TmpSignalConversionAtVeINP_;
    REL_DW.is_active_c3_REL = 1U;
    REL_DW.is_c3_REL = REL_IN_Initial_a;
    REL_B.SO_b_FRDoorRatReleaseReq = false;
    REL_B.SO_b_RLDoorRatReleaseReq = false;
    REL_B.SO_b_RRDoorRatReleaseReq = false;
    REL_B.SO_DLKUnlockReq_a = false;
  } else if (REL_DW.is_c3_REL == REL_IN_Initial_a) {
    if ((((rtb_TmpSignalConversionAtVeOU_i <= 0) &&
          (!rtb_TmpSignalConversionAtVbINP_)) ||
         (rtb_TmpSignalConversionAtVeINP_ == 1)) &&
        ((REL_DW.SI_b_DoublePressSucc_prev != REL_DW.SI_b_DoublePressSucc_start)
         && REL_DW.SI_b_DoublePressSucc_start)) {
      REL_DW.is_c3_REL = REL_IN_TRIGGER_g;
      REL_DW.temporalCounter_i2 = 0U;
      if (rtb_TmpSignalConversionAtVeOU_n == 0) {
        REL_DW.is_TRIGGER = REL_IN_DOOR_LOCK_f;
        REL_DW.is_DOOR_LOCK = REL_IN_REQ_UNLOCK_g;
        REL_DW.temporalCounter_i1_n = 0U;
        REL_B.SO_DLKUnlockReq_a = true;
      } else {
        REL_DW.is_TRIGGER = REL_IN_DOOR_UNLOCK_i;
      }
    }

    /* case IN_TRIGGER: */
  } else if (((REL_DW.SI_e_VcuGearPosn_prev != REL_DW.SI_e_VcuGearPosn_start) &&
              (REL_DW.SI_e_VcuGearPosn_prev == 1)) ||
             ((rtb_TmpSignalConversionAtVeOU_i >= 5) &&
              (!rtb_TmpSignalConversionAtVbINP_)) || ((REL_DW.temporalCounter_i2
    >= 105) && (rtb_TmpSignalConversionAtVeOU_n == 0)) ||
             ((rtb_TmpSignalConversionAtVeOU_n == 1) && (REL_B.SO_e_DoorRatSts_d
    == 3) && (REL_B.SO_e_DoorRatSts_g == 3) && (REL_B.SO_e_DoorRatSts == 3))) {
    REL_DW.is_DOOR_LOCK = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_TRIGGER = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_c3_REL = REL_IN_Initial_a;
    REL_B.SO_b_FRDoorRatReleaseReq = false;
    REL_B.SO_b_RLDoorRatReleaseReq = false;
    REL_B.SO_b_RRDoorRatReleaseReq = false;
    REL_B.SO_DLKUnlockReq_a = false;
  } else {
    switch (REL_DW.is_TRIGGER) {
     case REL_IN_DOOR_LOCK_f:
      if ((rtb_TmpSignalConversionAtVeOU_n == 1) && ((REL_B.SO_e_DoorRatSts_d !=
            3) || (REL_B.SO_e_DoorRatSts_g != 3) || (REL_B.SO_e_DoorRatSts != 3)))
      {
        REL_DW.is_DOOR_LOCK = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_TRIGGER = REL_IN_RELEASE_b;
        REL_DW.temporalCounter_i1_n = 0U;
        REL_B.SO_b_FRDoorRatReleaseReq = ((REL_B.SO_e_DoorRatSts_d != 3) ||
          REL_B.SO_b_FRDoorRatReleaseReq);
        REL_B.SO_b_RLDoorRatReleaseReq = ((REL_B.SO_e_DoorRatSts_g != 3) ||
          REL_B.SO_b_RLDoorRatReleaseReq);
        REL_B.SO_b_RRDoorRatReleaseReq = ((REL_B.SO_e_DoorRatSts != 3) ||
          REL_B.SO_b_RRDoorRatReleaseReq);
      } else {
        switch (REL_DW.is_DOOR_LOCK) {
         case REL_IN_FAIL_UNLOCK_m:
          break;

         case REL_IN_REQ_UNLOCK_g:
          if (rtb_TmpSignalConversionAtVeOU_n == 1) {
            REL_DW.is_DOOR_LOCK = REL_IN_SUCESS_UNLOCK_j;
          } else if ((REL_DW.temporalCounter_i1_n >= 100) &&
                     (rtb_TmpSignalConversionAtVeOU_n == 0)) {
            REL_DW.is_DOOR_LOCK = REL_IN_FAIL_UNLOCK_m;
          }
          break;

         default:
          /* case IN_SUCESS_UNLOCK: */
          break;
        }
      }
      break;

     case REL_IN_DOOR_UNLOCK_i:
      if ((rtb_TmpSignalConversionAtVeOU_n == 1) && ((REL_B.SO_e_DoorRatSts_d !=
            3) || (REL_B.SO_e_DoorRatSts_g != 3) || (REL_B.SO_e_DoorRatSts != 3)))
      {
        REL_DW.is_TRIGGER = REL_IN_RELEASE_b;
        REL_DW.temporalCounter_i1_n = 0U;
        REL_B.SO_b_FRDoorRatReleaseReq = ((REL_B.SO_e_DoorRatSts_d != 3) ||
          REL_B.SO_b_FRDoorRatReleaseReq);
        REL_B.SO_b_RLDoorRatReleaseReq = ((REL_B.SO_e_DoorRatSts_g != 3) ||
          REL_B.SO_b_RLDoorRatReleaseReq);
        REL_B.SO_b_RRDoorRatReleaseReq = ((REL_B.SO_e_DoorRatSts != 3) ||
          REL_B.SO_b_RRDoorRatReleaseReq);
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i1_n >= 5) {
        REL_DW.is_TRIGGER = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_c3_REL = REL_IN_Initial_a;
        REL_B.SO_b_FRDoorRatReleaseReq = false;
        REL_B.SO_b_RLDoorRatReleaseReq = false;
        REL_B.SO_b_RRDoorRatReleaseReq = false;
        REL_B.SO_DLKUnlockReq_a = false;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/PassInnDoorRat' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg' */
  (void)Rte_Read_VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg
    (&tmpRead_6);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/FRElecDoorRat' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/VeOUT_DHM_BDCPassDoorHndSts_sig_VeOUT_DHM_BDCPassDoorHndSts_sig'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg_read'
   */
  if (REL_DW.temporalCounter_i1_p < 7U) {
    REL_DW.temporalCounter_i1_p++;
  }

  REL_DW.SI_b_DoorHandleSW_prev_k = REL_DW.SI_b_DoorHandleSW_start_e;
  REL_DW.SI_b_DoorHandleSW_start_e = tmpRead_6;
  REL_DW.SI_e_BTDoorOpenReq_prev_g = REL_DW.SI_e_BTDoorOpenReq_start_j;
  REL_DW.SI_e_BTDoorOpenReq_start_j = 0U;
  if (REL_DW.is_active_c12_REL == 0U) {
    REL_DW.SI_b_DoorHandleSW_prev_k = tmpRead_6;
    REL_DW.SI_e_BTDoorOpenReq_prev_g = 0U;
    REL_DW.is_active_c12_REL = 1U;
    REL_DW.is_c12_REL = REL_IN_Initial_a;
    REL_B.SO_b_DoorRatRelaseReq_h = false;
  } else if (REL_DW.is_c12_REL == REL_IN_Initial_a) {
    (void)
      Rte_Read_VeOUT_DHM_BDCPassDoorHndSts_sig_VeOUT_DHM_BDCPassDoorHndSts_sig
      (&tmpRead_j);
    if ((!rtb_Compare) && (rtb_TmpSignalConversionAtVeOU_n == 1) &&
        (REL_B.SO_e_DoorRatSts_d != 3) && (((rtb_TmpSignalConversionAtVeOU_i <=
           0) && (!rtb_TmpSignalConversionAtVbINP_)) ||
         (rtb_TmpSignalConversionAtVeINP_ == 1)) && ((tmpRead_j == 1) &&
         ((REL_DW.SI_b_DoorHandleSW_prev_k != REL_DW.SI_b_DoorHandleSW_start_e) &&
          REL_DW.SI_b_DoorHandleSW_start_e))) {
      REL_DW.is_c12_REL = REL_IN_RELEASE_a;
      REL_DW.temporalCounter_i1_p = 0U;
      REL_B.SO_b_DoorRatRelaseReq_h = true;
    }

    /* case IN_RELEASE: */
  } else if (REL_DW.temporalCounter_i1_p >= 5) {
    REL_DW.is_c12_REL = REL_IN_Initial_a;
    REL_B.SO_b_DoorRatRelaseReq_h = false;
  }

  /* End of Chart: '<S3>/FRElecDoorRat' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VbINP_CAN_FRDCUCinchHomeSwitch_flg_VbINP_CAN_FRDCUCinchHomeSwitch_flg' */
  (void)
    Rte_Read_VbINP_CAN_FRDCUCinchHomeSwitch_flg_VbINP_CAN_FRDCUCinchHomeSwitch_flg
    (&tmpRead_g);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Logic: '<S3>/Logical Operator4' */
  REL_B.LogicalOperator4 = (REL_B.SO_b_FRDoorRatReleaseReq ||
    REL_B.SO_b_DoorRatRelaseReq_h || REL_B.SO_b_DoorRatRelaseReq_o);

  /* Chart: '<S3>/FRDoorReleaseDriver' */
  REL_FLDoorReleaseDriver(REL_B.LogicalOperator4,
    REL_B.TmpSignalConversionAtVbINP_HW_g, tmpRead_g,
    REL_B.TmpSignalConversionAtVbINP_CFG_, &REL_B.SO_b_MotorA_a,
    &REL_B.SO_b_MotorB_c, &REL_B.SO_e_MotorMode_m, &SO_b_Error_j,
    &REL_DW.sf_FRDoorReleaseDriver);

  /* Chart: '<S3>/HandleButtonState' */
  if (REL_DW.temporalCounter_i1_l < 16383U) {
    REL_DW.temporalCounter_i1_l++;
  }

  REL_DW.SI_b_CrashOutpSts_prev_d = REL_DW.SI_b_CrashOutpSts_start_f;
  REL_DW.SI_b_CrashOutpSts_start_f = rtb_TmpSignalConversionAtVbOUT_;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg' */
  (void)Rte_Read_VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg
    (&rtb_LogicalOperator5);

  /* Inport: '<Root>/VbINP_HWA_FRDoorHandleSW_flg_VbINP_HWA_FRDoorHandleSW_flg' */
  (void)Rte_Read_VbINP_HWA_FRDoorHandleSW_flg_VbINP_HWA_FRDoorHandleSW_flg
    (&tmpRead_9);

  /* Inport: '<Root>/VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg' */
  (void)Rte_Read_VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg
    (&tmpRead_a);

  /* Inport: '<Root>/VbINP_HWA_RRDoorHandleSW_flg_VbINP_HWA_RRDoorHandleSW_flg' */
  (void)Rte_Read_VbINP_HWA_RRDoorHandleSW_flg_VbINP_HWA_RRDoorHandleSW_flg
    (&tmpRead_b);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/HandleButtonState' */
  if (REL_DW.is_active_c24_REL == 0U) {
    REL_DW.SI_b_CrashOutpSts_prev_d = rtb_TmpSignalConversionAtVbOUT_;
    REL_DW.is_active_c24_REL = 1U;
    REL_DW.is_c24_REL = REL_IN_Initial_a;
    REL_B.SO_b_FLDoorInnerSwtSts_p = rtb_LogicalOperator5;
    REL_B.SO_b_FRDoorInnerSwtSts_j = tmpRead_9;
    REL_B.SO_b_RLDoorInnerSwtSts_p = tmpRead_a;
    REL_B.SO_b_RRDoorInnerSwtSts_b = tmpRead_b;
  } else if (REL_DW.is_c24_REL == REL_IN_Initial_a) {
    if ((REL_DW.SI_b_CrashOutpSts_prev_d != REL_DW.SI_b_CrashOutpSts_start_f) &&
        REL_DW.SI_b_CrashOutpSts_start_f) {
      REL_DW.is_c24_REL = REL_IN_ONCE;
      REL_DW.temporalCounter_i1_l = 0U;
      REL_B.SO_b_FLDoorInnerSwtSts_p = false;
      REL_B.SO_b_FRDoorInnerSwtSts_j = false;
      REL_B.SO_b_RLDoorInnerSwtSts_p = false;
      REL_B.SO_b_RRDoorInnerSwtSts_b = false;
    } else {
      REL_B.SO_b_FLDoorInnerSwtSts_p = rtb_LogicalOperator5;
      REL_B.SO_b_FRDoorInnerSwtSts_j = tmpRead_9;
      REL_B.SO_b_RLDoorInnerSwtSts_p = tmpRead_a;
      REL_B.SO_b_RRDoorInnerSwtSts_b = tmpRead_b;
    }

    /* case IN_ONCE: */
  } else if (REL_DW.temporalCounter_i1_l >= 10000) {
    REL_DW.is_c24_REL = REL_IN_Initial_a;
    REL_B.SO_b_FLDoorInnerSwtSts_p = rtb_LogicalOperator5;
    REL_B.SO_b_FRDoorInnerSwtSts_j = tmpRead_9;
    REL_B.SO_b_RLDoorInnerSwtSts_p = tmpRead_a;
    REL_B.SO_b_RRDoorInnerSwtSts_b = tmpRead_b;
  }

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VbINP_CAN_CdcRiReDoorButtonSts_flg_VbINP_CAN_CdcRiReDoorButtonSts_flg' */
  (void)
    Rte_Read_VbINP_CAN_CdcRiReDoorButtonSts_flg_VbINP_CAN_CdcRiReDoorButtonSts_flg
    (&tmpRead_f);

  /* Inport: '<Root>/VbINP_CAN_CdcLeReDoorButtonSts_flg_VbINP_CAN_CdcLeReDoorButtonSts_flg' */
  (void)
    Rte_Read_VbINP_CAN_CdcLeReDoorButtonSts_flg_VbINP_CAN_CdcLeReDoorButtonSts_flg
    (&tmpRead_e);

  /* Inport: '<Root>/VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg' */
  (void)Rte_Read_VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg
    (&tmpRead_7);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/RLCenDoorRat' */
  REL_FLCenDoorRat(rtb_Compare, rtb_TmpSignalConversionAtVeOU_n,
                   rtb_TmpSignalConversionAtVeOU_i,
                   rtb_TmpSignalConversionAtVbINP_, REL_B.SO_e_DoorRatSts_g,
                   rtb_TmpSignalConversionAtVeINP_, tmpRead_e,
                   rtb_TmpSignalConversionAtVbIN_f,
                   &REL_B.SO_b_DoorRatRelaseReq_b, &REL_B.SO_DLKUnlockReq_h,
                   &REL_DW.sf_RLCenDoorRat);

  /* Chart: '<S3>/RRCenDoorRat' */
  REL_FLCenDoorRat(rtb_Compare, rtb_TmpSignalConversionAtVeOU_n,
                   rtb_TmpSignalConversionAtVeOU_i,
                   rtb_TmpSignalConversionAtVbINP_, REL_B.SO_e_DoorRatSts_g,
                   rtb_TmpSignalConversionAtVeINP_, tmpRead_f,
                   rtb_TmpSignalConversionAtVbIN_f,
                   &REL_B.SO_b_DoorRatRelaseReq_m, &REL_B.SO_DLKUnlockReq,
                   &REL_DW.sf_RRCenDoorRat);

  /* Logic: '<S3>/Logical Operator1' */
  rtb_TmpSignalConversionAtVbOUT_ = (REL_B.SO_DLKUnlockReq_a ||
    REL_B.SO_DLKUnlockReq_c || REL_B.SO_DLKUnlockReq_h || REL_B.SO_DLKUnlockReq);

  /* Logic: '<S3>/Logical Operator5' */
  rtb_LogicalOperator5 = (REL_B.SO_DLKUnlockReq_ay || REL_B.SO_DLKUnlockReq_d);

  /* Chart: '<S3>/RLElecDoorRat' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/VeOUT_DHM_BDCLeReDoorHndSts_sig_VeOUT_DHM_BDCLeReDoorHndSts_sig'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg_read'
   */
  if (REL_DW.temporalCounter_i1_d < 7U) {
    REL_DW.temporalCounter_i1_d++;
  }

  REL_DW.SI_b_DoorHandleSW_prev_j = REL_DW.SI_b_DoorHandleSW_start_j;
  REL_DW.SI_b_DoorHandleSW_start_j = tmpRead_7;
  REL_DW.SI_e_BTDoorOpenReq_prev_a = REL_DW.SI_e_BTDoorOpenReq_start_e;
  REL_DW.SI_e_BTDoorOpenReq_start_e = 0U;
  if (REL_DW.is_active_c15_REL == 0U) {
    REL_DW.SI_b_DoorHandleSW_prev_j = tmpRead_7;
    REL_DW.SI_e_BTDoorOpenReq_prev_a = 0U;
    REL_DW.is_active_c15_REL = 1U;
    REL_DW.is_c15_REL = REL_IN_Initial_a;
    REL_B.SO_b_DoorRatRelaseReq_f = false;
  } else if (REL_DW.is_c15_REL == REL_IN_Initial_a) {
    (void)
      Rte_Read_VeOUT_DHM_BDCLeReDoorHndSts_sig_VeOUT_DHM_BDCLeReDoorHndSts_sig
      (&tmpRead_k);
    if ((!rtb_Compare) && (rtb_TmpSignalConversionAtVeOU_n == 1) &&
        (REL_B.SO_e_DoorRatSts_g != 3) && (((rtb_TmpSignalConversionAtVeOU_i <=
           0) && (!rtb_TmpSignalConversionAtVbINP_)) ||
         (rtb_TmpSignalConversionAtVeINP_ == 1)) && ((tmpRead_k == 1) &&
         ((REL_DW.SI_b_DoorHandleSW_prev_j != REL_DW.SI_b_DoorHandleSW_start_j) &&
          REL_DW.SI_b_DoorHandleSW_start_j))) {
      REL_DW.is_c15_REL = REL_IN_RELEASE_a;
      REL_DW.temporalCounter_i1_d = 0U;
      REL_B.SO_b_DoorRatRelaseReq_f = true;
    }

    /* case IN_RELEASE: */
  } else if (REL_DW.temporalCounter_i1_d >= 5) {
    REL_DW.is_c15_REL = REL_IN_Initial_a;
    REL_B.SO_b_DoorRatRelaseReq_f = false;
  }

  /* End of Chart: '<S3>/RLElecDoorRat' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg' */
  (void)Rte_Read_VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg
    (&tmpRead_8);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/RRElecDoorRat' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/VeOUT_DHM_BDCRiReDoorHndSts_sig_VeOUT_DHM_BDCRiReDoorHndSts_sig'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg_read'
   */
  if (REL_DW.temporalCounter_i1_g < 7U) {
    REL_DW.temporalCounter_i1_g++;
  }

  REL_DW.SI_b_DoorHandleSW_prev = REL_DW.SI_b_DoorHandleSW_start;
  REL_DW.SI_b_DoorHandleSW_start = tmpRead_8;
  REL_DW.SI_e_BTDoorOpenReq_prev = REL_DW.SI_e_BTDoorOpenReq_start;
  REL_DW.SI_e_BTDoorOpenReq_start = 0U;
  if (REL_DW.is_active_c17_REL == 0U) {
    REL_DW.SI_b_DoorHandleSW_prev = tmpRead_8;
    REL_DW.SI_e_BTDoorOpenReq_prev = 0U;
    REL_DW.is_active_c17_REL = 1U;
    REL_DW.is_c17_REL = REL_IN_Initial_a;
    REL_B.SO_b_DoorRatRelaseReq = false;
  } else if (REL_DW.is_c17_REL == REL_IN_Initial_a) {
    (void)
      Rte_Read_VeOUT_DHM_BDCRiReDoorHndSts_sig_VeOUT_DHM_BDCRiReDoorHndSts_sig
      (&tmpRead_l);
    if ((!rtb_Compare) && (rtb_TmpSignalConversionAtVeOU_n == 1) &&
        (REL_B.SO_e_DoorRatSts != 3) && (((rtb_TmpSignalConversionAtVeOU_i <= 0)
          && (!rtb_TmpSignalConversionAtVbINP_)) ||
         (rtb_TmpSignalConversionAtVeINP_ == 1)) && ((tmpRead_l == 1) &&
         ((REL_DW.SI_b_DoorHandleSW_prev != REL_DW.SI_b_DoorHandleSW_start) &&
          REL_DW.SI_b_DoorHandleSW_start))) {
      REL_DW.is_c17_REL = REL_IN_RELEASE_a;
      REL_DW.temporalCounter_i1_g = 0U;
      REL_B.SO_b_DoorRatRelaseReq = true;
    }

    /* case IN_RELEASE: */
  } else if (REL_DW.temporalCounter_i1_g >= 5) {
    REL_DW.is_c17_REL = REL_IN_Initial_a;
    REL_B.SO_b_DoorRatRelaseReq = false;
  }

  /* End of Chart: '<S3>/RRElecDoorRat' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VbINP_CAN_RRDCUCinchHomeSwitch_flg_VbINP_CAN_RRDCUCinchHomeSwitch_flg' */
  (void)
    Rte_Read_VbINP_CAN_RRDCUCinchHomeSwitch_flg_VbINP_CAN_RRDCUCinchHomeSwitch_flg
    (&tmpRead_h);

  /* Inport: '<Root>/VbINP_CAN_RLDCUCinchHomeSwitch_flg_VbINP_CAN_RLDCUCinchHomeSwitch_flg' */
  (void)
    Rte_Read_VbINP_CAN_RLDCUCinchHomeSwitch_flg_VbINP_CAN_RLDCUCinchHomeSwitch_flg
    (&SO_b_Error);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Logic: '<S3>/Logical Operator7' */
  REL_B.LogicalOperator7 = (REL_B.SO_b_RRDoorRatReleaseReq ||
    REL_B.SO_b_DoorRatRelaseReq || REL_B.SO_b_DoorRatRelaseReq_m);

  /* Logic: '<S3>/Logical Operator6' */
  REL_B.LogicalOperator6 = (REL_B.SO_b_RLDoorRatReleaseReq ||
    REL_B.SO_b_DoorRatRelaseReq_f || REL_B.SO_b_DoorRatRelaseReq_b);

  /* Chart: '<S3>/RLDoorReleaseDriver' */
  REL_FLDoorReleaseDriver(REL_B.LogicalOperator6,
    REL_B.TmpSignalConversionAtVbINP_HW_f, SO_b_Error,
    REL_B.TmpSignalConversionAtVbINP_CFG_, &REL_B.SO_b_MotorA_e,
    &REL_B.SO_b_MotorB_p, &REL_B.SO_e_MotorMode_e, &rtb_Compare,
    &REL_DW.sf_RLDoorReleaseDriver);

  /* Chart: '<S3>/RLDoorReleaseDriver1' */
  REL_FLDoorReleaseDriver(REL_B.LogicalOperator7,
    REL_B.TmpSignalConversionAtVbINP_H_gz, tmpRead_h,
    REL_B.TmpSignalConversionAtVbINP_CFG_, &REL_B.SO_b_MotorA,
    &REL_B.SO_b_MotorB, &REL_B.SO_e_MotorMode, &SO_b_Error,
    &REL_DW.sf_RLDoorReleaseDriver1);

  /* Chart: '<S3>/Request_DLK_Unlock' */
  REL_DW.SL_DLKDrvUnlockReq_prev = REL_DW.SL_DLKDrvUnlockReq_start;
  REL_DW.SL_DLKDrvUnlockReq_start = rtb_LogicalOperator5;
  REL_DW.SL_DLKPassUnlockReq_prev = REL_DW.SL_DLKPassUnlockReq_start;
  REL_DW.SL_DLKPassUnlockReq_start = rtb_TmpSignalConversionAtVbOUT_;
  if (REL_DW.is_active_c9_REL == 0U) {
    REL_DW.SL_DLKDrvUnlockReq_prev = rtb_LogicalOperator5;
    REL_DW.SL_DLKPassUnlockReq_prev = rtb_TmpSignalConversionAtVbOUT_;
    REL_DW.is_active_c9_REL = 1U;
    REL_DW.is_c9_REL = REL_IN_Initial_a;
    REL_B.SO_e_DLKUnlockReq = 0U;
  } else if (REL_DW.is_c9_REL == REL_IN_Initial_a) {
    if (((REL_DW.SL_DLKDrvUnlockReq_prev != REL_DW.SL_DLKDrvUnlockReq_start) &&
         REL_DW.SL_DLKDrvUnlockReq_start) || ((REL_DW.SL_DLKPassUnlockReq_prev
          != REL_DW.SL_DLKPassUnlockReq_start) &&
         REL_DW.SL_DLKPassUnlockReq_start)) {
      REL_DW.is_c9_REL = REL_IN_REQ_SENT;
    }
  } else {
    /* case IN_REQ_SENT: */
    SO_b_Error_j = !rtb_TmpSignalConversionAtVbOUT_;
    tmpRead_h = !rtb_LogicalOperator5;
    if (tmpRead_h && SO_b_Error_j) {
      REL_DW.is_c9_REL = REL_IN_Initial_a;
      REL_B.SO_e_DLKUnlockReq = 0U;
    } else if (rtb_LogicalOperator5 && rtb_TmpSignalConversionAtVbOUT_) {
      REL_B.SO_e_DLKUnlockReq = 3U;
    } else if (rtb_LogicalOperator5 && SO_b_Error_j) {
      REL_B.SO_e_DLKUnlockReq = 1U;
    } else if (tmpRead_h && rtb_TmpSignalConversionAtVbOUT_) {
      REL_B.SO_e_DLKUnlockReq = 2U;
    } else {
      REL_B.SO_e_DLKUnlockReq = 0U;
    }
  }

  /* End of Chart: '<S3>/Request_DLK_Unlock' */

  /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockOpenReq_flg_VbOUT_REL_BdcDrvrDoorLockOpenReq_flg' incorporates:
   *  Constant: '<S3>/Constant3'
   */
  (void)
    Rte_Write_VbOUT_REL_BdcDrvrDoorLockOpenReq_flg_VbOUT_REL_BdcDrvrDoorLockOpenReq_flg
    (false);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
  (void)
    Rte_Write_VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg
    (REL_B.SO_b_BdcDrvrDoorLockSetSts);

  /* Outport: '<Root>/VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg_VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg' */
  (void)
    Rte_Write_VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg_VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg
    (REL_B.SO_b_E2BdcDrvrDoorLockSetSts);

  /* Outport: '<Root>/VeOUT_REL_BcmDrvrDoorSwtSts_sig_VeOUT_REL_BcmDrvrDoorSwtSts_sig' */
  (void)
    Rte_Write_VeOUT_REL_BcmDrvrDoorSwtSts_sig_VeOUT_REL_BcmDrvrDoorSwtSts_sig
    (REL_B.SO_b_FLDoorInnerSwtSts);

  /* Outport: '<Root>/VeOUT_REL_BcmPassDoorSwtSts_sig_VeOUT_REL_BcmPassDoorSwtSts_sig' */
  (void)
    Rte_Write_VeOUT_REL_BcmPassDoorSwtSts_sig_VeOUT_REL_BcmPassDoorSwtSts_sig
    (REL_B.SO_b_FRDoorInnerSwtSts);

  /* Outport: '<Root>/VeOUT_REL_BcmLeReDoorSwtSts_sig_VeOUT_REL_BcmLeReDoorSwtSts_sig' */
  (void)
    Rte_Write_VeOUT_REL_BcmLeReDoorSwtSts_sig_VeOUT_REL_BcmLeReDoorSwtSts_sig
    (REL_B.SO_b_RLDoorInnerSwtSts);

  /* Outport: '<Root>/VeOUT_REL_BcmRiReDoorSwtSts_sig_VeOUT_REL_BcmRiReDoorSwtSts_sig' */
  (void)
    Rte_Write_VeOUT_REL_BcmRiReDoorSwtSts_sig_VeOUT_REL_BcmRiReDoorSwtSts_sig
    (REL_B.SO_b_RRDoorInnerSwtSts);

  /* Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig' */
  (void)Rte_Write_VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig
    (REL_B.SO_e_DoorRatSts_i);

  /* Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig' */
  (void)Rte_Write_VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig
    (REL_B.SO_e_DoorRatSts_d);

  /* Outport: '<Root>/VeOUT_REL_BdcLRDoorRatSts_sig_VeOUT_REL_BdcLRDoorRatSts_sig' */
  (void)Rte_Write_VeOUT_REL_BdcLRDoorRatSts_sig_VeOUT_REL_BdcLRDoorRatSts_sig
    (REL_B.SO_e_DoorRatSts_g);

  /* Outport: '<Root>/VeOUT_REL_BdcRRDoorRatSts_sig_VeOUT_REL_BdcRRDoorRatSts_sig' */
  (void)Rte_Write_VeOUT_REL_BdcRRDoorRatSts_sig_VeOUT_REL_BdcRRDoorRatSts_sig
    (REL_B.SO_e_DoorRatSts);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Outport: '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg' incorporates:
   *  SignalConversion generated from: '<S2>/VbINP_HWA_FLDoorOutButton_flg_VbINP_HWA_FLDoorOutButton_flg_read'
   */
  (void)
    Rte_Write_VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg
    (tmpRead_5);

  /* Outport: '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg' incorporates:
   *  SignalConversion generated from: '<S2>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg_read'
   */
  (void)
    Rte_Write_VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg
    (tmpRead_6);

  /* Outport: '<Root>/VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg' incorporates:
   *  SignalConversion generated from: '<S2>/VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg_read'
   */
  (void)
    Rte_Write_VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg
    (tmpRead_7);

  /* Outport: '<Root>/VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg' incorporates:
   *  SignalConversion generated from: '<S2>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg_read'
   */
  (void)
    Rte_Write_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg
    (tmpRead_8);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Outport: '<Root>/VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg' */
  (void)Rte_Write_VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg
    (REL_B.SO_b_FLDoorInnerSwtSts_p);

  /* Outport: '<Root>/VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg' */
  (void)Rte_Write_VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg
    (REL_B.SO_b_FRDoorInnerSwtSts_j);

  /* Outport: '<Root>/VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg' */
  (void)Rte_Write_VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg
    (REL_B.SO_b_RLDoorInnerSwtSts_p);

  /* Outport: '<Root>/VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg' */
  (void)Rte_Write_VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg
    (REL_B.SO_b_RRDoorInnerSwtSts_b);

  /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
  (void)Rte_Write_VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg
    (REL_B.SO_b_MotorA_m);

  /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
  (void)Rte_Write_VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg
    (REL_B.SO_b_MotorB_d);

  /* Outport: '<Root>/VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg' */
  (void)Rte_Write_VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg
    (REL_B.SO_b_MotorA_a);

  /* Outport: '<Root>/VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg' */
  (void)Rte_Write_VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg
    (REL_B.SO_b_MotorB_c);

  /* Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg' */
  (void)Rte_Write_VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg
    (REL_B.SO_b_MotorA_e);

  /* Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg' */
  (void)Rte_Write_VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg
    (REL_B.SO_b_MotorB_p);

  /* Outport: '<Root>/VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg' */
  (void)Rte_Write_VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg
    (REL_B.SO_b_MotorA);

  /* Outport: '<Root>/VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg' */
  (void)Rte_Write_VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg
    (REL_B.SO_b_MotorB);

  /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
  (void)Rte_Write_VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig
    (REL_B.SO_e_DLKUnlockReq);

  /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
  (void)Rte_Write_VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg
    (REL_B.LogicalOperator2);

  /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
  (void)Rte_Write_VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg
    (REL_B.LogicalOperator4);

  /* Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg' */
  (void)Rte_Write_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg
    (REL_B.LogicalOperator6);

  /* Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg' */
  (void)Rte_Write_VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg
    (REL_B.LogicalOperator7);

  /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
  (void)Rte_Write_VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig
    (REL_B.SO_e_MotorMode_h);

  /* Outport: '<Root>/VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig' */
  (void)Rte_Write_VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig
    (REL_B.SO_e_MotorMode_m);

  /* Outport: '<Root>/VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig' */
  (void)Rte_Write_VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig
    (REL_B.SO_e_MotorMode_e);

  /* Outport: '<Root>/VeOUT_REL_RRDoorMotorSts_sig_VeOUT_REL_RRDoorMotorSts_sig' */
  (void)Rte_Write_VeOUT_REL_RRDoorMotorSts_sig_VeOUT_REL_RRDoorMotorSts_sig
    (REL_B.SO_e_MotorMode);
}

/* Model initialize function */
void REL_Init(void)
{
  {
    boolean SO_b_Error_d;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
     *  SubSystem: '<Root>/REL_Step_sys'
     */

    /* SystemInitialize for Chart: '<S3>/FLCenDoorRat' */
    REL_FLCenDoorRat_Init(&REL_B.SO_b_DoorRatRelaseReq_i,
                          &REL_B.SO_DLKUnlockReq_d);

    /* SystemInitialize for Chart: '<S3>/FLDoorReleaseDriver' */
    REL_FLDoorReleaseDriver_Init(&REL_B.SO_b_MotorA_m, &REL_B.SO_b_MotorB_d,
      &REL_B.SO_e_MotorMode_h, &SO_b_Error_d);

    /* SystemInitialize for Chart: '<S3>/FRCenDoorRat' */
    REL_FLCenDoorRat_Init(&REL_B.SO_b_DoorRatRelaseReq_o,
                          &REL_B.SO_DLKUnlockReq_c);

    /* SystemInitialize for Chart: '<S3>/FRDoorReleaseDriver' */
    REL_FLDoorReleaseDriver_Init(&REL_B.SO_b_MotorA_a, &REL_B.SO_b_MotorB_c,
      &REL_B.SO_e_MotorMode_m, &SO_b_Error_d);

    /* SystemInitialize for Chart: '<S3>/RLCenDoorRat' */
    REL_FLCenDoorRat_Init(&REL_B.SO_b_DoorRatRelaseReq_b,
                          &REL_B.SO_DLKUnlockReq_h);

    /* SystemInitialize for Chart: '<S3>/RLDoorReleaseDriver' */
    REL_FLDoorReleaseDriver_Init(&REL_B.SO_b_MotorA_e, &REL_B.SO_b_MotorB_p,
      &REL_B.SO_e_MotorMode_e, &SO_b_Error_d);

    /* SystemInitialize for Chart: '<S3>/RLDoorReleaseDriver1' */
    REL_FLDoorReleaseDriver_Init(&REL_B.SO_b_MotorA, &REL_B.SO_b_MotorB,
      &REL_B.SO_e_MotorMode, &SO_b_Error_d);

    /* SystemInitialize for Chart: '<S3>/RRCenDoorRat' */
    REL_FLCenDoorRat_Init(&REL_B.SO_b_DoorRatRelaseReq_m, &REL_B.SO_DLKUnlockReq);

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
    (void)Rte_Write_VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg
      (REL_B.SO_b_MotorA_m);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
    (void)Rte_Write_VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg
      (REL_B.SO_b_MotorB_d);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg' */
    (void)Rte_Write_VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg
      (REL_B.SO_b_MotorA_a);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg' */
    (void)Rte_Write_VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg
      (REL_B.SO_b_MotorB_c);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg' */
    (void)Rte_Write_VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg
      (REL_B.SO_b_MotorA_e);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg' */
    (void)Rte_Write_VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg
      (REL_B.SO_b_MotorB_p);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg' */
    (void)Rte_Write_VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg
      (REL_B.SO_b_MotorA);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg' */
    (void)Rte_Write_VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg
      (REL_B.SO_b_MotorB);

    /* SystemInitialize for Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
    (void)Rte_Write_VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig
      (REL_B.SO_e_MotorMode_h);

    /* SystemInitialize for Outport: '<Root>/VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig' */
    (void)Rte_Write_VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig
      (REL_B.SO_e_MotorMode_m);

    /* SystemInitialize for Outport: '<Root>/VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig' */
    (void)Rte_Write_VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig
      (REL_B.SO_e_MotorMode_e);

    /* SystemInitialize for Outport: '<Root>/VeOUT_REL_RRDoorMotorSts_sig_VeOUT_REL_RRDoorMotorSts_sig' */
    (void)Rte_Write_VeOUT_REL_RRDoorMotorSts_sig_VeOUT_REL_RRDoorMotorSts_sig
      (REL_B.SO_e_MotorMode);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
