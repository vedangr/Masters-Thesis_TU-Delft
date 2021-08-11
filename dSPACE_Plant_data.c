/*
 * dSPACE_Plant_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "dSPACE_Plant".
 *
 * Model version              : 1.3
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Thu Jul 22 15:51:02 2021
 *
 * Target selection: rti1401.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "dSPACE_Plant.h"
#include "dSPACE_Plant_private.h"

/* Block parameters (default storage) */
P_dSPACE_Plant_T dSPACE_Plant_P = {
  /* Variable: A
   * Referenced by: '<Root>/2-tank level control lant1'
   */
  { -0.05, 0.2, 0.0, -0.2 },

  /* Variable: B
   * Referenced by: '<Root>/2-tank level control lant1'
   */
  { 0.1, 0.0, 0.1, 0.1 },

  /* Variable: C
   * Referenced by: '<Root>/2-tank level control lant1'
   */
  { 1.0, 0.0, 0.0, 1.0 },

  /* Expression: [3 3]
   * Referenced by: '<Root>/2-tank level control lant1'
   */
  { 3.0, 3.0 }
};
