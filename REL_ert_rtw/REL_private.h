/*
 * File: REL_private.h
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.201
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Oct 30 16:56:27 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_REL_private_h_
#define RTW_HEADER_REL_private_h_
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "REL.h"
#include "REL_types.h"

extern void REL_FLDoorRlsDriver_Init(uint8_T *rty_SO_e_MotorCmd, uint8_T
  *rty_SO_e_MotorPwm, boolean_T *rty_SO_b_Error);
extern void REL_FLDoorRlsDriver(UInt8 rtu_SI_e_Volt100mV, boolean_T
  rtu_SO_b_DoorRlsReq, Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_DoorOpen,
  uint8_T rtu_SI_e_DoorRlsDelayTime, uint8_T *rty_SO_e_MotorCmd, uint8_T
  *rty_SO_e_MotorPwm, boolean_T *rty_SO_b_Error, DW_FLDoorRlsDriver_REL_T
  *localDW);
extern void REL_RLDoorRlsReq_Init(boolean_T *rty_SO_b_DoorRlsReq, uint8_T
  *rty_SO_e_DoorRlsDelayTime, Unlock_Req_E *rty_SO_m_UnlockReq);
extern void REL_RLDoorRlsReq(boolean_T rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd,
  Boolean rtu_SI_b_EspVehSpdVld, Gear_Posn_E rtu_SI_m_VcuGearPosn, Door_Sts_E
  rtu_SI_m_DoorLockSts, Rat_Sts_E rtu_SI_m_DoorRatSts, boolean_T
  rtu_SI_b_DoorInBtnSts, boolean_T rtu_SI_b_DoorHndPullSts, boolean_T
  rtu_SI_b_DoorHndBtnSts, HndPos_Sts_E rtu_SI_m_DoorHandPosSts, Boolean
  rtu_SI_b_CentSingleDoorBtnSts, Boolean rtu_SI_b_CentAllDoorBtnSts, Boolean
  rtu_SI_b_ChildLckSts, boolean_T rtu_SI_b_DoorAutoRlsSetSts, boolean_T
  rtu_SI_b_DoorAutoRlsReq, Boolean rtu_SI_b_DoorHndBtnSetSts, boolean_T
  rtu_SI_b_BleDoorOpenReq, boolean_T rtu_SI_b_BleKeyPosValid, boolean_T
  *rty_SO_b_DoorRlsReq, uint8_T *rty_SO_e_DoorRlsDelayTime, Unlock_Req_E
  *rty_SO_m_UnlockReq, DW_RLDoorRlsReq_REL_T *localDW);

#endif                                 /* RTW_HEADER_REL_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
