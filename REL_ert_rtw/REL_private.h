/*
 * File: REL_private.h
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.267
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Sep  5 09:38:44 2023
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

extern void REL_FLDoorRatSts(Boolean rtu_SI_b_DoorOpen, uint8_T
  *rty_SO_e_DoorRatSts);
extern void REL_FLDoorReleaseDriver_Init(boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorMode, boolean_T *rty_SO_b_Error,
  uint8_T *rty_SO_e_MotorPwm);
extern void REL_FLDoorReleaseDriver(boolean_T rtu_SO_b_DoorRlsReq, Boolean
  rtu_SI_b_DoorAjar, Boolean rtu_SI_b_CinchHome, Boolean rtu_SI_b_ElecDoorCfg,
  boolean_T *rty_SO_b_MotorA, boolean_T *rty_SO_b_MotorB, uint8_T
  *rty_SO_e_MotorMode, boolean_T *rty_SO_b_Error, uint8_T *rty_SO_e_MotorPwm,
  DW_FLDoorReleaseDriver_REL_T *localDW);
extern void REL_RLDoorRelease_Init(boolean_T *rty_SO_b_DoorRlsReq, boolean_T
  *rty_SO_b_UnlockReq);
extern void REL_RLDoorRelease(boolean_T rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd,
  Boolean rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8
  rtu_SI_e_DoorLockSts, uint8_T rtu_SI_e_DoorRatSts, Boolean
  rtu_SI_b_DoorInSwSts, Boolean rtu_SI_b_DoorOutSwSts, Boolean
  rtu_SI_b_DoorHandSwSts, Boolean rtu_SI_b_CentSingleDoorSwSts, Boolean
  rtu_SI_b_CentAllDoorSwSts, Boolean rtu_SI_b_ChildLckSts, boolean_T
  rtu_SI_b_DoorLockSetSts, boolean_T *rty_SO_b_DoorRlsReq, boolean_T
  *rty_SO_b_UnlockReq, DW_RLDoorRelease_REL_T *localDW);

#endif                                 /* RTW_HEADER_REL_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
