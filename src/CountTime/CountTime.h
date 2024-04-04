#pragma once

class CountTime
{
private:
	int m_start_time;
	int m_end_time;
	int m_now_time;

	int m_minutes;
	int m_seconds;

	bool m_count_time_flag;

	int m_display_font_handle;

public:
	CountTime();
	~CountTime();

	void InitCountTime(int minutes = 0, int seconds = 0);
	void StartCountTime();

	void StepCountTimeDown();
	void CheckEndCountTimeDown();

	void DrawCountTime();

	int GetMinutes() { return m_minutes; }
	int GetSeconds() { return m_seconds; }
	bool GetCountTimeFlag() { return m_count_time_flag; }
};