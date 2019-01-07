#pragma once
#include "bytes.h"
#include <wtypes.h>

struct avih_data
{
	byte	strName[4];				// ����Ϊ��avih��
	DWORD	dwSize;					// �����ݽṹ�Ĵ�С�������������8���ֽڣ�fcc��cb������
	DWORD	dwIntervalTime;			// ��Ƶ֡���ʱ�䣨�Ժ���Ϊ��λ��
	DWORD	dwMaxBytesPerSec;		// ���AVI�ļ������������
	DWORD	dwPaddingGranularity;	// ������������
	DWORD	dwFlags;				// AVI�ļ���ȫ�ֱ�ǣ������Ƿ����������
	DWORD	dwTotalFrames;			// ��֡��
	DWORD	dwInitialFrames;		// Ϊ������ʽָ����ʼ֡�����ǽ�����ʽӦ��ָ��Ϊ0��
	DWORD	dwStreams;				// ���ļ����������ĸ���
	DWORD	dwSBuffSize;			// �����ȡ���ļ��Ļ����С��Ӧ���������Ŀ飩
	DWORD	dwWidth;				// ��Ƶͼ��Ŀ�������Ϊ��λ��
	DWORD	dwHeight;				// ��Ƶͼ��ĸߣ�������Ϊ��λ��
	byte	dwReserved[16];			// ����
};

// (��Ƶ����������)����Ƶ�������е���ʾλ��
// ��Ƶ��������AVIMAINHEADER�ṹ�е�dwWidth��dwHeight����
struct rectFrame
{
	short int left;
	short int top;
	short int right;
	short int bottom;
};

struct strh_data
{
	byte	strName[4];		// ����Ϊ��strh��
	DWORD	dwSize;			// �����ݽṹ�Ĵ�С�������������8���ֽڣ�fcc��cb������
	byte	strType[4];		// �������ͣ���auds������Ƶ��������vids������Ƶ��������mids����MIDI��������txts������������
	byte	strHandler[4];	// ָ�����Ĵ����ߣ���������Ƶ��˵���ǽ�����
	DWORD	dwFlags;		// ��ǣ��Ƿ�����������������ɫ���Ƿ�仯��
	WORD	wPriority;		// �������ȼ������ж����ͬ���͵���ʱ���ȼ���ߵ�ΪĬ������
	WORD	wLanguage;
	DWORD	dwIniFrames;	// Ϊ������ʽָ����ʼ֡��
	DWORD	dwScale;		// �����ʹ�õ�ʱ��߶�
	DWORD	dwRate;
	DWORD	dwStart;		// ���Ŀ�ʼʱ��
	DWORD	dwLength;		// ���ĳ��ȣ���λ��dwScale��dwRate�Ķ����йأ�
	DWORD	dwSBuffSize;	// ��ȡ��������ݽ���ʹ�õĻ����С
	DWORD	dwQuality;		// �����ݵ�����ָ�꣨0~10,000��
	DWORD	dwSampleSize;	// Sample�Ĵ�С
	
	rectFrame rcFrame;
};