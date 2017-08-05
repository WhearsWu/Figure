#include "Figure.h"
void Figure_Clean()
{
	unsigned short int x,y;
	for(y = 0;y!=PictreHeight;y++)
	{
		for(x = 0;x!=PictreWidth;x++)
		{
			image[y][x] = 0;
		}
	}
}
void Figure_edge()
{
	unsigned short int x,y;
	unsigned short int mag;
	
	for(y = 1;y!=PictreHeight-1;y++)
	{
		for(x = 1;x!=PictreWidth-1;x++)
		{
 			Figure_Sobel(x,y,&mag);
			if(mag > 2)
				tempimage[y][x]=1;
			else
				tempimage[y][x]=0;
		}
	}
	for(y = 0;y!=PictreHeight;y++)
	{
		for(x = 0;x!=PictreWidth;x++)
		{
			image[y][x] = tempimage[y][x];
		}
	}
}

void Figure_RectangularToDescartes(PointListType blackp,DEPointListType *deblackp)
{
	unsigned short int i;
	LineType PointVector;
	DEPointType depoint;
	Figure_StructInit_LineType(&PointVector);
	for(i = 0;i!=blackp.counter;i++)
	{
		PointVector.end = blackp.pint[i];
		depoint.r = Figure_Leng(&PointVector);
		depoint.theta = atan(blackp.pint[i].y/blackp.pint[i].x);
		deblackp->pint[deblackp->counter++] = depoint;
	}
}
void Figure_DescartesToRectangular(DELineType *DEline,RTLineType *line)
{
	line->k = (-1)/atan(DEline->theta);
	line->d = DEline->r/sin(DEline->theta);
}
//void Figure_HoughTransform(PointListType *output)//未完成
//{     
//	unsigned short int i;
//	DELineType templine;
//	DELineType line_add[HoughAccuracy];
//	unsigned short int counter = 0;
//	for(i = 0;i!=EdgePoint.counter;i++)
//	{
//		for(templine.theta = atan(EdgePoint.pint[i].y/EdgePoint.pint[i].y)+1.5*pi;templine.theta!=atan(EdgePoint.pint[i].y/EdgePoint.pint[i].y)+pi/2;templine.theta+=HoughAccuracy)
//		{
//			if(templine.theta==2*pi)
//				templine.theta = 0;
//			templine.r = EdgePoint.pint[i].y*sin(templine.theta) +  EdgePoint.pint[i].x*cos(templine.theta);
//			line_add[]
//			theta_add[Figure_Roundf (templine.theta)/HoughAccuracyR]++;
//			r_add[templine.r/10]++；
//		}
//	}
//	for(i=0;i!=360/HoughAccuracyA;i++)
//	{
//		if(theta_add[i]>threshold)
//		{
//			outputLine->line[counter].theta = i*HoughAccuracyR;	
//			counter++;
//		}
//	}
//	for(i=0;i!=50;i++)
//	{
//		if(r_add[i]>threshold)
//			outputLine->line[counter].r = i*HoughAccuracyR;	
//	}
//}

void Figure_FindCircles(PointListType *output)
{
	unsigned short int x,y,i,counter = 0;
	unsigned short int theta[PictreHeight*PictreWidth],mag[PictreHeight*PictreWidth];
	unsigned short int acc[PictreWidth][PictreHeight],valil_x,valil_y;
	unsigned short int r;
	PointType edge[PictreHeight*PictreWidth];
	for(y = 1;y!=PictreHeight-1;y++)
	{
		for(x = 1;x!=PictreWidth-1;x++)		
		{
			theta[counter] = Figure_Sobel(x,y,&mag[counter]);
			edge[counter].x = x;
			edge[counter].y = y;
			if(mag[counter])
				counter++;
		}
	}
	for(r = 2;r!=PictreHeight/2;r++)
	{
		for(i=0;i!=counter;i++)
		{
			valil_x = Figure_Roundf(edge[i].x+r*cos(theta[i]));
			valil_y = Figure_Roundf(edge[i].y+r*sin(theta[i]));
			acc[valil_y][valil_x]++;
		}
	}
	counter = 0;
	for(y = 1;y!=PictreHeight-1;y++)
	{
		for(x = 1;x!=PictreWidth-1;x++)	
		{
			if(	acc[y][x]>acc[y][x-1]&&
				acc[y][x]>acc[y][x+1]&&
				acc[y][x]>acc[y+1][x+1]&&
				acc[y][x]>acc[y+1][x-1]&&
				acc[y][x]>acc[y+1][x]&&
				acc[y][x]>acc[y-1][x+1]&&
				acc[y][x]>acc[y-1][x-1]&&
				acc[y][x]>acc[y-1][x])
			{
				output->pint[counter].x = x;
				output->pint[counter].y = y;
				counter++;				
			}
		}
	}
	output->counter = counter;
}
void Figure_FindSingleCircle(PointType *output)
{
	unsigned short int x,y,counter = 0;
	unsigned int add_x=0,add_y=0; 
	for(y=0;y!=PictreHeight;y++)
	{
		for(x=0;x!=PictreWidth;x++)
		{
			if(	image[y-1][x-1]&
				image[y-1][x]&
				image[y-1][x+1]&
				image[y][x-1]&
				image[y][x]&
				image[y][x+1]&
				image[y+1][x-1]&
				image[y+1][x]&
				image[y+1][x+1]
				)
			{
				add_x+=x;
				add_y+=y;
				counter++;
				tempimage[y][x] = 1;
			}
			else
				tempimage[y][x] = 0;
		}
	}
	output->x=add_x/counter;
	output->y=add_y/counter;
}
unsigned short int Figure_TowPoint(LineType *EdgeLeft,LineType *EdgeRight)
{
	
	unsigned short int empty = 0;
	unsigned char lineflag1 = 0,lineflag2 = 0,oneceflag1 = 1,oneceflag2 = 1;
	LineType templine1,templine2;
	LineType Max1,Max2;
	PointType search1,search2;

	for(search1.y=5;(search1.y!=PictreHeight)&&(oneceflag1||oneceflag2);search1.y++)//行扫描
	{
		Figure_StructInit_LineType(&Max1);
		Figure_StructInit_LineType(&Max2);
		search2.y = PictreHeight - (search1.y);
	for(search1.x = 0;search1.x!=PictreWidth;search1.x++)//列扫描
		{
			if(oneceflag1)
			{
				if(image[search1.y][search1.x] == 1)	//黑
				{
					if(lineflag1==0)
					{
						lineflag1 = 1;
						templine1.start = search1;
					}
					
				}
				else						//白
				{
					if(lineflag1==1)
					{
						templine1.end = search1;
						if(Figure_Leng(&templine1)>Max1.leng)
						{
							Max1 = templine1;
						}
						lineflag1 = 0;
					}
				}
			}
			search2.x = search1.x;
			
		
			if(oneceflag2)
			{
				if(image[search2.y][search1.x] == 1)
				{
					if(lineflag2 == 0)
					{
						lineflag2 = 1;
						templine2.start = search2;
					}
				}
				else						//白
				{
					if(lineflag2==1)
					{
						templine2.end = search2;
						if(Figure_Leng(&templine2)>Max2.leng)
						{
							Max2 = templine2;
						}
						lineflag2 = 0;
					}
				}
			}
		}
		if(lineflag1)
		{
			Max1.leng = PictreWidth;
			lineflag1 = 0;
		}
		if(lineflag2)
		{
			Max2.leng = PictreWidth;
			lineflag2 = 0;
		}		
		if(Max1.leng<30&&Max1.leng>10)//下
		{
			EdgeLeft->start = Max1.start;
			EdgeRight->start = Max1.end;
			oneceflag1 = 0;
		}

		if(Max2.leng<15&&Max2.leng>5)//上
		{
			EdgeLeft->end = Max2.start;
			EdgeRight->end = Max2.end;
			oneceflag2 = 0;
		}
		else
			empty++;
		
	}
	return empty;
}
//void Figure_LeastSquares(unsigned short int middle,float *k,unsigned short int *Distence)
//{
//	unsigned short int x,y;
//	PointType start,end,detect;
//	LineType blackline,blackline_last;
//	unsigned char blackdet = 0,once = 1;
//	unsigned short int item_1 = 0;//y*x
//	unsigned short int item_2 = 0;//y
//	unsigned short int item_3 = 0;//x
//	unsigned short int item_4 = 0;//x^2
//	unsigned short int counter,bottom_x = 0;
//	for(detect.y=0;detect.y!=PictreHeight;detect.y++)//行扫描
//	{
//		for(detect.x = 0;detect.x!=PictreWidth;detect.x++)//列扫描
//		{
//				if(image[detect.y][detect.x] == 1)	//黑
//				{
//					blackdet = 1;
//					blackline.start = detect;
//				}
//				else						//白
//				{
//					if(blackdet==1)
//					{
//						blackline.end = detect;
//						Figure_XLeng(&blackline);
//						Figure_Middle(&blackline);
//						if(once)
//						{
//							bottom_x = blackline.Middle.x;
//							once = 0;
//						}
//						item_1 += blackline.Middle.x * blackline.Middle.y;
//						item_2 += blackline.Middle.y;
//						item_3 += blackline.Middle.x;
//						item_4 += blackline.Middle.x * blackline.Middle.x;
//						blackdet = 0;
//						counter ++;
//					}
//				}
//		}//行结束
//		if(fabs(blackline.Middle.x - blackline_last.Middle.x) > 3)
//			break;	
//	}//帧结束
//	*k = (item_1 - item_2*item_3/counter)/(item_4 - item_3*item_3/counter);
//	*Distence =( bottom_x-middle)- dest / *k;
//}
void Figure_LeastSquares(unsigned char blackline[PictreHeight][3],float *k,float *Distence)
{
	float item_xy = 0.0f;//y*x
	float item_y = 0.0f;//y
	float item_x = 0.0f;//x
	float item_x2 = 0.0f;//x^2
	int counter;
	for(counter = 0;counter!=PictreHeight;counter++)
	{	
		item_xy += blackline[counter+1][2] * (counter+1);
		item_y += (counter+1);
		item_x += blackline[counter][2];
		item_x2 += blackline[counter][2] * blackline[counter][2];
	}

	*k = (item_xy - item_y*item_x/counter)/(item_x2 - item_x*item_x/counter); 
	*Distence =	(item_x2*item_y - item_x*item_xy)/(counter*item_x2-item_x*item_x);
}

void Figure_Corrosion(unsigned short int effects)//未验证
{
	unsigned char chang[PictreHeight][PictreWidth];
	unsigned short int x,y;
	for(x = 0;x!=PictreWidth;x++)
	{
		for(y = 0;y!=PictreHeight;y++)
		{
			
			if(x == 0||x==(PictreWidth-1)||y == 0||y==(PictreHeight-1))
			{
				chang[x][y] = 0;
			}
			else
			{
				chang[x][y] = image[x-1][y-1]+image[x][y-1]+image[x+1][y-1]+image[x-1][y]+image[x][y]+image[x+1][y]+image[x-1][y+1]+image[x][y+1]+image[x+1][y+1];
				if(chang[x][y] < effects)
					chang[x][y] = 0;
				else
					if(chang[x][y] != 9)
						chang[x][y] -= effects; 
			}
		} 
	}
	for(x = 1;x!=PictreWidth-1;x++)
		for(y = 1;y!=PictreHeight-1;y++)
		{
			image[x][y] = chang[x-1][y-1]+chang[x][y-1]+chang[x+1][y-1]+chang[x-1][y]+chang[x][y]+chang[x+1][y]+chang[x-1][y+1]+chang[x][y+1]+chang[x+1][y+1];
			image[x][y]/=9;
			if(image[x][y]>1)
				image[x][y] = 1;
		}
}
