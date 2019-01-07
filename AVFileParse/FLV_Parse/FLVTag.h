#pragma once
#include "bytes.h"
#include "FLVTagHeader.h"
#include "FLVTagBody.h"

class CFLVTag
{
public:
	CFLVTag();
	~CFLVTag();

	// ��������,���ؽ����ֽ���;
	int ReadData(byte_ptr &pData);
	// �������;
	int WriteData(byte_ptr &pData);

	// ��ʾ;
	void Display();

	bool IsKeyFrame();

public:
	CFLVTagHeader	m_tagHeader;
	CFLVTagBody		m_tagBody;
};

