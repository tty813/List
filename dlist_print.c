#include <stdio.h>
#include <stdlib.h>

#define DLIST_RET_OK 1
#define DLIST_RET_ERROR 0

typedef int DListRet;
typedef struct Student
{
    int serial;
    float score;
    struct Student *pNext;
    void* data;
}ST;

typedef DListRet (*DListDataPrintFunc)(void* data);
DListRet dlist_print(ST* thiz, DListDataPrintFunc print);

DListRet dlist_print(ST* pHead, DListDataPrintFunc print)
{
    DListRet ret = DLIST_RET_OK;
    ST* iter = pHead;//thiz->pNext;
    
		while(iter != NULL)
    {
        print(iter->data);
        iter = iter->pNext;
    }
    return ret;
}

static DListRet print_int(void* data)
{
    printf("%d \n", (int*)data);
    return DLIST_RET_OK;
}

static DListRet print_char(void* data)
{
    printf("%c \n", (char*)data);
    return DLIST_RET_OK;
}

void CreatNode(ST **pHead, int iserial, float iscore, void* Data)//Why use **pHead not *pHead(傳入頭節點""地址"")
{
    //ST *newNode;
    
    if(*pHead == NULL)
    {//判斷鏈表是否為空 
        ST *newNode = (ST*)malloc(sizeof(ST));//Why need to use (ST*)
       	if(newNode == NULL)
        {
			      printf("malloc error in creat");
			      return;
        }
        newNode->serial = iserial;
        newNode->score = iscore;
        newNode->pNext = NULL;
        newNode->data = Data;
        *pHead = newNode;
    }
    else
    {
		 		ST *p = *pHead;
		 		while( p->pNext != NULL)
		 		        p=p->pNext;
				
				ST *newNode = (ST*)malloc(sizeof(ST));//Why need yo use (ST*)
				if(newNode == NULL)
        {
			      printf("malloc error");
			      return;
        }
        newNode->serial = iserial;
        newNode->score = iscore;
        newNode->pNext = NULL;
        newNode->data = Data;
        p->pNext = newNode;
		 		
    }
}

void ListPrint(ST *pHead)//傳遞頭節點 
{
 		 while(pHead != NULL) // Why use "*pHead != NULL" error ?
 		 {    //position 形成"鏈式結構" 
          printf("inum = %2d, iscore = %2.2f, now position = 0x%6X, next position = 0x%6X \n", pHead->serial, pHead->score, pHead, pHead->pNext);
          pHead = pHead->pNext;
     }
}

int main()
{
    ST* pHead = NULL;
    printf("Hello, World!\n");
    CreatNode(&pHead, 1, 70.5,(int*)65);		 
    CreatNode(&pHead, 2, 72.5,(char*)'A');
    CreatNode(&pHead, 3, 75.5,(char*)'B');
     
    //printf("serial=%d, score=%f \n", pHead->serial, pHead->score);
     
    ListPrint(pHead);//Why use pHead not &pHead
    
    dlist_print(pHead, print_int);
    dlist_print(pHead, print_char);
    system("pause");
    return 0;
}
