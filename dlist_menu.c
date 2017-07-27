#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DLIST_RET_OK 1
#define DLIST_RET_ERROR 0

typedef int DListRet;
typedef struct Student
{
    int serial;
    float score;
    char* name;
    struct Student *pNext;
    struct Student *pPrev;
}ST;

ST *CreatNode(char name[], float iscore) 
{                                                                                                       
    ST *newNode;
    
    newNode = (ST*)malloc(sizeof(ST));//若一開始即宣告  ST *newNode; 但未初始化會有影響嗎? newNode會被malloc初始化，所以不會有影響? 
   	if(newNode == NULL)
    {
		 printf("malloc error in creat \r\n");
		 return;
    }
    else
      printf("create list \r\n");
      
    newNode->serial = 1;
    newNode->score = iscore;
    newNode->name = name;
    newNode->pNext = NULL;
    newNode->pPrev = NULL;      
    
    return newNode;
}

ST *InsertNode(ST *pHead, char cname[], float iscore)
{                                                    
    static int pos=1;                                                     
    ST *newNode;
    
    //ST *p = *pHead;
    while( pHead->pNext != NULL)
        pHead=pHead->pNext;
    
    newNode = (ST*)malloc(sizeof(ST));
    if(newNode == NULL)
    {
        printf("malloc error");
        return;
    }
    
    newNode->serial = (++pos);
    newNode->score = iscore;
    
    //newNode->name = cname;
    newNode->name=(char *) malloc(sizeof(char) * 20);
    strcpy(newNode->name ,cname);
     
    newNode->pNext = NULL;
    newNode->pPrev = pHead;
    pHead->pNext = newNode;	
    	 		
    return newNode;
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

void DListPrintNode(ST *pHead, int iserial)
{
    int i=0;   
    
    if(pHead == NULL)
        return;
    
    for( i=0; i < (iserial-1); i++)
    { 
       pHead = pHead->pNext; //Head往下一節點移動 
    }
    
    printf("Pos %02d, %10s , %4d \r\n", pHead->serial, pHead->name, (int)pHead->score);  
}

void DListPrint(ST *pHead)//傳入 頭節點 指標 
{
    printf("Number    Name     score \r\n");
    while(pHead != NULL) // Why use "*pHead != NULL" error ?
    {
        //printf("Serial number is %2d, %6X, %6X, %6X  \n", pHead->serial, pHead, pHead->pNext , pHead->pPrev);//print head position and next , prev position
        printf("Pos %02d, %10s , %4d \r\n", pHead->serial, pHead->name, (int)(pHead->score));
        pHead = pHead->pNext;
    }
}

void list_menu_printf()
{
	//printf menu
	/*
	1.Add one node // call CreateNode
	  keyin name, score
	2.Delete one node //call DeleteNode
    3.Print all node //DListPrint(pHead); 
    4.Print the assigned node
    5.Search node
      (1) condition 1 : score max
      (2) condition 2 : score min	  
	*/
	printf("List menu \r\n\
	1. Insert a node \r\n \
	2. Delete a node \r\n \
	3. Print all node \r\n \
	4. Print a node \r\n \
	5. Search the max/min score\r\n");
}

void list_menu_handle(ST *pHead, int id)
{
	/*
	//keyin hanle : menu 1~5
    1. meun 1 error hadle and correspond action
	2. meun 2 error hadle and correspond action	
	3. meun 3 error hadle and correspond action	
	4. meun 4 error hadle and correspond action	
	5. meun 5 error hadle and correspond action	
	*/
	
    int iscore=0.0;
    int ipos=0;
    char buf_name[10]={0};
    ST* pNode=NULL;
            	
	if (id >= 6)
		return;
	printf("\r\n");
	switch (id)
	{
		case 1:
		    printf("Insert a node\r\n");			
			printf("Please input 'student name' and 'score', seperate with space\r\n");
			scanf("%s %d", buf_name, &iscore);
			//printf("name:%s, score:%d\r\n", buf_name, iscore);			
			pNode=InsertNode(pHead, buf_name, iscore);
			//DListPrintNode(pHead, iSerial);//DListPrintNode(pHead, &buf_name, iSerial);		
		break;
		
		case 2:
		    printf("Delete a node from list\r\n");
		    DListPrint(pHead);
		    printf("Please input 'Pos'\r\n");
			scanf("%d", &ipos);
            DeleteNode(pHead, ipos); 
		break;
		
		case 3:
		    printf("Print all node\r\n");
		    DListPrint(pHead);
		break;
		
		case 4:
		    printf("Print a node\r\n");
		    printf("Please input 'Pos'\r\n");
			scanf("%d", &ipos);
		    DListPrintNode(pHead, ipos); 
		break;
		
		case 5:
		printf("handle-5\r\n");
		break;
	}
	printf("Please select the menu action ...\r\n");
}

int main()
{
    int ch=0;
    ST* pHead=NULL;	
    char buf_name[10]={"ListStart"};
    int iscore=98;
    
	//printf menu
	list_menu_printf();	
    
    //Create list    
    pHead=CreatNode(buf_name, iscore);
     
    //print : please keyin the number to use this list	
	printf("Please select the menu action ...\r\n");
	
    while(1)
    {
        scanf("%d",&ch);
        if(ch != 0 )
        {
            if((int)ch < 6)
                list_menu_handle(pHead, (int)ch);
            else
                printf("OutOfRange, Select again \r\n");
            ch=0;
        }
    }
	
    system("pause");
    return 0;
}
