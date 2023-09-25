/*
 * File: REL_types.h
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.76
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Sep 25 10:54:21 2023
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

/* Forward declaration for rtModel */
typedef struct tag_RTM_REL_T RT_MODEL_REL_T;

#endif                                 /* RTW_HEADER_REL_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
