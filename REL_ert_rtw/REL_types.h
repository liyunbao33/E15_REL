/*
 * File: REL_types.h
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.83
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Sep 25 11:15:10 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_REL_types_h_
#define RTW_HEADER_REL_types_h_
#include "Rte_Type.h"
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_DoorRat_Sts_E_
#define DEFINED_TYPEDEF_FOR_DoorRat_Sts_E_

typedef uint8_T DoorRat_Sts_E;

/* enum DoorRat_Sts_E */
#define Invalid                        ((DoorRat_Sts_E)0U)       /* Default value */
#define All_Lock                       ((DoorRat_Sts_E)1U)
#define Half_Lock                      ((DoorRat_Sts_E)2U)
#define Unlock                         ((DoorRat_Sts_E)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Motor_Cmd_E_
#define DEFINED_TYPEDEF_FOR_Motor_Cmd_E_

typedef uint8_T Motor_Cmd_E;

/* enum Motor_Cmd_E */
#define Stop                           ((Motor_Cmd_E)0U)         /* Default value */
#define Rls                            ((Motor_Cmd_E)1U)
#define Reset                          ((Motor_Cmd_E)2U)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_REL_T RT_MODEL_REL_T;

#endif                                 /* RTW_HEADER_REL_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
