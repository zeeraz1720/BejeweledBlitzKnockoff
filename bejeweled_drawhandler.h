#include <windows.h>



void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void myLine(int x1, int y1, int x2, int y2,int color) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen =CreatePen(PS_SOLID,2,RGB(color,color,color)); //2 is the width of the pen
    SelectObject(device_context,pen);
	MoveToEx(device_context,x1,y1,NULL);
    LineTo(device_context,x2, y2);
	ReleaseDC(console_handle, device_context);  
	DeleteObject(pen);
	
}

void myAdvLine(int x1, int y1, int x2, int y2, int widthNum, int col1, int col2, int col3) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, widthNum, RGB(col1, col2, col3)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}


// This function checks if any of the 4 cursor keys are pressed. 
// If any cursor key is pressed, then the function returns true, and whichKey identifies which of the 4 cursor keys is pressed.
// whichkey is assigned following values if any cursor key is pressed. 1 for left, 2 for up, 3 for right and 4 for left.
bool isCursorKeyPressed(int& whichKey)   //whichKey passed as reference.... 
{
	char key;
	key = GetAsyncKeyState(37) || GetAsyncKeyState(65);
	if (key == 1)
	{
		whichKey = 1;		// 1 if left key is pressed 
		return true;
	}
	key = GetAsyncKeyState(38) || GetAsyncKeyState(87);
	if (key == 1)
	{

		whichKey = 2;		// 2 if up key is pressed
		return true;
	}

	key = GetAsyncKeyState(39) || GetAsyncKeyState(68);
	if (key == 1)
	{

		whichKey = 3;		// 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(40) || GetAsyncKeyState(83);
	if (key == 1)
	{

		whichKey = 4;		// 4 if down key is pressed
		return true;
	}
	key = GetAsyncKeyState(32);
	if (key == 1)
	{

		whichKey = 5;   // 5 if Space key is pressed
		return true;
	}
	key = GetAsyncKeyState(13);
	if (key == 1)
	{

		whichKey = 6;   // 5 if Enter key is pressed
		return true;
	}
	return false;
}

void myRectangle(int x1, int y1, int x2, int y2, int R, int G, int B )
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,RGB(R,G,B)); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(0,0,0)); //Fill color can also be passed as parameter to the function!!!
	
	SelectObject(device_context,brush);
	
	Rectangle(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context); 
	DeleteObject(pen);
	DeleteObject(brush);
}

void myRectangle_filled(int x1, int y1, int x2, int y2, int Rb, int Gb, int Bb, int Ri, int Gi, int Bi)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(Rb, Gb, Bb));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(Ri, Gi, Bi)); //Fill color is passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,RGB(R,G,B)); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(0, 0, 0));  //Fill color is black
	SelectObject(device_context,brush);
	Ellipse(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);

}

void myEllipse_filled(int x1, int y1, int x2, int y2, int Rb, int Gb, int Bb, int Ri, int Gi, int Bi)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(Rb, Gb, Bb));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(Ri, Gi, Bi));  // Fill color
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);

}

void myTriangle(int x1, int y1, int x2, int y2, int R, int  G, int B)
{
	int tx1, tx2, tx3, ty1, ty2, ty3;
	tx1 = (x1 + x2) / 2;
	ty1 = y1;
	tx2 = x2;
	ty2 = y2;
	tx3 = x1;
	ty3 = y2;
	POINT A[3] = { {tx1,ty1},{tx2,ty2},{tx3,ty3} };
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Polygon(device_context, A, 3);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void myTriangle_filled(int x1, int y1, int x2, int y2, int Rb, int Gb, int Bb, int Ri, int Gi, int Bi)
{
	int tx1, tx2, tx3, ty1, ty2, ty3;
	tx1 = (x1 + x2) / 2;
	ty1 = y1;
	tx2 = x2;
	ty2 = y2;
	tx3 = x1;
	ty3 = y2;
	POINT A[3] = { {tx1,ty1},{tx2,ty2},{tx3,ty3} };
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(Rb, Gb, Bb));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(Ri, Gi, Bi)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Polygon(device_context, A, 3);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void myDiamond(int x1, int y1, int x2, int y2, int R, int  G, int B)
{
	int dx1, dx2, dx3, dx4, dy1, dy2, dy3, dy4;
	dx1 = (x1 + x2) / 2;
	dx2 = dx1;
	dy1 = y1;
	dy2 = y2;
	dy3 = (y1 + y2) / 2;
	dy4 = dy3;
	dx3 = x1;
	dx4 = x2;
	POINT A[4] = { {dx1,dy1},{dx4,dy4},{dx2,dy2},{dx3,dy3} };
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Polygon(device_context, A, 4);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void myDiamond_filled(int x1, int y1, int x2, int y2, int Rb, int Gb, int Bb, int Ri, int Gi, int Bi)
{
	int dx1, dx2, dx3, dx4, dy1, dy2, dy3, dy4;
	dx1 = (x1 + x2) / 2;
	dy1 = y1;
	dx2 = dx1;
	dy2 = y2;
	dx3 = x1;
	dy3 = (y1 + y2) / 2;
	dx4 = x2;
	dy4 = dy3;
	POINT A[4] = { {dx1,dy1},{dx4,dy4},{dx2,dy2},{dx3,dy3} };
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(Rb, Gb, Bb));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(Ri, Gi, Bi)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Polygon(device_context, A, 4);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void myHexagon(int x1, int y1, int x2, int y2, int R, int  G, int B)
{
	int hx1, hx2, hx3, hx4, hx5, hx6, hy1, hy2, hy3, hy4, hy5, hy6;
	int diff = abs(x2 - x1);

	hx1 = (x1 + x2) / 2;
	hy1 = y1;

	hx2 = x2 - int(diff * 0.057142857) + 1;
	hy2 = y1 + int(diff * 0.257142857) + 1;

	hx3 = x2 - int(diff * 0.057142857) + 1;
	hy3 = y1 + int(diff * 0.6857142857) + 1;

	hx4 = hx1;
	hy4 = y2;

	hx5 = x1 + int(diff * 0.057142857) + 1;
	hy5 = hy3;

	hx6 = x1 + int(diff * 0.057142857) + 1;
	hy6 = hy2;

	POINT A[6] = { {hx1,hy1},{hx2,hy2},{hx3,hy3},{hx4,hy4},{hx5,hy5},{hx6,hy6} };
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Polygon(device_context, A, 6);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void myHexagon_filled(int x1, int y1, int x2, int y2, int Rb, int Gb, int Bb, int Ri, int Gi, int Bi)
{
	int hx1, hx2, hx3, hx4, hx5, hx6, hy1, hy2, hy3, hy4, hy5, hy6;
	int diff = abs(x2 - x1);

	hx1 = (x1 + x2) / 2;
	hy1 = y1;

	hx2 = x2 - int(diff * 0.057142857) + 1;
	hy2 = y1 + int(diff * 0.257142857) + 1;

	hx3 = x2 - int(diff * 0.057142857) + 1;
	hy3 = y1 + int(diff * 0.6857142857) + 1;

	hx4 = hx1;
	hy4 = y2;

	hx5 = x1 + int(diff * 0.057142857) + 1;
	hy5 = hy3;

	hx6 = x1 + int(diff * 0.057142857) + 1;
	hy6 = hy2;

	POINT A[6] = { {hx1,hy1},{hx2,hy2},{hx3,hy3},{hx4,hy4},{hx5,hy5},{hx6,hy6} };
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(Rb, Gb, Bb));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(Ri, Gi, Bi)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Polygon(device_context, A, 6);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void myEmerald(int x1, int y1, int x2, int y2, int R, int  G, int B)
{
	int tx1, tx2, tx3, tx4, tx5, ty1, ty2, ty3, ty4, ty5;
	int diff = abs(x2 - x1);

	tx1 = (x1 + x2) / 2;
	ty1 = y2;

	tx2 = x1;
	ty2 = y1 + int(diff * 0.37142857) + 1;

	tx3 = x1 + int(diff * 0.22857142857) + 1;
	ty3 = y1;

	tx4 = x1 + int(diff * 0.82857142857) + 1;
	ty4 = ty3;

	tx5 = x2;
	ty5 = ty2;

	POINT A[5] = { {tx1,ty1},{tx2,ty2},{tx3,ty3},{tx4,ty4},{tx5,ty5} };
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Polygon(device_context, A, 5);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void myEmerald_filled(int x1, int y1, int x2, int y2, int Rb, int Gb, int Bb, int Ri, int Gi, int Bi)
{
	int tx1, tx2, tx3, tx4, tx5, ty1, ty2, ty3, ty4, ty5;
	int diff = abs(x2 - x1);
	
	tx1 = (x1 + x2) / 2;
	ty1 = y2;

	tx2 = x1;
	ty2 = y1 + int(diff * 0.37142857) + 1;

	tx3 = x1 + int(diff * 0.22857142857) + 1;
	ty3 = y1;

	tx4 = x1 + int(diff * 0.82857142857) + 1;
	ty4 = ty3;

	tx5 = x2;
	ty5 = ty2;

	POINT A[5] = { {tx1,ty1},{tx2,ty2},{tx3,ty3},{tx4,ty4},{tx5,ty5} };
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(Rb, Gb, Bb));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(Ri, Gi, Bi)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Polygon(device_context, A, 5);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void myDecagon(int x1, int y1, int x2, int y2, int R, int  G, int B)
{
	int tx1, tx2, tx3, tx4, tx5, ty1, ty2, ty3, ty4, ty5;
	int diff = abs(x2 - x1);

	tx1 = (x1 + x2) / 2;
	ty1 = y2;

	tx2 = x1;
	ty2 = y1 + int(diff * 0.57142857) + 1;

	tx3 = x1 + int(diff * 0.142857) + 1;
	ty3 = y1;

	tx4 = x1 + 36;
	ty4 = ty3;

	tx5 = x2;
	ty5 = ty2;

	POINT A[5] = { {tx1,ty1},{tx2,ty2},{tx3,ty3},{tx4,ty4},{tx5,ty5} };
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Polygon(device_context, A, 5);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void myDecagon_filled(int x1, int y1, int x2, int y2, int Rb, int Gb, int Bb, int Ri, int Gi, int Bi)
{
	int dx1, dx2, dx3, dx4, dx5, dx6, dx7, dx8, dx9, dx10;
	int dy1, dy2, dy3, dy4, dy5, dy6, dy7, dy8, dy9, dy10;
	int diff = abs(x2 - x1);

	dx1 = x1 + int(diff * 0.37142857) + 1;
	dy1 = y1 + int(diff * 0.142857) + 1;

	dx2 = x1 + int(diff * 0.62857142857) + 1;
	dy2 = y1 + int(diff * 0.142857) + 1;

	dx3 = x2;
	dy3 = y1;

	dx4 = x2 - (int(diff * 0.142857) + 1);
	dy4 = (y1 + y2) / 2;

	dx5 = x2;
	dy5 = y2;

	dx6 = x1 + int(diff * 0.62857142857) + 1;
	dy6 = y2 - (int(diff * 0.142857) + 1);

	dx7 = x1 + int(diff * 0.37142857) + 1;
	dy7 = y2 - (int(diff * 0.142857) + 1);

	dx8 = x1;
	dy8 = y2;

	dx9 = x1 + int(diff * 0.142857) + 1;
	dy9 = (y1 + y2) / 2;

	dx10 = x1;
	dy10 = y1;

	POINT A[10] = { {dx1,dy1},{dx2,dy2},{dx3,dy3},{dx4,dy4},{dx5,dy5},{dx6,dy6},{dx7,dy7},{dx8,dy8},{dx9,dy9},{dx10,dy10} };
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(Rb, Gb, Bb));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(Ri, Gi, Bi)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Polygon(device_context, A, 10);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

