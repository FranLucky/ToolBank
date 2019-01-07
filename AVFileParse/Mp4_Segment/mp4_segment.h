#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <inttypes.h>
#include <string.h>
#include <string>

#define IN	
#define OUT	

struct mp4Buffer
{
	unsigned int		m_iSize;
	unsigned char*		m_pBuff;
};

/************************************************************************************************************
*	@brief		: �ָ�mp4�ļ�(��ȡiStartTime~iEndTime���ڵ�����Ƶ���ݲ�������װ��С��mp4�ļ�)
*	@author		: sunc
*	@date		: 2017/7/17 17:33
*	@version	: ver 1.0
*	@param		: 
				outMp4		:		�����mp4buffer
				inMp4		:		�����mp4buffer
				fStartTime	:		��ȡ�Ŀ�ʼʱ��;
				fEndTime	:		��ȡ�Ľ���ʱ��;

*	@return	:
				�ɹ�����true, ʧ�ܷ���false;

************************************************************************************************************/
bool mp4_segment(OUT mp4Buffer& outMp4, IN mp4Buffer& inMp4, IN float fStartTime, IN float fEndTime);
