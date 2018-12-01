#pragma once
#include "bytes.h"

/************************************************************************************************************
header���ּ�¼��flv�����͡��汾����Ϣ����flv�Ŀ�ͷ��һ�㶼��࣬ռ9bytes.

�����ʽ����;
�ļ�����	3 bytes		"FLV";
�汾		1 byte		һ��Ϊ0x01;
����Ϣ		1 byte		������һλ��1��ʾ����Ƶ����������λ��1��ʾ����Ƶ�������ڶ�����λ����Ϊ0;
header����	4 bytes		����header�ĳ��ȣ�һ��Ϊ9������9��ʾ���滹����չ��Ϣ;
************************************************************************************************************/
struct flvfileheader_data
{
	byte Type[3];
	byte Version;
	byte StreamInfo;
	byte HeaderSize[4];
};

class CFLVFileHeader
{
public:
	CFLVFileHeader();
	~CFLVFileHeader();

	// ��������,���ؽ����ֽ���;
	int ReadData(byte_ptr &pData);
	// �������;
	int WriteData(byte_ptr &pData);

	// ��ʾ;
	void Display();

public:
	flvfileheader_data		m_data;
};