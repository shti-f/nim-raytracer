/* Generated by Nim Compiler v0.17.2 */
/*   (c) 2017 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: MacOSX, amd64, clang */
/* Command for C compiler:
   clang -c  -w  -I/usr/local/Cellar/nim/0.17.2/nim/lib -o /Users/nao/Documents/ray/nim-ray/nimcache/stdlib_math.o /Users/nao/Documents/ray/nim-ray/nimcache/stdlib_math.c */
#define NIM_NEW_MANGLING_RULES
#define NIM_INTBITS 64

#include "nimbase.h"
#include <math.h>
#undef LANGUAGE_C
#undef MIPSEB
#undef MIPSEL
#undef PPC
#undef R3000
#undef R4000
#undef i386
#undef linux
#undef mips
#undef near
#undef powerpc
#undef unix
typedef NU8 tyEnum_FloatClass_pPga1yW9b8J9cwNnm9b1aPRnA;
N_NIMCALL(NI, binom_TP1l1uTkkFkPa6yon2PyGg)(NI n, NI k);
N_NIMCALL(NI, mulInt)(NI a, NI b);
static N_INLINE(NI, subInt)(NI a, NI b);
N_NOINLINE(void, raiseOverflow)(void);
static N_INLINE(NI, addInt)(NI a, NI b);
static N_INLINE(NI, divInt)(NI a, NI b);
N_NOINLINE(void, raiseDivByZero)(void);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackOverflow_II46IjNZztN9bmbxUD8dt8g)(void);
static N_INLINE(void, popFrame)(void);
N_NIMCALL(NI, fac_07E8HBGS9a9a9amVjbwI9a9a7yg)(NI n);
N_NIMCALL(tyEnum_FloatClass_pPga1yW9b8J9cwNnm9b1aPRnA, classify_rfodLs2J9b87EDgWnWZoObA)(NF x);
N_NIMCALL(NIM_BOOL, isPowerOfTwo_M0Db9b9cHxuUgw2ZF0P8utPg)(NI x);
N_NIMCALL(NI, nextPowerOfTwo_gcitR3TEXHJ3GR9bmwIvtRA)(NI x);
N_NIMCALL(NI, countBits32_hJyETcwTUJpi9clvlrTbRyA)(NI32 n);
extern TFrame* framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw;

static N_INLINE(NI, subInt)(NI a, NI b) {
	NI result;
{	result = (NI)0;
	result = (NI)((NU64)(a) - (NU64)(b));
	{
		NIM_BOOL T3_;
		T3_ = (NIM_BOOL)0;
		T3_ = (((NI) 0) <= (NI)(result ^ a));
		if (T3_) goto LA4_;
		T3_ = (((NI) 0) <= (NI)(result ^ (NI)((NU64) ~(b))));
		LA4_: ;
		if (!T3_) goto LA5_;
		goto BeforeRet_;
	}
	LA5_: ;
	raiseOverflow();
	}BeforeRet_: ;
	return result;
}

static N_INLINE(NI, addInt)(NI a, NI b) {
	NI result;
{	result = (NI)0;
	result = (NI)((NU64)(a) + (NU64)(b));
	{
		NIM_BOOL T3_;
		T3_ = (NIM_BOOL)0;
		T3_ = (((NI) 0) <= (NI)(result ^ a));
		if (T3_) goto LA4_;
		T3_ = (((NI) 0) <= (NI)(result ^ b));
		LA4_: ;
		if (!T3_) goto LA5_;
		goto BeforeRet_;
	}
	LA5_: ;
	raiseOverflow();
	}BeforeRet_: ;
	return result;
}

static N_INLINE(NI, divInt)(NI a, NI b) {
	NI result;
{	result = (NI)0;
	{
		if (!(b == ((NI) 0))) goto LA3_;
		raiseDivByZero();
	}
	LA3_: ;
	{
		NIM_BOOL T7_;
		T7_ = (NIM_BOOL)0;
		T7_ = (a == ((NI) (IL64(-9223372036854775807) - IL64(1))));
		if (!(T7_)) goto LA8_;
		T7_ = (b == ((NI) -1));
		LA8_: ;
		if (!T7_) goto LA9_;
		raiseOverflow();
	}
	LA9_: ;
	result = (NI)(a / b);
	goto BeforeRet_;
	}BeforeRet_: ;
	return result;
}

static N_INLINE(void, nimFrame)(TFrame* s) {
	NI T1_;
	T1_ = (NI)0;
	{
		if (!(framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw == NIM_NIL)) goto LA4_;
		T1_ = ((NI) 0);
	}
	goto LA2_;
	LA4_: ;
	{
		T1_ = ((NI) ((NI16)((*framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw).calldepth + ((NI16) 1))));
	}
	LA2_: ;
	(*s).calldepth = ((NI16) (T1_));
	(*s).prev = framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw;
	framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw = s;
	{
		if (!((*s).calldepth == ((NI16) 2000))) goto LA9_;
		stackOverflow_II46IjNZztN9bmbxUD8dt8g();
	}
	LA9_: ;
}

static N_INLINE(void, popFrame)(void) {
	framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw = (*framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw).prev;
}

N_NIMCALL(NI, binom_TP1l1uTkkFkPa6yon2PyGg)(NI n, NI k) {
	NI result;
	nimfr_("binom", "math.nim");
{	result = (NI)0;
	nimln_(26, "math.nim");
	{
		if (!(k <= ((NI) 0))) goto LA3_;
		result = ((NI) 1);
		goto BeforeRet_;
	}
	LA3_: ;
	nimln_(27, "math.nim");
	{
		NI TM_YqBQIdfvZX5pt75kDBsDLg_2;
		NI TM_YqBQIdfvZX5pt75kDBsDLg_3;
		TM_YqBQIdfvZX5pt75kDBsDLg_2 = mulInt(((NI) 2), k);
		if (!(n < (NI)(TM_YqBQIdfvZX5pt75kDBsDLg_2))) goto LA7_;
		TM_YqBQIdfvZX5pt75kDBsDLg_3 = subInt(n, k);
		result = binom_TP1l1uTkkFkPa6yon2PyGg(n, (NI)(TM_YqBQIdfvZX5pt75kDBsDLg_3));
		goto BeforeRet_;
	}
	LA7_: ;
	nimln_(28, "math.nim");
	result = n;
	{
		NI i;
		NI res;
		i = (NI)0;
		nimln_(1973, "system.nim");
		res = ((NI) 2);
		{
			nimln_(1974, "system.nim");
			while (1) {
				NI TM_YqBQIdfvZX5pt75kDBsDLg_4;
				NI TM_YqBQIdfvZX5pt75kDBsDLg_5;
				NI TM_YqBQIdfvZX5pt75kDBsDLg_6;
				NI TM_YqBQIdfvZX5pt75kDBsDLg_7;
				NI TM_YqBQIdfvZX5pt75kDBsDLg_8;
				if (!(res <= k)) goto LA11;
				nimln_(1975, "system.nim");
				i = res;
				nimln_(30, "math.nim");
				TM_YqBQIdfvZX5pt75kDBsDLg_4 = addInt(n, ((NI) 1));
				TM_YqBQIdfvZX5pt75kDBsDLg_5 = subInt((NI)(TM_YqBQIdfvZX5pt75kDBsDLg_4), i);
				TM_YqBQIdfvZX5pt75kDBsDLg_6 = mulInt(result, (NI)(TM_YqBQIdfvZX5pt75kDBsDLg_5));
				TM_YqBQIdfvZX5pt75kDBsDLg_7 = divInt((NI)(TM_YqBQIdfvZX5pt75kDBsDLg_6), i);
				result = (NI)(TM_YqBQIdfvZX5pt75kDBsDLg_7);
				nimln_(1976, "system.nim");
				TM_YqBQIdfvZX5pt75kDBsDLg_8 = addInt(res, ((NI) 1));
				res = (NI)(TM_YqBQIdfvZX5pt75kDBsDLg_8);
			} LA11: ;
		}
	}
	}BeforeRet_: ;
	popFrame();
	return result;
}

N_NIMCALL(NI, fac_07E8HBGS9a9a9amVjbwI9a9a7yg)(NI n) {
	NI result;
	nimfr_("fac", "math.nim");
	result = (NI)0;
	nimln_(34, "math.nim");
	result = ((NI) 1);
	{
		NI i;
		NI res;
		i = (NI)0;
		nimln_(1973, "system.nim");
		res = ((NI) 2);
		{
			nimln_(1974, "system.nim");
			while (1) {
				NI TM_YqBQIdfvZX5pt75kDBsDLg_9;
				NI TM_YqBQIdfvZX5pt75kDBsDLg_10;
				if (!(res <= n)) goto LA3;
				nimln_(1975, "system.nim");
				i = res;
				nimln_(36, "math.nim");
				TM_YqBQIdfvZX5pt75kDBsDLg_9 = mulInt(result, i);
				result = (NI)(TM_YqBQIdfvZX5pt75kDBsDLg_9);
				nimln_(1976, "system.nim");
				TM_YqBQIdfvZX5pt75kDBsDLg_10 = addInt(res, ((NI) 1));
				res = (NI)(TM_YqBQIdfvZX5pt75kDBsDLg_10);
			} LA3: ;
		}
	}
	popFrame();
	return result;
}

N_NIMCALL(tyEnum_FloatClass_pPga1yW9b8J9cwNnm9b1aPRnA, classify_rfodLs2J9b87EDgWnWZoObA)(NF x) {
	tyEnum_FloatClass_pPga1yW9b8J9cwNnm9b1aPRnA result;
{	result = (tyEnum_FloatClass_pPga1yW9b8J9cwNnm9b1aPRnA)0;
	{
		if (!(x == 0.0)) goto LA3_;
		{
			if (!(((NF)(1.0000000000000000e+00) / (NF)(x)) == INF)) goto LA7_;
			result = ((tyEnum_FloatClass_pPga1yW9b8J9cwNnm9b1aPRnA) 2);
			goto BeforeRet_;
		}
		goto LA5_;
		LA7_: ;
		{
			result = ((tyEnum_FloatClass_pPga1yW9b8J9cwNnm9b1aPRnA) 3);
			goto BeforeRet_;
		}
		LA5_: ;
	}
	LA3_: ;
	{
		if (!(((NF)(x) * (NF)(5.0000000000000000e-01)) == x)) goto LA12_;
		{
			if (!(0.0 < x)) goto LA16_;
			result = ((tyEnum_FloatClass_pPga1yW9b8J9cwNnm9b1aPRnA) 5);
			goto BeforeRet_;
		}
		goto LA14_;
		LA16_: ;
		{
			result = ((tyEnum_FloatClass_pPga1yW9b8J9cwNnm9b1aPRnA) 6);
			goto BeforeRet_;
		}
		LA14_: ;
	}
	LA12_: ;
	{
		if (!!((x == x))) goto LA21_;
		result = ((tyEnum_FloatClass_pPga1yW9b8J9cwNnm9b1aPRnA) 4);
		goto BeforeRet_;
	}
	LA21_: ;
	result = ((tyEnum_FloatClass_pPga1yW9b8J9cwNnm9b1aPRnA) 0);
	goto BeforeRet_;
	}BeforeRet_: ;
	return result;
}

N_NIMCALL(NIM_BOOL, isPowerOfTwo_M0Db9b9cHxuUgw2ZF0P8utPg)(NI x) {
	NIM_BOOL result;
	NIM_BOOL T1_;
{	result = (NIM_BOOL)0;
	T1_ = (NIM_BOOL)0;
	T1_ = (((NI) 0) < x);
	if (!(T1_)) goto LA2_;
	T1_ = ((NI)(x & (NI)(x - ((NI) 1))) == ((NI) 0));
	LA2_: ;
	result = T1_;
	goto BeforeRet_;
	}BeforeRet_: ;
	return result;
}

N_NIMCALL(NI, nextPowerOfTwo_gcitR3TEXHJ3GR9bmwIvtRA)(NI x) {
	NI result;
	result = (NI)0;
	result = (NI)(x - ((NI) 1));
	result = (NI)(result | (NI)((NU64)(result) >> (NU64)(((NI) 32))));
	result = (NI)(result | (NI)((NU64)(result) >> (NU64)(((NI) 16))));
	result = (NI)(result | (NI)((NU64)(result) >> (NU64)(((NI) 8))));
	result = (NI)(result | (NI)((NU64)(result) >> (NU64)(((NI) 4))));
	result = (NI)(result | (NI)((NU64)(result) >> (NU64)(((NI) 2))));
	result = (NI)(result | (NI)((NU64)(result) >> (NU64)(((NI) 1))));
	result += ((NI) ((NI)(((NI) 1) + ((NI) ((x <= ((NI) 0)))))));
	return result;
}

N_NIMCALL(NI, countBits32_hJyETcwTUJpi9clvlrTbRyA)(NI32 n) {
	NI result;
	NI32 v;
	result = (NI)0;
	v = n;
	v = (NI32)((NU32)(v) - (NU32)((NI32)((NI32)((NU32)(v) >> (NU32)(((NI32) 1))) & ((NI32) 1431655765))));
	v = (NI32)((NU32)((NI32)(v & ((NI32) 858993459))) + (NU32)((NI32)((NI32)((NU32)(v) >> (NU32)(((NI32) 2))) & ((NI32) 858993459))));
	result = ((NI) ((NI32)((NU32)((NI32)((NU32)((NI32)((NI32)((NU32)(v) + (NU32)((NI32)((NU32)(v) >> (NU32)(((NI32) 4))))) & ((NI32) 252645135))) * (NU32)(((NI32) 16843009)))) >> (NU32)(((NI32) 24)))));
	return result;
}

N_NIMCALL(NF, round_FL9bhksfuQsfLDCxRHuknsg)(NF x, NI places) {
	NF result;
	result = (NF)0;
	{
		if (!(places == ((NI) 0))) goto LA3_;
		result = round(x);
	}
	goto LA1_;
	LA3_: ;
	{
		NF mult;
		NF T6_;
		mult = pow(1.0000000000000000e+01, ((NF) (places)));
		T6_ = (NF)0;
		T6_ = round(((NF)(x) * (NF)(mult)));
		result = ((NF)(T6_) / (NF)(mult));
	}
	LA1_: ;
	return result;
}
NIM_EXTERNC N_NOINLINE(void, stdlib_mathInit000)(void) {
	nimfr_("math", "math.nim");
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_mathDatInit000)(void) {
}

