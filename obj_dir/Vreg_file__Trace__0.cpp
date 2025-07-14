// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vreg_file__Syms.h"


void Vreg_file___024root__trace_chg_0_sub_0(Vreg_file___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vreg_file___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root__trace_chg_0\n"); );
    // Init
    Vreg_file___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vreg_file___024root*>(voidSelf);
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vreg_file___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vreg_file___024root__trace_chg_0_sub_0(Vreg_file___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgQData(oldp+0,(vlSelf->regfile64__DOT__regs[0]),64);
        bufp->chgQData(oldp+2,(vlSelf->regfile64__DOT__regs[1]),64);
        bufp->chgQData(oldp+4,(vlSelf->regfile64__DOT__regs[2]),64);
        bufp->chgQData(oldp+6,(vlSelf->regfile64__DOT__regs[3]),64);
        bufp->chgQData(oldp+8,(vlSelf->regfile64__DOT__regs[4]),64);
        bufp->chgQData(oldp+10,(vlSelf->regfile64__DOT__regs[5]),64);
        bufp->chgQData(oldp+12,(vlSelf->regfile64__DOT__regs[6]),64);
        bufp->chgQData(oldp+14,(vlSelf->regfile64__DOT__regs[7]),64);
        bufp->chgQData(oldp+16,(vlSelf->regfile64__DOT__regs[8]),64);
        bufp->chgQData(oldp+18,(vlSelf->regfile64__DOT__regs[9]),64);
        bufp->chgQData(oldp+20,(vlSelf->regfile64__DOT__regs[10]),64);
        bufp->chgQData(oldp+22,(vlSelf->regfile64__DOT__regs[11]),64);
        bufp->chgQData(oldp+24,(vlSelf->regfile64__DOT__regs[12]),64);
        bufp->chgQData(oldp+26,(vlSelf->regfile64__DOT__regs[13]),64);
        bufp->chgQData(oldp+28,(vlSelf->regfile64__DOT__regs[14]),64);
        bufp->chgQData(oldp+30,(vlSelf->regfile64__DOT__regs[15]),64);
        bufp->chgQData(oldp+32,(vlSelf->regfile64__DOT__regs[16]),64);
        bufp->chgQData(oldp+34,(vlSelf->regfile64__DOT__regs[17]),64);
        bufp->chgQData(oldp+36,(vlSelf->regfile64__DOT__regs[18]),64);
        bufp->chgQData(oldp+38,(vlSelf->regfile64__DOT__regs[19]),64);
        bufp->chgQData(oldp+40,(vlSelf->regfile64__DOT__regs[20]),64);
        bufp->chgQData(oldp+42,(vlSelf->regfile64__DOT__regs[21]),64);
        bufp->chgQData(oldp+44,(vlSelf->regfile64__DOT__regs[22]),64);
        bufp->chgQData(oldp+46,(vlSelf->regfile64__DOT__regs[23]),64);
        bufp->chgQData(oldp+48,(vlSelf->regfile64__DOT__regs[24]),64);
        bufp->chgQData(oldp+50,(vlSelf->regfile64__DOT__regs[25]),64);
        bufp->chgQData(oldp+52,(vlSelf->regfile64__DOT__regs[26]),64);
        bufp->chgQData(oldp+54,(vlSelf->regfile64__DOT__regs[27]),64);
        bufp->chgQData(oldp+56,(vlSelf->regfile64__DOT__regs[28]),64);
        bufp->chgQData(oldp+58,(vlSelf->regfile64__DOT__regs[29]),64);
        bufp->chgQData(oldp+60,(vlSelf->regfile64__DOT__regs[30]),64);
        bufp->chgQData(oldp+62,(vlSelf->regfile64__DOT__regs[31]),64);
        bufp->chgIData(oldp+64,(vlSelf->regfile64__DOT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+65,(vlSelf->clk));
    bufp->chgBit(oldp+66,(vlSelf->reset));
    bufp->chgBit(oldp+67,(vlSelf->we));
    bufp->chgCData(oldp+68,(vlSelf->rs1),5);
    bufp->chgCData(oldp+69,(vlSelf->rs2),5);
    bufp->chgCData(oldp+70,(vlSelf->rd),5);
    bufp->chgQData(oldp+71,(vlSelf->wd),64);
    bufp->chgQData(oldp+73,(vlSelf->rd1),64);
    bufp->chgQData(oldp+75,(vlSelf->rd2),64);
}

void Vreg_file___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root__trace_cleanup\n"); );
    // Init
    Vreg_file___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vreg_file___024root*>(voidSelf);
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
