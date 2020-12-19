// Dialog_Admin.cpp: файл реализации
//

#include "pch.h"
#include "MFC_travel.h"
#include "Dialog_Admin.h"
#include "afxdialogex.h"
#include "AddHotelDialog.h"


// Диалоговое окно Dialog_Admin

IMPLEMENT_DYNAMIC(Dialog_Admin, CDialogEx)

Dialog_Admin::Dialog_Admin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Dialog_Admin, pParent)
{
}

Dialog_Admin::~Dialog_Admin()
{
	delete hotels;
}

void Dialog_Admin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listbox);
}


BEGIN_MESSAGE_MAP(Dialog_Admin, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &Dialog_Admin::OnBnClickedButtonLoad)
	ON_BN_CLICKED(IDC_BUTTON_Add_H, &Dialog_Admin::OnBnClickedButtonAddH)
END_MESSAGE_MAP()


// Обработчики сообщений Dialog_Admin




void Dialog_Admin::OnBnClickedButtonLoad()
{
	m_listbox.SendMessage(LB_RESETCONTENT);
	hotels->Update();
	for (auto& h : hotels->all_hotels) {
		CString str(h.Name.c_str());
		m_listbox.AddString(str);
	}
}


void Dialog_Admin::OnBnClickedButtonAddH()
{
	{
		AddHotelDialog dialog;
		dialog.loadbase = loadbase;
		dialog.DoModal();
	}
}


