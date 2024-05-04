#include<iostream>
#define max 10
using namespace std;
class telephone
{
	long int tn[max];
	int count;
	public:
		int hashfun(long int);
		void insert();
		void display();
		telephone()
		{
			for(int i=0;i<max;i++)
			{
				tn[i]=0;
			}
			count=0;
		}
};

int telephone::hashfun(long int num)
{
	return(num%10);
}

void telephone::insert()
{
	int ind;
	long int num;
	cout<<"Enter telephone number:"<<endl;
	cin>>num;
	ind=hashfun(num);
	while(count<max&&ind<max)
	{
		if(tn[ind]==0)
			{
				tn[ind]=num;
				count++;
				break;
			}
			else
			{
				if(ind==max-1)
					ind=0;
				else
					ind++;
			}
	}
	if(count==max)
		cout<<"Hash table overflow!!";
}

void telephone::display()
{
	for(int i=0;i<max;i++)
	{
		cout<<i<<" - "<<tn[i]<<endl;
	}
}

int main()
{
	telephone t;
	int ch;
	char ans;
	do{
		cout<<"Enter choice: 1.Insert  2.Display"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:t.insert();
					break;
			case 2:t.display();
					break;
			default:
				cout<<"Invalid choice!!";
		}
		cout<<"Do you want to continue? (1/0)";
		cin>>ans;
	}while(ans=='1');
	return 0;
}