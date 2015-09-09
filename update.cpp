#include "header.h"

void updateData(Road* roads)
{
	if(roads == NULL)
	{
		printf("你尚未读入文件！\n");
		return;
	}

	printf("你的选择将更改硬盘文件！是否确定？1为是，2为否。\n");

	int choose;
	scanf("%d", &choose);
	switch(choose)
	{
	case 1:
		{
			writeFile(roads, "data/GTBL.dat");
			printf("文件写入成功！\n");
			break;
		}
	case 2:
		{
			printf("正在取消操作……\n");
			printf("操作已取消。\n");
			break;
		}

	default:
		break;
	}

	return;
}