#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define ff first
#define ss second
#define ll long long
#define mod 1000000007;
//using namespace __gnu_pbds;
using namespace std;
 
 bool isSafe(int row, int col, vector<vector<char>>& board){
 	int dupRow = row;
 	int dupCol = col;

 	while(row >=0 and col >=0){
 		if(board[row][col] == 'Q') return false;
 		row--;
 		col--;
 	}

 	col = dupCol;
 	row = dupRow;
 	while(col >= 0){
 		if(board[row][col] == 'Q') return false;
 		col--;
 	}

 	col = dupCol;
 	row = dupRow;
 	while(row<8 and col>=0){
 		if(board[row][col] == 'Q') return false;
 		row++;
 		col--;
 	}

 	return true;
 }



void solveNQueen(int col,vector<vector<char>>& board, ll& res){
	if(col == 8){
		res++;
	}
	for(int row = 0; row < 8; row++){
		if(isSafe(row,col,board) and board[row][col] == '.'){
			board[row][col] = 'Q';
			solveNQueen(col+1,board,res);
			board[row][col] = '.';
		}
	}
}

void solve(){
	vector<vector<char>> board(8,vector<char>(8));
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cin>>board[i][j];
		}
	}
	ll res = 0;
	solveNQueen(0,board,res);
	cout<<res<<endl;
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}