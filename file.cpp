#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "header.h"

void readSingle(FILE *, Road *); //读取单条记录
void writeSingle(FILE *, Road *); //写入单条记录

void readSingle(FILE *fp, Road *road)
{
	char buf[30];

	memset(buf, 0, sizeof(buf));
	fread(buf, 1, 2, fp);
	memcpy(road->data, buf, 2);
	road->lenth = buf[1] + buf[0] * (1 << 8);

	if (road->lenth == 0)
		return;

	memset(buf, 0, sizeof(buf));
	fread(buf, 1, 4, fp);
	memcpy(&(road->data[2]), buf, 4);
	road->roadNO = buf[3] + buf[2] * (1 << 8) + buf[1] * (1 << 16) + buf[0] * (1 << 24);

	memset(buf, 0, sizeof(buf));
	fread(buf, 1, 2, fp);
	memcpy(&(road->data[6]), buf, 2);
	road->sizeOfName = buf[1] + buf[0] * (1 << 8);

	memset(buf, 0, sizeof(buf));
	fread(buf, 1, 4, fp);
	memcpy(&(road->data[8]), buf, 4);
	road->flag = (buf[3] & 128) ? true : false;
	road->brunch = (buf[3] & 112) >> 4;
	road->dispclass = (buf[3] & 15);
	road->otherinfo = buf[3] + buf[2] * (1 << 8) + buf[1] * (1 << 16) + buf[0] * (1 << 24);

	memset(buf, 0, sizeof(buf));
	fread(buf, 1, road->lenth - 12,fp);
	memcpy(&(road->data[12]), buf, road->lenth - 12);
	memcpy(road->roadName, buf, road->lenth - 12);
}

Road* openFile(const char* sou)
{
	FILE* fp = fopen(sou, "rb");
	Road* roads = (Road*)malloc(sizeof(Road) * 100000);
	memset(roads, 0, sizeof(Road) * 100000);
	long long i = 0;
	while (!feof(fp))
	{
		readSingle(fp, &roads[i++]);
	}
	fclose(fp);
	return roads;
}

bool writeFile(Road *roads, char * des)
{
	int i = 0;
	FILE *fp = fopen(des, "wb");
	if (fp == nullptr)
		return false;
	while (roads[i].lenth != 0)
	{
		writeSingle(fp, &roads[i++]);
	}
	fclose(fp);
	return true;
}

void writeSingle(FILE *fp, Road *road)
{
	fwrite(road->data, 1, road->lenth, fp);
}