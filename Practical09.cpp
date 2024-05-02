#include<bits/stdc++.h>
using namespace std;

struct node {
    char word[20], mean[20];
    node *left;
    node *right;
    int ht;

    node() {
        left = NULL;
        right = NULL;
    }
};

class AVL
{
	public:

	node* create(node *root);
	node* insert(node *root,char word[],char mean[]);
	void display(node *);
	int height(node *);
	node* search(node* root,  char word[]);
	node* minValueNode(node* root);
	node* deleteNode(node* root,  char word[]);
    node* update(node* root, char word[], char newMean[]);
    node* balanceNode(node* root);
   	node* rotateright(node *);
   	node* rotateleft(node *);
    int BF(node *);
   	node* RR(node*);
   	node* LL(node*);
   	node* RL(node*);
   	node* LR(node*);
};

node* AVL::create(node *root)
{
	int n,i;
	char w[20],m[50];
	cout<<"\n Enter total number of words:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\n Enter word "<<i+1<<" : ";
		cin>>w;
		cout<<"\n Enter meaning : ";
		cin>>m;
		root=insert(root,w,m);

	}
	return root;
}


node* AVL::insert(node *root,char w[],char m[]) {
    if(root==NULL) {
        root=new node;
        strcpy(root->word,w);
        strcpy(root->mean,m);
        root->left=NULL;
        root->right=NULL;
        return root;
    } else {
        if(strcmp(w,root->word)>0) {
            root->right=insert(root->right,w,m);
            if(BF(root)==-2) {
                if(strcmp(w,root->word)>0)
                    root=RR(root);
                else
                    root=RL(root);
            }
        } else {
            if(strcmp(w,root->word)<0) {
                root->left=insert(root->left,w,m);
                if(BF(root)==2) {
                    if(strcmp(w,root->word)<0)
                        root=LL(root);
                    else
                        root=LR(root);
                }
            }
        }
    }
    root->ht=height(root);
    return root;
}



void AVL::display(node* root)
{
	if(root!=NULL)
	{
		display(root->left);
		cout<<"\n Node is:"<<root->word<<"-"<<root->mean;
		display(root->right);
	}
	
}


int AVL::height(node *root)
{
	if(root==NULL){
		return 0;
	}
	else{
		int r = height(root->right);
		int l = height(root->left);
		return (1+max(r,l));
	}
}

node* AVL::rotateright(node *x)
{
	node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}

node* AVL::rotateleft(node *x)
{
	node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}
int AVL::BF(node *root)
{
	int lh,rh;
	if(root==NULL)
		return(0);
	if(root->left==NULL)
		lh=0;
	else
		lh=1+root->left->ht;
	if(root->right==NULL)
	  rh=0;
	else
		rh=1+root->right->ht;
	int z=lh-rh;
	return(z);
}


node* AVL::RR(node *T)
{
	T=rotateleft(T);
	return(T);
}
node* AVL::LL(node *T)
{
	T=rotateright(T);
	return(T);
}
node* AVL::LR(node *T)
{
	T->left=rotateleft(T->left);
	T=rotateright(T);
	return(T);
}
node* AVL::RL(node *T)
{
	T->right=rotateright(T->right);
	T=rotateleft(T);
	return(T);
}

node* AVL::search(node* root, char word[]) 
{
    if (root == NULL || strcmp(root->word, word) == 0)
        return root;

    if (strcmp(root->word, word) < 0)
        return search(root->right, word);

    return search(root->left, word);
}


node* AVL::update(node* root, char word[], char newMean[]) {
    root = deleteNode(root, word); 
    root = insert(root, word, newMean); 
    return root;
}

node *AVL::minValueNode(node *root) {
    node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}

node* AVL::balanceNode(node* root) {
    int balance = BF(root);

    if (balance > 1 && BF(root->left) >= 0)
        return LL(root);

    if (balance > 1 && BF(root->left) < 0)
        return LR(root);

    if (balance < -1 && BF(root->right) <= 0)
        return RR(root);

    if (balance < -1 && BF(root->right) > 0)
        return RL(root);

    return root;
}


node* AVL:: deleteNode(node * root,char k[20])
{
	node *temp;
 	if(root == NULL)
 	{
  		cout<<"\nElement No Found";
  		return root;
 	}
 	if (strcmp(k,root->word) < 0)
 	{
  		root->left = deleteNode(root->left, k);
  		return root;
 	}
 	if (strcmp(k,root->word) > 0)
 	{
   		root->right = deleteNode(root->right, k);
   		return root;
 	}
 	if (root->right==NULL&&root->left==NULL)
 	{
  		temp = root;
  		delete temp;
  		return NULL;
  	}
  	if(root->right==NULL)
  	{
  		temp = root;
  		root = root->left;
  		delete temp;
  		return root;
  	}
  	else if(root->left==NULL)
  	{
  		temp = root;
  		root = root->right;
  		delete temp;
  		return root;
  	}
  	temp = minValueNode(root->right);
  	strcpy(root->word,temp->word);
  	root->right = deleteNode(root->right, temp->word);
  	return root;

}


int main()
{
	int ch;
	char choice;
	AVL obj;
	node *root;
	root=NULL;
	char w[20],m[50],deleteWord[20],searchWord[20],updateWord[20],updateMean[20];


	do{
		cout<<"\n\n **********MENU**********";
		cout<<"\n1.Create \n2.Insert \n3.Delete\n4.Display \n5. Search \n6. Update \n7.Exit";
		cout<<"\n Enter your choice:";
		cin>>ch;

		node *searchedNode = NULL;

		switch(ch)
		{
			case 1: 
				root=obj.create(root);
				break;
			case 2: 
				cout<<"\n Enter word:";
		        cin>>w;
		        cout<<"\n Enter meaning";
		        cin>>m;
		        root=obj.insert(root,w,m);
		        break;
			case 3: 
    			cout << "\nEnter word to delete: ";
    			cin >> deleteWord;
    			root = obj.deleteNode(root, deleteWord);
    			cout << "\nTree after deletion: ";
   	 			obj.display(root);
    			break;
			case 4: 
				obj.display(root);
				break;
			case 5:
				cout<<"Enter the word to search :";
				cin>>searchWord;
				searchedNode = obj.search(root, searchWord);
				if(searchedNode) cout<<"\nMeaning of "<<searchWord<<" is "<<searchedNode->mean;
				else cout<<"\nWord not found ";
				break;
			case 6:
				cout<<"Enter the word to update :";
				cin>>updateWord;
				cout<<"Enter the new meaning :";
				cin>>updateMean;
				root=obj.update(root, updateWord, updateMean);
				cout<<"Tree after update :"<<endl;
				obj.display(root);
				break;
			case 7: 
				break;
			default:
				cout<<"\n Invalid choice!";
		}
		cout<<"Do you want to continue(y/n) ? :";
		cin>>choice;
	}while(choice=='y');

	return 0;
}
