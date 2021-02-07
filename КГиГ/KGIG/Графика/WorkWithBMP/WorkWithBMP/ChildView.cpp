#include "stdafx.h"
#include "WorkWithBMP.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CChildView::CChildView() : m_Index(0), m_Bitmap(NULL)
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_FILE_OPEN, &CChildView::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE_AS, &CChildView::OnFileSaveAs)
END_MESSAGE_MAP()



// ����������� ��������� CChildView

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this);

	switch (m_Index)
	{
	case DRAW_BMP_STATE:
		ShowBitMap(m_hWnd, m_Bitmap, 10, 10);
		m_Index = 0;
		break;
	}
}


void CChildView::OnFileOpen()
{
	m_Bitmap = (HBITMAP)LoadImage(NULL, _TEXT("test.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	m_Index = DRAW_BMP_STATE;
	Invalidate();
}

void CChildView::OnFileSaveAs()
{
	ClientToBmp(m_hWnd, _TEXT("saved.bmp"));
}

void CChildView::ShowBitMap(HWND hWnd, HBITMAP hBit, int x, int y)
	// ������� ���������� ������� hBit � ������� (x, y) ���� hWnd
{
	BITMAP bitmap;
	GetObject(hBit, sizeof(BITMAP), &bitmap);

	int 
		width = bitmap.bmWidth,
		height = bitmap.bmHeight;
		
	HDC 
		hdc = ::GetDC(hWnd), // ��������� ��������� �����������
		hdcMem = CreateCompatibleDC(hdc); // �������� ��������� ������

	HBITMAP oldBitmap = (HBITMAP)SelectObject(hdcMem, hBit);

	::BitBlt(hdc, x, y, width, height, hdcMem, 0, 0, SRCCOPY);
	::SelectObject(hdcMem, oldBitmap);
	::ReleaseDC(hWnd, hdc);
	::DeleteDC(hdcMem);
}

void CChildView::ClientToBmp(HWND hWnd, CString name)
	// ���������� ������� ������� ���� � �����
{
	RECT rect;
	BITMAPFILEHEADER bmfFileHdr;
	BITMAPINFOHEADER bmpInfoHdr;
	HDC hdc = ::GetDC(hWnd), hdcMem = ::CreateCompatibleDC(hdc);

	int bitToPixel = 16;          // �������� �������
	::GetClientRect(hWnd, &rect); // ��������� �������� ������� �������

	// ������� ������� ����� BitMap �� ������� ������� ������� ����
	// ������� ����� ��������� �� ������ ��������� ���������� hdc, �������
	// ��� ������ ����������� DDB-������� (� �� DIB). ������� ������ 
	// ������������ ������� WriteDIBC()

	HBITMAP bitmap = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
	HBITMAP oldBitmap = (HBITMAP)SelectObject(hdcMem, bitmap);
	BitBlt(hdcMem, 0, 0, rect.right, rect.bottom, hdc, 0, 0, SRCCOPY);
	bitmap = (HBITMAP)SelectObject(hdcMem, oldBitmap);
	::ZeroMemory(&bmpInfoHdr, sizeof(BITMAPINFOHEADER));

	bmpInfoHdr.biSize = sizeof(BITMAPINFOHEADER);
	bmpInfoHdr.biWidth = rect.right;
	bmpInfoHdr.biHeight = rect.bottom;
	bmpInfoHdr.biPlanes = 1;
	bmpInfoHdr.biBitCount = bitToPixel;

	// ��� ���������� ������� ����������� � ������ ����������� ��������
	// rect.right * bitToPixel / 8 ���� �� ������ �� ��������, �������� ������.
	// ��� ���������� ����� ��������� � ������� GetDIBits() (��. MSDN)

	bmpInfoHdr.biSizeImage = (rect.right * bitToPixel + 31) / 32 * 4 * rect.bottom;

	HANDLE fileHdr = ::CreateFile(name, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL); // ��������� ����

	if (FAILED(fileHdr)) return;

	bmfFileHdr.bfType = ('M' << 8) | 'B'; // ��������� �������� ���������

	bmfFileHdr.bfSize = // ������ �����
		bmpInfoHdr.biSizeImage + sizeof(BITMAPFILEHEADER) +	bmpInfoHdr.biSize;

	bmfFileHdr.bfReserved1 = bmfFileHdr.bfReserved2 = 0;

	bmfFileHdr.bfOffBits = // �������� �� ������ ������
		sizeof(bmfFileHdr) + bmpInfoHdr.biSize;

	DWORD dwWritten; // ���� ��������

	::WriteFile(fileHdr, (LPSTR)&bmfFileHdr, sizeof(BITMAPFILEHEADER), &dwWritten, NULL); // ������ ��������� � ����
	::WriteFile(fileHdr, (LPSTR)&bmpInfoHdr, sizeof(BITMAPINFOHEADER), &dwWritten, NULL); // ������ ������������ ���������

	// �������� ����� � ������ ��� ����, ����� ������� GetDIBits() ��������� ���� ���� ����� � DIB-�������

	LPVOID lp = (LPVOID)::GlobalAlloc(GMEM_FIXED, bmpInfoHdr.biSizeImage);

	// �� ����� 

	int err = ::GetDIBits(hdc, bitmap, 0, (UINT)rect.bottom, lp, (LPBITMAPINFO)&bmpInfoHdr, DIB_RGB_COLORS);

	::WriteFile(fileHdr, lp, bmpInfoHdr.biSizeImage, &dwWritten, NULL); // ������ ����������� �� ����

	::GlobalFree(::GlobalHandle(lp));
	::CloseHandle(fileHdr);
	::ReleaseDC(hWnd, hdc);
	::DeleteDC(hdcMem);
}