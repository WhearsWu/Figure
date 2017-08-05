#include "Figure_Define.h"
char image[PictreHeight][PictreWidth];
char imag_Minesweep[PictreHeight][PictreWidth];
void Figure_StuctInit_PictreType(PictreType *Pictre)
{
	Pictre->height = 0;
	Pictre->width = 0;
}
void Figure_StructInit_PointListType(PointListType *PointList)
{
	PointList->counter = 0;
}
void Figure_StructInit_LineListType(LineListType *LinList)
{
	LinList->counter = 0;
}
void Figure_StructInit_LineType(LineType *line)
{
	line->start.x = 0;
	line->start.y = 0;
	line->end.x = 0;
	line->end.y = 0;
	line->Middle.x = 0;
	line->Middle.y = 0;
	line->leng = 0;
}
