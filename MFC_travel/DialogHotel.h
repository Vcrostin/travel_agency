#pragma once


// Диалоговое окно DialogHotel

class DialogHotel : public CDialogEx
{
	DECLARE_DYNAMIC(DialogHotel)

public:
	DialogHotel(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~DialogHotel();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dialog_Hotel };
#endif

private:
	Hotels* hotels = new Hotels();
	Hotel* hot = nullptr;
	int nums_hot = -1;
public:
	LoadBase* loadbase = nullptr;
	std::string stw;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listbox;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
