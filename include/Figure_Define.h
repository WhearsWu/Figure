#ifndef _FIGURE_DEFINE_H
#define _FIGURE_DEFINE_H
#define pi 3.1415
#define PictreHeight   120//20
#define PictreWidth    160//15
#define RtA(theta)		theta/2*pi*316
#define AtR(angle)		angle/360*2pi
#define HoughAccuracyA  5
#define HoughAccuracyR  AtR(HoughAccuracyA)

typedef struct
{
	unsigned short int x;
	unsigned short int y;
}PointType;//ֱ������ϵ������
typedef struct
{
	PointType pint[PictreHeight];
	unsigned short int counter;
}PointListType;//ֱ������ϵ���б�
typedef struct
{
	PointType start;
	PointType end;
	PointType Middle;
	unsigned short int leng;
}LineType;//ֱ������ϵֱ��
typedef struct
{
	float k;
	float d;
}RTLineType;
typedef struct
{
	LineType line[10];
	unsigned short int counter;
}LineListType;//ֱ������ϵֱ���б�


typedef struct
{
	float theta;
	unsigned short int r;
}DEPointType;//�ѿ�������ϵ������
typedef struct
{
	DEPointType pint[100];
	unsigned short int counter;
}DEPointListType;//�ѿ�������ϵ���б�
typedef struct
{
	float theta;
	unsigned short int r;
}DELineType;//�ѿ�������ϵֱ������
typedef struct
{
	DELineType line[10];
	unsigned short int counter;
}DELineListType;//�ѿ�������ϵֱ���б�

typedef struct
{
	unsigned short int height;
	unsigned short int width;
	char pictre[20][15];
	//char pictre[320][240];
}PictreType;

extern char image[PictreHeight][PictreWidth];
extern char tempimage[PictreHeight][PictreWidth];
extern char imag_Minesweep[PictreHeight][PictreWidth];

void Figure_StructInit_LineType(LineType *line);//��սṹ��
void Figure_StructInit_PictreType(PictreType *Pictre);//��սṹ��
void Figure_StructInit_PointListType(PointListType *PointList);//��սṹ��
#endif
