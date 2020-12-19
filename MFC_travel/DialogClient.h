#pragma once


// Диалоговое окно DialogClient

class DialogClient : public CDialogEx
{
	DECLARE_DYNAMIC(DialogClient)

public:
	DialogClient(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~DialogClient();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dialog_Client };
#endif
private:
	Hotels* hotels = new Hotels();
public:
	NodeBase* nb = nullptr;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listbox;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
