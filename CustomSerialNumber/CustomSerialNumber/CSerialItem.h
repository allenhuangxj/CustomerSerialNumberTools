#pragma once
#include "Item.h"
class CSerialItem :
    public CItem
{
public:
	//��ǰֵ
	ULONG m_curOctValue;
	//��Сֵ
	ULONG m_OctMinValue;
	//���ֵ
	ULONG m_OctMaxValue;
	//��ʾ����
	UINT m_StringLength;
	//�Ƿ�ѭ���������ֵ������Сֵ��
	BOOL m_bCirculate;
public:
	//�ַ�����
	CString m_CharacterCollection;

public:
	CSerialItem();
	CSerialItem(CString, UINT);
	CSerialItem(CString, UINT, CString,CString,CString,BOOL);

	CString ToString();
	void Serialize(CArchive& archive);
	BOOL Plus(int nloop = 1);
	void Clear();
	void Clone(CItem& ct);
	CString OctToAny(ULONG);//10����ת�������
	ULONG AnyToOct(CString strAny);//�������ת10����
private:
	void OctToAny();//10����ת�������
	ULONG GetMax();

};

