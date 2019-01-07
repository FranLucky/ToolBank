#pragma once
#include <string>
#include <vector>
using namespace std;

typedef unsigned char byte;
typedef byte* byteptr;

struct Parameter
{
	byteptr	pData;
	int		iSize;
};

class BaseBox;
typedef vector<BaseBox*>	VecBoxs;
typedef vector<string>		VecStrs;
typedef vector<Parameter>	VecParameters;

#define min(a,b)            (((a) < (b)) ? (a) : (b))

#define BOXSIZE_SIZE			4			// box size: 4 bytes;
#define BOXTYPE_SIZE			4			// box type: 4 bytes;
#define BOXHEADER_SIZE			(BOXSIZE_SIZE + BOXTYPE_SIZE)		

struct box_header
{
	byte BoxSize[BOXSIZE_SIZE];
	byte BoxType[BOXTYPE_SIZE];
};

/********************************************************************************************
**		�ֶ�����			|	����(bytes)	|		�й�����
--------------------------------------------------------------------------------------------
**		boxsize				|	4			|		box�ĳ���
**		boxtype				|	4			|		box������
********************************************************************************************/
class BaseBox
{
public:
	BaseBox();
	virtual ~BaseBox();

	// �����ļ���Ϣ��ȡ ����ṹ��;
	static BaseBox* GetBoxFromFile(byteptr &pData);

	// ��pData���iCount�ֽ�ת��Ϊ����
	// bOffset ת����pData�Ƿ����iCount���ֽ�;
	// bBigEndian �������;
	static int BytesToIntEx(byteptr &pData, int iCount, bool bOffset = true, bool bBigEndian = true);

	static int BytesToInt(byte arrByte[], int iCount);

	// ��pData���iCount�ֽ�ת��Ϊ�ַ���;
	// bOffset ת����pData�Ƿ����iCount���ֽ�;
	static std::string BytesToStrEx(byteptr &pData, int iCount, bool bOffset = true);

	static std::string BytesToStr(byte arrByte[], int iCount);

	static std::string BytesToStr(char* pByte, int iCount);

	// iM, iN�ֱ��Ӧ������С��λ��;
	static double BytesToDoubleEx(byteptr &pData, int iM, int iN, bool bOffset = true);

	// iM, iN�ֱ��Ӧ������С��λ��;
	static double BytesToDouble(byte arrByte[], int iM, int iN);

	// ��iPos���iCountλ��ת��Ϊ����(�˴������ش���);
	static int BitsToIntEx(byteptr &pData, int iPos, int iCount, bool bOffset = true);

	// ������Ϻ�, ���ؽ��������ֽ���;
	virtual int ParseBox(byteptr &pData);

protected:

	virtual int ParseHeader(byteptr &pData);
	virtual int ParseAttrs(byteptr &pData);
	virtual int ParseChild(byteptr &pData);

	static BaseBox* CreateObject();

public:
	int			m_iBoxSize;				// Box ��С;
	string		m_strBoxType;			// Box ����;

	VecBoxs		m_vecBoxs;				// �� Box;
};