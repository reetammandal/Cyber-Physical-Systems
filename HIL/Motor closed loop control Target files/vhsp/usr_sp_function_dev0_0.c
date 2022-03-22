// generated using template: cop_main.template---------------------------------------------
/******************************************************************************************
**
**  Module Name: cop_main.c
**  NOTE: Automatically generated file. DO NOT MODIFY!
**  Description:
**            Main file
**
******************************************************************************************/
// generated using template: arm/custom_include.template-----------------------------------

#ifdef __cplusplus
#include <limits>

extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <complex.h>

// x86 libraries:
#include "../include/sp_functions_dev0.h"

#ifdef __cplusplus
}
#endif

// H files from Advanced C Function components

// Header files from additional sources (Advanced C Function)

// ----------------------------------------------------------------------------------------
// generated using template: VirtualHIL/custom_defines.template----------------------------

typedef unsigned char X_UnInt8;
typedef char X_Int8;
typedef signed short X_Int16;
typedef unsigned short X_UnInt16;
typedef int X_Int32;
typedef unsigned int X_UnInt32;
typedef unsigned int uint;
typedef double real;

// ----------------------------------------------------------------------------------------
// generated using template: custom_consts.template----------------------------------------

// arithmetic constants
#define C_SQRT_2                    1.4142135623730950488016887242097f
#define C_SQRT_3                    1.7320508075688772935274463415059f
#define C_PI                        3.1415926535897932384626433832795f
#define C_E                         2.7182818284590452353602874713527f
#define C_2PI                       6.283185307179586476925286766559f

//@cmp.def.start
//component defines




























//@cmp.def.end

//#define SP_SCOPE_FILE_DEBUG
#define SP_SCOPE_BUFF_SIZE (4194304*4)
#define SP_SCOPE_BUFF_SIZE_PER_ER (SP_SCOPE_BUFF_SIZE/4)

//-----------------------------------------------------------------------------------------
// generated using template: common_variables.template-------------------------------------
// true global variables

extern X_UnInt8* sp_scope_buffer_dev0;
extern FILE* f_sp_scope_debug;
uint64_t sp_scope_buff_addr_cpu0_er0_dev0;
uint64_t sp_scope_buff_start_addr_cpu0_er0_dev0;
uint32_t sp_scope_buff_index_cpu0_er0_dev0;

//@cmp.var.start
// variables
double _dc_machine1_machine_wrapper1__out[2];

double _enable__out;
double _im_load__out;
X_Int32 _load_sel__out;
double _saw_load__out;
double _speed_rpm__out;
double _square_load__out;
double _triangular_load__out;
double _machine_3_sp_outputs_machine_3sp_outputs__out;
double _machine_3_sp_outputs_machine_3sp_outputs__out1;
float _enable_1__tmp;
double _rpm_to_w_elec__out;
double _mux__out;
double _to_rpm__out;
float _torque__in;
double _w_meh_to_w_elec__out;
double _gain6__out;
float _speed__in;
double _sum3__out;
double _product6__out;
double _pi_controller__out;
double _pi_controller__pi_reg_out_int;
double _vf_ratio__out;
double _limit1__out;
double _product2__out;
double _bus_join1__out;
X_UnInt32 _buck1_pwm_modulator__channels[1] = {0};
double _buck1_pwm_modulator__limited_in[1];
X_UnInt32 _buck1_pwm_modulator__update_mask;
X_UnInt32 _buck1_pwm_modulator__sig_dir[1];

//@cmp.var.end

//@cmp.svar.start
// state variables
double _dc_machine1_machine_wrapper1__model_load;
double _saw_load__current_phase;
double _square_load__current_phase;
double _triangular_load__current_phase;
double _pi_controller__integrator_state;
X_UnInt32 _pi_controller__av_active;
double _pi_controller__filter_state;//@cmp.svar.end

//
// Tunable parameters
//
static struct Tunable_params {
} __attribute__((__packed__)) tunable_params;

void *tunable_params_dev0_cpu0_ptr = &tunable_params;





// generated using template: virtual_hil/custom_functions.template---------------------------------
void ReInit_user_sp_cpu0_dev0() {
#if DEBUG_MODE
    printf("\n\rReInitTimer");
#endif
    //@cmp.init.block.start
    _dc_machine1_machine_wrapper1__model_load = 0.0;
    _saw_load__current_phase = 0.0;
    _square_load__current_phase = 0.0;
    _triangular_load__current_phase = 0.0;
    sp_scope_buff_index_cpu0_er0_dev0 = 0;
    HIL_OutAO(0x2001, 0.0f);
    sp_scope_buff_index_cpu0_er0_dev0 = 0;
    HIL_OutAO(0x2000, 0.0f);
    sp_scope_buff_index_cpu0_er0_dev0 = 0;
    _pi_controller__integrator_state =  0.0;
    _pi_controller__filter_state =  0.0;
    HIL_OutAO(0x2002, 0.0f);
    sp_scope_buff_index_cpu0_er0_dev0 = 0;
    HIL_OutAO(0x2003, 0.0f);
    sp_scope_buff_index_cpu0_er0_dev0 = 0;
    HIL_OutAO(0x2004, 0.0f);
    sp_scope_buff_index_cpu0_er0_dev0 = 0;
    _buck1_pwm_modulator__update_mask = 1;
    HIL_OutInt32(0x2000080 + _buck1_pwm_modulator__channels[0], 20000);// divide by 2 is already implemented in hw
    HIL_OutInt32(0x20000c0 + _buck1_pwm_modulator__channels[0], 800);
    HIL_OutInt32(0x20001c0 + _buck1_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000200 + _buck1_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000240 + _buck1_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000300 + _buck1_pwm_modulator__channels[0], 2);
    HIL_OutInt32(0x2000140, _buck1_pwm_modulator__update_mask);
    //@cmp.init.block.end
}

void ReInit_sp_scope_user_sp_cpu0_dev0() {
    // initialise SP Scope buffer pointer
    sp_scope_buff_index_cpu0_er0_dev0 = 0;
    sp_scope_buff_start_addr_cpu0_er0_dev0 = (uint64_t)sp_scope_buffer_dev0 + 0 * SP_SCOPE_BUFF_SIZE + 0 * SP_SCOPE_BUFF_SIZE_PER_ER;
}

void load_fmi_libraries_user_sp_cpu0_dev0(void) {
#if defined(_WIN64)
#else
#endif
}
// generated using template:generic_macros.template-----------------------------------------
/*********************** Macros (Inline Functions) Definitions ***************************/

// ----------------------------------------------------------------------------------------

#ifndef MAX
#define MAX(value, limit) (((value) > (limit)) ? (value) : (limit))
#endif
#ifndef MIN
#define MIN(value, limit) (((value) < (limit)) ? (value) : (limit))
#endif

// generated using template: common_timer_counter_handler.template-------------------------

/*****************************************************************************************/
/**
* This function is the handler which performs processing for the timer counter.
* It is called from an interrupt context such that the amount of processing
* performed should be minimized.  It is called when the timer counter expires
* if interrupts are enabled.
*
*
* @param    None
*
* @return   None
*
* @note     None
*
*****************************************************************************************/

void TimerCounterHandler_0_user_sp_cpu0_dev0() {
#if DEBUG_MODE
    printf("\n\rTimerCounterHandler_0");
#endif
    //////////////////////////////////////////////////////////////////////////
    // Set tunable parameters
    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    // Output block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.out.block.start
    // Generated from the component: DC Machine1.Machine Wrapper1
    HIL_OutFloat((0x800000 + 0x40000 * 0x0 + 0x18),  _dc_machine1_machine_wrapper1__model_load);
    _dc_machine1_machine_wrapper1__out[0] = HIL_InFloat(0xc80000 + 16392);
    _dc_machine1_machine_wrapper1__out[1] = HIL_InFloat(0xc80000 + 16394);
    // Generated from the component: Enable
    _enable__out = XIo_InFloat(0x55000100);
    // Generated from the component: IM_Load
    _im_load__out = XIo_InFloat(0x55000104);
    // Generated from the component: Load_sel
    _load_sel__out = XIo_InInt32(0x55000108);
    // Generated from the component: Saw load
    if (_saw_load__current_phase < 1.0) {
        _saw_load__out = 0.0 + (((1.0) - (0.0)) * (_saw_load__current_phase / 1.0));
    } else {
        _saw_load__out = 1.0 - (((1.0) - (0.0)) * ((_saw_load__current_phase - 1.0) / (1.0f - 1.0)));
    }
    // Generated from the component: Speed RPM
    _speed_rpm__out = XIo_InFloat(0x5500010c);
    // Generated from the component: Square load
    if (_square_load__current_phase < 0.5) {
        _square_load__out = 1.0;
    } else {
        _square_load__out = 0.0;
    }
    // Generated from the component: Triangular load
    if (_triangular_load__current_phase < 0.5) {
        _triangular_load__out = 0.0 + (((1.0) - (0.0)) * (_triangular_load__current_phase / 0.5));
    } else {
        _triangular_load__out = 1.0 - (((1.0) - (0.0)) * ((_triangular_load__current_phase - 0.5) / (1.0f - 0.5)));
    }
    // Generated from the component: machine 3_sp_outputs.machine 3sp_outputs
    _machine_3_sp_outputs_machine_3sp_outputs__out = _dc_machine1_machine_wrapper1__out[0];
    _machine_3_sp_outputs_machine_3sp_outputs__out1 = _dc_machine1_machine_wrapper1__out[1];
    // Generated from the component: enable
    HIL_OutInt32(0xf00400, _enable__out != 0x0);
    // Generated from the component: rpm_to_w_elec
    _rpm_to_w_elec__out = 0.20943951023931953 * _speed_rpm__out;
    // Generated from the component: Mux
    switch((X_UnInt32) _load_sel__out) {
    case 1:
        _mux__out = _im_load__out;
        break;
    case 2:
        _mux__out = _triangular_load__out;
        break;
    case 3:
        _mux__out = _saw_load__out;
        break;
    case 4:
        _mux__out = _square_load__out;
        break;
    default:
        _mux__out = 0x0;
    }
    // Generated from the component: To rpm
    _to_rpm__out = 9.549296585513721 * _machine_3_sp_outputs_machine_3sp_outputs__out1;
    // Generated from the component: Torque
    HIL_OutAO(0x2001, (float)_machine_3_sp_outputs_machine_3sp_outputs__out);
    _torque__in = _machine_3_sp_outputs_machine_3sp_outputs__out;
    sp_scope_buff_addr_cpu0_er0_dev0 = sp_scope_buff_start_addr_cpu0_er0_dev0 + sp_scope_buff_index_cpu0_er0_dev0;
    //#ifdef SP_SCOPE_FILE_DEBUG
    //  fprintf(f_sp_scope_debug, "\nstart = %x, index = %x, addr = %x, value = %f.", sp_scope_buff_start_addr_cpu0_er0_dev0, sp_scope_buff_index_cpuuser_sp_cpu}_cpu0_er0_dev0, sp_scope_buff_addr_cpu0_er0_dev0, _torque__in);
    //#endif
    memcpy((X_UnInt8 *)sp_scope_buff_addr_cpu0_er0_dev0, &_torque__in, 4);
    //printf("\n\sp_scope_buff_addr_cpu0_er0_dev0, _torque__in 0x%x\r\n", sp_scope_buff_addr_cpu0_er0_dev0);
    //printf("\n\r addr 0x%x, value 0x%x\r\n", sp_scope_buff_addr_cpu0_er0_dev0, *(X_UnInt32*)(sp_scope_buff_addr_cpu0_er0_dev0));
    //XIo_OutInt32(sp_scope_buff_addr_cpu0_er0_dev0, _torque__in);
    sp_scope_buff_index_cpu0_er0_dev0 = (sp_scope_buff_index_cpu0_er0_dev0 + 4) % SP_SCOPE_BUFF_SIZE_PER_ER;
    // Generated from the component: w_meh_to_w_elec
    _w_meh_to_w_elec__out = 2.0 * _machine_3_sp_outputs_machine_3sp_outputs__out1;
    // Generated from the component: Gain6
    _gain6__out = 4.0 * _mux__out;
    // Generated from the component: Speed
    HIL_OutAO(0x2000, (float)_to_rpm__out);
    _speed__in = _to_rpm__out;
    sp_scope_buff_addr_cpu0_er0_dev0 = sp_scope_buff_start_addr_cpu0_er0_dev0 + sp_scope_buff_index_cpu0_er0_dev0;
    //#ifdef SP_SCOPE_FILE_DEBUG
    //  fprintf(f_sp_scope_debug, "\nstart = %x, index = %x, addr = %x, value = %f.", sp_scope_buff_start_addr_cpu0_er0_dev0, sp_scope_buff_index_cpuuser_sp_cpu}_cpu0_er0_dev0, sp_scope_buff_addr_cpu0_er0_dev0, _speed__in);
    //#endif
    memcpy((X_UnInt8 *)sp_scope_buff_addr_cpu0_er0_dev0, &_speed__in, 4);
    //printf("\n\sp_scope_buff_addr_cpu0_er0_dev0, _speed__in 0x%x\r\n", sp_scope_buff_addr_cpu0_er0_dev0);
    //printf("\n\r addr 0x%x, value 0x%x\r\n", sp_scope_buff_addr_cpu0_er0_dev0, *(X_UnInt32*)(sp_scope_buff_addr_cpu0_er0_dev0));
    //XIo_OutInt32(sp_scope_buff_addr_cpu0_er0_dev0, _speed__in);
    sp_scope_buff_index_cpu0_er0_dev0 = (sp_scope_buff_index_cpu0_er0_dev0 + 4) % SP_SCOPE_BUFF_SIZE_PER_ER;
    // Generated from the component: Sum3
    _sum3__out = _rpm_to_w_elec__out - _w_meh_to_w_elec__out;
    // Generated from the component: Product6
    _product6__out = (_enable__out * _sum3__out);
    // Generated from the component: PI controller
    _pi_controller__pi_reg_out_int = _pi_controller__integrator_state + 0.9 * _product6__out;
    if (_pi_controller__pi_reg_out_int < -550.0)
        _pi_controller__av_active = 1;
    else if (_pi_controller__pi_reg_out_int > 550.0)
        _pi_controller__av_active = 1;
    else
        _pi_controller__av_active = 0;
    _pi_controller__out = MIN(MAX(_pi_controller__pi_reg_out_int, -550.0), 550.0);
    // Generated from the component: VF ratio
    _vf_ratio__out = 0.0031830988618379067 * _pi_controller__out;
    // Generated from the component: int_out
    HIL_OutAO(0x2002, (float)_pi_controller__out);
    // Generated from the component: sin_out1
    HIL_OutAO(0x2003, (float)_pi_controller__out);
    // Generated from the component: Limit1
    _limit1__out = MIN(MAX(_vf_ratio__out, 0.0), 1.0);
    // Generated from the component: Product2
    _product2__out = (_pi_controller__out * _limit1__out);
    // Generated from the component: voltage_pu
    HIL_OutAO(0x2004, (float)_limit1__out);
    // Generated from the component: Bus Join1
    _bus_join1__out = _product2__out;
    // Generated from the component: Buck1.PWM_Modulator
    _buck1_pwm_modulator__limited_in[0] = MIN(MAX(_bus_join1__out, -1.0), 1.0);
    HIL_OutInt32(0x2000040 + _buck1_pwm_modulator__channels[0], ((unsigned)((_buck1_pwm_modulator__limited_in[0] - (-1.0)) * 10000.0)));
    if (_enable__out == 0x0) {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _buck1_pwm_modulator__channels[0], 0x0);
    }
    else {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _buck1_pwm_modulator__channels[0], 0x1);
    }
    HIL_OutInt32(0x2000140, _buck1_pwm_modulator__update_mask);
    //@cmp.out.block.end
    //////////////////////////////////////////////////////////////////////////
    // Update block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.update.block.start
    // Generated from the component: DC Machine1.Machine Wrapper1
    _dc_machine1_machine_wrapper1__model_load = _gain6__out;
    // Generated from the component: Saw load
    _saw_load__current_phase += 0.5 * 0.0001;
    if (_saw_load__current_phase >= 1.0f) {
        _saw_load__current_phase -= 1.0f;
    }
    // Generated from the component: Square load
    _square_load__current_phase += 0.5 * 0.0001;
    if (_square_load__current_phase >= 1.0f) {
        _square_load__current_phase -= 1.0f;
    }
    // Generated from the component: Triangular load
    _triangular_load__current_phase += 0.5 * 0.0001;
    if (_triangular_load__current_phase >= 1.0f) {
        _triangular_load__current_phase -= 1.0f;
    }
    // Generated from the component: PI controller
    if (!_pi_controller__av_active) {
        _pi_controller__integrator_state += 4.9 * _product6__out * 0.0001;
    }
    //@cmp.update.block.end
}
// ----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------