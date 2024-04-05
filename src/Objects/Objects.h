#pragma once

class Objects
{
protected:
	int m_handle;
	VECTOR m_pos;

public:
	Objects() {
		m_pos = { 0 };
		m_handle = 0;
	}

	VECTOR GetPos() { return m_pos; }
	int GetHandle() { return m_handle; }
};