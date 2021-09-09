#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct
{
	struct node *top;
}stack;
stack g_stack;

typedef struct
{
	struct node *front;
	struct node *rear;
}queue;
queue g_queue;
typedef struct bst
{
	int data;
	struct bst *left;
	struct bst *right;
}bst;


void fill_structures(stack **stack_,queue **queue_,bst **bst_,int data[20])
{
	clock_t begin = clock();
	
	(*stack_)=(stack *)malloc(sizeof(stack));
	(*stack_)->top=(struct node*)malloc(sizeof(struct node));
	(*stack_)->top->data=data[0];
	(*stack_)->top->next=NULL;
	int i=1;
	for(;i<20;i++)
	{
		struct node *pilot=(struct node*)malloc(sizeof(struct node));
		pilot->data=data[i];
		pilot->next=(*stack_)->top;
		(*stack_)->top=pilot;
	}
	clock_t end = clock();
	double time_stack = (double)(end - begin);
	
	begin = clock();
	(*queue_)=(queue*)malloc(sizeof(queue));
	(*queue_)->front=(*queue_)->rear=(struct node*)malloc(sizeof(struct node));
	(*queue_)->front->data=(*queue_)->rear->data=data[0];
	i=1;
	for(;i<20;i++)
	{
		struct node *pilot=(struct node*)malloc(sizeof(struct node));
		pilot->data=data[i];
		(*queue_)->rear->next=pilot;
		(*queue_)->rear=pilot;
	}
	(*queue_)->rear->next=NULL;
	end = clock();
	double time_que = (double)(end - begin);
	begin = clock();
	(*bst_)=(bst*)malloc(sizeof(bst));
	(*bst_)->data=data[0];
	(*bst_)->left=(*bst_)->right=NULL;
	i=1;
	for(;i<20;i++)
	{
		bst *pilot=(bst*)malloc(sizeof(bst));
		pilot->data=data[i];
		pilot->left=pilot->right=NULL;
		bst *plt=(*bst_);
		while(1)
		{
			if(data[i]<=plt->data)
			{
				if(plt->left==NULL)
				{
					plt->left=pilot;
					break;
				}
				else
				{
					plt=plt->left;
					continue;
				}
			}
			if(data[i]>plt->data)
			{
				if(plt->right==NULL)
				{
					plt->right=pilot;
					break;
				}
				else
				{
					plt=plt->right;
					continue;
				}
			}
			
		}
	}
	end = clock();
	double time_bst = (double)(end - begin);
	printf("FILLSTRUCTURES\n---------------\n");
	printf("Structures  Stack    Queue     BST\n");
	printf("Exec.time   %.2f    %.2f      %.2f\n",time_stack,time_que,time_bst);
	
}
void print_bst(bst *bst_)
{
	if(bst_==NULL)
		return;
	print_bst(bst_->left);
	printf("%d ",bst_->data);
	print_bst(bst_->right);
}
void print_inorder(bst *bst_)
{
	if(bst_==NULL)
		return;
	printf("%d->",bst_->data);
	print_bst(bst_->left);
	print_bst(bst_->right);
}
void ordered_print(stack *stack_,queue* queue_,bst* bst_)
{
	stack *stk_;
	stk_=(stack*)malloc(sizeof(stack));//veri korumak icin yeni bir stk_ olusturuyoruz..
	stk_->top=(struct node*)malloc(sizeof(struct node));
	struct node *pllt=stack_->top;
	stk_->top->data=pllt->data;
	stk_->top->next=NULL;
	int k=1;
 	pllt=pllt->next;
	for(;k<20;k++)
	{
		struct node *pilot=(struct node*)malloc(sizeof(struct node));
		pilot->data=pllt->data;
		pilot->next=stk_->top;
		stk_->top=pilot;
		pllt=pllt->next;
	}
 	int swapped, i,temp; 
    struct node *pointer; 
    struct node *last = NULL; 
    clock_t begin = clock();
    do
    { 
        swapped = 0;
        pointer = stk_->top; 
  
        while (pointer->next != last) 
        { 
            if (pointer->data > pointer->next->data) 
            {  
                temp=pointer->data;
                pointer->data=pointer->next->data;
                pointer->next->data=temp;
                swapped = 1; 
            } 
            pointer = pointer->next; 
        } 
        last = pointer; 
    } 
    while (swapped);  
	printf("\n\n\nORDERED_PRINT(STACK)\n-------------------\n");
	struct node *plt=stk_->top;
	while(plt!=NULL)
	{
		printf("%d ",plt->data);
		plt=plt->next;
	}
	clock_t end = clock();
	double time_stack = (double)(end - begin);
	begin=clock();
	queue *que=(queue*)malloc(sizeof(queue));//veri korumak icin yeni bir que olusturuyoruz..
	que->front=que->rear=(struct node*)malloc(sizeof(struct node));
	struct node *pltt=queue_->front;
	que->front->data=que->rear->data=pltt->data;
	k=1;
	pltt=pltt->next;
	for(;k<20;k++)
	{
		struct node *pilot=(struct node*)malloc(sizeof(struct node));
		pilot->data=pltt->data;
		que->rear->next=pilot;
		que->rear=pilot;
		pltt=pltt->next;
	}
	que->rear->next=NULL;
	last=NULL;
	do
    { 
        swapped = 0; 
        pointer = que->front; 
  
        while (pointer->next != last) 
        { 
            if (pointer->data > pointer->next->data) 
            {  
                temp=pointer->data;
                pointer->data=pointer->next->data;
                pointer->next->data=temp;
                swapped = 1; 
            } 
            pointer = pointer->next; 
        } 
        last = pointer; 
    } 
    while (swapped);
	
	printf("\nORDERED_PRINT(QUEUE)\n-------------------\n");
	struct node *plt_q=que->front;
	while(plt_q!=NULL)
	{
		printf("%d ",plt_q->data);
		plt_q=plt_q->next;
	}
	end = clock();
	double time_que = (double)(end - begin);
	begin=clock();
	printf("\nORDERED_PRINT(BST)\n-------------------\n");
	print_bst(bst_); 
	end = clock();
	double time_bst = (double)(end - begin);
	printf("\nStructures  Stack    Queue     BST\n");
	printf("Exec.time   %.2f    %.2f      %.2f\n",time_stack,time_que,time_bst);
	
	g_stack=*stk_;/////---->sirali hallerini kaydetmek için
	g_queue=*que;/////---->sirali hallerini kaydetmek için(specialtraversede kullanılacak..)
	

	 
}
int counter_bst=0;
int search_bst(bst *bst_,int val)//recursive fonksiyon oldugu icin ayri yazdim..
{
	if(bst_==NULL)
		return 0;
	counter_bst++;
	if(bst_->data==val)
		return counter_bst;
	else if(bst_->data>val)
		return search_bst(bst_->left,val);
	else if(bst_->data<val)
		return search_bst(bst_->right,val);
}

void search(stack * stack_, queue * queue_, bst * bst_, int val_to_search)
{
	struct node *pilot=stack_->top;//veri korumak icin..
	int count=1,count_2=-1;
	printf("\n\n\nSEARCH(STACK)\n-------------------\n");
	clock_t begin = clock();
	printf("(top)");
	while(pilot!=NULL)
	{
		printf("%d->",pilot->data);
		if(pilot->data==val_to_search)
		{
			count_2=count;
		}
		pilot=pilot->next;
		count++;
	}
	if(count_2==-1)
	{
		printf("\nARANAN SAYİ BULUNAMADİ\n");
	}
	else
	{
		printf("\n%d founded on %d.step\n",val_to_search,count_2);
	}
	clock_t end = clock();
	double time_stack = (double)(end - begin);
	printf("SEARCH(QUEUE)\n-------------------\n");
	begin = clock();
	pilot=queue_->front;
	count=1,count_2=-1;
	printf("(head)");
	while(pilot!=NULL)
	{
		printf("%d->",pilot->data);
		if(pilot->data==val_to_search)
		{
			count_2=count;
		}
		pilot=pilot->next;
		count++;
	}
	printf("(tail)");
	if(count_2==-1)
	{
		printf("\nARANAN SAYİ BULUNAMADİ\n");//sonuc cikmazsa raporluyor
	}
	else
	{
		printf("\n%d founded on %d.step\n",val_to_search,count_2);
	}
	end = clock();
	double time_que = (double)(end - begin);
	printf("SEARCH(BST)\n-------------------\n");
	begin = clock();
	printf("(root)");
	print_inorder(bst_);
	
	int sonuc=search_bst(bst_,val_to_search);
	if(sonuc!=0)
	{
		printf("\n%d founded on %d.step\n",val_to_search,sonuc);
	}
	else
	{
		printf("\nARANAN SAYİ BULUNAMADİ\n");//sonuc cikmazsa raporluyor
	}
	end = clock();
	double time_bst = (double)(end - begin);
	printf("Structures  Stack    Queue     BST\n");
	printf("Exec.time   %.2f    %.2f      %.2f\n",time_stack,time_que,time_bst);
	
}
int max(bst *bst_)
{
	if(bst_!=NULL)
	{
	bst *pilot=bst_;
	while (pilot->right!=NULL)//sag null olana kadar gider
        pilot = pilot->right; 
      
    int re=pilot->data;
    //pilot->data=-1;
    return (re);
	}	
}
int min(bst *bst_)
{
	if(bst_!=NULL)
	{
	bst *pilot=bst_;
	while (pilot->left!=NULL)  //sol null olana kadar gider
        pilot = pilot->left; 
    int re=pilot->data;
    //pilot->data=-1;
    return (re);
	}
		
	
}
bst* minValueNode(bst* node) 
{ 
    bst* current = node; 
  
    
    while (current!=NULL && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
bst* deleteNode(bst* root,int data) 
{ 
    
    if(root==NULL) 
		return root; 
  
   
    if(data<root->data) 
        root->left=deleteNode(root->left,data); 
  
    else if(data>root->data) 
        root->right=deleteNode(root->right,data); 
  
    
    else
    { 
      
        if(root->left==NULL) 
        { 
            bst *temp=root->right; 
            free(root); 
            return temp; 
        } 
        else if(root->right==NULL) 
        { 
            bst *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        bst* temp=minValueNode(root->right); 
  
        
        root->data=temp->data; 
  
       
        root->right=deleteNode(root->right,temp->data); 
    } 
    return root; 
}
void special_traverse(stack * stack_, queue * queue_, bst * bst_)
{
	stack_=&g_stack;//sirali halini aliyoruz
	queue_=&g_queue;//sirali halini aliyoruz
	printf("\n\n\nSPECIALTRAVERSE(STACK)\n-------------------\n");
	clock_t begin = clock();
	struct node *pilot,*pilot_2=stack_->top;
	int i=0,j=0;
	for(;i<10;i++)
	{
		pilot=pilot_2=stack_->top;
		j=0;
		while(j<19-i)//sondan baslar
		{
			pilot=pilot->next;
			j++;
		}
		printf("%d,",pilot->data);//bastan baslar
		j=0;
		while(j<i)
		{
			pilot_2=pilot_2->next;
			j++;
		}
		printf("%d,",pilot_2->data);
	}
	clock_t end = clock();
	double time_stack = (double)(end - begin);
	printf("\n\nSPECIALTRAVERSE(QUEUE)\n-------------------\n");
	begin = clock();
	pilot=pilot_2=queue_->front;
	i=0,j=0;
	for(;i<10;i++)
	{
		pilot=pilot_2=queue_->front;
		j=0;
		while(j<19-i)
		{
			pilot=pilot->next;
			j++;
		}
		printf("%d,",pilot->data);
		j=0;
		while(j<i)
		{
			pilot_2=pilot_2->next;
			j++;
		}
		printf("%d,",pilot_2->data);
	}
	end = clock();
	double time_que = (double)(end - begin);
	printf("\n\nSPECIALTRAVERSE(BST)\n-------------------\n");
	begin = clock();
	i=0;
	int max_,min_;
	for(;i<10;i++)
	{
		max_=max(bst_);
		min_=min(bst_);
		printf("%d,",max_);//en saga gidip en buyugu..
		bst_=deleteNode(bst_,max_);
		printf("%d,",min_);//en sola gidip en kucugu..
		bst_=deleteNode(bst_,min_);
	}
	end = clock();
	double time_bst = (double)(end - begin);
	

	printf("\nStructures  Stack    Queue     BST\n");
	printf("Exec.time   %.2f    %.2f      %.2f\n\n",time_stack,time_que,time_bst);
	
	
}




int main()
{
int data[20]={5, 2, 7, 8, 11, 3, 21, 7, 6, 15, 19, 35, 24, 1, 8, 12, 17, 8, 23, 4};
bst * bst;
queue * queue_;
stack * stack_;
fill_structures(&stack_,&queue_,&bst, data);
ordered_print(stack_, queue_, bst);
search(stack_, queue_, bst, 5);
special_traverse(stack_, queue_, bst);
return 0;
	
	
	
}
