#pragma once
#include "BaseBox.h"

#define HDLR_VERSION_SIZE				1
#define HDLR_FLAGS_SIZE					3
#define HDLR_PREDEFINED_SIZE			4
#define HDLR_HANDLERTYPE_SIZE			4
#define HDLR_RESERVED_SIZE				12

/************************************************************************************************************
**										hdlr
**
-------------------------------------------------------------------------------------------------------------
**		�ֶ�����			|	����(bytes)	|		�й�����
-------------------------------------------------------------------------------------------------------------
**		boxsize				|	4			|		box�ĳ���
**		boxtype				|	4			|		box������
**		version				|	1			|		box�汾0��1 һ��Ϊ0 (�����ֽ�������version=0)
**		flags				|	3			|
**		pre-defined			|	4			|
**		handler type		|	4			|		��media box�У���ֵΪ4���ַ�
													"vide"�� video track
													"soun"�� audio track
													"hint"�� hint track
**		reserved			|	12			|
**		name				|	����		|		track type name���ԡ�\0����β���ַ���
************************************************************************************************************/
class HdlrBox : public BaseBox
{
public:
	HdlrBox();
	~HdlrBox();

	virtual int ParseAttrs(byteptr &pData);

	static BaseBox* CreateObject();

public:
	int				m_iVersion;
	int				m_iFlags;
	int				m_iPreDefined;
	string			m_strHandlerType;
	string			m_strReserved;
	string			m_strName;
};
