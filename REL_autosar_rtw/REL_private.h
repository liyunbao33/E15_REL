/*
 * File: REL_private.h
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Sep  8 15:08:23 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_REL_private_h_
#define RTW_HEADER_REL_private_h_
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "REL.h"

extern void REL_FLDoorRatSts(Boolean rtu_SI_b_DoorOpen, uint8
  *rty_SO_e_DoorRatSts);
extern void REL_FLDoorRlsDriver_Init(boolean *rty_SO_b_MotorA, boolean
  *rty_SO_b_MotorB, uint8 *rty_SO_e_MotorMode, boolean *rty_SO_b_Error, uint8
  *rty_SO_e_MotorPwm);
extern void REL_FLDoorRlsDriver(boolean rtu_SO_b_DoorRlsReq, Boolean
  rtu_SI_b_DoorAjar, Boolean rtu_SI_b_CinchHome, Boolean rtu_SI_b_ElecDoorCfg,
  uint8 rtu_SI_e_DoorRlsDelayTime, boolean *rty_SO_b_MotorA, boolean
  *rty_SO_b_MotorB, uint8 *rty_SO_e_MotorMode, boolean *rty_SO_b_Error, uint8
  *rty_SO_e_MotorPwm, DW_FLDoorRlsDriver_REL_T *localDW);
extern void REL_RLDoorRlsReq_Init(boolean *rty_SO_b_DoorRlsReq, boolean
  *rty_SO_b_UnlockReq, uint8 *rty_SO_e_DoorRlsDelayTime);
extern void REL_RLDoorRlsReq(boolean rtu_SI_b_OFF, UInt8 rtu_SI_e_EspVehSpd,
  Boolean rtu_SI_b_EspVehSpdVld, UInt8 rtu_SI_e_VcuGearPosn, UInt8
  rtu_SI_e_DoorLockSts, uint8 rtu_SI_e_DoorRatSts, boolean rtu_SI_b_DoorInSwSts,
  boolean rtu_SI_b_DoorOutSwSts, boolean rtu_SI_b_DoorHandSwSts, UInt8
  rtu_SI_e_DoorHandPosSts, Boolean rtu_SI_b_CentSingleDoorSwSts, Boolean
  rtu_SI_b_CentAllDoorSwSts, Boolean rtu_SI_b_ChildLckSts, boolean
  rtu_SI_b_DoorLockSetSts, boolean rtu_SI_b_DoorLockOpenReq, boolean
  *rty_SO_b_DoorRlsReq, boolean *rty_SO_b_UnlockReq, uint8
  *rty_SO_e_DoorRlsDelayTime, DW_RLDoorRlsReq_REL_T *localDW);

#endif                                 /* RTW_HEADER_REL_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
