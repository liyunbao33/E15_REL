/*
 * File: REL.h
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

#ifndef RTW_HEADER_REL_h_
#define RTW_HEADER_REL_h_
#ifndef REL_COMMON_INCLUDES_
#define REL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_REL.h"
#endif                                 /* REL_COMMON_INCLUDES_ */

#include "REL_types.h"
#include "Rte_Type.h"

/* Block states (default storage) for system '<S3>/FLCenDoorRat' */
typedef struct {
  uint8 is_active_c11_REL;             /* '<S3>/FLCenDoorRat' */
  uint8 is_c11_REL;                    /* '<S3>/FLCenDoorRat' */
  uint8 is_TRIGGER;                    /* '<S3>/FLCenDoorRat' */
  uint8 is_DOOR_LOCK;                  /* '<S3>/FLCenDoorRat' */
  uint8 temporalCounter_i1;            /* '<S3>/FLCenDoorRat' */
  uint8 temporalCounter_i2;            /* '<S3>/FLCenDoorRat' */
  uint8 SI_e_VcuGearPosn_prev;         /* '<S3>/FLCenDoorRat' */
  uint8 SI_e_VcuGearPosn_start;        /* '<S3>/FLCenDoorRat' */
  boolean SI_b_CdcDoorButtonSts_prev;  /* '<S3>/FLCenDoorRat' */
  boolean SI_b_CdcDoorButtonSts_start; /* '<S3>/FLCenDoorRat' */
  boolean SI_b_Cdc4DoorOpenButtonSts_prev;/* '<S3>/FLCenDoorRat' */
  boolean SI_b_Cdc4DoorOpenButtonSts_star;/* '<S3>/FLCenDoorRat' */
} DW_FLCenDoorRat_REL_T;

/* Block states (default storage) for system '<S3>/FLDoorReleaseDriver' */
typedef struct {
  uint16 temporalCounter_i1;           /* '<S3>/FLDoorReleaseDriver' */
  uint8 is_active_c19_REL;             /* '<S3>/FLDoorReleaseDriver' */
  uint8 is_c19_REL;                    /* '<S3>/FLDoorReleaseDriver' */
  uint8 is_NORMAL;                     /* '<S3>/FLDoorReleaseDriver' */
  uint8 is_MAIN_PROGRESS;              /* '<S3>/FLDoorReleaseDriver' */
  uint8 is_RELEASE;                    /* '<S3>/FLDoorReleaseDriver' */
  uint8 is_STEP2_OPEN;                 /* '<S3>/FLDoorReleaseDriver' */
  uint8 is_MAIN_PROGRESS_k;            /* '<S3>/FLDoorReleaseDriver' */
  uint8 is_RELEASE_h;                  /* '<S3>/FLDoorReleaseDriver' */
  uint8 is_STEP2_OPEN_j;               /* '<S3>/FLDoorReleaseDriver' */
  uint8 SL_e_CheckCycle;               /* '<S3>/FLDoorReleaseDriver' */
  boolean SI_b_TriggerRelease_prev;    /* '<S3>/FLDoorReleaseDriver' */
  boolean SI_b_TriggerRelease_start;   /* '<S3>/FLDoorReleaseDriver' */
  boolean SI_b_DoorOpenSts_prev;       /* '<S3>/FLDoorReleaseDriver' */
  boolean SI_b_DoorOpenSts_start;      /* '<S3>/FLDoorReleaseDriver' */
  boolean SI_b_DCUCinchHomeSwt_prev;   /* '<S3>/FLDoorReleaseDriver' */
  boolean SI_b_DCUCinchHomeSwt_start;  /* '<S3>/FLDoorReleaseDriver' */
} DW_FLDoorReleaseDriver_REL_T;

/* Block signals (default storage) */
typedef struct tag_B_REL_T {
  uint8 SO_e_DLKUnlockReq;             /* '<S3>/Request_DLK_Unlock' */
  uint8 SO_e_DoorRatSts;               /* '<S3>/RRDoorRatSts' */
  uint8 SO_e_MotorMode;                /* '<S3>/RLDoorReleaseDriver1' */
  uint8 SO_e_MotorMode_e;              /* '<S3>/RLDoorReleaseDriver' */
  uint8 SO_e_DoorRatSts_g;             /* '<S3>/RLDoorRatSts' */
  uint8 SO_b_FLDoorInnerSwtSts;        /* '<S3>/InnerButtonState' */
  uint8 SO_b_FRDoorInnerSwtSts;        /* '<S3>/InnerButtonState' */
  uint8 SO_b_RLDoorInnerSwtSts;        /* '<S3>/InnerButtonState' */
  uint8 SO_b_RRDoorInnerSwtSts;        /* '<S3>/InnerButtonState' */
  uint8 SO_e_MotorMode_m;              /* '<S3>/FRDoorReleaseDriver' */
  uint8 SO_e_DoorRatSts_d;             /* '<S3>/FRDoorRatSts' */
  uint8 SO_e_MotorMode_h;              /* '<S3>/FLDoorReleaseDriver' */
  uint8 SO_e_DoorRatSts_i;             /* '<S3>/FLDoorRatSts' */
  Boolean TmpSignalConversionAtVbINP_HWA_;
  boolean LogicalOperator2;            /* '<S3>/Logical Operator2' */
  Boolean TmpSignalConversionAtVbINP_CFG_;
  Boolean TmpSignalConversionAtVbINP_HW_g;
  Boolean TmpSignalConversionAtVbINP_H_gz;
  Boolean TmpSignalConversionAtVbINP_HW_f;
  boolean LogicalOperator4;            /* '<S3>/Logical Operator4' */
  boolean LogicalOperator7;            /* '<S3>/Logical Operator7' */
  boolean LogicalOperator6;            /* '<S3>/Logical Operator6' */
  boolean SO_b_DoorRatRelaseReq;       /* '<S3>/RRElecDoorRat' */
  boolean SO_b_DoorRatRelaseReq_m;     /* '<S3>/RRCenDoorRat' */
  boolean SO_DLKUnlockReq;             /* '<S3>/RRCenDoorRat' */
  boolean SO_b_DoorRatRelaseReq_f;     /* '<S3>/RLElecDoorRat' */
  boolean SO_b_MotorA;                 /* '<S3>/RLDoorReleaseDriver1' */
  boolean SO_b_MotorB;                 /* '<S3>/RLDoorReleaseDriver1' */
  boolean SO_b_MotorA_e;               /* '<S3>/RLDoorReleaseDriver' */
  boolean SO_b_MotorB_p;               /* '<S3>/RLDoorReleaseDriver' */
  boolean SO_b_DoorRatRelaseReq_b;     /* '<S3>/RLCenDoorRat' */
  boolean SO_DLKUnlockReq_h;           /* '<S3>/RLCenDoorRat' */
  boolean SO_DLKUnlockReq_a;           /* '<S3>/PassInnDoorRat' */
  boolean SO_b_FRDoorRatReleaseReq;    /* '<S3>/PassInnDoorRat' */
  boolean SO_b_RLDoorRatReleaseReq;    /* '<S3>/PassInnDoorRat' */
  boolean SO_b_RRDoorRatReleaseReq;    /* '<S3>/PassInnDoorRat' */
  boolean SO_b_DoublePressSucc;        /* '<S3>/InnerButtonPass' */
  boolean SO_b_DoublePressSucc_e;      /* '<S3>/InnerButtonDrv' */
  boolean SO_b_FLDoorInnerSwtSts_p;    /* '<S3>/HandleButtonState' */
  boolean SO_b_FRDoorInnerSwtSts_j;    /* '<S3>/HandleButtonState' */
  boolean SO_b_RLDoorInnerSwtSts_p;    /* '<S3>/HandleButtonState' */
  boolean SO_b_RRDoorInnerSwtSts_b;    /* '<S3>/HandleButtonState' */
  boolean SO_b_DoorRatRelaseReq_h;     /* '<S3>/FRElecDoorRat' */
  boolean SO_b_MotorA_a;               /* '<S3>/FRDoorReleaseDriver' */
  boolean SO_b_MotorB_c;               /* '<S3>/FRDoorReleaseDriver' */
  boolean SO_b_DoorRatRelaseReq_o;     /* '<S3>/FRCenDoorRat' */
  boolean SO_DLKUnlockReq_c;           /* '<S3>/FRCenDoorRat' */
  boolean SO_b_DoorRatRelaseReq_e;     /* '<S3>/FLInnDoorRat' */
  boolean SO_DLKUnlockReq_ay;          /* '<S3>/FLInnDoorRat' */
  boolean SO_b_DoorRatRelaseReq_k;     /* '<S3>/FLElecDoorRat' */
  boolean SO_b_MotorA_m;               /* '<S3>/FLDoorReleaseDriver' */
  boolean SO_b_MotorB_d;               /* '<S3>/FLDoorReleaseDriver' */
  boolean SO_b_DoorRatRelaseReq_i;     /* '<S3>/FLCenDoorRat' */
  boolean SO_DLKUnlockReq_d;           /* '<S3>/FLCenDoorRat' */
  boolean SO_b_BdcDrvrDoorLockSetSts;  /* '<S3>/DrvDoorUnlockAutoOpen' */
  boolean SO_b_E2BdcDrvrDoorLockSetSts;/* '<S3>/DrvDoorUnlockAutoOpen' */
} B_REL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_REL_T {
  uint16 temporalCounter_i1;           /* '<S3>/InnerButtonState' */
  uint16 temporalCounter_i1_l;         /* '<S3>/HandleButtonState' */
  uint8 is_active_c9_REL;              /* '<S3>/Request_DLK_Unlock' */
  uint8 is_c9_REL;                     /* '<S3>/Request_DLK_Unlock' */
  uint8 is_active_c17_REL;             /* '<S3>/RRElecDoorRat' */
  uint8 is_c17_REL;                    /* '<S3>/RRElecDoorRat' */
  uint8 temporalCounter_i1_g;          /* '<S3>/RRElecDoorRat' */
  uint8 SI_e_BTDoorOpenReq_prev;       /* '<S3>/RRElecDoorRat' */
  uint8 SI_e_BTDoorOpenReq_start;      /* '<S3>/RRElecDoorRat' */
  uint8 is_active_c15_REL;             /* '<S3>/RLElecDoorRat' */
  uint8 is_c15_REL;                    /* '<S3>/RLElecDoorRat' */
  uint8 temporalCounter_i1_d;          /* '<S3>/RLElecDoorRat' */
  uint8 SI_e_BTDoorOpenReq_prev_a;     /* '<S3>/RLElecDoorRat' */
  uint8 SI_e_BTDoorOpenReq_start_e;    /* '<S3>/RLElecDoorRat' */
  uint8 is_active_c3_REL;              /* '<S3>/PassInnDoorRat' */
  uint8 is_c3_REL;                     /* '<S3>/PassInnDoorRat' */
  uint8 is_TRIGGER;                    /* '<S3>/PassInnDoorRat' */
  uint8 is_DOOR_LOCK;                  /* '<S3>/PassInnDoorRat' */
  uint8 temporalCounter_i1_n;          /* '<S3>/PassInnDoorRat' */
  uint8 temporalCounter_i2;            /* '<S3>/PassInnDoorRat' */
  uint8 SI_e_VcuGearPosn_prev;         /* '<S3>/PassInnDoorRat' */
  uint8 SI_e_VcuGearPosn_start;        /* '<S3>/PassInnDoorRat' */
  uint8 is_active_c23_REL;             /* '<S3>/InnerButtonState' */
  uint8 is_c23_REL;                    /* '<S3>/InnerButtonState' */
  uint8 is_active_c4_REL;              /* '<S3>/InnerButtonPass' */
  uint8 is_FR_BUTTON;                  /* '<S3>/InnerButtonPass' */
  uint8 is_RL_BUTTON;                  /* '<S3>/InnerButtonPass' */
  uint8 is_RR_BUTTON;                  /* '<S3>/InnerButtonPass' */
  uint8 is_OUTPUT;                     /* '<S3>/InnerButtonPass' */
  uint8 temporalCounter_i1_j;          /* '<S3>/InnerButtonPass' */
  uint8 temporalCounter_i2_d;          /* '<S3>/InnerButtonPass' */
  uint8 temporalCounter_i3;            /* '<S3>/InnerButtonPass' */
  uint8 SL_b_FRDoorInnerSwtSts_prev;   /* '<S3>/InnerButtonPass' */
  uint8 SL_b_FRDoorInnerSwtSts_start;  /* '<S3>/InnerButtonPass' */
  uint8 SL_b_RLDoorInnerSwtSts_prev;   /* '<S3>/InnerButtonPass' */
  uint8 SL_b_RLDoorInnerSwtSts_start;  /* '<S3>/InnerButtonPass' */
  uint8 SL_b_RRDoorInnerSwtSts_prev;   /* '<S3>/InnerButtonPass' */
  uint8 SL_b_RRDoorInnerSwtSts_start;  /* '<S3>/InnerButtonPass' */
  uint8 is_active_c2_REL;              /* '<S3>/InnerButtonDrv' */
  uint8 is_c2_REL;                     /* '<S3>/InnerButtonDrv' */
  uint8 temporalCounter_i1_lm;         /* '<S3>/InnerButtonDrv' */
  uint8 SI_b_FLDoorButton_prev;        /* '<S3>/InnerButtonDrv' */
  uint8 SI_b_FLDoorButton_start;       /* '<S3>/InnerButtonDrv' */
  uint8 is_active_c24_REL;             /* '<S3>/HandleButtonState' */
  uint8 is_c24_REL;                    /* '<S3>/HandleButtonState' */
  uint8 is_active_c12_REL;             /* '<S3>/FRElecDoorRat' */
  uint8 is_c12_REL;                    /* '<S3>/FRElecDoorRat' */
  uint8 temporalCounter_i1_p;          /* '<S3>/FRElecDoorRat' */
  uint8 SI_e_BTDoorOpenReq_prev_g;     /* '<S3>/FRElecDoorRat' */
  uint8 SI_e_BTDoorOpenReq_start_j;    /* '<S3>/FRElecDoorRat' */
  uint8 is_active_c13_REL;             /* '<S3>/FLInnDoorRat' */
  uint8 is_c13_REL;                    /* '<S3>/FLInnDoorRat' */
  uint8 is_TRIGGER_o;                  /* '<S3>/FLInnDoorRat' */
  uint8 is_DOOR_LOCK_e;                /* '<S3>/FLInnDoorRat' */
  uint8 temporalCounter_i1_gl;         /* '<S3>/FLInnDoorRat' */
  uint8 temporalCounter_i2_f;          /* '<S3>/FLInnDoorRat' */
  uint8 SI_e_VcuGearPosn_prev_o;       /* '<S3>/FLInnDoorRat' */
  uint8 SI_e_VcuGearPosn_start_e;      /* '<S3>/FLInnDoorRat' */
  uint8 is_active_c10_REL;             /* '<S3>/FLElecDoorRat' */
  uint8 is_c10_REL;                    /* '<S3>/FLElecDoorRat' */
  uint8 temporalCounter_i1_b;          /* '<S3>/FLElecDoorRat' */
  uint8 SI_e_BTDoorOpenReq_prev_e;     /* '<S3>/FLElecDoorRat' */
  uint8 SI_e_BTDoorOpenReq_start_d;    /* '<S3>/FLElecDoorRat' */
  uint8 is_active_c1_REL;              /* '<S3>/DrvDoorUnlockAutoOpen' */
  uint8 is_c1_REL;                     /* '<S3>/DrvDoorUnlockAutoOpen' */
  uint8 temporalCounter_i1_c;          /* '<S3>/DrvDoorUnlockAutoOpen' */
  boolean SL_DLKDrvUnlockReq_prev;     /* '<S3>/Request_DLK_Unlock' */
  boolean SL_DLKDrvUnlockReq_start;    /* '<S3>/Request_DLK_Unlock' */
  boolean SL_DLKPassUnlockReq_prev;    /* '<S3>/Request_DLK_Unlock' */
  boolean SL_DLKPassUnlockReq_start;   /* '<S3>/Request_DLK_Unlock' */
  boolean SI_b_DoorHandleSW_prev;      /* '<S3>/RRElecDoorRat' */
  boolean SI_b_DoorHandleSW_start;     /* '<S3>/RRElecDoorRat' */
  boolean SI_b_DoorHandleSW_prev_j;    /* '<S3>/RLElecDoorRat' */
  boolean SI_b_DoorHandleSW_start_j;   /* '<S3>/RLElecDoorRat' */
  boolean SI_b_DoublePressSucc_prev;   /* '<S3>/PassInnDoorRat' */
  boolean SI_b_DoublePressSucc_start;  /* '<S3>/PassInnDoorRat' */
  boolean SI_b_CrashOutpSts_prev;      /* '<S3>/InnerButtonState' */
  boolean SI_b_CrashOutpSts_start;     /* '<S3>/InnerButtonState' */
  boolean SL_b_FRDBLPressSucc;         /* '<S3>/InnerButtonPass' */
  boolean SL_b_RRDBLPressSucc;         /* '<S3>/InnerButtonPass' */
  boolean SL_b_RLDBLPressSucc;         /* '<S3>/InnerButtonPass' */
  boolean SI_b_CrashOutpSts_prev_d;    /* '<S3>/HandleButtonState' */
  boolean SI_b_CrashOutpSts_start_f;   /* '<S3>/HandleButtonState' */
  boolean SI_b_DoorHandleSW_prev_k;    /* '<S3>/FRElecDoorRat' */
  boolean SI_b_DoorHandleSW_start_e;   /* '<S3>/FRElecDoorRat' */
  boolean SI_b_DoublePressSucc_prev_h; /* '<S3>/FLInnDoorRat' */
  boolean SI_b_DoublePressSucc_start_j;/* '<S3>/FLInnDoorRat' */
  boolean SI_b_DoorHandleSW_prev_ko;   /* '<S3>/FLElecDoorRat' */
  boolean SI_b_DoorHandleSW_start_d;   /* '<S3>/FLElecDoorRat' */
  DW_FLCenDoorRat_REL_T sf_RRCenDoorRat;/* '<S3>/RRCenDoorRat' */
  DW_FLDoorReleaseDriver_REL_T sf_RLDoorReleaseDriver1;/* '<S3>/RLDoorReleaseDriver1' */
  DW_FLDoorReleaseDriver_REL_T sf_RLDoorReleaseDriver;/* '<S3>/RLDoorReleaseDriver' */
  DW_FLCenDoorRat_REL_T sf_RLCenDoorRat;/* '<S3>/RLCenDoorRat' */
  DW_FLDoorReleaseDriver_REL_T sf_FRDoorReleaseDriver;/* '<S3>/FRDoorReleaseDriver' */
  DW_FLCenDoorRat_REL_T sf_FRCenDoorRat;/* '<S3>/FRCenDoorRat' */
  DW_FLDoorReleaseDriver_REL_T sf_FLDoorReleaseDriver;/* '<S3>/FLDoorReleaseDriver' */
  DW_FLCenDoorRat_REL_T sf_FLCenDoorRat;/* '<S3>/FLCenDoorRat' */
} DW_REL_T;

/* Block signals (default storage) */
extern B_REL_T REL_B;

/* Block states (default storage) */
extern DW_REL_T REL_DW;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Compare' : Unused code path elimination
 * Block '<S4>/Constant' : Unused code path elimination
 * Block '<S3>/Logical Operator3' : Unused code path elimination
 * Block '<S20>/Compare' : Unused code path elimination
 * Block '<S20>/Constant' : Unused code path elimination
 * Block '<S21>/Compare' : Unused code path elimination
 * Block '<S21>/Constant' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion3' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'REL'
 * '<S1>'   : 'REL/REL_Init'
 * '<S2>'   : 'REL/REL_Step_sys'
 * '<S3>'   : 'REL/REL_Step_sys/REL'
 * '<S4>'   : 'REL/REL_Step_sys/REL/CRANK'
 * '<S5>'   : 'REL/REL_Step_sys/REL/DrvDoorUnlockAutoOpen'
 * '<S6>'   : 'REL/REL_Step_sys/REL/FLCenDoorRat'
 * '<S7>'   : 'REL/REL_Step_sys/REL/FLDoorRatSts'
 * '<S8>'   : 'REL/REL_Step_sys/REL/FLDoorReleaseDriver'
 * '<S9>'   : 'REL/REL_Step_sys/REL/FLElecDoorRat'
 * '<S10>'  : 'REL/REL_Step_sys/REL/FLInnDoorRat'
 * '<S11>'  : 'REL/REL_Step_sys/REL/FRCenDoorRat'
 * '<S12>'  : 'REL/REL_Step_sys/REL/FRDoorRatSts'
 * '<S13>'  : 'REL/REL_Step_sys/REL/FRDoorReleaseDriver'
 * '<S14>'  : 'REL/REL_Step_sys/REL/FRElecDoorRat'
 * '<S15>'  : 'REL/REL_Step_sys/REL/HandleButtonState'
 * '<S16>'  : 'REL/REL_Step_sys/REL/InnerButtonDrv'
 * '<S17>'  : 'REL/REL_Step_sys/REL/InnerButtonPass'
 * '<S18>'  : 'REL/REL_Step_sys/REL/InnerButtonState'
 * '<S19>'  : 'REL/REL_Step_sys/REL/OFF '
 * '<S20>'  : 'REL/REL_Step_sys/REL/ON'
 * '<S21>'  : 'REL/REL_Step_sys/REL/OTA'
 * '<S22>'  : 'REL/REL_Step_sys/REL/PassInnDoorRat'
 * '<S23>'  : 'REL/REL_Step_sys/REL/RLCenDoorRat'
 * '<S24>'  : 'REL/REL_Step_sys/REL/RLDoorRatSts'
 * '<S25>'  : 'REL/REL_Step_sys/REL/RLDoorReleaseDriver'
 * '<S26>'  : 'REL/REL_Step_sys/REL/RLDoorReleaseDriver1'
 * '<S27>'  : 'REL/REL_Step_sys/REL/RLElecDoorRat'
 * '<S28>'  : 'REL/REL_Step_sys/REL/RRCenDoorRat'
 * '<S29>'  : 'REL/REL_Step_sys/REL/RRDoorRatSts'
 * '<S30>'  : 'REL/REL_Step_sys/REL/RRElecDoorRat'
 * '<S31>'  : 'REL/REL_Step_sys/REL/Request_DLK_Unlock'
 */
#endif                                 /* RTW_HEADER_REL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
