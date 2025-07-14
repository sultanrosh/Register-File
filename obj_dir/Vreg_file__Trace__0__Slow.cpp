// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vreg_file__Syms.h"


VL_ATTR_COLD void Vreg_file___024root__trace_init_sub__TOP__0(Vreg_file___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+69,0,"rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+70,0,"rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+71,0,"rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declQuad(c+72,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+74,0,"rd1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+76,0,"rd2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->pushPrefix("regfile64", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+69,0,"rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+70,0,"rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+71,0,"rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declQuad(c+72,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+74,0,"rd1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+76,0,"rd2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declQuad(c+1+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 63,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+65,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vreg_file___024root__trace_init_top(Vreg_file___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root__trace_init_top\n"); );
    // Body
    Vreg_file___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vreg_file___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vreg_file___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vreg_file___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vreg_file___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vreg_file___024root__trace_register(Vreg_file___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vreg_file___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vreg_file___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vreg_file___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vreg_file___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vreg_file___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root__trace_const_0\n"); );
    // Init
    Vreg_file___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vreg_file___024root*>(voidSelf);
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vreg_file___024root__trace_full_0_sub_0(Vreg_file___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vreg_file___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root__trace_full_0\n"); );
    // Init
    Vreg_file___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vreg_file___024root*>(voidSelf);
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vreg_file___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vreg_file___024root__trace_full_0_sub_0(Vreg_file___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullQData(oldp+1,(vlSelf->regfile64__DOT__regs[0]),64);
    bufp->fullQData(oldp+3,(vlSelf->regfile64__DOT__regs[1]),64);
    bufp->fullQData(oldp+5,(vlSelf->regfile64__DOT__regs[2]),64);
    bufp->fullQData(oldp+7,(vlSelf->regfile64__DOT__regs[3]),64);
    bufp->fullQData(oldp+9,(vlSelf->regfile64__DOT__regs[4]),64);
    bufp->fullQData(oldp+11,(vlSelf->regfile64__DOT__regs[5]),64);
    bufp->fullQData(oldp+13,(vlSelf->regfile64__DOT__regs[6]),64);
    bufp->fullQData(oldp+15,(vlSelf->regfile64__DOT__regs[7]),64);
    bufp->fullQData(oldp+17,(vlSelf->regfile64__DOT__regs[8]),64);
    bufp->fullQData(oldp+19,(vlSelf->regfile64__DOT__regs[9]),64);
    bufp->fullQData(oldp+21,(vlSelf->regfile64__DOT__regs[10]),64);
    bufp->fullQData(oldp+23,(vlSelf->regfile64__DOT__regs[11]),64);
    bufp->fullQData(oldp+25,(vlSelf->regfile64__DOT__regs[12]),64);
    bufp->fullQData(oldp+27,(vlSelf->regfile64__DOT__regs[13]),64);
    bufp->fullQData(oldp+29,(vlSelf->regfile64__DOT__regs[14]),64);
    bufp->fullQData(oldp+31,(vlSelf->regfile64__DOT__regs[15]),64);
    bufp->fullQData(oldp+33,(vlSelf->regfile64__DOT__regs[16]),64);
    bufp->fullQData(oldp+35,(vlSelf->regfile64__DOT__regs[17]),64);
    bufp->fullQData(oldp+37,(vlSelf->regfile64__DOT__regs[18]),64);
    bufp->fullQData(oldp+39,(vlSelf->regfile64__DOT__regs[19]),64);
    bufp->fullQData(oldp+41,(vlSelf->regfile64__DOT__regs[20]),64);
    bufp->fullQData(oldp+43,(vlSelf->regfile64__DOT__regs[21]),64);
    bufp->fullQData(oldp+45,(vlSelf->regfile64__DOT__regs[22]),64);
    bufp->fullQData(oldp+47,(vlSelf->regfile64__DOT__regs[23]),64);
    bufp->fullQData(oldp+49,(vlSelf->regfile64__DOT__regs[24]),64);
    bufp->fullQData(oldp+51,(vlSelf->regfile64__DOT__regs[25]),64);
    bufp->fullQData(oldp+53,(vlSelf->regfile64__DOT__regs[26]),64);
    bufp->fullQData(oldp+55,(vlSelf->regfile64__DOT__regs[27]),64);
    bufp->fullQData(oldp+57,(vlSelf->regfile64__DOT__regs[28]),64);
    bufp->fullQData(oldp+59,(vlSelf->regfile64__DOT__regs[29]),64);
    bufp->fullQData(oldp+61,(vlSelf->regfile64__DOT__regs[30]),64);
    bufp->fullQData(oldp+63,(vlSelf->regfile64__DOT__regs[31]),64);
    bufp->fullIData(oldp+65,(vlSelf->regfile64__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+66,(vlSelf->clk));
    bufp->fullBit(oldp+67,(vlSelf->reset));
    bufp->fullBit(oldp+68,(vlSelf->we));
    bufp->fullCData(oldp+69,(vlSelf->rs1),5);
    bufp->fullCData(oldp+70,(vlSelf->rs2),5);
    bufp->fullCData(oldp+71,(vlSelf->rd),5);
    bufp->fullQData(oldp+72,(vlSelf->wd),64);
    bufp->fullQData(oldp+74,(vlSelf->rd1),64);
    bufp->fullQData(oldp+76,(vlSelf->rd2),64);
}
