#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
    int serial;
    float score;
    struct Student *pNext;
    struct Student *pPrev;
}ST;

void CreatNode(ST **pHead, int iserial, float iscore)//Why use **pHead not *pHead ->傳入存放頭節點指標的位址 
{                                                    //CreatNode(&pHead, 1, 70.5); -> "&pHead" : 傳入"pHead" 的地址 ;
                                                     // 
    ST *newNode;
    if(*pHead == NULL)
    {//判斷鏈表是否為空 
         //ST *newNode = (ST*)malloc(sizeof(ST));//Why need yo use (ST*)
        newNode = (ST*)malloc(sizeof(ST));//若一開始即宣告  ST *newNode; 但未初始化會有影響嗎? newNode會被malloc初始化，所以不會有影響? 
       	if(newNode == NULL)
        {
			 printf("malloc error in creat");
			 return;
        }
        newNode->serial = iserial;
        newNode->score = iscore;
        newNode->pNext = NULL;
        newNode->pPrev = NULL;
        *pHead = newNode;
        
    }
    else
    {
        ST *p = *pHead;
        while( p->pNext != NULL)
            p=p->pNext;
        
        //ST *newNode = (ST*)malloc(sizeof(ST));
        newNode = (ST*)malloc(sizeof(ST));
        if(newNode == NULL)
        {
            printf("malloc error");
            return;
        }
        newNode->serial = iserial;
        newNode->score = iscore;
        newNode->pNext = NULL;
        newNode->pPrev = p;
        p->pNext = newNode;		 		
    }
}

void DeleteNode(ST *pHead, int iserial)
{
    int i=1;
    ST *p1 = pHead->pNext;//p1 指向Head的下一節點 
    ST *p2 = NULL;     
    
    if(pHead == NULL)
        return;
    
    for( i=1; i < (iserial-1); i++)
    { 
       pHead = pHead->pNext; //Head往下一節點移動 
       p1 = pHead->pNext; //p1 指向Head的下一節點 
       p2 = pHead;//p1->pPrev; //p2保存 前一個Head 的位置 
               
       //printf(" %d, %6X, %6X, %6X , %6X \n", iserial, pHead, pHead->pNext , p1, p2);
    }
    
    pHead->pNext = p1->pNext;
    pHead = pHead->pNext;
    //printf("pHead->prev=%6X\n",pHead->pPrev);
    free(pHead->pPrev);
    pHead->pPrev = NULL;
   // printf("pHead->prev=%6X\n",pHead->pPrev);
    pHead->pPrev = p2; 
    
     
}

void DListPrint(ST *pHead)//傳入 頭節點 指標 
{
    while(pHead != NULL) // Why use "*pHead != NULL" error ?
    {
        printf("Serial number is %2d, %6X, %6X, %6X  \n", pHead->serial, pHead, pHead->pNext , pHead->pPrev);//print head position and next , prev position
        //printf("Serial number is %2d, and the score is %3f\n", pHead->serial, pHead->score);
        pHead = pHead->pNext;
    }
}

int main()
{
    ST *pHead = NULL;//未初始化error原因? 是因為原本的位置可能有其他資料存在嗎? 
    ST *pLast = NULL;
    printf("Hello, World!\n");
     CreatNode(&pHead, 1, 70.5);  
     CreatNode(&pHead, 2, 72.5);
     CreatNode(&pHead, 3, 75.5);
     CreatNode(&pHead, 4, 77.5);
     CreatNode(&pHead, 5, 79.5);
     //printf("pHead = %x, *pHead=%x, &pHead=%x!\n",pHead,*pHead,&pHead);
     DListPrint(pHead); //"&pHead" : 傳入"pHead" 的地址 ;  "pHead" : 傳入"pHead" 的內容，即"頭節點的指標" 
     
     printf("\nDo node 3 delete !! \n\n");
     DeleteNode(pHead, 3);
     DListPrint(pHead);
     
     system("pause");
    return 0;
}
