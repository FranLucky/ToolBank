#pragma once
#include "BaseBox.h"

class CMP4File
{
public:
	CMP4File();
	~CMP4File();

	// �����ļ�;
	bool LoadFile(std::string strFile);
	bool LoadFile(byte* pData, int iDataSize);

	// �����ļ�;
	bool SaveFile(std::string strFile);
	bool SaveFile();

private:
	VecBoxs m_vecBoxs;
};