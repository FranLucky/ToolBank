#pragma once
#include "TagType.h"

class CTagVideo : public CTagType
{
public:
	CTagVideo();
	~CTagVideo();

	// ��ʾ;
	virtual void Display();

	// �Ƿ���Ƶ�Ĺؼ�֡;
	virtual bool IsKeyFrame();
};