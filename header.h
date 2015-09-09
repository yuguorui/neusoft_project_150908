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


Road* openFile(const char*); //�ļ���ȡ
bool writeFile(Road*, char*); //�ļ�д��

void gui();

long quickSort(Road*); //��������
long bubbleSoft(Road*); //ð������

Road* search(Road*, SearchType, void*); //���м����ĺ���������Ϊ���������

void displaySingle(Road*); //��ʾ����·����¼

void updateData(Road*); //��������