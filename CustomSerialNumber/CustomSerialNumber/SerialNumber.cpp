// SerialNumber.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SerialNumber.h"
#include "afxdialogex.h"
#include "resource.h"

#include "MyTool.h"
#include "Item.h"
#include "SerializeTool.h"

// CSerialNumber �Ի���

IMPLEMENT_DYNAMIC(CSerialNumber, CDialogEx)

CSerialNumber::CSerialNumber(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CustomSerialNumber, pParent)
{

}

CSerialNumber::~CSerialNumber()
{
}

void CSerialNumber::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSerialNumber, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSerialNumber::OnBnClickedOk)
END_MESSAGE_MAP()


// CSerialNumber ��Ϣ�������

BOOL CSerialNumber::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	GetDlgItem(IDC_EDIT_SerialName)->SetWindowText(serial_name_);

	// չʾ�����л�����
	CString cur_path = CMyTool::Instance()->GetModuleDirPath();
	CString file_name;
	file_name.Format(_T("%s\\SerialData\\%s.dat"), cur_path, serial_name_);
	if (PathFileExists(file_name))
	{
		CFile read_file;
		read_file.Open(file_name, CFile::modeRead);
		CArchive ar2(&read_file, CArchive::load);
		CSerializeTool tool_read;
		tool_read.Serialize(ar2);
		for (int i = 0; i < tool_read.m_arrItems.GetSize(); i++)
		{
			// ����չʾ���б�
			CItem* item = tool_read.m_arrItems[i];
			CString strValue = item->m_Value;
			ItemType type = item->m_Type;

			// ��ʱ�������к�
			GetDlgItem(IDC_EDIT_SN)->SetWindowText(strValue);
		}
		ar2.Close();
		read_file.Close();
	}
	else
	{
		GetDlgItem(IDC_EDIT_SN)->SetWindowText(_T("0001"));
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CSerialNumber::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString cur_serial_number;
	GetDlgItem(IDC_EDIT_SN)->GetWindowText(cur_serial_number);

	CString cur_path = CMyTool::Instance()->GetModuleDirPath();
	CString dir_path = cur_path + "\\SerialData\\";
	std::string str_dir_path = CW2A(dir_path.GetString());
	CMyTool::Instance()->CreateDirectoryRecursion(str_dir_path);

	CItem item(cur_serial_number, SerialNumber);
	CSerializeTool tool;
	tool.AddItem(&item);

	//���л�
	CString file_name;
	file_name.Format(_T("%s\\SerialData\\%s.dat"), cur_path, serial_name_);

	CFile write_file;
	write_file.Open(file_name, CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&write_file, CArchive::store);
	tool.Serialize(ar);
	ar.Close();
	write_file.Close();

	CDialogEx::OnOK();
}
