#pragma once


// Диалоговое окно DialogReg

class DialogReg : public CDialogEx
{
	DECLARE_DYNAMIC(DialogReg)

public:
	DialogReg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~DialogReg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonReg();

private:
	LoadBase* loadBase = new LoadBase();
};
