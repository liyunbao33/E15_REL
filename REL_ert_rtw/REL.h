/*
 * File: REL.h
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.31
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Sep 19 16:42:13 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_REL_h_
#define RTW_HEADER_REL_h_
#ifndef REL_COMMON_INCLUDES_
#define REL_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* REL_COMMON_INCLUDES_ */

#include "REL_types.h"
#include "Rte_Type.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S3>/FLDoorRlsDriver' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S3>/FLDoorRlsDriver' */
  uint8_T is_active_c19_DoorRlsDriver; /* '<S3>/FLDoorRlsDriver' */
  uint8_T is_c19_DoorRlsDriver;        /* '<S3>/FLDoorRlsDriver' */
  uint8_T is_MainProgress;             /* '<S3>/FLDoorRlsDriver' */
  uint8_T is_Release;                  /* '<S3>/FLDoorRlsDriver' */
  uint8_T is_Step2_Open;               /* '<S3>/FLDoorRlsDriver' */
  uint8_T SL_e_CheckCycle;             /* '<S3>/FLDoorRlsDriver' */
  uint8_T SL_e_DoorRlsDelayTime;       /* '<S3>/FLDoorRlsDriver' */
  boolean_T SO_b_DoorRlsReq_prev;      /* '<S3>/FLDoorRlsDriver' */
  boolean_T SO_b_DoorRlsReq_start;     /* '<S3>/FLDoorRlsDriver' */
} DW_FLDoorRlsDriver_REL_T;

/* Block states (default storage) for system '<S3>/RLDoorRlsReq' */
typedef struct {
  uint8_T is_active_c5_DoorRlsReq;     /* '<S3>/RLDoorRlsReq' */
  uint8_T is_SwValid;                  /* '<S3>/RLDoorRlsReq' */
  uint8_T is_RlsReq;                   /* '<S3>/RLDoorRlsReq' */
  uint8_T is_Trigger;                  /* '<S3>/RLDoorRlsReq' */
  uint8_T is_DoorLock;                 /* '<S3>/RLDoorRlsReq' */
  uint8_T is_RlsReq_i;                 /* '<S3>/RLDoorRlsReq' */
  uint8_T is_Trigger_g;                /* '<S3>/RLDoorRlsReq' */
  uint8_T is_SwValid_f;                /* '<S3>/RLDoorRlsReq' */
  uint8_T is_RlsReq_e;                 /* '<S3>/RLDoorRlsReq' */
  uint8_T is_Trigger_c;                /* '<S3>/RLDoorRlsReq' */
  uint8_T is_DoorLock_n;               /* '<S3>/RLDoorRlsReq' */
  uint8_T is_DoorCentral;              /* '<S3>/RLDoorRlsReq' */
  uint8_T is_Trigger_f;                /* '<S3>/RLDoorRlsReq' */
  uint8_T is_DoorLock_o;               /* '<S3>/RLDoorRlsReq' */
  uint8_T is_RlsReq_h;                 /* '<S3>/RLDoorRlsReq' */
  uint8_T is_Trigger_l;                /* '<S3>/RLDoorRlsReq' */
  uint8_T temporalCounter_i1;          /* '<S3>/RLDoorRlsReq' */
  uint8_T temporalCounter_i2;          /* '<S3>/RLDoorRlsReq' */
  uint8_T temporalCounter_i3;          /* '<S3>/RLDoorRlsReq' */
  uint8_T temporalCounter_i4;          /* '<S3>/RLDoorRlsReq' */
  uint8_T temporalCounter_i5;          /* '<S3>/RLDoorRlsReq' */
  uint8_T temporalCounter_i6;          /* '<S3>/RLDoorRlsReq' */
  uint8_T temporalCounter_i7;          /* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_DoorInBtnValid;       /* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_CentSingleDoorBtnValid;/* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_CentAllDoorBtnValid;  /* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_DoorHndPullValid;     /* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_DoorHndBtnValid;      /* '<S3>/RLDoorRlsReq' */
  boolean_T SI_b_DoorInBtnSts_prev;    /* '<S3>/RLDoorRlsReq' */
  boolean_T SI_b_DoorInBtnSts_start;   /* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_DoorInBtnValid_prev;  /* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_DoorInBtnValid_start; /* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_DoorHndPullValid_prev;/* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_DoorHndPullValid_start;/* '<S3>/RLDoorRlsReq' */
  boolean_T SI_b_DoorHndBtnSts_prev;   /* '<S3>/RLDoorRlsReq' */
  boolean_T SI_b_DoorHndBtnSts_start;  /* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_DoorHndBtnValid_prev; /* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_DoorHndBtnValid_start;/* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_CentSingleDoorBtnValid_pre;/* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_CentSingleDoorBtnValid_sta;/* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_CentAllDoorBtnValid_prev;/* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_CentAllDoorBtnValid_start;/* '<S3>/RLDoorRlsReq' */
  boolean_T SI_b_DoorAutoRlsReq_prev;  /* '<S3>/RLDoorRlsReq' */
  boolean_T SI_b_DoorAutoRlsReq_start; /* '<S3>/RLDoorRlsReq' */
} DW_RLDoorRlsReq_REL_T;

/* Block signals (default storage) */
typedef struct {
  uint8_T SO_e_DoorRlsDelayTime;       /* '<S3>/RRDoorRlsReq' */
  uint8_T SO_e_DoorRlsDelayTime_e;     /* '<S3>/RLDoorRlsReq' */
  uint8_T SO_e_DoorRlsDelayTime_k;     /* '<S3>/FRDoorRlsReq' */
  uint8_T SO_e_DoorRlsDelayTime_m;     /* '<S3>/FLDoorRlsReq' */
  boolean_T SO_b_UnlockReq;            /* '<S3>/RRDoorRlsReq' */
  boolean_T SO_b_PEUnlockReq;          /* '<S3>/RRDoorRlsReq' */
  boolean_T SO_b_UnlockReq_m;          /* '<S3>/RLDoorRlsReq' */
  boolean_T SO_b_PEUnlockReq_i;        /* '<S3>/RLDoorRlsReq' */
  boolean_T SO_b_UnlockReq_c;          /* '<S3>/FRDoorRlsReq' */
  boolean_T SO_b_PEUnlockReq_e;        /* '<S3>/FRDoorRlsReq' */
  boolean_T SO_b_UnlockReq_k;          /* '<S3>/FLDoorRlsReq' */
  boolean_T SO_b_PEUnlockReq_g;        /* '<S3>/FLDoorRlsReq' */
} B_REL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S3>/DoorSwSts' */
  uint8_T is_active_c6_REL;            /* '<S3>/Unlock_Request' */
  uint8_T is_active_c5_DoorRlsReq;     /* '<S3>/FRDoorRlsReq' */
  uint8_T is_SwValid;                  /* '<S3>/FRDoorRlsReq' */
  uint8_T is_RlsReq;                   /* '<S3>/FRDoorRlsReq' */
  uint8_T is_Trigger;                  /* '<S3>/FRDoorRlsReq' */
  uint8_T is_DoorLock;                 /* '<S3>/FRDoorRlsReq' */
  uint8_T is_RlsReq_c;                 /* '<S3>/FRDoorRlsReq' */
  uint8_T is_Trigger_i;                /* '<S3>/FRDoorRlsReq' */
  uint8_T is_SwValid_k;                /* '<S3>/FRDoorRlsReq' */
  uint8_T is_RlsReq_n;                 /* '<S3>/FRDoorRlsReq' */
  uint8_T is_Trigger_f;                /* '<S3>/FRDoorRlsReq' */
  uint8_T is_DoorLock_m;               /* '<S3>/FRDoorRlsReq' */
  uint8_T is_DoorCentral;              /* '<S3>/FRDoorRlsReq' */
  uint8_T is_Trigger_b;                /* '<S3>/FRDoorRlsReq' */
  uint8_T is_DoorLock_m3;              /* '<S3>/FRDoorRlsReq' */
  uint8_T is_RlsReq_p;                 /* '<S3>/FRDoorRlsReq' */
  uint8_T is_Trigger_e;                /* '<S3>/FRDoorRlsReq' */
  uint8_T temporalCounter_i1_e;        /* '<S3>/FRDoorRlsReq' */
  uint8_T temporalCounter_i2;          /* '<S3>/FRDoorRlsReq' */
  uint8_T temporalCounter_i3;          /* '<S3>/FRDoorRlsReq' */
  uint8_T temporalCounter_i4;          /* '<S3>/FRDoorRlsReq' */
  uint8_T temporalCounter_i5;          /* '<S3>/FRDoorRlsReq' */
  uint8_T temporalCounter_i6;          /* '<S3>/FRDoorRlsReq' */
  uint8_T temporalCounter_i7;          /* '<S3>/FRDoorRlsReq' */
  uint8_T is_active_c5_DoorRlsReq_b;   /* '<S3>/FLDoorRlsReq' */
  uint8_T is_SwValid_c;                /* '<S3>/FLDoorRlsReq' */
  uint8_T is_RlsReq_k;                 /* '<S3>/FLDoorRlsReq' */
  uint8_T is_Trigger_d;                /* '<S3>/FLDoorRlsReq' */
  uint8_T is_DoorLock_k;               /* '<S3>/FLDoorRlsReq' */
  uint8_T is_RlsReq_ku;                /* '<S3>/FLDoorRlsReq' */
  uint8_T is_Trigger_o;                /* '<S3>/FLDoorRlsReq' */
  uint8_T is_SwValid_d;                /* '<S3>/FLDoorRlsReq' */
  uint8_T is_RlsReq_o;                 /* '<S3>/FLDoorRlsReq' */
  uint8_T is_Trigger_h;                /* '<S3>/FLDoorRlsReq' */
  uint8_T is_DoorLock_h;               /* '<S3>/FLDoorRlsReq' */
  uint8_T is_DoorCentral_m;            /* '<S3>/FLDoorRlsReq' */
  uint8_T is_Trigger_do;               /* '<S3>/FLDoorRlsReq' */
  uint8_T is_DoorLock_c;               /* '<S3>/FLDoorRlsReq' */
  uint8_T is_RlsReq_na;                /* '<S3>/FLDoorRlsReq' */
  uint8_T is_Trigger_fu;               /* '<S3>/FLDoorRlsReq' */
  uint8_T temporalCounter_i1_h;        /* '<S3>/FLDoorRlsReq' */
  uint8_T temporalCounter_i2_d;        /* '<S3>/FLDoorRlsReq' */
  uint8_T temporalCounter_i3_b;        /* '<S3>/FLDoorRlsReq' */
  uint8_T temporalCounter_i4_k;        /* '<S3>/FLDoorRlsReq' */
  uint8_T temporalCounter_i5_h;        /* '<S3>/FLDoorRlsReq' */
  uint8_T temporalCounter_i6_i;        /* '<S3>/FLDoorRlsReq' */
  uint8_T temporalCounter_i7_l;        /* '<S3>/FLDoorRlsReq' */
  uint8_T is_active_c23_REL;           /* '<S3>/DoorSwSts' */
  uint8_T is_c23_REL;                  /* '<S3>/DoorSwSts' */
  uint8_T is_active_c1_REL;            /* '<S3>/DoorLockSetSts' */
  uint8_T SL_e_DoorAutoRlsSetBackup;   /* '<S3>/DoorLockSetSts' */
  boolean_T SL_b_DoorInBtnValid;       /* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_CentSingleDoorBtnValid;/* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_CentAllDoorBtnValid;  /* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_DoorHndPullValid;     /* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_DoorHndBtnValid;      /* '<S3>/FRDoorRlsReq' */
  boolean_T SI_b_DoorInBtnSts_start;   /* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_DoorInBtnValid_start; /* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_DoorHndPullValid_start;/* '<S3>/FRDoorRlsReq' */
  boolean_T SI_b_DoorHndBtnSts_start;  /* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_DoorHndBtnValid_start;/* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_CentSingleDoorBtnValid_sta;/* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_CentAllDoorBtnValid_start;/* '<S3>/FRDoorRlsReq' */
  boolean_T SI_b_DoorAutoRlsReq_start; /* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_DoorInBtnValid_b;     /* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_CentSingleDoorBtnValid_p;/* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_CentAllDoorBtnValid_h;/* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_DoorHndPullValid_h;   /* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_DoorHndBtnValid_i;    /* '<S3>/FLDoorRlsReq' */
  boolean_T SI_b_DoorInBtnSts_start_a; /* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_DoorInBtnValid_start_g;/* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_DoorHndPullValid_start_g;/* '<S3>/FLDoorRlsReq' */
  boolean_T SI_b_DoorHndBtnSts_start_m;/* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_DoorHndBtnValid_start_h;/* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_CentSingleDoorBtnValid_s_a;/* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_CentAllDoorBtnValid_star_m;/* '<S3>/FLDoorRlsReq' */
  boolean_T SI_b_DoorAutoRlsReq_start_k;/* '<S3>/FLDoorRlsReq' */
  boolean_T SI_b_CrashSts_start;       /* '<S3>/DoorSwSts' */
  DW_RLDoorRlsReq_REL_T sf_RRDoorRlsReq;/* '<S3>/RRDoorRlsReq' */
  DW_FLDoorRlsDriver_REL_T sf_RRDoorRlsDriver;/* '<S3>/RRDoorRlsDriver' */
  DW_RLDoorRlsReq_REL_T sf_RLDoorRlsReq;/* '<S3>/RLDoorRlsReq' */
  DW_FLDoorRlsDriver_REL_T sf_RLDoorRlsDriver;/* '<S3>/RLDoorRlsDriver' */
  DW_FLDoorRlsDriver_REL_T sf_FRDoorRlsDriver;/* '<S3>/FRDoorRlsDriver' */
  DW_FLDoorRlsDriver_REL_T sf_FLDoorRlsDriver;/* '<S3>/FLDoorRlsDriver' */
} DW_REL_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  UInt8 VeOUT_PDU_BcmPowerStatusFeedbac;
  /* '<Root>/VeOUT_PDU_BcmPowerStatusFeedback_sig_VeOUT_PDU_BcmPowerStatusFeedback_sig' */
  UInt8 VeINP_CAN_CdcDrvrDoorLockSet_si;
  /* '<Root>/VeINP_CAN_CdcDrvrDoorLockSet_sig_VeINP_CAN_CdcDrvrDoorLockSet_sig' */
  UInt8 VeINP_EPRM_BdcDrvrDoorLockSetSt;
  /* '<Root>/VeINP_EPRM_BdcDrvrDoorLockSetSts_sig_VeINP_EPRM_BdcDrvrDoorLockSetSts_sig' */
  UInt8 VeOUT_DLK_BdcDrvrDoorLockSts_si;
  /* '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig' */
  UInt8 VeOUT_SP_EspVehSpd_kmh_VeOUT_SP;
                    /* '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' */
  Boolean VbINP_CAN_EspVehSpdVld_flg_VbIN;
            /* '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg' */
  UInt8 VeINP_CAN_VcuGearPosn_sig_VeINP;
              /* '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig' */
  Boolean VbINP_HWA_FLDoorButton_flg_VbIN;
            /* '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg' */
  Boolean VbINP_HWA_FRDoorButton_flg_VbIN;
            /* '<Root>/VbINP_HWA_FRDoorButton_flg_VbINP_HWA_FRDoorButton_flg' */
  Boolean VbINP_HWA_RLDoorButton_flg_VbIN;
            /* '<Root>/VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg' */
  Boolean VbINP_HWA_RRDoorButton_flg_VbIN;
            /* '<Root>/VbINP_HWA_RRDoorButton_flg_VbINP_HWA_RRDoorButton_flg' */
  UInt8 VmOUT_DLK_LockSrc_enum_VmOUT_DL;
                    /* '<Root>/VmOUT_DLK_LockSrc_enum_VmOUT_DLK_LockSrc_enum' */
  Boolean VbINP_HWA_LRChildLckSt_flg_VbIN;
            /* '<Root>/VbINP_HWA_LRChildLckSt_flg_VbINP_HWA_LRChildLckSt_flg' */
  Boolean VbINP_HWA_RRChildLckSt_flg_VbIN;
            /* '<Root>/VbINP_HWA_RRChildLckSt_flg_VbINP_HWA_RRChildLckSt_flg' */
  Boolean VbOUT_DLK_Unlock_flg_VbOUT_DLK_;
                        /* '<Root>/VbOUT_DLK_Unlock_flg_VbOUT_DLK_Unlock_flg' */
  Boolean VbINP_HWA_FLDoorOutButton_flg_V;
      /* '<Root>/VbINP_HWA_FLDoorOutButton_flg_VbINP_HWA_FLDoorOutButton_flg' */
  Boolean VbINP_HWA_FRDoorOutButton_flg_V;
      /* '<Root>/VbINP_HWA_FRDoorOutButton_flg_VbINP_HWA_FRDoorOutButton_flg' */
  Boolean VbINP_HWA_RLDoorOutButton_flg_V;
      /* '<Root>/VbINP_HWA_RLDoorOutButton_flg_VbINP_HWA_RLDoorOutButton_flg' */
  Boolean VbINP_HWA_RRDoorOutButton_flg_V;
      /* '<Root>/VbINP_HWA_RRDoorOutButton_flg_VbINP_HWA_RRDoorOutButton_flg' */
  Boolean VbINP_HWA_FLDoorHandleSW_flg_Vb;
        /* '<Root>/VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg' */
  Boolean VbINP_HWA_FRDoorHandleSW_flg_Vb;
        /* '<Root>/VbINP_HWA_FRDoorHandleSW_flg_VbINP_HWA_FRDoorHandleSW_flg' */
  Boolean VbINP_HWA_RLDoorHandleSW_flg_Vb;
        /* '<Root>/VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg' */
  Boolean VbINP_HWA_RRDoorHandleSW_flg_Vb;
        /* '<Root>/VbINP_HWA_RRDoorHandleSW_flg_VbINP_HWA_RRDoorHandleSW_flg' */
  Boolean VbINP_CAN_CdcAllDoorOpenButtonS;
  /* '<Root>/VbINP_CAN_CdcAllDoorOpenButtonSts_flg_VbINP_CAN_CdcAllDoorOpenButtonSts_flg' */
  UInt8 VeOUT_DLK_BCMPassengerDoorLockS;
  /* '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig' */
  Boolean VbINP_CAN_CdcDrvrDoorButtonSts_;
  /* '<Root>/VbINP_CAN_CdcDrvrDoorButtonSts_flg_VbINP_CAN_CdcDrvrDoorButtonSts_flg' */
  Boolean VbINP_CAN_CdcPassDoorButtonSts_;
  /* '<Root>/VbINP_CAN_CdcPassDoorButtonSts_flg_VbINP_CAN_CdcPassDoorButtonSts_flg' */
  Boolean VbINP_CAN_CdcLeReDoorButtonSts_;
  /* '<Root>/VbINP_CAN_CdcLeReDoorButtonSts_flg_VbINP_CAN_CdcLeReDoorButtonSts_flg' */
  Boolean VbINP_CAN_CdcRiReDoorButtonSts_;
  /* '<Root>/VbINP_CAN_CdcRiReDoorButtonSts_flg_VbINP_CAN_CdcRiReDoorButtonSts_flg' */
  Boolean VbINP_CFG_ElectricalDoorCfg_flg;
  /* '<Root>/VbINP_CFG_ElectricalDoorCfg_flg_VbINP_CFG_ElectricalDoorCfg_flg' */
  Boolean VbINP_HWA_FLDoorAjar_flg_VbINP_;
                /* '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg' */
  Boolean VbINP_HWA_FRDoorAjar_flg_VbINP_;
                /* '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg' */
  Boolean VbINP_HWA_RLDoorAjar_flg_VbINP_;
                /* '<Root>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg' */
  Boolean VbINP_HWA_RRDoorAjar_flg_VbINP_;
                /* '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg' */
  Boolean VbINP_CAN_FLDCUCinchHomeSwitch_;
  /* '<Root>/VbINP_CAN_FLDCUCinchHomeSwitch_flg_VbINP_CAN_FLDCUCinchHomeSwitch_flg' */
  Boolean VbINP_CAN_FRDCUCinchHomeSwitch_;
  /* '<Root>/VbINP_CAN_FRDCUCinchHomeSwitch_flg_VbINP_CAN_FRDCUCinchHomeSwitch_flg' */
  Boolean VbINP_CAN_RLDCUCinchHomeSwitch_;
  /* '<Root>/VbINP_CAN_RLDCUCinchHomeSwitch_flg_VbINP_CAN_RLDCUCinchHomeSwitch_flg' */
  Boolean VbINP_CAN_RRDCUCinchHomeSwitch_;
  /* '<Root>/VbINP_CAN_RRDCUCinchHomeSwitch_flg_VbINP_CAN_RRDCUCinchHomeSwitch_flg' */
  Boolean VbINP_HWA_FLCinchHomeSW_flg_VbI;
          /* '<Root>/VbINP_HWA_FLCinchHomeSW_flg_VbINP_HWA_FLCinchHomeSW_flg' */
  Boolean VbINP_HWA_FRCinchHomeSW_flg_VbI;
          /* '<Root>/VbINP_HWA_FRCinchHomeSW_flg_VbINP_HWA_FRCinchHomeSW_flg' */
  Boolean VbINP_HWA_RLCinchHomeSW_flg_VbI;
          /* '<Root>/VbINP_HWA_RLCinchHomeSW_flg_VbINP_HWA_RLCinchHomeSW_flg' */
  Boolean VbINP_HWA_RRCinchHomeSW_flg_VbI;
          /* '<Root>/VbINP_HWA_RRCinchHomeSW_flg_VbINP_HWA_RRCinchHomeSW_flg' */
  UInt8 VeOUT_DHM_BDCDrvrDoorHndSts_sig;
  /* '<Root>/VeOUT_DHM_BDCDrvrDoorHndSts_sig_VeOUT_DHM_BDCDrvrDoorHndSts_sig' */
  UInt8 VeOUT_DHM_BDCPassDoorHndSts_sig;
  /* '<Root>/VeOUT_DHM_BDCPassDoorHndSts_sig_VeOUT_DHM_BDCPassDoorHndSts_sig' */
  UInt8 VeOUT_DHM_BDCLeReDoorHndSts_sig;
  /* '<Root>/VeOUT_DHM_BDCLeReDoorHndSts_sig_VeOUT_DHM_BDCLeReDoorHndSts_sig' */
  UInt8 VeOUT_DHM_BDCRiReDoorHndSts_sig;
  /* '<Root>/VeOUT_DHM_BDCRiReDoorHndSts_sig_VeOUT_DHM_BDCRiReDoorHndSts_sig' */
  Boolean VbOUT_SP_CrashOutpSts_flg_VbOUT;
              /* '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg' */
  Boolean VbOUT_DLK_BdcDrvrDoorLockOpenRe;
  /* '<Root>/VbOUT_DLK_BdcDrvrDoorLockOpenReq_flg_VbOUT_DLK_BdcDrvrDoorLockOpenReq_flg' */
} ExtU_REL_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  Boolean VbOUT_REL_BdcDrvrDoorLockSetSts;
  /* '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
  Boolean VbOUT_REL_BdcDrvrDoorLockSetS_j;
  /* '<Root>/VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg_VbOUT_REL_BdcDrvrDoorLockSetStsToEE_flg' */
  UInt8 VeOUT_REL_BcmDrvrDoorSwtSts_sig;
  /* '<Root>/VeOUT_REL_BcmDrvrDoorSwtSts_sig_VeOUT_REL_BcmDrvrDoorSwtSts_sig' */
  UInt8 VeOUT_REL_BcmPassDoorSwtSts_sig;
  /* '<Root>/VeOUT_REL_BcmPassDoorSwtSts_sig_VeOUT_REL_BcmPassDoorSwtSts_sig' */
  UInt8 VeOUT_REL_BcmLeReDoorSwtSts_sig;
  /* '<Root>/VeOUT_REL_BcmLeReDoorSwtSts_sig_VeOUT_REL_BcmLeReDoorSwtSts_sig' */
  UInt8 VeOUT_REL_BcmRiReDoorSwtSts_sig;
  /* '<Root>/VeOUT_REL_BcmRiReDoorSwtSts_sig_VeOUT_REL_BcmRiReDoorSwtSts_sig' */
  UInt8 VeOUT_REL_BdcLFDoorRatSts_sig_V;
      /* '<Root>/VeOUT_REL_BdcLFDoorRatSts_sig_VeOUT_REL_BdcLFDoorRatSts_sig' */
  UInt8 VeOUT_REL_BdcRFDoorRatSts_sig_V;
      /* '<Root>/VeOUT_REL_BdcRFDoorRatSts_sig_VeOUT_REL_BdcRFDoorRatSts_sig' */
  UInt8 VeOUT_REL_BdcLRDoorRatSts_sig_V;
      /* '<Root>/VeOUT_REL_BdcLRDoorRatSts_sig_VeOUT_REL_BdcLRDoorRatSts_sig' */
  UInt8 VeOUT_REL_BdcRRDoorRatSts_sig_V;
      /* '<Root>/VeOUT_REL_BdcRRDoorRatSts_sig_VeOUT_REL_BdcRRDoorRatSts_sig' */
  Boolean VbOUT_REL_BcmDrvrDoorHandleReq_;
  /* '<Root>/VbOUT_REL_BcmDrvrDoorHandleReq_flg_VbOUT_REL_BcmDrvrDoorHandleReq_flg' */
  Boolean VbOUT_REL_BcmPassDoorHandleReq_;
  /* '<Root>/VbOUT_REL_BcmPassDoorHandleReq_flg_VbOUT_REL_BcmPassDoorHandleReq_flg' */
  Boolean VbOUT_REL_BcmLeReDoorHandleReq_;
  /* '<Root>/VbOUT_REL_BcmLeReDoorHandleReq_flg_VbOUT_REL_BcmLeReDoorHandleReq_flg' */
  Boolean VbOUT_REL_BcmBcmRiReDoorHandleR;
  /* '<Root>/VbOUT_REL_BcmBcmRiReDoorHandleReq_flg_VbOUT_REL_BcmBcmRiReDoorHandleReq_flg' */
  Boolean VbOUT_REL_FLDoorHndlBtnSig_flg_;
    /* '<Root>/VbOUT_REL_FLDoorHndlBtnSig_flg_VbOUT_REL_FLDoorHndlBtnSig_flg' */
  Boolean VbOUT_REL_FRDoorHndlBtnSig_flg_;
    /* '<Root>/VbOUT_REL_FRDoorHndlBtnSig_flg_VbOUT_REL_FRDoorHndlBtnSig_flg' */
  Boolean VbOUT_REL_RLDoorHndlBtnSig_flg_;
    /* '<Root>/VbOUT_REL_RLDoorHndlBtnSig_flg_VbOUT_REL_RLDoorHndlBtnSig_flg' */
  Boolean VbOUT_REL_RRDoorHndlBtnSig_flg_;
    /* '<Root>/VbOUT_REL_RRDoorHndlBtnSig_flg_VbOUT_REL_RRDoorHndlBtnSig_flg' */
  Boolean VbOUT_REL_FLDoorMotorA_flg_VbOU;
            /* '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
  Boolean VbOUT_REL_FLDoorMotorB_flg_VbOU;
            /* '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
  Boolean VbOUT_REL_FRDoorMotorA_flg_VbOU;
            /* '<Root>/VbOUT_REL_FRDoorMotorA_flg_VbOUT_REL_FRDoorMotorA_flg' */
  Boolean VbOUT_REL_FRDoorMotorB_flg_VbOU;
            /* '<Root>/VbOUT_REL_FRDoorMotorB_flg_VbOUT_REL_FRDoorMotorB_flg' */
  Boolean VbOUT_REL_RLDoorMotorA_flg_VbOU;
            /* '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg' */
  Boolean VbOUT_REL_RLDoorMotorB_flg_VbOU;
            /* '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg' */
  Boolean VbOUT_REL_RRDoorMotorA_flg_VbOU;
            /* '<Root>/VbOUT_REL_RRDoorMotorA_flg_VbOUT_REL_RRDoorMotorA_flg' */
  Boolean VbOUT_REL_RRDoorMotorB_flg_VbOU;
            /* '<Root>/VbOUT_REL_RRDoorMotorB_flg_VbOUT_REL_RRDoorMotorB_flg' */
  UInt8 VeOUT_REL_DLKReqUnlock_sig_VeOU;
            /* '<Root>/VeOUT_REL_DLKReqUnlock_sig_VeOUT_REL_DLKReqUnlock_sig' */
  Boolean VbOUT_REL_FLDoorRlsReq_flg_VbOU;
            /* '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
  Boolean VbOUT_REL_FRDoorRlsReq_flg_VbOU;
            /* '<Root>/VbOUT_REL_FRDoorRlsReq_flg_VbOUT_REL_FRDoorRlsReq_flg' */
  Boolean VbOUT_REL_RLDoorRlsReq_flg_VbOU;
            /* '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg' */
  Boolean VbOUT_REL_RRDoorRlsReq_flg_VbOU;
            /* '<Root>/VbOUT_REL_RRDoorRlsReq_flg_VbOUT_REL_RRDoorRlsReq_flg' */
  UInt8 VeOUT_REL_FLDoorMotorSts_sig_Ve;
        /* '<Root>/VeOUT_REL_FLDoorMotorSts_sig_VeOUT_REL_FLDoorMotorSts_sig' */
  UInt8 VeOUT_REL_FRDoorMotorSts_sig_Ve;
        /* '<Root>/VeOUT_REL_FRDoorMotorSts_sig_VeOUT_REL_FRDoorMotorSts_sig' */
  UInt8 VeOUT_REL_RLDoorMotorSts_sig_Ve;
        /* '<Root>/VeOUT_REL_RLDoorMotorSts_sig_VeOUT_REL_RLDoorMotorSts_sig' */
  UInt8 VeOUT_REL_RRDoorMotorSts_sig_Ve;
        /* '<Root>/VeOUT_REL_RRDoorMotorSts_sig_VeOUT_REL_RRDoorMotorSts_sig' */
} ExtY_REL_T;

/* Real-time Model Data Structure */
struct tag_RTM_REL_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_REL_T REL_B;

/* Block states (default storage) */
extern DW_REL_T REL_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_REL_T REL_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_REL_T REL_Y;

/* Model entry point functions */
extern void REL_initialize(void);
extern void REL_terminate(void);

/* Exported entry point function */
extern void REL_Step(void);

/* Real-time Model object */
extern RT_MODEL_REL_T *const REL_M;

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
