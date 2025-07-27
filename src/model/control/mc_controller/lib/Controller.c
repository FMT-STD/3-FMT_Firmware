/*
 * File: Controller.c
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

#include "Controller.h"
#include "Controller_private.h"

/* Exported block signals */
real32_T att_cmd_B_rad[2];             /* '<S85>/Switch' */
real32_T att_est_B_rad[2];             /* '<S88>/Signal Copy' */
real32_T rate_cmd_B_radPs[3];          /* '<S69>/Switch' */
real32_T rate_est_B_radPs[3];          /* '<S73>/Signal Copy' */
real32_T w_cmd_C_mPs;                  /* '<S115>/Integrator1' */
real32_T w_est_C_mPs;                  /* '<S113>/Signal Copy1' */

/* Exported block parameters */
struct_oqmoiGpNYV6eEvDoym9FPF CONTROL_PARAM = {
  1.4F,
  0.2F,
  0.2F,
  0.6F,
  0.1F,
  0.0F,
  -1.0F,
  1.0F,
  -1.0F,
  1.0F,
  -0.15F,
  0.15F,
  -0.1F,
  0.1F,
  5.0F,
  5.0F,
  0.52359879F,
  0.1F,
  0.1F,
  0.15F,
  0.1F,
  0.1F,
  0.2F,
  0.003F,
  0.003F,
  0.001F,
  0.0F,
  0.0F,
  -0.1F,
  0.1F,
  -0.1F,
  0.1F,
  1.57079637F,
  3.14159274F,
  0.5F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S17>/hover_throttle'
                                        *   '<S23>/hover_throttle'
                                        *   '<S29>/hover_throttle'
                                        *   '<S35>/hover_throttle'
                                        *   '<S41>/hover_throttle'
                                        *   '<S47>/hover_throttle'
                                        *   '<S53>/hover_throttle'
                                        *   '<S59>/hover_throttle'
                                        *   '<S94>/Saturation'
                                        *   '<S68>/Saturation'
                                        *   '<S68>/Saturation1'
                                        *   '<S103>/kd'
                                        *   '<S103>/Saturation'
                                        *   '<S104>/ki'
                                        *   '<S104>/Discrete-Time Integrator'
                                        *   '<S105>/kp'
                                        *   '<S117>/kd'
                                        *   '<S117>/Saturation'
                                        *   '<S118>/Constant'
                                        *   '<S118>/ki'
                                        *   '<S118>/Discrete-Time Integrator'
                                        *   '<S119>/kp'
                                        *   '<S71>/Gain'
                                        *   '<S71>/Gain1'
                                        *   '<S87>/Constant1'
                                        *   '<S87>/Constant2'
                                        *   '<S76>/gain1'
                                        *   '<S76>/gain2'
                                        *   '<S76>/gain3'
                                        *   '<S76>/Saturation'
                                        *   '<S77>/gain1'
                                        *   '<S77>/gain2'
                                        *   '<S77>/gain3'
                                        *   '<S77>/Discrete-Time Integrator'
                                        *   '<S78>/gain1'
                                        *   '<S78>/gain2'
                                        *   '<S78>/gain3'
                                        */

struct_ny3PY9hontv4J5WqwlFzJB CONTROL_EXPORT = {
  2U,

  { 77, 67, 32, 67, 111, 110, 116, 114, 111, 108, 108, 101, 114, 32, 118, 49, 46,
    48, 46, 48, 0 }
} ;                                    /* Variable: CONTROL_EXPORT
                                        * Referenced by: '<S3>/Constant'
                                        */

/* Block states (default storage) */
DW_Controller_T Controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Controller_T Controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Controller_T Controller_Y;

/* Real-time model */
static RT_MODEL_Controller_T Controller_M_;
RT_MODEL_Controller_T *const Controller_M = &Controller_M_;
const Control_Out_Bus Controller_rtZControl_Out_Bus = { 0U,/* timestamp */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }/* actuator_cmd */
};

/* Model step function */
void Controller_step(void)
{
  g_dsp_internal_SlidingWindowA_T *obj;
  int32_T k;
  int32_T modIndex;
  real32_T csumrev[24];
  real32_T rtb_VectorConcatenate[9];
  real32_T rtb_rate_error_B_radPs[3];
  real32_T cumRevIndex;
  real32_T rtb_Add3_c;
  real32_T rtb_DiscreteTimeIntegrator1_j;
  real32_T rtb_Subtract3_i;
  real32_T rtb_a_n;
  real32_T z;

#if AIRFRAME == 6

  uint16_T rtb_MultiportSwitch_p[12];

#endif

#if (AIRFRAME == 3) || (AIRFRAME == 7) || (AIRFRAME == 8)

  uint16_T rtb_MultiportSwitch_ev[8];

#endif

#if (AIRFRAME == 4) || (AIRFRAME == 5)

  uint16_T rtb_MultiportSwitch_i[6];

#endif

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  uint16_T rtb_MultiportSwitch_b0[4];

#endif

  int32_T i;
  real32_T rtb_VectorConcatenate_0[3];
  real32_T rtb_Add_g_idx_0;
  real32_T rtb_Add_g_idx_1;
  real32_T rtb_Add_g_idx_2;
  real32_T rtb_Gain_c_idx_1;
  real32_T rtb_Gain_c_idx_2;
  real32_T rtb_Gain_idx_0;
  real32_T rtb_Gain_idx_1;
  real32_T rtb_Saturation1_is_idx_0;
  real32_T rtb_Saturation_d_idx_1;
  real32_T rtb_Saturation_d_idx_2;
  real32_T rtb_Subtract3_idx_0;
  real32_T rtb_Subtract3_idx_1;
  real32_T rtb_Sum_idx_0;
  real32_T rtb_att_error_B_rad_idx_0;
  real32_T rtb_att_error_B_rad_idx_1;
  real32_T rtb_uv_error_C_mPs_idx_0;
  real32_T rtb_uv_error_C_mPs_idx_1;
  real32_T u0;

  /* Trigonometry: '<S101>/Trigonometric Function1' incorporates:
   *  Gain: '<S100>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S101>/Trigonometric Function3'
   */
  rtb_uv_error_C_mPs_idx_1 = arm_cos_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[0] = rtb_uv_error_C_mPs_idx_1;

  /* Trigonometry: '<S101>/Trigonometric Function' incorporates:
   *  Gain: '<S100>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S101>/Trigonometric Function2'
   */
  rtb_Gain_idx_1 = arm_sin_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[1] = rtb_Gain_idx_1;

  /* SignalConversion generated from: '<S101>/Vector Concatenate1' incorporates:
   *  Constant: '<S101>/Constant3'
   */
  rtb_VectorConcatenate[2] = 0.0F;

  /* Gain: '<S101>/Gain' */
  rtb_VectorConcatenate[3] = -rtb_Gain_idx_1;

  /* Trigonometry: '<S101>/Trigonometric Function3' */
  rtb_VectorConcatenate[4] = rtb_uv_error_C_mPs_idx_1;

  /* SignalConversion generated from: '<S101>/Vector Concatenate2' incorporates:
   *  Constant: '<S101>/Constant4'
   */
  rtb_VectorConcatenate[5] = 0.0F;

  /* SignalConversion generated from: '<S101>/Vector Concatenate' incorporates:
   *  Concatenate: '<S101>/Vector Concatenate3'
   */
  rtb_VectorConcatenate[6] = Controller_ConstB.VectorConcatenate3[0];
  rtb_VectorConcatenate[7] = Controller_ConstB.VectorConcatenate3[1];
  rtb_VectorConcatenate[8] = Controller_ConstB.VectorConcatenate3[2];

  /* Product: '<S98>/Multiply' incorporates:
   *  Concatenate: '<S101>/Vector Concatenate'
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion generated from: '<S98>/Multiply'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 3] *
      Controller_U.INS_Out.ve + rtb_VectorConcatenate[i] *
      Controller_U.INS_Out.vn;
  }

  /* End of Product: '<S98>/Multiply' */

  /* Sum: '<S95>/Sum' incorporates:
   *  DiscreteIntegrator: '<S99>/Integrator1'
   */
  rtb_uv_error_C_mPs_idx_0 = Controller_DW.Integrator1_DSTATE[0] -
    rtb_VectorConcatenate_0[0];
  rtb_uv_error_C_mPs_idx_1 = Controller_DW.Integrator1_DSTATE[1] -
    rtb_VectorConcatenate_0[1];

  /* DiscreteIntegrator: '<S104>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
      Controller_ConstB.Constant_g;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
        CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
               CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
      Controller_ConstB.Constant_g;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
        CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
               CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.VEL_XY_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
             CONTROL_PARAM.VEL_XY_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.VEL_XY_I_MIN;
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.VEL_XY_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
             CONTROL_PARAM.VEL_XY_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.VEL_XY_I_MIN;
  }

  /* DiscreteIntegrator: '<S106>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_uv_error_C_mPs_idx_0;
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_uv_error_C_mPs_idx_1;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_uv_error_C_mPs_idx_0;
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_uv_error_C_mPs_idx_1;
  }

  /* Gain: '<S106>/Gain' incorporates:
   *  DiscreteIntegrator: '<S106>/Discrete-Time Integrator1'
   *  Sum: '<S106>/Sum5'
   */
  rtb_Gain_idx_0 = (rtb_uv_error_C_mPs_idx_0 -
                    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) *
    62.831852F;
  rtb_Gain_idx_1 = (rtb_uv_error_C_mPs_idx_1 -
                    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) *
    62.831852F;

  /* Switch: '<S106>/Switch' incorporates:
   *  Gain: '<S106>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_att_error_B_rad_idx_0 = 0.0F;
    rtb_att_error_B_rad_idx_1 = 0.0F;
  } else {
    rtb_att_error_B_rad_idx_0 = rtb_Gain_idx_0;
    rtb_att_error_B_rad_idx_1 = rtb_Gain_idx_1;
  }

  /* End of Switch: '<S106>/Switch' */

  /* Saturate: '<S103>/Saturation' incorporates:
   *  Constant: '<S103>/kd'
   *  Product: '<S103>/Multiply'
   */
  u0 = CONTROL_PARAM.VEL_XY_D * rtb_att_error_B_rad_idx_0;
  cumRevIndex = CONTROL_PARAM.VEL_XY_D * rtb_att_error_B_rad_idx_1;

  /* Switch: '<S97>/Switch' incorporates:
   *  Constant: '<S105>/kp'
   *  Constant: '<S107>/Constant'
   *  Constant: '<S109>/Constant'
   *  Constant: '<S110>/Constant'
   *  DiscreteIntegrator: '<S104>/Discrete-Time Integrator'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S105>/Multiply'
   *  Product: '<S108>/Multiply2'
   *  Product: '<S108>/Multiply3'
   *  RelationalOperator: '<S107>/Compare'
   *  RelationalOperator: '<S109>/Compare'
   *  RelationalOperator: '<S110>/Compare'
   *  S-Function (sfix_bitop): '<S108>/cmd_ax valid'
   *  S-Function (sfix_bitop): '<S108>/cmd_ay valid'
   *  S-Function (sfix_bitop): '<S108>/cmd_u valid'
   *  S-Function (sfix_bitop): '<S108>/cmd_v valid'
   *  Saturate: '<S103>/Saturation'
   *  Sum: '<S108>/Sum1'
   *  Sum: '<S96>/Add'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Saturate: '<S103>/Saturation' */
    if (u0 > CONTROL_PARAM.VEL_XY_D_MAX) {
      u0 = CONTROL_PARAM.VEL_XY_D_MAX;
    } else if (u0 < CONTROL_PARAM.VEL_XY_D_MIN) {
      u0 = CONTROL_PARAM.VEL_XY_D_MIN;
    }

    rtb_att_error_B_rad_idx_0 = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
      (CONTROL_PARAM.VEL_XY_P * rtb_uv_error_C_mPs_idx_0 +
       Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) + u0 : 0.0F) +
      ((Controller_U.FMS_Out.cmd_mask & 512) > 0 ? Controller_U.FMS_Out.ax_cmd :
       0.0F);

    /* Saturate: '<S103>/Saturation' incorporates:
     *  Constant: '<S105>/kp'
     *  Constant: '<S109>/Constant'
     *  Constant: '<S110>/Constant'
     *  DiscreteIntegrator: '<S104>/Discrete-Time Integrator'
     *  Product: '<S105>/Multiply'
     *  Product: '<S108>/Multiply2'
     *  Product: '<S108>/Multiply3'
     *  RelationalOperator: '<S109>/Compare'
     *  RelationalOperator: '<S110>/Compare'
     *  S-Function (sfix_bitop): '<S108>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S108>/cmd_u valid'
     *  Sum: '<S108>/Sum1'
     *  Sum: '<S96>/Add'
     */
    if (cumRevIndex > CONTROL_PARAM.VEL_XY_D_MAX) {
      cumRevIndex = CONTROL_PARAM.VEL_XY_D_MAX;
    } else if (cumRevIndex < CONTROL_PARAM.VEL_XY_D_MIN) {
      cumRevIndex = CONTROL_PARAM.VEL_XY_D_MIN;
    }

    rtb_att_error_B_rad_idx_1 = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
      (CONTROL_PARAM.VEL_XY_P * rtb_uv_error_C_mPs_idx_1 +
       Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) + cumRevIndex : 0.0F) +
      ((Controller_U.FMS_Out.cmd_mask & 1024) > 0 ? Controller_U.FMS_Out.ay_cmd :
       0.0F);
  } else {
    if (u0 > CONTROL_PARAM.VEL_XY_D_MAX) {
      /* Saturate: '<S103>/Saturation' */
      u0 = CONTROL_PARAM.VEL_XY_D_MAX;
    } else if (u0 < CONTROL_PARAM.VEL_XY_D_MIN) {
      /* Saturate: '<S103>/Saturation' */
      u0 = CONTROL_PARAM.VEL_XY_D_MIN;
    }

    rtb_att_error_B_rad_idx_0 = (CONTROL_PARAM.VEL_XY_P *
      rtb_uv_error_C_mPs_idx_0 + Controller_DW.DiscreteTimeIntegrator_DSTATE[0])
      + u0;

    /* Saturate: '<S103>/Saturation' incorporates:
     *  Constant: '<S105>/kp'
     *  DiscreteIntegrator: '<S104>/Discrete-Time Integrator'
     *  Product: '<S105>/Multiply'
     *  Sum: '<S96>/Add'
     */
    if (cumRevIndex > CONTROL_PARAM.VEL_XY_D_MAX) {
      cumRevIndex = CONTROL_PARAM.VEL_XY_D_MAX;
    } else if (cumRevIndex < CONTROL_PARAM.VEL_XY_D_MIN) {
      cumRevIndex = CONTROL_PARAM.VEL_XY_D_MIN;
    }

    rtb_att_error_B_rad_idx_1 = (CONTROL_PARAM.VEL_XY_P *
      rtb_uv_error_C_mPs_idx_1 + Controller_DW.DiscreteTimeIntegrator_DSTATE[1])
      + cumRevIndex;
  }

  /* End of Switch: '<S97>/Switch' */

  /* Trigonometry: '<S94>/Atan' incorporates:
   *  Constant: '<S94>/g'
   *  Gain: '<S94>/gain'
   *  Product: '<S94>/Divide'
   */
  u0 = atanf(1.1F * rtb_att_error_B_rad_idx_1 / 9.8055F);

  /* Saturate: '<S94>/Saturation' */
  if (u0 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    att_cmd_B_rad[0] = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else if (u0 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    att_cmd_B_rad[0] = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else {
    att_cmd_B_rad[0] = u0;
  }

  /* Trigonometry: '<S94>/Atan' incorporates:
   *  Constant: '<S94>/g'
   *  Gain: '<S94>/Gain1'
   *  Gain: '<S94>/gain'
   *  Product: '<S94>/Divide'
   */
  u0 = atanf(1.1F * -rtb_att_error_B_rad_idx_0 / 9.8055F);

  /* Saturate: '<S94>/Saturation' */
  if (u0 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    att_cmd_B_rad[1] = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else if (u0 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    att_cmd_B_rad[1] = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else {
    att_cmd_B_rad[1] = u0;
  }

  /* Switch: '<S85>/Switch' incorporates:
   *  Constant: '<S91>/Constant'
   *  Constant: '<S92>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  Logic: '<S85>/Logical Operator'
   *  RelationalOperator: '<S91>/Compare'
   *  RelationalOperator: '<S92>/Compare'
   *  Switch: '<S85>/Switch1'
   */
  if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode ==
       4)) {
    /* Switch: '<S85>/Switch' */
    att_cmd_B_rad[0] = Controller_U.FMS_Out.phi_cmd;
    att_cmd_B_rad[1] = Controller_U.FMS_Out.theta_cmd;
  } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Switch: '<S93>/Switch' incorporates:
     *  S-Function (sfix_bitop): '<S93>/cmd_phi valid'
     *  S-Function (sfix_bitop): '<S93>/cmd_theta valid'
     *  Switch: '<S85>/Switch1'
     */
    if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
      /* Switch: '<S85>/Switch' */
      att_cmd_B_rad[0] = Controller_U.FMS_Out.phi_cmd;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
      /* Switch: '<S85>/Switch' */
      att_cmd_B_rad[1] = Controller_U.FMS_Out.theta_cmd;
    }

    /* End of Switch: '<S93>/Switch' */
  }

  /* End of Switch: '<S85>/Switch' */

  /* SignalConversion: '<S88>/Signal Copy' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  att_est_B_rad[0] = Controller_U.INS_Out.phi;
  att_est_B_rad[1] = Controller_U.INS_Out.theta;

  /* Sum: '<S86>/Sum' */
  rtb_DiscreteTimeIntegrator1_j = att_cmd_B_rad[0] - att_est_B_rad[0];

  /* Product: '<S89>/Divide1' incorporates:
   *  Abs: '<S89>/Abs'
   *  Constant: '<S89>/const2'
   */
  cumRevIndex = fabsf(rtb_DiscreteTimeIntegrator1_j) / 0.002F;

  /* Product: '<S89>/Divide' incorporates:
   *  Constant: '<S87>/Constant1'
   *  Constant: '<S89>/const1'
   *  Math: '<S89>/Square'
   *  SignalConversion generated from: '<S89>/Square'
   */
  z = 9.5993F / (CONTROL_PARAM.ROLL_P * CONTROL_PARAM.ROLL_P);

  /* Signum: '<S89>/Sign' */
  if (rtb_DiscreteTimeIntegrator1_j < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else if (rtb_DiscreteTimeIntegrator1_j > 0.0F) {
    rtb_Subtract3_i = 1.0F;
  } else {
    rtb_Subtract3_i = rtb_DiscreteTimeIntegrator1_j;
  }

  /* Switch: '<S89>/Switch' incorporates:
   *  Constant: '<S87>/Constant1'
   *  Gain: '<S89>/Gain1'
   *  Gain: '<S89>/Gain2'
   *  Logic: '<S89>/Logical Operator'
   *  Product: '<S89>/Multiply'
   *  Product: '<S89>/Multiply1'
   *  Product: '<S89>/Multiply2'
   *  Product: '<S89>/Multiply3'
   *  RelationalOperator: '<S89>/Relational Operator'
   *  RelationalOperator: '<S89>/Relational Operator2'
   *  SignalConversion generated from: '<S89>/Square'
   *  Sqrt: '<S89>/Sqrt'
   *  Sum: '<S89>/Subtract'
   */
  if ((rtb_DiscreteTimeIntegrator1_j <= z) && (rtb_DiscreteTimeIntegrator1_j >=
       -z)) {
    rtb_Subtract3_i = rtb_DiscreteTimeIntegrator1_j * CONTROL_PARAM.ROLL_P;
  } else {
    rtb_Subtract3_i *= sqrtf((rtb_Subtract3_i * rtb_DiscreteTimeIntegrator1_j -
      0.5F * z) * Controller_ConstB.Gain);
  }

  /* Saturate: '<S68>/Saturation1' incorporates:
   *  Gain: '<S89>/Gain3'
   *  Product: '<S89>/Divide1'
   *  RelationalOperator: '<S90>/LowerRelop1'
   *  RelationalOperator: '<S90>/UpperRelop'
   *  Switch: '<S90>/Switch'
   *  Switch: '<S90>/Switch2'
   */
  if (rtb_Subtract3_i > cumRevIndex) {
    rtb_Subtract3_i = cumRevIndex;
  } else if (rtb_Subtract3_i < -cumRevIndex) {
    /* Switch: '<S90>/Switch' incorporates:
     *  Gain: '<S89>/Gain3'
     */
    rtb_Subtract3_i = -cumRevIndex;
  }

  if (rtb_Subtract3_i > CONTROL_PARAM.P_Q_CMD_LIM) {
    rtb_Saturation1_is_idx_0 = CONTROL_PARAM.P_Q_CMD_LIM;
  } else if (rtb_Subtract3_i < -CONTROL_PARAM.P_Q_CMD_LIM) {
    rtb_Saturation1_is_idx_0 = -CONTROL_PARAM.P_Q_CMD_LIM;
  } else {
    rtb_Saturation1_is_idx_0 = rtb_Subtract3_i;
  }

  /* Sum: '<S86>/Sum' */
  rtb_DiscreteTimeIntegrator1_j = att_cmd_B_rad[1] - att_est_B_rad[1];

  /* Product: '<S89>/Divide1' incorporates:
   *  Abs: '<S89>/Abs'
   *  Constant: '<S89>/const2'
   */
  cumRevIndex = fabsf(rtb_DiscreteTimeIntegrator1_j) / 0.002F;

  /* Product: '<S89>/Divide' incorporates:
   *  Constant: '<S87>/Constant2'
   *  Constant: '<S89>/const1'
   *  Math: '<S89>/Square'
   *  SignalConversion generated from: '<S89>/Square'
   */
  z = 9.5993F / (CONTROL_PARAM.PITCH_P * CONTROL_PARAM.PITCH_P);

  /* Signum: '<S89>/Sign' */
  if (rtb_DiscreteTimeIntegrator1_j < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else if (rtb_DiscreteTimeIntegrator1_j > 0.0F) {
    rtb_Subtract3_i = 1.0F;
  } else {
    rtb_Subtract3_i = rtb_DiscreteTimeIntegrator1_j;
  }

  /* Switch: '<S89>/Switch' incorporates:
   *  Constant: '<S87>/Constant2'
   *  Gain: '<S89>/Gain1'
   *  Gain: '<S89>/Gain2'
   *  Logic: '<S89>/Logical Operator'
   *  Product: '<S89>/Multiply'
   *  Product: '<S89>/Multiply1'
   *  Product: '<S89>/Multiply2'
   *  Product: '<S89>/Multiply3'
   *  RelationalOperator: '<S89>/Relational Operator'
   *  RelationalOperator: '<S89>/Relational Operator2'
   *  SignalConversion generated from: '<S89>/Square'
   *  Sqrt: '<S89>/Sqrt'
   *  Sum: '<S89>/Subtract'
   */
  if ((rtb_DiscreteTimeIntegrator1_j <= z) && (rtb_DiscreteTimeIntegrator1_j >=
       -z)) {
    rtb_Subtract3_i = rtb_DiscreteTimeIntegrator1_j * CONTROL_PARAM.PITCH_P;
  } else {
    rtb_Subtract3_i *= sqrtf((rtb_Subtract3_i * rtb_DiscreteTimeIntegrator1_j -
      0.5F * z) * Controller_ConstB.Gain);
  }

  /* Saturate: '<S68>/Saturation1' incorporates:
   *  Gain: '<S89>/Gain3'
   *  RelationalOperator: '<S90>/LowerRelop1'
   *  RelationalOperator: '<S90>/UpperRelop'
   *  Switch: '<S90>/Switch'
   *  Switch: '<S90>/Switch2'
   */
  if (rtb_Subtract3_i > cumRevIndex) {
    rtb_Subtract3_i = cumRevIndex;
  } else if (rtb_Subtract3_i < -cumRevIndex) {
    /* Switch: '<S90>/Switch' incorporates:
     *  Gain: '<S89>/Gain3'
     */
    rtb_Subtract3_i = -cumRevIndex;
  }

  if (rtb_Subtract3_i > CONTROL_PARAM.P_Q_CMD_LIM) {
    cumRevIndex = CONTROL_PARAM.P_Q_CMD_LIM;
  } else if (rtb_Subtract3_i < -CONTROL_PARAM.P_Q_CMD_LIM) {
    cumRevIndex = -CONTROL_PARAM.P_Q_CMD_LIM;
  } else {
    cumRevIndex = rtb_Subtract3_i;
  }

  /* Saturate: '<S68>/Saturation' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.R_CMD_LIM) {
    rtb_Add3_c = CONTROL_PARAM.R_CMD_LIM;
  } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.R_CMD_LIM) {
    rtb_Add3_c = -CONTROL_PARAM.R_CMD_LIM;
  } else {
    rtb_Add3_c = Controller_U.FMS_Out.psi_rate_cmd;
  }

  /* End of Saturate: '<S68>/Saturation' */

  /* Trigonometry: '<S80>/Sin' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_a_n = arm_sin_f32(Controller_U.INS_Out.phi);

  /* Trigonometry: '<S80>/Cos1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Subtract3_i = arm_cos_f32(Controller_U.INS_Out.theta);

  /* Trigonometry: '<S80>/Cos' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_DiscreteTimeIntegrator1_j = arm_cos_f32(Controller_U.INS_Out.phi);

  /* Switch: '<S69>/Switch' incorporates:
   *  Constant: '<S81>/Constant'
   *  Constant: '<S82>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S81>/Compare'
   *  RelationalOperator: '<S82>/Compare'
   *  Switch: '<S69>/Switch1'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 2) {
    /* Switch: '<S69>/Switch' */
    rate_cmd_B_radPs[0] = Controller_U.FMS_Out.p_cmd;
    rate_cmd_B_radPs[1] = Controller_U.FMS_Out.q_cmd;
    rate_cmd_B_radPs[2] = Controller_U.FMS_Out.r_cmd;
  } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Switch: '<S83>/Switch' incorporates:
     *  S-Function (sfix_bitop): '<S83>/cmd_p valid'
     *  S-Function (sfix_bitop): '<S83>/cmd_q valid'
     *  S-Function (sfix_bitop): '<S83>/cmd_r valid'
     *  Switch: '<S69>/Switch1'
     */
    if ((Controller_U.FMS_Out.cmd_mask & 1) > 0) {
      /* Switch: '<S69>/Switch' */
      rate_cmd_B_radPs[0] = Controller_U.FMS_Out.p_cmd;
    } else {
      /* Switch: '<S69>/Switch' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S80>/Multiply'
       *  Sum: '<S80>/Add'
       *  Trigonometry: '<S80>/Sin1'
       */
      rate_cmd_B_radPs[0] = rtb_Saturation1_is_idx_0 - arm_sin_f32
        (Controller_U.INS_Out.theta) * rtb_Add3_c;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 2) > 0) {
      /* Switch: '<S69>/Switch' */
      rate_cmd_B_radPs[1] = Controller_U.FMS_Out.q_cmd;
    } else {
      /* Switch: '<S69>/Switch' incorporates:
       *  Product: '<S80>/Multiply1'
       *  Product: '<S80>/Multiply3'
       *  Sum: '<S80>/Add1'
       */
      rate_cmd_B_radPs[1] = rtb_a_n * rtb_Subtract3_i * rtb_Add3_c +
        rtb_DiscreteTimeIntegrator1_j * cumRevIndex;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 4) > 0) {
      /* Switch: '<S69>/Switch' */
      rate_cmd_B_radPs[2] = Controller_U.FMS_Out.r_cmd;
    } else {
      /* Switch: '<S69>/Switch' incorporates:
       *  Product: '<S80>/Multiply4'
       *  Product: '<S80>/Multiply5'
       *  Sum: '<S80>/Add2'
       */
      rate_cmd_B_radPs[2] = rtb_DiscreteTimeIntegrator1_j * rtb_Subtract3_i *
        rtb_Add3_c - rtb_a_n * cumRevIndex;
    }

    /* End of Switch: '<S83>/Switch' */
  } else {
    /* Switch: '<S69>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S80>/Multiply'
     *  Product: '<S80>/Multiply1'
     *  Product: '<S80>/Multiply3'
     *  Product: '<S80>/Multiply4'
     *  Product: '<S80>/Multiply5'
     *  Sum: '<S80>/Add'
     *  Sum: '<S80>/Add1'
     *  Sum: '<S80>/Add2'
     *  Switch: '<S69>/Switch1'
     *  Trigonometry: '<S80>/Sin1'
     */
    rate_cmd_B_radPs[0] = rtb_Saturation1_is_idx_0 - arm_sin_f32
      (Controller_U.INS_Out.theta) * rtb_Add3_c;
    rate_cmd_B_radPs[1] = rtb_a_n * rtb_Subtract3_i * rtb_Add3_c +
      rtb_DiscreteTimeIntegrator1_j * cumRevIndex;
    rate_cmd_B_radPs[2] = rtb_DiscreteTimeIntegrator1_j * rtb_Subtract3_i *
      rtb_Add3_c - rtb_a_n * cumRevIndex;
  }

  /* End of Switch: '<S69>/Switch' */

  /* SignalConversion: '<S73>/Signal Copy' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rate_est_B_radPs[0] = Controller_U.INS_Out.p;
  rate_est_B_radPs[1] = Controller_U.INS_Out.q;
  rate_est_B_radPs[2] = Controller_U.INS_Out.r;

  /* MATLABSystem: '<S70>/Moving Average' */
  if (Controller_DW.obj.TunablePropsChanged) {
    Controller_DW.obj.TunablePropsChanged = false;
  }

  obj = Controller_DW.obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0F;
    for (i = 0; i < 24; i++) {
      obj->pCumSumRev[i] = 0.0F;
    }

    obj->pCumRevIndex = 1.0F;
    obj->pModValueRev = 0.0F;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0F;
    for (i = 0; i < 24; i++) {
      obj->pCumSumRev[i] = 0.0F;
    }

    obj->pCumRevIndex = 1.0F;
    obj->pModValueRev = 0.0F;
  }

  cumRevIndex = obj->pCumRevIndex;
  rtb_Saturation1_is_idx_0 = obj->pCumSum;
  for (i = 0; i < 24; i++) {
    csumrev[i] = obj->pCumSumRev[i];
  }

  rtb_DiscreteTimeIntegrator1_j = obj->pModValueRev;
  modIndex = 1;
  z = 0.0F;
  rtb_rate_error_B_radPs[0] = 0.0F;
  rtb_rate_error_B_radPs[1] = 0.0F;
  rtb_rate_error_B_radPs[2] = 0.0F;
  for (i = 0; i < 3; i++) {
    rtb_Saturation1_is_idx_0 += rate_est_B_radPs[i];
    if (rtb_DiscreteTimeIntegrator1_j == 0.0F) {
      z = csumrev[(int32_T)cumRevIndex - 1] + rtb_Saturation1_is_idx_0;
    }

    csumrev[(int32_T)cumRevIndex - 1] = rate_est_B_radPs[i];
    if (cumRevIndex != 24.0F) {
      cumRevIndex++;
    } else {
      cumRevIndex = 1.0F;
      rtb_Saturation1_is_idx_0 = 0.0F;
      for (k = 22; k >= 0; k--) {
        csumrev[k] += csumrev[k + 1];
      }
    }

    if (rtb_DiscreteTimeIntegrator1_j == 0.0F) {
      rtb_rate_error_B_radPs[modIndex - 1] = z / 25.0F;
      if (modIndex > 2147483646) {
        modIndex = MAX_int32_T;
      } else {
        modIndex++;
      }
    }

    if (rtb_DiscreteTimeIntegrator1_j > 0.0F) {
      rtb_DiscreteTimeIntegrator1_j--;
    } else {
      rtb_DiscreteTimeIntegrator1_j = 0.0F;
    }
  }

  obj->pCumSum = rtb_Saturation1_is_idx_0;
  for (i = 0; i < 24; i++) {
    obj->pCumSumRev[i] = csumrev[i];
  }

  obj->pCumRevIndex = cumRevIndex;
  obj->pModValueRev = rtb_DiscreteTimeIntegrator1_j;

  /* Sum: '<S70>/Sum' incorporates:
   *  MATLABSystem: '<S70>/Moving Average'
   */
  cumRevIndex = rate_cmd_B_radPs[0] - rtb_rate_error_B_radPs[0];
  rtb_Saturation1_is_idx_0 = rate_cmd_B_radPs[1] - rtb_rate_error_B_radPs[1];
  rtb_DiscreteTimeIntegrator1_j = rate_cmd_B_radPs[2] - rtb_rate_error_B_radPs[2];

  /* DiscreteIntegrator: '<S74>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] = cumRevIndex;
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_Saturation1_is_idx_0;
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] =
      rtb_DiscreteTimeIntegrator1_j;
  }

  /* DiscreteIntegrator: '<S77>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRe_g != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
      Controller_ConstB.Constant[0];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MAX;
    } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] <=
               CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MIN;
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
      Controller_ConstB.Constant[1];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MAX;
    } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] <=
               CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MIN;
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
      Controller_ConstB.Constant[2];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MAX;
    } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] <=
               CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] = CONTROL_PARAM.RATE_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] <=
             CONTROL_PARAM.RATE_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] = CONTROL_PARAM.RATE_I_MIN;
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] = CONTROL_PARAM.RATE_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] <=
             CONTROL_PARAM.RATE_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] = CONTROL_PARAM.RATE_I_MIN;
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] = CONTROL_PARAM.RATE_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] <=
             CONTROL_PARAM.RATE_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] = CONTROL_PARAM.RATE_I_MIN;
  }

  /* DiscreteIntegrator: '<S79>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S74>/Discrete-Time Integrator5'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_l != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_i != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];
  }

  /* Gain: '<S79>/Gain' incorporates:
   *  DiscreteIntegrator: '<S74>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S79>/Discrete-Time Integrator1'
   *  Sum: '<S79>/Sum5'
   */
  z = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] -
       Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0]) * 188.49556F;
  rtb_Gain_c_idx_1 = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] -
                      Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1]) *
    188.49556F;
  rtb_Gain_c_idx_2 = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] -
                      Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2]) *
    188.49556F;

  /* Switch: '<S79>/Switch' incorporates:
   *  Gain: '<S79>/Gain'
   *  Gain: '<S79>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   *  Saturate: '<S76>/Saturation'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_a_n = 0.0F;
    rtb_Saturation_d_idx_1 = 0.0F;
    rtb_Saturation_d_idx_2 = 0.0F;
  } else {
    rtb_a_n = z;
    rtb_Saturation_d_idx_1 = rtb_Gain_c_idx_1;
    rtb_Saturation_d_idx_2 = rtb_Gain_c_idx_2;
  }

  /* End of Switch: '<S79>/Switch' */

  /* Product: '<S76>/Multiply' incorporates:
   *  Constant: '<S76>/gain1'
   *  Saturate: '<S76>/Saturation'
   */
  u0 = CONTROL_PARAM.ROLL_RATE_D * rtb_a_n;

  /* DeadZone: '<S75>/Dead Zone' */
  if (rate_cmd_B_radPs[0] > 0.1F) {
    rtb_a_n = rate_cmd_B_radPs[0] - 0.1F;
  } else if (rate_cmd_B_radPs[0] >= -0.1F) {
    rtb_a_n = 0.0F;
  } else {
    rtb_a_n = rate_cmd_B_radPs[0] - -0.1F;
  }

  /* Saturate: '<S76>/Saturation' */
  if (u0 > CONTROL_PARAM.RATE_D_MAX) {
    u0 = CONTROL_PARAM.RATE_D_MAX;
  } else if (u0 < CONTROL_PARAM.RATE_D_MIN) {
    u0 = CONTROL_PARAM.RATE_D_MIN;
  }

  /* Sum: '<S67>/Sum' incorporates:
   *  Constant: '<S78>/gain1'
   *  DiscreteIntegrator: '<S74>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S77>/Discrete-Time Integrator'
   *  Gain: '<S71>/Gain'
   *  Gain: '<S75>/Gain'
   *  Product: '<S78>/Multiply'
   *  Sum: '<S72>/Add'
   */
  rtb_Sum_idx_0 = ((CONTROL_PARAM.ROLL_RATE_P *
                    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
                    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0]) + u0) +
    1.11111116F * rtb_a_n * CONTROL_PARAM.ROLL_RATE_FF;

  /* Product: '<S76>/Multiply' incorporates:
   *  Constant: '<S76>/gain2'
   *  Saturate: '<S76>/Saturation'
   */
  u0 = CONTROL_PARAM.PITCH_RATE_D * rtb_Saturation_d_idx_1;

  /* DeadZone: '<S75>/Dead Zone' */
  if (rate_cmd_B_radPs[1] > 0.1F) {
    rtb_a_n = rate_cmd_B_radPs[1] - 0.1F;
  } else if (rate_cmd_B_radPs[1] >= -0.1F) {
    rtb_a_n = 0.0F;
  } else {
    rtb_a_n = rate_cmd_B_radPs[1] - -0.1F;
  }

  /* Saturate: '<S76>/Saturation' */
  if (u0 > CONTROL_PARAM.RATE_D_MAX) {
    u0 = CONTROL_PARAM.RATE_D_MAX;
  } else if (u0 < CONTROL_PARAM.RATE_D_MIN) {
    u0 = CONTROL_PARAM.RATE_D_MIN;
  }

  /* Sum: '<S67>/Sum' incorporates:
   *  Constant: '<S78>/gain2'
   *  DiscreteIntegrator: '<S74>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S77>/Discrete-Time Integrator'
   *  Gain: '<S71>/Gain'
   *  Gain: '<S75>/Gain'
   *  Product: '<S78>/Multiply'
   *  Sum: '<S72>/Add'
   */
  rtb_att_error_B_rad_idx_1 = ((CONTROL_PARAM.PITCH_RATE_P *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1]) + u0) + 1.11111116F *
    rtb_a_n * CONTROL_PARAM.ROLL_RATE_FF;

  /* Product: '<S76>/Multiply' incorporates:
   *  Constant: '<S76>/gain3'
   *  Saturate: '<S76>/Saturation'
   */
  u0 = CONTROL_PARAM.YAW_RATE_D * rtb_Saturation_d_idx_2;

  /* DeadZone: '<S75>/Dead Zone' */
  if (rate_cmd_B_radPs[2] > 0.1F) {
    rtb_a_n = rate_cmd_B_radPs[2] - 0.1F;
  } else if (rate_cmd_B_radPs[2] >= -0.1F) {
    rtb_a_n = 0.0F;
  } else {
    rtb_a_n = rate_cmd_B_radPs[2] - -0.1F;
  }

  /* Saturate: '<S76>/Saturation' */
  if (u0 > CONTROL_PARAM.RATE_D_MAX) {
    u0 = CONTROL_PARAM.RATE_D_MAX;
  } else if (u0 < CONTROL_PARAM.RATE_D_MIN) {
    u0 = CONTROL_PARAM.RATE_D_MIN;
  }

  /* Sum: '<S67>/Sum' incorporates:
   *  Constant: '<S78>/gain3'
   *  DiscreteIntegrator: '<S74>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S77>/Discrete-Time Integrator'
   *  Gain: '<S71>/Gain1'
   *  Gain: '<S75>/Gain'
   *  Product: '<S78>/Multiply'
   *  Sum: '<S72>/Add'
   */
  rtb_att_error_B_rad_idx_0 = ((CONTROL_PARAM.YAW_RATE_P *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2]) + u0) + 1.11111116F *
    rtb_a_n * CONTROL_PARAM.PITCH_RATE_FF;

  /* DiscreteIntegrator: '<S115>/Integrator1' */
  w_cmd_C_mPs = Controller_DW.Integrator1_DSTATE_p;

  /* SignalConversion: '<S113>/Signal Copy1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  w_est_C_mPs = Controller_U.INS_Out.vd;

  /* Gain: '<S113>/Gain' incorporates:
   *  Sum: '<S113>/Sum1'
   */
  rtb_Saturation_d_idx_2 = -(w_cmd_C_mPs - w_est_C_mPs);

  /* DiscreteIntegrator: '<S118>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S118>/Constant'
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRe_m != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MIN;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m >=
        CONTROL_PARAM.VEL_Z_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MAX;
    } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m <=
               CONTROL_PARAM.VEL_Z_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m >= CONTROL_PARAM.VEL_Z_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m <=
             CONTROL_PARAM.VEL_Z_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MIN;
  }

  /* DiscreteIntegrator: '<S120>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_k != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h = rtb_Saturation_d_idx_2;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_Prev_iy != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h = rtb_Saturation_d_idx_2;
  }

  /* Gain: '<S120>/Gain' incorporates:
   *  DiscreteIntegrator: '<S120>/Discrete-Time Integrator1'
   *  Sum: '<S120>/Sum5'
   */
  rtb_Saturation_d_idx_1 = (rtb_Saturation_d_idx_2 -
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h) * 62.831852F;

  /* Switch: '<S120>/Switch' incorporates:
   *  Gain: '<S120>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_a_n = 0.0F;
  } else {
    rtb_a_n = rtb_Saturation_d_idx_1;
  }

  /* End of Switch: '<S120>/Switch' */

  /* Product: '<S117>/Multiply' incorporates:
   *  Constant: '<S117>/kd'
   */
  rtb_a_n *= CONTROL_PARAM.VEL_Z_D;

  /* Product: '<S112>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S112>/Cos'
   *  Trigonometry: '<S112>/Cos1'
   */
  rtb_Subtract3_i = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
    (Controller_U.INS_Out.theta);

  /* Gain: '<S112>/Gain' */
  u0 = 2.0F * rtb_Subtract3_i;

  /* Saturate: '<S117>/Saturation' */
  if (rtb_a_n > CONTROL_PARAM.VEL_Z_D_MAX) {
    rtb_a_n = CONTROL_PARAM.VEL_Z_D_MAX;
  } else if (rtb_a_n < CONTROL_PARAM.VEL_Z_D_MIN) {
    rtb_a_n = CONTROL_PARAM.VEL_Z_D_MIN;
  }

  /* End of Saturate: '<S117>/Saturation' */

  /* Saturate: '<S112>/Saturation1' */
  if (rtb_Subtract3_i < 0.5F) {
    rtb_Subtract3_i = 0.5F;
  }

  /* End of Saturate: '<S112>/Saturation1' */

  /* Saturate: '<S112>/Saturation' */
  if (u0 > 1.0F) {
    u0 = 1.0F;
  } else if (u0 < 0.0F) {
    u0 = 0.0F;
  }

  /* End of Saturate: '<S112>/Saturation' */

  /* Product: '<S112>/Multiply1' incorporates:
   *  Constant: '<S112>/Constant'
   *  Constant: '<S119>/kp'
   *  DiscreteIntegrator: '<S118>/Discrete-Time Integrator'
   *  Product: '<S112>/Divide'
   *  Product: '<S119>/Multiply'
   *  Sum: '<S114>/Add'
   */
  rtb_Subtract3_i = ((CONTROL_PARAM.VEL_Z_P * rtb_Saturation_d_idx_2 +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_m) + rtb_a_n) *
    (1.0F / rtb_Subtract3_i) * u0;

  /* Saturate: '<S111>/Saturation' */
  if (rtb_Subtract3_i > 0.35F) {
    rtb_Subtract3_i = 0.35F;
  } else if (rtb_Subtract3_i < -0.35F) {
    rtb_Subtract3_i = -0.35F;
  }

  /* End of Saturate: '<S111>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S2>/Control_Allocation' */
#if AIRFRAME == 6

  /* Outputs for Atomic SubSystem: '<S4>/Coxial_Hexacopter_x' */
  /* MultiPortSwitch: '<S16>/Multiport Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    for (i = 0; i < 12; i++) {
      rtb_MultiportSwitch_p[i] = 1000U;
    }
    break;

   case 2:
    for (i = 0; i < 12; i++) {
      rtb_MultiportSwitch_p[i] = 1150U;
    }
    break;

   case 3:
    {

#if (AIRFRAME == 1) || (AIRFRAME == 2) || (AIRFRAME == 3) || (AIRFRAME == 4) || (AIRFRAME == 5) || (AIRFRAME == 6) || (AIRFRAME == 7) || (AIRFRAME == 8)

      uint16_T rtb_throttle_cmd_f;

#endif

      /* Switch: '<S15>/Switch' incorporates:
       *  Constant: '<S18>/Constant'
       *  Constant: '<S19>/Constant'
       *  Logic: '<S15>/Logical Operator'
       *  RelationalOperator: '<S18>/Compare'
       *  RelationalOperator: '<S19>/Compare'
       *  Switch: '<S15>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S20>/Switch' incorporates:
         *  Constant: '<S17>/Constant1'
         *  DataTypeConversion: '<S17>/Data Type Conversion'
         *  Gain: '<S17>/Gain1'
         *  S-Function (sfix_bitop): '<S20>/cmd_throttle valid'
         *  Sum: '<S17>/Sum1'
         *  Switch: '<S15>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
        } else {
          /* Sum: '<S17>/Sum' incorporates:
           *  Constant: '<S17>/hover_throttle'
           *  Saturate: '<S7>/Saturation2'
           */
          u0 = rtb_Subtract3_i + CONTROL_PARAM.HOVER_THRO;

          /* Saturate: '<S17>/Saturation' */
          if (u0 > 1.0F) {
            u0 = 1.0F;
          } else if (u0 < 0.0F) {
            u0 = 0.0F;
          }

          /* Gain: '<S17>/Gain1' */
          rtb_a_n = fmodf(floorf(1000.0F * u0), 4.2949673E+9F);
          rtb_throttle_cmd_f = (uint16_T)((rtb_a_n < 0.0F ? (uint32_T)-(int32_T)
            (uint32_T)-rtb_a_n : (uint32_T)rtb_a_n) + 1000U);
        }

        /* End of Switch: '<S20>/Switch' */
      } else {
        /* Sum: '<S17>/Sum' incorporates:
         *  Constant: '<S17>/hover_throttle'
         *  Saturate: '<S7>/Saturation2'
         */
        u0 = rtb_Subtract3_i + CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S17>/Saturation' */
        if (u0 > 1.0F) {
          u0 = 1.0F;
        } else if (u0 < 0.0F) {
          u0 = 0.0F;
        }

        /* Gain: '<S17>/Gain1' */
        rtb_a_n = fmodf(floorf(1000.0F * u0), 4.2949673E+9F);

        /* Switch: '<S15>/Switch1' incorporates:
         *  Constant: '<S17>/Constant1'
         *  DataTypeConversion: '<S17>/Data Type Conversion'
         *  Gain: '<S17>/Gain1'
         *  Sum: '<S17>/Sum1'
         */
        rtb_throttle_cmd_f = (uint16_T)((rtb_a_n < 0.0F ? (uint32_T)-(int32_T)
          (uint32_T)-rtb_a_n : (uint32_T)rtb_a_n) + 1000U);
      }

      /* End of Switch: '<S15>/Switch' */

      /* Saturate: '<S7>/Saturation1' */
      if (rtb_Sum_idx_0 > 1.0F) {
        u0 = 1.0F;
      } else if (rtb_Sum_idx_0 < -1.0F) {
        u0 = -1.0F;
      } else {
        u0 = rtb_Sum_idx_0;
      }

      if (rtb_att_error_B_rad_idx_1 > 1.0F) {
        rtb_Add_g_idx_0 = 1.0F;
      } else if (rtb_att_error_B_rad_idx_1 < -1.0F) {
        rtb_Add_g_idx_0 = -1.0F;
      } else {
        rtb_Add_g_idx_0 = rtb_att_error_B_rad_idx_1;
      }

      if (rtb_att_error_B_rad_idx_0 > 1.0F) {
        rtb_Add_g_idx_1 = 1.0F;
      } else if (rtb_att_error_B_rad_idx_0 < -1.0F) {
        rtb_Add_g_idx_1 = -1.0F;
      } else {
        rtb_Add_g_idx_1 = rtb_att_error_B_rad_idx_0;
      }

      /* End of Saturate: '<S7>/Saturation1' */

      /* Product: '<S7>/Multiply' */
      for (i = 0; i < 12; i++) {

#if (AIRFRAME == 1) || (AIRFRAME == 2) || (AIRFRAME == 3) || (AIRFRAME == 4) || (AIRFRAME == 5) || (AIRFRAME == 6) || (AIRFRAME == 7) || (AIRFRAME == 8)

        uint16_T u0_0;

#endif

        /* Saturate: '<S7>/Saturation' incorporates:
         *  Constant: '<S7>/Effective_Matrix'
         *  Gain: '<S7>/Gain'
         *  MultiPortSwitch: '<S16>/Multiport Switch'
         *  Sum: '<S7>/Add'
         */
        rtb_a_n = fmodf(floorf(((Controller_ConstP.Effective_Matrix_Value[i + 12]
          * rtb_Add_g_idx_0 + Controller_ConstP.Effective_Matrix_Value[i] * u0)
          + Controller_ConstP.Effective_Matrix_Value[i + 24] * rtb_Add_g_idx_1) *
          1000.0F + (real32_T)rtb_throttle_cmd_f), 65536.0F);
        u0_0 = (uint16_T)(rtb_a_n < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                          (uint16_T)-rtb_a_n : (int32_T)(uint16_T)rtb_a_n);
        if (u0_0 > 1900) {
          rtb_MultiportSwitch_p[i] = 1900U;
        } else if (u0_0 < 1100) {
          rtb_MultiportSwitch_p[i] = 1100U;
        } else {
          rtb_MultiportSwitch_p[i] = u0_0;
        }

        /* End of Saturate: '<S7>/Saturation' */
      }

      /* End of Product: '<S7>/Multiply' */
    }
    break;

   default:
    for (i = 0; i < 12; i++) {
      rtb_MultiportSwitch_p[i] = 1000U;
    }
    break;
  }

  /* End of MultiPortSwitch: '<S16>/Multiport Switch' */

  /* Reshape: '<S16>/Reshape' incorporates:
   *  Constant: '<S16>/Constant'
   *  VariantMerge generated from: '<S4>/actuator_cmd'
   */
  for (i = 0; i < 12; i++) {
    Controller_Y.Control_Out.actuator_cmd[i] = rtb_MultiportSwitch_p[i];
  }

  Controller_Y.Control_Out.actuator_cmd[12] = 0U;
  Controller_Y.Control_Out.actuator_cmd[13] = 0U;
  Controller_Y.Control_Out.actuator_cmd[14] = 0U;
  Controller_Y.Control_Out.actuator_cmd[15] = 0U;

  /* End of Reshape: '<S16>/Reshape' */
  /* End of Outputs for SubSystem: '<S4>/Coxial_Hexacopter_x' */
#elif AIRFRAME == 3

  /* Outputs for Atomic SubSystem: '<S4>/Coxial_Quadcopter_x' */
  /* MultiPortSwitch: '<S22>/Multiport Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    for (i = 0; i < 8; i++) {
      rtb_MultiportSwitch_ev[i] = 1000U;
    }
    break;

   case 2:
    for (i = 0; i < 8; i++) {
      rtb_MultiportSwitch_ev[i] = 1150U;
    }
    break;

   case 3:
    {
      uint16_T rtb_throttle_cmd_f;

      /* Switch: '<S21>/Switch' incorporates:
       *  Constant: '<S24>/Constant'
       *  Constant: '<S25>/Constant'
       *  Logic: '<S21>/Logical Operator'
       *  RelationalOperator: '<S24>/Compare'
       *  RelationalOperator: '<S25>/Compare'
       *  Switch: '<S21>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S26>/Switch' incorporates:
         *  Constant: '<S23>/Constant1'
         *  DataTypeConversion: '<S23>/Data Type Conversion'
         *  Gain: '<S23>/Gain1'
         *  S-Function (sfix_bitop): '<S26>/cmd_throttle valid'
         *  Sum: '<S23>/Sum1'
         *  Switch: '<S21>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
        } else {
          /* Sum: '<S23>/Sum' incorporates:
           *  Constant: '<S23>/hover_throttle'
           *  Saturate: '<S8>/Saturation2'
           */
          u0 = rtb_Subtract3_i + CONTROL_PARAM.HOVER_THRO;

          /* Saturate: '<S23>/Saturation' */
          if (u0 > 1.0F) {
            u0 = 1.0F;
          } else if (u0 < 0.0F) {
            u0 = 0.0F;
          }

          /* Gain: '<S23>/Gain1' */
          rtb_a_n = fmodf(floorf(1000.0F * u0), 4.2949673E+9F);
          rtb_throttle_cmd_f = (uint16_T)((rtb_a_n < 0.0F ? (uint32_T)-(int32_T)
            (uint32_T)-rtb_a_n : (uint32_T)rtb_a_n) + 1000U);
        }

        /* End of Switch: '<S26>/Switch' */
      } else {
        /* Sum: '<S23>/Sum' incorporates:
         *  Constant: '<S23>/hover_throttle'
         *  Saturate: '<S8>/Saturation2'
         */
        u0 = rtb_Subtract3_i + CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S23>/Saturation' */
        if (u0 > 1.0F) {
          u0 = 1.0F;
        } else if (u0 < 0.0F) {
          u0 = 0.0F;
        }

        /* Gain: '<S23>/Gain1' */
        rtb_a_n = fmodf(floorf(1000.0F * u0), 4.2949673E+9F);

        /* Switch: '<S21>/Switch1' incorporates:
         *  Constant: '<S23>/Constant1'
         *  DataTypeConversion: '<S23>/Data Type Conversion'
         *  Gain: '<S23>/Gain1'
         *  Sum: '<S23>/Sum1'
         */
        rtb_throttle_cmd_f = (uint16_T)((rtb_a_n < 0.0F ? (uint32_T)-(int32_T)
          (uint32_T)-rtb_a_n : (uint32_T)rtb_a_n) + 1000U);
      }

      /* End of Switch: '<S21>/Switch' */

      /* Saturate: '<S8>/Saturation1' */
      if (rtb_Sum_idx_0 > 1.0F) {
        u0 = 1.0F;
      } else if (rtb_Sum_idx_0 < -1.0F) {
        u0 = -1.0F;
      } else {
        u0 = rtb_Sum_idx_0;
      }

      if (rtb_att_error_B_rad_idx_1 > 1.0F) {
        rtb_Add_g_idx_0 = 1.0F;
      } else if (rtb_att_error_B_rad_idx_1 < -1.0F) {
        rtb_Add_g_idx_0 = -1.0F;
      } else {
        rtb_Add_g_idx_0 = rtb_att_error_B_rad_idx_1;
      }

      if (rtb_att_error_B_rad_idx_0 > 1.0F) {
        rtb_Add_g_idx_1 = 1.0F;
      } else if (rtb_att_error_B_rad_idx_0 < -1.0F) {
        rtb_Add_g_idx_1 = -1.0F;
      } else {
        rtb_Add_g_idx_1 = rtb_att_error_B_rad_idx_0;
      }

      /* End of Saturate: '<S8>/Saturation1' */

      /* Product: '<S8>/Multiply' */
      for (i = 0; i < 8; i++) {
        uint16_T u0_0;

        /* Saturate: '<S8>/Saturation' incorporates:
         *  Constant: '<S8>/Effective_Matrix'
         *  Gain: '<S8>/Gain'
         *  MultiPortSwitch: '<S22>/Multiport Switch'
         *  Sum: '<S8>/Add'
         */
        rtb_a_n = fmodf(floorf(((Controller_ConstP.Effective_Matrix_Value_j[i +
          8] * rtb_Add_g_idx_0 + Controller_ConstP.Effective_Matrix_Value_j[i] *
          u0) + Controller_ConstP.Effective_Matrix_Value_j[i + 16] *
          rtb_Add_g_idx_1) * 1000.0F + (real32_T)rtb_throttle_cmd_f), 65536.0F);
        u0_0 = (uint16_T)(rtb_a_n < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                          (uint16_T)-rtb_a_n : (int32_T)(uint16_T)rtb_a_n);
        if (u0_0 > 1900) {
          rtb_MultiportSwitch_ev[i] = 1900U;
        } else if (u0_0 < 1100) {
          rtb_MultiportSwitch_ev[i] = 1100U;
        } else {
          rtb_MultiportSwitch_ev[i] = u0_0;
        }

        /* End of Saturate: '<S8>/Saturation' */
      }

      /* End of Product: '<S8>/Multiply' */
    }
    break;

   default:
    for (i = 0; i < 8; i++) {
      rtb_MultiportSwitch_ev[i] = 1000U;
    }
    break;
  }

  /* End of MultiPortSwitch: '<S22>/Multiport Switch' */

  /* Reshape: '<S22>/Reshape' incorporates:
   *  VariantMerge generated from: '<S4>/actuator_cmd'
   */
  for (i = 0; i < 8; i++) {
    Controller_Y.Control_Out.actuator_cmd[i] = rtb_MultiportSwitch_ev[i];
    Controller_Y.Control_Out.actuator_cmd[i + 8] = 0U;
  }

  /* End of Reshape: '<S22>/Reshape' */
  /* End of Outputs for SubSystem: '<S4>/Coxial_Quadcopter_x' */
#elif AIRFRAME == 5

  /* Outputs for Atomic SubSystem: '<S4>/Hexacopter_+' */
  /* MultiPortSwitch: '<S28>/Multiport Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    for (i = 0; i < 6; i++) {
      rtb_MultiportSwitch_i[i] = 1000U;
    }
    break;

   case 2:
    for (i = 0; i < 6; i++) {
      rtb_MultiportSwitch_i[i] = 1150U;
    }
    break;

   case 3:
    {
      uint16_T rtb_throttle_cmd_f;

      /* Switch: '<S27>/Switch' incorporates:
       *  Constant: '<S30>/Constant'
       *  Constant: '<S31>/Constant'
       *  Logic: '<S27>/Logical Operator'
       *  RelationalOperator: '<S30>/Compare'
       *  RelationalOperator: '<S31>/Compare'
       *  Switch: '<S27>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S32>/Switch' incorporates:
         *  Constant: '<S29>/Constant1'
         *  DataTypeConversion: '<S29>/Data Type Conversion'
         *  Gain: '<S29>/Gain1'
         *  S-Function (sfix_bitop): '<S32>/cmd_throttle valid'
         *  Sum: '<S29>/Sum1'
         *  Switch: '<S27>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
        } else {
          /* Sum: '<S29>/Sum' incorporates:
           *  Constant: '<S29>/hover_throttle'
           *  Saturate: '<S9>/Saturation2'
           */
          u0 = rtb_Subtract3_i + CONTROL_PARAM.HOVER_THRO;

          /* Saturate: '<S29>/Saturation' */
          if (u0 > 1.0F) {
            u0 = 1.0F;
          } else if (u0 < 0.0F) {
            u0 = 0.0F;
          }

          /* Gain: '<S29>/Gain1' */
          rtb_a_n = fmodf(floorf(1000.0F * u0), 4.2949673E+9F);
          rtb_throttle_cmd_f = (uint16_T)((rtb_a_n < 0.0F ? (uint32_T)-(int32_T)
            (uint32_T)-rtb_a_n : (uint32_T)rtb_a_n) + 1000U);
        }

        /* End of Switch: '<S32>/Switch' */
      } else {
        /* Sum: '<S29>/Sum' incorporates:
         *  Constant: '<S29>/hover_throttle'
         *  Saturate: '<S9>/Saturation2'
         */
        u0 = rtb_Subtract3_i + CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S29>/Saturation' */
        if (u0 > 1.0F) {
          u0 = 1.0F;
        } else if (u0 < 0.0F) {
          u0 = 0.0F;
        }

        /* Gain: '<S29>/Gain1' */
        rtb_a_n = fmodf(floorf(1000.0F * u0), 4.2949673E+9F);

        /* Switch: '<S27>/Switch1' incorporates:
         *  Constant: '<S29>/Constant1'
         *  DataTypeConversion: '<S29>/Data Type Conversion'
         *  Gain: '<S29>/Gain1'
         *  Sum: '<S29>/Sum1'
         */
        rtb_throttle_cmd_f = (uint16_T)((rtb_a_n < 0.0F ? (uint32_T)-(int32_T)
          (uint32_T)-rtb_a_n : (uint32_T)rtb_a_n) + 1000U);
      }

      /* End of Switch: '<S27>/Switch' */

      /* Saturate: '<S9>/Saturation1' */
      if (rtb_Sum_idx_0 > 1.0F) {
        u0 = 1.0F;
      } else if (rtb_Sum_idx_0 < -1.0F) {
        u0 = -1.0F;
      } else {
        u0 = rtb_Sum_idx_0;
      }

      if (rtb_att_error_B_rad_idx_1 > 1.0F) {
        rtb_Add_g_idx_0 = 1.0F;
      } else if (rtb_att_error_B_rad_idx_1 < -1.0F) {
        rtb_Add_g_idx_0 = -1.0F;
      } else {
        rtb_Add_g_idx_0 = rtb_att_error_B_rad_idx_1;
      }

      if (rtb_att_error_B_rad_idx_0 > 1.0F) {
        rtb_Add_g_idx_1 = 1.0F;
      } else if (rtb_att_error_B_rad_idx_0 < -1.0F) {
        rtb_Add_g_idx_1 = -1.0F;
      } else {
        rtb_Add_g_idx_1 = rtb_att_error_B_rad_idx_0;
      }

      /* End of Saturate: '<S9>/Saturation1' */

      /* Product: '<S9>/Multiply' */
      for (i = 0; i < 6; i++) {
        uint16_T u0_0;

        /* Saturate: '<S9>/Saturation' incorporates:
         *  Constant: '<S9>/Effective_Matrix'
         *  Gain: '<S9>/Gain'
         *  MultiPortSwitch: '<S28>/Multiport Switch'
         *  Sum: '<S9>/Add'
         */
        rtb_a_n = fmodf(floorf(((Controller_ConstP.Effective_Matrix_Value_je[i +
          6] * rtb_Add_g_idx_0 + Controller_ConstP.Effective_Matrix_Value_je[i] *
          u0) + Controller_ConstP.Effective_Matrix_Value_je[i + 12] *
          rtb_Add_g_idx_1) * 1000.0F + (real32_T)rtb_throttle_cmd_f), 65536.0F);
        u0_0 = (uint16_T)(rtb_a_n < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                          (uint16_T)-rtb_a_n : (int32_T)(uint16_T)rtb_a_n);
        if (u0_0 > 1900) {
          rtb_MultiportSwitch_i[i] = 1900U;
        } else if (u0_0 < 1100) {
          rtb_MultiportSwitch_i[i] = 1100U;
        } else {
          rtb_MultiportSwitch_i[i] = u0_0;
        }

        /* End of Saturate: '<S9>/Saturation' */
      }

      /* End of Product: '<S9>/Multiply' */
    }
    break;

   default:
    for (i = 0; i < 6; i++) {
      rtb_MultiportSwitch_i[i] = 1000U;
    }
    break;
  }

  /* End of MultiPortSwitch: '<S28>/Multiport Switch' */

  /* Reshape: '<S28>/Reshape' incorporates:
   *  VariantMerge generated from: '<S4>/actuator_cmd'
   */
  for (i = 0; i < 6; i++) {
    Controller_Y.Control_Out.actuator_cmd[i] = rtb_MultiportSwitch_i[i];
  }

  for (i = 0; i < 10; i++) {
    Controller_Y.Control_Out.actuator_cmd[i + 6] = 0U;
  }

  /* End of Reshape: '<S28>/Reshape' */
  /* End of Outputs for SubSystem: '<S4>/Hexacopter_+' */
#elif AIRFRAME == 4

  /* Outputs for Atomic SubSystem: '<S4>/Hexacopter_x' */
  /* MultiPortSwitch: '<S34>/Multiport Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    for (i = 0; i < 6; i++) {
      rtb_MultiportSwitch_i[i] = 1000U;
    }
    break;

   case 2:
    for (i = 0; i < 6; i++) {
      rtb_MultiportSwitch_i[i] = 1150U;
    }
    break;

   case 3:
    {
      uint16_T rtb_throttle_cmd_f;

      /* Switch: '<S33>/Switch' incorporates:
       *  Constant: '<S36>/Constant'
       *  Constant: '<S37>/Constant'
       *  Logic: '<S33>/Logical Operator'
       *  RelationalOperator: '<S36>/Compare'
       *  RelationalOperator: '<S37>/Compare'
       *  Switch: '<S33>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S38>/Switch' incorporates:
         *  Constant: '<S35>/Constant1'
         *  DataTypeConversion: '<S35>/Data Type Conversion'
         *  Gain: '<S35>/Gain1'
         *  S-Function (sfix_bitop): '<S38>/cmd_throttle valid'
         *  Sum: '<S35>/Sum1'
         *  Switch: '<S33>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
        } else {
          /* Sum: '<S35>/Sum' incorporates:
           *  Constant: '<S35>/hover_throttle'
           *  Saturate: '<S10>/Saturation2'
           */
          u0 = rtb_Subtract3_i + CONTROL_PARAM.HOVER_THRO;

          /* Saturate: '<S35>/Saturation' */
          if (u0 > 1.0F) {
            u0 = 1.0F;
          } else if (u0 < 0.0F) {
            u0 = 0.0F;
          }

          /* Gain: '<S35>/Gain1' */
          rtb_a_n = fmodf(floorf(1000.0F * u0), 4.2949673E+9F);
          rtb_throttle_cmd_f = (uint16_T)((rtb_a_n < 0.0F ? (uint32_T)-(int32_T)
            (uint32_T)-rtb_a_n : (uint32_T)rtb_a_n) + 1000U);
        }

        /* End of Switch: '<S38>/Switch' */
      } else {
        /* Sum: '<S35>/Sum' incorporates:
         *  Constant: '<S35>/hover_throttle'
         *  Saturate: '<S10>/Saturation2'
         */
        u0 = rtb_Subtract3_i + CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S35>/Saturation' */
        if (u0 > 1.0F) {
          u0 = 1.0F;
        } else if (u0 < 0.0F) {
          u0 = 0.0F;
        }

        /* Gain: '<S35>/Gain1' */
        rtb_a_n = fmodf(floorf(1000.0F * u0), 4.2949673E+9F);

        /* Switch: '<S33>/Switch1' incorporates:
         *  Constant: '<S35>/Constant1'
         *  DataTypeConversion: '<S35>/Data Type Conversion'
         *  Gain: '<S35>/Gain1'
         *  Sum: '<S35>/Sum1'
         */
        rtb_throttle_cmd_f = (uint16_T)((rtb_a_n < 0.0F ? (uint32_T)-(int32_T)
          (uint32_T)-rtb_a_n : (uint32_T)rtb_a_n) + 1000U);
      }

      /* End of Switch: '<S33>/Switch' */

      /* Saturate: '<S10>/Saturation1' */
      if (rtb_Sum_idx_0 > 1.0F) {
        u0 = 1.0F;
      } else if (rtb_Sum_idx_0 < -1.0F) {
        u0 = -1.0F;
      } else {
        u0 = rtb_Sum_idx_0;
      }

      if (rtb_att_error_B_rad_idx_1 > 1.0F) {
        rtb_Add_g_idx_0 = 1.0F;
      } else if (rtb_att_error_B_rad_idx_1 < -1.0F) {
        rtb_Add_g_idx_0 = -1.0F;
      } else {
        rtb_Add_g_idx_0 = rtb_att_error_B_rad_idx_1;
      }

      if (rtb_att_error_B_rad_idx_0 > 1.0F) {
        rtb_Add_g_idx_1 = 1.0F;
      } else if (rtb_att_error_B_rad_idx_0 < -1.0F) {
        rtb_Add_g_idx_1 = -1.0F;
      } else {
        rtb_Add_g_idx_1 = rtb_att_error_B_rad_idx_0;
      }

      /* End of Saturate: '<S10>/Saturation1' */

      /* Product: '<S10>/Multiply' */
      for (i = 0; i < 6; i++) {
        uint16_T u0_0;

        /* Saturate: '<S10>/Saturation' incorporates:
         *  Constant: '<S10>/Effective_Matrix'
         *  Gain: '<S10>/Gain'
         *  MultiPortSwitch: '<S34>/Multiport Switch'
         *  Sum: '<S10>/Add'
         */
        rtb_a_n = fmodf(floorf(((Controller_ConstP.Effective_Matrix_Value_f[i +
          6] * rtb_Add_g_idx_0 + Controller_ConstP.Effective_Matrix_Value_f[i] *
          u0) + Controller_ConstP.Effective_Matrix_Value_f[i + 12] *
          rtb_Add_g_idx_1) * 1000.0F + (real32_T)rtb_throttle_cmd_f), 65536.0F);
        u0_0 = (uint16_T)(rtb_a_n < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                          (uint16_T)-rtb_a_n : (int32_T)(uint16_T)rtb_a_n);
        if (u0_0 > 1900) {
          rtb_MultiportSwitch_i[i] = 1900U;
        } else if (u0_0 < 1100) {
          rtb_MultiportSwitch_i[i] = 1100U;
        } else {
          rtb_MultiportSwitch_i[i] = u0_0;
        }

        /* End of Saturate: '<S10>/Saturation' */
      }

      /* End of Product: '<S10>/Multiply' */
    }
    break;

   default:
    for (i = 0; i < 6; i++) {
      rtb_MultiportSwitch_i[i] = 1000U;
    }
    break;
  }

  /* End of MultiPortSwitch: '<S34>/Multiport Switch' */

  /* Reshape: '<S34>/Reshape' incorporates:
   *  VariantMerge generated from: '<S4>/actuator_cmd'
   */
  for (i = 0; i < 6; i++) {
    Controller_Y.Control_Out.actuator_cmd[i] = rtb_MultiportSwitch_i[i];
  }

  for (i = 0; i < 10; i++) {
    Controller_Y.Control_Out.actuator_cmd[i + 6] = 0U;
  }

  /* End of Reshape: '<S34>/Reshape' */
  /* End of Outputs for SubSystem: '<S4>/Hexacopter_x' */
#elif AIRFRAME == 8

  /* Outputs for Atomic SubSystem: '<S4>/Octocopter_+' */
  /* MultiPortSwitch: '<S40>/Multiport Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    for (i = 0; i < 8; i++) {
      rtb_MultiportSwitch_ev[i] = 1000U;
    }
    break;

   case 2:
    for (i = 0; i < 8; i++) {
      rtb_MultiportSwitch_ev[i] = 1150U;
    }
    break;

   case 3:
    {
      uint16_T rtb_throttle_cmd_f;

      /* Switch: '<S39>/Switch' incorporates:
       *  Constant: '<S42>/Constant'
       *  Constant: '<S43>/Constant'
       *  Logic: '<S39>/Logical Operator'
       *  RelationalOperator: '<S42>/Compare'
       *  RelationalOperator: '<S43>/Compare'
       *  Switch: '<S39>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S44>/Switch' incorporates:
         *  Constant: '<S41>/Constant1'
         *  DataTypeConversion: '<S41>/Data Type Conversion'
         *  Gain: '<S41>/Gain1'
         *  S-Function (sfix_bitop): '<S44>/cmd_throttle valid'
         *  Sum: '<S41>/Sum1'
         *  Switch: '<S39>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
        } else {
          /* Sum: '<S41>/Sum' incorporates:
           *  Constant: '<S41>/hover_throttle'
           *  Saturate: '<S11>/Saturation2'
           */
          u0 = rtb_Subtract3_i + CONTROL_PARAM.HOVER_THRO;

          /* Saturate: '<S41>/Saturation' */
          if (u0 > 1.0F) {
            u0 = 1.0F;
          } else if (u0 < 0.0F) {
            u0 = 0.0F;
          }

          /* Gain: '<S41>/Gain1' */
          rtb_a_n = fmodf(floorf(1000.0F * u0), 4.2949673E+9F);
          rtb_throttle_cmd_f = (uint16_T)((rtb_a_n < 0.0F ? (uint32_T)-(int32_T)
            (uint32_T)-rtb_a_n : (uint32_T)rtb_a_n) + 1000U);
        }

        /* End of Switch: '<S44>/Switch' */
      } else {
        /* Sum: '<S41>/Sum' incorporates:
         *  Constant: '<S41>/hover_throttle'
         *  Saturate: '<S11>/Saturation2'
         */
        u0 = rtb_Subtract3_i + CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S41>/Saturation' */
        if (u0 > 1.0F) {
          u0 = 1.0F;
        } else if (u0 < 0.0F) {
          u0 = 0.0F;
        }

        /* Gain: '<S41>/Gain1' */
        rtb_a_n = fmodf(floorf(1000.0F * u0), 4.2949673E+9F);

        /* Switch: '<S39>/Switch1' incorporates:
         *  Constant: '<S41>/Constant1'
         *  DataTypeConversion: '<S41>/Data Type Conversion'
         *  Gain: '<S41>/Gain1'
         *  Sum: '<S41>/Sum1'
         */
        rtb_throttle_cmd_f = (uint16_T)((rtb_a_n < 0.0F ? (uint32_T)-(int32_T)
          (uint32_T)-rtb_a_n : (uint32_T)rtb_a_n) + 1000U);
      }

      /* End of Switch: '<S39>/Switch' */

      /* Saturate: '<S11>/Saturation1' */
      if (rtb_Sum_idx_0 > 1.0F) {
        u0 = 1.0F;
      } else if (rtb_Sum_idx_0 < -1.0F) {
        u0 = -1.0F;
      } else {
        u0 = rtb_Sum_idx_0;
      }

      if (rtb_att_error_B_rad_idx_1 > 1.0F) {
        rtb_Add_g_idx_0 = 1.0F;
      } else if (rtb_att_error_B_rad_idx_1 < -1.0F) {
        rtb_Add_g_idx_0 = -1.0F;
      } else {
        rtb_Add_g_idx_0 = rtb_att_error_B_rad_idx_1;
      }

      if (rtb_att_error_B_rad_idx_0 > 1.0F) {
        rtb_Add_g_idx_1 = 1.0F;
      } else if (rtb_att_error_B_rad_idx_0 < -1.0F) {
        rtb_Add_g_idx_1 = -1.0F;
      } else {
        rtb_Add_g_idx_1 = rtb_att_error_B_rad_idx_0;
      }

      /* End of Saturate: '<S11>/Saturation1' */

      /* Product: '<S11>/Multiply' */
      for (i = 0; i < 8; i++) {
        uint16_T u0_0;

        /* Saturate: '<S11>/Saturation' incorporates:
         *  Constant: '<S11>/Effective_Matrix'
         *  Gain: '<S11>/Gain'
         *  MultiPortSwitch: '<S40>/Multiport Switch'
         *  Sum: '<S11>/Add'
         */
        rtb_a_n = fmodf(floorf(((Controller_ConstP.Effective_Matrix_Value_m[i +
          8] * rtb_Add_g_idx_0 + Controller_ConstP.Effective_Matrix_Value_m[i] *
          u0) + Controller_ConstP.Effective_Matrix_Value_m[i + 16] *
          rtb_Add_g_idx_1) * 1000.0F + (real32_T)rtb_throttle_cmd_f), 65536.0F);
        u0_0 = (uint16_T)(rtb_a_n < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                          (uint16_T)-rtb_a_n : (int32_T)(uint16_T)rtb_a_n);
        if (u0_0 > 1900) {
          rtb_MultiportSwitch_ev[i] = 1900U;
        } else if (u0_0 < 1100) {
          rtb_MultiportSwitch_ev[i] = 1100U;
        } else {
          rtb_MultiportSwitch_ev[i] = u0_0;
        }

        /* End of Saturate: '<S11>/Saturation' */
      }

      /* End of Product: '<S11>/Multiply' */
    }
    break;

   default:
    for (i = 0; i < 8; i++) {
      rtb_MultiportSwitch_ev[i] = 1000U;
    }
    break;
  }

  /* End of MultiPortSwitch: '<S40>/Multiport Switch' */

  /* Reshape: '<S40>/Reshape' incorporates:
   *  VariantMerge generated from: '<S4>/actuator_cmd'
   */
  for (i = 0; i < 8; i++) {
    Controller_Y.Control_Out.actuator_cmd[i] = rtb_MultiportSwitch_ev[i];
    Controller_Y.Control_Out.actuator_cmd[i + 8] = 0U;
  }

  /* End of Reshape: '<S40>/Reshape' */
  /* End of Outputs for SubSystem: '<S4>/Octocopter_+' */
#elif AIRFRAME == 7

  /* Outputs for Atomic SubSystem: '<S4>/Octocopter_x' */
  /* MultiPortSwitch: '<S46>/Multiport Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    for (i = 0; i < 8; i++) {
      rtb_MultiportSwitch_ev[i] = 1000U;
    }
    break;

   case 2:
    for (i = 0; i < 8; i++) {
      rtb_MultiportSwitch_ev[i] = 1150U;
    }
    break;

   case 3:
    {
      uint16_T rtb_throttle_cmd_f;

      /* Switch: '<S45>/Switch' incorporates:
       *  Constant: '<S48>/Constant'
       *  Constant: '<S49>/Constant'
       *  Logic: '<S45>/Logical Operator'
       *  RelationalOperator: '<S48>/Compare'
       *  RelationalOperator: '<S49>/Compare'
       *  Switch: '<S45>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S50>/Switch' incorporates:
         *  Constant: '<S47>/Constant1'
         *  DataTypeConversion: '<S47>/Data Type Conversion'
         *  Gain: '<S47>/Gain1'
         *  S-Function (sfix_bitop): '<S50>/cmd_throttle valid'
         *  Sum: '<S47>/Sum1'
         *  Switch: '<S45>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
        } else {
          /* Sum: '<S47>/Sum' incorporates:
           *  Constant: '<S47>/hover_throttle'
           *  Saturate: '<S12>/Saturation2'
           */
          u0 = rtb_Subtract3_i + CONTROL_PARAM.HOVER_THRO;

          /* Saturate: '<S47>/Saturation' */
          if (u0 > 1.0F) {
            u0 = 1.0F;
          } else if (u0 < 0.0F) {
            u0 = 0.0F;
          }

          /* Gain: '<S47>/Gain1' */
          rtb_a_n = fmodf(floorf(1000.0F * u0), 4.2949673E+9F);
          rtb_throttle_cmd_f = (uint16_T)((rtb_a_n < 0.0F ? (uint32_T)-(int32_T)
            (uint32_T)-rtb_a_n : (uint32_T)rtb_a_n) + 1000U);
        }

        /* End of Switch: '<S50>/Switch' */
      } else {
        /* Sum: '<S47>/Sum' incorporates:
         *  Constant: '<S47>/hover_throttle'
         *  Saturate: '<S12>/Saturation2'
         */
        u0 = rtb_Subtract3_i + CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S47>/Saturation' */
        if (u0 > 1.0F) {
          u0 = 1.0F;
        } else if (u0 < 0.0F) {
          u0 = 0.0F;
        }

        /* Gain: '<S47>/Gain1' */
        rtb_a_n = fmodf(floorf(1000.0F * u0), 4.2949673E+9F);

        /* Switch: '<S45>/Switch1' incorporates:
         *  Constant: '<S47>/Constant1'
         *  DataTypeConversion: '<S47>/Data Type Conversion'
         *  Gain: '<S47>/Gain1'
         *  Sum: '<S47>/Sum1'
         */
        rtb_throttle_cmd_f = (uint16_T)((rtb_a_n < 0.0F ? (uint32_T)-(int32_T)
          (uint32_T)-rtb_a_n : (uint32_T)rtb_a_n) + 1000U);
      }

      /* End of Switch: '<S45>/Switch' */

      /* Saturate: '<S12>/Saturation1' */
      if (rtb_Sum_idx_0 > 1.0F) {
        u0 = 1.0F;
      } else if (rtb_Sum_idx_0 < -1.0F) {
        u0 = -1.0F;
      } else {
        u0 = rtb_Sum_idx_0;
      }

      if (rtb_att_error_B_rad_idx_1 > 1.0F) {
        rtb_Add_g_idx_0 = 1.0F;
      } else if (rtb_att_error_B_rad_idx_1 < -1.0F) {
        rtb_Add_g_idx_0 = -1.0F;
      } else {
        rtb_Add_g_idx_0 = rtb_att_error_B_rad_idx_1;
      }

      if (rtb_att_error_B_rad_idx_0 > 1.0F) {
        rtb_Add_g_idx_1 = 1.0F;
      } else if (rtb_att_error_B_rad_idx_0 < -1.0F) {
        rtb_Add_g_idx_1 = -1.0F;
      } else {
        rtb_Add_g_idx_1 = rtb_att_error_B_rad_idx_0;
      }

      /* End of Saturate: '<S12>/Saturation1' */

      /* Product: '<S12>/Multiply' */
      for (i = 0; i < 8; i++) {
        uint16_T u0_0;

        /* Saturate: '<S12>/Saturation' incorporates:
         *  Constant: '<S12>/Effective_Matrix'
         *  Gain: '<S12>/Gain'
         *  MultiPortSwitch: '<S46>/Multiport Switch'
         *  Sum: '<S12>/Add'
         */
        rtb_a_n = fmodf(floorf(((Controller_ConstP.Effective_Matrix_Value_k[i +
          8] * rtb_Add_g_idx_0 + Controller_ConstP.Effective_Matrix_Value_k[i] *
          u0) + Controller_ConstP.Effective_Matrix_Value_k[i + 16] *
          rtb_Add_g_idx_1) * 1000.0F + (real32_T)rtb_throttle_cmd_f), 65536.0F);
        u0_0 = (uint16_T)(rtb_a_n < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                          (uint16_T)-rtb_a_n : (int32_T)(uint16_T)rtb_a_n);
        if (u0_0 > 1900) {
          rtb_MultiportSwitch_ev[i] = 1900U;
        } else if (u0_0 < 1100) {
          rtb_MultiportSwitch_ev[i] = 1100U;
        } else {
          rtb_MultiportSwitch_ev[i] = u0_0;
        }

        /* End of Saturate: '<S12>/Saturation' */
      }

      /* End of Product: '<S12>/Multiply' */
    }
    break;

   default:
    for (i = 0; i < 8; i++) {
      rtb_MultiportSwitch_ev[i] = 1000U;
    }
    break;
  }

  /* End of MultiPortSwitch: '<S46>/Multiport Switch' */

  /* Reshape: '<S46>/Reshape' incorporates:
   *  VariantMerge generated from: '<S4>/actuator_cmd'
   */
  for (i = 0; i < 8; i++) {
    Controller_Y.Control_Out.actuator_cmd[i] = rtb_MultiportSwitch_ev[i];
    Controller_Y.Control_Out.actuator_cmd[i + 8] = 0U;
  }

  /* End of Reshape: '<S46>/Reshape' */
  /* End of Outputs for SubSystem: '<S4>/Octocopter_x' */
#elif AIRFRAME == 2

  /* Outputs for Atomic SubSystem: '<S4>/Quadcopter_+' */
  /* MultiPortSwitch: '<S52>/Multiport Switch' incorporates:
   *  Constant: '<S52>/Disarm'
   *  Constant: '<S52>/Standby'
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    rtb_MultiportSwitch_b0[0] = 1000U;
    rtb_MultiportSwitch_b0[1] = 1000U;
    rtb_MultiportSwitch_b0[2] = 1000U;
    rtb_MultiportSwitch_b0[3] = 1000U;
    break;

   case 2:
    rtb_MultiportSwitch_b0[0] = 1150U;
    rtb_MultiportSwitch_b0[1] = 1150U;
    rtb_MultiportSwitch_b0[2] = 1150U;
    rtb_MultiportSwitch_b0[3] = 1150U;
    break;

   case 3:
    {
      uint16_T rtb_throttle_cmd_f;

      /* Switch: '<S51>/Switch' incorporates:
       *  Constant: '<S54>/Constant'
       *  Constant: '<S55>/Constant'
       *  Logic: '<S51>/Logical Operator'
       *  RelationalOperator: '<S54>/Compare'
       *  RelationalOperator: '<S55>/Compare'
       *  Switch: '<S51>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S56>/Switch' incorporates:
         *  Constant: '<S53>/Constant1'
         *  DataTypeConversion: '<S53>/Data Type Conversion'
         *  Gain: '<S53>/Gain1'
         *  S-Function (sfix_bitop): '<S56>/cmd_throttle valid'
         *  Sum: '<S53>/Sum1'
         *  Switch: '<S51>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
        } else {
          /* Sum: '<S53>/Sum' incorporates:
           *  Constant: '<S53>/hover_throttle'
           *  Saturate: '<S13>/Saturation2'
           */
          u0 = rtb_Subtract3_i + CONTROL_PARAM.HOVER_THRO;

          /* Saturate: '<S53>/Saturation' */
          if (u0 > 1.0F) {
            u0 = 1.0F;
          } else if (u0 < 0.0F) {
            u0 = 0.0F;
          }

          /* Gain: '<S53>/Gain1' */
          rtb_a_n = fmodf(floorf(1000.0F * u0), 4.2949673E+9F);
          rtb_throttle_cmd_f = (uint16_T)((rtb_a_n < 0.0F ? (uint32_T)-(int32_T)
            (uint32_T)-rtb_a_n : (uint32_T)rtb_a_n) + 1000U);
        }

        /* End of Switch: '<S56>/Switch' */
      } else {
        /* Sum: '<S53>/Sum' incorporates:
         *  Constant: '<S53>/hover_throttle'
         *  Saturate: '<S13>/Saturation2'
         */
        u0 = rtb_Subtract3_i + CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S53>/Saturation' */
        if (u0 > 1.0F) {
          u0 = 1.0F;
        } else if (u0 < 0.0F) {
          u0 = 0.0F;
        }

        /* Gain: '<S53>/Gain1' */
        rtb_a_n = fmodf(floorf(1000.0F * u0), 4.2949673E+9F);

        /* Switch: '<S51>/Switch1' incorporates:
         *  Constant: '<S53>/Constant1'
         *  DataTypeConversion: '<S53>/Data Type Conversion'
         *  Gain: '<S53>/Gain1'
         *  Sum: '<S53>/Sum1'
         */
        rtb_throttle_cmd_f = (uint16_T)((rtb_a_n < 0.0F ? (uint32_T)-(int32_T)
          (uint32_T)-rtb_a_n : (uint32_T)rtb_a_n) + 1000U);
      }

      /* End of Switch: '<S51>/Switch' */

      /* Saturate: '<S13>/Saturation1' */
      if (rtb_Sum_idx_0 > 1.0F) {
        u0 = 1.0F;
      } else if (rtb_Sum_idx_0 < -1.0F) {
        u0 = -1.0F;
      } else {
        u0 = rtb_Sum_idx_0;
      }

      if (rtb_att_error_B_rad_idx_1 > 1.0F) {
        rtb_Add_g_idx_0 = 1.0F;
      } else if (rtb_att_error_B_rad_idx_1 < -1.0F) {
        rtb_Add_g_idx_0 = -1.0F;
      } else {
        rtb_Add_g_idx_0 = rtb_att_error_B_rad_idx_1;
      }

      if (rtb_att_error_B_rad_idx_0 > 1.0F) {
        rtb_Add_g_idx_1 = 1.0F;
      } else if (rtb_att_error_B_rad_idx_0 < -1.0F) {
        rtb_Add_g_idx_1 = -1.0F;
      } else {
        rtb_Add_g_idx_1 = rtb_att_error_B_rad_idx_0;
      }

      /* End of Saturate: '<S13>/Saturation1' */

      /* Product: '<S13>/Multiply' */
      for (i = 0; i < 4; i++) {
        uint16_T u0_0;

        /* Saturate: '<S13>/Saturation' incorporates:
         *  Constant: '<S13>/Effective_Matrix'
         *  Gain: '<S13>/Gain'
         *  MultiPortSwitch: '<S52>/Multiport Switch'
         *  Sum: '<S13>/Add'
         */
        rtb_a_n = fmodf(floorf(((Controller_ConstP.Effective_Matrix_Value_fr[i +
          4] * rtb_Add_g_idx_0 + Controller_ConstP.Effective_Matrix_Value_fr[i] *
          u0) + Controller_ConstP.Effective_Matrix_Value_fr[i + 8] *
          rtb_Add_g_idx_1) * 1000.0F + (real32_T)rtb_throttle_cmd_f), 65536.0F);
        u0_0 = (uint16_T)(rtb_a_n < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                          (uint16_T)-rtb_a_n : (int32_T)(uint16_T)rtb_a_n);
        if (u0_0 > 1900) {
          rtb_MultiportSwitch_b0[i] = 1900U;
        } else if (u0_0 < 1100) {
          rtb_MultiportSwitch_b0[i] = 1100U;
        } else {
          rtb_MultiportSwitch_b0[i] = u0_0;
        }

        /* End of Saturate: '<S13>/Saturation' */
      }

      /* End of Product: '<S13>/Multiply' */
    }
    break;

   default:
    rtb_MultiportSwitch_b0[0] = 1000U;
    rtb_MultiportSwitch_b0[1] = 1000U;
    rtb_MultiportSwitch_b0[2] = 1000U;
    rtb_MultiportSwitch_b0[3] = 1000U;
    break;
  }

  /* End of MultiPortSwitch: '<S52>/Multiport Switch' */

  /* Reshape: '<S52>/Reshape' incorporates:
   *  VariantMerge generated from: '<S4>/actuator_cmd'
   */
  Controller_Y.Control_Out.actuator_cmd[0] = rtb_MultiportSwitch_b0[0];
  Controller_Y.Control_Out.actuator_cmd[1] = rtb_MultiportSwitch_b0[1];
  Controller_Y.Control_Out.actuator_cmd[2] = rtb_MultiportSwitch_b0[2];
  Controller_Y.Control_Out.actuator_cmd[3] = rtb_MultiportSwitch_b0[3];
  for (i = 0; i < 12; i++) {
    Controller_Y.Control_Out.actuator_cmd[i + 4] = 0U;
  }

  /* End of Reshape: '<S52>/Reshape' */
  /* End of Outputs for SubSystem: '<S4>/Quadcopter_+' */
#elif AIRFRAME == 1

  /* Outputs for Atomic SubSystem: '<S4>/Quadcopter_x' */
  /* MultiPortSwitch: '<S58>/Multiport Switch' incorporates:
   *  Constant: '<S58>/Disarm'
   *  Constant: '<S58>/Standby'
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    rtb_MultiportSwitch_b0[0] = 1000U;
    rtb_MultiportSwitch_b0[1] = 1000U;
    rtb_MultiportSwitch_b0[2] = 1000U;
    rtb_MultiportSwitch_b0[3] = 1000U;
    break;

   case 2:
    rtb_MultiportSwitch_b0[0] = 1150U;
    rtb_MultiportSwitch_b0[1] = 1150U;
    rtb_MultiportSwitch_b0[2] = 1150U;
    rtb_MultiportSwitch_b0[3] = 1150U;
    break;

   case 3:
    {
      uint16_T rtb_throttle_cmd_f;

      /* Switch: '<S57>/Switch' incorporates:
       *  Constant: '<S60>/Constant'
       *  Constant: '<S61>/Constant'
       *  Logic: '<S57>/Logical Operator'
       *  RelationalOperator: '<S60>/Compare'
       *  RelationalOperator: '<S61>/Compare'
       *  Switch: '<S57>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S62>/Switch' incorporates:
         *  Constant: '<S59>/Constant1'
         *  DataTypeConversion: '<S59>/Data Type Conversion'
         *  Gain: '<S59>/Gain1'
         *  S-Function (sfix_bitop): '<S62>/cmd_throttle valid'
         *  Sum: '<S59>/Sum1'
         *  Switch: '<S57>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
        } else {
          /* Sum: '<S59>/Sum' incorporates:
           *  Constant: '<S59>/hover_throttle'
           *  Saturate: '<S14>/Saturation2'
           */
          u0 = rtb_Subtract3_i + CONTROL_PARAM.HOVER_THRO;

          /* Saturate: '<S59>/Saturation' */
          if (u0 > 1.0F) {
            u0 = 1.0F;
          } else if (u0 < 0.0F) {
            u0 = 0.0F;
          }

          /* Gain: '<S59>/Gain1' */
          rtb_a_n = fmodf(floorf(1000.0F * u0), 4.2949673E+9F);
          rtb_throttle_cmd_f = (uint16_T)((rtb_a_n < 0.0F ? (uint32_T)-(int32_T)
            (uint32_T)-rtb_a_n : (uint32_T)rtb_a_n) + 1000U);
        }

        /* End of Switch: '<S62>/Switch' */
      } else {
        /* Sum: '<S59>/Sum' incorporates:
         *  Constant: '<S59>/hover_throttle'
         *  Saturate: '<S14>/Saturation2'
         */
        u0 = rtb_Subtract3_i + CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S59>/Saturation' */
        if (u0 > 1.0F) {
          u0 = 1.0F;
        } else if (u0 < 0.0F) {
          u0 = 0.0F;
        }

        /* Gain: '<S59>/Gain1' */
        rtb_a_n = fmodf(floorf(1000.0F * u0), 4.2949673E+9F);

        /* Switch: '<S57>/Switch1' incorporates:
         *  Constant: '<S59>/Constant1'
         *  DataTypeConversion: '<S59>/Data Type Conversion'
         *  Gain: '<S59>/Gain1'
         *  Sum: '<S59>/Sum1'
         */
        rtb_throttle_cmd_f = (uint16_T)((rtb_a_n < 0.0F ? (uint32_T)-(int32_T)
          (uint32_T)-rtb_a_n : (uint32_T)rtb_a_n) + 1000U);
      }

      /* End of Switch: '<S57>/Switch' */

      /* Saturate: '<S14>/Saturation1' */
      if (rtb_Sum_idx_0 > 1.0F) {
        rtb_Sum_idx_0 = 1.0F;
      } else if (rtb_Sum_idx_0 < -1.0F) {
        rtb_Sum_idx_0 = -1.0F;
      }

      if (rtb_att_error_B_rad_idx_1 > 1.0F) {
        rtb_att_error_B_rad_idx_1 = 1.0F;
      } else if (rtb_att_error_B_rad_idx_1 < -1.0F) {
        rtb_att_error_B_rad_idx_1 = -1.0F;
      }

      if (rtb_att_error_B_rad_idx_0 > 1.0F) {
        rtb_att_error_B_rad_idx_0 = 1.0F;
      } else if (rtb_att_error_B_rad_idx_0 < -1.0F) {
        rtb_att_error_B_rad_idx_0 = -1.0F;
      }

      /* End of Saturate: '<S14>/Saturation1' */

      /* Product: '<S14>/Multiply' */
      for (i = 0; i < 4; i++) {
        uint16_T u0_0;

        /* Saturate: '<S14>/Saturation' incorporates:
         *  Constant: '<S14>/Effective_Matrix'
         *  Gain: '<S14>/Gain'
         *  MultiPortSwitch: '<S58>/Multiport Switch'
         *  Sum: '<S14>/Add'
         */
        rtb_a_n = fmodf(floorf(((Controller_ConstP.Effective_Matrix_Value_h[i +
          4] * rtb_att_error_B_rad_idx_1 +
          Controller_ConstP.Effective_Matrix_Value_h[i] * rtb_Sum_idx_0) +
          Controller_ConstP.Effective_Matrix_Value_h[i + 8] *
          rtb_att_error_B_rad_idx_0) * 1000.0F + (real32_T)rtb_throttle_cmd_f),
                        65536.0F);
        u0_0 = (uint16_T)(rtb_a_n < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                          (uint16_T)-rtb_a_n : (int32_T)(uint16_T)rtb_a_n);
        if (u0_0 > 1900) {
          rtb_MultiportSwitch_b0[i] = 1900U;
        } else if (u0_0 < 1100) {
          rtb_MultiportSwitch_b0[i] = 1100U;
        } else {
          rtb_MultiportSwitch_b0[i] = u0_0;
        }

        /* End of Saturate: '<S14>/Saturation' */
      }

      /* End of Product: '<S14>/Multiply' */
    }
    break;

   default:
    rtb_MultiportSwitch_b0[0] = 1000U;
    rtb_MultiportSwitch_b0[1] = 1000U;
    rtb_MultiportSwitch_b0[2] = 1000U;
    rtb_MultiportSwitch_b0[3] = 1000U;
    break;
  }

  /* End of MultiPortSwitch: '<S58>/Multiport Switch' */

  /* Reshape: '<S58>/Reshape' incorporates:
   *  VariantMerge generated from: '<S4>/actuator_cmd'
   */
  Controller_Y.Control_Out.actuator_cmd[0] = rtb_MultiportSwitch_b0[0];
  Controller_Y.Control_Out.actuator_cmd[1] = rtb_MultiportSwitch_b0[1];
  Controller_Y.Control_Out.actuator_cmd[2] = rtb_MultiportSwitch_b0[2];
  Controller_Y.Control_Out.actuator_cmd[3] = rtb_MultiportSwitch_b0[3];
  for (i = 0; i < 12; i++) {
    Controller_Y.Control_Out.actuator_cmd[i + 4] = 0U;
  }

  /* End of Reshape: '<S58>/Reshape' */
  /* End of Outputs for SubSystem: '<S4>/Quadcopter_x' */
#endif

  /* End of Outputs for SubSystem: '<S2>/Control_Allocation' */

  /* Product: '<S77>/Multiply' incorporates:
   *  Constant: '<S77>/gain1'
   *  Constant: '<S77>/gain2'
   *  Constant: '<S77>/gain3'
   *  DiscreteIntegrator: '<S74>/Discrete-Time Integrator5'
   */
  rtb_Add_g_idx_0 = CONTROL_PARAM.ROLL_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
  rtb_Add_g_idx_1 = CONTROL_PARAM.PITCH_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
  rtb_Add_g_idx_2 = CONTROL_PARAM.YAW_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];

  /* Product: '<S102>/Multiply1' incorporates:
   *  Constant: '<S102>/const1'
   *  DiscreteIntegrator: '<S99>/Integrator'
   */
  rtb_att_error_B_rad_idx_0 = Controller_DW.Integrator_DSTATE[0] * 0.05F;
  rtb_att_error_B_rad_idx_1 = Controller_DW.Integrator_DSTATE[1] * 0.05F;

  /* Sum: '<S102>/Add' incorporates:
   *  DiscreteIntegrator: '<S99>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S99>/Subtract'
   */
  rtb_Subtract3_idx_0 = (Controller_DW.Integrator1_DSTATE[0] -
    Controller_U.FMS_Out.u_cmd) + rtb_att_error_B_rad_idx_0;
  rtb_Subtract3_idx_1 = (Controller_DW.Integrator1_DSTATE[1] -
    Controller_U.FMS_Out.v_cmd) + rtb_att_error_B_rad_idx_1;

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;

  /* Product: '<S116>/Multiply1' incorporates:
   *  Constant: '<S116>/const1'
   *  DiscreteIntegrator: '<S115>/Integrator'
   */
  rtb_Add3_c = Controller_DW.Integrator_DSTATE_p * 0.05F;

  /* Sum: '<S116>/Add' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S115>/Subtract'
   */
  rtb_Subtract3_i = (w_cmd_C_mPs - Controller_U.FMS_Out.w_cmd) + rtb_Add3_c;

  /* Signum: '<S116>/Sign' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_a_n = -1.0F;
  } else if (rtb_Subtract3_i > 0.0F) {
    rtb_a_n = 1.0F;
  } else {
    rtb_a_n = rtb_Subtract3_i;
  }

  /* End of Signum: '<S116>/Sign' */

  /* Sum: '<S116>/Add2' incorporates:
   *  Abs: '<S116>/Abs'
   *  Gain: '<S116>/Gain'
   *  Gain: '<S116>/Gain1'
   *  Product: '<S116>/Multiply2'
   *  Product: '<S116>/Multiply3'
   *  Sqrt: '<S116>/Sqrt'
   *  Sum: '<S116>/Add1'
   *  Sum: '<S116>/Subtract'
   */
  rtb_a_n = (sqrtf((8.0F * fabsf(rtb_Subtract3_i) + Controller_ConstB.d_n) *
                   Controller_ConstB.d_n) - Controller_ConstB.d_n) * 0.5F *
    rtb_a_n + rtb_Add3_c;

  /* Sum: '<S116>/Add3' */
  u0 = rtb_Subtract3_i + Controller_ConstB.d_n;

  /* Sum: '<S116>/Subtract1' */
  rtb_Sum_idx_0 = rtb_Subtract3_i - Controller_ConstB.d_n;

  /* Signum: '<S116>/Sign1' */
  if (u0 < 0.0F) {
    u0 = -1.0F;
  } else if (u0 > 0.0F) {
    u0 = 1.0F;
  }

  /* End of Signum: '<S116>/Sign1' */

  /* Signum: '<S116>/Sign2' */
  if (rtb_Sum_idx_0 < 0.0F) {
    rtb_Sum_idx_0 = -1.0F;
  } else if (rtb_Sum_idx_0 > 0.0F) {
    rtb_Sum_idx_0 = 1.0F;
  }

  /* End of Signum: '<S116>/Sign2' */

  /* Sum: '<S116>/Add5' incorporates:
   *  Gain: '<S116>/Gain2'
   *  Product: '<S116>/Multiply4'
   *  Sum: '<S116>/Add4'
   *  Sum: '<S116>/Subtract2'
   */
  rtb_a_n += ((rtb_Subtract3_i - rtb_a_n) + rtb_Add3_c) * ((u0 - rtb_Sum_idx_0) *
    0.5F);

  /* Update for DiscreteIntegrator: '<S104>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S106>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

  /* Signum: '<S102>/Sign' */
  if (rtb_Subtract3_idx_0 < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else if (rtb_Subtract3_idx_0 > 0.0F) {
    rtb_Subtract3_i = 1.0F;
  } else {
    rtb_Subtract3_i = rtb_Subtract3_idx_0;
  }

  /* Sum: '<S102>/Add2' incorporates:
   *  Abs: '<S102>/Abs'
   *  Gain: '<S102>/Gain'
   *  Gain: '<S102>/Gain1'
   *  Product: '<S102>/Multiply2'
   *  Product: '<S102>/Multiply3'
   *  Signum: '<S102>/Sign'
   *  Sqrt: '<S102>/Sqrt'
   *  Sum: '<S102>/Add1'
   *  Sum: '<S102>/Subtract'
   */
  rtb_Subtract3_i = (sqrtf((8.0F * fabsf(rtb_Subtract3_idx_0) +
    Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    rtb_Subtract3_i + rtb_att_error_B_rad_idx_0;

  /* Signum: '<S102>/Sign1' incorporates:
   *  Signum: '<S102>/Sign'
   *  Sum: '<S102>/Add3'
   */
  u0 = rtb_Subtract3_idx_0 + Controller_ConstB.d;

  /* Signum: '<S102>/Sign2' incorporates:
   *  Signum: '<S102>/Sign'
   *  Sum: '<S102>/Subtract1'
   */
  rtb_Sum_idx_0 = rtb_Subtract3_idx_0 - Controller_ConstB.d;

  /* Signum: '<S102>/Sign1' */
  if (u0 < 0.0F) {
    u0 = -1.0F;
  } else if (u0 > 0.0F) {
    u0 = 1.0F;
  }

  /* Signum: '<S102>/Sign2' */
  if (rtb_Sum_idx_0 < 0.0F) {
    rtb_Sum_idx_0 = -1.0F;
  } else if (rtb_Sum_idx_0 > 0.0F) {
    rtb_Sum_idx_0 = 1.0F;
  }

  /* Sum: '<S102>/Add2' incorporates:
   *  Gain: '<S102>/Gain2'
   *  Product: '<S102>/Multiply4'
   *  Signum: '<S102>/Sign'
   *  Sum: '<S102>/Add4'
   *  Sum: '<S102>/Add5'
   *  Sum: '<S102>/Subtract2'
   */
  rtb_att_error_B_rad_idx_0 = ((rtb_Subtract3_idx_0 - rtb_Subtract3_i) +
    rtb_att_error_B_rad_idx_0) * ((u0 - rtb_Sum_idx_0) * 0.5F) + rtb_Subtract3_i;

  /* Update for DiscreteIntegrator: '<S99>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S99>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE[0] += 0.002F *
    Controller_DW.Integrator_DSTATE[0];

  /* Update for DiscreteIntegrator: '<S104>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S104>/ki'
   *  Product: '<S104>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[0] += CONTROL_PARAM.VEL_XY_I *
    rtb_uv_error_C_mPs_idx_0 * 0.002F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.VEL_XY_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
             CONTROL_PARAM.VEL_XY_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.VEL_XY_I_MIN;
  }

  /* Update for DiscreteIntegrator: '<S106>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_Gain_idx_0;

  /* Signum: '<S102>/Sign' */
  if (rtb_Subtract3_idx_1 < 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = -1.0F;
  } else if (rtb_Subtract3_idx_1 > 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = 1.0F;
  } else {
    rtb_uv_error_C_mPs_idx_0 = rtb_Subtract3_idx_1;
  }

  /* Sum: '<S102>/Add2' incorporates:
   *  Abs: '<S102>/Abs'
   *  Gain: '<S102>/Gain'
   *  Gain: '<S102>/Gain1'
   *  Product: '<S102>/Multiply2'
   *  Product: '<S102>/Multiply3'
   *  Signum: '<S102>/Sign'
   *  Sqrt: '<S102>/Sqrt'
   *  Sum: '<S102>/Add1'
   *  Sum: '<S102>/Subtract'
   */
  rtb_Subtract3_i = (sqrtf((8.0F * fabsf(rtb_Subtract3_idx_1) +
    Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    rtb_uv_error_C_mPs_idx_0 + rtb_att_error_B_rad_idx_1;

  /* Signum: '<S102>/Sign1' incorporates:
   *  Signum: '<S102>/Sign'
   *  Sum: '<S102>/Add3'
   */
  u0 = rtb_Subtract3_idx_1 + Controller_ConstB.d;

  /* Signum: '<S102>/Sign2' incorporates:
   *  Signum: '<S102>/Sign'
   *  Sum: '<S102>/Subtract1'
   */
  rtb_Sum_idx_0 = rtb_Subtract3_idx_1 - Controller_ConstB.d;

  /* Signum: '<S102>/Sign1' */
  if (u0 < 0.0F) {
    u0 = -1.0F;
  } else if (u0 > 0.0F) {
    u0 = 1.0F;
  }

  /* Signum: '<S102>/Sign2' */
  if (rtb_Sum_idx_0 < 0.0F) {
    rtb_Sum_idx_0 = -1.0F;
  } else if (rtb_Sum_idx_0 > 0.0F) {
    rtb_Sum_idx_0 = 1.0F;
  }

  /* Sum: '<S102>/Add5' incorporates:
   *  Gain: '<S102>/Gain2'
   *  Product: '<S102>/Multiply4'
   *  Signum: '<S102>/Sign'
   *  Sum: '<S102>/Add2'
   *  Sum: '<S102>/Add4'
   *  Sum: '<S102>/Subtract2'
   */
  rtb_Subtract3_i += ((rtb_Subtract3_idx_1 - rtb_Subtract3_i) +
                      rtb_att_error_B_rad_idx_1) * ((u0 - rtb_Sum_idx_0) * 0.5F);

  /* Update for DiscreteIntegrator: '<S99>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S99>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE[1] += 0.002F *
    Controller_DW.Integrator_DSTATE[1];

  /* Update for DiscreteIntegrator: '<S104>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S104>/ki'
   *  Product: '<S104>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[1] += CONTROL_PARAM.VEL_XY_I *
    rtb_uv_error_C_mPs_idx_1 * 0.002F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.VEL_XY_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
             CONTROL_PARAM.VEL_XY_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.VEL_XY_I_MIN;
  }

  /* Update for DiscreteIntegrator: '<S106>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Gain_idx_1;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S74>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S77>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_g = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S79>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_l = 0U;

  /* Update for DiscreteIntegrator: '<S74>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S74>/Gain'
   *  Sum: '<S74>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] += (cumRevIndex -
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S77>/Discrete-Time Integrator' incorporates:
   *  Product: '<S77>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] += 0.002F * rtb_Add_g_idx_0;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] = CONTROL_PARAM.RATE_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] <=
             CONTROL_PARAM.RATE_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] = CONTROL_PARAM.RATE_I_MIN;
  }

  /* Update for DiscreteIntegrator: '<S79>/Discrete-Time Integrator1' incorporates:
   *  Gain: '<S79>/Gain'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] += 0.002F * z;

  /* Update for DiscreteIntegrator: '<S74>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S74>/Gain'
   *  Sum: '<S74>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Saturation1_is_idx_0 -
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S77>/Discrete-Time Integrator' incorporates:
   *  Product: '<S77>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] += 0.002F * rtb_Add_g_idx_1;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] = CONTROL_PARAM.RATE_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] <=
             CONTROL_PARAM.RATE_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] = CONTROL_PARAM.RATE_I_MIN;
  }

  /* Update for DiscreteIntegrator: '<S79>/Discrete-Time Integrator1' incorporates:
   *  Gain: '<S79>/Gain'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] += 0.002F * rtb_Gain_c_idx_1;

  /* Update for DiscreteIntegrator: '<S74>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S74>/Gain'
   *  Sum: '<S74>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +=
    (rtb_DiscreteTimeIntegrator1_j -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S77>/Discrete-Time Integrator' incorporates:
   *  Product: '<S77>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] += 0.002F * rtb_Add_g_idx_2;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] = CONTROL_PARAM.RATE_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] <=
             CONTROL_PARAM.RATE_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] = CONTROL_PARAM.RATE_I_MIN;
  }

  /* Update for DiscreteIntegrator: '<S79>/Discrete-Time Integrator1' incorporates:
   *  Gain: '<S79>/Gain'
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2] += 0.002F * rtb_Gain_c_idx_2;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_i = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S115>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S115>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE_p += 0.002F *
    Controller_DW.Integrator_DSTATE_p;

  /* Update for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S118>/ki'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S118>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m += CONTROL_PARAM.VEL_Z_I *
    rtb_Saturation_d_idx_2 * 0.002F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m >= CONTROL_PARAM.VEL_Z_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m <=
             CONTROL_PARAM.VEL_Z_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MIN;
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_m = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_k = 0U;
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_h += 0.002F *
    rtb_Saturation_d_idx_1;
  Controller_DW.DiscreteTimeIntegrator1_Prev_iy = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Signum: '<S102>/Sign3' incorporates:
   *  Product: '<S102>/Divide'
   *  Sum: '<S102>/Add6'
   */
  u0 = rtb_att_error_B_rad_idx_0 + Controller_ConstB.d;

  /* Signum: '<S102>/Sign4' incorporates:
   *  Product: '<S102>/Divide'
   *  Sum: '<S102>/Subtract3'
   */
  rtb_Sum_idx_0 = rtb_att_error_B_rad_idx_0 - Controller_ConstB.d;

  /* Signum: '<S102>/Sign5' incorporates:
   *  Product: '<S102>/Divide'
   */
  if (rtb_att_error_B_rad_idx_0 < 0.0F) {
    rtb_uv_error_C_mPs_idx_1 = -1.0F;
  } else if (rtb_att_error_B_rad_idx_0 > 0.0F) {
    rtb_uv_error_C_mPs_idx_1 = 1.0F;
  } else {
    rtb_uv_error_C_mPs_idx_1 = rtb_att_error_B_rad_idx_0;
  }

  /* Signum: '<S102>/Sign3' */
  if (u0 < 0.0F) {
    u0 = -1.0F;
  } else if (u0 > 0.0F) {
    u0 = 1.0F;
  }

  /* Signum: '<S102>/Sign4' */
  if (rtb_Sum_idx_0 < 0.0F) {
    rtb_Sum_idx_0 = -1.0F;
  } else if (rtb_Sum_idx_0 > 0.0F) {
    rtb_Sum_idx_0 = 1.0F;
  }

  /* Signum: '<S102>/Sign6' incorporates:
   *  Product: '<S102>/Divide'
   */
  if (rtb_att_error_B_rad_idx_0 < 0.0F) {
    rtb_Gain_idx_1 = -1.0F;
  } else if (rtb_att_error_B_rad_idx_0 > 0.0F) {
    rtb_Gain_idx_1 = 1.0F;
  } else {
    rtb_Gain_idx_1 = rtb_att_error_B_rad_idx_0;
  }

  /* Update for DiscreteIntegrator: '<S99>/Integrator' incorporates:
   *  Constant: '<S102>/const'
   *  Gain: '<S102>/Gain3'
   *  Product: '<S102>/Divide'
   *  Product: '<S102>/Multiply5'
   *  Product: '<S102>/Multiply6'
   *  Sum: '<S102>/Subtract4'
   *  Sum: '<S102>/Subtract5'
   *  Sum: '<S102>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[0] += ((rtb_att_error_B_rad_idx_0 /
    Controller_ConstB.d - rtb_uv_error_C_mPs_idx_1) * Controller_ConstB.Gain4 *
    ((u0 - rtb_Sum_idx_0) * 0.5F) - rtb_Gain_idx_1 * 58.836F) * 0.002F;

  /* Signum: '<S102>/Sign3' incorporates:
   *  Sum: '<S102>/Add6'
   */
  u0 = rtb_Subtract3_i + Controller_ConstB.d;

  /* Signum: '<S102>/Sign4' incorporates:
   *  Sum: '<S102>/Subtract3'
   */
  rtb_Sum_idx_0 = rtb_Subtract3_i - Controller_ConstB.d;

  /* Signum: '<S102>/Sign5' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_uv_error_C_mPs_idx_1 = -1.0F;
  } else if (rtb_Subtract3_i > 0.0F) {
    rtb_uv_error_C_mPs_idx_1 = 1.0F;
  } else {
    rtb_uv_error_C_mPs_idx_1 = rtb_Subtract3_i;
  }

  /* Signum: '<S102>/Sign3' */
  if (u0 < 0.0F) {
    u0 = -1.0F;
  } else if (u0 > 0.0F) {
    u0 = 1.0F;
  }

  /* Signum: '<S102>/Sign4' */
  if (rtb_Sum_idx_0 < 0.0F) {
    rtb_Sum_idx_0 = -1.0F;
  } else if (rtb_Sum_idx_0 > 0.0F) {
    rtb_Sum_idx_0 = 1.0F;
  }

  /* Signum: '<S102>/Sign6' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Gain_idx_1 = -1.0F;
  } else if (rtb_Subtract3_i > 0.0F) {
    rtb_Gain_idx_1 = 1.0F;
  } else {
    rtb_Gain_idx_1 = rtb_Subtract3_i;
  }

  /* Update for DiscreteIntegrator: '<S99>/Integrator' incorporates:
   *  Constant: '<S102>/const'
   *  Gain: '<S102>/Gain3'
   *  Product: '<S102>/Divide'
   *  Product: '<S102>/Multiply5'
   *  Product: '<S102>/Multiply6'
   *  Sum: '<S102>/Subtract4'
   *  Sum: '<S102>/Subtract5'
   *  Sum: '<S102>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[1] += ((rtb_Subtract3_i / Controller_ConstB.d
    - rtb_uv_error_C_mPs_idx_1) * Controller_ConstB.Gain4 * ((u0 - rtb_Sum_idx_0)
    * 0.5F) - rtb_Gain_idx_1 * 58.836F) * 0.002F;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S3>/Constant'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_n += CONTROL_EXPORT.period;

  /* Signum: '<S116>/Sign5' */
  if (rtb_a_n < 0.0F) {
    /* Signum: '<S116>/Sign6' */
    rtb_uv_error_C_mPs_idx_1 = -1.0F;
  } else if (rtb_a_n > 0.0F) {
    /* Signum: '<S116>/Sign6' */
    rtb_uv_error_C_mPs_idx_1 = 1.0F;
  } else {
    /* Signum: '<S116>/Sign6' */
    rtb_uv_error_C_mPs_idx_1 = rtb_a_n;
  }

  /* Sum: '<S116>/Add6' */
  u0 = rtb_a_n + Controller_ConstB.d_n;

  /* Sum: '<S116>/Subtract3' */
  rtb_Sum_idx_0 = rtb_a_n - Controller_ConstB.d_n;

  /* Signum: '<S116>/Sign3' */
  if (u0 < 0.0F) {
    u0 = -1.0F;
  } else if (u0 > 0.0F) {
    u0 = 1.0F;
  }

  /* End of Signum: '<S116>/Sign3' */

  /* Signum: '<S116>/Sign4' */
  if (rtb_Sum_idx_0 < 0.0F) {
    rtb_Sum_idx_0 = -1.0F;
  } else if (rtb_Sum_idx_0 > 0.0F) {
    rtb_Sum_idx_0 = 1.0F;
  }

  /* End of Signum: '<S116>/Sign4' */

  /* Update for DiscreteIntegrator: '<S115>/Integrator' incorporates:
   *  Constant: '<S116>/const'
   *  Gain: '<S116>/Gain3'
   *  Product: '<S116>/Divide'
   *  Product: '<S116>/Multiply5'
   *  Product: '<S116>/Multiply6'
   *  Signum: '<S116>/Sign5'
   *  Sum: '<S116>/Subtract4'
   *  Sum: '<S116>/Subtract5'
   *  Sum: '<S116>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE_p += ((rtb_a_n / Controller_ConstB.d_n -
    rtb_uv_error_C_mPs_idx_1) * Controller_ConstB.Gain4_k * ((u0 - rtb_Sum_idx_0)
    * 0.5F) - rtb_uv_error_C_mPs_idx_1 * 78.448F) * 0.002F;
}

/* Model initialize function */
void Controller_init(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Controller_M, (NULL));

  /* block I/O */

  /* exported global signals */
  att_cmd_B_rad[0] = 0.0F;
  att_cmd_B_rad[1] = 0.0F;
  att_est_B_rad[0] = 0.0F;
  att_est_B_rad[1] = 0.0F;
  rate_cmd_B_radPs[0] = 0.0F;
  rate_cmd_B_radPs[1] = 0.0F;
  rate_cmd_B_radPs[2] = 0.0F;
  rate_est_B_radPs[0] = 0.0F;
  rate_est_B_radPs[1] = 0.0F;
  rate_est_B_radPs[2] = 0.0F;
  w_cmd_C_mPs = 0.0F;
  w_est_C_mPs = 0.0F;

  /* states (dwork) */
  (void) memset((void *)&Controller_DW, 0,
                sizeof(DW_Controller_T));

  /* external inputs */
  (void)memset(&Controller_U, 0, sizeof(ExtU_Controller_T));

  /* external outputs */
  Controller_Y.Control_Out = Controller_rtZControl_Out_Bus;

  {
    g_dsp_internal_SlidingWindowA_T *iobj_0;
    int32_T i;

    /* Start for Constant: '<S118>/Constant' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MIN;

    /* InitializeConditions for DiscreteIntegrator: '<S104>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
      Controller_ConstB.Constant_g;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
        CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
               CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
      Controller_ConstB.Constant_g;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
        CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
               CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }

    Controller_DW.DiscreteTimeIntegrator_PrevRese = 0;

    /* End of InitializeConditions for DiscreteIntegrator: '<S104>/Discrete-Time Integrator' */

    /* InitializeConditions for DiscreteIntegrator: '<S106>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S74>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S77>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
      Controller_ConstB.Constant[0];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MAX;
    } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] <=
               CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MIN;
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
      Controller_ConstB.Constant[1];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MAX;
    } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] <=
               CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MIN;
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
      Controller_ConstB.Constant[2];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MAX;
    } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] <=
               CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MIN;
    }

    Controller_DW.DiscreteTimeIntegrator_PrevRe_g = 0;

    /* End of InitializeConditions for DiscreteIntegrator: '<S77>/Discrete-Time Integrator' */

    /* InitializeConditions for DiscreteIntegrator: '<S79>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_PrevR_i = 0;
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_l = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m >=
        CONTROL_PARAM.VEL_Z_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MAX;
    } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m <=
               CONTROL_PARAM.VEL_Z_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MIN;
    }

    Controller_DW.DiscreteTimeIntegrator_PrevRe_m = 0;

    /* End of InitializeConditions for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */

    /* InitializeConditions for DiscreteIntegrator: '<S120>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_Prev_iy = 0;
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_k = 1U;

    /* Start for MATLABSystem: '<S70>/Moving Average' */
    Controller_DW.obj.matlabCodegenIsDeleted = true;
    Controller_DW.obj.isInitialized = 0;
    Controller_DW.obj.NumChannels = -1;
    Controller_DW.obj.matlabCodegenIsDeleted = false;
    Controller_DW.obj.isSetupComplete = false;
    Controller_DW.obj.isInitialized = 1;
    Controller_DW.obj.NumChannels = 1;
    iobj_0 = &Controller_DW.obj._pobj0;
    iobj_0->isInitialized = 0;
    iobj_0->isInitialized = 0;
    Controller_DW.obj.pStatistic = iobj_0;
    Controller_DW.obj.isSetupComplete = true;
    Controller_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S70>/Moving Average' */
    iobj_0 = Controller_DW.obj.pStatistic;
    if (iobj_0->isInitialized == 1) {
      iobj_0->pCumSum = 0.0F;
      for (i = 0; i < 24; i++) {
        iobj_0->pCumSumRev[i] = 0.0F;
      }

      iobj_0->pCumRevIndex = 1.0F;
      iobj_0->pModValueRev = 0.0F;
    }

    /* End of InitializeConditions for MATLABSystem: '<S70>/Moving Average' */
  }
}

/* Model terminate function */
void Controller_terminate(void)
{
  g_dsp_internal_SlidingWindowA_T *obj;

  /* Terminate for MATLABSystem: '<S70>/Moving Average' */
  if (!Controller_DW.obj.matlabCodegenIsDeleted) {
    Controller_DW.obj.matlabCodegenIsDeleted = true;
    if ((Controller_DW.obj.isInitialized == 1) &&
        Controller_DW.obj.isSetupComplete) {
      obj = Controller_DW.obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      Controller_DW.obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S70>/Moving Average' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
