#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
    int serial;
    float score;
    struct Student *pNext;
}ST;

void CreatNode(ST **pHead, int iserial, float iscore)//Why use **pHead not *pHead(傳入頭節點""地址"")
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
        p->pNext = newNode;
		 		
    }
}

void ListPrint(ST *pHead)//傳遞頭節點 
{
 		 while(pHead != NULL) // Why use "*pHead != NULL" error ?
 		 {    //position 形成"鏈式結構" 
          printf("iserial = %2d, iscore = %.2f, now position = %X, next position = %X \n", pHead->serial, pHead->score, pHead, pHead->pNext);
          pHead = pHead->pNext;
     }
}

int main()
{
    ST* pHead = NULL;
    printf("Hello, World!\n");
     CreatNode(&pHead, 1, 70.5);
     CreatNode(&pHead, 2, 72.5);
     CreatNode(&pHead, 3, 75.5);
     
     ListPrint(pHead);//Why use pHead not &pHead
     
    return 0;
}
