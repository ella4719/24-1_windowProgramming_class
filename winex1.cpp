#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM IParam);



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpszCmdLine, int nCmdShow)
{

	HWND 		hwnd;												// ������ �ڵ�
	MSG 		msg;												// �޽��� ����ü
	WNDCLASSEX	WndClass;   										// ������ Ŭ���� ����ü		

	// �� ������ Ŭ���� ����ü WndClass�� ���� ä�� ������ Ŭ������ ����Ѵ�.
	WndClass.cbSize = sizeof(WNDCLASSEX);							// ����ü ũ��
	WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;			// Ŭ���� ��Ÿ��
	WndClass.lpfnWndProc = WndProc;									// ������ ���ν���
	WndClass.cbClsExtra = 0;										// ������Ŭ���� �����Ϳ���
	WndClass.cbWndExtra = 0;										// �������� �����Ϳ���
	WndClass.hInstance = hInstance;									// �ν��Ͻ� �ڵ�
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// ������ �ڵ�
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// Ŀ�� �ڵ�
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// ��� �귯�� �ڵ�
	WndClass.lpszMenuName = NULL;									// �޴� �̸�
	WndClass.lpszClassName = "EasyText";							// ������ Ŭ���� �̸�
	WndClass.hIconSm = 0;											// �⺻���� ���� ������

	// ������ Ŭ������ ����Ѵ�.
	RegisterClassEx(&WndClass);

	// �� ������ �����츦 �����Ѵ�.
	hwnd = CreateWindow(											// ������ ���� API���Լ�
		"EasyText",													// ��ϵ� ������ Ŭ���� �̸�
		"Practice1",												// Ÿ��Ʋ �ٿ� ��µ� ���ڿ�
		WS_OVERLAPPEDWINDOW,										// ������ ��Ÿ��
		CW_USEDEFAULT,												// ������ ���� ����� x��ǥ
		CW_USEDEFAULT,												// ������ ���� ����� y��ǥ
		CW_USEDEFAULT,												// �������� �ʺ�
		CW_USEDEFAULT,												// �������� ����
		NULL,														// �θ� �������� �ڵ�
		NULL,														// �޴� �Ǵ� �ڽ� �������� �ڵ�
		hInstance,													// ���ø����̼� �ν��Ͻ� �ڵ�
		NULL														// ������ ���� �������� �ּ� 
	);

	//������ �����츦 ȭ�鿡 ǥ���Ѵ�.
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	//�޽��� ť�κ��� �޽����� �޾ƿ� �޽����� �ش� ������ ���ν����� ������.
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); //�޽����� �����Ѵ�.
		DispatchMessage(&msg); //�޽����� �ش� ������ ���ν����� ������.


	}
	return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc; //����̽� ���ؽ�Ʈ
	RECT rect; // RECT ����ü
	PAINTSTRUCT ps; // ����Ʈ ����ü
	LPTSTR szMsg1 = "I love Window Programming!";
	LPTSTR szMsg2 = "Ű���� ����";
	LPTSTR szMsg3 = "Ű���� ������";
	LPTSTR szMsg4 = "���콺�� ���������ϴ�.";
	LPTSTR szMsg5 = "���콺�� �̵����Դϴ�";
	

	//1.Ŀ�ο��� ���� �޽����� ����ġ ���� �̿��Ͽ� ó��
	switch (message)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 10, 10, szMsg1, strlen(szMsg1)); //printout letters at window
		EndPaint(hwnd, &ps);
		break;
	case WM_KEYDOWN:
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg2, strlen(szMsg2), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_KEYUP:
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg3, strlen(szMsg3), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;

	case WM_LBUTTONDOWN:
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg4, strlen(szMsg4), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;


	case WM_LBUTTONUP:
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		InvalidateRect(hwnd, NULL, TRUE);
		ReleaseDC(hwnd, hdc);
		break;
	
	case WM_MOUSEMOVE:
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg5, strlen(szMsg5), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;

	case WM_LBUTTONDBLCLK:
		//left mouse key double clicked
		MessageBox(hwnd, "���콺 ���� Ŭ��! ", "���콺�޽���", MB_OK | MB_ICONASTERISK);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;

}
