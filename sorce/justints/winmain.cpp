#define BILLGATES

#include "grax.h"
#include "ging.h"
#include "chub.h"
#include "LaceyBanks.h"

	//SHBOBO OPENSOURCE CODE
	//DEVICE: DEERDICK CHUB
	//OS: WINDOWS, USING RAWINPUT
	//DEPENDANCIES (LINKER INPUTS):
	//winmm.lib for sound stuff
	//gdi32.lib for drawing things
	//user32.lib for recieving messages
	//commdlg32.lib for open save dialogs
	//BJUSTINTS, just intonation, only ints
	//no floats allowed! except in static 
	//functions at initiation time, for 
	//computing sine, cosine, and technicalValue

	#include "stdafx.h"
	//#include "MultiplexPotentiator.h"
//#include "GwonzoSound.h"
	//#include "gonzosound.h"

	HINSTANCE hInst; // current instance
	LPCTSTR szTitle =L"JUSTINTS"; // The title bar text
	LPCTSTR szWindowClass =L"JUSTINTS";	// the main window class name
	BOOL InitInstance(HINSTANCE, int);
	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	BOOL goat = TRUE;
	
	HWND hWnd;
	GwonzoSound * g;

	int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
		UNREFERENCED_PARAMETER(hPrevInstance);
		UNREFERENCED_PARAMETER(lpCmdLine);
		MSG msg;
		WNDCLASSEX wcex;
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style			= CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc	= WndProc;
		wcex.cbClsExtra		= 0;
		wcex.cbWndExtra		= 0;
		wcex.hInstance		= hInstance;
		wcex.hIcon			= NULL;
		wcex.hCursor		= NULL;
		wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
		wcex.lpszMenuName	= NULL;
		wcex.lpszClassName	= szWindowClass;
		wcex.hIconSm		= NULL;
		wcex.style = 0;
		RegisterClassEx(&wcex);
		
		if (!InitInstance (hInstance, nCmdShow)) return FALSE;
		
		while (goat) {
			if (g->GonzoTimeCheck()) {
				if (g->GonzoSound())
					g->increment();
				
				//InvalidateRect(hWnd, &rrrq, TRUE); 
			}
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		return (int) msg.wParam;
	}

	



	BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
		hInst = hInstance; // Store instance handle in our global variable
		hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
			30, 30, 500, 500, NULL, NULL, hInstance, NULL);
		if (!hWnd)return FALSE;
     
		//abstr = new MultiplexPotentiator();
		abstr = new LaceyBanks();
		g = new GwonzoSound(abstr);
		
		ChubInit();

		ShowWindow(hWnd, nCmdShow);
		UpdateWindow(hWnd);
		return TRUE;
	}

	void openDialog();
	void saveDialog();
	

	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
		WCHAR *  buffer;
		buffer = L"yoyoyo";
		static LPWAVEHDR pWaveHdr;
		switch (message){
		//case MM_WOM_DONE:
			//pWaveHdr = (WAVEHDR*)lParam;   
			//GonzoSoundL(m, pWaveHdr->dwUser);
			break;
		case WM_ERASEBKGND:
			break;
		case WM_INPUT_DEVICE_CHANGE:
			//if (wParam == GIDC_ARRIVAL) m->arrive((HANDLE)lParam);
			//if (wParam == GIDC_REMOVAL) m->remove((HANDLE)lParam);
			break;
		case WM_INPUT: {
			ChubMassage(lParam);
			InvalidateRect(hWnd, &rrrq, TRUE);
			return 0;
		} 
		case WM_PAINT: {
			GraxWMPaintMassage(hWnd);
			break;
					   }
		case WM_LBUTTONDOWN:
			abstr->mouseButt(MAKEPOINTS(lParam));
			InvalidateRect(hWnd, &rrrq, TRUE);
			break;
		case WM_CHAR:
			if (GetKeyState(VK_CONTROL) < 0) {
				if (((char)(unsigned char)wParam) == 15)//15 not 111 for'o'?
					openDialog();
				if (((char)(unsigned char)wParam) == 19)//same deal?
					saveDialog();
				if (GetKeyState(VK_SHIFT) < 0) {
					if (wParam==4) abstr->dupe_multiplex();
				} else if (wParam==4) abstr->dupe_chubbery();
			} else 
				abstr->charactros(wParam);
			InvalidateRect(hWnd, &rrrq, TRUE);
			break;
		case WM_DESTROY:
			goat = FALSE;
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		return 0;
	}

	void openDialog() {
		OPENFILENAMEA ofn;
		char szFileName[MAX_PATH] = "";
		
	    ZeroMemory(&ofn, sizeof(ofn));

		ofn.lStructSize = sizeof(ofn); // SEE NOTE BELOW
		ofn.hwndOwner = hWnd;
	    ofn.lpstrFilter = "Texte Files (*.texte)\0*.texte\0Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
	    ofn.lpstrFile = szFileName;
	    ofn.nMaxFile = MAX_PATH;
	    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY|OFN_ALLOWMULTISELECT;
	    ofn.lpstrDefExt = "texte";

	    if(GetOpenFileNameA(&ofn)) {
			abstr->textorium_script(ofn.lpstrFile);
	    }
	}
	void saveDialog() {
		OPENFILENAMEA ofn;
		char szFileName[MAX_PATH] = "";
		
	    ZeroMemory(&ofn, sizeof(ofn));

		ofn.lStructSize = sizeof(ofn); // SEE NOTE BELOW
		ofn.hwndOwner = hWnd;
	    ofn.lpstrFilter = "Texte Files (*.texte)\0*.texte\0Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
	    ofn.lpstrFile = szFileName;
	    ofn.nMaxFile = MAX_PATH;
	    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY|OFN_ALLOWMULTISELECT;
	    ofn.lpstrDefExt = "texte";

	    if(GetSaveFileNameA(&ofn)) {
			abstr->textorium_trigger(ofn.lpstrFile);
	    }
	}