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

void displaySingle(Road *road)
{
	//记录大小，linkid，道路名称size，有无flag，岔路数，分类编号，道路名称
	printf("道路编号: %lld  ", road->roadNO);
	if(road->flag)
	{
		printf("道路名称: %s", road->roadName);
	}
	printf("  岔路数: %d  分类编号: %d\n", road->brunch, road->dispclass);
	return;
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
			printf("排序完成！耗时%ldms。\n", t);
			writeFile(roads, "data/SortGTBL.dat");
			break;
		}

		case 2:
		{
			long t = bubbleSoft(roads);
			printf("排序完成！耗时%ldms。\n", t);
			writeFile(roads, "data/SortGTBL.dat");
			break;
		}
		default:
			break;
	}

}

void searchRecords(Road* roads)
{
	if (roads == NULL)
	{
		readFile(&roads);
	}

	printf("\t请选择检索方式:\n");
	printf("\t  1.指定LinkID检索\n\t  2.指定分类番号检索\n\t  3.指定岔路数检索\n\t  4.指定道路名称检索\n\t  5.退出\n\n");
	
	int choose;
	scanf("%d", &choose);
	Road* ans;
	switch(choose)
	{
	case 1:
		{
			printf("\t  请输入道路编号：\n");
			unsigned long long id;
			scanf("%lld",&id);
			ans = search(roads, Linkid, &id);
			break;
		}
	
	case 2:
		{
			printf("\t  请输入分类番号：\n");
			unsigned long long id;
			scanf("%lld",&id);
			ans = search(roads, Dispclass, &id);
			break;
		}

	case 3:
		{
			printf("\t  请输入岔路数：\n");
			unsigned long long id;
			scanf("%lld",&id);
			ans = search(roads, Brunch, &id);
			break;
		}

	case 4:
		{
			printf("\t  请输入道路名称：\n");
			char name[30];
			scanf("%s",&name);
			ans = search(roads, Roadname, name);
			break;
		}

	default:
		break;
	}

	int i = 0;
	while(ans[i].lenth != 0)
	{
		displaySingle(&ans[i++]);
	}
	
	putchar('\n');
	return;
}


void gui()
{
	printf("/********************---Welcome---**********************\\\n");
	printf("/***                电子地图信息统计系统             ***\\\n");
	printf("/***                第12组    2015年9月              ***\\\n");
	printf("/*******************************************************\\\n");

	Road* roads = NULL;

	while (true)
	{
		printTips();

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
				searchRecords(roads);
				break;
			}

			case 4:
			{
				updateData(roads);
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