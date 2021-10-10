#include <bits/stdc++.h>
#include<cstdlib>
#include<ctime>

using namespace std;

int genRandom(int l, int r)
{
	int dif = r-l+1;
	int ans = l+(rand()%dif);
	return ans;
}

int main()
{
	srand(time(0));
	cout<<"Enter the number of nodes: ";
	int n; cin>>n;

	//choosing a random node to initiate election algorithm
	int chose = genRandom(0, n-1);
	cout<<"Node #"<<chose<<" has detected failure of coordinator!\n\n";

	//If highest priority node is the chosen node, finalize the coordinator
	if(chose == n-1)
	{
		cout<<"Node #"<<chose<<" has highest priority.\n";
		cout<<"Hence it is chosen as the new coordinator!\n";
		cout<<"Sending victory message to all nodes from Node#"<<chose<<"!\n";
		return 0;
	}

	bool check = 0;

	while(!check)
	{
		cout<<"Sending election message to all nodes above Node#"<<chose<<"!\n";
		
		//choosing a higher lower limit value for better simulation
		int low = chose/5;
		int newchose = genRandom(chose-low, n-1);

		//No upper node has replied, so end the process
		if(newchose <= chose)
		{
			check = 1;
			continue;
		}

		cout<<"Received answer from an upper node! (Node#"<<newchose<<")\n";
		chose = newchose;
		cout<<"\n";
	}

	if(chose == n-1)
	{
		cout<<"No node exists above Node #"<<chose<<"!\n";
		cout<<"Hence it is chosen as the new coordinator!\n";
	}

	else
	{
		cout<<"No node above Node#"<<chose<<" has answered!\n";
		cout<<"So, Node#"<<chose<<" has been selected as the new coordinator!\n";
	}

	cout<<"\nSending victory message to all nodes from Node#"<<chose<<"!\n";

	return 0;
}