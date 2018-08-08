#ifndef __LINKLIST_H__
#define __LINKLIST_H__


typedef void LinkList;
typedef struct _tag_LinkListNode
{
	struct _tag_LinkListNode * next;
}LinkListNode;

typedef struct _tag_LinkList
{
	int length;
	LinkListNode header;
}TLinkList;

LinkList * LinkList_Create();
void LinkList_Destroy(LinkList * list);
void LinkList_Clear(LinkList * list);
int LinkList_GetLen(LinkList * list);
int LinkList_Insert(LinkList * list, LinkListNode * node, int pos);
LinkListNode* LinkList_Delete(LinkList * list, int pos);
LinkListNode* LinkList_Get(LinkList * list,int pos);

#endif
