#pragma once
#include "bytes.h"
#include "FLVTag.h"
#include <vector>

typedef std::vector<CFLVTag*>	VecFlvTag;

class CFLVFileBody
{
public:
	CFLVFileBody();
	~CFLVFileBody();

	// ��������,���ؽ����ֽ���;
	bool ReadData(byte_ptr &pData, int iSize);
	// �������;
	int WriteData(byte_ptr &pData, double dStart, double dEnd);

	// ��ʾ;
	void Display();

public:
	VecFlvTag	m_vecFlvTags;
};