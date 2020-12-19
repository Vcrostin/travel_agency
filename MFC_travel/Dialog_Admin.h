#pragma once
#include "hotel.h"

// Диалоговое окно Dialog_Admin

class Dialog_Admin : public CDialogEx
{
	DECLARE_DYNAMIC(Dialog_Admin)

public:
	Dialog_Admin(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~Dialog_Admin();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dialog_Admin };
#endif
public:
	LoadBase* loadbase = nullptr;

private:
	Hotels *hotels = new Hotels();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listbox;
	afx_msg void OnBnClickedButtonLoad();
	afx_msg void OnBnClickedButtonAddH();
};
