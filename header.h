#pragma once
#include <stdio.h>
#include <stdbool.h>

typedef struct Road
{
	unsigned short lenth;
	unsigned long long roadNO;
	unsigned short sizeOfName;
	unsigned otherinfo;
	bool flag;
	unsigned brunch;
	unsigned dispclass;
	char roadName[20];
	char data[100];
}Road;

Road* openFile(const char*); //�ļ���ȡ
bool writeFile(Road *, char*); //�ļ�д��

void gui();

long quickSort(Road *); //��������
long bubbleSoft(Road *); //ð������