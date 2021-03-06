/* Include files */

#include "blascompat32.h"
#include "QUARC_Prog_Rover_sfun.h"
#include "c13_QUARC_Prog_Rover.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QUARC_Prog_Rover_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c13_debug_family_names[8] = { "ind_discont", "nargin",
  "nargout", "Euler", "Euler_old", "count_old", "Euler_cont", "count" };

/* Function Declarations */
static void initialize_c13_QUARC_Prog_Rover(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance);
static void initialize_params_c13_QUARC_Prog_Rover
  (SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance);
static void enable_c13_QUARC_Prog_Rover(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance);
static void disable_c13_QUARC_Prog_Rover(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance);
static void c13_update_debugger_state_c13_QUARC_Prog_Rover
  (SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance);
static void ext_mode_exec_c13_QUARC_Prog_Rover
  (SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c13_QUARC_Prog_Rover
  (SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance);
static void set_sim_state_c13_QUARC_Prog_Rover
  (SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance, const mxArray *c13_st);
static void finalize_c13_QUARC_Prog_Rover(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance);
static void sf_c13_QUARC_Prog_Rover(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance);
static void initSimStructsc13_QUARC_Prog_Rover
  (SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber);
static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static void c13_emlrt_marshallIn(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance, const mxArray *c13_count, const char_T *c13_identifier, real_T
  c13_y[3]);
static void c13_b_emlrt_marshallIn(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[3]);
static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_c_emlrt_marshallIn(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static void c13_d_emlrt_marshallIn(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  boolean_T c13_y[3]);
static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static void c13_eml_li_find(SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance,
  boolean_T c13_x[3], int32_T c13_y_data[3], int32_T c13_y_sizes[1]);
static const mxArray *c13_e_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static int32_T c13_e_emlrt_marshallIn(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static uint8_T c13_f_emlrt_marshallIn(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance, const mxArray *c13_is_active_c13_QUARC_Prog_Rover, const
  char_T *c13_identifier);
static uint8_T c13_g_emlrt_marshallIn(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void init_dsm_address_info(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c13_QUARC_Prog_Rover(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance)
{
  int32_T *c13_sfEvent;
  uint8_T *c13_is_active_c13_QUARC_Prog_Rover;
  c13_is_active_c13_QUARC_Prog_Rover = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c13_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c13_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c13_is_active_c13_QUARC_Prog_Rover = 0U;
}

static void initialize_params_c13_QUARC_Prog_Rover
  (SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance)
{
}

static void enable_c13_QUARC_Prog_Rover(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c13_QUARC_Prog_Rover(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c13_update_debugger_state_c13_QUARC_Prog_Rover
  (SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c13_QUARC_Prog_Rover
  (SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance)
{
  c13_update_debugger_state_c13_QUARC_Prog_Rover(chartInstance);
}

static const mxArray *get_sim_state_c13_QUARC_Prog_Rover
  (SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance)
{
  const mxArray *c13_st;
  const mxArray *c13_y = NULL;
  int32_T c13_i0;
  real_T c13_u[3];
  const mxArray *c13_b_y = NULL;
  int32_T c13_i1;
  real_T c13_b_u[3];
  const mxArray *c13_c_y = NULL;
  uint8_T c13_hoistedGlobal;
  uint8_T c13_c_u;
  const mxArray *c13_d_y = NULL;
  uint8_T *c13_is_active_c13_QUARC_Prog_Rover;
  real_T (*c13_count)[3];
  real_T (*c13_Euler_cont)[3];
  c13_count = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c13_Euler_cont = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c13_is_active_c13_QUARC_Prog_Rover = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c13_st = NULL;
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellarray(3), FALSE);
  for (c13_i0 = 0; c13_i0 < 3; c13_i0++) {
    c13_u[c13_i0] = (*c13_Euler_cont)[c13_i0];
  }

  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c13_y, 0, c13_b_y);
  for (c13_i1 = 0; c13_i1 < 3; c13_i1++) {
    c13_b_u[c13_i1] = (*c13_count)[c13_i1];
  }

  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", c13_b_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c13_y, 1, c13_c_y);
  c13_hoistedGlobal = *c13_is_active_c13_QUARC_Prog_Rover;
  c13_c_u = c13_hoistedGlobal;
  c13_d_y = NULL;
  sf_mex_assign(&c13_d_y, sf_mex_create("y", &c13_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c13_y, 2, c13_d_y);
  sf_mex_assign(&c13_st, c13_y, FALSE);
  return c13_st;
}

static void set_sim_state_c13_QUARC_Prog_Rover
  (SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance, const mxArray *c13_st)
{
  const mxArray *c13_u;
  real_T c13_dv0[3];
  int32_T c13_i2;
  real_T c13_dv1[3];
  int32_T c13_i3;
  boolean_T *c13_doneDoubleBufferReInit;
  uint8_T *c13_is_active_c13_QUARC_Prog_Rover;
  real_T (*c13_Euler_cont)[3];
  real_T (*c13_count)[3];
  c13_count = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c13_Euler_cont = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c13_is_active_c13_QUARC_Prog_Rover = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c13_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c13_doneDoubleBufferReInit = TRUE;
  c13_u = sf_mex_dup(c13_st);
  c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 0)),
                       "Euler_cont", c13_dv0);
  for (c13_i2 = 0; c13_i2 < 3; c13_i2++) {
    (*c13_Euler_cont)[c13_i2] = c13_dv0[c13_i2];
  }

  c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 1)),
                       "count", c13_dv1);
  for (c13_i3 = 0; c13_i3 < 3; c13_i3++) {
    (*c13_count)[c13_i3] = c13_dv1[c13_i3];
  }

  *c13_is_active_c13_QUARC_Prog_Rover = c13_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c13_u, 2)), "is_active_c13_QUARC_Prog_Rover");
  sf_mex_destroy(&c13_u);
  c13_update_debugger_state_c13_QUARC_Prog_Rover(chartInstance);
  sf_mex_destroy(&c13_st);
}

static void finalize_c13_QUARC_Prog_Rover(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance)
{
}

static void sf_c13_QUARC_Prog_Rover(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance)
{
  int32_T c13_i4;
  int32_T c13_i5;
  int32_T c13_i6;
  int32_T c13_i7;
  int32_T c13_i8;
  int32_T c13_i9;
  real_T c13_Euler[3];
  int32_T c13_i10;
  real_T c13_Euler_old[3];
  int32_T c13_i11;
  real_T c13_count_old[3];
  uint32_T c13_debug_family_var_map[8];
  boolean_T c13_ind_discont[3];
  real_T c13_nargin = 3.0;
  real_T c13_nargout = 2.0;
  real_T c13_Euler_cont[3];
  real_T c13_count[3];
  int32_T c13_i12;
  real_T c13_x[3];
  int32_T c13_k;
  real_T c13_b_k;
  real_T c13_b_x;
  real_T c13_y;
  real_T c13_b_y[3];
  int32_T c13_i13;
  int32_T c13_i14;
  int32_T c13_i15;
  boolean_T c13_b_ind_discont[3];
  int32_T c13_tmp_sizes;
  int32_T c13_tmp_data[3];
  int32_T c13_x_sizes;
  int32_T c13_loop_ub;
  int32_T c13_i16;
  real_T c13_x_data[3];
  int32_T c13_i17;
  boolean_T c13_c_ind_discont[3];
  int32_T c13_b_tmp_sizes;
  int32_T c13_b_loop_ub;
  int32_T c13_i18;
  real_T c13_b_tmp_data[3];
  int32_T c13_c_x[1];
  int32_T c13_iv0[1];
  int32_T c13_i19;
  boolean_T c13_d_ind_discont[3];
  int32_T c13_c_tmp_sizes;
  int32_T c13_c_loop_ub;
  int32_T c13_i20;
  real_T c13_c_tmp_data[3];
  int32_T c13_d_loop_ub;
  int32_T c13_i21;
  real_T c13_d0;
  int32_T c13_i22;
  int32_T c13_e_loop_ub;
  int32_T c13_c_k;
  real_T c13_d_k;
  real_T c13_d_x;
  real_T c13_e_x;
  int32_T c13_iv1[1];
  int32_T c13_f_x[1];
  int32_T c13_i23;
  boolean_T c13_e_ind_discont[3];
  int32_T c13_f_loop_ub;
  int32_T c13_i24;
  int32_T c13_i25;
  int32_T c13_i26;
  int32_T c13_i27;
  int32_T c13_i28;
  int32_T c13_i29;
  int32_T c13_i30;
  int32_T *c13_sfEvent;
  real_T (*c13_b_Euler_cont)[3];
  real_T (*c13_b_count)[3];
  real_T (*c13_b_count_old)[3];
  real_T (*c13_b_Euler_old)[3];
  real_T (*c13_b_Euler)[3];
  c13_b_count = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c13_b_Euler_cont = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c13_b_count_old = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c13_b_Euler_old = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c13_b_Euler = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c13_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 10U, *c13_sfEvent);
  for (c13_i4 = 0; c13_i4 < 3; c13_i4++) {
    _SFD_DATA_RANGE_CHECK((*c13_b_Euler)[c13_i4], 0U);
  }

  for (c13_i5 = 0; c13_i5 < 3; c13_i5++) {
    _SFD_DATA_RANGE_CHECK((*c13_b_Euler_old)[c13_i5], 1U);
  }

  for (c13_i6 = 0; c13_i6 < 3; c13_i6++) {
    _SFD_DATA_RANGE_CHECK((*c13_b_count_old)[c13_i6], 2U);
  }

  for (c13_i7 = 0; c13_i7 < 3; c13_i7++) {
    _SFD_DATA_RANGE_CHECK((*c13_b_Euler_cont)[c13_i7], 3U);
  }

  for (c13_i8 = 0; c13_i8 < 3; c13_i8++) {
    _SFD_DATA_RANGE_CHECK((*c13_b_count)[c13_i8], 4U);
  }

  *c13_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 10U, *c13_sfEvent);
  for (c13_i9 = 0; c13_i9 < 3; c13_i9++) {
    c13_Euler[c13_i9] = (*c13_b_Euler)[c13_i9];
  }

  for (c13_i10 = 0; c13_i10 < 3; c13_i10++) {
    c13_Euler_old[c13_i10] = (*c13_b_Euler_old)[c13_i10];
  }

  for (c13_i11 = 0; c13_i11 < 3; c13_i11++) {
    c13_count_old[c13_i11] = (*c13_b_count_old)[c13_i11];
  }

  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c13_debug_family_names,
    c13_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c13_ind_discont, 0U,
    c13_d_sf_marshallOut, c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_nargin, 1U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_nargout, 2U,
    c13_c_sf_marshallOut, c13_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c13_Euler, 3U, c13_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c13_Euler_old, 4U, c13_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c13_count_old, 5U, c13_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c13_Euler_cont, 6U,
    c13_sf_marshallOut, c13_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c13_count, 7U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c13_sfEvent, 4);
  for (c13_i12 = 0; c13_i12 < 3; c13_i12++) {
    c13_x[c13_i12] = c13_Euler[c13_i12] - c13_Euler_old[c13_i12];
  }

  for (c13_k = 0; c13_k < 3; c13_k++) {
    c13_b_k = 1.0 + (real_T)c13_k;
    c13_b_x = c13_x[(int32_T)c13_b_k - 1];
    c13_y = muDoubleScalarAbs(c13_b_x);
    c13_b_y[(int32_T)c13_b_k - 1] = c13_y;
  }

  for (c13_i13 = 0; c13_i13 < 3; c13_i13++) {
    c13_ind_discont[c13_i13] = (c13_b_y[c13_i13] > 6.1831853071795866);
  }

  _SFD_EML_CALL(0U, *c13_sfEvent, 6);
  for (c13_i14 = 0; c13_i14 < 3; c13_i14++) {
    c13_count[c13_i14] = c13_count_old[c13_i14];
  }

  _SFD_EML_CALL(0U, *c13_sfEvent, 7);
  for (c13_i15 = 0; c13_i15 < 3; c13_i15++) {
    c13_b_ind_discont[c13_i15] = c13_ind_discont[c13_i15];
  }

  c13_eml_li_find(chartInstance, c13_b_ind_discont, c13_tmp_data, *(int32_T (*)
    [1])&c13_tmp_sizes);
  c13_x_sizes = c13_tmp_sizes;
  c13_loop_ub = c13_tmp_sizes - 1;
  for (c13_i16 = 0; c13_i16 <= c13_loop_ub; c13_i16++) {
    c13_x_data[c13_i16] = c13_Euler[c13_tmp_data[c13_i16] - 1];
  }

  for (c13_i17 = 0; c13_i17 < 3; c13_i17++) {
    c13_c_ind_discont[c13_i17] = c13_ind_discont[c13_i17];
  }

  c13_eml_li_find(chartInstance, c13_c_ind_discont, c13_tmp_data, *(int32_T (*)
    [1])&c13_tmp_sizes);
  c13_b_tmp_sizes = c13_tmp_sizes;
  c13_b_loop_ub = c13_tmp_sizes - 1;
  for (c13_i18 = 0; c13_i18 <= c13_b_loop_ub; c13_i18++) {
    c13_b_tmp_data[c13_i18] = c13_Euler_old[c13_tmp_data[c13_i18] - 1];
  }

  c13_c_x[0] = c13_x_sizes;
  c13_iv0[0] = c13_b_tmp_sizes;
  sf_debug_size_eq_check_nd(c13_c_x, c13_iv0, 1);
  for (c13_i19 = 0; c13_i19 < 3; c13_i19++) {
    c13_d_ind_discont[c13_i19] = c13_ind_discont[c13_i19];
  }

  c13_eml_li_find(chartInstance, c13_d_ind_discont, c13_tmp_data, *(int32_T (*)
    [1])&c13_tmp_sizes);
  c13_c_tmp_sizes = c13_tmp_sizes;
  c13_c_loop_ub = c13_tmp_sizes - 1;
  for (c13_i20 = 0; c13_i20 <= c13_c_loop_ub; c13_i20++) {
    c13_c_tmp_data[c13_i20] = c13_count[c13_tmp_data[c13_i20] - 1];
  }

  c13_x_sizes;
  c13_d_loop_ub = c13_x_sizes - 1;
  for (c13_i21 = 0; c13_i21 <= c13_d_loop_ub; c13_i21++) {
    c13_x_data[c13_i21] -= c13_b_tmp_data[c13_i21];
  }

  c13_d0 = (real_T)c13_x_sizes;
  c13_i22 = (int32_T)c13_d0 - 1;
  c13_e_loop_ub = c13_i22;
  for (c13_c_k = 0; c13_c_k <= c13_e_loop_ub; c13_c_k++) {
    c13_d_k = 1.0 + (real_T)c13_c_k;
    c13_d_x = c13_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)c13_d_k, 1,
      c13_x_sizes, 1, 0) - 1];
    c13_e_x = c13_d_x;
    if (c13_e_x > 0.0) {
      c13_e_x = 1.0;
    } else if (c13_e_x < 0.0) {
      c13_e_x = -1.0;
    } else {
      if (c13_e_x == 0.0) {
        c13_e_x = 0.0;
      }
    }

    c13_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)c13_d_k, 1, c13_x_sizes,
      1, 0) - 1] = c13_e_x;
  }

  c13_iv1[0] = c13_c_tmp_sizes;
  c13_f_x[0] = c13_x_sizes;
  sf_debug_size_eq_check_nd(c13_iv1, c13_f_x, 1);
  for (c13_i23 = 0; c13_i23 < 3; c13_i23++) {
    c13_e_ind_discont[c13_i23] = c13_ind_discont[c13_i23];
  }

  c13_eml_li_find(chartInstance, c13_e_ind_discont, c13_tmp_data, *(int32_T (*)
    [1])&c13_tmp_sizes);
  sf_debug_size_eq_check_1d(c13_tmp_sizes, c13_c_tmp_sizes);
  c13_f_loop_ub = c13_c_tmp_sizes - 1;
  for (c13_i24 = 0; c13_i24 <= c13_f_loop_ub; c13_i24++) {
    c13_count[c13_tmp_data[c13_i24] - 1] = c13_c_tmp_data[c13_i24] -
      c13_x_data[c13_i24];
  }

  _SFD_EML_CALL(0U, *c13_sfEvent, 9);
  for (c13_i25 = 0; c13_i25 < 3; c13_i25++) {
    c13_x[c13_i25] = c13_count[c13_i25];
  }

  for (c13_i26 = 0; c13_i26 < 3; c13_i26++) {
    c13_x[c13_i26] *= 2.0;
  }

  for (c13_i27 = 0; c13_i27 < 3; c13_i27++) {
    c13_x[c13_i27] *= 3.1415926535897931;
  }

  for (c13_i28 = 0; c13_i28 < 3; c13_i28++) {
    c13_Euler_cont[c13_i28] = c13_Euler[c13_i28] + c13_x[c13_i28];
  }

  _SFD_EML_CALL(0U, *c13_sfEvent, -9);
  sf_debug_symbol_scope_pop();
  for (c13_i29 = 0; c13_i29 < 3; c13_i29++) {
    (*c13_b_Euler_cont)[c13_i29] = c13_Euler_cont[c13_i29];
  }

  for (c13_i30 = 0; c13_i30 < 3; c13_i30++) {
    (*c13_b_count)[c13_i30] = c13_count[c13_i30];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, *c13_sfEvent);
  sf_debug_check_for_state_inconsistency(_QUARC_Prog_RoverMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc13_QUARC_Prog_Rover
  (SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber)
{
}

static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i31;
  real_T c13_b_inData[3];
  int32_T c13_i32;
  real_T c13_u[3];
  const mxArray *c13_y = NULL;
  SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance;
  chartInstance = (SFc13_QUARC_Prog_RoverInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  for (c13_i31 = 0; c13_i31 < 3; c13_i31++) {
    c13_b_inData[c13_i31] = (*(real_T (*)[3])c13_inData)[c13_i31];
  }

  for (c13_i32 = 0; c13_i32 < 3; c13_i32++) {
    c13_u[c13_i32] = c13_b_inData[c13_i32];
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static void c13_emlrt_marshallIn(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance, const mxArray *c13_count, const char_T *c13_identifier, real_T
  c13_y[3])
{
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_count), &c13_thisId,
    c13_y);
  sf_mex_destroy(&c13_count);
}

static void c13_b_emlrt_marshallIn(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[3])
{
  real_T c13_dv2[3];
  int32_T c13_i33;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c13_i33 = 0; c13_i33 < 3; c13_i33++) {
    c13_y[c13_i33] = c13_dv2[c13_i33];
  }

  sf_mex_destroy(&c13_u);
}

static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_count;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y[3];
  int32_T c13_i34;
  SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance;
  chartInstance = (SFc13_QUARC_Prog_RoverInstanceStruct *)chartInstanceVoid;
  c13_count = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_count), &c13_thisId,
    c13_y);
  sf_mex_destroy(&c13_count);
  for (c13_i34 = 0; c13_i34 < 3; c13_i34++) {
    (*(real_T (*)[3])c13_outData)[c13_i34] = c13_y[c13_i34];
  }

  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i35;
  real_T c13_b_inData[3];
  int32_T c13_i36;
  real_T c13_u[3];
  const mxArray *c13_y = NULL;
  SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance;
  chartInstance = (SFc13_QUARC_Prog_RoverInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  for (c13_i35 = 0; c13_i35 < 3; c13_i35++) {
    c13_b_inData[c13_i35] = (*(real_T (*)[3])c13_inData)[c13_i35];
  }

  for (c13_i36 = 0; c13_i36 < 3; c13_i36++) {
    c13_u[c13_i36] = c13_b_inData[c13_i36];
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 2, 3, 1), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance;
  chartInstance = (SFc13_QUARC_Prog_RoverInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static real_T c13_c_emlrt_marshallIn(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d1;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d1, 1, 0, 0U, 0, 0U, 0);
  c13_y = c13_d1;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_nargout;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance;
  chartInstance = (SFc13_QUARC_Prog_RoverInstanceStruct *)chartInstanceVoid;
  c13_nargout = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_nargout),
    &c13_thisId);
  sf_mex_destroy(&c13_nargout);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i37;
  boolean_T c13_b_inData[3];
  int32_T c13_i38;
  boolean_T c13_u[3];
  const mxArray *c13_y = NULL;
  SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance;
  chartInstance = (SFc13_QUARC_Prog_RoverInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  for (c13_i37 = 0; c13_i37 < 3; c13_i37++) {
    c13_b_inData[c13_i37] = (*(boolean_T (*)[3])c13_inData)[c13_i37];
  }

  for (c13_i38 = 0; c13_i38 < 3; c13_i38++) {
    c13_u[c13_i38] = c13_b_inData[c13_i38];
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 11, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static void c13_d_emlrt_marshallIn(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  boolean_T c13_y[3])
{
  boolean_T c13_bv0[3];
  int32_T c13_i39;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_bv0, 1, 11, 0U, 1, 0U, 1, 3);
  for (c13_i39 = 0; c13_i39 < 3; c13_i39++) {
    c13_y[c13_i39] = c13_bv0[c13_i39];
  }

  sf_mex_destroy(&c13_u);
}

static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_ind_discont;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  boolean_T c13_y[3];
  int32_T c13_i40;
  SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance;
  chartInstance = (SFc13_QUARC_Prog_RoverInstanceStruct *)chartInstanceVoid;
  c13_ind_discont = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_ind_discont), &c13_thisId,
    c13_y);
  sf_mex_destroy(&c13_ind_discont);
  for (c13_i40 = 0; c13_i40 < 3; c13_i40++) {
    (*(boolean_T (*)[3])c13_outData)[c13_i40] = c13_y[c13_i40];
  }

  sf_mex_destroy(&c13_mxArrayInData);
}

const mxArray *sf_c13_QUARC_Prog_Rover_get_eml_resolved_functions_info(void)
{
  const mxArray *c13_nameCaptureInfo;
  c13_ResolvedFunctionInfo c13_info[8];
  c13_ResolvedFunctionInfo (*c13_b_info)[8];
  const mxArray *c13_m0 = NULL;
  int32_T c13_i41;
  c13_ResolvedFunctionInfo *c13_r0;
  c13_nameCaptureInfo = NULL;
  c13_nameCaptureInfo = NULL;
  c13_b_info = (c13_ResolvedFunctionInfo (*)[8])c13_info;
  (*c13_b_info)[0].context = "";
  (*c13_b_info)[0].name = "abs";
  (*c13_b_info)[0].dominantType = "double";
  (*c13_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c13_b_info)[0].fileTimeLo = 1286818694U;
  (*c13_b_info)[0].fileTimeHi = 0U;
  (*c13_b_info)[0].mFileTimeLo = 0U;
  (*c13_b_info)[0].mFileTimeHi = 0U;
  (*c13_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c13_b_info)[1].name = "eml_scalar_abs";
  (*c13_b_info)[1].dominantType = "double";
  (*c13_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  (*c13_b_info)[1].fileTimeLo = 1286818712U;
  (*c13_b_info)[1].fileTimeHi = 0U;
  (*c13_b_info)[1].mFileTimeLo = 0U;
  (*c13_b_info)[1].mFileTimeHi = 0U;
  (*c13_b_info)[2].context = "";
  (*c13_b_info)[2].name = "mtimes";
  (*c13_b_info)[2].dominantType = "double";
  (*c13_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c13_b_info)[2].fileTimeLo = 1289519692U;
  (*c13_b_info)[2].fileTimeHi = 0U;
  (*c13_b_info)[2].mFileTimeLo = 0U;
  (*c13_b_info)[2].mFileTimeHi = 0U;
  (*c13_b_info)[3].context = "";
  (*c13_b_info)[3].name = "eml_li_find";
  (*c13_b_info)[3].dominantType = "";
  (*c13_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  (*c13_b_info)[3].fileTimeLo = 1286818786U;
  (*c13_b_info)[3].fileTimeHi = 0U;
  (*c13_b_info)[3].mFileTimeLo = 0U;
  (*c13_b_info)[3].mFileTimeHi = 0U;
  (*c13_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  (*c13_b_info)[4].name = "eml_index_class";
  (*c13_b_info)[4].dominantType = "";
  (*c13_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c13_b_info)[4].fileTimeLo = 1286818778U;
  (*c13_b_info)[4].fileTimeHi = 0U;
  (*c13_b_info)[4].mFileTimeLo = 0U;
  (*c13_b_info)[4].mFileTimeHi = 0U;
  (*c13_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones";
  (*c13_b_info)[5].name = "eml_index_plus";
  (*c13_b_info)[5].dominantType = "int32";
  (*c13_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  (*c13_b_info)[5].fileTimeLo = 1286818778U;
  (*c13_b_info)[5].fileTimeHi = 0U;
  (*c13_b_info)[5].mFileTimeLo = 0U;
  (*c13_b_info)[5].mFileTimeHi = 0U;
  (*c13_b_info)[6].context = "";
  (*c13_b_info)[6].name = "sign";
  (*c13_b_info)[6].dominantType = "double";
  (*c13_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  (*c13_b_info)[6].fileTimeLo = 1286818750U;
  (*c13_b_info)[6].fileTimeHi = 0U;
  (*c13_b_info)[6].mFileTimeLo = 0U;
  (*c13_b_info)[6].mFileTimeHi = 0U;
  (*c13_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  (*c13_b_info)[7].name = "eml_scalar_sign";
  (*c13_b_info)[7].dominantType = "double";
  (*c13_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  (*c13_b_info)[7].fileTimeLo = 1286818736U;
  (*c13_b_info)[7].fileTimeHi = 0U;
  (*c13_b_info)[7].mFileTimeLo = 0U;
  (*c13_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c13_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8), FALSE);
  for (c13_i41 = 0; c13_i41 < 8; c13_i41++) {
    c13_r0 = &c13_info[c13_i41];
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c13_r0->context)), "context", "nameCaptureInfo",
                    c13_i41);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c13_r0->name)), "name", "nameCaptureInfo",
                    c13_i41);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo",
      c13_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c13_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c13_i41);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c13_r0->resolved)), "resolved",
                    "nameCaptureInfo", c13_i41);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", &c13_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c13_i41);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", &c13_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c13_i41);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo",
      &c13_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c13_i41);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo",
      &c13_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c13_i41);
  }

  sf_mex_assign(&c13_nameCaptureInfo, c13_m0, FALSE);
  return c13_nameCaptureInfo;
}

static void c13_eml_li_find(SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance,
  boolean_T c13_x[3], int32_T c13_y_data[3], int32_T c13_y_sizes[1])
{
  int32_T c13_k;
  int32_T c13_i;
  int32_T c13_b_i;
  int32_T c13_a;
  const mxArray *c13_y = NULL;
  int32_T c13_tmp_sizes;
  int32_T c13_loop_ub;
  int32_T c13_i42;
  int32_T c13_tmp_data[3];
  int32_T c13_j;
  int32_T c13_c_i;
  int32_T c13_d_i;
  int32_T c13_b_a;
  c13_k = 0;
  for (c13_i = 1; c13_i < 4; c13_i++) {
    c13_b_i = c13_i - 1;
    if (c13_x[c13_b_i]) {
      c13_a = c13_k + 1;
      c13_k = c13_a;
    }
  }

  if (c13_k <= 3) {
  } else {
    c13_y = NULL;
    sf_mex_assign(&c13_y, sf_mex_create("y", "Assertion failed.", 15, 0U, 0U, 0U,
      2, 1, strlen("Assertion failed.")), FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, c13_y);
  }

  c13_tmp_sizes = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c13_k);
  c13_loop_ub = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c13_k) - 1;
  for (c13_i42 = 0; c13_i42 <= c13_loop_ub; c13_i42++) {
    c13_tmp_data[c13_i42] = 0;
  }

  c13_y_sizes[0] = c13_tmp_sizes;
  c13_j = 1;
  for (c13_c_i = 1; c13_c_i < 4; c13_c_i++) {
    c13_d_i = c13_c_i;
    if (c13_x[c13_d_i - 1]) {
      c13_y_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c13_j, 1, c13_y_sizes[0], 1, 0)
        - 1] = c13_d_i;
      c13_b_a = c13_j + 1;
      c13_j = c13_b_a;
    }
  }
}

static const mxArray *c13_e_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance;
  chartInstance = (SFc13_QUARC_Prog_RoverInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(int32_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static int32_T c13_e_emlrt_marshallIn(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  int32_T c13_y;
  int32_T c13_i43;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_i43, 1, 6, 0U, 0, 0U, 0);
  c13_y = c13_i43;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_sfEvent;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  int32_T c13_y;
  SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance;
  chartInstance = (SFc13_QUARC_Prog_RoverInstanceStruct *)chartInstanceVoid;
  c13_sfEvent = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_sfEvent),
    &c13_thisId);
  sf_mex_destroy(&c13_sfEvent);
  *(int32_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static uint8_T c13_f_emlrt_marshallIn(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance, const mxArray *c13_is_active_c13_QUARC_Prog_Rover, const
  char_T *c13_identifier)
{
  uint8_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_is_active_c13_QUARC_Prog_Rover), &c13_thisId);
  sf_mex_destroy(&c13_is_active_c13_QUARC_Prog_Rover);
  return c13_y;
}

static uint8_T c13_g_emlrt_marshallIn(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  uint8_T c13_y;
  uint8_T c13_u0;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_u0, 1, 3, 0U, 0, 0U, 0);
  c13_y = c13_u0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void init_dsm_address_info(SFc13_QUARC_Prog_RoverInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c13_QUARC_Prog_Rover_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(551804787U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2394181291U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(950008342U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2788188940U);
}

mxArray *sf_c13_QUARC_Prog_Rover_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("PO3A0kb20TajMPKqBrR9YH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c13_QUARC_Prog_Rover(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[26],T\"Euler_cont\",},{M[1],M[27],T\"count\",},{M[8],M[0],T\"is_active_c13_QUARC_Prog_Rover\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_QUARC_Prog_Rover_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance;
    chartInstance = (SFc13_QUARC_Prog_RoverInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_QUARC_Prog_RoverMachineNumber_,
           13,
           1,
           1,
           5,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_QUARC_Prog_RoverMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_QUARC_Prog_RoverMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_QUARC_Prog_RoverMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Euler");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Euler_old");
          _SFD_SET_DATA_PROPS(2,1,1,0,"count_old");
          _SFD_SET_DATA_PROPS(3,2,0,1,"Euler_cont");
          _SFD_SET_DATA_PROPS(4,2,0,1,"count");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,295);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)
            c13_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)
            c13_sf_marshallIn);
        }

        {
          real_T (*c13_Euler)[3];
          real_T (*c13_Euler_old)[3];
          real_T (*c13_count_old)[3];
          real_T (*c13_Euler_cont)[3];
          real_T (*c13_count)[3];
          c13_count = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c13_Euler_cont = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S,
            1);
          c13_count_old = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S,
            2);
          c13_Euler_old = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S,
            1);
          c13_Euler = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c13_Euler);
          _SFD_SET_DATA_VALUE_PTR(1U, *c13_Euler_old);
          _SFD_SET_DATA_VALUE_PTR(2U, *c13_count_old);
          _SFD_SET_DATA_VALUE_PTR(3U, *c13_Euler_cont);
          _SFD_SET_DATA_VALUE_PTR(4U, *c13_count);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_QUARC_Prog_RoverMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_QUARC_Prog_Rover_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S, infoStruct,
      13, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c13_QUARC_Prog_Rover(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc13_QUARC_Prog_RoverInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc13_QUARC_Prog_RoverInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c13_QUARC_Prog_Rover((SFc13_QUARC_Prog_RoverInstanceStruct*)
    chartInstanceVar);
  initialize_c13_QUARC_Prog_Rover((SFc13_QUARC_Prog_RoverInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c13_QUARC_Prog_Rover(void *chartInstanceVar)
{
  enable_c13_QUARC_Prog_Rover((SFc13_QUARC_Prog_RoverInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c13_QUARC_Prog_Rover(void *chartInstanceVar)
{
  disable_c13_QUARC_Prog_Rover((SFc13_QUARC_Prog_RoverInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c13_QUARC_Prog_Rover(void *chartInstanceVar)
{
  sf_c13_QUARC_Prog_Rover((SFc13_QUARC_Prog_RoverInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c13_QUARC_Prog_Rover(void *chartInstanceVar)
{
  ext_mode_exec_c13_QUARC_Prog_Rover((SFc13_QUARC_Prog_RoverInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c13_QUARC_Prog_Rover(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c13_QUARC_Prog_Rover
    ((SFc13_QUARC_Prog_RoverInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_QUARC_Prog_Rover();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c13_QUARC_Prog_Rover(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_QUARC_Prog_Rover();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c13_QUARC_Prog_Rover((SFc13_QUARC_Prog_RoverInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c13_QUARC_Prog_Rover(SimStruct* S)
{
  return sf_internal_get_sim_state_c13_QUARC_Prog_Rover(S);
}

static void sf_opaque_set_sim_state_c13_QUARC_Prog_Rover(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c13_QUARC_Prog_Rover(S, st);
}

static void sf_opaque_terminate_c13_QUARC_Prog_Rover(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc13_QUARC_Prog_RoverInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c13_QUARC_Prog_Rover((SFc13_QUARC_Prog_RoverInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_QUARC_Prog_Rover_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc13_QUARC_Prog_Rover((SFc13_QUARC_Prog_RoverInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_QUARC_Prog_Rover(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c13_QUARC_Prog_Rover((SFc13_QUARC_Prog_RoverInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c13_QUARC_Prog_Rover_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c13_QUARC_Prog_Rover\",T\"is_active_c13_QUARC_Prog_Rover\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x4'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"int32\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 4, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 3851270630U, 3363230343U, 1651207761U,
    946165807U };

  return checksum;
}

static void mdlSetWorkWidths_c13_QUARC_Prog_Rover(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QUARC_Prog_Rover_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,13);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,13,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,13,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,13,3);
      sf_mark_chart_reusable_outputs(S,infoStruct,13,2);
    }

    sf_set_rtw_dwork_info(S,infoStruct,13);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3604165521U));
  ssSetChecksum1(S,(529901885U));
  ssSetChecksum2(S,(1959095957U));
  ssSetChecksum3(S,(1998941548U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c13_QUARC_Prog_Rover(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c13_QUARC_Prog_Rover(SimStruct *S)
{
  SFc13_QUARC_Prog_RoverInstanceStruct *chartInstance;
  chartInstance = (SFc13_QUARC_Prog_RoverInstanceStruct *)malloc(sizeof
    (SFc13_QUARC_Prog_RoverInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc13_QUARC_Prog_RoverInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c13_QUARC_Prog_Rover;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c13_QUARC_Prog_Rover;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c13_QUARC_Prog_Rover;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c13_QUARC_Prog_Rover;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c13_QUARC_Prog_Rover;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c13_QUARC_Prog_Rover;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c13_QUARC_Prog_Rover;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c13_QUARC_Prog_Rover;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c13_QUARC_Prog_Rover;
  chartInstance->chartInfo.mdlStart = mdlStart_c13_QUARC_Prog_Rover;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c13_QUARC_Prog_Rover;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c13_QUARC_Prog_Rover;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c13_QUARC_Prog_Rover_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c13_QUARC_Prog_Rover(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_QUARC_Prog_Rover(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_QUARC_Prog_Rover(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_QUARC_Prog_Rover_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
