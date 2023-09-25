/*
 * File: REL_private.h
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.86
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Sep 25 12:24:35 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_REL_private_h_
#define RTW_HEADER_REL_private_h_
#include "rtwtypes.h"
#include "REL_types.h"
#include "Rte_Type.h"
#include "REL.h"

extern void REL_FLDoorRlsDriver_Init(boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, Mot_Cmd_E *rty_SO_e_MotorCmd, boolean_T *rty_SO_b_Error,
  uint8_T *rty_SO_e_MotorPwm);
extern void REL_FLDoorRlsDriver(boolean_T rtu_SO_b_DoorRlsReq, Boolean
  rtu_SI_b_DoorAjar, Boolean rtu_SI_b_CinchHome, Boolean rtu_SI_b_ElecDoorCfg,
  uint8_T rtu_SI_e_DoorRlsDelayTime, boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, Mot_Cmd_E *rty_SO_e_MotorCmd, boolean_T *rty_SO_b_Error,
  uint8_T *rty_SO_e_MotorPwm, DW_FLDoorRlsDriver_REL_T *localDW);
extern void REL_RLDoorRlsReq_Init(boolean_T *rty_SO_b_DoorRlsReq, uint8_T
  *rty_SO_e_DoorRlsDelayTime, boolean_T *rty_SO_b_UnlockReq, boolean_T
  *rty_SO_b_PEUnlockReq);
extern void REL_RLDoorRlsReq(boolean_T rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd,
  Boolean rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8
  rtu_SI_e_DoorLockSts, Rat_Sts_E rtu_SI_e_DoorRatSts, boolean_T
  rtu_SI_b_DoorInBtnSts, boolean_T rtu_SI_b_DoorHndPullSts, boolean_T
  rtu_SI_b_DoorHndBtnSts, UInt8 rtu_SI_e_DoorHandPosSts, Boolean
  rtu_SI_b_CentSingleDoorBtnSts, Boolean rtu_SI_b_CentAllDoorBtnSts, Boolean
  rtu_SI_b_ChildLckSts, boolean_T rtu_SI_b_DoorAutoRlsSetSts, boolean_T
  rtu_SI_b_DoorAutoRlsReq, boolean_T *rty_SO_b_DoorRlsReq, uint8_T
  *rty_SO_e_DoorRlsDelayTime, boolean_T *rty_SO_b_UnlockReq, boolean_T
  *rty_SO_b_PEUnlockReq, DW_RLDoorRlsReq_REL_T *localDW);

#endif                                 /* RTW_HEADER_REL_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
