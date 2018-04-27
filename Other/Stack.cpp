#include<bits/stdc++.h>

using namespace std;

int size;
int top=-1;

vector<int>s;               ///Dynamic Array for flexibility

void Top();
void push();
void pop();                  ///Function Initializer
void show();
void menu();
void choice(int n);

int main()                   ///Main Function
{
    cout<<"Stack Size : ";
    cin>>size;               ///Getting Stack Size

    menu();                  ///Menu Function Calling

    int c;                   ///Choice Variable

    while(1)
    {
        cout<<"Choice : ";
        cin>>c;
        cout<<endl;
        if(c==6)
        {
            cout<<"Terminating Program\n";
            break;
        }

        choice(c);
    }
    return 0;
}

void push()                ///Push Function
{
    if(top==size-1)
    {
        cout<<"Stack Full\n\n";
        return;
    }

    int v;
    cout<<"Insert Value to push: ";
    cin>>v;
    cout<<endl;
    top++;
    s.push_back(v);          ///Inserting elements in stack
}

void pop()                   ///Pop Function
{
    if(top==-1)
    {
        cout<<"Stack Empty\n\n";
        return;
    }
    top--;
    s.pop_back();
}

void show()                      ///Stack Print Function
{
    if(top==-1)
    {
        cout<<"Stack Empty\n\n";
        return;
    }
    cout<<"Stack : ";
    for(int i=0;i<=top;i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl<<endl;
}

void menu()                         ///Menu Function
{
    cout<<"\n***** CHOICE LIST *****\n\n";
    cout<<"     1 for Push\n\n";
    cout<<"     2 for Pop\n\n";
    cout<<"     3 for Resize\n\n";
    cout<<"     4 for Top\n\n";
    cout<<"     5 for Show\n\n";
    cout<<"     6 for Exit\n\n";
    cout<<"***********************\n\n";
}

void Top()                        ///TOP function
{
    if(top==-1)
    {
        cout<<"Stack Empty\n\n";
        return ;
    }
    cout<<"Top : "<<s[top]<<endl<<endl;
}

void choice(int n)                /// Choice Function
{
    if(n==1)
        push();

    else if(n==2)
        pop();

    else if(n==3)
    {
        cout<<"New size: ";
        cin>>size;
        cout<<endl;
    }

    else if(n==4)
        Top();

    else if (n==5)
        show();
}

