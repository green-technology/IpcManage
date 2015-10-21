
// mfcTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "mfcTest.h"
#include "mfcTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CmfcTestDlg �Ի���




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
END_MESSAGE_MAP()


// CmfcTestDlg ��Ϣ�������

BOOL CmfcTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CmfcTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
			m_stuUserVerification.UserID = stuUserLoginR.UserID;			
			m_stuUserVerification.SessionID = stuUserLoginR.SessionID;
			bRet = true;
		}
	}
	catch(apache::thrift::transport::TTransportException &exc)
	{
		MessageBox(_T("��¼�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
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
			MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
			return;
		}

		m_vResInfo.clear();

		m_pRpcClient->GetResInfoList(m_vResInfo,m_stuUserVerification,ResourceType::ResourceTypeIPC);



		if (m_vResInfo.size()==0)
		{
			transport->close();
			MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
			return ;
		}
		else
		{
			ResourceInfoReturnStruct resInfo;
			for (int i=0;i<m_vResInfo.size();i++)
			{
				resInfo = m_vResInfo.at(i);
				cout<<"deviceName: "<<resInfo.deviceName
					<<"IP: "<<resInfo.IP
					<<endl;
			}
		}

	}
	catch (...)
	{
		MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);

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
			MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

		RequestPTZControlDataPacket rqPTZ;
		rqPTZ.hResource = m_vResInfo[2].hResource;
		m_pRpcClient->RequestPTZControl(m_reqPTZctl, m_stuUserVerification,rqPTZ);

		cout<<"ptzhandle:"<<m_reqPTZctl.hPTZ
			<<endl;

	}
	catch (...)
	{
		MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);

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
			MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
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

		//if (!m_pRpcClient->UserLogout(m_stuUserVerification))
		{
			MessageBox(_T("UserLogout �쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

	}
	catch (...)
	{
		MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);

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

		/*if (m_stuUserVerification.UserID.length() == 0)*/
		{
			MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}


		if (!m_pRpcClient->UserLogout(m_stuUserVerification))
		{
			MessageBox(_T(" �쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

	}
	catch (...)
	{
		MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);

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
			MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
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

		//if (!m_pRpcClient->UserLogout(m_stuUserVerification))
		{
			MessageBox(_T("UserLogout �쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

	}
	catch (...)
	{
		MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);

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
			MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
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
		//if (!m_pRpcClient->UserLogout(m_stuUserVerification))
		{
			MessageBox(_T("UserLogout �쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

	}
	catch (...)
	{
		MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);

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
			MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

		IPCResourceDataPacket ipcRes;
		ipcRes.deviceName ="deviceName1";
		ipcRes.IP = "127.0.0.1";

		ReturnType::type ret = m_pRpcClient->addResource(m_stuUserVerification,ipcRes);

		cout<<"addResource:" 
			<<ipcRes.deviceName<<ipcRes.IP
			<<endl;
		if (ret != ReturnType::Success)
		{
			MessageBox(_T("UserLogout �쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

	}
	catch (...)
	{
		MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);

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
			MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

		ReturnType::type ret = m_pRpcClient->deleteResource(m_stuUserVerification,m_vResInfo[3].hResource);

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
				<<endl;
		}

		if (ret != ReturnType::Success)
		{
			MessageBox(_T("UserLogout �쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

	}
	catch (...)
	{
		MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);

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
			MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}


		if (!m_pRpcClient->UserLogout(m_stuUserVerification))
		{
			MessageBox(_T("UserLogout �쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

	}
	catch (...)
	{
		MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);

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
			MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}


		if (!m_pRpcClient->UserLogout(m_stuUserVerification))
		{
			MessageBox(_T("UserLogout �쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);
		}

	}
	catch (...)
	{
		MessageBox(_T("�쳣"),_T("��ʾ"),MB_ICONINFORMATION|MB_TOPMOST|MB_OK);

	}

	if(transport != NULL)
	{
		transport->close();
	}

	CDialogEx::OnCancel();
}




