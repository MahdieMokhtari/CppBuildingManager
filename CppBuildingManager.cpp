#include <iostream>
#include <string.h>
using namespace std;
struct date
{
	int y , d , m;
};
enum type {  residential=0 , commercial=1 , official=2  };
struct center
{
	char name [20];
	char address [20];
	date build;
	type user;
	int person;
	float pricemeter;
	int unit;
};
void print (center );
int main ()
{
	center a[10];
	int n,m;
	cin>>n;
	for (int i=0 ; i<n ; i++)
	{
		cin>>a[i].name>>a[i].address>>a[i].build.y>>a[i].build.m>>a[i].build.d;
		cout<<"enter 0 for residential, 1 for commercial, 2 for official : ";
		cin>>m;
		switch (m)
		{
			case 0 :
				a[i].user=residential;
					break;
			case 1 :
				a[i].user=commercial;
					break;
			case 2 :
				a[i].user=official;
					break;
			default :
				cout<<"invalid input... ";
					break;
		}
		cin>>a[i].person>>a[i].pricemeter>>a[i].unit;
	}
	
	int sum=0;
	for (int i=0 ; i<n ; i++)
		if (a[i].person > 500 && a[i].user == commercial)
			sum++;
	cout<<"number of person>500 & commercial : "<<sum<<'\n';
	
	center oldest=a[0];
	for (int i=0 ; i<n ; i++)
		if (a[i].build.y<oldest.build.y)
			oldest = a[i];
		else if (a[i].build.y==oldest.build.y && a[i].build.m<oldest.build.m)
			oldest = a[i];
		else if (a[i].build.y==oldest.build.y && a[i].build.m==oldest.build.m && a[i].build.d<oldest.build.d)
			oldest = a[i];
	cout<<"oldest is : "<<'\n';
	print (oldest);
	
	for (int i=0 ; i<n ; i++)
	print (a[i]);
	
	int sum2=0;
	for (int i=0 ; i<n ; i++)
		if (a[i].user==residential && a[i].person>1000 && strlen(a[i].name)>10)
			sum2++;
	cout<<'\n'<<"number of user residential & person>1000 & char>10 : "<<sum2<<'\n';			
	
}
void print (center a)
{
	cout<<'\n'<<a.name<<'\t'<<a.address<<'\n';
	cout<<a.build.y<<"/"<<a.build.m<<"/"<<a.build.d<<'\n';
	cout<<a.user<<'\t'<<a.person<<'\t'<<a.pricemeter<<'\t'<<a.unit<<'\n';
}
