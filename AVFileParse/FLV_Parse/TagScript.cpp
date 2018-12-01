#include "TagScript.h"


CTagScript::CTagScript()
{
}

CTagScript::~CTagScript()
{
}

void CTagScript::Display()
{
	// ����������Ϣ;
	byte* pTemp = m_pData;
	byte* pEnd = pTemp + m_iSize;

	while (pTemp < pEnd)
	{
		byte DataType = pTemp[0];
		pTemp = pTemp + 1;		// �������� ����һλ;
		switch (DataType)
		{
		case AMF_NUMBER:		// ����(double);
			break;
		case AMF_BOOLEAN:		// ����;
			break;
		case AMF_STRING:		// �ַ���;
			{
				AVal strName;
				AMF_DecodeString((char*)pTemp, &strName);
				pTemp = pTemp + (strName.av_len + 2);

				printf("\t %s : \n", BytesToStr((byte_ptr)strName.av_val, strName.av_len).c_str());
			}
			break;
		case AMF_OBJECT:		// ����;
		case AMF_MOVIECLIP:		// ����,δʹ��;
			break;
			// AMF_NULL,				// null;
			// AMF_UNDEFINED,			// δ����;
			// AMF_REFERENCE,			// ����;
		case AMF_ECMA_ARRAY:			// ����;
			{
				// ����Ԫ�ظ���;
				int iArrCount = BytesToInt(pTemp, 4);
				pTemp = pTemp + 4;

				AMFObject objTemp;
				int iSize = pEnd - pTemp;
				int nRes = AMF_DecodeArray(&objTemp, (char*)pTemp, iSize, iArrCount, TRUE);
				if (nRes == -1)
				{
					return;
				}
				pTemp = pTemp + iSize;

				// ���;
				printf("\t { \n");
				for (int i = 0; i < iArrCount; i++)
				{
					switch (objTemp.o_props[i].p_type)
					{
					case AMF_NUMBER:			// ����(double);
						{
							printf("\t     %s : %.0f\n", BytesToStr((byte_ptr)objTemp.o_props[i].p_name.av_val, objTemp.o_props[i].p_name.av_len).c_str(), objTemp.o_props[i].p_vu.p_number);
						}
						break;
					case AMF_STRING:			// �ַ���; 
						{
							std::string strValue(objTemp.o_props[i].p_vu.p_aval.av_val, objTemp.o_props[i].p_vu.p_aval.av_len);
							printf("\t     %s : %s\n", BytesToStr((byte_ptr)objTemp.o_props[i].p_name.av_val, objTemp.o_props[i].p_name.av_len).c_str(), strValue.c_str());
						}
						break;
					default:
						break;
					}
				}
				printf("\t } \n");
			}
			break;
			// AMF_OBJECT_END,			// �������(0x09);
			// AMF_STRICT_ARRAY,		// �ϸ������;
			// AMF_DATE,				// ����;
			// AMF_LONG_STRING,			// ���ַ���;
			// AMF_UNSUPPORTED,			// δ֧��;
			// AMF_RECORDSET,			// ����,δʹ��;
			// AMF_XML_DOC,				// xml�ĵ�;
			// AMF_TYPED_OBJECT,		// �����͵Ķ���;
			// AMF_AVMPLUS,				// ��Ҫ��չ��AMF3;
			// AMF_INVALID = 0xff		// ��Ч��;
		default:
			break;
		}
	}
}
