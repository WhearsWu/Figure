#include "Figure_Transform.h"
void Figure_Transform()
{
	unsigned short int x,y;
	for(x = 0;x!=PictreWidth;x++)
	{
		for(y = 0;y!=PictreHeight;y++)
		{
			
			if(x == 0||x==(PictreWidth-1)||y == 0||y==(PictreHeight-1))
			{
				imag_Minesweep[x][y] = 0;
			}
			else
			{
				imag_Minesweep[x][y] = image[x-1][y-1]+image[x][y-1]+image[x+1][y-1]+image[x-1][y]+image[x][y]+image[x+1][y]+image[x-1][y+1]+image[x][y+1]+image[x+1][y+1];
			}
		} 
	}
}

void Figure_InverseTransform()
{
	unsigned short int x,y;
	for(x = 1;x!=PictreWidth-1;x++)
	{
		for(y = 1;y!=PictreHeight-1;y++)
		{
			image[x][y] = imag_Minesweep[x-1][y-1]+imag_Minesweep[x][y-1]+imag_Minesweep[x+1][y-1]+imag_Minesweep[x-1][y]+imag_Minesweep[x][y]+imag_Minesweep[x+1][y]+imag_Minesweep[x-1][y+1]+imag_Minesweep[x][y+1]+imag_Minesweep[x+1][y+1];
			image[x][y]/=9;
			if(image[x][y]>1)
				image[x][y] = 1;
		}
	}
}	

