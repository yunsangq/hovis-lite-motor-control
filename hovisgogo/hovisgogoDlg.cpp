
// hovisgogoDlg.cpp : ���� ����
//

#include <stdio.h>
#include "stdafx.h"
#include "hovisgogo.h"
#include "hovisgogoDlg.h"
#include "afxdialogex.h"
#include "hovis.h"

#pragma comment(lib, "drapi.lib")

//#include <iostream>
//#include <vector>
//#include <afxwin.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//using std::vector;
bool checkconnect=false;

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ChovisgogoDlg ��ȭ ����




ChovisgogoDlg::ChovisgogoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ChovisgogoDlg::IDD, pParent)
	, m_edit_id2(0)
	, m_edit_id1(0)
	, m_edit_id0(0)
	, m_edit_id3(0)
	, m_edit_id4(0)
	, m_edit_id5(0)
	, m_edit_id6(0)
	, m_edit_id7(0)
	, m_edit_id8(0)
	, m_edit_id10(0)
	, m_edit_id9(0)
	, m_edit_id11(0)
	, m_edit_id12(0)
	, m_edit_id13(0)
	, m_edit_id15(0)
	, m_edit_id14(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void ChovisgogoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_COMPORT, m_combo_comport_list);
	DDX_Control(pDX, IDC_COMBO_BAUDRATE, m_combo_baudrate_list);
	DDX_Text(pDX, IDC_EDIT_ID2, m_edit_id2);
	DDV_MinMaxFloat(pDX, m_edit_id2, -159, 159);
	DDX_Text(pDX, IDC_EDIT_ID1, m_edit_id1);
	DDV_MinMaxFloat(pDX, m_edit_id1, -159, 159);
	DDX_Text(pDX, IDC_EDIT_ID0, m_edit_id0);
	DDV_MinMaxFloat(pDX, m_edit_id0, -159, 159);
	DDX_Text(pDX, IDC_EDIT_ID3, m_edit_id3);
	DDV_MinMaxFloat(pDX, m_edit_id3, -159, 159);
	DDX_Text(pDX, IDC_EDIT_ID4, m_edit_id4);
	DDV_MinMaxFloat(pDX, m_edit_id4, -159, 159);
	DDX_Text(pDX, IDC_EDIT_ID5, m_edit_id5);
	DDV_MinMaxFloat(pDX, m_edit_id5, -159, 159);
	DDX_Text(pDX, IDC_EDIT_ID6, m_edit_id6);
	DDV_MinMaxFloat(pDX, m_edit_id6, -159, 159);
	DDX_Text(pDX, IDC_EDIT_ID7, m_edit_id7);
	DDV_MinMaxFloat(pDX, m_edit_id7, -159, 159);
	DDX_Text(pDX, IDC_EDIT_ID8, m_edit_id8);
	DDV_MinMaxFloat(pDX, m_edit_id8, -159, 159);
	DDX_Text(pDX, IDC_EDIT_ID10, m_edit_id10);
	DDV_MinMaxFloat(pDX, m_edit_id10, -159, 159);
	DDX_Text(pDX, IDC_EDIT_ID9, m_edit_id9);
	DDV_MinMaxFloat(pDX, m_edit_id9, -159, 159);
	DDX_Text(pDX, IDC_EDIT_ID11, m_edit_id11);
	DDV_MinMaxFloat(pDX, m_edit_id11, -159, 159);
	DDX_Text(pDX, IDC_EDIT_ID12, m_edit_id12);
	DDV_MinMaxFloat(pDX, m_edit_id12, -159, 159);
	DDX_Text(pDX, IDC_EDIT_ID13, m_edit_id13);
	DDV_MinMaxFloat(pDX, m_edit_id13, -159, 159);
	DDX_Text(pDX, IDC_EDIT_ID15, m_edit_id15);
	DDV_MinMaxFloat(pDX, m_edit_id15, -159, 159);
	DDX_Text(pDX, IDC_EDIT_ID14, m_edit_id14);
	DDV_MinMaxFloat(pDX, m_edit_id14, -159, 159);
}

BEGIN_MESSAGE_MAP(ChovisgogoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &ChovisgogoDlg::OnBnClickedButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_DISCONNECT, &ChovisgogoDlg::OnBnClickedButtonDisconnect)
	ON_WM_ERASEBKGND()
ON_BN_CLICKED(IDC_BUTTON_SET, &ChovisgogoDlg::OnBnClickedButtonSet)
ON_BN_CLICKED(IDC_BUTTON_OPEN, &ChovisgogoDlg::OnBnClickedButtonOpen)
END_MESSAGE_MAP()


// ChovisgogoDlg �޽��� ó����

BOOL ChovisgogoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_combo_comport_list.AddString(_T("COM1"));
	m_combo_comport_list.AddString(_T("COM2"));
	m_combo_comport_list.AddString(_T("COM3"));
	m_combo_comport_list.AddString(_T("COM4"));
	m_combo_comport_list.AddString(_T("COM5"));

	m_combo_baudrate_list.AddString(_T("9600"));
	m_combo_baudrate_list.AddString(_T("19200"));
	m_combo_baudrate_list.AddString(_T("115200"));
	
	m_background.LoadBitmapW(IDB_BITMAP);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void ChovisgogoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void ChovisgogoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR ChovisgogoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void ChovisgogoDlg::OnBnClickedButtonConnect()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int nResult, nIndexcom, nIndexbaud;										// ������� ���Ϲ��� ����
	CString comport, strbaudrate;
	DWORD baudrate;

	nIndexcom=m_combo_comport_list.GetCurSel();
	if(nIndexcom==-1)
		return;

	nIndexbaud=m_combo_baudrate_list.GetCurSel();
	if(nIndexbaud==-1)
		return;

	m_combo_comport_list.GetLBText(nIndexcom, comport);
	m_combo_baudrate_list.GetLBText(nIndexbaud, strbaudrate);

	baudrate = (DWORD)_ttoi((LPCTSTR)strbaudrate);

	// �ʱ�ȭ - �κ���� �ϱ����� �ݵ�� �� �κп� �����Ѵ�.
	nResult = initialize(comport, baudrate);			// �� �������� �ʱ�ȭ �Ѵ�.	
	if(nResult == 0){									// ���� �� ���� �̻��� �ִ� �� Ȯ���Ѵ�.
		MessageBox(_T("Initialization Failed"));				// �̻��� �ִٸ� ���� ���
		checkconnect = false;
		return;											// ���α׷� ����
	}
	else{
		checkconnect = true;
		MessageBox(_T("Success Connect"));
	}
}


void ChovisgogoDlg::OnBnClickedButtonDisconnect()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(checkconnect==true){
		terminate();
		checkconnect=false;
		MessageBox(_T("Disconnect"));
	}
	else
		MessageBox(_T("Not Connected"));
}


BOOL ChovisgogoDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CDialogEx::OnEraseBkgnd(pDC);

	if(!m_background.m_hObject)
		return true;

	CRect rect;
	GetClientRect(&rect);

	CDC dc;
	dc.CreateCompatibleDC(pDC);
	CBitmap* pOldBitmap = dc.SelectObject(&m_background);

	BITMAP bmap;
	m_background.GetBitmap(&bmap);
	pDC->StretchBlt(0,50,rect.Width(),rect.Height()-50,&dc,0,0,bmap.bmWidth,bmap.bmHeight,SRCCOPY);

	dc.SelectObject(pOldBitmap);
	return true;
	
	return CDialogEx::OnEraseBkgnd(pDC);
}



void ChovisgogoDlg::OnBnClickedButtonSet()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	float id0=0,id1=0,id2=0,id3=0,id4=0,id5=0;
	float id6=0,id7=0,id8=0,id9=0,id10=0,id11=0;
	float id12=0,id13=0,id14=0,id15=0;

	if(checkconnect==false){
		MessageBox(_T("Not Connected"));
	}
	else{
		UpdateData();
		id0=m_edit_id0;
		id1=m_edit_id1;
		id2=m_edit_id2;
		id3=m_edit_id3-4;
		id4=m_edit_id4+3;
		id5=m_edit_id5;
		id6=m_edit_id6;
		id7=m_edit_id7;
		id8=m_edit_id8;
		id9=m_edit_id9;
		id10=m_edit_id10;
		id11=m_edit_id11-2;
		id12=m_edit_id12;
		id13=m_edit_id13;
		id14=m_edit_id14;
		id15=m_edit_id15;
		UpdateData(FALSE);

		for(int i=0;i<16;i++){
			g_fMotorPos[i]=0;								// ��� ����(16�� ����)�� 0 ��ġ�� ������
		}

		g_fMotorPos[0] = id0;
		g_fMotorPos[1] = id1;
		g_fMotorPos[2] = id2;
		g_fMotorPos[3] = id3;
		g_fMotorPos[4] = id4;
		g_fMotorPos[5] = id5;
		g_fMotorPos[6] = id6;
		g_fMotorPos[7] = id7;
		g_fMotorPos[8] = id8;
		g_fMotorPos[9] = id9;
		g_fMotorPos[10] = id10;
		g_fMotorPos[11] = id11;
		g_fMotorPos[12] = id12;
		g_fMotorPos[13] = id13;
		g_fMotorPos[14] = id14;
		g_fMotorPos[15] = id15;
		run(1000);											// ���� ����(�ش� �ڼ��� 1000ms ���� ����)
		delay(1000);										// ���� ���(1000ms)
	}
}


BOOL ChovisgogoDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if(pMsg->message == WM_KEYDOWN)
	{
		if(pMsg->wParam == VK_RETURN)
			return TRUE;
		if(pMsg->wParam == VK_ESCAPE)
			return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

void ChovisgogoDlg::OnBnClickedButtonOpen()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CFileDialog dlg(TRUE,_T("txt"),_T("*.txt"),OFN_HIDEREADONLY,_T("txt ����(*.txt)|*.txt|�������(*.*)|*.*|"));
	
	if(dlg.DoModal()==IDOK)
	{
		CString Filename = dlg.GetPathName();
		MessageBox(_T("OPEN "+Filename));
		/*
		CStdioFile File;
		CString oneline;
		vector<CString> list;

		File.Open(Filename, CFile::modeRead);
		
		list.push_back(File.GetFilePath());

		int cnt=0;

		CString splitStr;
		while(File.ReadString(oneline)){
			int cutPos=0;
			while(cutPos>=0){
				splitStr = oneline.Tokenize(_T(" "), cutPos);
			}
		}

		MessageBox(splitStr);
		File.Close();
		*/

	}
}
