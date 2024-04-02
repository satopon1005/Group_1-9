#pragma once

#include "DxLib.h"

//�����̍���Ԃ�
float GetDefLen_f(float pos_A, float pos_B);
//��
bool NearyEqual(float num1, float num2, float error_num = 1.0f);

int GetNumLen(int num);

//�x�N�g���̑����Z
VECTOR AddVec(VECTOR vec1, VECTOR vec2);
//�x�N�g���̈����Z
VECTOR SubVec(VECTOR vec1, VECTOR vec2);
//�x�N�g���̊|���Z
VECTOR MulVec(VECTOR vec, float mul);
//�x�N�g���̊���Z
VECTOR DivVec(VECTOR vec, float div);

//�x�N�g���̒����擾
float GetVecLen(VECTOR vec);

//�x�N�g���̐��K��
VECTOR NorVec(VECTOR vec);

//���ݒn����ړI�n�܂Ŏw��̑����œ����x�N�g��
VECTOR GetVector(VECTOR vec_here, VECTOR vec_dis, float speed = 1.0f);


//����
float VecDot(VECTOR vec1, VECTOR vec2);

//�O��
float VecCross2D(VECTOR vec1, VECTOR vec2);

VECTOR VecCross(VECTOR vec1, VECTOR vec2);

//�x�N�g���̂Ȃ��p
float AngleOf2Vector(VECTOR vec1, VECTOR vec2, bool degree_switch = false);