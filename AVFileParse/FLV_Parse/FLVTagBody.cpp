#include "FLVTagBody.h"
#include "TagAudio.h"
#include "TagVideo.h"
#include "TagScript.h"

CFLVTagBody::CFLVTagBody()
{
	m_pTag = NULL;
}

CFLVTagBody::~CFLVTagBody()
{
	if (m_pTag)
	{
		delete m_pTag;
		m_pTag = NULL;
	}
}

int CFLVTagBody::ReadData(byte_ptr &pData, int iTagSize, int iTagType)
{
	switch (iTagType)
	{
	case TAG_TYPE_AUDIO:	// ��Ƶ;
		{
			m_pTag = new CTagAudio();
		}
		break;
	case TAG_TYPE_VIDEO:	// ��Ƶ;
		{
			m_pTag = new CTagVideo();
		}
		break;
	case TAG_TYPE_SCRIPT:	// �ű�, �Զ�������;
		{
			m_pTag = new CTagScript();
		}
		break;
	default:
		{
			printf("\t unknown tagtype �� %d \n", iTagType);
			return -1;
		}
		break;
	}

	if (m_pTag)
	{
		int iParseSize = m_pTag->ReadData(pData, iTagSize);
		assert(iParseSize == iTagSize);
	}
	else
	{
		// ����ʶ������,������;
		pData += iTagSize;
	}

	return iTagSize;
}

int CFLVTagBody::WriteData(byte_ptr &pData)
{
	int iSize = -1;
	if (m_pTag)
	{
		iSize = m_pTag->WriteData(pData);
	}
	return iSize;
}

void CFLVTagBody::Display()
{
	if (m_pTag)
	{
		m_pTag->Display();
	}
}

bool CFLVTagBody::IsKeyFrame()
{
	bool bIsKeyFrame = false;
	if (m_pTag)
	{
		bIsKeyFrame = m_pTag->IsKeyFrame();
	}
	return bIsKeyFrame;
}