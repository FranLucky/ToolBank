#pragma once
#include "TagType.h"
#include "amf.h"
#include <vector>

class CTagScript : public CTagType
{
public:
	CTagScript();
	~CTagScript();

	// ��ʾ;
	virtual void Display();
};