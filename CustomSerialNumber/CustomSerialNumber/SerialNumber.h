#pragma once


// CSerialNumber �Ի���

class CSerialNumber : public CDialogEx
{
	DECLARE_DYNAMIC(CSerialNumber)

public:
	CSerialNumber(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSerialNumber();

public:
	// ��������
	CString serial_name_;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CustomSerialNumber };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
