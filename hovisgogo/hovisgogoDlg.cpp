
// hovisgogoDlg.cpp : 구현 파일
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

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// ChovisgogoDlg 대화 상자




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


// ChovisgogoDlg 메시지 처리기

BOOL ChovisgogoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_combo_comport_list.AddString(_T("COM1"));
	m_combo_comport_list.AddString(_T("COM2"));
	m_combo_comport_list.AddString(_T("COM3"));
	m_combo_comport_list.AddString(_T("COM4"));
	m_combo_comport_list.AddString(_T("COM5"));

	m_combo_baudrate_list.AddString(_T("9600"));
	m_combo_baudrate_list.AddString(_T("19200"));
	m_combo_baudrate_list.AddString(_T("115200"));
	
	m_background.LoadBitmapW(IDB_BITMAP);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void ChovisgogoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR ChovisgogoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void ChovisgogoDlg::OnBnClickedButtonConnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nResult, nIndexcom, nIndexbaud;										// 결과값을 리턴받을 변수
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

	// 초기화 - 로봇제어를 하기위해 반드시 앞 부분에 선언한다.
	nResult = initialize(comport, baudrate);			// 각 변수들을 초기화 한다.	
	if(nResult == 0){									// 열고 난 이후 이상이 있는 지 확인한다.
		MessageBox(_T("Initialization Failed"));				// 이상이 있다면 에러 출력
		checkconnect = false;
		return;											// 프로그램 종료
	}
	else{
		checkconnect = true;
		MessageBox(_T("Success Connect"));
	}
}


void ChovisgogoDlg::OnBnClickedButtonDisconnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
			g_fMotorPos[i]=0;								// 모든 모터(16개 모터)를 0 위치로 설정함
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
		run(1000);											// 모터 동작(해당 자세를 1000ms 동안 동작)
		delay(1000);										// 동작 대기(1000ms)
	}
}


BOOL ChovisgogoDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog dlg(TRUE,_T("txt"),_T("*.txt"),OFN_HIDEREADONLY,_T("txt 파일(*.txt)|*.txt|모든파일(*.*)|*.*|"));
	
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
