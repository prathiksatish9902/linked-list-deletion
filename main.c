#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * next;
};

struct node *newnode;
struct node *temp;
//head = 0;
int choice =1 ;
struct node* createNode(struct node * head){

    while(choice){
        newnode = (struct node *)malloc(sizeof(struct node));
        if(newnode == 0)
        {
            printf("Memory allocation failed\n");
            return ;
        }
        printf("enter the data");
        scanf("%d",&newnode->data);
        newnode->next = 0;
        if (head == 0){
            head = temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
        printf("do you want to continue (0,1)?");
        scanf("%d",&choice);
    }
    return head;
}

struct node * deleteAtBeginning(struct node * head){
    if(head == NULL){
        printf("empty list");
    }
    else{
        struct node * temp;
        temp = head->next;
        free(head);
        head = temp;
        return head;
    }
}


struct node * deleteAtEnd(struct node * head){
    struct node * prev;
    prev = NULL;
    temp = head;
    while (temp->next != 0){
        prev = temp;
        temp =temp->next;
    }
    prev->next = NULL;
    free(temp);
    return head;
}


struct node * deleteAtPosition(struct node * head){
    struct node * prev;
    int pos , i=1 ;
    prev = NULL ;
    temp = head;
    printf("enter the position:");
    scanf("%d",&pos);
    if(pos == 1){
        temp = head;
        head = head->next;
        free(temp);
    }
    else{
        while(i<pos){
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = temp->next;
        free(temp);
    }
    return head;

}

int display(struct node * head,int count){
    struct node *temp;
    temp = head;
    while(temp != 0)
    {
        printf("%d",temp->data);
        temp = temp->next;
        ++count;
    }
    printf("\ncount = %d",count);
    return count;
}
int main()
{
    struct node * head;
    int count = 0;
    int choice =1,option = 1 ;
    while(choice){
        printf("\n1.crete node\n");
        printf("2.delete at beginning\n");
        printf("3.delete at end\n");
        printf("4.delete at position\n");
        printf("5.display\n");
        printf("6.exit\n");
        printf("enter choice:");
        scanf("%d",&option);
        switch(option){
        case 1 :
            head = createNode(head);
            break;
        case 2:
            head = deleteAtBeginning(head);
            break;
        case 3:
            head = deleteAtEnd(head);
            break;
        case 4:
            head = deleteAtPosition(head);
            break;
        case 5:
            count = display(head,count);
            break;
        case 6:
            exit(0);
            break;
        default :
            printf("invalid option");
            return;
        }
    }


    return 0;
}
