#pragma once

#include "hotel.h"
// Диалоговое окно AddHotelDialog

class AddHotelDialog : public CDialogEx
{
	DECLARE_DYNAMIC(AddHotelDialog)

public:
	AddHotelDialog(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~AddHotelDialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_HOTEL_DIALOG };
#endif
public:
	LoadBase* loadbase = nullptr;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
private:
	Hotels* hotel = new Hotels();

	std::pair<bool, int> convert2int(std::string& str);
public:
	afx_msg void OnBnClickedButton1();
};
