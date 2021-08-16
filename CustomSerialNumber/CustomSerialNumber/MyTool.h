#pragma once

#include <iostream>
using namespace std;

class CMyTool
{
public:
	CMyTool();
	virtual ~CMyTool();
	static CMyTool* Instance();

public:
	static std::string base_chars_;

private:
	static CMyTool* instance_;

public:
	// �ݹ鴴���ļ���
	int CreateDirectoryRecursion(std::string path);
	CString GetModuleDirPath();
	std::string Increment(std::string src, bool is_from_recursion = false);
};

