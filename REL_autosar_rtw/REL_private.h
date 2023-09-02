/*
 * File: REL_private.h
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Aug 28 16:23:44 2023
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

extern void REL_FLCenDoorRat_Init(boolean *rty_SO_b_DoorRatRelaseReq, boolean
  *rty_SO_DLKUnlockReq);
extern void REL_FLCenDoorRat(boolean rtu_SI_b_OFF, UInt8 rtu_SI_e_DoorLockSts,
  UInt8 rtu_SI_e_EspVehSpd, Boolean rtu_SI_b_EspVehSpdVld, uint8
  rtu_SI_e_DoorRatSts, UInt8 rtu_SI_e_VcuGearPosn, Boolean
  rtu_SI_b_CdcDoorButtonSts, Boolean rtu_SI_b_Cdc4DoorOpenButtonSts, boolean
  *rty_SO_b_DoorRatRelaseReq, boolean *rty_SO_DLKUnlockReq,
  DW_FLCenDoorRat_REL_T *localDW);
extern void REL_FLDoorRatSts(Boolean rtu_SI_b_DoorAjarSwt, uint8
  *rty_SO_e_DoorRatSts);
extern void REL_FLDoorReleaseDriver_Init(boolean *rty_SO_b_MotorA, boolean
  *rty_SO_b_MotorB, uint8 *rty_SO_e_MotorMode, boolean *rty_SO_b_Error);
extern void REL_FLDoorReleaseDriver(boolean rtu_SI_b_TriggerRelease, Boolean
  rtu_SI_b_DoorOpenSts, Boolean rtu_SI_b_DCUCinchHomeSwt, Boolean
  rtu_SI_b_ElectricDoorCfg, boolean *rty_SO_b_MotorA, boolean *rty_SO_b_MotorB,
  uint8 *rty_SO_e_MotorMode, boolean *rty_SO_b_Error,
  DW_FLDoorReleaseDriver_REL_T *localDW);

#endif                                 /* RTW_HEADER_REL_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
