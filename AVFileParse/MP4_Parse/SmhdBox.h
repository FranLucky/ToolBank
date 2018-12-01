#pragma once
#include "BaseBox.h"

#define SMHD_VERSION_SIZE			1
#define SMHD_FLAGS_SIZE				3
#define SMHD_BALANCE_SIZE			2
#define SMHD_RESERVED_SIZE			2

/************************************************************************************************************
							Smhd Box

version					1					box�汾��0��1��һ��Ϊ0���������ֽ�������version=0��
flags					3
balance					2					������ƽ�⣬[8.8] ��ʽֵ��һ��Ϊ0��-1.0��ʾȫ����������1.0��ʾȫ��������
reserved				2
************************************************************************************************************/
class SmhdBox : public BaseBox
{
public:
	SmhdBox();
	~SmhdBox();

	virtual int ParseAttrs(byteptr &pData);

	static BaseBox* CreateObject();

public:
	int				m_iVersion;
	int				m_iFlags;
	double			m_dBalance;
	string			m_strReserved;
};