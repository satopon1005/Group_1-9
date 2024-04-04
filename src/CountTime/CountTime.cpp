#include "DxLib.h"
#include "CountTime.h"

CountTime::CountTime()
{
	m_start_time = 0;
	m_end_time = 0;
	m_now_time = 0;

	m_minutes = 0;
	m_seconds = 0;

	m_count_time_flag = false;

	m_display_font_handle = CreateFontToHandle(NULL, 40, 3);
}

CountTime::~CountTime()
{
	DeleteFontToHandle(m_display_font_handle);
}

void CountTime::InitCountTime(int minutes, int seconds)
{
	m_start_time = 0;
	m_end_time = 0;
	m_now_time = 0;

	m_end_time += minutes * 60;
	m_end_time += seconds;

	m_end_time *= 1000;

	m_minutes = minutes;
	m_seconds = seconds;
}

void CountTime::StartCountTime()
{
	m_start_time = GetNowCount();
	m_count_time_flag = true;
}

void CountTime::StepCountTimeDown()
{
	m_now_time = GetNowCount();

	int elapsed_time = m_now_time - m_start_time;

	if (elapsed_time >= 1000) {

		m_start_time = m_now_time;
		m_seconds--;

		if (m_seconds < 0) {
			m_minutes--;
			m_seconds = 59;
		}
	}
}

void CountTime::CheckEndCountTimeDown()
{
	if (m_minutes == 0 && m_seconds == 0) {
		m_count_time_flag = false;
	}
}

void CountTime::DrawCountTime()
{
	DrawFormatStringToHandle(0, 0, GetColor(0, 0, 0),
		m_display_font_handle,
		"%02d:%02d", m_minutes, m_seconds);
}