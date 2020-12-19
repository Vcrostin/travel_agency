// DialogAuth.cpp: файл реализации
//

#include "pch.h"
#include "MFC_travel.h"
#include "DialogAuth.h"
#include "afxdialogex.h"
#include <string>
#include <stdexcept>
#include "Dialog_Admin.h"
#include "DialogClient.h"
#include "DialogHotel.h"

// Диалоговое окно DialogAuth

IMPLEMENT_DYNAMIC(DialogAuth, CDialogEx)

DialogAuth::DialogAuth(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
}

DialogAuth::~DialogAuth()
{
	delete loadBase;
}

void DialogAuth::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DialogAuth, CDialogEx)

	ON_BN_CLICKED(IDC_ISCLIENT, &DialogAuth::OnBnClickedIsclient)
	ON_BN_CLICKED(IDC_ISHOTEL, &DialogAuth::OnBnClickedIshotel)
	ON_BN_CLICKED(IDC_ISADMIN, &DialogAuth::OnBnClickedIsadmin)
	ON_BN_CLICKED(IDC_LogIn, &DialogAuth::OnBnClickedLogin)
END_MESSAGE_MAP()


// Обработчики сообщений DialogAuth




void DialogAuth::OnBnClickedIsclient()
{
	SetValue = Argument::CLIENT;
}


void DialogAuth::OnBnClickedIshotel()
{
	SetValue = Argument::HOTEL;
}


void DialogAuth::OnBnClickedIsadmin()
{
	SetValue = Argument::ADMIN;
}

void DialogAuth::OnBnClickedLogin()
{
	CString login;
	GetDlgItemText(IDC_EDIT1, login);
	CString password;
	GetDlgItemText(IDC_EDIT2, password);
	std::string login_s = to_string(login);
	std::string pass = to_string(password);
	try {
		if (loadBase->Exist(login_s, pass)) {
			switch (loadBase->GetNode(login_s)->TypeEntry)
			{
			case Argument::ADMIN:
			{
				this->ShowWindow(SW_HIDE);
				Dialog_Admin dlg;
				dlg.loadbase = loadBase;
				dlg.DoModal();
				this->ShowWindow(SW_SHOW);
				break;
			}
			case Argument::CLIENT:
			{
				this->ShowWindow(SW_HIDE);
				DialogClient dialog;
				dialog.nb = loadBase->GetNode(login_s);
				dialog.DoModal();
				this->ShowWindow(SW_SHOW);
				break;
			}
			case Argument::HOTEL:
			{
				this->ShowWindow(SW_HIDE);
				DialogHotel dlg;
				dlg.loadbase = loadBase;
				dlg.stw = login_s;
				dlg.DoModal();
				this->ShowWindow(SW_SHOW);
				break;
			}
			}
			delete loadBase;
			loadBase = new LoadBase();
		}
	}
	catch(std::out_of_range e){
		CString inf("Неверный логин и/или пароль");
		AfxMessageBox(inf, MB_OK | MB_ICONERROR);
	}
}
