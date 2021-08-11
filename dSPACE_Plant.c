/*
 * dSPACE_Plant.c
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

#include "dSPACE_Plant_trc_ptr.h"
#include "dSPACE_Plant.h"
#include "dSPACE_Plant_private.h"

/* Block signals (default storage) */
B_dSPACE_Plant_T dSPACE_Plant_B;

/* Continuous states */
X_dSPACE_Plant_T dSPACE_Plant_X;

/* Block states (default storage) */
DW_dSPACE_Plant_T dSPACE_Plant_DW;

/* Real-time model */
RT_MODEL_dSPACE_Plant_T dSPACE_Plant_M_;
RT_MODEL_dSPACE_Plant_T *const dSPACE_Plant_M = &dSPACE_Plant_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  dSPACE_Plant_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void dSPACE_Plant_output(void)
{
  if (rtmIsMajorTimeStep(dSPACE_Plant_M)) {
    /* set solver stop time */
    if (!(dSPACE_Plant_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&dSPACE_Plant_M->solverInfo,
                            ((dSPACE_Plant_M->Timing.clockTickH0 + 1) *
        dSPACE_Plant_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&dSPACE_Plant_M->solverInfo,
                            ((dSPACE_Plant_M->Timing.clockTick0 + 1) *
        dSPACE_Plant_M->Timing.stepSize0 + dSPACE_Plant_M->Timing.clockTickH0 *
        dSPACE_Plant_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(dSPACE_Plant_M)) {
    dSPACE_Plant_M->Timing.t[0] = rtsiGetT(&dSPACE_Plant_M->solverInfo);
  }

  /* StateSpace: '<Root>/2-tank level control lant1' */
  dSPACE_Plant_B.utanklevelcontrollant1[0] = 0.0;
  dSPACE_Plant_B.utanklevelcontrollant1[1] = 0.0;
  dSPACE_Plant_B.utanklevelcontrollant1[0] += dSPACE_Plant_P.C[0] *
    dSPACE_Plant_X.utanklevelcontrollant1_CSTATE[0];
  dSPACE_Plant_B.utanklevelcontrollant1[0] += dSPACE_Plant_P.C[2] *
    dSPACE_Plant_X.utanklevelcontrollant1_CSTATE[1];
  dSPACE_Plant_B.utanklevelcontrollant1[1] += dSPACE_Plant_P.C[1] *
    dSPACE_Plant_X.utanklevelcontrollant1_CSTATE[0];
  dSPACE_Plant_B.utanklevelcontrollant1[1] += dSPACE_Plant_P.C[3] *
    dSPACE_Plant_X.utanklevelcontrollant1_CSTATE[1];
  if (rtmIsMajorTimeStep(dSPACE_Plant_M)) {
    /* S-Function (rti_commonblock): '<S3>/S-Function1' */
    /* This comment workarounds a code generation problem */
    {
      /* dSPACE I/O Board DS1401STDAIOT1 #1 Unit:DAC */
      /* write value of DAC for output channels 1-2 synchronous*/
      /*write to buffer*/
      aio_tp1_dac_buffer_write(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CH1, (dsfloat)
        dSPACE_Plant_B.utanklevelcontrollant1[0]);
      aio_tp1_dac_buffer_write(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CH2, (dsfloat)
        dSPACE_Plant_B.utanklevelcontrollant1[1]);

      /*release buffer*/
      aio_tp1_dac_buffer_release(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CTRL_CH1|
        AIO_TP1_DAC_CTRL_CH2);
    }

    /* S-Function (rti_commonblock): '<S1>/S-Function1' */
    /* This comment workarounds a code generation problem */
    {
      /* dSPACE I/O Board DS1401STDAIOT1 #1 Unit:ADC */
      aio_tp1_adc_read(AIO_TP1_1_MODULE_ADDR, AIO_TP1_ADC_CH1, (dsfloat *)
                       &dSPACE_Plant_B.SFunction1);
    }

    /* S-Function (rti_commonblock): '<S2>/S-Function1' */
    /* This comment workarounds a code generation problem */
    {
      /* dSPACE I/O Board DS1401STDAIOT1 #1 Unit:ADC */
      aio_tp1_adc_read(AIO_TP1_1_MODULE_ADDR, AIO_TP1_ADC_CH2, (dsfloat *)
                       &dSPACE_Plant_B.SFunction1_e);
    }
  }

  /* SignalConversion: '<Root>/TmpSignal ConversionAt2-tank level control lant1Inport1' */
  dSPACE_Plant_B.TmpSignalConversionAt2tanklevel[0] = dSPACE_Plant_B.SFunction1;
  dSPACE_Plant_B.TmpSignalConversionAt2tanklevel[1] =
    dSPACE_Plant_B.SFunction1_e;
}

/* Model update function */
void dSPACE_Plant_update(void)
{
  if (rtmIsMajorTimeStep(dSPACE_Plant_M)) {
    rt_ertODEUpdateContinuousStates(&dSPACE_Plant_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++dSPACE_Plant_M->Timing.clockTick0)) {
    ++dSPACE_Plant_M->Timing.clockTickH0;
  }

  dSPACE_Plant_M->Timing.t[0] = rtsiGetSolverStopTime
    (&dSPACE_Plant_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    dSPACE_Plant_M->Timing.clockTick1++;
    if (!dSPACE_Plant_M->Timing.clockTick1) {
      dSPACE_Plant_M->Timing.clockTickH1++;
    }
  }
}

/* Derivatives for root system: '<Root>' */
void dSPACE_Plant_derivatives(void)
{
  XDot_dSPACE_Plant_T *_rtXdot;
  _rtXdot = ((XDot_dSPACE_Plant_T *) dSPACE_Plant_M->derivs);

  /* Derivatives for StateSpace: '<Root>/2-tank level control lant1' */
  _rtXdot->utanklevelcontrollant1_CSTATE[0] = 0.0;
  _rtXdot->utanklevelcontrollant1_CSTATE[0] += dSPACE_Plant_P.A[0] *
    dSPACE_Plant_X.utanklevelcontrollant1_CSTATE[0];
  _rtXdot->utanklevelcontrollant1_CSTATE[0] += dSPACE_Plant_P.A[2] *
    dSPACE_Plant_X.utanklevelcontrollant1_CSTATE[1];
  _rtXdot->utanklevelcontrollant1_CSTATE[1] = 0.0;
  _rtXdot->utanklevelcontrollant1_CSTATE[1] += dSPACE_Plant_P.A[1] *
    dSPACE_Plant_X.utanklevelcontrollant1_CSTATE[0];
  _rtXdot->utanklevelcontrollant1_CSTATE[1] += dSPACE_Plant_P.A[3] *
    dSPACE_Plant_X.utanklevelcontrollant1_CSTATE[1];
  _rtXdot->utanklevelcontrollant1_CSTATE[0] += dSPACE_Plant_P.B[0] *
    dSPACE_Plant_B.TmpSignalConversionAt2tanklevel[0];
  _rtXdot->utanklevelcontrollant1_CSTATE[0] += dSPACE_Plant_P.B[2] *
    dSPACE_Plant_B.TmpSignalConversionAt2tanklevel[1];
  _rtXdot->utanklevelcontrollant1_CSTATE[1] += dSPACE_Plant_P.B[1] *
    dSPACE_Plant_B.TmpSignalConversionAt2tanklevel[0];
  _rtXdot->utanklevelcontrollant1_CSTATE[1] += dSPACE_Plant_P.B[3] *
    dSPACE_Plant_B.TmpSignalConversionAt2tanklevel[1];
}

/* Model initialize function */
void dSPACE_Plant_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)dSPACE_Plant_M, 0,
                sizeof(RT_MODEL_dSPACE_Plant_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&dSPACE_Plant_M->solverInfo,
                          &dSPACE_Plant_M->Timing.simTimeStep);
    rtsiSetTPtr(&dSPACE_Plant_M->solverInfo, &rtmGetTPtr(dSPACE_Plant_M));
    rtsiSetStepSizePtr(&dSPACE_Plant_M->solverInfo,
                       &dSPACE_Plant_M->Timing.stepSize0);
    rtsiSetdXPtr(&dSPACE_Plant_M->solverInfo, &dSPACE_Plant_M->derivs);
    rtsiSetContStatesPtr(&dSPACE_Plant_M->solverInfo, (real_T **)
                         &dSPACE_Plant_M->contStates);
    rtsiSetNumContStatesPtr(&dSPACE_Plant_M->solverInfo,
      &dSPACE_Plant_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&dSPACE_Plant_M->solverInfo,
      &dSPACE_Plant_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&dSPACE_Plant_M->solverInfo,
      &dSPACE_Plant_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&dSPACE_Plant_M->solverInfo,
      &dSPACE_Plant_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&dSPACE_Plant_M->solverInfo, (&rtmGetErrorStatus
      (dSPACE_Plant_M)));
    rtsiSetRTModelPtr(&dSPACE_Plant_M->solverInfo, dSPACE_Plant_M);
  }

  rtsiSetSimTimeStep(&dSPACE_Plant_M->solverInfo, MAJOR_TIME_STEP);
  dSPACE_Plant_M->intgData.f[0] = dSPACE_Plant_M->odeF[0];
  dSPACE_Plant_M->contStates = ((X_dSPACE_Plant_T *) &dSPACE_Plant_X);
  rtsiSetSolverData(&dSPACE_Plant_M->solverInfo, (void *)
                    &dSPACE_Plant_M->intgData);
  rtsiSetSolverName(&dSPACE_Plant_M->solverInfo,"ode1");
  rtmSetTPtr(dSPACE_Plant_M, &dSPACE_Plant_M->Timing.tArray[0]);
  dSPACE_Plant_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) &dSPACE_Plant_B), 0,
                sizeof(B_dSPACE_Plant_T));

  /* states (continuous) */
  {
    (void) memset((void *)&dSPACE_Plant_X, 0,
                  sizeof(X_dSPACE_Plant_T));
  }

  /* states (dwork) */
  (void) memset((void *)&dSPACE_Plant_DW, 0,
                sizeof(DW_dSPACE_Plant_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    dSPACE_Plant_rti_init_trc_pointers();
  }

  /* InitializeConditions for StateSpace: '<Root>/2-tank level control lant1' */
  dSPACE_Plant_X.utanklevelcontrollant1_CSTATE[0] =
    dSPACE_Plant_P.utanklevelcontrollant1_InitialC[0];
  dSPACE_Plant_X.utanklevelcontrollant1_CSTATE[1] =
    dSPACE_Plant_P.utanklevelcontrollant1_InitialC[1];
}

/* Model terminate function */
void dSPACE_Plant_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S3>/S-Function1' */

  /* write termination value of DAC for relevant output channels synchronous*/
  /*write to buffer*/
  /*release buffer*/
  aio_tp1_dac_buffer_release(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CTRL_CH1|
    AIO_TP1_DAC_CTRL_CH2);
}
