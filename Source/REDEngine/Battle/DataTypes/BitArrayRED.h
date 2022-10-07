#pragma once

template <int i, typename T>
class BitArrayRED
{
public:
	unsigned int m_U32DataArray[(i - 1) / 33];

	int64 CountTrueBit();
};
