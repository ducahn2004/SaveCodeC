#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles);
vector<vector<int>> create_South_To_North(int n, int r_q, int c_q);
vector<vector<int>> create_West_To_East (int n, int r_q, int c_q);
vector<vector<int>> creat_SouthEast_To_NorthWest(int n, int r_q, int c_q);
vector<vector<int>> creat_SouthWest_To_NorthEast(int n, int r_q, int c_q);
int checkIndex(vector<vector<int>>input, int r, int c);
int checkSquareAvailable(vector<vector<int>>input,  int r_q, int c_q, vector<vector<int>>obstacles);
vector<vector<int>> clearObsacles(vector<vector<int>> obstacles, int r_q, int c_q , int index , int n);
int main(){
	int n ,k;
	//n is number of col or row 
	// k is number of obstacles
	cin >> n >> k;

	int r_q = 3 ,c_q = 2;
	cin >> r_q >> c_q;

	vector<vector<int>> obstacles;
	for(int i = 1; i <= k; i++){
		int r,c;
		cin >> r >> c;
		vector<int>tmp{r,c};
		obstacles.push_back(tmp);
	}
	cout << queensAttack(n,k,r_q,c_q,obstacles);

	code check 
	cout << "West to East" << endl;
	vector<vector<int>>result = create_West_To_East(n,r_q,c_q);
	for(int i = 0; i < result.size(); i++){
		cout <<"(" << result[i][0] <<" " << result[i][1] <<")" << endl;
	}
	cout << "South_To_North" << endl;
	vector<vector<int>>result1 = create_South_To_North(n,r_q,c_q);
	for(int i = 0; i < result1.size(); i++){
		cout <<"(" << result1[i][0] <<" " << result1[i][1] <<")" << endl;
	}
	cout << "SouthEast_To_NorthWest" << endl;
	vector<vector<int>>result2 = creat_SouthEast_To_NorthWest(n,r_q,c_q);
	for(int i = 0; i < result2.size(); i++){
		cout <<"(" << result2[i][0] <<" " << result2[i][1] <<")" << endl;
	}
	cout << "SouthWest_To_NorthEast" << endl;
	vector<vector<int>>result3 = creat_SouthWest_To_NorthEast(n,r_q,c_q);
	for(int i = 0; i < result3.size(); i++){
		cout <<"(" << result3[i][0] <<" " << result3[i][1] <<")" << endl;
	}

}	

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
	int result = 0;
	
	vector<vector<int>>West_To_East = create_West_To_East(n,r_q,c_q);
	vector<vector<int>>South_To_North = create_South_To_North(n,r_q,c_q);
	vector<vector<int>>SouthEast_To_NorthWest = creat_SouthEast_To_NorthWest(n,r_q,c_q);
	vector<vector<int>>SouthWest_To_NorthEast = creat_SouthWest_To_NorthEast(n,r_q,c_q);
	
	vector<vector<int>>obstacles_West_To_East = clearObsacles(obstacles, r_q, c_q, 1 , n);
	vector<vector<int>>obstacles_South_To_North = clearObsacles(obstacles, r_q, c_q, 2 , n);
	vector<vector<int>>obstacles_SouthEast_To_NorthWest = clearObsacles(obstacles, r_q, c_q, 3 , n);
	vector<vector<int>>obstacles_SouthWest_To_NorthEast = clearObsacles(obstacles, r_q, c_q, 4 , n);


	result +=  checkSquareAvailable(West_To_East, r_q, c_q, obstacles_West_To_East);
	//cout << "West_To_East " <<  checkSquareAvailable(West_To_East, r_q, c_q, obstacles) << endl;
	result +=  checkSquareAvailable(South_To_North, r_q, c_q, obstacles_South_To_North);
	//cout << "South_To_North " <<  checkSquareAvailable(South_To_North, r_q, c_q, obstacles)<<endl;
	result +=  checkSquareAvailable(SouthEast_To_NorthWest, r_q, c_q, obstacles_SouthEast_To_NorthWest);
	//cout << "SouthEast_To_NorthWest " <<  checkSquareAvailable(SouthEast_To_NorthWest, r_q, c_q, obstacles) << endl;
	result +=  checkSquareAvailable(SouthWest_To_NorthEast, r_q, c_q, obstacles_SouthWest_To_NorthEast) ;
	//cout << "SouthWest_To_NorthEast " <<  checkSquareAvailable(SouthWest_To_NorthEast, r_q, c_q, obstacles) << endl;

	
	return result;
}
vector<vector<int>> clearObsacles(vector<vector<int>> obstacles, int r_q, int c_q , int index , int n){
	vector<vector<int>> result;
	for(int i = 0; i < obstacles.size(); i++){
		if(index == 1 && obstacles[i][0] == r_q && obstacles[i][0] <= n && obstacles[i][1] <= n){
			result.push_back({obstacles[i][0],obstacles[i][1]});
		}
		if(index == 2 && obstacles[i][1] == c_q && obstacles[i][0] <= n && obstacles[i][1] <= n){
			result.push_back({obstacles[i][0],obstacles[i][1]});
		}
		if(index == 3 && obstacles[i][0] + obstacles[i][1] == c_q + r_q && obstacles[i][0] <= n && obstacles[i][1] <= n){
			result.push_back({obstacles[i][0],obstacles[i][1]});
		}
		if(index == 4 && ((obstacles[i][0] - obstacles[i][1]) == (r_q - c_q))&& obstacles[i][0] <= n && obstacles[i][1] <= n){
			result.push_back({obstacles[i][0],obstacles[i][1]});
		}
	}

	return result;
}
int checkIndex(vector<vector<int>>input, int r, int c){
	int result = - 1;
	for(int i = 0; i < input.size(); i++){
		if(input[i][0] == r && input[i][1] == c){
			result = i;
			break;
		}
	}
	return result;
}
int checkSquareAvailable(vector<vector<int>>input, int r_q, int c_q, vector<vector<int>>obstacles){
	
	for(int i = 0; i < obstacles.size();i++){
		int indexQueen =  checkIndex(input, r_q ,c_q);
		int indexObstacle = checkIndex(input, obstacles[i][0],obstacles[i][1]);
		if(indexQueen > indexObstacle){
			input.erase(input.begin(), input.begin() + indexObstacle + 1);
		}
		else{
			input.erase(input.begin() + indexObstacle, input.end());
		}		
	}	
	
	return input.size() - 1;
}
vector<vector<int>> create_South_To_North(int n, int r_q, int c_q){
	vector<vector<int>> result;
	for(int i = 1; i <= n; i++){
		// result[index].push_back(i);
		// result[index].push_back(c_q);
		result.push_back({i,c_q});
	}
	return result;
}
vector<vector<int>> create_West_To_East (int n, int r_q, int c_q){
	vector<vector<int>> result;
	for(int i = 1; i <=  n; i++){
		result.push_back({r_q,i});
	}
	return result;
}
vector<vector<int>> creat_SouthEast_To_NorthWest(int n, int r_q, int c_q){
	vector<vector<int>> result;
	if(c_q + r_q > n){
		for(int i = c_q + r_q - n; i <= n; i++){
			// result[index].push_back(i);
			// result[index].push_back(c_q + r_q - i);
			result.push_back({i,c_q + r_q - i});
		}
	}
	else{
		for(int i = 1; i < c_q + r_q; i++){
			// result[index].push_back(i);
			// result[index].push_back(c_q + r_q - i);
			result.push_back({i,c_q + r_q - i});

		}
	}
	return result;
}
vector<vector<int>> creat_SouthWest_To_NorthEast(int n, int r_q, int c_q){
	vector<vector<int>> result;
	if(c_q > r_q){
		for(int i = 1; i <= n - (c_q - r_q) ; i++){
			// result[i].push_back(i);
			// result[i].push_back(c_q - r_q + i);
			result.push_back({i,c_q - r_q + i});

		}
	}
	else if(c_q < r_q){
		for(int i = 1; i <= n - (r_q - c_q); i++){
			result.push_back({r_q - c_q + i,i});
		}
	}
	else{
		for(int i = 1; i <= n; i++){
			result.push_back({i,i});
		}
	}
	return result;
}	