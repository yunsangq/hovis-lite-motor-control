
// hovisgogoDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// ChovisgogoDlg 대화 상자
class ChovisgogoDlg : public CDialogEx
{
// 생성입니다.
public:
	ChovisgogoDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	CBitmap m_background;

// 대화 상자 데이터입니다.
	enum { IDD = IDD_HOVISGOGO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo_comport_list;
	CComboBox m_combo_baudrate_list;
	afx_msg void OnBnClickedButtonConnect();
	afx_msg void OnBnClickedButtonDisconnect();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedButtonSet();
	float m_edit_id2;
	float m_edit_id1;
	float m_edit_id0;
	float m_edit_id3;
	float m_edit_id4;
	float m_edit_id5;
	float m_edit_id6;
	float m_edit_id7;
	float m_edit_id8;
	float m_edit_id10;
	float m_edit_id9;
	float m_edit_id11;
	float m_edit_id12;
	float m_edit_id13;
	float m_edit_id15;
	float m_edit_id14;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonOpen();
};
