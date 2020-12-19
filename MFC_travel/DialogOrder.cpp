// DialogOrder.cpp: файл реализации
//

#include "pch.h"
#include "MFC_travel.h"
#include "DialogOrder.h"
#include "afxdialogex.h"
#include <stdexcept>


// Диалоговое окно DialogOrder

IMPLEMENT_DYNAMIC(DialogOrder, CDialogEx)

DialogOrder::DialogOrder(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ORDER, pParent)
{
}

DialogOrder::~DialogOrder()
{
}

void DialogOrder::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listbox);
}


BEGIN_MESSAGE_MAP(DialogOrder, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &DialogOrder::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &DialogOrder::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &DialogOrder::OnBnClickedButton3)
END_MESSAGE_MAP()


// Обработчики сообщений DialogOrder


//Заказ
void DialogOrder::OnBnClickedButton1()
{
	int m = m_listbox.GetCurSel();
	if (m != -1) {
		CString str;
		m_listbox.GetText(m, str);
		std::string chosen_text(to_string(str));
		if (hotel->Rooms[m] == TypeRooms::AVAILABLE) {
			hotel->Rooms[m] = TypeRooms::FULL;
			while ((int)nb->ordered_rooms.size() <= number_hotel) {
				nb->ordered_rooms.push_back({ });
			}
			nb->ordered_rooms[number_hotel].ord_rooms[m] = TypeRooms::ORDERED;
		}
	}
}

//Подтверждение
void DialogOrder::OnBnClickedButton2()
{
	int m = m_listbox.GetCurSel();
	if (m != -1) {
		CString str;
		m_listbox.GetText(m, str);
		std::string chosen_text(to_string(str));
		if (nb->ordered_rooms[number_hotel].ord_rooms.count(m)>0&& nb->ordered_rooms[number_hotel].ord_rooms[m] == TypeRooms::BUY_AVAILABLE) {
			nb->ordered_rooms[number_hotel].ord_rooms[m] = TypeRooms::BOUGHT;
		}
	}
}


void DialogOrder::OnBnClickedButton3()
{
	m_listbox.SendMessage(LB_RESETCONTENT);
	int counter = 1;
	for (auto& a : hotel->Rooms) {
		CString s(std::to_string(counter).c_str());
		while (s.GetLength() < 4) {
			s = CString("0") + s;
		}
		switch (a)
		{
		case TypeRooms::AVAILABLE:
			s += ": Доступен";
			break;
		case TypeRooms::FULL:
		{
			if ((int)nb->ordered_rooms.size() > number_hotel && nb->ordered_rooms[number_hotel].ord_rooms.count(counter - 1) > 0) {
				switch (nb->ordered_rooms[number_hotel].ord_rooms[counter - 1])
				{
				case TypeRooms::ORDERED:
					s += ": Заказан";
					break;
				case TypeRooms::BUY_AVAILABLE:
					s += ": Ожидается оплата";
					break;
				case TypeRooms::BOUGHT:
					s += ": Оплачен";
					break;
				default:
					s += ": Error";
					break;
				}
			}
			else {
				s += ": Занят";
			}
			break;
		}
		default:
			break;
		}
		counter++;
		m_listbox.AddString(s);
	}
}
