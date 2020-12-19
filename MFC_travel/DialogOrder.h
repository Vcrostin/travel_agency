#pragma once


// Диалоговое окно DialogOrder

class DialogOrder : public CDialogEx
{
	DECLARE_DYNAMIC(DialogOrder)

public:
	DialogOrder(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~DialogOrder();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ORDER };
#endif
public:
	int number_hotel = 0;
	Hotel* hotel = nullptr;
	NodeBase* nb = nullptr;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listbox;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
};
