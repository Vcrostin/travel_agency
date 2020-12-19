// DialogReg.cpp: файл реализации
//

#include "pch.h"
#include "MFC_travel.h"
#include "DialogReg.h"
#include "afxdialogex.h"


// Диалоговое окно DialogReg

IMPLEMENT_DYNAMIC(DialogReg, CDialogEx)

DialogReg::DialogReg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

DialogReg::~DialogReg()
{
	delete loadBase;
}

void DialogReg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DialogReg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_REG, &DialogReg::OnBnClickedButtonReg)
END_MESSAGE_MAP()


// Обработчики сообщений DialogReg


void DialogReg::OnBnClickedButtonReg()
{
	CString login;
	GetDlgItemText(IDC_EDIT1, login);
	CString password;
	GetDlgItemText(IDC_EDIT2, password);
	std::string login_s = to_string(login);
	std::string pass = to_string(password);
	if (loadBase->Insert(login_s, pass)) {
		CString inf("Запись успешно создана");
		AfxMessageBox(inf, MB_OK | MB_ICONINFORMATION);
		this->OnOK();
	}
}
