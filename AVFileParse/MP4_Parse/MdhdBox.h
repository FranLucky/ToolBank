#pragma once
#include "BaseBox.h"

#define MDHD_VERSION_SIZE				1
#define MDHD_FLAGS_SIZE					3
#define MDHD_CREATETIME_SIZE			4
#define MDHD_MODIFYTIME_SIZE			4
#define MDHD_TIMESCALE_SIZE				4
#define MDHD_DURATION_SIZE				4
#define MDHD_LANGUAGE_SIZE				2
#define MDHD_PREDEFINED_SIZE			2

/************************************************************************************************************
**										tkhd
**
-------------------------------------------------------------------------------------------------------------
**		�ֶ�����			|	����(bytes)	|		�й�����
-------------------------------------------------------------------------------------------------------------
**		boxsize				|	4			|		box�ĳ���
**		boxtype				|	4			|		box������
**		version				|	1			|		box�汾0��1 һ��Ϊ0 (�����ֽ�������version=0)
**		flags				|	3			|		
**		creation_time		|	4			|		����ʱ�䣨�����UTCʱ��1904 - 01 - 01����������
**		modification_time	|	4			|		�޸�ʱ��
**		time_scale			|	4			|		
**		duration			|	4			|		track��ʱ�䳤��
**		language			|	2			|		ý��������,���λΪ0 ����15λΪ3���ַ�[��ISO 639-2/T��׼�ж���]
**		pre-defined			|	2			|		����λ
************************************************************************************************************/
class MdhdBox : public BaseBox
{
public:
	MdhdBox();
	~MdhdBox();

	virtual int ParseAttrs(byteptr &pData);

	static BaseBox* CreateObject();

public:
	int				m_iVersion;
	int				m_iFlags;
	int				m_iCreateTime;
	int				m_iModifyTime;
	int				m_iTimeScale;
	int				m_iDuration;
	int				m_iLanguage;
	int				m_iPreDefined;
};