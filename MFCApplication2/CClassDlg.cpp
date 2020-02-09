// CClassDlg.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplication2.h"
#include "CClassDlg.h"
#include "afxdialogex.h"


// Диалоговое окно CClassDlg

IMPLEMENT_DYNAMIC(CClassDlg, CDialogEx)

CClassDlg::CClassDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLASSDIALOG, pParent)
{

}

CClassDlg::~CClassDlg()
{
}

void CClassDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CClassDlg, CDialogEx)
	ON_BN_CLICKED(IDC_EXIT, &CClassDlg::OnBnClickedExit)
	ON_BN_CLICKED(IDC_ADD, &CClassDlg::OnBnClickedAdd)
END_MESSAGE_MAP()


// Обработчики сообщений CClassDlg


void CClassDlg::OnBnClickedExit()
{
	// TODO: добавьте свой код обработчика уведомлений
	this->OnCancel();
}


void CClassDlg::OnBnClickedAdd()
{
	// TODO: добавьте свой код обработчика уведомлений
	CAddClassDlg addDlg;
	addDlg.DoModal();
}
