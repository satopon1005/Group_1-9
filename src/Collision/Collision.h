#pragma once


class Collision {
public:

	static void UpDateOverlap(bool current_overlap, bool& pre_overlap) { pre_overlap = current_overlap; }

	//��`�̓����蔻��
	static bool IsHitRect(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);

	//�~�̓����蔻��
	static bool IsHitCircle(float x1, float y1, float r1, float x2, float y2, float r2);
	static bool BeginOverlapCircle(float x1, float y1, float r1, float x2, float y2, float r2, bool& current_overlap, bool pre_overlap);

	//�~�Ƌ�`�̓����蔻��
	static bool IsHitRectCircle(float x1, float y1, float r1, float x2, float y2, float w2, float h2);

	//��`�Ɠ_�̓����蔻��
	static bool IsHitRectPoint(float rect_x, float rect_y, float rect_w, float rect_h, float point_pos_x, float point_pos_y);

	//�~�Ɠ_�̓����蔻��
	static bool IsHitCirclePoint(float circcle_pos_x, float circcle_pos_y, float circle_len, float point_pos_x, float point_pos_y);

	//�~�Ɛ��̓����蔻��
	static bool IsHitCircleLine(float circle_x, float circle_y, float circle_len,
		float line_start_x, float line_start_y, float line_end_x, float line_end_y);


	//��`�Ɠ_�̓����蔻��
	static bool IsHitFanPoint(float fan_pos_x, float fan_pos_y, float len, float angle, float direction,
		float point_pos_x, float point_pos_y);

	//��`�Ɖ~�̓����蔻��
	static bool IsHitFanCircle(float fan_pos_x, float fan_pos_y, float fan_len, float angle, float direction,
		float circcle_pos_x, float circcle_pos_y, float circle_len);

	// �� ������ ��
	//��`�Ƌ�`�̓����蔻��
	static bool IsHitFanRect(float fan_pos_x, float fan_pos_y, float fan_len, float angle, float direction,
		float rect_x, float rect_y, float rect_w, float rect_h);
};