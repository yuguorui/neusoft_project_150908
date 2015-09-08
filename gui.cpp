#include <stdio.h>
#include "header.h"
#include <windows.h>

void printTips()
{
	putchar('\n');
	printf("��ѡ����������:\n");
	printf("\t1.��ȡ�ļ�(\"data/GTBL.dat\")\n");
	printf("\t2.����������(\"data/SortGTBL.dat\")\n");
	printf("\t3.��������\n");
	printf("\t4.��������\n");
	printf("\t0.�˳�\n");
}

void readFile(Road** roads)
{
	//����ļ��Ƿ����
	FILE *fp = fopen("data/GTBL.dat", "rb");
	char addr[100] = "data/GTBL.dat";
	while (fp == NULL)
	{
		printf("ѡ���λ�ò����������ļ����Ƿ��ֶ�����λ��?1�����ǣ�2�����\n");
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
				printf("�޷��򿪱�����ļ�����������رա�\n");
				Sleep(2500);
				return;
			}

			default:
				break;
		}
	}
	printf("���ڴ��ļ�����\n");
	*roads = openFile(addr);
	printf("���ļ��ɹ�!\n");
	fclose(fp);
}

void sortRecords(Road* roads)
{
	if (roads == NULL)
	{
		readFile(&roads);
	}

	printf("\t��ѡ�����򷽷�:\n");
	printf("\t  1.��������\n\t  2.ð������\n\t  3.����\n");

	int choose;
	scanf("%d", &choose);

	switch (choose)
	{
		case 1:
		{
			long t = quickSort(roads);
			printf("��ʱ%ldms��\n", t);
			writeFile(roads, "data/SortGTBL.dat");
			break;
		}

		case 2:
		{
			long t = bubbleSoft(roads);
			printf("��ʱ%ldms��\n", t);
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
	printf("/***                ���ӵ�ͼ��Ϣͳ��ϵͳ             ***\\\n");
	printf("/***                ��12��    2015��9��              ***\\\n");
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
				//TODO ��������
				break;
			}

			case 4:
			{
				//TODO ��������
				break;
			}

			case 0:
			{
				printf("лл����ʹ�ã�\n");
				return;
			}


			default:
			{
				printf("�޷�ʶ��Ĳ��������򼴽��˳���\n");
				Sleep(2500);
				return;
			}
		}
	}

}