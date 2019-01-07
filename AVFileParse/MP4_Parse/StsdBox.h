#pragma once
#include "BaseBox.h"

#define STSD_VERSION_SIZE				1
#define STSD_FLAGS_SIZE					3
#define STSD_ENTRYCOUNT_SIZE			4

/************************************************************************************************************
**										stsd
**
-------------------------------------------------------------------------------------------------------------
**		�ֶ�����			|	����(bytes)	|		�й�����
-------------------------------------------------------------------------------------------------------------
**		boxsize				|	4			|		box�ĳ���
**		boxtype				|	4			|		box������
**		version				|	1			|		box�汾0��1 һ��Ϊ0 (�����ֽ�������version=0)
**		flags				|	3			|
**		entry_count			|	4			|		
************************************************************************************************************/
class StsdBox : public BaseBox
{
public:
	StsdBox();
	~StsdBox();

	virtual int ParseAttrs(byteptr &pData);

	static BaseBox* CreateObject();

public:
	int				m_iVersion;
	int				m_iFlags;
	int				m_iEntryCount;
};