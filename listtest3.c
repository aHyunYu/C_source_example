#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
typedef struct ListNode{ 
	char data[100]; 
	struct ListNode* link; 
}listNode; 

typedef struct{
	listNode* head; 
}linkedList_h; 

linkedList_h* createLinkedList_h(void);  

void add(linkedList_h*, char*);
void printList(linkedList_h*);
void clear(linkedList_h*);
void removeNode(linkedList_h* List, int delnum);
void removeNode2(linkedList_h* List, char *string);
void insertMNode(linkedList_h* List, int num, char *string);
void get(linkedList_h* List, int index);
int contains(linkedList_h* List, char *string);
int indexOf(linkedList_h* List, char *string);
int size(linkedList_h* List);
int isEmpty(linkedList_h* List);
void replace(linkedList_h* List, int index, char *string);

int main() 
{ 
	char insertString[100];
	int caseNum, index, delnum;

	linkedList_h* List;
	List = createLinkedList_h();
	do{
		printf("\n----------Linkedlist Menu----------\n");
		printf("\n");
		printf("1. addNode \n2. insertMNode \n3. removeNode \n4. allClear \n5. get \n6. contains \n7. indexOf \n8. size \n9. replace \n0. exit\n");
		printf("\nChoose the number which you want : ");
		scanf("%d", &caseNum);
	switch(caseNum){
	case 1:
		printf("Insert string in the list : ");
 		scanf("%s", insertString);
    		add(List, insertString);
		printList(List);
		break;
	case 2:
		printf("What is number of index that you insert string? ");
 		scanf("%d",&index);
     		printf("\n");
     		printf("String of inserted index : ");
     		scanf("%s",insertString);
     		insertMNode(List, index, insertString);
		printList(List);
		break;
	case 3:
		printf("\n What number of index that you will delete : ");
		scanf("%d", &delnum);
    		removeNode(List, delnum);
    		printList(List);
		break;
	case 4:
		printf("Delete All\n");
		clear(List);
		printList(List);
		break;
	case 5:
		printf("What is index that you want to see : ");
    		scanf("%d", &index);
    		get(List, index);
		printf("\n");
    		printList(List);
		break;
	case 6:
		printf("If you are curious about what you want, Write string : ");
		scanf("%s", insertString);
		contains(List, insertString);
		break;
	case 7:
		printf("What is word what you want to know?? \n");
		scanf("%s", insertString);
		indexOf(List, insertString);
		break;
	case 8:
		printf("\n");
		printf("Size of List : ");
		size(List);
		break;
	case 9:
		printf("what is the word to be entered? : \n");
		scanf("%s", insertString);
		printf("What is number of index what be replaced? \n");
		scanf("%d", &index);
		replace(List, index, insertString);
		printList(List);
		break;
	case 0:
		printf("EXIT\n");
		break;
	default:
		printf("Wrong number. Please write again : ");
		break;	
	}
	}while(caseNum!=0);
return 0;
}

//Init the linkedlist
linkedList_h* createLinkedList_h(void) 
{ 
	linkedList_h* List; 
	List = (linkedList_h*)malloc(sizeof(linkedList_h)); 
	List -> head = NULL; 
	return List; 
} 
//Insert the specified element in order
void add(linkedList_h* List, char* string) 
{ 
	listNode* newNode; 
	listNode* point; 
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, string);
	newNode->link= NULL; 
	if (List->head == NULL){ 
		List->head = newNode; 
		return; 
   	} 
   	point = List->head; 
   	while (point->link != NULL){ 
	      	point = point->link; 
   	} 
   	point->link = newNode; 
}
//Removes the element at the specified position in this list
void removeNode(linkedList_h* List, int delnum)
{

	int count=0;
        listNode* findNode2 = List->head;
        while(findNode2 != NULL ){
                findNode2=findNode2->link;
                count++;
        }
        if(delnum > count || delnum <= 0){
                printf("The (%d)index does not exist. \n", delnum);
        }else{
		if(delnum == 1){
			free(List->head);
			List->head = List->head->link;
          		return;
        	}else{
        		listNode* findNode = List->head;
        		listNode* current;
        		int count = 1;
			for (count = 0 ; count <delnum-2 ; count++){
        			findNode = findNode -> link;
        		}
        		current = findNode->link;
        		findNode->link=findNode->link->link;
        		free(current);
		}
	}
}
 
//Returns the index of the specified element
int indexOf(linkedList_h* List, char *string){

	int count1=1;
   
	listNode* findNode = List->head;
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, string);

	while(strcmp(findNode->data ,newNode->data) != 0 ){
      		count1++;
      		findNode=findNode->link;
	}
	printf("The index number of the inserted string is (%d) \n", count1);
	return 0;
}

//Delete node that received string value
void removeNode2(linkedList_h* List, char *string){
	
	listNode* del;
	listNode* findNode;
	for(findNode=List->head; findNode->link!=NULL; findNode=findNode->link){
		if(strcmp(findNode->data, string) == 0){
			del = findNode->link;
			findNode->link=findNode->link->link;
			free(del);
			break;
		}
	}
}

//Size of linkedlist
int size(linkedList_h* List){
	int count=0;
	listNode* findNode = List->head;
	while(findNode != NULL ){
		findNode=findNode->link;
		count++;
	}
	printf("size = %d\n", count);
	return count;
}

//Check whether or not empty
int isEmpty(linkedList_h* List){
	int empty=0;
	listNode* findNode = List->head;
	if(findNode = NULL){
		empty = 0;
		printf("The list is empty. Value is (%d) \n", empty);
	}else{
		empty = 1;
		printf("List exists. Value is (%d) \n", empty);
	}
}

//Replace the value of the index had
void replace(linkedList_h* List, int index, char *string){

	removeNode(List, index);
	insertMNode(List, index, string);

}

//Get value of index
void get(linkedList_h* List, int index){
	
	int count=0;
        listNode* findNode = List->head;
        while(findNode != NULL){
                findNode=findNode->link;
                count++;
        }
	if(index > count || index <= 0){
		printf("(%d) is not an index in the list\n", index);
	}else{
		if(index == 1){
			printf("you entered in the index value is (%s) \n", List->head->data);
		}else{
			int count = 1;
			listNode* findNode;
			findNode = List->head;
			while(count != index){
				findNode=findNode->link;
				count++;
   			}
			printf("you entered in the index value is (%s) \n", findNode->data);
		}
	}
}

//Does this include the value written?
int contains(linkedList_h* List, char *string){
	
        listNode* findNode=List->head;

	for(findNode=List->head; findNode->link!=NULL; findNode=findNode->link){
        	
		if(strcmp(findNode->data, string)){
			printf("Included.\n");
			break;
		}
			
	}
        
	return 0;
}

//Print linkedlist
void printList(linkedList_h* List) 
{ 
	listNode* findNode; 
	printf("List = ("); 
	findNode= List->head; 
	while(findNode != NULL){ 
		printf("%s", findNode->data); 
		findNode = findNode->link; 
		if(findNode != NULL){ 
         		printf(", "); 
		} 
	} 
	printf(") \n"); 
}

//All delete in linkedlist
void clear(linkedList_h* List)
{
	listNode* point;
	while(List->head != NULL){
		point = List->head;
		List->head = List->head->link;	
		free(point);
		point=NULL;
	}
}
  
//Insert string type value in middle of linkedlist
void insertMNode(linkedList_h *List, int num, char *string) 
{ 

	int count=0;
        listNode* findNode = List->head;
        while(findNode != NULL ){
                findNode=findNode->link;
                count++;
        }
        if(num > count || num <= 0){
                printf("(%d) is not an index in the list.\n", num);
        }else{
		if(num == 1){
			listNode* newNode;
			newNode = (listNode*)malloc(sizeof(listNode));
			strcpy(newNode->data, string);
			newNode->link = List->head;
			List->head = newNode;
		}else{
			int count = 2;
			listNode* findNode = List->head;
  
			while(count != num){
				findNode=findNode->link;
				count++;
			}

			listNode* newNode; 
			newNode = (listNode*)malloc(sizeof(listNode)); 
			strcpy(newNode->data, string);
 
			if (List==NULL){ 
				List->head = newNode; 
				newNode -> link = NULL; 
			}else{ 
				newNode->link = findNode->link;
				findNode->link = newNode; 
			} 
		}
	}
}
