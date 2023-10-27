/*
 * File: REL.c
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Oct 27 16:19:24 2023
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
#define REL_IN_DoorUnlock_c            ((uint8_T)1U)
#define REL_IN_Error                   ((uint8_T)3U)
#define REL_IN_Idle_f                  ((uint8_T)1U)
#define REL_IN_NO_ACTIVE_CHILD_j       ((uint8_T)0U)
#define REL_IN_Once                    ((uint8_T)2U)
#define REL_IN_Press                   ((uint8_T)2U)
#define REL_IN_RELEASE                 ((uint8_T)4U)
#define REL_IN_Release_e               ((uint8_T)4U)
#define REL_IN_Release_er              ((uint8_T)2U)
#define REL_IN_Release_erx             ((uint8_T)3U)
#define REL_IN_Trigger                 ((uint8_T)2U)
#define REL_IN_Twice                   ((uint8_T)3U)
#define REL_IN_UnlockFail              ((uint8_T)1U)
#define REL_IN_UnlockReq               ((uint8_T)2U)
#define REL_IN_UnlockSuccess           ((uint8_T)3U)
#define REL_IN_UnlockSucess            ((uint8_T)3U)

/* Named constants for Chart: '<S3>/DoorSwSts' */
#define REL_IN_Crash                   ((uint8_T)1U)
#define REL_IN_NoCrash                 ((uint8_T)2U)

/* Named constants for Chart: '<S3>/FLDoorRlsReq' */
#define REL_IN_DoorLock_j              ((uint8_T)1U)
#define REL_IN_DoorUnlock_c3           ((uint8_T)2U)
#define REL_IN_DoorUnlock_c3m          ((uint8_T)1U)
#define REL_IN_Error_p                 ((uint8_T)3U)
#define REL_IN_Idle_p                  ((uint8_T)1U)
#define REL_IN_Once_l                  ((uint8_T)2U)
#define REL_IN_Press_p                 ((uint8_T)2U)
#define REL_IN_RELEASE_m               ((uint8_T)4U)
#define REL_IN_Release_p               ((uint8_T)4U)
#define REL_IN_Release_pc              ((uint8_T)2U)
#define REL_IN_Release_pcz             ((uint8_T)3U)
#define REL_IN_Trigger_d               ((uint8_T)2U)
#define REL_IN_Twice_k                 ((uint8_T)3U)
#define REL_IN_UnlockFail_p            ((uint8_T)1U)
#define REL_IN_UnlockReq_e             ((uint8_T)2U)
#define REL_IN_UnlockSuccess_p         ((uint8_T)3U)
#define REL_IN_UnlockSucess_e          ((uint8_T)3U)

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
  rtu_SI_b_DoorHndBtnSetSts, boolean_T *rty_SO_b_DoorRlsReq, Unlock_Req_E
  *rty_SO_m_UnlockReq, DW_RLDoorRlsReq_REL_T *localDW);

/* Forward declaration for local functions */
static real_T REL_GetDoorRatSts(real_T ajar, real_T open);
static uint8_T REL_safe_cast_to_Rat_Sts_E(uint8_T input);
static void REL_enter_atomic_NoCrash(boolean_T *SL_b_FLDoorInBtnSts, boolean_T
  *SL_b_FRDoorInBtnSts, boolean_T *SL_b_RLDoorInBtnSts, boolean_T
  *SL_b_RRDoorInBtnSts, boolean_T *SL_b_FLDoorHndPullSts, boolean_T
  *SL_b_FRDoorHndPullSts);
static void REL_DoorInBtn_k(const boolean_T *SI_b_DoorInBtnSts_prev_g, const
  boolean_T *SL_b_DoorInBtnValid_prev_e, const Door_Sts_E *DataTypeConversion12,
  const Gear_Posn_E *DataTypeConversion14, const Rat_Sts_E *SO_m_FLDoorRatSts);
static void REL_DoorHndBtn_f(const boolean_T *SI_b_DoorHndBtnSts_prev_i, const
  boolean_T *SL_b_DoorHndBtnValid_prev_k, const Door_Sts_E *DataTypeConversion12,
  const Gear_Posn_E *DataTypeConversion14, const Rat_Sts_E *SO_m_FLDoorRatSts);
static void REL_DoorInBtn_o(const boolean_T *SI_b_DoorInBtnSts_prev, const
  boolean_T *SL_b_DoorInBtnValid_prev, const Door_Sts_E *DataTypeConversion13,
  const Gear_Posn_E *DataTypeConversion14, const Rat_Sts_E *SO_m_FRDoorRatSts);
static void REL_DoorHndBtn_m(const boolean_T *SI_b_DoorHndBtnSts_prev, const
  boolean_T *SL_b_DoorHndBtnValid_prev, const Door_Sts_E *DataTypeConversion13,
  const Gear_Posn_E *DataTypeConversion14, const Rat_Sts_E *SO_m_FRDoorRatSts);

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
  Boolean rtu_SI_b_DoorAjar, uint8_T rtu_SI_e_DoorRlsDelayTime, uint8_T
  *rty_SO_e_MotorCmd, uint8_T *rty_SO_e_MotorPwm, boolean_T *rty_SO_b_Error,
  DW_FLDoorRlsDriver_REL_T *localDW)
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
            if ((localDW->temporalCounter_i1 < 270) && rtu_SI_b_DoorAjar) {
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
   case REL_IN_Idle_f:
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
      localDW->is_SwValid = REL_IN_Idle_f;
      localDW->SL_b_DoorInBtnValid = false;
    }
    break;

   default:
    /* case IN_Twice: */
    if (localDW->temporalCounter_i4 >= 3) {
      localDW->is_SwValid = REL_IN_Idle_f;
      localDW->SL_b_DoorInBtnValid = false;
    }
    break;
  }

  if (localDW->is_RlsReq == REL_IN_Idle_f) {
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
    localDW->is_RlsReq = REL_IN_Idle_f;
  } else {
    switch (localDW->is_Trigger) {
     case REL_IN_DoorLock:
      switch (localDW->is_DoorLock) {
       case REL_IN_UnlockFail:
        localDW->is_DoorLock = REL_IN_NO_ACTIVE_CHILD_j;
        localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_j;
        localDW->is_RlsReq = REL_IN_Idle_f;
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
          localDW->is_Trigger = REL_IN_Release_e;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_DoorRlsReq = true;
          *rty_SO_e_DoorRlsDelayTime = 20U;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock:
      if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
        localDW->is_Trigger = REL_IN_Release_e;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_DoorRlsReq = true;
        *rty_SO_e_DoorRlsDelayTime = 20U;
      }
      break;

     case REL_IN_Error:
      localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_j;
      localDW->is_RlsReq = REL_IN_Idle_f;
      break;

     default:
      /* case IN_Release: */
      if (localDW->temporalCounter_i1 >= 5) {
        *rty_SO_b_DoorRlsReq = false;
        *rty_SO_e_DoorRlsDelayTime = 0U;
        localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_j;
        localDW->is_RlsReq = REL_IN_Idle_f;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/RLDoorRlsReq' */
static void REL_DoorHndBtn(UInt8 rtu_SI_e_EspVehSpd, Boolean
  rtu_SI_b_EspVehSpdVld, Gear_Posn_E rtu_SI_m_VcuGearPosn, Door_Sts_E
  rtu_SI_m_DoorLockSts, Rat_Sts_E rtu_SI_m_DoorRatSts, Boolean
  rtu_SI_b_DoorHndBtnSetSts, boolean_T *rty_SO_b_DoorRlsReq, Unlock_Req_E
  *rty_SO_m_UnlockReq, DW_RLDoorRlsReq_REL_T *localDW)
{
  if (localDW->is_RlsReq_i == REL_IN_Idle_f) {
    if ((((rtu_SI_e_EspVehSpd <= 0) && (!rtu_SI_b_EspVehSpdVld)) ||
         (rtu_SI_m_VcuGearPosn == Gear_P)) && (!rtu_SI_b_DoorHndBtnSetSts) &&
        ((localDW->SL_b_DoorHndBtnValid_prev !=
          localDW->SL_b_DoorHndBtnValid_start) &&
         localDW->SL_b_DoorHndBtnValid_start)) {
      localDW->is_RlsReq_i = REL_IN_Trigger;
      switch (rtu_SI_m_DoorLockSts) {
       case Door_Lock:
        localDW->is_Trigger_m = REL_IN_DoorLock;
        localDW->is_DoorLock_i = REL_IN_UnlockReq;
        localDW->temporalCounter_i2 = 0U;
        *rty_SO_m_UnlockReq = Unlock_PE;
        break;

       case Door_Unlock:
        localDW->is_Trigger_m = REL_IN_DoorUnlock;
        break;

       default:
        localDW->is_Trigger_m = REL_IN_Error;
        break;
      }
    }

    /* case IN_Trigger: */
  } else if (((rtu_SI_e_EspVehSpd >= 1) && (!rtu_SI_b_EspVehSpdVld) &&
              (rtu_SI_m_VcuGearPosn != Gear_P)) || rtu_SI_b_DoorHndBtnSetSts ||
             ((rtu_SI_m_DoorLockSts == Door_Unlock) && (rtu_SI_m_DoorRatSts ==
               Rat_Unlock))) {
    localDW->is_DoorLock_i = REL_IN_NO_ACTIVE_CHILD_j;
    localDW->is_Trigger_m = REL_IN_NO_ACTIVE_CHILD_j;
    localDW->is_RlsReq_i = REL_IN_Idle_f;
  } else {
    switch (localDW->is_Trigger_m) {
     case REL_IN_DoorLock:
      switch (localDW->is_DoorLock_i) {
       case REL_IN_UnlockFail:
        localDW->is_DoorLock_i = REL_IN_NO_ACTIVE_CHILD_j;
        localDW->is_Trigger_m = REL_IN_NO_ACTIVE_CHILD_j;
        localDW->is_RlsReq_i = REL_IN_Idle_f;
        break;

       case REL_IN_UnlockReq:
        if (rtu_SI_m_DoorLockSts == Door_Unlock) {
          localDW->is_DoorLock_i = REL_IN_UnlockSuccess;
        } else if ((localDW->temporalCounter_i2 >= 50) && (rtu_SI_m_DoorLockSts ==
                    Door_Lock)) {
          localDW->is_DoorLock_i = REL_IN_UnlockFail;
        } else if (localDW->temporalCounter_i2 == 5) {
          *rty_SO_m_UnlockReq = Unlock_Idle;
        }
        break;

       default:
        /* case IN_UnlockSuccess: */
        if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
          localDW->is_DoorLock_i = REL_IN_NO_ACTIVE_CHILD_j;
          localDW->is_Trigger_m = REL_IN_Release_e;
          localDW->temporalCounter_i2 = 0U;
          *rty_SO_b_DoorRlsReq = true;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock:
      if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
        localDW->is_Trigger_m = REL_IN_Release_e;
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
        localDW->is_Trigger_m = REL_IN_NO_ACTIVE_CHILD_j;
        localDW->is_RlsReq_i = REL_IN_Idle_f;
      }
      break;
    }
  }

  switch (localDW->is_SwValid_c) {
   case REL_IN_Idle_f:
    if ((localDW->SI_b_DoorHndBtnSts_prev != localDW->SI_b_DoorHndBtnSts_start) &&
        localDW->SI_b_DoorHndBtnSts_start) {
      localDW->is_SwValid_c = REL_IN_Press;
      localDW->temporalCounter_i6 = 0U;
    }
    break;

   case REL_IN_Press:
    if ((localDW->SI_b_DoorHndBtnSts_prev != localDW->SI_b_DoorHndBtnSts_start) &&
        (!localDW->SI_b_DoorHndBtnSts_start)) {
      localDW->is_SwValid_c = REL_IN_Release_erx;
      localDW->temporalCounter_i6 = 0U;
      localDW->SL_b_DoorHndBtnValid = true;
    } else if (localDW->temporalCounter_i6 >= 100) {
      localDW->is_SwValid_c = REL_IN_Idle_f;
      localDW->SL_b_DoorHndBtnValid = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (localDW->temporalCounter_i6 >= 3) {
      localDW->is_SwValid_c = REL_IN_Idle_f;
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
                      boolean_T *rty_SO_b_DoorRlsReq, uint8_T
                      *rty_SO_e_DoorRlsDelayTime, Unlock_Req_E
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
    localDW->is_SwValid = REL_IN_Idle_f;
    localDW->SL_b_DoorInBtnValid = false;
    localDW->is_RlsReq = REL_IN_Idle_f;
    localDW->SL_b_DoorHndPullValid = rtu_SI_b_DoorHndPullSts;
    localDW->is_RlsReq_a = REL_IN_Idle_f;
    localDW->is_RlsReq_i = REL_IN_Idle_f;
    localDW->is_SwValid_c = REL_IN_Idle_f;
    localDW->SL_b_DoorHndBtnValid = false;
    localDW->is_DoorCentral = REL_IN_Idle_f;
    localDW->SL_b_CentSingleDoorBtnValid = rtu_SI_b_CentSingleDoorBtnSts;
    localDW->SL_b_CentAllDoorBtnValid = rtu_SI_b_CentAllDoorBtnSts;
    localDW->is_RlsReq_o = REL_IN_Idle_f;
  } else {
    REL_DoorInBtn(rtu_SI_e_EspVehSpd, rtu_SI_b_EspVehSpdVld,
                  rtu_SI_m_VcuGearPosn, rtu_SI_m_DoorLockSts,
                  rtu_SI_m_DoorRatSts, rtu_SI_b_ChildLckSts, rty_SO_b_DoorRlsReq,
                  rty_SO_e_DoorRlsDelayTime, rty_SO_m_UnlockReq, localDW);
    localDW->SL_b_DoorHndPullValid = rtu_SI_b_DoorHndPullSts;
    if (localDW->is_RlsReq_a == REL_IN_Idle_f) {
      if ((!rtu_SI_b_OFF) && (((rtu_SI_e_EspVehSpd <= 0) &&
            (!rtu_SI_b_EspVehSpdVld)) || (rtu_SI_m_VcuGearPosn == Gear_P)) &&
          (rtu_SI_m_DoorLockSts == Door_Unlock) && (rtu_SI_m_DoorHandPosSts ==
           Hnd_Unfold) && ((localDW->SL_b_DoorHndPullValid_prev !=
                            localDW->SL_b_DoorHndPullValid_start) &&
                           localDW->SL_b_DoorHndPullValid_start)) {
        localDW->is_RlsReq_a = REL_IN_Trigger;
        localDW->is_Trigger_k = REL_IN_DoorUnlock_c;
      }

      /* case IN_Trigger: */
    } else if (rtu_SI_b_OFF || ((rtu_SI_e_EspVehSpd >= 1) &&
                (!rtu_SI_b_EspVehSpdVld) && (rtu_SI_m_VcuGearPosn != Gear_P)) ||
               (rtu_SI_m_DoorLockSts != Door_Unlock) || (rtu_SI_m_DoorHandPosSts
                != Hnd_Unfold) || (rtu_SI_m_DoorRatSts == Rat_Unlock)) {
      localDW->is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_j;
      localDW->is_RlsReq_a = REL_IN_Idle_f;
    } else if (localDW->is_Trigger_k == REL_IN_DoorUnlock_c) {
      if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
        localDW->is_Trigger_k = REL_IN_Release_er;
        localDW->temporalCounter_i5 = 0U;
        *rty_SO_b_DoorRlsReq = true;
        *rty_SO_e_DoorRlsDelayTime = 4U;
      }

      /* case IN_Release: */
    } else if (localDW->temporalCounter_i5 >= 5) {
      *rty_SO_b_DoorRlsReq = false;
      *rty_SO_e_DoorRlsDelayTime = 0U;
      localDW->is_Trigger_k = REL_IN_NO_ACTIVE_CHILD_j;
      localDW->is_RlsReq_a = REL_IN_Idle_f;
    }

    REL_DoorHndBtn(rtu_SI_e_EspVehSpd, rtu_SI_b_EspVehSpdVld,
                   rtu_SI_m_VcuGearPosn, rtu_SI_m_DoorLockSts,
                   rtu_SI_m_DoorRatSts, rtu_SI_b_DoorHndBtnSetSts,
                   rty_SO_b_DoorRlsReq, rty_SO_m_UnlockReq, localDW);
    if (localDW->is_DoorCentral == REL_IN_Idle_f) {
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
          localDW->is_Trigger_i = REL_IN_DoorLock;
          localDW->is_DoorLock_a = REL_IN_UnlockReq;
          localDW->temporalCounter_i3 = 0U;
          *rty_SO_m_UnlockReq = Unlock_Req;
          break;

         case Door_Unlock:
          localDW->is_Trigger_i = REL_IN_DoorUnlock;
          break;

         default:
          localDW->is_Trigger_i = REL_IN_Error;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (rtu_SI_b_OFF || ((rtu_SI_e_EspVehSpd >= 1) &&
                (!rtu_SI_b_EspVehSpdVld) && (rtu_SI_m_VcuGearPosn != Gear_P)) ||
               ((rtu_SI_m_DoorLockSts == Door_Unlock) && (rtu_SI_m_DoorRatSts ==
      Rat_Unlock))) {
      localDW->is_DoorLock_a = REL_IN_NO_ACTIVE_CHILD_j;
      localDW->is_Trigger_i = REL_IN_NO_ACTIVE_CHILD_j;
      localDW->is_DoorCentral = REL_IN_Idle_f;
    } else {
      switch (localDW->is_Trigger_i) {
       case REL_IN_DoorLock:
        switch (localDW->is_DoorLock_a) {
         case REL_IN_UnlockFail:
          localDW->is_DoorLock_a = REL_IN_NO_ACTIVE_CHILD_j;
          localDW->is_Trigger_i = REL_IN_NO_ACTIVE_CHILD_j;
          localDW->is_DoorCentral = REL_IN_Idle_f;
          break;

         case REL_IN_UnlockReq:
          if (rtu_SI_m_DoorLockSts == Door_Unlock) {
            localDW->is_DoorLock_a = REL_IN_UnlockSucess;
          } else if ((localDW->temporalCounter_i3 >= 50) &&
                     (rtu_SI_m_DoorLockSts == Door_Lock)) {
            localDW->is_DoorLock_a = REL_IN_UnlockFail;
          } else if (localDW->temporalCounter_i3 == 5) {
            *rty_SO_m_UnlockReq = Unlock_Idle;
          }
          break;

         default:
          /* case IN_UnlockSucess: */
          if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
            localDW->is_DoorLock_a = REL_IN_NO_ACTIVE_CHILD_j;
            localDW->is_Trigger_i = REL_IN_RELEASE;
            localDW->temporalCounter_i3 = 0U;
            *rty_SO_b_DoorRlsReq = true;
          }
          break;
        }
        break;

       case REL_IN_DoorUnlock:
        if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
          localDW->is_Trigger_i = REL_IN_RELEASE;
          localDW->temporalCounter_i3 = 0U;
          *rty_SO_b_DoorRlsReq = true;
        }
        break;

       case REL_IN_Error:
        localDW->is_Trigger_i = REL_IN_NO_ACTIVE_CHILD_j;
        localDW->is_DoorCentral = REL_IN_Idle_f;
        break;

       default:
        /* case IN_RELEASE: */
        if (localDW->temporalCounter_i3 >= 5) {
          *rty_SO_b_DoorRlsReq = false;
          localDW->is_Trigger_i = REL_IN_NO_ACTIVE_CHILD_j;
          localDW->is_DoorCentral = REL_IN_Idle_f;
        }
        break;
      }
    }

    localDW->SL_b_CentSingleDoorBtnValid = rtu_SI_b_CentSingleDoorBtnSts;
    localDW->SL_b_CentAllDoorBtnValid = rtu_SI_b_CentAllDoorBtnSts;
    if (localDW->is_RlsReq_o == REL_IN_Idle_f) {
      if ((!rtu_SI_b_OFF) && (((rtu_SI_e_EspVehSpd <= 0) &&
            (!rtu_SI_b_EspVehSpdVld)) || (rtu_SI_m_VcuGearPosn == Gear_P)) &&
          rtu_SI_b_DoorAutoRlsSetSts && (rtu_SI_m_DoorLockSts == Door_Unlock) &&
          ((localDW->SI_b_DoorAutoRlsReq_prev !=
            localDW->SI_b_DoorAutoRlsReq_start) &&
           localDW->SI_b_DoorAutoRlsReq_start)) {
        localDW->is_RlsReq_o = REL_IN_Trigger;
        localDW->is_Trigger_j = REL_IN_DoorUnlock_c;
      }

      /* case IN_Trigger: */
    } else if (rtu_SI_b_OFF || ((rtu_SI_e_EspVehSpd >= 1) &&
                (!rtu_SI_b_EspVehSpdVld) && (rtu_SI_m_VcuGearPosn != Gear_P)) ||
               (!rtu_SI_b_DoorAutoRlsSetSts) || (rtu_SI_m_DoorLockSts !=
                Door_Unlock) || (rtu_SI_m_DoorRatSts == Rat_Unlock)) {
      localDW->is_Trigger_j = REL_IN_NO_ACTIVE_CHILD_j;
      localDW->is_RlsReq_o = REL_IN_Idle_f;
    } else if (localDW->is_Trigger_j == REL_IN_DoorUnlock_c) {
      if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
        localDW->is_Trigger_j = REL_IN_Release_er;
        localDW->temporalCounter_i7 = 0U;
        *rty_SO_b_DoorRlsReq = true;
      }

      /* case IN_Release: */
    } else if (localDW->temporalCounter_i7 >= 5) {
      *rty_SO_b_DoorRlsReq = false;
      localDW->is_Trigger_j = REL_IN_NO_ACTIVE_CHILD_j;
      localDW->is_RlsReq_o = REL_IN_Idle_f;
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
static void REL_enter_atomic_NoCrash(boolean_T *SL_b_FLDoorInBtnSts, boolean_T
  *SL_b_FRDoorInBtnSts, boolean_T *SL_b_RLDoorInBtnSts, boolean_T
  *SL_b_RRDoorInBtnSts, boolean_T *SL_b_FLDoorHndPullSts, boolean_T
  *SL_b_FRDoorHndPullSts)
{
  /* Inport: '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg' */
  *SL_b_FLDoorInBtnSts = REL_U.VbINP_HWA_FLDoorButton_flg_VbIN;

  /* Inport: '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg' */
  *SL_b_FRDoorInBtnSts = REL_U.VbINP_HWA_FRDoorButton_flg_VbIN;

  /* Inport: '<Root>/VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg' */
  *SL_b_RLDoorInBtnSts = REL_U.VbINP_HWA_RLDoorButton_flg_VbIN;

  /* Inport: '<Root>/VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg' */
  *SL_b_RRDoorInBtnSts = REL_U.VbINP_HWA_RRDoorButton_flg_VbIN;

  /* Inport: '<Root>/VbINP_HWA_FLDoorOutButton_flg_VbINP_HWA_FLDoorOutButton_flg' */
  *SL_b_FLDoorHndPullSts = REL_U.VbINP_HWA_FLDoorOutButton_flg_V;

  /* Inport: '<Root>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg' */
  *SL_b_FRDoorHndPullSts = REL_U.VbINP_HWA_FRDoorOutButton_flg_V;

  /* Inport: '<Root>/VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg' */
  REL_B.SL_b_RLDoorHndPullSts = REL_U.VbINP_HWA_RLDoorOutButton_flg_V;

  /* Inport: '<Root>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg' */
  REL_B.SL_b_RRDoorHndPullSts = REL_U.VbINP_HWA_RRDoorOutButton_flg_V;

  /* Inport: '<Root>/VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg' */
  REL_B.SL_b_FLDoorHndBtnSts = REL_U.VbINP_HWA_FLDoorHandleSW_flg_Vb;

  /* Inport: '<Root>/VbINP_HWA_FRDoorHandleSW_flg_VbINP_HWA_FRDoorHandleSW_flg' */
  REL_B.SL_b_FRDoorHndBtnSts = REL_U.VbINP_HWA_FRDoorHandleSW_flg_Vb;

  /* Inport: '<Root>/VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg' */
  REL_B.SL_b_RLDoorHndBtnSts = REL_U.VbINP_HWA_RLDoorHandleSW_flg_Vb;

  /* Inport: '<Root>/VbINP_HWA_RRDoorHandleSW_flg_VbINP_HWA_RRDoorHandleSW_flg' */
  REL_B.SL_b_RRDoorHndBtnSts = REL_U.VbINP_HWA_RRDoorHandleSW_flg_Vb;
}

/* Function for Chart: '<S3>/FLDoorRlsReq' */
static void REL_DoorInBtn_k(const boolean_T *SI_b_DoorInBtnSts_prev_g, const
  boolean_T *SL_b_DoorInBtnValid_prev_e, const Door_Sts_E *DataTypeConversion12,
  const Gear_Posn_E *DataTypeConversion14, const Rat_Sts_E *SO_m_FLDoorRatSts)
{
  switch (REL_DW.is_SwValid_p) {
   case REL_IN_Idle_p:
    if ((*SI_b_DoorInBtnSts_prev_g != REL_DW.SI_b_DoorInBtnSts_start_p) &&
        REL_DW.SI_b_DoorInBtnSts_start_p) {
      REL_DW.is_SwValid_p = REL_IN_Once_l;
      REL_DW.temporalCounter_i4_f = 0U;
    }
    break;

   case REL_IN_Once_l:
    if ((*SI_b_DoorInBtnSts_prev_g != REL_DW.SI_b_DoorInBtnSts_start_p) &&
        REL_DW.SI_b_DoorInBtnSts_start_p) {
      REL_DW.is_SwValid_p = REL_IN_Twice_k;
      REL_DW.temporalCounter_i4_f = 0U;
      REL_DW.SL_b_DoorInBtnValid_h = true;
    } else if (REL_DW.temporalCounter_i4_f >= 200) {
      REL_DW.is_SwValid_p = REL_IN_Idle_p;
      REL_DW.SL_b_DoorInBtnValid_h = false;
    }
    break;

   default:
    /* case IN_Twice: */
    if (REL_DW.temporalCounter_i4_f >= 3) {
      REL_DW.is_SwValid_p = REL_IN_Idle_p;
      REL_DW.SL_b_DoorInBtnValid_h = false;
    }
    break;
  }

  if (REL_DW.is_RlsReq_b == REL_IN_Idle_p) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion12'
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     */
    if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) || (*DataTypeConversion14 ==
          Gear_P)) && ((*SL_b_DoorInBtnValid_prev_e !=
                        REL_DW.SL_b_DoorInBtnValid_start_m) &&
                       REL_DW.SL_b_DoorInBtnValid_start_m)) {
      REL_DW.is_RlsReq_b = REL_IN_Trigger_d;
      switch (*DataTypeConversion12) {
       case Door_Lock:
        REL_DW.is_Trigger_a = REL_IN_DoorLock_j;
        REL_DW.is_DoorLock_j = REL_IN_UnlockReq_e;
        REL_DW.temporalCounter_i1_g = 0U;
        REL_B.SO_m_UnlockReq_i = Unlock_Req;
        break;

       case Door_Unlock:
        REL_DW.is_Trigger_a = REL_IN_DoorUnlock_c3;
        break;

       default:
        REL_DW.is_Trigger_a = REL_IN_Error_p;
        break;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion12'
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     */
    /* case IN_Trigger: */
  } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) && (*DataTypeConversion14
    != Gear_P)) || ((*DataTypeConversion12 == Door_Unlock) &&
                    (*SO_m_FLDoorRatSts == Rat_Unlock))) {
    REL_DW.is_DoorLock_j = 0;
    REL_DW.is_Trigger_a = 0;
    REL_DW.is_RlsReq_b = REL_IN_Idle_p;
  } else {
    switch (REL_DW.is_Trigger_a) {
     case REL_IN_DoorLock_j:
      switch (REL_DW.is_DoorLock_j) {
       case REL_IN_UnlockFail_p:
        REL_DW.is_DoorLock_j = 0;
        REL_DW.is_Trigger_a = 0;
        REL_DW.is_RlsReq_b = REL_IN_Idle_p;
        break;

       case REL_IN_UnlockReq_e:
        if (*DataTypeConversion12 == Door_Unlock) {
          REL_DW.is_DoorLock_j = REL_IN_UnlockSuccess_p;
        } else if ((REL_DW.temporalCounter_i1_g >= 50) && (*DataTypeConversion12
                    == Door_Lock)) {
          REL_DW.is_DoorLock_j = REL_IN_UnlockFail_p;
        } else if (REL_DW.temporalCounter_i1_g == 5) {
          REL_B.SO_m_UnlockReq_i = Unlock_Idle;
        }
        break;

       default:
        /* case IN_UnlockSuccess: */
        if (*SO_m_FLDoorRatSts != Rat_Unlock) {
          REL_DW.is_DoorLock_j = 0;
          REL_DW.is_Trigger_a = REL_IN_Release_p;
          REL_DW.temporalCounter_i1_g = 0U;
          REL_B.SO_b_DoorRlsReq_d = true;
          REL_B.SO_e_DoorRlsDelayTime_k = 20U;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock_c3:
      if (*SO_m_FLDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_a = REL_IN_Release_p;
        REL_DW.temporalCounter_i1_g = 0U;
        REL_B.SO_b_DoorRlsReq_d = true;
        REL_B.SO_e_DoorRlsDelayTime_k = 20U;
      }
      break;

     case REL_IN_Error_p:
      REL_DW.is_Trigger_a = 0;
      REL_DW.is_RlsReq_b = REL_IN_Idle_p;
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i1_g >= 5) {
        REL_B.SO_b_DoorRlsReq_d = false;
        REL_B.SO_e_DoorRlsDelayTime_k = 0U;
        REL_DW.is_Trigger_a = 0;
        REL_DW.is_RlsReq_b = REL_IN_Idle_p;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/FLDoorRlsReq' */
static void REL_DoorHndBtn_f(const boolean_T *SI_b_DoorHndBtnSts_prev_i, const
  boolean_T *SL_b_DoorHndBtnValid_prev_k, const Door_Sts_E *DataTypeConversion12,
  const Gear_Posn_E *DataTypeConversion14, const Rat_Sts_E *SO_m_FLDoorRatSts)
{
  if (REL_DW.is_RlsReq_o == REL_IN_Idle_p) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion12'
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VbOUT_DHM_BdcDrivDoorHandButtonSts_flg_VbOUT_DHM_BdcDrivDoorHandButtonSts_flg'
     */
    if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) || (*DataTypeConversion14 ==
          Gear_P)) && (!REL_U.VbOUT_DHM_BdcDrivDoorHandButton) &&
        ((*SL_b_DoorHndBtnValid_prev_k != REL_DW.SL_b_DoorHndBtnValid_start_l) &&
         REL_DW.SL_b_DoorHndBtnValid_start_l)) {
      REL_DW.is_RlsReq_o = REL_IN_Trigger_d;
      switch (*DataTypeConversion12) {
       case Door_Lock:
        REL_DW.is_Trigger_i = REL_IN_DoorLock_j;
        REL_DW.is_DoorLock_p = REL_IN_UnlockReq_e;
        REL_DW.temporalCounter_i2_k = 0U;
        REL_B.SO_m_UnlockReq_i = Unlock_PE;
        break;

       case Door_Unlock:
        REL_DW.is_Trigger_i = REL_IN_DoorUnlock_c3;
        break;

       default:
        REL_DW.is_Trigger_i = REL_IN_Error_p;
        break;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion12'
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VbOUT_DHM_BdcDrivDoorHandButtonSts_flg_VbOUT_DHM_BdcDrivDoorHandButtonSts_flg'
     */
    /* case IN_Trigger: */
  } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) && (*DataTypeConversion14
    != Gear_P)) || REL_U.VbOUT_DHM_BdcDrivDoorHandButton ||
             ((*DataTypeConversion12 == Door_Unlock) && (*SO_m_FLDoorRatSts ==
               Rat_Unlock))) {
    REL_DW.is_DoorLock_p = 0;
    REL_DW.is_Trigger_i = 0;
    REL_DW.is_RlsReq_o = REL_IN_Idle_p;
  } else {
    switch (REL_DW.is_Trigger_i) {
     case REL_IN_DoorLock_j:
      switch (REL_DW.is_DoorLock_p) {
       case REL_IN_UnlockFail_p:
        REL_DW.is_DoorLock_p = 0;
        REL_DW.is_Trigger_i = 0;
        REL_DW.is_RlsReq_o = REL_IN_Idle_p;
        break;

       case REL_IN_UnlockReq_e:
        if (*DataTypeConversion12 == Door_Unlock) {
          REL_DW.is_DoorLock_p = REL_IN_UnlockSuccess_p;
        } else if ((REL_DW.temporalCounter_i2_k >= 50) && (*DataTypeConversion12
                    == Door_Lock)) {
          REL_DW.is_DoorLock_p = REL_IN_UnlockFail_p;
        } else if (REL_DW.temporalCounter_i2_k == 5) {
          REL_B.SO_m_UnlockReq_i = Unlock_Idle;
        }
        break;

       default:
        /* case IN_UnlockSuccess: */
        if (*SO_m_FLDoorRatSts != Rat_Unlock) {
          REL_DW.is_DoorLock_p = 0;
          REL_DW.is_Trigger_i = REL_IN_Release_p;
          REL_DW.temporalCounter_i2_k = 0U;
          REL_B.SO_b_DoorRlsReq_d = true;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock_c3:
      if (*SO_m_FLDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_i = REL_IN_Release_p;
        REL_DW.temporalCounter_i2_k = 0U;
        REL_B.SO_b_DoorRlsReq_d = true;
      }
      break;

     case REL_IN_Error_p:
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i2_k >= 5) {
        REL_B.SO_b_DoorRlsReq_d = false;
        REL_DW.is_Trigger_i = 0;
        REL_DW.is_RlsReq_o = REL_IN_Idle_p;
      }
      break;
    }
  }

  switch (REL_DW.is_SwValid_d) {
   case REL_IN_Idle_p:
    if ((*SI_b_DoorHndBtnSts_prev_i != REL_DW.SI_b_DoorHndBtnSts_start_p) &&
        REL_DW.SI_b_DoorHndBtnSts_start_p) {
      REL_DW.is_SwValid_d = REL_IN_Press_p;
      REL_DW.temporalCounter_i6_n = 0U;
    }
    break;

   case REL_IN_Press_p:
    if ((*SI_b_DoorHndBtnSts_prev_i != REL_DW.SI_b_DoorHndBtnSts_start_p) &&
        (!REL_DW.SI_b_DoorHndBtnSts_start_p)) {
      REL_DW.is_SwValid_d = REL_IN_Release_pcz;
      REL_DW.temporalCounter_i6_n = 0U;
      REL_DW.SL_b_DoorHndBtnValid_a = true;
    } else if (REL_DW.temporalCounter_i6_n >= 100) {
      REL_DW.is_SwValid_d = REL_IN_Idle_p;
      REL_DW.SL_b_DoorHndBtnValid_a = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (REL_DW.temporalCounter_i6_n >= 3) {
      REL_DW.is_SwValid_d = REL_IN_Idle_p;
      REL_DW.SL_b_DoorHndBtnValid_a = false;
    }
    break;
  }
}

/* Function for Chart: '<S3>/FRDoorRlsReq' */
static void REL_DoorInBtn_o(const boolean_T *SI_b_DoorInBtnSts_prev, const
  boolean_T *SL_b_DoorInBtnValid_prev, const Door_Sts_E *DataTypeConversion13,
  const Gear_Posn_E *DataTypeConversion14, const Rat_Sts_E *SO_m_FRDoorRatSts)
{
  switch (REL_DW.is_SwValid) {
   case REL_IN_Idle_p:
    if ((*SI_b_DoorInBtnSts_prev != REL_DW.SI_b_DoorInBtnSts_start) &&
        REL_DW.SI_b_DoorInBtnSts_start) {
      REL_DW.is_SwValid = REL_IN_Once_l;
      REL_DW.temporalCounter_i4 = 0U;
    }
    break;

   case REL_IN_Once_l:
    if ((*SI_b_DoorInBtnSts_prev != REL_DW.SI_b_DoorInBtnSts_start) &&
        REL_DW.SI_b_DoorInBtnSts_start) {
      REL_DW.is_SwValid = REL_IN_Twice_k;
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
      REL_DW.is_RlsReq = REL_IN_Trigger_d;
      switch (*DataTypeConversion13) {
       case Door_Lock:
        REL_DW.is_Trigger = REL_IN_DoorLock_j;
        REL_DW.is_DoorLock = REL_IN_UnlockReq_e;
        REL_DW.temporalCounter_i1_m = 0U;
        REL_B.SO_m_UnlockReq_d = Unlock_Req;
        break;

       case Door_Unlock:
        REL_DW.is_Trigger = REL_IN_DoorUnlock_c3;
        break;

       default:
        REL_DW.is_Trigger = REL_IN_Error_p;
        break;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion13'
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     */
    /* case IN_Trigger: */
  } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) && (*DataTypeConversion14
    != Gear_P)) || ((*DataTypeConversion13 == Door_Unlock) &&
                    (*SO_m_FRDoorRatSts == Rat_Unlock))) {
    REL_DW.is_DoorLock = 0;
    REL_DW.is_Trigger = 0;
    REL_DW.is_RlsReq = REL_IN_Idle_p;
  } else {
    switch (REL_DW.is_Trigger) {
     case REL_IN_DoorLock_j:
      switch (REL_DW.is_DoorLock) {
       case REL_IN_UnlockFail_p:
        REL_DW.is_DoorLock = 0;
        REL_DW.is_Trigger = 0;
        REL_DW.is_RlsReq = REL_IN_Idle_p;
        break;

       case REL_IN_UnlockReq_e:
        if (*DataTypeConversion13 == Door_Unlock) {
          REL_DW.is_DoorLock = REL_IN_UnlockSuccess_p;
        } else if ((REL_DW.temporalCounter_i1_m >= 50) && (*DataTypeConversion13
                    == Door_Lock)) {
          REL_DW.is_DoorLock = REL_IN_UnlockFail_p;
        } else if (REL_DW.temporalCounter_i1_m == 5) {
          REL_B.SO_m_UnlockReq_d = Unlock_Idle;
        }
        break;

       default:
        /* case IN_UnlockSuccess: */
        if (*SO_m_FRDoorRatSts != Rat_Unlock) {
          REL_DW.is_DoorLock = 0;
          REL_DW.is_Trigger = REL_IN_Release_p;
          REL_DW.temporalCounter_i1_m = 0U;
          REL_B.SO_b_DoorRlsReq_jd = true;
          REL_B.SO_e_DoorRlsDelayTime_g = 20U;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock_c3:
      if (*SO_m_FRDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger = REL_IN_Release_p;
        REL_DW.temporalCounter_i1_m = 0U;
        REL_B.SO_b_DoorRlsReq_jd = true;
        REL_B.SO_e_DoorRlsDelayTime_g = 20U;
      }
      break;

     case REL_IN_Error_p:
      REL_DW.is_Trigger = 0;
      REL_DW.is_RlsReq = REL_IN_Idle_p;
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i1_m >= 5) {
        REL_B.SO_b_DoorRlsReq_jd = false;
        REL_B.SO_e_DoorRlsDelayTime_g = 0U;
        REL_DW.is_Trigger = 0;
        REL_DW.is_RlsReq = REL_IN_Idle_p;
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/FRDoorRlsReq' */
static void REL_DoorHndBtn_m(const boolean_T *SI_b_DoorHndBtnSts_prev, const
  boolean_T *SL_b_DoorHndBtnValid_prev, const Door_Sts_E *DataTypeConversion13,
  const Gear_Posn_E *DataTypeConversion14, const Rat_Sts_E *SO_m_FRDoorRatSts)
{
  if (REL_DW.is_RlsReq_g == REL_IN_Idle_p) {
    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion13'
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VbOUT_DHM_BdcPassDoorHandButtonSts_flg_VbOUT_DHM_BdcPassDoorHandButtonSts_flg'
     */
    if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) || (*DataTypeConversion14 ==
          Gear_P)) && (!REL_U.VbOUT_DHM_BdcPassDoorHandButton) &&
        ((*SL_b_DoorHndBtnValid_prev != REL_DW.SL_b_DoorHndBtnValid_start) &&
         REL_DW.SL_b_DoorHndBtnValid_start)) {
      REL_DW.is_RlsReq_g = REL_IN_Trigger_d;
      switch (*DataTypeConversion13) {
       case Door_Lock:
        REL_DW.is_Trigger_d = REL_IN_DoorLock_j;
        REL_DW.is_DoorLock_f = REL_IN_UnlockReq_e;
        REL_DW.temporalCounter_i2 = 0U;
        REL_B.SO_m_UnlockReq_d = Unlock_PE;
        break;

       case Door_Unlock:
        REL_DW.is_Trigger_d = REL_IN_DoorUnlock_c3;
        break;

       default:
        REL_DW.is_Trigger_d = REL_IN_Error_p;
        break;
      }
    }

    /* Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion13'
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
     *  Inport: '<Root>/VbOUT_DHM_BdcPassDoorHandButtonSts_flg_VbOUT_DHM_BdcPassDoorHandButtonSts_flg'
     */
    /* case IN_Trigger: */
  } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
              (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) && (*DataTypeConversion14
    != Gear_P)) || REL_U.VbOUT_DHM_BdcPassDoorHandButton ||
             ((*DataTypeConversion13 == Door_Unlock) && (*SO_m_FRDoorRatSts ==
               Rat_Unlock))) {
    REL_DW.is_DoorLock_f = 0;
    REL_DW.is_Trigger_d = 0;
    REL_DW.is_RlsReq_g = REL_IN_Idle_p;
  } else {
    switch (REL_DW.is_Trigger_d) {
     case REL_IN_DoorLock_j:
      switch (REL_DW.is_DoorLock_f) {
       case REL_IN_UnlockFail_p:
        REL_DW.is_DoorLock_f = 0;
        REL_DW.is_Trigger_d = 0;
        REL_DW.is_RlsReq_g = REL_IN_Idle_p;
        break;

       case REL_IN_UnlockReq_e:
        if (*DataTypeConversion13 == Door_Unlock) {
          REL_DW.is_DoorLock_f = REL_IN_UnlockSuccess_p;
        } else if ((REL_DW.temporalCounter_i2 >= 50) && (*DataTypeConversion13 ==
                    Door_Lock)) {
          REL_DW.is_DoorLock_f = REL_IN_UnlockFail_p;
        } else if (REL_DW.temporalCounter_i2 == 5) {
          REL_B.SO_m_UnlockReq_d = Unlock_Idle;
        }
        break;

       default:
        /* case IN_UnlockSuccess: */
        if (*SO_m_FRDoorRatSts != Rat_Unlock) {
          REL_DW.is_DoorLock_f = 0;
          REL_DW.is_Trigger_d = REL_IN_Release_p;
          REL_DW.temporalCounter_i2 = 0U;
          REL_B.SO_b_DoorRlsReq_jd = true;
        }
        break;
      }
      break;

     case REL_IN_DoorUnlock_c3:
      if (*SO_m_FRDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_d = REL_IN_Release_p;
        REL_DW.temporalCounter_i2 = 0U;
        REL_B.SO_b_DoorRlsReq_jd = true;
      }
      break;

     case REL_IN_Error_p:
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i2 >= 5) {
        REL_B.SO_b_DoorRlsReq_jd = false;
        REL_DW.is_Trigger_d = 0;
        REL_DW.is_RlsReq_g = REL_IN_Idle_p;
      }
      break;
    }
  }

  switch (REL_DW.is_SwValid_m) {
   case REL_IN_Idle_p:
    if ((*SI_b_DoorHndBtnSts_prev != REL_DW.SI_b_DoorHndBtnSts_start) &&
        REL_DW.SI_b_DoorHndBtnSts_start) {
      REL_DW.is_SwValid_m = REL_IN_Press_p;
      REL_DW.temporalCounter_i6 = 0U;
    }
    break;

   case REL_IN_Press_p:
    if ((*SI_b_DoorHndBtnSts_prev != REL_DW.SI_b_DoorHndBtnSts_start) &&
        (!REL_DW.SI_b_DoorHndBtnSts_start)) {
      REL_DW.is_SwValid_m = REL_IN_Release_pcz;
      REL_DW.temporalCounter_i6 = 0U;
      REL_DW.SL_b_DoorHndBtnValid = true;
    } else if (REL_DW.temporalCounter_i6 >= 100) {
      REL_DW.is_SwValid_m = REL_IN_Idle_p;
      REL_DW.SL_b_DoorHndBtnValid = false;
    }
    break;

   default:
    /* case IN_Release: */
    if (REL_DW.temporalCounter_i6 >= 3) {
      REL_DW.is_SwValid_m = REL_IN_Idle_p;
      REL_DW.SL_b_DoorHndBtnValid = false;
    }
    break;
  }
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
  uint8_T SO_e_MotorCmd_o;
  uint8_T SO_e_MotorPwm_f;
  boolean_T Compare;
  boolean_T SI_b_CrashSts_prev;
  boolean_T SI_b_DoorAutoRlsReq_prev_g;
  boolean_T SI_b_DoorHndBtnSts_prev_i;
  boolean_T SI_b_DoorInBtnSts_prev_g;
  boolean_T SL_b_CentAllDoorBtnValid_prev_k;
  boolean_T SL_b_CentSingleDoorBtnValid_p_g;
  boolean_T SL_b_DoorHndBtnValid_prev_k;
  boolean_T SL_b_DoorHndPullValid_prev_a;
  boolean_T SL_b_FLDoorHndPullSts;
  boolean_T SL_b_FLDoorInBtnSts;
  boolean_T SL_b_FRDoorHndPullSts;
  boolean_T SL_b_FRDoorInBtnSts;
  boolean_T SL_b_RLDoorInBtnSts;

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* DataTypeConversion: '<S3>/Data Type Conversion12' incorporates:
   *  Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig'
   */
  DataTypeConversion12 = REL_U.VeOUT_DLK_BdcDrvrDoorLockSts_si;

  /* DataTypeConversion: '<S3>/Data Type Conversion13' incorporates:
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   */
  DataTypeConversion13 = REL_U.VeOUT_DLK_BCMPassengerDoorLockS;

  /* DataTypeConversion: '<S3>/Data Type Conversion14' incorporates:
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   */
  DataTypeConversion14 = REL_U.VeINP_CAN_VcuGearPosn_sig_VeINP;

  /* DataTypeConversion: '<S3>/Data Type Conversion15' incorporates:
   *  Inport: '<Root>/VeOUT_DHM_BDCDrvrDoorHndSts_sig_VeOUT_DHM_BDCDrvrDoorHndSts_sig'
   */
  DataTypeConversion15 = REL_U.VeOUT_DHM_BDCDrvrDoorHndSts_sig;

  /* DataTypeConversion: '<S3>/Data Type Conversion16' incorporates:
   *  Inport: '<Root>/VeOUT_DHM_BDCPassDoorHndSts_sig_VeOUT_DHM_BDCPassDoorHndSts_sig'
   */
  DataTypeConversion16 = REL_U.VeOUT_DHM_BDCPassDoorHndSts_sig;

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
      REL_B.SO_b_DoorAutoRlsSetSts = true;
      REL_DW.SL_e_DoorAutoRlsSetBackup = 1U;
    } else if ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si == 2) ||
               ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si != 1) &&
                (REL_DW.SL_e_DoorAutoRlsSetBackup == 2))) {
      REL_B.SO_b_DoorAutoRlsSetSts = false;
      REL_DW.SL_e_DoorAutoRlsSetBackup = 2U;
    } else {
      switch (REL_U.VeINP_EPRM_BdcDrvrDoorLockSetSt) {
       case 1:
        REL_B.SO_b_DoorAutoRlsSetSts = true;
        break;

       case 0:
        REL_B.SO_b_DoorAutoRlsSetSts = false;
        break;
      }
    }
  } else if ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si == 1) ||
             ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si != 2) &&
              (REL_DW.SL_e_DoorAutoRlsSetBackup == 1))) {
    REL_B.SO_b_DoorAutoRlsSetSts = true;
    REL_DW.SL_e_DoorAutoRlsSetBackup = 1U;
  } else if ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si == 2) ||
             ((REL_U.VeINP_CAN_CdcDrvrDoorLockSet_si != 1) &&
              (REL_DW.SL_e_DoorAutoRlsSetBackup == 2))) {
    REL_B.SO_b_DoorAutoRlsSetSts = false;
    REL_DW.SL_e_DoorAutoRlsSetBackup = 2U;
  } else {
    switch (REL_U.VeINP_EPRM_BdcDrvrDoorLockSetSt) {
     case 1:
      REL_B.SO_b_DoorAutoRlsSetSts = true;
      break;

     case 0:
      REL_B.SO_b_DoorAutoRlsSetSts = false;
      break;
    }
  }

  /* End of Chart: '<S3>/DoorAutoRlsSts' */

  /* Chart: '<S3>/DoorRatSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg'
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   *  Inport: '<Root>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg'
   *  Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg'
   */
  if (REL_DW.is_active_c3_REL == 0U) {
    real_T tmp;
    REL_DW.is_active_c3_REL = 1U;
    tmp = REL_GetDoorRatSts((real_T)REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_,
      (real_T)REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_);
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
      (real_T)REL_U.VbINP_HWA_FRDoorAjar_flg_VbINP_);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8_T)(int32_T)tmp);
      } else {
        SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((real_T)REL_U.VbINP_HWA_RRDoorAjar_flg_VbINP_,
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
      (real_T)REL_U.VbINP_HWA_RLDoorAjar_flg_VbINP_);
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
      (real_T)REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_);
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
      (real_T)REL_U.VbINP_HWA_FRDoorAjar_flg_VbINP_);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8_T)(int32_T)tmp);
      } else {
        SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      SO_m_FRDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((real_T)REL_U.VbINP_HWA_RRDoorAjar_flg_VbINP_,
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
      (real_T)REL_U.VbINP_HWA_RLDoorAjar_flg_VbINP_);
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
    REL_enter_atomic_NoCrash(&SL_b_FLDoorInBtnSts, &SL_b_FRDoorInBtnSts,
      &SL_b_RLDoorInBtnSts, &SI_b_CrashSts_prev, &SL_b_FLDoorHndPullSts,
      &SL_b_FRDoorHndPullSts);
  } else if (REL_DW.is_c23_REL == REL_IN_Crash) {
    if (REL_DW.temporalCounter_i1 >= 1000) {
      REL_DW.is_c23_REL = REL_IN_NoCrash;
      REL_enter_atomic_NoCrash(&SL_b_FLDoorInBtnSts, &SL_b_FRDoorInBtnSts,
        &SL_b_RLDoorInBtnSts, &SI_b_CrashSts_prev, &SL_b_FLDoorHndPullSts,
        &SL_b_FRDoorHndPullSts);
    } else {
      SL_b_FLDoorInBtnSts = false;
      SL_b_FRDoorInBtnSts = false;
      SL_b_RLDoorInBtnSts = false;
      SI_b_CrashSts_prev = false;
      SL_b_FLDoorHndPullSts = false;
      SL_b_FRDoorHndPullSts = false;
      REL_B.SL_b_RLDoorHndPullSts = false;
      REL_B.SL_b_RRDoorHndPullSts = false;
      REL_B.SL_b_FLDoorHndBtnSts = false;
      REL_B.SL_b_FRDoorHndBtnSts = false;
      REL_B.SL_b_RLDoorHndBtnSts = false;
      REL_B.SL_b_RRDoorHndBtnSts = false;
    }

    /* case IN_NoCrash: */
  } else if ((SI_b_CrashSts_prev != REL_DW.SI_b_CrashSts_start) &&
             REL_DW.SI_b_CrashSts_start) {
    REL_DW.is_c23_REL = REL_IN_Crash;
    REL_DW.temporalCounter_i1 = 0U;
    SL_b_FLDoorInBtnSts = false;
    SL_b_FRDoorInBtnSts = false;
    SL_b_RLDoorInBtnSts = false;
    SI_b_CrashSts_prev = false;
    SL_b_FLDoorHndPullSts = false;
    SL_b_FRDoorHndPullSts = false;
    REL_B.SL_b_RLDoorHndPullSts = false;
    REL_B.SL_b_RRDoorHndPullSts = false;
    REL_B.SL_b_FLDoorHndBtnSts = false;
    REL_B.SL_b_FRDoorHndBtnSts = false;
    REL_B.SL_b_RLDoorHndBtnSts = false;
    REL_B.SL_b_RRDoorHndBtnSts = false;
  } else {
    SL_b_FLDoorInBtnSts = REL_U.VbINP_HWA_FLDoorButton_flg_VbIN;
    SL_b_FRDoorInBtnSts = REL_U.VbINP_HWA_FRDoorButton_flg_VbIN;
    SL_b_RLDoorInBtnSts = REL_U.VbINP_HWA_RLDoorButton_flg_VbIN;
    SI_b_CrashSts_prev = REL_U.VbINP_HWA_RRDoorButton_flg_VbIN;
    SL_b_FLDoorHndPullSts = REL_U.VbINP_HWA_FLDoorOutButton_flg_V;
    SL_b_FRDoorHndPullSts = REL_U.VbINP_HWA_FRDoorOutButton_flg_V;
    REL_B.SL_b_RLDoorHndPullSts = REL_U.VbINP_HWA_RLDoorOutButton_flg_V;
    REL_B.SL_b_RRDoorHndPullSts = REL_U.VbINP_HWA_RRDoorOutButton_flg_V;
    REL_B.SL_b_FLDoorHndBtnSts = REL_U.VbINP_HWA_FLDoorHandleSW_flg_Vb;
    REL_B.SL_b_FRDoorHndBtnSts = REL_U.VbINP_HWA_FRDoorHandleSW_flg_Vb;
    REL_B.SL_b_RLDoorHndBtnSts = REL_U.VbINP_HWA_RLDoorHandleSW_flg_Vb;
    REL_B.SL_b_RRDoorHndBtnSts = REL_U.VbINP_HWA_RRDoorHandleSW_flg_Vb;
  }

  /* End of Chart: '<S3>/DoorSwSts' */

  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<S19>/Constant'
   *  Inport: '<Root>/VeOUT_PDU_BcmPowerStatusFeedback_sig_VeOUT_PDU_BcmPowerStatusFeedback_sig'
   */
  Compare = (REL_U.VeOUT_PDU_BcmPowerStatusFeedbac == 0);

  /* Chart: '<S3>/FLDoorRlsReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion12'
   *  DataTypeConversion: '<S3>/Data Type Conversion14'
   *  DataTypeConversion: '<S3>/Data Type Conversion15'
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbOUT_DLK_BdcDrvrDoorLockOpenReq_flg_VbOUT_DLK_BdcDrvrDoorLockOpenReq_flg'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   */
  if (REL_DW.temporalCounter_i1_g < 63U) {
    REL_DW.temporalCounter_i1_g++;
  }

  if (REL_DW.temporalCounter_i2_k < 63U) {
    REL_DW.temporalCounter_i2_k++;
  }

  if (REL_DW.temporalCounter_i3_d < 63U) {
    REL_DW.temporalCounter_i3_d++;
  }

  if (REL_DW.temporalCounter_i4_f < 255U) {
    REL_DW.temporalCounter_i4_f++;
  }

  if (REL_DW.temporalCounter_i5_e < 7U) {
    REL_DW.temporalCounter_i5_e++;
  }

  if (REL_DW.temporalCounter_i6_n < 127U) {
    REL_DW.temporalCounter_i6_n++;
  }

  if (REL_DW.temporalCounter_i7_m < 7U) {
    REL_DW.temporalCounter_i7_m++;
  }

  SI_b_DoorInBtnSts_prev_g = REL_DW.SI_b_DoorInBtnSts_start_p;
  REL_DW.SI_b_DoorInBtnSts_start_p = SL_b_FLDoorInBtnSts;
  SL_b_FLDoorInBtnSts = REL_DW.SL_b_DoorInBtnValid_start_m;
  REL_DW.SL_b_DoorInBtnValid_start_m = REL_DW.SL_b_DoorInBtnValid_h;
  SL_b_DoorHndPullValid_prev_a = REL_DW.SL_b_DoorHndPullValid_start_m;
  REL_DW.SL_b_DoorHndPullValid_start_m = REL_DW.SL_b_DoorHndPullValid_h;
  SI_b_DoorHndBtnSts_prev_i = REL_DW.SI_b_DoorHndBtnSts_start_p;
  REL_DW.SI_b_DoorHndBtnSts_start_p = REL_B.SL_b_FLDoorHndBtnSts;
  SL_b_DoorHndBtnValid_prev_k = REL_DW.SL_b_DoorHndBtnValid_start_l;
  REL_DW.SL_b_DoorHndBtnValid_start_l = REL_DW.SL_b_DoorHndBtnValid_a;
  SL_b_CentSingleDoorBtnValid_p_g = REL_DW.SL_b_CentSingleDoorBtnValid_s_o;
  REL_DW.SL_b_CentSingleDoorBtnValid_s_o = REL_DW.SL_b_CentSingleDoorBtnValid_h;
  SL_b_CentAllDoorBtnValid_prev_k = REL_DW.SL_b_CentAllDoorBtnValid_star_k;
  REL_DW.SL_b_CentAllDoorBtnValid_star_k = REL_DW.SL_b_CentAllDoorBtnValid_a;
  SI_b_DoorAutoRlsReq_prev_g = REL_DW.SI_b_DoorAutoRlsReq_start_a;
  REL_DW.SI_b_DoorAutoRlsReq_start_a = REL_U.VbOUT_DLK_BdcDrvrDoorLockOpenRe;
  if (REL_DW.is_active_c5_DoorRlsReq_a == 0U) {
    REL_DW.is_active_c5_DoorRlsReq_a = 1U;
    REL_DW.is_SwValid_p = REL_IN_Idle_p;
    REL_DW.SL_b_DoorInBtnValid_h = false;
    REL_DW.is_RlsReq_b = REL_IN_Idle_p;
    REL_DW.SL_b_DoorHndPullValid_h = SL_b_FLDoorHndPullSts;
    REL_DW.is_RlsReq_a = REL_IN_Idle_p;
    REL_DW.is_RlsReq_o = REL_IN_Idle_p;
    REL_DW.is_SwValid_d = REL_IN_Idle_p;
    REL_DW.SL_b_DoorHndBtnValid_a = false;
    REL_DW.is_DoorCentral_j = REL_IN_Idle_p;
    REL_DW.SL_b_CentSingleDoorBtnValid_h = REL_U.VbINP_CAN_CdcDrvrDoorButtonSts_;
    REL_DW.SL_b_CentAllDoorBtnValid_a = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
    REL_DW.is_RlsReq_b4 = REL_IN_Idle_p;
  } else {
    REL_DoorInBtn_k(&SI_b_DoorInBtnSts_prev_g, &SL_b_FLDoorInBtnSts,
                    &DataTypeConversion12, &DataTypeConversion14,
                    &SO_m_FLDoorRatSts);
    REL_DW.SL_b_DoorHndPullValid_h = SL_b_FLDoorHndPullSts;
    if (REL_DW.is_RlsReq_a == REL_IN_Idle_p) {
      if ((!Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                         (DataTypeConversion14 == Gear_P)) &&
          (DataTypeConversion12 == Door_Unlock) && (DataTypeConversion15 ==
           Hnd_Unfold) && ((SL_b_DoorHndPullValid_prev_a !=
                            REL_DW.SL_b_DoorHndPullValid_start_m) &&
                           REL_DW.SL_b_DoorHndPullValid_start_m)) {
        REL_DW.is_RlsReq_a = REL_IN_Trigger_d;
        REL_DW.is_Trigger_p = REL_IN_DoorUnlock_c3m;
      }

      /* case IN_Trigger: */
    } else if (Compare || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                           (DataTypeConversion14 != Gear_P)) ||
               (DataTypeConversion12 != Door_Unlock) || (DataTypeConversion15 !=
                Hnd_Unfold) || (SO_m_FLDoorRatSts == Rat_Unlock)) {
      REL_DW.is_Trigger_p = 0;
      REL_DW.is_RlsReq_a = REL_IN_Idle_p;
    } else if (REL_DW.is_Trigger_p == REL_IN_DoorUnlock_c3m) {
      if (SO_m_FLDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_p = REL_IN_Release_pc;
        REL_DW.temporalCounter_i5_e = 0U;
        REL_B.SO_b_DoorRlsReq_d = true;
        REL_B.SO_e_DoorRlsDelayTime_k = 4U;
      }

      /* case IN_Release: */
    } else if (REL_DW.temporalCounter_i5_e >= 5) {
      REL_B.SO_b_DoorRlsReq_d = false;
      REL_B.SO_e_DoorRlsDelayTime_k = 0U;
      REL_DW.is_Trigger_p = 0;
      REL_DW.is_RlsReq_a = REL_IN_Idle_p;
    }

    REL_DoorHndBtn_f(&SI_b_DoorHndBtnSts_prev_i, &SL_b_DoorHndBtnValid_prev_k,
                     &DataTypeConversion12, &DataTypeConversion14,
                     &SO_m_FLDoorRatSts);
    if (REL_DW.is_DoorCentral_j == REL_IN_Idle_p) {
      if ((!Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                         (DataTypeConversion14 == Gear_P)) &&
          (((SL_b_CentSingleDoorBtnValid_p_g !=
             REL_DW.SL_b_CentSingleDoorBtnValid_s_o) &&
            REL_DW.SL_b_CentSingleDoorBtnValid_s_o) ||
           ((SL_b_CentAllDoorBtnValid_prev_k !=
             REL_DW.SL_b_CentAllDoorBtnValid_star_k) &&
            REL_DW.SL_b_CentAllDoorBtnValid_star_k))) {
        REL_DW.is_DoorCentral_j = REL_IN_Trigger_d;
        switch (DataTypeConversion12) {
         case Door_Lock:
          REL_DW.is_Trigger_h = REL_IN_DoorLock_j;
          REL_DW.is_DoorLock_cd = REL_IN_UnlockReq_e;
          REL_DW.temporalCounter_i3_d = 0U;
          REL_B.SO_m_UnlockReq_i = Unlock_Req;
          break;

         case Door_Unlock:
          REL_DW.is_Trigger_h = REL_IN_DoorUnlock_c3;
          break;

         default:
          REL_DW.is_Trigger_h = REL_IN_Error_p;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (Compare || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                           (DataTypeConversion14 != Gear_P)) ||
               ((DataTypeConversion12 == Door_Unlock) && (SO_m_FLDoorRatSts ==
                 Rat_Unlock))) {
      REL_DW.is_DoorLock_cd = 0;
      REL_DW.is_Trigger_h = 0;
      REL_DW.is_DoorCentral_j = REL_IN_Idle_p;
    } else {
      switch (REL_DW.is_Trigger_h) {
       case REL_IN_DoorLock_j:
        switch (REL_DW.is_DoorLock_cd) {
         case REL_IN_UnlockFail_p:
          REL_DW.is_DoorLock_cd = 0;
          REL_DW.is_Trigger_h = 0;
          REL_DW.is_DoorCentral_j = REL_IN_Idle_p;
          break;

         case REL_IN_UnlockReq_e:
          if (DataTypeConversion12 == Door_Unlock) {
            REL_DW.is_DoorLock_cd = REL_IN_UnlockSucess_e;
          } else if ((REL_DW.temporalCounter_i3_d >= 50) &&
                     (DataTypeConversion12 == Door_Lock)) {
            REL_DW.is_DoorLock_cd = REL_IN_UnlockFail_p;
          } else if (REL_DW.temporalCounter_i3_d == 5) {
            REL_B.SO_m_UnlockReq_i = Unlock_Idle;
          }
          break;

         default:
          /* case IN_UnlockSucess: */
          if (SO_m_FLDoorRatSts != Rat_Unlock) {
            REL_DW.is_DoorLock_cd = 0;
            REL_DW.is_Trigger_h = REL_IN_RELEASE_m;
            REL_DW.temporalCounter_i3_d = 0U;
            REL_B.SO_b_DoorRlsReq_d = true;
          }
          break;
        }
        break;

       case REL_IN_DoorUnlock_c3:
        if (SO_m_FLDoorRatSts != Rat_Unlock) {
          REL_DW.is_Trigger_h = REL_IN_RELEASE_m;
          REL_DW.temporalCounter_i3_d = 0U;
          REL_B.SO_b_DoorRlsReq_d = true;
        }
        break;

       case REL_IN_Error_p:
        REL_DW.is_Trigger_h = 0;
        REL_DW.is_DoorCentral_j = REL_IN_Idle_p;
        break;

       default:
        /* case IN_RELEASE: */
        if (REL_DW.temporalCounter_i3_d >= 5) {
          REL_B.SO_b_DoorRlsReq_d = false;
          REL_DW.is_Trigger_h = 0;
          REL_DW.is_DoorCentral_j = REL_IN_Idle_p;
        }
        break;
      }
    }

    REL_DW.SL_b_CentSingleDoorBtnValid_h = REL_U.VbINP_CAN_CdcDrvrDoorButtonSts_;
    REL_DW.SL_b_CentAllDoorBtnValid_a = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
    if (REL_DW.is_RlsReq_b4 == REL_IN_Idle_p) {
      if ((!Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                         (DataTypeConversion14 == Gear_P)) &&
          REL_B.SO_b_DoorAutoRlsSetSts && (DataTypeConversion12 == Door_Unlock) &&
          ((SI_b_DoorAutoRlsReq_prev_g != REL_DW.SI_b_DoorAutoRlsReq_start_a) &&
           REL_DW.SI_b_DoorAutoRlsReq_start_a)) {
        REL_DW.is_RlsReq_b4 = REL_IN_Trigger_d;
        REL_DW.is_Trigger_ih = REL_IN_DoorUnlock_c3m;
      }

      /* case IN_Trigger: */
    } else if (Compare || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                           (DataTypeConversion14 != Gear_P)) ||
               (!REL_B.SO_b_DoorAutoRlsSetSts) || (DataTypeConversion12 !=
                Door_Unlock) || (SO_m_FLDoorRatSts == Rat_Unlock)) {
      REL_DW.is_Trigger_ih = 0;
      REL_DW.is_RlsReq_b4 = REL_IN_Idle_p;
    } else if (REL_DW.is_Trigger_ih == REL_IN_DoorUnlock_c3m) {
      if (SO_m_FLDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_ih = REL_IN_Release_pc;
        REL_DW.temporalCounter_i7_m = 0U;
        REL_B.SO_b_DoorRlsReq_d = true;
      }

      /* case IN_Release: */
    } else if (REL_DW.temporalCounter_i7_m >= 5) {
      REL_B.SO_b_DoorRlsReq_d = false;
      REL_DW.is_Trigger_ih = 0;
      REL_DW.is_RlsReq_b4 = REL_IN_Idle_p;
    }
  }

  /* End of Chart: '<S3>/FLDoorRlsReq' */

  /* Chart: '<S3>/FLDoorRlsDriver' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg'
   *  Inport: '<Root>/VeINP_HWA_Voltage_100mV_VeINP_HWA_Voltage_100mV'
   */
  REL_FLDoorRlsDriver(REL_U.VeINP_HWA_Voltage_100mV_VeINP_H,
                      REL_B.SO_b_DoorRlsReq_d,
                      REL_U.VbINP_HWA_FLDoorAjar_flg_VbINP_,
                      REL_B.SO_e_DoorRlsDelayTime_k, &SO_e_MotorCmd_o,
                      &SO_e_MotorPwm_f, &SL_b_FLDoorHndPullSts,
                      &REL_DW.sf_FLDoorRlsDriver);

  /* Chart: '<S3>/FRDoorRlsReq' incorporates:
   *  Constant: '<S3>/Constant8'
   *  DataTypeConversion: '<S3>/Data Type Conversion13'
   *  DataTypeConversion: '<S3>/Data Type Conversion14'
   *  DataTypeConversion: '<S3>/Data Type Conversion16'
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   */
  if (REL_DW.temporalCounter_i1_m < 63U) {
    REL_DW.temporalCounter_i1_m++;
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

  SL_b_FLDoorHndPullSts = REL_DW.SI_b_DoorInBtnSts_start;
  REL_DW.SI_b_DoorInBtnSts_start = SL_b_FRDoorInBtnSts;
  SL_b_FRDoorInBtnSts = REL_DW.SL_b_DoorInBtnValid_start;
  REL_DW.SL_b_DoorInBtnValid_start = REL_DW.SL_b_DoorInBtnValid;
  SI_b_DoorInBtnSts_prev_g = REL_DW.SL_b_DoorHndPullValid_start;
  REL_DW.SL_b_DoorHndPullValid_start = REL_DW.SL_b_DoorHndPullValid;
  SL_b_FLDoorInBtnSts = REL_DW.SI_b_DoorHndBtnSts_start;
  REL_DW.SI_b_DoorHndBtnSts_start = REL_B.SL_b_FRDoorHndBtnSts;
  SL_b_DoorHndPullValid_prev_a = REL_DW.SL_b_DoorHndBtnValid_start;
  REL_DW.SL_b_DoorHndBtnValid_start = REL_DW.SL_b_DoorHndBtnValid;
  SI_b_DoorHndBtnSts_prev_i = REL_DW.SL_b_CentSingleDoorBtnValid_sta;
  REL_DW.SL_b_CentSingleDoorBtnValid_sta = REL_DW.SL_b_CentSingleDoorBtnValid;
  SL_b_DoorHndBtnValid_prev_k = REL_DW.SL_b_CentAllDoorBtnValid_start;
  REL_DW.SL_b_CentAllDoorBtnValid_start = REL_DW.SL_b_CentAllDoorBtnValid;
  REL_DW.SI_b_DoorAutoRlsReq_start = false;
  if (REL_DW.is_active_c5_DoorRlsReq == 0U) {
    REL_DW.is_active_c5_DoorRlsReq = 1U;
    REL_DW.is_SwValid = REL_IN_Idle_p;
    REL_DW.SL_b_DoorInBtnValid = false;
    REL_DW.is_RlsReq = REL_IN_Idle_p;
    REL_DW.SL_b_DoorHndPullValid = SL_b_FRDoorHndPullSts;
    REL_DW.is_RlsReq_j = REL_IN_Idle_p;
    REL_DW.is_RlsReq_g = REL_IN_Idle_p;
    REL_DW.is_SwValid_m = REL_IN_Idle_p;
    REL_DW.SL_b_DoorHndBtnValid = false;
    REL_DW.is_DoorCentral = REL_IN_Idle_p;
    REL_DW.SL_b_CentSingleDoorBtnValid = REL_U.VbINP_CAN_CdcPassDoorButtonSts_;
    REL_DW.SL_b_CentAllDoorBtnValid = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
    REL_DW.is_RlsReq_l = REL_IN_Idle_p;
  } else {
    REL_DoorInBtn_o(&SL_b_FLDoorHndPullSts, &SL_b_FRDoorInBtnSts,
                    &DataTypeConversion13, &DataTypeConversion14,
                    &SO_m_FRDoorRatSts);
    REL_DW.SL_b_DoorHndPullValid = SL_b_FRDoorHndPullSts;
    if (REL_DW.is_RlsReq_j == REL_IN_Idle_p) {
      if ((!Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                         (DataTypeConversion14 == Gear_P)) &&
          (DataTypeConversion13 == Door_Unlock) && (DataTypeConversion16 ==
           Hnd_Unfold) && ((SI_b_DoorInBtnSts_prev_g !=
                            REL_DW.SL_b_DoorHndPullValid_start) &&
                           REL_DW.SL_b_DoorHndPullValid_start)) {
        REL_DW.is_RlsReq_j = REL_IN_Trigger_d;
        REL_DW.is_Trigger_m = REL_IN_DoorUnlock_c3m;
      }

      /* case IN_Trigger: */
    } else if (Compare || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                           (DataTypeConversion14 != Gear_P)) ||
               (DataTypeConversion13 != Door_Unlock) || (DataTypeConversion16 !=
                Hnd_Unfold) || (SO_m_FRDoorRatSts == Rat_Unlock)) {
      REL_DW.is_Trigger_m = 0;
      REL_DW.is_RlsReq_j = REL_IN_Idle_p;
    } else if (REL_DW.is_Trigger_m == REL_IN_DoorUnlock_c3m) {
      if (SO_m_FRDoorRatSts != Rat_Unlock) {
        REL_DW.is_Trigger_m = REL_IN_Release_pc;
        REL_DW.temporalCounter_i5 = 0U;
        REL_B.SO_b_DoorRlsReq_jd = true;
        REL_B.SO_e_DoorRlsDelayTime_g = 4U;
      }

      /* case IN_Release: */
    } else if (REL_DW.temporalCounter_i5 >= 5) {
      REL_B.SO_b_DoorRlsReq_jd = false;
      REL_B.SO_e_DoorRlsDelayTime_g = 0U;
      REL_DW.is_Trigger_m = 0;
      REL_DW.is_RlsReq_j = REL_IN_Idle_p;
    }

    REL_DoorHndBtn_m(&SL_b_FLDoorInBtnSts, &SL_b_DoorHndPullValid_prev_a,
                     &DataTypeConversion13, &DataTypeConversion14,
                     &SO_m_FRDoorRatSts);
    if (REL_DW.is_DoorCentral == REL_IN_Idle_p) {
      if ((!Compare) && (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
                          (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
                         (DataTypeConversion14 == Gear_P)) &&
          (((SI_b_DoorHndBtnSts_prev_i != REL_DW.SL_b_CentSingleDoorBtnValid_sta)
            && REL_DW.SL_b_CentSingleDoorBtnValid_sta) ||
           ((SL_b_DoorHndBtnValid_prev_k !=
             REL_DW.SL_b_CentAllDoorBtnValid_start) &&
            REL_DW.SL_b_CentAllDoorBtnValid_start))) {
        REL_DW.is_DoorCentral = REL_IN_Trigger_d;
        switch (DataTypeConversion13) {
         case Door_Lock:
          REL_DW.is_Trigger_e = REL_IN_DoorLock_j;
          REL_DW.is_DoorLock_c = REL_IN_UnlockReq_e;
          REL_DW.temporalCounter_i3 = 0U;
          REL_B.SO_m_UnlockReq_d = Unlock_Req;
          break;

         case Door_Unlock:
          REL_DW.is_Trigger_e = REL_IN_DoorUnlock_c3;
          break;

         default:
          REL_DW.is_Trigger_e = REL_IN_Error_p;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (Compare || ((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                           (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                           (DataTypeConversion14 != Gear_P)) ||
               ((DataTypeConversion13 == Door_Unlock) && (SO_m_FRDoorRatSts ==
                 Rat_Unlock))) {
      REL_DW.is_DoorLock_c = 0;
      REL_DW.is_Trigger_e = 0;
      REL_DW.is_DoorCentral = REL_IN_Idle_p;
    } else {
      switch (REL_DW.is_Trigger_e) {
       case REL_IN_DoorLock_j:
        switch (REL_DW.is_DoorLock_c) {
         case REL_IN_UnlockFail_p:
          REL_DW.is_DoorLock_c = 0;
          REL_DW.is_Trigger_e = 0;
          REL_DW.is_DoorCentral = REL_IN_Idle_p;
          break;

         case REL_IN_UnlockReq_e:
          if (DataTypeConversion13 == Door_Unlock) {
            REL_DW.is_DoorLock_c = REL_IN_UnlockSucess_e;
          } else if ((REL_DW.temporalCounter_i3 >= 50) && (DataTypeConversion13 ==
                      Door_Lock)) {
            REL_DW.is_DoorLock_c = REL_IN_UnlockFail_p;
          } else if (REL_DW.temporalCounter_i3 == 5) {
            REL_B.SO_m_UnlockReq_d = Unlock_Idle;
          }
          break;

         default:
          /* case IN_UnlockSucess: */
          if (SO_m_FRDoorRatSts != Rat_Unlock) {
            REL_DW.is_DoorLock_c = 0;
            REL_DW.is_Trigger_e = REL_IN_RELEASE_m;
            REL_DW.temporalCounter_i3 = 0U;
            REL_B.SO_b_DoorRlsReq_jd = true;
          }
          break;
        }
        break;

       case REL_IN_DoorUnlock_c3:
        if (SO_m_FRDoorRatSts != Rat_Unlock) {
          REL_DW.is_Trigger_e = REL_IN_RELEASE_m;
          REL_DW.temporalCounter_i3 = 0U;
          REL_B.SO_b_DoorRlsReq_jd = true;
        }
        break;

       case REL_IN_Error_p:
        REL_DW.is_Trigger_e = 0;
        REL_DW.is_DoorCentral = REL_IN_Idle_p;
        break;

       default:
        /* case IN_RELEASE: */
        if (REL_DW.temporalCounter_i3 >= 5) {
          REL_B.SO_b_DoorRlsReq_jd = false;
          REL_DW.is_Trigger_e = 0;
          REL_DW.is_DoorCentral = REL_IN_Idle_p;
        }
        break;
      }
    }

    REL_DW.SL_b_CentSingleDoorBtnValid = REL_U.VbINP_CAN_CdcPassDoorButtonSts_;
    REL_DW.SL_b_CentAllDoorBtnValid = REL_U.VbINP_CAN_CdcAllDoorOpenButtonS;
    if (REL_DW.is_RlsReq_l != REL_IN_Idle_p) {
      /* case IN_Trigger: */
      REL_DW.is_Trigger_el = 0;
      REL_DW.is_RlsReq_l = REL_IN_Idle_p;
    }
  }

  /* End of Chart: '<S3>/FRDoorRlsReq' */

  /* Chart: '<S3>/FRDoorRlsDriver' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   *  Inport: '<Root>/VeINP_HWA_Voltage_100mV_VeINP_HWA_Voltage_100mV'
   */
  REL_FLDoorRlsDriver(REL_U.VeINP_HWA_Voltage_100mV_VeINP_H,
                      REL_B.SO_b_DoorRlsReq_jd,
                      REL_U.VbINP_HWA_FRDoorAjar_flg_VbINP_,
                      REL_B.SO_e_DoorRlsDelayTime_g, &SO_e_MotorCmd_o,
                      &SO_e_MotorPwm_f, &SL_b_FRDoorHndPullSts,
                      &REL_DW.sf_FRDoorRlsDriver);

  /* Chart: '<S3>/RLDoorRlsReq' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcLeReDoorButtonSts_flg_VbINP_CAN_CdcLeReDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbINP_HWA_LRChildLckSt_flg_VbINP_HWA_LRChildLckSt_flg'
   *  Inport: '<Root>/VbOUT_DHM_BdcPassDoorHandButtonSts_flg_VbOUT_DHM_BdcPassDoorHandButtonSts_flg'
   *  Inport: '<Root>/VeOUT_DHM_BDCLeReDoorHndSts_sig_VeOUT_DHM_BDCLeReDoorHndSts_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   */
  REL_RLDoorRlsReq(Compare, REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                   REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN, DataTypeConversion14,
                   DataTypeConversion13, SO_m_RLDoorRatSts, SL_b_RLDoorInBtnSts,
                   REL_B.SL_b_RLDoorHndPullSts, REL_B.SL_b_RLDoorHndBtnSts,
                   REL_U.VeOUT_DHM_BDCLeReDoorHndSts_sig,
                   REL_U.VbINP_CAN_CdcLeReDoorButtonSts_,
                   REL_U.VbINP_CAN_CdcAllDoorOpenButtonS,
                   REL_U.VbINP_HWA_LRChildLckSt_flg_VbIN, false, false,
                   REL_U.VbOUT_DHM_BdcPassDoorHandButton,
                   &REL_B.SO_b_DoorRlsReq_j, &REL_B.SO_e_DoorRlsDelayTime_d,
                   &REL_B.SO_m_UnlockReq_o, &REL_DW.sf_RLDoorRlsReq);

  /* Chart: '<S3>/RLDoorRlsDriver' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg'
   *  Inport: '<Root>/VeINP_HWA_Voltage_100mV_VeINP_HWA_Voltage_100mV'
   */
  REL_FLDoorRlsDriver(REL_U.VeINP_HWA_Voltage_100mV_VeINP_H,
                      REL_B.SO_b_DoorRlsReq_j,
                      REL_U.VbINP_HWA_RLDoorAjar_flg_VbINP_,
                      REL_B.SO_e_DoorRlsDelayTime_d, &SO_e_MotorCmd_o,
                      &SO_e_MotorPwm_f, &SL_b_RLDoorInBtnSts,
                      &REL_DW.sf_RLDoorRlsDriver);

  /* Chart: '<S3>/RRDoorRlsReq' incorporates:
   *  Constant: '<S3>/Constant3'
   *  Constant: '<S3>/Constant5'
   *  Inport: '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_CdcRiReDoorButtonSts_flg_VbINP_CAN_CdcRiReDoorButtonSts_flg'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbINP_HWA_RRChildLckSt_flg_VbINP_HWA_RRChildLckSt_flg'
   *  Inport: '<Root>/VbOUT_DHM_BdcPassDoorHandButtonSts_flg_VbOUT_DHM_BdcPassDoorHandButtonSts_flg'
   *  Inport: '<Root>/VeOUT_DHM_BDCRiReDoorHndSts_sig_VeOUT_DHM_BDCRiReDoorHndSts_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   */
  REL_RLDoorRlsReq(Compare, REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                   REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN, DataTypeConversion14,
                   DataTypeConversion13, SO_m_RRDoorRatSts, SI_b_CrashSts_prev,
                   REL_B.SL_b_RRDoorHndPullSts, REL_B.SL_b_RRDoorHndBtnSts,
                   REL_U.VeOUT_DHM_BDCRiReDoorHndSts_sig,
                   REL_U.VbINP_CAN_CdcRiReDoorButtonSts_,
                   REL_U.VbINP_CAN_CdcAllDoorOpenButtonS,
                   REL_U.VbINP_HWA_RRChildLckSt_flg_VbIN, false, false,
                   REL_U.VbOUT_DHM_BdcPassDoorHandButton, &REL_B.SO_b_DoorRlsReq,
                   &REL_B.SO_e_DoorRlsDelayTime, &REL_B.SO_m_UnlockReq,
                   &REL_DW.sf_RRDoorRlsReq);

  /* Chart: '<S3>/RRDoorRlsDriver' incorporates:
   *  Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg'
   *  Inport: '<Root>/VeINP_HWA_Voltage_100mV_VeINP_HWA_Voltage_100mV'
   */
  REL_FLDoorRlsDriver(REL_U.VeINP_HWA_Voltage_100mV_VeINP_H,
                      REL_B.SO_b_DoorRlsReq,
                      REL_U.VbINP_HWA_RRDoorAjar_flg_VbINP_,
                      REL_B.SO_e_DoorRlsDelayTime, &SO_e_MotorCmd_o,
                      &SO_e_MotorPwm_f, &SI_b_CrashSts_prev,
                      &REL_DW.sf_RRDoorRlsDriver);

  /* Chart: '<S3>/Unlock_Request' */
  if (REL_DW.is_active_c6_REL == 0U) {
    REL_DW.is_active_c6_REL = 1U;
  }

  /* End of Chart: '<S3>/Unlock_Request' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
  REL_Y.VbOUT_REL_BdcDrvrDoorLockSetSts = false;

  /* Outport: '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
  REL_Y.VbOUT_REL_BdcDrvrDoorLockSetS_h = false;

  /* Outport: '<Root>/VeOUT_REL_BcmDrvrDoorSwtSts_sig_VeOUT_REL_BcmDrvrDoorSwtSts_sig' */
  REL_Y.VeOUT_REL_BcmDrvrDoorSwtSts_sig = 0U;

  /* Outport: '<Root>/VeOUT_REL_BcmPassDoorSwtSts_sig_VeOUT_REL_BcmPassDoorSwtSts_sig' */
  REL_Y.VeOUT_REL_BcmPassDoorSwtSts_sig = 0U;

  /* Outport: '<Root>/VeOUT_REL_BcmLeReDoorSwtSts_sig_VeOUT_REL_BcmLeReDoorSwtSts_sig' */
  REL_Y.VeOUT_REL_BcmLeReDoorSwtSts_sig = 0U;

  /* Outport: '<Root>/VeOUT_REL_BcmRiReDoorSwtSts_sig_VeOUT_REL_BcmRiReDoorSwtSts_sig' */
  REL_Y.VeOUT_REL_BcmRiReDoorSwtSts_sig = 0U;

  /* Outport: '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig' */
  REL_Y.VeOUT_REL_BdcLFDoorRatSts_sig_V = 0U;

  /* Outport: '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig' */
  REL_Y.VeOUT_REL_BdcRFDoorRatSts_sig_V = 0U;

  /* Outport: '<Root>/VeOUT_REL_BdcLRDoorRatSts_sig_VeOUT_REL_BdcLRDoorRatSts_sig' */
  REL_Y.VeOUT_REL_BdcLRDoorRatSts_sig_V = 0U;

  /* Outport: '<Root>/VeOUT_REL_BdcRRDoorRatSts_sig_VeOUT_REL_BdcRRDoorRatSts_sig' */
  REL_Y.VeOUT_REL_BdcRRDoorRatSts_sig_V = 0U;

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

  /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
  REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = false;

  /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
  REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = false;

  /* Outport: '<Root>/VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg' */
  REL_Y.VbOUT_REL_FRDoorMotorA_flg_VbOU = false;

  /* Outport: '<Root>/VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg' */
  REL_Y.VbOUT_REL_FRDoorMotorB_flg_VbOU = false;

  /* Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg' */
  REL_Y.VbOUT_REL_RLDoorMotorA_flg_VbOU = false;

  /* Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg' */
  REL_Y.VbOUT_REL_RLDoorMotorB_flg_VbOU = false;

  /* Outport: '<Root>/VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg' */
  REL_Y.VbOUT_REL_RRDoorMotorA_flg_VbOU = false;

  /* Outport: '<Root>/VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg' */
  REL_Y.VbOUT_REL_RRDoorMotorB_flg_VbOU = false;

  /* Outport: '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
  REL_Y.VeOUT_REL_DLKReqUnlock_sig_VeOU = 0U;

  /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
  REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU = false;

  /* Outport: '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
  REL_Y.VbOUT_REL_FRDoorRlsReq_flg_VbOU = false;

  /* Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg' */
  REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU = false;

  /* Outport: '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg' */
  REL_Y.VbOUT_REL_RRDoorRlsReq_flg_VbOU = false;

  /* Outport: '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
  REL_Y.VeOUT_REL_FLDoorMotorSts_sig_Ve = 0U;

  /* Outport: '<Root>/VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig' */
  REL_Y.VeOUT_REL_FRDoorMotorSts_sig_Ve = 0U;

  /* Outport: '<Root>/VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig' */
  REL_Y.VeOUT_REL_RLDoorMotorSts_sig_Ve = 0U;

  /* Outport: '<Root>/VeOUT_REL_RRDoorMotorSts_sig_VeOUT_REL_RRDoorMotorSts_sig' */
  REL_Y.VeOUT_REL_RRDoorMotorSts_sig_Ve = 0U;

  /* Outport: '<Root>/VbOUT_REL_FLDoorMotorErrSts_flg_VbOUT_REL_FLDoorMotorErrSts_flg' */
  REL_Y.VbOUT_REL_FLDoorMotorErrSts_flg = false;

  /* Outport: '<Root>/VbOUT_REL_FRDoorMotorErrSts_flg_VbOUT_REL_FRDoorMotorErrSts_flg' */
  REL_Y.VbOUT_REL_FRDoorMotorErrSts_flg = false;

  /* Outport: '<Root>/VbOUT_REL_RLDoorMotorErrSts_flg_VbOUT_REL_RLDoorMotorErrSts_flg' */
  REL_Y.VbOUT_REL_RLDoorMotorErrSts_flg = false;

  /* Outport: '<Root>/VbOUT_REL_RRDoorMotorErrSts_flg_VbOUT_REL_RRDoorMotorErrSts_flg' */
  REL_Y.VbOUT_REL_RRDoorMotorErrSts_flg = false;

  /* Outport: '<Root>/VeOUT_REL_BDCBleKeyClsDoorRsp_sig_VeOUT_REL_BDCBleKeyClsDoorRsp_sig' */
  REL_Y.VeOUT_REL_BDCBleKeyClsDoorRsp_s = 0U;

  /* Outport: '<Root>/VeOUT_REL_BDCBleKeyOpenDoorRsp_sig_VeOUT_REL_BDCBleKeyOpenDoorRsp_sig' */
  REL_Y.VeOUT_REL_BDCBleKeyOpenDoorRsp_ = 0U;
}

/* Model initialize function */
void REL_initialize(void)
{
  {
    uint8_T SO_e_MotorCmd_o;
    uint8_T SO_e_MotorPwm_f;
    boolean_T SO_b_Error_j;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
     *  SubSystem: '<Root>/REL_Step_sys'
     */

    /* SystemInitialize for Chart: '<S3>/FLDoorRlsDriver' */
    REL_FLDoorRlsDriver_Init(&SO_e_MotorCmd_o, &SO_e_MotorPwm_f, &SO_b_Error_j);

    /* SystemInitialize for Chart: '<S3>/FRDoorRlsDriver' */
    REL_FLDoorRlsDriver_Init(&SO_e_MotorCmd_o, &SO_e_MotorPwm_f, &SO_b_Error_j);

    /* SystemInitialize for Chart: '<S3>/RLDoorRlsDriver' */
    REL_FLDoorRlsDriver_Init(&SO_e_MotorCmd_o, &SO_e_MotorPwm_f, &SO_b_Error_j);

    /* SystemInitialize for Chart: '<S3>/RLDoorRlsReq' */
    REL_RLDoorRlsReq_Init(&REL_B.SO_b_DoorRlsReq_j,
                          &REL_B.SO_e_DoorRlsDelayTime_d,
                          &REL_B.SO_m_UnlockReq_o);

    /* SystemInitialize for Chart: '<S3>/RRDoorRlsDriver' */
    REL_FLDoorRlsDriver_Init(&SO_e_MotorCmd_o, &SO_e_MotorPwm_f, &SO_b_Error_j);

    /* SystemInitialize for Chart: '<S3>/RRDoorRlsReq' */
    REL_RLDoorRlsReq_Init(&REL_B.SO_b_DoorRlsReq, &REL_B.SO_e_DoorRlsDelayTime,
                          &REL_B.SO_m_UnlockReq);

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
