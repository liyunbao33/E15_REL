/*
 * File: REL.c
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.44
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Sep 11 13:20:45 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "REL.h"
#include "Rte_Type.h"
#include "rtwtypes.h"
#include "REL_private.h"

/* Named constants for Chart: '<S3>/FLDoorRlsDriver' */
#define REL_IN_Checking                ((uint8)1U)
#define REL_IN_Delay                   ((uint8)2U)
#define REL_IN_ElectricDoor            ((uint8)1U)
#define REL_IN_Error                   ((uint8)1U)
#define REL_IN_Error1                  ((uint8)2U)
#define REL_IN_Ice_Break               ((uint8)3U)
#define REL_IN_Idle                    ((uint8)1U)
#define REL_IN_Idle_c                  ((uint8)4U)
#define REL_IN_Initial                 ((uint8)3U)
#define REL_IN_LastCheck               ((uint8)5U)
#define REL_IN_LastCheck_m             ((uint8)2U)
#define REL_IN_NO_ACTIVE_CHILD         ((uint8)0U)
#define REL_IN_NonElectricDoor         ((uint8)2U)
#define REL_IN_Normal                  ((uint8)1U)
#define REL_IN_PowerOn                 ((uint8)2U)
#define REL_IN_Release                 ((uint8)2U)
#define REL_IN_Reset                   ((uint8)4U)
#define REL_IN_Step2_Open              ((uint8)5U)

/* Named constants for Chart: '<S3>/RLDoorRlsReq' */
#define REL_IN_DoorLock                ((uint8)1U)
#define REL_IN_DoorUnlock              ((uint8)2U)
#define REL_IN_Error_l                 ((uint8)3U)
#define REL_IN_Idle_a                  ((uint8)1U)
#define REL_IN_Initial_k               ((uint8)1U)
#define REL_IN_NO_ACTIVE_CHILD_a       ((uint8)0U)
#define REL_IN_Once                    ((uint8)2U)
#define REL_IN_Press                   ((uint8)2U)
#define REL_IN_RELEASE                 ((uint8)4U)
#define REL_IN_Release_l               ((uint8)1U)
#define REL_IN_Release_lv              ((uint8)4U)
#define REL_IN_Release_lvk             ((uint8)3U)
#define REL_IN_Trigger                 ((uint8)2U)
#define REL_IN_Twice                   ((uint8)3U)
#define REL_IN_WAIT                    ((uint8)2U)
#define REL_IN_Wait                    ((uint8)2U)

/* Named constants for Chart: '<S3>/DoorLockSetSts' */
#define REL_IN_DoorLockSet             ((uint8)1U)
#define REL_IN_Init                    ((uint8)2U)
#define REL_IN_NO_ACTIVE_CHILD_f       ((uint8)0U)

/* Named constants for Chart: '<S3>/DoorSwSts' */
#define REL_IN_Crash                   ((uint8)1U)
#define REL_IN_NoCrash                 ((uint8)2U)

/* Named constants for Chart: '<S3>/FLDoorRlsReq' */
#define REL_IN_DoorLock_b              ((uint8)1U)
#define REL_IN_DoorUnlock_h            ((uint8)2U)
#define REL_IN_Error_f                 ((uint8)3U)
#define REL_IN_Idle_n                  ((uint8)1U)
#define REL_IN_Initial_b               ((uint8)1U)
#define REL_IN_Once_a                  ((uint8)2U)
#define REL_IN_Press_f                 ((uint8)2U)
#define REL_IN_RELEASE_j               ((uint8)4U)
#define REL_IN_Release_h               ((uint8)1U)
#define REL_IN_Release_ht              ((uint8)4U)
#define REL_IN_Release_htd             ((uint8)3U)
#define REL_IN_Trigger_h               ((uint8)2U)
#define REL_IN_Twice_m                 ((uint8)3U)
#define REL_IN_Wait_b                  ((uint8)2U)

/* Named constants for Chart: '<S3>/Unlock_Request' */
#define REL_IN_REQ_SENT                ((uint8)2U)

/* Block signals (default storage) */
B_REL_T REL_B;

/* Block states (default storage) */
DW_REL_T REL_DW;

/* Forward declaration for local functions */
static void REL_Normal(Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_CinchHome,
  uint8 rtu_SI_e_DoorRlsDelayTime, boolean *rty_SO_b_MotorA, boolean
  *rty_SO_b_MotorB, uint8 *rty_SO_e_MotorMode, boolean *rty_SO_b_Error, uint8
  *rty_SO_e_MotorPwm, DW_FLDoorRlsDriver_REL_T *localDW);

/* Forward declaration for local functions */
static void REL_DoorInBtn(UInt8 rtu_SI_e_EspVehSpd, Boolean
  rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8 rtu_SI_e_DoorLockSts,
  uint8 rtu_SI_e_DoorRatSts, Boolean rtu_SI_b_ChildLckSts, boolean
  *rty_SO_b_DoorRlsReq, boolean *rty_SO_b_UnlockReq, uint8
  *rty_SO_e_DoorRlsDelayTime, DW_RLDoorRlsReq_REL_T *localDW);
static void REL_DoorHand(UInt8 rtu_SI_e_EspVehSpd, Boolean rtu_SI_b_EspVehSpdVld,
  UInt8 rtu_SI_e_VcuGearPosn, UInt8 rtu_SI_e_DoorLockSts, uint8
  rtu_SI_e_DoorRatSts, boolean *rty_SO_b_DoorRlsReq, boolean *rty_SO_b_UnlockReq,
  uint8 *rty_SO_e_DoorRlsDelayTime, DW_RLDoorRlsReq_REL_T *localDW);

/* Forward declaration for local functions */
static void REL_enter_atomic_NoCrash(boolean *SL_b_FLDoorInBtnSts, boolean
  *SL_b_FRDoorInBtnSts, boolean *SL_b_FLDoorHndPullSts);
static void REL_DoorInBtn_i(void);
static void REL_DoorHand_c(void);
static void REL_DoorInBtn_i5(void);
static void REL_DoorHand_e(void);

/*
 * Output and update for atomic system:
 *    '<S3>/FLDoorRatSts'
 *    '<S3>/FRDoorRatSts'
 *    '<S3>/RLDoorRatSts'
 *    '<S3>/RRDoorRatSts'
 */
void REL_FLDoorRatSts(Boolean rtu_SI_b_DoorOpen, uint8 *rty_SO_e_DoorRatSts)
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
  uint8 rtu_SI_e_DoorRlsDelayTime, boolean *rty_SO_b_MotorA, boolean
  *rty_SO_b_MotorB, uint8 *rty_SO_e_MotorMode, boolean *rty_SO_b_Error, uint8
  *rty_SO_e_MotorPwm, DW_FLDoorRlsDriver_REL_T *localDW)
{
  if (localDW->is_Normal == REL_IN_ElectricDoor) {
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
            localDW->is_Step2_Open = REL_IN_Idle_c;
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
            sint32 tmp;
            localDW->is_Release = REL_IN_Checking;
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

       case REL_IN_Reset:
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

         case REL_IN_Idle_c:
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
  } else if (localDW->is_MainProgress_k == REL_IN_Idle) {
    if ((localDW->SO_b_DoorRlsReq_prev != localDW->SO_b_DoorRlsReq_start) &&
        localDW->SO_b_DoorRlsReq_start) {
      localDW->is_MainProgress_k = REL_IN_Release;
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
        if ((localDW->temporalCounter_i1 >= 5) && rtu_SI_b_DoorAjar) {
          localDW->is_Release_i = REL_IN_Step2_Open;
          localDW->is_Step2_Open_e = REL_IN_Idle;
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
        if (localDW->temporalCounter_i1 >= 30) {
          sint32 tmp;
          localDW->is_Release_i = REL_IN_Checking;
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

     case REL_IN_Reset:
      if (localDW->temporalCounter_i1 >= 30) {
        localDW->is_Release_i = REL_IN_NO_ACTIVE_CHILD;
        localDW->is_MainProgress_k = REL_IN_Idle;
        *rty_SO_b_MotorA = false;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorMode = 0U;
        *rty_SO_e_MotorPwm = 0U;
      }
      break;

     default:
      /* case IN_Step2_Open: */
      if (localDW->is_Step2_Open_e == REL_IN_Idle) {
        if ((localDW->temporalCounter_i1 < 270) && rtu_SI_b_DoorAjar) {
          localDW->is_Step2_Open_e = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_Release_i = REL_IN_Reset;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorMode = 2U;
          *rty_SO_e_MotorPwm = 70U;
        } else if (localDW->temporalCounter_i1 >= 300) {
          localDW->is_Step2_Open_e = REL_IN_LastCheck_m;
        }
      } else {
        /* case IN_LastCheck: */
        localDW->is_Step2_Open_e = REL_IN_NO_ACTIVE_CHILD;
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
void REL_FLDoorRlsDriver_Init(boolean *rty_SO_b_MotorA, boolean *rty_SO_b_MotorB,
  uint8 *rty_SO_e_MotorMode, boolean *rty_SO_b_Error, uint8 *rty_SO_e_MotorPwm)
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
void REL_FLDoorRlsDriver(boolean rtu_SO_b_DoorRlsReq, Boolean rtu_SI_b_DoorAjar,
  Boolean rtu_SI_b_CinchHome, Boolean rtu_SI_b_ElecDoorCfg, uint8
  rtu_SI_e_DoorRlsDelayTime, boolean *rty_SO_b_MotorA, boolean *rty_SO_b_MotorB,
  uint8 *rty_SO_e_MotorMode, boolean *rty_SO_b_Error, uint8 *rty_SO_e_MotorPwm,
  DW_FLDoorRlsDriver_REL_T *localDW)
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

    /* case IN_PowerOn: */
  } else if (localDW->temporalCounter_i1 >= 30) {
    *rty_SO_b_MotorA = false;
    *rty_SO_b_MotorB = false;
    *rty_SO_e_MotorMode = 0U;
    *rty_SO_e_MotorPwm = 100U;
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
      localDW->is_MainProgress_k = REL_IN_Idle;
      *rty_SO_b_MotorA = false;
      *rty_SO_b_MotorB = false;
      *rty_SO_e_MotorMode = 0U;
      *rty_SO_e_MotorPwm = 0U;
    }
  }

  /* End of Chart: '<S3>/FLDoorRlsDriver' */
}

/* Function for Chart: '<S3>/RLDoorRlsReq' */
static void REL_DoorInBtn(UInt8 rtu_SI_e_EspVehSpd, Boolean
  rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8 rtu_SI_e_DoorLockSts,
  uint8 rtu_SI_e_DoorRatSts, Boolean rtu_SI_b_ChildLckSts, boolean
  *rty_SO_b_DoorRlsReq, boolean *rty_SO_b_UnlockReq, uint8
  *rty_SO_e_DoorRlsDelayTime, DW_RLDoorRlsReq_REL_T *localDW)
{
  switch (localDW->is_SwValid) {
   case REL_IN_Idle_a:
    if ((localDW->SI_b_DoorInBtnSts_prev != localDW->SI_b_DoorInBtnSts_start) &&
        localDW->SI_b_DoorInBtnSts_start && (!rtu_SI_b_ChildLckSts)) {
      localDW->is_SwValid = REL_IN_Once;
      localDW->temporalCounter_i2 = 0U;
    }
    break;

   case REL_IN_Once:
    if ((localDW->SI_b_DoorInBtnSts_prev != localDW->SI_b_DoorInBtnSts_start) &&
        localDW->SI_b_DoorInBtnSts_start && (!rtu_SI_b_ChildLckSts)) {
      localDW->is_SwValid = REL_IN_Twice;
      localDW->temporalCounter_i2 = 0U;
      localDW->SL_b_DoorInBtnValid = true;
    } else if ((localDW->temporalCounter_i2 >= 200) || rtu_SI_b_ChildLckSts) {
      localDW->is_SwValid = REL_IN_Idle_a;
      localDW->SL_b_DoorInBtnValid = false;
    }
    break;

   default:
    /* case IN_Twice: */
    if (localDW->temporalCounter_i2 >= 3) {
      localDW->is_SwValid = REL_IN_Idle_a;
      localDW->SL_b_DoorInBtnValid = false;
    }
    break;
  }

  if (localDW->is_RlsReq_l == REL_IN_Initial_k) {
    if ((((rtu_SI_e_EspVehSpd <= 0) && (!rtu_SI_b_EspVehSpdVld)) ||
         (rtu_SI_e_VcuGearPosn == 1)) && ((localDW->SL_b_DoorInBtnValid_prev !=
          localDW->SL_b_DoorInBtnValid_start) &&
         localDW->SL_b_DoorInBtnValid_start)) {
      localDW->is_RlsReq_l = REL_IN_Trigger;
      switch (rtu_SI_e_DoorLockSts) {
       case 0:
        localDW->is_Trigger_l = REL_IN_DoorLock;
        localDW->temporalCounter_i3 = 0U;
        *rty_SO_b_UnlockReq = true;
        break;

       case 1:
        localDW->is_Trigger_l = REL_IN_DoorUnlock;
        break;

       default:
        localDW->is_Trigger_l = REL_IN_Error_l;
        break;
      }
    }

    /* case IN_Trigger: */
  } else if (((rtu_SI_e_EspVehSpd >= 1) && (!rtu_SI_b_EspVehSpdVld) &&
              (rtu_SI_e_VcuGearPosn != 1)) || ((rtu_SI_e_DoorLockSts == 1) &&
              (rtu_SI_e_DoorRatSts == 3))) {
    localDW->is_Trigger_l = REL_IN_NO_ACTIVE_CHILD_a;
    localDW->is_RlsReq_l = REL_IN_Initial_k;
    *rty_SO_b_DoorRlsReq = false;
    *rty_SO_b_UnlockReq = false;
  } else {
    switch (localDW->is_Trigger_l) {
     case REL_IN_DoorLock:
      if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
        localDW->is_Trigger_l = REL_IN_Release_lv;
        localDW->temporalCounter_i3 = 0U;
        *rty_SO_b_DoorRlsReq = true;
        *rty_SO_e_DoorRlsDelayTime = 20U;
      } else if (localDW->temporalCounter_i3 >= 100) {
        localDW->is_Trigger_l = REL_IN_NO_ACTIVE_CHILD_a;
        localDW->is_RlsReq_l = REL_IN_Initial_k;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
      }
      break;

     case REL_IN_DoorUnlock:
      if (rtu_SI_e_DoorRatSts != 3) {
        localDW->is_Trigger_l = REL_IN_Release_lv;
        localDW->temporalCounter_i3 = 0U;
        *rty_SO_b_DoorRlsReq = true;
        *rty_SO_e_DoorRlsDelayTime = 20U;
      }
      break;

     case REL_IN_Error_l:
      localDW->is_Trigger_l = REL_IN_NO_ACTIVE_CHILD_a;
      localDW->is_RlsReq_l = REL_IN_Initial_k;
      *rty_SO_b_DoorRlsReq = false;
      *rty_SO_b_UnlockReq = false;
      break;

     default:
      /* case IN_Release: */
      if (localDW->temporalCounter_i3 >= 5) {
        localDW->is_Trigger_l = REL_IN_NO_ACTIVE_CHILD_a;
        localDW->is_RlsReq_l = REL_IN_Initial_k;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/RLDoorRlsReq' */
static void REL_DoorHand(UInt8 rtu_SI_e_EspVehSpd, Boolean rtu_SI_b_EspVehSpdVld,
  UInt8 rtu_SI_e_VcuGearPosn, UInt8 rtu_SI_e_DoorLockSts, uint8
  rtu_SI_e_DoorRatSts, boolean *rty_SO_b_DoorRlsReq, boolean *rty_SO_b_UnlockReq,
  uint8 *rty_SO_e_DoorRlsDelayTime, DW_RLDoorRlsReq_REL_T *localDW)
{
  if (localDW->is_RlsReq_o == REL_IN_Initial_k) {
    if ((((rtu_SI_e_EspVehSpd <= 0) && (!rtu_SI_b_EspVehSpdVld)) ||
         (rtu_SI_e_VcuGearPosn == 1)) && ((localDW->SL_b_DoorHndBtnValid_prev !=
          localDW->SL_b_DoorHndBtnValid_start) &&
         localDW->SL_b_DoorHndBtnValid_start)) {
      localDW->is_RlsReq_o = REL_IN_Trigger;
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
        localDW->is_Trigger_b = REL_IN_Error_l;
        break;
      }
    }

    /* case IN_Trigger: */
  } else if (((rtu_SI_e_EspVehSpd >= 1) && (!rtu_SI_b_EspVehSpdVld) &&
              (rtu_SI_e_VcuGearPosn != 1)) || ((rtu_SI_e_DoorLockSts == 1) &&
              (rtu_SI_e_DoorRatSts == 3))) {
    localDW->is_Trigger_b = REL_IN_NO_ACTIVE_CHILD_a;
    localDW->is_RlsReq_o = REL_IN_Initial_k;
    *rty_SO_b_DoorRlsReq = false;
    *rty_SO_b_UnlockReq = false;
  } else {
    switch (localDW->is_Trigger_b) {
     case REL_IN_DoorLock:
      if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
        localDW->is_Trigger_b = REL_IN_RELEASE;
        localDW->temporalCounter_i6 = 0U;
        *rty_SO_b_DoorRlsReq = true;
        *rty_SO_e_DoorRlsDelayTime = 0U;
      } else if (localDW->temporalCounter_i6 >= 100) {
        localDW->is_Trigger_b = REL_IN_NO_ACTIVE_CHILD_a;
        localDW->is_RlsReq_o = REL_IN_Initial_k;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
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

     case REL_IN_Error_l:
      break;

     default:
      /* case IN_RELEASE: */
      if (localDW->temporalCounter_i6 >= 5) {
        localDW->is_Trigger_b = REL_IN_NO_ACTIVE_CHILD_a;
        localDW->is_RlsReq_o = REL_IN_Initial_k;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
      }
      break;
    }
  }

  switch (localDW->is_SwValid_g) {
   case REL_IN_Initial_k:
    if ((localDW->SI_b_DoorHndBtnSts_prev != localDW->SI_b_DoorHndBtnSts_start) &&
        localDW->SI_b_DoorHndBtnSts_start) {
      localDW->is_SwValid_g = REL_IN_Press;
      localDW->temporalCounter_i5 = 0U;
    }
    break;

   case REL_IN_Press:
    if ((localDW->SI_b_DoorHndBtnSts_prev != localDW->SI_b_DoorHndBtnSts_start) &&
        (!localDW->SI_b_DoorHndBtnSts_start)) {
      localDW->is_SwValid_g = REL_IN_Release_lvk;
      localDW->temporalCounter_i5 = 0U;
      localDW->SL_b_DoorHndBtnValid = true;
    } else if (localDW->temporalCounter_i5 >= 100) {
      localDW->is_SwValid_g = REL_IN_Initial_k;
      localDW->SL_b_DoorHndBtnValid = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (localDW->temporalCounter_i5 >= 3) {
      localDW->is_SwValid_g = REL_IN_Initial_k;
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
void REL_RLDoorRlsReq_Init(boolean *rty_SO_b_DoorRlsReq, boolean
  *rty_SO_b_UnlockReq, uint8 *rty_SO_e_DoorRlsDelayTime)
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
void REL_RLDoorRlsReq(boolean rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd, Boolean
                      rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8
                      rtu_SI_e_DoorLockSts, uint8 rtu_SI_e_DoorRatSts, boolean
                      rtu_SI_b_DoorInBtnSts, boolean rtu_SI_b_DoorHndPullSts,
                      boolean rtu_SI_b_DoorHndBtnSts, UInt8
                      rtu_SI_e_DoorHandPosSts, Boolean
                      rtu_SI_b_CentSingleDoorSwSts, Boolean
                      rtu_SI_b_CentAllDoorSwSts, Boolean rtu_SI_b_ChildLckSts,
                      boolean rtu_SI_b_DoorLockSetSts, boolean
                      rtu_SI_b_DoorLockOpenReq, boolean *rty_SO_b_DoorRlsReq,
                      boolean *rty_SO_b_UnlockReq, uint8
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
  localDW->SL_b_CentSingleDoorSwValid_prev =
    localDW->SL_b_CentSingleDoorSwValid_star;
  localDW->SL_b_CentSingleDoorSwValid_star = localDW->SL_b_CentSingleDoorSwValid;
  localDW->SL_b_CentAllDoorSwValid_prev = localDW->SL_b_CentAllDoorSwValid_start;
  localDW->SL_b_CentAllDoorSwValid_start = localDW->SL_b_CentAllDoorSwValid;

  /* Chart: '<S3>/RLDoorRlsReq' */
  if (localDW->is_active_c5_DoorRlsReq == 0U) {
    localDW->SI_b_DoorLockOpenReq_prev = rtu_SI_b_DoorLockOpenReq;
    localDW->SI_b_DoorInBtnSts_prev = rtu_SI_b_DoorInBtnSts;
    localDW->SI_b_DoorHndBtnSts_prev = rtu_SI_b_DoorHndBtnSts;
    localDW->is_active_c5_DoorRlsReq = 1U;
    localDW->is_SwValid = REL_IN_Idle_a;
    localDW->SL_b_DoorInBtnValid = false;
    localDW->is_RlsReq_l = REL_IN_Initial_k;
    localDW->is_DoorCentral = REL_IN_Initial_k;
    localDW->SL_b_CentSingleDoorSwValid = rtu_SI_b_CentSingleDoorSwSts;
    localDW->SL_b_CentAllDoorSwValid = rtu_SI_b_CentAllDoorSwSts;
    localDW->SL_b_DoorHndPullValid = rtu_SI_b_DoorHndPullSts;
    localDW->is_RlsReq_b = REL_IN_Initial_k;
    localDW->is_RlsReq_o = REL_IN_Initial_k;
    *rty_SO_b_UnlockReq = false;
    localDW->is_SwValid_g = REL_IN_Initial_k;
    localDW->SL_b_DoorHndBtnValid = false;
    localDW->is_RlsReq = REL_IN_Idle_a;
    *rty_SO_b_DoorRlsReq = false;
  } else {
    REL_DoorInBtn(rtu_SI_e_EspVehSpd, rtu_SI_b_EspVehSpdVld,
                  rtu_SI_e_VcuGearPosn, rtu_SI_e_DoorLockSts,
                  rtu_SI_e_DoorRatSts, rtu_SI_b_ChildLckSts, rty_SO_b_DoorRlsReq,
                  rty_SO_b_UnlockReq, rty_SO_e_DoorRlsDelayTime, localDW);
    if (localDW->is_DoorCentral == REL_IN_Initial_k) {
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
          localDW->is_Trigger_mi = REL_IN_DoorLock;
          localDW->temporalCounter_i7 = 0U;
          *rty_SO_b_UnlockReq = true;
          break;

         case 1:
          localDW->is_Trigger_mi = REL_IN_DoorUnlock;
          break;

         default:
          localDW->is_Trigger_mi = REL_IN_Error_l;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (rtu_SI_b_OFF || ((rtu_SI_e_EspVehSpd >= 1) &&
                (!rtu_SI_b_EspVehSpdVld) && (rtu_SI_e_VcuGearPosn != 1)) ||
               ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts == 3))) {
      localDW->is_Trigger_mi = REL_IN_NO_ACTIVE_CHILD_a;
      localDW->is_DoorCentral = REL_IN_Initial_k;
      *rty_SO_b_DoorRlsReq = false;
      *rty_SO_b_UnlockReq = false;
    } else {
      switch (localDW->is_Trigger_mi) {
       case REL_IN_DoorLock:
        if (localDW->temporalCounter_i7 >= 100) {
          localDW->is_Trigger_mi = REL_IN_NO_ACTIVE_CHILD_a;
          localDW->is_DoorCentral = REL_IN_Initial_k;
          *rty_SO_b_DoorRlsReq = false;
          *rty_SO_b_UnlockReq = false;
        } else if ((rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorRatSts != 3)) {
          localDW->is_Trigger_mi = REL_IN_RELEASE;
          localDW->temporalCounter_i7 = 0U;
          *rty_SO_b_DoorRlsReq = true;
          *rty_SO_e_DoorRlsDelayTime = 0U;
        }
        break;

       case REL_IN_DoorUnlock:
        if (rtu_SI_e_DoorRatSts != 3) {
          localDW->is_Trigger_mi = REL_IN_RELEASE;
          localDW->temporalCounter_i7 = 0U;
          *rty_SO_b_DoorRlsReq = true;
          *rty_SO_e_DoorRlsDelayTime = 0U;
        }
        break;

       case REL_IN_Error_l:
        localDW->is_Trigger_mi = REL_IN_NO_ACTIVE_CHILD_a;
        localDW->is_DoorCentral = REL_IN_Initial_k;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
        break;

       default:
        /* case IN_RELEASE: */
        if (localDW->temporalCounter_i7 >= 5) {
          localDW->is_Trigger_mi = REL_IN_NO_ACTIVE_CHILD_a;
          localDW->is_DoorCentral = REL_IN_Initial_k;
          *rty_SO_b_DoorRlsReq = false;
          *rty_SO_b_UnlockReq = false;
        }
        break;
      }
    }

    localDW->SL_b_CentSingleDoorSwValid = rtu_SI_b_CentSingleDoorSwSts;
    localDW->SL_b_CentAllDoorSwValid = rtu_SI_b_CentAllDoorSwSts;
    localDW->SL_b_DoorHndPullValid = rtu_SI_b_DoorHndPullSts;
    if (localDW->is_RlsReq_b == REL_IN_Initial_k) {
      if ((!rtu_SI_b_OFF) && (((rtu_SI_e_EspVehSpd <= 0) &&
            (!rtu_SI_b_EspVehSpdVld)) || (rtu_SI_e_VcuGearPosn == 1)) &&
          (rtu_SI_e_DoorLockSts == 1) && (rtu_SI_e_DoorHandPosSts == 1) &&
          ((localDW->SL_b_DoorHndPullValid_prev !=
            localDW->SL_b_DoorHndPullValid_start) &&
           localDW->SL_b_DoorHndPullValid_start)) {
        localDW->is_RlsReq_b = REL_IN_Trigger;
        localDW->is_Trigger_m = REL_IN_Wait;
      }

      /* case IN_Trigger: */
    } else if (rtu_SI_b_OFF || ((rtu_SI_e_EspVehSpd >= 1) &&
                (!rtu_SI_b_EspVehSpdVld) && (rtu_SI_e_VcuGearPosn != 1)) ||
               (rtu_SI_e_DoorLockSts != 1) || (rtu_SI_e_DoorHandPosSts != 1) ||
               (rtu_SI_e_DoorRatSts == 3)) {
      localDW->is_Trigger_m = REL_IN_NO_ACTIVE_CHILD_a;
      localDW->is_RlsReq_b = REL_IN_Initial_k;
      *rty_SO_b_DoorRlsReq = false;
      *rty_SO_b_UnlockReq = false;
    } else if (localDW->is_Trigger_m == REL_IN_Release_l) {
      if (localDW->temporalCounter_i4 >= 5) {
        localDW->is_Trigger_m = REL_IN_NO_ACTIVE_CHILD_a;
        localDW->is_RlsReq_b = REL_IN_Initial_k;
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_b_UnlockReq = false;
      }

      /* case IN_Wait: */
    } else if (rtu_SI_e_DoorRatSts != 3) {
      localDW->is_Trigger_m = REL_IN_Release_l;
      localDW->temporalCounter_i4 = 0U;
      *rty_SO_b_DoorRlsReq = true;
      *rty_SO_e_DoorRlsDelayTime = 4U;
    }

    REL_DoorHand(rtu_SI_e_EspVehSpd, rtu_SI_b_EspVehSpdVld, rtu_SI_e_VcuGearPosn,
                 rtu_SI_e_DoorLockSts, rtu_SI_e_DoorRatSts, rty_SO_b_DoorRlsReq,
                 rty_SO_b_UnlockReq, rty_SO_e_DoorRlsDelayTime, localDW);
    if (localDW->is_RlsReq == REL_IN_Idle_a) {
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
      localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_a;
      localDW->is_RlsReq = REL_IN_Idle_a;
      *rty_SO_b_DoorRlsReq = false;
    } else if (localDW->is_Trigger == REL_IN_Release_l) {
      if (localDW->temporalCounter_i1 >= 5) {
        localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_a;
        localDW->is_RlsReq = REL_IN_Idle_a;
        *rty_SO_b_DoorRlsReq = false;
      }

      /* case IN_WAIT: */
    } else if (rtu_SI_e_DoorRatSts != 3) {
      localDW->is_Trigger = REL_IN_Release_l;
      localDW->temporalCounter_i1 = 0U;
      *rty_SO_b_DoorRlsReq = true;
      *rty_SO_e_DoorRlsDelayTime = 0U;
    }
  }

  /* End of Chart: '<S3>/RLDoorRlsReq' */
}

/* Function for Chart: '<S3>/DoorSwSts' */
static void REL_enter_atomic_NoCrash(boolean *SL_b_FLDoorInBtnSts, boolean
  *SL_b_FRDoorInBtnSts, boolean *SL_b_FLDoorHndPullSts)
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
    (&REL_B.SL_b_FLDoorHndBtnSts);

  /* Inport: '<Root>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg' */
  (void)Rte_Read_VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg
    (&REL_B.SL_b_RRDoorHndPullSts);

  /* Inport: '<Root>/VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg' */
  (void)Rte_Read_VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg
    (&REL_B.SL_b_RLDoorHndPullSts);

  /* Inport: '<Root>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg' */
  (void)Rte_Read_VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg
    (&REL_B.SL_b_FRDoorHndPullSts);

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
    (SL_b_FRDoorInBtnSts);

  /* Inport: '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg' */
  (void)Rte_Read_VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg
    (SL_b_FLDoorInBtnSts);
}

/* Function for Chart: '<S3>/FLDoorRlsReq' */
static void REL_DoorInBtn_i(void)
{
  UInt8 tmpRead;
  switch (REL_DW.is_SwValid_a) {
   case REL_IN_Idle_n:
    if ((REL_DW.SI_b_DoorInBtnSts_prev_a != REL_DW.SI_b_DoorInBtnSts_start_l) &&
        REL_DW.SI_b_DoorInBtnSts_start_l) {
      REL_DW.is_SwValid_a = REL_IN_Once_a;
      REL_DW.temporalCounter_i2_h = 0U;
    }
    break;

   case REL_IN_Once_a:
    if ((REL_DW.SI_b_DoorInBtnSts_prev_a != REL_DW.SI_b_DoorInBtnSts_start_l) &&
        REL_DW.SI_b_DoorInBtnSts_start_l) {
      REL_DW.is_SwValid_a = REL_IN_Twice_m;
      REL_DW.temporalCounter_i2_h = 0U;
      REL_DW.SL_b_DoorInBtnValid_f = true;
    } else if (REL_DW.temporalCounter_i2_h >= 200) {
      REL_DW.is_SwValid_a = REL_IN_Idle_n;
      REL_DW.SL_b_DoorInBtnValid_f = false;
    }
    break;

   default:
    /* case IN_Twice: */
    if (REL_DW.temporalCounter_i2_h >= 3) {
      REL_DW.is_SwValid_a = REL_IN_Idle_n;
      REL_DW.SL_b_DoorInBtnValid_f = false;
    }
    break;
  }

  /* Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig' */
  (void)
    Rte_Read_VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig
    (&tmpRead);
  if (REL_DW.is_RlsReq_n3 == REL_IN_Initial_b) {
    if ((((REL_B.TmpSignalConversionAtVeOUT_SP_E <= 0) &&
          (!REL_B.TmpSignalConversionAtVbINP_CAN_)) ||
         (REL_B.TmpSignalConversionAtVeINP_CAN_ == 1)) &&
        ((REL_DW.SL_b_DoorInBtnValid_prev_j !=
          REL_DW.SL_b_DoorInBtnValid_start_d) &&
         REL_DW.SL_b_DoorInBtnValid_start_d)) {
      REL_DW.is_RlsReq_n3 = REL_IN_Trigger_h;
      switch (tmpRead) {
       case 0:
        REL_DW.is_Trigger_gs = REL_IN_DoorLock_b;
        REL_DW.temporalCounter_i3_i = 0U;
        REL_B.SO_b_UnlockReq_m = true;
        break;

       case 1:
        REL_DW.is_Trigger_gs = REL_IN_DoorUnlock_h;
        break;

       default:
        REL_DW.is_Trigger_gs = REL_IN_Error_f;
        break;
      }
    }

    /* case IN_Trigger: */
  } else if (((REL_B.TmpSignalConversionAtVeOUT_SP_E >= 1) &&
              (!REL_B.TmpSignalConversionAtVbINP_CAN_) &&
              (REL_B.TmpSignalConversionAtVeINP_CAN_ != 1)) || ((tmpRead == 1) &&
              (REL_B.SO_e_DoorRatSts_dw == 3))) {
    REL_DW.is_Trigger_gs = REL_IN_NO_ACTIVE_CHILD_f;
    REL_DW.is_RlsReq_n3 = REL_IN_Initial_b;
    REL_B.SO_b_DoorRlsReq_fz = false;
    REL_B.SO_b_UnlockReq_m = false;
  } else {
    switch (REL_DW.is_Trigger_gs) {
     case REL_IN_DoorLock_b:
      if ((tmpRead == 1) && (REL_B.SO_e_DoorRatSts_dw != 3)) {
        REL_DW.is_Trigger_gs = REL_IN_Release_ht;
        REL_DW.temporalCounter_i3_i = 0U;
        REL_B.SO_b_DoorRlsReq_fz = true;
        REL_B.SO_e_DoorRlsDelayTime_g = 20U;
      } else if (REL_DW.temporalCounter_i3_i >= 100) {
        REL_DW.is_Trigger_gs = REL_IN_NO_ACTIVE_CHILD_f;
        REL_DW.is_RlsReq_n3 = REL_IN_Initial_b;
        REL_B.SO_b_DoorRlsReq_fz = false;
        REL_B.SO_b_UnlockReq_m = false;
      }
      break;

     case REL_IN_DoorUnlock_h:
      if (REL_B.SO_e_DoorRatSts_dw != 3) {
        REL_DW.is_Trigger_gs = REL_IN_Release_ht;
        REL_DW.temporalCounter_i3_i = 0U;
        REL_B.SO_b_DoorRlsReq_fz = true;
        REL_B.SO_e_DoorRlsDelayTime_g = 20U;
      }
      break;

     case REL_IN_Error_f:
      REL_DW.is_Trigger_gs = REL_IN_NO_ACTIVE_CHILD_f;
      REL_DW.is_RlsReq_n3 = REL_IN_Initial_b;
      REL_B.SO_b_DoorRlsReq_fz = false;
      REL_B.SO_b_UnlockReq_m = false;
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i3_i >= 5) {
        REL_DW.is_Trigger_gs = REL_IN_NO_ACTIVE_CHILD_f;
        REL_DW.is_RlsReq_n3 = REL_IN_Initial_b;
        REL_B.SO_b_DoorRlsReq_fz = false;
        REL_B.SO_b_UnlockReq_m = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/FLDoorRlsReq' */
static void REL_DoorHand_c(void)
{
  UInt8 tmpRead;

  /* Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig' */
  (void)
    Rte_Read_VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig
    (&tmpRead);
  if (REL_DW.is_RlsReq_cd == REL_IN_Initial_b) {
    if ((((REL_B.TmpSignalConversionAtVeOUT_SP_E <= 0) &&
          (!REL_B.TmpSignalConversionAtVbINP_CAN_)) ||
         (REL_B.TmpSignalConversionAtVeINP_CAN_ == 1)) &&
        ((REL_DW.SL_b_DoorHndBtnValid_prev_e !=
          REL_DW.SL_b_DoorHndBtnValid_start_l) &&
         REL_DW.SL_b_DoorHndBtnValid_start_l)) {
      REL_DW.is_RlsReq_cd = REL_IN_Trigger_h;
      switch (tmpRead) {
       case 0:
        REL_DW.is_Trigger_j = REL_IN_DoorLock_b;
        REL_DW.temporalCounter_i6_f = 0U;
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
  } else if (((REL_B.TmpSignalConversionAtVeOUT_SP_E >= 1) &&
              (!REL_B.TmpSignalConversionAtVbINP_CAN_) &&
              (REL_B.TmpSignalConversionAtVeINP_CAN_ != 1)) || ((tmpRead == 1) &&
              (REL_B.SO_e_DoorRatSts_dw == 3))) {
    REL_DW.is_Trigger_j = REL_IN_NO_ACTIVE_CHILD_f;
    REL_DW.is_RlsReq_cd = REL_IN_Initial_b;
    REL_B.SO_b_DoorRlsReq_fz = false;
    REL_B.SO_b_UnlockReq_m = false;
  } else {
    switch (REL_DW.is_Trigger_j) {
     case REL_IN_DoorLock_b:
      if ((tmpRead == 1) && (REL_B.SO_e_DoorRatSts_dw != 3)) {
        REL_DW.is_Trigger_j = REL_IN_RELEASE_j;
        REL_DW.temporalCounter_i6_f = 0U;
        REL_B.SO_b_DoorRlsReq_fz = true;
        REL_B.SO_e_DoorRlsDelayTime_g = 0U;
      } else if (REL_DW.temporalCounter_i6_f >= 100) {
        REL_DW.is_Trigger_j = REL_IN_NO_ACTIVE_CHILD_f;
        REL_DW.is_RlsReq_cd = REL_IN_Initial_b;
        REL_B.SO_b_DoorRlsReq_fz = false;
        REL_B.SO_b_UnlockReq_m = false;
      }
      break;

     case REL_IN_DoorUnlock_h:
      if (REL_B.SO_e_DoorRatSts_dw != 3) {
        REL_DW.is_Trigger_j = REL_IN_RELEASE_j;
        REL_DW.temporalCounter_i6_f = 0U;
        REL_B.SO_b_DoorRlsReq_fz = true;
        REL_B.SO_e_DoorRlsDelayTime_g = 0U;
      }
      break;

     case REL_IN_Error_f:
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i6_f >= 5) {
        REL_DW.is_Trigger_j = REL_IN_NO_ACTIVE_CHILD_f;
        REL_DW.is_RlsReq_cd = REL_IN_Initial_b;
        REL_B.SO_b_DoorRlsReq_fz = false;
        REL_B.SO_b_UnlockReq_m = false;
      }
      break;
    }
  }

  switch (REL_DW.is_SwValid_g) {
   case REL_IN_Initial_b:
    if ((REL_DW.SI_b_DoorHndBtnSts_prev_a != REL_DW.SI_b_DoorHndBtnSts_start_h) &&
        REL_DW.SI_b_DoorHndBtnSts_start_h) {
      REL_DW.is_SwValid_g = REL_IN_Press_f;
      REL_DW.temporalCounter_i5_a = 0U;
    }
    break;

   case REL_IN_Press_f:
    if ((REL_DW.SI_b_DoorHndBtnSts_prev_a != REL_DW.SI_b_DoorHndBtnSts_start_h) &&
        (!REL_DW.SI_b_DoorHndBtnSts_start_h)) {
      REL_DW.is_SwValid_g = REL_IN_Release_htd;
      REL_DW.temporalCounter_i5_a = 0U;
      REL_DW.SL_b_DoorHndBtnValid_g = true;
    } else if (REL_DW.temporalCounter_i5_a >= 100) {
      REL_DW.is_SwValid_g = REL_IN_Initial_b;
      REL_DW.SL_b_DoorHndBtnValid_g = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (REL_DW.temporalCounter_i5_a >= 3) {
      REL_DW.is_SwValid_g = REL_IN_Initial_b;
      REL_DW.SL_b_DoorHndBtnValid_g = false;
    }
    break;
  }
}

/* Function for Chart: '<S3>/FRDoorRlsReq' */
static void REL_DoorInBtn_i5(void)
{
  switch (REL_DW.is_SwValid) {
   case REL_IN_Idle_n:
    if ((REL_DW.SI_b_DoorInBtnSts_prev != REL_DW.SI_b_DoorInBtnSts_start) &&
        REL_DW.SI_b_DoorInBtnSts_start) {
      REL_DW.is_SwValid = REL_IN_Once_a;
      REL_DW.temporalCounter_i2 = 0U;
    }
    break;

   case REL_IN_Once_a:
    if ((REL_DW.SI_b_DoorInBtnSts_prev != REL_DW.SI_b_DoorInBtnSts_start) &&
        REL_DW.SI_b_DoorInBtnSts_start) {
      REL_DW.is_SwValid = REL_IN_Twice_m;
      REL_DW.temporalCounter_i2 = 0U;
      REL_DW.SL_b_DoorInBtnValid = true;
    } else if (REL_DW.temporalCounter_i2 >= 200) {
      REL_DW.is_SwValid = REL_IN_Idle_n;
      REL_DW.SL_b_DoorInBtnValid = false;
    }
    break;

   default:
    /* case IN_Twice: */
    if (REL_DW.temporalCounter_i2 >= 3) {
      REL_DW.is_SwValid = REL_IN_Idle_n;
      REL_DW.SL_b_DoorInBtnValid = false;
    }
    break;
  }

  if (REL_DW.is_RlsReq_c == REL_IN_Initial_b) {
    if ((((REL_B.TmpSignalConversionAtVeOUT_SP_E <= 0) &&
          (!REL_B.TmpSignalConversionAtVbINP_CAN_)) ||
         (REL_B.TmpSignalConversionAtVeINP_CAN_ == 1)) &&
        ((REL_DW.SL_b_DoorInBtnValid_prev != REL_DW.SL_b_DoorInBtnValid_start) &&
         REL_DW.SL_b_DoorInBtnValid_start)) {
      REL_DW.is_RlsReq_c = REL_IN_Trigger_h;
      switch (REL_B.TmpSignalConversionAtVeOUT_DLK_) {
       case 0:
        REL_DW.is_Trigger_i = REL_IN_DoorLock_b;
        REL_DW.temporalCounter_i3 = 0U;
        REL_B.SO_b_UnlockReq_b = true;
        break;

       case 1:
        REL_DW.is_Trigger_i = REL_IN_DoorUnlock_h;
        break;

       default:
        REL_DW.is_Trigger_i = REL_IN_Error_f;
        break;
      }
    }

    /* case IN_Trigger: */
  } else if (((REL_B.TmpSignalConversionAtVeOUT_SP_E >= 1) &&
              (!REL_B.TmpSignalConversionAtVbINP_CAN_) &&
              (REL_B.TmpSignalConversionAtVeINP_CAN_ != 1)) ||
             ((REL_B.TmpSignalConversionAtVeOUT_DLK_ == 1) &&
              (REL_B.SO_e_DoorRatSts_d == 3))) {
    REL_DW.is_Trigger_i = REL_IN_NO_ACTIVE_CHILD_f;
    REL_DW.is_RlsReq_c = REL_IN_Initial_b;
    REL_B.SO_b_DoorRlsReq_p = false;
    REL_B.SO_b_UnlockReq_b = false;
  } else {
    switch (REL_DW.is_Trigger_i) {
     case REL_IN_DoorLock_b:
      if ((REL_B.TmpSignalConversionAtVeOUT_DLK_ == 1) &&
          (REL_B.SO_e_DoorRatSts_d != 3)) {
        REL_DW.is_Trigger_i = REL_IN_Release_ht;
        REL_DW.temporalCounter_i3 = 0U;
        REL_B.SO_b_DoorRlsReq_p = true;
        REL_B.SO_e_DoorRlsDelayTime_e = 20U;
      } else if (REL_DW.temporalCounter_i3 >= 100) {
        REL_DW.is_Trigger_i = REL_IN_NO_ACTIVE_CHILD_f;
        REL_DW.is_RlsReq_c = REL_IN_Initial_b;
        REL_B.SO_b_DoorRlsReq_p = false;
        REL_B.SO_b_UnlockReq_b = false;
      }
      break;

     case REL_IN_DoorUnlock_h:
      if (REL_B.SO_e_DoorRatSts_d != 3) {
        REL_DW.is_Trigger_i = REL_IN_Release_ht;
        REL_DW.temporalCounter_i3 = 0U;
        REL_B.SO_b_DoorRlsReq_p = true;
        REL_B.SO_e_DoorRlsDelayTime_e = 20U;
      }
      break;

     case REL_IN_Error_f:
      REL_DW.is_Trigger_i = REL_IN_NO_ACTIVE_CHILD_f;
      REL_DW.is_RlsReq_c = REL_IN_Initial_b;
      REL_B.SO_b_DoorRlsReq_p = false;
      REL_B.SO_b_UnlockReq_b = false;
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i3 >= 5) {
        REL_DW.is_Trigger_i = REL_IN_NO_ACTIVE_CHILD_f;
        REL_DW.is_RlsReq_c = REL_IN_Initial_b;
        REL_B.SO_b_DoorRlsReq_p = false;
        REL_B.SO_b_UnlockReq_b = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/FRDoorRlsReq' */
static void REL_DoorHand_e(void)
{
  if (REL_DW.is_RlsReq_py == REL_IN_Initial_b) {
    if ((((REL_B.TmpSignalConversionAtVeOUT_SP_E <= 0) &&
          (!REL_B.TmpSignalConversionAtVbINP_CAN_)) ||
         (REL_B.TmpSignalConversionAtVeINP_CAN_ == 1)) &&
        ((REL_DW.SL_b_DoorHndBtnValid_prev != REL_DW.SL_b_DoorHndBtnValid_start)
         && REL_DW.SL_b_DoorHndBtnValid_start)) {
      REL_DW.is_RlsReq_py = REL_IN_Trigger_h;
      switch (REL_B.TmpSignalConversionAtVeOUT_DLK_) {
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
  } else if (((REL_B.TmpSignalConversionAtVeOUT_SP_E >= 1) &&
              (!REL_B.TmpSignalConversionAtVbINP_CAN_) &&
              (REL_B.TmpSignalConversionAtVeINP_CAN_ != 1)) ||
             ((REL_B.TmpSignalConversionAtVeOUT_DLK_ == 1) &&
              (REL_B.SO_e_DoorRatSts_d == 3))) {
    REL_DW.is_Trigger_g = REL_IN_NO_ACTIVE_CHILD_f;
    REL_DW.is_RlsReq_py = REL_IN_Initial_b;
    REL_B.SO_b_DoorRlsReq_p = false;
    REL_B.SO_b_UnlockReq_b = false;
  } else {
    switch (REL_DW.is_Trigger_g) {
     case REL_IN_DoorLock_b:
      if ((REL_B.TmpSignalConversionAtVeOUT_DLK_ == 1) &&
          (REL_B.SO_e_DoorRatSts_d != 3)) {
        REL_DW.is_Trigger_g = REL_IN_RELEASE_j;
        REL_DW.temporalCounter_i6 = 0U;
        REL_B.SO_b_DoorRlsReq_p = true;
        REL_B.SO_e_DoorRlsDelayTime_e = 0U;
      } else if (REL_DW.temporalCounter_i6 >= 100) {
        REL_DW.is_Trigger_g = REL_IN_NO_ACTIVE_CHILD_f;
        REL_DW.is_RlsReq_py = REL_IN_Initial_b;
        REL_B.SO_b_DoorRlsReq_p = false;
        REL_B.SO_b_UnlockReq_b = false;
      }
      break;

     case REL_IN_DoorUnlock_h:
      if (REL_B.SO_e_DoorRatSts_d != 3) {
        REL_DW.is_Trigger_g = REL_IN_RELEASE_j;
        REL_DW.temporalCounter_i6 = 0U;
        REL_B.SO_b_DoorRlsReq_p = true;
        REL_B.SO_e_DoorRlsDelayTime_e = 0U;
      }
      break;

     case REL_IN_Error_f:
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i6 >= 5) {
        REL_DW.is_Trigger_g = REL_IN_NO_ACTIVE_CHILD_f;
        REL_DW.is_RlsReq_py = REL_IN_Initial_b;
        REL_B.SO_b_DoorRlsReq_p = false;
        REL_B.SO_b_UnlockReq_b = false;
      }
      break;
    }
  }

  switch (REL_DW.is_SwValid_k) {
   case REL_IN_Initial_b:
    if ((REL_DW.SI_b_DoorHndBtnSts_prev != REL_DW.SI_b_DoorHndBtnSts_start) &&
        REL_DW.SI_b_DoorHndBtnSts_start) {
      REL_DW.is_SwValid_k = REL_IN_Press_f;
      REL_DW.temporalCounter_i5 = 0U;
    }
    break;

   case REL_IN_Press_f:
    if ((REL_DW.SI_b_DoorHndBtnSts_prev != REL_DW.SI_b_DoorHndBtnSts_start) && (
         !REL_DW.SI_b_DoorHndBtnSts_start)) {
      REL_DW.is_SwValid_k = REL_IN_Release_htd;
      REL_DW.temporalCounter_i5 = 0U;
      REL_DW.SL_b_DoorHndBtnValid = true;
    } else if (REL_DW.temporalCounter_i5 >= 100) {
      REL_DW.is_SwValid_k = REL_IN_Initial_b;
      REL_DW.SL_b_DoorHndBtnValid = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (REL_DW.temporalCounter_i5 >= 3) {
      REL_DW.is_SwValid_k = REL_IN_Initial_b;
      REL_DW.SL_b_DoorHndBtnValid = false;
    }
    break;
  }
}

/* Model step function for TID1 */
void REL_Step(void)                    /* Explicit Task: REL_Step */
{
  UInt8 tmpRead;
  UInt8 tmpRead_0;
  UInt8 tmpRead_1;
  UInt8 tmpRead_7;
  UInt8 tmpRead_8;
  uint8 SO_e_MotorPwm_a;
  uint8 SO_e_MotorPwm_h;
  uint8 SO_e_MotorPwm_m;
  Boolean tmpRead_2;
  Boolean tmpRead_3;
  Boolean tmpRead_4;
  Boolean tmpRead_5;
  Boolean tmpRead_6;
  Boolean tmpRead_9;
  boolean SL_b_FLDoorHndPullSts;
  boolean SL_b_FLDoorInBtnSts;
  boolean SL_b_FRDoorInBtnSts;
  boolean SO_b_Error;
  boolean SO_b_Error_h;
  boolean rtb_LogicalOperator;

  /* Inport: '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg' */
  (void)Rte_Read_VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg(&tmpRead_9);

  /* Inport: '<Root>/VeINP_CAN_CdcDrvrDoorLockSet_sig_VeINP_CAN_CdcDrvrDoorLockSet_sig' */
  (void)
    Rte_Read_VeINP_CAN_CdcDrvrDoorLockSet_sig_VeINP_CAN_CdcDrvrDoorLockSet_sig
    (&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* DataStoreWrite: '<S3>/Data Store Write' incorporates:
   *  Constant: '<S3>/Constant'
   */
  REL_DW.E15 = 3.0;

  /* Chart: '<S3>/DoorLockSetSts' */
  if (REL_DW.temporalCounter_i1_k < 127U) {
    REL_DW.temporalCounter_i1_k++;
  }

  REL_DW.SI_e_DoorLockSet_prev = REL_DW.SI_e_DoorLockSet_start;
  REL_DW.SI_e_DoorLockSet_start = tmpRead;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VeINP_EPRM_BdcDrvrDoorLockSetSts_sig_VeINP_EPRM_BdcDrvrDoorLockSetSts_sig' */
  (void)
    Rte_Read_VeINP_EPRM_BdcDrvrDoorLockSetSts_sig_VeINP_EPRM_BdcDrvrDoorLockSetSts_sig
    (&tmpRead_0);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/DoorLockSetSts' */
  if (REL_DW.is_active_c1_REL == 0U) {
    REL_DW.SI_e_DoorLockSet_prev = tmpRead;
    REL_DW.is_active_c1_REL = 1U;

    /*  ReadEEDoorLockSet  */
    REL_DW.is_c1_REL = REL_IN_Init;
    REL_DW.temporalCounter_i1_k = 0U;
    REL_B.SO_b_EEDoorLockSetSts = (tmpRead_0 != 0);
  } else if (REL_DW.is_c1_REL == REL_IN_DoorLockSet) {
    if (REL_DW.SI_e_DoorLockSet_prev != REL_DW.SI_e_DoorLockSet_start) {
      /*  DoorLockSet  */
      switch (tmpRead) {
       case 1:
        REL_B.SO_b_DoorLockSetSts = true;
        REL_B.SO_b_EEDoorLockSetSts = true;
        break;

       case 2:
        REL_B.SO_b_DoorLockSetSts = false;
        REL_B.SO_b_EEDoorLockSetSts = false;
        break;

       default:
        REL_B.SO_b_DoorLockSetSts = REL_B.SO_b_EEDoorLockSetSts;
        break;
      }
    }

    /* case IN_Init: */
  } else if (REL_DW.temporalCounter_i1_k >= 100) {
    REL_DW.is_c1_REL = REL_IN_DoorLockSet;

    /*  DoorLockSet  */
    switch (tmpRead) {
     case 1:
      REL_B.SO_b_DoorLockSetSts = true;
      REL_B.SO_b_EEDoorLockSetSts = true;
      break;

     case 2:
      REL_B.SO_b_DoorLockSetSts = false;
      REL_B.SO_b_EEDoorLockSetSts = false;
      break;

     default:
      REL_B.SO_b_DoorLockSetSts = REL_B.SO_b_EEDoorLockSetSts;
      break;
    }
  } else {
    REL_B.SO_b_EEDoorLockSetSts = (tmpRead_0 != 0);
  }

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
  REL_DW.SI_b_CrashSts_start = tmpRead_9;
  if (REL_DW.is_active_c23_REL == 0U) {
    REL_DW.SI_b_CrashSts_prev = tmpRead_9;
    REL_DW.is_active_c23_REL = 1U;
    REL_DW.is_c23_REL = REL_IN_NoCrash;
    REL_enter_atomic_NoCrash(&SL_b_FLDoorInBtnSts, &SL_b_FRDoorInBtnSts,
      &SL_b_FLDoorHndPullSts);
  } else if (REL_DW.is_c23_REL == REL_IN_Crash) {
    if (REL_DW.temporalCounter_i1 >= 1000) {
      REL_DW.is_c23_REL = REL_IN_NoCrash;
      REL_enter_atomic_NoCrash(&SL_b_FLDoorInBtnSts, &SL_b_FRDoorInBtnSts,
        &SL_b_FLDoorHndPullSts);
    } else {
      SL_b_FLDoorInBtnSts = false;
      SL_b_FRDoorInBtnSts = false;
      REL_B.SL_b_RLDoorInBtnSts = false;
      REL_B.SL_b_RRDoorInBtnSts = false;
      SL_b_FLDoorHndPullSts = false;
      REL_B.SL_b_FRDoorHndPullSts = false;
      REL_B.SL_b_RLDoorHndPullSts = false;
      REL_B.SL_b_RRDoorHndPullSts = false;
      REL_B.SL_b_FLDoorHndBtnSts = false;
      REL_B.SL_b_FRDoorHndBtnSts = false;
      REL_B.SL_b_RLDoorHndBtnSts = false;
      REL_B.SL_b_RRDoorHndBtnSts = false;
    }

    /* case IN_NoCrash: */
  } else if ((REL_DW.SI_b_CrashSts_prev != REL_DW.SI_b_CrashSts_start) &&
             REL_DW.SI_b_CrashSts_start) {
    REL_DW.is_c23_REL = REL_IN_Crash;
    REL_DW.temporalCounter_i1 = 0U;
    SL_b_FLDoorInBtnSts = false;
    SL_b_FRDoorInBtnSts = false;
    REL_B.SL_b_RLDoorInBtnSts = false;
    REL_B.SL_b_RRDoorInBtnSts = false;
    SL_b_FLDoorHndPullSts = false;
    REL_B.SL_b_FRDoorHndPullSts = false;
    REL_B.SL_b_RLDoorHndPullSts = false;
    REL_B.SL_b_RRDoorHndPullSts = false;
    REL_B.SL_b_FLDoorHndBtnSts = false;
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
      (&REL_B.SL_b_FLDoorHndBtnSts);
    (void)Rte_Read_VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg
      (&REL_B.SL_b_RRDoorHndPullSts);
    (void)Rte_Read_VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg
      (&REL_B.SL_b_RLDoorHndPullSts);
    (void)Rte_Read_VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg
      (&REL_B.SL_b_FRDoorHndPullSts);
    (void)Rte_Read_VbINP_HWA_FLDoorOutButton_flg_VbINP_HWA_FLDoorOutButton_flg
      (&SL_b_FLDoorHndPullSts);
    (void)Rte_Read_VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg
      (&REL_B.SL_b_RRDoorInBtnSts);
    (void)Rte_Read_VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg
      (&REL_B.SL_b_RLDoorInBtnSts);
    (void)Rte_Read_VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg
      (&SL_b_FRDoorInBtnSts);
    (void)Rte_Read_VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg
      (&SL_b_FLDoorInBtnSts);
  }

  /* End of Chart: '<S3>/DoorSwSts' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VeOUT_PDU_BcmPowerStatusFeedback_sig_VeOUT_PDU_BcmPowerStatusFeedback_sig' */
  (void)
    Rte_Read_VeOUT_PDU_BcmPowerStatusFeedback_sig_VeOUT_PDU_BcmPowerStatusFeedback_sig
    (&SO_e_MotorPwm_h);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* SignalConversion generated from: '<S2>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg'
   */
  (void)Rte_Read_VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg
    (&REL_B.TmpSignalConversionAtVbINP_HWA_);

  /* Truth Table: '<S3>/FLDoorRatSts' */
  REL_FLDoorRatSts(REL_B.TmpSignalConversionAtVbINP_HWA_,
                   &REL_B.SO_e_DoorRatSts_dw);

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Constant: '<S12>/Constant'
   */
  REL_B.Compare = (SO_e_MotorPwm_h == 0);

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

  /* SignalConversion generated from: '<S2>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig_read' incorporates:
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   */
  (void)Rte_Read_VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig
    (&REL_B.TmpSignalConversionAtVeINP_CAN_);

  /* SignalConversion generated from: '<S2>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   */
  (void)
    Rte_Read_VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg
    (&REL_B.TmpSignalConversionAtVbINP_CA_f);

  /* Chart: '<S3>/FLDoorRlsReq' incorporates:
   *  Constant: '<S3>/Constant2'
   */
  if (REL_DW.temporalCounter_i1_o < 7U) {
    REL_DW.temporalCounter_i1_o++;
  }

  if (REL_DW.temporalCounter_i2_h < 255U) {
    REL_DW.temporalCounter_i2_h++;
  }

  if (REL_DW.temporalCounter_i3_i < 127U) {
    REL_DW.temporalCounter_i3_i++;
  }

  if (REL_DW.temporalCounter_i4_j < 7U) {
    REL_DW.temporalCounter_i4_j++;
  }

  if (REL_DW.temporalCounter_i5_a < 127U) {
    REL_DW.temporalCounter_i5_a++;
  }

  if (REL_DW.temporalCounter_i6_f < 127U) {
    REL_DW.temporalCounter_i6_f++;
  }

  if (REL_DW.temporalCounter_i7_j < 127U) {
    REL_DW.temporalCounter_i7_j++;
  }

  REL_DW.SI_b_DoorLockOpenReq_prev_j = REL_DW.SI_b_DoorLockOpenReq_start_f;
  REL_DW.SI_b_DoorLockOpenReq_start_f = false;
  REL_DW.SI_b_DoorInBtnSts_prev_a = REL_DW.SI_b_DoorInBtnSts_start_l;
  REL_DW.SI_b_DoorInBtnSts_start_l = SL_b_FLDoorInBtnSts;
  REL_DW.SL_b_DoorInBtnValid_prev_j = REL_DW.SL_b_DoorInBtnValid_start_d;
  REL_DW.SL_b_DoorInBtnValid_start_d = REL_DW.SL_b_DoorInBtnValid_f;
  REL_DW.SL_b_DoorHndPullValid_prev_f = REL_DW.SL_b_DoorHndPullValid_start_o;
  REL_DW.SL_b_DoorHndPullValid_start_o = REL_DW.SL_b_DoorHndPullValid_g;
  REL_DW.SI_b_DoorHndBtnSts_prev_a = REL_DW.SI_b_DoorHndBtnSts_start_h;
  REL_DW.SI_b_DoorHndBtnSts_start_h = REL_B.SL_b_FLDoorHndBtnSts;
  REL_DW.SL_b_DoorHndBtnValid_prev_e = REL_DW.SL_b_DoorHndBtnValid_start_l;
  REL_DW.SL_b_DoorHndBtnValid_start_l = REL_DW.SL_b_DoorHndBtnValid_g;
  REL_DW.SL_b_CentSingleDoorSwValid_pr_k =
    REL_DW.SL_b_CentSingleDoorSwValid_st_o;
  REL_DW.SL_b_CentSingleDoorSwValid_st_o = REL_DW.SL_b_CentSingleDoorSwValid_a;
  REL_DW.SL_b_CentAllDoorSwValid_prev_g = REL_DW.SL_b_CentAllDoorSwValid_start_m;
  REL_DW.SL_b_CentAllDoorSwValid_start_m = REL_DW.SL_b_CentAllDoorSwValid_j;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg' */
  (void)
    Rte_Read_VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg
    (&REL_DW.SL_b_CentSingleDoorSwValid_a);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/FLDoorRlsReq' incorporates:
   *  Constant: '<S3>/Constant2'
   *  Inport: '<Root>/VeOUT_DHM_BDCDrvrDoorHndSts_sig_VeOUT_DHM_BDCDrvrDoorHndSts_sig'
   *  Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig'
   */
  if (REL_DW.is_active_c5_DoorRlsReq_m == 0U) {
    REL_DW.SI_b_DoorLockOpenReq_prev_j = false;
    REL_DW.SI_b_DoorInBtnSts_prev_a = SL_b_FLDoorInBtnSts;
    REL_DW.SI_b_DoorHndBtnSts_prev_a = REL_B.SL_b_FLDoorHndBtnSts;
    REL_DW.is_active_c5_DoorRlsReq_m = 1U;
    REL_DW.is_SwValid_a = REL_IN_Idle_n;
    REL_DW.SL_b_DoorInBtnValid_f = false;
    REL_DW.is_RlsReq_n3 = REL_IN_Initial_b;
    REL_DW.is_DoorCentral_j = REL_IN_Initial_b;
    REL_DW.SL_b_CentAllDoorSwValid_j = REL_B.TmpSignalConversionAtVbINP_CA_f;
    REL_DW.SL_b_DoorHndPullValid_g = SL_b_FLDoorHndPullSts;
    REL_DW.is_RlsReq_nw = REL_IN_Initial_b;
    REL_DW.is_RlsReq_cd = REL_IN_Initial_b;
    REL_B.SO_b_UnlockReq_m = false;
    REL_DW.is_SwValid_g = REL_IN_Initial_b;
    REL_DW.SL_b_DoorHndBtnValid_g = false;
    REL_DW.is_RlsReq_n = REL_IN_Idle_n;
    REL_B.SO_b_DoorRlsReq_fz = false;
  } else {
    (void)
      Rte_Read_VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig
      (&tmpRead_1);
    REL_DoorInBtn_i();
    if (REL_DW.is_DoorCentral_j == REL_IN_Initial_b) {
      if ((!REL_B.Compare) && (((REL_B.TmpSignalConversionAtVeOUT_SP_E <= 0) &&
            (!REL_B.TmpSignalConversionAtVbINP_CAN_)) ||
           (REL_B.TmpSignalConversionAtVeINP_CAN_ == 1)) &&
          (((REL_DW.SL_b_CentSingleDoorSwValid_pr_k !=
             REL_DW.SL_b_CentSingleDoorSwValid_st_o) &&
            REL_DW.SL_b_CentSingleDoorSwValid_st_o) ||
           ((REL_DW.SL_b_CentAllDoorSwValid_prev_g !=
             REL_DW.SL_b_CentAllDoorSwValid_start_m) &&
            REL_DW.SL_b_CentAllDoorSwValid_start_m))) {
        REL_DW.is_DoorCentral_j = REL_IN_Trigger_h;
        switch (tmpRead_1) {
         case 0:
          REL_DW.is_Trigger_c = REL_IN_DoorLock_b;
          REL_DW.temporalCounter_i7_j = 0U;
          REL_B.SO_b_UnlockReq_m = true;
          break;

         case 1:
          REL_DW.is_Trigger_c = REL_IN_DoorUnlock_h;
          break;

         default:
          REL_DW.is_Trigger_c = REL_IN_Error_f;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (REL_B.Compare || ((REL_B.TmpSignalConversionAtVeOUT_SP_E >= 1) &&
                (!REL_B.TmpSignalConversionAtVbINP_CAN_) &&
                (REL_B.TmpSignalConversionAtVeINP_CAN_ != 1)) || ((tmpRead_1 ==
                 1) && (REL_B.SO_e_DoorRatSts_dw == 3))) {
      REL_DW.is_Trigger_c = REL_IN_NO_ACTIVE_CHILD_f;
      REL_DW.is_DoorCentral_j = REL_IN_Initial_b;
      REL_B.SO_b_DoorRlsReq_fz = false;
      REL_B.SO_b_UnlockReq_m = false;
    } else {
      switch (REL_DW.is_Trigger_c) {
       case REL_IN_DoorLock_b:
        if (REL_DW.temporalCounter_i7_j >= 100) {
          REL_DW.is_Trigger_c = REL_IN_NO_ACTIVE_CHILD_f;
          REL_DW.is_DoorCentral_j = REL_IN_Initial_b;
          REL_B.SO_b_DoorRlsReq_fz = false;
          REL_B.SO_b_UnlockReq_m = false;
        } else if ((tmpRead_1 == 1) && (REL_B.SO_e_DoorRatSts_dw != 3)) {
          REL_DW.is_Trigger_c = REL_IN_RELEASE_j;
          REL_DW.temporalCounter_i7_j = 0U;
          REL_B.SO_b_DoorRlsReq_fz = true;
          REL_B.SO_e_DoorRlsDelayTime_g = 0U;
        }
        break;

       case REL_IN_DoorUnlock_h:
        if (REL_B.SO_e_DoorRatSts_dw != 3) {
          REL_DW.is_Trigger_c = REL_IN_RELEASE_j;
          REL_DW.temporalCounter_i7_j = 0U;
          REL_B.SO_b_DoorRlsReq_fz = true;
          REL_B.SO_e_DoorRlsDelayTime_g = 0U;
        }
        break;

       case REL_IN_Error_f:
        REL_DW.is_Trigger_c = REL_IN_NO_ACTIVE_CHILD_f;
        REL_DW.is_DoorCentral_j = REL_IN_Initial_b;
        REL_B.SO_b_DoorRlsReq_fz = false;
        REL_B.SO_b_UnlockReq_m = false;
        break;

       default:
        /* case IN_RELEASE: */
        if (REL_DW.temporalCounter_i7_j >= 5) {
          REL_DW.is_Trigger_c = REL_IN_NO_ACTIVE_CHILD_f;
          REL_DW.is_DoorCentral_j = REL_IN_Initial_b;
          REL_B.SO_b_DoorRlsReq_fz = false;
          REL_B.SO_b_UnlockReq_m = false;
        }
        break;
      }
    }

    REL_DW.SL_b_CentAllDoorSwValid_j = REL_B.TmpSignalConversionAtVbINP_CA_f;
    REL_DW.SL_b_DoorHndPullValid_g = SL_b_FLDoorHndPullSts;
    (void)
      Rte_Read_VeOUT_DHM_BDCDrvrDoorHndSts_sig_VeOUT_DHM_BDCDrvrDoorHndSts_sig
      (&tmpRead_7);
    if (REL_DW.is_RlsReq_nw == REL_IN_Initial_b) {
      if ((!REL_B.Compare) && (((REL_B.TmpSignalConversionAtVeOUT_SP_E <= 0) &&
            (!REL_B.TmpSignalConversionAtVbINP_CAN_)) ||
           (REL_B.TmpSignalConversionAtVeINP_CAN_ == 1)) && (tmpRead_1 == 1) &&
          (tmpRead_7 == 1) && ((REL_DW.SL_b_DoorHndPullValid_prev_f !=
            REL_DW.SL_b_DoorHndPullValid_start_o) &&
           REL_DW.SL_b_DoorHndPullValid_start_o)) {
        REL_DW.is_RlsReq_nw = REL_IN_Trigger_h;
        REL_DW.is_Trigger_f = REL_IN_Wait_b;
      }

      /* case IN_Trigger: */
    } else if (REL_B.Compare || ((REL_B.TmpSignalConversionAtVeOUT_SP_E >= 1) &&
                (!REL_B.TmpSignalConversionAtVbINP_CAN_) &&
                (REL_B.TmpSignalConversionAtVeINP_CAN_ != 1)) || (tmpRead_1 != 1)
               || (tmpRead_7 != 1) || (REL_B.SO_e_DoorRatSts_dw == 3)) {
      REL_DW.is_Trigger_f = REL_IN_NO_ACTIVE_CHILD_f;
      REL_DW.is_RlsReq_nw = REL_IN_Initial_b;
      REL_B.SO_b_DoorRlsReq_fz = false;
      REL_B.SO_b_UnlockReq_m = false;
    } else if (REL_DW.is_Trigger_f == REL_IN_Release_h) {
      if (REL_DW.temporalCounter_i4_j >= 5) {
        REL_DW.is_Trigger_f = REL_IN_NO_ACTIVE_CHILD_f;
        REL_DW.is_RlsReq_nw = REL_IN_Initial_b;
        REL_B.SO_b_DoorRlsReq_fz = false;
        REL_B.SO_b_UnlockReq_m = false;
      }

      /* case IN_Wait: */
    } else if (REL_B.SO_e_DoorRatSts_dw != 3) {
      REL_DW.is_Trigger_f = REL_IN_Release_h;
      REL_DW.temporalCounter_i4_j = 0U;
      REL_B.SO_b_DoorRlsReq_fz = true;
      REL_B.SO_e_DoorRlsDelayTime_g = 4U;
    }

    REL_DoorHand_c();
    if (REL_DW.is_RlsReq_n != REL_IN_Idle_n) {
      /* case IN_Trigger: */
      if (REL_B.Compare || ((REL_B.TmpSignalConversionAtVeOUT_SP_E >= 1) &&
                            (!REL_B.TmpSignalConversionAtVbINP_CAN_) &&
                            (REL_B.TmpSignalConversionAtVeINP_CAN_ != 1)) ||
          (!REL_B.SO_b_DoorLockSetSts) || (tmpRead_1 != 1) ||
          (REL_B.SO_e_DoorRatSts_dw == 3)) {
        REL_DW.is_Trigger_o = REL_IN_NO_ACTIVE_CHILD_f;
        REL_DW.is_RlsReq_n = REL_IN_Idle_n;
        REL_B.SO_b_DoorRlsReq_fz = false;
      } else if (REL_DW.is_Trigger_o == REL_IN_Release_h) {
        if (REL_DW.temporalCounter_i1_o >= 5) {
          REL_DW.is_Trigger_o = REL_IN_NO_ACTIVE_CHILD_f;
          REL_DW.is_RlsReq_n = REL_IN_Idle_n;
          REL_B.SO_b_DoorRlsReq_fz = false;
        }

        /* case IN_WAIT: */
      } else if (REL_B.SO_e_DoorRatSts_dw != 3) {
        REL_DW.is_Trigger_o = REL_IN_Release_h;
        REL_DW.temporalCounter_i1_o = 0U;
        REL_B.SO_b_DoorRlsReq_fz = true;
        REL_B.SO_e_DoorRlsDelayTime_g = 0U;
      }
    }
  }

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VbINP_CAN_FLDCUCinchHomeSwitch_flg_VbINP_CAN_FLDCUCinchHomeSwitch_flg' */
  (void)
    Rte_Read_VbINP_CAN_FLDCUCinchHomeSwitch_flg_VbINP_CAN_FLDCUCinchHomeSwitch_flg
    (&tmpRead_5);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* SignalConversion generated from: '<S2>/VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg'
   */
  (void)Rte_Read_VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg
    (&REL_B.TmpSignalConversionAtVbINP_CFG_);

  /* Chart: '<S3>/FLDoorRlsDriver' */
  REL_FLDoorRlsDriver(REL_B.SO_b_DoorRlsReq_fz,
                      REL_B.TmpSignalConversionAtVbINP_HWA_, tmpRead_5,
                      REL_B.TmpSignalConversionAtVbINP_CFG_,
                      REL_B.SO_e_DoorRlsDelayTime_g, &REL_B.SO_b_MotorA_p,
                      &REL_B.SO_b_MotorB_e, &REL_B.SO_e_MotorMode_d,
                      &SL_b_FLDoorHndPullSts, &SO_e_MotorPwm_h,
                      &REL_DW.sf_FLDoorRlsDriver);

  /* SignalConversion generated from: '<S2>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   */
  (void)Rte_Read_VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg
    (&REL_B.TmpSignalConversionAtVbINP_HW_g);

  /* Truth Table: '<S3>/FRDoorRatSts' */
  REL_FLDoorRatSts(REL_B.TmpSignalConversionAtVbINP_HW_g,
                   &REL_B.SO_e_DoorRatSts_d);

  /* SignalConversion generated from: '<S2>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig_read' incorporates:
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   */
  (void)
    Rte_Read_VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig
    (&REL_B.TmpSignalConversionAtVeOUT_DLK_);

  /* Chart: '<S3>/FRDoorRlsReq' incorporates:
   *  Constant: '<S3>/Constant4'
   */
  if (REL_DW.temporalCounter_i1_h < 7U) {
    REL_DW.temporalCounter_i1_h++;
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

  REL_DW.SI_b_DoorLockOpenReq_prev = REL_DW.SI_b_DoorLockOpenReq_start;
  REL_DW.SI_b_DoorLockOpenReq_start = false;
  REL_DW.SI_b_DoorInBtnSts_prev = REL_DW.SI_b_DoorInBtnSts_start;
  REL_DW.SI_b_DoorInBtnSts_start = SL_b_FRDoorInBtnSts;
  REL_DW.SL_b_DoorInBtnValid_prev = REL_DW.SL_b_DoorInBtnValid_start;
  REL_DW.SL_b_DoorInBtnValid_start = REL_DW.SL_b_DoorInBtnValid;
  REL_DW.SL_b_DoorHndPullValid_prev = REL_DW.SL_b_DoorHndPullValid_start;
  REL_DW.SL_b_DoorHndPullValid_start = REL_DW.SL_b_DoorHndPullValid;
  REL_DW.SI_b_DoorHndBtnSts_prev = REL_DW.SI_b_DoorHndBtnSts_start;
  REL_DW.SI_b_DoorHndBtnSts_start = REL_B.SL_b_FRDoorHndBtnSts;
  REL_DW.SL_b_DoorHndBtnValid_prev = REL_DW.SL_b_DoorHndBtnValid_start;
  REL_DW.SL_b_DoorHndBtnValid_start = REL_DW.SL_b_DoorHndBtnValid;
  REL_DW.SL_b_CentSingleDoorSwValid_prev =
    REL_DW.SL_b_CentSingleDoorSwValid_star;
  REL_DW.SL_b_CentSingleDoorSwValid_star = REL_DW.SL_b_CentSingleDoorSwValid;
  REL_DW.SL_b_CentAllDoorSwValid_prev = REL_DW.SL_b_CentAllDoorSwValid_start;
  REL_DW.SL_b_CentAllDoorSwValid_start = REL_DW.SL_b_CentAllDoorSwValid;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg' */
  (void)
    Rte_Read_VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg
    (&REL_DW.SL_b_CentSingleDoorSwValid);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/FRDoorRlsReq' incorporates:
   *  Constant: '<S3>/Constant4'
   *  Inport: '<Root>/VeOUT_DHM_BDCPassDoorHndSts_sig_VeOUT_DHM_BDCPassDoorHndSts_sig'
   */
  if (REL_DW.is_active_c5_DoorRlsReq == 0U) {
    REL_DW.SI_b_DoorLockOpenReq_prev = false;
    REL_DW.SI_b_DoorInBtnSts_prev = SL_b_FRDoorInBtnSts;
    REL_DW.SI_b_DoorHndBtnSts_prev = REL_B.SL_b_FRDoorHndBtnSts;
    REL_DW.is_active_c5_DoorRlsReq = 1U;
    REL_DW.is_SwValid = REL_IN_Idle_n;
    REL_DW.SL_b_DoorInBtnValid = false;
    REL_DW.is_RlsReq_c = REL_IN_Initial_b;
    REL_DW.is_DoorCentral = REL_IN_Initial_b;
    REL_DW.SL_b_CentAllDoorSwValid = REL_B.TmpSignalConversionAtVbINP_CA_f;
    REL_DW.SL_b_DoorHndPullValid = REL_B.SL_b_FRDoorHndPullSts;
    REL_DW.is_RlsReq_p = REL_IN_Initial_b;
    REL_DW.is_RlsReq_py = REL_IN_Initial_b;
    REL_B.SO_b_UnlockReq_b = false;
    REL_DW.is_SwValid_k = REL_IN_Initial_b;
    REL_DW.SL_b_DoorHndBtnValid = false;
    REL_DW.is_RlsReq = REL_IN_Idle_n;
    REL_B.SO_b_DoorRlsReq_p = false;
  } else {
    REL_DoorInBtn_i5();
    if (REL_DW.is_DoorCentral == REL_IN_Initial_b) {
      if ((!REL_B.Compare) && (((REL_B.TmpSignalConversionAtVeOUT_SP_E <= 0) &&
            (!REL_B.TmpSignalConversionAtVbINP_CAN_)) ||
           (REL_B.TmpSignalConversionAtVeINP_CAN_ == 1)) &&
          (((REL_DW.SL_b_CentSingleDoorSwValid_prev !=
             REL_DW.SL_b_CentSingleDoorSwValid_star) &&
            REL_DW.SL_b_CentSingleDoorSwValid_star) ||
           ((REL_DW.SL_b_CentAllDoorSwValid_prev !=
             REL_DW.SL_b_CentAllDoorSwValid_start) &&
            REL_DW.SL_b_CentAllDoorSwValid_start))) {
        REL_DW.is_DoorCentral = REL_IN_Trigger_h;
        switch (REL_B.TmpSignalConversionAtVeOUT_DLK_) {
         case 0:
          REL_DW.is_Trigger_hb = REL_IN_DoorLock_b;
          REL_DW.temporalCounter_i7 = 0U;
          REL_B.SO_b_UnlockReq_b = true;
          break;

         case 1:
          REL_DW.is_Trigger_hb = REL_IN_DoorUnlock_h;
          break;

         default:
          REL_DW.is_Trigger_hb = REL_IN_Error_f;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (REL_B.Compare || ((REL_B.TmpSignalConversionAtVeOUT_SP_E >= 1) &&
                (!REL_B.TmpSignalConversionAtVbINP_CAN_) &&
                (REL_B.TmpSignalConversionAtVeINP_CAN_ != 1)) ||
               ((REL_B.TmpSignalConversionAtVeOUT_DLK_ == 1) &&
                (REL_B.SO_e_DoorRatSts_d == 3))) {
      REL_DW.is_Trigger_hb = REL_IN_NO_ACTIVE_CHILD_f;
      REL_DW.is_DoorCentral = REL_IN_Initial_b;
      REL_B.SO_b_DoorRlsReq_p = false;
      REL_B.SO_b_UnlockReq_b = false;
    } else {
      switch (REL_DW.is_Trigger_hb) {
       case REL_IN_DoorLock_b:
        if (REL_DW.temporalCounter_i7 >= 100) {
          REL_DW.is_Trigger_hb = REL_IN_NO_ACTIVE_CHILD_f;
          REL_DW.is_DoorCentral = REL_IN_Initial_b;
          REL_B.SO_b_DoorRlsReq_p = false;
          REL_B.SO_b_UnlockReq_b = false;
        } else if ((REL_B.TmpSignalConversionAtVeOUT_DLK_ == 1) &&
                   (REL_B.SO_e_DoorRatSts_d != 3)) {
          REL_DW.is_Trigger_hb = REL_IN_RELEASE_j;
          REL_DW.temporalCounter_i7 = 0U;
          REL_B.SO_b_DoorRlsReq_p = true;
          REL_B.SO_e_DoorRlsDelayTime_e = 0U;
        }
        break;

       case REL_IN_DoorUnlock_h:
        if (REL_B.SO_e_DoorRatSts_d != 3) {
          REL_DW.is_Trigger_hb = REL_IN_RELEASE_j;
          REL_DW.temporalCounter_i7 = 0U;
          REL_B.SO_b_DoorRlsReq_p = true;
          REL_B.SO_e_DoorRlsDelayTime_e = 0U;
        }
        break;

       case REL_IN_Error_f:
        REL_DW.is_Trigger_hb = REL_IN_NO_ACTIVE_CHILD_f;
        REL_DW.is_DoorCentral = REL_IN_Initial_b;
        REL_B.SO_b_DoorRlsReq_p = false;
        REL_B.SO_b_UnlockReq_b = false;
        break;

       default:
        /* case IN_RELEASE: */
        if (REL_DW.temporalCounter_i7 >= 5) {
          REL_DW.is_Trigger_hb = REL_IN_NO_ACTIVE_CHILD_f;
          REL_DW.is_DoorCentral = REL_IN_Initial_b;
          REL_B.SO_b_DoorRlsReq_p = false;
          REL_B.SO_b_UnlockReq_b = false;
        }
        break;
      }
    }

    REL_DW.SL_b_CentAllDoorSwValid = REL_B.TmpSignalConversionAtVbINP_CA_f;
    REL_DW.SL_b_DoorHndPullValid = REL_B.SL_b_FRDoorHndPullSts;
    (void)
      Rte_Read_VeOUT_DHM_BDCPassDoorHndSts_sig_VeOUT_DHM_BDCPassDoorHndSts_sig
      (&SO_e_MotorPwm_a);
    if (REL_DW.is_RlsReq_p == REL_IN_Initial_b) {
      if ((!REL_B.Compare) && (((REL_B.TmpSignalConversionAtVeOUT_SP_E <= 0) &&
            (!REL_B.TmpSignalConversionAtVbINP_CAN_)) ||
           (REL_B.TmpSignalConversionAtVeINP_CAN_ == 1)) &&
          (REL_B.TmpSignalConversionAtVeOUT_DLK_ == 1) && (SO_e_MotorPwm_a == 1)
          && ((REL_DW.SL_b_DoorHndPullValid_prev !=
               REL_DW.SL_b_DoorHndPullValid_start) &&
              REL_DW.SL_b_DoorHndPullValid_start)) {
        REL_DW.is_RlsReq_p = REL_IN_Trigger_h;
        REL_DW.is_Trigger_h = REL_IN_Wait_b;
      }

      /* case IN_Trigger: */
    } else if (REL_B.Compare || ((REL_B.TmpSignalConversionAtVeOUT_SP_E >= 1) &&
                (!REL_B.TmpSignalConversionAtVbINP_CAN_) &&
                (REL_B.TmpSignalConversionAtVeINP_CAN_ != 1)) ||
               (REL_B.TmpSignalConversionAtVeOUT_DLK_ != 1) || (SO_e_MotorPwm_a
                != 1) || (REL_B.SO_e_DoorRatSts_d == 3)) {
      REL_DW.is_Trigger_h = REL_IN_NO_ACTIVE_CHILD_f;
      REL_DW.is_RlsReq_p = REL_IN_Initial_b;
      REL_B.SO_b_DoorRlsReq_p = false;
      REL_B.SO_b_UnlockReq_b = false;
    } else if (REL_DW.is_Trigger_h == REL_IN_Release_h) {
      if (REL_DW.temporalCounter_i4 >= 5) {
        REL_DW.is_Trigger_h = REL_IN_NO_ACTIVE_CHILD_f;
        REL_DW.is_RlsReq_p = REL_IN_Initial_b;
        REL_B.SO_b_DoorRlsReq_p = false;
        REL_B.SO_b_UnlockReq_b = false;
      }

      /* case IN_Wait: */
    } else if (REL_B.SO_e_DoorRatSts_d != 3) {
      REL_DW.is_Trigger_h = REL_IN_Release_h;
      REL_DW.temporalCounter_i4 = 0U;
      REL_B.SO_b_DoorRlsReq_p = true;
      REL_B.SO_e_DoorRlsDelayTime_e = 4U;
    }

    REL_DoorHand_e();
    if (REL_DW.is_RlsReq != REL_IN_Idle_n) {
      /* case IN_Trigger: */
      REL_DW.is_Trigger = REL_IN_NO_ACTIVE_CHILD_f;
      REL_DW.is_RlsReq = REL_IN_Idle_n;
      REL_B.SO_b_DoorRlsReq_p = false;
    }
  }

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VeOUT_DHM_BDCRiReDoorHndSts_sig_VeOUT_DHM_BDCRiReDoorHndSts_sig' */
  (void)Rte_Read_VeOUT_DHM_BDCRiReDoorHndSts_sig_VeOUT_DHM_BDCRiReDoorHndSts_sig
    (&SO_e_MotorPwm_m);

  /* Inport: '<Root>/VeOUT_DHM_BDCLeReDoorHndSts_sig_VeOUT_DHM_BDCLeReDoorHndSts_sig' */
  (void)Rte_Read_VeOUT_DHM_BDCLeReDoorHndSts_sig_VeOUT_DHM_BDCLeReDoorHndSts_sig
    (&tmpRead_8);

  /* Inport: '<Root>/VbINP_CAN_RRDCUCinchHomeSwitch_flg_VbINP_CAN_RRDCUCinchHomeSwitch_flg' */
  (void)
    Rte_Read_VbINP_CAN_RRDCUCinchHomeSwitch_flg_VbINP_CAN_RRDCUCinchHomeSwitch_flg
    (&tmpRead_6);

  /* Inport: '<Root>/VbINP_CAN_RLDCUCinchHomeSwitch_flg_VbINP_CAN_RLDCUCinchHomeSwitch_flg' */
  (void)
    Rte_Read_VbINP_CAN_RLDCUCinchHomeSwitch_flg_VbINP_CAN_RLDCUCinchHomeSwitch_flg
    (&SO_b_Error);

  /* Inport: '<Root>/VbINP_CAN_FRDCUCinchHomeSwitch_flg_VbINP_CAN_FRDCUCinchHomeSwitch_flg' */
  (void)
    Rte_Read_VbINP_CAN_FRDCUCinchHomeSwitch_flg_VbINP_CAN_FRDCUCinchHomeSwitch_flg
    (&rtb_LogicalOperator);

  /* Inport: '<Root>/VbINP_CAN_CdcRiReDoorButtonSts_flg_VbINP_CAN_CdcRiReDoorButtonSts_flg' */
  (void)
    Rte_Read_VbINP_CAN_CdcRiReDoorButtonSts_flg_VbINP_CAN_CdcRiReDoorButtonSts_flg
    (&SO_b_Error_h);

  /* Inport: '<Root>/VbINP_CAN_CdcLeReDoorButtonSts_flg_VbINP_CAN_CdcLeReDoorButtonSts_flg' */
  (void)
    Rte_Read_VbINP_CAN_CdcLeReDoorButtonSts_flg_VbINP_CAN_CdcLeReDoorButtonSts_flg
    (&tmpRead_4);

  /* Inport: '<Root>/VbINP_HWA_RRChildLckSt_flg_VbINP_HWA_RRChildLckSt_flg' */
  (void)Rte_Read_VbINP_HWA_RRChildLckSt_flg_VbINP_HWA_RRChildLckSt_flg
    (&tmpRead_3);

  /* Inport: '<Root>/VbINP_HWA_LRChildLckSt_flg_VbINP_HWA_LRChildLckSt_flg' */
  (void)Rte_Read_VbINP_HWA_LRChildLckSt_flg_VbINP_HWA_LRChildLckSt_flg
    (&tmpRead_2);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/FRDoorRlsDriver' */
  REL_FLDoorRlsDriver(REL_B.SO_b_DoorRlsReq_p,
                      REL_B.TmpSignalConversionAtVbINP_HW_g, rtb_LogicalOperator,
                      REL_B.TmpSignalConversionAtVbINP_CFG_,
                      REL_B.SO_e_DoorRlsDelayTime_e, &REL_B.SO_b_MotorA_b,
                      &REL_B.SO_b_MotorB_p, &REL_B.SO_e_MotorMode_h,
                      &SL_b_FRDoorInBtnSts, &SO_e_MotorPwm_a,
                      &REL_DW.sf_FRDoorRlsDriver);

  /* SignalConversion generated from: '<S2>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg'
   */
  (void)Rte_Read_VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg
    (&REL_B.TmpSignalConversionAtVbINP_HW_f);

  /* Truth Table: '<S3>/RLDoorRatSts' */
  REL_FLDoorRatSts(REL_B.TmpSignalConversionAtVbINP_HW_f,
                   &REL_B.SO_e_DoorRatSts_f);

  /* Chart: '<S3>/RLDoorRlsReq' incorporates:
   *  Constant: '<S3>/Constant10'
   *  Constant: '<S3>/Constant6'
   */
  REL_RLDoorRlsReq(REL_B.Compare, REL_B.TmpSignalConversionAtVeOUT_SP_E,
                   REL_B.TmpSignalConversionAtVbINP_CAN_,
                   REL_B.TmpSignalConversionAtVeINP_CAN_,
                   REL_B.TmpSignalConversionAtVeOUT_DLK_,
                   REL_B.SO_e_DoorRatSts_f, REL_B.SL_b_RLDoorInBtnSts,
                   REL_B.SL_b_RLDoorHndPullSts, REL_B.SL_b_RLDoorHndBtnSts,
                   tmpRead_8, tmpRead_4, REL_B.TmpSignalConversionAtVbINP_CA_f,
                   tmpRead_2, false, false, &REL_B.SO_b_DoorRlsReq_f,
                   &REL_B.SO_b_UnlockReq_h, &REL_B.SO_e_DoorRlsDelayTime_o,
                   &REL_DW.sf_RLDoorRlsReq);

  /* SignalConversion generated from: '<S2>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg'
   */
  (void)Rte_Read_VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg
    (&REL_B.TmpSignalConversionAtVbINP_H_gz);

  /* Truth Table: '<S3>/RRDoorRatSts' */
  REL_FLDoorRatSts(REL_B.TmpSignalConversionAtVbINP_H_gz, &REL_B.SO_e_DoorRatSts);

  /* Chart: '<S3>/RRDoorRlsReq' incorporates:
   *  Constant: '<S3>/Constant11'
   *  Constant: '<S3>/Constant12'
   */
  REL_RLDoorRlsReq(REL_B.Compare, REL_B.TmpSignalConversionAtVeOUT_SP_E,
                   REL_B.TmpSignalConversionAtVbINP_CAN_,
                   REL_B.TmpSignalConversionAtVeINP_CAN_,
                   REL_B.TmpSignalConversionAtVeOUT_DLK_, REL_B.SO_e_DoorRatSts,
                   REL_B.SL_b_RRDoorInBtnSts, REL_B.SL_b_RRDoorHndPullSts,
                   REL_B.SL_b_RRDoorHndBtnSts, SO_e_MotorPwm_m, SO_b_Error_h,
                   REL_B.TmpSignalConversionAtVbINP_CA_f, tmpRead_3, false,
                   false, &REL_B.SO_b_DoorRlsReq, &REL_B.SO_b_UnlockReq,
                   &REL_B.SO_e_DoorRlsDelayTime, &REL_DW.sf_RRDoorRlsReq);

  /* Logic: '<S3>/Logical Operator' */
  rtb_LogicalOperator = (REL_B.SO_b_UnlockReq_b || REL_B.SO_b_UnlockReq_h ||
    REL_B.SO_b_UnlockReq);

  /* Chart: '<S3>/RLDoorRlsDriver' */
  REL_FLDoorRlsDriver(REL_B.SO_b_DoorRlsReq_f,
                      REL_B.TmpSignalConversionAtVbINP_HW_f, SO_b_Error,
                      REL_B.TmpSignalConversionAtVbINP_CFG_,
                      REL_B.SO_e_DoorRlsDelayTime_o, &REL_B.SO_b_MotorA_d,
                      &REL_B.SO_b_MotorB_o, &REL_B.SO_e_MotorMode_l,
                      &SO_b_Error_h, &SO_e_MotorPwm_m,
                      &REL_DW.sf_RLDoorRlsDriver);

  /* Chart: '<S3>/RRDoorRlsDriver' */
  REL_FLDoorRlsDriver(REL_B.SO_b_DoorRlsReq,
                      REL_B.TmpSignalConversionAtVbINP_H_gz, tmpRead_6,
                      REL_B.TmpSignalConversionAtVbINP_CFG_,
                      REL_B.SO_e_DoorRlsDelayTime, &REL_B.SO_b_MotorA,
                      &REL_B.SO_b_MotorB, &REL_B.SO_e_MotorMode, &SO_b_Error,
                      &SO_e_MotorPwm_m, &REL_DW.sf_RRDoorRlsDriver);

  /* Chart: '<S3>/Unlock_Request' */
  REL_DW.SI_b_DrvUnlockReq_prev = REL_DW.SI_b_DrvUnlockReq_start;
  REL_DW.SI_b_DrvUnlockReq_start = REL_B.SO_b_UnlockReq_m;
  REL_DW.SI_b_PassUnlockReq_prev = REL_DW.SI_b_PassUnlockReq_start;
  REL_DW.SI_b_PassUnlockReq_start = rtb_LogicalOperator;
  if (REL_DW.is_active_c6_REL == 0U) {
    REL_DW.SI_b_DrvUnlockReq_prev = REL_B.SO_b_UnlockReq_m;
    REL_DW.SI_b_PassUnlockReq_prev = rtb_LogicalOperator;
    REL_DW.is_active_c6_REL = 1U;
    REL_DW.is_c6_REL = REL_IN_Initial_b;
    REL_B.SO_e_UnlockReq = 0U;
  } else if (REL_DW.is_c6_REL == REL_IN_Initial_b) {
    if (((REL_DW.SI_b_DrvUnlockReq_prev != REL_DW.SI_b_DrvUnlockReq_start) &&
         REL_DW.SI_b_DrvUnlockReq_start) || ((REL_DW.SI_b_PassUnlockReq_prev !=
          REL_DW.SI_b_PassUnlockReq_start) && REL_DW.SI_b_PassUnlockReq_start))
    {
      REL_DW.is_c6_REL = REL_IN_REQ_SENT;
    }
  } else {
    /* case IN_REQ_SENT: */
    tmpRead_6 = !rtb_LogicalOperator;
    SO_b_Error = !REL_B.SO_b_UnlockReq_m;
    if (SO_b_Error && tmpRead_6) {
      REL_DW.is_c6_REL = REL_IN_Initial_b;
      REL_B.SO_e_UnlockReq = 0U;
    } else if (REL_B.SO_b_UnlockReq_m && rtb_LogicalOperator) {
      REL_B.SO_e_UnlockReq = 3U;
    } else if (REL_B.SO_b_UnlockReq_m && tmpRead_6) {
      REL_B.SO_e_UnlockReq = 1U;
    } else if (SO_b_Error && rtb_LogicalOperator) {
      REL_B.SO_e_UnlockReq = 2U;
    } else {
      REL_B.SO_e_UnlockReq = 0U;
    }
  }

  /* End of Chart: '<S3>/Unlock_Request' */

  /* Outport: '<Root>/VeOUT_REL_BcmDrvrDoorSwtSts_sig_VeOUT_REL_BcmDrvrDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   */
  (void)
    Rte_Write_VeOUT_REL_BcmDrvrDoorSwtSts_sig_VeOUT_REL_BcmDrvrDoorSwtSts_sig(0U);

  /* Outport: '<Root>/VeOUT_REL_BcmPassDoorSwtSts_sig_VeOUT_REL_BcmPassDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  (void)
    Rte_Write_VeOUT_REL_BcmPassDoorSwtSts_sig_VeOUT_REL_BcmPassDoorSwtSts_sig(0U);

  /* Outport: '<Root>/VeOUT_REL_BcmLeReDoorSwtSts_sig_VeOUT_REL_BcmLeReDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  (void)
    Rte_Write_VeOUT_REL_BcmLeReDoorSwtSts_sig_VeOUT_REL_BcmLeReDoorSwtSts_sig(0U);

  /* Outport: '<Root>/VeOUT_REL_BcmRiReDoorSwtSts_sig_VeOUT_REL_BcmRiReDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  (void)
    Rte_Write_VeOUT_REL_BcmRiReDoorSwtSts_sig_VeOUT_REL_BcmRiReDoorSwtSts_sig(0U);

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
    (REL_B.SO_b_DoorLockSetSts);

  /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
  (void)
    Rte_Write_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg
    (REL_B.SO_b_EEDoorLockSetSts);

  /* Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig' */
  (void)Rte_Write_VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig
    (REL_B.SO_e_DoorRatSts_dw);

  /* Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig' */
  (void)Rte_Write_VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig
    (REL_B.SO_e_DoorRatSts_d);

  /* Outport: '<Root>/VeOUT_REL_BdcLRDoorRatSts_sig_VeOUT_REL_BdcLRDoorRatSts_sig' */
  (void)Rte_Write_VeOUT_REL_BdcLRDoorRatSts_sig_VeOUT_REL_BdcLRDoorRatSts_sig
    (REL_B.SO_e_DoorRatSts_f);

  /* Outport: '<Root>/VeOUT_REL_BdcRRDoorRatSts_sig_VeOUT_REL_BdcRRDoorRatSts_sig' */
  (void)Rte_Write_VeOUT_REL_BdcRRDoorRatSts_sig_VeOUT_REL_BdcRRDoorRatSts_sig
    (REL_B.SO_e_DoorRatSts);

  /* Outport: '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg' */
  (void)
    Rte_Write_VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg
    (false);

  /* Outport: '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg' */
  (void)
    Rte_Write_VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg
    (false);

  /* Outport: '<Root>/VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg' */
  (void)
    Rte_Write_VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg
    (false);

  /* Outport: '<Root>/VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg' */
  (void)
    Rte_Write_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg
    (false);

  /* Outport: '<Root>/VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg' */
  (void)Rte_Write_VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg
    (false);

  /* Outport: '<Root>/VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg' */
  (void)Rte_Write_VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg
    (false);

  /* Outport: '<Root>/VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg' */
  (void)Rte_Write_VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg
    (false);

  /* Outport: '<Root>/VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg' */
  (void)Rte_Write_VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg
    (false);

  /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
  (void)Rte_Write_VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg
    (REL_B.SO_b_MotorA_p);

  /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
  (void)Rte_Write_VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg
    (REL_B.SO_b_MotorB_e);

  /* Outport: '<Root>/VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg' */
  (void)Rte_Write_VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg
    (REL_B.SO_b_MotorA_b);

  /* Outport: '<Root>/VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg' */
  (void)Rte_Write_VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg
    (REL_B.SO_b_MotorB_p);

  /* Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg' */
  (void)Rte_Write_VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg
    (REL_B.SO_b_MotorA_d);

  /* Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg' */
  (void)Rte_Write_VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg
    (REL_B.SO_b_MotorB_o);

  /* Outport: '<Root>/VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg' */
  (void)Rte_Write_VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg
    (REL_B.SO_b_MotorA);

  /* Outport: '<Root>/VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg' */
  (void)Rte_Write_VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg
    (REL_B.SO_b_MotorB);

  /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
  (void)Rte_Write_VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig
    (REL_B.SO_e_UnlockReq);

  /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
  (void)Rte_Write_VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg
    (REL_B.SO_b_DoorRlsReq_fz);

  /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
  (void)Rte_Write_VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg
    (REL_B.SO_b_DoorRlsReq_p);

  /* Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg' */
  (void)Rte_Write_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg
    (REL_B.SO_b_DoorRlsReq_f);

  /* Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg' */
  (void)Rte_Write_VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg
    (REL_B.SO_b_DoorRlsReq);

  /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
  (void)Rte_Write_VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig
    (REL_B.SO_e_MotorMode_d);

  /* Outport: '<Root>/VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig' */
  (void)Rte_Write_VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig
    (REL_B.SO_e_MotorMode_h);

  /* Outport: '<Root>/VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig' */
  (void)Rte_Write_VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig
    (REL_B.SO_e_MotorMode_l);

  /* Outport: '<Root>/VeOUT_REL_RRDoorMotorSts_sig_VeOUT_REL_RRDoorMotorSts_sig' */
  (void)Rte_Write_VeOUT_REL_RRDoorMotorSts_sig_VeOUT_REL_RRDoorMotorSts_sig
    (REL_B.SO_e_MotorMode);
}

/* Model initialize function */
void REL_Init(void)
{
  {
    uint8 SO_e_MotorPwm_h;
    boolean SO_b_Error_d;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
     *  SubSystem: '<Root>/REL_Step_sys'
     */

    /* SystemInitialize for Chart: '<S3>/FLDoorRlsDriver' */
    REL_FLDoorRlsDriver_Init(&REL_B.SO_b_MotorA_p, &REL_B.SO_b_MotorB_e,
      &REL_B.SO_e_MotorMode_d, &SO_b_Error_d, &SO_e_MotorPwm_h);

    /* SystemInitialize for Chart: '<S3>/FRDoorRlsDriver' */
    REL_FLDoorRlsDriver_Init(&REL_B.SO_b_MotorA_b, &REL_B.SO_b_MotorB_p,
      &REL_B.SO_e_MotorMode_h, &SO_b_Error_d, &SO_e_MotorPwm_h);

    /* SystemInitialize for Chart: '<S3>/RLDoorRlsDriver' */
    REL_FLDoorRlsDriver_Init(&REL_B.SO_b_MotorA_d, &REL_B.SO_b_MotorB_o,
      &REL_B.SO_e_MotorMode_l, &SO_b_Error_d, &SO_e_MotorPwm_h);

    /* SystemInitialize for Chart: '<S3>/RLDoorRlsReq' */
    REL_RLDoorRlsReq_Init(&REL_B.SO_b_DoorRlsReq_f, &REL_B.SO_b_UnlockReq_h,
                          &REL_B.SO_e_DoorRlsDelayTime_o);

    /* SystemInitialize for Chart: '<S3>/RRDoorRlsDriver' */
    REL_FLDoorRlsDriver_Init(&REL_B.SO_b_MotorA, &REL_B.SO_b_MotorB,
      &REL_B.SO_e_MotorMode, &SO_b_Error_d, &SO_e_MotorPwm_h);

    /* SystemInitialize for Chart: '<S3>/RRDoorRlsReq' */
    REL_RLDoorRlsReq_Init(&REL_B.SO_b_DoorRlsReq, &REL_B.SO_b_UnlockReq,
                          &REL_B.SO_e_DoorRlsDelayTime);

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
    (void)Rte_Write_VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg
      (REL_B.SO_b_MotorA_p);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
    (void)Rte_Write_VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg
      (REL_B.SO_b_MotorB_e);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg' */
    (void)Rte_Write_VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg
      (REL_B.SO_b_MotorA_b);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg' */
    (void)Rte_Write_VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg
      (REL_B.SO_b_MotorB_p);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg' */
    (void)Rte_Write_VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg
      (REL_B.SO_b_MotorA_d);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg' */
    (void)Rte_Write_VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg
      (REL_B.SO_b_MotorB_o);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg' */
    (void)Rte_Write_VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg
      (REL_B.SO_b_MotorA);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg' */
    (void)Rte_Write_VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg
      (REL_B.SO_b_MotorB);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg' */
    (void)Rte_Write_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg
      (REL_B.SO_b_DoorRlsReq_f);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg' */
    (void)Rte_Write_VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg
      (REL_B.SO_b_DoorRlsReq);

    /* SystemInitialize for Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
    (void)Rte_Write_VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig
      (REL_B.SO_e_MotorMode_d);

    /* SystemInitialize for Outport: '<Root>/VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig' */
    (void)Rte_Write_VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig
      (REL_B.SO_e_MotorMode_h);

    /* SystemInitialize for Outport: '<Root>/VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig' */
    (void)Rte_Write_VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig
      (REL_B.SO_e_MotorMode_l);

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
