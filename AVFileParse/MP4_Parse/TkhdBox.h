#pragma once
#include "BaseBox.h"

#define TKHD_VERSION_SIZE			1
#define TKHD_FLAGS_SIZE				3
#define TKHD_CREATETIME_SIZE		4
#define TKHD_MODIFYTIME_SIZE		4
#define TKHD_TRACKID_SIZE			4
#define TKHD_RESERVED1_SIZE			4
#define TKHD_DURATION_SIZE			4
#define TKHD_RESERVED2_SIZE			8
#define TKHD_LAYER_SIZE				2
#define TKHD_ALTERGROUP_SIZE		2
#define TKHD_VOLUME_SIZE			2
#define TKHD_RESERVED3_SIZE			2
#define TKHD_MATRIX_SIZE			36
#define TKHD_WIDTH_SIZE				4
#define TKHD_HEIGHT_SIZE			4

/************************************************************************************************************
**										tkhd
**
-------------------------------------------------------------------------------------------------------------
**		�ֶ�����			|	����(bytes)	|		�й�����
-------------------------------------------------------------------------------------------------------------
**		boxsize				|	4			|		box�ĳ���
**		boxtype				|	4			|		box������
**		version				|	1			|		box�汾��0��1��һ��Ϊ0���������ֽ�������version = 0��
**		flags				|	3			|		��λ��������ֵ��Ԥ��������;
													0x000001 track_enabled�������track�������ţ�
													0x000002 track_in_movie����ʾ��track�ڲ����б����ã�
													0x000004 track_in_preview����ʾ��track��Ԥ��ʱ�����á�
													һ���ֵΪ7�����һ��ý������track��δ����track_in_movie��track_in_preview,�������Ϊ����track��������������;
													����hint track����ֵΪ0;
**		creation_time		|	4			|		����ʱ�䣨�����UTCʱ��1904 - 01 - 01����������
**		modification_time	|	4			|		�޸�ʱ��
**		track_id			|	4			|		id�� �����ظ��Ҳ���Ϊ0
**		reserved			|	4			|		����λ
**		duration			|	4			|		track��ʱ�䳤��
**		reserved			|	8			|		����λ
**		layer				|	2			|		��Ƶ�㣬Ĭ��Ϊ0��ֵС�����ϲ�
**		alternate_group		|	2			|		track������Ϣ��Ĭ��Ϊ0��ʾ��trackδ������track��Ⱥ���ϵ
**		volume				|	2			|		[8.8] ��ʽ�����Ϊ��Ƶtrack��1.0��0x0100����ʾ�������������Ϊ0
**		reserved			|	2			|		����λ
**		matrix				|	36			|		��Ƶ�任����
**		width				|	4			|		��
**		height				|	4			|		�ߣ���Ϊ[16.16] ��ʽֵ ��sample�����е�ʵ�ʻ����С��ֵ�����ڲ���ʱ��չʾ���
************************************************************************************************************/
class TkhdBox : public BaseBox
{
public:
	TkhdBox();
	~TkhdBox();

	virtual int ParseAttrs(byteptr &pData);

	static BaseBox* CreateObject();

public:
	int				m_iVersion;
	int				m_iFlags;
	int				m_iCreateTime;
	int				m_iModifyTime;
	int				m_iTrackID;
	string			m_strReserved1;
	int				m_iDuration;
	string			m_strReserved2;
	int				m_iLayer;
	int				m_iAlterGroup;
	double			m_dVolume;
	string			m_strReserved3;
	string			m_strMatrix;
	double			m_dWidth;
	double			m_dHeight;
};