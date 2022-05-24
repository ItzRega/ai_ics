#include <bits/stdc++.h>
using namespace std;



int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int cal_cost(vector <vector<int>> &initial, vector <vector<int>> &finall){
	int cost = 0;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++){
			if(initial[i][j] != finall[i][j])
				cost++;		
		}
	return cost;
}

void print(vector <vector<int>> &node, vector <vector<int>> &finall){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << node[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "cost : " << cal_cost(node, finall) << "\n";
	cout << "\n" << "\n";
}

bool ok(int x, int y){
	if(x < 0 || y < 0 || x >= 3 || y >= 3)
		return false;
	return true;
}

bool find_path(vector <vector<int>> &initial, vector <vector<int>> &finall){
				
	queue <vector <vector<int>>> q;
	q.push(initial);
	while(true){
		vector <vector<int>> node = q.front();		
		q.pop();
		print(node, finall);
		if(node == finall)
			break;
		int x, y;
		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j){
				if(!node[i][j]){
					x = i, y = j;
				}
			}
		}

		//cout << x << " " << y << "\n";
		int fin_cost = INT_MAX; 
		int ind = -1;
		cout << "row" << " " << "coloumn" << " " << "cost" << "\n";
		for(int i = 0; i < 4; ++i){
			int tx = x + dx[i];
			int ty = y + dy[i];
			if(ok(tx, ty)){
				swap(node[tx][ty], node[x][y]);
				int cost = cal_cost(node, finall);  
				cout << tx << " " << ty << " " << cost << "\n";
				if(cost < fin_cost){
					ind = i;
					fin_cost = cost;				
				}
				swap(node[tx][ty], node[x][y]);			
			}
		}
cout << "\n";
		int tx = x + dx[ind];
		int ty = y + dy[ind];
		swap(node[tx][ty], node[x][y]);
		q.push(node);
	}
}
 
int main()
{
	
	int N = 3;

	vector <vector<int>> initial(N, vector <int> (N, 0));
	vector <vector<int>> finall(N, vector <int> (N, 0));
	
	cout << "Enter initial matrix (3x3)" << "\n";
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			cin >> initial[i][j];
	
	cout << "Enter final matrix (3x3)" << "\n";
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			cin >> finall[i][j];	
	
	cout << "\n";

	find_path(initial, finall);
	
 
	return 0;
}

/*
	1 2 3
        5 6 0
        7 8 4
 
        1 2 3
        5 8 6
        0 7 4
*/
        
