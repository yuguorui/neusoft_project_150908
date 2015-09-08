#include <stdio.h>
#include "header.h"
#include <windows.h>

void printTips()
{
	putchar('\n');
	printf("请选择服务的种类:\n");
	printf("\t1.读取文件(\"data/GTBL.dat\")\n");
	printf("\t2.排序并输出结果(\"data/SortGTBL.dat\")\n");
	printf("\t3.检索数据\n");
	printf("\t4.更新数据\n");
	printf("\t0.退出\n");
}

void readFile(Road** roads)
{
	//检查文件是否存在
	FILE *fp = fopen("data/GTBL.dat", "rb");
	char addr[100] = "data/GTBL.dat";
	while (fp == NULL)
	{
		printf("选择的位置不存在数据文件，是否手动输入位置?1代表是，2代表否。\n");
		int choose_2;
		scanf("%d", &choose_2);
		switch (choose_2)
		{
			case 1:
			{
				scanf("%s", addr);
				break;
			}
			case 2:
			{
				printf("无法打开必须的文件，软件即将关闭。\n");
				Sleep(2500);
				return;
			}

			default:
				break;
		}
	}
	printf("正在打开文件……\n");
	*roads = openFile(addr);
	printf("打开文件成功!\n");
	fclose(fp);
}

void sortRecords(Road* roads)
{
	if (roads == NULL)
	{
		readFile(&roads);
	}

	printf("\t请选择排序方法:\n");
	printf("\t  1.快速排序\n\t  2.冒泡排序\n\t  3.返回\n");

	int choose;
	scanf("%d", &choose);

	switch (choose)
	{
		case 1:
		{
			long t = quickSort(roads);
			printf("耗时%ldms。\n", t);
			writeFile(roads, "data/SortGTBL.dat");
			break;
		}

		case 2:
		{
			long t = bubbleSoft(roads);
			printf("耗时%ldms。\n", t);
			writeFile(roads, "data/SortGTBL.dat");
			break;
		}
		default:
			break;
	}

}

void gui()
{
	printf("/********************---Welcome---**********************\\\n");
	printf("/***                电子地图信息统计系统             ***\\\n");
	printf("/***                第12组    2015年9月              ***\\\n");
	printf("/*******************************************************\\\n");

	while (true)
	{
		printTips();
		Road* roads = NULL;

		int choose;
		scanf("%d", &choose);
		switch (choose)
		{
			case 1:
			{
				readFile(&roads);
				break;
			}

			case 2:
			{
				sortRecords(roads);
				break;
			}

			case 3:
			{
				//TODO 检索数据
				break;
			}

			case 4:
			{
				//TODO 更新数据
				break;
			}

			case 0:
			{
				printf("谢谢您的使用！\n");
				return;
			}


			default:
			{
				printf("无法识别的操作，程序即将退出。\n");
				Sleep(2500);
				return;
			}
		}
	}

}