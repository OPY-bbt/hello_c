#include <iostream>
#include <locale>
#include "windows.h"
#include "function.h"

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
  // 获取窗口名
  wchar_t *windowName = new wchar_t[128];
  GetWindowTextW(hwnd, windowName, sizeof(windowName));

  const wchar_t *targetName = L"滚滚滚";

  // 判断窗口名是否包含chrome
  if (wcsstr(windowName, targetName) != NULL)
  {
      // 打印窗口名
      wprintf(L"find window: %s \n", targetName);

      // 使用FindWindow函数查找匹配的窗口句柄
      HWND hDesigner = FindWindowW(NULL, windowName);

      // 判断是否找到匹配的窗口句柄
      if (hDesigner != NULL)
      {
          // 打印成功信息
          printf("Found chrome window handle: %p\n", hDesigner);
          SetForegroundWindow(hDesigner);
      }
      else
      {
          // 打印失败信息
          printf("Failed to find chrome window handle.\n");
      }
  }

  // 返回TRUE，继续枚举下一个顶层窗口
  return TRUE;
}

int func() {
  std::cout << "from function.cpp \n";

  // std::wstring filePath(L"D:\\avatar.jpg");
  // HINSTANCE res =  ShellExecuteW(nullptr, L"open", filePath.c_str(), nullptr, nullptr, SW_SHOWNORMAL);

  // if ((int)res > 32)
  //       MessageBoxW(NULL, L"成功打开文件", L"提示", MB_OK);
  //   else
  //       MessageBoxW(NULL, L"打开文件失败", L"错误", MB_OK);


  // std::wstring winName(L"滚滚滚");
  // const char* winName = "滚滚滚";
  // const winName = L"滚滚滚";
  // LPCSTR winName = "滚滚滚";
  // HWND hDesigner = FindWindow(NULL, winName);

  // if (hDesigner != NULL) {
  //   std::cout << "find designer window \n";
  //   SetForegroundWindow(hDesigner);
  // } else {
  //   std::cout << "can't find designer window \n";
  // }
  setlocale(LC_ALL, "chs");
  EnumWindows(EnumWindowsProc, 0);

  // char str[] = "滚滚滚";
  // char subStr[] = "滚滚滚";
  // char *a = strstr(str, subStr);

  // if (a != NULL) {
  //   printf("str2 is a substring of str1 at position %d\n", a - str);
  // } else {
  //   printf("str2 is not a substring of str1\n");
  // }

  // LPWSTR str = L"设计器";
  // LPWSTR subStr = L"设计器";
  // LPWSTR result = wcsstr(str, subStr);

  // if (result != NULL) {
  //   printf("str2 is a substring of str1 %ls \n", str);
  // } else {
  //   printf("str2 is not a substring of str1\n");
  // }
  
  return 0;
}
