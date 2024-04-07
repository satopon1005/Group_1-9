#include "DxLib.h"
#include "MyMath.h"
#include <math.h>

//�����̍���Ԃ�
float GetDefLen_f(float pos_A, float pos_B) { return fabsf(pos_A - pos_B); }

// ��
bool NearyEqual(float num1, float num2, float error_num)
{
	if (fabsf(num1 - num2) < error_num)
		return true;

	return false;
}

int GetNumLen(int num)
{
	int len = 0;
	if (num == 0)
		return 1;
	else
		while (num != 0){
			num /= 10;
			len++;
		}

	return len;
}

//�x�N�g���̑����Z
VECTOR AddVec(VECTOR vec1, VECTOR vec2)
{
	VECTOR vec = {
		vec1.x + vec2.x,
		vec1.y + vec2.y,
		vec1.z + vec2.z
	};

	return vec;
}

//�x�N�g���̈����Z
VECTOR SubVec(VECTOR vec1, VECTOR vec2)
{
	VECTOR vec = {
		vec1.x - vec2.x,
		vec1.y - vec2.y,
		vec1.z - vec2.z
	};

	return vec;
}

//�x�N�g���̊|���Z
VECTOR MulVec(VECTOR vec, float mul)
{
	VECTOR mul_vec = {
		vec.x * mul,
		vec.y * mul,
		vec.z * mul,
	};

	return mul_vec;
}

//�x�N�g���̊���Z
VECTOR DivVec(VECTOR vec, float div)
{
	VECTOR div_vec = {
		vec.x / div,
		vec.y / div,
		vec.z / div,
	};

	return div_vec;
}

//�x�N�g���̒����擾
float GetVecLen(VECTOR vec)
{
	float vec_len = (float)sqrt((double)pow(vec.x, 2) + (double)pow(vec.y, 2) + (double)pow(vec.z, 2));

	return vec_len;
}

//�x�N�g���̐��K��
VECTOR NorVec(VECTOR vec)
{
	float vec_len = GetVecLen(vec);

	if (vec_len == 0)
		return VGet(0.0f, 0.0f, 0.0f);

	VECTOR nor_vec = {
		vec.x / vec_len,
		vec.y / vec_len,
		vec.z / vec_len
	};

	return nor_vec;
}

//���ݒn����ړI�n�܂Ŏw��̑����œ����x�N�g��
VECTOR GetVector(VECTOR vec_here, VECTOR vec_dis, float speed)
{
	//���ݒn����ړI�n�̃x�N�g��
	VECTOR sub_vec = SubVec(vec_dis, vec_here);

	//���K��
	VECTOR nor_vec = NorVec(sub_vec);

	//�擾����x�N�g���̑傫��
	VECTOR mul_vec = MulVec(nor_vec, speed);

	return mul_vec;
}

//����
float VecDot(VECTOR vec1, VECTOR vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

//�O��
float VecCross2D(VECTOR vec1, VECTOR vec2)
{
	return (vec1.x * vec2.y - vec1.y * vec2.x);
}

VECTOR VecCross(VECTOR vec1, VECTOR vec2)
{
	VECTOR EP = {
		vec1.y * vec2.z - vec1.z * vec2.y,
		vec1.z * vec2.x - vec1.x * vec2.z,
		vec1.x * vec2.y - vec1.y * vec2.x
	};

	return EP;
}

//�x�N�g���̂Ȃ��p
float AngleOf2Vector(VECTOR vec1, VECTOR vec2,bool degree_switch)
{
	//�x�N�g���̒���
	double len1 = GetVecLen(vec1);
	double len2 = GetVecLen(vec2);

	//cos��
	double cos_sita = VecDot(vec1, vec2) / (len1 * len2);

	//��
	double sita = acos(cos_sita);

	//�p�x
	if (degree_switch)
		sita = sita * 180.0 / DX_PI;

	return (float)sita;
}

//�Q�_�Ԃ̋���
float GetDistance(VECTOR pos1, VECTOR pos2)
{
	VECTOR distance = {
		fabsf(pos1.x - pos2.x),
		fabsf(pos1.y - pos2.y),
		fabsf(pos1.z - pos2.z),
	};

	return (float)sqrt(distance.x * distance.x + distance.y * distance.y + distance.z * distance.z);
}

//�����
float GetInverseProportion(float x,int constant)
{
	if (x != 0)
		return constant / x;
	else
		return 0;
}