// Animations.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "main.h"
#include "StaticAnimation.h"
#include "DynamicAnimation.h"
static StaticAnimation staticAnimation;
static DynamicAnimation *dynamicAnimation;

int AnimationPlaySpeed = 2;

void changeAnimationPlaySpeed(int val) {
	
	val > 0 ? AnimationPlaySpeed = AnimationPlaySpeed < 22 ? AnimationPlaySpeed + 1 : AnimationPlaySpeed : AnimationPlaySpeed = AnimationPlaySpeed > 0 ? AnimationPlaySpeed - 1 : AnimationPlaySpeed;
	staticAnimation.playSpeed(AnimationPlaySpeed);
	dynamicAnimation->playSpeed(AnimationPlaySpeed);
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	PAINTSTRUCT ps;
	HDC hdc = NULL;
	HDC hdcMem;
	RECT rect;
	HBITMAP hbmMem;
	int width;
	int height;
	HANDLE hOld;

	

    switch (message)
    {
	case WM_CREATE:
			
			SetTimer(hWnd, TIMER_ELAPSE, 40, (TIMERPROC)NULL);
			dynamicAnimation = new  DynamicAnimation(hWnd);
			staticAnimation.playSpeed(AnimationPlaySpeed);
			dynamicAnimation->playSpeed(AnimationPlaySpeed);
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case TIMER_ELAPSE:
			staticAnimation.update(hWnd);
			dynamicAnimation->update(hWnd);
			break;
		}
		break;
    case WM_COMMAND:
        {
			RECT rect;
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case ID_FILE_EXIT:
                DestroyWindow(hWnd);
                break;
			case ID_ANIMATION_STATIC:
				GetClientRect(hWnd, &rect);
				dynamicAnimation->stop();
				InvalidateRect(hWnd, &rect, false);
				staticAnimation.start();
				break;
			case ID_ANIMATION_DYNAMIC:
				GetClientRect(hWnd, &rect);
				staticAnimation.stop();
				InvalidateRect(hWnd, &rect, false);
				dynamicAnimation->start();
				break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
			GetClientRect(hWnd, &rect);
			width = rect.right - rect.left;
			height = rect.bottom - rect.top;

			hdc = BeginPaint(hWnd, &ps);

			// Create an off-screen DC for double-buffering
			hdcMem = CreateCompatibleDC(hdc);
			hbmMem = CreateCompatibleBitmap(hdc, width, height);

			hOld = SelectObject(hdcMem, hbmMem);

			staticAnimation.render(hdcMem);
			dynamicAnimation->render(hdcMem);

			// Transfer the off-screen DC to the screen
			BitBlt(hdc, 0, 0, width, height, hdcMem, 0, 0, SRCCOPY);

			// Free-up the off-screen DC
			SelectObject(hdcMem, hOld);
			DeleteObject(hbmMem);
			DeleteDC(hdcMem);

			EndPaint(hWnd, &ps);
			return 0;
        }
        break;
	case WM_LBUTTONUP: {
		dynamicAnimation->addShape(LOWORD(lParam), HIWORD(lParam),0);
		break;
	}
	case WM_RBUTTONUP: {
		dynamicAnimation->addShape(LOWORD(lParam), HIWORD(lParam), 1);
		break;
	}
	case WM_MOUSEWHEEL: {
		int mouseWheel = (short)HIWORD(wParam);
		changeAnimationPlaySpeed(mouseWheel);
		break;
	}
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

