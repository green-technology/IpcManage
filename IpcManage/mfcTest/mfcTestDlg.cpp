
// mfcTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "mfcTest.h"
#include "mfcTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CmfcTestDlg 对话框




CmfcTestDlg::CmfcTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CmfcTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pRpcClient = nullptr;
	
}

void CmfcTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOGIN, &CmfcTestDlg::OnBnClickedLogin)
	ON_BN_CLICKED(IDC_GETRESLIST, &CmfcTestDlg::OnBnClickedGetreslist)
	ON_BN_CLICKED(IDC_LEFT, &CmfcTestDlg::OnBnClickedLeft)
	ON_BN_CLICKED(IDC_RIGHT, &CmfcTestDlg::OnBnClickedRight)
	ON_BN_CLICKED(IDC_DOWN, &CmfcTestDlg::OnBnClickedDown)
	ON_BN_CLICKED(IDC_ADDDEVRES, &CmfcTestDlg::OnBnClickedAdddevres)
	ON_BN_CLICKED(IDC_DELDEVRES, &CmfcTestDlg::OnBnClickedDeldevres)
	ON_BN_CLICKED(IDC_CLEARDEVS, &CmfcTestDlg::OnBnClickedCleardevs)
	ON_BN_CLICKED(IDCANCEL, &CmfcTestDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_REQUESTPTZCONTROL, &CmfcTestDlg::OnBnClickedRequestptzcontrol)
	ON_BN_CLICKED(IDC_UP, &CmfcTestDlg::OnBnClickedUp)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CmfcTestDlg 消息处理程序

BOOL CmfcTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmfcTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CmfcTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CmfcTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmfcTestDlg::OnBnClickedLogin()
{
	UserLoginReturnStruct stuUserLoginR;
	boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
	socket->setSendTimeout(TIMEOUT);
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
	bool bRet;

	try
	{
		if (m_pRpcClient == NULL)
		{
			m_pRpcClient = new IpcManageServerClient(protocol);
		}

		m_pRpcClient->setProtocol(protocol);
		transport->open();

		m_pRpcClient->UserLogin(stuUserLoginR,"test");

		if (stuUserLoginR.ErrorNum == TRUE)
		{
			cout<<"UserLogin Success! ++++++++++++++++++++++++++++"<<endl;
			cout<<" "<<endl;
			m_stuUserVerification.UserID = stuUserLoginR.UserID;			
			m_stuUserVerification.SessionID = stuUserLoginR.SessionID;
			bRet = true;
		}
	}
	catch(apache::thrift::transport::TTransportException &exc)
	{
		MessageBox(_T("登录异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		bRet = false;
	}
	catch (...)
	{
		bRet = false;
	}

	if(transport != NULL)
	{
		transport->close();
	}

}


void CmfcTestDlg::OnBnClickedGetreslist()
{
	boost::shared_ptr<TSocket> socket(new TSocket(SERVERIP,SERVERPORT));
	socket->setSendTimeout(TIMEOUT);
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	try
	{
		if (m_pRpcClient == NULL)
		{
			m_pRpcClient = new IpcManageServerClient(protocol);
		}

		m_pRpcClient->setProtocol(protocol);

		transport->open();

		if (m_stuUserVerification.UserID.length() == 0)
		{
			MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
			return;
		}

		m_vResInfo.clear();
		m_pRpcClient->GetResInfoList(m_vResInfo,m_stuUserVerification,ResourceType::ResourceTypeIPC);

		cout<<"GetResInfoList was executed---------------"<<endl;

		if (m_vResInfo.size()==0)
		{
			transport->close();
			cout<<"There is not available res"<<"\n"<<endl;
			//MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
			return ;
		}
		else
		{
			cout<<"before deleteResource:"
				<<"m_vResInfo.size"<<m_vResInfo.size()<<endl;
			ResourceInfoReturnStruct resInfo;
			for (int i=0;i<m_vResInfo.size();i++)
			{
				resInfo = m_vResInfo.at(i);
				cout<<"ResInfo"<<i<<": "
					<<resInfo.deviceName
					<<resInfo.IP
					<<resInfo.hResource
					<<resInfo.resourceType
					<<" id: "<<resInfo.ID
					<<endl;
			}
			cout<<" "<<endl;
		}

	}
	catch (...)
	{
		MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);

		return;
	}

	if(transport != NULL)
	{
		transport->close();
	}

	return;
}


void CmfcTestDlg::OnBnClickedRequestptzcontrol()
{
	boost::shared_ptr<TSocket> socket(new TSocket(SERVERIP,SERVERPORT));
	socket->setSendTimeout(TIMEOUT);
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	try
	{
		if (m_pRpcClient == NULL)
		{
			m_pRpcClient = new IpcManageServerClient(protocol);
		}

		m_pRpcClient->setProtocol(protocol);

		transport->open();

		if (m_stuUserVerification.UserID.length() == 0)
		{
			MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

		if (m_vResInfo.size() != 0)
		{
			RequestPTZControlDataPacket rqPTZ;
			rqPTZ.hResource = m_vResInfo[0].hResource;
			m_pRpcClient->RequestPTZControl(m_reqPTZctl, m_stuUserVerification,rqPTZ);

			cout<<"RequestPTZControl was exectued ------------------------"<<endl;
			cout<<"ptzhandle:"<<m_reqPTZctl.hPTZ
				<<endl;
			cout<<" "<<endl;
		}
		else
		{
			cout<<"There is not available dev"<<"\n"<<endl;
		}
	}
	catch (...)
	{
		MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
	}

	if(transport != NULL)
	{
		transport->close();
	}
}


void CmfcTestDlg::OnBnClickedLeft()
{
	boost::shared_ptr<TSocket> socket(new TSocket(SERVERIP,SERVERPORT));
	socket->setSendTimeout(TIMEOUT);
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	try
	{
		if (m_pRpcClient == NULL)
		{
			m_pRpcClient = new IpcManageServerClient(protocol);
		}

		m_pRpcClient->setProtocol(protocol);

		transport->open();

		if (m_stuUserVerification.UserID.length() == 0)
		{
			MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

		PTZControlDataPacket cmd;
		cmd.hPTZ = m_reqPTZctl.hPTZ;
		cmd.command = PTZCommand::PTZ_LEFT;
		cmd.param1 = 0;
		cmd.param2 = 7;
		cmd.param3 = 0;
		cmd.dwStop = false;
		PTZControlReturnStruct rtn_cmd;
		m_pRpcClient->PTZControl(rtn_cmd, m_stuUserVerification, cmd);

		cout<<"PTZControl:"<< cmd.command<<" was executed!++++++++++++++"<<endl; 
		cout<<" "<<endl;

		//if (!m_pRpcClient->UserLogout(m_stuUserVerification))
		{
			MessageBox(_T("UserLogout 异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

	}
	catch (...)
	{
		MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);

	}

	if(transport != NULL)
	{
		transport->close();
	}
}


void CmfcTestDlg::OnBnClickedRight()
{
	boost::shared_ptr<TSocket> socket(new TSocket(SERVERIP,SERVERPORT));
	socket->setSendTimeout(TIMEOUT);
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	try
	{
		if (m_pRpcClient == NULL)
		{
			m_pRpcClient = new IpcManageServerClient(protocol);
		}

		m_pRpcClient->setProtocol(protocol);
		transport->open();

		PTZControlDataPacket cmd;
		cmd.hPTZ = m_reqPTZctl.hPTZ;
		cmd.command = PTZCommand::PTZ_RIGHT;
		cmd.param1 = 0;
		cmd.param2 = 7;
		cmd.param3 = 0;
		cmd.dwStop = false;
		PTZControlReturnStruct rtn_cmd;
		m_pRpcClient->PTZControl(rtn_cmd, m_stuUserVerification, cmd);

		cout<<"PTZControl:"<< cmd.command<<" was executed!++++++++++++++"<<endl;
		cout<<" "<<endl;

		/*if (m_stuUserVerification.UserID.length() == 0)*/
		{
			MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}


		if (!m_pRpcClient->UserLogout(m_stuUserVerification))
		{
			MessageBox(_T(" 异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

	}
	catch (...)
	{
		MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);

	}

	if(transport != NULL)
	{
		transport->close();
	}
}


void CmfcTestDlg::OnBnClickedDown()
{
	boost::shared_ptr<TSocket> socket(new TSocket(SERVERIP,SERVERPORT));
	socket->setSendTimeout(TIMEOUT);
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	try
	{
		if (m_pRpcClient == NULL)
		{
			m_pRpcClient = new IpcManageServerClient(protocol);
		}

		m_pRpcClient->setProtocol(protocol);

		transport->open();

		if (m_stuUserVerification.UserID.length() == 0)
		{
			MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

		PTZControlDataPacket cmd;
		cmd.hPTZ = m_reqPTZctl.hPTZ;
		cmd.command = PTZCommand::PTZ_DOWN;
		cmd.param1 = 0;
		cmd.param2 = 7;
		cmd.param3 = 0;
		cmd.dwStop = false;
		PTZControlReturnStruct rtn_cmd;
		m_pRpcClient->PTZControl(rtn_cmd, m_stuUserVerification, cmd);

		cout<<"PTZControl:"<< cmd.command<<" was executed!++++++++++++++"<<endl;
		cout<<" "<<endl;

		//if (!m_pRpcClient->UserLogout(m_stuUserVerification))
		{
			MessageBox(_T("UserLogout 异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

	}
	catch (...)
	{
		MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);

	}

	if(transport != NULL)
	{
		transport->close();
	}
}


void CmfcTestDlg::OnBnClickedUp()
{
	boost::shared_ptr<TSocket> socket(new TSocket(SERVERIP,SERVERPORT));
	socket->setSendTimeout(TIMEOUT);
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	try
	{
		if (m_pRpcClient == NULL)
		{
			m_pRpcClient = new IpcManageServerClient(protocol);
		}

		m_pRpcClient->setProtocol(protocol);

		transport->open();

		if (m_stuUserVerification.UserID.length() == 0)
		{
			MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

		PTZControlDataPacket cmd;
		cmd.hPTZ = m_reqPTZctl.hPTZ;
		cmd.command = PTZCommand::PTZ_UP;
		cmd.param1 = 0;
		cmd.param2 = 7;
		cmd.param3 = 0;
		cmd.dwStop = false;
		PTZControlReturnStruct rtn_cmd;
		m_pRpcClient->PTZControl(rtn_cmd, m_stuUserVerification, cmd);

		cout<<"PTZControl:"<< cmd.command<<" was executed!++++++++++++++"<<endl;
		cout<<" "<<endl;
		//if (!m_pRpcClient->UserLogout(m_stuUserVerification))
		{
			MessageBox(_T("UserLogout 异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

	}
	catch (...)
	{
		MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);

	}

	if(transport != NULL)
	{
		transport->close();
	}
}

void CmfcTestDlg::OnBnClickedAdddevres()
{
	boost::shared_ptr<TSocket> socket(new TSocket(SERVERIP,SERVERPORT));
	socket->setSendTimeout(TIMEOUT);
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	try
	{
		if (m_pRpcClient == NULL)
		{
			m_pRpcClient = new IpcManageServerClient(protocol);
		}

		m_pRpcClient->setProtocol(protocol);

		transport->open();

		if (m_stuUserVerification.UserID.length() == 0)
		{
			MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

		IPCResourceDataPacket ipcRes;
		ipcRes.deviceName ="lf内部测试点_海康01";
		ipcRes.IP = "14.23.115.10";
		ipcRes.port=9090;
		ipcRes.channel=1;
		ipcRes.deviceType = DeviceType::type::DeviceTypeHC;
		ipcRes.userName="admin";
		ipcRes.password="lf123456";
		ipcRes.rtspUrl="rtsp://admin:lf123456@14.23.115.10/mpeg4/ch1/sub/av_stream";

		ReturnType::type ret = m_pRpcClient->addResource(m_stuUserVerification,ipcRes);

		m_vResInfo.clear();
		m_pRpcClient->GetResInfoList(m_vResInfo,m_stuUserVerification,ResourceType::type::ResourceTypeIPC);

		cout<<"after addResource+++++++++++++++++++++"<<endl;
		cout<<"device size is "<<m_vResInfo.size()<<endl;
		cout<<" "<<endl;

		if (ret != ReturnType::Success)
		{
			MessageBox(_T("UserLogout 异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

	}
	catch (...)
	{
		MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);

	}

	if(transport != NULL)
	{
		transport->close();
	}
}


void CmfcTestDlg::OnBnClickedDeldevres()
{
	boost::shared_ptr<TSocket> socket(new TSocket(SERVERIP,SERVERPORT));
	socket->setSendTimeout(TIMEOUT);
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	try
	{
		if (m_pRpcClient == NULL)
		{
			m_pRpcClient = new IpcManageServerClient(protocol);
		}

		m_pRpcClient->setProtocol(protocol);

		transport->open();

		if (m_stuUserVerification.UserID.length() == 0)
		{
			MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

		int size = m_vResInfo.size();
		ReturnType::type ret = m_pRpcClient->deleteResource(m_stuUserVerification,m_vResInfo[size-1].ID);

		m_vResInfo.clear();
		m_pRpcClient->GetResInfoList(m_vResInfo,m_stuUserVerification,ResourceType::ResourceTypeIPC);

		cout<<"after deleteResource:"
			<<"m_vResInfo.size"<<m_vResInfo.size()<<endl;
		ResourceInfoReturnStruct resInfo;
		for (int i=0;i<m_vResInfo.size();i++)
		{
			resInfo = m_vResInfo.at(i);
			cout<<"ResInfo"<<i<<": "
				<<resInfo.deviceName
				<<resInfo.IP
				<<resInfo.hResource
				<<resInfo.resourceType
				<<" id: "<<resInfo.ID
				<<endl;
		}
		cout<<""<<endl;

		if (ret != ReturnType::Success)
		{
			MessageBox(_T("UserLogout 异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

	}
	catch (...)
	{
		MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);

	}

	if(transport != NULL)
	{
		transport->close();
	}
}


void CmfcTestDlg::OnBnClickedCleardevs()
{
	boost::shared_ptr<TSocket> socket(new TSocket(SERVERIP,SERVERPORT));
	socket->setSendTimeout(TIMEOUT);
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	try
	{
		if (m_pRpcClient == NULL)
		{
			m_pRpcClient = new IpcManageServerClient(protocol);
		}

		m_pRpcClient->setProtocol(protocol);

		transport->open();

		if (m_stuUserVerification.UserID.length() == 0)
		{
			MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

		ReturnType::type ret = m_pRpcClient->deleteAllResources(m_stuUserVerification);
		if (ret != ReturnType::type::Success)
		{
			MessageBox(_T("deleteAllResources Success"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}
		else
		{
			m_vResInfo.clear();
			m_pRpcClient->GetResInfoList(m_vResInfo,m_stuUserVerification,ResourceType::type::ResourceTypeIPC);

			cout<<"after deleteAllResources 00000000000000000000000000000000"<<endl;
			cout<<"Res size is "<<m_vResInfo.size()<<endl;
			cout<<""<<endl;
		}

	}
	catch (...)
	{
		MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);

	}

	if(transport != NULL)
	{
		transport->close();
	}
}


void CmfcTestDlg::OnBnClickedCancel()
{
	boost::shared_ptr<TSocket> socket(new TSocket(SERVERIP,SERVERPORT));
	socket->setSendTimeout(TIMEOUT);
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	try
	{
		if (m_pRpcClient == NULL)
		{
			m_pRpcClient = new IpcManageServerClient(protocol);
		}

		m_pRpcClient->setProtocol(protocol);

		transport->open();

		if (m_stuUserVerification.UserID.length() == 0)
		{
			MessageBox(_T("异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}


		if (!m_pRpcClient->UserLogout(m_stuUserVerification))
		{
			MessageBox(_T("UserLogout 异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

	}
	catch (...)
	{
		MessageBox(_T("UserLogout net 异常"),_T("提示"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);

	}

	if(transport != NULL)
	{
		transport->close();
	}

	if (m_pRpcClient!= nullptr)
	{
		delete m_pRpcClient;
		m_pRpcClient = nullptr;
	}

	CDialogEx::OnCancel();
}




