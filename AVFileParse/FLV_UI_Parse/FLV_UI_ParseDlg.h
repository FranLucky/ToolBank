
// FLV_UI_ParseDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "FLVFile.h"

enum COL_NAME
{
	COL_INDEX = 0,
	COL_TYPE,
	COL_TIME,
	COL_CODE,
	COL_FRAME,
	COL_SIZE,
	COL_COUNT
};

// CFLV_UI_ParseDlg �Ի���
class CFLV_UI_ParseDlg : public CDialogEx
{
// ����
public:
	CFLV_UI_ParseDlg(CWnd* pParent = NULL);
	~CFLV_UI_ParseDlg();

	enum { IDD = IDD_FLV_UI_PARSE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedMfcbuttonOpenpath();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnCustomdrawList(NMHDR*, LRESULT*);
public:
	CListCtrl m_list;
	CEdit m_edtPath;

	CFLVFile*	m_pFlvFile;
};
