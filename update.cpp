#include "header.h"

void updateData(Road* roads)
{
	if(roads == NULL)
	{
		printf("����δ�����ļ���\n");
		return;
	}

	printf("���ѡ�񽫸���Ӳ���ļ����Ƿ�ȷ����1Ϊ�ǣ�2Ϊ��\n");

	int choose;
	scanf("%d", &choose);
	switch(choose)
	{
	case 1:
		{
			writeFile(roads, "data/GTBL.dat");
			printf("�ļ�д��ɹ���\n");
			break;
		}
	case 2:
		{
			printf("����ȡ����������\n");
			printf("������ȡ����\n");
			break;
		}

	default:
		break;
	}

	return;
}