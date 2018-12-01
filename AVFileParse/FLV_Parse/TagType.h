#pragma once
#include "bytes.h"

class CTagType
{
public:
	CTagType();
	virtual ~CTagType();

	// ��������,���ؽ����ֽ���;
	int ReadData(byte_ptr &pData, int iTagSize) ;
	// �������;
	int WriteData(byte_ptr &pData);

	// ��ʾ;
	virtual void Display() = 0;

	// �Ƿ���Ƶ�Ĺؼ�֡;
	virtual bool IsKeyFrame();

public:
	byte_ptr		m_pData;
	int				m_iSize;
};

