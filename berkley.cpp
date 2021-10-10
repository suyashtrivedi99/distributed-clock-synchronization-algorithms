#include <bits/stdc++.h>
#include<cstdlib>
#include<ctime>

using namespace std;

pair<int,int> nodes[100];
int store[100];

pair<int,int> generateTime()
{
	int hr = rand()%24;
	int min = rand()%60;
	return make_pair(hr,min);
}

void printTime(pair<int,int> t)
{
	if(t.first < 10)cout<<0;
	cout<<t.first<<":";
	if(t.second < 10)cout<<0;
	cout<<t.second<<'\n';
}

int convFromTime(pair<int,int> t)
{
	return ((t.first*60) + t.second);
}

pair<int,int> convToTime(int t)
{
	int hr = t/60;
	int min = t%60;
	return make_pair(hr,min);
}

int main()
{
	srand(time(0));
	cout<<"Enter number of nodes\n";
	int n; cin>>n;	
	
	for(int i = 0; i < n; i++)
	{
		auto p = generateTime();
		nodes[i] = p;
		store[i] = convFromTime(nodes[i]);		
		
		cout<<"Time at Node #"<<i<<": ";
		printTime(nodes[i]);
	}
	
	cout<<"\nChoose ID of master node\n";
	int id; cin>>id;

	int sum = 0;
	cout<<'\n';

	// Calculating offsets of all times with respect to master node
	for(int i = 0; i < n; i++)
	{
		int cur = store[i] - convFromTime(nodes[id]);
		auto curTime = convToTime(abs(cur));
		cout<<"Time Offset of Node #"<<i<<" from Master Node: ";
		
		if(cur < 0)cout<<"-";
		printTime(curTime);

		sum += store[i];	
	}
	
	// Calculating average time
	int avg = sum/n;
	auto avgTime = convToTime(abs(avg));
	cout<<"\nAverage Time of all nodes: ";
	printTime(avgTime);
	
	cout<<'\n';

	// Calculating all synchronization values
	for(int i = 0; i < n; i++)
	{
		int cur = avg - store[i];
		bool sign = (cur >= 0)?1:0;
		cur = abs(cur);
		auto curTime = convToTime(cur);

		cout<<"Node #"<<i<<" needs to ";

		if(sign) cout<<"increase its time by ";
		else cout<<"decrease its time by ";
		printTime(curTime); 				
	}

	return 0;	
}
