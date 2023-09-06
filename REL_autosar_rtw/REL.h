/*
 * File: REL.h
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.309
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Sep  6 14:19:56 2023
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

/* Block states (default storage) for system '<S3>/FLDoorRlsDriver' */
typedef struct {
  uint16 temporalCounter_i1;           /* '<S3>/FLDoorRlsDriver' */
  uint8 is_active_c19_DoorRlsDriver;   /* '<S3>/FLDoorRlsDriver' */
  uint8 is_c19_DoorRlsDriver;          /* '<S3>/FLDoorRlsDriver' */
  uint8 is_Normal;                     /* '<S3>/FLDoorRlsDriver' */
  uint8 is_MainProgress;               /* '<S3>/FLDoorRlsDriver' */
  uint8 is_Release;                    /* '<S3>/FLDoorRlsDriver' */
  uint8 is_Step2_Open;                 /* '<S3>/FLDoorRlsDriver' */
  uint8 is_MainProgress_j;             /* '<S3>/FLDoorRlsDriver' */
  uint8 is_Release_i;                  /* '<S3>/FLDoorRlsDriver' */
  uint8 is_Step2_Open_c;               /* '<S3>/FLDoorRlsDriver' */
  uint8 SL_e_CheckCycle;               /* '<S3>/FLDoorRlsDriver' */
  boolean SO_b_DoorRlsReq_prev;        /* '<S3>/FLDoorRlsDriver' */
  boolean SO_b_DoorRlsReq_start;       /* '<S3>/FLDoorRlsDriver' */
} DW_FLDoorRlsDriver_REL_T;

/* Block states (default storage) for system '<S3>/RLDoorRlsReq' */
typedef struct {
  uint8 is_active_c5_DoorRlsReq;       /* '<S3>/RLDoorRlsReq' */
  uint8 is_RlsReq;                     /* '<S3>/RLDoorRlsReq' */
  uint8 is_Trigger;                    /* '<S3>/RLDoorRlsReq' */
  uint8 is_SwValid;                    /* '<S3>/RLDoorRlsReq' */
  uint8 is_RlsReq_o;                   /* '<S3>/RLDoorRlsReq' */
  uint8 is_Trigger_k;                  /* '<S3>/RLDoorRlsReq' */
  uint8 is_RlsReq_g;                   /* '<S3>/RLDoorRlsReq' */
  uint8 is_Trigger_b;                  /* '<S3>/RLDoorRlsReq' */
  uint8 is_SwValid_o;                  /* '<S3>/RLDoorRlsReq' */
  uint8 is_RlsReq_f;                   /* '<S3>/RLDoorRlsReq' */
  uint8 is_Trigger_c;                  /* '<S3>/RLDoorRlsReq' */
  uint8 is_DoorCentral;                /* '<S3>/RLDoorRlsReq' */
  uint8 is_Trigger_h;                  /* '<S3>/RLDoorRlsReq' */
  uint8 temporalCounter_i1;            /* '<S3>/RLDoorRlsReq' */
  uint8 temporalCounter_i2;            /* '<S3>/RLDoorRlsReq' */
  uint8 temporalCounter_i3;            /* '<S3>/RLDoorRlsReq' */
  uint8 temporalCounter_i4;            /* '<S3>/RLDoorRlsReq' */
  uint8 temporalCounter_i5;            /* '<S3>/RLDoorRlsReq' */
  uint8 temporalCounter_i6;            /* '<S3>/RLDoorRlsReq' */
  uint8 temporalCounter_i7;            /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_DoorInSwValid;          /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_CentSingleDoorSwValid;  /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_CentAllDoorSwValid;     /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_DoorOutSwValid;         /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_DoorHandSwValid;        /* '<S3>/RLDoorRlsReq' */
  boolean SI_b_DoorLockOpenReq_prev;   /* '<S3>/RLDoorRlsReq' */
  boolean SI_b_DoorLockOpenReq_start;  /* '<S3>/RLDoorRlsReq' */
  boolean SI_b_DoorInSwSts_prev;       /* '<S3>/RLDoorRlsReq' */
  boolean SI_b_DoorInSwSts_start;      /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_DoorInSwValid_prev;     /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_DoorInSwValid_start;    /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_DoorOutSwValid_prev;    /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_DoorOutSwValid_start;   /* '<S3>/RLDoorRlsReq' */
  boolean SI_b_DoorHandSwSts_prev;     /* '<S3>/RLDoorRlsReq' */
  boolean SI_b_DoorHandSwSts_start;    /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_DoorHandSwValid_prev;   /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_DoorHandSwValid_start;  /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_CentSingleDoorSwValid_prev;/* '<S3>/RLDoorRlsReq' */
  boolean SL_b_CentSingleDoorSwValid_star;/* '<S3>/RLDoorRlsReq' */
  boolean SL_b_CentAllDoorSwValid_prev;/* '<S3>/RLDoorRlsReq' */
  boolean SL_b_CentAllDoorSwValid_start;/* '<S3>/RLDoorRlsReq' */
} DW_RLDoorRlsReq_REL_T;

/* Block signals (default storage) */
typedef struct tag_B_REL_T {
  UInt8 TmpSignalConversionAtVeOUT_SP_E;
  UInt8 TmpSignalConversionAtVeINP_CAN_;
  UInt8 TmpSignalConversionAtVeOUT_DLK_;
  uint8 SO_e_UnlockReq;                /* '<S3>/Unlock_Request' */
  uint8 SO_e_DoorRlsDelayTime;         /* '<S3>/RRDoorRlsReq' */
  uint8 SO_e_MotorMode;                /* '<S3>/RRDoorRlsDriver' */
  uint8 SO_e_DoorRatSts;               /* '<S3>/RRDoorRatSts' */
  uint8 SO_e_DoorRlsDelayTime_m;       /* '<S3>/RLDoorRlsReq' */
  uint8 SO_e_MotorMode_g;              /* '<S3>/RLDoorRlsDriver' */
  uint8 SO_e_DoorRatSts_p;             /* '<S3>/RLDoorRatSts' */
  uint8 SO_e_DoorRlsDelayTime_n;       /* '<S3>/FRDoorRlsReq' */
  uint8 SO_e_MotorMode_a;              /* '<S3>/FRDoorRlsDriver' */
  uint8 SO_e_DoorRatSts_g;             /* '<S3>/FRDoorRatSts' */
  uint8 SO_e_DoorRlsDelayTime_n3;      /* '<S3>/FLDoorRlsReq' */
  uint8 SO_e_MotorMode_b;              /* '<S3>/FLDoorRlsDriver' */
  uint8 SO_e_DoorRatSts_gx;            /* '<S3>/FLDoorRatSts' */
  Boolean TmpSignalConversionAtVbINP_HWA_;
  Boolean TmpSignalConversionAtVbINP_HW_j;
  Boolean TmpSignalConversionAtVbINP_HW_m;
  Boolean TmpSignalConversionAtVbINP_H_jc;
  Boolean VbINP_HWA_RRDoorOutButton_flg_V;
  /* '<S2>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg_read' */
  Boolean VbINP_HWA_FLDoorHandleSW_flg_Vb;
     /* '<S2>/VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg_read' */
  Boolean VbINP_HWA_FRDoorHandleSW_flg_Vb;
     /* '<S2>/VbINP_HWA_FRDoorHandleSW_flg_VbINP_HWA_FRDoorHandleSW_flg_read' */
  Boolean VbINP_HWA_RLDoorHandleSW_flg_Vb;
     /* '<S2>/VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg_read' */
  Boolean VbINP_HWA_RRDoorHandleSW_flg_Vb;
     /* '<S2>/VbINP_HWA_RRDoorHandleSW_flg_VbINP_HWA_RRDoorHandleSW_flg_read' */
  Boolean TmpSignalConversionAtVbINP_H_m0;
  boolean Compare;                     /* '<S12>/Compare' */
  Boolean TmpSignalConversionAtVbINP_CAN_;
  Boolean TmpSignalConversionAtVbINP_CA_f;
  Boolean TmpSignalConversionAtVbINP_CFG_;
  Boolean TmpSignalConversionAtVbINP_HW_g;
  Boolean TmpSignalConversionAtVbINP_HW_f;
  Boolean TmpSignalConversionAtVbINP_H_gz;
  boolean SO_b_DoorRlsReq;             /* '<S3>/RRDoorRlsReq' */
  boolean SO_b_UnlockReq;              /* '<S3>/RRDoorRlsReq' */
  boolean SO_b_MotorA;                 /* '<S3>/RRDoorRlsDriver' */
  boolean SO_b_MotorB;                 /* '<S3>/RRDoorRlsDriver' */
  boolean SO_b_DoorRlsReq_h;           /* '<S3>/RLDoorRlsReq' */
  boolean SO_b_UnlockReq_e;            /* '<S3>/RLDoorRlsReq' */
  boolean SO_b_MotorA_f;               /* '<S3>/RLDoorRlsDriver' */
  boolean SO_b_MotorB_j;               /* '<S3>/RLDoorRlsDriver' */
  boolean SO_b_DoorRlsReq_f;           /* '<S3>/FRDoorRlsReq' */
  boolean SO_b_UnlockReq_i;            /* '<S3>/FRDoorRlsReq' */
  boolean SO_b_MotorA_n;               /* '<S3>/FRDoorRlsDriver' */
  boolean SO_b_MotorB_k;               /* '<S3>/FRDoorRlsDriver' */
  boolean SO_b_DoorRlsReq_d;           /* '<S3>/FLDoorRlsReq' */
  boolean SO_b_UnlockReq_f;            /* '<S3>/FLDoorRlsReq' */
  boolean SO_b_MotorA_fp;              /* '<S3>/FLDoorRlsDriver' */
  boolean SO_b_MotorB_c;               /* '<S3>/FLDoorRlsDriver' */
  boolean SL_b_RLDoorInSwSts;          /* '<S3>/DoorSwSts' */
  boolean SL_b_RRDoorInSwSts;          /* '<S3>/DoorSwSts' */
  boolean SL_b_FRDoorOutSwSts;         /* '<S3>/DoorSwSts' */
  boolean SL_b_RLDoorOutSwSts;         /* '<S3>/DoorSwSts' */
  boolean SL_b_RRDoorOutSwSts;         /* '<S3>/DoorSwSts' */
  boolean SL_b_FLDoorHandSwSts;        /* '<S3>/DoorSwSts' */
  boolean SL_b_FRDoorHandSwSts;        /* '<S3>/DoorSwSts' */
  boolean SL_b_RLDoorHandSwSts;        /* '<S3>/DoorSwSts' */
  boolean SL_b_RRDoorHandSwSts;        /* '<S3>/DoorSwSts' */
  boolean SO_b_DoorLockSetSts;         /* '<S3>/DoorLockSetSts' */
  boolean SO_b_EEDoorLockSetSts;       /* '<S3>/DoorLockSetSts' */
} B_REL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_REL_T {
  uint16 temporalCounter_i1;           /* '<S3>/DoorSwSts' */
  uint8 is_active_c6_REL;              /* '<S3>/Unlock_Request' */
  uint8 is_c6_REL;                     /* '<S3>/Unlock_Request' */
  uint8 is_active_c5_DoorRlsReq;       /* '<S3>/FRDoorRlsReq' */
  uint8 is_RlsReq;                     /* '<S3>/FRDoorRlsReq' */
  uint8 is_Trigger;                    /* '<S3>/FRDoorRlsReq' */
  uint8 is_SwValid;                    /* '<S3>/FRDoorRlsReq' */
  uint8 is_RlsReq_f;                   /* '<S3>/FRDoorRlsReq' */
  uint8 is_Trigger_h;                  /* '<S3>/FRDoorRlsReq' */
  uint8 is_RlsReq_i;                   /* '<S3>/FRDoorRlsReq' */
  uint8 is_Trigger_b;                  /* '<S3>/FRDoorRlsReq' */
  uint8 is_SwValid_p;                  /* '<S3>/FRDoorRlsReq' */
  uint8 is_RlsReq_j;                   /* '<S3>/FRDoorRlsReq' */
  uint8 is_Trigger_g;                  /* '<S3>/FRDoorRlsReq' */
  uint8 is_DoorCentral;                /* '<S3>/FRDoorRlsReq' */
  uint8 is_Trigger_f;                  /* '<S3>/FRDoorRlsReq' */
  uint8 temporalCounter_i1_b;          /* '<S3>/FRDoorRlsReq' */
  uint8 temporalCounter_i2;            /* '<S3>/FRDoorRlsReq' */
  uint8 temporalCounter_i3;            /* '<S3>/FRDoorRlsReq' */
  uint8 temporalCounter_i4;            /* '<S3>/FRDoorRlsReq' */
  uint8 temporalCounter_i5;            /* '<S3>/FRDoorRlsReq' */
  uint8 temporalCounter_i6;            /* '<S3>/FRDoorRlsReq' */
  uint8 temporalCounter_i7;            /* '<S3>/FRDoorRlsReq' */
  uint8 is_active_c5_DoorRlsReq_o;     /* '<S3>/FLDoorRlsReq' */
  uint8 is_RlsReq_p;                   /* '<S3>/FLDoorRlsReq' */
  uint8 is_Trigger_h3;                 /* '<S3>/FLDoorRlsReq' */
  uint8 is_SwValid_pj;                 /* '<S3>/FLDoorRlsReq' */
  uint8 is_RlsReq_o;                   /* '<S3>/FLDoorRlsReq' */
  uint8 is_Trigger_gx;                 /* '<S3>/FLDoorRlsReq' */
  uint8 is_RlsReq_o0;                  /* '<S3>/FLDoorRlsReq' */
  uint8 is_Trigger_d;                  /* '<S3>/FLDoorRlsReq' */
  uint8 is_SwValid_j;                  /* '<S3>/FLDoorRlsReq' */
  uint8 is_RlsReq_id;                  /* '<S3>/FLDoorRlsReq' */
  uint8 is_Trigger_g0;                 /* '<S3>/FLDoorRlsReq' */
  uint8 is_DoorCentral_f;              /* '<S3>/FLDoorRlsReq' */
  uint8 is_Trigger_k;                  /* '<S3>/FLDoorRlsReq' */
  uint8 temporalCounter_i1_m;          /* '<S3>/FLDoorRlsReq' */
  uint8 temporalCounter_i2_h;          /* '<S3>/FLDoorRlsReq' */
  uint8 temporalCounter_i3_b;          /* '<S3>/FLDoorRlsReq' */
  uint8 temporalCounter_i4_p;          /* '<S3>/FLDoorRlsReq' */
  uint8 temporalCounter_i5_l;          /* '<S3>/FLDoorRlsReq' */
  uint8 temporalCounter_i6_c;          /* '<S3>/FLDoorRlsReq' */
  uint8 temporalCounter_i7_l;          /* '<S3>/FLDoorRlsReq' */
  uint8 is_active_c23_REL;             /* '<S3>/DoorSwSts' */
  uint8 is_c23_REL;                    /* '<S3>/DoorSwSts' */
  uint8 is_active_c1_REL;              /* '<S3>/DoorLockSetSts' */
  uint8 is_c1_REL;                     /* '<S3>/DoorLockSetSts' */
  uint8 temporalCounter_i1_c;          /* '<S3>/DoorLockSetSts' */
  uint8 SI_e_DoorLockSet_prev;         /* '<S3>/DoorLockSetSts' */
  uint8 SI_e_DoorLockSet_start;        /* '<S3>/DoorLockSetSts' */
  boolean SI_b_DrvUnlockReq_prev;      /* '<S3>/Unlock_Request' */
  boolean SI_b_DrvUnlockReq_start;     /* '<S3>/Unlock_Request' */
  boolean SI_b_PassUnlockReq_prev;     /* '<S3>/Unlock_Request' */
  boolean SI_b_PassUnlockReq_start;    /* '<S3>/Unlock_Request' */
  boolean SL_b_DoorInSwValid;          /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_CentSingleDoorSwValid;  /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_CentAllDoorSwValid;     /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorOutSwValid;         /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorHandSwValid;        /* '<S3>/FRDoorRlsReq' */
  boolean SI_b_DoorLockOpenReq_prev;   /* '<S3>/FRDoorRlsReq' */
  boolean SI_b_DoorLockOpenReq_start;  /* '<S3>/FRDoorRlsReq' */
  boolean SI_b_DoorInSwSts_prev;       /* '<S3>/FRDoorRlsReq' */
  boolean SI_b_DoorInSwSts_start;      /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorInSwValid_prev;     /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorInSwValid_start;    /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorOutSwValid_prev;    /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorOutSwValid_start;   /* '<S3>/FRDoorRlsReq' */
  boolean SI_b_DoorHandSwSts_prev;     /* '<S3>/FRDoorRlsReq' */
  boolean SI_b_DoorHandSwSts_start;    /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorHandSwValid_prev;   /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorHandSwValid_start;  /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_CentSingleDoorSwValid_prev;/* '<S3>/FRDoorRlsReq' */
  boolean SL_b_CentSingleDoorSwValid_star;/* '<S3>/FRDoorRlsReq' */
  boolean SL_b_CentAllDoorSwValid_prev;/* '<S3>/FRDoorRlsReq' */
  boolean SL_b_CentAllDoorSwValid_start;/* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorInSwValid_g;        /* '<S3>/FLDoorRlsReq' */
  boolean SL_b_CentSingleDoorSwValid_h;/* '<S3>/FLDoorRlsReq' */
  boolean SL_b_CentAllDoorSwValid_h;   /* '<S3>/FLDoorRlsReq' */
  boolean SL_b_DoorOutSwValid_n;       /* '<S3>/FLDoorRlsReq' */
  boolean SL_b_DoorHandSwValid_m;      /* '<S3>/FLDoorRlsReq' */
  boolean SI_b_DoorLockOpenReq_prev_b; /* '<S3>/FLDoorRlsReq' */
  boolean SI_b_DoorLockOpenReq_start_e;/* '<S3>/FLDoorRlsReq' */
  boolean SI_b_DoorInSwSts_prev_d;     /* '<S3>/FLDoorRlsReq' */
  boolean SI_b_DoorInSwSts_start_g;    /* '<S3>/FLDoorRlsReq' */
  boolean SL_b_DoorInSwValid_prev_f;   /* '<S3>/FLDoorRlsReq' */
  boolean SL_b_DoorInSwValid_start_n;  /* '<S3>/FLDoorRlsReq' */
  boolean SL_b_DoorOutSwValid_prev_b;  /* '<S3>/FLDoorRlsReq' */
  boolean SL_b_DoorOutSwValid_start_a; /* '<S3>/FLDoorRlsReq' */
  boolean SI_b_DoorHandSwSts_prev_k;   /* '<S3>/FLDoorRlsReq' */
  boolean SI_b_DoorHandSwSts_start_c;  /* '<S3>/FLDoorRlsReq' */
  boolean SL_b_DoorHandSwValid_prev_c; /* '<S3>/FLDoorRlsReq' */
  boolean SL_b_DoorHandSwValid_start_l;/* '<S3>/FLDoorRlsReq' */
  boolean SL_b_CentSingleDoorSwValid_pr_a;/* '<S3>/FLDoorRlsReq' */
  boolean SL_b_CentSingleDoorSwValid_st_o;/* '<S3>/FLDoorRlsReq' */
  boolean SL_b_CentAllDoorSwValid_prev_n;/* '<S3>/FLDoorRlsReq' */
  boolean SL_b_CentAllDoorSwValid_start_o;/* '<S3>/FLDoorRlsReq' */
  boolean SI_b_CrashSts_prev;          /* '<S3>/DoorSwSts' */
  boolean SI_b_CrashSts_start;         /* '<S3>/DoorSwSts' */
  DW_RLDoorRlsReq_REL_T sf_RRDoorRlsReq;/* '<S3>/RRDoorRlsReq' */
  DW_FLDoorRlsDriver_REL_T sf_RRDoorRlsDriver;/* '<S3>/RRDoorRlsDriver' */
  DW_RLDoorRlsReq_REL_T sf_RLDoorRlsReq;/* '<S3>/RLDoorRlsReq' */
  DW_FLDoorRlsDriver_REL_T sf_RLDoorRlsDriver;/* '<S3>/RLDoorRlsDriver' */
  DW_FLDoorRlsDriver_REL_T sf_FRDoorRlsDriver;/* '<S3>/FRDoorRlsDriver' */
  DW_FLDoorRlsDriver_REL_T sf_FLDoorRlsDriver;/* '<S3>/FLDoorRlsDriver' */
} DW_REL_T;

/* Block signals (default storage) */
extern B_REL_T REL_B;

/* Block states (default storage) */
extern DW_REL_T REL_DW;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Constant1' : Unused code path elimination
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
 * '<S4>'   : 'REL/REL_Step_sys/REL/DoorLockSetSts'
 * '<S5>'   : 'REL/REL_Step_sys/REL/DoorSwSts'
 * '<S6>'   : 'REL/REL_Step_sys/REL/FLDoorRatSts'
 * '<S7>'   : 'REL/REL_Step_sys/REL/FLDoorRlsDriver'
 * '<S8>'   : 'REL/REL_Step_sys/REL/FLDoorRlsReq'
 * '<S9>'   : 'REL/REL_Step_sys/REL/FRDoorRatSts'
 * '<S10>'  : 'REL/REL_Step_sys/REL/FRDoorRlsDriver'
 * '<S11>'  : 'REL/REL_Step_sys/REL/FRDoorRlsReq'
 * '<S12>'  : 'REL/REL_Step_sys/REL/OFF '
 * '<S13>'  : 'REL/REL_Step_sys/REL/RLDoorRatSts'
 * '<S14>'  : 'REL/REL_Step_sys/REL/RLDoorRlsDriver'
 * '<S15>'  : 'REL/REL_Step_sys/REL/RLDoorRlsReq'
 * '<S16>'  : 'REL/REL_Step_sys/REL/RRDoorRatSts'
 * '<S17>'  : 'REL/REL_Step_sys/REL/RRDoorRlsDriver'
 * '<S18>'  : 'REL/REL_Step_sys/REL/RRDoorRlsReq'
 * '<S19>'  : 'REL/REL_Step_sys/REL/Unlock_Request'
 */
#endif                                 /* RTW_HEADER_REL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
