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

Road* openFile(const char*); //文件读取
bool writeFile(Road *, char*); //文件写入

void gui();

long quickSort(Road *); //快速排序
long bubbleSoft(Road *); //冒泡排序