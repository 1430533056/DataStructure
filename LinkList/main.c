#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

typedef struct Teacher
{
	LinkListNode header;
	char name[32];
	int age;
}Teacher;

int main()
{
	TLinkList * tlist = NULL;
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 13;
	tlist=(TLinkList*)LinkList_Create();
	LinkList_Insert(tlist,(LinkListNode*)&t1, 0);
	LinkList_Insert(tlist,(LinkListNode*)&t2, 0);
	LinkList_Insert(tlist,(LinkListNode*)&t3, 0);
	for(int i = 0; i < LinkList_GetLen(tlist); i++)
	{
		Teacher * p = (Teacher*)LinkList_Get(tlist, i);
		printf("%d ", p->age);
	}
	LinkList_Delete(tlist, 1);
	for(int i = 0; i < LinkList_GetLen(tlist); i++)
	{
		Teacher * p = (Teacher*)LinkList_Get(tlist, i);
		printf("%d ", p->age);
	}
	LinkList_Destroy(tlist);
	return 0;
}
