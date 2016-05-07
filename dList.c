#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
    int serial;
    float score;
    struct Student *pNext;
    struct Student *pPrev;
}ST;

void CreatNode(ST **pHead, int iserial, float iscore)//Why use **pHead not *pHead ->�ǤJ�s���Y�`�I���Ъ���} 
{                                                    //CreatNode(&pHead, 1, 70.5); -> "&pHead" : �ǤJ"pHead" ���a�} ;
                                                     // 
    ST *newNode;
    if(*pHead == NULL)
    {//�P�_���O�_���� 
         //ST *newNode = (ST*)malloc(sizeof(ST));//Why need yo use (ST*)
        newNode = (ST*)malloc(sizeof(ST));//�Y�@�}�l�Y�ŧi  ST *newNode; ������l�Ʒ|���v�T��? newNode�|�Qmalloc��l�ơA�ҥH���|���v�T? 
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
    ST *p1 = pHead->pNext;//p1 ���VHead���U�@�`�I 
    ST *p2 = NULL;     
    
    if(pHead == NULL)
        return;
    
    for( i=1; i < (iserial-1); i++)
    { 
       pHead = pHead->pNext; //Head���U�@�`�I���� 
       p1 = pHead->pNext; //p1 ���VHead���U�@�`�I 
       p2 = pHead;//p1->pPrev; //p2�O�s �e�@��Head ����m 
               
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

void DListPrint(ST *pHead)//�ǤJ �Y�`�I ���� 
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
    ST *pHead = NULL;//����l��error��]? �O�]���쥻����m�i�঳��L��Ʀs�b��? 
    ST *pLast = NULL;
    printf("Hello, World!\n");
     CreatNode(&pHead, 1, 70.5);  
     CreatNode(&pHead, 2, 72.5);
     CreatNode(&pHead, 3, 75.5);
     CreatNode(&pHead, 4, 77.5);
     CreatNode(&pHead, 5, 79.5);
     //printf("pHead = %x, *pHead=%x, &pHead=%x!\n",pHead,*pHead,&pHead);
     DListPrint(pHead); //"&pHead" : �ǤJ"pHead" ���a�} ;  "pHead" : �ǤJ"pHead" �����e�A�Y"�Y�`�I������" 
     
     printf("\nDo node 3 delete !! \n\n");
     DeleteNode(pHead, 3);
     DListPrint(pHead);
     
     system("pause");
    return 0;
}
