/*
 * File: REL.h
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.204
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Oct 30 17:06:52 2023
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
  uint8_T SL_e_CycleCount;             /* '<S3>/FLDoorRlsDriver' */
  uint8_T SL_e_DoorRlsDelayTime;       /* '<S3>/FLDoorRlsDriver' */
} DW_FLDoorRlsDriver_REL_T;

/* Block states (default storage) for system '<S3>/RLDoorRlsReq' */
typedef struct {
  uint8_T is_active_c5_DoorRlsReq;     /* '<S3>/RLDoorRlsReq' */
  uint8_T is_SwValid;                  /* '<S3>/RLDoorRlsReq' */
  uint8_T is_RlsReq;                   /* '<S3>/RLDoorRlsReq' */
  uint8_T is_Trigger;                  /* '<S3>/RLDoorRlsReq' */
  uint8_T is_DoorLock;                 /* '<S3>/RLDoorRlsReq' */
  uint8_T is_RlsReq_m;                 /* '<S3>/RLDoorRlsReq' */
  uint8_T is_Trigger_m;                /* '<S3>/RLDoorRlsReq' */
  uint8_T is_SwValid_m;                /* '<S3>/RLDoorRlsReq' */
  uint8_T is_RlsReq_b;                 /* '<S3>/RLDoorRlsReq' */
  uint8_T is_Trigger_p;                /* '<S3>/RLDoorRlsReq' */
  uint8_T is_DoorLock_h;               /* '<S3>/RLDoorRlsReq' */
  uint8_T is_DoorCentral;              /* '<S3>/RLDoorRlsReq' */
  uint8_T is_Trigger_o;                /* '<S3>/RLDoorRlsReq' */
  uint8_T is_DoorLock_f;               /* '<S3>/RLDoorRlsReq' */
  uint8_T is_RlsReq_bj;                /* '<S3>/RLDoorRlsReq' */
  uint8_T is_Trigger_k;                /* '<S3>/RLDoorRlsReq' */
  uint8_T is_RlsReq_o;                 /* '<S3>/RLDoorRlsReq' */
  uint8_T is_Trigger_mj;               /* '<S3>/RLDoorRlsReq' */
  uint8_T temporalCounter_i1;          /* '<S3>/RLDoorRlsReq' */
  uint8_T temporalCounter_i2;          /* '<S3>/RLDoorRlsReq' */
  uint8_T temporalCounter_i3;          /* '<S3>/RLDoorRlsReq' */
  uint8_T temporalCounter_i4;          /* '<S3>/RLDoorRlsReq' */
  uint8_T temporalCounter_i5;          /* '<S3>/RLDoorRlsReq' */
  uint8_T temporalCounter_i6;          /* '<S3>/RLDoorRlsReq' */
  uint8_T temporalCounter_i7;          /* '<S3>/RLDoorRlsReq' */
  uint8_T temporalCounter_i8;          /* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_DoorInBtnValid;       /* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_CentSingleDoorBtnValid;/* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_CentAllDoorBtnValid;  /* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_DoorHndPullValid;     /* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_DoorHndBtnValid;      /* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_BleDoorOpenValid;     /* '<S3>/RLDoorRlsReq' */
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
  boolean_T SL_b_BleDoorOpenValid_prev;/* '<S3>/RLDoorRlsReq' */
  boolean_T SL_b_BleDoorOpenValid_start;/* '<S3>/RLDoorRlsReq' */
} DW_RLDoorRlsReq_REL_T;

/* Block signals (default storage) */
typedef struct {
  uint8_T SO_e_DoorRlsDelayTime;       /* '<S3>/RRDoorRlsReq' */
  uint8_T SO_e_DoorRlsDelayTime_n;     /* '<S3>/RLDoorRlsReq' */
  uint8_T SO_e_DoorRlsDelayTime_h;     /* '<S3>/FRDoorRlsReq' */
  uint8_T SO_e_DoorRlsDelayTime_k;     /* '<S3>/FLDoorRlsReq' */
  Unlock_Req_E SO_m_UnlockReq;         /* '<S3>/RRDoorRlsReq' */
  Unlock_Req_E SO_m_UnlockReq_f;       /* '<S3>/RLDoorRlsReq' */
  Unlock_Req_E SO_m_UnlockReq_p;       /* '<S3>/FRDoorRlsReq' */
  Unlock_Req_E SO_m_UnlockReq_j;       /* '<S3>/FLDoorRlsReq' */
} B_REL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S3>/DoorSwSts' */
  uint16_T temporalCounter_i1_h;       /* '<S3>/BleOpenAndClsDoorRsp' */
  uint8_T is_active_c6_REL;            /* '<S3>/Unlock_Request' */
  uint8_T is_active_c5_DoorRlsReq;     /* '<S3>/FRDoorRlsReq' */
  uint8_T is_SwValid;                  /* '<S3>/FRDoorRlsReq' */
  uint8_T is_RlsReq;                   /* '<S3>/FRDoorRlsReq' */
  uint8_T is_Trigger;                  /* '<S3>/FRDoorRlsReq' */
  uint8_T is_DoorLock;                 /* '<S3>/FRDoorRlsReq' */
  uint8_T is_RlsReq_j;                 /* '<S3>/FRDoorRlsReq' */
  uint8_T is_Trigger_c;                /* '<S3>/FRDoorRlsReq' */
  uint8_T is_SwValid_d;                /* '<S3>/FRDoorRlsReq' */
  uint8_T is_RlsReq_a;                 /* '<S3>/FRDoorRlsReq' */
  uint8_T is_Trigger_m;                /* '<S3>/FRDoorRlsReq' */
  uint8_T is_DoorLock_l;               /* '<S3>/FRDoorRlsReq' */
  uint8_T is_DoorCentral;              /* '<S3>/FRDoorRlsReq' */
  uint8_T is_Trigger_p;                /* '<S3>/FRDoorRlsReq' */
  uint8_T is_DoorLock_b;               /* '<S3>/FRDoorRlsReq' */
  uint8_T is_RlsReq_a0;                /* '<S3>/FRDoorRlsReq' */
  uint8_T is_Trigger_o;                /* '<S3>/FRDoorRlsReq' */
  uint8_T is_RlsReq_b;                 /* '<S3>/FRDoorRlsReq' */
  uint8_T is_Trigger_og;               /* '<S3>/FRDoorRlsReq' */
  uint8_T temporalCounter_i1_k;        /* '<S3>/FRDoorRlsReq' */
  uint8_T temporalCounter_i2;          /* '<S3>/FRDoorRlsReq' */
  uint8_T temporalCounter_i3;          /* '<S3>/FRDoorRlsReq' */
  uint8_T temporalCounter_i4;          /* '<S3>/FRDoorRlsReq' */
  uint8_T temporalCounter_i5;          /* '<S3>/FRDoorRlsReq' */
  uint8_T temporalCounter_i6;          /* '<S3>/FRDoorRlsReq' */
  uint8_T temporalCounter_i7;          /* '<S3>/FRDoorRlsReq' */
  uint8_T temporalCounter_i8;          /* '<S3>/FRDoorRlsReq' */
  uint8_T is_active_c5_DoorRlsReq_b;   /* '<S3>/FLDoorRlsReq' */
  uint8_T is_SwValid_j;                /* '<S3>/FLDoorRlsReq' */
  uint8_T is_RlsReq_p;                 /* '<S3>/FLDoorRlsReq' */
  uint8_T is_Trigger_g;                /* '<S3>/FLDoorRlsReq' */
  uint8_T is_DoorLock_bg;              /* '<S3>/FLDoorRlsReq' */
  uint8_T is_RlsReq_jz;                /* '<S3>/FLDoorRlsReq' */
  uint8_T is_Trigger_b;                /* '<S3>/FLDoorRlsReq' */
  uint8_T is_SwValid_b;                /* '<S3>/FLDoorRlsReq' */
  uint8_T is_RlsReq_b3;                /* '<S3>/FLDoorRlsReq' */
  uint8_T is_Trigger_n;                /* '<S3>/FLDoorRlsReq' */
  uint8_T is_DoorLock_f;               /* '<S3>/FLDoorRlsReq' */
  uint8_T is_DoorCentral_l;            /* '<S3>/FLDoorRlsReq' */
  uint8_T is_Trigger_h;                /* '<S3>/FLDoorRlsReq' */
  uint8_T is_DoorLock_i;               /* '<S3>/FLDoorRlsReq' */
  uint8_T is_RlsReq_jc;                /* '<S3>/FLDoorRlsReq' */
  uint8_T is_Trigger_k;                /* '<S3>/FLDoorRlsReq' */
  uint8_T is_RlsReq_c;                 /* '<S3>/FLDoorRlsReq' */
  uint8_T is_Trigger_go;               /* '<S3>/FLDoorRlsReq' */
  uint8_T temporalCounter_i1_m;        /* '<S3>/FLDoorRlsReq' */
  uint8_T temporalCounter_i2_i;        /* '<S3>/FLDoorRlsReq' */
  uint8_T temporalCounter_i3_g;        /* '<S3>/FLDoorRlsReq' */
  uint8_T temporalCounter_i4_d;        /* '<S3>/FLDoorRlsReq' */
  uint8_T temporalCounter_i5_p;        /* '<S3>/FLDoorRlsReq' */
  uint8_T temporalCounter_i6_d;        /* '<S3>/FLDoorRlsReq' */
  uint8_T temporalCounter_i7_p;        /* '<S3>/FLDoorRlsReq' */
  uint8_T temporalCounter_i8_h;        /* '<S3>/FLDoorRlsReq' */
  uint8_T is_active_c23_REL;           /* '<S3>/DoorSwSts' */
  uint8_T is_c23_REL;                  /* '<S3>/DoorSwSts' */
  uint8_T is_active_c3_REL;            /* '<S3>/DoorRatSts' */
  uint8_T is_active_c1_REL;            /* '<S3>/DoorAutoRlsSts' */
  uint8_T SL_e_DoorAutoRlsSetBackup;   /* '<S3>/DoorAutoRlsSts' */
  uint8_T is_active_c2_REL;            /* '<S3>/BleReqDirectTransfer' */
  uint8_T is_active_c4_REL;            /* '<S3>/BleOpenAndClsDoorRsp' */
  uint8_T is_BleOpenAndClsDoorRsp;     /* '<S3>/BleOpenAndClsDoorRsp' */
  uint8_T SI_e_BleKeyDoorCtrlReq_start;/* '<S3>/BleOpenAndClsDoorRsp' */
  boolean_T SL_b_DoorInBtnValid;       /* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_CentSingleDoorBtnValid;/* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_CentAllDoorBtnValid;  /* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_DoorHndPullValid;     /* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_DoorHndBtnValid;      /* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_BleDoorOpenValid;     /* '<S3>/FRDoorRlsReq' */
  boolean_T SI_b_DoorInBtnSts_start;   /* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_DoorInBtnValid_start; /* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_DoorHndPullValid_start;/* '<S3>/FRDoorRlsReq' */
  boolean_T SI_b_DoorHndBtnSts_start;  /* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_DoorHndBtnValid_start;/* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_CentSingleDoorBtnValid_sta;/* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_CentAllDoorBtnValid_start;/* '<S3>/FRDoorRlsReq' */
  boolean_T SI_b_DoorAutoRlsReq_start; /* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_BleDoorOpenValid_start;/* '<S3>/FRDoorRlsReq' */
  boolean_T SL_b_DoorInBtnValid_e;     /* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_CentSingleDoorBtnValid_k;/* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_CentAllDoorBtnValid_a;/* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_DoorHndPullValid_b;   /* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_DoorHndBtnValid_f;    /* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_BleDoorOpenValid_k;   /* '<S3>/FLDoorRlsReq' */
  boolean_T SI_b_DoorInBtnSts_start_b; /* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_DoorInBtnValid_start_m;/* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_DoorHndPullValid_start_f;/* '<S3>/FLDoorRlsReq' */
  boolean_T SI_b_DoorHndBtnSts_start_i;/* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_DoorHndBtnValid_start_d;/* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_CentSingleDoorBtnValid_s_d;/* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_CentAllDoorBtnValid_star_l;/* '<S3>/FLDoorRlsReq' */
  boolean_T SI_b_DoorAutoRlsReq_start_h;/* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_BleDoorOpenValid_start_g;/* '<S3>/FLDoorRlsReq' */
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
  UInt8 VeINP_BLE_BDCBleKeyDoorCtrReque;
  /* '<Root>/VeINP_BLE_BDCBleKeyDoorCtrRequest_sig_VeINP_BLE_BDCBleKeyDoorCtrRequest_sig' */
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
  Boolean VbOUT_DHM_BdcDrivDoorHandButton;
  /* '<Root>/VbOUT_DHM_BdcDrivDoorHandButtonSts_flg_VbOUT_DHM_BdcDrivDoorHandButtonSts_flg' */
  Boolean VbOUT_DHM_BdcPassDoorHandButton;
  /* '<Root>/VbOUT_DHM_BdcPassDoorHandButtonSts_flg_VbOUT_DHM_BdcPassDoorHandButtonSts_flg' */
  UInt8 VeINP_BLE_BleKey1Posn_sig_VeINP;
              /* '<Root>/VeINP_BLE_BleKey1Posn_sig_VeINP_BLE_BleKey1Posn_sig' */
  UInt8 VeINP_BLE_BleKey2Posn_sig_VeINP;
              /* '<Root>/VeINP_BLE_BleKey2Posn_sig_VeINP_BLE_BleKey2Posn_sig' */
  UInt8 VeINP_BLE_BleKey3Posn_sig_VeINP;
              /* '<Root>/VeINP_BLE_BleKey3Posn_sig_VeINP_BLE_BleKey3Posn_sig' */
  UInt16 VuINP_CFG_TiLongPressHndlBtn_si;
  /* '<Root>/VuINP_CFG_TiLongPressHndlBtn_sig_VuINP_CFG_TiLongPressHndlBtn_sig' */
  UInt16 VuINP_CFG_OutsideDoorOpenDelay_;
  /* '<Root>/VuINP_CFG_OutsideDoorOpenDelay_sig_VuINP_CFG_OutsideDoorOpenDelay_sig' */
  UInt16 VuINP_CFG_InsideDoorOpenDelay_s;
  /* '<Root>/VuINP_CFG_InsideDoorOpenDelay_sig_VuINP_CFG_InsideDoorOpenDelay_sig' */
  UInt16 VuINP_CFG_Ti2xPressDoorSw_sig_V;
      /* '<Root>/VuINP_CFG_Ti2xPressDoorSw_sig_VuINP_CFG_Ti2xPressDoorSw_sig' */
  UInt16 VuINP_CFG_TiRelsActv_sig_VuINP_;
                /* '<Root>/VuINP_CFG_TiRelsActv_sig_VuINP_CFG_TiRelsActv_sig' */
  UInt8 VeINP_CFG_TiRelsBrakeActv_sig_V;
      /* '<Root>/VeINP_CFG_TiRelsBrakeActv_sig_VeINP_CFG_TiRelsBrakeActv_sig' */
  UInt16 VuINP_CFG_TiRelsResetActv_sig_V;
      /* '<Root>/VuINP_CFG_TiRelsResetActv_sig_VuINP_CFG_TiRelsResetActv_sig' */
  UInt16 VuINP_CFG_TiRelsBrakehold_sig_V;
      /* '<Root>/VuINP_CFG_TiRelsBrakehold_sig_VuINP_CFG_TiRelsBrakehold_sig' */
  UInt16 VuINP_CFG_TiRelsBrakeholdDelay_;
  /* '<Root>/VuINP_CFG_TiRelsBrakeholdDelay_sig_VuINP_CFG_TiRelsBrakeholdDelay_sig' */
  UInt16 VuINP_CFG_TiIceBrakeActv_sig_Vu;
        /* '<Root>/VuINP_CFG_TiIceBrakeActv_sig_VuINP_CFG_TiIceBrakeActv_sig' */
  UInt8 VeINP_CFG_VoltRelsActv_sig_VeIN;
            /* '<Root>/VeINP_CFG_VoltRelsActv_sig_VeINP_CFG_VoltRelsActv_sig' */
  UInt8 VeINP_CFG_VoltRelsBrakeActv_sig;
  /* '<Root>/VeINP_CFG_VoltRelsBrakeActv_sig_VeINP_CFG_VoltRelsBrakeActv_sig' */
  UInt8 VeINP_CFG_TiCrashRelsDiable_sig;
  /* '<Root>/VeINP_CFG_TiCrashRelsDiable_sig_VeINP_CFG_TiCrashRelsDiable_sig' */
  UInt8 VeINP_CFG_TiBleOpenDoorFb_sig_V;
      /* '<Root>/VeINP_CFG_TiBleOpenDoorFb_sig_VeINP_CFG_TiBleOpenDoorFb_sig' */
  UInt8 VeINP_CFG_TiBleClsDoorFb_sig_Ve;
        /* '<Root>/VeINP_CFG_TiBleClsDoorFb_sig_VeINP_CFG_TiBleClsDoorFb_sig' */
  UInt8 VeINP_HWA_Voltage_100mV_VeINP_H;
                  /* '<Root>/VeINP_HWA_Voltage_100mV_VeINP_HWA_Voltage_100mV' */
  Boolean VbINP_HWA_FLDoorOpenSW_flg_VbIN;
            /* '<Root>/VbINP_HWA_FLDoorOpenSW_flg_VbINP_HWA_FLDoorOpenSW_flg' */
  Boolean VbINP_HWA_FRDoorOpenSW_flg_VbIN;
            /* '<Root>/VbINP_HWA_FRDoorOpenSW_flg_VbINP_HWA_FRDoorOpenSW_flg' */
  Boolean VbINP_HWA_RLDoorOpenSW_flg_VbIN;
            /* '<Root>/VbINP_HWA_RLDoorOpenSW_flg_VbINP_HWA_RLDoorOpenSW_flg' */
  Boolean VbINP_HWA_RRDoorOpenSW_flg_VbIN;
            /* '<Root>/VbINP_HWA_RRDoorOpenSW_flg_VbINP_HWA_RRDoorOpenSW_flg' */
} ExtU_REL_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  Boolean VbOUT_REL_BdcDrvrDoorLockSetSts;
  /* '<Root>/VbOUT_REL_BdcDrvrDoorLockSetSts_flg_VbOUT_REL_BdcDrvrDoorLockSetSts_flg' */
  Boolean VbOUT_REL_BdcDrvrDoorLockSetS_m;
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
  Boolean VbOUT_REL_FLDoorMotorErrSts_flg;
  /* '<Root>/VbOUT_REL_FLDoorMotorErrSts_flg_VbOUT_REL_FLDoorMotorErrSts_flg' */
  Boolean VbOUT_REL_FRDoorMotorErrSts_flg;
  /* '<Root>/VbOUT_REL_FRDoorMotorErrSts_flg_VbOUT_REL_FRDoorMotorErrSts_flg' */
  Boolean VbOUT_REL_RLDoorMotorErrSts_flg;
  /* '<Root>/VbOUT_REL_RLDoorMotorErrSts_flg_VbOUT_REL_RLDoorMotorErrSts_flg' */
  Boolean VbOUT_REL_RRDoorMotorErrSts_flg;
  /* '<Root>/VbOUT_REL_RRDoorMotorErrSts_flg_VbOUT_REL_RRDoorMotorErrSts_flg' */
  UInt8 VeOUT_REL_BDCBleKeyClsDoorRsp_s;
  /* '<Root>/VeOUT_REL_BDCBleKeyClsDoorRsp_sig_VeOUT_REL_BDCBleKeyClsDoorRsp_sig' */
  UInt8 VeOUT_REL_BDCBleKeyOpenDoorRsp_;
  /* '<Root>/VeOUT_REL_BDCBleKeyOpenDoorRsp_sig_VeOUT_REL_BDCBleKeyOpenDoorRsp_sig' */
  UInt8 VeOUT_REL_BDCBleKeyDoorCtrReque;
  /* '<Root>/VeOUT_REL_BDCBleKeyDoorCtrRequest_sig_VeOUT_REL_BDCBleKeyDoorCtrRequest_sig' */
  UInt8 VeOUT_REL_FLDoorMotorCmd_sig_Ve;
        /* '<Root>/VeOUT_REL_FLDoorMotorCmd_sig_VeOUT_REL_FLDoorMotorCmd_sig' */
  UInt8 VeOUT_REL_FRDoorMotorCmd_sig_Ve;
        /* '<Root>/VeOUT_REL_FRDoorMotorCmd_sig_VeOUT_REL_FRDoorMotorCmd_sig' */
  UInt8 VeOUT_REL_RLDoorMotorCmd_sig_Ve;
        /* '<Root>/VeOUT_REL_RLDoorMotorCmd_sig_VeOUT_REL_RLDoorMotorCmd_sig' */
  UInt8 VeOUT_REL_RRDoorMotorCmd_sig_Ve;
        /* '<Root>/VeOUT_REL_RRDoorMotorCmd_sig_VeOUT_REL_RRDoorMotorCmd_sig' */
  UInt8 VeOUT_REL_FLDoorMotorPWM_pct_Ve;
        /* '<Root>/VeOUT_REL_FLDoorMotorPWM_pct_VeOUT_REL_FLDoorMotorPWM_pct' */
  UInt8 VeOUT_REL_FRDoorMotorPWM_pct_Ve;
        /* '<Root>/VeOUT_REL_FRDoorMotorPWM_pct_VeOUT_REL_FRDoorMotorPWM_pct' */
  UInt8 VeOUT_REL_RLDoorMotorPWM_pct_Ve;
        /* '<Root>/VeOUT_REL_RLDoorMotorPWM_pct_VeOUT_REL_RLDoorMotorPWM_pct' */
  UInt8 VeOUT_REL_RRDoorMotorPWM_pct_Ve;
        /* '<Root>/VeOUT_REL_RRDoorMotorPWM_pct_VeOUT_REL_RRDoorMotorPWM_pct' */
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
 * Block '<S3>/Data Type Conversion10' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion11' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion9' : Eliminate redundant data type conversion
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
 * '<S4>'   : 'REL/REL_Step_sys/REL/BleOpenAndClsDoorRsp'
 * '<S5>'   : 'REL/REL_Step_sys/REL/BleReqDirectTransfer'
 * '<S6>'   : 'REL/REL_Step_sys/REL/Compare To Constant10'
 * '<S7>'   : 'REL/REL_Step_sys/REL/Compare To Constant11'
 * '<S8>'   : 'REL/REL_Step_sys/REL/Compare To Constant12'
 * '<S9>'   : 'REL/REL_Step_sys/REL/Compare To Constant13'
 * '<S10>'  : 'REL/REL_Step_sys/REL/Compare To Constant14'
 * '<S11>'  : 'REL/REL_Step_sys/REL/Compare To Constant15'
 * '<S12>'  : 'REL/REL_Step_sys/REL/Compare To Constant16'
 * '<S13>'  : 'REL/REL_Step_sys/REL/Compare To Constant17'
 * '<S14>'  : 'REL/REL_Step_sys/REL/Compare To Constant18'
 * '<S15>'  : 'REL/REL_Step_sys/REL/Compare To Constant8'
 * '<S16>'  : 'REL/REL_Step_sys/REL/Compare To Constant9'
 * '<S17>'  : 'REL/REL_Step_sys/REL/DoorAutoRlsSts'
 * '<S18>'  : 'REL/REL_Step_sys/REL/DoorRatSts'
 * '<S19>'  : 'REL/REL_Step_sys/REL/DoorSwSts'
 * '<S20>'  : 'REL/REL_Step_sys/REL/FLDoorRlsDriver'
 * '<S21>'  : 'REL/REL_Step_sys/REL/FLDoorRlsReq'
 * '<S22>'  : 'REL/REL_Step_sys/REL/FRDoorRlsDriver'
 * '<S23>'  : 'REL/REL_Step_sys/REL/FRDoorRlsReq'
 * '<S24>'  : 'REL/REL_Step_sys/REL/OFF '
 * '<S25>'  : 'REL/REL_Step_sys/REL/RLDoorRlsDriver'
 * '<S26>'  : 'REL/REL_Step_sys/REL/RLDoorRlsReq'
 * '<S27>'  : 'REL/REL_Step_sys/REL/RRDoorRlsDriver'
 * '<S28>'  : 'REL/REL_Step_sys/REL/RRDoorRlsReq'
 * '<S29>'  : 'REL/REL_Step_sys/REL/Recycle Bin'
 * '<S30>'  : 'REL/REL_Step_sys/REL/Unlock_Request'
 */
#endif                                 /* RTW_HEADER_REL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
