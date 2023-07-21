#include "WindowsApplication.hpp"
#include <tchar.h>

using namespace My;

void WindowsApplication::CreateMainWindow() {
    // get the HINSTANCE of the Console Program
    HINSTANCE hInstance = GetModuleHandle(NULL);

    // this struct holds information for the window class
    WNDCLASSEX wc;

    // clear out the window class for use
    ZeroMemory(&wc, sizeof(WNDCLASSEX));

    // fill in the struct with the needed information
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = _T("GameEngineFromScratch");

    // register the window class
    RegisterClassEx(&wc);

    // create the window and use the result as the handle
    m_hWnd =
        CreateWindowEx(0,
                       _T("GameEngineFromScratch"),  // name of the window class
                       m_Config.appName,             // title of the window
                       WS_OVERLAPPEDWINDOW,          // window style
                       CW_USEDEFAULT,                // x-position of the window
                       CW_USEDEFAULT,                // y-position of the window
                       m_Config.screenWidth,         // width of the window
                       m_Config.screenHeight,        // height of the window
                       NULL,       // we have no parent window, NULL
                       NULL,       // we aren't using menus, NULL
                       hInstance,  // application handle
                       this);      // pass pointer to current object

    // display the window on the screen
    ShowWindow(m_hWnd, SW_SHOW);
}

int WindowsApplication::Initialize() {
    int result;

    CreateMainWindow();

    // first call base class initialization
    result = BaseApplication::Initialize();

    if (result != 0)
        exit(result);

    return result;
}

void WindowsApplication::Finalize() {
    BaseApplication::Finalize();
}

void WindowsApplication::Tick() {
    BaseApplication::Tick();

    // this struct holds Windows event messages
    MSG msg;

    // we use PeekMessage instead of GetMessage here
    // because we should not block the thread at anywhere
    // except the engine execution driver module
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        // translate keystroke messages into the right format
        TranslateMessage(&msg);

        // send the message to the WindowProc function
        DispatchMessage(&msg);
    }
}

// this is the main message handler for the program
LRESULT CALLBACK WindowsApplication::WindowProc(HWND hWnd, UINT message,
                                                WPARAM wParam, LPARAM lParam) {
    WindowsApplication* pThis;
    if (message == WM_NCCREATE) {
        pThis = static_cast<WindowsApplication*>(
            reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);

        SetLastError(0);
        if (!SetWindowLongPtr(hWnd, GWLP_USERDATA,
                              reinterpret_cast<LONG_PTR>(pThis))) {
            if (GetLastError() != 0)
                return FALSE;
        }
    } else {
        pThis = reinterpret_cast<WindowsApplication*>(
            GetWindowLongPtr(hWnd, GWLP_USERDATA));
    }

    // sort through and find what code to run for the message given
    switch (message) {
        case WM_PAINT: {
            g_pApp->OnDraw();
        } break;
        case WM_KEYUP: {
            switch (wParam) {
                case VK_LEFT:
                    g_pInputManager->LeftArrowKeyUp();
                    break;
                case VK_RIGHT:
                    g_pInputManager->RightArrowKeyUp();
                    break;
                case VK_UP:
                    g_pInputManager->UpArrowKeyUp();
                    break;
                case VK_DOWN:
                    g_pInputManager->DownArrowKeyUp();
                    break;

                case 'W':
                    g_pInputManager->WKeyUp();
                    break;
                case 'A':
                    g_pInputManager->AKeyUp();
                    break;
                case 'S':
                    g_pInputManager->SKeyUp();
                    break;
                case 'D':
                    g_pInputManager->DKeyUp();
                    break;
                default:
                    break;
            }
        } break;
        case WM_KEYDOWN: {
            switch (wParam) {
                case VK_LEFT:
                    g_pInputManager->LeftArrowKeyDown();
                    break;
                case VK_RIGHT:
                    g_pInputManager->RightArrowKeyDown();
                    break;
                case VK_UP:
                    g_pInputManager->UpArrowKeyDown();
                    break;
                case VK_DOWN:
                    g_pInputManager->DownArrowKeyDown();
                    break;
                case 'W':
                    g_pInputManager->WKeyDown();
                    break;
                case 'A':
                    g_pInputManager->AKeyDown();
                    break;
                case 'S':
                    g_pInputManager->SKeyDown();
                    break;
                case 'D':
                    g_pInputManager->DKeyDown();
                    break;
                default:
                    break;
            }
        } break;

        // For mouse movement
        case WM_MOUSEMOVE: {
            // Get the x and y coordinates of the mouse cursor
            int xPos = GET_X_LPARAM(lParam);
            int yPos = GET_Y_LPARAM(lParam);
            // Pass them to the input manager
            g_pInputManager->MouseMove(xPos, yPos);
        } break;

        /*
        * That’s a good question. The reason I add the xpos and ypos parameters in the MouseScroll function is 
        * because they can be useful for some scenarios, such as zooming in or out of a specific point on the screen,
        * or scrolling a specific window or control under the mouse cursor. However, if you don’t need them, you can 
        * omit them and just use the zDelta parameter. It depends on your design and requirements.
        */
        case WM_MOUSEWHEEL: {
            // Get the distance and direction of the wheel rotation
            int zDelta = GET_WHEEL_DELTA_WPARAM(wParam);
            // Get the x and y coordinates of the mouse cursor
            int xPos = GET_X_LPARAM(lParam);
            int yPos = GET_Y_LPARAM(lParam);
            // Pass them to the input manager
            g_pInputManager->MouseScroll(zDelta, xPos, yPos);
        } break;

            // this message is read when the window is closed
        case WM_DESTROY: {
            // close the application entirely
            PostQuitMessage(0);
            m_bQuit = true;
        }
    }

    // Handle any messages the switch statement didn't
    return DefWindowProc(hWnd, message, wParam, lParam);
}