/*
 * File: REL.c
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.305
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Sep  6 11:35:47 2023
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
#define REL_IN_Error                   ((uint8_T)1U)
#define REL_IN_Error1                  ((uint8_T)2U)
#define REL_IN_Ice_Break               ((uint8_T)3U)
#define REL_IN_Idle                    ((uint8_T)1U)
#define REL_IN_Idle_e                  ((uint8_T)4U)
#define REL_IN_Initial                 ((uint8_T)3U)
#define REL_IN_LastCheck               ((uint8_T)5U)
#define REL_IN_LastCheck_l             ((uint8_T)2U)
#define REL_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define REL_IN_NonElectricDoor         ((uint8_T)2U)
#define REL_IN_Normal                  ((uint8_T)1U)
#define REL_IN_PowerOn                 ((uint8_T)2U)
#define REL_IN_Release                 ((uint8_T)2U)
#define REL_IN_Reset                   ((uint8_T)4U)
#define REL_IN_Step2_Open              ((uint8_T)5U)

/* Named constants for Chart: '<S3>/RLDoorRlsReq' */
#define REL_IN_DoorLock                ((uint8_T)1U)
#define REL_IN_DoorUnlock              ((uint8_T)2U)
#define REL_IN_Error_n                 ((uint8_T)3U)
#define REL_IN_Initial_i               ((uint8_T)1U)
#define REL_IN_NO_ACTIVE_CHILD_i       ((uint8_T)0U)
#define REL_IN_Once                    ((uint8_T)2U)
#define REL_IN_Press                   ((uint8_T)2U)
#define REL_IN_RELEASE                 ((uint8_T)4U)
#define REL_IN_Release_h               ((uint8_T)1U)
#define REL_IN_Release_hw              ((uint8_T)4U)
#define REL_IN_Release_hwa             ((uint8_T)3U)
#define REL_IN_Trigger                 ((uint8_T)2U)
#define REL_IN_Twice                   ((uint8_T)3U)
#define REL_IN_WAIT                    ((uint8_T)2U)
#define REL_IN_Wait                    ((uint8_T)2U)

/* Named constants for Chart: '<S3>/DoorLockSetSts' */
#define REL_IN_DoorLockSet             ((uint8_T)1U)
#define REL_IN_Init                    ((uint8_T)2U)
#define REL_IN_NO_ACTIVE_CHILD_h       ((uint8_T)0U)

/* Named constants for Chart: '<S3>/DoorSwSts' */
#define REL_IN_Crash                   ((uint8_T)1U)
#define REL_IN_NoCrash                 ((uint8_T)2U)

/* Named constants for Chart: '<S3>/FLDoorRlsReq' */
#define REL_IN_DoorLock_l              ((uint8_T)1U)
#define REL_IN_DoorUnlock_l            ((uint8_T)2U)
#define REL_IN_Error_m                 ((uint8_T)3U)
#define REL_IN_Initial_ic              ((uint8_T)1U)
#define REL_IN_Once_o                  ((uint8_T)2U)
#define REL_IN_Press_p                 ((uint8_T)2U)
#define REL_IN_RELEASE_n               ((uint8_T)4U)
#define REL_IN_Release_d               ((uint8_T)1U)
#define REL_IN_Release_dn              ((uint8_T)4U)
#define REL_IN_Release_dnm             ((uint8_T)3U)
#define REL_IN_Trigger_g               ((uint8_T)2U)
#define REL_IN_Twice_k                 ((uint8_T)3U)
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
static void REL_Normal(Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_CinchHome,
  uint8_T rtu_SI_e_DoorRlsDelayTime, boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorMode, boolean_T *rty_SO_b_Error,
  uint8_T *rty_SO_e_MotorPwm, DW_FLDoorRlsDriver_REL_T *localDW);

/* Forward declaration for local functions */
static void REL_DoorIn(UInt8 rtu_SI_e_EspVehSpd, Boolean rtu_SI_b_EspVehSpdVld,
  UInt8 rtu_SI_e_VcuGearPosn, UInt8 rtu_SI_e_DoorLockSts, uint8_T
  rtu_SI_e_DoorRatSts, Boolean rtu_SI_b_ChildLckSts, boolean_T
  *rty_SO_b_DoorRlsReq, boolean_T *rty_SO_b_UnlockReq, uint8_T
  *rty_SO_e_DoorRlsDelayTime, DW_RLDoorRlsReq_REL_T *localDW);
static void REL_DoorHand(UInt8 rtu_SI_e_EspVehSpd, Boolean rtu_SI_b_EspVehSpdVld,
  UInt8 rtu_SI_e_VcuGearPosn, UInt8 rtu_SI_e_DoorLockSts, uint8_T
  rtu_SI_e_DoorRatSts, boolean_T *rty_SO_b_DoorRlsReq, boolean_T
  *rty_SO_b_UnlockReq, uint8_T *rty_SO_e_DoorRlsDelayTime, DW_RLDoorRlsReq_REL_T
  *localDW);

/* Forward declaration for local functions */
static void REL_enter_atomic_NoCrash(boolean_T *SL_b_FLDoorInSwSts, boolean_T
  *SL_b_FRDoorInSwSts, boolean_T *SL_b_RLDoorInSwSts, boolean_T
  *SL_b_RRDoorInSwSts, boolean_T *SL_b_FLDoorOutSwSts, boolean_T
  *SL_b_FRDoorOutSwSts);
static void REL_DoorIn_l(const boolean_T *SI_b_DoorInSwSts_prev_d, const
  boolean_T *SL_b_DoorInSwValid_prev_f);
static void REL_DoorHand_k(const boolean_T *SI_b_DoorHandSwSts_prev_k, const
  boolean_T *SL_b_DoorHandSwValid_prev_c);
static void REL_DoorIn_e(const boolean_T *SI_b_DoorInSwSts_prev, const boolean_T
  *SL_b_DoorInSwValid_prev);
static void REL_DoorHand_b(const boolean_T *SI_b_DoorHandSwSts_prev, const
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
static void REL_Normal(Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_CinchHome,
  uint8_T rtu_SI_e_DoorRlsDelayTime, boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorMode, boolean_T *rty_SO_b_Error,
  uint8_T *rty_SO_e_MotorPwm, DW_FLDoorRlsDriver_REL_T *localDW)
{
  if (localDW->is_Normal == REL_IN_ElectricDoor) {
    if (localDW->is_MainProgress == REL_IN_Idle) {
      *rty_SO_e_MotorMode = 0U;
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
          *rty_SO_e_MotorMode = 0U;
          if ((localDW->temporalCounter_i1 >= 5) && rtu_SI_b_DoorAjar) {
            localDW->is_Release = REL_IN_Step2_Open;
            localDW->is_Step2_Open = REL_IN_Idle_e;
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
          *rty_SO_e_MotorMode = 1U;
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
        *rty_SO_e_MotorMode = 2U;
        if (localDW->temporalCounter_i1 >= 30) {
          localDW->is_Release = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_MainProgress = REL_IN_Idle;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorMode = 0U;
          *rty_SO_e_MotorPwm = 0U;
          *rty_SO_b_Error = false;
        }
        break;

       default:
        /* case IN_Step2_Open: */
        switch (localDW->is_Step2_Open) {
         case REL_IN_Error:
          localDW->is_Step2_Open = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_Release = REL_IN_Reset;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorMode = 2U;
          *rty_SO_e_MotorPwm = 70U;
          break;

         case REL_IN_Error1:
          localDW->is_Step2_Open = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_Release = REL_IN_Reset;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorMode = 2U;
          *rty_SO_e_MotorPwm = 70U;
          break;

         case REL_IN_Ice_Break:
          if ((localDW->temporalCounter_i1 < 600) && (!rtu_SI_b_CinchHome)) {
            localDW->is_Step2_Open = REL_IN_NO_ACTIVE_CHILD;
            localDW->is_Release = REL_IN_Reset;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = true;
            *rty_SO_e_MotorMode = 2U;
            *rty_SO_e_MotorPwm = 70U;
          } else if ((localDW->temporalCounter_i1 >= 600) && rtu_SI_b_CinchHome)
          {
            localDW->is_Step2_Open = REL_IN_Error1;
            *rty_SO_b_Error = true;
          }
          break;

         case REL_IN_Idle_e:
          *rty_SO_e_MotorMode = 0U;
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
          break;

         default:
          /* case IN_LastCheck: */
          if (!rtu_SI_b_CinchHome) {
            localDW->is_Step2_Open = REL_IN_Error;
            *rty_SO_b_Error = true;
          } else {
            localDW->is_Step2_Open = REL_IN_Ice_Break;
            localDW->temporalCounter_i1 = 0U;
          }
          break;
        }
        break;
      }
    }

    /* case IN_NonElectricDoor: */
  } else if (localDW->is_MainProgress_j == REL_IN_Idle) {
    *rty_SO_e_MotorMode = 0U;
    if ((localDW->SO_b_DoorRlsReq_prev != localDW->SO_b_DoorRlsReq_start) &&
        localDW->SO_b_DoorRlsReq_start) {
      localDW->is_MainProgress_j = REL_IN_Release;
      localDW->SL_e_CheckCycle = 0U;
      *rty_SO_e_MotorPwm = 100U;
      localDW->is_Release_i = REL_IN_Delay;
      localDW->temporalCounter_i1 = 0U;
    }
  } else {
    /* case IN_Release: */
    switch (localDW->is_Release_i) {
     case REL_IN_Checking:
      {
        *rty_SO_e_MotorMode = 0U;
        if ((localDW->temporalCounter_i1 >= 5) && rtu_SI_b_DoorAjar) {
          localDW->is_Release_i = REL_IN_Step2_Open;
          localDW->is_Step2_Open_c = REL_IN_Idle;
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
            localDW->is_Release_i = REL_IN_Initial;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = true;
            *rty_SO_b_MotorB = false;
            *rty_SO_e_MotorMode = 1U;
          } else if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                     (localDW->SL_e_CheckCycle >= 2)) {
            localDW->is_Release_i = REL_IN_Reset;
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
        localDW->is_Release_i = REL_IN_Initial;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_MotorA = true;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorMode = 1U;
      }
      break;

     case REL_IN_Initial:
      {
        *rty_SO_e_MotorMode = 1U;
        if (localDW->temporalCounter_i1 >= 30) {
          int32_T tmp;
          localDW->is_Release_i = REL_IN_Checking;
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
      *rty_SO_e_MotorMode = 2U;
      if (localDW->temporalCounter_i1 >= 30) {
        localDW->is_Release_i = REL_IN_NO_ACTIVE_CHILD;
        localDW->is_MainProgress_j = REL_IN_Idle;
        *rty_SO_b_MotorA = false;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorMode = 0U;
        *rty_SO_e_MotorPwm = 0U;
      }
      break;

     default:
      /* case IN_Step2_Open: */
      if (localDW->is_Step2_Open_c == REL_IN_Idle) {
        *rty_SO_e_MotorMode = 0U;
        if ((localDW->temporalCounter_i1 < 270) && rtu_SI_b_DoorAjar) {
          localDW->is_Step2_Open_c = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_Release_i = REL_IN_Reset;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorMode = 2U;
          *rty_SO_e_MotorPwm = 70U;
        } else if (localDW->temporalCounter_i1 >= 300) {
          localDW->is_Step2_Open_c = REL_IN_LastCheck_l;
        }
      } else {
        /* case IN_LastCheck: */
        localDW->is_Step2_Open_c = REL_IN_NO_ACTIVE_CHILD;
        localDW->is_Release_i = REL_IN_Reset;
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
  uint8_T rtu_SI_e_DoorRlsDelayTime, boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorMode, boolean_T *rty_SO_b_Error,
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
    *rty_SO_e_MotorMode = 2U;
    *rty_SO_e_MotorPwm = 100U;
  } else if (localDW->is_c19_DoorRlsDriver == REL_IN_Normal) {
    REL_Normal(rtu_SI_b_DoorAjar, rtu_SI_b_CinchHome, rtu_SI_e_DoorRlsDelayTime,
               rty_SO_b_MotorA, rty_SO_b_MotorB, rty_SO_e_MotorMode,
               rty_SO_b_Error, rty_SO_e_MotorPwm, localDW);
  } else {
    /* case IN_PowerOn: */
    *rty_SO_e_MotorMode = 2U;
    if (localDW->temporalCounter_i1 >= 30) {
      localDW->is_c19_DoorRlsDriver = REL_IN_Normal;
      if (rtu_SI_b_ElecDoorCfg) {
        localDW->is_Normal = REL_IN_ElectricDoor;
        localDW->is_MainProgress = REL_IN_Idle;
        *rty_SO_b_MotorA = false;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorMode = 0U;
        *rty_SO_e_MotorPwm = 0U;
        *rty_SO_b_Error = false;
      } else {
        localDW->is_Normal = REL_IN_NonElectricDoor;
        localDW->is_MainProgress_j = REL_IN_Idle;
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
  *rty_SO_b_DoorRlsReq, boolean_T *rty_SO_b_UnlockReq, uint8_T
  *rty_SO_e_DoorRlsDelayTime, DW_RLDoorRlsReq_REL_T *localDW)
{
  switch (localDW->is_SwValid) {
   case REL_IN_Initial_i:
    if ((localDW->SI_b_DoorInSwSts_prev != localDW->SI_b_DoorInSwSts_start) &&
        localDW->SI_b_DoorInSwSts_start && (!rtu_SI_b_ChildLckSts)) {
      localDW->is_SwValid = REL_IN_Once;
      localDW->temporalCounter_i2 = 0U;
    }
    break;

   case REL_IN_Once:
    if ((localDW->SI_b_DoorInSwSts_prev != localDW->SI_b_DoorInSwSts_start) &&
        localDW->SI_b_DoorInSwSts_start && (!rtu_SI_b_ChildLckSts)) {
      localDW->is_SwValid = REL_IN_Twice;
      localDW->temporalCounter_i2 = 0U;
      localDW->SL_b_DoorInSwValid = true;
    } else if ((localDW->temporalCounter_i2 >= 200) || rtu_SI_b_ChildLckSts) {
      localDW->is_SwValid = REL_IN_Initial_i;
      localDW->SL_b_DoorInSwValid = false;
    }
    break;

   default:
    /* case IN_Twice: */
    if (localDW->temporalCounter_i2 >= 3) {
      localDW->is_SwValid = REL_IN_Initial_i;
      localDW->SL_b_DoorInSwValid = false;
    }
    break;
  }

  if (localDW->is_RlsReq_o == REL_IN_Initial_i) {
    if ((((rtu_SI_e_EspVehSpd <= 0) && (!rtu_SI_b_EspVehSpdVld)) ||
         (rtu_SI_e_VcuGearPosn == 1)) && ((localDW->SL_b_DoorInSwValid_prev !=
          localDW->SL_b_DoorInSwValid_start) &&
         localDW->SL_b_DoorInSwValid_start)) {
      localDW->is_RlsReq_o = REL_IN_Trigger;
      switch (rtu_SI_e_DoorLockSts) {
       case 0:
        localDW->is_Trigger_k = REL_IN_DoorLock;
        localDW->temporalCounter_i3 = 0U;
        *rty_SO_b_UnlockReq = true;
        break;

       case 1:
        localDW->is_Trigger_k = REL_IN_DoorUnlock;
        break;

       default:
        localDW->is_Trigger_k = REL_IN_Error_n;
        break;
      }
    }

    /* case IN_Trigger: */
  } else if (((rtu_SI_e_EspVehSpd >= 1) && (!rtu_SI_b_EspVehSpdVld) &&
              (rtu_SI_e_VcuGearPosn != 1)) || ((rtu_SI_e_DoorLockSts == 1) &&
              (rtu_SI_e_DoorRatSts == 3))) {
    localDW->is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_i;
    localDW->is_RlsReq_o = REL_IN_Initial_i;
    *rty_SO_b_DoorRlsReq = false;
    *rty_SO_b_UnlockReq = false;
  } else {
    switch (localDW->is_Trigger_k) {
     case REL_IN_DoorLock:
      if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
        localDW->is_Trigger_k = REL_IN_Release_hw;
        localDW->temporalCounter_i3 = 0U;
        *rty_SO_b_DoorRlsReq = true;
        *rty_SO_e_DoorRlsDelayTime = 20U;
      } else if (localDW->temporalCounter_i3 >= 100) {
        localDW->is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_i;
        localDW->is_RlsReq_o = REL_IN_Initial_i;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
      }
      break;

     case REL_IN_DoorUnlock:
      if (rtu_SI_e_DoorRatSts != 3) {
        localDW->is_Trigger_k = REL_IN_Release_hw;
        localDW->temporalCounter_i3 = 0U;
        *rty_SO_b_DoorRlsReq = true;
        *rty_SO_e_DoorRlsDelayTime = 20U;
      }
      break;

     case REL_IN_Error_n:
      localDW->is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_i;
      localDW->is_RlsReq_o = REL_IN_Initial_i;
      *rty_SO_b_DoorRlsReq = false;
      *rty_SO_b_UnlockReq = false;
      break;

     default:
      /* case IN_Release: */
      if (localDW->temporalCounter_i3 >= 5) {
        localDW->is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_i;
        localDW->is_RlsReq_o = REL_IN_Initial_i;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/RLDoorRlsReq' */
static void REL_DoorHand(UInt8 rtu_SI_e_EspVehSpd, Boolean rtu_SI_b_EspVehSpdVld,
  UInt8 rtu_SI_e_VcuGearPosn, UInt8 rtu_SI_e_DoorLockSts, uint8_T
  rtu_SI_e_DoorRatSts, boolean_T *rty_SO_b_DoorRlsReq, boolean_T
  *rty_SO_b_UnlockReq, uint8_T *rty_SO_e_DoorRlsDelayTime, DW_RLDoorRlsReq_REL_T
  *localDW)
{
  if (localDW->is_RlsReq_f == REL_IN_Initial_i) {
    if ((((rtu_SI_e_EspVehSpd <= 0) && (!rtu_SI_b_EspVehSpdVld)) ||
         (rtu_SI_e_VcuGearPosn == 1)) && ((localDW->SL_b_DoorHandSwValid_prev !=
          localDW->SL_b_DoorHandSwValid_start) &&
         localDW->SL_b_DoorHandSwValid_start)) {
      localDW->is_RlsReq_f = REL_IN_Trigger;
      switch (rtu_SI_e_DoorLockSts) {
       case 0:
        localDW->is_Trigger_c = REL_IN_DoorLock;
        localDW->temporalCounter_i6 = 0U;
        *rty_SO_b_UnlockReq = true;
        break;

       case 1:
        localDW->is_Trigger_c = REL_IN_DoorUnlock;
        break;

       default:
        localDW->is_Trigger_c = REL_IN_Error_n;
        break;
      }
    }

    /* case IN_Trigger: */
  } else if (((rtu_SI_e_EspVehSpd >= 1) && (!rtu_SI_b_EspVehSpdVld) &&
              (rtu_SI_e_VcuGearPosn != 1)) || ((rtu_SI_e_DoorLockSts == 1) &&
              (rtu_SI_e_DoorRatSts == 3))) {
    localDW->is_Trigger_c = REL_IN_NO_ACTIVE_CHILD_i;
    localDW->is_RlsReq_f = REL_IN_Initial_i;
    *rty_SO_b_DoorRlsReq = false;
    *rty_SO_b_UnlockReq = false;
  } else {
    switch (localDW->is_Trigger_c) {
     case REL_IN_DoorLock:
      if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
        localDW->is_Trigger_c = REL_IN_RELEASE;
        localDW->temporalCounter_i6 = 0U;
        *rty_SO_b_DoorRlsReq = true;
        *rty_SO_e_DoorRlsDelayTime = 0U;
      } else if (localDW->temporalCounter_i6 >= 100) {
        localDW->is_Trigger_c = REL_IN_NO_ACTIVE_CHILD_i;
        localDW->is_RlsReq_f = REL_IN_Initial_i;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
      }
      break;

     case REL_IN_DoorUnlock:
      if (rtu_SI_e_DoorRatSts != 3) {
        localDW->is_Trigger_c = REL_IN_RELEASE;
        localDW->temporalCounter_i6 = 0U;
        *rty_SO_b_DoorRlsReq = true;
        *rty_SO_e_DoorRlsDelayTime = 0U;
      }
      break;

     case REL_IN_Error_n:
      break;

     default:
      /* case IN_RELEASE: */
      if (localDW->temporalCounter_i6 >= 5) {
        localDW->is_Trigger_c = REL_IN_NO_ACTIVE_CHILD_i;
        localDW->is_RlsReq_f = REL_IN_Initial_i;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
      }
      break;
    }
  }

  switch (localDW->is_SwValid_o) {
   case REL_IN_Initial_i:
    if ((localDW->SI_b_DoorHandSwSts_prev != localDW->SI_b_DoorHandSwSts_start) &&
        localDW->SI_b_DoorHandSwSts_start) {
      localDW->is_SwValid_o = REL_IN_Press;
      localDW->temporalCounter_i5 = 0U;
    }
    break;

   case REL_IN_Press:
    if ((localDW->SI_b_DoorHandSwSts_prev != localDW->SI_b_DoorHandSwSts_start) &&
        (!localDW->SI_b_DoorHandSwSts_start)) {
      localDW->is_SwValid_o = REL_IN_Release_hwa;
      localDW->temporalCounter_i5 = 0U;
      localDW->SL_b_DoorHandSwValid = true;
    } else if (localDW->temporalCounter_i5 >= 100) {
      localDW->is_SwValid_o = REL_IN_Initial_i;
      localDW->SL_b_DoorHandSwValid = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (localDW->temporalCounter_i5 >= 3) {
      localDW->is_SwValid_o = REL_IN_Initial_i;
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
                      boolean_T rtu_SI_b_DoorInSwSts, boolean_T
                      rtu_SI_b_DoorOutSwSts, boolean_T rtu_SI_b_DoorHandSwSts,
                      UInt8 rtu_SI_e_DoorHandPosSts, Boolean
                      rtu_SI_b_CentSingleDoorSwSts, Boolean
                      rtu_SI_b_CentAllDoorSwSts, Boolean rtu_SI_b_ChildLckSts,
                      boolean_T rtu_SI_b_DoorLockSetSts, boolean_T
                      rtu_SI_b_DoorLockOpenReq, boolean_T *rty_SO_b_DoorRlsReq,
                      boolean_T *rty_SO_b_UnlockReq, uint8_T
                      *rty_SO_e_DoorRlsDelayTime, DW_RLDoorRlsReq_REL_T *localDW)
{
  if (localDW->temporalCounter_i1 < 7U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->temporalCounter_i2 < 255U) {
    localDW->temporalCounter_i2++;
  }

  if (localDW->temporalCounter_i3 < 127U) {
    localDW->temporalCounter_i3++;
  }

  if (localDW->temporalCounter_i4 < 7U) {
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

  localDW->SI_b_DoorLockOpenReq_prev = localDW->SI_b_DoorLockOpenReq_start;
  localDW->SI_b_DoorLockOpenReq_start = rtu_SI_b_DoorLockOpenReq;
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
    localDW->SI_b_DoorLockOpenReq_prev = rtu_SI_b_DoorLockOpenReq;
    localDW->SI_b_DoorInSwSts_prev = rtu_SI_b_DoorInSwSts;
    localDW->SI_b_DoorHandSwSts_prev = rtu_SI_b_DoorHandSwSts;
    localDW->is_active_c5_DoorRlsReq = 1U;
    localDW->is_SwValid = REL_IN_Initial_i;
    localDW->SL_b_DoorInSwValid = false;
    localDW->is_RlsReq_o = REL_IN_Initial_i;
    localDW->is_DoorCentral = REL_IN_Initial_i;
    localDW->SL_b_CentSingleDoorSwValid = rtu_SI_b_CentSingleDoorSwSts;
    localDW->SL_b_CentAllDoorSwValid = rtu_SI_b_CentAllDoorSwSts;
    localDW->SL_b_DoorOutSwValid = rtu_SI_b_DoorOutSwSts;
    localDW->is_RlsReq_g = REL_IN_Initial_i;
    localDW->is_RlsReq_f = REL_IN_Initial_i;
    *rty_SO_b_UnlockReq = false;
    localDW->is_SwValid_o = REL_IN_Initial_i;
    localDW->SL_b_DoorHandSwValid = false;
    localDW->is_RlsReq = REL_IN_Initial_i;
    *rty_SO_b_DoorRlsReq = false;
  } else {
    REL_DoorIn(rtu_SI_e_EspVehSpd, rtu_SI_b_EspVehSpdVld, rtu_SI_e_VcuGearPosn,
               rtu_SI_e_DoorLockSts, rtu_SI_e_DoorRatSts, rtu_SI_b_ChildLckSts,
               rty_SO_b_DoorRlsReq, rty_SO_b_UnlockReq,
               rty_SO_e_DoorRlsDelayTime, localDW);
    if (localDW->is_DoorCentral == REL_IN_Initial_i) {
      if ((!rtu_SI_b_OFF) && (((rtu_SI_e_EspVehSpd <= 0) &&
            (!rtu_SI_b_EspVehSpdVld)) || (rtu_SI_e_VcuGearPosn == 1)) &&
          (((localDW->SL_b_CentSingleDoorSwValid_prev !=
             localDW->SL_b_CentSingleDoorSwValid_star) &&
            localDW->SL_b_CentSingleDoorSwValid_star) ||
           ((localDW->SL_b_CentAllDoorSwValid_prev !=
             localDW->SL_b_CentAllDoorSwValid_start) &&
            localDW->SL_b_CentAllDoorSwValid_start))) {
        localDW->is_DoorCentral = REL_IN_Trigger;
        switch (rtu_SI_e_DoorLockSts) {
         case 0:
          localDW->is_Trigger_h = REL_IN_DoorLock;
          localDW->temporalCounter_i7 = 0U;
          *rty_SO_b_UnlockReq = true;
          break;

         case 1:
          localDW->is_Trigger_h = REL_IN_DoorUnlock;
          break;

         default:
          localDW->is_Trigger_h = REL_IN_Error_n;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (rtu_SI_b_OFF || ((rtu_SI_e_EspVehSpd >= 1) &&
                (!rtu_SI_b_EspVehSpdVld) && (rtu_SI_e_VcuGearPosn != 1)) ||
               ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts == 3))) {
      localDW->is_Trigger_h = REL_IN_NO_ACTIVE_CHILD_i;
      localDW->is_DoorCentral = REL_IN_Initial_i;
      *rty_SO_b_DoorRlsReq = false;
      *rty_SO_b_UnlockReq = false;
    } else {
      switch (localDW->is_Trigger_h) {
       case REL_IN_DoorLock:
        if (localDW->temporalCounter_i7 >= 100) {
          localDW->is_Trigger_h = REL_IN_NO_ACTIVE_CHILD_i;
          localDW->is_DoorCentral = REL_IN_Initial_i;
          *rty_SO_b_DoorRlsReq = false;
          *rty_SO_b_UnlockReq = false;
        } else if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
          localDW->is_Trigger_h = REL_IN_RELEASE;
          localDW->temporalCounter_i7 = 0U;
          *rty_SO_b_DoorRlsReq = true;
          *rty_SO_e_DoorRlsDelayTime = 0U;
        }
        break;

       case REL_IN_DoorUnlock:
        if (rtu_SI_e_DoorRatSts != 3) {
          localDW->is_Trigger_h = REL_IN_RELEASE;
          localDW->temporalCounter_i7 = 0U;
          *rty_SO_b_DoorRlsReq = true;
          *rty_SO_e_DoorRlsDelayTime = 0U;
        }
        break;

       case REL_IN_Error_n:
        localDW->is_Trigger_h = REL_IN_NO_ACTIVE_CHILD_i;
        localDW->is_DoorCentral = REL_IN_Initial_i;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
        break;

       default:
        /* case IN_RELEASE: */
        if (localDW->temporalCounter_i7 >= 5) {
          localDW->is_Trigger_h = REL_IN_NO_ACTIVE_CHILD_i;
          localDW->is_DoorCentral = REL_IN_Initial_i;
          *rty_SO_b_DoorRlsReq = false;
          *rty_SO_b_UnlockReq = false;
        }
        break;
      }
    }

    localDW->SL_b_CentSingleDoorSwValid = rtu_SI_b_CentSingleDoorSwSts;
    localDW->SL_b_CentAllDoorSwValid = rtu_SI_b_CentAllDoorSwSts;
    localDW->SL_b_DoorOutSwValid = rtu_SI_b_DoorOutSwSts;
    if (localDW->is_RlsReq_g == REL_IN_Initial_i) {
      if ((!rtu_SI_b_OFF) && (((rtu_SI_e_EspVehSpd <= 0) &&
            (!rtu_SI_b_EspVehSpdVld)) || (rtu_SI_e_VcuGearPosn == 1)) &&
          (rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorHandPosSts == 1) &&
          ((localDW->SL_b_DoorOutSwValid_prev !=
            localDW->SL_b_DoorOutSwValid_start) &&
           localDW->SL_b_DoorOutSwValid_start)) {
        localDW->is_RlsReq_g = REL_IN_Trigger;
        localDW->is_Trigger_b = REL_IN_Wait;
      }

      /* case IN_Trigger: */
    } else if (rtu_SI_b_OFF || ((rtu_SI_e_EspVehSpd >= 1) &&
                (!rtu_SI_b_EspVehSpdVld) && (rtu_SI_e_VcuGearPosn != 1)) ||
               (rtu_SI_e_DoorLockSts != 1) || (rtu_SI_e_DoorHandPosSts != 1) ||
               (rtu_SI_e_DoorRatSts == 3)) {
      localDW->is_Trigger_b = REL_IN_NO_ACTIVE_CHILD_i;
      localDW->is_RlsReq_g = REL_IN_Initial_i;
      *rty_SO_b_DoorRlsReq = false;
      *rty_SO_b_UnlockReq = false;
    } else if (localDW->is_Trigger_b == REL_IN_Release_h) {
      if (localDW->temporalCounter_i4 >= 5) {
        localDW->is_Trigger_b = REL_IN_NO_ACTIVE_CHILD_i;
        localDW->is_RlsReq_g = REL_IN_Initial_i;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
      }

      /* case IN_Wait: */
    } else if (rtu_SI_e_DoorRatSts != 3) {
      localDW->is_Trigger_b = REL_IN_Release_h;
      localDW->temporalCounter_i4 = 0U;
      *rty_SO_b_DoorRlsReq = true;
      *rty_SO_e_DoorRlsDelayTime = 4U;
    }

    REL_DoorHand(rtu_SI_e_EspVehSpd, rtu_SI_b_EspVehSpdVld, rtu_SI_e_VcuGearPosn,
                 rtu_SI_e_DoorLockSts, rtu_SI_e_DoorRatSts, rty_SO_b_DoorRlsReq,
                 rty_SO_b_UnlockReq, rty_SO_e_DoorRlsDelayTime, localDW);
    if (localDW->is_RlsReq == REL_IN_Initial_i) {
      if ((!rtu_SI_b_OFF) && (((rtu_SI_e_EspVehSpd <= 0) &&
            (!rtu_SI_b_EspVehSpdVld)) || (rtu_SI_e_VcuGearPosn == 1)) &&
          rtu_SI_b_DoorLockSetSts && (rtu_SI_e_DoorLockSts == 1) &&
          ((localDW->SI_b_DoorLockOpenReq_prev !=
            localDW->SI_b_DoorLockOpenReq_start) &&
           localDW->SI_b_DoorLockOpenReq_start)) {
        localDW->is_RlsReq = REL_IN_Trigger;
        localDW->is_Trigger = REL_IN_WAIT;
      }

      /* case IN_Trigger: */
    } else if (rtu_SI_b_OFF || ((rtu_SI_e_EspVehSpd >= 1) &&
                (!rtu_SI_b_EspVehSpdVld) && (rtu_SI_e_VcuGearPosn != 1)) ||
               (!rtu_SI_b_DoorLockSetSts) || (rtu_SI_e_DoorLockSts != 1) ||
               (rtu_SI_e_DoorRatSts == 3)) {
      localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_i;
      localDW->is_RlsReq = REL_IN_Initial_i;
      *rty_SO_b_DoorRlsReq = false;
    } else if (localDW->is_Trigger == REL_IN_Release_h) {
      if (localDW->temporalCounter_i1 >= 5) {
        localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_i;
        localDW->is_RlsReq = REL_IN_Initial_i;
        *rty_SO_b_DoorRlsReq = false;
      }

      /* case IN_WAIT: */
    } else if (rtu_SI_e_DoorRatSts != 3) {
      localDW->is_Trigger = REL_IN_Release_h;
      localDW->temporalCounter_i1 = 0U;
      *rty_SO_b_DoorRlsReq = true;
    }
  }

  /* End of Chart: '<S3>/RLDoorRlsReq' */
}

/* Function for Chart: '<S3>/DoorSwSts' */
static void REL_enter_atomic_NoCrash(boolean_T *SL_b_FLDoorInSwSts, boolean_T
  *SL_b_FRDoorInSwSts, boolean_T *SL_b_RLDoorInSwSts, boolean_T
  *SL_b_RRDoorInSwSts, boolean_T *SL_b_FLDoorOutSwSts, boolean_T
  *SL_b_FRDoorOutSwSts)
{
  /* Inport: '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg' */
  *SL_b_FLDoorInSwSts = REL_U.VbINP_HWA_FLDoorButton_flg_VbIN;

  /* Inport: '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg' */
  *SL_b_FRDoorInSwSts = REL_U.VbINP_HWA_FRDoorButton_flg_VbIN;

  /* Inport: '<Root>/VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg' */
  *SL_b_RLDoorInSwSts = REL_U.VbINP_HWA_RLDoorButton_flg_VbIN;

  /* Inport: '<Root>/VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg' */
  *SL_b_RRDoorInSwSts = REL_U.VbINP_HWA_RRDoorButton_flg_VbIN;

  /* Outport: '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg' */
  *SL_b_FLDoorOutSwSts = REL_Y.VbOUT_REL_BcmDrvrDoorHandleReq_;

  /* Outport: '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg' */
  *SL_b_FRDoorOutSwSts = REL_Y.VbOUT_REL_BcmPassDoorHandleReq_;

  /* Outport: '<Root>/VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg' */
  REL_B.SL_b_RLDoorOutSwSts = REL_Y.VbOUT_REL_BcmLeReDoorHandleReq_;

  /* Outport: '<Root>/VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg' */
  REL_B.SL_b_RRDoorOutSwSts = REL_Y.VbOUT_REL_BcmBcmRiReDoorHandleR;

  /* Outport: '<Root>/VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg' */
  REL_B.SL_b_FLDoorHandSwSts = REL_Y.VbOUT_REL_FLDoorHndlBtnSig_flg_;

  /* Outport: '<Root>/VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg' */
  REL_B.SL_b_FRDoorHandSwSts = REL_Y.VbOUT_REL_FRDoorHndlBtnSig_flg_;

  /* Outport: '<Root>/VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg' */
  REL_B.SL_b_RLDoorHandSwSts = REL_Y.VbOUT_REL_RLDoorHndlBtnSig_flg_;

  /* Outport: '<Root>/VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg' */
  REL_B.SL_b_RRDoorHandSwSts = REL_Y.VbOUT_REL_RRDoorHndlBtnSig_flg_;
}

/* Function for Chart: '<S3>/FLDoorRlsReq' */
static void REL_DoorIn_l(const boolean_T *SI_b_DoorInSwSts_prev_d, const
  boolean_T *SL_b_DoorInSwValid_prev_f)
{
  switch (REL_DW.is_SwValid_pj) {
   case REL_IN_Initial_ic:
    if ((*SI_b_DoorInSwSts_prev_d != REL_DW.SI_b_DoorInSwSts_start_g) &&
        REL_DW.SI_b_DoorInSwSts_start_g) {
      REL_DW.is_SwValid_pj = REL_IN_Once_o;
      REL_DW.temporalCounter_i2_h = 0U;
    }
    break;

   case REL_IN_Once_o:
    if ((*SI_b_DoorInSwSts_prev_d != REL_DW.SI_b_DoorInSwSts_start_g) &&
        REL_DW.SI_b_DoorInSwSts_start_g) {
      REL_DW.is_SwValid_pj = REL_IN_Twice_k;
      REL_DW.temporalCounter_i2_h = 0U;
      REL_DW.SL_b_DoorInSwValid_g = true;
    } else if (REL_DW.temporalCounter_i2_h >= 200) {
      REL_DW.is_SwValid_pj = REL_IN_Initial_ic;
      REL_DW.SL_b_DoorInSwValid_g = false;
    }
    break;

   default:
    /* case IN_Twice: */
    if (REL_DW.temporalCounter_i2_h >= 3) {
      REL_DW.is_SwValid_pj = REL_IN_Initial_ic;
      REL_DW.SL_b_DoorInSwValid_g = false;
    }
    break;
  }

  if (REL_DW.is_RlsReq_o == REL_IN_Initial_ic) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     */
    if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
        ((*SL_b_DoorInSwValid_prev_f != REL_DW.SL_b_DoorInSwValid_start_n) &&
         REL_DW.SL_b_DoorInSwValid_start_n)) {
      REL_DW.is_RlsReq_o = REL_IN_Trigger_g;

      /* Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig' */
      switch (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si) {
       case 0:
        REL_DW.is_Trigger_gx = REL_IN_DoorLock_l;
        REL_DW.temporalCounter_i3_b = 0U;
        REL_B.SO_b_UnlockReq_f = true;
        break;

       case 1:
        REL_DW.is_Trigger_gx = REL_IN_DoorUnlock_l;
        break;

       default:
        REL_DW.is_Trigger_gx = REL_IN_Error_m;
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
    REL_DW.is_Trigger_gx = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_RlsReq_o = REL_IN_Initial_ic;
    REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_f = false;
  } else {
    switch (REL_DW.is_Trigger_gx) {
     case REL_IN_DoorLock_l:
      if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
          (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
        REL_DW.is_Trigger_gx = REL_IN_Release_dn;
        REL_DW.temporalCounter_i3_b = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_n3 = 20U;
      } else if (REL_DW.temporalCounter_i3_b >= 100) {
        REL_DW.is_Trigger_gx = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_RlsReq_o = REL_IN_Initial_ic;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_f = false;
      }
      break;

     case REL_IN_DoorUnlock_l:
      if (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3) {
        REL_DW.is_Trigger_gx = REL_IN_Release_dn;
        REL_DW.temporalCounter_i3_b = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_n3 = 20U;
      }
      break;

     case REL_IN_Error_m:
      REL_DW.is_Trigger_gx = REL_IN_NO_ACTIVE_CHILD_h;
      REL_DW.is_RlsReq_o = REL_IN_Initial_ic;
      REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
      REL_B.SO_b_UnlockReq_f = false;
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i3_b >= 5) {
        REL_DW.is_Trigger_gx = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_RlsReq_o = REL_IN_Initial_ic;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_f = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/FLDoorRlsReq' */
static void REL_DoorHand_k(const boolean_T *SI_b_DoorHandSwSts_prev_k, const
  boolean_T *SL_b_DoorHandSwValid_prev_c)
{
  if (REL_DW.is_RlsReq_id == REL_IN_Initial_ic) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     */
    if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
        ((*SL_b_DoorHandSwValid_prev_c != REL_DW.SL_b_DoorHandSwValid_start_l) &&
         REL_DW.SL_b_DoorHandSwValid_start_l)) {
      REL_DW.is_RlsReq_id = REL_IN_Trigger_g;

      /* Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig' */
      switch (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si) {
       case 0:
        REL_DW.is_Trigger_g0 = REL_IN_DoorLock_l;
        REL_DW.temporalCounter_i6_c = 0U;
        REL_B.SO_b_UnlockReq_f = true;
        break;

       case 1:
        REL_DW.is_Trigger_g0 = REL_IN_DoorUnlock_l;
        break;

       default:
        REL_DW.is_Trigger_g0 = REL_IN_Error_m;
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
    REL_DW.is_Trigger_g0 = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_RlsReq_id = REL_IN_Initial_ic;
    REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_f = false;
  } else {
    switch (REL_DW.is_Trigger_g0) {
     case REL_IN_DoorLock_l:
      if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
          (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
        REL_DW.is_Trigger_g0 = REL_IN_RELEASE_n;
        REL_DW.temporalCounter_i6_c = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_n3 = 0U;
      } else if (REL_DW.temporalCounter_i6_c >= 100) {
        REL_DW.is_Trigger_g0 = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_RlsReq_id = REL_IN_Initial_ic;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_f = false;
      }
      break;

     case REL_IN_DoorUnlock_l:
      if (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3) {
        REL_DW.is_Trigger_g0 = REL_IN_RELEASE_n;
        REL_DW.temporalCounter_i6_c = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_n3 = 0U;
      }
      break;

     case REL_IN_Error_m:
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i6_c >= 5) {
        REL_DW.is_Trigger_g0 = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_RlsReq_id = REL_IN_Initial_ic;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_f = false;
      }
      break;
    }
  }

  switch (REL_DW.is_SwValid_j) {
   case REL_IN_Initial_ic:
    if ((*SI_b_DoorHandSwSts_prev_k != REL_DW.SI_b_DoorHandSwSts_start_c) &&
        REL_DW.SI_b_DoorHandSwSts_start_c) {
      REL_DW.is_SwValid_j = REL_IN_Press_p;
      REL_DW.temporalCounter_i5_l = 0U;
    }
    break;

   case REL_IN_Press_p:
    if ((*SI_b_DoorHandSwSts_prev_k != REL_DW.SI_b_DoorHandSwSts_start_c) &&
        (!REL_DW.SI_b_DoorHandSwSts_start_c)) {
      REL_DW.is_SwValid_j = REL_IN_Release_dnm;
      REL_DW.temporalCounter_i5_l = 0U;
      REL_DW.SL_b_DoorHandSwValid_m = true;
    } else if (REL_DW.temporalCounter_i5_l >= 100) {
      REL_DW.is_SwValid_j = REL_IN_Initial_ic;
      REL_DW.SL_b_DoorHandSwValid_m = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (REL_DW.temporalCounter_i5_l >= 3) {
      REL_DW.is_SwValid_j = REL_IN_Initial_ic;
      REL_DW.SL_b_DoorHandSwValid_m = false;
    }
    break;
  }
}

/* Function for Chart: '<S3>/FRDoorRlsReq' */
static void REL_DoorIn_e(const boolean_T *SI_b_DoorInSwSts_prev, const boolean_T
  *SL_b_DoorInSwValid_prev)
{
  switch (REL_DW.is_SwValid) {
   case REL_IN_Initial_ic:
    if ((*SI_b_DoorInSwSts_prev != REL_DW.SI_b_DoorInSwSts_start) &&
        REL_DW.SI_b_DoorInSwSts_start) {
      REL_DW.is_SwValid = REL_IN_Once_o;
      REL_DW.temporalCounter_i2 = 0U;
    }
    break;

   case REL_IN_Once_o:
    if ((*SI_b_DoorInSwSts_prev != REL_DW.SI_b_DoorInSwSts_start) &&
        REL_DW.SI_b_DoorInSwSts_start) {
      REL_DW.is_SwValid = REL_IN_Twice_k;
      REL_DW.temporalCounter_i2 = 0U;
      REL_DW.SL_b_DoorInSwValid = true;
    } else if (REL_DW.temporalCounter_i2 >= 200) {
      REL_DW.is_SwValid = REL_IN_Initial_ic;
      REL_DW.SL_b_DoorInSwValid = false;
    }
    break;

   default:
    /* case IN_Twice: */
    if (REL_DW.temporalCounter_i2 >= 3) {
      REL_DW.is_SwValid = REL_IN_Initial_ic;
      REL_DW.SL_b_DoorInSwValid = false;
    }
    break;
  }

  if (REL_DW.is_RlsReq_f == REL_IN_Initial_ic) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     */
    if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
        ((*SL_b_DoorInSwValid_prev != REL_DW.SL_b_DoorInSwValid_start) &&
         REL_DW.SL_b_DoorInSwValid_start)) {
      REL_DW.is_RlsReq_f = REL_IN_Trigger_g;

      /* Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig' */
      switch (REL_U.VeOUT_DLK_BCMPassengerDoorLockS) {
       case 0:
        REL_DW.is_Trigger_h = REL_IN_DoorLock_l;
        REL_DW.temporalCounter_i3 = 0U;
        REL_B.SO_b_UnlockReq_i = true;
        break;

       case 1:
        REL_DW.is_Trigger_h = REL_IN_DoorUnlock_l;
        break;

       default:
        REL_DW.is_Trigger_h = REL_IN_Error_m;
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
    REL_DW.is_Trigger_h = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_RlsReq_f = REL_IN_Initial_ic;
    REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_i = false;
  } else {
    switch (REL_DW.is_Trigger_h) {
     case REL_IN_DoorLock_l:
      if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
          (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
        REL_DW.is_Trigger_h = REL_IN_Release_dn;
        REL_DW.temporalCounter_i3 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_n = 20U;
      } else if (REL_DW.temporalCounter_i3 >= 100) {
        REL_DW.is_Trigger_h = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_RlsReq_f = REL_IN_Initial_ic;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_i = false;
      }
      break;

     case REL_IN_DoorUnlock_l:
      if (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3) {
        REL_DW.is_Trigger_h = REL_IN_Release_dn;
        REL_DW.temporalCounter_i3 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_n = 20U;
      }
      break;

     case REL_IN_Error_m:
      REL_DW.is_Trigger_h = REL_IN_NO_ACTIVE_CHILD_h;
      REL_DW.is_RlsReq_f = REL_IN_Initial_ic;
      REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
      REL_B.SO_b_UnlockReq_i = false;
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i3 >= 5) {
        REL_DW.is_Trigger_h = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_RlsReq_f = REL_IN_Initial_ic;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_i = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/FRDoorRlsReq' */
static void REL_DoorHand_b(const boolean_T *SI_b_DoorHandSwSts_prev, const
  boolean_T *SL_b_DoorHandSwValid_prev)
{
  if (REL_DW.is_RlsReq_j == REL_IN_Initial_ic) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
     */
    if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
        ((*SL_b_DoorHandSwValid_prev != REL_DW.SL_b_DoorHandSwValid_start) &&
         REL_DW.SL_b_DoorHandSwValid_start)) {
      REL_DW.is_RlsReq_j = REL_IN_Trigger_g;

      /* Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig' */
      switch (REL_U.VeOUT_DLK_BCMPassengerDoorLockS) {
       case 0:
        REL_DW.is_Trigger_g = REL_IN_DoorLock_l;
        REL_DW.temporalCounter_i6 = 0U;
        REL_B.SO_b_UnlockReq_i = true;
        break;

       case 1:
        REL_DW.is_Trigger_g = REL_IN_DoorUnlock_l;
        break;

       default:
        REL_DW.is_Trigger_g = REL_IN_Error_m;
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
    REL_DW.is_Trigger_g = REL_IN_NO_ACTIVE_CHILD_h;
    REL_DW.is_RlsReq_j = REL_IN_Initial_ic;
    REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
    REL_B.SO_b_UnlockReq_i = false;
  } else {
    switch (REL_DW.is_Trigger_g) {
     case REL_IN_DoorLock_l:
      if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
          (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
        REL_DW.is_Trigger_g = REL_IN_RELEASE_n;
        REL_DW.temporalCounter_i6 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_n = 0U;
      } else if (REL_DW.temporalCounter_i6 >= 100) {
        REL_DW.is_Trigger_g = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_RlsReq_j = REL_IN_Initial_ic;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_i = false;
      }
      break;

     case REL_IN_DoorUnlock_l:
      if (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3) {
        REL_DW.is_Trigger_g = REL_IN_RELEASE_n;
        REL_DW.temporalCounter_i6 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_n = 0U;
      }
      break;

     case REL_IN_Error_m:
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i6 >= 5) {
        REL_DW.is_Trigger_g = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_RlsReq_j = REL_IN_Initial_ic;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_i = false;
      }
      break;
    }
  }

  switch (REL_DW.is_SwValid_p) {
   case REL_IN_Initial_ic:
    if ((*SI_b_DoorHandSwSts_prev != REL_DW.SI_b_DoorHandSwSts_start) &&
        REL_DW.SI_b_DoorHandSwSts_start) {
      REL_DW.is_SwValid_p = REL_IN_Press_p;
      REL_DW.temporalCounter_i5 = 0U;
    }
    break;

   case REL_IN_Press_p:
    if ((*SI_b_DoorHandSwSts_prev != REL_DW.SI_b_DoorHandSwSts_start) &&
        (!REL_DW.SI_b_DoorHandSwSts_start)) {
      REL_DW.is_SwValid_p = REL_IN_Release_dnm;
      REL_DW.temporalCounter_i5 = 0U;
      REL_DW.SL_b_DoorHandSwValid = true;
    } else if (REL_DW.temporalCounter_i5 >= 100) {
      REL_DW.is_SwValid_p = REL_IN_Initial_ic;
      REL_DW.SL_b_DoorHandSwValid = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (REL_DW.temporalCounter_i5 >= 3) {
      REL_DW.is_SwValid_p = REL_IN_Initial_ic;
      REL_DW.SL_b_DoorHandSwValid = false;
    }
    break;
  }
}

/* Model step function for TID1 */
void REL_Step(void)                    /* Explicit Task: REL_Step */
{
  uint8_T SI_e_DoorLockSet_prev;
  boolean_T Compare;
  boolean_T SI_b_CrashSts_prev;
  boolean_T SI_b_DoorHandSwSts_prev_k;
  boolean_T SI_b_DoorInSwSts_prev_d;
  boolean_T SL_b_CentAllDoorSwValid_prev_n;
  boolean_T SL_b_CentSingleDoorSwValid_pr_a;
  boolean_T SL_b_DoorHandSwValid_prev_c;
  boolean_T SL_b_DoorOutSwValid_prev_b;
  boolean_T SL_b_FLDoorInSwSts;
  boolean_T SL_b_FLDoorOutSwSts;
  boolean_T SL_b_FRDoorInSwSts;
  boolean_T SL_b_FRDoorOutSwSts;
  boolean_T SL_b_RRDoorInSwSts;

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Outport: '<Root>/VeOUT_REL_BcmPassDoorSwtSts_sig_VeOUT_REL_BcmPassDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Inport: '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg'
   */
  REL_Y.VeOUT_REL_BcmPassDoorSwtSts_sig = REL_U.VbINP_HWA_FRDoorButton_flg_VbIN;

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

  /* Outport: '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorOutButton_flg_VbINP_HWA_FLDoorOutButton_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_FLDoorOutButton_flg_VbINP_HWA_FLDoorOutButton_flg_read'
   */
  REL_Y.VbOUT_REL_BcmDrvrDoorHandleReq_ = REL_U.VbINP_HWA_FLDoorOutButton_flg_V;

  /* Outport: '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg_read'
   */
  REL_Y.VbOUT_REL_BcmPassDoorHandleReq_ = REL_U.VbINP_HWA_FRDoorOutButton_flg_V;

  /* Outport: '<Root>/VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg_read'
   */
  REL_Y.VbOUT_REL_BcmLeReDoorHandleReq_ = REL_U.VbINP_HWA_RLDoorOutButton_flg_V;

  /* Outport: '<Root>/VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg_read'
   */
  REL_Y.VbOUT_REL_BcmBcmRiReDoorHandleR = REL_U.VbINP_HWA_RRDoorOutButton_flg_V;

  /* Outport: '<Root>/VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg_read'
   */
  REL_Y.VbOUT_REL_FLDoorHndlBtnSig_flg_ = REL_U.VbINP_HWA_FLDoorHandleSW_flg_Vb;

  /* Outport: '<Root>/VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorHandleSW_flg_VbINP_HWA_FRDoorHandleSW_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_FRDoorHandleSW_flg_VbINP_HWA_FRDoorHandleSW_flg_read'
   */
  REL_Y.VbOUT_REL_FRDoorHndlBtnSig_flg_ = REL_U.VbINP_HWA_FRDoorHandleSW_flg_Vb;

  /* Outport: '<Root>/VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg_read'
   */
  REL_Y.VbOUT_REL_RLDoorHndlBtnSig_flg_ = REL_U.VbINP_HWA_RLDoorHandleSW_flg_Vb;

  /* Outport: '<Root>/VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorHandleSW_flg_VbINP_HWA_RRDoorHandleSW_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_RRDoorHandleSW_flg_VbINP_HWA_RRDoorHandleSW_flg_read'
   */
  REL_Y.VbOUT_REL_RRDoorHndlBtnSig_flg_ = REL_U.VbINP_HWA_RRDoorHandleSW_flg_Vb;

  /* Chart: '<S3>/DoorSwSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg'
   *  Inport: '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg'
   *  Inport: '<Root>/VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg'
   *  Inport: '<Root>/VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg'
   *  Inport: '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg'
   *  Outport: '<Root>/VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg'
   *  Outport: '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg'
   *  Outport: '<Root>/VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg'
   *  Outport: '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg'
   *  Outport: '<Root>/VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg'
   */
  if (REL_DW.temporalCounter_i1 < 1023U) {
    REL_DW.temporalCounter_i1++;
  }

  SI_b_CrashSts_prev = REL_DW.SI_b_CrashSts_start;
  REL_DW.SI_b_CrashSts_start = REL_U.VbOUT_SP_CrashOutpSts_flg_VbOUT;
  if (REL_DW.is_active_c23_REL == 0U) {
    REL_DW.is_active_c23_REL = 1U;
    REL_DW.is_c23_REL = REL_IN_NoCrash;
    REL_enter_atomic_NoCrash(&SL_b_FLDoorInSwSts, &SL_b_FRDoorInSwSts,
      &SI_b_CrashSts_prev, &SL_b_RRDoorInSwSts, &SL_b_FLDoorOutSwSts,
      &SL_b_FRDoorOutSwSts);
  } else if (REL_DW.is_c23_REL == REL_IN_Crash) {
    if (REL_DW.temporalCounter_i1 >= 1000) {
      REL_DW.is_c23_REL = REL_IN_NoCrash;
      REL_enter_atomic_NoCrash(&SL_b_FLDoorInSwSts, &SL_b_FRDoorInSwSts,
        &SI_b_CrashSts_prev, &SL_b_RRDoorInSwSts, &SL_b_FLDoorOutSwSts,
        &SL_b_FRDoorOutSwSts);
    } else {
      SL_b_FLDoorInSwSts = false;
      SL_b_FRDoorInSwSts = false;
      SI_b_CrashSts_prev = false;
      SL_b_RRDoorInSwSts = false;
      SL_b_FLDoorOutSwSts = false;
      SL_b_FRDoorOutSwSts = false;
      REL_B.SL_b_RLDoorOutSwSts = false;
      REL_B.SL_b_RRDoorOutSwSts = false;
      REL_B.SL_b_FLDoorHandSwSts = false;
      REL_B.SL_b_FRDoorHandSwSts = false;
      REL_B.SL_b_RLDoorHandSwSts = false;
      REL_B.SL_b_RRDoorHandSwSts = false;
    }

    /* case IN_NoCrash: */
  } else if ((SI_b_CrashSts_prev != REL_DW.SI_b_CrashSts_start) &&
             REL_DW.SI_b_CrashSts_start) {
    REL_DW.is_c23_REL = REL_IN_Crash;
    REL_DW.temporalCounter_i1 = 0U;
    SL_b_FLDoorInSwSts = false;
    SL_b_FRDoorInSwSts = false;
    SI_b_CrashSts_prev = false;
    SL_b_RRDoorInSwSts = false;
    SL_b_FLDoorOutSwSts = false;
    SL_b_FRDoorOutSwSts = false;
    REL_B.SL_b_RLDoorOutSwSts = false;
    REL_B.SL_b_RRDoorOutSwSts = false;
    REL_B.SL_b_FLDoorHandSwSts = false;
    REL_B.SL_b_FRDoorHandSwSts = false;
    REL_B.SL_b_RLDoorHandSwSts = false;
    REL_B.SL_b_RRDoorHandSwSts = false;
  } else {
    SL_b_FLDoorInSwSts = REL_U.VbINP_HWA_FLDoorButton_flg_VbIN;
    SL_b_FRDoorInSwSts = REL_U.VbINP_HWA_FRDoorButton_flg_VbIN;
    SI_b_CrashSts_prev = REL_U.VbINP_HWA_RLDoorButton_flg_VbIN;
    SL_b_RRDoorInSwSts = REL_U.VbINP_HWA_RRDoorButton_flg_VbIN;
    SL_b_FLDoorOutSwSts = REL_Y.VbOUT_REL_BcmDrvrDoorHandleReq_;
    SL_b_FRDoorOutSwSts = REL_Y.VbOUT_REL_BcmPassDoorHandleReq_;
    REL_B.SL_b_RLDoorOutSwSts = REL_Y.VbOUT_REL_BcmLeReDoorHandleReq_;
    REL_B.SL_b_RRDoorOutSwSts = REL_Y.VbOUT_REL_BcmBcmRiReDoorHandleR;
    REL_B.SL_b_FLDoorHandSwSts = REL_Y.VbOUT_REL_FLDoorHndlBtnSig_flg_;
    REL_B.SL_b_FRDoorHandSwSts = REL_Y.VbOUT_REL_FRDoorHndlBtnSig_flg_;
    REL_B.SL_b_RLDoorHandSwSts = REL_Y.VbOUT_REL_RLDoorHndlBtnSig_flg_;
    REL_B.SL_b_RRDoorHandSwSts = REL_Y.VbOUT_REL_RRDoorHndlBtnSig_flg_;
  }

  /* End of Chart: '<S3>/DoorSwSts' */

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Constant: '<S12>/Constant'
   *  Inport: '<Root>/VeOUT_PDU_BcmPowerStatusFeedback_sig_VeOUT_PDU_BcmPowerStatusFeedback_sig'
   */
  Compare = (REL_U.VeOUT_PDU_BcmPowerStatusFeedbac == 0);

  /* Truth Table: '<S3>/FLDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V);

  /* Chart: '<S3>/FLDoorRlsReq' incorporates:
   *  Constant: '<S3>/Constant2'
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DHM_BDCDrvrDoorHndSts_sig_VeOUT_DHM_BDCDrvrDoorHndSts_sig'
   *  Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig'
   */
  if (REL_DW.temporalCounter_i1_m < 7U) {
    REL_DW.temporalCounter_i1_m++;
  }

  if (REL_DW.temporalCounter_i2_h < 255U) {
    REL_DW.temporalCounter_i2_h++;
  }

  if (REL_DW.temporalCounter_i3_b < 127U) {
    REL_DW.temporalCounter_i3_b++;
  }

  if (REL_DW.temporalCounter_i4_p < 7U) {
    REL_DW.temporalCounter_i4_p++;
  }

  if (REL_DW.temporalCounter_i5_l < 127U) {
    REL_DW.temporalCounter_i5_l++;
  }

  if (REL_DW.temporalCounter_i6_c < 127U) {
    REL_DW.temporalCounter_i6_c++;
  }

  if (REL_DW.temporalCounter_i7_l < 127U) {
    REL_DW.temporalCounter_i7_l++;
  }

  REL_DW.SI_b_DoorLockOpenReq_start_e = false;
  SI_b_DoorInSwSts_prev_d = REL_DW.SI_b_DoorInSwSts_start_g;
  REL_DW.SI_b_DoorInSwSts_start_g = SL_b_FLDoorInSwSts;
  SL_b_FLDoorInSwSts = REL_DW.SL_b_DoorInSwValid_start_n;
  REL_DW.SL_b_DoorInSwValid_start_n = REL_DW.SL_b_DoorInSwValid_g;
  SL_b_DoorOutSwValid_prev_b = REL_DW.SL_b_DoorOutSwValid_start_a;
  REL_DW.SL_b_DoorOutSwValid_start_a = REL_DW.SL_b_DoorOutSwValid_n;
  SI_b_DoorHandSwSts_prev_k = REL_DW.SI_b_DoorHandSwSts_start_c;
  REL_DW.SI_b_DoorHandSwSts_start_c = REL_B.SL_b_FLDoorHandSwSts;
  SL_b_DoorHandSwValid_prev_c = REL_DW.SL_b_DoorHandSwValid_start_l;
  REL_DW.SL_b_DoorHandSwValid_start_l = REL_DW.SL_b_DoorHandSwValid_m;
  SL_b_CentSingleDoorSwValid_pr_a = REL_DW.SL_b_CentSingleDoorSwValid_st_o;
  REL_DW.SL_b_CentSingleDoorSwValid_st_o = REL_DW.SL_b_CentSingleDoorSwValid_h;
  SL_b_CentAllDoorSwValid_prev_n = REL_DW.SL_b_CentAllDoorSwValid_start_o;
  REL_DW.SL_b_CentAllDoorSwValid_start_o = REL_DW.SL_b_CentAllDoorSwValid_h;
  if (REL_DW.is_active_c5_DoorRlsReq_o == 0U) {
    REL_DW.is_active_c5_DoorRlsReq_o = 1U;
    REL_DW.is_SwValid_pj = REL_IN_Initial_ic;
    REL_DW.SL_b_DoorInSwValid_g = false;
    REL_DW.is_RlsReq_o = REL_IN_Initial_ic;
    REL_DW.is_DoorCentral_f = REL_IN_Initial_ic;
    REL_DW.SL_b_CentSingleDoorSwValid_h = REL_U.VbINP_CAN_CdcDrvrDoorButtonSts_;
    REL_DW.SL_b_CentAllDoorSwValid_h = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
    REL_DW.SL_b_DoorOutSwValid_n = SL_b_FLDoorOutSwSts;
    REL_DW.is_RlsReq_o0 = REL_IN_Initial_ic;
    REL_DW.is_RlsReq_id = REL_IN_Initial_ic;
    REL_B.SO_b_UnlockReq_f = false;
    REL_DW.is_SwValid_j = REL_IN_Initial_ic;
    REL_DW.SL_b_DoorHandSwValid_m = false;
    REL_DW.is_RlsReq_p = REL_IN_Initial_ic;

    /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' incorporates:
     *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
     *  Inport: '<Root>/VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg'
     */
    REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
  } else {
    REL_DoorIn_l(&SI_b_DoorInSwSts_prev_d, &SL_b_FLDoorInSwSts);
    if (REL_DW.is_DoorCentral_f == REL_IN_Initial_ic) {
      if ((!Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
          (((SL_b_CentSingleDoorSwValid_pr_a !=
             REL_DW.SL_b_CentSingleDoorSwValid_st_o) &&
            REL_DW.SL_b_CentSingleDoorSwValid_st_o) ||
           ((SL_b_CentAllDoorSwValid_prev_n !=
             REL_DW.SL_b_CentAllDoorSwValid_start_o) &&
            REL_DW.SL_b_CentAllDoorSwValid_start_o))) {
        REL_DW.is_DoorCentral_f = REL_IN_Trigger_g;
        switch (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si) {
         case 0:
          REL_DW.is_Trigger_k = REL_IN_DoorLock_l;
          REL_DW.temporalCounter_i7_l = 0U;
          REL_B.SO_b_UnlockReq_f = true;
          break;

         case 1:
          REL_DW.is_Trigger_k = REL_IN_DoorUnlock_l;
          break;

         default:
          REL_DW.is_Trigger_k = REL_IN_Error_m;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (Compare || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                           (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP != 1)) ||
               ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
                (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V == 3))) {
      REL_DW.is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_h;
      REL_DW.is_DoorCentral_f = REL_IN_Initial_ic;

      /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
      REL_B.SO_b_UnlockReq_f = false;
    } else {
      switch (REL_DW.is_Trigger_k) {
       case REL_IN_DoorLock_l:
        if (REL_DW.temporalCounter_i7_l >= 100) {
          REL_DW.is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_h;
          REL_DW.is_DoorCentral_f = REL_IN_Initial_ic;

          /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
          REL_B.SO_b_UnlockReq_f = false;
        } else if ((REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
                   (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3)) {
          REL_DW.is_Trigger_k = REL_IN_RELEASE_n;
          REL_DW.temporalCounter_i7_l = 0U;

          /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
          REL_B.SO_e_DoorRlsDelayTime_n3 = 0U;
        }
        break;

       case REL_IN_DoorUnlock_l:
        if (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3) {
          REL_DW.is_Trigger_k = REL_IN_RELEASE_n;
          REL_DW.temporalCounter_i7_l = 0U;

          /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
          REL_B.SO_e_DoorRlsDelayTime_n3 = 0U;
        }
        break;

       case REL_IN_Error_m:
        REL_DW.is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_DoorCentral_f = REL_IN_Initial_ic;

        /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_f = false;
        break;

       default:
        /* case IN_RELEASE: */
        if (REL_DW.temporalCounter_i7_l >= 5) {
          REL_DW.is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_h;
          REL_DW.is_DoorCentral_f = REL_IN_Initial_ic;

          /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
          REL_B.SO_b_UnlockReq_f = false;
        }
        break;
      }
    }

    REL_DW.SL_b_CentSingleDoorSwValid_h = REL_U.VbINP_CAN_CdcDrvrDoorButtonSts_;
    REL_DW.SL_b_CentAllDoorSwValid_h = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
    REL_DW.SL_b_DoorOutSwValid_n = SL_b_FLDoorOutSwSts;
    if (REL_DW.is_RlsReq_o0 == REL_IN_Initial_ic) {
      if ((!Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
          (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si == 1) &&
          (REL_U.VeOUT_DHM_BDCDrvrDoorHndSts_sig == 1) &&
          ((SL_b_DoorOutSwValid_prev_b != REL_DW.SL_b_DoorOutSwValid_start_a) &&
           REL_DW.SL_b_DoorOutSwValid_start_a)) {
        REL_DW.is_RlsReq_o0 = REL_IN_Trigger_g;
        REL_DW.is_Trigger_d = REL_IN_Wait_g;
      }

      /* case IN_Trigger: */
    } else if (Compare || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                           (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP != 1)) ||
               (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si != 1) ||
               (REL_U.VeOUT_DHM_BDCDrvrDoorHndSts_sig != 1) ||
               (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V == 3)) {
      REL_DW.is_Trigger_d = REL_IN_NO_ACTIVE_CHILD_h;
      REL_DW.is_RlsReq_o0 = REL_IN_Initial_ic;

      /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
      REL_B.SO_b_UnlockReq_f = false;
    } else if (REL_DW.is_Trigger_d == REL_IN_Release_d) {
      if (REL_DW.temporalCounter_i4_p >= 5) {
        REL_DW.is_Trigger_d = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_RlsReq_o0 = REL_IN_Initial_ic;

        /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_f = false;
      }

      /* case IN_Wait: */
    } else if (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3) {
      REL_DW.is_Trigger_d = REL_IN_Release_d;
      REL_DW.temporalCounter_i4_p = 0U;

      /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
      REL_B.SO_e_DoorRlsDelayTime_n3 = 4U;
    }

    REL_DoorHand_k(&SI_b_DoorHandSwSts_prev_k, &SL_b_DoorHandSwValid_prev_c);
    if (REL_DW.is_RlsReq_p != REL_IN_Initial_ic) {
      /* case IN_Trigger: */
      if (Compare || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                      (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                      (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP != 1)) ||
          (!REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts) ||
          (REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si != 1) ||
          (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V == 3)) {
        REL_DW.is_Trigger_h3 = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_RlsReq_p = REL_IN_Initial_ic;

        /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
      } else if (REL_DW.is_Trigger_h3 == REL_IN_Release_d) {
        if (REL_DW.temporalCounter_i1_m >= 5) {
          REL_DW.is_Trigger_h3 = REL_IN_NO_ACTIVE_CHILD_h;
          REL_DW.is_RlsReq_p = REL_IN_Initial_ic;

          /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        }

        /* case IN_WAIT: */
      } else if (REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V != 3) {
        REL_DW.is_Trigger_h3 = REL_IN_Release_d;
        REL_DW.temporalCounter_i1_m = 0U;

        /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
      }
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
                      REL_B.SO_e_DoorRlsDelayTime_n3,
                      &REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU,
                      &REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU,
                      &REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve,
                      &SL_b_FLDoorOutSwSts, &SI_e_DoorLockSet_prev,
                      &REL_DW.sf_FLDoorRlsDriver);

  /* Truth Table: '<S3>/FRDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_FRDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V);

  /* Chart: '<S3>/FRDoorRlsReq' incorporates:
   *  Constant: '<S3>/Constant4'
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DHM_BDCPassDoorHndSts_sig_VeOUT_DHM_BDCPassDoorHndSts_sig'
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig'
   */
  if (REL_DW.temporalCounter_i1_b < 7U) {
    REL_DW.temporalCounter_i1_b++;
  }

  if (REL_DW.temporalCounter_i2 < 255U) {
    REL_DW.temporalCounter_i2++;
  }

  if (REL_DW.temporalCounter_i3 < 127U) {
    REL_DW.temporalCounter_i3++;
  }

  if (REL_DW.temporalCounter_i4 < 7U) {
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

  REL_DW.SI_b_DoorLockOpenReq_start = false;
  SL_b_FLDoorOutSwSts = REL_DW.SI_b_DoorInSwSts_start;
  REL_DW.SI_b_DoorInSwSts_start = SL_b_FRDoorInSwSts;
  SL_b_FRDoorInSwSts = REL_DW.SL_b_DoorInSwValid_start;
  REL_DW.SL_b_DoorInSwValid_start = REL_DW.SL_b_DoorInSwValid;
  SI_b_DoorInSwSts_prev_d = REL_DW.SL_b_DoorOutSwValid_start;
  REL_DW.SL_b_DoorOutSwValid_start = REL_DW.SL_b_DoorOutSwValid;
  SL_b_FLDoorInSwSts = REL_DW.SI_b_DoorHandSwSts_start;
  REL_DW.SI_b_DoorHandSwSts_start = REL_B.SL_b_FRDoorHandSwSts;
  SL_b_DoorOutSwValid_prev_b = REL_DW.SL_b_DoorHandSwValid_start;
  REL_DW.SL_b_DoorHandSwValid_start = REL_DW.SL_b_DoorHandSwValid;
  SI_b_DoorHandSwSts_prev_k = REL_DW.SL_b_CentSingleDoorSwValid_star;
  REL_DW.SL_b_CentSingleDoorSwValid_star = REL_DW.SL_b_CentSingleDoorSwValid;
  SL_b_DoorHandSwValid_prev_c = REL_DW.SL_b_CentAllDoorSwValid_start;
  REL_DW.SL_b_CentAllDoorSwValid_start = REL_DW.SL_b_CentAllDoorSwValid;
  if (REL_DW.is_active_c5_DoorRlsReq == 0U) {
    REL_DW.is_active_c5_DoorRlsReq = 1U;
    REL_DW.is_SwValid = REL_IN_Initial_ic;
    REL_DW.SL_b_DoorInSwValid = false;
    REL_DW.is_RlsReq_f = REL_IN_Initial_ic;
    REL_DW.is_DoorCentral = REL_IN_Initial_ic;
    REL_DW.SL_b_CentSingleDoorSwValid = REL_U.VbINP_CAN_CdcPassDoorButtonSts_;
    REL_DW.SL_b_CentAllDoorSwValid = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
    REL_DW.SL_b_DoorOutSwValid = SL_b_FRDoorOutSwSts;
    REL_DW.is_RlsReq_i = REL_IN_Initial_ic;
    REL_DW.is_RlsReq_j = REL_IN_Initial_ic;
    REL_B.SO_b_UnlockReq_i = false;
    REL_DW.is_SwValid_p = REL_IN_Initial_ic;
    REL_DW.SL_b_DoorHandSwValid = false;
    REL_DW.is_RlsReq = REL_IN_Initial_ic;

    /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' incorporates:
     *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
     *  Inport: '<Root>/VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg'
     */
    REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
  } else {
    REL_DoorIn_e(&SL_b_FLDoorOutSwSts, &SL_b_FRDoorInSwSts);
    if (REL_DW.is_DoorCentral == REL_IN_Initial_ic) {
      if ((!Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
          (((SI_b_DoorHandSwSts_prev_k != REL_DW.SL_b_CentSingleDoorSwValid_star)
            && REL_DW.SL_b_CentSingleDoorSwValid_star) ||
           ((SL_b_DoorHandSwValid_prev_c != REL_DW.SL_b_CentAllDoorSwValid_start)
            && REL_DW.SL_b_CentAllDoorSwValid_start))) {
        REL_DW.is_DoorCentral = REL_IN_Trigger_g;
        switch (REL_U.VeOUT_DLK_BCMPassengerDoorLockS) {
         case 0:
          REL_DW.is_Trigger_f = REL_IN_DoorLock_l;
          REL_DW.temporalCounter_i7 = 0U;
          REL_B.SO_b_UnlockReq_i = true;
          break;

         case 1:
          REL_DW.is_Trigger_f = REL_IN_DoorUnlock_l;
          break;

         default:
          REL_DW.is_Trigger_f = REL_IN_Error_m;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (Compare || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                           (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP != 1)) ||
               ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
                (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V == 3))) {
      REL_DW.is_Trigger_f = REL_IN_NO_ACTIVE_CHILD_h;
      REL_DW.is_DoorCentral = REL_IN_Initial_ic;

      /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
      REL_B.SO_b_UnlockReq_i = false;
    } else {
      switch (REL_DW.is_Trigger_f) {
       case REL_IN_DoorLock_l:
        if (REL_DW.temporalCounter_i7 >= 100) {
          REL_DW.is_Trigger_f = REL_IN_NO_ACTIVE_CHILD_h;
          REL_DW.is_DoorCentral = REL_IN_Initial_ic;

          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
          REL_B.SO_b_UnlockReq_i = false;
        } else if ((REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
                   (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3)) {
          REL_DW.is_Trigger_f = REL_IN_RELEASE_n;
          REL_DW.temporalCounter_i7 = 0U;

          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
          REL_B.SO_e_DoorRlsDelayTime_n = 0U;
        }
        break;

       case REL_IN_DoorUnlock_l:
        if (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3) {
          REL_DW.is_Trigger_f = REL_IN_RELEASE_n;
          REL_DW.temporalCounter_i7 = 0U;

          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
          REL_B.SO_e_DoorRlsDelayTime_n = 0U;
        }
        break;

       case REL_IN_Error_m:
        REL_DW.is_Trigger_f = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_DoorCentral = REL_IN_Initial_ic;

        /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_i = false;
        break;

       default:
        /* case IN_RELEASE: */
        if (REL_DW.temporalCounter_i7 >= 5) {
          REL_DW.is_Trigger_f = REL_IN_NO_ACTIVE_CHILD_h;
          REL_DW.is_DoorCentral = REL_IN_Initial_ic;

          /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
          REL_B.SO_b_UnlockReq_i = false;
        }
        break;
      }
    }

    REL_DW.SL_b_CentSingleDoorSwValid = REL_U.VbINP_CAN_CdcPassDoorButtonSts_;
    REL_DW.SL_b_CentAllDoorSwValid = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
    REL_DW.SL_b_DoorOutSwValid = SL_b_FRDoorOutSwSts;
    if (REL_DW.is_RlsReq_i == REL_IN_Initial_ic) {
      if ((!Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                         (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP == 1)) &&
          (REL_U.VeOUT_DLK_BCMPassengerDoorLockS == 1) &&
          (REL_U.VeOUT_DHM_BDCPassDoorHndSts_sig == 1) &&
          ((SI_b_DoorInSwSts_prev_d != REL_DW.SL_b_DoorOutSwValid_start) &&
           REL_DW.SL_b_DoorOutSwValid_start)) {
        REL_DW.is_RlsReq_i = REL_IN_Trigger_g;
        REL_DW.is_Trigger_b = REL_IN_Wait_g;
      }

      /* case IN_Trigger: */
    } else if (Compare || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                           (REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP != 1)) ||
               (REL_U.VeOUT_DLK_BCMPassengerDoorLockS != 1) ||
               (REL_U.VeOUT_DHM_BDCPassDoorHndSts_sig != 1) ||
               (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V == 3)) {
      REL_DW.is_Trigger_b = REL_IN_NO_ACTIVE_CHILD_h;
      REL_DW.is_RlsReq_i = REL_IN_Initial_ic;

      /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
      REL_B.SO_b_UnlockReq_i = false;
    } else if (REL_DW.is_Trigger_b == REL_IN_Release_d) {
      if (REL_DW.temporalCounter_i4 >= 5) {
        REL_DW.is_Trigger_b = REL_IN_NO_ACTIVE_CHILD_h;
        REL_DW.is_RlsReq_i = REL_IN_Initial_ic;

        /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_B.SO_b_UnlockReq_i = false;
      }

      /* case IN_Wait: */
    } else if (REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V != 3) {
      REL_DW.is_Trigger_b = REL_IN_Release_d;
      REL_DW.temporalCounter_i4 = 0U;

      /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
      REL_B.SO_e_DoorRlsDelayTime_n = 4U;
    }

    REL_DoorHand_b(&SL_b_FLDoorInSwSts, &SL_b_DoorOutSwValid_prev_b);
    if (REL_DW.is_RlsReq != REL_IN_Initial_ic) {
      /* case IN_Trigger: */
      REL_DW.is_Trigger = REL_IN_NO_ACTIVE_CHILD_h;
      REL_DW.is_RlsReq = REL_IN_Initial_ic;

      /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
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
                      REL_B.SO_e_DoorRlsDelayTime_n,
                      &REL_Y.VbOUT_REL_FRDoorMotorA_flg_VbOU,
                      &REL_Y.VbOUT_REL_FRDoorMotorB_flg_VbOU,
                      &REL_Y.VeOUT_REL_FRDoorMotorSts_sig_Ve,
                      &SL_b_FRDoorOutSwSts, &SI_e_DoorLockSet_prev,
                      &REL_DW.sf_FRDoorRlsDriver);

  /* Truth Table: '<S3>/RLDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLRDoorRatSts_sig_VeOUT_REL_BdcLRDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_RLDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcLRDoorRatSts_sig_V);

  /* Chart: '<S3>/RLDoorRlsReq' incorporates:
   *  Constant: '<S3>/Constant10'
   *  Constant: '<S3>/Constant6'
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcLeReDoorButtonSts_flg_VbINP_CAN_CdcLeReDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbINP_HWA_LRChildLckSt_flg_VbINP_HWA_LRChildLckSt_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DHM_BDCLeReDoorHndSts_sig_VeOUT_DHM_BDCLeReDoorHndSts_sig'
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcLRDoorRatSts_sig_VeOUT_REL_BdcLRDoorRatSts_sig'
   */
  REL_RLDoorRlsReq(Compare, REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                   REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN,
                   REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP,
                   REL_U.VeOUT_DLK_BCMPassengerDoorLockS,
                   REL_Y.VeOUT_REL_BdcLRDoorRatSts_sig_V, SI_b_CrashSts_prev,
                   REL_B.SL_b_RLDoorOutSwSts, REL_B.SL_b_RLDoorHandSwSts,
                   REL_U.VeOUT_DHM_BDCLeReDoorHndSts_sig,
                   REL_U.VbINP_CAN_CdcLeReDoorButtonSts_,
                   REL_U.VbINP_CAN_CdcAllDoorOpenButtonS,
                   REL_U.VbINP_HWA_LRChildLckSt_flg_VbIN, false, false,
                   &REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU,
                   &REL_B.SO_b_UnlockReq_e, &REL_B.SO_e_DoorRlsDelayTime_m,
                   &REL_DW.sf_RLDoorRlsReq);

  /* Truth Table: '<S3>/RRDoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcRRDoorRatSts_sig_VeOUT_REL_BdcRRDoorRatSts_sig'
   */
  REL_FLDoorRatSts(REL_U.VbINP_HWA_RRDoorAjar_flg_VbINP_,
                   &REL_Y.VeOUT_REL_BdcRRDoorRatSts_sig_V);

  /* Chart: '<S3>/RRDoorRlsReq' incorporates:
   *  Constant: '<S3>/Constant11'
   *  Constant: '<S3>/Constant12'
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcRiReDoorButtonSts_flg_VbINP_CAN_CdcRiReDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbINP_HWA_RRChildLckSt_flg_VbINP_HWA_RRChildLckSt_flg'
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   *  Inport: '<Root>/VeOUT_DHM_BDCRiReDoorHndSts_sig_VeOUT_DHM_BDCRiReDoorHndSts_sig'
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_BdcRRDoorRatSts_sig_VeOUT_REL_BdcRRDoorRatSts_sig'
   */
  REL_RLDoorRlsReq(Compare, REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                   REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN,
                   REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP,
                   REL_U.VeOUT_DLK_BCMPassengerDoorLockS,
                   REL_Y.VeOUT_REL_BdcRRDoorRatSts_sig_V, SL_b_RRDoorInSwSts,
                   REL_B.SL_b_RRDoorOutSwSts, REL_B.SL_b_RRDoorHandSwSts,
                   REL_U.VeOUT_DHM_BDCRiReDoorHndSts_sig,
                   REL_U.VbINP_CAN_CdcRiReDoorButtonSts_,
                   REL_U.VbINP_CAN_CdcAllDoorOpenButtonS,
                   REL_U.VbINP_HWA_RRChildLckSt_flg_VbIN, false, false,
                   &REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU, &REL_B.SO_b_UnlockReq,
                   &REL_B.SO_e_DoorRlsDelayTime, &REL_DW.sf_RRDoorRlsReq);

  /* Logic: '<S3>/Logical Operator' */
  SI_b_CrashSts_prev = (REL_B.SO_b_UnlockReq_i || REL_B.SO_b_UnlockReq_e ||
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
                      REL_B.SO_e_DoorRlsDelayTime_m,
                      &REL_Y.VbOUT_REL_RLDoorMotorA_flg_VbOU,
                      &REL_Y.VbOUT_REL_RLDoorMotorB_flg_VbOU,
                      &REL_Y.VeOUT_REL_RLDoorMotorSts_sig_Ve,
                      &SL_b_RRDoorInSwSts, &SI_e_DoorLockSet_prev,
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
                      &SL_b_RRDoorInSwSts, &SI_e_DoorLockSet_prev,
                      &REL_DW.sf_RRDoorRlsDriver);

  /* Chart: '<S3>/Unlock_Request' */
  SL_b_RRDoorInSwSts = REL_DW.SI_b_DrvUnlockReq_start;
  REL_DW.SI_b_DrvUnlockReq_start = REL_B.SO_b_UnlockReq_f;
  Compare = REL_DW.SI_b_PassUnlockReq_start;
  REL_DW.SI_b_PassUnlockReq_start = SI_b_CrashSts_prev;
  if (REL_DW.is_active_c6_REL == 0U) {
    REL_DW.is_active_c6_REL = 1U;
    REL_DW.is_c6_REL = REL_IN_Initial_ic;

    /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
    REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 0U;
  } else if (REL_DW.is_c6_REL == REL_IN_Initial_ic) {
    if (((SL_b_RRDoorInSwSts != REL_DW.SI_b_DrvUnlockReq_start) &&
         REL_DW.SI_b_DrvUnlockReq_start) || ((Compare !=
          REL_DW.SI_b_PassUnlockReq_start) && REL_DW.SI_b_PassUnlockReq_start))
    {
      REL_DW.is_c6_REL = REL_IN_REQ_SENT;
    }
  } else {
    /* case IN_REQ_SENT: */
    SL_b_RRDoorInSwSts = !SI_b_CrashSts_prev;
    Compare = !REL_B.SO_b_UnlockReq_f;
    if (Compare && SL_b_RRDoorInSwSts) {
      REL_DW.is_c6_REL = REL_IN_Initial_ic;

      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 0U;
    } else if (REL_B.SO_b_UnlockReq_f && SI_b_CrashSts_prev) {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 3U;
    } else if (REL_B.SO_b_UnlockReq_f && SL_b_RRDoorInSwSts) {
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
                          &REL_B.SO_b_UnlockReq_e,
                          &REL_B.SO_e_DoorRlsDelayTime_m);

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
