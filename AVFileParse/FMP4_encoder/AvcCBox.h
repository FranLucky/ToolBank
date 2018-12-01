#pragma once
#include "BaseBox.h"

#define AVCC_VERSION_SIZE					1
#define AVCC_PROFILE_SIZE					1
#define AVCC_COMPAT_SIZE					1
#define AVCC_LEVEL_SIZE						1
#define AVCC_LENSIZE_SIZE					1
#define AVCC_SPSNUM_SIZE					1
#define AVCC_SPSLEN_SIZE					2
#define AVCC_PPSNUM_SIZE					1
#define AVCC_PPSLEN_SIZE					2

/************************************************************************************************************
**									avvC Box

configurationVersion			1			�汾;
AVCProfileIndication			1			10���Ƶ�77 ����profile����� ֪����main profile;
profile_compatibility			1			һ��0
AVCLevelIndication				1			10���Ƶ�31
lengthSizeMinusOne				1			1111 1111	ǰ��6λΪreserved������2λ��0b11��Ϊ��lengthSizeMinusOne����ʾ3.
											��ô������ʾsize���ֽھ���3 + 1 = 4��

numOfSequenceParameterSets		1			1110 0001	ǰ��3λ��reserved, ����5bit��numOfSequenceParameterSets����ʾ��1��sps.
sequenceParameterSetLength		2			
SPS								23

numOfPictureParameterSets		1			��1��pps
pictureParameterSetLength		2			pictureParameterSetLength
PPS								4			PPS������

************************************************************************************************************/
class AvcCBox : public BaseBox
{
public:
	AvcCBox();
	~AvcCBox();

	virtual int ParseAttrs(byteptr &pData);

	static BaseBox* CreateObject();

public:
	int			m_iVersion;
	int			m_iProfile;
	int			m_iCompat;
	int			m_iLevel;
	int			m_iLenSize;
	int			m_iSpsNum;
	VecParameters		m_vecSpsContent;
	int			m_iPpsNum;
	VecParameters		m_vecPpsContent;
};