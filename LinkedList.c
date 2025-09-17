#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node node;
node* head = NULL;

void insert(int a) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = a;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node* t = head;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = new_node;
    }
    printf("Inserted %d into list.\n", a);
}

void delete(int a) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }else if(head->data==a){
    	head=head->next;
	}else{
		node* t;
		for(t=head;t->next->data!=a && t->next!=NULL;t=t->next)
		;
		if(t->next==NULL){
			printf("element not found\n");
		}else{
			printf("deleted\n");
			t->next=t->next->next;
		}
	}
    

}

void disp() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* t = head;
    printf("Linked List: ");
    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int countnodes() {
    int c = 0;
    node* temp = head;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    return c;
}

void sort() {
    if (head == NULL) {
        printf("List is empty, cannot sort.\n");
        return;
    }
    node* i;
    node* j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = head; j->next!= NULL; j = j->next) {
            if (j->data > j->next->data) {
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
    printf("List sorted in ascending order.\n");
}
void replace(int a, int b){
	if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }else if(head->data==a){
    	head->data=b;
	}else{
		node* t;
		int flag=0;
		for(t=head;t!=NULL;t=t->next){
			if(t->data==a){
				t->data=b;
				flag=1;
				printf("Replaced\n");
				break;
			}
		}
		if(flag==0){
			printf("Not found\n");
		}
	}
}

void search(int a){
	 if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }else if(head->data==a){
    	printf("element found");
	}else{
		node* t;
		int flag=0;
		for(t=head;t!=NULL;t=t->next){
			if(t->data==a){
				flag=1;
				printf("found\n");
				break;
			}
		}
		if(flag==0){
			printf("not found\n");
		}
	}
}

void reverse()
{
int count=countnodes();
node *t1=head;
int i,j,temp;
for(i=0;i<count/2;i++){
    node *t2=head;
    for(j=1;j<=count-i-1;j++){
        t2=t2->next;
    }
    temp=t1->data;
    t1->data=t2->data;
    t2->data=temp;
    t1=t1->next;
}
}


int choice() {
    int ch;
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Sort\n5.Count\n 6.Reverse\n 7.Replace\n 8.Search \n 9.Exit \nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}


void process() {
    int ch,n;
    for (ch = choice(); ch != 9; ch = choice()) {
        switch (ch) {
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d", &n);
                insert(n);
                break;
            case 2:
            	printf("enter a number to delete:");
            	int d;
            	scanf("%d",&d);
                delete(d);
                break;
            case 3:
                disp();
                break;
            case 4:
                sort();
                break;
            case 5:
                n=countnodes();
                printf("Count: %d\n", n);
                break;
            case 6:
            	reverse();
                break;
            case 7:
            	printf("enter a number to replace:");
                int r1,r2;
                scanf("%d",&r1);
                printf("enter a number to replace with:");
                scanf("%d",&r2);
                replace(r1,r2);
                break;
            case 8:
            	printf("enter a number to search:");
                int s1;
                scanf("%d",&s1);
                search(s1);
                break;
            case 9:
                printf("Exiting...\n");
                break;                                                       

            default:
                printf("Wrong choice! Please try again.\n");
        }
    }
}

int main() {            
    process();
    return 0;
}
