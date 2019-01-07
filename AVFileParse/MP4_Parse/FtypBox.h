#pragma once
#include "BaseBox.h"

#define FTYP_MAJORBRAND_SIZE		4
#define FTYP_MINORVERSION_SIZE		4
#define FTYP_COMPBRAND_SIZE			4

/********************************************************************************************
**							File Type Box (ftyp)
**
--------------------------------------------------------------------------------------------
**		�ֶ�����			|	����(bytes)	|		�й�����
--------------------------------------------------------------------------------------------
**		boxsize				|	4			|		box�ĳ���
**		boxtype				|	4			|		box������
**		major_brand			|	4			|
**		minor_version		|	4			|		�汾��
**		compatible_brands	|	4 * N		|		���ļ���ӵĶ���Э�飨ismo, iso2, mp41��
********************************************************************************************/
class FtypBox : public BaseBox
{
public:
	FtypBox();
	virtual ~FtypBox();

	virtual int ParseAttrs(byteptr &pData);

	static BaseBox* CreateObject();

public:
	string				m_strMajorBrand;
	int					m_iMinorVersion;
	vector<string>		m_vecCompBrands;
};