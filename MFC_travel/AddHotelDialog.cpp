// AddHotelDialog.cpp: файл реализации
//

#include "pch.h"
#include "MFC_travel.h"
#include "AddHotelDialog.h"
#include "afxdialogex.h"


// Диалоговое окно AddHotelDialog

IMPLEMENT_DYNAMIC(AddHotelDialog, CDialogEx)

AddHotelDialog::AddHotelDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD_HOTEL_DIALOG, pParent)
{

}

AddHotelDialog::~AddHotelDialog()
{
	delete hotel;
}

void AddHotelDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddHotelDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &AddHotelDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений AddHotelDialog


std::pair<bool, int> AddHotelDialog::convert2int(std::string& str)
{
	int k = 0;
	bool ret = true;
	for (int i = 0; i <(int) str.size(); ++i) {
		if (str[i] <= '9' && str[i] >= '0') {
			k = k * 10 + str[i] - '0';
		}
		else {
			ret = false;
		}
	}
	return { ret,k };
}

void AddHotelDialog::OnBnClickedButton1()
{
	CString hotel_name;
	GetDlgItemText(IDC_EDIT1, hotel_name);
	CString size;
	GetDlgItemText(IDC_EDIT2, size);
	std::string hotel_name_s = to_string(hotel_name);
	std::string size_s = to_string(size);
	bool checkstr = true;
	std::pair<bool, int> to_int;
	if (size_s.size() > 0 && size_s.size() <= 5) {
		to_int = convert2int(size_s);
		checkstr = to_int.first;
	}
	else
		checkstr = false;
	if (checkstr && hotel_name_s.length() > 0) {
		for (auto& h : hotel_name_s) {
			if (h == '_' || (h <= 'z' && h >= 'a') || (h >= 'A' && h <= 'Z')) {
			}
			else
				checkstr = false;
		}
	}
	if (checkstr) {
		if (!loadbase->possinshotel(hotel_name_s)) {
			CString st("Данное название уже занято");
			AfxMessageBox(st, MB_OK, MB_ICONERROR);
			return;
		}
		bool add = hotel->AddHotel(hotel_name_s, to_int.second);
		if (!add) {
			CString st("Такой отель уже есть");
			AfxMessageBox(st, MB_OK, MB_ICONERROR);
		}
		else {
			loadbase->Insert_hotel(hotel_name_s, hotel_name_s);
			this->OnOK();
		}
	}
	else {
		CString st("Неправильный формат ввода");
		AfxMessageBox(st, MB_OK, MB_ICONERROR);
	}
}
