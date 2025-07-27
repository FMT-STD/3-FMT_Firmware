/*
 * File: Controller_types.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 7.0
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sun Jul 27 11:47:43 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Controller_types_h_
#define RTW_HEADER_Controller_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
/**
 * You can use either of the following to alter the value of "normal" variant
 * control variables:
 *
 *  1. -DVC_VARIABLE1=VALUE1 -DVC_VARIABLE2=VALUE2, etc.
 *  2. -DUSE_VARIANT_DEFINES_HEADER="header.h" and within header.h you
 *      specify "#define VC_VARIABLE VALUE1", etc.
 *
 * Variant control variables are the independent variables of variant control
 * expressions specified in a variant block. For example, a Variant Source block
 * may contain "V==1" and V is the variant control variable of this
 * expression. A normal variant control variable is a plain MATLAB variable,
 * i.e. not a Simulink.Parameter.  The default define for a normal variant
 * control variable is the value specified in MATLAB at time of code generation.
 *
 * Alternatively, you can use Simulink.Parameter's as variant control variables to
 * explicitly specify code generation behavior.
 */
#ifdef USE_VARIANT_DEFINES_HEADER
#define VARIANT_DEFINES_HEADER_STR(h)  #h
#define VARIANT_DEFINES_HEADER(h)      VARIANT_DEFINES_HEADER_STR(h)
#include VARIANT_DEFINES_HEADER(USE_VARIANT_DEFINES_HEADER)
#endif                                 /* USE_VARIANT_DEFINES_HEADER */

/*
 * Validate the variant control variables are consistent with the model requirements
 */
#ifndef AIRFRAME
#define AIRFRAME                       1
#endif

/* MW_VALIDATE_PREPROCESSOR_VARIANT_CHOICES */
#undef MW_HAVE_ACTIVE_VARIANT_CHOICE
#undef MW_HAVE_MORE_THAN_ONE_ACTIVE_CHOICE
#if AIRFRAME == 1
#ifdef MW_HAVE_ACTIVE_VARIANT_CHOICE
#define MW_HAVE_MORE_THAN_ONE_ACTIVE_CHOICE
#else
#define MW_HAVE_ACTIVE_VARIANT_CHOICE
#endif
#endif

#if AIRFRAME == 2
#ifdef MW_HAVE_ACTIVE_VARIANT_CHOICE
#define MW_HAVE_MORE_THAN_ONE_ACTIVE_CHOICE
#else
#define MW_HAVE_ACTIVE_VARIANT_CHOICE
#endif
#endif

#if AIRFRAME == 3
#ifdef MW_HAVE_ACTIVE_VARIANT_CHOICE
#define MW_HAVE_MORE_THAN_ONE_ACTIVE_CHOICE
#else
#define MW_HAVE_ACTIVE_VARIANT_CHOICE
#endif
#endif

#if AIRFRAME == 4
#ifdef MW_HAVE_ACTIVE_VARIANT_CHOICE
#define MW_HAVE_MORE_THAN_ONE_ACTIVE_CHOICE
#else
#define MW_HAVE_ACTIVE_VARIANT_CHOICE
#endif
#endif

#if AIRFRAME == 5
#ifdef MW_HAVE_ACTIVE_VARIANT_CHOICE
#define MW_HAVE_MORE_THAN_ONE_ACTIVE_CHOICE
#else
#define MW_HAVE_ACTIVE_VARIANT_CHOICE
#endif
#endif

#if AIRFRAME == 6
#ifdef MW_HAVE_ACTIVE_VARIANT_CHOICE
#define MW_HAVE_MORE_THAN_ONE_ACTIVE_CHOICE
#else
#define MW_HAVE_ACTIVE_VARIANT_CHOICE
#endif
#endif

#if AIRFRAME == 7
#ifdef MW_HAVE_ACTIVE_VARIANT_CHOICE
#define MW_HAVE_MORE_THAN_ONE_ACTIVE_CHOICE
#else
#define MW_HAVE_ACTIVE_VARIANT_CHOICE
#endif
#endif

#if AIRFRAME == 8
#ifdef MW_HAVE_ACTIVE_VARIANT_CHOICE
#define MW_HAVE_MORE_THAN_ONE_ACTIVE_CHOICE
#else
#define MW_HAVE_ACTIVE_VARIANT_CHOICE
#endif
#endif

/* At most one variant choice can be active for block 'Controller/Controller/Control_Allocation' */
#ifdef MW_HAVE_MORE_THAN_ONE_ACTIVE_CHOICE
#error "At most one variant choice can be active for block 'Controller/Controller/Control_Allocation'"
#endif

/*At least one variant choice must be active for block 'Controller/Controller/Control_Allocation' */
#ifndef MW_HAVE_ACTIVE_VARIANT_CHOICE
#error "At least one variant choice must be active for block 'Controller/Controller/Control_Allocation'"
#endif

/* MW_END_VALIDATE_PREPROCESSOR_VARIANT_CHOICES */
#ifndef DEFINED_TYPEDEF_FOR_FMS_Out_Bus_
#define DEFINED_TYPEDEF_FOR_FMS_Out_Bus_

typedef struct {
  /* fms output timestamp */
  uint32_T timestamp;

  /* roll rate command in body frame */
  real32_T p_cmd;

  /* pitch rate command in body frame */
  real32_T q_cmd;

  /* yaw rate command in body frame */
  real32_T r_cmd;

  /* roll command in body frame */
  real32_T phi_cmd;

  /* pitch command in body frame */
  real32_T theta_cmd;

  /* yaw rate command in body frame */
  real32_T psi_rate_cmd;

  /* velocity x command in control frame */
  real32_T u_cmd;

  /* velocity y command in control frame */
  real32_T v_cmd;

  /* velocity z command in control frame */
  real32_T w_cmd;

  /* acceleration x command in control frame */
  real32_T ax_cmd;

  /* acceleration y command in control frame */
  real32_T ay_cmd;

  /* acceleration z command in control frame */
  real32_T az_cmd;

  /* actuator command */
  uint16_T actuator_cmd[16];

  /* throttle command */
  uint16_T throttle_cmd;

  /* Type mask for offboard mode:
     1: p_cmd valid
     2: q_cmd valid
     3: r_cmd valid
     4: phi_cmd valid
     5: theta_cmd valid
     6: psi_rate_cmd_valid
     7: u_cmd valid
     8: v_cmd valid
     9: w_cmd valid
     10: ax_cmd valid
     11: ay_cmd valid
     12: ax_cmd valid
     13: throttle_cmd valid */
  uint16_T cmd_mask;

  /* enum VehicleStatus

     vehicle status:
     0: None
     1: Disarm
     2: Standby
     3: Arm */
  uint8_T status;

  /* enum VehicleState

     vehicle state:
     0: None
     1: Disarm
     2: Standby
     3: Offboard
     4: Mission
     5: InvalidAutoMode
     6: Hold
     7: Acro
     8: Stabilize
     9: Altitude
     10: Position
     11: InvalidAssistMode
     12: Manual
     13: InvalidManualMode
     14: InvalidArmMode
     15: Land
     16: Return
     17: Takeoff */
  uint8_T state;

  /* enum ControlMode

     control mode:
     0: None
     1: Manual
     2: Acro
     3: Stabilize
     4: ALTCTL
     5: POSCTL */
  uint8_T ctrl_mode;

  /* enum PilotMode

     pilot mode:
     0: None
     1: Manual
     2: Acro
     3: Stabilize
     4: Altitude
     5: Position
     6: Mission
     7: Offboard */
  uint8_T mode;

  /* reset the controller */
  uint8_T reset;

  /* consumed waypoints */
  uint8_T wp_consume;

  /* current waypoint */
  uint8_T wp_current;

  /* enum of PilotMode */
  uint8_T reserved;

  /* home position [x y h yaw], unit [m m m rad] */
  real32_T home[4];
  uint32_T error;
} FMS_Out_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_INS_Out_Bus_
#define DEFINED_TYPEDEF_FOR_INS_Out_Bus_

typedef struct {
  uint32_T timestamp;
  real32_T phi;
  real32_T theta;
  real32_T psi;
  real32_T quat[4];
  real32_T p;
  real32_T q;
  real32_T r;
  real32_T ax;
  real32_T ay;
  real32_T az;
  real32_T vn;
  real32_T ve;
  real32_T vd;
  real32_T airspeed;
  real_T lat;
  real_T lon;
  real_T alt;
  real_T lat_0;
  real_T lon_0;
  real_T alt_0;
  real_T dx_dlat;
  real_T dy_dlon;
  real32_T x_R;
  real32_T y_R;
  real32_T h_R;
  real32_T h_AGL;
  uint32_T flag;
  uint32_T status;
} INS_Out_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Control_Out_Bus_
#define DEFINED_TYPEDEF_FOR_Control_Out_Bus_

typedef struct {
  uint32_T timestamp;
  uint16_T actuator_cmd[16];
} Control_Out_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ny3PY9hontv4J5WqwlFzJB_
#define DEFINED_TYPEDEF_FOR_struct_ny3PY9hontv4J5WqwlFzJB_

typedef struct {
  uint32_T period;
  int8_T model_info[21];
} struct_ny3PY9hontv4J5WqwlFzJB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_oqmoiGpNYV6eEvDoym9FPF_
#define DEFINED_TYPEDEF_FOR_struct_oqmoiGpNYV6eEvDoym9FPF_

typedef struct {
  real32_T VEL_XY_P;
  real32_T VEL_XY_I;
  real32_T VEL_XY_D;
  real32_T VEL_Z_P;
  real32_T VEL_Z_I;
  real32_T VEL_Z_D;
  real32_T VEL_XY_I_MIN;
  real32_T VEL_XY_I_MAX;
  real32_T VEL_XY_D_MIN;
  real32_T VEL_XY_D_MAX;
  real32_T VEL_Z_I_MIN;
  real32_T VEL_Z_I_MAX;
  real32_T VEL_Z_D_MIN;
  real32_T VEL_Z_D_MAX;
  real32_T ROLL_P;
  real32_T PITCH_P;
  real32_T ROLL_PITCH_CMD_LIM;
  real32_T ROLL_RATE_P;
  real32_T PITCH_RATE_P;
  real32_T YAW_RATE_P;
  real32_T ROLL_RATE_I;
  real32_T PITCH_RATE_I;
  real32_T YAW_RATE_I;
  real32_T ROLL_RATE_D;
  real32_T PITCH_RATE_D;
  real32_T YAW_RATE_D;
  real32_T ROLL_RATE_FF;
  real32_T PITCH_RATE_FF;
  real32_T RATE_I_MIN;
  real32_T RATE_I_MAX;
  real32_T RATE_D_MIN;
  real32_T RATE_D_MAX;
  real32_T P_Q_CMD_LIM;
  real32_T R_CMD_LIM;
  real32_T HOVER_THRO;
} struct_oqmoiGpNYV6eEvDoym9FPF;

#endif

#ifndef struct_tag_BRSaP7y3BhtPUJTbZuX5y
#define struct_tag_BRSaP7y3BhtPUJTbZuX5y

struct tag_BRSaP7y3BhtPUJTbZuX5y
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real32_T pCumSum;
  real32_T pCumSumRev[24];
  real32_T pCumRevIndex;
  real32_T pModValueRev;
};

#endif                                 /* struct_tag_BRSaP7y3BhtPUJTbZuX5y */

#ifndef typedef_g_dsp_internal_SlidingWindowA_T
#define typedef_g_dsp_internal_SlidingWindowA_T

typedef struct tag_BRSaP7y3BhtPUJTbZuX5y g_dsp_internal_SlidingWindowA_T;

#endif                             /* typedef_g_dsp_internal_SlidingWindowA_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_Controller_T
#define typedef_cell_wrap_Controller_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_Controller_T;

#endif                                 /* typedef_cell_wrap_Controller_T */

#ifndef struct_tag_1bqjMGkkIjGpVLizksnpTF
#define struct_tag_1bqjMGkkIjGpVLizksnpTF

struct tag_1bqjMGkkIjGpVLizksnpTF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_Controller_T inputVarSize;
  g_dsp_internal_SlidingWindowA_T *pStatistic;
  int32_T NumChannels;
  g_dsp_internal_SlidingWindowA_T _pobj0;
};

#endif                                 /* struct_tag_1bqjMGkkIjGpVLizksnpTF */

#ifndef typedef_dsp_simulink_MovingAverage_Co_T
#define typedef_dsp_simulink_MovingAverage_Co_T

typedef struct tag_1bqjMGkkIjGpVLizksnpTF dsp_simulink_MovingAverage_Co_T;

#endif                             /* typedef_dsp_simulink_MovingAverage_Co_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_Controller_T RT_MODEL_Controller_T;

#endif                                 /* RTW_HEADER_Controller_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
