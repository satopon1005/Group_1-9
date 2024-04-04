#pragma once

class Objects
{
protected:
	VECTOR m_pos;

public:
	Objects() { m_pos = { 0 }; }

	VECTOR GetPos() { return m_pos; }
};