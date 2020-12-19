// DialogHotel.cpp: файл реализации
//

#include "pch.h"
#include "MFC_travel.h"
#include "DialogHotel.h"
#include "afxdialogex.h"
#include <algorithm>

// Диалоговое окно DialogHotel

IMPLEMENT_DYNAMIC(DialogHotel, CDialogEx)

DialogHotel::DialogHotel(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Dialog_Hotel, pParent)
{

}

DialogHotel::~DialogHotel()
{
}

void DialogHotel::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listbox);
}


BEGIN_MESSAGE_MAP(DialogHotel, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &DialogHotel::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &DialogHotel::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DialogHotel::OnBnClickedButton2)
END_MESSAGE_MAP()


// Обработчики сообщений DialogHotel


void DialogHotel::OnBnClickedButton3()
{
	m_listbox.SendMessage(LB_RESETCONTENT);
	hotels->Update();
	auto hotel = std::find_if(hotels->all_hotels.begin(), hotels->all_hotels.end(), [this](const Hotel& h) {
		return (h.Name == stw);
		});
	hot = &*hotel;
	int nums_hotel = hotel - hotels->all_hotels.begin();
	nums_hot = nums_hotel;
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
			for (auto& pers : loadbase->all_db) {
				if (pers.second.TypeEntry == Argument::CLIENT && pers.second.ordered_rooms.size() > nums_hotel) {
					if (pers.second.ordered_rooms[nums_hotel].ord_rooms.count(counter - 1)) {
						switch (pers.second.ordered_rooms[nums_hotel].ord_rooms[counter - 1])
						{
						case TypeRooms::ORDERED:
							s += ": Заказан";
							break;
						case TypeRooms::BUY_AVAILABLE:
							s += ": Ожидается оплата";
							break;
						case TypeRooms::BOUGHT:
							s += ": Куплен";
							break;
						default:
							s += ": ERROR";
						}
					}
				}
			}
			break;
		}
		default:
			break;
		}
		counter++;
		m_listbox.AddString(s);
	}
	hotels->Save();
}

//Confirm
void DialogHotel::OnBnClickedButton1()
{
	int m = m_listbox.GetCurSel();
	if (m != -1) {
		CString str;
		m_listbox.GetText(m, str);
		std::string chosen_text(to_string(str));
		for (auto& pers : loadbase->all_db) {
			if (pers.second.TypeEntry == Argument::CLIENT && pers.second.ordered_rooms.size() > nums_hot) {
				if (pers.second.ordered_rooms[nums_hot].ord_rooms.count(m)) {
					if (pers.second.ordered_rooms[nums_hot].ord_rooms[m] == TypeRooms::ORDERED) {
						pers.second.ordered_rooms[nums_hot].ord_rooms[m] = TypeRooms::BUY_AVAILABLE;
					}
				}
			}
		}
	}
	hotels->Save();
}

//Deny
void DialogHotel::OnBnClickedButton2()
{
	int m = m_listbox.GetCurSel();
	if (m != -1) {
		CString str;
		m_listbox.GetText(m, str);
		std::string chosen_text(to_string(str));
		for (auto& pers : loadbase->all_db) {
			if (pers.second.TypeEntry == Argument::CLIENT && pers.second.ordered_rooms.size() > nums_hot) {
				if (pers.second.ordered_rooms[nums_hot].ord_rooms.count(m)) {
					if (pers.second.ordered_rooms[nums_hot].ord_rooms[m] == TypeRooms::ORDERED) {
						pers.second.ordered_rooms[nums_hot].ord_rooms[m] = TypeRooms::AVAILABLE;
						hot->Rooms[m] = TypeRooms::AVAILABLE;
					}
				}
			}
		}
	}
	hotels->Save();
}
