#include "TagAudio.h"

CTagAudio::CTagAudio()
{
}

CTagAudio::~CTagAudio()
{
}

/************************************************************************************************************
	��һ���ֽ�����Ƶ��Ϣ��ʽ,��ʽ����;

	����			����					����;
	
	��Ƶ��ʽ		4 bits					
											0 = Linear PCM, platform endian
											1 = ADPCM
											2 = MP3
											3 = Linear PCM, little endian
											4 = Nellymoser 16-kHz mono
											5 = Nellymoser 8-kHz mono
											6 = Nellymoser
											7 = G.711 A-law logarithmic PCM
											8 = G.711 mu-law logarithmic PCM
											9 = reserved
											10 = AAC
											11 = Speex
											14 = MP3 8-Khz
											15 = Device-specific sound

	������			2 bits					(����AAC����3)
											0 = 5.5-kHz
											1 = 11-kHz
											2 = 22-kHz
											3 = 44-kHz

	�����ĳ���		1 bit					(ѹ��������Ƶ����16bit)
											0 = snd8Bit
											1 = snd16Bit

	��Ƶ����		1 bit					(����AAC����1)
											0 = sndMono
											1 = sndStereo

	�ڶ����ֽڿ�ʼ������Ƶ��������;
************************************************************************************************************/
void CTagAudio::Display()
{
	// ������Ƶ��ʽ;
	byte audioHeader = m_pData[0];
	char strAudioInfo[100] = { 0 };
	{
		byte audioFormat = audioHeader >> 4;
		switch (audioFormat)
		{
		case 0:strcat(strAudioInfo, "Linear PCM, platform endian"); break;
		case 1:strcat(strAudioInfo, "ADPCM"); break;
		case 2:strcat(strAudioInfo, "MP3"); break;
		case 3:strcat(strAudioInfo, "Linear PCM, little endian"); break;
		case 4:strcat(strAudioInfo, "Nellymoser 16-kHz mono"); break;
		case 5:strcat(strAudioInfo, "Nellymoser 8-kHz mono"); break;
		case 6:strcat(strAudioInfo, "Nellymoser"); break;
		case 7:strcat(strAudioInfo, "G.711 A-law logarithmic PCM"); break;
		case 8:strcat(strAudioInfo, "G.711 mu-law logarithmic PCM"); break;
		case 9:strcat(strAudioInfo, "reserved"); break;
		case 10:strcat(strAudioInfo, "AAC"); break;
		case 11:strcat(strAudioInfo, "Speex"); break;
		case 14:strcat(strAudioInfo, "MP3 8-Khz"); break;
		case 15:strcat(strAudioInfo, "Device-specific sound"); break;
		default:strcat(strAudioInfo, "UNKNOWN"); break;
		}
		strcat(strAudioInfo, "| ");
	}

	{
		byte sampBits = audioHeader << 4;
		sampBits = sampBits >> 6;
		switch (sampBits)
		{
		case 0:strcat(strAudioInfo, "5.5-kHz"); break;
		case 1:strcat(strAudioInfo, "1-kHz"); break;
		case 2:strcat(strAudioInfo, "22-kHz"); break;
		case 3:strcat(strAudioInfo, "44-kHz"); break;
		default:strcat(strAudioInfo, "UNKNOWN"); break;
		}
		strcat(strAudioInfo, "| ");
	}

	{
		byte sampLen = audioHeader << 6;
		sampLen = sampLen >> 7;
		switch (sampLen)
		{
		case 0:strcat(strAudioInfo, "8Bit"); break;
		case 1:strcat(strAudioInfo, "16Bit"); break;
		default:strcat(strAudioInfo, "UNKNOWN"); break;
		}
		strcat(strAudioInfo, "| ");
	}

	{
		byte audioType = audioHeader << 7;
		audioType = audioType >> 7;
		switch (audioType)
		{
		case 0:strcat(strAudioInfo, "Mono"); break;
		case 1:strcat(strAudioInfo, "Stereo"); break;
		default:strcat(strAudioInfo, "UNKNOWN"); break;
		}
		strcat(strAudioInfo, "| ");
	}

	printf("\t %s \n\t audio data: %d bytes \n", strAudioInfo, m_iSize - 1);
}