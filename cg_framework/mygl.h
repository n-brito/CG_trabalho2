#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

void putPixel(int x, int y, int r, int g , int b) {
    
	// Posicao do primeiro componente do pixel no colorbuffer
	int pos = (x * 4) + (y * IMAGE_WIDTH * 4);
	
	
        FBptr[pos] = r;
        FBptr[pos + 1] = g;
        FBptr[pos + 2] = b;
        FBptr[pos + 3] = 255;
  
}


void drawLine(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
 
	dx=x1-x0;
	dy=y1-y0;
 
	x=x0;
	y=y0;
 
	p=2*dy-dx;
 
	while(x<x1)  
	{
		if(p>=0)
		{	
			
			putPixel(x, y, x/2, x/2, x+y/2);
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			putPixel(x, y, x/2, x/2, x+y/2);
			p=p+2*dy;
		}
		x=x+1;
	}
}

void drawTriangle (int x0, int y0, int x1, int y1, int x2, int y2) {
	drawLine(x0, y0, x1, y1);
	drawLine(x1, y1, x2, y2);
	drawLine(x0, y0, x2, y2);
}




#endif // _MYGL_H_
	
