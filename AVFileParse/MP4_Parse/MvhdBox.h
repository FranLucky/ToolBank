#pragma once
#include "BaseBox.h"

#define MVHD_VERSION_SIZE			1
#define MVHD_FLAGS_SIZE				3
#define MVHD_CREATETIME_SIZE		4
#define MVHD_MODIFYTIME_SIZE		4
#define MVHD_TIMESCALE_SIZE			4
#define MVHD_DURATION_SIZE			4
#define MVHD_RATE_SIZE				4
#define MVHD_VOLUME_SIZE			2
#define MVHD_RESERVED_SIZE			10
#define MVHD_MATRIX_SIZE			36
#define MVHD_PREDEFINED_SIZE		24
#define MVHD_NEXTTRACKID_SIZE		4

/************************************************************************************************************
**											mvhd
**
--------------------------------------------------------------------------------------------
**		�ֶ�����			|	����(bytes)	|		�й�����
--------------------------------------------------------------------------------------------
**		boxsize				|	4			|		box�ĳ���
**		boxtype				|	4			|		box������
**		version				|	1			|		box�汾��0��1��һ��Ϊ0�������ֽ�������version = 0��
**		flags				|	3			|		
**		creation time		|	4			|		����ʱ�䣨�����UTCʱ��1904 - 01 - 01����������
**		modification time	|	4			|		�޸�ʱ��
**		time scale			|	4			|		�ļ�ý����1��ʱ���ڵĿ̶�ֵ���������Ϊ1�볤�ȵ�ʱ�䵥Ԫ��
**		duration			|	4			|		��track��ʱ�䳤�ȣ���duration��time scaleֵ���Լ���trackʱ��
**		rate				|	4			|		�Ƽ��������ʣ���16λ�͵�16λ�ֱ�ΪС�����������ֺ�С�����֣���[16.16] ��ʽ.��ֵΪ1.0��0x00010000����ʾ����ǰ�򲥷�
**		volume				|	2			|		��rate���ƣ�[8.8] ��ʽ��1.0��0x0100����ʾ�������
**		reserved			|	10			|		����λ
**		matrix				|	36			|		��Ƶ�任����
**		pre-defined			|	24			|		
**		next track id		|	4			|		��һ��trackʹ�õ�id��
************************************************************************************************************/
class MvhdBox : public BaseBox
{
public:
	MvhdBox();
	virtual ~MvhdBox();

	virtual int ParseAttrs(byteptr &pData);

	static BaseBox* CreateObject();

public:
	int				m_iVersion;
	int				m_iFlags;
	int				m_iCreateTime;
	int				m_iModifyTime;
	int				m_iTimeScale;
	int				m_iDuration;
	double			m_dRate;
	double			m_dVolume;
	string			m_strReserved;
	string			m_strMatrix;
	string			m_strPreDefined;
	int				m_iNextTrackID;
};