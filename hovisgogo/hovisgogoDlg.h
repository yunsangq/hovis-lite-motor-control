
// hovisgogoDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// ChovisgogoDlg ��ȭ ����
class ChovisgogoDlg : public CDialogEx
{
// �����Դϴ�.
public:
	ChovisgogoDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	CBitmap m_background;

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_HOVISGOGO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
