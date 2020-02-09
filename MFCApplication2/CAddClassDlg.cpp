// CAddClassDlg.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplication2.h"
#include "CAddClassDlg.h"
#include "afxdialogex.h"
#include <locale>


// Диалоговое окно CAddClassDlg

IMPLEMENT_DYNAMIC(CAddClassDlg, CDialogEx)

CAddClassDlg::CAddClassDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADDCLASSDIALOG, pParent)
{
}

CAddClassDlg::~CAddClassDlg()
{
}

void CAddClassDlg::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBONUM, m_numCombo);
	DDX_Control(pDX, IDC_COMBOLET, m_letCombo);
	DDX_Control(pDX, IDC_CHECK1, m_checkBoxLet);
	DDX_Control(pDX, IDC_RADIOLET2, m_rusRadio);
	DDX_Control(pDX, IDC_RADIOLET3, m_enRadio);
}

BEGIN_MESSAGE_MAP(CAddClassDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK1, &CAddClassDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_RADIOLET2, &CAddClassDlg::OnBnClickedRadiolet2)
	ON_BN_CLICKED(IDC_RADIOLET3, &CAddClassDlg::OnBnClickedRadiolet3)
	ON_BN_CLICKED(IDOK, &CAddClassDlg::OnBnClickedOk)
END_MESSAGE_MAP()

// Обработчики сообщений CAddClassDlg

// если стоит галка "Без буквы"
void CAddClassDlg::OnBnClickedCheck1()
{
	// TODO: добавьте свой код обработчика уведомлений
	CComboBox* mp_letComboLet = &m_letCombo;
	UINT nCheck = m_checkBoxLet.GetCheck();
	if (nCheck == BST_CHECKED)
		mp_letComboLet->EnableWindow(FALSE);
	else
		mp_letComboLet->EnableWindow(TRUE);
}

// если выбран русский алфавит
void CAddClassDlg::OnBnClickedRadiolet2()
{
	// TODO: добавьте свой код обработчика уведомлений

	CButton* mp_rusRadio = &m_rusRadio;
	CButton* mp_enRadio = &m_enRadio;
	CComboBox* mp_letCombo = &m_letCombo;
	mp_letCombo->ResetContent();
	CString lettersstr = NULL;
	CString letter = NULL;
	if (mp_rusRadio->GetCheck() == BST_CHECKED)
		lettersstr.Format(L"АБВГДЕЖЗИКМНОПРСТУФХЦЧШЩЭЮЯ");
	else if (mp_enRadio->GetCheck() == BST_CHECKED)
		lettersstr.Format(L"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	for (int i = 0; i < lettersstr.GetLength(); ++i)
	{
		letter.Format(L"%c", lettersstr[i]);
		mp_letCombo->AddString(letter);
	}
}

// если выбран латинский алфавит
void CAddClassDlg::OnBnClickedRadiolet3()
{
	// TODO: добавьте свой код обработчика уведомлений
	CButton* mp_rusRadio = &m_rusRadio;
	CButton* mp_enRadio = &m_enRadio;
	CComboBox* mp_letCombo = &m_letCombo;

	mp_letCombo->ResetContent();
	CString lettersstr = NULL;
	CString letter = NULL;
	if (mp_rusRadio->GetCheck() == BST_CHECKED)
		lettersstr.Format(L"АБВГДЕЖЗИКМНОПРСТУФХЦЧШЩЭЮЯ");
	else if (mp_enRadio->GetCheck() == BST_CHECKED)
		lettersstr.Format(L"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	for (int i = 0; i < lettersstr.GetLength(); ++i)
	{
		letter.Format(L"%c", lettersstr[i]);
		mp_letCombo->AddString(letter);
	}
}

// если пользователь нажал "Принять" класс заносится в файл.dat
void CAddClassDlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	_wsetlocale(LC_CTYPE, _T("rus"));

	CStdioFile file;
	CComboBox* mp_letCombo = &m_letCombo;
	CComboBox* mp_numCombo = &m_numCombo;
	CString letStr, numStr;
	mp_letCombo->GetLBText(mp_letCombo->GetCurSel(), letStr);
	mp_numCombo->GetLBText(mp_numCombo->GetCurSel(), numStr);
	if (file.Open(_T("e:\\file.dat"), CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate ))
	{
		file.SeekToEnd();
		file.WriteString(numStr);
		file.WriteString(letStr);
		file.WriteString(_T(";"));
		file.Flush();
	}
	file.Close();
	CDialogEx::OnOK();
}




