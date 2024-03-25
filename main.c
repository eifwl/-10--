#include <windows.h>

HWND hwndButton1;
HWND hwndButton2;
HWND hwndButton3;
HWND hwndButton4;
HWND hwndButton5;
HWND hwndInfo;
HWND hwndColor;
HBRUSH hBrush; // Оголошення глобальної змінної

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE:
            // Створення кнопок для пального
            hwndButton1 = CreateWindowEx(0, "BUTTON", "Gasoline<3",
                                         WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                         20, 20, 100, 25, hwnd, (HMENU)1, NULL, NULL);

            hwndButton2 = CreateWindowEx(0, "BUTTON", "Diesel<3",
                                         WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                         20, 50, 100, 25, hwnd, (HMENU)2, NULL, NULL);

            hwndButton3 = CreateWindowEx(0, "BUTTON", "Hybrid<3",
                                         WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                         20, 80, 100, 25, hwnd, (HMENU)3, NULL, NULL);

            hwndButton4 = CreateWindowEx(0, "BUTTON", "Electric<3",
                                         WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                         20, 110, 100, 25, hwnd, (HMENU)4, NULL, NULL);

            // Створення кнопок для типу машини
            CreateWindow("STATIC", "Choose car type:", WS_VISIBLE | WS_CHILD,
                         150, 20, 120, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("BUTTON", "Universal<3", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                         150, 50, 100, 20, hwnd, (HMENU)5, NULL, NULL);

            CreateWindow("BUTTON", "Hatchback<3", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                         150, 80, 100, 20, hwnd, (HMENU)6, NULL, NULL);

            CreateWindow("BUTTON", "Crossover<3", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                         150, 110, 100, 20, hwnd, (HMENU)7, NULL, NULL);

            CreateWindow("BUTTON", "SUV<3", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                         150, 140, 100, 20, hwnd, (HMENU)8, NULL, NULL);

            // Створення кнопок для вибору коробки передач
            CreateWindow("STATIC", "Choose transmission type:", WS_VISIBLE | WS_CHILD,
                         280, 20, 160, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("BUTTON", "Manual<3", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                         280, 50, 100, 25, hwnd, (HMENU)9, NULL, NULL);

            CreateWindow("BUTTON", "Automatic<3", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                         280, 80, 100, 25, hwnd, (HMENU)10, NULL, NULL);

            CreateWindow("BUTTON", "Robot<3", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                         280, 110, 100, 25, hwnd, (HMENU)11, NULL, NULL);

            // Створення кнопок для вибору кольору
            CreateWindow("STATIC", "Choose color:", WS_VISIBLE | WS_CHILD,
                         420, 20, 120, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("BUTTON", "Black<3", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                         420, 50, 100, 25, hwnd, (HMENU)12, NULL, NULL);

            CreateWindow("BUTTON", "Red<3", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                         420, 80, 100, 25, hwnd, (HMENU)13, NULL, NULL);

            CreateWindow("BUTTON", "Green<3", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                         420, 110, 100, 25, hwnd, (HMENU)14, NULL, NULL);

            CreateWindow("BUTTON", "Yellow<3", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                         420, 140, 100, 25, hwnd, (HMENU)15, NULL, NULL);

            // Створення статичного текстового елемента для відображення вибору
            hwndInfo = CreateWindow("STATIC", "", WS_VISIBLE | WS_CHILD | SS_LEFT
                                                  | WS_BORDER,
                                    20, 200, 580, 250, hwnd, NULL, NULL, NULL);

            // Оголошення м'ятного кольору
            hBrush = CreateSolidBrush(RGB(155, 255, 152));

            break;

        case WM_CTLCOLORBTN: {
            HDC hdc = (HDC)wParam;
            SetBkColor(hdc, RGB(155, 255, 152)); // М'ятний колір
            return (INT_PTR)hBrush;
        }

        case WM_ERASEBKGND:
        {
            HDC hdc = (HDC)wParam;
            RECT rect;
            GetClientRect(hwnd, &rect);
            FillRect(hdc, &rect, hBrush);
            return (LRESULT)1;
        }

        case WM_COMMAND:
        {
            char buffer[256];
            switch (LOWORD(wParam)) {
                case 1:
                    strcpy(buffer, "You chose gasoline<3\r\n");
                    break;
                case 2:
                    strcpy(buffer, "You chose diesel<3\r\n");
                    break;
                case 3:
                    strcpy(buffer, "You chose hybrid<3\r\n");
                    break;
                case 4:
                    strcpy(buffer, "You chose electric<3\r\n");
                    break;
                case 5:
                    strcpy(buffer, "You chose universal<3\r\n");
                    break;
                case 6:
                    strcpy(buffer, "You chose hatchback<3\r\n");
                    break;
                case 7:
                    strcpy(buffer, "You chose crossover<3\r\n");
                    break;
                case 8:
                    strcpy(buffer, "You chose SUV<3\r\n");
                    break;
                case 9:
                    strcpy(buffer, "You chose manual transmission<3\r\n");
                    break;
                case 10:
                    strcpy(buffer, "You chose automatic transmission<3\r\n");
                    break;
                case 11:
                    strcpy(buffer, "You chose robot transmission<3\r\n");
                    break;
                case 12:
                    strcpy(buffer, "You chose black color<3\r\n");
                    break;
                case 13:
                    strcpy(buffer, "You chose red color<3\r\n");
                    break;
                case 14:
                    strcpy(buffer, "You chose green color<3\r\n");
                    break;
                case 15:
                    strcpy(buffer, "You chose yellow color<3\r\n");
                    break;
                default:
                    strcpy(buffer, "");
                    break;
            }

            // Отримуємо поточний текст
            char currentText[4096];
            GetWindowText(hwndInfo, currentText, sizeof(currentText));

            // Об'єднуємо поточний текст з новим
            strcat(currentText, buffer);

            // Встановлюємо новий текст
            SetWindowText(hwndInfo, currentText);
        }
            break;

        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    // Оголошення м'ятного кольору
    hBrush = CreateSolidBrush(RGB(155, 255, 152));

    // Реєстрація класу вікна
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "WindowClass";
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Створення вікна
    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, "WindowClass", "Експертна система «Вибір автомобіля»",
                          WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Головний цикл повідомлень
    while (GetMessage(&Msg, NULL, 0, 0) > 0) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}

