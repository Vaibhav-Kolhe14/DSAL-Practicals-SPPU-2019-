#include<bits/stdc++.h>
using namespace std;
#define max 20

struct node{
    char data;
    struct node* left;
    struct node* right;
};

class cstack{
    int top;
    node *exp[max];
    public:
    cstack()
    {
        top=-1;
    }
    int isEmpty()
    {
        if(top==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int isFull()
    {
        if(top==max-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void push(node *t)
    {
        if(isFull()==1)
        {
            cout<<"Stack is full"<<endl;
        }
        else
        {
            top++;
            exp[top]=t;
        }
    }
    struct node *pop()
    {
        if(isEmpty()==1)
        {
            cout<<"stack is empty"<<endl;
        }
        else
        {
            node *t;
            t=exp[top];
            top--;
            return t;
        }
    }
};

class expTree{
    struct node *top;
    public:
    struct node *expression(string);
    void display(node*);
    void postorder(node*);
    void del(node*);
};

struct node* expTree::expression(string prefix)
{
    int len;
    len=prefix.length();
    cstack s1,s2;
    for(int i=len;i >= 0;i--)
    {
        top=new node;
        top->left=NULL;
        top->right=NULL;

        if(isalpha(prefix[i]))
        {
            top->data=prefix[i];
            s1.push(top);
        }
        else
        {
            if(prefix[i]=='+' || prefix[i]=='-' || prefix[i]=='/' || prefix[i]=='*')
            {
                node *t1,*t2;
                t1=s1.pop();
                t2=s1.pop();
                top->data=prefix[i];
                top->left=t1;
                top->right=t2;
                s1.push(top);
            }
        }
    }
    return top;
}

void expTree::postorder(node *top)
{
    cstack s1,s2;
    node *t=top;
    s1.push(t);
    while(!s1.isEmpty())
    {
        t=s1.pop();
        s2.push(t);
        if(t->left != NULL)
        {
            s1.push(t->left);
        }
        if(t->right != NULL)
        {
            s1.push(t->right);
        }
    }

    while(s2.isEmpty() != 1)
    {
        node *temp2;
        temp2=s2.pop();
        cout<<temp2->data;
    }
    cout<<endl;
}

void expTree::display(node *root)
{
    if(root != NULL)
    {
        display(root->left);
        display(root->right);
        cout<<root->data;
    }
}

void expTree::del(node *t)
{
    if(t==NULL)
    {
        return;
    }
    else
    {
        del(t->left);
        del(t->right);
        delete(t);
    }
}

int main()
{
    string exp;
    cout<<"Enter :";
    cin>>exp;
    expTree e1;
    struct node *top=NULL;

    top=e1.expression(exp);
    e1.postorder(top);
    e1.display(top);
    e1.del(top);
    return 0;
}