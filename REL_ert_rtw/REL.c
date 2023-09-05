/*
 * File: REL.c
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.272
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Sep  5 09:51:43 2023
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
#define REL_IN_CHECKING                ((uint8_T)1U)
#define REL_IN_ELECTRIC_DOOR           ((uint8_T)1U)
#define REL_IN_ERROR                   ((uint8_T)1U)
#define REL_IN_ERROR1                  ((uint8_T)2U)
#define REL_IN_ICE_BREAK               ((uint8_T)3U)
#define REL_IN_IDLE                    ((uint8_T)1U)
#define REL_IN_IDLE_j                  ((uint8_T)4U)
#define REL_IN_INITIAL                 ((uint8_T)2U)
#define REL_IN_LAST_CHECK              ((uint8_T)5U)
#define REL_IN_LAST_CHECK_b            ((uint8_T)2U)
#define REL_IN_NON_ELECTRIC_DOOR       ((uint8_T)2U)
#define REL_IN_NORMAL                  ((uint8_T)1U)
#define REL_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define REL_IN_RELEASE                 ((uint8_T)2U)
#define REL_IN_RESET                   ((uint8_T)3U)
#define REL_IN_STARTUP_SETTING         ((uint8_T)2U)
#define REL_IN_STEP2_OPEN              ((uint8_T)4U)

/* Named constants for Chart: '<S3>/RLDoorRlsReq' */
#define REL_IN_DOOR_LOCK               ((uint8_T)1U)
#define REL_IN_DOOR_UNLOCK             ((uint8_T)2U)
#define REL_IN_FAIL_UNLOCK             ((uint8_T)1U)
#define REL_IN_Initial                 ((uint8_T)1U)
#define REL_IN_NO_ACTIVE_CHILD_i       ((uint8_T)0U)
#define REL_IN_ONCE                    ((uint8_T)2U)
#define REL_IN_Press                   ((uint8_T)2U)
#define REL_IN_RELEASE_k               ((uint8_T)1U)
#define REL_IN_RELEASE_kx              ((uint8_T)3U)
#define REL_IN_REQ_UNLOCK              ((uint8_T)2U)
#define REL_IN_Release                 ((uint8_T)3U)
#define REL_IN_SUCESS_UNLOCK           ((uint8_T)3U)
#define REL_IN_TRIGGER                 ((uint8_T)2U)
#define REL_IN_TWICE                   ((uint8_T)3U)
#define REL_IN_Wait                    ((uint8_T)2U)

/* Named constants for Chart: '<S3>/DoorLockSetSts' */
#define REL_IN_DoorLockSet             ((uint8_T)1U)
#define REL_IN_Init                    ((uint8_T)2U)
#define REL_IN_NO_ACTIVE_CHILD_h       ((uint8_T)0U)

/* Named constants for Chart: '<S3>/FLDoorRlsReq' */
#define REL_IN_DOOR_LOCK_c             ((uint8_T)1U)
#define REL_IN_DOOR_UNLOCK_h           ((uint8_T)2U)
#define REL_IN_FAIL_UNLOCK_m           ((uint8_T)1U)
#define REL_IN_Initial_i               ((uint8_T)1U)
#define REL_IN_ONCE_n                  ((uint8_T)2U)
#define REL_IN_Press_p                 ((uint8_T)2U)
#define REL_IN_RELEASE_n               ((uint8_T)1U)
#define REL_IN_RELEASE_nr              ((uint8_T)3U)
#define REL_IN_REQ_UNLOCK_o            ((uint8_T)2U)
#define REL_IN_Release_d               ((uint8_T)3U)
#define REL_IN_SUCESS_UNLOCK_n         ((uint8_T)3U)
#define REL_IN_TRIGGER_m               ((uint8_T)2U)
#define REL_IN_TWICE_c                 ((uint8_T)3U)
#define REL_IN_Wait_g                  ((uint8_T)2U)

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
static void REL_NORMAL(Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_CinchHome,
  boolean_T *rty_SO_b_MotorA, boolean_T *rty_SO_b_MotorB, uint8_T
  *rty_SO_e_MotorMode, boolean_T *rty_SO_b_Error, uint8_T *rty_SO_e_MotorPwm,
  DW_FLDoorRlsDriver_REL_T *localDW);

/* Forward declaration for local functions */
static void REL_DoorIn(UInt8 rtu_SI_e_EspVehSpd, Boolean rtu_SI_b_EspVehSpdVld,
  UInt8 rtu_SI_e_VcuGearPosn, UInt8 rtu_SI_e_DoorLockSts, uint8_T
  rtu_SI_e_DoorRatSts, Boolean rtu_SI_b_ChildLckSts, boolean_T
  *rty_SO_b_DoorRlsReq, boolean_T *rty_SO_b_UnlockReq, DW_RLDoorRlsReq_REL_T
  *localDW);
static void REL_DoorCent(boolean_T rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd,
  Boolean rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8
  rtu_SI_e_DoorLockSts, uint8_T rtu_SI_e_DoorRatSts, Boolean
  rtu_SI_b_CentSingleDoorSwSts, Boolean rtu_SI_b_CentAllDoorSwSts, boolean_T
  *rty_SO_b_DoorRlsReq, boolean_T *rty_SO_b_UnlockReq, DW_RLDoorRlsReq_REL_T
  *localDW);
static void REL_DoorHand(boolean_T rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd,
  Boolean rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8
  rtu_SI_e_DoorLockSts, uint8_T rtu_SI_e_DoorRatSts, boolean_T
  *rty_SO_b_DoorRlsReq, boolean_T *rty_SO_b_UnlockReq, DW_RLDoorRlsReq_REL_T
  *localDW);

/* Forward declaration for local functions */
static void REL_DoorIn_l(const uint8_T *SI_e_VcuGearPosn_prev_i, const boolean_T
  *SI_b_DoorInSwSts_prev_m, const boolean_T *SL_b_DoorInSwValid_prev_i);
static void REL_DoorCent_g(const boolean_T *Compare, const uint8_T
  *SI_e_VcuGearPosn_prev_i, const boolean_T *SL_b_CentSingleDoorSwValid_pr_a,
  const boolean_T *SL_b_CentAllDoorSwValid_prev_n);
static void REL_DoorHand_k(const boolean_T *Compare, const uint8_T
  *SI_e_VcuGearPosn_prev_i, const boolean_T *SI_b_DoorHandSwSts_prev_i, const
  boolean_T *SL_b_DoorHandSwValid_prev_n);
static void REL_DoorIn_e(const uint8_T *SI_e_VcuGearPosn_prev, const boolean_T
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

/* Function for Chart: '<S3>/FLDoorRlsDriver' */
static void REL_NORMAL(Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_CinchHome,
  boolean_T *rty_SO_b_MotorA, boolean_T *rty_SO_b_MotorB, uint8_T
  *rty_SO_e_MotorMode, boolean_T *rty_SO_b_Error, uint8_T *rty_SO_e_MotorPwm,
  DW_FLDoorRlsDriver_REL_T *localDW)
{
  if (localDW->is_NORMAL == REL_IN_ELECTRIC_DOOR) {
    if (localDW->is_MAIN_PROGRESS == REL_IN_IDLE) {
      *rty_SO_e_MotorMode = 0U;
      if ((localDW->SO_b_DoorRlsReq_prev != localDW->SO_b_DoorRlsReq_start) &&
          localDW->SO_b_DoorRlsReq_start) {
        localDW->is_MAIN_PROGRESS = REL_IN_RELEASE;
        localDW->SL_e_CheckCycle = 0U;
        *rty_SO_e_MotorPwm = 100U;
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
        *rty_SO_e_MotorMode = 0U;
        if ((localDW->temporalCounter_i1 >= 5) && (!rtu_SI_b_DoorAjar)) {
          localDW->is_RELEASE = REL_IN_STEP2_OPEN;
          localDW->is_STEP2_OPEN = REL_IN_IDLE_j;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorMode = 0U;
        } else if ((localDW->temporalCounter_i1 >= 5) && rtu_SI_b_DoorAjar &&
                   (localDW->SL_e_CheckCycle < 2)) {
          *rty_SO_e_MotorPwm = 80U;
          localDW->is_RELEASE = REL_IN_INITIAL;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = true;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorMode = 1U;

          /* MotorA=Release Side */
        } else if ((localDW->temporalCounter_i1 >= 5) && rtu_SI_b_DoorAjar &&
                   (localDW->SL_e_CheckCycle >= 2)) {
          localDW->is_RELEASE = REL_IN_RESET;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorMode = 2U;
          *rty_SO_e_MotorPwm = 70U;
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
          *rty_SO_e_MotorPwm = 0U;
          *rty_SO_b_Error = false;
        }
        break;

       default:
        /* case IN_STEP2_OPEN: */
        switch (localDW->is_STEP2_OPEN) {
         case REL_IN_ERROR:
          localDW->is_STEP2_OPEN = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_RELEASE = REL_IN_RESET;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorMode = 2U;
          *rty_SO_e_MotorPwm = 70U;
          break;

         case REL_IN_ERROR1:
          localDW->is_STEP2_OPEN = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_RELEASE = REL_IN_RESET;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorMode = 2U;
          *rty_SO_e_MotorPwm = 70U;
          break;

         case REL_IN_ICE_BREAK:
          if ((localDW->temporalCounter_i1 < 600) &&
              ((localDW->SI_b_CinchHome_prev != localDW->SI_b_CinchHome_start) &&
               (!localDW->SI_b_CinchHome_start))) {
            localDW->is_STEP2_OPEN = REL_IN_NO_ACTIVE_CHILD;
            localDW->is_RELEASE = REL_IN_RESET;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = true;
            *rty_SO_e_MotorMode = 2U;
            *rty_SO_e_MotorPwm = 70U;
          } else if ((localDW->temporalCounter_i1 >= 600) && rtu_SI_b_CinchHome)
          {
            localDW->is_STEP2_OPEN = REL_IN_ERROR1;
            *rty_SO_b_Error = true;
          }
          break;

         case REL_IN_IDLE_j:
          *rty_SO_e_MotorMode = 0U;
          if ((localDW->temporalCounter_i1 < 270) && (!rtu_SI_b_DoorAjar)) {
            localDW->is_STEP2_OPEN = REL_IN_NO_ACTIVE_CHILD;
            localDW->is_RELEASE = REL_IN_RESET;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = true;
            *rty_SO_e_MotorMode = 2U;
            *rty_SO_e_MotorPwm = 70U;
          } else if (localDW->temporalCounter_i1 >= 300) {
            localDW->is_STEP2_OPEN = REL_IN_LAST_CHECK;
          }
          break;

         default:
          /* case IN_LAST_CHECK: */
          if (!rtu_SI_b_CinchHome) {
            localDW->is_STEP2_OPEN = REL_IN_ERROR;
            *rty_SO_b_Error = true;
          } else {
            localDW->is_STEP2_OPEN = REL_IN_ICE_BREAK;
            localDW->temporalCounter_i1 = 0U;
          }
          break;
        }
        break;
      }
    }

    /* case IN_NON_ELECTRIC_DOOR: */
  } else if (localDW->is_MAIN_PROGRESS_f == REL_IN_IDLE) {
    *rty_SO_e_MotorMode = 0U;
    if ((localDW->SO_b_DoorRlsReq_prev != localDW->SO_b_DoorRlsReq_start) &&
        localDW->SO_b_DoorRlsReq_start) {
      localDW->is_MAIN_PROGRESS_f = REL_IN_RELEASE;
      localDW->SL_e_CheckCycle = 0U;
      *rty_SO_e_MotorPwm = 100U;
      localDW->is_RELEASE_k = REL_IN_INITIAL;
      localDW->temporalCounter_i1 = 0U;
      *rty_SO_b_MotorA = true;
      *rty_SO_b_MotorB = false;
      *rty_SO_e_MotorMode = 1U;

      /* MotorA=Release Side */
    }
  } else {
    /* case IN_RELEASE: */
    switch (localDW->is_RELEASE_k) {
     case REL_IN_CHECKING:
      *rty_SO_e_MotorMode = 0U;
      if ((localDW->temporalCounter_i1 >= 5) && (!rtu_SI_b_DoorAjar)) {
        localDW->is_RELEASE_k = REL_IN_STEP2_OPEN;
        localDW->is_STEP2_OPEN_p = REL_IN_IDLE;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_MotorA = false;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorMode = 0U;
      } else if ((localDW->temporalCounter_i1 >= 5) && rtu_SI_b_DoorAjar &&
                 (localDW->SL_e_CheckCycle < 2)) {
        *rty_SO_e_MotorPwm = 80U;
        localDW->is_RELEASE_k = REL_IN_INITIAL;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_MotorA = true;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorMode = 1U;

        /* MotorA=Release Side */
      } else if ((localDW->temporalCounter_i1 >= 5) && rtu_SI_b_DoorAjar &&
                 (localDW->SL_e_CheckCycle >= 2)) {
        localDW->is_RELEASE_k = REL_IN_RESET;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_MotorA = false;
        *rty_SO_b_MotorB = true;
        *rty_SO_e_MotorMode = 2U;
        *rty_SO_e_MotorPwm = 70U;
      }
      break;

     case REL_IN_INITIAL:
      {
        *rty_SO_e_MotorMode = 1U;
        if (localDW->temporalCounter_i1 >= 30) {
          int32_T tmp;
          localDW->is_RELEASE_k = REL_IN_CHECKING;
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
        localDW->is_RELEASE_k = REL_IN_NO_ACTIVE_CHILD;
        localDW->is_MAIN_PROGRESS_f = REL_IN_IDLE;
        *rty_SO_b_MotorA = false;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorMode = 0U;
        *rty_SO_e_MotorPwm = 0U;
      }
      break;

     default:
      /* case IN_STEP2_OPEN: */
      if (localDW->is_STEP2_OPEN_p == REL_IN_IDLE) {
        *rty_SO_e_MotorMode = 0U;
        if ((localDW->temporalCounter_i1 < 270) && (!rtu_SI_b_DoorAjar)) {
          localDW->is_STEP2_OPEN_p = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_RELEASE_k = REL_IN_RESET;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorMode = 2U;
          *rty_SO_e_MotorPwm = 70U;
        } else if (localDW->temporalCounter_i1 >= 300) {
          localDW->is_STEP2_OPEN_p = REL_IN_LAST_CHECK_b;
        }
      } else {
        /* case IN_LAST_CHECK: */
        localDW->is_STEP2_OPEN_p = REL_IN_NO_ACTIVE_CHILD;
        localDW->is_RELEASE_k = REL_IN_RESET;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_MotorA = false;
        *rty_SO_b_MotorB = true;
        *rty_SO_e_MotorMode = 2U;
        *rty_SO_e_MotorPwm = 70U;
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
  rtu_SI_b_DoorAjar, Boolean rtu_SI_b_CinchHome, Boolean rtu_SI_b_ElecDoorCfg,
  boolean_T *rty_SO_b_MotorA, boolean_T *rty_SO_b_MotorB, uint8_T
  *rty_SO_e_MotorMode, boolean_T *rty_SO_b_Error, uint8_T *rty_SO_e_MotorPwm,
  DW_FLDoorRlsDriver_REL_T *localDW)
{
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  localDW->SI_b_CinchHome_prev = localDW->SI_b_CinchHome_start;
  localDW->SI_b_CinchHome_start = rtu_SI_b_CinchHome;
  localDW->SO_b_DoorRlsReq_prev = localDW->SO_b_DoorRlsReq_start;
  localDW->SO_b_DoorRlsReq_start = rtu_SO_b_DoorRlsReq;

  /* Chart: '<S3>/FLDoorRlsDriver' */
  if (localDW->is_active_c19_DoorRlsDriver == 0U) {
    localDW->SI_b_CinchHome_prev = rtu_SI_b_CinchHome;
    localDW->SO_b_DoorRlsReq_prev = rtu_SO_b_DoorRlsReq;
    localDW->is_active_c19_DoorRlsDriver = 1U;
    localDW->is_c19_DoorRlsDriver = REL_IN_STARTUP_SETTING;
    localDW->temporalCounter_i1 = 0U;
    *rty_SO_b_MotorA = false;
    *rty_SO_b_MotorB = true;
    *rty_SO_e_MotorMode = 2U;
    *rty_SO_e_MotorPwm = 100U;
  } else if (localDW->is_c19_DoorRlsDriver == REL_IN_NORMAL) {
    REL_NORMAL(rtu_SI_b_DoorAjar, rtu_SI_b_CinchHome, rty_SO_b_MotorA,
               rty_SO_b_MotorB, rty_SO_e_MotorMode, rty_SO_b_Error,
               rty_SO_e_MotorPwm, localDW);
  } else {
    /* case IN_STARTUP_SETTING: */
    *rty_SO_e_MotorMode = 2U;
    if (localDW->temporalCounter_i1 >= 30) {
      localDW->is_c19_DoorRlsDriver = REL_IN_NORMAL;
      if (rtu_SI_b_ElecDoorCfg) {
        localDW->is_NORMAL = REL_IN_ELECTRIC_DOOR;
        localDW->is_MAIN_PROGRESS = REL_IN_IDLE;
        *rty_SO_b_MotorA = false;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorMode = 0U;
        *rty_SO_e_MotorPwm = 0U;
        *rty_SO_b_Error = false;
      } else {
        localDW->is_NORMAL = REL_IN_NON_ELECTRIC_DOOR;
        localDW->is_MAIN_PROGRESS_f = REL_IN_IDLE;
        *rty_SO_b_MotorA = false;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorMode = 0U;
        *rty_SO_e_MotorPwm = 0U;
      }
    }
  }

  /* End of Chart: '<S3>/FLDoorRlsDriver' */
}

/* Function for Chart: '<S3>/RLDoorRlsReq' */
static void REL_DoorIn(UInt8 rtu_SI_e_EspVehSpd, Boolean rtu_SI_b_EspVehSpdVld,
  UInt8 rtu_SI_e_VcuGearPosn, UInt8 rtu_SI_e_DoorLockSts, uint8_T
  rtu_SI_e_DoorRatSts, Boolean rtu_SI_b_ChildLckSts, boolean_T
  *rty_SO_b_DoorRlsReq, boolean_T *rty_SO_b_UnlockReq, DW_RLDoorRlsReq_REL_T
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

  if (localDW->is_RlsReq_o == REL_IN_Initial) {
    if ((((rtu_SI_e_EspVehSpd <= 0) && (!rtu_SI_b_EspVehSpdVld)) ||
         (rtu_SI_e_VcuGearPosn == 1)) && ((localDW->SL_b_DoorInSwValid_prev !=
          localDW->SL_b_DoorInSwValid_start) &&
         localDW->SL_b_DoorInSwValid_start)) {
      localDW->is_RlsReq_o = REL_IN_TRIGGER;
      localDW->temporalCounter_i5 = 0U;
      if (rtu_SI_e_DoorLockSts == 0) {
        localDW->is_TRIGGER_h = REL_IN_DOOR_LOCK;
        localDW->is_DOOR_LOCK = REL_IN_REQ_UNLOCK;
        localDW->temporalCounter_i4 = 0U;
        *rty_SO_b_UnlockReq = true;
      } else {
        localDW->is_TRIGGER_h = REL_IN_DOOR_UNLOCK;
      }
    }

    /* case IN_TRIGGER: */
  } else if (((localDW->SI_e_VcuGearPosn_prev != localDW->SI_e_VcuGearPosn_start)
              && (localDW->SI_e_VcuGearPosn_prev == 1)) || ((rtu_SI_e_EspVehSpd >=
    5) && (!rtu_SI_b_EspVehSpdVld)) || ((localDW->temporalCounter_i5 >= 105) &&
              (rtu_SI_e_DoorLockSts == 0)) || ((rtu_SI_e_DoorLockSts == 1) &&
              (rtu_SI_e_DoorRatSts == 3))) {
    localDW->is_DOOR_LOCK = REL_IN_NO_ACTIVE_CHILD_i;
    localDW->is_TRIGGER_h = REL_IN_NO_ACTIVE_CHILD_i;
    localDW->is_RlsReq_o = REL_IN_Initial;
    *rty_SO_b_DoorRlsReq = false;
    *rty_SO_b_UnlockReq = false;
  } else {
    switch (localDW->is_TRIGGER_h) {
     case REL_IN_DOOR_LOCK:
      if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
        localDW->is_DOOR_LOCK = REL_IN_NO_ACTIVE_CHILD_i;
        localDW->is_TRIGGER_h = REL_IN_RELEASE_kx;
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
        localDW->is_TRIGGER_h = REL_IN_RELEASE_kx;
        localDW->temporalCounter_i4 = 0U;
        *rty_SO_b_DoorRlsReq = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (localDW->temporalCounter_i4 >= 5) {
        localDW->is_TRIGGER_h = REL_IN_NO_ACTIVE_CHILD_i;
        localDW->is_RlsReq_o = REL_IN_Initial;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/RLDoorRlsReq' */
static void REL_DoorCent(boolean_T rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd,
  Boolean rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8
  rtu_SI_e_DoorLockSts, uint8_T rtu_SI_e_DoorRatSts, Boolean
  rtu_SI_b_CentSingleDoorSwSts, Boolean rtu_SI_b_CentAllDoorSwSts, boolean_T
  *rty_SO_b_DoorRlsReq, boolean_T *rty_SO_b_UnlockReq, DW_RLDoorRlsReq_REL_T
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
        localDW->is_TRIGGER_l = REL_IN_DOOR_LOCK;
        localDW->is_DOOR_LOCK_f = REL_IN_REQ_UNLOCK;
        localDW->temporalCounter_i11 = 0U;
        *rty_SO_b_UnlockReq = true;
      } else {
        localDW->is_TRIGGER_l = REL_IN_DOOR_UNLOCK;
      }
    }

    /* case IN_TRIGGER: */
  } else if (((localDW->SI_e_VcuGearPosn_prev != localDW->SI_e_VcuGearPosn_start)
              && (localDW->SI_e_VcuGearPosn_prev == 1)) || ((rtu_SI_e_EspVehSpd >=
    5) && (!rtu_SI_b_EspVehSpdVld)) || ((localDW->temporalCounter_i12 >= 105) &&
              (rtu_SI_e_DoorLockSts == 0)) || ((rtu_SI_e_DoorLockSts == 1) &&
              (rtu_SI_e_DoorRatSts == 3))) {
    localDW->is_DOOR_LOCK_f = REL_IN_NO_ACTIVE_CHILD_i;
    localDW->is_TRIGGER_l = REL_IN_NO_ACTIVE_CHILD_i;
    localDW->is_DoorCentral = REL_IN_Initial;
    *rty_SO_b_DoorRlsReq = false;
    *rty_SO_b_UnlockReq = false;
  } else {
    switch (localDW->is_TRIGGER_l) {
     case REL_IN_DOOR_LOCK:
      if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
        localDW->is_DOOR_LOCK_f = REL_IN_NO_ACTIVE_CHILD_i;
        localDW->is_TRIGGER_l = REL_IN_RELEASE_kx;
        localDW->temporalCounter_i11 = 0U;
        *rty_SO_b_DoorRlsReq = true;
      } else {
        switch (localDW->is_DOOR_LOCK_f) {
         case REL_IN_FAIL_UNLOCK:
          break;

         case REL_IN_REQ_UNLOCK:
          if (rtu_SI_e_DoorLockSts == 1) {
            localDW->is_DOOR_LOCK_f = REL_IN_SUCESS_UNLOCK;
          } else if ((localDW->temporalCounter_i11 >= 100) &&
                     (rtu_SI_e_DoorLockSts == 0)) {
            localDW->is_DOOR_LOCK_f = REL_IN_FAIL_UNLOCK;
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
        localDW->is_TRIGGER_l = REL_IN_RELEASE_kx;
        localDW->temporalCounter_i11 = 0U;
        *rty_SO_b_DoorRlsReq = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (localDW->temporalCounter_i11 >= 5) {
        localDW->is_TRIGGER_l = REL_IN_NO_ACTIVE_CHILD_i;
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

/* Function for Chart: '<S3>/RLDoorRlsReq' */
static void REL_DoorHand(boolean_T rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd,
  Boolean rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8
  rtu_SI_e_DoorLockSts, uint8_T rtu_SI_e_DoorRatSts, boolean_T
  *rty_SO_b_DoorRlsReq, boolean_T *rty_SO_b_UnlockReq, DW_RLDoorRlsReq_REL_T
  *localDW)
{
  if (localDW->is_RlsReq_f == REL_IN_Initial) {
    if ((!rtu_SI_b_OFF) && (((rtu_SI_e_EspVehSpd <= 0) &&
          (!rtu_SI_b_EspVehSpdVld)) || (rtu_SI_e_VcuGearPosn == 1)) &&
        ((localDW->SL_b_DoorHandSwValid_prev !=
          localDW->SL_b_DoorHandSwValid_start) &&
         localDW->SL_b_DoorHandSwValid_start)) {
      localDW->is_RlsReq_f = REL_IN_TRIGGER;
      localDW->temporalCounter_i10 = 0U;
      if (rtu_SI_e_DoorLockSts == 0) {
        localDW->is_TRIGGER_p = REL_IN_DOOR_LOCK;
        localDW->is_DOOR_LOCK_n = REL_IN_REQ_UNLOCK;
        localDW->temporalCounter_i9 = 0U;
        *rty_SO_b_UnlockReq = true;
      } else {
        localDW->is_TRIGGER_p = REL_IN_DOOR_UNLOCK;
      }
    }

    /* case IN_TRIGGER: */
  } else if (((localDW->SI_e_VcuGearPosn_prev != localDW->SI_e_VcuGearPosn_start)
              && (localDW->SI_e_VcuGearPosn_prev == 1)) || ((rtu_SI_e_EspVehSpd >=
    5) && (!rtu_SI_b_EspVehSpdVld)) || ((localDW->temporalCounter_i10 >= 105) &&
              (rtu_SI_e_DoorLockSts == 0)) || ((rtu_SI_e_DoorLockSts == 1) &&
              (rtu_SI_e_DoorRatSts == 3))) {
    localDW->is_DOOR_LOCK_n = REL_IN_NO_ACTIVE_CHILD_i;
    localDW->is_TRIGGER_p = REL_IN_NO_ACTIVE_CHILD_i;
    localDW->is_RlsReq_f = REL_IN_Initial;
    *rty_SO_b_DoorRlsReq = false;
    *rty_SO_b_UnlockReq = false;
  } else {
    switch (localDW->is_TRIGGER_p) {
     case REL_IN_DOOR_LOCK:
      if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
        localDW->is_DOOR_LOCK_n = REL_IN_NO_ACTIVE_CHILD_i;
        localDW->is_TRIGGER_p = REL_IN_RELEASE_kx;
        localDW->temporalCounter_i9 = 0U;
        *rty_SO_b_DoorRlsReq = true;
      } else {
        switch (localDW->is_DOOR_LOCK_n) {
         case REL_IN_FAIL_UNLOCK:
          break;

         case REL_IN_REQ_UNLOCK:
          if (rtu_SI_e_DoorLockSts == 1) {
            localDW->is_DOOR_LOCK_n = REL_IN_SUCESS_UNLOCK;
          } else if ((localDW->temporalCounter_i9 >= 100) &&
                     (rtu_SI_e_DoorLockSts == 0)) {
            localDW->is_DOOR_LOCK_n = REL_IN_FAIL_UNLOCK;
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
        localDW->is_TRIGGER_p = REL_IN_RELEASE_kx;
        localDW->temporalCounter_i9 = 0U;
        *rty_SO_b_DoorRlsReq = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (localDW->temporalCounter_i9 >= 5) {
        localDW->is_TRIGGER_p = REL_IN_NO_ACTIVE_CHILD_i;
        localDW->is_RlsReq_f = REL_IN_Initial;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
      }
      break;
    }
  }

  switch (localDW->is_SwValid_p) {
   case REL_IN_Initial:
    if ((localDW->SI_b_DoorHandSwSts_prev != localDW->SI_b_DoorHandSwSts_start) &&
        localDW->SI_b_DoorHandSwSts_start) {
      localDW->is_SwValid_p = REL_IN_Press;
      localDW->temporalCounter_i8 = 0U;
    }
    break;

   case REL_IN_Press:
    if ((localDW->SI_b_DoorHandSwSts_prev != localDW->SI_b_DoorHandSwSts_start) &&
        (!localDW->SI_b_DoorHandSwSts_start)) {
      localDW->is_SwValid_p = REL_IN_Release;
      localDW->temporalCounter_i8 = 0U;
      localDW->SL_b_DoorHandSwValid = true;
    } else if (localDW->temporalCounter_i8 >= 100) {
      localDW->is_SwValid_p = REL_IN_Initial;
      localDW->SL_b_DoorHandSwValid = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (localDW->temporalCounter_i8 >= 3) {
      localDW->is_SwValid_p = REL_IN_Initial;
      localDW->SL_b_DoorHandSwValid = false;
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
  *rty_SO_b_UnlockReq)
{
  *rty_SO_b_DoorRlsReq = false;
  *rty_SO_b_UnlockReq = false;
}

/*
 * Output and update for atomic system:
 *    '<S3>/RLDoorRlsReq'
 *    '<S3>/RRDoorRlsReq'
 */
void REL_RLDoorRlsReq(boolean_T rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd, Boolean
                      rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8
                      rtu_SI_e_DoorLockSts, uint8_T rtu_SI_e_DoorRatSts, Boolean
                      rtu_SI_b_DoorInSwSts, Boolean rtu_SI_b_DoorOutSwSts,
                      Boolean rtu_SI_b_DoorHandSwSts, Boolean
                      rtu_SI_b_CentSingleDoorSwSts, Boolean
                      rtu_SI_b_CentAllDoorSwSts, Boolean rtu_SI_b_ChildLckSts,
                      boolean_T rtu_SI_b_DoorLockSetSts, boolean_T
                      *rty_SO_b_DoorRlsReq, boolean_T *rty_SO_b_UnlockReq,
                      DW_RLDoorRlsReq_REL_T *localDW)
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

  /* Chart: '<S3>/RLDoorRlsReq' */
  if (localDW->is_active_c5_DoorRlsReq == 0U) {
    localDW->SI_e_DoorLockSts_prev = rtu_SI_e_DoorLockSts;
    localDW->SI_e_VcuGearPosn_prev = rtu_SI_e_VcuGearPosn;
    localDW->SI_b_DoorInSwSts_prev = rtu_SI_b_DoorInSwSts;
    localDW->SI_b_DoorHandSwSts_prev = rtu_SI_b_DoorHandSwSts;
    localDW->is_active_c5_DoorRlsReq = 1U;
    localDW->is_SwValid = REL_IN_Initial;
    localDW->SL_b_DoorInSwValid = false;
    localDW->is_RlsReq_o = REL_IN_Initial;
    localDW->is_DoorCentral = REL_IN_Initial;
    localDW->SL_b_CentSingleDoorSwValid = rtu_SI_b_CentSingleDoorSwSts;
    localDW->SL_b_CentAllDoorSwValid = rtu_SI_b_CentAllDoorSwSts;
    localDW->SL_b_DoorOutSwValid = rtu_SI_b_DoorOutSwSts;
    localDW->is_RlsReq_ou = REL_IN_Initial;
    localDW->is_RlsReq_f = REL_IN_Initial;
    *rty_SO_b_UnlockReq = false;
    localDW->is_SwValid_p = REL_IN_Initial;
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
    if (localDW->is_RlsReq_ou == REL_IN_Initial) {
      if ((((rtu_SI_e_EspVehSpd <= 0) && (!rtu_SI_b_EspVehSpdVld)) ||
           (rtu_SI_e_VcuGearPosn == 1)) && ((localDW->SL_b_DoorOutSwValid_prev
            != localDW->SL_b_DoorOutSwValid_start) &&
           localDW->SL_b_DoorOutSwValid_start)) {
        localDW->is_RlsReq_ou = REL_IN_TRIGGER;
        localDW->temporalCounter_i7 = 0U;
        if (rtu_SI_e_DoorLockSts == 0) {
          localDW->is_TRIGGER_n = REL_IN_DOOR_LOCK;
          localDW->is_DOOR_LOCK_d = REL_IN_REQ_UNLOCK;
          localDW->temporalCounter_i6 = 0U;
          *rty_SO_b_UnlockReq = true;
        } else {
          localDW->is_TRIGGER_n = REL_IN_DOOR_UNLOCK;
        }
      }

      /* case IN_TRIGGER: */
    } else if (((localDW->SI_e_VcuGearPosn_prev !=
                 localDW->SI_e_VcuGearPosn_start) &&
                (localDW->SI_e_VcuGearPosn_prev == 1)) || ((rtu_SI_e_EspVehSpd >=
      5) && (!rtu_SI_b_EspVehSpdVld)) || ((localDW->temporalCounter_i7 >= 105) &&
                (rtu_SI_e_DoorLockSts == 0)) || ((rtu_SI_e_DoorLockSts == 1) &&
                (rtu_SI_e_DoorRatSts == 3))) {
      localDW->is_DOOR_LOCK_d = REL_IN_NO_ACTIVE_CHILD_i;
      localDW->is_TRIGGER_n = REL_IN_NO_ACTIVE_CHILD_i;
      localDW->is_RlsReq_ou = REL_IN_Initial;
      *rty_SO_b_DoorRlsReq = false;
      *rty_SO_b_UnlockReq = false;
    } else {
      switch (localDW->is_TRIGGER_n) {
       case REL_IN_DOOR_LOCK:
        if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
          localDW->is_DOOR_LOCK_d = REL_IN_NO_ACTIVE_CHILD_i;
          localDW->is_TRIGGER_n = REL_IN_RELEASE_kx;
          localDW->temporalCounter_i6 = 0U;
          *rty_SO_b_DoorRlsReq = true;
        } else {
          switch (localDW->is_DOOR_LOCK_d) {
           case REL_IN_FAIL_UNLOCK:
            break;

           case REL_IN_REQ_UNLOCK:
            if (rtu_SI_e_DoorLockSts == 1) {
              localDW->is_DOOR_LOCK_d = REL_IN_SUCESS_UNLOCK;
            } else if ((localDW->temporalCounter_i6 >= 100) &&
                       (rtu_SI_e_DoorLockSts == 0)) {
              localDW->is_DOOR_LOCK_d = REL_IN_FAIL_UNLOCK;
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
          localDW->is_TRIGGER_n = REL_IN_RELEASE_kx;
          localDW->temporalCounter_i6 = 0U;
          *rty_SO_b_DoorRlsReq = true;
        }
        break;

       default:
        /* case IN_RELEASE: */
        if (localDW->temporalCounter_i6 >= 5) {
          localDW->is_TRIGGER_n = REL_IN_NO_ACTIVE_CHILD_i;
          localDW->is_RlsReq_ou = REL_IN_Initial;
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
      localDW->is_TRIGGER = REL_IN_NO_ACTIVE_CHILD_i;
      localDW->is_RlsReq = REL_IN_Initial;
      *rty_SO_b_DoorRlsReq = false;
    } else if (localDW->is_TRIGGER == REL_IN_RELEASE_k) {
      if (localDW->temporalCounter_i2 >= 5) {
        localDW->is_TRIGGER = REL_IN_NO_ACTIVE_CHILD_i;
        localDW->is_RlsReq = REL_IN_Initial;
        *rty_SO_b_DoorRlsReq = false;
      }

      /* case IN_Wait: */
    } else if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
      localDW->is_TRIGGER = REL_IN_RELEASE_k;
      localDW->temporalCounter_i2 = 0U;
      *rty_SO_b_DoorRlsReq = true;
    }
  }

  /* End of Chart: '<S3>/RLDoorRlsReq' */
}

/* Function for Chart: '<S3>/FLDoorRlsReq' */
static void REL_DoorIn_l(const uint8_T *SI_e_VcuGearPosn_prev_i, const boolean_T
  *SI_b_DoorInSwSts_prev_m, const boolean_T *SL_b_DoorInSwValid_prev_i)
{
  switch (REL_DW.is_SwValid_pj) {
   case REL_IN_Initial_i:
    if ((*SI_b_DoorInSwSts_prev_m != REL_DW.SI_b_DoorInSwSts_start_b) &&
        REL_DW.SI_b_DoorInSwSts_start_b) {
      REL_DW.is_SwValid_pj = REL_IN_ONCE_n;
      REL_DW.temporalCounter_i3_e = 0U;
    }
    break;

   case REL_IN_ONCE_n:
    if ((*SI_b_DoorInSwSts_prev_m != REL_DW.SI_b_DoorInSwSts_start_b) &&
        REL_DW.SI_b_DoorInSwSts_start_b) {
      REL_DW.is_SwValid_pj = REL_IN_TWICE_c;
      REL_DW.temporalCounter_i3_e = 0U;
      REL_DW.SL_b_DoorInSwValid_i = true;
    } else if (REL_DW.temporalCounter_i3_e >= 200) {
      REL_DW.is_SwValid_pj = REL_IN_Initial_i;
      REL_DW.SL_b_DoorInSwValid_i = false;
    }
    break;

   default:
    /* case IN_TWICE: */
    if (REL_DW.temporalCounter_i3_e >= 3) {
      REL_DW.is_SwValid_pj = REL_IN_Initial_i;
      REL_DW.SL_b_DoorInSwValid_i = false;
    }
    break;
  }

  if (REL_DW.is_RlsReq_o == REL_IN_Initial_i) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     */
    if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
        ((*SL_b_DoorInSwValid_prev_i != REL_DW.SL_b_DoorInSwValid_start_d) &&
         REL_DW.SL_b_DoorInSwValid_start_d)) {
      REL_DW.is_RlsReq_o = REL_IN_TRIGGER_m;
      REL_DW.temporalCounter_i5_j = 0U;

      /* Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig' */
      if (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0) {
        REL_DW.is_TRIGGER_df = REL_IN_DOOR_LOCK_c;
        REL_DW.is_DOOR_LOCK_h = REL_IN_REQ_UNLOCK_o;
        REL_DW.temporalCounter_i4_o = 0U;
        REL_B.SO_b_UnlockReq_f = true;
      } else {
        REL_DW.is_TRIGGER_df = REL_IN_DOOR_UNLOCK_h;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig'
     *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
     *  Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig'
     */
    /* case IN_TRIGGER: */
  } else if (((*SI_e_VcuGearPosn_prev_i != REL_DW.SI_e_VcuGearPosn_start_f) && (*
               SI_e_VcuGearPosn_prev_i == 1)) ||
             ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 5) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
             ((REL_DW.temporalCounter_i5_j >= 105) &&
              (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) ||
             ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
              (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V == 3))) {
    REL_DW.is_DOOR_LOCK_h = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_TRIGGER_df = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_RlsReq_o = REL_IN_Initial_i;
    REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_f = false;
  } else {
    switch (REL_DW.is_TRIGGER_df) {
     case REL_IN_DOOR_LOCK_c:
      if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
          (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
        REL_DW.is_DOOR_LOCK_h = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_TRIGGER_df = REL_IN_RELEASE_nr;
        REL_DW.temporalCounter_i4_o = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
      } else {
        switch (REL_DW.is_DOOR_LOCK_h) {
         case REL_IN_FAIL_UNLOCK_m:
          break;

         case REL_IN_REQ_UNLOCK_o:
          if (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) {
            REL_DW.is_DOOR_LOCK_h = REL_IN_SUCESS_UNLOCK_n;
          } else if ((REL_DW.temporalCounter_i4_o >= 100) &&
                     (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) {
            REL_DW.is_DOOR_LOCK_h = REL_IN_FAIL_UNLOCK_m;
          }
          break;

         default:
          /* case IN_SUCESS_UNLOCK: */
          break;
        }
      }
      break;

     case REL_IN_DOOR_UNLOCK_h:
      if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
          (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
        REL_DW.is_TRIGGER_df = REL_IN_RELEASE_nr;
        REL_DW.temporalCounter_i4_o = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i4_o >= 5) {
        REL_DW.is_TRIGGER_df = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_RlsReq_o = REL_IN_Initial_i;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_f = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/FLDoorRlsReq' */
static void REL_DoorCent_g(const boolean_T *Compare, const uint8_T
  *SI_e_VcuGearPosn_prev_i, const boolean_T *SL_b_CentSingleDoorSwValid_pr_a,
  const boolean_T *SL_b_CentAllDoorSwValid_prev_n)
{
  if (REL_DW.is_DoorCentral_c == REL_IN_Initial_i) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     */
    if ((!*Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                         (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                        (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
        (((*SL_b_CentSingleDoorSwValid_pr_a !=
           REL_DW.SL_b_CentSingleDoorSwValid_st_j) &&
          REL_DW.SL_b_CentSingleDoorSwValid_st_j) ||
         ((*SL_b_CentAllDoorSwValid_prev_n !=
           REL_DW.SL_b_CentAllDoorSwValid_start_i) &&
          REL_DW.SL_b_CentAllDoorSwValid_start_i))) {
      REL_DW.is_DoorCentral_c = REL_IN_TRIGGER_m;
      REL_DW.temporalCounter_i12_j = 0U;

      /* Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig' */
      if (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0) {
        REL_DW.is_TRIGGER_p = REL_IN_DOOR_LOCK_c;
        REL_DW.is_DOOR_LOCK_o = REL_IN_REQ_UNLOCK_o;
        REL_DW.temporalCounter_i11_p = 0U;
        REL_B.SO_b_UnlockReq_f = true;
      } else {
        REL_DW.is_TRIGGER_p = REL_IN_DOOR_UNLOCK_h;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig'
     *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
     *  Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig'
     */
    /* case IN_TRIGGER: */
  } else if (((*SI_e_VcuGearPosn_prev_i != REL_DW.SI_e_VcuGearPosn_start_f) && (*
               SI_e_VcuGearPosn_prev_i == 1)) ||
             ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 5) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
             ((REL_DW.temporalCounter_i12_j >= 105) &&
              (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) ||
             ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
              (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V == 3))) {
    REL_DW.is_DOOR_LOCK_o = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_TRIGGER_p = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_DoorCentral_c = REL_IN_Initial_i;
    REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_f = false;
  } else {
    switch (REL_DW.is_TRIGGER_p) {
     case REL_IN_DOOR_LOCK_c:
      if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
          (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
        REL_DW.is_DOOR_LOCK_o = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_TRIGGER_p = REL_IN_RELEASE_nr;
        REL_DW.temporalCounter_i11_p = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
      } else {
        switch (REL_DW.is_DOOR_LOCK_o) {
         case REL_IN_FAIL_UNLOCK_m:
          break;

         case REL_IN_REQ_UNLOCK_o:
          if (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) {
            REL_DW.is_DOOR_LOCK_o = REL_IN_SUCESS_UNLOCK_n;
          } else if ((REL_DW.temporalCounter_i11_p >= 100) &&
                     (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) {
            REL_DW.is_DOOR_LOCK_o = REL_IN_FAIL_UNLOCK_m;
          }
          break;

         default:
          /* case IN_SUCESS_UNLOCK: */
          break;
        }
      }
      break;

     case REL_IN_DOOR_UNLOCK_h:
      if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
          (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
        REL_DW.is_TRIGGER_p = REL_IN_RELEASE_nr;
        REL_DW.temporalCounter_i11_p = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i11_p >= 5) {
        REL_DW.is_TRIGGER_p = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_DoorCentral_c = REL_IN_Initial_i;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_f = false;
      }
      break;
    }
  }

  /* Inport: '<Root>/VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg' */
  REL_DW.SL_b_CentSingleDoorSwValid_g = REL_U.VbINP_CAN_CdcDrvrDoorButtonSts_;

  /* Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg' */
  REL_DW.SL_b_CentAllDoorSwValid_l = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
}

/* Function for Chart: '<S3>/FLDoorRlsReq' */
static void REL_DoorHand_k(const boolean_T *Compare, const uint8_T
  *SI_e_VcuGearPosn_prev_i, const boolean_T *SI_b_DoorHandSwSts_prev_i, const
  boolean_T *SL_b_DoorHandSwValid_prev_n)
{
  if (REL_DW.is_RlsReq_a == REL_IN_Initial_i) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     */
    if ((!*Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                         (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                        (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
        ((*SL_b_DoorHandSwValid_prev_n != REL_DW.SL_b_DoorHandSwValid_start_g) &&
         REL_DW.SL_b_DoorHandSwValid_start_g)) {
      REL_DW.is_RlsReq_a = REL_IN_TRIGGER_m;
      REL_DW.temporalCounter_i10_c = 0U;

      /* Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig' */
      if (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0) {
        REL_DW.is_TRIGGER_n = REL_IN_DOOR_LOCK_c;
        REL_DW.is_DOOR_LOCK_nf = REL_IN_REQ_UNLOCK_o;
        REL_DW.temporalCounter_i9_g = 0U;
        REL_B.SO_b_UnlockReq_f = true;
      } else {
        REL_DW.is_TRIGGER_n = REL_IN_DOOR_UNLOCK_h;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig'
     *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
     *  Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig'
     */
    /* case IN_TRIGGER: */
  } else if (((*SI_e_VcuGearPosn_prev_i != REL_DW.SI_e_VcuGearPosn_start_f) && (*
               SI_e_VcuGearPosn_prev_i == 1)) ||
             ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 5) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
             ((REL_DW.temporalCounter_i10_c >= 105) &&
              (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) ||
             ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
              (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V == 3))) {
    REL_DW.is_DOOR_LOCK_nf = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_TRIGGER_n = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_RlsReq_a = REL_IN_Initial_i;
    REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_f = false;
  } else {
    switch (REL_DW.is_TRIGGER_n) {
     case REL_IN_DOOR_LOCK_c:
      if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
          (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
        REL_DW.is_DOOR_LOCK_nf = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_TRIGGER_n = REL_IN_RELEASE_nr;
        REL_DW.temporalCounter_i9_g = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
      } else {
        switch (REL_DW.is_DOOR_LOCK_nf) {
         case REL_IN_FAIL_UNLOCK_m:
          break;

         case REL_IN_REQ_UNLOCK_o:
          if (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) {
            REL_DW.is_DOOR_LOCK_nf = REL_IN_SUCESS_UNLOCK_n;
          } else if ((REL_DW.temporalCounter_i9_g >= 100) &&
                     (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) {
            REL_DW.is_DOOR_LOCK_nf = REL_IN_FAIL_UNLOCK_m;
          }
          break;

         default:
          /* case IN_SUCESS_UNLOCK: */
          break;
        }
      }
      break;

     case REL_IN_DOOR_UNLOCK_h:
      if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
          (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
        REL_DW.is_TRIGGER_n = REL_IN_RELEASE_nr;
        REL_DW.temporalCounter_i9_g = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i9_g >= 5) {
        REL_DW.is_TRIGGER_n = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_RlsReq_a = REL_IN_Initial_i;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_f = false;
      }
      break;
    }
  }

  switch (REL_DW.is_SwValid_f) {
   case REL_IN_Initial_i:
    if ((*SI_b_DoorHandSwSts_prev_i != REL_DW.SI_b_DoorHandSwSts_start_c) &&
        REL_DW.SI_b_DoorHandSwSts_start_c) {
      REL_DW.is_SwValid_f = REL_IN_Press_p;
      REL_DW.temporalCounter_i8_l = 0U;
    }
    break;

   case REL_IN_Press_p:
    if ((*SI_b_DoorHandSwSts_prev_i != REL_DW.SI_b_DoorHandSwSts_start_c) &&
        (!REL_DW.SI_b_DoorHandSwSts_start_c)) {
      REL_DW.is_SwValid_f = REL_IN_Release_d;
      REL_DW.temporalCounter_i8_l = 0U;
      REL_DW.SL_b_DoorHandSwValid_l = true;
    } else if (REL_DW.temporalCounter_i8_l >= 100) {
      REL_DW.is_SwValid_f = REL_IN_Initial_i;
      REL_DW.SL_b_DoorHandSwValid_l = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (REL_DW.temporalCounter_i8_l >= 3) {
      REL_DW.is_SwValid_f = REL_IN_Initial_i;
      REL_DW.SL_b_DoorHandSwValid_l = false;
    }
    break;
  }
}

/* Function for Chart: '<S3>/FRDoorRlsReq' */
static void REL_DoorIn_e(const uint8_T *SI_e_VcuGearPosn_prev, const boolean_T
  *SI_b_DoorInSwSts_prev, const boolean_T *SL_b_DoorInSwValid_prev)
{
  switch (REL_DW.is_SwValid) {
   case REL_IN_Initial_i:
    if ((*SI_b_DoorInSwSts_prev != REL_DW.SI_b_DoorInSwSts_start) &&
        REL_DW.SI_b_DoorInSwSts_start) {
      REL_DW.is_SwValid = REL_IN_ONCE_n;
      REL_DW.temporalCounter_i3 = 0U;
    }
    break;

   case REL_IN_ONCE_n:
    if ((*SI_b_DoorInSwSts_prev != REL_DW.SI_b_DoorInSwSts_start) &&
        REL_DW.SI_b_DoorInSwSts_start) {
      REL_DW.is_SwValid = REL_IN_TWICE_c;
      REL_DW.temporalCounter_i3 = 0U;
      REL_DW.SL_b_DoorInSwValid = true;
    } else if (REL_DW.temporalCounter_i3 >= 200) {
      REL_DW.is_SwValid = REL_IN_Initial_i;
      REL_DW.SL_b_DoorInSwValid = false;
    }
    break;

   default:
    /* case IN_TWICE: */
    if (REL_DW.temporalCounter_i3 >= 3) {
      REL_DW.is_SwValid = REL_IN_Initial_i;
      REL_DW.SL_b_DoorInSwValid = false;
    }
    break;
  }

  if (REL_DW.is_RlsReq_f == REL_IN_Initial_i) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     */
    if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
        ((*SL_b_DoorInSwValid_prev != REL_DW.SL_b_DoorInSwValid_start) &&
         REL_DW.SL_b_DoorInSwValid_start)) {
      REL_DW.is_RlsReq_f = REL_IN_TRIGGER_m;
      REL_DW.temporalCounter_i5 = 0U;

      /* Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig' */
      if (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0) {
        REL_DW.is_TRIGGER_o = REL_IN_DOOR_LOCK_c;
        REL_DW.is_DOOR_LOCK = REL_IN_REQ_UNLOCK_o;
        REL_DW.temporalCounter_i4 = 0U;
        REL_B.SO_b_UnlockReq_i = true;
      } else {
        REL_DW.is_TRIGGER_o = REL_IN_DOOR_UNLOCK_h;
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
    REL_DW.is_DOOR_LOCK = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_TRIGGER_o = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_RlsReq_f = REL_IN_Initial_i;
    REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_i = false;
  } else {
    switch (REL_DW.is_TRIGGER_o) {
     case REL_IN_DOOR_LOCK_c:
      if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
          (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
        REL_DW.is_DOOR_LOCK = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_TRIGGER_o = REL_IN_RELEASE_nr;
        REL_DW.temporalCounter_i4 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
      } else {
        switch (REL_DW.is_DOOR_LOCK) {
         case REL_IN_FAIL_UNLOCK_m:
          break;

         case REL_IN_REQ_UNLOCK_o:
          if (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) {
            REL_DW.is_DOOR_LOCK = REL_IN_SUCESS_UNLOCK_n;
          } else if ((REL_DW.temporalCounter_i4 >= 100) &&
                     (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0)) {
            REL_DW.is_DOOR_LOCK = REL_IN_FAIL_UNLOCK_m;
          }
          break;

         default:
          /* case IN_SUCESS_UNLOCK: */
          break;
        }
      }
      break;

     case REL_IN_DOOR_UNLOCK_h:
      if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
          (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
        REL_DW.is_TRIGGER_o = REL_IN_RELEASE_nr;
        REL_DW.temporalCounter_i4 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i4 >= 5) {
        REL_DW.is_TRIGGER_o = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_RlsReq_f = REL_IN_Initial_i;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_i = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/FRDoorRlsReq' */
static void REL_DoorCent_b(const boolean_T *Compare, const uint8_T
  *SI_e_VcuGearPosn_prev, const boolean_T *SL_b_CentSingleDoorSwValid_prev,
  const boolean_T *SL_b_CentAllDoorSwValid_prev)
{
  if (REL_DW.is_DoorCentral == REL_IN_Initial_i) {
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
      REL_DW.is_DoorCentral = REL_IN_TRIGGER_m;
      REL_DW.temporalCounter_i12 = 0U;

      /* Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig' */
      if (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0) {
        REL_DW.is_TRIGGER_f = REL_IN_DOOR_LOCK_c;
        REL_DW.is_DOOR_LOCK_b = REL_IN_REQ_UNLOCK_o;
        REL_DW.temporalCounter_i11 = 0U;
        REL_B.SO_b_UnlockReq_i = true;
      } else {
        REL_DW.is_TRIGGER_f = REL_IN_DOOR_UNLOCK_h;
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
    REL_DW.is_DOOR_LOCK_b = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_TRIGGER_f = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_DoorCentral = REL_IN_Initial_i;
    REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_i = false;
  } else {
    switch (REL_DW.is_TRIGGER_f) {
     case REL_IN_DOOR_LOCK_c:
      if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
          (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
        REL_DW.is_DOOR_LOCK_b = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_TRIGGER_f = REL_IN_RELEASE_nr;
        REL_DW.temporalCounter_i11 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
      } else {
        switch (REL_DW.is_DOOR_LOCK_b) {
         case REL_IN_FAIL_UNLOCK_m:
          break;

         case REL_IN_REQ_UNLOCK_o:
          if (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) {
            REL_DW.is_DOOR_LOCK_b = REL_IN_SUCESS_UNLOCK_n;
          } else if ((REL_DW.temporalCounter_i11 >= 100) &&
                     (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0)) {
            REL_DW.is_DOOR_LOCK_b = REL_IN_FAIL_UNLOCK_m;
          }
          break;

         default:
          /* case IN_SUCESS_UNLOCK: */
          break;
        }
      }
      break;

     case REL_IN_DOOR_UNLOCK_h:
      if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
          (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
        REL_DW.is_TRIGGER_f = REL_IN_RELEASE_nr;
        REL_DW.temporalCounter_i11 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i11 >= 5) {
        REL_DW.is_TRIGGER_f = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_DoorCentral = REL_IN_Initial_i;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_i = false;
      }
      break;
    }
  }

  /* Inport: '<Root>/VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg' */
  REL_DW.SL_b_CentSingleDoorSwValid = REL_U.VbINP_CAN_CdcPassDoorButtonSts_;

  /* Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg' */
  REL_DW.SL_b_CentAllDoorSwValid = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
}

/* Function for Chart: '<S3>/FRDoorRlsReq' */
static void REL_DoorHand_b(const boolean_T *Compare, const uint8_T
  *SI_e_VcuGearPosn_prev, const boolean_T *SI_b_DoorHandSwSts_prev, const
  boolean_T *SL_b_DoorHandSwValid_prev)
{
  if (REL_DW.is_RlsReq_j == REL_IN_Initial_i) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     */
    if ((!*Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                         (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                        (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
        ((*SL_b_DoorHandSwValid_prev != REL_DW.SL_b_DoorHandSwValid_start) &&
         REL_DW.SL_b_DoorHandSwValid_start)) {
      REL_DW.is_RlsReq_j = REL_IN_TRIGGER_m;
      REL_DW.temporalCounter_i10 = 0U;

      /* Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig' */
      if (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0) {
        REL_DW.is_TRIGGER_m = REL_IN_DOOR_LOCK_c;
        REL_DW.is_DOOR_LOCK_e = REL_IN_REQ_UNLOCK_o;
        REL_DW.temporalCounter_i9 = 0U;
        REL_B.SO_b_UnlockReq_i = true;
      } else {
        REL_DW.is_TRIGGER_m = REL_IN_DOOR_UNLOCK_h;
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
    REL_DW.is_DOOR_LOCK_e = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_TRIGGER_m = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_RlsReq_j = REL_IN_Initial_i;
    REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_i = false;
  } else {
    switch (REL_DW.is_TRIGGER_m) {
     case REL_IN_DOOR_LOCK_c:
      if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
          (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
        REL_DW.is_DOOR_LOCK_e = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_TRIGGER_m = REL_IN_RELEASE_nr;
        REL_DW.temporalCounter_i9 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
      } else {
        switch (REL_DW.is_DOOR_LOCK_e) {
         case REL_IN_FAIL_UNLOCK_m:
          break;

         case REL_IN_REQ_UNLOCK_o:
          if (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) {
            REL_DW.is_DOOR_LOCK_e = REL_IN_SUCESS_UNLOCK_n;
          } else if ((REL_DW.temporalCounter_i9 >= 100) &&
                     (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0)) {
            REL_DW.is_DOOR_LOCK_e = REL_IN_FAIL_UNLOCK_m;
          }
          break;

         default:
          /* case IN_SUCESS_UNLOCK: */
          break;
        }
      }
      break;

     case REL_IN_DOOR_UNLOCK_h:
      if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
          (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
        REL_DW.is_TRIGGER_m = REL_IN_RELEASE_nr;
        REL_DW.temporalCounter_i9 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
      }
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i9 >= 5) {
        REL_DW.is_TRIGGER_m = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_RlsReq_j = REL_IN_Initial_i;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_i = false;
      }
      break;
    }
  }

  switch (REL_DW.is_SwValid_p) {
   case REL_IN_Initial_i:
    if ((*SI_b_DoorHandSwSts_prev != REL_DW.SI_b_DoorHandSwSts_start) &&
        REL_DW.SI_b_DoorHandSwSts_start) {
      REL_DW.is_SwValid_p = REL_IN_Press_p;
      REL_DW.temporalCounter_i8 = 0U;
    }
    break;

   case REL_IN_Press_p:
    if ((*SI_b_DoorHandSwSts_prev != REL_DW.SI_b_DoorHandSwSts_start) &&
        (!REL_DW.SI_b_DoorHandSwSts_start)) {
      REL_DW.is_SwValid_p = REL_IN_Release_d;
      REL_DW.temporalCounter_i8 = 0U;
      REL_DW.SL_b_DoorHandSwValid = true;
    } else if (REL_DW.temporalCounter_i8 >= 100) {
      REL_DW.is_SwValid_p = REL_IN_Initial_i;
      REL_DW.SL_b_DoorHandSwValid = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (REL_DW.temporalCounter_i8 >= 3) {
      REL_DW.is_SwValid_p = REL_IN_Initial_i;
      REL_DW.SL_b_DoorHandSwValid = false;
    }
    break;
  }
}

/* Model step function for TID1 */
void REL_Step(void)                    /* Explicit Task: REL_Step */
{
  uint8_T SI_e_DoorLockSet_prev;
  uint8_T SI_e_VcuGearPosn_prev_i;
  boolean_T Compare;
  boolean_T SI_b_DoorHandSwSts_prev_i;
  boolean_T SI_b_DoorInSwSts_prev_m;
  boolean_T SL_b_CentAllDoorSwValid_prev_n;
  boolean_T SL_b_CentSingleDoorSwValid_pr_a;
  boolean_T SL_b_DoorHandSwValid_prev_n;
  boolean_T SL_b_DoorInSwValid_prev_i;
  boolean_T SL_b_DoorOutSwValid_prev_g;

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

  /* Chart: '<S3>/FLDoorRlsReq' incorporates:
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
  if (REL_DW.temporalCounter_i1_d < 127U) {
    REL_DW.temporalCounter_i1_d++;
  }

  if (REL_DW.temporalCounter_i2_f < 7U) {
    REL_DW.temporalCounter_i2_f++;
  }

  if (REL_DW.temporalCounter_i3_e < 255U) {
    REL_DW.temporalCounter_i3_e++;
  }

  if (REL_DW.temporalCounter_i4_o < 127U) {
    REL_DW.temporalCounter_i4_o++;
  }

  if (REL_DW.temporalCounter_i5_j < 127U) {
    REL_DW.temporalCounter_i5_j++;
  }

  if (REL_DW.temporalCounter_i6_l < 127U) {
    REL_DW.temporalCounter_i6_l++;
  }

  if (REL_DW.temporalCounter_i7_j < 127U) {
    REL_DW.temporalCounter_i7_j++;
  }

  if (REL_DW.temporalCounter_i8_l < 127U) {
    REL_DW.temporalCounter_i8_l++;
  }

  if (REL_DW.temporalCounter_i9_g < 127U) {
    REL_DW.temporalCounter_i9_g++;
  }

  if (REL_DW.temporalCounter_i10_c < 127U) {
    REL_DW.temporalCounter_i10_c++;
  }

  if (REL_DW.temporalCounter_i11_p < 127U) {
    REL_DW.temporalCounter_i11_p++;
  }

  if (REL_DW.temporalCounter_i12_j < 127U) {
    REL_DW.temporalCounter_i12_j++;
  }

  SI_e_DoorLockSet_prev = REL_DW.SI_e_DoorLockSts_start_n;
  REL_DW.SI_e_DoorLockSts_start_n = REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si;
  SI_e_VcuGearPosn_prev_i = REL_DW.SI_e_VcuGearPosn_start_f;
  REL_DW.SI_e_VcuGearPosn_start_f = REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP;
  SI_b_DoorInSwSts_prev_m = REL_DW.SI_b_DoorInSwSts_start_b;
  REL_DW.SI_b_DoorInSwSts_start_b = REL_U.VbINP_HWA_FLDoorButton_flg_VbIN;
  SL_b_DoorInSwValid_prev_i = REL_DW.SL_b_DoorInSwValid_start_d;
  REL_DW.SL_b_DoorInSwValid_start_d = REL_DW.SL_b_DoorInSwValid_i;
  SL_b_DoorOutSwValid_prev_g = REL_DW.SL_b_DoorOutSwValid_start_c;
  REL_DW.SL_b_DoorOutSwValid_start_c = REL_DW.SL_b_DoorOutSwValid_e;
  SI_b_DoorHandSwSts_prev_i = REL_DW.SI_b_DoorHandSwSts_start_c;
  REL_DW.SI_b_DoorHandSwSts_start_c = REL_Y.VbOUT_REL_FLDoorHndlBtnSig_flg_;
  SL_b_DoorHandSwValid_prev_n = REL_DW.SL_b_DoorHandSwValid_start_g;
  REL_DW.SL_b_DoorHandSwValid_start_g = REL_DW.SL_b_DoorHandSwValid_l;
  SL_b_CentSingleDoorSwValid_pr_a = REL_DW.SL_b_CentSingleDoorSwValid_st_j;
  REL_DW.SL_b_CentSingleDoorSwValid_st_j = REL_DW.SL_b_CentSingleDoorSwValid_g;
  SL_b_CentAllDoorSwValid_prev_n = REL_DW.SL_b_CentAllDoorSwValid_start_i;
  REL_DW.SL_b_CentAllDoorSwValid_start_i = REL_DW.SL_b_CentAllDoorSwValid_l;
  if (REL_DW.is_active_c5_DoorRlsReq_o == 0U) {
    REL_DW.is_active_c5_DoorRlsReq_o = 1U;
    REL_DW.is_SwValid_pj = REL_IN_Initial_i;
    REL_DW.SL_b_DoorInSwValid_i = false;
    REL_DW.is_RlsReq_o = REL_IN_Initial_i;
    REL_DW.is_DoorCentral_c = REL_IN_Initial_i;
    REL_DW.SL_b_CentSingleDoorSwValid_g = REL_U.VbINP_CAN_CdcDrvrDoorButtonSts_;
    REL_DW.SL_b_CentAllDoorSwValid_l = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
    REL_DW.SL_b_DoorOutSwValid_e = REL_Y.VbOUT_REL_BcmDrvrDoorHandleReq_;
    REL_DW.is_RlsReq_fx = REL_IN_Initial_i;
    REL_DW.is_RlsReq_a = REL_IN_Initial_i;
    REL_B.SO_b_UnlockReq_f = false;
    REL_DW.is_SwValid_f = REL_IN_Initial_i;
    REL_DW.SL_b_DoorHandSwValid_l = false;
    REL_DW.is_RlsReq_p = REL_IN_Initial_i;

    /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' incorporates:
     *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
     *  Inport: '<Root>/VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg'
     *  Outport: '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg'
     */
    REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
  } else {
    REL_DoorIn_l(&SI_e_VcuGearPosn_prev_i, &SI_b_DoorInSwSts_prev_m,
                 &SL_b_DoorInSwValid_prev_i);
    REL_DoorCent_g(&Compare, &SI_e_VcuGearPosn_prev_i,
                   &SL_b_CentSingleDoorSwValid_pr_a,
                   &SL_b_CentAllDoorSwValid_prev_n);
    REL_DW.SL_b_DoorOutSwValid_e = REL_Y.VbOUT_REL_BcmDrvrDoorHandleReq_;
    if (REL_DW.is_RlsReq_fx == REL_IN_Initial_i) {
      if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
            (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
           (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
          ((SL_b_DoorOutSwValid_prev_g != REL_DW.SL_b_DoorOutSwValid_start_c) &&
           REL_DW.SL_b_DoorOutSwValid_start_c)) {
        REL_DW.is_RlsReq_fx = REL_IN_TRIGGER_m;
        REL_DW.temporalCounter_i7_j = 0U;
        if (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0) {
          REL_DW.is_TRIGGER_b = REL_IN_DOOR_LOCK_c;
          REL_DW.is_DOOR_LOCK_n = REL_IN_REQ_UNLOCK_o;
          REL_DW.temporalCounter_i6_l = 0U;
          REL_B.SO_b_UnlockReq_f = true;
        } else {
          REL_DW.is_TRIGGER_b = REL_IN_DOOR_UNLOCK_h;
        }
      }

      /* case IN_TRIGGER: */
    } else if (((SI_e_VcuGearPosn_prev_i != REL_DW.SI_e_VcuGearPosn_start_f) &&
                (SI_e_VcuGearPosn_prev_i == 1)) ||
               ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 5) &&
                (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
               ((REL_DW.temporalCounter_i7_j >= 105) &&
                (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) ||
               ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
                (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V == 3))) {
      REL_DW.is_DOOR_LOCK_n = REL_IN_NO_ACTIVE_CHILD_h;
      REL_DW.is_TRIGGER_b = REL_IN_NO_ACTIVE_CHILD_h;
      REL_DW.is_RlsReq_fx = REL_IN_Initial_i;

      /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
      REL_B.SO_b_UnlockReq_f = false;
    } else {
      switch (REL_DW.is_TRIGGER_b) {
       case REL_IN_DOOR_LOCK_c:
        if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
            (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
          REL_DW.is_DOOR_LOCK_n = REL_IN_NO_ACTIVE_CHILD_h;
          REL_DW.is_TRIGGER_b = REL_IN_RELEASE_nr;
          REL_DW.temporalCounter_i6_l = 0U;

          /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
        } else {
          switch (REL_DW.is_DOOR_LOCK_n) {
           case REL_IN_FAIL_UNLOCK_m:
            break;

           case REL_IN_REQ_UNLOCK_o:
            if (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) {
              REL_DW.is_DOOR_LOCK_n = REL_IN_SUCESS_UNLOCK_n;
            } else if ((REL_DW.temporalCounter_i6_l >= 100) &&
                       (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) {
              REL_DW.is_DOOR_LOCK_n = REL_IN_FAIL_UNLOCK_m;
            }
            break;

           default:
            /* case IN_SUCESS_UNLOCK: */
            break;
          }
        }
        break;

       case REL_IN_DOOR_UNLOCK_h:
        if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
            (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
          REL_DW.is_TRIGGER_b = REL_IN_RELEASE_nr;
          REL_DW.temporalCounter_i6_l = 0U;

          /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
        }
        break;

       default:
        /* case IN_RELEASE: */
        if (REL_DW.temporalCounter_i6_l >= 5) {
          REL_DW.is_TRIGGER_b = REL_IN_NO_ACTIVE_CHILD_h;
          REL_DW.is_RlsReq_fx = REL_IN_Initial_i;

          /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
          REL_B.SO_b_UnlockReq_f = false;
        }
        break;
      }
    }

    REL_DoorHand_k(&Compare, &SI_e_VcuGearPosn_prev_i,
                   &SI_b_DoorHandSwSts_prev_i, &SL_b_DoorHandSwValid_prev_n);
    if (REL_DW.is_RlsReq_p == REL_IN_Initial_i) {
      if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
            (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
           (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
          REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts && ((SI_e_DoorLockSet_prev !=
            REL_DW.SI_e_DoorLockSts_start_n) && (REL_DW.SI_e_DoorLockSts_start_n
            == 1))) {
        REL_DW.is_RlsReq_p = REL_IN_TRIGGER_m;
        REL_DW.temporalCounter_i1_d = 0U;
        REL_DW.is_TRIGGER_fb = REL_IN_Wait_g;
      }

      /* case IN_TRIGGER: */
    } else if (((SI_e_VcuGearPosn_prev_i != REL_DW.SI_e_VcuGearPosn_start_f) &&
                (SI_e_VcuGearPosn_prev_i == 1)) ||
               ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 5) &&
                (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
               ((REL_DW.temporalCounter_i1_d >= 105) &&
                (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 0)) ||
               ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
                (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V == 3))) {
      REL_DW.is_TRIGGER_fb = REL_IN_NO_ACTIVE_CHILD_h;
      REL_DW.is_RlsReq_p = REL_IN_Initial_i;

      /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
    } else if (REL_DW.is_TRIGGER_fb == REL_IN_RELEASE_n) {
      if (REL_DW.temporalCounter_i2_f >= 5) {
        REL_DW.is_TRIGGER_fb = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_RlsReq_p = REL_IN_Initial_i;

        /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
      }

      /* case IN_Wait: */
    } else if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
               (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
      REL_DW.is_TRIGGER_fb = REL_IN_RELEASE_n;
      REL_DW.temporalCounter_i2_f = 0U;

      /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
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
                      &REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU,
                      &REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU,
                      &REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve,
                      &SI_b_DoorInSwSts_prev_m, &SI_e_DoorLockSet_prev,
                      &REL_DW.sf_FLDoorRlsDriver);

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

  /* Chart: '<S3>/FRDoorRlsReq' incorporates:
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
  if (REL_DW.temporalCounter_i1 < 127U) {
    REL_DW.temporalCounter_i1++;
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
  SI_b_DoorInSwSts_prev_m = REL_DW.SI_b_DoorInSwSts_start;
  REL_DW.SI_b_DoorInSwSts_start = REL_U.VbINP_HWA_FRDoorButton_flg_VbIN;
  SL_b_DoorInSwValid_prev_i = REL_DW.SL_b_DoorInSwValid_start;
  REL_DW.SL_b_DoorInSwValid_start = REL_DW.SL_b_DoorInSwValid;
  SL_b_DoorOutSwValid_prev_g = REL_DW.SL_b_DoorOutSwValid_start;
  REL_DW.SL_b_DoorOutSwValid_start = REL_DW.SL_b_DoorOutSwValid;
  SI_b_DoorHandSwSts_prev_i = REL_DW.SI_b_DoorHandSwSts_start;
  REL_DW.SI_b_DoorHandSwSts_start = REL_Y.VbOUT_REL_FRDoorHndlBtnSig_flg_;
  SL_b_DoorHandSwValid_prev_n = REL_DW.SL_b_DoorHandSwValid_start;
  REL_DW.SL_b_DoorHandSwValid_start = REL_DW.SL_b_DoorHandSwValid;
  SL_b_CentSingleDoorSwValid_pr_a = REL_DW.SL_b_CentSingleDoorSwValid_star;
  REL_DW.SL_b_CentSingleDoorSwValid_star = REL_DW.SL_b_CentSingleDoorSwValid;
  SL_b_CentAllDoorSwValid_prev_n = REL_DW.SL_b_CentAllDoorSwValid_start;
  REL_DW.SL_b_CentAllDoorSwValid_start = REL_DW.SL_b_CentAllDoorSwValid;
  if (REL_DW.is_active_c5_DoorRlsReq == 0U) {
    REL_DW.is_active_c5_DoorRlsReq = 1U;
    REL_DW.is_SwValid = REL_IN_Initial_i;
    REL_DW.SL_b_DoorInSwValid = false;
    REL_DW.is_RlsReq_f = REL_IN_Initial_i;
    REL_DW.is_DoorCentral = REL_IN_Initial_i;
    REL_DW.SL_b_CentSingleDoorSwValid = REL_U.VbINP_CAN_CdcPassDoorButtonSts_;
    REL_DW.SL_b_CentAllDoorSwValid = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
    REL_DW.SL_b_DoorOutSwValid = REL_Y.VbOUT_REL_BcmPassDoorHandleReq_;
    REL_DW.is_RlsReq_b = REL_IN_Initial_i;
    REL_DW.is_RlsReq_j = REL_IN_Initial_i;
    REL_B.SO_b_UnlockReq_i = false;
    REL_DW.is_SwValid_p = REL_IN_Initial_i;
    REL_DW.SL_b_DoorHandSwValid = false;
    REL_DW.is_RlsReq = REL_IN_Initial_i;

    /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' incorporates:
     *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
     *  Inport: '<Root>/VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg'
     *  Outport: '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg'
     */
    REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
  } else {
    REL_DoorIn_e(&SI_e_DoorLockSet_prev, &SI_b_DoorInSwSts_prev_m,
                 &SL_b_DoorInSwValid_prev_i);
    REL_DoorCent_b(&Compare, &SI_e_DoorLockSet_prev,
                   &SL_b_CentSingleDoorSwValid_pr_a,
                   &SL_b_CentAllDoorSwValid_prev_n);
    REL_DW.SL_b_DoorOutSwValid = REL_Y.VbOUT_REL_BcmPassDoorHandleReq_;
    if (REL_DW.is_RlsReq_b == REL_IN_Initial_i) {
      if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
            (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
           (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
          ((SL_b_DoorOutSwValid_prev_g != REL_DW.SL_b_DoorOutSwValid_start) &&
           REL_DW.SL_b_DoorOutSwValid_start)) {
        REL_DW.is_RlsReq_b = REL_IN_TRIGGER_m;
        REL_DW.temporalCounter_i7 = 0U;
        if (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0) {
          REL_DW.is_TRIGGER_d = REL_IN_DOOR_LOCK_c;
          REL_DW.is_DOOR_LOCK_j = REL_IN_REQ_UNLOCK_o;
          REL_DW.temporalCounter_i6 = 0U;
          REL_B.SO_b_UnlockReq_i = true;
        } else {
          REL_DW.is_TRIGGER_d = REL_IN_DOOR_UNLOCK_h;
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
      REL_DW.is_DOOR_LOCK_j = REL_IN_NO_ACTIVE_CHILD_h;
      REL_DW.is_TRIGGER_d = REL_IN_NO_ACTIVE_CHILD_h;
      REL_DW.is_RlsReq_b = REL_IN_Initial_i;

      /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
      REL_B.SO_b_UnlockReq_i = false;
    } else {
      switch (REL_DW.is_TRIGGER_d) {
       case REL_IN_DOOR_LOCK_c:
        if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
            (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
          REL_DW.is_DOOR_LOCK_j = REL_IN_NO_ACTIVE_CHILD_h;
          REL_DW.is_TRIGGER_d = REL_IN_RELEASE_nr;
          REL_DW.temporalCounter_i6 = 0U;

          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
        } else {
          switch (REL_DW.is_DOOR_LOCK_j) {
           case REL_IN_FAIL_UNLOCK_m:
            break;

           case REL_IN_REQ_UNLOCK_o:
            if (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) {
              REL_DW.is_DOOR_LOCK_j = REL_IN_SUCESS_UNLOCK_n;
            } else if ((REL_DW.temporalCounter_i6 >= 100) &&
                       (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0)) {
              REL_DW.is_DOOR_LOCK_j = REL_IN_FAIL_UNLOCK_m;
            }
            break;

           default:
            /* case IN_SUCESS_UNLOCK: */
            break;
          }
        }
        break;

       case REL_IN_DOOR_UNLOCK_h:
        if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
            (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
          REL_DW.is_TRIGGER_d = REL_IN_RELEASE_nr;
          REL_DW.temporalCounter_i6 = 0U;

          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
        }
        break;

       default:
        /* case IN_RELEASE: */
        if (REL_DW.temporalCounter_i6 >= 5) {
          REL_DW.is_TRIGGER_d = REL_IN_NO_ACTIVE_CHILD_h;
          REL_DW.is_RlsReq_b = REL_IN_Initial_i;

          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
          REL_B.SO_b_UnlockReq_i = false;
        }
        break;
      }
    }

    REL_DoorHand_b(&Compare, &SI_e_DoorLockSet_prev, &SI_b_DoorHandSwSts_prev_i,
                   &SL_b_DoorHandSwValid_prev_n);
    if (REL_DW.is_RlsReq != REL_IN_Initial_i) {
      /* case IN_TRIGGER: */
      if (((SI_e_DoorLockSet_prev != REL_DW.SI_e_VcuGearPosn_start) &&
           (SI_e_DoorLockSet_prev == 1)) ||
          ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 5) &&
           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
          ((REL_DW.temporalCounter_i1 >= 105) &&
           (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 0)) ||
          ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
           (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V == 3))) {
        REL_DW.is_TRIGGER = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_RlsReq = REL_IN_Initial_i;

        /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
      } else if (REL_DW.is_TRIGGER == REL_IN_RELEASE_n) {
        if (REL_DW.temporalCounter_i2 >= 5) {
          REL_DW.is_TRIGGER = REL_IN_NO_ACTIVE_CHILD_h;
          REL_DW.is_RlsReq = REL_IN_Initial_i;

          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        }

        /* case IN_Wait: */
      } else if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
                 (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
        REL_DW.is_TRIGGER = REL_IN_RELEASE_n;
        REL_DW.temporalCounter_i2 = 0U;

        /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
      }
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
                      &REL_Y.VbOUT_REL_FRDoorMotorA_flg_VbOU,
                      &REL_Y.VbOUT_REL_FRDoorMotorB_flg_VbOU,
                      &REL_Y.VeOUT_REL_FRDoorMotorSts_sig_Ve,
                      &SI_b_DoorInSwSts_prev_m, &SI_e_DoorLockSet_prev,
                      &REL_DW.sf_FRDoorRlsDriver);

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

  /* Chart: '<S3>/RLDoorRlsReq' incorporates:
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
  REL_RLDoorRlsReq(Compare, REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
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
                   &REL_B.SO_b_UnlockReq_e, &REL_DW.sf_RLDoorRlsReq);

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

  /* Chart: '<S3>/RRDoorRlsReq' incorporates:
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
  REL_RLDoorRlsReq(Compare, REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
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
                   &REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU, &REL_B.SO_b_UnlockReq,
                   &REL_DW.sf_RRDoorRlsReq);

  /* Logic: '<S3>/Logical Operator' */
  Compare = (REL_B.SO_b_UnlockReq_i || REL_B.SO_b_UnlockReq_e ||
             REL_B.SO_b_UnlockReq);

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
                      &REL_Y.VbOUT_REL_RLDoorMotorA_flg_VbOU,
                      &REL_Y.VbOUT_REL_RLDoorMotorB_flg_VbOU,
                      &REL_Y.VeOUT_REL_RLDoorMotorSts_sig_Ve,
                      &SI_b_DoorInSwSts_prev_m, &SI_e_DoorLockSet_prev,
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
                      &REL_Y.VbOUT_REL_RRDoorMotorA_flg_VbOU,
                      &REL_Y.VbOUT_REL_RRDoorMotorB_flg_VbOU,
                      &REL_Y.VeOUT_REL_RRDoorMotorSts_sig_Ve,
                      &SI_b_DoorInSwSts_prev_m, &SI_e_DoorLockSet_prev,
                      &REL_DW.sf_RRDoorRlsDriver);

  /* Chart: '<S3>/Unlock_Request' */
  SI_b_DoorInSwSts_prev_m = REL_DW.SI_b_DrvUnlockReq_start;
  REL_DW.SI_b_DrvUnlockReq_start = REL_B.SO_b_UnlockReq_f;
  SL_b_DoorInSwValid_prev_i = REL_DW.SI_b_PassUnlockReq_start;
  REL_DW.SI_b_PassUnlockReq_start = Compare;
  if (REL_DW.is_active_c6_REL == 0U) {
    REL_DW.is_active_c6_REL = 1U;
    REL_DW.is_c6_REL = REL_IN_Initial_i;

    /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
    REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 0U;
  } else if (REL_DW.is_c6_REL == REL_IN_Initial_i) {
    if (((SI_b_DoorInSwSts_prev_m != REL_DW.SI_b_DrvUnlockReq_start) &&
         REL_DW.SI_b_DrvUnlockReq_start) || ((SL_b_DoorInSwValid_prev_i !=
          REL_DW.SI_b_PassUnlockReq_start) && REL_DW.SI_b_PassUnlockReq_start))
    {
      REL_DW.is_c6_REL = REL_IN_REQ_SENT;
    }
  } else {
    /* case IN_REQ_SENT: */
    SI_b_DoorInSwSts_prev_m = !Compare;
    SL_b_DoorInSwValid_prev_i = !REL_B.SO_b_UnlockReq_f;
    if (SL_b_DoorInSwValid_prev_i && SI_b_DoorInSwSts_prev_m) {
      REL_DW.is_c6_REL = REL_IN_Initial_i;

      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 0U;
    } else if (REL_B.SO_b_UnlockReq_f && Compare) {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 3U;
    } else if (REL_B.SO_b_UnlockReq_f && SI_b_DoorInSwSts_prev_m) {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 1U;
    } else if (SL_b_DoorInSwValid_prev_i && Compare) {
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
    uint8_T SO_e_MotorPwm_d;
    boolean_T SO_b_Error_h;

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
      &REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve, &SO_b_Error_h, &SO_e_MotorPwm_d);

    /* SystemInitialize for Chart: '<S3>/FRDoorRlsDriver' incorporates:
     *  Outport: '<Root>/VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg'
     *  Outport: '<Root>/VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg'
     *  Outport: '<Root>/VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig'
     */
    REL_FLDoorRlsDriver_Init(&REL_Y.VbOUT_REL_FRDoorMotorA_flg_VbOU,
      &REL_Y.VbOUT_REL_FRDoorMotorB_flg_VbOU,
      &REL_Y.VeOUT_REL_FRDoorMotorSts_sig_Ve, &SO_b_Error_h, &SO_e_MotorPwm_d);

    /* SystemInitialize for Chart: '<S3>/RLDoorRlsDriver' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg'
     *  Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg'
     *  Outport: '<Root>/VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig'
     */
    REL_FLDoorRlsDriver_Init(&REL_Y.VbOUT_REL_RLDoorMotorA_flg_VbOU,
      &REL_Y.VbOUT_REL_RLDoorMotorB_flg_VbOU,
      &REL_Y.VeOUT_REL_RLDoorMotorSts_sig_Ve, &SO_b_Error_h, &SO_e_MotorPwm_d);

    /* SystemInitialize for Chart: '<S3>/RLDoorRlsReq' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg'
     */
    REL_RLDoorRlsReq_Init(&REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU,
                          &REL_B.SO_b_UnlockReq_e);

    /* SystemInitialize for Chart: '<S3>/RRDoorRlsDriver' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg'
     *  Outport: '<Root>/VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg'
     *  Outport: '<Root>/VeOUT_REL_RRDoorMotorSts_sig_VeOUT_REL_RRDoorMotorSts_sig'
     */
    REL_FLDoorRlsDriver_Init(&REL_Y.VbOUT_REL_RRDoorMotorA_flg_VbOU,
      &REL_Y.VbOUT_REL_RRDoorMotorB_flg_VbOU,
      &REL_Y.VeOUT_REL_RRDoorMotorSts_sig_Ve, &SO_b_Error_h, &SO_e_MotorPwm_d);

    /* SystemInitialize for Chart: '<S3>/RRDoorRlsReq' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg'
     */
    REL_RLDoorRlsReq_Init(&REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU,
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
