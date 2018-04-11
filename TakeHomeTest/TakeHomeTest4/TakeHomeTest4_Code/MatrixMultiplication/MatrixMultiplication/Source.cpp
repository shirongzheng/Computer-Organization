#include "stdafx.h"
#include "omp.h"
#include<Windows.h>
#include<iostream>
#include<xmmintrin.h>

using namespace std;

void matrix_multiplications(float A[size][size], float B[size][size], float S[size][size]){
	const int mask=0x1F;
	_m128 v1={0.0, 0.0, 0.0, 0.0}, v2={0.0, 0.0, 0.0, 0.0},v3={0.0, 0.0, 0.0, 0.0}, v4={0.0, 0.0, 0.0, 0.0}, s={0.0, 0.0, 0.0, 0.0};
	for (int i=0; i<size; i++){
		for (int j=0; j<size;j++){
			for (int k=0; k<size; k+=8){
				v1=_mm_set_ps(A[i][k],A[i][k+1],A[i][k+2],A[i][k+3]);
				v2=_mm_set_ps(A[i][k+4],A[i][k+5],A[i][k+6],A[i][k+7]);
				v3=_mm_set_ps(B[i][k],B[i][k+1],B[i][k+2],B[i][k+3]);
				v4=_mm_set_ps(B[i][k+4],B[i][k+5],B[i][k+6],B[i][k+7]);
				s=_mm_dp_ps(v1,v3,mask);
				S[i][j] += s.m128_f32[0] + s.m128_f32[1] +s.m128_f32[2] + s.m128_f32[3];
				s=_mm_dp_ps(v2,v4,mask);
				S[i][j] += s.m128_f32[0] +s.m128_f32[1] +s.m128.f32[2]+s.m128_f32[3];
			}
		}
	}
}