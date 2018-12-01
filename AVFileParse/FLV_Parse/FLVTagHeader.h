#pragma once
#include "bytes.h"

/************************************************************************************************************
ÿ��Tag��Ҳ������������ɵģ�Tag Header��Tag Data;
Tag Header���ŵ��ǵ�ǰTag�����͡���������Tag Data�����ȵ���Ϣ;
��������;

����			����					����;
Tag����			1 bytes					8����Ƶ \ 9����Ƶ \ 18���ű� \  ����������;
����������		3 bytes					���������ĳ���;
ʱ���			3 bytes					��������λ�Ǻ��� ���ڽű��͵�tag����0;
ʱ�����չ		1 bytes					��ʱ�����չΪ4bytes,�����8λ �����õ�;
StreamsID		3 bytes					����0;
������(data)	�����������Ⱦ���		����ʵ��;
************************************************************************************************************/
struct flvtagheader_data
{
	byte TagType;
	byte DataSize[3];
	byte Timestamp[3];
	byte TimeExtend;
	byte StreamsID[3];
};

class CFLVTagHeader
{
public:
	CFLVTagHeader();
	~CFLVTagHeader();

	// ��������,���ؽ����ֽ���;
	int ReadData(byte_ptr &pData);
	// �������;
	int WriteData(byte_ptr &pData);

	// ��ʾ;
	void Display();

	// ��ȡTag����;
	int GetTagType();
	// ��ȡTag��С;
	int GetTagSize();

public:
	flvtagheader_data m_data;
};