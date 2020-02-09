#pragma once
using namespace std;


// Диалоговое окно CAddClassDlg

class CAddClassDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddClassDlg)

public:
	CAddClassDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CAddClassDlg();
	CComboBox m_numCombo;
	CComboBox m_letCombo;
	CButton m_checkBoxLet;
	CButton m_rusRadio;
	CButton m_enRadio;



// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDCLASSDIALOG	};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	BOOL CAddClassDlg::OnInitDialog()
	{
		CDialog::OnInitDialog();
		CComboBox* mp_numCombo = &m_numCombo;
		CComboBox* mp_letCombo = &m_letCombo;
		CButton* mp_rusRadio = &m_rusRadio;
		CButton* mp_enRadio = &m_enRadio;
		CString a;
		for (int i = 1; i <= 12; ++i)
		{
			a.Format(L"%d", i);
			mp_numCombo->AddString(a);
		}
		return true;
	}

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedRadiolet2();
	afx_msg void OnBnClickedRadiolet3();
	afx_msg void OnBnClickedOk();
	CEdit testBox;
	CButton testBut;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
};

