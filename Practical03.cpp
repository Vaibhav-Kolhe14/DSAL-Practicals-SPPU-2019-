#include<bits/stdc++.h>
using namespace std;

struct node{
    string label;
    int count;
    node *child[10];
};

class book{
    node *root;
    public:
    book(){
        root=NULL;
    }
    void create();
    void display();
};

void book::create()
{
    root = new node;
    cout << "Enter the name of book : ";
    cin >> root->label;
    cout << "Enter no. of chapters : ";
    cin >> root->count;
    for(int i = 0 ; i < root->count ; i++)
    {
        root->child[i] = new node;
        cout << "Enter name of chapter "<< i+1 <<" : ";
        cin >> root->child[i]->label;
        cout << "Enter no. of sections : ";
        cin >> root->child[i]->count;

        for(int j = 0; j < root->child[i]->count; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "Enter name of section " << j+1 <<" : ";
            cin >> root->child[i]->child[j]->label;
            cout << "Enter no. of subsections : ";
            cin >> root->child[i]->child[j]->count;

            for(int k = 0; k < root->child[i]->child[j]->count; k++)
            {
                root->child[i]->child[j]->child[k] = new node;
                cout << "Enter name of subsections "<< k+1 <<" : ";
                cin >> root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}

void book::display()
{
    if(root == NULL)
    {
        cout << "tree is empty ! "<< endl;
    }
    else
    {
        cout << "book name :"<< root->label << endl;
        for(int i = 0; i < root->count; i++)
        {
            cout << i+1 << ". " << root->child[i]->label << endl;
           // cout<<'\t';

            for(int j = 0;j < root->child[i]->count; j++)
            {
                cout << "\t" << "[" << j+1 <<"]"<<". "<<root->child[i]->child[j]->label<<endl;
               // cout << "\t\t";

                for(int k = 0; k < root->child[i]->child[j]->count; k++)
                {
                    cout << "\t\t" << "(" << k+1 << ")" << root->child[i]->child[j]->child[k]->label << endl;
                }
            }
           // cout << endl;
        }
        cout << endl;
    }
}


int main()
{
    book obj;
    obj.create();
    obj.display();
    return 0;
}