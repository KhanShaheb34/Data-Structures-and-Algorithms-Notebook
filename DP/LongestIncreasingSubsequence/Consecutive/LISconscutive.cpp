#include <bits/stdc++.h>
using  namespace std;

int main()
{
	int ara[]={10,22,9,11,33,12};
	int lis[]={1,1,1,1,1,1};
	int n=6;
	int max=1;
	int lastindex=n-1;
	for(int i=1;i<n;i++)
	{	
		cout<<"Step "<<i<<": ";
		for(int i=0;i<n;i++)
			cout<<lis[i]<<" ";
		cout<<endl;
		for(int j=0;j<i;j++)
		{
			if(ara[j]+1==ara[i] && lis[j]+1>lis[i])
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
	int before=i;
	while(max>0)
	{	
		//int before=;
		if(lis[i]==max && (ara[before]==ara[i]+1)||(i==before))
		{
			max--;
			vec.push_back(ara[i]);
			before=i;
			
		}
		i--;
	}
	for(int i=vec.size()-1;i>=0;i--)
		cout<<vec[i]<<" ";
	cout<<endl;

	return 0;
}
