#pragma once
#include "bytes.h"
#include <windows.h>

class CBMPFile
{
public:
	CBMPFile();
	~CBMPFile();

public:
	// �����ļ�,��ȡ����;
	bool LoadFile(const char* strFile);

	bool SaveFile(const char* strFile, RECT rt = {0});

	// ��ʾ;
	void Display();

protected:
	// ��������;
	bool ReadData(byte_ptr pData, int iSize);
	// �������;
	bool WriteData(byte_ptr pData, int &iSize, double dStart, double dEnd);

public:
	BITMAPFILEHEADER	m_bmpFileHeader;
	BITMAPINFOHEADER	m_bmpInfoHeader;
	byte*				m_pData;
	int					m_iFileSize;
};