#pragma once
#include "BaseBox.h"

#define VMHD_VERSION_SIZE			1
#define VMHD_FLAGS_SIZE				3
#define VMHD_GRAPHICSMODE_SIZE		4
#define VMHD_OPCOLOR_SIZE			4

/************************************************************************************************************
**										vmhd
**
-------------------------------------------------------------------------------------------------------------
**		�ֶ�����			|	����(bytes)	|		�й�����
-------------------------------------------------------------------------------------------------------------
**		boxsize				|	4			|		box�ĳ���
**		boxtype				|	4			|		box������
**		version				|	1			|		box�汾0��1 һ��Ϊ0 (�����ֽ�������version=0)
**		flags				|	3			|
**		graphics_mode		|	4			|		��Ƶ�ϳ�ģʽ��Ϊ0ʱ����ԭʼͼ�񣬷�����opcolor���кϳ�
**		opcolor				|	2 ��3		|		��red��green��blue��
************************************************************************************************************/
class VmhdBox : public BaseBox
{
public:
	VmhdBox();
	~VmhdBox();

	virtual int ParseAttrs(byteptr &pData);

	static BaseBox* CreateObject();

public:
	int				m_iVersion;
	int				m_iFlags;
	int				m_iGraphicsMode;
	int				m_iRed;
	int				m_iGreen;
	int				m_iBlue;
};
