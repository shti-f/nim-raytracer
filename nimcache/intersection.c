/* Generated by Nim Compiler v0.18.0 */
/*   (c) 2018 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: MacOSX, amd64, clang */
/* Command for C compiler:
   clang -c  -w  -I/usr/local/Cellar/nim/0.18.0_1/nim/lib -o /Users/nao/Documents/ray/nim-ray/nimcache/intersection.o /Users/nao/Documents/ray/nim-ray/nimcache/intersection.c */
#define NIM_NEW_MANGLING_RULES
#define NIM_INTBITS 64

#include "nimbase.h"
#include <string.h>
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
typedef struct tyObject_RaycolonObjectType__yItp9be63YkzBMUq0NA9cyMQ tyObject_RaycolonObjectType__yItp9be63YkzBMUq0NA9cyMQ;
typedef struct RootObj RootObj;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg;
typedef struct tyObject_IntersectioncolonObjectType__ez5BZXnG89cynYRdZ8nGXQA tyObject_IntersectioncolonObjectType__ez5BZXnG89cynYRdZ8nGXQA;
typedef NF tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ[3];
typedef NU8 tyEnum_TNimKind_jIBKr1ejBgsfM33Kxw4j7A;
typedef NU8 tySet_tyEnum_TNimTypeFlag_v8QUszD1sWlSIWZz7mC4bQ;
typedef N_NIMCALL_PTR(void, tyProc_ojoeKfW4VYIm36I9cpDTQIg) (void* p, NI op);
typedef N_NIMCALL_PTR(void*, tyProc_WSm2xU5ARYv9aAR4l0z9c9auQ) (void* p);
struct TNimType {
NI size;
tyEnum_TNimKind_jIBKr1ejBgsfM33Kxw4j7A kind;
tySet_tyEnum_TNimTypeFlag_v8QUszD1sWlSIWZz7mC4bQ flags;
TNimType* base;
TNimNode* node;
void* finalizer;
tyProc_ojoeKfW4VYIm36I9cpDTQIg marker;
tyProc_WSm2xU5ARYv9aAR4l0z9c9auQ deepcopy;
};
struct RootObj {
TNimType* m_type;
};
struct tyObject_RaycolonObjectType__yItp9be63YkzBMUq0NA9cyMQ {
  RootObj Sup;
tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ origin;
tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ direction;
};
typedef NU8 tyEnum_TNimNodeKind_unfNsxrcATrufDZmpBq4HQ;
struct TNimNode {
tyEnum_TNimNodeKind_unfNsxrcATrufDZmpBq4HQ kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
struct tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg {
  RootObj Sup;
NF radius;
tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ position;
tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ emission;
tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ color;
};
struct tyObject_IntersectioncolonObjectType__ez5BZXnG89cynYRdZ8nGXQA {
  RootObj Sup;
NF distance;
tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ position;
tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ normal;
tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ color;
};
N_LIB_PRIVATE N_NIMCALL(void, vinit_NR9bsEPN4kVj7xVgDhfHxYg)(NF x, NF y, NF z, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ Result);
N_NOINLINE(void, chckNil)(void* p);
static N_INLINE(void, nimFrame)(TFrame* s);
N_LIB_PRIVATE N_NOINLINE(void, stackOverflow_II46IjNZztN9bmbxUD8dt8g)(void);
static N_INLINE(void, popFrame)(void);
N_LIB_PRIVATE N_NIMCALL(void, plus__lUId4ok88EeE1RPmV09buIQ)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ left, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ right, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ Result);
N_LIB_PRIVATE N_NIMCALL(void, minus__lUId4ok88EeE1RPmV09buIQ_2)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ left, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ right, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ Result);
N_LIB_PRIVATE N_NIMCALL(void, star__E9avUBV6ECAjkkRaBlYT18g)(NF left, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ right, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ Result);
N_LIB_PRIVATE N_NIMCALL(void, star__yJwfGePDAHtDQuTQ3T1n5g)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ left, NF right, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ Result);
N_LIB_PRIVATE N_NIMCALL(void, slash__yJwfGePDAHtDQuTQ3T1n5g_2)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ left, NF right, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ Result);
N_LIB_PRIVATE N_NIMCALL(NF, dot_vMvkLTKfkxfBDCkfaiCujQ)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ left, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ right);
N_LIB_PRIVATE N_NIMCALL(void, cross_lUId4ok88EeE1RPmV09buIQ_3)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ left, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ right, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ Result);
N_LIB_PRIVATE N_NIMCALL(void, mult_lUId4ok88EeE1RPmV09buIQ_4)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ left, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ right, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ Result);
N_LIB_PRIVATE N_NIMCALL(NF, norm_cMYpiSUXdmcjKTIisCMLeg)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ this_0);
N_LIB_PRIVATE N_NIMCALL(void, normalize_Z0pi1hweFjr4uVVUJE2Rvg)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ this_0, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ Result);
N_LIB_PRIVATE N_NIMCALL(tyObject_RaycolonObjectType__yItp9be63YkzBMUq0NA9cyMQ*, rinit_gHUempGhSyUh2hQWXNTPmw)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ o, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ d);
static N_NIMCALL(void, Marker_tyRef_YJznnTIo305R9akdHV5yqpw)(void* p, NI op);
N_NIMCALL(void*, newObj)(TNimType* typ, NI size);
N_LIB_PRIVATE N_NIMCALL(tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg*, sinit_AbZPzgQR9bquGxUjJeTAIGw)(NF radius, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ position, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ emission, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ color);
static N_NIMCALL(void, Marker_tyRef_vmukBQJn5NKYYPIyqS1p2w)(void* p, NI op);
N_LIB_PRIVATE N_NIMCALL(tyObject_IntersectioncolonObjectType__ez5BZXnG89cynYRdZ8nGXQA*, intersect_gZG6Bl0EcnZjGa56OIToOw)(tyObject_RaycolonObjectType__yItp9be63YkzBMUq0NA9cyMQ* r, tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg* sphere);
static N_NIMCALL(void, Marker_tyRef_ExjOMgSUV9agAX9a7wybnKzw)(void* p, NI op);
extern TFrame* framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw;
extern TNimType NTI_13RNkKqUOX1TtorOUlKtqA_;
TNimType NTI_yItp9be63YkzBMUq0NA9cyMQ_;
extern TNimType NTI_w9bl9a1ul9ctRJWiMl9cNnIMvg_;
TNimType NTI_9ce69c9a1NzlPVqY9aKHS79b5IQ_;
TNimType NTI_YJznnTIo305R9akdHV5yqpw_;
TNimType NTI_EnbbGzdxyUrulo0Zp8QWAg_;
TNimType NTI_vmukBQJn5NKYYPIyqS1p2w_;
TNimType NTI_ez5BZXnG89cynYRdZ8nGXQA_;
TNimType NTI_ExjOMgSUV9agAX9a7wybnKzw_;

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

N_LIB_PRIVATE N_NIMCALL(void, vinit_NR9bsEPN4kVj7xVgDhfHxYg)(NF x, NF y, NF z, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ Result) {
	nimfr_("vinit", "vector3.nim");
	chckNil((void*)Result);
	memset((void*)Result, 0, sizeof(Result));
	nimln_(7, "vector3.nim");
	Result[0] = x;
	Result[1] = y;
	Result[2] = z;
	popFrame();
}

N_LIB_PRIVATE N_NIMCALL(void, plus__lUId4ok88EeE1RPmV09buIQ)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ left, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ right, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ Result) {
	nimfr_("+", "vector3.nim");
	chckNil((void*)Result);
	memset((void*)Result, 0, sizeof(Result));
	nimln_(13, "vector3.nim");
	Result[0] = ((NF)(left[(((NI) 0))- 0]) + (NF)(right[(((NI) 0))- 0]));
	Result[1] = ((NF)(left[(((NI) 1))- 0]) + (NF)(right[(((NI) 1))- 0]));
	Result[2] = ((NF)(left[(((NI) 2))- 0]) + (NF)(right[(((NI) 2))- 0]));
	popFrame();
}

N_LIB_PRIVATE N_NIMCALL(void, minus__lUId4ok88EeE1RPmV09buIQ_2)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ left, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ right, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ Result) {
	nimfr_("-", "vector3.nim");
	chckNil((void*)Result);
	memset((void*)Result, 0, sizeof(Result));
	nimln_(16, "vector3.nim");
	Result[0] = ((NF)(left[(((NI) 0))- 0]) - (NF)(right[(((NI) 0))- 0]));
	Result[1] = ((NF)(left[(((NI) 1))- 0]) - (NF)(right[(((NI) 1))- 0]));
	Result[2] = ((NF)(left[(((NI) 2))- 0]) - (NF)(right[(((NI) 2))- 0]));
	popFrame();
}

N_LIB_PRIVATE N_NIMCALL(void, star__E9avUBV6ECAjkkRaBlYT18g)(NF left, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ right, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ Result) {
	nimfr_("*", "vector3.nim");
	chckNil((void*)Result);
	memset((void*)Result, 0, sizeof(Result));
	nimln_(19, "vector3.nim");
	Result[0] = ((NF)(left) * (NF)(right[(((NI) 0))- 0]));
	Result[1] = ((NF)(left) * (NF)(right[(((NI) 1))- 0]));
	Result[2] = ((NF)(left) * (NF)(right[(((NI) 2))- 0]));
	popFrame();
}

N_LIB_PRIVATE N_NIMCALL(void, star__yJwfGePDAHtDQuTQ3T1n5g)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ left, NF right, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ Result) {
	nimfr_("*", "vector3.nim");
	chckNil((void*)Result);
	memset((void*)Result, 0, sizeof(Result));
	nimln_(22, "vector3.nim");
	Result[0] = ((NF)(left[(((NI) 0))- 0]) * (NF)(right));
	Result[1] = ((NF)(left[(((NI) 1))- 0]) * (NF)(right));
	Result[2] = ((NF)(left[(((NI) 2))- 0]) * (NF)(right));
	popFrame();
}

N_LIB_PRIVATE N_NIMCALL(void, slash__yJwfGePDAHtDQuTQ3T1n5g_2)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ left, NF right, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ Result) {
	nimfr_("/", "vector3.nim");
	chckNil((void*)Result);
	memset((void*)Result, 0, sizeof(Result));
	nimln_(25, "vector3.nim");
	Result[0] = ((NF)(left[(((NI) 0))- 0]) / (NF)(right));
	Result[1] = ((NF)(left[(((NI) 1))- 0]) / (NF)(right));
	Result[2] = ((NF)(left[(((NI) 2))- 0]) / (NF)(right));
	popFrame();
}

N_LIB_PRIVATE N_NIMCALL(NF, dot_vMvkLTKfkxfBDCkfaiCujQ)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ left, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ right) {
	NF result;
	nimfr_("dot", "vector3.nim");
	result = (NF)0;
	nimln_(28, "vector3.nim");
	result = ((NF)(((NF)(((NF)(left[(((NI) 0))- 0]) * (NF)(right[(((NI) 0))- 0]))) + (NF)(((NF)(left[(((NI) 1))- 0]) * (NF)(right[(((NI) 1))- 0]))))) + (NF)(((NF)(left[(((NI) 2))- 0]) * (NF)(right[(((NI) 2))- 0]))));
	popFrame();
	return result;
}

N_LIB_PRIVATE N_NIMCALL(void, cross_lUId4ok88EeE1RPmV09buIQ_3)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ left, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ right, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ Result) {
	nimfr_("cross", "vector3.nim");
	chckNil((void*)Result);
	memset((void*)Result, 0, sizeof(Result));
	nimln_(31, "vector3.nim");
	Result[0] = ((NF)(((NF)(left[(((NI) 1))- 0]) * (NF)(right[(((NI) 2))- 0]))) - (NF)(((NF)(right[(((NI) 2))- 0]) * (NF)(left[(((NI) 1))- 0]))));
	Result[1] = ((NF)(((NF)(left[(((NI) 2))- 0]) * (NF)(right[(((NI) 0))- 0]))) - (NF)(((NF)(right[(((NI) 0))- 0]) * (NF)(left[(((NI) 2))- 0]))));
	Result[2] = ((NF)(((NF)(left[(((NI) 0))- 0]) * (NF)(right[(((NI) 1))- 0]))) - (NF)(((NF)(right[(((NI) 1))- 0]) * (NF)(left[(((NI) 0))- 0]))));
	popFrame();
}

N_LIB_PRIVATE N_NIMCALL(void, mult_lUId4ok88EeE1RPmV09buIQ_4)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ left, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ right, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ Result) {
	nimfr_("mult", "vector3.nim");
	chckNil((void*)Result);
	memset((void*)Result, 0, sizeof(Result));
	nimln_(34, "vector3.nim");
	Result[0] = ((NF)(left[(((NI) 0))- 0]) * (NF)(right[(((NI) 0))- 0]));
	Result[1] = ((NF)(left[(((NI) 1))- 0]) * (NF)(right[(((NI) 1))- 0]));
	Result[2] = ((NF)(left[(((NI) 2))- 0]) * (NF)(right[(((NI) 2))- 0]));
	popFrame();
}

N_LIB_PRIVATE N_NIMCALL(NF, norm_cMYpiSUXdmcjKTIisCMLeg)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ this_0) {
	NF result;
	NF T1_;
	nimfr_("norm", "vector3.nim");
	result = (NF)0;
	nimln_(37, "vector3.nim");
	T1_ = (NF)0;
	T1_ = dot_vMvkLTKfkxfBDCkfaiCujQ(this_0, this_0);
	result = sqrt(T1_);
	popFrame();
	return result;
}

N_LIB_PRIVATE N_NIMCALL(void, normalize_Z0pi1hweFjr4uVVUJE2Rvg)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ this_0, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ Result) {
	NF T1_;
	tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ T2_;
	nimfr_("normalize", "vector3.nim");
	chckNil((void*)Result);
	memset((void*)Result, 0, sizeof(Result));
	nimln_(40, "vector3.nim");
	T1_ = (NF)0;
	T1_ = norm_cMYpiSUXdmcjKTIisCMLeg(this_0);
	memset((void*)T2_, 0, sizeof(T2_));
	star__yJwfGePDAHtDQuTQ3T1n5g(this_0, ((NF)(1.0000000000000000e+00) / (NF)(T1_)), T2_);
	memcpy((void*)Result, (NIM_CONST void*)T2_, sizeof(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ));
	popFrame();
}
static N_NIMCALL(void, Marker_tyRef_YJznnTIo305R9akdHV5yqpw)(void* p, NI op) {
	tyObject_RaycolonObjectType__yItp9be63YkzBMUq0NA9cyMQ* a;
	NI T1_;
	NI T2_;
	a = (tyObject_RaycolonObjectType__yItp9be63YkzBMUq0NA9cyMQ*)p;
	T1_ = (NI)0;
	T2_ = (NI)0;
}

N_LIB_PRIVATE N_NIMCALL(tyObject_RaycolonObjectType__yItp9be63YkzBMUq0NA9cyMQ*, rinit_gHUempGhSyUh2hQWXNTPmw)(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ o, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ d) {
	tyObject_RaycolonObjectType__yItp9be63YkzBMUq0NA9cyMQ* result;
	tyObject_RaycolonObjectType__yItp9be63YkzBMUq0NA9cyMQ* T1_;
	nimfr_("rinit", "ray.nim");
	result = (tyObject_RaycolonObjectType__yItp9be63YkzBMUq0NA9cyMQ*)0;
	nimln_(7, "ray.nim");
	T1_ = (tyObject_RaycolonObjectType__yItp9be63YkzBMUq0NA9cyMQ*)0;
	T1_ = (tyObject_RaycolonObjectType__yItp9be63YkzBMUq0NA9cyMQ*) newObj((&NTI_YJznnTIo305R9akdHV5yqpw_), sizeof(tyObject_RaycolonObjectType__yItp9be63YkzBMUq0NA9cyMQ));
	(*T1_).Sup.m_type = (&NTI_yItp9be63YkzBMUq0NA9cyMQ_);
	memcpy((void*)(*T1_).origin, (NIM_CONST void*)o, sizeof(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ));
	memcpy((void*)(*T1_).direction, (NIM_CONST void*)d, sizeof(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ));
	result = T1_;
	popFrame();
	return result;
}
static N_NIMCALL(void, Marker_tyRef_vmukBQJn5NKYYPIyqS1p2w)(void* p, NI op) {
	tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg* a;
	NI T1_;
	NI T2_;
	NI T3_;
	a = (tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg*)p;
	T1_ = (NI)0;
	T2_ = (NI)0;
	T3_ = (NI)0;
}

N_LIB_PRIVATE N_NIMCALL(tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg*, sinit_AbZPzgQR9bquGxUjJeTAIGw)(NF radius, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ position, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ emission, tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ color) {
	tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg* result;
	tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg* T1_;
	nimfr_("sinit", "objects.nim");
	result = (tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg*)0;
	nimln_(9, "objects.nim");
	T1_ = (tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg*)0;
	T1_ = (tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg*) newObj((&NTI_vmukBQJn5NKYYPIyqS1p2w_), sizeof(tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg));
	(*T1_).Sup.m_type = (&NTI_EnbbGzdxyUrulo0Zp8QWAg_);
	(*T1_).radius = radius;
	memcpy((void*)(*T1_).position, (NIM_CONST void*)position, sizeof(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ));
	memcpy((void*)(*T1_).emission, (NIM_CONST void*)emission, sizeof(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ));
	memcpy((void*)(*T1_).color, (NIM_CONST void*)color, sizeof(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ));
	result = T1_;
	popFrame();
	return result;
}
static N_NIMCALL(void, Marker_tyRef_ExjOMgSUV9agAX9a7wybnKzw)(void* p, NI op) {
	tyObject_IntersectioncolonObjectType__ez5BZXnG89cynYRdZ8nGXQA* a;
	NI T1_;
	NI T2_;
	NI T3_;
	a = (tyObject_IntersectioncolonObjectType__ez5BZXnG89cynYRdZ8nGXQA*)p;
	T1_ = (NI)0;
	T2_ = (NI)0;
	T3_ = (NI)0;
}

N_LIB_PRIVATE N_NIMCALL(tyObject_IntersectioncolonObjectType__ez5BZXnG89cynYRdZ8nGXQA*, intersect_gZG6Bl0EcnZjGa56OIToOw)(tyObject_RaycolonObjectType__yItp9be63YkzBMUq0NA9cyMQ* r, tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg* sphere) {
	tyObject_IntersectioncolonObjectType__ez5BZXnG89cynYRdZ8nGXQA* result;
	tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ po;
	tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ T1_;
	NF det;
	NF T2_;
	NF T3_;
	NF T4_;
	NF T5_;
	NF EPS;
	NF tminus;
	NF T10_;
	NF T11_;
	NF tplus;
	NF T12_;
	NF T13_;
	NF distance;
	tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ position;
	tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ T25_;
	tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ T26_;
	tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ normal;
	tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ T27_;
	tyObject_IntersectioncolonObjectType__ez5BZXnG89cynYRdZ8nGXQA* T28_;
	nimfr_("intersect", "intersection.nim");
{	result = (tyObject_IntersectioncolonObjectType__ez5BZXnG89cynYRdZ8nGXQA*)0;
	memset((void*)po, 0, sizeof(po));
	nimln_(12, "intersection.nim");
	memset((void*)T1_, 0, sizeof(T1_));
	minus__lUId4ok88EeE1RPmV09buIQ_2((*r).origin, (*sphere).position, T1_);
	memcpy((void*)po, (NIM_CONST void*)T1_, sizeof(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ));
	nimln_(13, "intersection.nim");
	T2_ = (NF)0;
	T2_ = dot_vMvkLTKfkxfBDCkfaiCujQ((*r).direction, po);
	T3_ = (NF)0;
	T3_ = pow(T2_, 2.0000000000000000e+00);
	T4_ = (NF)0;
	T4_ = dot_vMvkLTKfkxfBDCkfaiCujQ(po, po);
	T5_ = (NF)0;
	T5_ = pow((*sphere).radius, 2.0000000000000000e+00);
	det = ((NF)(((NF)(T3_) - (NF)(T4_))) + (NF)(T5_));
	nimln_(14, "intersection.nim");
	EPS = 1.0000000000000000e-10;
	nimln_(15, "intersection.nim");
	{
		if (!(det < 0.0)) goto LA8_;
		nimln_(16, "intersection.nim");
		result = NIM_NIL;
		goto BeforeRet_;
	}
	LA8_: ;
	nimln_(18, "intersection.nim");
	T10_ = (NF)0;
	T10_ = dot_vMvkLTKfkxfBDCkfaiCujQ((*r).direction, po);
	T11_ = (NF)0;
	T11_ = sqrt(det);
	tminus = ((NF)(-(T10_)) - (NF)(T11_));
	nimln_(19, "intersection.nim");
	T12_ = (NF)0;
	T12_ = dot_vMvkLTKfkxfBDCkfaiCujQ((*r).direction, po);
	T13_ = (NF)0;
	T13_ = sqrt(det);
	tplus = ((NF)(-(T12_)) + (NF)(T13_));
	nimln_(20, "intersection.nim");
	{
		NIM_BOOL T16_;
		T16_ = (NIM_BOOL)0;
		T16_ = (tminus < EPS);
		if (!(T16_)) goto LA17_;
		T16_ = (tplus < EPS);
		LA17_: ;
		if (!T16_) goto LA18_;
		nimln_(21, "intersection.nim");
		result = NIM_NIL;
		goto BeforeRet_;
	}
	LA18_: ;
	nimln_(22, "intersection.nim");
	{
		if (!(tminus < 0.0)) goto LA22_;
		distance = tplus;
	}
	goto LA20_;
	LA22_: ;
	{
		distance = tminus;
	}
	LA20_: ;
	memset((void*)position, 0, sizeof(position));
	nimln_(25, "intersection.nim");
	memset((void*)T25_, 0, sizeof(T25_));
	star__E9avUBV6ECAjkkRaBlYT18g(distance, (*r).direction, T25_);
	memset((void*)T26_, 0, sizeof(T26_));
	plus__lUId4ok88EeE1RPmV09buIQ((*r).origin, T25_, T26_);
	memcpy((void*)position, (NIM_CONST void*)T26_, sizeof(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ));
	memset((void*)normal, 0, sizeof(normal));
	nimln_(26, "intersection.nim");
	memset((void*)T27_, 0, sizeof(T27_));
	minus__lUId4ok88EeE1RPmV09buIQ_2(position, (*sphere).position, T27_);
	normalize_Z0pi1hweFjr4uVVUJE2Rvg(T27_, normal);
	nimln_(27, "intersection.nim");
	T28_ = (tyObject_IntersectioncolonObjectType__ez5BZXnG89cynYRdZ8nGXQA*)0;
	T28_ = (tyObject_IntersectioncolonObjectType__ez5BZXnG89cynYRdZ8nGXQA*) newObj((&NTI_ExjOMgSUV9agAX9a7wybnKzw_), sizeof(tyObject_IntersectioncolonObjectType__ez5BZXnG89cynYRdZ8nGXQA));
	(*T28_).Sup.m_type = (&NTI_ez5BZXnG89cynYRdZ8nGXQA_);
	(*T28_).distance = distance;
	memcpy((void*)(*T28_).position, (NIM_CONST void*)position, sizeof(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ));
	memcpy((void*)(*T28_).normal, (NIM_CONST void*)normal, sizeof(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ));
	memcpy((void*)(*T28_).color, (NIM_CONST void*)(*sphere).color, sizeof(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ));
	result = T28_;
	goto BeforeRet_;
	}BeforeRet_: ;
	popFrame();
	return result;
}
NIM_EXTERNC N_NOINLINE(void, unknown_intersectionInit000)(void) {
	nimfr_("intersection", "intersection.nim");
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, unknown_intersectionDatInit000)(void) {
static TNimNode* TM_QGFAcZxAQtHvKWaog5sY1w_2[2];
static TNimNode* TM_QGFAcZxAQtHvKWaog5sY1w_3[4];
static TNimNode* TM_QGFAcZxAQtHvKWaog5sY1w_4[4];
static TNimNode TM_QGFAcZxAQtHvKWaog5sY1w_0[13];
NTI_yItp9be63YkzBMUq0NA9cyMQ_.size = sizeof(tyObject_RaycolonObjectType__yItp9be63YkzBMUq0NA9cyMQ);
NTI_yItp9be63YkzBMUq0NA9cyMQ_.kind = 17;
NTI_yItp9be63YkzBMUq0NA9cyMQ_.base = (&NTI_13RNkKqUOX1TtorOUlKtqA_);
NTI_yItp9be63YkzBMUq0NA9cyMQ_.flags = 1;
TM_QGFAcZxAQtHvKWaog5sY1w_2[0] = &TM_QGFAcZxAQtHvKWaog5sY1w_0[1];
NTI_9ce69c9a1NzlPVqY9aKHS79b5IQ_.size = sizeof(tyArray_9ce69c9a1NzlPVqY9aKHS79b5IQ);
NTI_9ce69c9a1NzlPVqY9aKHS79b5IQ_.kind = 16;
NTI_9ce69c9a1NzlPVqY9aKHS79b5IQ_.base = (&NTI_w9bl9a1ul9ctRJWiMl9cNnIMvg_);
NTI_9ce69c9a1NzlPVqY9aKHS79b5IQ_.flags = 3;
TM_QGFAcZxAQtHvKWaog5sY1w_0[1].kind = 1;
TM_QGFAcZxAQtHvKWaog5sY1w_0[1].offset = offsetof(tyObject_RaycolonObjectType__yItp9be63YkzBMUq0NA9cyMQ, origin);
TM_QGFAcZxAQtHvKWaog5sY1w_0[1].typ = (&NTI_9ce69c9a1NzlPVqY9aKHS79b5IQ_);
TM_QGFAcZxAQtHvKWaog5sY1w_0[1].name = "origin";
TM_QGFAcZxAQtHvKWaog5sY1w_2[1] = &TM_QGFAcZxAQtHvKWaog5sY1w_0[2];
TM_QGFAcZxAQtHvKWaog5sY1w_0[2].kind = 1;
TM_QGFAcZxAQtHvKWaog5sY1w_0[2].offset = offsetof(tyObject_RaycolonObjectType__yItp9be63YkzBMUq0NA9cyMQ, direction);
TM_QGFAcZxAQtHvKWaog5sY1w_0[2].typ = (&NTI_9ce69c9a1NzlPVqY9aKHS79b5IQ_);
TM_QGFAcZxAQtHvKWaog5sY1w_0[2].name = "direction";
TM_QGFAcZxAQtHvKWaog5sY1w_0[0].len = 2; TM_QGFAcZxAQtHvKWaog5sY1w_0[0].kind = 2; TM_QGFAcZxAQtHvKWaog5sY1w_0[0].sons = &TM_QGFAcZxAQtHvKWaog5sY1w_2[0];
NTI_yItp9be63YkzBMUq0NA9cyMQ_.node = &TM_QGFAcZxAQtHvKWaog5sY1w_0[0];
NTI_YJznnTIo305R9akdHV5yqpw_.size = sizeof(tyObject_RaycolonObjectType__yItp9be63YkzBMUq0NA9cyMQ*);
NTI_YJznnTIo305R9akdHV5yqpw_.kind = 22;
NTI_YJznnTIo305R9akdHV5yqpw_.base = (&NTI_yItp9be63YkzBMUq0NA9cyMQ_);
NTI_YJznnTIo305R9akdHV5yqpw_.marker = Marker_tyRef_YJznnTIo305R9akdHV5yqpw;
NTI_EnbbGzdxyUrulo0Zp8QWAg_.size = sizeof(tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg);
NTI_EnbbGzdxyUrulo0Zp8QWAg_.kind = 17;
NTI_EnbbGzdxyUrulo0Zp8QWAg_.base = (&NTI_13RNkKqUOX1TtorOUlKtqA_);
NTI_EnbbGzdxyUrulo0Zp8QWAg_.flags = 1;
TM_QGFAcZxAQtHvKWaog5sY1w_3[0] = &TM_QGFAcZxAQtHvKWaog5sY1w_0[4];
TM_QGFAcZxAQtHvKWaog5sY1w_0[4].kind = 1;
TM_QGFAcZxAQtHvKWaog5sY1w_0[4].offset = offsetof(tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg, radius);
TM_QGFAcZxAQtHvKWaog5sY1w_0[4].typ = (&NTI_w9bl9a1ul9ctRJWiMl9cNnIMvg_);
TM_QGFAcZxAQtHvKWaog5sY1w_0[4].name = "radius";
TM_QGFAcZxAQtHvKWaog5sY1w_3[1] = &TM_QGFAcZxAQtHvKWaog5sY1w_0[5];
TM_QGFAcZxAQtHvKWaog5sY1w_0[5].kind = 1;
TM_QGFAcZxAQtHvKWaog5sY1w_0[5].offset = offsetof(tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg, position);
TM_QGFAcZxAQtHvKWaog5sY1w_0[5].typ = (&NTI_9ce69c9a1NzlPVqY9aKHS79b5IQ_);
TM_QGFAcZxAQtHvKWaog5sY1w_0[5].name = "position";
TM_QGFAcZxAQtHvKWaog5sY1w_3[2] = &TM_QGFAcZxAQtHvKWaog5sY1w_0[6];
TM_QGFAcZxAQtHvKWaog5sY1w_0[6].kind = 1;
TM_QGFAcZxAQtHvKWaog5sY1w_0[6].offset = offsetof(tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg, emission);
TM_QGFAcZxAQtHvKWaog5sY1w_0[6].typ = (&NTI_9ce69c9a1NzlPVqY9aKHS79b5IQ_);
TM_QGFAcZxAQtHvKWaog5sY1w_0[6].name = "emission";
TM_QGFAcZxAQtHvKWaog5sY1w_3[3] = &TM_QGFAcZxAQtHvKWaog5sY1w_0[7];
TM_QGFAcZxAQtHvKWaog5sY1w_0[7].kind = 1;
TM_QGFAcZxAQtHvKWaog5sY1w_0[7].offset = offsetof(tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg, color);
TM_QGFAcZxAQtHvKWaog5sY1w_0[7].typ = (&NTI_9ce69c9a1NzlPVqY9aKHS79b5IQ_);
TM_QGFAcZxAQtHvKWaog5sY1w_0[7].name = "color";
TM_QGFAcZxAQtHvKWaog5sY1w_0[3].len = 4; TM_QGFAcZxAQtHvKWaog5sY1w_0[3].kind = 2; TM_QGFAcZxAQtHvKWaog5sY1w_0[3].sons = &TM_QGFAcZxAQtHvKWaog5sY1w_3[0];
NTI_EnbbGzdxyUrulo0Zp8QWAg_.node = &TM_QGFAcZxAQtHvKWaog5sY1w_0[3];
NTI_vmukBQJn5NKYYPIyqS1p2w_.size = sizeof(tyObject_SpherecolonObjectType__EnbbGzdxyUrulo0Zp8QWAg*);
NTI_vmukBQJn5NKYYPIyqS1p2w_.kind = 22;
NTI_vmukBQJn5NKYYPIyqS1p2w_.base = (&NTI_EnbbGzdxyUrulo0Zp8QWAg_);
NTI_vmukBQJn5NKYYPIyqS1p2w_.marker = Marker_tyRef_vmukBQJn5NKYYPIyqS1p2w;
NTI_ez5BZXnG89cynYRdZ8nGXQA_.size = sizeof(tyObject_IntersectioncolonObjectType__ez5BZXnG89cynYRdZ8nGXQA);
NTI_ez5BZXnG89cynYRdZ8nGXQA_.kind = 17;
NTI_ez5BZXnG89cynYRdZ8nGXQA_.base = (&NTI_13RNkKqUOX1TtorOUlKtqA_);
NTI_ez5BZXnG89cynYRdZ8nGXQA_.flags = 1;
TM_QGFAcZxAQtHvKWaog5sY1w_4[0] = &TM_QGFAcZxAQtHvKWaog5sY1w_0[9];
TM_QGFAcZxAQtHvKWaog5sY1w_0[9].kind = 1;
TM_QGFAcZxAQtHvKWaog5sY1w_0[9].offset = offsetof(tyObject_IntersectioncolonObjectType__ez5BZXnG89cynYRdZ8nGXQA, distance);
TM_QGFAcZxAQtHvKWaog5sY1w_0[9].typ = (&NTI_w9bl9a1ul9ctRJWiMl9cNnIMvg_);
TM_QGFAcZxAQtHvKWaog5sY1w_0[9].name = "distance";
TM_QGFAcZxAQtHvKWaog5sY1w_4[1] = &TM_QGFAcZxAQtHvKWaog5sY1w_0[10];
TM_QGFAcZxAQtHvKWaog5sY1w_0[10].kind = 1;
TM_QGFAcZxAQtHvKWaog5sY1w_0[10].offset = offsetof(tyObject_IntersectioncolonObjectType__ez5BZXnG89cynYRdZ8nGXQA, position);
TM_QGFAcZxAQtHvKWaog5sY1w_0[10].typ = (&NTI_9ce69c9a1NzlPVqY9aKHS79b5IQ_);
TM_QGFAcZxAQtHvKWaog5sY1w_0[10].name = "position";
TM_QGFAcZxAQtHvKWaog5sY1w_4[2] = &TM_QGFAcZxAQtHvKWaog5sY1w_0[11];
TM_QGFAcZxAQtHvKWaog5sY1w_0[11].kind = 1;
TM_QGFAcZxAQtHvKWaog5sY1w_0[11].offset = offsetof(tyObject_IntersectioncolonObjectType__ez5BZXnG89cynYRdZ8nGXQA, normal);
TM_QGFAcZxAQtHvKWaog5sY1w_0[11].typ = (&NTI_9ce69c9a1NzlPVqY9aKHS79b5IQ_);
TM_QGFAcZxAQtHvKWaog5sY1w_0[11].name = "normal";
TM_QGFAcZxAQtHvKWaog5sY1w_4[3] = &TM_QGFAcZxAQtHvKWaog5sY1w_0[12];
TM_QGFAcZxAQtHvKWaog5sY1w_0[12].kind = 1;
TM_QGFAcZxAQtHvKWaog5sY1w_0[12].offset = offsetof(tyObject_IntersectioncolonObjectType__ez5BZXnG89cynYRdZ8nGXQA, color);
TM_QGFAcZxAQtHvKWaog5sY1w_0[12].typ = (&NTI_9ce69c9a1NzlPVqY9aKHS79b5IQ_);
TM_QGFAcZxAQtHvKWaog5sY1w_0[12].name = "color";
TM_QGFAcZxAQtHvKWaog5sY1w_0[8].len = 4; TM_QGFAcZxAQtHvKWaog5sY1w_0[8].kind = 2; TM_QGFAcZxAQtHvKWaog5sY1w_0[8].sons = &TM_QGFAcZxAQtHvKWaog5sY1w_4[0];
NTI_ez5BZXnG89cynYRdZ8nGXQA_.node = &TM_QGFAcZxAQtHvKWaog5sY1w_0[8];
NTI_ExjOMgSUV9agAX9a7wybnKzw_.size = sizeof(tyObject_IntersectioncolonObjectType__ez5BZXnG89cynYRdZ8nGXQA*);
NTI_ExjOMgSUV9agAX9a7wybnKzw_.kind = 22;
NTI_ExjOMgSUV9agAX9a7wybnKzw_.base = (&NTI_ez5BZXnG89cynYRdZ8nGXQA_);
NTI_ExjOMgSUV9agAX9a7wybnKzw_.marker = Marker_tyRef_ExjOMgSUV9agAX9a7wybnKzw;
}

