/*
 * File: REL.c
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.204
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Oct 30 17:06:52 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "REL.h"
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "REL_types.h"
#include "REL_private.h"

/* Named constants for Chart: '<S3>/FLDoorRlsDriver' */
#define REL_IN_Check                   ((uint8_T)1U)
#define REL_IN_Delay                   ((uint8_T)2U)
#define REL_IN_Idle                    ((uint8_T)1U)
#define REL_IN_LastCheck               ((uint8_T)2U)
#define REL_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define REL_IN_Normal                  ((uint8_T)1U)
#define REL_IN_PowerOn                 ((uint8_T)2U)
#define REL_IN_Release                 ((uint8_T)2U)
#define REL_IN_Reset                   ((uint8_T)3U)
#define REL_IN_Stall_Handle            ((uint8_T)4U)
#define REL_IN_Step1_Ajar              ((uint8_T)5U)
#define REL_IN_Step2_Open              ((uint8_T)6U)

/* Named constants for Chart: '<S3>/RLDoorRlsReq' */
#define REL_IN_DoorLock                ((uint8_T)1U)
#define REL_IN_DoorUnlock              ((uint8_T)2U)
#define REL_IN_DoorUnlock_p            ((uint8_T)1U)
#define REL_IN_Error                   ((uint8_T)3U)
#define REL_IN_Idle_m                  ((uint8_T)1U)
#define REL_IN_NO_ACTIVE_CHILD_j       ((uint8_T)0U)
#define REL_IN_Once                    ((uint8_T)2U)
#define REL_IN_Press                   ((uint8_T)2U)
#define REL_IN_RELEASE                 ((uint8_T)4U)
#define REL_IN_Release_n               ((uint8_T)4U)
#define REL_IN_Release_ns              ((uint8_T)2U)
#define REL_IN_Release_nsm             ((uint8_T)3U)
#define REL_IN_Trigger                 ((uint8_T)2U)
#define REL_IN_Twice                   ((uint8_T)3U)
#define REL_IN_UnlockFail              ((uint8_T)1U)
#define REL_IN_UnlockReq               ((uint8_T)2U)
#define REL_IN_UnlockSuccess           ((uint8_T)3U)
#define REL_IN_UnlockSucess            ((uint8_T)3U)

/* Named constants for Chart: '<S3>/BleOpenAndClsDoorRsp' */
#define REL_IN_ClsFLDoorsReq           ((uint8_T)1U)
#define REL_IN_ClsFRDoorsReq           ((uint8_T)2U)
#define REL_IN_ClsFourDoorsReq         ((uint8_T)3U)
#define REL_IN_ClsRLDoorsReq           ((uint8_T)4U)
#define REL_IN_ClsRRDoorsReq           ((uint8_T)5U)
#define REL_IN_Idle_i                  ((uint8_T)6U)
#define REL_IN_NO_ACTIVE_CHILD_b       ((uint8_T)0U)
#define REL_IN_OpenFLDoorsReq          ((uint8_T)7U)
#define REL_IN_OpenFRDoorsReq          ((uint8_T)8U)
#define REL_IN_OpenFourDoorsReq        ((uint8_T)9U)
#define REL_IN_OpenRLDoorsReq          ((uint8_T)10U)
#define REL_IN_OpenRRDoorsReq          ((uint8_T)11U)

/* Named constants for Chart: '<S3>/DoorSwSts' */
#define REL_IN_Crash                   ((uint8_T)1U)
#define REL_IN_NoCrash                 ((uint8_T)2U)

/* Named constants for Chart: '<S3>/FLDoorRlsReq' */
#define REL_IN_DoorLock_k              ((uint8_T)1U)
#define REL_IN_DoorUnlock_i            ((uint8_T)2U)
#define REL_IN_DoorUnlock_i4           ((uint8_T)1U)
#define REL_IN_Error_g                 ((uint8_T)3U)
#define REL_IN_Idle_d                  ((uint8_T)1U)
#define REL_IN_Once_b                  ((uint8_T)2U)
#define REL_IN_Press_p                 ((uint8_T)2U)
#define REL_IN_RELEASE_k               ((uint8_T)4U)
#define REL_IN_Release_l               ((uint8_T)4U)
#define REL_IN_Release_lh              ((uint8_T)2U)
#define REL_IN_Release_lhf             ((uint8_T)3U)
#define REL_IN_Trigger_o               ((uint8_T)2U)
#define REL_IN_Twice_i                 ((uint8_T)3U)
#define REL_IN_UnlockFail_d            ((uint8_T)1U)
#define REL_IN_UnlockReq_o             ((uint8_T)2U)
#define REL_IN_UnlockSuccess_k         ((uint8_T)3U)
#define REL_IN_UnlockSucess_j          ((uint8_T)3U)

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
static real_T REL_GetPwm(real_T x, UInt8 rtu_SI_e_Volt100mV);

/* Forward declaration for local functions */
static void REL_DoorInBtn(UInt8 rtu_SI_e_EspVehSpd, Boolean
  rtu_SI_b_EspVehSpdVld, Gear_Posn_E rtu_SI_m_VcuGearPosn, Door_Sts_E
  rtu_SI_m_DoorLockSts, Rat_Sts_E rtu_SI_m_DoorRatSts, Boolean
  rtu_SI_b_ChildLckSts, boolean_T *rty_SO_b_DoorRlsReq, uint8_T
  *rty_SO_e_DoorRlsDelayTime, Unlock_Req_E *rty_SO_m_UnlockReq,
  DW_RLDoorRlsReq_REL_T *localDW);
static void REL_DoorHndBtn(UInt8 rtu_SI_e_EspVehSpd, Boolean
  rtu_SI_b_EspVehSpdVld, Gear_Posn_E rtu_SI_m_VcuGearPosn, Door_Sts_E
  rtu_SI_m_DoorLockSts, Rat_Sts_E rtu_SI_m_DoorRatSts, Boolean
  rtu_SI_b_DoorHndBtnSetSts, boolean_T rtu_SI_b_BleKeyPosValid, boolean_T
  *rty_SO_b_DoorRlsReq, Unlock_Req_E *rty_SO_m_UnlockReq, DW_RLDoorRlsReq_REL_T *
  localDW);
static void REL_CentDoorBtn(boolean_T rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd,
  Boolean rtu_SI_b_EspVehSpdVld, Gear_Posn_E rtu_SI_m_VcuGearPosn, Door_Sts_E
  rtu_SI_m_DoorLockSts, Rat_Sts_E rtu_SI_m_DoorRatSts, Boolean
  rtu_SI_b_CentSingleDoorBtnSts, Boolean rtu_SI_b_CentAllDoorBtnSts, boolean_T
  *rty_SO_b_DoorRlsReq, Unlock_Req_E *rty_SO_m_UnlockReq, DW_RLDoorRlsReq_REL_T *
  localDW);

/* Forward declaration for local functions */
static real_T REL_GetDoorRatSts(real_T ajar, real_T open);
static uint8_T REL_safe_cast_to_Rat_Sts_E(uint8_T input);
static void REL_enter_atomic_NoCrash(boolean_T *SL_b_FRDoorInBtnSts, boolean_T
  *SL_b_RLDoorInBtnSts, boolean_T *SL_b_RRDoorInBtnSts, boolean_T
  *SL_b_FLDoorInBtnSts);
static void REL_DoorInBtn_j(const boolean_T *SI_b_DoorInBtnSts_prev_j, const
  boolean_T *SL_b_DoorInBtnValid_prev_j, const Gear_Posn_E *DataTypeConversion14,
  const Rat_Sts_E *SO_m_FLDoorRatSts, const Door_Sts_E *DataTypeConversion12);
static void REL_DoorHndBtn_a(const boolean_T *LogicalOperator, const boolean_T
  *SI_b_DoorHndBtnSts_prev_f, const boolean_T *SL_b_DoorHndBtnValid_prev_l,
  const Gear_Posn_E *DataTypeConversion14, const Rat_Sts_E *SO_m_FLDoorRatSts,
  const Door_Sts_E *DataTypeConversion12);
static void REL_CentDoorBtn_e(const boolean_T *Compare, const boolean_T
  *SL_b_CentSingleDoorBtnValid_p_g, const boolean_T
  *SL_b_CentAllDoorBtnValid_prev_g, const Gear_Posn_E *DataTypeConversion14,
  const Rat_Sts_E *SO_m_FLDoorRatSts, const Door_Sts_E *DataTypeConversion12);
static void REL_DoorInBtn_e(const boolean_T *SI_b_DoorInBtnSts_prev, const
  boolean_T *SL_b_DoorInBtnValid_prev, const Gear_Posn_E *DataTypeConversion14,
  const Rat_Sts_E *SO_m_FRDoorRatSts, const Door_Sts_E *DataTypeConversion13);
static void REL_DoorHndBtn_d(const boolean_T *LogicalOperator, const boolean_T
  *SI_b_DoorHndBtnSts_prev, const boolean_T *SL_b_DoorHndBtnValid_prev, const
  Gear_Posn_E *DataTypeConversion14, const Rat_Sts_E *SO_m_FRDoorRatSts, const
  Door_Sts_E *DataTypeConversion13);
static void REL_CentDoorBtn_ew(const boolean_T *Compare, const boolean_T
  *SL_b_CentSingleDoorBtnValid_pre, const boolean_T
  *SL_b_CentAllDoorBtnValid_prev, const Gear_Posn_E *DataTypeConversion14, const
  Rat_Sts_E *SO_m_FRDoorRatSts, const Door_Sts_E *DataTypeConversion13);
static real_T REL_GetDrvUnlockReq(void);
static real_T REL_GetPassUnlockReq(void);

/* Function for Chart: '<S3>/FLDoorRlsDriver' */
static real_T REL_GetPwm(real_T x, UInt8 rtu_SI_e_Volt100mV)
{
  real_T y;
  y = x * 100.0 / (real_T)rtu_SI_e_Volt100mV;

  /*  扩大100倍，浮点转整型  */
  if ((y > 100.0) || (rtu_SI_e_Volt100mV == 0)) {
    y = 100.0;
  }

  return y;
}

/*
 * System initialize for atomic system:
 *    '<S3>/FLDoorRlsDriver'
 *    '<S3>/FRDoorRlsDriver'
 *    '<S3>/RLDoorRlsDriver'
 *    '<S3>/RRDoorRlsDriver'
 */
void REL_FLDoorRlsDriver_Init(uint8_T *rty_SO_e_MotorCmd, uint8_T
  *rty_SO_e_MotorPwm, boolean_T *rty_SO_b_Error)
{
  *rty_SO_e_MotorCmd = 0U;
  *rty_SO_e_MotorPwm = 0U;
  *rty_SO_b_Error = false;
}

/*
 * Output and update for atomic system:
 *    '<S3>/FLDoorRlsDriver'
 *    '<S3>/FRDoorRlsDriver'
 *    '<S3>/RLDoorRlsDriver'
 *    '<S3>/RRDoorRlsDriver'
 */
void REL_FLDoorRlsDriver(UInt8 rtu_SI_e_Volt100mV, boolean_T rtu_SO_b_DoorRlsReq,
  Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_DoorOpen, uint8_T
  rtu_SI_e_DoorRlsDelayTime, uint8_T *rty_SO_e_MotorCmd, uint8_T
  *rty_SO_e_MotorPwm, boolean_T *rty_SO_b_Error, DW_FLDoorRlsDriver_REL_T
  *localDW)
{
  if (localDW->temporalCounter_i1 < 511U) {
    localDW->temporalCounter_i1++;
  }

  /* Chart: '<S3>/FLDoorRlsDriver' */
  if (localDW->is_active_c19_DoorRlsDriver == 0U) {
    localDW->is_active_c19_DoorRlsDriver = 1U;
    localDW->is_c19_DoorRlsDriver = REL_IN_PowerOn;
    localDW->temporalCounter_i1 = 0U;

    /*  上电释放电机执行一次复位  */
    *rty_SO_e_MotorCmd = 2U;
    *rty_SO_e_MotorPwm = 100U;
  } else if (localDW->is_c19_DoorRlsDriver == REL_IN_Normal) {
    if (localDW->is_MainProgress == REL_IN_Idle) {
      if (rtu_SO_b_DoorRlsReq) {
        localDW->SL_e_DoorRlsDelayTime = rtu_SI_e_DoorRlsDelayTime;
        localDW->is_MainProgress = REL_IN_Release;
        localDW->SL_e_CycleCount = 0U;
        localDW->is_Release = REL_IN_Delay;
        localDW->temporalCounter_i1 = 0U;

        /*  无框车门电释放延时  */
      }
    } else {
      /* case IN_Release: */
      switch (localDW->is_Release) {
       case REL_IN_Check:
        {
          if ((localDW->temporalCounter_i1 >= 5) && rtu_SI_b_DoorAjar) {
            localDW->is_Release = REL_IN_Step2_Open;
            localDW->is_Step2_Open = REL_IN_Idle;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_e_MotorCmd = 0U;
            *rty_SO_e_MotorPwm = 0U;
          } else {
            Boolean tmp_0;
            tmp_0 = !rtu_SI_b_DoorAjar;
            if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                (localDW->SL_e_CycleCount < 1)) {
              localDW->is_Release = REL_IN_Stall_Handle;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_e_MotorCmd = 1U;
              *rty_SO_e_MotorPwm = 100U;
              localDW->SL_e_CycleCount = 1U;
            } else if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                       (localDW->SL_e_CycleCount >= 1)) {
              real_T tmp;
              *rty_SO_b_Error = true;
              localDW->is_Release = REL_IN_Reset;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_e_MotorCmd = 2U;
              tmp = REL_GetPwm(70.0, rtu_SI_e_Volt100mV);
              if (tmp < 256.0) {
                if (tmp >= 0.0) {
                  *rty_SO_e_MotorPwm = (uint8_T)tmp;
                } else {
                  *rty_SO_e_MotorPwm = 0U;
                }
              } else {
                *rty_SO_e_MotorPwm = MAX_uint8_T;
              }
            }
          }
        }
        break;

       case REL_IN_Delay:
        {
          if (localDW->temporalCounter_i1 >= localDW->SL_e_DoorRlsDelayTime) {
            real_T tmp;
            localDW->is_Release = REL_IN_Step1_Ajar;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_e_MotorCmd = 1U;
            tmp = REL_GetPwm(105.0, rtu_SI_e_Volt100mV);
            if (tmp < 256.0) {
              if (tmp >= 0.0) {
                *rty_SO_e_MotorPwm = (uint8_T)tmp;
              } else {
                *rty_SO_e_MotorPwm = 0U;
              }
            } else {
              *rty_SO_e_MotorPwm = MAX_uint8_T;
            }
          }
        }
        break;

       case REL_IN_Reset:
        if (localDW->temporalCounter_i1 >= 30) {
          localDW->is_Release = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_MainProgress = REL_IN_Idle;
          *rty_SO_e_MotorCmd = 0U;
          *rty_SO_e_MotorPwm = 0U;
        }
        break;

       case REL_IN_Stall_Handle:
        if (localDW->temporalCounter_i1 >= 30) {
          localDW->is_Release = REL_IN_Check;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_e_MotorCmd = 0U;
          *rty_SO_e_MotorPwm = 0U;
        }
        break;

       case REL_IN_Step1_Ajar:
        if (localDW->temporalCounter_i1 >= 30) {
          localDW->is_Release = REL_IN_Check;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_e_MotorCmd = 0U;
          *rty_SO_e_MotorPwm = 0U;
        }
        break;

       default:
        {
          /* case IN_Step2_Open: */
          if (localDW->is_Step2_Open == REL_IN_Idle) {
            if ((localDW->temporalCounter_i1 < 270) && rtu_SI_b_DoorOpen) {
              real_T tmp;
              *rty_SO_b_Error = false;
              localDW->is_Step2_Open = REL_IN_NO_ACTIVE_CHILD;
              localDW->is_Release = REL_IN_Reset;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_e_MotorCmd = 2U;
              tmp = REL_GetPwm(70.0, rtu_SI_e_Volt100mV);
              if (tmp < 256.0) {
                if (tmp >= 0.0) {
                  *rty_SO_e_MotorPwm = (uint8_T)tmp;
                } else {
                  *rty_SO_e_MotorPwm = 0U;
                }
              } else {
                *rty_SO_e_MotorPwm = MAX_uint8_T;
              }
            } else if (localDW->temporalCounter_i1 >= 300) {
              localDW->is_Step2_Open = REL_IN_LastCheck;
            }
          } else {
            real_T tmp;

            /* case IN_LastCheck: */
            localDW->is_Step2_Open = REL_IN_NO_ACTIVE_CHILD;
            localDW->is_Release = REL_IN_Reset;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_e_MotorCmd = 2U;
            tmp = REL_GetPwm(70.0, rtu_SI_e_Volt100mV);
            if (tmp < 256.0) {
              if (tmp >= 0.0) {
                *rty_SO_e_MotorPwm = (uint8_T)tmp;
              } else {
                *rty_SO_e_MotorPwm = 0U;
              }
            } else {
              *rty_SO_e_MotorPwm = MAX_uint8_T;
            }
          }
        }
        break;
      }
    }

    /* case IN_PowerOn: */
  } else if (localDW->temporalCounter_i1 >= 30) {
    localDW->is_c19_DoorRlsDriver = REL_IN_Normal;

    /*  非电动门  */
    localDW->is_MainProgress = REL_IN_Idle;
    *rty_SO_e_MotorCmd = 0U;
    *rty_SO_e_MotorPwm = 0U;
  }

  /* End of Chart: '<S3>/FLDoorRlsDriver' */
}

/* Function for Chart: '<S3>/RLDoorRlsReq' */
static void REL_DoorInBtn(UInt8 rtu_SI_e_EspVehSpd, Boolean
  rtu_SI_b_EspVehSpdVld, Gear_Posn_E rtu_SI_m_VcuGearPosn, Door_Sts_E
  rtu_SI_m_DoorLockSts, Rat_Sts_E rtu_SI_m_DoorRatSts, Boolean
  rtu_SI_b_ChildLckSts, boolean_T *rty_SO_b_DoorRlsReq, uint8_T
  *rty_SO_e_DoorRlsDelayTime, Unlock_Req_E *rty_SO_m_UnlockReq,
  DW_RLDoorRlsReq_REL_T *localDW)
{
  switch (localDW->is_SwValid) {
   case REL_IN_Idle_m:
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
      localDW->is_SwValid = REL_IN_Idle_m;
      localDW->SL_b_DoorInBtnValid = false;
    }
    break;

   default:
    /* case IN_Twice: */
    if (localDW->temporalCounter_i4 >= 3) {
      localDW->is_SwValid = REL_IN_Idle_m;
      localDW->SL_b_DoorInBtnValid = false;
    }
    break;
  }

  if (localDW->is_RlsReq == REL_IN_Idle_m) {
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
    localDW->is_DoorLock = REL_IN_NO_ACTIVE_CHILD_j;
    localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_j;
    localDW->is_RlsReq = REL_IN_Idle_m;
  } else {
    switch (localDW->is_Trigger) {
     case REL_IN_DoorLock:
      switch (localDW->is_DoorLock) {
       case REL_IN_UnlockFail:
        localDW->is_DoorLock = REL_IN_NO_ACTIVE_CHILD_j;
        localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_j;
        localDW->is_RlsReq = REL_IN_Idle_m;
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
          localDW->is_DoorLock = REL_IN_NO_ACTIVE_CHILD_j;
          localDW->is_Trigger = REL_IN_Release_n;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_DoorRlsReq = true;
          *rty_SO_e_DoorRlsDelayTime = 20U;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock:
      if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
        localDW->is_Trigger = REL_IN_Release_n;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_DoorRlsReq = true;
        *rty_SO_e_DoorRlsDelayTime = 20U;
      }
      break;

     case REL_IN_Error:
      localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_j;
      localDW->is_RlsReq = REL_IN_Idle_m;
      break;

     default:
      /* case IN_Release: */
      if (localDW->temporalCounter_i1 >= 5) {
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_e_DoorRlsDelayTime = 0U;
        localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_j;
        localDW->is_RlsReq = REL_IN_Idle_m;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/RLDoorRlsReq' */
static void REL_DoorHndBtn(UInt8 rtu_SI_e_EspVehSpd, Boolean
  rtu_SI_b_EspVehSpdVld, Gear_Posn_E rtu_SI_m_VcuGearPosn, Door_Sts_E
  rtu_SI_m_DoorLockSts, Rat_Sts_E rtu_SI_m_DoorRatSts, Boolean
  rtu_SI_b_DoorHndBtnSetSts, boolean_T rtu_SI_b_BleKeyPosValid, boolean_T
  *rty_SO_b_DoorRlsReq, Unlock_Req_E *rty_SO_m_UnlockReq, DW_RLDoorRlsReq_REL_T *
  localDW)
{
  if (localDW->is_RlsReq_b == REL_IN_Idle_m) {
    if ((((rtu_SI_e_EspVehSpd <= 0) && (!rtu_SI_b_EspVehSpdVld)) ||
         (rtu_SI_m_VcuGearPosn == Gear_P)) && (!rtu_SI_b_DoorHndBtnSetSts) &&
        rtu_SI_b_BleKeyPosValid && ((localDW->SL_b_DoorHndBtnValid_prev !=
          localDW->SL_b_DoorHndBtnValid_start) &&
         localDW->SL_b_DoorHndBtnValid_start)) {
      localDW->is_RlsReq_b = REL_IN_Trigger;
      switch (rtu_SI_m_DoorLockSts) {
       case Door_Lock:
        localDW->is_Trigger_p = REL_IN_DoorLock;
        localDW->is_DoorLock_h = REL_IN_UnlockReq;
        localDW->temporalCounter_i2 = 0U;
        *rty_SO_m_UnlockReq = Unlock_PE;
        break;

       case Door_Unlock:
        localDW->is_Trigger_p = REL_IN_DoorUnlock;
        break;

       default:
        localDW->is_Trigger_p = REL_IN_Error;
        break;
      }
    }

    /* case IN_Trigger: */
  } else if (((rtu_SI_e_EspVehSpd >= 1) && (!rtu_SI_b_EspVehSpdVld) &&
              (rtu_SI_m_VcuGearPosn != Gear_P)) || rtu_SI_b_DoorHndBtnSetSts ||
             ((rtu_SI_m_DoorLockSts == Door_Unlock) && (rtu_SI_m_DoorRatSts ==
               Rat_Unlock))) {
    localDW->is_DoorLock_h = REL_IN_NO_ACTIVE_CHILD_j;
    localDW->is_Trigger_p = REL_IN_NO_ACTIVE_CHILD_j;
    localDW->is_RlsReq_b = REL_IN_Idle_m;
  } else {
    switch (localDW->is_Trigger_p) {
     case REL_IN_DoorLock:
      switch (localDW->is_DoorLock_h) {
       case REL_IN_UnlockFail:
        localDW->is_DoorLock_h = REL_IN_NO_ACTIVE_CHILD_j;
        localDW->is_Trigger_p = REL_IN_NO_ACTIVE_CHILD_j;
        localDW->is_RlsReq_b = REL_IN_Idle_m;
        break;

       case REL_IN_UnlockReq:
        if (rtu_SI_m_DoorLockSts == Door_Unlock) {
          localDW->is_DoorLock_h = REL_IN_UnlockSuccess;
        } else if ((localDW->temporalCounter_i2 >= 50) && (rtu_SI_m_DoorLockSts ==
                    Door_Lock)) {
          localDW->is_DoorLock_h = REL_IN_UnlockFail;
        } else if (localDW->temporalCounter_i2 == 5) {
          *rty_SO_m_UnlockReq = Unlock_Idle;
        }
        break;

       default:
        /* case IN_UnlockSuccess: */
        if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
          localDW->is_DoorLock_h = REL_IN_NO_ACTIVE_CHILD_j;
          localDW->is_Trigger_p = REL_IN_Release_n;
          localDW->temporalCounter_i2 = 0U;
          *rty_SO_b_DoorRlsReq = true;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock:
      if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
        localDW->is_Trigger_p = REL_IN_Release_n;
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
        localDW->is_Trigger_p = REL_IN_NO_ACTIVE_CHILD_j;
        localDW->is_RlsReq_b = REL_IN_Idle_m;
      }
      break;
    }
  }

  switch (localDW->is_SwValid_m) {
   case REL_IN_Idle_m:
    if ((localDW->SI_b_DoorHndBtnSts_prev != localDW->SI_b_DoorHndBtnSts_start) &&
        localDW->SI_b_DoorHndBtnSts_start) {
      localDW->is_SwValid_m = REL_IN_Press;
      localDW->temporalCounter_i6 = 0U;
    }
    break;

   case REL_IN_Press:
    if ((localDW->SI_b_DoorHndBtnSts_prev != localDW->SI_b_DoorHndBtnSts_start) &&
        (!localDW->SI_b_DoorHndBtnSts_start)) {
      localDW->is_SwValid_m = REL_IN_Release_nsm;
      localDW->temporalCounter_i6 = 0U;
      localDW->SL_b_DoorHndBtnValid = true;
    } else if (localDW->temporalCounter_i6 >= 100) {
      localDW->is_SwValid_m = REL_IN_Idle_m;
      localDW->SL_b_DoorHndBtnValid = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (localDW->temporalCounter_i6 >= 3) {
      localDW->is_SwValid_m = REL_IN_Idle_m;
      localDW->SL_b_DoorHndBtnValid = false;
    }
    break;
  }
}

/* Function for Chart: '<S3>/RLDoorRlsReq' */
static void REL_CentDoorBtn(boolean_T rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd,
  Boolean rtu_SI_b_EspVehSpdVld, Gear_Posn_E rtu_SI_m_VcuGearPosn, Door_Sts_E
  rtu_SI_m_DoorLockSts, Rat_Sts_E rtu_SI_m_DoorRatSts, Boolean
  rtu_SI_b_CentSingleDoorBtnSts, Boolean rtu_SI_b_CentAllDoorBtnSts, boolean_T
  *rty_SO_b_DoorRlsReq, Unlock_Req_E *rty_SO_m_UnlockReq, DW_RLDoorRlsReq_REL_T *
  localDW)
{
  if (localDW->is_DoorCentral == REL_IN_Idle_m) {
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
        localDW->is_Trigger_o = REL_IN_DoorLock;
        localDW->is_DoorLock_f = REL_IN_UnlockReq;
        localDW->temporalCounter_i3 = 0U;
        *rty_SO_m_UnlockReq = Unlock_Req;
        break;

       case Door_Unlock:
        localDW->is_Trigger_o = REL_IN_DoorUnlock;
        break;

       default:
        localDW->is_Trigger_o = REL_IN_Error;
        break;
      }
    }

    /* case IN_Trigger: */
  } else if (rtu_SI_b_OFF || ((rtu_SI_e_EspVehSpd >= 1) &&
              (!rtu_SI_b_EspVehSpdVld) && (rtu_SI_m_VcuGearPosn != Gear_P)) ||
             ((rtu_SI_m_DoorLockSts == Door_Unlock) && (rtu_SI_m_DoorRatSts ==
               Rat_Unlock))) {
    localDW->is_DoorLock_f = REL_IN_NO_ACTIVE_CHILD_j;
    localDW->is_Trigger_o = REL_IN_NO_ACTIVE_CHILD_j;
    localDW->is_DoorCentral = REL_IN_Idle_m;
  } else {
    switch (localDW->is_Trigger_o) {
     case REL_IN_DoorLock:
      switch (localDW->is_DoorLock_f) {
       case REL_IN_UnlockFail:
        localDW->is_DoorLock_f = REL_IN_NO_ACTIVE_CHILD_j;
        localDW->is_Trigger_o = REL_IN_NO_ACTIVE_CHILD_j;
        localDW->is_DoorCentral = REL_IN_Idle_m;
        break;

       case REL_IN_UnlockReq:
        if (rtu_SI_m_DoorLockSts == Door_Unlock) {
          localDW->is_DoorLock_f = REL_IN_UnlockSucess;
        } else if ((localDW->temporalCounter_i3 >= 50) && (rtu_SI_m_DoorLockSts ==
                    Door_Lock)) {
          localDW->is_DoorLock_f = REL_IN_UnlockFail;
        } else if (localDW->temporalCounter_i3 == 5) {
          *rty_SO_m_UnlockReq = Unlock_Idle;
        }
        break;

       default:
        /* case IN_UnlockSucess: */
        if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
          localDW->is_DoorLock_f = REL_IN_NO_ACTIVE_CHILD_j;
          localDW->is_Trigger_o = REL_IN_RELEASE;
          localDW->temporalCounter_i3 = 0U;
          *rty_SO_b_DoorRlsReq = true;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock:
      if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
        localDW->is_Trigger_o = REL_IN_RELEASE;
        localDW->temporalCounter_i3 = 0U;
        *rty_SO_b_DoorRlsReq = true;
      }
      break;

     case REL_IN_Error:
      localDW->is_Trigger_o = REL_IN_NO_ACTIVE_CHILD_j;
      localDW->is_DoorCentral = REL_IN_Idle_m;
      break;

     default:
      /* case IN_RELEASE: */
      if (localDW->temporalCounter_i3 >= 5) {
        *rty_SO_b_DoorRlsReq = false;
        localDW->is_Trigger_o = REL_IN_NO_ACTIVE_CHILD_j;
        localDW->is_DoorCentral = REL_IN_Idle_m;
      }
      break;
    }
  }

  localDW->SL_b_CentSingleDoorBtnValid = rtu_SI_b_CentSingleDoorBtnSts;
  localDW->SL_b_CentAllDoorBtnValid = rtu_SI_b_CentAllDoorBtnSts;
}

/*
 * System initialize for atomic system:
 *    '<S3>/RLDoorRlsReq'
 *    '<S3>/RRDoorRlsReq'
 */
void REL_RLDoorRlsReq_Init(boolean_T *rty_SO_b_DoorRlsReq, uint8_T
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
void REL_RLDoorRlsReq(boolean_T rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd, Boolean
                      rtu_SI_b_EspVehSpdVld, Gear_Posn_E rtu_SI_m_VcuGearPosn,
                      Door_Sts_E rtu_SI_m_DoorLockSts, Rat_Sts_E
                      rtu_SI_m_DoorRatSts, boolean_T rtu_SI_b_DoorInBtnSts,
                      boolean_T rtu_SI_b_DoorHndPullSts, boolean_T
                      rtu_SI_b_DoorHndBtnSts, HndPos_Sts_E
                      rtu_SI_m_DoorHandPosSts, Boolean
                      rtu_SI_b_CentSingleDoorBtnSts, Boolean
                      rtu_SI_b_CentAllDoorBtnSts, Boolean rtu_SI_b_ChildLckSts,
                      boolean_T rtu_SI_b_DoorAutoRlsSetSts, boolean_T
                      rtu_SI_b_DoorAutoRlsReq, Boolean rtu_SI_b_DoorHndBtnSetSts,
                      boolean_T rtu_SI_b_BleDoorOpenReq, boolean_T
                      rtu_SI_b_BleKeyPosValid, boolean_T *rty_SO_b_DoorRlsReq,
                      uint8_T *rty_SO_e_DoorRlsDelayTime, Unlock_Req_E
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

  if (localDW->temporalCounter_i8 < 7U) {
    localDW->temporalCounter_i8++;
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
  localDW->SL_b_BleDoorOpenValid_prev = localDW->SL_b_BleDoorOpenValid_start;
  localDW->SL_b_BleDoorOpenValid_start = localDW->SL_b_BleDoorOpenValid;

  /* Chart: '<S3>/RLDoorRlsReq' */
  if (localDW->is_active_c5_DoorRlsReq == 0U) {
    localDW->SI_b_DoorInBtnSts_prev = rtu_SI_b_DoorInBtnSts;
    localDW->SI_b_DoorHndBtnSts_prev = rtu_SI_b_DoorHndBtnSts;
    localDW->SI_b_DoorAutoRlsReq_prev = rtu_SI_b_DoorAutoRlsReq;
    localDW->is_active_c5_DoorRlsReq = 1U;
    localDW->is_SwValid = REL_IN_Idle_m;
    localDW->SL_b_DoorInBtnValid = false;
    localDW->is_RlsReq = REL_IN_Idle_m;
    localDW->SL_b_DoorHndPullValid = rtu_SI_b_DoorHndPullSts;
    localDW->is_RlsReq_m = REL_IN_Idle_m;
    localDW->is_RlsReq_b = REL_IN_Idle_m;
    localDW->is_SwValid_m = REL_IN_Idle_m;
    localDW->SL_b_DoorHndBtnValid = false;
    localDW->is_DoorCentral = REL_IN_Idle_m;
    localDW->SL_b_CentSingleDoorBtnValid = rtu_SI_b_CentSingleDoorBtnSts;
    localDW->SL_b_CentAllDoorBtnValid = rtu_SI_b_CentAllDoorBtnSts;
    localDW->is_RlsReq_bj = REL_IN_Idle_m;
    localDW->SL_b_BleDoorOpenValid = rtu_SI_b_BleDoorOpenReq;
    localDW->is_RlsReq_o = REL_IN_Idle_m;
  } else {
    REL_DoorInBtn(rtu_SI_e_EspVehSpd, rtu_SI_b_EspVehSpdVld,
                  rtu_SI_m_VcuGearPosn, rtu_SI_m_DoorLockSts,
                  rtu_SI_m_DoorRatSts, rtu_SI_b_ChildLckSts, rty_SO_b_DoorRlsReq,
                  rty_SO_e_DoorRlsDelayTime, rty_SO_m_UnlockReq, localDW);
    localDW->SL_b_DoorHndPullValid = rtu_SI_b_DoorHndPullSts;
    if (localDW->is_RlsReq_m == REL_IN_Idle_m) {
      if ((!rtu_SI_b_OFF) && (((rtu_SI_e_EspVehSpd <= 0) &&
            (!rtu_SI_b_EspVehSpdVld)) || (rtu_SI_m_VcuGearPosn == Gear_P)) &&
          (rtu_SI_m_DoorLockSts == Door_Unlock) && (rtu_SI_m_DoorHandPosSts ==
           Hnd_Unfold) && ((localDW->SL_b_DoorHndPullValid_prev !=
                            localDW->SL_b_DoorHndPullValid_start) &&
                           localDW->SL_b_DoorHndPullValid_start)) {
        localDW->is_RlsReq_m = REL_IN_Trigger;
        localDW->is_Trigger_m = REL_IN_DoorUnlock_p;
      }

      /* case IN_Trigger: */
    } else if (rtu_SI_b_OFF || ((rtu_SI_e_EspVehSpd >= 1) &&
                (!rtu_SI_b_EspVehSpdVld) && (rtu_SI_m_VcuGearPosn != Gear_P)) ||
               (rtu_SI_m_DoorLockSts != Door_Unlock) || (rtu_SI_m_DoorHandPosSts
                != Hnd_Unfold) || (rtu_SI_m_DoorRatSts == Rat_Unlock)) {
      localDW->is_Trigger_m = REL_IN_NO_ACTIVE_CHILD_j;
      localDW->is_RlsReq_m = REL_IN_Idle_m;
    } else if (localDW->is_Trigger_m == REL_IN_DoorUnlock_p) {
      if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
        localDW->is_Trigger_m = REL_IN_Release_ns;
        localDW->temporalCounter_i5 = 0U;
        *rty_SO_b_DoorRlsReq = true;
        *rty_SO_e_DoorRlsDelayTime = 4U;
      }

      /* case IN_Release: */
    } else if (localDW->temporalCounter_i5 >= 5) {
      *rty_SO_b_DoorRlsReq = false;
      *rty_SO_e_DoorRlsDelayTime = 0U;
      localDW->is_Trigger_m = REL_IN_NO_ACTIVE_CHILD_j;
      localDW->is_RlsReq_m = REL_IN_Idle_m;
    }

    REL_DoorHndBtn(rtu_SI_e_EspVehSpd, rtu_SI_b_EspVehSpdVld,
                   rtu_SI_m_VcuGearPosn, rtu_SI_m_DoorLockSts,
                   rtu_SI_m_DoorRatSts, rtu_SI_b_DoorHndBtnSetSts,
                   rtu_SI_b_BleKeyPosValid, rty_SO_b_DoorRlsReq,
                   rty_SO_m_UnlockReq, localDW);
    REL_CentDoorBtn(rtu_SI_b_OFF, rtu_SI_e_EspVehSpd, rtu_SI_b_EspVehSpdVld,
                    rtu_SI_m_VcuGearPosn, rtu_SI_m_DoorLockSts,
                    rtu_SI_m_DoorRatSts, rtu_SI_b_CentSingleDoorBtnSts,
                    rtu_SI_b_CentAllDoorBtnSts, rty_SO_b_DoorRlsReq,
                    rty_SO_m_UnlockReq, localDW);
    if (localDW->is_RlsReq_bj == REL_IN_Idle_m) {
      if ((!rtu_SI_b_OFF) && (((rtu_SI_e_EspVehSpd <= 0) &&
            (!rtu_SI_b_EspVehSpdVld)) || (rtu_SI_m_VcuGearPosn == Gear_P)) &&
          rtu_SI_b_DoorAutoRlsSetSts && (rtu_SI_m_DoorLockSts == Door_Unlock) &&
          ((localDW->SI_b_DoorAutoRlsReq_prev !=
            localDW->SI_b_DoorAutoRlsReq_start) &&
           localDW->SI_b_DoorAutoRlsReq_start)) {
        localDW->is_RlsReq_bj = REL_IN_Trigger;
        localDW->is_Trigger_k = REL_IN_DoorUnlock_p;
      }

      /* case IN_Trigger: */
    } else if (rtu_SI_b_OFF || ((rtu_SI_e_EspVehSpd >= 1) &&
                (!rtu_SI_b_EspVehSpdVld) && (rtu_SI_m_VcuGearPosn != Gear_P)) ||
               (!rtu_SI_b_DoorAutoRlsSetSts) || (rtu_SI_m_DoorLockSts !=
                Door_Unlock) || (rtu_SI_m_DoorRatSts == Rat_Unlock)) {
      localDW->is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_j;
      localDW->is_RlsReq_bj = REL_IN_Idle_m;
    } else if (localDW->is_Trigger_k == REL_IN_DoorUnlock_p) {
      if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
        localDW->is_Trigger_k = REL_IN_Release_ns;
        localDW->temporalCounter_i7 = 0U;
        *rty_SO_b_DoorRlsReq = true;
      }

      /* case IN_Release: */
    } else if (localDW->temporalCounter_i7 >= 5) {
      *rty_SO_b_DoorRlsReq = false;
      localDW->is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_j;
      localDW->is_RlsReq_bj = REL_IN_Idle_m;
    }

    localDW->SL_b_BleDoorOpenValid = rtu_SI_b_BleDoorOpenReq;
    if (localDW->is_RlsReq_o == REL_IN_Idle_m) {
      if ((!rtu_SI_b_OFF) && ((rtu_SI_e_EspVehSpd <= 0) &&
                              (!rtu_SI_b_EspVehSpdVld)) && (rtu_SI_m_VcuGearPosn
           == Gear_P) && (rtu_SI_m_DoorLockSts == Door_Unlock) &&
          ((localDW->SL_b_BleDoorOpenValid_prev !=
            localDW->SL_b_BleDoorOpenValid_start) &&
           localDW->SL_b_BleDoorOpenValid_start)) {
        localDW->is_RlsReq_o = REL_IN_Trigger;
        localDW->is_Trigger_mj = REL_IN_DoorUnlock_p;
      }

      /* case IN_Trigger: */
    } else if (rtu_SI_b_OFF || ((rtu_SI_e_EspVehSpd >= 1) &&
                (!rtu_SI_b_EspVehSpdVld)) || (rtu_SI_m_VcuGearPosn != Gear_P) ||
               (rtu_SI_m_DoorLockSts != Door_Unlock) || (rtu_SI_m_DoorRatSts ==
                Rat_Unlock)) {
      localDW->is_Trigger_mj = REL_IN_NO_ACTIVE_CHILD_j;
      localDW->is_RlsReq_o = REL_IN_Idle_m;
    } else if (localDW->is_Trigger_mj == REL_IN_DoorUnlock_p) {
      if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
        localDW->is_Trigger_mj = REL_IN_Release_ns;
        localDW->temporalCounter_i8 = 0U;
        *rty_SO_b_DoorRlsReq = true;
      }

      /* case IN_Release: */
    } else if (localDW->temporalCounter_i8 >= 5) {
      *rty_SO_b_DoorRlsReq = false;
      localDW->is_Trigger_mj = REL_IN_NO_ACTIVE_CHILD_j;
      localDW->is_RlsReq_o = REL_IN_Idle_m;
    }
  }

  /* End of Chart: '<S3>/RLDoorRlsReq' */
}

/* Function for Chart: '<S3>/DoorRatSts' */
static real_T REL_GetDoorRatSts(real_T ajar, real_T open)
{
  real_T status;
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

static uint8_T REL_safe_cast_to_Rat_Sts_E(uint8_T input)
{
  uint8_T output;

  /* Initialize output value to default value for Rat_Sts_E (Rat_Invalid) */
  output = 0U;
  if (input <= 3) {
    /* Set output value to input value if it is a member of Rat_Sts_E */
    output = input;
  }

  return output;
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
static void REL_DoorInBtn_j(const boolean_T *SI_b_DoorInBtnSts_prev_j, const
  boolean_T *SL_b_DoorInBtnValid_prev_j, const Gear_Posn_E *DataTypeConversion14,
  const Rat_Sts_E *SO_m_FLDoorRatSts, const Door_Sts_E *DataTypeConversion12)
{
  switch (REL_DW.is_SwValid_j) {
   case REL_IN_Idle_d:
    if ((*SI_b_DoorInBtnSts_prev_j != REL_DW.SI_b_DoorInBtnSts_start_b) &&
        REL_DW.SI_b_DoorInBtnSts_start_b) {
      REL_DW.is_SwValid_j = REL_IN_Once_b;
      REL_DW.temporalCounter_i4_d = 0U;
    }
    break;

   case REL_IN_Once_b:
    if ((*SI_b_DoorInBtnSts_prev_j != REL_DW.SI_b_DoorInBtnSts_start_b) &&
        REL_DW.SI_b_DoorInBtnSts_start_b) {
      REL_DW.is_SwValid_j = REL_IN_Twice_i;
      REL_DW.temporalCounter_i4_d = 0U;
      REL_DW.SL_b_DoorInBtnValid_e = true;
    } else if (REL_DW.temporalCounter_i4_d >= 200) {
      REL_DW.is_SwValid_j = REL_IN_Idle_d;
      REL_DW.SL_b_DoorInBtnValid_e = false;
    }
    break;

   default:
    /* case IN_Twice: */
    if (REL_DW.temporalCounter_i4_d >= 3) {
      REL_DW.is_SwValid_j = REL_IN_Idle_d;
      REL_DW.SL_b_DoorInBtnValid_e = false;
    }
    break;
  }

  if (REL_DW.is_RlsReq_p == REL_IN_Idle_d) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion12'
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     */
    if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) || (*DataTypeConversion14 ==
          Gear_P)) && ((*SL_b_DoorInBtnValid_prev_j !=
                        REL_DW.SL_b_DoorInBtnValid_start_m) &&
                       REL_DW.SL_b_DoorInBtnValid_start_m)) {
      REL_DW.is_RlsReq_p = REL_IN_Trigger_o;
      switch (*DataTypeConversion12) {
       case Door_Lock:
        REL_DW.is_Trigger_g = REL_IN_DoorLock_k;
        REL_DW.is_DoorLock_bg = REL_IN_UnlockReq_o;
        REL_DW.temporalCounter_i1_m = 0U;
        REL_B.SO_m_UnlockReq_j = Unlock_Req;
        break;

       case Door_Unlock:
        REL_DW.is_Trigger_g = REL_IN_DoorUnlock_i;
        break;

       default:
        REL_DW.is_Trigger_g = REL_IN_Error_g;
        break;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion12'
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
     */
    /* case IN_Trigger: */
  } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) && (*DataTypeConversion14
    != Gear_P)) || ((*DataTypeConversion12 == Door_Unlock) &&
                    (*SO_m_FLDoorRatSts == Rat_Unlock))) {
    REL_DW.is_DoorLock_bg = REL_IN_NO_ACTIVE_CHILD_b;
    REL_DW.is_Trigger_g = REL_IN_NO_ACTIVE_CHILD_b;
    REL_DW.is_RlsReq_p = REL_IN_Idle_d;
  } else {
    switch (REL_DW.is_Trigger_g) {
     case REL_IN_DoorLock_k:
      switch (REL_DW.is_DoorLock_bg) {
       case REL_IN_UnlockFail_d:
        REL_DW.is_DoorLock_bg = REL_IN_NO_ACTIVE_CHILD_b;
        REL_DW.is_Trigger_g = REL_IN_NO_ACTIVE_CHILD_b;
        REL_DW.is_RlsReq_p = REL_IN_Idle_d;
        break;

       case REL_IN_UnlockReq_o:
        if (*DataTypeConversion12 == Door_Unlock) {
          REL_DW.is_DoorLock_bg = REL_IN_UnlockSuccess_k;
        } else if ((REL_DW.temporalCounter_i1_m >= 50) && (*DataTypeConversion12
                    == Door_Lock)) {
          REL_DW.is_DoorLock_bg = REL_IN_UnlockFail_d;
        } else if (REL_DW.temporalCounter_i1_m == 5) {
          REL_B.SO_m_UnlockReq_j = Unlock_Idle;
        }
        break;

       default:
        /* case IN_UnlockSuccess: */
        if (*SO_m_FLDoorRatSts != Rat_Unlock) {
          REL_DW.is_DoorLock_bg = REL_IN_NO_ACTIVE_CHILD_b;
          REL_DW.is_Trigger_g = REL_IN_Release_l;
          REL_DW.temporalCounter_i1_m = 0U;
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
          REL_B.SO_e_DoorRlsDelayTime_k = 20U;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock_i:
      if (*SO_m_FLDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_g = REL_IN_Release_l;
        REL_DW.temporalCounter_i1_m = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_k = 20U;
      }
      break;

     case REL_IN_Error_g:
      REL_DW.is_Trigger_g = REL_IN_NO_ACTIVE_CHILD_b;
      REL_DW.is_RlsReq_p = REL_IN_Idle_d;
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i1_m >= 5) {
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_B.SO_e_DoorRlsDelayTime_k = 0U;
        REL_DW.is_Trigger_g = REL_IN_NO_ACTIVE_CHILD_b;
        REL_DW.is_RlsReq_p = REL_IN_Idle_d;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/FLDoorRlsReq' */
static void REL_DoorHndBtn_a(const boolean_T *LogicalOperator, const boolean_T
  *SI_b_DoorHndBtnSts_prev_f, const boolean_T *SL_b_DoorHndBtnValid_prev_l,
  const Gear_Posn_E *DataTypeConversion14, const Rat_Sts_E *SO_m_FLDoorRatSts,
  const Door_Sts_E *DataTypeConversion12)
{
  if (REL_DW.is_RlsReq_b3 == REL_IN_Idle_d) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion12'
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VbOUT_DHM_BdcDrivDoorHandButtonSts_flg_VbOUT_DHM_BdcDrivDoorHandButtonSts_flg'
     */
    if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) || (*DataTypeConversion14 ==
          Gear_P)) && (!REL_U.VbOUT_DHM_BdcDrivDoorHandButton) &&
        (*LogicalOperator) && ((*SL_b_DoorHndBtnValid_prev_l !=
          REL_DW.SL_b_DoorHndBtnValid_start_d) &&
         REL_DW.SL_b_DoorHndBtnValid_start_d)) {
      REL_DW.is_RlsReq_b3 = REL_IN_Trigger_o;
      switch (*DataTypeConversion12) {
       case Door_Lock:
        REL_DW.is_Trigger_n = REL_IN_DoorLock_k;
        REL_DW.is_DoorLock_f = REL_IN_UnlockReq_o;
        REL_DW.temporalCounter_i2_i = 0U;
        REL_B.SO_m_UnlockReq_j = Unlock_PE;
        break;

       case Door_Unlock:
        REL_DW.is_Trigger_n = REL_IN_DoorUnlock_i;
        break;

       default:
        REL_DW.is_Trigger_n = REL_IN_Error_g;
        break;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion12'
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VbOUT_DHM_BdcDrivDoorHandButtonSts_flg_VbOUT_DHM_BdcDrivDoorHandButtonSts_flg'
     *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
     */
    /* case IN_Trigger: */
  } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) && (*DataTypeConversion14
    != Gear_P)) || REL_U.VbOUT_DHM_BdcDrivDoorHandButton ||
             ((*DataTypeConversion12 == Door_Unlock) && (*SO_m_FLDoorRatSts ==
               Rat_Unlock))) {
    REL_DW.is_DoorLock_f = REL_IN_NO_ACTIVE_CHILD_b;
    REL_DW.is_Trigger_n = REL_IN_NO_ACTIVE_CHILD_b;
    REL_DW.is_RlsReq_b3 = REL_IN_Idle_d;
  } else {
    switch (REL_DW.is_Trigger_n) {
     case REL_IN_DoorLock_k:
      switch (REL_DW.is_DoorLock_f) {
       case REL_IN_UnlockFail_d:
        REL_DW.is_DoorLock_f = REL_IN_NO_ACTIVE_CHILD_b;
        REL_DW.is_Trigger_n = REL_IN_NO_ACTIVE_CHILD_b;
        REL_DW.is_RlsReq_b3 = REL_IN_Idle_d;
        break;

       case REL_IN_UnlockReq_o:
        if (*DataTypeConversion12 == Door_Unlock) {
          REL_DW.is_DoorLock_f = REL_IN_UnlockSuccess_k;
        } else if ((REL_DW.temporalCounter_i2_i >= 50) && (*DataTypeConversion12
                    == Door_Lock)) {
          REL_DW.is_DoorLock_f = REL_IN_UnlockFail_d;
        } else if (REL_DW.temporalCounter_i2_i == 5) {
          REL_B.SO_m_UnlockReq_j = Unlock_Idle;
        }
        break;

       default:
        /* case IN_UnlockSuccess: */
        if (*SO_m_FLDoorRatSts != Rat_Unlock) {
          REL_DW.is_DoorLock_f = REL_IN_NO_ACTIVE_CHILD_b;
          REL_DW.is_Trigger_n = REL_IN_Release_l;
          REL_DW.temporalCounter_i2_i = 0U;
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock_i:
      if (*SO_m_FLDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_n = REL_IN_Release_l;
        REL_DW.temporalCounter_i2_i = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
      }
      break;

     case REL_IN_Error_g:
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i2_i >= 5) {
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_DW.is_Trigger_n = REL_IN_NO_ACTIVE_CHILD_b;
        REL_DW.is_RlsReq_b3 = REL_IN_Idle_d;
      }
      break;
    }
  }

  switch (REL_DW.is_SwValid_b) {
   case REL_IN_Idle_d:
    if ((*SI_b_DoorHndBtnSts_prev_f != REL_DW.SI_b_DoorHndBtnSts_start_i) &&
        REL_DW.SI_b_DoorHndBtnSts_start_i) {
      REL_DW.is_SwValid_b = REL_IN_Press_p;
      REL_DW.temporalCounter_i6_d = 0U;
    }
    break;

   case REL_IN_Press_p:
    if ((*SI_b_DoorHndBtnSts_prev_f != REL_DW.SI_b_DoorHndBtnSts_start_i) &&
        (!REL_DW.SI_b_DoorHndBtnSts_start_i)) {
      REL_DW.is_SwValid_b = REL_IN_Release_lhf;
      REL_DW.temporalCounter_i6_d = 0U;
      REL_DW.SL_b_DoorHndBtnValid_f = true;
    } else if (REL_DW.temporalCounter_i6_d >= 100) {
      REL_DW.is_SwValid_b = REL_IN_Idle_d;
      REL_DW.SL_b_DoorHndBtnValid_f = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (REL_DW.temporalCounter_i6_d >= 3) {
      REL_DW.is_SwValid_b = REL_IN_Idle_d;
      REL_DW.SL_b_DoorHndBtnValid_f = false;
    }
    break;
  }
}

/* Function for Chart: '<S3>/FLDoorRlsReq' */
static void REL_CentDoorBtn_e(const boolean_T *Compare, const boolean_T
  *SL_b_CentSingleDoorBtnValid_p_g, const boolean_T
  *SL_b_CentAllDoorBtnValid_prev_g, const Gear_Posn_E *DataTypeConversion14,
  const Rat_Sts_E *SO_m_FLDoorRatSts, const Door_Sts_E *DataTypeConversion12)
{
  if (REL_DW.is_DoorCentral_l == REL_IN_Idle_d) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion12'
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     */
    if ((!*Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                         (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                        (*DataTypeConversion14 == Gear_P)) &&
        (((*SL_b_CentSingleDoorBtnValid_p_g !=
           REL_DW.SL_b_CentSingleDoorBtnValid_s_d) &&
          REL_DW.SL_b_CentSingleDoorBtnValid_s_d) ||
         ((*SL_b_CentAllDoorBtnValid_prev_g !=
           REL_DW.SL_b_CentAllDoorBtnValid_star_l) &&
          REL_DW.SL_b_CentAllDoorBtnValid_star_l))) {
      REL_DW.is_DoorCentral_l = REL_IN_Trigger_o;
      switch (*DataTypeConversion12) {
       case Door_Lock:
        REL_DW.is_Trigger_h = REL_IN_DoorLock_k;
        REL_DW.is_DoorLock_i = REL_IN_UnlockReq_o;
        REL_DW.temporalCounter_i3_g = 0U;
        REL_B.SO_m_UnlockReq_j = Unlock_Req;
        break;

       case Door_Unlock:
        REL_DW.is_Trigger_h = REL_IN_DoorUnlock_i;
        break;

       default:
        REL_DW.is_Trigger_h = REL_IN_Error_g;
        break;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion12'
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
     */
    /* case IN_Trigger: */
  } else if ((*Compare) || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) && (*DataTypeConversion14
    != Gear_P)) || ((*DataTypeConversion12 == Door_Unlock) &&
                    (*SO_m_FLDoorRatSts == Rat_Unlock))) {
    REL_DW.is_DoorLock_i = REL_IN_NO_ACTIVE_CHILD_b;
    REL_DW.is_Trigger_h = REL_IN_NO_ACTIVE_CHILD_b;
    REL_DW.is_DoorCentral_l = REL_IN_Idle_d;
  } else {
    switch (REL_DW.is_Trigger_h) {
     case REL_IN_DoorLock_k:
      switch (REL_DW.is_DoorLock_i) {
       case REL_IN_UnlockFail_d:
        REL_DW.is_DoorLock_i = REL_IN_NO_ACTIVE_CHILD_b;
        REL_DW.is_Trigger_h = REL_IN_NO_ACTIVE_CHILD_b;
        REL_DW.is_DoorCentral_l = REL_IN_Idle_d;
        break;

       case REL_IN_UnlockReq_o:
        if (*DataTypeConversion12 == Door_Unlock) {
          REL_DW.is_DoorLock_i = REL_IN_UnlockSucess_j;
        } else if ((REL_DW.temporalCounter_i3_g >= 50) && (*DataTypeConversion12
                    == Door_Lock)) {
          REL_DW.is_DoorLock_i = REL_IN_UnlockFail_d;
        } else if (REL_DW.temporalCounter_i3_g == 5) {
          REL_B.SO_m_UnlockReq_j = Unlock_Idle;
        }
        break;

       default:
        /* case IN_UnlockSucess: */
        if (*SO_m_FLDoorRatSts != Rat_Unlock) {
          REL_DW.is_DoorLock_i = REL_IN_NO_ACTIVE_CHILD_b;
          REL_DW.is_Trigger_h = REL_IN_RELEASE_k;
          REL_DW.temporalCounter_i3_g = 0U;
          REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock_i:
      if (*SO_m_FLDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_h = REL_IN_RELEASE_k;
        REL_DW.temporalCounter_i3_g = 0U;
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
      }
      break;

     case REL_IN_Error_g:
      REL_DW.is_Trigger_h = REL_IN_NO_ACTIVE_CHILD_b;
      REL_DW.is_DoorCentral_l = REL_IN_Idle_d;
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i3_g >= 5) {
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
        REL_DW.is_Trigger_h = REL_IN_NO_ACTIVE_CHILD_b;
        REL_DW.is_DoorCentral_l = REL_IN_Idle_d;
      }
      break;
    }
  }

  /* Inport: '<Root>/VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg' */
  REL_DW.SL_b_CentSingleDoorBtnValid_k = REL_U.VbINP_CAN_CdcDrvrDoorButtonSts_;

  /* Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg' */
  REL_DW.SL_b_CentAllDoorBtnValid_a = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
}

/* Function for Chart: '<S3>/FRDoorRlsReq' */
static void REL_DoorInBtn_e(const boolean_T *SI_b_DoorInBtnSts_prev, const
  boolean_T *SL_b_DoorInBtnValid_prev, const Gear_Posn_E *DataTypeConversion14,
  const Rat_Sts_E *SO_m_FRDoorRatSts, const Door_Sts_E *DataTypeConversion13)
{
  switch (REL_DW.is_SwValid) {
   case REL_IN_Idle_d:
    if ((*SI_b_DoorInBtnSts_prev != REL_DW.SI_b_DoorInBtnSts_start) &&
        REL_DW.SI_b_DoorInBtnSts_start) {
      REL_DW.is_SwValid = REL_IN_Once_b;
      REL_DW.temporalCounter_i4 = 0U;
    }
    break;

   case REL_IN_Once_b:
    if ((*SI_b_DoorInBtnSts_prev != REL_DW.SI_b_DoorInBtnSts_start) &&
        REL_DW.SI_b_DoorInBtnSts_start) {
      REL_DW.is_SwValid = REL_IN_Twice_i;
      REL_DW.temporalCounter_i4 = 0U;
      REL_DW.SL_b_DoorInBtnValid = true;
    } else if (REL_DW.temporalCounter_i4 >= 200) {
      REL_DW.is_SwValid = REL_IN_Idle_d;
      REL_DW.SL_b_DoorInBtnValid = false;
    }
    break;

   default:
    /* case IN_Twice: */
    if (REL_DW.temporalCounter_i4 >= 3) {
      REL_DW.is_SwValid = REL_IN_Idle_d;
      REL_DW.SL_b_DoorInBtnValid = false;
    }
    break;
  }

  if (REL_DW.is_RlsReq == REL_IN_Idle_d) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion13'
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     */
    if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) || (*DataTypeConversion14 ==
          Gear_P)) && ((*SL_b_DoorInBtnValid_prev !=
                        REL_DW.SL_b_DoorInBtnValid_start) &&
                       REL_DW.SL_b_DoorInBtnValid_start)) {
      REL_DW.is_RlsReq = REL_IN_Trigger_o;
      switch (*DataTypeConversion13) {
       case Door_Lock:
        REL_DW.is_Trigger = REL_IN_DoorLock_k;
        REL_DW.is_DoorLock = REL_IN_UnlockReq_o;
        REL_DW.temporalCounter_i1_k = 0U;
        REL_B.SO_m_UnlockReq_p = Unlock_Req;
        break;

       case Door_Unlock:
        REL_DW.is_Trigger = REL_IN_DoorUnlock_i;
        break;

       default:
        REL_DW.is_Trigger = REL_IN_Error_g;
        break;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion13'
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg'
     */
    /* case IN_Trigger: */
  } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) && (*DataTypeConversion14
    != Gear_P)) || ((*DataTypeConversion13 == Door_Unlock) &&
                    (*SO_m_FRDoorRatSts == Rat_Unlock))) {
    REL_DW.is_DoorLock = REL_IN_NO_ACTIVE_CHILD_b;
    REL_DW.is_Trigger = REL_IN_NO_ACTIVE_CHILD_b;
    REL_DW.is_RlsReq = REL_IN_Idle_d;
  } else {
    switch (REL_DW.is_Trigger) {
     case REL_IN_DoorLock_k:
      switch (REL_DW.is_DoorLock) {
       case REL_IN_UnlockFail_d:
        REL_DW.is_DoorLock = REL_IN_NO_ACTIVE_CHILD_b;
        REL_DW.is_Trigger = REL_IN_NO_ACTIVE_CHILD_b;
        REL_DW.is_RlsReq = REL_IN_Idle_d;
        break;

       case REL_IN_UnlockReq_o:
        if (*DataTypeConversion13 == Door_Unlock) {
          REL_DW.is_DoorLock = REL_IN_UnlockSuccess_k;
        } else if ((REL_DW.temporalCounter_i1_k >= 50) && (*DataTypeConversion13
                    == Door_Lock)) {
          REL_DW.is_DoorLock = REL_IN_UnlockFail_d;
        } else if (REL_DW.temporalCounter_i1_k == 5) {
          REL_B.SO_m_UnlockReq_p = Unlock_Idle;
        }
        break;

       default:
        /* case IN_UnlockSuccess: */
        if (*SO_m_FRDoorRatSts != Rat_Unlock) {
          REL_DW.is_DoorLock = REL_IN_NO_ACTIVE_CHILD_b;
          REL_DW.is_Trigger = REL_IN_Release_l;
          REL_DW.temporalCounter_i1_k = 0U;
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
          REL_B.SO_e_DoorRlsDelayTime_h = 20U;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock_i:
      if (*SO_m_FRDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger = REL_IN_Release_l;
        REL_DW.temporalCounter_i1_k = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_h = 20U;
      }
      break;

     case REL_IN_Error_g:
      REL_DW.is_Trigger = REL_IN_NO_ACTIVE_CHILD_b;
      REL_DW.is_RlsReq = REL_IN_Idle_d;
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i1_k >= 5) {
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_B.SO_e_DoorRlsDelayTime_h = 0U;
        REL_DW.is_Trigger = REL_IN_NO_ACTIVE_CHILD_b;
        REL_DW.is_RlsReq = REL_IN_Idle_d;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/FRDoorRlsReq' */
static void REL_DoorHndBtn_d(const boolean_T *LogicalOperator, const boolean_T
  *SI_b_DoorHndBtnSts_prev, const boolean_T *SL_b_DoorHndBtnValid_prev, const
  Gear_Posn_E *DataTypeConversion14, const Rat_Sts_E *SO_m_FRDoorRatSts, const
  Door_Sts_E *DataTypeConversion13)
{
  if (REL_DW.is_RlsReq_a == REL_IN_Idle_d) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion13'
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VbOUT_DHM_BdcPassDoorHandButtonSts_flg_VbOUT_DHM_BdcPassDoorHandButtonSts_flg'
     */
    if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) || (*DataTypeConversion14 ==
          Gear_P)) && (!REL_U.VbOUT_DHM_BdcPassDoorHandButton) &&
        (*LogicalOperator) && ((*SL_b_DoorHndBtnValid_prev !=
          REL_DW.SL_b_DoorHndBtnValid_start) &&
         REL_DW.SL_b_DoorHndBtnValid_start)) {
      REL_DW.is_RlsReq_a = REL_IN_Trigger_o;
      switch (*DataTypeConversion13) {
       case Door_Lock:
        REL_DW.is_Trigger_m = REL_IN_DoorLock_k;
        REL_DW.is_DoorLock_l = REL_IN_UnlockReq_o;
        REL_DW.temporalCounter_i2 = 0U;
        REL_B.SO_m_UnlockReq_p = Unlock_PE;
        break;

       case Door_Unlock:
        REL_DW.is_Trigger_m = REL_IN_DoorUnlock_i;
        break;

       default:
        REL_DW.is_Trigger_m = REL_IN_Error_g;
        break;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion13'
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VbOUT_DHM_BdcPassDoorHandButtonSts_flg_VbOUT_DHM_BdcPassDoorHandButtonSts_flg'
     *  Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg'
     */
    /* case IN_Trigger: */
  } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) && (*DataTypeConversion14
    != Gear_P)) || REL_U.VbOUT_DHM_BdcPassDoorHandButton ||
             ((*DataTypeConversion13 == Door_Unlock) && (*SO_m_FRDoorRatSts ==
               Rat_Unlock))) {
    REL_DW.is_DoorLock_l = REL_IN_NO_ACTIVE_CHILD_b;
    REL_DW.is_Trigger_m = REL_IN_NO_ACTIVE_CHILD_b;
    REL_DW.is_RlsReq_a = REL_IN_Idle_d;
  } else {
    switch (REL_DW.is_Trigger_m) {
     case REL_IN_DoorLock_k:
      switch (REL_DW.is_DoorLock_l) {
       case REL_IN_UnlockFail_d:
        REL_DW.is_DoorLock_l = REL_IN_NO_ACTIVE_CHILD_b;
        REL_DW.is_Trigger_m = REL_IN_NO_ACTIVE_CHILD_b;
        REL_DW.is_RlsReq_a = REL_IN_Idle_d;
        break;

       case REL_IN_UnlockReq_o:
        if (*DataTypeConversion13 == Door_Unlock) {
          REL_DW.is_DoorLock_l = REL_IN_UnlockSuccess_k;
        } else if ((REL_DW.temporalCounter_i2 >= 50) && (*DataTypeConversion13 ==
                    Door_Lock)) {
          REL_DW.is_DoorLock_l = REL_IN_UnlockFail_d;
        } else if (REL_DW.temporalCounter_i2 == 5) {
          REL_B.SO_m_UnlockReq_p = Unlock_Idle;
        }
        break;

       default:
        /* case IN_UnlockSuccess: */
        if (*SO_m_FRDoorRatSts != Rat_Unlock) {
          REL_DW.is_DoorLock_l = REL_IN_NO_ACTIVE_CHILD_b;
          REL_DW.is_Trigger_m = REL_IN_Release_l;
          REL_DW.temporalCounter_i2 = 0U;
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock_i:
      if (*SO_m_FRDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_m = REL_IN_Release_l;
        REL_DW.temporalCounter_i2 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
      }
      break;

     case REL_IN_Error_g:
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i2 >= 5) {
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_DW.is_Trigger_m = REL_IN_NO_ACTIVE_CHILD_b;
        REL_DW.is_RlsReq_a = REL_IN_Idle_d;
      }
      break;
    }
  }

  switch (REL_DW.is_SwValid_d) {
   case REL_IN_Idle_d:
    if ((*SI_b_DoorHndBtnSts_prev != REL_DW.SI_b_DoorHndBtnSts_start) &&
        REL_DW.SI_b_DoorHndBtnSts_start) {
      REL_DW.is_SwValid_d = REL_IN_Press_p;
      REL_DW.temporalCounter_i6 = 0U;
    }
    break;

   case REL_IN_Press_p:
    if ((*SI_b_DoorHndBtnSts_prev != REL_DW.SI_b_DoorHndBtnSts_start) &&
        (!REL_DW.SI_b_DoorHndBtnSts_start)) {
      REL_DW.is_SwValid_d = REL_IN_Release_lhf;
      REL_DW.temporalCounter_i6 = 0U;
      REL_DW.SL_b_DoorHndBtnValid = true;
    } else if (REL_DW.temporalCounter_i6 >= 100) {
      REL_DW.is_SwValid_d = REL_IN_Idle_d;
      REL_DW.SL_b_DoorHndBtnValid = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (REL_DW.temporalCounter_i6 >= 3) {
      REL_DW.is_SwValid_d = REL_IN_Idle_d;
      REL_DW.SL_b_DoorHndBtnValid = false;
    }
    break;
  }
}

/* Function for Chart: '<S3>/FRDoorRlsReq' */
static void REL_CentDoorBtn_ew(const boolean_T *Compare, const boolean_T
  *SL_b_CentSingleDoorBtnValid_pre, const boolean_T
  *SL_b_CentAllDoorBtnValid_prev, const Gear_Posn_E *DataTypeConversion14, const
  Rat_Sts_E *SO_m_FRDoorRatSts, const Door_Sts_E *DataTypeConversion13)
{
  if (REL_DW.is_DoorCentral == REL_IN_Idle_d) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion13'
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     */
    if ((!*Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                         (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                        (*DataTypeConversion14 == Gear_P)) &&
        (((*SL_b_CentSingleDoorBtnValid_pre !=
           REL_DW.SL_b_CentSingleDoorBtnValid_sta) &&
          REL_DW.SL_b_CentSingleDoorBtnValid_sta) ||
         ((*SL_b_CentAllDoorBtnValid_prev !=
           REL_DW.SL_b_CentAllDoorBtnValid_start) &&
          REL_DW.SL_b_CentAllDoorBtnValid_start))) {
      REL_DW.is_DoorCentral = REL_IN_Trigger_o;
      switch (*DataTypeConversion13) {
       case Door_Lock:
        REL_DW.is_Trigger_p = REL_IN_DoorLock_k;
        REL_DW.is_DoorLock_b = REL_IN_UnlockReq_o;
        REL_DW.temporalCounter_i3 = 0U;
        REL_B.SO_m_UnlockReq_p = Unlock_Req;
        break;

       case Door_Unlock:
        REL_DW.is_Trigger_p = REL_IN_DoorUnlock_i;
        break;

       default:
        REL_DW.is_Trigger_p = REL_IN_Error_g;
        break;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion13'
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg'
     */
    /* case IN_Trigger: */
  } else if ((*Compare) || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) && (*DataTypeConversion14
    != Gear_P)) || ((*DataTypeConversion13 == Door_Unlock) &&
                    (*SO_m_FRDoorRatSts == Rat_Unlock))) {
    REL_DW.is_DoorLock_b = REL_IN_NO_ACTIVE_CHILD_b;
    REL_DW.is_Trigger_p = REL_IN_NO_ACTIVE_CHILD_b;
    REL_DW.is_DoorCentral = REL_IN_Idle_d;
  } else {
    switch (REL_DW.is_Trigger_p) {
     case REL_IN_DoorLock_k:
      switch (REL_DW.is_DoorLock_b) {
       case REL_IN_UnlockFail_d:
        REL_DW.is_DoorLock_b = REL_IN_NO_ACTIVE_CHILD_b;
        REL_DW.is_Trigger_p = REL_IN_NO_ACTIVE_CHILD_b;
        REL_DW.is_DoorCentral = REL_IN_Idle_d;
        break;

       case REL_IN_UnlockReq_o:
        if (*DataTypeConversion13 == Door_Unlock) {
          REL_DW.is_DoorLock_b = REL_IN_UnlockSucess_j;
        } else if ((REL_DW.temporalCounter_i3 >= 50) && (*DataTypeConversion13 ==
                    Door_Lock)) {
          REL_DW.is_DoorLock_b = REL_IN_UnlockFail_d;
        } else if (REL_DW.temporalCounter_i3 == 5) {
          REL_B.SO_m_UnlockReq_p = Unlock_Idle;
        }
        break;

       default:
        /* case IN_UnlockSucess: */
        if (*SO_m_FRDoorRatSts != Rat_Unlock) {
          REL_DW.is_DoorLock_b = REL_IN_NO_ACTIVE_CHILD_b;
          REL_DW.is_Trigger_p = REL_IN_RELEASE_k;
          REL_DW.temporalCounter_i3 = 0U;
          REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock_i:
      if (*SO_m_FRDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_p = REL_IN_RELEASE_k;
        REL_DW.temporalCounter_i3 = 0U;
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
      }
      break;

     case REL_IN_Error_g:
      REL_DW.is_Trigger_p = REL_IN_NO_ACTIVE_CHILD_b;
      REL_DW.is_DoorCentral = REL_IN_Idle_d;
      break;

     default:
      /* case IN_RELEASE: */
      if (REL_DW.temporalCounter_i3 >= 5) {
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
        REL_DW.is_Trigger_p = REL_IN_NO_ACTIVE_CHILD_b;
        REL_DW.is_DoorCentral = REL_IN_Idle_d;
      }
      break;
    }
  }

  /* Inport: '<Root>/VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg' */
  REL_DW.SL_b_CentSingleDoorBtnValid = REL_U.VbINP_CAN_CdcPassDoorButtonSts_;

  /* Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg' */
  REL_DW.SL_b_CentAllDoorBtnValid = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
}

/* Function for Chart: '<S3>/Unlock_Request' */
static real_T REL_GetDrvUnlockReq(void)
{
  real_T req;
  switch (REL_B.SO_m_UnlockReq_j) {
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
static real_T REL_GetPassUnlockReq(void)
{
  real_T req;
  if ((REL_B.SO_m_UnlockReq_p == Unlock_PE) || (REL_B.SO_m_UnlockReq_f ==
       Unlock_PE) || (REL_B.SO_m_UnlockReq == Unlock_PE)) {
    req = 2.0;
  } else {
    req = ((REL_B.SO_m_UnlockReq_p == Unlock_Req) || (REL_B.SO_m_UnlockReq_f ==
            Unlock_Req) || (REL_B.SO_m_UnlockReq == Unlock_Req));
  }

  return req;
}

/* Model step function for TID1 */
void REL_Step(void)                    /* Explicit Task: REL_Step */
{
  Door_Sts_E DataTypeConversion12;
  Door_Sts_E DataTypeConversion13;
  Gear_Posn_E DataTypeConversion14;
  HndPos_Sts_E DataTypeConversion15;
  HndPos_Sts_E DataTypeConversion16;
  Rat_Sts_E SO_m_FLDoorRatSts;
  Rat_Sts_E SO_m_FRDoorRatSts;
  Rat_Sts_E SO_m_RLDoorRatSts;
  Rat_Sts_E SO_m_RRDoorRatSts;
  uint8_T SI_e_BleKeyDoorCtrlReq_prev;
  boolean_T Compare;
  boolean_T LogicalOperator;
  boolean_T LogicalOperator1;
  boolean_T SI_b_CrashSts_prev;
  boolean_T SI_b_DoorAutoRlsReq_prev_f;
  boolean_T SI_b_DoorHndBtnSts_prev_f;
  boolean_T SI_b_DoorInBtnSts_prev_j;
  boolean_T SL_b_BleDoorOpenValid_prev_g;
  boolean_T SL_b_CentAllDoorBtnValid_prev_g;
  boolean_T SL_b_CentSingleDoorBtnValid_p_g;
  boolean_T SL_b_DoorHndBtnValid_prev_l;
  boolean_T SL_b_DoorHndPullValid_prev_i;
  boolean_T SL_b_FLDoorInBtnSts;
  boolean_T SL_b_FRDoorInBtnSts;
  boolean_T SL_b_RRDoorInBtnSts;
  boolean_T rtb_Compare_i;

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* DataTypeConversion: '<S3>/Data Type Conversion14' incorporates:
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   */
  DataTypeConversion14 = REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP;

  /* Chart: '<S3>/DoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg'
   *  Inport: '<Root>/VbINP_HWA_FLDoorOpenSW_flg_VbINP_HWA_FLDoorOpenSW_flg'
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   *  Inport: '<Root>/VbINP_HWA_FRDoorOpenSW_flg_VbINP_HWA_FRDoorOpenSW_flg'
   *  Inport: '<Root>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg'
   *  Inport: '<Root>/VbINP_HWA_RLDoorOpenSW_flg_VbINP_HWA_RLDoorOpenSW_flg'
   *  Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg'
   *  Inport: '<Root>/VbINP_HWA_RRDoorOpenSW_flg_VbINP_HWA_RRDoorOpenSW_flg'
   */
  if (REL_DW.is_active_c3_REL == 0U) {
    real_T tmp;
    REL_DW.is_active_c3_REL = 1U;
    tmp = REL_GetDoorRatSts((real_T)REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_,
      (real_T)REL_U.VbINP_HWA_FLDoorOpenSW_flg_VbIN);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8_T)(int32_T)tmp);
      } else {
        SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((real_T)REL_U.VbINP_HWA_RLDoorAjar_flg_VbINP_,
      (real_T)REL_U.VbINP_HWA_FRDoorOpenSW_flg_VbIN);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8_T)(int32_T)tmp);
      } else {
        SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((real_T)REL_U.VbINP_HWA_RRDoorOpenSW_flg_VbIN,
      (real_T)REL_U.VbINP_HWA_FRDoorAjar_flg_VbINP_);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8_T)(int32_T)tmp);
      } else {
        SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((real_T)REL_U.VbINP_HWA_RRDoorAjar_flg_VbINP_,
      (real_T)REL_U.VbINP_HWA_RLDoorOpenSW_flg_VbIN);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8_T)(int32_T)tmp);
      } else {
        SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }
  } else {
    real_T tmp;
    tmp = REL_GetDoorRatSts((real_T)REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_,
      (real_T)REL_U.VbINP_HWA_FLDoorOpenSW_flg_VbIN);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8_T)(int32_T)tmp);
      } else {
        SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((real_T)REL_U.VbINP_HWA_RLDoorAjar_flg_VbINP_,
      (real_T)REL_U.VbINP_HWA_FRDoorOpenSW_flg_VbIN);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8_T)(int32_T)tmp);
      } else {
        SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((real_T)REL_U.VbINP_HWA_RRDoorOpenSW_flg_VbIN,
      (real_T)REL_U.VbINP_HWA_FRDoorAjar_flg_VbINP_);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8_T)(int32_T)tmp);
      } else {
        SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((real_T)REL_U.VbINP_HWA_RRDoorAjar_flg_VbINP_,
      (real_T)REL_U.VbINP_HWA_RLDoorOpenSW_flg_VbIN);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8_T)(int32_T)tmp);
      } else {
        SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      SO_m_RRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }
  }

  /* End of Chart: '<S3>/DoorRatSts' */

  /* DataTypeConversion: '<S3>/Data Type Conversion12' incorporates:
   *  Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig'
   */
  DataTypeConversion12 = REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si;

  /* DataTypeConversion: '<S3>/Data Type Conversion13' incorporates:
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   */
  DataTypeConversion13 = REL_U.VeOUT_DLK_BCMPassengerDoorLockS;

  /* Chart: '<S3>/BleOpenAndClsDoorRsp' incorporates:
   *  Inport: '<Root>/VeINP_BLE_BDCBleKeyDoorCtrRequest_sig_VeINP_BLE_BDCBleKeyDoorCtrRequest_sig'
   */
  if (REL_DW.temporalCounter_i1_h < 1023U) {
    REL_DW.temporalCounter_i1_h++;
  }

  SI_e_BleKeyDoorCtrlReq_prev = REL_DW.SI_e_BleKeyDoorCtrlReq_start;
  REL_DW.SI_e_BleKeyDoorCtrlReq_start = REL_U.VeINP_BLE_BDCBleKeyDoorCtrReque;
  if (REL_DW.is_active_c4_REL == 0U) {
    REL_DW.is_active_c4_REL = 1U;
    REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_Idle_i;
    REL_DW.temporalCounter_i1_h = 0U;
  } else if (SI_e_BleKeyDoorCtrlReq_prev != REL_DW.SI_e_BleKeyDoorCtrlReq_start)
  {
    REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_Idle_i;
    REL_DW.temporalCounter_i1_h = 0U;
  } else {
    boolean_T guard1 = false;
    boolean_T guard10 = false;
    boolean_T guard2 = false;
    boolean_T guard3 = false;
    boolean_T guard4 = false;
    boolean_T guard5 = false;
    boolean_T guard6 = false;
    boolean_T guard7 = false;
    boolean_T guard8 = false;
    boolean_T guard9 = false;
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    guard5 = false;
    guard6 = false;
    guard7 = false;
    guard8 = false;
    guard9 = false;
    guard10 = false;
    switch (REL_DW.is_BleOpenAndClsDoorRsp) {
     case REL_IN_ClsFLDoorsReq:
      if (DataTypeConversion14 == Gear_P) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyClsDoorRsp_sig_VeOUT_REL_BDCBleKeyClsDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyClsDoorRsp_s = 3U;
        guard2 = true;
      } else if (SO_m_FLDoorRatSts == Rat_All_Lock) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyClsDoorRsp_sig_VeOUT_REL_BDCBleKeyClsDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyClsDoorRsp_s = 1U;
        guard2 = true;
      } else if (REL_DW.temporalCounter_i1_h >= 550) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyClsDoorRsp_sig_VeOUT_REL_BDCBleKeyClsDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyClsDoorRsp_s = 2U;
        guard2 = true;
      }
      break;

     case REL_IN_ClsFRDoorsReq:
      if (DataTypeConversion14 == Gear_P) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyClsDoorRsp_sig_VeOUT_REL_BDCBleKeyClsDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyClsDoorRsp_s = 3U;
        guard3 = true;
      } else if (SO_m_FRDoorRatSts == Rat_All_Lock) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyClsDoorRsp_sig_VeOUT_REL_BDCBleKeyClsDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyClsDoorRsp_s = 1U;
        guard3 = true;
      } else if (REL_DW.temporalCounter_i1_h >= 550) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyClsDoorRsp_sig_VeOUT_REL_BDCBleKeyClsDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyClsDoorRsp_s = 2U;
        guard3 = true;
      }
      break;

     case REL_IN_ClsFourDoorsReq:
      if (DataTypeConversion14 == Gear_P) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyClsDoorRsp_sig_VeOUT_REL_BDCBleKeyClsDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyClsDoorRsp_s = 3U;
        guard4 = true;
      } else if ((SO_m_FLDoorRatSts == Rat_All_Lock) && (SO_m_FRDoorRatSts ==
                  Rat_All_Lock) && (SO_m_RLDoorRatSts == Rat_All_Lock) &&
                 (SO_m_RRDoorRatSts == Rat_All_Lock)) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyClsDoorRsp_sig_VeOUT_REL_BDCBleKeyClsDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyClsDoorRsp_s = 1U;
        guard4 = true;
      } else if (REL_DW.temporalCounter_i1_h >= 550) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyClsDoorRsp_sig_VeOUT_REL_BDCBleKeyClsDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyClsDoorRsp_s = 2U;
        guard4 = true;
      }
      break;

     case REL_IN_ClsRLDoorsReq:
      if (DataTypeConversion14 == Gear_P) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyClsDoorRsp_sig_VeOUT_REL_BDCBleKeyClsDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyClsDoorRsp_s = 3U;
        guard5 = true;
      } else if (SO_m_RLDoorRatSts == Rat_All_Lock) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyClsDoorRsp_sig_VeOUT_REL_BDCBleKeyClsDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyClsDoorRsp_s = 1U;
        guard5 = true;
      } else if (REL_DW.temporalCounter_i1_h >= 550) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyClsDoorRsp_sig_VeOUT_REL_BDCBleKeyClsDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyClsDoorRsp_s = 2U;
        guard5 = true;
      }
      break;

     case REL_IN_ClsRRDoorsReq:
      if (DataTypeConversion14 == Gear_P) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyClsDoorRsp_sig_VeOUT_REL_BDCBleKeyClsDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyClsDoorRsp_s = 3U;
        guard6 = true;
      } else if (SO_m_RRDoorRatSts == Rat_All_Lock) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyClsDoorRsp_sig_VeOUT_REL_BDCBleKeyClsDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyClsDoorRsp_s = 1U;
        guard6 = true;
      } else if (REL_DW.temporalCounter_i1_h >= 550) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyClsDoorRsp_sig_VeOUT_REL_BDCBleKeyClsDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyClsDoorRsp_s = 2U;
        guard6 = true;
      }
      break;

     case REL_IN_Idle_i:
      if ((SI_e_BleKeyDoorCtrlReq_prev != REL_DW.SI_e_BleKeyDoorCtrlReq_start) &&
          (REL_DW.SI_e_BleKeyDoorCtrlReq_start == 9)) {
        REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_OpenFourDoorsReq;
        REL_DW.temporalCounter_i1_h = 0U;
      } else if ((SI_e_BleKeyDoorCtrlReq_prev !=
                  REL_DW.SI_e_BleKeyDoorCtrlReq_start) &&
                 (REL_DW.SI_e_BleKeyDoorCtrlReq_start == 7)) {
        REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_OpenRRDoorsReq;
        REL_DW.temporalCounter_i1_h = 0U;
      } else if ((SI_e_BleKeyDoorCtrlReq_prev !=
                  REL_DW.SI_e_BleKeyDoorCtrlReq_start) &&
                 (REL_DW.SI_e_BleKeyDoorCtrlReq_start == 6)) {
        REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_ClsRRDoorsReq;
        REL_DW.temporalCounter_i1_h = 0U;
      } else if ((SI_e_BleKeyDoorCtrlReq_prev !=
                  REL_DW.SI_e_BleKeyDoorCtrlReq_start) &&
                 (REL_DW.SI_e_BleKeyDoorCtrlReq_start == 6)) {
        REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_ClsRLDoorsReq;
        REL_DW.temporalCounter_i1_h = 0U;
      } else if ((SI_e_BleKeyDoorCtrlReq_prev !=
                  REL_DW.SI_e_BleKeyDoorCtrlReq_start) &&
                 (REL_DW.SI_e_BleKeyDoorCtrlReq_start == 4)) {
        REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_ClsFRDoorsReq;
        REL_DW.temporalCounter_i1_h = 0U;
      } else if ((SI_e_BleKeyDoorCtrlReq_prev !=
                  REL_DW.SI_e_BleKeyDoorCtrlReq_start) &&
                 (REL_DW.SI_e_BleKeyDoorCtrlReq_start == 2)) {
        REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_ClsFLDoorsReq;
        REL_DW.temporalCounter_i1_h = 0U;
      } else if ((SI_e_BleKeyDoorCtrlReq_prev !=
                  REL_DW.SI_e_BleKeyDoorCtrlReq_start) &&
                 (REL_DW.SI_e_BleKeyDoorCtrlReq_start == 10)) {
        REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_ClsFourDoorsReq;
        REL_DW.temporalCounter_i1_h = 0U;
      } else if ((SI_e_BleKeyDoorCtrlReq_prev !=
                  REL_DW.SI_e_BleKeyDoorCtrlReq_start) &&
                 (REL_DW.SI_e_BleKeyDoorCtrlReq_start == 5)) {
        REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_OpenRLDoorsReq;
        REL_DW.temporalCounter_i1_h = 0U;
      } else if ((SI_e_BleKeyDoorCtrlReq_prev !=
                  REL_DW.SI_e_BleKeyDoorCtrlReq_start) &&
                 (REL_DW.SI_e_BleKeyDoorCtrlReq_start == 3)) {
        REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_OpenFRDoorsReq;
        REL_DW.temporalCounter_i1_h = 0U;
      } else if ((SI_e_BleKeyDoorCtrlReq_prev !=
                  REL_DW.SI_e_BleKeyDoorCtrlReq_start) &&
                 (REL_DW.SI_e_BleKeyDoorCtrlReq_start == 1)) {
        REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_OpenFLDoorsReq;
        REL_DW.temporalCounter_i1_h = 0U;
      } else if (REL_DW.temporalCounter_i1_h >= 5) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyOpenDoorRsp_sig_VeOUT_REL_BDCBleKeyOpenDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyOpenDoorRsp_ = 0U;

        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyClsDoorRsp_sig_VeOUT_REL_BDCBleKeyClsDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyClsDoorRsp_s = 0U;
      }
      break;

     case REL_IN_OpenFLDoorsReq:
      if (DataTypeConversion14 == Gear_P) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyOpenDoorRsp_sig_VeOUT_REL_BDCBleKeyOpenDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyOpenDoorRsp_ = 3U;
        guard7 = true;
      } else if (DataTypeConversion12 == Door_Lock) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyOpenDoorRsp_sig_VeOUT_REL_BDCBleKeyOpenDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyOpenDoorRsp_ = 2U;
        guard7 = true;
      } else if (SO_m_FLDoorRatSts == Rat_Unlock) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyOpenDoorRsp_sig_VeOUT_REL_BDCBleKeyOpenDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyOpenDoorRsp_ = 1U;
        guard7 = true;
      } else if (REL_DW.temporalCounter_i1_h >= 100) {
        guard7 = true;
      }
      break;

     case REL_IN_OpenFRDoorsReq:
      if (DataTypeConversion14 == Gear_P) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyOpenDoorRsp_sig_VeOUT_REL_BDCBleKeyOpenDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyOpenDoorRsp_ = 3U;
        guard8 = true;
      } else if (DataTypeConversion13 == Door_Lock) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyOpenDoorRsp_sig_VeOUT_REL_BDCBleKeyOpenDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyOpenDoorRsp_ = 2U;
        guard8 = true;
      } else if (SO_m_FRDoorRatSts == Rat_Unlock) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyOpenDoorRsp_sig_VeOUT_REL_BDCBleKeyOpenDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyOpenDoorRsp_ = 1U;
        guard8 = true;
      } else if (REL_DW.temporalCounter_i1_h >= 100) {
        guard8 = true;
      }
      break;

     case REL_IN_OpenFourDoorsReq:
      if (DataTypeConversion14 == Gear_P) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyOpenDoorRsp_sig_VeOUT_REL_BDCBleKeyOpenDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyOpenDoorRsp_ = 3U;
        guard9 = true;
      } else if ((DataTypeConversion12 == Door_Lock) && (DataTypeConversion13 ==
                  Door_Lock)) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyOpenDoorRsp_sig_VeOUT_REL_BDCBleKeyOpenDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyOpenDoorRsp_ = 2U;
        guard9 = true;
      } else if ((SO_m_FLDoorRatSts == Rat_Unlock) || (SO_m_FRDoorRatSts ==
                  Rat_Unlock) || (SO_m_RLDoorRatSts == Rat_Unlock) ||
                 (SO_m_RRDoorRatSts == Rat_Unlock)) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyOpenDoorRsp_sig_VeOUT_REL_BDCBleKeyOpenDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyOpenDoorRsp_ = 1U;
        guard9 = true;
      } else if (REL_DW.temporalCounter_i1_h >= 100) {
        guard9 = true;
      }
      break;

     case REL_IN_OpenRLDoorsReq:
      if (DataTypeConversion14 == Gear_P) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyOpenDoorRsp_sig_VeOUT_REL_BDCBleKeyOpenDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyOpenDoorRsp_ = 3U;
        guard10 = true;
      } else if (DataTypeConversion13 == Door_Lock) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyOpenDoorRsp_sig_VeOUT_REL_BDCBleKeyOpenDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyOpenDoorRsp_ = 2U;
        guard10 = true;
      } else if (SO_m_RLDoorRatSts == Rat_Unlock) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyOpenDoorRsp_sig_VeOUT_REL_BDCBleKeyOpenDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyOpenDoorRsp_ = 1U;
        guard10 = true;
      } else if (REL_DW.temporalCounter_i1_h >= 100) {
        guard10 = true;
      }
      break;

     default:
      /* case IN_OpenRRDoorsReq: */
      if (DataTypeConversion14 == Gear_P) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyOpenDoorRsp_sig_VeOUT_REL_BDCBleKeyOpenDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyOpenDoorRsp_ = 3U;
        guard1 = true;
      } else if (DataTypeConversion13 == Door_Lock) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyOpenDoorRsp_sig_VeOUT_REL_BDCBleKeyOpenDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyOpenDoorRsp_ = 2U;
        guard1 = true;
      } else if (SO_m_RRDoorRatSts == Rat_Unlock) {
        /* Outport: '<Root>/VeOUT_REL_BDCBleKeyOpenDoorRsp_sig_VeOUT_REL_BDCBleKeyOpenDoorRsp_sig' */
        REL_Y.VeOUT_REL_BDCBleKeyOpenDoorRsp_ = 1U;
        guard1 = true;
      } else if (REL_DW.temporalCounter_i1_h >= 100) {
        guard1 = true;
      }
      break;
    }

    if (guard10) {
      REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_Idle_i;
      REL_DW.temporalCounter_i1_h = 0U;
    }

    if (guard9) {
      REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_Idle_i;
      REL_DW.temporalCounter_i1_h = 0U;
    }

    if (guard8) {
      REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_Idle_i;
      REL_DW.temporalCounter_i1_h = 0U;
    }

    if (guard7) {
      REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_Idle_i;
      REL_DW.temporalCounter_i1_h = 0U;
    }

    if (guard6) {
      REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_Idle_i;
      REL_DW.temporalCounter_i1_h = 0U;
    }

    if (guard5) {
      REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_Idle_i;
      REL_DW.temporalCounter_i1_h = 0U;
    }

    if (guard4) {
      REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_Idle_i;
      REL_DW.temporalCounter_i1_h = 0U;
    }

    if (guard3) {
      REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_Idle_i;
      REL_DW.temporalCounter_i1_h = 0U;
    }

    if (guard2) {
      REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_Idle_i;
      REL_DW.temporalCounter_i1_h = 0U;
    }

    if (guard1) {
      REL_DW.is_BleOpenAndClsDoorRsp = REL_IN_Idle_i;
      REL_DW.temporalCounter_i1_h = 0U;
    }
  }

  /* End of Chart: '<S3>/BleOpenAndClsDoorRsp' */

  /* Chart: '<S3>/BleReqDirectTransfer' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion14'
   */
  if (REL_DW.is_active_c2_REL == 0U) {
    REL_DW.is_active_c2_REL = 1U;
    if (DataTypeConversion14 == Gear_P) {
      /* Outport: '<Root>/VeOUT_REL_BDCBleKeyDoorCtrRequest_sig_VeOUT_REL_BDCBleKeyDoorCtrRequest_sig' incorporates:
       *  Inport: '<Root>/VeINP_BLE_BDCBleKeyDoorCtrRequest_sig_VeINP_BLE_BDCBleKeyDoorCtrRequest_sig'
       */
      REL_Y.VeOUT_REL_BDCBleKeyDoorCtrReque =
        REL_U.VeINP_BLE_BDCBleKeyDoorCtrReque;
    } else {
      /* Outport: '<Root>/VeOUT_REL_BDCBleKeyDoorCtrRequest_sig_VeOUT_REL_BDCBleKeyDoorCtrRequest_sig' */
      REL_Y.VeOUT_REL_BDCBleKeyDoorCtrReque = 0U;
    }
  } else if (DataTypeConversion14 == Gear_P) {
    /* Outport: '<Root>/VeOUT_REL_BDCBleKeyDoorCtrRequest_sig_VeOUT_REL_BDCBleKeyDoorCtrRequest_sig' incorporates:
     *  Inport: '<Root>/VeINP_BLE_BDCBleKeyDoorCtrRequest_sig_VeINP_BLE_BDCBleKeyDoorCtrRequest_sig'
     */
    REL_Y.VeOUT_REL_BDCBleKeyDoorCtrReque =
      REL_U.VeINP_BLE_BDCBleKeyDoorCtrReque;
  } else {
    /* Outport: '<Root>/VeOUT_REL_BDCBleKeyDoorCtrRequest_sig_VeOUT_REL_BDCBleKeyDoorCtrRequest_sig' */
    REL_Y.VeOUT_REL_BDCBleKeyDoorCtrReque = 0U;
  }

  /* End of Chart: '<S3>/BleReqDirectTransfer' */

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   *  Inport: '<Root>/VeINP_BLE_BDCBleKeyDoorCtrRequest_sig_VeINP_BLE_BDCBleKeyDoorCtrRequest_sig'
   */
  rtb_Compare_i = (REL_U.VeINP_BLE_BDCBleKeyDoorCtrReque == 9);

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

  /* DataTypeConversion: '<S3>/Data Type Conversion15' incorporates:
   *  Inport: '<Root>/VeOUT_DHM_BDCDrvrDoorHndSts_sig_VeOUT_DHM_BDCDrvrDoorHndSts_sig'
   */
  DataTypeConversion15 = REL_U.VeOUT_DHM_BDCDrvrDoorHndSts_sig;

  /* DataTypeConversion: '<S3>/Data Type Conversion16' incorporates:
   *  Inport: '<Root>/VeOUT_DHM_BDCPassDoorHndSts_sig_VeOUT_DHM_BDCPassDoorHndSts_sig'
   */
  DataTypeConversion16 = REL_U.VeOUT_DHM_BDCPassDoorHndSts_sig;

  /* Outport: '<Root>/VeOUT_REL_BcmRiReDoorSwtSts_sig_VeOUT_REL_BcmRiReDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  REL_Y.VeOUT_REL_BcmRiReDoorSwtSts_sig = SL_b_RRDoorInBtnSts;

  /* Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   */
  REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V = SO_m_FLDoorRatSts;

  /* Outport: '<Root>/VeOUT_REL_BcmDrvrDoorSwtSts_sig_VeOUT_REL_BcmDrvrDoorSwtSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   */
  REL_Y.VeOUT_REL_BcmDrvrDoorSwtSts_sig = SL_b_FLDoorInBtnSts;

  /* Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion5'
   */
  REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V = SO_m_FRDoorRatSts;

  /* Outport: '<Root>/VeOUT_REL_BdcLRDoorRatSts_sig_VeOUT_REL_BdcLRDoorRatSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion6'
   */
  REL_Y.VeOUT_REL_BdcLRDoorRatSts_sig_V = SO_m_RLDoorRatSts;

  /* Outport: '<Root>/VeOUT_REL_BdcRRDoorRatSts_sig_VeOUT_REL_BdcRRDoorRatSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   */
  REL_Y.VeOUT_REL_BdcRRDoorRatSts_sig_V = SO_m_RRDoorRatSts;

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
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_m = true;
      REL_DW.SL_e_DoorAutoRlsSetBackup = 1U;
    } else if ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si == 2) ||
               ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si != 1) &&
                (REL_DW.SL_e_DoorAutoRlsSetBackup == 2))) {
      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = false;

      /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
      REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_m = false;
      REL_DW.SL_e_DoorAutoRlsSetBackup = 2U;
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
             ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si != 2) &&
              (REL_DW.SL_e_DoorAutoRlsSetBackup == 1))) {
    /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
    REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = true;

    /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
    REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_m = true;
    REL_DW.SL_e_DoorAutoRlsSetBackup = 1U;
  } else if ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si == 2) ||
             ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si != 1) &&
              (REL_DW.SL_e_DoorAutoRlsSetBackup == 2))) {
    /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
    REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = false;

    /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
    REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_m = false;
    REL_DW.SL_e_DoorAutoRlsSetBackup = 2U;
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

  /* End of Chart: '<S3>/DoorAutoRlsSts' */

  /* RelationalOperator: '<S24>/Compare' incorporates:
   *  Constant: '<S24>/Constant'
   *  Inport: '<Root>/VeOUT_PDU_BcmPowerStatusFeedback_sig_VeOUT_PDU_BcmPowerStatusFeedback_sig'
   */
  Compare = (REL_U.VeOUT_PDU_BcmPowerStatusFeedbac == 0);

  /* Logic: '<S3>/Logical Operator1' incorporates:
   *  Constant: '<S16>/Constant'
   *  Inport: '<Root>/VeINP_BLE_BDCBleKeyDoorCtrRequest_sig_VeINP_BLE_BDCBleKeyDoorCtrRequest_sig'
   *  RelationalOperator: '<S16>/Compare'
   */
  LogicalOperator1 = ((REL_U.VeINP_BLE_BDCBleKeyDoorCtrReque == 1) ||
                      rtb_Compare_i);

  /* Logic: '<S3>/Logical Operator' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S15>/Constant'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  Inport: '<Root>/VeINP_BLE_BleKey1Posn_sig_VeINP_BLE_BleKey1Posn_sig'
   *  Inport: '<Root>/VeINP_BLE_BleKey2Posn_sig_VeINP_BLE_BleKey2Posn_sig'
   *  Inport: '<Root>/VeINP_BLE_BleKey3Posn_sig_VeINP_BLE_BleKey3Posn_sig'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S15>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   */
  LogicalOperator = ((REL_U.VeINP_BLE_BleKey1Posn_sig_VeINP == 1) ||
                     (REL_U.VeINP_BLE_BleKey1Posn_sig_VeINP == 5) ||
                     (REL_U.VeINP_BLE_BleKey2Posn_sig_VeINP == 1) ||
                     (REL_U.VeINP_BLE_BleKey2Posn_sig_VeINP == 5) ||
                     (REL_U.VeINP_BLE_BleKey3Posn_sig_VeINP == 1) ||
                     (REL_U.VeINP_BLE_BleKey3Posn_sig_VeINP == 5));

  /* Chart: '<S3>/FLDoorRlsReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion12'
   *  DataTypeConversion: '<S3>/Data Type Conversion14'
   *  DataTypeConversion: '<S3>/Data Type Conversion15'
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbOUT_DLK_BdcDrvrDoorLockOpenReq_flg_VbOUT_DLK_BdcDrvrDoorLockOpenReq_flg'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg'
   *  Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg'
   */
  if (REL_DW.temporalCounter_i1_m < 63U) {
    REL_DW.temporalCounter_i1_m++;
  }

  if (REL_DW.temporalCounter_i2_i < 63U) {
    REL_DW.temporalCounter_i2_i++;
  }

  if (REL_DW.temporalCounter_i3_g < 63U) {
    REL_DW.temporalCounter_i3_g++;
  }

  if (REL_DW.temporalCounter_i4_d < 255U) {
    REL_DW.temporalCounter_i4_d++;
  }

  if (REL_DW.temporalCounter_i5_p < 7U) {
    REL_DW.temporalCounter_i5_p++;
  }

  if (REL_DW.temporalCounter_i6_d < 127U) {
    REL_DW.temporalCounter_i6_d++;
  }

  if (REL_DW.temporalCounter_i7_p < 7U) {
    REL_DW.temporalCounter_i7_p++;
  }

  if (REL_DW.temporalCounter_i8_h < 7U) {
    REL_DW.temporalCounter_i8_h++;
  }

  SI_b_DoorInBtnSts_prev_j = REL_DW.SI_b_DoorInBtnSts_start_b;
  REL_DW.SI_b_DoorInBtnSts_start_b = SL_b_FLDoorInBtnSts;
  SL_b_FLDoorInBtnSts = REL_DW.SL_b_DoorInBtnValid_start_m;
  REL_DW.SL_b_DoorInBtnValid_start_m = REL_DW.SL_b_DoorInBtnValid_e;
  SL_b_DoorHndPullValid_prev_i = REL_DW.SL_b_DoorHndPullValid_start_f;
  REL_DW.SL_b_DoorHndPullValid_start_f = REL_DW.SL_b_DoorHndPullValid_b;
  SI_b_DoorHndBtnSts_prev_f = REL_DW.SI_b_DoorHndBtnSts_start_i;
  REL_DW.SI_b_DoorHndBtnSts_start_i = REL_Y.VbOUT_REL_FLDoorHndlBtnSig_flg_;
  SL_b_DoorHndBtnValid_prev_l = REL_DW.SL_b_DoorHndBtnValid_start_d;
  REL_DW.SL_b_DoorHndBtnValid_start_d = REL_DW.SL_b_DoorHndBtnValid_f;
  SL_b_CentSingleDoorBtnValid_p_g = REL_DW.SL_b_CentSingleDoorBtnValid_s_d;
  REL_DW.SL_b_CentSingleDoorBtnValid_s_d = REL_DW.SL_b_CentSingleDoorBtnValid_k;
  SL_b_CentAllDoorBtnValid_prev_g = REL_DW.SL_b_CentAllDoorBtnValid_star_l;
  REL_DW.SL_b_CentAllDoorBtnValid_star_l = REL_DW.SL_b_CentAllDoorBtnValid_a;
  SI_b_DoorAutoRlsReq_prev_f = REL_DW.SI_b_DoorAutoRlsReq_start_h;
  REL_DW.SI_b_DoorAutoRlsReq_start_h = REL_U.VbOUT_DLK_BdcDrvrDoorLockOpenRe;
  SL_b_BleDoorOpenValid_prev_g = REL_DW.SL_b_BleDoorOpenValid_start_g;
  REL_DW.SL_b_BleDoorOpenValid_start_g = REL_DW.SL_b_BleDoorOpenValid_k;
  if (REL_DW.is_active_c5_DoorRlsReq_b == 0U) {
    REL_DW.is_active_c5_DoorRlsReq_b = 1U;
    REL_DW.is_SwValid_j = REL_IN_Idle_d;
    REL_DW.SL_b_DoorInBtnValid_e = false;
    REL_DW.is_RlsReq_p = REL_IN_Idle_d;
    REL_DW.SL_b_DoorHndPullValid_b = REL_Y.VbOUT_REL_BcmDrvrDoorHandleReq_;
    REL_DW.is_RlsReq_jz = REL_IN_Idle_d;
    REL_DW.is_RlsReq_b3 = REL_IN_Idle_d;
    REL_DW.is_SwValid_b = REL_IN_Idle_d;
    REL_DW.SL_b_DoorHndBtnValid_f = false;
    REL_DW.is_DoorCentral_l = REL_IN_Idle_d;
    REL_DW.SL_b_CentSingleDoorBtnValid_k = REL_U.VbINP_CAN_CdcDrvrDoorButtonSts_;
    REL_DW.SL_b_CentAllDoorBtnValid_a = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
    REL_DW.is_RlsReq_jc = REL_IN_Idle_d;
    REL_DW.SL_b_BleDoorOpenValid_k = LogicalOperator1;
    REL_DW.is_RlsReq_c = REL_IN_Idle_d;
  } else {
    REL_DoorInBtn_j(&SI_b_DoorInBtnSts_prev_j, &SL_b_FLDoorInBtnSts,
                    &DataTypeConversion14, &SO_m_FLDoorRatSts,
                    &DataTypeConversion12);
    REL_DW.SL_b_DoorHndPullValid_b = REL_Y.VbOUT_REL_BcmDrvrDoorHandleReq_;
    if (REL_DW.is_RlsReq_jz == REL_IN_Idle_d) {
      if ((!Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                         (DataTypeConversion14 == Gear_P)) &&
          (DataTypeConversion12 == Door_Unlock) && (DataTypeConversion15 ==
           Hnd_Unfold) && ((SL_b_DoorHndPullValid_prev_i !=
                            REL_DW.SL_b_DoorHndPullValid_start_f) &&
                           REL_DW.SL_b_DoorHndPullValid_start_f)) {
        REL_DW.is_RlsReq_jz = REL_IN_Trigger_o;
        REL_DW.is_Trigger_b = REL_IN_DoorUnlock_i4;
      }

      /* case IN_Trigger: */
    } else if (Compare || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                           (DataTypeConversion14 != Gear_P)) ||
               (DataTypeConversion12 != Door_Unlock) || (DataTypeConversion15 !=
                Hnd_Unfold) || (SO_m_FLDoorRatSts == Rat_Unlock)) {
      REL_DW.is_Trigger_b = REL_IN_NO_ACTIVE_CHILD_b;
      REL_DW.is_RlsReq_jz = REL_IN_Idle_d;
    } else if (REL_DW.is_Trigger_b == REL_IN_DoorUnlock_i4) {
      if (SO_m_FLDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_b = REL_IN_Release_lh;
        REL_DW.temporalCounter_i5_p = 0U;

        /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_k = 4U;
      }

      /* case IN_Release: */
    } else if (REL_DW.temporalCounter_i5_p >= 5) {
      /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
      REL_B.SO_e_DoorRlsDelayTime_k = 0U;
      REL_DW.is_Trigger_b = REL_IN_NO_ACTIVE_CHILD_b;
      REL_DW.is_RlsReq_jz = REL_IN_Idle_d;
    }

    REL_DoorHndBtn_a(&LogicalOperator, &SI_b_DoorHndBtnSts_prev_f,
                     &SL_b_DoorHndBtnValid_prev_l, &DataTypeConversion14,
                     &SO_m_FLDoorRatSts, &DataTypeConversion12);
    REL_CentDoorBtn_e(&Compare, &SL_b_CentSingleDoorBtnValid_p_g,
                      &SL_b_CentAllDoorBtnValid_prev_g, &DataTypeConversion14,
                      &SO_m_FLDoorRatSts, &DataTypeConversion12);
    if (REL_DW.is_RlsReq_jc == REL_IN_Idle_d) {
      if ((!Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                         (DataTypeConversion14 == Gear_P)) &&
          REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts && (DataTypeConversion12 ==
           Door_Unlock) && ((SI_b_DoorAutoRlsReq_prev_f !=
                             REL_DW.SI_b_DoorAutoRlsReq_start_h) &&
                            REL_DW.SI_b_DoorAutoRlsReq_start_h)) {
        REL_DW.is_RlsReq_jc = REL_IN_Trigger_o;
        REL_DW.is_Trigger_k = REL_IN_DoorUnlock_i4;
      }

      /* case IN_Trigger: */
    } else if (Compare || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                           (DataTypeConversion14 != Gear_P)) ||
               (!REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts) || (DataTypeConversion12
                != Door_Unlock) || (SO_m_FLDoorRatSts == Rat_Unlock)) {
      REL_DW.is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_b;
      REL_DW.is_RlsReq_jc = REL_IN_Idle_d;
    } else if (REL_DW.is_Trigger_k == REL_IN_DoorUnlock_i4) {
      if (SO_m_FLDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_k = REL_IN_Release_lh;
        REL_DW.temporalCounter_i7_p = 0U;

        /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
      }

      /* case IN_Release: */
    } else if (REL_DW.temporalCounter_i7_p >= 5) {
      /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
      REL_DW.is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_b;
      REL_DW.is_RlsReq_jc = REL_IN_Idle_d;
    }

    REL_DW.SL_b_BleDoorOpenValid_k = LogicalOperator1;
    if (REL_DW.is_RlsReq_c == REL_IN_Idle_d) {
      if ((!Compare) && ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                         (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) &&
          (DataTypeConversion14 == Gear_P) && (DataTypeConversion12 ==
           Door_Unlock) && ((SL_b_BleDoorOpenValid_prev_g !=
                             REL_DW.SL_b_BleDoorOpenValid_start_g) &&
                            REL_DW.SL_b_BleDoorOpenValid_start_g)) {
        REL_DW.is_RlsReq_c = REL_IN_Trigger_o;
        REL_DW.is_Trigger_go = REL_IN_DoorUnlock_i4;
      }

      /* case IN_Trigger: */
    } else if (Compare || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
               (DataTypeConversion14 != Gear_P) || (DataTypeConversion12 !=
                Door_Unlock) || (SO_m_FLDoorRatSts == Rat_Unlock)) {
      REL_DW.is_Trigger_go = REL_IN_NO_ACTIVE_CHILD_b;
      REL_DW.is_RlsReq_c = REL_IN_Idle_d;
    } else if (REL_DW.is_Trigger_go == REL_IN_DoorUnlock_i4) {
      if (SO_m_FLDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_go = REL_IN_Release_lh;
        REL_DW.temporalCounter_i8_h = 0U;

        /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = true;
      }

      /* case IN_Release: */
    } else if (REL_DW.temporalCounter_i8_h >= 5) {
      /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;
      REL_DW.is_Trigger_go = REL_IN_NO_ACTIVE_CHILD_b;
      REL_DW.is_RlsReq_c = REL_IN_Idle_d;
    }
  }

  /* End of Chart: '<S3>/FLDoorRlsReq' */

  /* Chart: '<S3>/FLDoorRlsDriver' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg'
   *  Inport: '<Root>/VbINP_HWA_FLDoorOpenSW_flg_VbINP_HWA_FLDoorOpenSW_flg'
   *  Inport: '<Root>/VeINP_HWA_Voltage_100mV_VeINP_HWA_Voltage_100mV'
   *  Outport: '<Root>/VbOUT_REL_FLDoorMotorErrSts_flg_VbOUT_REL_FLDoorMotorErrSts_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_FLDoorMotorCmd_sig_VeOUT_REL_FLDoorMotorCmd_sig'
   *  Outport: '<Root>/VeOUT_REL_FLDoorMotorPWM_pct_VeOUT_REL_FLDoorMotorPWM_pct'
   */
  REL_FLDoorRlsDriver(REL_U.VeINP_HWA_Voltage_100mV_VeINP_H,
                      REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU,
                      REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_,
                      REL_U.VbINP_HWA_FLDoorOpenSW_flg_VbIN,
                      REL_B.SO_e_DoorRlsDelayTime_k,
                      &REL_Y.VeOUT_REL_FLDoorMotorCmd_sig_Ve,
                      &REL_Y.VeOUT_REL_FLDoorMotorPWM_pct_Ve,
                      &REL_Y.VbOUT_REL_FLDoorMotorErrSts_flg,
                      &REL_DW.sf_FLDoorRlsDriver);

  /* Logic: '<S3>/Logical Operator2' incorporates:
   *  Constant: '<S12>/Constant'
   *  Inport: '<Root>/VeINP_BLE_BDCBleKeyDoorCtrRequest_sig_VeINP_BLE_BDCBleKeyDoorCtrRequest_sig'
   *  RelationalOperator: '<S12>/Compare'
   */
  LogicalOperator1 = ((REL_U.VeINP_BLE_BDCBleKeyDoorCtrReque == 3) ||
                      rtb_Compare_i);

  /* Chart: '<S3>/FRDoorRlsReq' incorporates:
   *  Constant: '<S3>/Constant8'
   *  DataTypeConversion: '<S3>/Data Type Conversion13'
   *  DataTypeConversion: '<S3>/Data Type Conversion14'
   *  DataTypeConversion: '<S3>/Data Type Conversion16'
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg'
   *  Outport: '<Root>/VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg'
   */
  if (REL_DW.temporalCounter_i1_k < 63U) {
    REL_DW.temporalCounter_i1_k++;
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

  if (REL_DW.temporalCounter_i8 < 7U) {
    REL_DW.temporalCounter_i8++;
  }

  SI_b_DoorInBtnSts_prev_j = REL_DW.SI_b_DoorInBtnSts_start;
  REL_DW.SI_b_DoorInBtnSts_start = SL_b_FRDoorInBtnSts;
  SL_b_FRDoorInBtnSts = REL_DW.SL_b_DoorInBtnValid_start;
  REL_DW.SL_b_DoorInBtnValid_start = REL_DW.SL_b_DoorInBtnValid;
  SL_b_FLDoorInBtnSts = REL_DW.SL_b_DoorHndPullValid_start;
  REL_DW.SL_b_DoorHndPullValid_start = REL_DW.SL_b_DoorHndPullValid;
  SL_b_DoorHndPullValid_prev_i = REL_DW.SI_b_DoorHndBtnSts_start;
  REL_DW.SI_b_DoorHndBtnSts_start = REL_Y.VbOUT_REL_FRDoorHndlBtnSig_flg_;
  SI_b_DoorHndBtnSts_prev_f = REL_DW.SL_b_DoorHndBtnValid_start;
  REL_DW.SL_b_DoorHndBtnValid_start = REL_DW.SL_b_DoorHndBtnValid;
  SL_b_DoorHndBtnValid_prev_l = REL_DW.SL_b_CentSingleDoorBtnValid_sta;
  REL_DW.SL_b_CentSingleDoorBtnValid_sta = REL_DW.SL_b_CentSingleDoorBtnValid;
  SL_b_CentSingleDoorBtnValid_p_g = REL_DW.SL_b_CentAllDoorBtnValid_start;
  REL_DW.SL_b_CentAllDoorBtnValid_start = REL_DW.SL_b_CentAllDoorBtnValid;
  REL_DW.SI_b_DoorAutoRlsReq_start = false;
  SL_b_CentAllDoorBtnValid_prev_g = REL_DW.SL_b_BleDoorOpenValid_start;
  REL_DW.SL_b_BleDoorOpenValid_start = REL_DW.SL_b_BleDoorOpenValid;
  if (REL_DW.is_active_c5_DoorRlsReq == 0U) {
    REL_DW.is_active_c5_DoorRlsReq = 1U;
    REL_DW.is_SwValid = REL_IN_Idle_d;
    REL_DW.SL_b_DoorInBtnValid = false;
    REL_DW.is_RlsReq = REL_IN_Idle_d;
    REL_DW.SL_b_DoorHndPullValid = REL_Y.VbOUT_REL_BcmPassDoorHandleReq_;
    REL_DW.is_RlsReq_j = REL_IN_Idle_d;
    REL_DW.is_RlsReq_a = REL_IN_Idle_d;
    REL_DW.is_SwValid_d = REL_IN_Idle_d;
    REL_DW.SL_b_DoorHndBtnValid = false;
    REL_DW.is_DoorCentral = REL_IN_Idle_d;
    REL_DW.SL_b_CentSingleDoorBtnValid = REL_U.VbINP_CAN_CdcPassDoorButtonSts_;
    REL_DW.SL_b_CentAllDoorBtnValid = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
    REL_DW.is_RlsReq_a0 = REL_IN_Idle_d;
    REL_DW.SL_b_BleDoorOpenValid = LogicalOperator1;
    REL_DW.is_RlsReq_b = REL_IN_Idle_d;
  } else {
    REL_DoorInBtn_e(&SI_b_DoorInBtnSts_prev_j, &SL_b_FRDoorInBtnSts,
                    &DataTypeConversion14, &SO_m_FRDoorRatSts,
                    &DataTypeConversion13);
    REL_DW.SL_b_DoorHndPullValid = REL_Y.VbOUT_REL_BcmPassDoorHandleReq_;
    if (REL_DW.is_RlsReq_j == REL_IN_Idle_d) {
      if ((!Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                         (DataTypeConversion14 == Gear_P)) &&
          (DataTypeConversion13 == Door_Unlock) && (DataTypeConversion16 ==
           Hnd_Unfold) && ((SL_b_FLDoorInBtnSts !=
                            REL_DW.SL_b_DoorHndPullValid_start) &&
                           REL_DW.SL_b_DoorHndPullValid_start)) {
        REL_DW.is_RlsReq_j = REL_IN_Trigger_o;
        REL_DW.is_Trigger_c = REL_IN_DoorUnlock_i4;
      }

      /* case IN_Trigger: */
    } else if (Compare || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                           (DataTypeConversion14 != Gear_P)) ||
               (DataTypeConversion13 != Door_Unlock) || (DataTypeConversion16 !=
                Hnd_Unfold) || (SO_m_FRDoorRatSts == Rat_Unlock)) {
      REL_DW.is_Trigger_c = REL_IN_NO_ACTIVE_CHILD_b;
      REL_DW.is_RlsReq_j = REL_IN_Idle_d;
    } else if (REL_DW.is_Trigger_c == REL_IN_DoorUnlock_i4) {
      if (SO_m_FRDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_c = REL_IN_Release_lh;
        REL_DW.temporalCounter_i5 = 0U;

        /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
        REL_B.SO_e_DoorRlsDelayTime_h = 4U;
      }

      /* case IN_Release: */
    } else if (REL_DW.temporalCounter_i5 >= 5) {
      /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
      REL_B.SO_e_DoorRlsDelayTime_h = 0U;
      REL_DW.is_Trigger_c = REL_IN_NO_ACTIVE_CHILD_b;
      REL_DW.is_RlsReq_j = REL_IN_Idle_d;
    }

    REL_DoorHndBtn_d(&LogicalOperator, &SL_b_DoorHndPullValid_prev_i,
                     &SI_b_DoorHndBtnSts_prev_f, &DataTypeConversion14,
                     &SO_m_FRDoorRatSts, &DataTypeConversion13);
    REL_CentDoorBtn_ew(&Compare, &SL_b_DoorHndBtnValid_prev_l,
                       &SL_b_CentSingleDoorBtnValid_p_g, &DataTypeConversion14,
                       &SO_m_FRDoorRatSts, &DataTypeConversion13);
    if (REL_DW.is_RlsReq_a0 != REL_IN_Idle_d) {
      /* case IN_Trigger: */
      REL_DW.is_Trigger_o = REL_IN_NO_ACTIVE_CHILD_b;
      REL_DW.is_RlsReq_a0 = REL_IN_Idle_d;
    }

    REL_DW.SL_b_BleDoorOpenValid = LogicalOperator1;
    if (REL_DW.is_RlsReq_b == REL_IN_Idle_d) {
      if ((!Compare) && ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                         (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) &&
          (DataTypeConversion14 == Gear_P) && (DataTypeConversion13 ==
           Door_Unlock) && ((SL_b_CentAllDoorBtnValid_prev_g !=
                             REL_DW.SL_b_BleDoorOpenValid_start) &&
                            REL_DW.SL_b_BleDoorOpenValid_start)) {
        REL_DW.is_RlsReq_b = REL_IN_Trigger_o;
        REL_DW.is_Trigger_og = REL_IN_DoorUnlock_i4;
      }

      /* case IN_Trigger: */
    } else if (Compare || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
               (DataTypeConversion14 != Gear_P) || (DataTypeConversion13 !=
                Door_Unlock) || (SO_m_FRDoorRatSts == Rat_Unlock)) {
      REL_DW.is_Trigger_og = REL_IN_NO_ACTIVE_CHILD_b;
      REL_DW.is_RlsReq_b = REL_IN_Idle_d;
    } else if (REL_DW.is_Trigger_og == REL_IN_DoorUnlock_i4) {
      if (SO_m_FRDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_og = REL_IN_Release_lh;
        REL_DW.temporalCounter_i8 = 0U;

        /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
        REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = true;
      }

      /* case IN_Release: */
    } else if (REL_DW.temporalCounter_i8 >= 5) {
      /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
      REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;
      REL_DW.is_Trigger_og = REL_IN_NO_ACTIVE_CHILD_b;
      REL_DW.is_RlsReq_b = REL_IN_Idle_d;
    }
  }

  /* End of Chart: '<S3>/FRDoorRlsReq' */

  /* Chart: '<S3>/FRDoorRlsDriver' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   *  Inport: '<Root>/VbINP_HWA_FRDoorOpenSW_flg_VbINP_HWA_FRDoorOpenSW_flg'
   *  Inport: '<Root>/VeINP_HWA_Voltage_100mV_VeINP_HWA_Voltage_100mV'
   *  Outport: '<Root>/VbOUT_REL_FRDoorMotorErrSts_flg_VbOUT_REL_FRDoorMotorErrSts_flg'
   *  Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_FRDoorMotorCmd_sig_VeOUT_REL_FRDoorMotorCmd_sig'
   *  Outport: '<Root>/VeOUT_REL_FRDoorMotorPWM_pct_VeOUT_REL_FRDoorMotorPWM_pct'
   */
  REL_FLDoorRlsDriver(REL_U.VeINP_HWA_Voltage_100mV_VeINP_H,
                      REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU,
                      REL_U.VbINP_HWA_FRDoorAjar_flg_VbINP_,
                      REL_U.VbINP_HWA_FRDoorOpenSW_flg_VbIN,
                      REL_B.SO_e_DoorRlsDelayTime_h,
                      &REL_Y.VeOUT_REL_FRDoorMotorCmd_sig_Ve,
                      &REL_Y.VeOUT_REL_FRDoorMotorPWM_pct_Ve,
                      &REL_Y.VbOUT_REL_FRDoorMotorErrSts_flg,
                      &REL_DW.sf_FRDoorRlsDriver);

  /* Chart: '<S3>/RLDoorRlsReq' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcLeReDoorButtonSts_flg_VbINP_CAN_CdcLeReDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbINP_HWA_LRChildLckSt_flg_VbINP_HWA_LRChildLckSt_flg'
   *  Inport: '<Root>/VbOUT_DHM_BdcPassDoorHandButtonSts_flg_VbOUT_DHM_BdcPassDoorHandButtonSts_flg'
   *  Inport: '<Root>/VeINP_BLE_BDCBleKeyDoorCtrRequest_sig_VeINP_BLE_BDCBleKeyDoorCtrRequest_sig'
   *  Inport: '<Root>/VeOUT_DHM_BDCLeReDoorHndSts_sig_VeOUT_DHM_BDCLeReDoorHndSts_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Logic: '<S3>/Logical Operator4'
   *  Outport: '<Root>/VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg'
   *  RelationalOperator: '<S11>/Compare'
   */
  REL_RLDoorRlsReq(Compare, REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                   REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN, DataTypeConversion14,
                   DataTypeConversion13, SO_m_RLDoorRatSts, SI_b_CrashSts_prev,
                   REL_Y.VbOUT_REL_BcmLeReDoorHandleReq_,
                   REL_Y.VbOUT_REL_RLDoorHndlBtnSig_flg_,
                   REL_U.VeOUT_DHM_BDCLeReDoorHndSts_sig,
                   REL_U.VbINP_CAN_CdcLeReDoorButtonSts_,
                   REL_U.VbINP_CAN_CdcAllDoorOpenButtonS,
                   REL_U.VbINP_HWA_LRChildLckSt_flg_VbIN, false, false,
                   REL_U.VbOUT_DHM_BdcPassDoorHandButton,
                   (REL_U.VeINP_BLE_BDCBleKeyDoorCtrReque == 5) || rtb_Compare_i,
                   LogicalOperator, &REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU,
                   &REL_B.SO_e_DoorRlsDelayTime_n, &REL_B.SO_m_UnlockReq_f,
                   &REL_DW.sf_RLDoorRlsReq);

  /* Chart: '<S3>/RLDoorRlsDriver' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg'
   *  Inport: '<Root>/VbINP_HWA_RLDoorOpenSW_flg_VbINP_HWA_RLDoorOpenSW_flg'
   *  Inport: '<Root>/VeINP_HWA_Voltage_100mV_VeINP_HWA_Voltage_100mV'
   *  Outport: '<Root>/VbOUT_REL_RLDoorMotorErrSts_flg_VbOUT_REL_RLDoorMotorErrSts_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_RLDoorMotorCmd_sig_VeOUT_REL_RLDoorMotorCmd_sig'
   *  Outport: '<Root>/VeOUT_REL_RLDoorMotorPWM_pct_VeOUT_REL_RLDoorMotorPWM_pct'
   */
  REL_FLDoorRlsDriver(REL_U.VeINP_HWA_Voltage_100mV_VeINP_H,
                      REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU,
                      REL_U.VbINP_HWA_RLDoorAjar_flg_VbINP_,
                      REL_U.VbINP_HWA_RLDoorOpenSW_flg_VbIN,
                      REL_B.SO_e_DoorRlsDelayTime_n,
                      &REL_Y.VeOUT_REL_RLDoorMotorCmd_sig_Ve,
                      &REL_Y.VeOUT_REL_RLDoorMotorPWM_pct_Ve,
                      &REL_Y.VbOUT_REL_RLDoorMotorErrSts_flg,
                      &REL_DW.sf_RLDoorRlsDriver);

  /* Chart: '<S3>/RRDoorRlsReq' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S3>/Constant3'
   *  Constant: '<S3>/Constant5'
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcRiReDoorButtonSts_flg_VbINP_CAN_CdcRiReDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbINP_HWA_RRChildLckSt_flg_VbINP_HWA_RRChildLckSt_flg'
   *  Inport: '<Root>/VbOUT_DHM_BdcPassDoorHandButtonSts_flg_VbOUT_DHM_BdcPassDoorHandButtonSts_flg'
   *  Inport: '<Root>/VeINP_BLE_BDCBleKeyDoorCtrRequest_sig_VeINP_BLE_BDCBleKeyDoorCtrRequest_sig'
   *  Inport: '<Root>/VeOUT_DHM_BDCRiReDoorHndSts_sig_VeOUT_DHM_BDCRiReDoorHndSts_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Logic: '<S3>/Logical Operator5'
   *  Outport: '<Root>/VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg'
   *  RelationalOperator: '<S13>/Compare'
   */
  REL_RLDoorRlsReq(Compare, REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                   REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN, DataTypeConversion14,
                   DataTypeConversion13, SO_m_RRDoorRatSts, SL_b_RRDoorInBtnSts,
                   REL_Y.VbOUT_REL_BcmBcmRiReDoorHandleR,
                   REL_Y.VbOUT_REL_RRDoorHndlBtnSig_flg_,
                   REL_U.VeOUT_DHM_BDCRiReDoorHndSts_sig,
                   REL_U.VbINP_CAN_CdcRiReDoorButtonSts_,
                   REL_U.VbINP_CAN_CdcAllDoorOpenButtonS,
                   REL_U.VbINP_HWA_RRChildLckSt_flg_VbIN, false, false,
                   REL_U.VbOUT_DHM_BdcPassDoorHandButton,
                   (REL_U.VeINP_BLE_BDCBleKeyDoorCtrReque == 7) || rtb_Compare_i,
                   LogicalOperator, &REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU,
                   &REL_B.SO_e_DoorRlsDelayTime, &REL_B.SO_m_UnlockReq,
                   &REL_DW.sf_RRDoorRlsReq);

  /* Chart: '<S3>/RRDoorRlsDriver' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg'
   *  Inport: '<Root>/VbINP_HWA_RRDoorOpenSW_flg_VbINP_HWA_RRDoorOpenSW_flg'
   *  Inport: '<Root>/VeINP_HWA_Voltage_100mV_VeINP_HWA_Voltage_100mV'
   *  Outport: '<Root>/VbOUT_REL_RRDoorMotorErrSts_flg_VbOUT_REL_RRDoorMotorErrSts_flg'
   *  Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_RRDoorMotorCmd_sig_VeOUT_REL_RRDoorMotorCmd_sig'
   *  Outport: '<Root>/VeOUT_REL_RRDoorMotorPWM_pct_VeOUT_REL_RRDoorMotorPWM_pct'
   */
  REL_FLDoorRlsDriver(REL_U.VeINP_HWA_Voltage_100mV_VeINP_H,
                      REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU,
                      REL_U.VbINP_HWA_RRDoorAjar_flg_VbINP_,
                      REL_U.VbINP_HWA_RRDoorOpenSW_flg_VbIN,
                      REL_B.SO_e_DoorRlsDelayTime,
                      &REL_Y.VeOUT_REL_RRDoorMotorCmd_sig_Ve,
                      &REL_Y.VeOUT_REL_RRDoorMotorPWM_pct_Ve,
                      &REL_Y.VbOUT_REL_RRDoorMotorErrSts_flg,
                      &REL_DW.sf_RRDoorRlsDriver);

  /* Chart: '<S3>/Unlock_Request' */
  if (REL_DW.is_active_c6_REL == 0U) {
    REL_DW.is_active_c6_REL = 1U;
    if (((REL_GetDrvUnlockReq() == 1.0) && (REL_GetPassUnlockReq() == 1.0)) ||
        (REL_GetDrvUnlockReq() == 2.0) || (REL_GetPassUnlockReq() == 2.0)) {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 3U;

      /*   */
    } else if ((REL_GetDrvUnlockReq() == 0.0) && (REL_GetPassUnlockReq() == 1.0))
    {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 2U;
    } else {
      /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
      /*   */
      REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = (UInt8)((REL_GetDrvUnlockReq() ==
        1.0) && (REL_GetPassUnlockReq() == 0.0));
    }
  } else if (((REL_GetDrvUnlockReq() == 1.0) && (REL_GetPassUnlockReq() == 1.0))
             || (REL_GetDrvUnlockReq() == 2.0) || (REL_GetPassUnlockReq() == 2.0))
  {
    /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
    REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 3U;

    /*   */
  } else if ((REL_GetDrvUnlockReq() == 0.0) && (REL_GetPassUnlockReq() == 1.0))
  {
    /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
    REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 2U;
  } else {
    /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
    /*   */
    REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = (UInt8)((REL_GetDrvUnlockReq() ==
      1.0) && (REL_GetPassUnlockReq() == 0.0));
  }

  /* End of Chart: '<S3>/Unlock_Request' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' incorporates:
   *  Outport: '<Root>/VeOUT_REL_FLDoorMotorCmd_sig_VeOUT_REL_FLDoorMotorCmd_sig'
   */
  REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = REL_Y.VeOUT_REL_FLDoorMotorCmd_sig_Ve;

  /* Outport: '<Root>/VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig' incorporates:
   *  Outport: '<Root>/VeOUT_REL_FRDoorMotorCmd_sig_VeOUT_REL_FRDoorMotorCmd_sig'
   */
  REL_Y.VeOUT_REL_FRDoorMotorSts_sig_Ve = REL_Y.VeOUT_REL_FRDoorMotorCmd_sig_Ve;

  /* Outport: '<Root>/VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig' incorporates:
   *  Outport: '<Root>/VeOUT_REL_RLDoorMotorCmd_sig_VeOUT_REL_RLDoorMotorCmd_sig'
   */
  REL_Y.VeOUT_REL_RLDoorMotorSts_sig_Ve = REL_Y.VeOUT_REL_RLDoorMotorCmd_sig_Ve;

  /* Outport: '<Root>/VeOUT_REL_RRDoorMotorSts_sig_VeOUT_REL_RRDoorMotorSts_sig' incorporates:
   *  Outport: '<Root>/VeOUT_REL_RRDoorMotorCmd_sig_VeOUT_REL_RRDoorMotorCmd_sig'
   */
  REL_Y.VeOUT_REL_RRDoorMotorSts_sig_Ve = REL_Y.VeOUT_REL_RRDoorMotorCmd_sig_Ve;
}

/* Model initialize function */
void REL_initialize(void)
{
  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */

  /* SystemInitialize for Chart: '<S3>/FLDoorRlsDriver' incorporates:
   *  Outport: '<Root>/VbOUT_REL_FLDoorMotorErrSts_flg_VbOUT_REL_FLDoorMotorErrSts_flg'
   *  Outport: '<Root>/VeOUT_REL_FLDoorMotorCmd_sig_VeOUT_REL_FLDoorMotorCmd_sig'
   *  Outport: '<Root>/VeOUT_REL_FLDoorMotorPWM_pct_VeOUT_REL_FLDoorMotorPWM_pct'
   */
  REL_FLDoorRlsDriver_Init(&REL_Y.VeOUT_REL_FLDoorMotorCmd_sig_Ve,
    &REL_Y.VeOUT_REL_FLDoorMotorPWM_pct_Ve,
    &REL_Y.VbOUT_REL_FLDoorMotorErrSts_flg);

  /* SystemInitialize for Chart: '<S3>/FRDoorRlsDriver' incorporates:
   *  Outport: '<Root>/VbOUT_REL_FRDoorMotorErrSts_flg_VbOUT_REL_FRDoorMotorErrSts_flg'
   *  Outport: '<Root>/VeOUT_REL_FRDoorMotorCmd_sig_VeOUT_REL_FRDoorMotorCmd_sig'
   *  Outport: '<Root>/VeOUT_REL_FRDoorMotorPWM_pct_VeOUT_REL_FRDoorMotorPWM_pct'
   */
  REL_FLDoorRlsDriver_Init(&REL_Y.VeOUT_REL_FRDoorMotorCmd_sig_Ve,
    &REL_Y.VeOUT_REL_FRDoorMotorPWM_pct_Ve,
    &REL_Y.VbOUT_REL_FRDoorMotorErrSts_flg);

  /* SystemInitialize for Chart: '<S3>/RLDoorRlsDriver' incorporates:
   *  Outport: '<Root>/VbOUT_REL_RLDoorMotorErrSts_flg_VbOUT_REL_RLDoorMotorErrSts_flg'
   *  Outport: '<Root>/VeOUT_REL_RLDoorMotorCmd_sig_VeOUT_REL_RLDoorMotorCmd_sig'
   *  Outport: '<Root>/VeOUT_REL_RLDoorMotorPWM_pct_VeOUT_REL_RLDoorMotorPWM_pct'
   */
  REL_FLDoorRlsDriver_Init(&REL_Y.VeOUT_REL_RLDoorMotorCmd_sig_Ve,
    &REL_Y.VeOUT_REL_RLDoorMotorPWM_pct_Ve,
    &REL_Y.VbOUT_REL_RLDoorMotorErrSts_flg);

  /* SystemInitialize for Chart: '<S3>/RLDoorRlsReq' incorporates:
   *  Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg'
   */
  REL_RLDoorRlsReq_Init(&REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU,
                        &REL_B.SO_e_DoorRlsDelayTime_n, &REL_B.SO_m_UnlockReq_f);

  /* SystemInitialize for Chart: '<S3>/RRDoorRlsDriver' incorporates:
   *  Outport: '<Root>/VbOUT_REL_RRDoorMotorErrSts_flg_VbOUT_REL_RRDoorMotorErrSts_flg'
   *  Outport: '<Root>/VeOUT_REL_RRDoorMotorCmd_sig_VeOUT_REL_RRDoorMotorCmd_sig'
   *  Outport: '<Root>/VeOUT_REL_RRDoorMotorPWM_pct_VeOUT_REL_RRDoorMotorPWM_pct'
   */
  REL_FLDoorRlsDriver_Init(&REL_Y.VeOUT_REL_RRDoorMotorCmd_sig_Ve,
    &REL_Y.VeOUT_REL_RRDoorMotorPWM_pct_Ve,
    &REL_Y.VbOUT_REL_RRDoorMotorErrSts_flg);

  /* SystemInitialize for Chart: '<S3>/RRDoorRlsReq' incorporates:
   *  Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg'
   */
  REL_RLDoorRlsReq_Init(&REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU,
                        &REL_B.SO_e_DoorRlsDelayTime, &REL_B.SO_m_UnlockReq);

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */
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
