#pragma once
// Диалоговое окно DialogAuth


class DialogAuth : public CDialogEx
{
	DECLARE_DYNAMIC(DialogAuth)

public:
	DialogAuth(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~DialogAuth();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()

private:
	Argument SetValue = Argument::DEFFAULT;
	LoadBase* loadBase = new LoadBase();
public:
	afx_msg void OnBnClickedIsclient();
	afx_msg void OnBnClickedIshotel();
	afx_msg void OnBnClickedIsadmin();
	afx_msg void OnBnClickedLogin();
};