/*
 * File: REL_private.h
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.195
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Sep  1 20:22:52 2023
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
extern void REL_FLDoorRelease_Init(boolean_T *rty_SO_b_DoorRlsReq, boolean_T
  *rty_SO_b_UnlockReq);
extern void REL_FLDoorRelease(boolean_T rtu_SI_b_POW_OFF, UInt8
  rtu_SI_e_EspVehSpd, Boolean rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn,
  UInt8 rtu_SI_e_DoorLockSts, uint8_T rtu_SI_e_DoorRatSts, boolean_T
  rtu_SI_b_DoorInSW, Boolean rtu_SI_b_CentSingleDoorSW, Boolean
  rtu_SI_b_CentAllDoorSW, boolean_T *rty_SO_b_DoorRlsReq, boolean_T
  *rty_SO_b_UnlockReq, DW_FLDoorRelease_REL_T *localDW);
extern void REL_FLDoorReleaseDriver_Init(boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorMode, boolean_T *rty_SO_b_Error);
extern void REL_FLDoorReleaseDriver(boolean_T rtu_SI_b_TriggerRelease, Boolean
  rtu_SI_b_DoorOpenSts, Boolean rtu_SI_b_DCUCinchHomeSwt, Boolean
  rtu_SI_b_ElectricDoorCfg, boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorMode, boolean_T *rty_SO_b_Error,
  DW_FLDoorReleaseDriver_REL_T *localDW);
extern void REL_FLSwitchStatus_Init(boolean_T *rty_SO_b_DoorInSwSts, boolean_T
  *rty_SO_b_DoorOutSwSts, boolean_T *rty_SO_b_DoorHandSwSts);
extern void REL_FLSwitchStatus(Boolean rtu_SI_b_DoorInSW, Boolean
  rtu_SI_b_DoorOutSW, Boolean rtu_SI_b_DoorHandSW, uint8_T
  rtu_SI_e_DoublePressTime, uint8_T rtu_SI_e_SinglePressTime, boolean_T
  rtu_SI_b_ChildLckSts, boolean_T *rty_SO_b_DoorInSwSts, boolean_T
  *rty_SO_b_DoorOutSwSts, boolean_T *rty_SO_b_DoorHandSwSts,
  DW_FLSwitchStatus_REL_T *localDW);
extern void REL_RLSwitchStatus_Init(boolean_T *rty_SO_b_DoorInSwSts, boolean_T
  *rty_SO_b_DoorOutSwSts, boolean_T *rty_SO_b_DoorHandSwSts);
extern void REL_RLSwitchStatus(Boolean rtu_SI_b_DoorInSW, Boolean
  rtu_SI_b_DoorOutSW, Boolean rtu_SI_b_DoorHandSW, uint8_T
  rtu_SI_e_DoublePressTime, uint8_T rtu_SI_e_SinglePressTime, Boolean
  rtu_SI_b_ChildLckSts, boolean_T *rty_SO_b_DoorInSwSts, boolean_T
  *rty_SO_b_DoorOutSwSts, boolean_T *rty_SO_b_DoorHandSwSts,
  DW_RLSwitchStatus_REL_T *localDW);

#endif                                 /* RTW_HEADER_REL_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
