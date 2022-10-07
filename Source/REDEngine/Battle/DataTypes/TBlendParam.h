#pragma once

enum EACCType
{
	ACC_LINEAR = 0x0,
	ACC_DEC = 0x1,
	ACC_ACC = 0x2,
	ACC_ACC_TO_DEC = 0x3,
	ACC_EXP_DEC = 0x4,
	ACC_EXP_ACC = 0x5,
	ACC_EXP_ACC_TO_DEC = 0x6,
};

template <typename T>
struct __declspec(align(4)) TBlendParam
{
	T Val;
	T StartVal;
	T EndVal;
	int CurrentFrame;
	int MaxFrame;
	int IntervalFrame;
	EACCType AccType;
	bool bUpdateCellTiming;
};