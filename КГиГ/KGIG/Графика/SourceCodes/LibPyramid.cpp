#include "stdafx.h"


////////////////////////// ����������� ///////////////////////////////////
CPyramid::CPyramid()
{
	int rDown = 6, rUp = 3, height = 15;

	Vertices.RedimMatrix(4,8);
	                            // ���������� ������ - �������
	Vertices(0,0)=rDown;		// A: x=10,y=0,z=0
	Vertices(1,1)=-rDown;	    // B: x=0,y=-10,z=0
	Vertices(0,2)=-rDown;	    // C: x=-10,y=0,z=0
	Vertices(1,3)=rDown;		// D: x=0,y=10,z=0

	Vertices(0,4)=rUp;
	Vertices(1,5)=-rUp;
	Vertices(0,6)=-rUp;
	Vertices(1,7)=rUp;

	Vertices(2,4)=height;
	Vertices(2,5)=height;
	Vertices(2,6)=height;
	Vertices(2,7)=height;

	//for(int i=0;i<8;i++)Vertices(3,i)=0;
}


void CPyramid::Draw1(CDC& dc,CMatrix& PView,CRect& RW)
// ������ �������� � ��������� ��������� �����
// ��������������� �������� ��������� �� ������� � ������� (MM_TEXT)
// dc - ������ �� ����� CDC MFC
// PView - ���������� ����� ���������� � ������� ����������� ������� ���������
// (r,fi(����.), q(����.))
// RW - ������� � ���� ��� �����������
{
	CMatrix ViewCart=SphereToCart(PView);		// ��������� ���������� ����� ����������
	//double zz=ViewCart(2);
	CMatrix MV=CreateViewCoord(PView(0),PView(1),PView(2));	//�������(4x4) 
														                     //��� ��������� � ������� �� 
	CMatrix ViewVert=MV*Vertices; // ���������� ������ �������� � ������� ��
	CRectD RectView;
	GetRect(ViewVert,RectView);		// �������� ������������ �������������
	CMatrix MW=SpaceToWindow(RectView,RW);	// ������� (3x3) ��� ��������� 
                                          // � ������� ������� ���������
// ������� ������ ������� ��������� ��� ���������
	CPoint MasVert[8];	// ������ ������� ��������� ������
	CMatrix V(3); //V0(3);
	V(2)=1;
	//V0(0)=RectView.left;	
	//V0(1)=RectView.bottom;	
// ���� �� ���������� ������ - ��������� ������� ���������� ������
	for(int i=0;i<8;i++)		
	{
		V(0)=ViewVert(0,i); // x
		V(1)=ViewVert(1,i); // y
		//V=V-V0;			// x-xL, y-yL, 1
		V=MW*V;			// ������� ���������� �����
		MasVert[i].x=(int)V(0);
		MasVert[i].y=(int)V(1);			
	}
// ������

	
	CPen Pen(PS_SOLID, 2, RGB(100, 255, 100));
  CPen* pOldPen =dc.SelectObject(&Pen);
	CBrush Brus(RGB(255,100 , 100));
  CBrush* pOldBrush =dc.SelectObject(&Brus);
	CMatrix VE=Vertices.GetCol(4,0,2);	// ������� E
	CMatrix R1(3),R2(3), R3(3), VN(3);
	double sm;
	for(int i=0;i<4;i++)	
	{
		int k;
		if(i==3) k=0;
		else k=i+1;
		R1=Vertices.GetCol(i,0,2);
		R2=Vertices.GetCol(k,0,2);
		R3=Vertices.GetCol(i+4,0,2);
		//R2=Vertices.GetCol(i+5,0,2);
		CMatrix V1=R2-R1;			      // ������ - ����� � ���������
		CMatrix V2=R3-R2;			      // ������ - ����� ������
		VN=VectorMult(V2,V1);		  	// ������ �������(!) ������� � �����
		sm=ScalarMult(VN,ViewCart);  // ��������� ������������ ������� 
		                             //������� � ����� � ������� ����� ���������� 
		if(sm>=0) // ����� ������ - ������ ������� �����
			{	
				dc.MoveTo(MasVert[i]);
				dc.LineTo(MasVert[i+4]);
				dc.LineTo(MasVert[i == 3 ? 4 : (i+5)]);	
				dc.LineTo(MasVert[i == 3 ? 0 : (i+1)]);
				dc.LineTo(MasVert[i]);
			}
	}
	dc.SelectObject(&pOldBrush);
	VN=VectorMult(R1,R2);	
	sm=ScalarMult(VN,ViewCart);
	if(sm>=0)dc.Polygon(MasVert, 4);	// ���������
	else { // ��������
		
		dc.MoveTo(MasVert[4]);
		dc.LineTo(MasVert[5]);
		dc.LineTo(MasVert[6]);
		dc.LineTo(MasVert[7]);
		dc.LineTo(MasVert[4]);
	}
	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);
}


////////////////////////// Draw(...) ///////////////////////////////
void CPyramid::Draw(CDC& dc,CMatrix& PView,CRect& RW)
// ������ �������� ��� �������� ��������� �����
// ��������������� �������� ��������� �� ������� � ������� (MM_TEXT)
// dc - ������ �� ����� CDC MFC
// PView - ���������� ����� ���������� � ������� ����������� ������� ���������
// (r,fi(����.), q(����.))
// RW - ������� � ���� ��� �����������
{
	CMatrix ViewCart=SphereToCart(PView);		// ��������� ���������� ����� ����������
	//double zz=ViewCart(2);
	CMatrix MV=CreateViewCoord(PView(0),PView(1),PView(2));	//�������(4x4) 
														                     //��� ��������� � ������� �� 
	CMatrix ViewVert=MV*Vertices; // ���������� ������ �������� � ������� ��
	CRectD RectView;
	GetRect(ViewVert,RectView);		// �������� ������������ �������������
	CMatrix MW=SpaceToWindow(RectView,RW);	// ������� (3x3) ��� ��������� 
                                          // � ������� ������� ���������
// ������� ������ ������� ��������� ��� ���������
	CPoint MasVert[8];	// ������ ������� ��������� ������
	CMatrix V(3); //V0(3);
	V(2)=1;
	//V0(0)=RectView.left;	
	//V0(1)=RectView.bottom;	
// ���� �� ���������� ������ - ��������� ������� ���������� ������
	for(int i=0;i<8;i++)		
	{
		V(0)=ViewVert(0,i); // x
		V(1)=ViewVert(1,i); // y
		//V=V-V0;			// x-xL, y-yL, 1
		V=MW*V;			// ������� ���������� �����
		MasVert[i].x=(int)V(0);
		MasVert[i].y=(int)V(1);
	}
// ������

	CPen Pen(PS_SOLID, 2, RGB(0, 0, 0));
  CPen* pOldPen =dc.SelectObject(&Pen);
	dc.Polygon(MasVert, 4);	// ���������
	//dc.Polygon(MasVert + 4, 4);	// ��������
	dc.MoveTo(MasVert[4]);
	dc.LineTo(MasVert[5]);
	dc.LineTo(MasVert[6]);
	dc.LineTo(MasVert[7]);
	dc.LineTo(MasVert[4]);
	for(int i=0;i<4;i++)	
	{
		dc.MoveTo(MasVert[i+4]);	// ���� �� ������� E
		dc.LineTo(MasVert[i]);
	}
// ���������� ������ O 	����������� ���������� ���������
	int x0=(MasVert[0].x+MasVert[2].x)/2;
	int y0=(MasVert[0].y+MasVert[2].y)/2;
	int x1=(MasVert[4].x+MasVert[6].x)/2;
	int y1=(MasVert[4].y+MasVert[6].y)/2;
}


void CPyramid::Draw2(CDC& dc,CMatrix& PView,CRect& RW)
// ������ �������� ��� �������� ��������� �����
// �������� ��������� ��������� Windows, ��� �����
// ������ ���� ���������� ����� ����������� MM_ANISOTROPIC 
// dc - ������ �� ����� CDC MFC
// PView - ���������� ����� ���������� � ������� ����������� ������� ���������
// (r,fi(����.), q(����.))
// RW - ������� � ���� ��� �����������
{
	CMatrix ViewCart=SphereToCart(PView);		// ��������� ���������� ����� ����������
	double zz=ViewCart(2);
	CMatrix MV=CreateViewCoord(PView(0),PView(1),PView(2));	//�������(4x4) 
														                     //��� ��������� � ������� �� 
	CMatrix ViewVert=MV*Vertices; // ���������� ������ �������� � ������� ��
	CRectD RectView;
	GetRect(ViewVert,RectView);		// �������� ������������ �������������


/*
	CMatrix MW=SpaceToWindow(RectView,RW);	// ������� (3x3) ��� ��������� 
                                          // � ������� ������� ���������
// ������� ������ ������� ��������� ��� ���������
	CPoint MasVert[5];	// ������ ������� ��������� ������
	CMatrix V(3),V0(3);
	V(2)=1;
	V0(0)=RectView.left;	
	V0(1)=RectView.bottom;	
// ���� �� ���������� ������ - ��������� ������� ���������� ������
	for(int i=0;i<5;i++)		
	{
		V(0)=ViewVert(0,i); // x
		V(1)=ViewVert(1,i); // y
		V=V-V0;			// x-xL, y-yL, 1
		V=MW*V;			// ������� ���������� �����
		MasVert[i].x=(int)V(0);
		MasVert[i].y=(int)V(1);			
	}

*/

CPoint MasVert[8];	// 
	for(int i=0;i<8;i++)		
	{
		MasVert[i].x=(int)ViewVert(0,i);
		MasVert[i].y=(int)ViewVert(1,i);			
	}

	CRect IRV((int)RectView.left,(int)RectView.top,(int)RectView.right,(int)RectView.bottom);
	SetMyMode(dc,IRV,RW);

// ������
		CPen Pen(PS_SOLID, 0, RGB(255, 0, 0));
  CPen* pOldPen =dc.SelectObject(&Pen);
	dc.Polygon(MasVert, 4);	// ���������
	dc.Polygon(MasVert + 4, 4);	// ��������
	for(int i=0;i<8;i++)	
	{
		dc.MoveTo(MasVert[i+4]);
		dc.LineTo(MasVert[i]);
	}
// ���������� ������ O 	����������� ���������� ���������
	int x0=(MasVert[0].x+MasVert[2].x)/2;
	int y0=(MasVert[0].y+MasVert[2].y)/2;
	int x1=(MasVert[4].x+MasVert[6].x)/2;
	int y1=(MasVert[4].y+MasVert[6].y)/2;
// ������ ��������� � ����� �� E � O 
	CPen Pen1(PS_DASH, 0, RGB(0, 255, 0));
	dc.SelectObject(&Pen1);
	dc.MoveTo(x1,y1);
	dc.LineTo(x0,y0);
	dc.MoveTo(MasVert[0]);	// ���� �� ������� A
	dc.LineTo(MasVert[2]);	// ���������
	dc.MoveTo(MasVert[1]);	// ���� �� ������� B
	dc.LineTo(MasVert[3]);	// ���������

	dc.MoveTo(MasVert[4]);	// ���� �� ������� A1
	dc.LineTo(MasVert[6]);	// ���������
	dc.MoveTo(MasVert[5]);	// ���� �� ������� B1
	dc.LineTo(MasVert[7]);	// ���������

	dc.SelectObject(pOldPen);

	
	dc.SetMapMode(MM_TEXT);

}




////////////////////////// ColorDraw(...) ///////////////////////////////

void CPyramid::ColorDraw(CDC& dc,CMatrix& PView,CRect& RW,COLORREF Color) 

// ������ �������� � ��������� ��������� ����� + ������� � ���������
// ��������������� �������� ��������� �� ������� � ������� (MM_TEXT)
// dc - ������ �� ����� CDC MFC
// PView - ���������� ����� ���������� � ������� ����������� ������� ���������
// (r,fi(����.), q(����.))
// RW - ������� � ���� ��� �����������
{

	BYTE red=GetRValue(Color);
  BYTE green=GetGValue(Color);
  BYTE blue=GetBValue(Color);

	CMatrix ViewCart=SphereToCart(PView);		// ��������� ���������� ����� ����������
	CMatrix MV=CreateViewCoord(PView(0),PView(1),PView(2));	//�������(4x4) 
														                     //��� ��������� � ������� �� 
	CMatrix ViewVert=MV*Vertices; // ���������� ������ �������� � ������� ��
	CRectD RectView;
	GetRect(ViewVert,RectView);		// �������� ������������ �������������
	CMatrix MW=SpaceToWindow(RectView,RW);	// ������� (3x3) ��� ��������� 
                                          // � ������� ������� ���������
// ������� ������ ������� ��������� ��� ���������
	CPoint MasVert[8];	// ������ ������� ��������� ������
	CMatrix V(3); //V0(3);
	V(2)=1;
// ���� �� ���������� ������ - ��������� ������� ���������� ������
	for(int i=0;i<8;i++)		
	{
		V(0)=ViewVert(0,i); // x
		V(1)=ViewVert(1,i); // y
		//V=V-V0;			// x-xL, y-yL, 1
		V=MW*V;			// ������� ���������� �����
		MasVert[i].x=(int)V(0);
		MasVert[i].y=(int)V(1);			
	}
// ������

	CMatrix VE=Vertices.GetCol(4,0,2);	// ������� E
	CMatrix R1(3),R2(3), R3(3), VN(3);
	double sm;
	for(int i=0;i<4;i++)	
	{
		int k;
		if(i==3) k=0;
		else k=i+1;
		R1=Vertices.GetCol(i,0,2);
		R2=Vertices.GetCol(k,0,2);
		R3=Vertices.GetCol(i+4,0,2);
		CMatrix V1=R2-R1;			      // ������ - ����� � ���������
		CMatrix V2=R3-R2;			      // ������ - ����� � ��������
		VN=VectorMult(V2,V1);		  	// ������ �������(!) ������� � �����


		sm=CosV1V2(VN,ViewCart);	// ������� ���� ����� �������� ������� 
		                          // � ����� � �������� ����� ���������� 
		if(sm>=0) // ����� ������ - ������ ������� �����
			{	
				CPen Pen(PS_SOLID, 2, RGB(sm*sm*red, sm*sm*green, sm*sm*blue));
				CPen* pOldPen =dc.SelectObject(&Pen);
				CBrush Brus(RGB(sm*sm*red, sm*sm*green, sm*sm*blue));
				CBrush* pOldBrush =dc.SelectObject(&Brus);
				CPoint MasVertR[4]={MasVert[i+4], MasVert[i == 3 ? 4 : (i+5)], MasVert[i == 3 ? 0 : (i+1)], MasVert[i]};
				dc.Polygon(MasVertR, 4);	// �����
				dc.SelectObject(pOldBrush);
				dc.SelectObject(pOldPen);
			}
	}
	VN=VectorMult(R1,R2);	
	sm=CosV1V2(VN,ViewCart);
		
	CPen Pen(PS_SOLID, 2, RGB(sm*sm*red, sm*sm*green, sm*sm*blue));
	CPen* pOldPen =dc.SelectObject(&Pen);
	CBrush Brus(RGB(sm*sm*red, sm*sm*green, sm*sm*blue));
	CBrush* pOldBrush =dc.SelectObject(&Brus);

	if(sm>=0)
	{
		dc.Polygon(MasVert, 4);	// ���������
	}
	else
	{
		dc.Polygon(MasVert+4, 4);	// ��������
	}
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldPen);
}



////////////////////////// GetRect(...) ///////////////////////////

void CPyramid::GetRect(CMatrix& Vert,CRectD& RectView)
// ��������� ���������� ��������������,������������� �������� 
// �������� �� ��������� XY � ������� ������� ���������
// Ver - ���������� ������ (� ��������)
// RectView - �������� - ������������ �������������
{
	CMatrix V=Vert.GetRow(0);					// x - ����������
	double xMin=V.MinElement();
	double xMax=V.MaxElement();
	V=Vert.GetRow(1);									// y - ����������
	double yMin=V.MinElement();
	double yMax=V.MaxElement();
	RectView.SetRectD(xMin,yMax,xMax,yMin);
}

//---------------------------------------------------------------------