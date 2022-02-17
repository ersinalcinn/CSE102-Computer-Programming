#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define LENGHT 1000000 
//I define the struts we will use.
struct N {
	
	int numberr;
	struct N *nextptr;
};
struct node {
	int data;
	struct node* nextptr;
};
struct diff_value{
	int n1;
	int n2;
	struct diff_value* next;
};
/*

We read the data in the list.txt file and then split it up to comma.strtok.
Then we turn the integer number into a base of 10.And while doing this, we allocate space from our dynamic array every time as much as we will use.
We keep the timer for how long the function runs from us. We break the file down to the last data, create the node and send our array to main.
*/
struct N* read_linkedlist(char *filename, struct N *numbers){	
	clock_t start = clock();
	char temp_0[LENGHT];
	char *temp,*temp2;
	int num,iter = 0,count=0;
	FILE *fp = fopen("list.txt","r");
	struct N* head;
	fgets(temp_0,LENGHT,fp);
	temp = strtok(temp_0,",");
	num = strtol(temp, &temp2, 10);
	numbers = (struct N*)malloc(sizeof(struct N));
	head=numbers;
	numbers->numberr = num;
	if(temp != NULL)
	num = strtol(temp, &temp2, 10);
	while(temp != NULL){
		count++;
		temp = strtok(NULL,",");
		if(temp != NULL){
			num = strtol(temp, &temp2, 10);
			numbers->nextptr=(struct N*)malloc(sizeof(struct N*));
			numbers=numbers->nextptr;
			numbers->numberr = num;
		}
	}
	numbers->nextptr=NULL;
	clock_t end = clock();
	double time = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("For linkedlist filling took %f seconds to execute \n", time);
	return head;
}
/*
We read and save the data in a series as we do in the linklist and split it one by one. We convert it to 10 base with strtol.
Then we save the data in the linklist, we create a new node, move to that node and save our data over and over again.
It saves the beginning of our link list to a new temp. We need not to lose it. When our function is over, we send it to main.
Likewise, we print on the screen how long the function has been running.
*/
int *read_array(char *filename, int *numbers,int *array_size){
	
	char temp_0[LENGHT];
	char *temp,*temp2;
	int num,iter = 0,count=0;
	FILE *fp = fopen(filename,"r");
	clock_t start = clock();
	fgets(temp_0,LENGHT,fp);
	temp = strtok(temp_0,",");
	num = strtol(temp, &temp2, 10);
	numbers = (int*) malloc(sizeof(int));
	numbers[count] = num;
	if(temp != NULL)
	num = strtol(temp, &temp2, 10);
	while(temp != NULL){
		numbers = (int*) realloc(numbers,sizeof(numbers)+(sizeof(int)*count));
		count++;
		temp = strtok(NULL,",");
		if(temp != NULL){
			num = strtol(temp, &temp2, 10);
			numbers[count] = num;
		}
	}
	clock_t end = clock();
	double time = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("For array filling took %f seconds to execute \n", time);
	*array_size=count;
	return numbers;
}
/*

In this function, we calculate the smallest and largest value, average and standard deviation in the dynamic.
For this, we send our knee from the main and the first node of our linklist.
We also keep the results in a 4-dimensional array and send it back to the main.
*/
float *stats_array(float buffer[4], int *array, int count){
	clock_t start = clock();
	int i = 1, min = array[0], max = array[0];
	float mean = 0.0, stddev = 0.0, sum = array[0];
	while(i < count){
		if(array[i] < min)
		min = array[i];
		if(array[i] > max)
		max = array[i];
		sum += array[i];
		i++;
	}
	mean = sum / (float)count;
	for(i = 0; i < count; i++){
		stddev += ( (array[i]-mean)*(array[i]-mean) );
		stddev = sqrt(stddev/count);
		buffer[0] = (float)min;
		buffer[1] = (float)max;
		buffer[2] = mean;
		buffer[3] = stddev;
	}
	clock_t end = clock();
	double time = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("For array stats took %f seconds to execute \n", time);
		return buffer;
}
/*

We send the first head of our node in the linklist.
We throw it into the temporary variable to avoid losing the head of the knot. 
Since we went to the end of the knot, I used more than one temporary variable. Here, I also calculated the min, max, std, mean.
*/
float * stats_linkedlist(float buffer[4],struct N* head){	
	clock_t start = clock();
	int count=0;	
	struct N* temp;
	struct N* temp1;
	struct N* temp2;
	float max=0.0,min=0.0,mean=0.0,std=0.0;
	temp=head;
	temp1=head;
	temp2=head;
	while(temp!=NULL)
	{
		count+=1;
		temp=temp->nextptr;
	}
	int i=0;
	max=temp1->numberr;
	min=temp2->numberr;
	while(i<count && temp1!=NULL)
	{
		mean+=temp1->numberr;
		
		if(temp1->numberr>max)
		{
			max=temp1->numberr;
			temp1=temp1->nextptr;
		}
		else
		{
			temp1=temp1->nextptr;
		}
	}
	mean=mean/count;
	i=0;
	while(i<count && temp2!=NULL)
	{
		std += ( (temp2->numberr-mean)*(temp2->numberr-mean) );
		if(temp2->numberr<min)
		{
			min=temp2->numberr;
			temp2=temp2->nextptr;
		}
		else
		{
			temp2=temp2->nextptr;
		}
	}
	buffer[0]=min;
	buffer[1]=max;
	buffer[2]=mean;
	buffer[3]=sqrt(std/count);
	clock_t end = clock();
	double time = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("For linkedlist stats took %f seconds to execute \n", time);
	return buffer;
}
/*
Since our series is a dynamic series, I filled it with my hand, but I gave memory as much space as our series would take up. 
Then I saved the data in our series and sent it to main.
*/
int* fill_array(int *numb)
{
		numb =  (int *) calloc(10, sizeof(int));
		numb[0]=11;
		numb[1]=2;
		numb[2]=35;
		numb[3]=14;
		numb[4]=17;
		numb[5]=67;
		numb[6]=55;
		numb[7]=98;
		numb[8]=32;
		numb[9]=22;
		return numb;
}
/*
In the linklist, I filled the string with my hand and stored the first node of the string in the temporary variable and sent it back.
*/
struct node* fill_link(struct node* value)
{
	struct node* head;
	value = (struct node*)malloc(sizeof(struct node));
	head=value;
	value->data=11;
	value->nextptr=(struct node*)malloc(sizeof(struct node));
	value = value->nextptr;
	value->data=2;
	value->nextptr=(struct node*)malloc(sizeof(struct node));
	value = value->nextptr;
	value->data=35;
	value->nextptr=(struct node*)malloc(sizeof(struct node));
	value = value->nextptr;
	value->data=13;
	value->nextptr=(struct node*)malloc(sizeof(struct node));
	value = value->nextptr;
	value->data=17;
	value->nextptr=(struct node*)malloc(sizeof(struct node));
	value = value->nextptr;
	value->data=67;
	value->nextptr=(struct node*)malloc(sizeof(struct node));
	value = value->nextptr;
	value->data=55;
	value->nextptr=(struct node*)malloc(sizeof(struct node));
	value = value->nextptr;
	value->data=99;
	value->nextptr=(struct node*)malloc(sizeof(struct node));
	value = value->nextptr;
	value->data=32;
	value->nextptr=(struct node*)malloc(sizeof(struct node));
	value = value->nextptr;
	value->data=22;
	value->nextptr=(struct node*)malloc(sizeof(struct node));
	value = value->nextptr;
	return head;
}
/*
I called all the functions I used in the main menu, combining 2 separate assignments into a single file.
*/
int main(){

	int select,array_size,i=0;
	float calc_array[4],calc_linked[4];
	struct N* num;
	struct N* num2;
	int *array_linked,*number;
	printf("***********PLEASE SELECT PART*************\n");
	printf("(1)  Part1\n");
	printf("(2)  Part2\n");
	scanf("%d",&select);
	switch(select)
	{
		case 1://I pressed both 4-dimensional arrays that I sent to the function.
			printf("\n***********ARRAY**********\n");
			number = read_array("list.txt",number,&array_size);
			stats_array(calc_array,number,array_size);
			printf("Min : %lf\n",calc_array[0]);
			printf("Max : %lf\n",calc_array[1]);
			printf("Mean : %lf\n",calc_array[2]);
			printf("Std : %lf\n",calc_array[3]);
			printf("\n\n***********LINKEDLIST**********\n");
			num2=read_linkedlist("list.txt",num);
			stats_linkedlist(calc_linked,num2);
			printf("Min : %lf\n",calc_linked[0]);
			printf("Max : %lf\n",calc_linked[1]);
			printf("Mean : %lf\n",calc_linked[2]);
			printf("Std : %lf\n",calc_linked[3]);	break;
		case 2://I filled the link list with my first string. Then I compared the things I returned individually. I created a new linklist and saved it and printed it on the screen.
			array_linked=fill_array(array_linked);
			struct node* number;
			struct node* temp;
			struct diff_value* new;
			struct diff_value* new_t;
			new=(struct diff_value*)malloc(sizeof(struct diff_value));
			new_t=new;
			temp=fill_link(number);
			printf("ARRAY     LINKEDLIST\n");
			for (int i = 0; i < 10; ++i)
			{
				printf("%-13d",array_linked[i]);
				printf("%d\n",temp->data);
				if(array_linked[i]==temp->data)
				{
					temp=temp->nextptr;
				}
				else
				{	
					new->next=(struct diff_value*)malloc(sizeof(struct diff_value));
					new->n1=array_linked[i];
					new->n2=temp->data;
					new=new->next;
					temp=temp->nextptr;
				}
			}
			new->next=NULL;
			while(new_t->next!=NULL)
			{
				printf("Array : %d  Linkedlist : %d \n",new_t->n1,new_t->n2);
				new_t=new_t->next;
			}break;
		default:printf("ERROR.\n");break;
	}
}
