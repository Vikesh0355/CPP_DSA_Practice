#include<stdio.h>
#include<stdlib.h>

int  main()
{
    
    struct node{
                 int data;
                 struct node *next;
                 };
                 
    struct node *head;
    struct node *newnode;
    struct node *temp;
    
    head=NULL;
    int choice =1,count=0;
    
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter Data:\n");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
        {head=temp=newnode;}
        else
        {
        temp->next=newnode;
        temp=newnode;}
        printf("Do you want to continue (0,1)?\n");
        scanf("%d",&choice);
    }
    // Display the list
    printf("--------------------------------\n");
    temp = head;  // Start from the head for displaying
    while (temp != 0) {
        printf("%d ", temp->data);  // Print each data followed by a space
        temp = temp->next;
        count++;
    }
    printf("\n");  // Print a newline after all data is printed
    {
    printf("\nCount=%d",count);}
    return 0;
}