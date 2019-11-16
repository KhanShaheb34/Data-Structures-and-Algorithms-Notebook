#include <bits/stdc++.h>
using  namespace std;

int main()
{
	int ara[]={1,2,3,4,5,7,8};
	int lis[]={1,1,1,1,1,1,1};
	int n=7;
	int max=1;
	int lastindex=n-1;
	for(int i=1;i<n;i++)
	{		
		cout<<"Step "<<i<<": ";
		for(int i=0;i<n;i++)
			cout<<lis[i]<<" ";
		cout<<endl;
		if(ara[i]%2==1)
			continue;
		for(int j=0;j<i;j++)
		{	
			if(ara[j]%2==1)
				continue;
			if(ara[j]<ara[i] && lis[j]+1>lis[i])
			{
				lis[i]=lis[j]+1;
				if(lis[i]>max){
					max=lis[i];
					lastindex=i;
				}
			}
		}
	}
	cout<<"Step "<<n<<": ";
	for(int i=0;i<n;i++)
			cout<<lis[i]<<" ";
		cout<<endl;

	cout<<endl;
	cout<<"LIS ARRAY: ";
	for(int i=0;i<n;i++)
		cout<<lis[i]<<" ";
	cout<<endl;
	cout<<endl;

	cout<<"LIS: ";
	cout<<max<<endl;
	vector<int>vec;
	int i=lastindex;
	while(max>0)
	{
		if(lis[i]==max &&ara[i]%2==0)
		{
			max--;
			vec.push_back(ara[i]);
			
		}
		i--;
	}
	for(int i=vec.size()-1;i>=0;i--)
		cout<<vec[i]<<" ";
	cout<<endl;

	return 0;
}
