#include <iostream>

#include "windows.h"
#include "function.h"

int func() {
  std::cout << "from function.cpp \n";

  std::wstring filePath(L"D:\\avatar.jpg");
  HINSTANCE res =  ShellExecuteW(nullptr, L"open", filePath.c_str(), nullptr, nullptr, SW_SHOWNORMAL);

  if ((int)res > 32)
        MessageBoxW(NULL, L"成功打开文件", L"提示", MB_OK);
    else
        MessageBoxW(NULL, L"打开文件失败", L"错误", MB_OK);

  return 0;
}
