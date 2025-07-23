
#include <Windows.h>
#include <gl/GL.h>
#include <cmath>


#define WINDOW_TITLE "P1 Demo"

int qNo = 1;		//question no 1
float x = 0, y = 0;
float angle = 0;
float PI = 3.14159;
float x2, y2;
float radius = 0.2;
int noOfTri = 30;

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			PostQuitMessage(0);
		else if (wParam == '1')		//when press key 1
			qNo = 1;
		else if (wParam == '2')		//when press key 2
			qNo = 2;
		else if (wParam == '3')
			qNo = 3;
		else if (wParam == '4')
			qNo = 4;
		else if (wParam == '5')
			qNo = 5;
		else if (wParam == '6')
			qNo = 6;
		else if (wParam == '7')
			qNo = 7;
		else if (wParam == '8')
			qNo = 8;
		break;


	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

void pahangFlag() {
	glClearColor(0.1234, 0.3214, 0.5463, 0.5);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-0.5, 0.0);
	glVertex2f(-0.5, 0.4);
	glVertex2f(0.5, 0.4);
	glVertex2f(0.5, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0.5, 0.0);
	glVertex2f(0.5, -0.4);
	glVertex2f(-0.5, -0.4);
	glVertex2f(-0.5, 0.0);
	glEnd();
}

void sembilanFlag() {
	glClearColor(0.1234, 0.3214, 0.5463, 0.5);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(-0.8, -0.8);
	glVertex2f(-0.8, 0.8);
	glVertex2f(0.8, 0.8);
	glVertex2f(0.8, -0.8);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-0.8, 0.0);
	glVertex2f(0.0, 0.0);
	glVertex2f(-0.8, 0.8);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.8, 0.8);
	glVertex2f(0.0, 0.8);
	glVertex2f(0.0, 0.0);
	glEnd();
}

void englandFlag() {
	glClearColor(0.1234, 0.3214, 0.5463, 0.5);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-0.8, 0.4);
	glVertex2f(0.8, 0.4);
	glVertex2f(0.8, -0.4);
	glVertex2f(-0.8, -0.4);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.73, 0.0, 0.0);
	glVertex2f(0.1, 0.1);
	glVertex2f(0.8, 0.1);
	glVertex2f(0.8, -0.1);
	glVertex2f(0.1, -0.1);
	glVertex2f(0.1, -0.4);
	glVertex2f(-0.1, -0.4);
	glVertex2f(-0.1, -0.1);
	glVertex2f(-0.8, -0.1);
	glVertex2f(-0.8, 0.1);
	glVertex2f(-0.1, 0.1);
	glVertex2f(-0.1, 0.4);
	glVertex2f(0.1, 0.4);
	glEnd();
}

void scotlandFlag() {
	glClearColor(0.22, 0.0, 0.08, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-0.7, 0.4);
	glVertex2f(0.7, 0.4);
	glVertex2f(0.7, -0.4);
	glVertex2f(-0.7, -0.4);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.12, 0.33, 0.92);
	glVertex2f(-0.5, 0.4);
	glVertex2f(0.5, 0.4);
	glVertex2f(0.0, 0.2);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.12, 0.33, 0.92);
	glVertex2f(0.7, 0.2);
	glVertex2f(0.7, -0.2);
	glVertex2f(0.2, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.12, 0.33, 0.92);
	glVertex2f(0.5, -0.4);
	glVertex2f(-0.5, -0.4);
	glVertex2f(0.0, -0.2);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.12, 0.33, 0.92);
	glVertex2f(-0.7, -0.2);
	glVertex2f(-0.7, 0.2);
	glVertex2f(-0.2, 0.0);
	glEnd();
}

void japanFlag() {
	glClearColor(0.98, 0.52, 0.65, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-0.7, 0.4);
	glVertex2f(0.7, 0.4);
	glVertex2f(0.7, -0.4);
	glVertex2f(-0.7, -0.4);
	glEnd();

	glColor3f(0.73, 0.0, 0.0);

	const int num_segments = 1000;
	const float pi = 3.1415926f;
	const float radius = 0.25f;
	const float center_x = 0.0f;
	const float center_y = 0.0f;

	glBegin(GL_POLYGON);
	for (int i = 0; i < num_segments; i++) {
		float theta = 2.0 * pi * float(i) / float(num_segments);
		float x = radius * cosf(theta);
		float y = radius * sinf(theta);
		glVertex2f(x + center_x, y + center_y);
	}
	glEnd();
}


void japanFlag2() {
	glClearColor(1.0, 1.0, 1.0, 0.0);		//white
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);	//red
	//glVertex2f(x, y);		//origin of circle
	for (angle = PI; angle <= (2 * PI); angle += (2 * PI) / noOfTri) {
		x2 = x + radius * cos(angle);	//quadric equation
		y2 = y + radius * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-0.8, -0.5);
	glVertex2f(-0.8, 0.5);
	glVertex2f(0.8, 0.5);
	glVertex2f(0.8, -0.5);
	glEnd();
}

void japanFlag3() {
	glClearColor(1.0, 1.0, 1.0, 0.0);		//white
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 0.0);	//red
	glVertex2f(x, y);		//origin of circle
	for (angle = 0; angle <= (2 * PI); angle += (2 * PI) / noOfTri) {
		x2 = x + radius * cos(angle);	//quadric equation
		y2 = y + radius * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-0.8, -0.5);
	glVertex2f(-0.8, 0.5);
	glVertex2f(0.8, 0.5);
	glVertex2f(0.8, -0.5);
	glEnd();
}
float colorAngle = 0;  // global variable to track time for color changes



void spiderMan() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	const float radius = 0.8;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x, y);
	for (angle = 0; angle <= (2 * PI); angle += (2 * PI) / noOfTri) {
		x2 = x + radius * cos(angle);
		y2 = y + radius * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();

	glColor3f(0.58, 0, 0);
	glLineWidth(2.0);
	for (int i = 0; i <= 14; i++) {
		float angle = 2 * PI * i / 14;
		glBegin(GL_LINES);
		glVertex2f(0.0, 0.0);
		glVertex2f(0.8 * cos(angle), 0.8 * sin(angle));
		glEnd();
	}

	for (int r = 1; r <= 5; r++) {
		float radius = 0.16 * r;
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < 36; i++) {
			float theta = 2.0 * PI * float(i) / 36;
			glVertex2f(radius * cosf(theta), radius * sinf(theta));
		}
		glEnd();
	}

	// -------------------- Left Eye --------------------
	float eyeRadius = 0.35f;                  // Larger eye
	float whiteEyeRadius = eyeRadius * 0.7f;  // Smaller for black outline
	float eyeOffsetY = 0.2f;
	float eyeOffsetX = -0.35f;
	float tiltAngleLeft = -45.0f * PI / 180.0f;

	// Outer (Blue) - Left Eye
	glColor3f(0.67, 0.85, 0.9);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 180; i++) {
		float theta = PI + (PI * i / 180.0f);
		float x = eyeRadius * cos(theta);
		float y = eyeRadius * sin(theta);
		float rx = cos(tiltAngleLeft) * x - sin(tiltAngleLeft) * y;
		float ry = sin(tiltAngleLeft) * x + cos(tiltAngleLeft) * y;
		glVertex2f(eyeOffsetX + rx, eyeOffsetY + ry);
	}
	glEnd();

	// Inner (Purple) - Centered Left Eye
	glColor3f(0.5, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 180; i++) {
		float theta = PI + (PI * i / 180.0f);
		float x = whiteEyeRadius * cos(theta);
		float y = whiteEyeRadius * sin(theta);
		float rx = cos(tiltAngleLeft) * x - sin(tiltAngleLeft) * y;
		float ry = sin(tiltAngleLeft) * x + cos(tiltAngleLeft) * y;
		glVertex2f(eyeOffsetX + rx, eyeOffsetY + ry);
	}
	glEnd();

	// -------------------- Right Eye --------------------
	eyeOffsetX = 0.35f;
	float tiltAngleRight = 45.0f * PI / 180.0f;

	// Outer (PINk) - Right Eye
	glColor3f(0.98, 0.55, 0.67);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 180; i++) {
		float theta = PI + (PI * i / 180.0f);
		float x = eyeRadius * cos(theta);
		float y = eyeRadius * sin(theta);
		float rx = cos(tiltAngleRight) * x - sin(tiltAngleRight) * y;
		float ry = sin(tiltAngleRight) * x + cos(tiltAngleRight) * y;
		glVertex2f(eyeOffsetX + rx, eyeOffsetY + ry);
	}
	glEnd();

	// Inner (White) - Centered Right Eye
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 180; i++) {
		float theta = PI + (PI * i / 180.0f);
		float x = whiteEyeRadius * cos(theta);
		float y = whiteEyeRadius * sin(theta);
		float rx = cos(tiltAngleRight) * x - sin(tiltAngleRight) * y;
		float ry = sin(tiltAngleRight) * x + cos(tiltAngleRight) * y;
		glVertex2f(eyeOffsetX + rx, eyeOffsetY + ry);
	}
	glEnd();


}

void display()
{
	switch (qNo) {
	case 1:
		pahangFlag();
		break;
	case 2:
		sembilanFlag();
		break;
	case 3:
		englandFlag();
		break;
	case 4:
		scotlandFlag();
		break;
	case 5:
		japanFlag();
		break;
	case 6:
		japanFlag2();
		break;
	case 7:
		japanFlag3();
		break;
	case 8:
		spiderMan();
		break;
	}


}
//--------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------