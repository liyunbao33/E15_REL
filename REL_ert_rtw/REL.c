/*
 * File: REL.c
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.265
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Sep  5 09:17:58 2023
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

/* Named constants for Chart: '<S3>/FRDoorReleaseDriver' */
#define REL_IN_CHECKING                ((uint8_T)1U)
#define REL_IN_ELECTRIC_DOOR           ((uint8_T)1U)
#define REL_IN_ERROR                   ((uint8_T)1U)
#define REL_IN_ERROR1                  ((uint8_T)2U)
#define REL_IN_ICE_BREAK               ((uint8_T)3U)
#define REL_IN_IDLE                    ((uint8_T)1U)
#define REL_IN_IDLE_o                  ((uint8_T)4U)
#define REL_IN_INITIAL                 ((uint8_T)2U)
#define REL_IN_LAST_CHECK              ((uint8_T)5U)
#define REL_IN_LAST_CHECK_l            ((uint8_T)2U)
#define REL_IN_NON_ELECTRIC_DOOR       ((uint8_T)2U)
#define REL_IN_NORMAL                  ((uint8_T)1U)
#define REL_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define REL_IN_RELEASE                 ((uint8_T)2U)
#define REL_IN_RESET                   ((uint8_T)3U)
#define REL_IN_STARTUP_SETTING         ((uint8_T)2U)
#define REL_IN_STEP2_OPEN              ((uint8_T)4U)
#define REL_IN_WAITING                 ((uint8_T)6U)
#define REL_IN_WAITING_o               ((uint8_T)3U)

/* Named constants for Chart: '<S3>/RLDoorRelease' */
#define REL_IN_DOOR_LOCK               ((uint8_T)1U)
#define REL_IN_DOOR_UNLOCK             ((uint8_T)2U)
#define REL_IN_FAIL_UNLOCK             ((uint8_T)1U)
#define REL_IN_Initial                 ((uint8_T)1U)
#define REL_IN_NO_ACTIVE_CHILD_h       ((uint8_T)0U)
#define REL_IN_ONCE                    ((uint8_T)2U)
#define REL_IN_Press                   ((uint8_T)2U)
#define REL_IN_RELEASE_l               ((uint8_T)1U)
#define REL_IN_RELEASE_l4              ((uint8_T)3U)
#define REL_IN_REQ_UNLOCK              ((uint8_T)2U)
#define REL_IN_Release                 ((uint8_T)3U)
#define REL_IN_SUCESS_UNLOCK           ((uint8_T)3U)
#define REL_IN_TRIGGER                 ((uint8_T)2U)
#define REL_IN_TWICE                   ((uint8_T)3U)
#define REL_IN_Wait                    ((uint8_T)2U)

/* Named constants for Chart: '<S3>/DoorLockSetSts' */
#define REL_IN_DoorLockSet             ((uint8_T)1U)
#define REL_IN_Init                    ((uint8_T)2U)
#define REL_IN_NO_ACTIVE_CHILD_hj      ((uint8_T)0U)

/* Named constants for Chart: '<S3>/FLDoorRelease' */
#define REL_IN_DOOR_LOCK_h             ((uint8_T)1U)
#define REL_IN_DOOR_UNLOCK_o           ((uint8_T)2U)
#define REL_IN_FAIL_UNLOCK_b           ((uint8_T)1U)
#define REL_IN_Initial_k               ((uint8_T)1U)
#define REL_IN_ONCE_p                  ((uint8_T)2U)
#define REL_IN_Press_k                 ((uint8_T)2U)
#define REL_IN_RELEASE_p               ((uint8_T)1U)
#define REL_IN_RELEASE_p3              ((uint8_T)3U)
#define REL_IN_REQ_UNLOCK_a            ((uint8_T)2U)
#define REL_IN_Release_n               ((uint8_T)3U)
#define REL_IN_SUCESS_UNLOCK_b         ((uint8_T)3U)
#define REL_IN_TRIGGER_e               ((uint8_T)2U)
#define REL_IN_TWICE_h                 ((uint8_T)3U)
#define REL_IN_Wait_n                  ((uint8_T)2U)

/* Named constants for Chart: '<S3>/FLDoorReleaseDriver' */
#define REL_IN_CHECKING_g              ((uint8_T)1U)
#define REL_IN_ELECTRIC_DOOR_d         ((uint8_T)1U)
#define REL_IN_ERROR1_f                ((uint8_T)2U)
#define REL_IN_ERROR_i                 ((uint8_T)1U)
#define REL_IN_ICE_BREAK_f             ((uint8_T)3U)
#define REL_IN_IDLE_f                  ((uint8_T)1U)
#define REL_IN_IDLE_fk                 ((uint8_T)4U)
#define REL_IN_INITIAL_f               ((uint8_T)2U)
#define REL_IN_LAST_CHECK_a            ((uint8_T)5U)
#define REL_IN_LAST_CHECK_ad           ((uint8_T)2U)
#define REL_IN_NON_ELECTRIC_DOOR_g     ((uint8_T)2U)
#define REL_IN_NORMAL_f                ((uint8_T)1U)
#define REL_IN_RELEASE_i               ((uint8_T)2U)
#define REL_IN_RESET_l                 ((uint8_T)3U)
#define REL_IN_STARTUP_SETTING_i       ((uint8_T)2U)
#define REL_IN_STEP2_OPEN_l            ((uint8_T)4U)

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
  DW_FRDoorReleaseDriver_REL_T *localDW);

/* Forward declaration for local functions */
static void REL_DoorIn(UInt8 rtu_SI_e_EspVehSpd, Boolean rtu_SI_b_EspVehSpdVld,
  UInt8 rtu_SI_e_VcuGearPosn, UInt8 rtu_SI_e_DoorLockSts, uint8_T
  rtu_SI_e_DoorRatSts, Boolean rtu_SI_b_ChildLckSts, boolean_T
  *rty_SO_b_DoorRlsReq, boolean_T *rty_SO_b_UnlockReq, DW_RLDoorRelease_REL_T
  *localDW);
static void REL_DoorCent(boolean_T rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd,
  Boolean rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8
  rtu_SI_e_DoorLockSts, uint8_T rtu_SI_e_DoorRatSts, Boolean
  rtu_SI_b_CentSingleDoorSwSts, Boolean rtu_SI_b_CentAllDoorSwSts, boolean_T
  *rty_SO_b_DoorRlsReq, boolean_T *rty_SO_b_UnlockReq, DW_RLDoorRelease_REL_T
  *localDW);
static void REL_DoorHand(boolean_T rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd,
  Boolean rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8
  rtu_SI_e_DoorLockSts, uint8_T rtu_SI_e_DoorRatSts, boolean_T
  *rty_SO_b_DoorRlsReq, boolean_T *rty_SO_b_UnlockReq, DW_RLDoorRelease_REL_T
  *localDW);

/* Forward declaration for local functions */
static void REL_DoorIn_c(const uint8_T *SI_e_VcuGearPosn_prev_d, const boolean_T
  *SI_b_DoorInSwSts_prev_d, const boolean_T *SL_b_DoorInSwValid_prev_o);
static void REL_DoorCent_a(const boolean_T *Compare, const uint8_T
  *SI_e_VcuGearPosn_prev_d, const boolean_T *SL_b_CentSingleDoorSwValid_pr_d,
  const boolean_T *SL_b_CentAllDoorSwValid_prev_i);
static void REL_DoorHand_h(const boolean_T *Compare, const uint8_T
  *SI_e_VcuGearPosn_prev_d, const boolean_T *SI_b_DoorHandSwSts_prev_p, const
  boolean_T *SL_b_DoorHandSwValid_prev_e);
static void REL_NORMAL(const boolean_T *SI_b_CinchHome_prev, const boolean_T
  *SO_b_DoorRlsReq_prev);
static void REL_DoorIn_f(const uint8_T *SI_e_VcuGearPosn_prev, const boolean_T
  *SI_b_DoorInSwSts_prev, const boolean_T *SL_b_DoorInSwValid_prev);
static void REL_DoorCent_b(const boolean_T *Compare, const uint8_T
  *SI_e_VcuGearPosn_prev, const boolean_T *SL_b_CentSingleDoorSwValid_prev,
  const boolean_T *SL_b_CentAllDoorSwValid_prev);
static void REL_DoorHand_b(const boolean_T *Compare, const uint8_T
  *SI_e_VcuGearPosn_prev, const boolean_T *SI_b_DoorHandSwSts_prev, const
  boolean_T *SL_b_DoorHandSwValid_prev);

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

/* Function for Chart: '<S3>/FRDoorReleaseDriver' */
static void REL_ELECTRIC_DOOR(Boolean rtu_SI_b_DoorOpenSts, Boolean
  rtu_SI_b_DCUCinchHomeSwt, boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorMode, boolean_T *rty_SO_b_Error,
  DW_FRDoorReleaseDriver_REL_T *localDW)
{
  if (localDW->is_MAIN_PROGRESS == REL_IN_IDLE) {
    *rty_SO_e_MotorMode = 0U;
    if ((localDW->SI_b_TriggerRelease_prev != localDW->SI_b_TriggerRelease_start)
        && localDW->SI_b_TriggerRelease_start) {
      localDW->is_MAIN_PROGRESS = REL_IN_RELEASE;
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
          localDW->is_STEP2_OPEN = REL_IN_IDLE_o;
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
        localDW->is_RELEASE = REL_IN_NO_ACTIVE_CHILD;
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
          localDW->is_STEP2_OPEN = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_RELEASE = REL_IN_RESET;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorMode = 2U;
        }
        break;

       case REL_IN_ERROR1:
        if (localDW->temporalCounter_i1 >= 5) {
          localDW->is_STEP2_OPEN = REL_IN_NO_ACTIVE_CHILD;
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
          localDW->is_STEP2_OPEN = REL_IN_NO_ACTIVE_CHILD;
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

       case REL_IN_IDLE_o:
        *rty_SO_e_MotorMode = 0U;
        if (rtu_SI_b_DoorOpenSts) {
          localDW->is_STEP2_OPEN = REL_IN_WAITING;
          localDW->temporalCounter_i1 = 0U;
        } else if ((localDW->temporalCounter_i1 < 270) &&
                   ((localDW->SI_b_DoorOpenSts_prev !=
                     localDW->SI_b_DoorOpenSts_start) &&
                    localDW->SI_b_DoorOpenSts_start)) {
          localDW->is_STEP2_OPEN = REL_IN_NO_ACTIVE_CHILD;
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
          localDW->is_STEP2_OPEN = REL_IN_NO_ACTIVE_CHILD;
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
 *    '<S3>/FRDoorReleaseDriver'
 *    '<S3>/RLDoorReleaseDriver'
 *    '<S3>/RLDoorReleaseDriver1'
 */
void REL_FRDoorReleaseDriver_Init(boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorMode, boolean_T *rty_SO_b_Error)
{
  *rty_SO_b_MotorA = false;
  *rty_SO_b_MotorB = false;
  *rty_SO_e_MotorMode = 0U;
  *rty_SO_b_Error = false;
}

/*
 * Output and update for atomic system:
 *    '<S3>/FRDoorReleaseDriver'
 *    '<S3>/RLDoorReleaseDriver'
 *    '<S3>/RLDoorReleaseDriver1'
 */
void REL_FRDoorReleaseDriver(boolean_T rtu_SI_b_TriggerRelease, Boolean
  rtu_SI_b_DoorOpenSts, Boolean rtu_SI_b_DCUCinchHomeSwt, Boolean
  rtu_SI_b_ElectricDoorCfg, boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorMode, boolean_T *rty_SO_b_Error,
  DW_FRDoorReleaseDriver_REL_T *localDW)
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

  /* Chart: '<S3>/FRDoorReleaseDriver' */
  if (localDW->is_active_c20_REL == 0U) {
    localDW->SI_b_DoorOpenSts_prev = rtu_SI_b_DoorOpenSts;
    localDW->SI_b_DCUCinchHomeSwt_prev = rtu_SI_b_DCUCinchHomeSwt;
    localDW->SI_b_TriggerRelease_prev = rtu_SI_b_TriggerRelease;
    localDW->is_active_c20_REL = 1U;
    localDW->is_c20_REL = REL_IN_STARTUP_SETTING;
    localDW->temporalCounter_i1 = 0U;
    *rty_SO_b_MotorA = false;
    *rty_SO_b_MotorB = true;
    *rty_SO_e_MotorMode = 2U;
  } else if (localDW->is_c20_REL == REL_IN_NORMAL) {
    if (localDW->is_NORMAL == REL_IN_ELECTRIC_DOOR) {
      REL_ELECTRIC_DOOR(rtu_SI_b_DoorOpenSts, rtu_SI_b_DCUCinchHomeSwt,
                        rty_SO_b_MotorA, rty_SO_b_MotorB, rty_SO_e_MotorMode,
                        rty_SO_b_Error, localDW);

      /* case IN_NON_ELECTRIC_DOOR: */
    } else if (localDW->is_MAIN_PROGRESS_g == REL_IN_IDLE) {
      *rty_SO_e_MotorMode = 0U;
      if ((localDW->SI_b_TriggerRelease_prev !=
           localDW->SI_b_TriggerRelease_start) &&
          localDW->SI_b_TriggerRelease_start) {
        localDW->is_MAIN_PROGRESS_g = REL_IN_RELEASE;
        localDW->SL_e_CheckCycle = 0U;
        localDW->is_RELEASE_d = REL_IN_INITIAL;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_MotorA = true;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorMode = 1U;

        /* MotorA=Release Side */
      }
    } else {
      /* case IN_RELEASE: */
      switch (localDW->is_RELEASE_d) {
       case REL_IN_CHECKING:
        {
          *rty_SO_e_MotorMode = 0U;
          if ((localDW->temporalCounter_i1 >= 5) && rtu_SI_b_DoorOpenSts) {
            localDW->is_RELEASE_d = REL_IN_STEP2_OPEN;
            localDW->is_STEP2_OPEN_g = REL_IN_IDLE;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = false;
            *rty_SO_e_MotorMode = 0U;
          } else {
            Boolean tmp_0;
            tmp_0 = !rtu_SI_b_DoorOpenSts;
            if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                (localDW->SL_e_CheckCycle < 2)) {
              localDW->is_RELEASE_d = REL_IN_INITIAL;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_b_MotorA = true;
              *rty_SO_b_MotorB = false;
              *rty_SO_e_MotorMode = 1U;

              /* MotorA=Release Side */
            } else if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                       (localDW->SL_e_CheckCycle >= 2)) {
              localDW->is_RELEASE_d = REL_IN_RESET;
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
            localDW->is_RELEASE_d = REL_IN_CHECKING;
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
          localDW->is_RELEASE_d = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_MAIN_PROGRESS_g = REL_IN_IDLE;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorMode = 0U;
        }
        break;

       default:
        /* case IN_STEP2_OPEN: */
        switch (localDW->is_STEP2_OPEN_g) {
         case REL_IN_IDLE:
          *rty_SO_e_MotorMode = 0U;
          if (rtu_SI_b_DoorOpenSts) {
            localDW->is_STEP2_OPEN_g = REL_IN_WAITING_o;
            localDW->temporalCounter_i1 = 0U;
          } else if ((localDW->temporalCounter_i1 < 270) &&
                     ((localDW->SI_b_DoorOpenSts_prev !=
                       localDW->SI_b_DoorOpenSts_start) &&
                      localDW->SI_b_DoorOpenSts_start)) {
            localDW->is_STEP2_OPEN_g = REL_IN_NO_ACTIVE_CHILD;
            localDW->is_RELEASE_d = REL_IN_RESET;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = true;
            *rty_SO_e_MotorMode = 2U;
          } else if (localDW->temporalCounter_i1 >= 300) {
            localDW->is_STEP2_OPEN_g = REL_IN_LAST_CHECK_l;
          }
          break;

         case REL_IN_LAST_CHECK_l:
          localDW->is_STEP2_OPEN_g = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_RELEASE_d = REL_IN_RESET;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorMode = 2U;
          break;

         default:
          /* case IN_WAITING: */
          if (localDW->temporalCounter_i1 >= 5) {
            localDW->is_STEP2_OPEN_g = REL_IN_NO_ACTIVE_CHILD;
            localDW->is_RELEASE_d = REL_IN_RESET;
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
      localDW->is_c20_REL = REL_IN_NORMAL;
      if (rtu_SI_b_ElectricDoorCfg) {
        localDW->is_NORMAL = REL_IN_ELECTRIC_DOOR;
        localDW->is_MAIN_PROGRESS = REL_IN_IDLE;
        *rty_SO_b_MotorA = false;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorMode = 0U;
        *rty_SO_b_Error = false;
      } else {
        localDW->is_NORMAL = REL_IN_NON_ELECTRIC_DOOR;
        localDW->is_MAIN_PROGRESS_g = REL_IN_IDLE;
        *rty_SO_b_MotorA = false;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorMode = 0U;
      }
    }
  }

  /* End of Chart: '<S3>/FRDoorReleaseDriver' */
}

/* Function for Chart: '<S3>/RLDoorRelease' */
static void REL_DoorIn(UInt8 rtu_SI_e_EspVehSpd, Boolean rtu_SI_b_EspVehSpdVld,
  UInt8 rtu_SI_e_VcuGearPosn, UInt8 rtu_SI_e_DoorLockSts, uint8_T
  rtu_SI_e_DoorRatSts, Boolean rtu_SI_b_ChildLckSts, boolean_T
  *rty_SO_b_DoorRlsReq, boolean_T *rty_SO_b_UnlockReq, DW_RLDoorRelease_REL_T
  *localDW)
{
  switch (localDW->is_SwValid) {
   case REL_IN_Initial:
    if ((localDW->SI_b_DoorInSwSts_prev != localDW->SI_b_DoorInSwSts_start) &&
        localDW->SI_b_DoorInSwSts_start && (!rtu_SI_b_ChildLckSts)) {
      localDW->is_SwValid = REL_IN_ONCE;
      localDW->temporalCounter_i3 = 0U;
    }
    break;

   case REL_IN_ONCE:
    if ((localDW->SI_b_DoorInSwSts_prev != localDW->SI_b_DoorInSwSts_start) &&
        localDW->SI_b_DoorInSwSts_start && (!rtu_SI_b_ChildLckSts)) {
      localDW->is_SwValid = REL_IN_TWICE;
      localDW->temporalCounter_i3 = 0U;
      localDW->SL_b_DoorInSwValid = true;
    } else if ((localDW->temporalCounter_i3 >= 200) || rtu_SI_b_ChildLckSts) {
      localDW->is_SwValid = REL_IN_Initial;
      localDW->SL_b_DoorInSwValid = false;
    }
    break;

   default:
    /* case IN_TWICE: */
    if (localDW->temporalCounter_i3 >= 3) {
      localDW->is_SwValid = REL_IN_Initial;
      localDW->SL_b_DoorInSwValid = false;
    }
    break;
  }

  if (localDW->is_RlsReq_m == REL_IN_Initial) {
    if ((((rtu_SI_e_EspVehSpd <= 0) && (!rtu_SI_b_EspVehSpdVld)) ||
         (rtu_SI_e_VcuGearPosn == 1)) && ((localDW->SL_b_DoorInSwValid_prev !=
          localDW->SL_b_DoorInSwValid_start) &&
         localDW->SL_b_DoorInSwValid_start)) {
      localDW->is_RlsReq_m = REL_IN_TRIGGER;
      localDW->temporalCounter_i5 = 0U;
      if (rtu_SI_e_DoorLockSts == 0) {
        localDW->is_TRIGGER_g = REL_IN_DOOR_LOCK;
        localDW->is_DOOR_LOCK = REL_IN_REQ_UNLOCK;
        localDW->temporalCounter_i4 = 0U;
        *rty_SO_b_UnlockReq = true;
      } else {
        localDW->is_TRIGGER_g = REL_IN_DOOR_UNLOCK;
      }
    }

    /* case IN_TRIGGER: */
  } else if (((localDW->SI_e_VcuGearPosn_prev != localDW->SI_e_VcuGearPosn_start)
              && (localDW->SI_e_VcuGearPosn_prev == 1)) || ((rtu_SI_e_EspVehSpd >=
    5) && (!rtu_SI_b_EspVehSpdVld)) || ((localDW->temporalCounter_i5 >= 105) &&
              (rtu_SI_e_DoorLockSts == 0)) || ((rtu_SI_e_DoorLockSts == 1) &&
              (rtu_SI_e_DoorRatSts == 3))) {
    localDW->is_DOOR_LOCK = REL_IN_NO_ACTIVE_CHILD_h;
    localDW->is_TRIGGER_g = REL_IN_NO_ACTIVE_CHILD_h;
    localDW->is_RlsReq_m = REL_IN_Initial;
    *rty_SO_b_DoorRlsReq = false;
    *rty_SO_b_UnlockReq = false;
  } else {
    switch (localDW->is_TRIGGER_g) {
     case REL_IN_DOOR_LOCK:
      if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
        localDW->is_DOOR_LOCK = REL_IN_NO_ACTIVE_CHILD_h;
        localDW->is_TRIGGER_g = REL_IN_RELEASE_l4;
        localDW->temporalCounter_i4 = 0U;
        *rty_SO_b_DoorRlsReq = true;
      } else {
        switch (localDW->is_DOOR_LOCK) {
         case REL_IN_FAIL_UNLOCK:
          break;

         case REL_IN_REQ_UNLOCK:
          if (rtu_SI_e_DoorLockSts == 1) {
            localDW->is_DOOR_LOCK = REL_IN_SUCESS_UNLOCK;
          } else if ((localDW->temporalCounter_i4 >= 100) &&
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
        localDW->is_TRIGGER_g = REL_IN_RELEASE_l4;
        localDW->temporalCounter_i4 = 0U;
        *rty_SO_b_DoorRlsReq = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (localDW->temporalCounter_i4 >= 5) {
        localDW->is_TRIGGER_g = REL_IN_NO_ACTIVE_CHILD_h;
        localDW->is_RlsReq_m = REL_IN_Initial;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/RLDoorRelease' */
static void REL_DoorCent(boolean_T rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd,
  Boolean rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8
  rtu_SI_e_DoorLockSts, uint8_T rtu_SI_e_DoorRatSts, Boolean
  rtu_SI_b_CentSingleDoorSwSts, Boolean rtu_SI_b_CentAllDoorSwSts, boolean_T
  *rty_SO_b_DoorRlsReq, boolean_T *rty_SO_b_UnlockReq, DW_RLDoorRelease_REL_T
  *localDW)
{
  if (localDW->is_DoorCentral == REL_IN_Initial) {
    if ((!rtu_SI_b_OFF) && (((rtu_SI_e_EspVehSpd <= 0) &&
          (!rtu_SI_b_EspVehSpdVld)) || (rtu_SI_e_VcuGearPosn == 1)) &&
        (((localDW->SL_b_CentSingleDoorSwValid_prev !=
           localDW->SL_b_CentSingleDoorSwValid_star) &&
          localDW->SL_b_CentSingleDoorSwValid_star) ||
         ((localDW->SL_b_CentAllDoorSwValid_prev !=
           localDW->SL_b_CentAllDoorSwValid_start) &&
          localDW->SL_b_CentAllDoorSwValid_start))) {
      localDW->is_DoorCentral = REL_IN_TRIGGER;
      localDW->temporalCounter_i12 = 0U;
      if (rtu_SI_e_DoorLockSts == 0) {
        localDW->is_TRIGGER_j = REL_IN_DOOR_LOCK;
        localDW->is_DOOR_LOCK_h = REL_IN_REQ_UNLOCK;
        localDW->temporalCounter_i11 = 0U;
        *rty_SO_b_UnlockReq = true;
      } else {
        localDW->is_TRIGGER_j = REL_IN_DOOR_UNLOCK;
      }
    }

    /* case IN_TRIGGER: */
  } else if (((localDW->SI_e_VcuGearPosn_prev != localDW->SI_e_VcuGearPosn_start)
              && (localDW->SI_e_VcuGearPosn_prev == 1)) || ((rtu_SI_e_EspVehSpd >=
    5) && (!rtu_SI_b_EspVehSpdVld)) || ((localDW->temporalCounter_i12 >= 105) &&
              (rtu_SI_e_DoorLockSts == 0)) || ((rtu_SI_e_DoorLockSts == 1) &&
              (rtu_SI_e_DoorRatSts == 3))) {
    localDW->is_DOOR_LOCK_h = REL_IN_NO_ACTIVE_CHILD_h;
    localDW->is_TRIGGER_j = REL_IN_NO_ACTIVE_CHILD_h;
    localDW->is_DoorCentral = REL_IN_Initial;
    *rty_SO_b_DoorRlsReq = false;
    *rty_SO_b_UnlockReq = false;
  } else {
    switch (localDW->is_TRIGGER_j) {
     case REL_IN_DOOR_LOCK:
      if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
        localDW->is_DOOR_LOCK_h = REL_IN_NO_ACTIVE_CHILD_h;
        localDW->is_TRIGGER_j = REL_IN_RELEASE_l4;
        localDW->temporalCounter_i11 = 0U;
        *rty_SO_b_DoorRlsReq = true;
      } else {
        switch (localDW->is_DOOR_LOCK_h) {
         case REL_IN_FAIL_UNLOCK:
          break;

         case REL_IN_REQ_UNLOCK:
          if (rtu_SI_e_DoorLockSts == 1) {
            localDW->is_DOOR_LOCK_h = REL_IN_SUCESS_UNLOCK;
          } else if ((localDW->temporalCounter_i11 >= 100) &&
                     (rtu_SI_e_DoorLockSts == 0)) {
            localDW->is_DOOR_LOCK_h = REL_IN_FAIL_UNLOCK;
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
        localDW->is_TRIGGER_j = REL_IN_RELEASE_l4;
        localDW->temporalCounter_i11 = 0U;
        *rty_SO_b_DoorRlsReq = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (localDW->temporalCounter_i11 >= 5) {
        localDW->is_TRIGGER_j = REL_IN_NO_ACTIVE_CHILD_h;
        localDW->is_DoorCentral = REL_IN_Initial;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
      }
      break;
    }
  }

  localDW->SL_b_CentSingleDoorSwValid = rtu_SI_b_CentSingleDoorSwSts;
  localDW->SL_b_CentAllDoorSwValid = rtu_SI_b_CentAllDoorSwSts;
}

/* Function for Chart: '<S3>/RLDoorRelease' */
static void REL_DoorHand(boolean_T rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd,
  Boolean rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8
  rtu_SI_e_DoorLockSts, uint8_T rtu_SI_e_DoorRatSts, boolean_T
  *rty_SO_b_DoorRlsReq, boolean_T *rty_SO_b_UnlockReq, DW_RLDoorRelease_REL_T
  *localDW)
{
  if (localDW->is_RlsReq_a0 == REL_IN_Initial) {
    if ((!rtu_SI_b_OFF) && (((rtu_SI_e_EspVehSpd <= 0) &&
          (!rtu_SI_b_EspVehSpdVld)) || (rtu_SI_e_VcuGearPosn == 1)) &&
        ((localDW->SL_b_DoorHandSwValid_prev !=
          localDW->SL_b_DoorHandSwValid_start) &&
         localDW->SL_b_DoorHandSwValid_start)) {
      localDW->is_RlsReq_a0 = REL_IN_TRIGGER;
      localDW->temporalCounter_i10 = 0U;
      if (rtu_SI_e_DoorLockSts == 0) {
        localDW->is_TRIGGER_o = REL_IN_DOOR_LOCK;
        localDW->is_DOOR_LOCK_m = REL_IN_REQ_UNLOCK;
        localDW->temporalCounter_i9 = 0U;
        *rty_SO_b_UnlockReq = true;
      } else {
        localDW->is_TRIGGER_o = REL_IN_DOOR_UNLOCK;
      }
    }

    /* case IN_TRIGGER: */
  } else if (((localDW->SI_e_VcuGearPosn_prev != localDW->SI_e_VcuGearPosn_start)
              && (localDW->SI_e_VcuGearPosn_prev == 1)) || ((rtu_SI_e_EspVehSpd >=
    5) && (!rtu_SI_b_EspVehSpdVld)) || ((localDW->temporalCounter_i10 >= 105) &&
              (rtu_SI_e_DoorLockSts == 0)) || ((rtu_SI_e_DoorLockSts == 1) &&
              (rtu_SI_e_DoorRatSts == 3))) {
    localDW->is_DOOR_LOCK_m = REL_IN_NO_ACTIVE_CHILD_h;
    localDW->is_TRIGGER_o = REL_IN_NO_ACTIVE_CHILD_h;
    localDW->is_RlsReq_a0 = REL_IN_Initial;
    *rty_SO_b_DoorRlsReq = false;
    *rty_SO_b_UnlockReq = false;
  } else {
    switch (localDW->is_TRIGGER_o) {
     case REL_IN_DOOR_LOCK:
      if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
        localDW->is_DOOR_LOCK_m = REL_IN_NO_ACTIVE_CHILD_h;
        localDW->is_TRIGGER_o = REL_IN_RELEASE_l4;
        localDW->temporalCounter_i9 = 0U;
        *rty_SO_b_DoorRlsReq = true;
      } else {
        switch (localDW->is_DOOR_LOCK_m) {
         case REL_IN_FAIL_UNLOCK:
          break;

         case REL_IN_REQ_UNLOCK:
          if (rtu_SI_e_DoorLockSts == 1) {
            localDW->is_DOOR_LOCK_m = REL_IN_SUCESS_UNLOCK;
          } else if ((localDW->temporalCounter_i9 >= 100) &&
                     (rtu_SI_e_DoorLockSts == 0)) {
            localDW->is_DOOR_LOCK_m = REL_IN_FAIL_UNLOCK;
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
        localDW->is_TRIGGER_o = REL_IN_RELEASE_l4;
        localDW->temporalCounter_i9 = 0U;
        *rty_SO_b_DoorRlsReq = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (localDW->temporalCounter_i9 >= 5) {
        localDW->is_TRIGGER_o = REL_IN_NO_ACTIVE_CHILD_h;
        localDW->is_RlsReq_a0 = REL_IN_Initial;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
      }
      break;
    }
  }

  switch (localDW->is_SwValid_l) {
   case REL_IN_Initial:
    if ((localDW->SI_b_DoorHandSwSts_prev != localDW->SI_b_DoorHandSwSts_start) &&
        localDW->SI_b_DoorHandSwSts_start) {
      localDW->is_SwValid_l = REL_IN_Press;
      localDW->temporalCounter_i8 = 0U;
    }
    break;

   case REL_IN_Press:
    if ((localDW->SI_b_DoorHandSwSts_prev != localDW->SI_b_DoorHandSwSts_start) &&
        (!localDW->SI_b_DoorHandSwSts_start)) {
      localDW->is_SwValid_l = REL_IN_Release;
      localDW->temporalCounter_i8 = 0U;
      localDW->SL_b_DoorHandSwValid = true;
    } else if (localDW->temporalCounter_i8 >= 100) {
      localDW->is_SwValid_l = REL_IN_Initial;
      localDW->SL_b_DoorHandSwValid = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (localDW->temporalCounter_i8 >= 3) {
      localDW->is_SwValid_l = REL_IN_Initial;
      localDW->SL_b_DoorHandSwValid = false;
    }
    break;
  }
}

/*
 * System initialize for atomic system:
 *    '<S3>/RLDoorRelease'
 *    '<S3>/RRDoorRelease'
 */
void REL_RLDoorRelease_Init(boolean_T *rty_SO_b_DoorRlsReq, boolean_T
  *rty_SO_b_UnlockReq)
{
  *rty_SO_b_DoorRlsReq = false;
  *rty_SO_b_UnlockReq = false;
}

/*
 * Output and update for atomic system:
 *    '<S3>/RLDoorRelease'
 *    '<S3>/RRDoorRelease'
 */
void REL_RLDoorRelease(boolean_T rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd, Boolean
  rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8 rtu_SI_e_DoorLockSts,
  uint8_T rtu_SI_e_DoorRatSts, Boolean rtu_SI_b_DoorInSwSts, Boolean
  rtu_SI_b_DoorOutSwSts, Boolean rtu_SI_b_DoorHandSwSts, Boolean
  rtu_SI_b_CentSingleDoorSwSts, Boolean rtu_SI_b_CentAllDoorSwSts, Boolean
  rtu_SI_b_ChildLckSts, boolean_T rtu_SI_b_DoorLockSetSts, boolean_T
  *rty_SO_b_DoorRlsReq, boolean_T *rty_SO_b_UnlockReq, DW_RLDoorRelease_REL_T
  *localDW)
{
  if (localDW->temporalCounter_i1 < 127U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->temporalCounter_i2 < 7U) {
    localDW->temporalCounter_i2++;
  }

  if (localDW->temporalCounter_i3 < 255U) {
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

  if (localDW->temporalCounter_i7 < 127U) {
    localDW->temporalCounter_i7++;
  }

  if (localDW->temporalCounter_i8 < 127U) {
    localDW->temporalCounter_i8++;
  }

  if (localDW->temporalCounter_i9 < 127U) {
    localDW->temporalCounter_i9++;
  }

  if (localDW->temporalCounter_i10 < 127U) {
    localDW->temporalCounter_i10++;
  }

  if (localDW->temporalCounter_i11 < 127U) {
    localDW->temporalCounter_i11++;
  }

  if (localDW->temporalCounter_i12 < 127U) {
    localDW->temporalCounter_i12++;
  }

  localDW->SI_e_DoorLockSts_prev = localDW->SI_e_DoorLockSts_start;
  localDW->SI_e_DoorLockSts_start = rtu_SI_e_DoorLockSts;
  localDW->SI_e_VcuGearPosn_prev = localDW->SI_e_VcuGearPosn_start;
  localDW->SI_e_VcuGearPosn_start = rtu_SI_e_VcuGearPosn;
  localDW->SI_b_DoorInSwSts_prev = localDW->SI_b_DoorInSwSts_start;
  localDW->SI_b_DoorInSwSts_start = rtu_SI_b_DoorInSwSts;
  localDW->SL_b_DoorInSwValid_prev = localDW->SL_b_DoorInSwValid_start;
  localDW->SL_b_DoorInSwValid_start = localDW->SL_b_DoorInSwValid;
  localDW->SL_b_DoorOutSwValid_prev = localDW->SL_b_DoorOutSwValid_start;
  localDW->SL_b_DoorOutSwValid_start = localDW->SL_b_DoorOutSwValid;
  localDW->SI_b_DoorHandSwSts_prev = localDW->SI_b_DoorHandSwSts_start;
  localDW->SI_b_DoorHandSwSts_start = rtu_SI_b_DoorHandSwSts;
  localDW->SL_b_DoorHandSwValid_prev = localDW->SL_b_DoorHandSwValid_start;
  localDW->SL_b_DoorHandSwValid_start = localDW->SL_b_DoorHandSwValid;
  localDW->SL_b_CentSingleDoorSwValid_prev =
    localDW->SL_b_CentSingleDoorSwValid_star;
  localDW->SL_b_CentSingleDoorSwValid_star = localDW->SL_b_CentSingleDoorSwValid;
  localDW->SL_b_CentAllDoorSwValid_prev = localDW->SL_b_CentAllDoorSwValid_start;
  localDW->SL_b_CentAllDoorSwValid_start = localDW->SL_b_CentAllDoorSwValid;

  /* Chart: '<S3>/RLDoorRelease' */
  if (localDW->is_active_c5_DoorRelease == 0U) {
    localDW->SI_e_DoorLockSts_prev = rtu_SI_e_DoorLockSts;
    localDW->SI_e_VcuGearPosn_prev = rtu_SI_e_VcuGearPosn;
    localDW->SI_b_DoorInSwSts_prev = rtu_SI_b_DoorInSwSts;
    localDW->SI_b_DoorHandSwSts_prev = rtu_SI_b_DoorHandSwSts;
    localDW->is_active_c5_DoorRelease = 1U;
    localDW->is_SwValid = REL_IN_Initial;
    localDW->SL_b_DoorInSwValid = false;
    localDW->is_RlsReq_m = REL_IN_Initial;
    localDW->is_DoorCentral = REL_IN_Initial;
    localDW->SL_b_CentSingleDoorSwValid = rtu_SI_b_CentSingleDoorSwSts;
    localDW->SL_b_CentAllDoorSwValid = rtu_SI_b_CentAllDoorSwSts;
    localDW->SL_b_DoorOutSwValid = rtu_SI_b_DoorOutSwSts;
    localDW->is_RlsReq_a = REL_IN_Initial;
    localDW->is_RlsReq_a0 = REL_IN_Initial;
    *rty_SO_b_UnlockReq = false;
    localDW->is_SwValid_l = REL_IN_Initial;
    localDW->SL_b_DoorHandSwValid = false;
    localDW->is_RlsReq = REL_IN_Initial;
    *rty_SO_b_DoorRlsReq = false;
  } else {
    REL_DoorIn(rtu_SI_e_EspVehSpd, rtu_SI_b_EspVehSpdVld, rtu_SI_e_VcuGearPosn,
               rtu_SI_e_DoorLockSts, rtu_SI_e_DoorRatSts, rtu_SI_b_ChildLckSts,
               rty_SO_b_DoorRlsReq, rty_SO_b_UnlockReq, localDW);
    REL_DoorCent(rtu_SI_b_OFF, rtu_SI_e_EspVehSpd, rtu_SI_b_EspVehSpdVld,
                 rtu_SI_e_VcuGearPosn, rtu_SI_e_DoorLockSts, rtu_SI_e_DoorRatSts,
                 rtu_SI_b_CentSingleDoorSwSts, rtu_SI_b_CentAllDoorSwSts,
                 rty_SO_b_DoorRlsReq, rty_SO_b_UnlockReq, localDW);
    localDW->SL_b_DoorOutSwValid = rtu_SI_b_DoorOutSwSts;
    if (localDW->is_RlsReq_a == REL_IN_Initial) {
      if ((((rtu_SI_e_EspVehSpd <= 0) && (!rtu_SI_b_EspVehSpdVld)) ||
           (rtu_SI_e_VcuGearPosn == 1)) && ((localDW->SL_b_DoorOutSwValid_prev
            != localDW->SL_b_DoorOutSwValid_start) &&
           localDW->SL_b_DoorOutSwValid_start)) {
        localDW->is_RlsReq_a = REL_IN_TRIGGER;
        localDW->temporalCounter_i7 = 0U;
        if (rtu_SI_e_DoorLockSts == 0) {
          localDW->is_TRIGGER_e = REL_IN_DOOR_LOCK;
          localDW->is_DOOR_LOCK_p = REL_IN_REQ_UNLOCK;
          localDW->temporalCounter_i6 = 0U;
          *rty_SO_b_UnlockReq = true;
        } else {
          localDW->is_TRIGGER_e = REL_IN_DOOR_UNLOCK;
        }
      }

      /* case IN_TRIGGER: */
    } else if (((localDW->SI_e_VcuGearPosn_prev !=
                 localDW->SI_e_VcuGearPosn_start) &&
                (localDW->SI_e_VcuGearPosn_prev == 1)) || ((rtu_SI_e_EspVehSpd >=
      5) && (!rtu_SI_b_EspVehSpdVld)) || ((localDW->temporalCounter_i7 >= 105) &&
                (rtu_SI_e_DoorLockSts == 0)) || ((rtu_SI_e_DoorLockSts == 1) &&
                (rtu_SI_e_DoorRatSts == 3))) {
      localDW->is_DOOR_LOCK_p = REL_IN_NO_ACTIVE_CHILD_h;
      localDW->is_TRIGGER_e = REL_IN_NO_ACTIVE_CHILD_h;
      localDW->is_RlsReq_a = REL_IN_Initial;
      *rty_SO_b_DoorRlsReq = false;
      *rty_SO_b_UnlockReq = false;
    } else {
      switch (localDW->is_TRIGGER_e) {
       case REL_IN_DOOR_LOCK:
        if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
          localDW->is_DOOR_LOCK_p = REL_IN_NO_ACTIVE_CHILD_h;
          localDW->is_TRIGGER_e = REL_IN_RELEASE_l4;
          localDW->temporalCounter_i6 = 0U;
          *rty_SO_b_DoorRlsReq = true;
        } else {
          switch (localDW->is_DOOR_LOCK_p) {
           case REL_IN_FAIL_UNLOCK:
            break;

           case REL_IN_REQ_UNLOCK:
            if (rtu_SI_e_DoorLockSts == 1) {
              localDW->is_DOOR_LOCK_p = REL_IN_SUCESS_UNLOCK;
            } else if ((localDW->temporalCounter_i6 >= 100) &&
                       (rtu_SI_e_DoorLockSts == 0)) {
              localDW->is_DOOR_LOCK_p = REL_IN_FAIL_UNLOCK;
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
          localDW->is_TRIGGER_e = REL_IN_RELEASE_l4;
          localDW->temporalCounter_i6 = 0U;
          *rty_SO_b_DoorRlsReq = true;
        }
        break;

       default:
        /* case IN_RELEASE: */
        if (localDW->temporalCounter_i6 >= 5) {
          localDW->is_TRIGGER_e = REL_IN_NO_ACTIVE_CHILD_h;
          localDW->is_RlsReq_a = REL_IN_Initial;
          *rty_SO_b_DoorRlsReq = false;
          *rty_SO_b_UnlockReq = false;
        }
        break;
      }
    }

    REL_DoorHand(rtu_SI_b_OFF, rtu_SI_e_EspVehSpd, rtu_SI_b_EspVehSpdVld,
                 rtu_SI_e_VcuGearPosn, rtu_SI_e_DoorLockSts, rtu_SI_e_DoorRatSts,
                 rty_SO_b_DoorRlsReq, rty_SO_b_UnlockReq, localDW);
    if (localDW->is_RlsReq == REL_IN_Initial) {
      if ((((rtu_SI_e_EspVehSpd <= 0) && (!rtu_SI_b_EspVehSpdVld)) ||
           (rtu_SI_e_VcuGearPosn == 1)) && rtu_SI_b_DoorLockSetSts &&
          ((localDW->SI_e_DoorLockSts_prev != localDW->SI_e_DoorLockSts_start) &&
           (localDW->SI_e_DoorLockSts_start == 1))) {
        localDW->is_RlsReq = REL_IN_TRIGGER;
        localDW->temporalCounter_i1 = 0U;
        localDW->is_TRIGGER = REL_IN_Wait;
      }

      /* case IN_TRIGGER: */
    } else if (((localDW->SI_e_VcuGearPosn_prev !=
                 localDW->SI_e_VcuGearPosn_start) &&
                (localDW->SI_e_VcuGearPosn_prev == 1)) || ((rtu_SI_e_EspVehSpd >=
      5) && (!rtu_SI_b_EspVehSpdVld)) || ((localDW->temporalCounter_i1 >= 105) &&
                (rtu_SI_e_DoorLockSts == 0)) || ((rtu_SI_e_DoorLockSts == 1) &&
                (rtu_SI_e_DoorRatSts == 3))) {
      localDW->is_TRIGGER = REL_IN_NO_ACTIVE_CHILD_h;
      localDW->is_RlsReq = REL_IN_Initial;
      *rty_SO_b_DoorRlsReq = false;
    } else if (localDW->is_TRIGGER == REL_IN_RELEASE_l) {
      if (localDW->temporalCounter_i2 >= 5) {
        localDW->is_TRIGGER = REL_IN_NO_ACTIVE_CHILD_h;
        localDW->is_RlsReq = REL_IN_Initial;
        *rty_SO_b_DoorRlsReq = false;
      }

      /* case IN_Wait: */
    } else if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
      localDW->is_TRIGGER = REL_IN_RELEASE_l;
      localDW->temporalCounter_i2 = 0U;
      *rty_SO_b_DoorRlsReq = true;
    }
  }

  /* End of Chart: '<S3>/RLDoorRelease' */
}

/* Function for Chart: '<S3>/FLDoorRelease' */
static void REL_DoorIn_c(const uint8_T *SI_e_VcuGearPosn_prev_d, const boolean_T
  *SI_b_DoorInSwSts_prev_d, const boolean_T *SL_b_DoorInSwValid_prev_o)
{
  switch (REL_DW.is_SwValid_b) {
   case REL_IN_Initial_k:
    if ((*SI_b_DoorInSwSts_prev_d != REL_DW.SI_b_DoorInSwSts_start_g) &&
        REL_DW.SI_b_DoorInSwSts_start_g) {
      REL_DW.is_SwValid_b = REL_IN_ONCE_p;
      REL_DW.temporalCounter_i3_b = 0U;
    }
    break;

   case REL_IN_ONCE_p:
    if ((*SI_b_DoorInSwSts_prev_d != REL_DW.SI_b_DoorInSwSts_start_g) &&
        REL_DW.SI_b_DoorInSwSts_start_g) {
      REL_DW.is_SwValid_b = REL_IN_TWICE_h;
      REL_DW.temporalCounter_i3_b = 0U;
      REL_DW.SL_b_DoorInSwValid_n = true;
    } else if (REL_DW.temporalCounter_i3_b >= 200) {
      REL_DW.is_SwValid_b = REL_IN_Initial_k;
      REL_DW.SL_b_DoorInSwValid_n = false;
    }
    break;

   default:
    /* case IN_TWICE: */
    if (REL_DW.temporalCounter_i3_b >= 3) {
      REL_DW.is_SwValid_b = REL_IN_Initial_k;
      REL_DW.SL_b_DoorInSwValid_n = false;
    }
    break;
  }

  if (REL_DW.is_RlsReq_m == REL_IN_Initial_k) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     */
    if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
        ((*SL_b_DoorInSwValid_prev_o != REL_DW.SL_b_DoorInSwValid_start_p) &&
         REL_DW.SL_b_DoorInSwValid_start_p)) {
      REL_DW.is_RlsReq_m = REL_IN_TRIGGER_e;
      REL_DW.temporalCounter_i5_i = 0U;

      /* Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig' */
      if (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0) {
        REL_DW.is_TRIGGER_m = REL_IN_DOOR_LOCK_h;
        REL_DW.is_DOOR_LOCK_e = REL_IN_REQ_UNLOCK_a;
        REL_DW.temporalCounter_i4_g = 0U;
        REL_B.SO_b_UnlockReq_k = true;
      } else {
        REL_DW.is_TRIGGER_m = REL_IN_DOOR_UNLOCK_o;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig'
     *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
     *  Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig'
     */
    /* case IN_TRIGGER: */
  } else if (((*SI_e_VcuGearPosn_prev_d != REL_DW.SI_e_VcuGearPosn_start_i) && (*
               SI_e_VcuGearPosn_prev_d == 1)) ||
             ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 5) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
             ((REL_DW.temporalCounter_i5_i >= 105) &&
              (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) ||
             ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
              (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V == 3))) {
    REL_DW.is_DOOR_LOCK_e = REL_IN_NO_ACTIVE_CHILD_hj;
    REL_DW.is_TRIGGER_m = REL_IN_NO_ACTIVE_CHILD_hj;
    REL_DW.is_RlsReq_m = REL_IN_Initial_k;
    REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_k = false;
  } else {
    switch (REL_DW.is_TRIGGER_m) {
     case REL_IN_DOOR_LOCK_h:
      if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
          (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
        REL_DW.is_DOOR_LOCK_e = REL_IN_NO_ACTIVE_CHILD_hj;
        REL_DW.is_TRIGGER_m = REL_IN_RELEASE_p3;
        REL_DW.temporalCounter_i4_g = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
      } else {
        switch (REL_DW.is_DOOR_LOCK_e) {
         case REL_IN_FAIL_UNLOCK_b:
          break;

         case REL_IN_REQ_UNLOCK_a:
          if (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) {
            REL_DW.is_DOOR_LOCK_e = REL_IN_SUCESS_UNLOCK_b;
          } else if ((REL_DW.temporalCounter_i4_g >= 100) &&
                     (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) {
            REL_DW.is_DOOR_LOCK_e = REL_IN_FAIL_UNLOCK_b;
          }
          break;

         default:
          /* case IN_SUCESS_UNLOCK: */
          break;
        }
      }
      break;

     case REL_IN_DOOR_UNLOCK_o:
      if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
          (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
        REL_DW.is_TRIGGER_m = REL_IN_RELEASE_p3;
        REL_DW.temporalCounter_i4_g = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i4_g >= 5) {
        REL_DW.is_TRIGGER_m = REL_IN_NO_ACTIVE_CHILD_hj;
        REL_DW.is_RlsReq_m = REL_IN_Initial_k;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_k = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/FLDoorRelease' */
static void REL_DoorCent_a(const boolean_T *Compare, const uint8_T
  *SI_e_VcuGearPosn_prev_d, const boolean_T *SL_b_CentSingleDoorSwValid_pr_d,
  const boolean_T *SL_b_CentAllDoorSwValid_prev_i)
{
  if (REL_DW.is_DoorCentral_f == REL_IN_Initial_k) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     */
    if ((!*Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                         (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                        (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
        (((*SL_b_CentSingleDoorSwValid_pr_d !=
           REL_DW.SL_b_CentSingleDoorSwValid_st_a) &&
          REL_DW.SL_b_CentSingleDoorSwValid_st_a) ||
         ((*SL_b_CentAllDoorSwValid_prev_i !=
           REL_DW.SL_b_CentAllDoorSwValid_start_f) &&
          REL_DW.SL_b_CentAllDoorSwValid_start_f))) {
      REL_DW.is_DoorCentral_f = REL_IN_TRIGGER_e;
      REL_DW.temporalCounter_i12_l = 0U;

      /* Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig' */
      if (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0) {
        REL_DW.is_TRIGGER_cn = REL_IN_DOOR_LOCK_h;
        REL_DW.is_DOOR_LOCK_o = REL_IN_REQ_UNLOCK_a;
        REL_DW.temporalCounter_i11_c = 0U;
        REL_B.SO_b_UnlockReq_k = true;
      } else {
        REL_DW.is_TRIGGER_cn = REL_IN_DOOR_UNLOCK_o;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig'
     *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
     *  Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig'
     */
    /* case IN_TRIGGER: */
  } else if (((*SI_e_VcuGearPosn_prev_d != REL_DW.SI_e_VcuGearPosn_start_i) && (*
               SI_e_VcuGearPosn_prev_d == 1)) ||
             ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 5) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
             ((REL_DW.temporalCounter_i12_l >= 105) &&
              (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) ||
             ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
              (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V == 3))) {
    REL_DW.is_DOOR_LOCK_o = REL_IN_NO_ACTIVE_CHILD_hj;
    REL_DW.is_TRIGGER_cn = REL_IN_NO_ACTIVE_CHILD_hj;
    REL_DW.is_DoorCentral_f = REL_IN_Initial_k;
    REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_k = false;
  } else {
    switch (REL_DW.is_TRIGGER_cn) {
     case REL_IN_DOOR_LOCK_h:
      if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
          (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
        REL_DW.is_DOOR_LOCK_o = REL_IN_NO_ACTIVE_CHILD_hj;
        REL_DW.is_TRIGGER_cn = REL_IN_RELEASE_p3;
        REL_DW.temporalCounter_i11_c = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
      } else {
        switch (REL_DW.is_DOOR_LOCK_o) {
         case REL_IN_FAIL_UNLOCK_b:
          break;

         case REL_IN_REQ_UNLOCK_a:
          if (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) {
            REL_DW.is_DOOR_LOCK_o = REL_IN_SUCESS_UNLOCK_b;
          } else if ((REL_DW.temporalCounter_i11_c >= 100) &&
                     (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) {
            REL_DW.is_DOOR_LOCK_o = REL_IN_FAIL_UNLOCK_b;
          }
          break;

         default:
          /* case IN_SUCESS_UNLOCK: */
          break;
        }
      }
      break;

     case REL_IN_DOOR_UNLOCK_o:
      if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
          (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
        REL_DW.is_TRIGGER_cn = REL_IN_RELEASE_p3;
        REL_DW.temporalCounter_i11_c = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i11_c >= 5) {
        REL_DW.is_TRIGGER_cn = REL_IN_NO_ACTIVE_CHILD_hj;
        REL_DW.is_DoorCentral_f = REL_IN_Initial_k;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_k = false;
      }
      break;
    }
  }

  /* Inport: '<Root>/VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg' */
  REL_DW.SL_b_CentSingleDoorSwValid_m = REL_U.VbINP_CAN_CdcDrvrDoorButtonSts_;

  /* Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg' */
  REL_DW.SL_b_CentAllDoorSwValid_o = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
}

/* Function for Chart: '<S3>/FLDoorRelease' */
static void REL_DoorHand_h(const boolean_T *Compare, const uint8_T
  *SI_e_VcuGearPosn_prev_d, const boolean_T *SI_b_DoorHandSwSts_prev_p, const
  boolean_T *SL_b_DoorHandSwValid_prev_e)
{
  if (REL_DW.is_RlsReq_g == REL_IN_Initial_k) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     */
    if ((!*Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                         (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                        (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
        ((*SL_b_DoorHandSwValid_prev_e != REL_DW.SL_b_DoorHandSwValid_start_b) &&
         REL_DW.SL_b_DoorHandSwValid_start_b)) {
      REL_DW.is_RlsReq_g = REL_IN_TRIGGER_e;
      REL_DW.temporalCounter_i10_n = 0U;

      /* Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig' */
      if (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0) {
        REL_DW.is_TRIGGER_cc = REL_IN_DOOR_LOCK_h;
        REL_DW.is_DOOR_LOCK_l = REL_IN_REQ_UNLOCK_a;
        REL_DW.temporalCounter_i9_n = 0U;
        REL_B.SO_b_UnlockReq_k = true;
      } else {
        REL_DW.is_TRIGGER_cc = REL_IN_DOOR_UNLOCK_o;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig'
     *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
     *  Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig'
     */
    /* case IN_TRIGGER: */
  } else if (((*SI_e_VcuGearPosn_prev_d != REL_DW.SI_e_VcuGearPosn_start_i) && (*
               SI_e_VcuGearPosn_prev_d == 1)) ||
             ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 5) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
             ((REL_DW.temporalCounter_i10_n >= 105) &&
              (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) ||
             ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
              (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V == 3))) {
    REL_DW.is_DOOR_LOCK_l = REL_IN_NO_ACTIVE_CHILD_hj;
    REL_DW.is_TRIGGER_cc = REL_IN_NO_ACTIVE_CHILD_hj;
    REL_DW.is_RlsReq_g = REL_IN_Initial_k;
    REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_k = false;
  } else {
    switch (REL_DW.is_TRIGGER_cc) {
     case REL_IN_DOOR_LOCK_h:
      if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
          (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
        REL_DW.is_DOOR_LOCK_l = REL_IN_NO_ACTIVE_CHILD_hj;
        REL_DW.is_TRIGGER_cc = REL_IN_RELEASE_p3;
        REL_DW.temporalCounter_i9_n = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
      } else {
        switch (REL_DW.is_DOOR_LOCK_l) {
         case REL_IN_FAIL_UNLOCK_b:
          break;

         case REL_IN_REQ_UNLOCK_a:
          if (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) {
            REL_DW.is_DOOR_LOCK_l = REL_IN_SUCESS_UNLOCK_b;
          } else if ((REL_DW.temporalCounter_i9_n >= 100) &&
                     (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) {
            REL_DW.is_DOOR_LOCK_l = REL_IN_FAIL_UNLOCK_b;
          }
          break;

         default:
          /* case IN_SUCESS_UNLOCK: */
          break;
        }
      }
      break;

     case REL_IN_DOOR_UNLOCK_o:
      if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
          (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
        REL_DW.is_TRIGGER_cc = REL_IN_RELEASE_p3;
        REL_DW.temporalCounter_i9_n = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i9_n >= 5) {
        REL_DW.is_TRIGGER_cc = REL_IN_NO_ACTIVE_CHILD_hj;
        REL_DW.is_RlsReq_g = REL_IN_Initial_k;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_k = false;
      }
      break;
    }
  }

  switch (REL_DW.is_SwValid_a) {
   case REL_IN_Initial_k:
    if ((*SI_b_DoorHandSwSts_prev_p != REL_DW.SI_b_DoorHandSwSts_start_h) &&
        REL_DW.SI_b_DoorHandSwSts_start_h) {
      REL_DW.is_SwValid_a = REL_IN_Press_k;
      REL_DW.temporalCounter_i8_k = 0U;
    }
    break;

   case REL_IN_Press_k:
    if ((*SI_b_DoorHandSwSts_prev_p != REL_DW.SI_b_DoorHandSwSts_start_h) &&
        (!REL_DW.SI_b_DoorHandSwSts_start_h)) {
      REL_DW.is_SwValid_a = REL_IN_Release_n;
      REL_DW.temporalCounter_i8_k = 0U;
      REL_DW.SL_b_DoorHandSwValid_l = true;
    } else if (REL_DW.temporalCounter_i8_k >= 100) {
      REL_DW.is_SwValid_a = REL_IN_Initial_k;
      REL_DW.SL_b_DoorHandSwValid_l = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (REL_DW.temporalCounter_i8_k >= 3) {
      REL_DW.is_SwValid_a = REL_IN_Initial_k;
      REL_DW.SL_b_DoorHandSwValid_l = false;
    }
    break;
  }
}

/* Function for Chart: '<S3>/FLDoorReleaseDriver' */
static void REL_NORMAL(const boolean_T *SI_b_CinchHome_prev, const boolean_T
  *SO_b_DoorRlsReq_prev)
{
  if (REL_DW.is_NORMAL == REL_IN_ELECTRIC_DOOR_d) {
    if (REL_DW.is_MAIN_PROGRESS == REL_IN_IDLE_f) {
      /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
      REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 0U;
      if ((*SO_b_DoorRlsReq_prev != REL_DW.SO_b_DoorRlsReq_start) &&
          REL_DW.SO_b_DoorRlsReq_start) {
        REL_DW.is_MAIN_PROGRESS = REL_IN_RELEASE_i;
        REL_DW.SL_e_CheckCycle = 0U;
        REL_DW.is_RELEASE = REL_IN_INITIAL_f;
        REL_DW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
        REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = true;

        /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
        REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = false;

        /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
        REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 1U;

        /* MotorA=Release Side */
      }
    } else {
      /* case IN_RELEASE: */
      switch (REL_DW.is_RELEASE) {
       case REL_IN_CHECKING_g:
        /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
        REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 0U;

        /* Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg' */
        if ((REL_DW.temporalCounter_i1 >= 5) &&
            (!REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_)) {
          REL_DW.is_RELEASE = REL_IN_STEP2_OPEN_l;
          REL_DW.is_STEP2_OPEN = REL_IN_IDLE_fk;
          REL_DW.temporalCounter_i1 = 0U;

          /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
          REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = false;

          /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
          REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = false;
        } else if ((REL_DW.temporalCounter_i1 >= 5) &&
                   REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_ &&
                   (REL_DW.SL_e_CheckCycle < 2)) {
          REL_DW.is_RELEASE = REL_IN_INITIAL_f;
          REL_DW.temporalCounter_i1 = 0U;

          /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
          REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = true;

          /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
          REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = false;

          /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
          REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 1U;

          /* MotorA=Release Side */
        } else if ((REL_DW.temporalCounter_i1 >= 5) &&
                   REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_ &&
                   (REL_DW.SL_e_CheckCycle >= 2)) {
          REL_DW.is_RELEASE = REL_IN_RESET_l;
          REL_DW.temporalCounter_i1 = 0U;

          /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
          REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = false;

          /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
          REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = true;

          /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
          REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 2U;
        }
        break;

       case REL_IN_INITIAL_f:
        {
          /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
          REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 1U;
          if (REL_DW.temporalCounter_i1 >= 30) {
            int32_T tmp;
            REL_DW.is_RELEASE = REL_IN_CHECKING_g;
            REL_DW.temporalCounter_i1 = 0U;

            /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
            REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = false;

            /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
            REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = false;

            /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
            REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 0U;
            tmp = REL_DW.SL_e_CheckCycle + 1;
            if (REL_DW.SL_e_CheckCycle + 1 > 255) {
              tmp = 255;
            }

            REL_DW.SL_e_CheckCycle = (uint8_T)tmp;
          }
        }
        break;

       case REL_IN_RESET_l:
        /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
        REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 2U;
        if (REL_DW.temporalCounter_i1 >= 30) {
          REL_DW.is_RELEASE = REL_IN_NO_ACTIVE_CHILD_hj;
          REL_DW.is_MAIN_PROGRESS = REL_IN_IDLE_f;

          /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
          REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = false;

          /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
          REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = false;

          /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
          REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 0U;
        }
        break;

       default:
        /* case IN_STEP2_OPEN: */
        switch (REL_DW.is_STEP2_OPEN) {
         case REL_IN_ERROR_i:
          REL_DW.is_STEP2_OPEN = REL_IN_NO_ACTIVE_CHILD_hj;
          REL_DW.is_RELEASE = REL_IN_RESET_l;
          REL_DW.temporalCounter_i1 = 0U;

          /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
          REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = false;

          /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
          REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = true;

          /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
          REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 2U;
          break;

         case REL_IN_ERROR1_f:
          REL_DW.is_STEP2_OPEN = REL_IN_NO_ACTIVE_CHILD_hj;
          REL_DW.is_RELEASE = REL_IN_RESET_l;
          REL_DW.temporalCounter_i1 = 0U;

          /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
          REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = false;

          /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
          REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = true;

          /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
          REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 2U;
          break;

         case REL_IN_ICE_BREAK_f:
          if ((REL_DW.temporalCounter_i1 < 600) && ((*SI_b_CinchHome_prev !=
                REL_DW.SI_b_CinchHome_start) && (!REL_DW.SI_b_CinchHome_start)))
          {
            REL_DW.is_STEP2_OPEN = REL_IN_NO_ACTIVE_CHILD_hj;
            REL_DW.is_RELEASE = REL_IN_RESET_l;
            REL_DW.temporalCounter_i1 = 0U;

            /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
            REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = false;

            /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
            REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = true;

            /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
            REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 2U;
          } else if ((REL_DW.temporalCounter_i1 >= 600) &&
                     REL_U.VbINP_CAN_FLDCUCinchHomeSwitch_) {
            REL_DW.is_STEP2_OPEN = REL_IN_ERROR1_f;
          }
          break;

         case REL_IN_IDLE_fk:
          /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
          REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 0U;

          /* Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg' */
          if ((REL_DW.temporalCounter_i1 < 270) &&
              (!REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_)) {
            REL_DW.is_STEP2_OPEN = REL_IN_NO_ACTIVE_CHILD_hj;
            REL_DW.is_RELEASE = REL_IN_RESET_l;
            REL_DW.temporalCounter_i1 = 0U;

            /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
            REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = false;

            /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
            REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = true;

            /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
            REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 2U;
          } else if (REL_DW.temporalCounter_i1 >= 300) {
            REL_DW.is_STEP2_OPEN = REL_IN_LAST_CHECK_a;
          }
          break;

         default:
          /* Inport: '<Root>/VbINP_CAN_FLDCUCinchHomeSwitch_flg_VbINP_CAN_FLDCUCinchHomeSwitch_flg' */
          /* case IN_LAST_CHECK: */
          if (!REL_U.VbINP_CAN_FLDCUCinchHomeSwitch_) {
            REL_DW.is_STEP2_OPEN = REL_IN_ERROR_i;
          } else {
            REL_DW.is_STEP2_OPEN = REL_IN_ICE_BREAK_f;
            REL_DW.temporalCounter_i1 = 0U;
          }

          /* End of Inport: '<Root>/VbINP_CAN_FLDCUCinchHomeSwitch_flg_VbINP_CAN_FLDCUCinchHomeSwitch_flg' */
          break;
        }
        break;
      }
    }

    /* case IN_NON_ELECTRIC_DOOR: */
  } else if (REL_DW.is_MAIN_PROGRESS_k == REL_IN_IDLE_f) {
    /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
    REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 0U;
    if ((*SO_b_DoorRlsReq_prev != REL_DW.SO_b_DoorRlsReq_start) &&
        REL_DW.SO_b_DoorRlsReq_start) {
      REL_DW.is_MAIN_PROGRESS_k = REL_IN_RELEASE_i;
      REL_DW.SL_e_CheckCycle = 0U;
      REL_DW.is_RELEASE_h = REL_IN_INITIAL_f;
      REL_DW.temporalCounter_i1 = 0U;

      /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
      REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = true;

      /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
      REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = false;

      /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
      REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 1U;

      /* MotorA=Release Side */
    }
  } else {
    /* case IN_RELEASE: */
    switch (REL_DW.is_RELEASE_h) {
     case REL_IN_CHECKING_g:
      /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
      REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 0U;

      /* Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg' */
      if ((REL_DW.temporalCounter_i1 >= 5) &&
          (!REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_)) {
        REL_DW.is_RELEASE_h = REL_IN_STEP2_OPEN_l;
        REL_DW.is_STEP2_OPEN_j = REL_IN_IDLE_f;
        REL_DW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
        REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = false;

        /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
        REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = false;
      } else if ((REL_DW.temporalCounter_i1 >= 5) &&
                 REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_ &&
                 (REL_DW.SL_e_CheckCycle < 2)) {
        REL_DW.is_RELEASE_h = REL_IN_INITIAL_f;
        REL_DW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
        REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = true;

        /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
        REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = false;

        /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
        REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 1U;

        /* MotorA=Release Side */
      } else if ((REL_DW.temporalCounter_i1 >= 5) &&
                 REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_ &&
                 (REL_DW.SL_e_CheckCycle >= 2)) {
        REL_DW.is_RELEASE_h = REL_IN_RESET_l;
        REL_DW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
        REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = false;

        /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
        REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = true;

        /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
        REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 2U;
      }
      break;

     case REL_IN_INITIAL_f:
      {
        /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
        REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 1U;
        if (REL_DW.temporalCounter_i1 >= 30) {
          int32_T tmp;
          REL_DW.is_RELEASE_h = REL_IN_CHECKING_g;
          REL_DW.temporalCounter_i1 = 0U;

          /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
          REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = false;

          /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
          REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = false;

          /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
          REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 0U;
          tmp = REL_DW.SL_e_CheckCycle + 1;
          if (REL_DW.SL_e_CheckCycle + 1 > 255) {
            tmp = 255;
          }

          REL_DW.SL_e_CheckCycle = (uint8_T)tmp;
        }
      }
      break;

     case REL_IN_RESET_l:
      /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
      REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 2U;
      if (REL_DW.temporalCounter_i1 >= 30) {
        REL_DW.is_RELEASE_h = REL_IN_NO_ACTIVE_CHILD_hj;
        REL_DW.is_MAIN_PROGRESS_k = REL_IN_IDLE_f;

        /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
        REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = false;

        /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
        REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = false;

        /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
        REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 0U;
      }
      break;

     default:
      /* case IN_STEP2_OPEN: */
      if (REL_DW.is_STEP2_OPEN_j == REL_IN_IDLE_f) {
        /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
        REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 0U;

        /* Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg' */
        if ((REL_DW.temporalCounter_i1 < 270) &&
            (!REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_)) {
          REL_DW.is_STEP2_OPEN_j = REL_IN_NO_ACTIVE_CHILD_hj;
          REL_DW.is_RELEASE_h = REL_IN_RESET_l;
          REL_DW.temporalCounter_i1 = 0U;

          /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
          REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = false;

          /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
          REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = true;

          /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
          REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 2U;
        } else if (REL_DW.temporalCounter_i1 >= 300) {
          REL_DW.is_STEP2_OPEN_j = REL_IN_LAST_CHECK_ad;
        }
      } else {
        /* case IN_LAST_CHECK: */
        REL_DW.is_STEP2_OPEN_j = REL_IN_NO_ACTIVE_CHILD_hj;
        REL_DW.is_RELEASE_h = REL_IN_RESET_l;
        REL_DW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
        REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = false;

        /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
        REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = true;

        /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
        REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 2U;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/FRDoorRelease' */
static void REL_DoorIn_f(const uint8_T *SI_e_VcuGearPosn_prev, const boolean_T
  *SI_b_DoorInSwSts_prev, const boolean_T *SL_b_DoorInSwValid_prev)
{
  switch (REL_DW.is_SwValid) {
   case REL_IN_Initial_k:
    if ((*SI_b_DoorInSwSts_prev != REL_DW.SI_b_DoorInSwSts_start) &&
        REL_DW.SI_b_DoorInSwSts_start) {
      REL_DW.is_SwValid = REL_IN_ONCE_p;
      REL_DW.temporalCounter_i3 = 0U;
    }
    break;

   case REL_IN_ONCE_p:
    if ((*SI_b_DoorInSwSts_prev != REL_DW.SI_b_DoorInSwSts_start) &&
        REL_DW.SI_b_DoorInSwSts_start) {
      REL_DW.is_SwValid = REL_IN_TWICE_h;
      REL_DW.temporalCounter_i3 = 0U;
      REL_DW.SL_b_DoorInSwValid = true;
    } else if (REL_DW.temporalCounter_i3 >= 200) {
      REL_DW.is_SwValid = REL_IN_Initial_k;
      REL_DW.SL_b_DoorInSwValid = false;
    }
    break;

   default:
    /* case IN_TWICE: */
    if (REL_DW.temporalCounter_i3 >= 3) {
      REL_DW.is_SwValid = REL_IN_Initial_k;
      REL_DW.SL_b_DoorInSwValid = false;
    }
    break;
  }

  if (REL_DW.is_RlsReq_n == REL_IN_Initial_k) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     */
    if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
        ((*SL_b_DoorInSwValid_prev != REL_DW.SL_b_DoorInSwValid_start) &&
         REL_DW.SL_b_DoorInSwValid_start)) {
      REL_DW.is_RlsReq_n = REL_IN_TRIGGER_e;
      REL_DW.temporalCounter_i5 = 0U;

      /* Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig' */
      if (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0) {
        REL_DW.is_TRIGGER_f = REL_IN_DOOR_LOCK_h;
        REL_DW.is_DOOR_LOCK = REL_IN_REQ_UNLOCK_a;
        REL_DW.temporalCounter_i4 = 0U;
        REL_B.SO_b_UnlockReq_g = true;
      } else {
        REL_DW.is_TRIGGER_f = REL_IN_DOOR_UNLOCK_o;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
     *  Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg'
     *  Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig'
     */
    /* case IN_TRIGGER: */
  } else if (((*SI_e_VcuGearPosn_prev != REL_DW.SI_e_VcuGearPosn_start) &&
              (*SI_e_VcuGearPosn_prev == 1)) ||
             ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 5) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
             ((REL_DW.temporalCounter_i5 >= 105) &&
              (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0)) ||
             ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
              (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V == 3))) {
    REL_DW.is_DOOR_LOCK = REL_IN_NO_ACTIVE_CHILD_hj;
    REL_DW.is_TRIGGER_f = REL_IN_NO_ACTIVE_CHILD_hj;
    REL_DW.is_RlsReq_n = REL_IN_Initial_k;
    REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_g = false;
  } else {
    switch (REL_DW.is_TRIGGER_f) {
     case REL_IN_DOOR_LOCK_h:
      if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
          (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
        REL_DW.is_DOOR_LOCK = REL_IN_NO_ACTIVE_CHILD_hj;
        REL_DW.is_TRIGGER_f = REL_IN_RELEASE_p3;
        REL_DW.temporalCounter_i4 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
      } else {
        switch (REL_DW.is_DOOR_LOCK) {
         case REL_IN_FAIL_UNLOCK_b:
          break;

         case REL_IN_REQ_UNLOCK_a:
          if (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) {
            REL_DW.is_DOOR_LOCK = REL_IN_SUCESS_UNLOCK_b;
          } else if ((REL_DW.temporalCounter_i4 >= 100) &&
                     (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0)) {
            REL_DW.is_DOOR_LOCK = REL_IN_FAIL_UNLOCK_b;
          }
          break;

         default:
          /* case IN_SUCESS_UNLOCK: */
          break;
        }
      }
      break;

     case REL_IN_DOOR_UNLOCK_o:
      if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
          (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
        REL_DW.is_TRIGGER_f = REL_IN_RELEASE_p3;
        REL_DW.temporalCounter_i4 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i4 >= 5) {
        REL_DW.is_TRIGGER_f = REL_IN_NO_ACTIVE_CHILD_hj;
        REL_DW.is_RlsReq_n = REL_IN_Initial_k;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_g = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/FRDoorRelease' */
static void REL_DoorCent_b(const boolean_T *Compare, const uint8_T
  *SI_e_VcuGearPosn_prev, const boolean_T *SL_b_CentSingleDoorSwValid_prev,
  const boolean_T *SL_b_CentAllDoorSwValid_prev)
{
  if (REL_DW.is_DoorCentral == REL_IN_Initial_k) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     */
    if ((!*Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                         (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                        (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
        (((*SL_b_CentSingleDoorSwValid_prev !=
           REL_DW.SL_b_CentSingleDoorSwValid_star) &&
          REL_DW.SL_b_CentSingleDoorSwValid_star) ||
         ((*SL_b_CentAllDoorSwValid_prev != REL_DW.SL_b_CentAllDoorSwValid_start)
          && REL_DW.SL_b_CentAllDoorSwValid_start))) {
      REL_DW.is_DoorCentral = REL_IN_TRIGGER_e;
      REL_DW.temporalCounter_i12 = 0U;

      /* Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig' */
      if (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0) {
        REL_DW.is_TRIGGER_k = REL_IN_DOOR_LOCK_h;
        REL_DW.is_DOOR_LOCK_i = REL_IN_REQ_UNLOCK_a;
        REL_DW.temporalCounter_i11 = 0U;
        REL_B.SO_b_UnlockReq_g = true;
      } else {
        REL_DW.is_TRIGGER_k = REL_IN_DOOR_UNLOCK_o;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
     *  Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg'
     *  Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig'
     */
    /* case IN_TRIGGER: */
  } else if (((*SI_e_VcuGearPosn_prev != REL_DW.SI_e_VcuGearPosn_start) &&
              (*SI_e_VcuGearPosn_prev == 1)) ||
             ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 5) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
             ((REL_DW.temporalCounter_i12 >= 105) &&
              (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0)) ||
             ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
              (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V == 3))) {
    REL_DW.is_DOOR_LOCK_i = REL_IN_NO_ACTIVE_CHILD_hj;
    REL_DW.is_TRIGGER_k = REL_IN_NO_ACTIVE_CHILD_hj;
    REL_DW.is_DoorCentral = REL_IN_Initial_k;
    REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_g = false;
  } else {
    switch (REL_DW.is_TRIGGER_k) {
     case REL_IN_DOOR_LOCK_h:
      if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
          (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
        REL_DW.is_DOOR_LOCK_i = REL_IN_NO_ACTIVE_CHILD_hj;
        REL_DW.is_TRIGGER_k = REL_IN_RELEASE_p3;
        REL_DW.temporalCounter_i11 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
      } else {
        switch (REL_DW.is_DOOR_LOCK_i) {
         case REL_IN_FAIL_UNLOCK_b:
          break;

         case REL_IN_REQ_UNLOCK_a:
          if (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) {
            REL_DW.is_DOOR_LOCK_i = REL_IN_SUCESS_UNLOCK_b;
          } else if ((REL_DW.temporalCounter_i11 >= 100) &&
                     (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0)) {
            REL_DW.is_DOOR_LOCK_i = REL_IN_FAIL_UNLOCK_b;
          }
          break;

         default:
          /* case IN_SUCESS_UNLOCK: */
          break;
        }
      }
      break;

     case REL_IN_DOOR_UNLOCK_o:
      if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
          (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
        REL_DW.is_TRIGGER_k = REL_IN_RELEASE_p3;
        REL_DW.temporalCounter_i11 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i11 >= 5) {
        REL_DW.is_TRIGGER_k = REL_IN_NO_ACTIVE_CHILD_hj;
        REL_DW.is_DoorCentral = REL_IN_Initial_k;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_g = false;
      }
      break;
    }
  }

  /* Inport: '<Root>/VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg' */
  REL_DW.SL_b_CentSingleDoorSwValid = REL_U.VbINP_CAN_CdcPassDoorButtonSts_;

  /* Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg' */
  REL_DW.SL_b_CentAllDoorSwValid = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
}

/* Function for Chart: '<S3>/FRDoorRelease' */
static void REL_DoorHand_b(const boolean_T *Compare, const uint8_T
  *SI_e_VcuGearPosn_prev, const boolean_T *SI_b_DoorHandSwSts_prev, const
  boolean_T *SL_b_DoorHandSwValid_prev)
{
  if (REL_DW.is_RlsReq_cr == REL_IN_Initial_k) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     */
    if ((!*Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                         (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                        (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
        ((*SL_b_DoorHandSwValid_prev != REL_DW.SL_b_DoorHandSwValid_start) &&
         REL_DW.SL_b_DoorHandSwValid_start)) {
      REL_DW.is_RlsReq_cr = REL_IN_TRIGGER_e;
      REL_DW.temporalCounter_i10 = 0U;

      /* Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig' */
      if (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0) {
        REL_DW.is_TRIGGER_c = REL_IN_DOOR_LOCK_h;
        REL_DW.is_DOOR_LOCK_j = REL_IN_REQ_UNLOCK_a;
        REL_DW.temporalCounter_i9 = 0U;
        REL_B.SO_b_UnlockReq_g = true;
      } else {
        REL_DW.is_TRIGGER_c = REL_IN_DOOR_UNLOCK_o;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
     *  Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg'
     *  Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig'
     */
    /* case IN_TRIGGER: */
  } else if (((*SI_e_VcuGearPosn_prev != REL_DW.SI_e_VcuGearPosn_start) &&
              (*SI_e_VcuGearPosn_prev == 1)) ||
             ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 5) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
             ((REL_DW.temporalCounter_i10 >= 105) &&
              (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0)) ||
             ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
              (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V == 3))) {
    REL_DW.is_DOOR_LOCK_j = REL_IN_NO_ACTIVE_CHILD_hj;
    REL_DW.is_TRIGGER_c = REL_IN_NO_ACTIVE_CHILD_hj;
    REL_DW.is_RlsReq_cr = REL_IN_Initial_k;
    REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_g = false;
  } else {
    switch (REL_DW.is_TRIGGER_c) {
     case REL_IN_DOOR_LOCK_h:
      if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
          (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
        REL_DW.is_DOOR_LOCK_j = REL_IN_NO_ACTIVE_CHILD_hj;
        REL_DW.is_TRIGGER_c = REL_IN_RELEASE_p3;
        REL_DW.temporalCounter_i9 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
      } else {
        switch (REL_DW.is_DOOR_LOCK_j) {
         case REL_IN_FAIL_UNLOCK_b:
          break;

         case REL_IN_REQ_UNLOCK_a:
          if (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) {
            REL_DW.is_DOOR_LOCK_j = REL_IN_SUCESS_UNLOCK_b;
          } else if ((REL_DW.temporalCounter_i9 >= 100) &&
                     (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0)) {
            REL_DW.is_DOOR_LOCK_j = REL_IN_FAIL_UNLOCK_b;
          }
          break;

         default:
          /* case IN_SUCESS_UNLOCK: */
          break;
        }
      }
      break;

     case REL_IN_DOOR_UNLOCK_o:
      if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
          (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
        REL_DW.is_TRIGGER_c = REL_IN_RELEASE_p3;
        REL_DW.temporalCounter_i9 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i9 >= 5) {
        REL_DW.is_TRIGGER_c = REL_IN_NO_ACTIVE_CHILD_hj;
        REL_DW.is_RlsReq_cr = REL_IN_Initial_k;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_g = false;
      }
      break;
    }
  }

  switch (REL_DW.is_SwValid_i) {
   case REL_IN_Initial_k:
    if ((*SI_b_DoorHandSwSts_prev != REL_DW.SI_b_DoorHandSwSts_start) &&
        REL_DW.SI_b_DoorHandSwSts_start) {
      REL_DW.is_SwValid_i = REL_IN_Press_k;
      REL_DW.temporalCounter_i8 = 0U;
    }
    break;

   case REL_IN_Press_k:
    if ((*SI_b_DoorHandSwSts_prev != REL_DW.SI_b_DoorHandSwSts_start) &&
        (!REL_DW.SI_b_DoorHandSwSts_start)) {
      REL_DW.is_SwValid_i = REL_IN_Release_n;
      REL_DW.temporalCounter_i8 = 0U;
      REL_DW.SL_b_DoorHandSwValid = true;
    } else if (REL_DW.temporalCounter_i8 >= 100) {
      REL_DW.is_SwValid_i = REL_IN_Initial_k;
      REL_DW.SL_b_DoorHandSwValid = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (REL_DW.temporalCounter_i8 >= 3) {
      REL_DW.is_SwValid_i = REL_IN_Initial_k;
      REL_DW.SL_b_DoorHandSwValid = false;
    }
    break;
  }
}

/* Model step function for TID1 */
void REL_Step(void)                    /* Explicit Task: REL_Step */
{
  uint8_T SI_e_DoorLockSet_prev;
  uint8_T SI_e_VcuGearPosn_prev_d;
  boolean_T Compare;
  boolean_T SI_b_DoorHandSwSts_prev_p;
  boolean_T SI_b_DoorInSwSts_prev_d;
  boolean_T SL_b_CentAllDoorSwValid_prev_i;
  boolean_T SL_b_CentSingleDoorSwValid_pr_d;
  boolean_T SL_b_DoorHandSwValid_prev_e;
  boolean_T SL_b_DoorInSwValid_prev_o;
  boolean_T SL_b_DoorOutSwValid_prev_p;

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Outport: '<Root>/VeOUT_REL_BcmPassDoorSwtSts_sig_VeOUT_REL_BcmPassDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Inport: '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg'
   */
  REL_Y.VeOUT_REL_BcmPassDoorSwtSts_sig = REL_U.VbINP_HWA_FRDoorButton_flg_VbIN;

  /* RelationalOperator: '<S11>/Compare' incorporates:
   *  Constant: '<S11>/Constant'
   *  Inport: '<Root>/VeOUT_PDU_BcmPowerStatusFeedback_sig_VeOUT_PDU_BcmPowerStatusFeedback_sig'
   */
  Compare = (REL_U.VeOUT_PDU_BcmPowerStatusFeedbac == 0);

  /* Chart: '<S3>/DoorLockSetSts' incorporates:
   *  Inport: '<Root>/VeINP_CAN_CdcDrvrDoorLockSet_sig_VeINP_CAN_CdcDrvrDoorLockSet_sig'
   */
  if (REL_DW.temporalCounter_i1_c < 127U) {
    REL_DW.temporalCounter_i1_c++;
  }

  SI_e_DoorLockSet_prev = REL_DW.SI_e_DoorLockSet_start;
  REL_DW.SI_e_DoorLockSet_start = REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si;
  if (REL_DW.is_active_c1_REL == 0U) {
    REL_DW.is_active_c1_REL = 1U;

    /*  ReadEEDoorLockSet  */
    REL_DW.is_c1_REL = REL_IN_Init;
    REL_DW.temporalCounter_i1_c = 0U;

    /* Outport: '<Root>/VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg_VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg' incorporates:
     *  Inport: '<Root>/VeINP_EPRM_BdcDrvrDoorLockSetSts_sig_VeINP_EPRM_BdcDrvrDoorLockSetSts_sig'
     */
    REL_Y.VbOUT_REL_BcmAutoHeadLiSetStsTo =
      (REL_U.VeINP_EPRM_BdcDrvrDoorLockSetSt != 0);
  } else if (REL_DW.is_c1_REL == REL_IN_DoorLockSet) {
    if (SI_e_DoorLockSet_prev != REL_DW.SI_e_DoorLockSet_start) {
      /*  DoorLockSet  */
      switch (REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si) {
       case 1:
        /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
        REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = true;

        /* Outport: '<Root>/VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg_VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg' */
        REL_Y.VbOUT_REL_BcmAutoHeadLiSetStsTo = true;
        break;

       case 2:
        /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
        REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = false;

        /* Outport: '<Root>/VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg_VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg' */
        REL_Y.VbOUT_REL_BcmAutoHeadLiSetStsTo = false;
        break;

       default:
        /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' incorporates:
         *  Outport: '<Root>/VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg_VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg'
         */
        REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts =
          REL_Y.VbOUT_REL_BcmAutoHeadLiSetStsTo;
        break;
      }
    }

    /* case IN_Init: */
  } else if (REL_DW.temporalCounter_i1_c >= 100) {
    REL_DW.is_c1_REL = REL_IN_DoorLockSet;

    /*  DoorLockSet  */
    switch (REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si) {
     case 1:
      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = true;

      /* Outport: '<Root>/VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg_VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg' */
      REL_Y.VbOUT_REL_BcmAutoHeadLiSetStsTo = true;
      break;

     case 2:
      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = false;

      /* Outport: '<Root>/VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg_VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg' */
      REL_Y.VbOUT_REL_BcmAutoHeadLiSetStsTo = false;
      break;

     default:
      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' incorporates:
       *  Outport: '<Root>/VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg_VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg'
       */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts =
        REL_Y.VbOUT_REL_BcmAutoHeadLiSetStsTo;
      break;
    }
  } else {
    /* Outport: '<Root>/VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg_VbOUT_REL_BcmAutoHeadLiSetStsToEE_flg' incorporates:
     *  Inport: '<Root>/VeINP_EPRM_BdcDrvrDoorLockSetSts_sig_VeINP_EPRM_BdcDrvrDoorLockSetSts_sig'
     */
    REL_Y.VbOUT_REL_BcmAutoHeadLiSetStsTo =
      (REL_U.VeINP_EPRM_BdcDrvrDoorLockSetSt != 0);
  }

  /* End of Chart: '<S3>/DoorLockSetSts' */

  /* Truth Table: '<S3>/FLDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V);

  /* Outport: '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorOutButton_flg_VbINP_HWA_FLDoorOutButton_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_FLDoorOutButton_flg_VbINP_HWA_FLDoorOutButton_flg_read'
   */
  REL_Y.VbOUT_REL_BcmDrvrDoorHandleReq_ = REL_U.VbINP_HWA_FLDoorOutButton_flg_V;

  /* Outport: '<Root>/VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg_read'
   */
  REL_Y.VbOUT_REL_FLDoorHndlBtnSig_flg_ = REL_U.VbINP_HWA_FLDoorHandleSW_flg_Vb;

  /* Chart: '<S3>/FLDoorRelease' incorporates:
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg'
   *  Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig'
   */
  if (REL_DW.temporalCounter_i1_em < 127U) {
    REL_DW.temporalCounter_i1_em++;
  }

  if (REL_DW.temporalCounter_i2_p < 7U) {
    REL_DW.temporalCounter_i2_p++;
  }

  if (REL_DW.temporalCounter_i3_b < 255U) {
    REL_DW.temporalCounter_i3_b++;
  }

  if (REL_DW.temporalCounter_i4_g < 127U) {
    REL_DW.temporalCounter_i4_g++;
  }

  if (REL_DW.temporalCounter_i5_i < 127U) {
    REL_DW.temporalCounter_i5_i++;
  }

  if (REL_DW.temporalCounter_i6_j < 127U) {
    REL_DW.temporalCounter_i6_j++;
  }

  if (REL_DW.temporalCounter_i7_g < 127U) {
    REL_DW.temporalCounter_i7_g++;
  }

  if (REL_DW.temporalCounter_i8_k < 127U) {
    REL_DW.temporalCounter_i8_k++;
  }

  if (REL_DW.temporalCounter_i9_n < 127U) {
    REL_DW.temporalCounter_i9_n++;
  }

  if (REL_DW.temporalCounter_i10_n < 127U) {
    REL_DW.temporalCounter_i10_n++;
  }

  if (REL_DW.temporalCounter_i11_c < 127U) {
    REL_DW.temporalCounter_i11_c++;
  }

  if (REL_DW.temporalCounter_i12_l < 127U) {
    REL_DW.temporalCounter_i12_l++;
  }

  SI_e_DoorLockSet_prev = REL_DW.SI_e_DoorLockSts_start_b;
  REL_DW.SI_e_DoorLockSts_start_b = REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si;
  SI_e_VcuGearPosn_prev_d = REL_DW.SI_e_VcuGearPosn_start_i;
  REL_DW.SI_e_VcuGearPosn_start_i = REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP;
  SI_b_DoorInSwSts_prev_d = REL_DW.SI_b_DoorInSwSts_start_g;
  REL_DW.SI_b_DoorInSwSts_start_g = REL_U.VbINP_HWA_FLDoorButton_flg_VbIN;
  SL_b_DoorInSwValid_prev_o = REL_DW.SL_b_DoorInSwValid_start_p;
  REL_DW.SL_b_DoorInSwValid_start_p = REL_DW.SL_b_DoorInSwValid_n;
  SL_b_DoorOutSwValid_prev_p = REL_DW.SL_b_DoorOutSwValid_start_c;
  REL_DW.SL_b_DoorOutSwValid_start_c = REL_DW.SL_b_DoorOutSwValid_c;
  SI_b_DoorHandSwSts_prev_p = REL_DW.SI_b_DoorHandSwSts_start_h;
  REL_DW.SI_b_DoorHandSwSts_start_h = REL_Y.VbOUT_REL_FLDoorHndlBtnSig_flg_;
  SL_b_DoorHandSwValid_prev_e = REL_DW.SL_b_DoorHandSwValid_start_b;
  REL_DW.SL_b_DoorHandSwValid_start_b = REL_DW.SL_b_DoorHandSwValid_l;
  SL_b_CentSingleDoorSwValid_pr_d = REL_DW.SL_b_CentSingleDoorSwValid_st_a;
  REL_DW.SL_b_CentSingleDoorSwValid_st_a = REL_DW.SL_b_CentSingleDoorSwValid_m;
  SL_b_CentAllDoorSwValid_prev_i = REL_DW.SL_b_CentAllDoorSwValid_start_f;
  REL_DW.SL_b_CentAllDoorSwValid_start_f = REL_DW.SL_b_CentAllDoorSwValid_o;
  if (REL_DW.is_active_c5_DoorRelease_d == 0U) {
    REL_DW.is_active_c5_DoorRelease_d = 1U;
    REL_DW.is_SwValid_b = REL_IN_Initial_k;
    REL_DW.SL_b_DoorInSwValid_n = false;
    REL_DW.is_RlsReq_m = REL_IN_Initial_k;
    REL_DW.is_DoorCentral_f = REL_IN_Initial_k;
    REL_DW.SL_b_CentSingleDoorSwValid_m = REL_U.VbINP_CAN_CdcDrvrDoorButtonSts_;
    REL_DW.SL_b_CentAllDoorSwValid_o = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
    REL_DW.SL_b_DoorOutSwValid_c = REL_Y.VbOUT_REL_BcmDrvrDoorHandleReq_;
    REL_DW.is_RlsReq_b = REL_IN_Initial_k;
    REL_DW.is_RlsReq_g = REL_IN_Initial_k;
    REL_B.SO_b_UnlockReq_k = false;
    REL_DW.is_SwValid_a = REL_IN_Initial_k;
    REL_DW.SL_b_DoorHandSwValid_l = false;
    REL_DW.is_RlsReq_o = REL_IN_Initial_k;

    /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' incorporates:
     *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
     *  Inport: '<Root>/VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg'
     *  Outport: '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg'
     */
    REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
  } else {
    REL_DoorIn_c(&SI_e_VcuGearPosn_prev_d, &SI_b_DoorInSwSts_prev_d,
                 &SL_b_DoorInSwValid_prev_o);
    REL_DoorCent_a(&Compare, &SI_e_VcuGearPosn_prev_d,
                   &SL_b_CentSingleDoorSwValid_pr_d,
                   &SL_b_CentAllDoorSwValid_prev_i);
    REL_DW.SL_b_DoorOutSwValid_c = REL_Y.VbOUT_REL_BcmDrvrDoorHandleReq_;
    if (REL_DW.is_RlsReq_b == REL_IN_Initial_k) {
      if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
            (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
           (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
          ((SL_b_DoorOutSwValid_prev_p != REL_DW.SL_b_DoorOutSwValid_start_c) &&
           REL_DW.SL_b_DoorOutSwValid_start_c)) {
        REL_DW.is_RlsReq_b = REL_IN_TRIGGER_e;
        REL_DW.temporalCounter_i7_g = 0U;
        if (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0) {
          REL_DW.is_TRIGGER_cd = REL_IN_DOOR_LOCK_h;
          REL_DW.is_DOOR_LOCK_m = REL_IN_REQ_UNLOCK_a;
          REL_DW.temporalCounter_i6_j = 0U;
          REL_B.SO_b_UnlockReq_k = true;
        } else {
          REL_DW.is_TRIGGER_cd = REL_IN_DOOR_UNLOCK_o;
        }
      }

      /* case IN_TRIGGER: */
    } else if (((SI_e_VcuGearPosn_prev_d != REL_DW.SI_e_VcuGearPosn_start_i) &&
                (SI_e_VcuGearPosn_prev_d == 1)) ||
               ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 5) &&
                (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
               ((REL_DW.temporalCounter_i7_g >= 105) &&
                (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) ||
               ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
                (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V == 3))) {
      REL_DW.is_DOOR_LOCK_m = REL_IN_NO_ACTIVE_CHILD_hj;
      REL_DW.is_TRIGGER_cd = REL_IN_NO_ACTIVE_CHILD_hj;
      REL_DW.is_RlsReq_b = REL_IN_Initial_k;

      /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
      REL_B.SO_b_UnlockReq_k = false;
    } else {
      switch (REL_DW.is_TRIGGER_cd) {
       case REL_IN_DOOR_LOCK_h:
        if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
            (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
          REL_DW.is_DOOR_LOCK_m = REL_IN_NO_ACTIVE_CHILD_hj;
          REL_DW.is_TRIGGER_cd = REL_IN_RELEASE_p3;
          REL_DW.temporalCounter_i6_j = 0U;

          /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
        } else {
          switch (REL_DW.is_DOOR_LOCK_m) {
           case REL_IN_FAIL_UNLOCK_b:
            break;

           case REL_IN_REQ_UNLOCK_a:
            if (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) {
              REL_DW.is_DOOR_LOCK_m = REL_IN_SUCESS_UNLOCK_b;
            } else if ((REL_DW.temporalCounter_i6_j >= 100) &&
                       (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) {
              REL_DW.is_DOOR_LOCK_m = REL_IN_FAIL_UNLOCK_b;
            }
            break;

           default:
            /* case IN_SUCESS_UNLOCK: */
            break;
          }
        }
        break;

       case REL_IN_DOOR_UNLOCK_o:
        if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
            (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
          REL_DW.is_TRIGGER_cd = REL_IN_RELEASE_p3;
          REL_DW.temporalCounter_i6_j = 0U;

          /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
        }
        break;

       default:
        /* case IN_RELEASE: */
        if (REL_DW.temporalCounter_i6_j >= 5) {
          REL_DW.is_TRIGGER_cd = REL_IN_NO_ACTIVE_CHILD_hj;
          REL_DW.is_RlsReq_b = REL_IN_Initial_k;

          /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
          REL_B.SO_b_UnlockReq_k = false;
        }
        break;
      }
    }

    REL_DoorHand_h(&Compare, &SI_e_VcuGearPosn_prev_d,
                   &SI_b_DoorHandSwSts_prev_p, &SL_b_DoorHandSwValid_prev_e);
    if (REL_DW.is_RlsReq_o == REL_IN_Initial_k) {
      if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
            (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
           (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
          REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts && ((SI_e_DoorLockSet_prev !=
            REL_DW.SI_e_DoorLockSts_start_b) && (REL_DW.SI_e_DoorLockSts_start_b
            == 1))) {
        REL_DW.is_RlsReq_o = REL_IN_TRIGGER_e;
        REL_DW.temporalCounter_i1_em = 0U;
        REL_DW.is_TRIGGER_g = REL_IN_Wait_n;
      }

      /* case IN_TRIGGER: */
    } else if (((SI_e_VcuGearPosn_prev_d != REL_DW.SI_e_VcuGearPosn_start_i) &&
                (SI_e_VcuGearPosn_prev_d == 1)) ||
               ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 5) &&
                (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
               ((REL_DW.temporalCounter_i1_em >= 105) &&
                (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) ||
               ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
                (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V == 3))) {
      REL_DW.is_TRIGGER_g = REL_IN_NO_ACTIVE_CHILD_hj;
      REL_DW.is_RlsReq_o = REL_IN_Initial_k;

      /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
    } else if (REL_DW.is_TRIGGER_g == REL_IN_RELEASE_p) {
      if (REL_DW.temporalCounter_i2_p >= 5) {
        REL_DW.is_TRIGGER_g = REL_IN_NO_ACTIVE_CHILD_hj;
        REL_DW.is_RlsReq_o = REL_IN_Initial_k;

        /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
      }

      /* case IN_Wait: */
    } else if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
               (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
      REL_DW.is_TRIGGER_g = REL_IN_RELEASE_p;
      REL_DW.temporalCounter_i2_p = 0U;

      /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
    }
  }

  /* End of Chart: '<S3>/FLDoorRelease' */

  /* Chart: '<S3>/FLDoorReleaseDriver' incorporates:
   *  Inport: '<Root>/VbINP_CAN_FLDCUCinchHomeSwitch_flg_VbINP_CAN_FLDCUCinchHomeSwitch_flg'
   *  Inport: '<Root>/VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
   */
  if (REL_DW.temporalCounter_i1 < 1023U) {
    REL_DW.temporalCounter_i1++;
  }

  SI_b_DoorInSwSts_prev_d = REL_DW.SI_b_CinchHome_start;
  REL_DW.SI_b_CinchHome_start = REL_U.VbINP_CAN_FLDCUCinchHomeSwitch_;
  SL_b_DoorInSwValid_prev_o = REL_DW.SO_b_DoorRlsReq_start;
  REL_DW.SO_b_DoorRlsReq_start = REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU;
  if (REL_DW.is_active_c19_REL == 0U) {
    REL_DW.is_active_c19_REL = 1U;
    REL_DW.is_c19_REL = REL_IN_STARTUP_SETTING_i;
    REL_DW.temporalCounter_i1 = 0U;

    /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
    REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = false;

    /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
    REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = true;

    /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
    REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 2U;
  } else if (REL_DW.is_c19_REL == REL_IN_NORMAL_f) {
    REL_NORMAL(&SI_b_DoorInSwSts_prev_d, &SL_b_DoorInSwValid_prev_o);
  } else {
    /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
    /* case IN_STARTUP_SETTING: */
    REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 2U;
    if (REL_DW.temporalCounter_i1 >= 30) {
      REL_DW.is_c19_REL = REL_IN_NORMAL_f;
      if (REL_U.VbINP_CFG_ElectricalDoorCfg_flg) {
        REL_DW.is_NORMAL = REL_IN_ELECTRIC_DOOR_d;
        REL_DW.is_MAIN_PROGRESS = REL_IN_IDLE_f;

        /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
        REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = false;

        /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
        REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = false;

        /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
        REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 0U;
      } else {
        REL_DW.is_NORMAL = REL_IN_NON_ELECTRIC_DOOR_g;
        REL_DW.is_MAIN_PROGRESS_k = REL_IN_IDLE_f;

        /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
        REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = false;

        /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
        REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = false;

        /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
        REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 0U;
      }
    }
  }

  /* End of Chart: '<S3>/FLDoorReleaseDriver' */

  /* Truth Table: '<S3>/FRDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_FRDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V);

  /* Outport: '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg_read'
   */
  REL_Y.VbOUT_REL_BcmPassDoorHandleReq_ = REL_U.VbINP_HWA_FRDoorOutButton_flg_V;

  /* Outport: '<Root>/VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorHandleSW_flg_VbINP_HWA_FRDoorHandleSW_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_FRDoorHandleSW_flg_VbINP_HWA_FRDoorHandleSW_flg_read'
   */
  REL_Y.VbOUT_REL_FRDoorHndlBtnSig_flg_ = REL_U.VbINP_HWA_FRDoorHandleSW_flg_Vb;

  /* Chart: '<S3>/FRDoorRelease' incorporates:
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg'
   *  Outport: '<Root>/VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig'
   */
  if (REL_DW.temporalCounter_i1_e < 127U) {
    REL_DW.temporalCounter_i1_e++;
  }

  if (REL_DW.temporalCounter_i2 < 7U) {
    REL_DW.temporalCounter_i2++;
  }

  if (REL_DW.temporalCounter_i3 < 255U) {
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

  if (REL_DW.temporalCounter_i7 < 127U) {
    REL_DW.temporalCounter_i7++;
  }

  if (REL_DW.temporalCounter_i8 < 127U) {
    REL_DW.temporalCounter_i8++;
  }

  if (REL_DW.temporalCounter_i9 < 127U) {
    REL_DW.temporalCounter_i9++;
  }

  if (REL_DW.temporalCounter_i10 < 127U) {
    REL_DW.temporalCounter_i10++;
  }

  if (REL_DW.temporalCounter_i11 < 127U) {
    REL_DW.temporalCounter_i11++;
  }

  if (REL_DW.temporalCounter_i12 < 127U) {
    REL_DW.temporalCounter_i12++;
  }

  REL_DW.SI_e_DoorLockSts_start = REL_U.VeOUT_DLK_BCMPassengerDoorLockS;
  SI_e_DoorLockSet_prev = REL_DW.SI_e_VcuGearPosn_start;
  REL_DW.SI_e_VcuGearPosn_start = REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP;
  SI_b_DoorInSwSts_prev_d = REL_DW.SI_b_DoorInSwSts_start;
  REL_DW.SI_b_DoorInSwSts_start = REL_U.VbINP_HWA_FRDoorButton_flg_VbIN;
  SL_b_DoorInSwValid_prev_o = REL_DW.SL_b_DoorInSwValid_start;
  REL_DW.SL_b_DoorInSwValid_start = REL_DW.SL_b_DoorInSwValid;
  SL_b_DoorOutSwValid_prev_p = REL_DW.SL_b_DoorOutSwValid_start;
  REL_DW.SL_b_DoorOutSwValid_start = REL_DW.SL_b_DoorOutSwValid;
  SI_b_DoorHandSwSts_prev_p = REL_DW.SI_b_DoorHandSwSts_start;
  REL_DW.SI_b_DoorHandSwSts_start = REL_Y.VbOUT_REL_FRDoorHndlBtnSig_flg_;
  SL_b_DoorHandSwValid_prev_e = REL_DW.SL_b_DoorHandSwValid_start;
  REL_DW.SL_b_DoorHandSwValid_start = REL_DW.SL_b_DoorHandSwValid;
  SL_b_CentSingleDoorSwValid_pr_d = REL_DW.SL_b_CentSingleDoorSwValid_star;
  REL_DW.SL_b_CentSingleDoorSwValid_star = REL_DW.SL_b_CentSingleDoorSwValid;
  SL_b_CentAllDoorSwValid_prev_i = REL_DW.SL_b_CentAllDoorSwValid_start;
  REL_DW.SL_b_CentAllDoorSwValid_start = REL_DW.SL_b_CentAllDoorSwValid;
  if (REL_DW.is_active_c5_DoorRelease == 0U) {
    REL_DW.is_active_c5_DoorRelease = 1U;
    REL_DW.is_SwValid = REL_IN_Initial_k;
    REL_DW.SL_b_DoorInSwValid = false;
    REL_DW.is_RlsReq_n = REL_IN_Initial_k;
    REL_DW.is_DoorCentral = REL_IN_Initial_k;
    REL_DW.SL_b_CentSingleDoorSwValid = REL_U.VbINP_CAN_CdcPassDoorButtonSts_;
    REL_DW.SL_b_CentAllDoorSwValid = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
    REL_DW.SL_b_DoorOutSwValid = REL_Y.VbOUT_REL_BcmPassDoorHandleReq_;
    REL_DW.is_RlsReq_c = REL_IN_Initial_k;
    REL_DW.is_RlsReq_cr = REL_IN_Initial_k;
    REL_B.SO_b_UnlockReq_g = false;
    REL_DW.is_SwValid_i = REL_IN_Initial_k;
    REL_DW.SL_b_DoorHandSwValid = false;
    REL_DW.is_RlsReq = REL_IN_Initial_k;

    /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' incorporates:
     *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
     *  Inport: '<Root>/VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg'
     *  Outport: '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg'
     */
    REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
  } else {
    REL_DoorIn_f(&SI_e_DoorLockSet_prev, &SI_b_DoorInSwSts_prev_d,
                 &SL_b_DoorInSwValid_prev_o);
    REL_DoorCent_b(&Compare, &SI_e_DoorLockSet_prev,
                   &SL_b_CentSingleDoorSwValid_pr_d,
                   &SL_b_CentAllDoorSwValid_prev_i);
    REL_DW.SL_b_DoorOutSwValid = REL_Y.VbOUT_REL_BcmPassDoorHandleReq_;
    if (REL_DW.is_RlsReq_c == REL_IN_Initial_k) {
      if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
            (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
           (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
          ((SL_b_DoorOutSwValid_prev_p != REL_DW.SL_b_DoorOutSwValid_start) &&
           REL_DW.SL_b_DoorOutSwValid_start)) {
        REL_DW.is_RlsReq_c = REL_IN_TRIGGER_e;
        REL_DW.temporalCounter_i7 = 0U;
        if (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0) {
          REL_DW.is_TRIGGER_p = REL_IN_DOOR_LOCK_h;
          REL_DW.is_DOOR_LOCK_a = REL_IN_REQ_UNLOCK_a;
          REL_DW.temporalCounter_i6 = 0U;
          REL_B.SO_b_UnlockReq_g = true;
        } else {
          REL_DW.is_TRIGGER_p = REL_IN_DOOR_UNLOCK_o;
        }
      }

      /* case IN_TRIGGER: */
    } else if (((SI_e_DoorLockSet_prev != REL_DW.SI_e_VcuGearPosn_start) &&
                (SI_e_DoorLockSet_prev == 1)) ||
               ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 5) &&
                (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
               ((REL_DW.temporalCounter_i7 >= 105) &&
                (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0)) ||
               ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
                (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V == 3))) {
      REL_DW.is_DOOR_LOCK_a = REL_IN_NO_ACTIVE_CHILD_hj;
      REL_DW.is_TRIGGER_p = REL_IN_NO_ACTIVE_CHILD_hj;
      REL_DW.is_RlsReq_c = REL_IN_Initial_k;

      /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
      REL_B.SO_b_UnlockReq_g = false;
    } else {
      switch (REL_DW.is_TRIGGER_p) {
       case REL_IN_DOOR_LOCK_h:
        if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
            (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
          REL_DW.is_DOOR_LOCK_a = REL_IN_NO_ACTIVE_CHILD_hj;
          REL_DW.is_TRIGGER_p = REL_IN_RELEASE_p3;
          REL_DW.temporalCounter_i6 = 0U;

          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
        } else {
          switch (REL_DW.is_DOOR_LOCK_a) {
           case REL_IN_FAIL_UNLOCK_b:
            break;

           case REL_IN_REQ_UNLOCK_a:
            if (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) {
              REL_DW.is_DOOR_LOCK_a = REL_IN_SUCESS_UNLOCK_b;
            } else if ((REL_DW.temporalCounter_i6 >= 100) &&
                       (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0)) {
              REL_DW.is_DOOR_LOCK_a = REL_IN_FAIL_UNLOCK_b;
            }
            break;

           default:
            /* case IN_SUCESS_UNLOCK: */
            break;
          }
        }
        break;

       case REL_IN_DOOR_UNLOCK_o:
        if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
            (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
          REL_DW.is_TRIGGER_p = REL_IN_RELEASE_p3;
          REL_DW.temporalCounter_i6 = 0U;

          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
        }
        break;

       default:
        /* case IN_RELEASE: */
        if (REL_DW.temporalCounter_i6 >= 5) {
          REL_DW.is_TRIGGER_p = REL_IN_NO_ACTIVE_CHILD_hj;
          REL_DW.is_RlsReq_c = REL_IN_Initial_k;

          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
          REL_B.SO_b_UnlockReq_g = false;
        }
        break;
      }
    }

    REL_DoorHand_b(&Compare, &SI_e_DoorLockSet_prev, &SI_b_DoorHandSwSts_prev_p,
                   &SL_b_DoorHandSwValid_prev_e);
    if (REL_DW.is_RlsReq != REL_IN_Initial_k) {
      /* case IN_TRIGGER: */
      if (((SI_e_DoorLockSet_prev != REL_DW.SI_e_VcuGearPosn_start) &&
           (SI_e_DoorLockSet_prev == 1)) ||
          ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 5) &&
           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
          ((REL_DW.temporalCounter_i1_e >= 105) &&
           (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0)) ||
          ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
           (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V == 3))) {
        REL_DW.is_TRIGGER = REL_IN_NO_ACTIVE_CHILD_hj;
        REL_DW.is_RlsReq = REL_IN_Initial_k;

        /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
      } else if (REL_DW.is_TRIGGER == REL_IN_RELEASE_p) {
        if (REL_DW.temporalCounter_i2 >= 5) {
          REL_DW.is_TRIGGER = REL_IN_NO_ACTIVE_CHILD_hj;
          REL_DW.is_RlsReq = REL_IN_Initial_k;

          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        }

        /* case IN_Wait: */
      } else if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
                 (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
        REL_DW.is_TRIGGER = REL_IN_RELEASE_p;
        REL_DW.temporalCounter_i2 = 0U;

        /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
      }
    }
  }

  /* End of Chart: '<S3>/FRDoorRelease' */

  /* Chart: '<S3>/FRDoorReleaseDriver' incorporates:
   *  Inport: '<Root>/VbINP_CAN_FRDCUCinchHomeSwitch_flg_VbINP_CAN_FRDCUCinchHomeSwitch_flg'
   *  Inport: '<Root>/VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg'
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   *  Outport: '<Root>/VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg'
   *  Outport: '<Root>/VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg'
   *  Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig'
   */
  REL_FRDoorReleaseDriver(REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU,
    REL_U.VbINP_HWA_FRDoorAjar_flg_VbINP_, REL_U.VbINP_CAN_FRDCUCinchHomeSwitch_,
    REL_U.VbINP_CFG_ElectricalDoorCfg_flg,
    &REL_Y.VbOUT_REL_FRDoorMotorA_flg_VbOU,
    &REL_Y.VbOUT_REL_FRDoorMotorB_flg_VbOU,
    &REL_Y.VeOUT_REL_FRDoorMotorSts_sig_Ve, &SI_b_DoorInSwSts_prev_d,
    &REL_DW.sf_FRDoorReleaseDriver);

  /* Truth Table: '<S3>/RLDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLRDoorRatSts_sig_VeOUT_REL_BdcLRDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_RLDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcLRDoorRatSts_sig_V);

  /* Outport: '<Root>/VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg_read'
   */
  REL_Y.VbOUT_REL_BcmLeReDoorHandleReq_ = REL_U.VbINP_HWA_RLDoorOutButton_flg_V;

  /* Outport: '<Root>/VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg_read'
   */
  REL_Y.VbOUT_REL_RLDoorHndlBtnSig_flg_ = REL_U.VbINP_HWA_RLDoorHandleSW_flg_Vb;

  /* Chart: '<S3>/RLDoorRelease' incorporates:
   *  Constant: '<S3>/Constant10'
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcLeReDoorButtonSts_flg_VbINP_CAN_CdcLeReDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbINP_HWA_LRChildLckSt_flg_VbINP_HWA_LRChildLckSt_flg'
   *  Inport: '<Root>/VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLRDoorRatSts_sig_VeOUT_REL_BdcLRDoorRatSts_sig'
   */
  REL_RLDoorRelease(Compare, REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                    REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN,
                    REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP,
                    REL_U.VeOUT_DLK_BCMPassengerDoorLockS,
                    REL_Y.VeOUT_REL_BdcLRDoorRatSts_sig_V,
                    REL_U.VbINP_HWA_RLDoorButton_flg_VbIN,
                    REL_Y.VbOUT_REL_BcmLeReDoorHandleReq_,
                    REL_Y.VbOUT_REL_RLDoorHndlBtnSig_flg_,
                    REL_U.VbINP_CAN_CdcLeReDoorButtonSts_,
                    REL_U.VbINP_CAN_CdcAllDoorOpenButtonS,
                    REL_U.VbINP_HWA_LRChildLckSt_flg_VbIN, false,
                    &REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU,
                    &REL_B.SO_b_UnlockReq_d, &REL_DW.sf_RLDoorRelease);

  /* Truth Table: '<S3>/RRDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcRRDoorRatSts_sig_VeOUT_REL_BdcRRDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_RRDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcRRDoorRatSts_sig_V);

  /* Outport: '<Root>/VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg_read'
   */
  REL_Y.VbOUT_REL_BcmBcmRiReDoorHandleR = REL_U.VbINP_HWA_RRDoorOutButton_flg_V;

  /* Outport: '<Root>/VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorHandleSW_flg_VbINP_HWA_RRDoorHandleSW_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_RRDoorHandleSW_flg_VbINP_HWA_RRDoorHandleSW_flg_read'
   */
  REL_Y.VbOUT_REL_RRDoorHndlBtnSig_flg_ = REL_U.VbINP_HWA_RRDoorHandleSW_flg_Vb;

  /* Chart: '<S3>/RRDoorRelease' incorporates:
   *  Constant: '<S3>/Constant11'
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcRiReDoorButtonSts_flg_VbINP_CAN_CdcRiReDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbINP_HWA_RRChildLckSt_flg_VbINP_HWA_RRChildLckSt_flg'
   *  Inport: '<Root>/VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcRRDoorRatSts_sig_VeOUT_REL_BdcRRDoorRatSts_sig'
   */
  REL_RLDoorRelease(Compare, REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                    REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN,
                    REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP,
                    REL_U.VeOUT_DLK_BCMPassengerDoorLockS,
                    REL_Y.VeOUT_REL_BdcRRDoorRatSts_sig_V,
                    REL_U.VbINP_HWA_RRDoorButton_flg_VbIN,
                    REL_Y.VbOUT_REL_BcmBcmRiReDoorHandleR,
                    REL_Y.VbOUT_REL_RRDoorHndlBtnSig_flg_,
                    REL_U.VbINP_CAN_CdcRiReDoorButtonSts_,
                    REL_U.VbINP_CAN_CdcAllDoorOpenButtonS,
                    REL_U.VbINP_HWA_RRChildLckSt_flg_VbIN, false,
                    &REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU,
                    &REL_B.SO_b_UnlockReq, &REL_DW.sf_RRDoorRelease);

  /* Logic: '<S3>/Logical Operator' */
  Compare = (REL_B.SO_b_UnlockReq_g || REL_B.SO_b_UnlockReq_d ||
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
  REL_FRDoorReleaseDriver(REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU,
    REL_U.VbINP_HWA_RLDoorAjar_flg_VbINP_, REL_U.VbINP_CAN_RLDCUCinchHomeSwitch_,
    REL_U.VbINP_CFG_ElectricalDoorCfg_flg,
    &REL_Y.VbOUT_REL_RLDoorMotorA_flg_VbOU,
    &REL_Y.VbOUT_REL_RLDoorMotorB_flg_VbOU,
    &REL_Y.VeOUT_REL_RLDoorMotorSts_sig_Ve, &SI_b_DoorInSwSts_prev_d,
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
  REL_FRDoorReleaseDriver(REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU,
    REL_U.VbINP_HWA_RRDoorAjar_flg_VbINP_, REL_U.VbINP_CAN_RRDCUCinchHomeSwitch_,
    REL_U.VbINP_CFG_ElectricalDoorCfg_flg,
    &REL_Y.VbOUT_REL_RRDoorMotorA_flg_VbOU,
    &REL_Y.VbOUT_REL_RRDoorMotorB_flg_VbOU,
    &REL_Y.VeOUT_REL_RRDoorMotorSts_sig_Ve, &SI_b_DoorInSwSts_prev_d,
    &REL_DW.sf_RLDoorReleaseDriver1);

  /* Chart: '<S3>/Unlock_Request' */
  SI_b_DoorInSwSts_prev_d = REL_DW.SI_b_DrvUnlockReq_start;
  REL_DW.SI_b_DrvUnlockReq_start = REL_B.SO_b_UnlockReq_k;
  SL_b_DoorInSwValid_prev_o = REL_DW.SI_b_PassUnlockReq_start;
  REL_DW.SI_b_PassUnlockReq_start = Compare;
  if (REL_DW.is_active_c6_REL == 0U) {
    REL_DW.is_active_c6_REL = 1U;
    REL_DW.is_c6_REL = REL_IN_Initial_k;

    /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
    REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 0U;
  } else if (REL_DW.is_c6_REL == REL_IN_Initial_k) {
    if (((SI_b_DoorInSwSts_prev_d != REL_DW.SI_b_DrvUnlockReq_start) &&
         REL_DW.SI_b_DrvUnlockReq_start) || ((SL_b_DoorInSwValid_prev_o !=
          REL_DW.SI_b_PassUnlockReq_start) && REL_DW.SI_b_PassUnlockReq_start))
    {
      REL_DW.is_c6_REL = REL_IN_REQ_SENT;
    }
  } else {
    /* case IN_REQ_SENT: */
    SI_b_DoorInSwSts_prev_d = !Compare;
    SL_b_DoorInSwValid_prev_o = !REL_B.SO_b_UnlockReq_k;
    if (SL_b_DoorInSwValid_prev_o && SI_b_DoorInSwSts_prev_d) {
      REL_DW.is_c6_REL = REL_IN_Initial_k;

      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 0U;
    } else if (REL_B.SO_b_UnlockReq_k && Compare) {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 3U;
    } else if (REL_B.SO_b_UnlockReq_k && SI_b_DoorInSwSts_prev_d) {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 1U;
    } else if (SL_b_DoorInSwValid_prev_o && Compare) {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 2U;
    } else {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 0U;
    }
  }

  /* End of Chart: '<S3>/Unlock_Request' */

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
    boolean_T SO_b_Error_j;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
     *  SubSystem: '<Root>/REL_Step_sys'
     */

    /* SystemInitialize for Chart: '<S3>/FRDoorReleaseDriver' incorporates:
     *  Outport: '<Root>/VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg'
     *  Outport: '<Root>/VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg'
     *  Outport: '<Root>/VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig'
     */
    REL_FRDoorReleaseDriver_Init(&REL_Y.VbOUT_REL_FRDoorMotorA_flg_VbOU,
      &REL_Y.VbOUT_REL_FRDoorMotorB_flg_VbOU,
      &REL_Y.VeOUT_REL_FRDoorMotorSts_sig_Ve, &SO_b_Error_j);

    /* SystemInitialize for Chart: '<S3>/RLDoorRelease' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg'
     */
    REL_RLDoorRelease_Init(&REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU,
      &REL_B.SO_b_UnlockReq_d);

    /* SystemInitialize for Chart: '<S3>/RLDoorReleaseDriver' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg'
     *  Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg'
     *  Outport: '<Root>/VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig'
     */
    REL_FRDoorReleaseDriver_Init(&REL_Y.VbOUT_REL_RLDoorMotorA_flg_VbOU,
      &REL_Y.VbOUT_REL_RLDoorMotorB_flg_VbOU,
      &REL_Y.VeOUT_REL_RLDoorMotorSts_sig_Ve, &SO_b_Error_j);

    /* SystemInitialize for Chart: '<S3>/RLDoorReleaseDriver1' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg'
     *  Outport: '<Root>/VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg'
     *  Outport: '<Root>/VeOUT_REL_RRDoorMotorSts_sig_VeOUT_REL_RRDoorMotorSts_sig'
     */
    REL_FRDoorReleaseDriver_Init(&REL_Y.VbOUT_REL_RRDoorMotorA_flg_VbOU,
      &REL_Y.VbOUT_REL_RRDoorMotorB_flg_VbOU,
      &REL_Y.VeOUT_REL_RRDoorMotorSts_sig_Ve, &SO_b_Error_j);

    /* SystemInitialize for Chart: '<S3>/RRDoorRelease' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg'
     */
    REL_RLDoorRelease_Init(&REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU,
      &REL_B.SO_b_UnlockReq);

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
