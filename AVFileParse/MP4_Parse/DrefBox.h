#pragma once
#include "BaseBox.h"

#define DREF_VERSION_SIZE				1
#define DREF_FLAGS_SIZE					3
#define DREF_ENTRYCOUNT_SIZE			4

/************************************************************************************************************
							Dref Box

version					1					box�汾 0��1 һ��Ϊ0.�������ֽ�������version=0��
flags					3					
entry count				4					"url"��"urn"���Ԫ�ظ���
"url"��"urn"�б�		����
************************************************************************************************************/
class DrefBox : public BaseBox
{
public:
	DrefBox();
	~DrefBox();

	virtual int ParseAttrs(byteptr &pData);

	static BaseBox* CreateObject();

public:
	int				m_iVersion;
	int				m_iFlags;
	int				m_iEntryCount;
};