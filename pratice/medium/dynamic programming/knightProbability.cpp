/*
On an NxN chessboard, 
a knight starts at the r-th row and c-th column 
and attempts to make exactly K moves. 
The rows and columns are 0 indexed, 
so the top-left square is (0, 0), 
and the bottom-right square is (N-1, N-1).

A chess knight has 8 possible moves it can make, 
as illustrated below. Each move is two squares in a cardinal direction, 
then one square in an orthogonal direction.

Each time the knight is to move, 
it chooses one of eight possible moves uniformly at random 
(even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly K moves 
or has moved off the chessboard. 
Return the probability that the knight remains on the board 
after it has stopped moving.
*/
class Solution {
public:
	double A(int N, int r, int c){
		double num = 0.0;
		if(0 <= r-1 and r-1 < N){
			if(0 <= c-2 and c-2 < N){
				num += 1.0;
			}
			if(0 <= c+2 and c+2 < N){
				num += 1.0;
			}
		}
		if(0 <= r+1 and r+1 < N){
			if(0 <= c-2 and c-2 < N){
				num += 1.0;
			}
			if(0 <= c+2 and c+2 < N){
				num += 1.0;
			}
		}
		if(0 <= r-2 and r-2 < N){
			if(0 <= c-1 and c-1 < N){
				num += 1.0;
			}
			if(0 <= c+1 and c+1 < N){
				num += 1.0;
			}
		}
		if(0 <= r+2 and r+2 < N){
			if(0 <= c-1 and c-1 < N){
				num += 1.0;
			}
			if(0 <= c+1 and c+1 < N){
				num += 1.0;
			}
		}
		return num/8.0;
	}

    double knightProbability(int N, int K, int r, int c) {
    	if(K == 0)
        	return 1.0;

        double p = 1.0/8.0;
        //curr pos: (i,j)
        //next pos: (i-2,j+1),(i-2,j-1),(i+2,j+1),(i+2,j-1),(i-1,j+2),(i-1,j-2),(i+1,j+2),(i+1,j-2)
        double dp[K][N][N];
        memset(dp,0.0,sizeof(dp));
        
        for(int i = 0; i < N; i++){
        	for(int j = 0; j < N; j++){
        		dp[0][i][j] = A(N,i,j);
        	}
        }
        for(int k = 1; k < K; k++){
        	for(int i = 0; i < N; i++){
        		for(int j = 0; j < N; j++){
        			if(0 <= i-1 and i-1 < N){
						if(0 <= j-2 and j-2 < N)dp[k][i][j] += p*dp[k-1][i-1][j-2];
						if(0 <= j+2 and j+2 < N)dp[k][i][j] += p*dp[k-1][i-1][j+2];
					}
					if(0 <= i+1 and i+1 < N){
						if(0 <= j-2 and j-2 < N)dp[k][i][j] += p*dp[k-1][i+1][j-2];
						if(0 <= j+2 and j+2 < N)dp[k][i][j] += p*dp[k-1][i+1][j+2];
					}
					if(0 <= i-2 and i-2 < N){
						if(0 <= j-1 and j-1 < N)dp[k][i][j] += p*dp[k-1][i-2][j-1];
						if(0 <= j+1 and j+1 < N)dp[k][i][j] += p*dp[k-1][i-2][j+1];
					}
					if(0 <= i+2 and i+2 < N){
						if(0 <= j-1 and j-1 < N)dp[k][i][j] += p*dp[k-1][i+2][j-1];
						if(0 <= j+1 and j+1 < N)dp[k][i][j] += p*dp[k-1][i+2][j+1];
					}
        		}
        	}
        }
        return dp[K-1][r][c];
    }
};


//a faster approach:
class Solution {
public:
	double A(int N, int r, int c){
		
	}
};






