
// mfcTestDlg.h : ͷ�ļ�
//

#pragma once

#include "IpcManageServer.h"

#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace ipcms;

#pragma comment(lib,"libthrift.lib")

using namespace std;

#define SERVERIP "127.0.0.1"
#define SERVERPORT 9090
#define TIMEOUT		 1000


// CmfcTestDlg �Ի���
class CmfcTestDlg : public CDialogEx
{
// ����
public:
	CmfcTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLogin();
	afx_msg void OnBnClickedGetreslist();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedLeft();
	afx_msg void OnBnClickedRight();
	afx_msg void OnBnClickedDown();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedAdddevres();
	afx_msg void OnBnClickedDeldevres();
	afx_msg void OnBnClickedCleardevs();
	afx_msg void OnBnClickedCancel();



private:
	IpcManageServerClient* m_pRpcClient;
	UserVerificationDataPacket m_stuUserVerification;
};
