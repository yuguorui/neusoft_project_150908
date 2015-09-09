#include "header.h"
#include <string.h>
#include <stdlib.h>

Road* search(Road* roads, SearchType type, void* condition)
{
	char *roadName;
	unsigned long long id;

	quickSort(roads); //在搜索的基础上进行检索

	Road* ans = (Road*)malloc(sizeof(Road) * MAX_ANS);
	memset(ans, 0, sizeof(Road) * MAX_ANS);

	if(type == Roadname)
	{
		roadName = (char*)condition;
	}
	else 
	{
		id = *(unsigned long long*)condition;
	}

	int index = 0;
	switch (type)
	{
	case Linkid:
		{
			int i = 0;
			while(roads[index].lenth != 0)
			{
				if(roads[index].roadNO == id)
				{
					ans[i++] = roads[index];
				}
				index++;
			}
			break;
		}

	case Dispclass:
		{
			int i = 0;
			while(roads[index].lenth != 0)
			{
				if(roads[index].dispclass == id)
				{
					ans[i++] = roads[index];
				}
				index++;
			}
			break;
		}
	case Brunch:
		{
			int i = 0;
			while(roads[index].lenth != 0)
			{
				if(roads[index].brunch == id)
				{
					ans[i++] = roads[index];
				}
				index++;
			}
			break;
		}
	case Roadname:
		{
			int i = 0;
			while(roads[index].lenth != 0)
			{
				if(strcmp(roads[index].roadName, roadName))
				{
					ans[i++] = roads[index];
				}
				index++;
			}
			break;
		}

	default:
		break;
	}

	return ans;
}