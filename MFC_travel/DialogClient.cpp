// DialogClient.cpp: файл реализации
//

#include "pch.h"
#include "MFC_travel.h"
#include "DialogClient.h"
#include "afxdialogex.h"
#include "DialogOrder.h"

// Диалоговое окно DialogClient

IMPLEMENT_DYNAMIC(DialogClient, CDialogEx)

DialogClient::DialogClient(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Dialog_Client, pParent)
{

}

DialogClient::~DialogClient()
{
	delete hotels;
}

void DialogClient::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listbox);
}


BEGIN_MESSAGE_MAP(DialogClient, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DialogClient::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DialogClient::OnBnClickedButton2)
END_MESSAGE_MAP()


// Обработчики сообщений DialogClient


void DialogClient::OnBnClickedButton1()
{
	m_listbox.SendMessage(LB_RESETCONTENT);
	hotels->Update();
	for (auto& h : hotels->all_hotels) {
		CString str(h.Name.c_str());
		m_listbox.AddString(str);
	}
}


void DialogClient::OnBnClickedButton2()
{
	if (m_listbox.GetCurSel()!=-1) {
		int m = m_listbox.GetCurSel();
		Hotel* h = &hotels->all_hotels[m];
		this->ShowWindow(SW_HIDE);
		DialogOrder dlg;
		dlg.number_hotel = m;
		dlg.hotel = h;
		dlg.nb = nb;
		dlg.DoModal();
		hotels->Save();
		this->ShowWindow(SW_SHOW);
	}
}
