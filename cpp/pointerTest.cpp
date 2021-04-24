#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *next;
};
struct node *head;
void Insert(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->next = head;
    head = temp;
}
void insertAnyPosition(int n,int data)
{
    node *temp1 = new node();
    temp1 ->data = data;
    temp1 ->next = NULL;
    if(n == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    node *temp2 = head;
    for(int i = 0;i<n-2;i++) temp2 = temp2->next;
    temp1->next = temp2->next;
    temp2->next = temp1;
}
void Delete(int n)
{
    node *temp1 = head;
    if(n==1)
    {
        head = temp1->next;
        free(temp1);
    }
    for(int i = 0;i<n-2;i++) temp1 = temp1->next;
    node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}
void Print()
{
    node *temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void ReversePointer()
{
    node *current,*prev,*next;
    current = head;
    prev = NULL;
    while(current!=NULL)
    {
         next = current->next;
         current->next = prev;
         prev = current;
         current = next;
    }
    head = prev;
}
void ReverseRecursive(node *p)
{
    if(p->next == NULL)
    {
        head = p;
        return;
    }
    ReverseRecursive(p->next);
    node *q=p->next;
    q->next = p;
    p->next =NULL;
}

int main()
{
    head = NULL;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int data;
        cin >> data;
        Insert(data);
//        Print();
//        cout << endl;
    }
    Print();
    insertAnyPosition(4,34);
    Print();
    insertAnyPosition(1,33);
    Print();
    insertAnyPosition(2,14);
    Print();
    insertAnyPosition(2,44);
    ReverseRecursive(head);
    Print();
    ReversePointer();
    Print();


}
