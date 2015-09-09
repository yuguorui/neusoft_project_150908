#pragma once
#include <stdio.h>

#define MAX_ANS (1000)

typedef struct Road
{
	unsigned short lenth;
	unsigned long long roadNO;
	int sizeOfName;
	unsigned otherinfo;
	bool flag;
	unsigned brunch;
	unsigned dispclass;
	char roadName[20];
	char data[100];
}Road;

typedef enum SearchType
{
	Linkid,
	Dispclass,
	Brunch,
	Roadname
}SearchType;


Road* openFile(const char*); //文件读取
bool writeFile(Road*, char*); //文件写入

void gui();

long quickSort(Road*); //快速排序
long bubbleSoft(Road*); //冒泡排序

Road* search(Road*, SearchType, void*); //进行检索的函数，返回为结果的数组

void displaySingle(Road*); //显示单条路径记录

void updateData(Road*); //更新数据