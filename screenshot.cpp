#include <iostream>
#include <windows.h>
#include <xinput.h>

#pragma comment(lib, "XInput.lib")

int main()
{
  std::cout << "游戏运行时，按下<右摇杆>的同时会触发 steam 截图！\n";
  while (true)
  {
    DWORD dwResult;
    for (DWORD i = 0; i < XUSER_MAX_COUNT; i++)
    {
      XINPUT_STATE state;
      ZeroMemory(&state, sizeof(XINPUT_STATE));

      // Simply get the state of the controller from XInput.
      dwResult = XInputGetState(i, &state);

      if (dwResult == ERROR_SUCCESS)
      {
        if (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB)
        {
          std::cout << "截图成功！\n";
          keybd_event(123, 0, 0, 0);               // 按下f12
          keybd_event(123, 0, KEYEVENTF_KEYUP, 0); // 弹起f12
        }
      }
    }
    Sleep(16);
  }
}
