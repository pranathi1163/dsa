#include  <bits/stdc++.h>
#include<string>
using namespace std;
struct node
{
	int hour; // Store the hour / HH
    int minute; // Store the minute / MM
    int priority;
    char description[50]; // Store the event description
	struct node *fwd;
	struct node *bwd;
};

struct node* start=NULL;
struct node* prev=NULL;
struct node* next=NULL;
struct node* head=NULL;
struct node* ptr=NULL;

node* createHead()
{
	struct node* N = new node;
    cout<<"Enter hours : ";
    int hr;
    cin>>hr;
    cout<<"Enter minutes : ";
    int Min;
    cin>>Min;
    cout<<"Enter priority : ";
    int p;
    cin>>p;
    cout<<"Enter description : ";
    char str[50];
    cin.ignore();
    cin.getline(str,50);
    scanf("%s",str);
	N->hour=hr;
	N->minute=Min;
	N->priority=p;
	strcpy(N->description,str);
	N->fwd=NULL;
	N->bwd=NULL;
    start = N;

	return start;
}

void ins_end()
{
	struct node* prev=start;
	while(prev->fwd!=NULL)
	{
		prev=prev->fwd;
	}

	cout<<"Enter hours : ";
	int hour;
	cin>>hour;
	cout<<"Enter minutes : ";
	int minute;
	cin>>minute;
	cout<<"Enter priority : ";
	int priority;
	cin>>priority;
	cout<<"Enter description : ";
    char str[50];
    cin.ignore();
    cin.getline(str,50);

	struct node *N= new node;
	N->hour=hour;
	N->minute=minute;
	N->priority=priority;
	strcpy(N->description,str);
	N->fwd=NULL;
	N->bwd=prev;
	prev->fwd=N;
}

void del_position()
{
	int pos,i;
	cout<<"\nEnter the position to be deleted : ";
	cin>>pos;
	int x=1;

	cout<<endl<<x<<endl;
    struct node* prev=start;
    struct node* ptr=start;
    do
    {
       prev=ptr;
       ptr=ptr->fwd;
       x++;

    }while(x<pos);

	prev->fwd = ptr->fwd;
	if(ptr->fwd != NULL)
		ptr->fwd->bwd=prev;

	ptr->fwd = NULL;
	ptr->bwd = NULL;
	delete(ptr);
}

void count_nodes(struct node* head)
{

	int ct=1;
	ptr=head;
	while(ptr->fwd!=NULL)
	{
		ct++;
		ptr=ptr->fwd;
	}
	cout<<"\nNumber of events noted = "<<ct<<endl;

}

void display(struct node* head)
{
    cout<<"HOUR"<<"  "<<"MINUTES  "<<"PRIORITY\t"<<"DESCRIPTION\n";
	ptr=head;
	while(ptr->fwd!=NULL)
	{
		cout<<"\t\t\t\t\t\t";
		cout<<ptr->hour<<" "<<ptr->minute<<"\t"<<ptr->priority<<"\t\t";
		char str[50];
        puts(ptr->description);
		ptr=ptr->fwd;
	}

	cout<<ptr->hour<<"\t"<<ptr->minute<<"\t"<<ptr->priority<<"\t";
	char str[50];
    memcpy(str,ptr->description,sizeof(ptr->description));
    puts(str);

}

void sortListPriority(struct node* start)
{
    int swapped,i;
    struct node* ptr1;
    struct node* lptr=NULL;
    if(start==NULL)
        return;
    do
    {
        swapped=0;
        ptr1=start;
        while(ptr1->fwd != lptr)
        {
            if(ptr1->priority > ptr1->fwd->priority)
            {
                swap(ptr1->priority,ptr1->fwd->priority);
                swap(ptr1->description,ptr1->fwd->description);
                swap(ptr1->hour,ptr1->fwd->hour);
                swap(ptr1->minute,ptr1->fwd->minute);
                swapped=1;
            }
            ptr1=ptr1->fwd;
        }
        lptr=ptr1;
    }
    while(swapped);
}

void sortListTime(struct node* start)
{
    int swapped,i;
    struct node* ptr1;
    struct node* lptr=NULL;
    if(start==NULL)
        return;
    do
    {
        swapped=0;
        ptr1=start;
        while(ptr1->fwd != lptr)
        {
            if(ptr1->hour > ptr1->fwd->hour)
            {
                swap(ptr1->priority,ptr1->fwd->priority);
                swap(ptr1->description,ptr1->fwd->description);
                swap(ptr1->hour,ptr1->fwd->hour);
                swap(ptr1->minute,ptr1->fwd->minute);
                swapped=1;
            }
            if(ptr1->hour == ptr1->fwd->hour)
            {
                if(ptr1->minute > ptr1->fwd->minute)
                {
                    swap(ptr1->priority,ptr1->fwd->priority);
                    swap(ptr1->description,ptr1->fwd->description);
                    swap(ptr1->hour,ptr1->fwd->hour);
                    swap(ptr1->minute,ptr1->fwd->minute);
                    swapped=1;
                }
            }
            ptr1=ptr1->fwd;
        }
        lptr=ptr1;
    }
    while(swapped);
}

int main()
{
	int choice,elt;
    do
	{
		cout<<"Enter '1' to create a new event list.";
		cout<<"\nEnter '2' to add events.";
		cout<<"\nEnter '3' to sort the events in priority order.";
		cout<<"\nEnter '4' to sort the events in time order.";
		cout<<"\nEnter '5' to delete any event.";
		cout<<"\nEnter '6' to display the number of events in the event list.";
		cout<<"\nEnter '7' to display.";
		cout<<"\nEnter '8' to exit.";
		cout<<"\nEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				start=createHead();
				display(start);
				break;

			case 2:
				ins_end();
				break;

            case 3:
                sortListPriority(start);
                break;

            case 4:
                sortListTime(start);
                break;

			case 5:
				del_position();
				break;

            case 6:
                count_nodes(start);
                break;

			case 7:
				display(start);
				break;
				/* cout<<"\n\t\t\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\n";
        cout<<"\t\t\xb0                                               \xb0\n";
        cout<<"\n\t\t\xb0      \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4       \xb0\n";
        cout<<"\t\t\xb0                 TASK SCHEDULER                  \xb0\n";
        cout<<"\t\t\xb0      \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4       \xb0\n";
        cout<<"\t\t\xb0                                               \xb0\n";
        cout<<"\t\t    ";
        display(start);
        cout<<endl;

        cout<<"\t\t\xb0                                               \xb0\n";
        cout<<"\t\t\xb0                                               \xb0\n";
        cout<<"\n\t\t\xb0      \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4       \xb0\n";
        cout<<"\t\t\xb0                                               \xb0\n";
        cout<<"\n\t\t\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\n";
                break;*/

            case 8:
                exit(1);
                break;

		}

		}while(choice>0 && choice<9);

}



