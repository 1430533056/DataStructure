#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

LinkList * LinkList_Create()
{
	TLinkList * temp = NULL;
	temp=(TLinkList*)malloc(sizeof(TLinkList));
	if(temp == NULL)
	{
		printf("func LinkList_Create(): malloc err !\n");
		return NULL;
	}
	temp->length = 0;
	temp->header.next = NULL;
	return temp;
}
void LinkList_Destroy(LinkList * list)
{
	if(list != NULL)
	{
		free(list);
		list = NULL;
	}
	return;
}
void LinkList_Clear(LinkList * list)
{
	TLinkList * temp = NULL;
	if(list == NULL)
		return;
	temp=(TLinkList*)list;
	temp->length = 0;
	temp->header.next = NULL;
	return;
}
int LinkList_GetLen(LinkList * list)
{
	TLinkList * temp = NULL;
	if(list == NULL)
		return -1;
	temp=(TLinkList*)list;
	return temp->length;
}
int LinkList_Insert(LinkList * list, LinkListNode * node, int pos)
{
	TLinkList * temp = NULL;
	LinkListNode * current = NULL;
	if(list == NULL || node == NULL || pos < 0)
		return - 1;
	temp=(TLinkList*)list;
	current = &(temp->header);
	for(int i = 0; (i < pos) && (current->next!=NULL); i++)
		current = current->next;
	node->next = current->next;
	current->next = node;
	temp->length++;
	return 0;
}
LinkListNode * LinkList_Delete(LinkList * list, int pos)
{
	TLinkList * temp = NULL;
	LinkListNode * current = NULL;
	LinkListNode * ret = NULL;
	if(list == NULL || pos < 0)
		return NULL;
	temp=(TLinkList*)list;
	current = &(temp->header);
	for(int i = 0; (i < pos) && (current->next!=NULL); i++)
		current = current->next;
	ret = current->next;
	current->next = ret->next;
	temp->length--;
	return ret;
}
LinkListNode * LinkList_Get(LinkList * list,int pos)
{
	TLinkList * temp = NULL;
	LinkListNode * current = NULL;
	if(list == NULL || pos < 0)
		return NULL;
	temp=(TLinkList*)list;
	current = &(temp->header);
	for(int i = 0; (i < pos) && (current->next!=NULL); i++)
		current = current->next;
	return current->next;
}
