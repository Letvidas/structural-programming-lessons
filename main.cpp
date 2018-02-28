#include <iostream>

using namespace std;
void menu()
{
    cout<<"type 1- to create linked list"<<endl;
    cout<<"type 2- to print linked list"<<endl;
    cout<<"type 3- to add element to shown position of linked list"<<endl;
    cout<<"type 4- to add element before the other element"<<endl;
    cout<<"type 5- to delete element in linked list"<<endl;
    cout<<"type 6- to delete linked list"<<endl;
    cout<<"type 7- to end"<<endl;
    cout<<"type 8 - to delete element by typing it's data"<<endl;

}
struct linked_list
{
    int num;
    linked_list* next;
};
void first(int &n,linked_list* &head,linked_list* &tail,linked_list* &temp)
{
    cout<<"Type the length of the Linked list"<<endl;
    cin>>n;
    cout<<"Type first element of the list"<<endl;
    head= new linked_list;
    cin>>head->num;
    head->next=NULL;
    temp=head;
    tail=head;
    cout<<temp->num<<endl;
    for (int i=0; i<n-1; i++)
    {
        temp=new linked_list;
        cout<<"type "<<i+2<<" data of the list"<<endl;
        cin>>temp->num;
        temp->next=NULL;
        tail->next=temp;
        tail=temp;
    }
}
void second(int n,linked_list* &head,linked_list* &tail,linked_list* &temp)
{
    if (head==NULL)
        cout<<"List Empty"<<endl;
    else
    {
        temp=head;
        cout<<"Your list data= :"<<endl;
        while (temp!=NULL)
        {
            cout<<temp->num<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}
void third(int &n,linked_list* &head,linked_list* &tail,linked_list* &temp,int position)
{
    cout<<"in which position you want to add new element"<<endl;
    cin>>position;
    while (position<1||position>n)
    {
        cout<<"invalid position, type again"<<endl;
        cin>>position;
    }
    linked_list* temp2=new linked_list;
    cout<<"enter data"<<endl;
    cin>>temp2->num;
    if (position!=1&&position!=n)
    {
        temp=head;
        for (int i=0; i<position-2; i++)
        {
            temp=temp->next;
        }
        temp2->next=temp->next;
        temp->next=temp2;
    }
    else if(position==1)
    {
        temp2->next=head;
        head=temp2;
    }
    else if(position==n)
    {
        temp=tail;
        temp2->next=NULL;
        temp->next=temp2;
        tail=temp2;
    }
    n++;
}
void fourth(int &n,linked_list* &head,linked_list* &tail,linked_list* &temp,int &elemcount,int &counter,int elem)
{
    if (head==NULL)
        cout<<"List Empty"<<endl;
    else
    {
        cout<<"Enter element"<<endl;
        cin>>elem;
        temp=head;
        counter=0;
        elemcount=0;
        while (temp!=NULL)
        {
            counter++;
            if (elem==temp->num)
            {
                elemcount=counter;
                break;
            }
            temp=temp->next;
        }
        temp=head;
        linked_list* temp2=new linked_list;;
        if (elemcount==0)
        {
            cout<<"there is no such element"<<endl;
        }
        else if (elemcount==1)
        {
                    cout<<"enter data"<<endl;
        cin>>temp2->num;
            temp2->next=temp;
            head=temp2;

        }
        else
        {
            for (int i=1; i<elemcount-1; i++)
            {
                temp=temp->next;
            }
                    cout<<"enter data"<<endl;
        cin>>temp2->num;
            temp2->next=temp->next;
            temp->next=temp2;
        }
        n++;
    }
}
void fifth(int n,linked_list* &head,linked_list* &tail,linked_list* &temp,int position)
{
    linked_list* temp2=new linked_list;
    if (head==NULL)
        cout<<"List Empty"<<endl;
    else
    {
        cout<<"enter data you want to delete"<<endl;

        cin>>position;
        while (position<1||position>n)
        {
            cout<<"invalid position, type again"<<endl;
            cin>>position;
        }
        if (position!=1)
        {
            temp=head;
            for (int i=0; i<position-2; i++)
            {
                temp=temp->next;
            }
            if (position!=n)
            {temp2=temp->next;
                temp->next=temp->next->next;
            }
            else
            {
                temp->next=NULL;
                tail=temp;
            }
            temp=temp->next;
            delete temp2;
            n--;
        }
        else if(position==1)
        {
            temp=head;
            head=temp->next;
            n--;
        }
    }
}
void sixth(int n,linked_list* &head,linked_list* &tail,linked_list* &temp)
{
    if (head==NULL)
        cout<<"List Empty"<<endl;
    else
    {
        temp=head;
        while (head!=NULL)
        {
            head=temp->next;
            delete temp;
            temp=head;
        }
    }
}
void eight(int &n,linked_list* &head,linked_list* &tail,linked_list* &temp,int &elemcount,int &counter,int elem)
{
    elemcount=0;
    if (head==NULL)
        cout<<"List Empty"<<endl;
    else
    {
        linked_list* temp2=new linked_list;
       if (head==NULL)
        cout<<"List Empty"<<endl;
    else
    {
        cout<<"Enter element"<<endl;
        cin>>elem;
        temp=head;
        counter=0;
        while (temp!=NULL)
        {
            counter++;
            if (elem==temp->num)
            {
                elemcount=counter;
                break;
            }
            temp=temp->next;
        }
        if (elemcount==0)
        {
            cout<<"there is no such element"<<endl;
        }
        else if (elemcount==1)
        {
            temp=head;
            head=temp->next;
            delete temp;
            n--;

        }
        else if (elemcount<n)
        {
            temp=head;
            for (int i=1; i<elemcount-1; i++)
            {
                temp=temp->next;
            }
            temp2=temp->next;
            temp->next=temp->next->next;
            delete temp;
            n--;
        }
        else if (elemcount==n)
        {
            temp=head;
            for (int i=0;i<elemcount-2;i++)
                temp=temp->next;
            tail=temp;
            temp=temp->next;
            tail->next=NULL;
            delete temp;
            n--;
            }
    }
}}

int main()
{
    int n,choice,position,elem,elemcount=0,counter=0;
    linked_list* head=new linked_list;
    cout<<"Type the length of the Linked list"<<endl;
    cin>>n;
    while (n==0)
    {
        cout<<"invalid length try again"<<endl;
        cin>>n;
    }
    cout<<"Type first element of the list"<<endl;
    cin>>head->num;
    head->next=NULL;
    linked_list* temp,*tail;
    temp=head;
    tail=head;
    for (int i=0; i<n-1; i++)
    {
        temp=new linked_list;
        cout<<"type "<<i+2<<" data of the list"<<endl;
        cin>>temp->num;
        temp->next=NULL;
        tail->next=temp;
        tail=temp;
    }
    menu();
    cin>>choice;
    while (choice!=7)
    {
        if (choice==1)
        {
            sixth(n,head,tail,temp);
            first(n,head,tail,temp);
        }
        if (choice==2)
            second(n,head,tail,temp);
        if (choice==3)
        {
            third(n,head,tail,temp,position);
        }
        if (choice==4)
        {
            fourth(n,head,tail,temp,elemcount,counter,elem);
        }

        if (choice==5)
        {
            fifth(n,head,tail,temp,position);
        }

        if (choice==6)
        {
            sixth(n,head,tail,temp);
        }
        if (choice==7)
        {
            ;
        }
        if (choice==8)
        {
            eight(n,head,tail,temp,elemcount,counter,elem);
        }
        menu();
        cin>>choice;
    }

    return 0;
}
