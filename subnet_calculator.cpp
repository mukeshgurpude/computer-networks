#include <iostream>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;

void check(int arr[],int cidr,int cls,int ans2[],int ans3[],int ans4,int ans5)
{
	int flag1=1,flag2=1; //flag1 = subnet mass and flag2 = ip address 
	int arcidr[]={0,128,192,224,240,248,252,254},i;
	int x[4],y[4],z;    //x = subnet mass and y = Ip address
	int subnet,hosts;
	
	for(i=0;i<4;i++)
	{
		x[i]=0;
		y[i]=0;
		if(i<=cls)
		{
			x[i]=255;
			y[i]=arr[i];
		}else if(i==cls+1)
		{
			z=cidr%8;
			x[i]=arcidr[z];	
		}
		
		if(x[i]!=ans2[i])
		flag1=0;
		if(y[i]!=ans3[i])
		flag2=0;
	}
	
	subnet=pow(2,z);
	z=32-cidr;
	hosts=pow(2,z);
	
	if(flag1==1)
	cout<<"\nyour subnet mass is correct.........";
	else{
		cout<<"\nCorrect subnet mass is ";
		for(i=0;i<4;i++)
		cout<<x[i]<<" ";
	}
	if(flag2==1)
	cout<<"\nyour IP address is correct.........";
	else{
		cout<<"\nCorrect IP address is ";
		for(i=0;i<4;i++)
		cout<<y[i]<<" ";
	}
	if(subnet==ans4)
	cout<<"\nyour value for subnets are correct.........";
	else
	cout<<"\nCorrect number of subnets are "<<subnet;
	
	if(hosts==ans5)
	cout<<"\nyour value for hosts are correct.........";
	else
	cout<<"\nCorrect number of Hosts are "<<hosts;
	
}

int main()
{
	srand((unsigned) time(0));
	int arr[4],cidr,ans2[4],ans3[4],ans4,ans5; //ans2 = subnet mass, ans3 = ip address, ans4 = subnets, ans5 = hosts
	int i,intcls;
	char ans1,clas; //ans1= for class
	
	cout<<"Question : ";
	for(i=0;i<4;i++)
	{
		if(i==0)
		arr[i]=rand()%224;
		else
		arr[i]=rand()%254+1;
		cout<<arr[i];
		if(i==3)
		break;
		cout<<".";
	}
	
	if(arr[0]<128)
	{
		clas='A';
		intcls=0;
		cidr=rand()%8+8;
	}else if(arr[0]>=128 && arr[0]<192)
	{
		clas='B';
		intcls=1;
		cidr=rand()%8+16;
	}else if(arr[0]>=192 && arr[0]<224)
	{
		clas='C';
		intcls=2;
		cidr=rand()%8+24;
	}
	cout<<"/"<<cidr; 
	
	
	cout<<"\n\nEnter the class for given IPv4 (A/B/C): ";
	cin>>ans1;
	
	if(clas==ans1)
	{
		cout<<"Enter the IP address (Note: make space between no.) : ";
		for(i=0;i<4;i++)
	    {
			cin>>ans3[i];
		}
		cout<<"Enter it's Subnet mass (Note: make space between no.) = ";
		for(i=0;i<4;i++)
		{
			cin>>ans2[i];
		}
		cout<<"Enter totle subnets made here = ";
		cin>>ans4;
		cout<<"Enter number of hosts in one subnet = ";
		cin>>ans5;	
	}else
	cout<<"\nInput Class is wrong ..... answer is Class = "<<clas;
	
	check(arr,cidr,intcls,ans2,ans3,ans4,ans5);
    return 0;	
}
