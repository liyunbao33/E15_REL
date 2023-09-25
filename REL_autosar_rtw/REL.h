/*
 * File: REL.h
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.139
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Sep 25 16:10:50 2023
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
  uint8 is_MainProgress_c;             /* '<S3>/FLDoorRlsDriver' */
  uint8 is_Release_a;                  /* '<S3>/FLDoorRlsDriver' */
  uint8 is_Step2_Open_i;               /* '<S3>/FLDoorRlsDriver' */
  uint8 SL_e_CycleCount;               /* '<S3>/FLDoorRlsDriver' */
  uint8 SL_e_DoorRlsDelayTime;         /* '<S3>/FLDoorRlsDriver' */
  boolean SO_b_DoorRlsReq_prev;        /* '<S3>/FLDoorRlsDriver' */
  boolean SO_b_DoorRlsReq_start;       /* '<S3>/FLDoorRlsDriver' */
} DW_FLDoorRlsDriver_REL_T;

/* Block states (default storage) for system '<S3>/RLDoorRlsReq' */
typedef struct {
  uint8 is_active_c5_DoorRlsReq;       /* '<S3>/RLDoorRlsReq' */
  uint8 is_SwValid;                    /* '<S3>/RLDoorRlsReq' */
  uint8 is_RlsReq;                     /* '<S3>/RLDoorRlsReq' */
  uint8 is_Trigger;                    /* '<S3>/RLDoorRlsReq' */
  uint8 is_DoorLock;                   /* '<S3>/RLDoorRlsReq' */
  uint8 is_RlsReq_i;                   /* '<S3>/RLDoorRlsReq' */
  uint8 is_Trigger_g;                  /* '<S3>/RLDoorRlsReq' */
  uint8 is_SwValid_f;                  /* '<S3>/RLDoorRlsReq' */
  uint8 is_RlsReq_e;                   /* '<S3>/RLDoorRlsReq' */
  uint8 is_Trigger_c;                  /* '<S3>/RLDoorRlsReq' */
  uint8 is_DoorLock_n;                 /* '<S3>/RLDoorRlsReq' */
  uint8 is_DoorCentral;                /* '<S3>/RLDoorRlsReq' */
  uint8 is_Trigger_f;                  /* '<S3>/RLDoorRlsReq' */
  uint8 is_DoorLock_o;                 /* '<S3>/RLDoorRlsReq' */
  uint8 is_RlsReq_h;                   /* '<S3>/RLDoorRlsReq' */
  uint8 is_Trigger_l;                  /* '<S3>/RLDoorRlsReq' */
  uint8 temporalCounter_i1;            /* '<S3>/RLDoorRlsReq' */
  uint8 temporalCounter_i2;            /* '<S3>/RLDoorRlsReq' */
  uint8 temporalCounter_i3;            /* '<S3>/RLDoorRlsReq' */
  uint8 temporalCounter_i4;            /* '<S3>/RLDoorRlsReq' */
  uint8 temporalCounter_i5;            /* '<S3>/RLDoorRlsReq' */
  uint8 temporalCounter_i6;            /* '<S3>/RLDoorRlsReq' */
  uint8 temporalCounter_i7;            /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_DoorInBtnValid;         /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_CentSingleDoorBtnValid; /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_CentAllDoorBtnValid;    /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_DoorHndPullValid;       /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_DoorHndBtnValid;        /* '<S3>/RLDoorRlsReq' */
  boolean SI_b_DoorInBtnSts_prev;      /* '<S3>/RLDoorRlsReq' */
  boolean SI_b_DoorInBtnSts_start;     /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_DoorInBtnValid_prev;    /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_DoorInBtnValid_start;   /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_DoorHndPullValid_prev;  /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_DoorHndPullValid_start; /* '<S3>/RLDoorRlsReq' */
  boolean SI_b_DoorHndBtnSts_prev;     /* '<S3>/RLDoorRlsReq' */
  boolean SI_b_DoorHndBtnSts_start;    /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_DoorHndBtnValid_prev;   /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_DoorHndBtnValid_start;  /* '<S3>/RLDoorRlsReq' */
  boolean SL_b_CentSingleDoorBtnValid_pre;/* '<S3>/RLDoorRlsReq' */
  boolean SL_b_CentSingleDoorBtnValid_sta;/* '<S3>/RLDoorRlsReq' */
  boolean SL_b_CentAllDoorBtnValid_prev;/* '<S3>/RLDoorRlsReq' */
  boolean SL_b_CentAllDoorBtnValid_start;/* '<S3>/RLDoorRlsReq' */
  boolean SI_b_DoorAutoRlsReq_prev;    /* '<S3>/RLDoorRlsReq' */
  boolean SI_b_DoorAutoRlsReq_start;   /* '<S3>/RLDoorRlsReq' */
} DW_RLDoorRlsReq_REL_T;

/* Block signals (default storage) */
typedef struct tag_B_REL_T {
  UInt8 TmpSignalConversionAtVeOUT_SP_E;
  uint8 SO_e_DoorRlsDelayTime;         /* '<S3>/RRDoorRlsReq' */
  uint8 SO_e_DoorRlsDelayTime_e;       /* '<S3>/RLDoorRlsReq' */
  uint8 SO_e_DoorRlsDelayTime_k;       /* '<S3>/FRDoorRlsReq' */
  uint8 SO_e_DoorRlsDelayTime_m;       /* '<S3>/FLDoorRlsReq' */
  boolean Compare;                     /* '<S11>/Compare' */
  Boolean TmpSignalConversionAtVbINP_CAN_;
  Boolean TmpSignalConversionAtVbINP_HWA_;
  Boolean TmpSignalConversionAtVbINP_HW_g;
  Boolean TmpSignalConversionAtVbINP_HW_f;
  Boolean TmpSignalConversionAtVbINP_H_gz;
  Boolean TmpSignalConversionAtVbINP_CA_f;
  Boolean TmpSignalConversionAtVbINP_CFG_;
  boolean SO_b_DoorRlsReq;             /* '<S3>/RRDoorRlsReq' */
  boolean SO_b_MotorA;                 /* '<S3>/RRDoorRlsDriver' */
  boolean SO_b_MotorB;                 /* '<S3>/RRDoorRlsDriver' */
  boolean SO_b_DoorRlsReq_j;           /* '<S3>/RLDoorRlsReq' */
  boolean SO_b_MotorA_f;               /* '<S3>/RLDoorRlsDriver' */
  boolean SO_b_MotorB_f;               /* '<S3>/RLDoorRlsDriver' */
  boolean SO_b_DoorRlsReq_l;           /* '<S3>/FRDoorRlsReq' */
  boolean SO_b_MotorA_fc;              /* '<S3>/FRDoorRlsDriver' */
  boolean SO_b_MotorB_b;               /* '<S3>/FRDoorRlsDriver' */
  boolean SO_b_DoorRlsReq_jt;          /* '<S3>/FLDoorRlsReq' */
  boolean SO_b_MotorA_b;               /* '<S3>/FLDoorRlsDriver' */
  boolean SO_b_MotorB_m;               /* '<S3>/FLDoorRlsDriver' */
  boolean SL_b_FLDoorInBtnSts;         /* '<S3>/DoorSwSts' */
  boolean SL_b_FRDoorInBtnSts;         /* '<S3>/DoorSwSts' */
  boolean SL_b_RLDoorInBtnSts;         /* '<S3>/DoorSwSts' */
  boolean SL_b_RRDoorInBtnSts;         /* '<S3>/DoorSwSts' */
  boolean SL_b_RLDoorHndPullSts;       /* '<S3>/DoorSwSts' */
  boolean SL_b_RRDoorHndPullSts;       /* '<S3>/DoorSwSts' */
  boolean SL_b_FRDoorHndBtnSts;        /* '<S3>/DoorSwSts' */
  boolean SL_b_RLDoorHndBtnSts;        /* '<S3>/DoorSwSts' */
  boolean SL_b_RRDoorHndBtnSts;        /* '<S3>/DoorSwSts' */
  boolean SO_b_DoorAutoRlsSetSts;      /* '<S3>/DoorAutoRlsSts' */
  boolean SO_b_DoorAutoRlsSetStsToEE;  /* '<S3>/DoorAutoRlsSts' */
  Unlock_Req_E SO_m_UnlockReq;         /* '<S3>/RRDoorRlsReq' */
  Unlock_Req_E SO_m_UnlockReq_e;       /* '<S3>/RLDoorRlsReq' */
  Unlock_Req_E SO_m_UnlockReq_d;       /* '<S3>/FRDoorRlsReq' */
  Unlock_Req_E SO_m_UnlockReq_k;       /* '<S3>/FLDoorRlsReq' */
  Rat_Sts_E SO_m_RLDoorRatSts;         /* '<S3>/DoorRatSts' */
  Rat_Sts_E SO_m_RRDoorRatSts;         /* '<S3>/DoorRatSts' */
  Mot_Cmd_E SO_e_MotorCmd;             /* '<S3>/RRDoorRlsDriver' */
  Mot_Cmd_E SO_e_MotorCmd_c;           /* '<S3>/RLDoorRlsDriver' */
  Mot_Cmd_E SO_e_MotorCmd_e;           /* '<S3>/FRDoorRlsDriver' */
  Mot_Cmd_E SO_e_MotorCmd_l;           /* '<S3>/FLDoorRlsDriver' */
  HndPos_Sts_E DataTypeConversion17;   /* '<S3>/Data Type Conversion17' */
  HndPos_Sts_E DataTypeConversion18;   /* '<S3>/Data Type Conversion18' */
  Gear_Posn_E DataTypeConversion14;    /* '<S3>/Data Type Conversion14' */
  Door_Sts_E DataTypeConversion13;     /* '<S3>/Data Type Conversion13' */
} B_REL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_REL_T {
  float64 E15_REL;                     /* '<S3>/Data Store Memory' */
  uint16 temporalCounter_i1;           /* '<S3>/DoorSwSts' */
  uint8 is_active_c6_REL;              /* '<S3>/Unlock_Request' */
  uint8 is_active_c5_DoorRlsReq;       /* '<S3>/FRDoorRlsReq' */
  uint8 is_SwValid;                    /* '<S3>/FRDoorRlsReq' */
  uint8 is_RlsReq;                     /* '<S3>/FRDoorRlsReq' */
  uint8 is_Trigger;                    /* '<S3>/FRDoorRlsReq' */
  uint8 is_DoorLock;                   /* '<S3>/FRDoorRlsReq' */
  uint8 is_RlsReq_c;                   /* '<S3>/FRDoorRlsReq' */
  uint8 is_Trigger_i;                  /* '<S3>/FRDoorRlsReq' */
  uint8 is_SwValid_k;                  /* '<S3>/FRDoorRlsReq' */
  uint8 is_RlsReq_n;                   /* '<S3>/FRDoorRlsReq' */
  uint8 is_Trigger_f;                  /* '<S3>/FRDoorRlsReq' */
  uint8 is_DoorLock_m;                 /* '<S3>/FRDoorRlsReq' */
  uint8 is_DoorCentral;                /* '<S3>/FRDoorRlsReq' */
  uint8 is_Trigger_b;                  /* '<S3>/FRDoorRlsReq' */
  uint8 is_DoorLock_m3;                /* '<S3>/FRDoorRlsReq' */
  uint8 is_RlsReq_p;                   /* '<S3>/FRDoorRlsReq' */
  uint8 is_Trigger_e;                  /* '<S3>/FRDoorRlsReq' */
  uint8 temporalCounter_i1_e;          /* '<S3>/FRDoorRlsReq' */
  uint8 temporalCounter_i2;            /* '<S3>/FRDoorRlsReq' */
  uint8 temporalCounter_i3;            /* '<S3>/FRDoorRlsReq' */
  uint8 temporalCounter_i4;            /* '<S3>/FRDoorRlsReq' */
  uint8 temporalCounter_i5;            /* '<S3>/FRDoorRlsReq' */
  uint8 temporalCounter_i6;            /* '<S3>/FRDoorRlsReq' */
  uint8 temporalCounter_i7;            /* '<S3>/FRDoorRlsReq' */
  uint8 is_active_c5_DoorRlsReq_b;     /* '<S3>/FLDoorRlsReq' */
  uint8 is_SwValid_c;                  /* '<S3>/FLDoorRlsReq' */
  uint8 is_RlsReq_k;                   /* '<S3>/FLDoorRlsReq' */
  uint8 is_Trigger_d;                  /* '<S3>/FLDoorRlsReq' */
  uint8 is_DoorLock_k;                 /* '<S3>/FLDoorRlsReq' */
  uint8 is_RlsReq_ku;                  /* '<S3>/FLDoorRlsReq' */
  uint8 is_Trigger_o;                  /* '<S3>/FLDoorRlsReq' */
  uint8 is_SwValid_d;                  /* '<S3>/FLDoorRlsReq' */
  uint8 is_RlsReq_o;                   /* '<S3>/FLDoorRlsReq' */
  uint8 is_Trigger_h;                  /* '<S3>/FLDoorRlsReq' */
  uint8 is_DoorLock_h;                 /* '<S3>/FLDoorRlsReq' */
  uint8 is_DoorCentral_m;              /* '<S3>/FLDoorRlsReq' */
  uint8 is_Trigger_do;                 /* '<S3>/FLDoorRlsReq' */
  uint8 is_DoorLock_c;                 /* '<S3>/FLDoorRlsReq' */
  uint8 is_RlsReq_na;                  /* '<S3>/FLDoorRlsReq' */
  uint8 is_Trigger_fu;                 /* '<S3>/FLDoorRlsReq' */
  uint8 temporalCounter_i1_h;          /* '<S3>/FLDoorRlsReq' */
  uint8 temporalCounter_i2_d;          /* '<S3>/FLDoorRlsReq' */
  uint8 temporalCounter_i3_b;          /* '<S3>/FLDoorRlsReq' */
  uint8 temporalCounter_i4_k;          /* '<S3>/FLDoorRlsReq' */
  uint8 temporalCounter_i5_h;          /* '<S3>/FLDoorRlsReq' */
  uint8 temporalCounter_i6_i;          /* '<S3>/FLDoorRlsReq' */
  uint8 temporalCounter_i7_l;          /* '<S3>/FLDoorRlsReq' */
  uint8 is_active_c23_REL;             /* '<S3>/DoorSwSts' */
  uint8 is_c23_REL;                    /* '<S3>/DoorSwSts' */
  uint8 is_active_c3_REL;              /* '<S3>/DoorRatSts' */
  uint8 is_active_c1_REL;              /* '<S3>/DoorAutoRlsSts' */
  uint8 SL_e_DoorAutoRlsSetBackup;     /* '<S3>/DoorAutoRlsSts' */
  boolean SL_b_DoorInBtnValid;         /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_CentSingleDoorBtnValid; /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_CentAllDoorBtnValid;    /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorHndPullValid;       /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorHndBtnValid;        /* '<S3>/FRDoorRlsReq' */
  boolean SI_b_DoorInBtnSts_prev;      /* '<S3>/FRDoorRlsReq' */
  boolean SI_b_DoorInBtnSts_start;     /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorInBtnValid_prev;    /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorInBtnValid_start;   /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorHndPullValid_prev;  /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorHndPullValid_start; /* '<S3>/FRDoorRlsReq' */
  boolean SI_b_DoorHndBtnSts_prev;     /* '<S3>/FRDoorRlsReq' */
  boolean SI_b_DoorHndBtnSts_start;    /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorHndBtnValid_prev;   /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorHndBtnValid_start;  /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_CentSingleDoorBtnValid_pre;/* '<S3>/FRDoorRlsReq' */
  boolean SL_b_CentSingleDoorBtnValid_sta;/* '<S3>/FRDoorRlsReq' */
  boolean SL_b_CentAllDoorBtnValid_prev;/* '<S3>/FRDoorRlsReq' */
  boolean SL_b_CentAllDoorBtnValid_start;/* '<S3>/FRDoorRlsReq' */
  boolean SI_b_DoorAutoRlsReq_prev;    /* '<S3>/FRDoorRlsReq' */
  boolean SI_b_DoorAutoRlsReq_start;   /* '<S3>/FRDoorRlsReq' */
  boolean SL_b_DoorInBtnValid_b;       /* '<S3>/FLDoorRlsReq' */
  boolean SL_b_CentSingleDoorBtnValid_p;/* '<S3>/FLDoorRlsReq' */
  boolean SL_b_CentAllDoorBtnValid_h;  /* '<S3>/FLDoorRlsReq' */
  boolean SL_b_DoorHndPullValid_h;     /* '<S3>/FLDoorRlsReq' */
  boolean SL_b_DoorHndBtnValid_i;      /* '<S3>/FLDoorRlsReq' */
  boolean SI_b_DoorInBtnSts_prev_j;    /* '<S3>/FLDoorRlsReq' */
  boolean SI_b_DoorInBtnSts_start_a;   /* '<S3>/FLDoorRlsReq' */
  boolean SL_b_DoorInBtnValid_prev_e;  /* '<S3>/FLDoorRlsReq' */
  boolean SL_b_DoorInBtnValid_start_g; /* '<S3>/FLDoorRlsReq' */
  boolean SL_b_DoorHndPullValid_prev_d;/* '<S3>/FLDoorRlsReq' */
  boolean SL_b_DoorHndPullValid_start_g;/* '<S3>/FLDoorRlsReq' */
  boolean SI_b_DoorHndBtnSts_prev_f;   /* '<S3>/FLDoorRlsReq' */
  boolean SI_b_DoorHndBtnSts_start_m;  /* '<S3>/FLDoorRlsReq' */
  boolean SL_b_DoorHndBtnValid_prev_m; /* '<S3>/FLDoorRlsReq' */
  boolean SL_b_DoorHndBtnValid_start_h;/* '<S3>/FLDoorRlsReq' */
  boolean SL_b_CentSingleDoorBtnValid_p_e;/* '<S3>/FLDoorRlsReq' */
  boolean SL_b_CentSingleDoorBtnValid_s_a;/* '<S3>/FLDoorRlsReq' */
  boolean SL_b_CentAllDoorBtnValid_prev_c;/* '<S3>/FLDoorRlsReq' */
  boolean SL_b_CentAllDoorBtnValid_star_m;/* '<S3>/FLDoorRlsReq' */
  boolean SI_b_DoorAutoRlsReq_prev_b;  /* '<S3>/FLDoorRlsReq' */
  boolean SI_b_DoorAutoRlsReq_start_k; /* '<S3>/FLDoorRlsReq' */
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
 * Block '<S3>/Data Type Conversion8' : Unused code path elimination
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
 * '<S4>'   : 'REL/REL_Step_sys/REL/DoorAutoRlsSts'
 * '<S5>'   : 'REL/REL_Step_sys/REL/DoorRatSts'
 * '<S6>'   : 'REL/REL_Step_sys/REL/DoorSwSts'
 * '<S7>'   : 'REL/REL_Step_sys/REL/FLDoorRlsDriver'
 * '<S8>'   : 'REL/REL_Step_sys/REL/FLDoorRlsReq'
 * '<S9>'   : 'REL/REL_Step_sys/REL/FRDoorRlsDriver'
 * '<S10>'  : 'REL/REL_Step_sys/REL/FRDoorRlsReq'
 * '<S11>'  : 'REL/REL_Step_sys/REL/OFF '
 * '<S12>'  : 'REL/REL_Step_sys/REL/RLDoorRlsDriver'
 * '<S13>'  : 'REL/REL_Step_sys/REL/RLDoorRlsReq'
 * '<S14>'  : 'REL/REL_Step_sys/REL/RRDoorRlsDriver'
 * '<S15>'  : 'REL/REL_Step_sys/REL/RRDoorRlsReq'
 * '<S16>'  : 'REL/REL_Step_sys/REL/Recycle Bin'
 * '<S17>'  : 'REL/REL_Step_sys/REL/Unlock_Request'
 */
#endif                                 /* RTW_HEADER_REL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
