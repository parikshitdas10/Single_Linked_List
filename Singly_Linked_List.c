//Singly Linked List.

#include<stdio.h>
#include<stdlib.h>


struct Node
{
	int data;
	struct Node* next;
}*head=NULL;

//0
struct Node* create_new_node()
{
	return (struct Node*)calloc(1,sizeof(struct Node));
}

//14
int cnt_records()
{
	if(!head)
	return 0;

	struct Node* ptr=head->next;
	int cnt=1;

	while(ptr)
	{
		cnt++;
		ptr=ptr->next;
	}

	return cnt;
}

//2
struct Node** insert_beg(int data)
{
	struct Node* nd=create_new_node();

	if(!nd)
	{
		printf("\n\nERROR: Dynamic allocation failed.");
		return NULL;
	}

	nd->data=data;
	nd->next=head;
	head=nd;

	return &head;
}

//3
struct Node** insert_end(int data)
{
	struct Node* nd=create_new_node(),*ptr=head;

	if(!nd)
	{
		printf("\n\nERROR: Dynamic allocation failed.");
		return NULL;
	}

	if(head)
	{
		while(ptr->next)
		ptr=ptr->next;

		ptr->next=nd;
	}
	else
	head=nd;

	nd->data=data;
	nd->next=NULL;

	return &head;
}

//4
struct Node** insert(int pos,int data)
{
	if(!head && pos!=1)
	{
		printf("\n\nERROR: No list found.");
		return NULL;
	}

	int cnt=cnt_records();

	if(pos>cnt+1 || pos<1)
	{
		printf("\n\nERROR: Position out of range in list.");
		return NULL;
	}

	if(pos==1)
	return insert_beg(data);

	if(pos==cnt_records()+1)
	return insert_end(data);

	struct Node* nd=create_new_node(),*ptr=head;
	int node_no=1;

	if(!nd)
	{
		printf("\n\nERROR: Dynamic allocation failed.");
		return NULL;
	}

	while(node_no!=pos-1)
	{
		ptr=ptr->next;
		node_no++;
	}

	nd->data=data;
	nd->next=ptr->next;
	ptr->next=nd;

	return &head;
}

//5
struct Node** insert_bef(int element,int data)
{
	if(!head)
	{
		printf("\n\nERROR: No list found.");
		return NULL;
	}

	struct Node* nd=create_new_node(),*ptr=head;

	if(!nd)
	{
		printf("\n\nERROR: Dynamic allocation failed.");
		return NULL;
	}

	if(ptr->data==element)
	return insert_beg(data);

	while(ptr->next && ptr->next->data!=element)
	ptr=ptr->next;

	if(!ptr->next && ptr->data!=element)
	{
		printf("\n\nERROR: No such node having data '%d' has been found in the list.",element);
		return NULL;
	}

	nd->data=data;
	nd->next=ptr->next;
	ptr->next=nd;

	return &head;
}

//6
struct Node** insert_after(int element,int data)
{
	if(!head)
	{
		printf("\n\nERROR: No list found.");
		return NULL;
	}

	struct Node* nd=create_new_node(),*ptr=head;

	if(!nd)
	{
		printf("\n\nERROR: Dynamic allocation failed.");
		return NULL;
	}

	while(ptr->data!=element && ptr)
	ptr=ptr->next;

	if(!ptr)
	{
		printf("\n\nERROR: No such node having data '%d' has been found in the list.",element);
		return NULL;
	}

	nd->data=data;
	nd->next=ptr->next;
	ptr->next=nd;

	return &head;
}

//7
struct Node** delete_beg()
{
	if(!head)
	{
		printf("\n\nERROR: No list found.");
		return NULL;
	}

	struct Node* ptr=head;

	head=ptr->next;
	free(ptr);
	return &head;
}

//8
struct Node** delete_end()
{
	if(!head)
	{
		printf("\n\nERROR: No list found.");
		return NULL;
	}

	struct Node* ptr=head;

	if(!ptr->next)
	return delete_beg();

	while(ptr->next->next)
	ptr=ptr->next;

	free(ptr->next);
	ptr->next=NULL;
}

//9
struct Node** delete_element(int element)
{
	if(!head)
	{
		printf("\n\nERROR: No list found.");
		return NULL;
	}

	struct Node* ptr=head;

	if(ptr->data==element)
	{
		head=ptr->next;
		free(ptr);
		return &head;
	}

	while(ptr->next && ptr->next->data!=element)
	ptr=ptr->next;

	if(!ptr->next)
	{
		printf("\n\nERROR: No such node having data '%d' has been found in the list.",element);
		return NULL;
	}

	struct Node* qtr=ptr->next;

	ptr->next=ptr->next->next;

	free(qtr);

	return &head;
}


//10
struct Node** delete_node(int pos)
{
	if(!head)
	{
		printf("\n\nERROR: No list found.");
		return NULL;
	}

	int cnt=cnt_records();

	if(pos>cnt || pos<1)
	{
		printf("\n\nERROR: Position out of range in list.");
		return NULL;
	}

	struct Node* ptr=head;

	if(pos==1)
	{
		head=ptr->next;
		free(ptr);
		return &head;
	}

	cnt=1;

	while(cnt!=pos-1)
	{
		ptr=ptr->next;
		cnt++;
	}

	struct Node* qtr=ptr->next;

	ptr->next=ptr->next->next;

	free(qtr);

	return &head;
}

//11
int search(int element)
{
	if(!head)
	{
		printf("\n\nERROR: No list found.");
		return 0;
	}

	struct Node* ptr=head;
	int pos=1;

	while(ptr)
	{
		if(ptr->data==element)
		return pos;
		ptr=ptr->next;
		pos++;
	}

	printf("\n\nERROR: No such node having data '%d' has been found in the list.",element);
	return 0;
}

//12
struct Node** update_element(int element,int data)
{
	if(!head)
	{
		printf("\n\nERROR: No list found.");
		return NULL;
	}

	struct Node* ptr=head;

	while(ptr)
	{
		if(ptr->data==element)
		{
			ptr->data=data;
			return &head;
		}

		ptr=ptr->next;
	}

	printf("\n\nERROR: No such node having data '%d' has been found in the list.",element);
	return NULL;
}

//13
struct Node** update_pos(int pos,int data)
{
	if(!head)
	{
		printf("\n\nERROR: No list found.");
		return NULL;
	}

	if(pos>cnt_records() || pos<1)
	{
		printf("\n\nERROR: Position out of range in list.");
		return NULL;
	}

	struct Node* ptr=head;
	int cnt=1;

	while(ptr)
	{
		if(cnt==pos)
		{
			ptr->data=data;
			return &head;
		}

		ptr=ptr->next;
		cnt++;
	}
}

//15
struct Node** display()
{
	if(!head)
	{
		printf("\n\nERROR: No list found.");
		return NULL;
	}

	struct Node* ptr=head;

	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}

	return &head;
}

//16
struct Node** display_pos(int pos)
{
	if(!head)
	{
		printf("\n\nERROR: No list found.");
		return NULL;
	}

	if(pos>cnt_records() || pos<1)
	{
		printf("\n\nERROR: Position out of range in list.");
		return NULL;
	}

	struct Node* ptr=head;
	int cnt=1;

	while(ptr)
	{
		if(cnt==pos)
		{
			printf("\nMESSAGE: Data of the node at position '%d' is: %d ",pos,ptr->data);
			return &head;
		}

		ptr=ptr->next;
		cnt++;
	}
}

//17
struct Node** display_reverse(struct Node* ptr)
{
	if(!head)
	{
		printf("\n\nERROR: No list found.");
		return NULL;
	}

	if(!ptr)
	return &head;

	display_reverse(ptr->next);
	printf("%d ",ptr->data);
}


//18
struct Node** reverse()
{
	struct Node *ptr,*qtr,*rtr;

	if(!head)
	{
		printf("\n\nERROR: No list found.");
		return NULL;
	}

	if(!(head->next))
	return &head;

	ptr=NULL;
	qtr=head;
	rtr=qtr->next;

	while(rtr)
	{
		qtr->next=ptr;
		ptr=qtr;
		qtr=rtr;
		rtr=rtr->next;
	}

	qtr->next=ptr;
	head=qtr;

	return &head;
}

//21
void free_all()
{
	struct Node* ptr=head;
	while(ptr)
	{
		head=head->next;
		free(ptr);
		ptr=head;
	}

	head=NULL;
}

//1
void create_linked_list(int n)
{
	if(head)
	{
		printf("\n\nERROR: A linked list is already present.");
		printf("\n\nMESSAGE: Displaying the list:\n\n");
		display();
		int ch;
		printf("\n\nMESSAGE: Do you want to delete the previous linked list and make a new one. If yes, enter '1', otherwise '0'.\nEnter your choice: ");
		scanf("%d",&ch);
		if(ch==0)
		return;
		else
		free_all();
	}

	if(!n)
	{
		printf("\n\nMESSAGE: No node created for the list.");
		return;
	}

	printf("\n\nMESSAGE: Enter the '%d' sized data sequentially from left to right:\n\n",n);

	int i,data;

	for(i=0;i<n;i++)
	{
		scanf("%d",&data);

		if(!insert_end(data))
		return;
	}

	printf("\n\nMESSAGE: The linked list with '%d' elements has been successfully created.");

	printf("\n\nMESSAGE: Displaying the entered list:\n\n");
	display();
}

//19
void menu()
{
	printf(" Menu (Linked List):\n---------------------");
	printf("\n\n1)  Create and display linked list.");
	printf("\n2)  Insert an element in the beginning of the list.");
	printf("\n3)  Insert an element at the end of the list.");
	printf("\n4)  Insert at any specified position.");
	printf("\n5)  Insert an element before a particular element.");
	printf("\n6)  Insert an element after a particular element.");
	printf("\n7)  Delete a node from beginning.");
	printf("\n8)  Delete a node from end.");
	printf("\n9)  Delete a particular element.");
	printf("\n10) Delete node of any location.");
	printf("\n11) Search for a particular element.");
	printf("\n12) Update an element of a partiucular value.");
	printf("\n13) Update an element at a particular position.");
	printf("\n14) Count the no of records or nodes.");
	printf("\n15) Display the list.");
	printf("\n16) Display an element of a particular position.");
	printf("\n17) Display reversely the list.");
	printf("\n18) Reverse the list.");
	printf("\n19) Display the Menu.");
	printf("\n20) Count the number of nodes.");
	printf("\n21) Exit.");
}

int main()
{

	int ch,data,pos,element,n;

	menu();

	printf("\n\n");
	int i;
	for(i=0;i<130;i++)
	putchar('-');
	printf("\n\nEnter choice: ");
	scanf("%d",&ch);
	printf("\n");
	for(i=0;i<130;i++)
	putchar('-');

	while(ch!=21)
	{

		switch(ch)
		{
			case 1:		printf("\n\nEnter the no of nodes, you want to create: ");
						scanf("%d",&n);
						create_linked_list(n);
						break;

			case 2:		printf("\n\nEnter the value to be inserted at the begining: ");
						scanf("%d",&data);
						if(insert_beg(data))
						printf("\n\nMESSAGE: New node with data '%d' has been inserted at the beginning of the list.",data);
						break;

			case 3:		printf("\n\nEnter the value to be inserted at the end: ");
						scanf("%d",&data);
						if(insert_end(data))
						printf("\n\nMESSAGE: New node with data '%d' has been inserted at the end of the list.",data);
						break;

			case 4:		printf("\n\nEnter the position at which you want to enter the new data: ");
						scanf("%d",&pos);
						printf("\nEnter the data to be inserted at the position '%d': ",pos);
						scanf("%d",&data);
						if(insert(pos,data))
						printf("\n\nMESSAGE: New node with data '%d' has been inserted at the required position '%d' in the list.",data,pos);
						break;

			case 5:		printf("\n\nEnter the element before which you want to insert the new data: ");
						scanf("%d",&element);
						printf("\nEnter the data to be inserted before the existing data '%d': ",element);
						scanf("%d",&data);
						if(insert_bef(element,data))
						printf("\n\nMESSAGE: New node with data '%d' has been inserted before the given element '%d' in the list.",data,element);
						break;

			case 6: 	printf("\n\nEnter the element after which you want to insert the new data: ");
						scanf("%d",&element);
						printf("\nEnter the data to be inserted after the existing data '%d': ",element);
						scanf("%d",&data);
						if(insert_after(element,data))
						printf("\n\nMESSAGE: New node with data '%d' has been inserted after the given element '%d' in the list.",data,element);
						break;

			case 7:		if(delete_beg())
						printf("\n\nMESSAGE: 1st node has been successfully deleted.");
						break;

			case 8:		if(delete_end())
						printf("\n\nMESSAGE: Last node has been successfully deleted.");
						break;

			case 9:		printf("\n\nEnter the element to be deleted: ");
						scanf("%d",&element);
						if(delete_element(element))
						printf("\n\nMESSAGE: The node having the data '%d' has been deleted from the list.",element);
						break;

			case 10: 	printf("\n\nEnter the position of the node which you want to delete: ");
						scanf("%d",&pos);
						if(delete_node(pos))
						printf("\n\nMESSAGE: The node at the position '%d' has been deleted from the list.",pos);
						break;

			case 11:	printf("\n\nEnter the element you want to search for: ");
						scanf("%d",&element);
						int pos=search(element);
						if(pos)
						printf("\n\nMESSAGE: The node with element '%d' has been found at the position '%d'",element,pos);
						break;

			case 12:	printf("\n\nEnter the element, whose data you want to update: ");
						scanf("%d",&element);
						printf("\nEnter the new data: ");
						scanf("%d",&data);
						if(update_element(element,data))
						printf("\n\nMESSAGE: The node previously with element '%d' has been updated with the new data '%d'.",element,data);
						break;

			case 13:	printf("\n\nEnter the position of the node, whose data you want to update: ");
						scanf("%d",&pos);
						printf("\nEnter the new data: ");
						scanf("%d",&data);
						if(update_pos(pos,data))
						printf("\n\nMESSAGE: The node at the position '%d' has been updated with the new data '%d'.",pos,data);
						break;

			case 14:	printf("\n\nThe total no of records in the list are: %d",cnt_records());
						break;

			case 15:	printf("\n\nMESSAGE: Displaying the whole list.\n\n");
						if(display())
						printf("\n\nMESSAGE: Successfully displayed the whole list.");
						break;

			case 16:	printf("\n\nEnter the position whose element you want to see: ");
						scanf("%d",&pos);
						if(display_pos(pos))
						printf("\n\nMESSAGE: Successfully displayed the data of the node at the position '%d'.",pos);
						break;

			case 17:	printf("\n\nMESSAGE: Displaying the list reversely.");
						if(display_reverse(head))
						printf("\n\nMESSAGE: Successfully displayed the whole list in the reverse order.");
						break;

			case 18:	printf("\n\nMESSAGE: Reversing the list.");
						if(reverse())
						printf("\n\nMESSAGE: List has been successfully reversed.");
						break;

			case 19:	printf("\n\nMESSAGE: Re-displaying the menu.\n\n\n");
						menu();
						break;
			case 20:	printf("\n\nMESSAGE: Counting the nodes\n\n\n");
			            count();
			            break;
			default:	printf("\n\nERROR: Wrong choice.");
						break;

		};

		printf("\n\n");
		for(i=0;i<130;i++)
		putchar('-');
		printf("\n\nEnter choice: ");
		scanf("%d",&ch);
		printf("\n");
		for(i=0;i<130;i++)
		putchar('-');

	}

	printf("\n\nMESSAGE: Program Exited.");

	printf("\n\n");
	for(i=0;i<130;i++)
	putchar('-');

	printf("\n\n");

	free_all();
}
//20
void count()
{
    int n=1;
    struct Node *temp;
    temp=head;
    while(temp->next)
    {
        n++;
        temp=temp->next;
    }
    printf("\n\nMESSAGE: There are %d nodes in the list.",n);
}
