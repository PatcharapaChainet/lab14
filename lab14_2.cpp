#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

//Do not modify source code above this line 
void showMatrix(const bool x[][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << x[i][j] << " ";
	    }
		cout << endl;
	}
}

void inputMatrix(double x[][N]){
	for(int i=0;i<N;i++){
		cout <<"Row "<< i+1 << ": ";
		for(int j=0;j<N;j++){
			cin >> x[i][j];
	    }
	}
}

void findLocalMax(const double src[][N], bool x[][N]){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			
			if(src[i][j] >= src[i-1][j] && src[i][j] >= src[i+1][j] &&
			   src[i][j] >= src[i][j-1] && src[i][j] >= src[i][j+1]) x[i][j] = 1;
			else x[i][j] = 0;

			if(i==0 || i==N-1){
			    x[i][j] = 0;
			}else{
				x[i][0] = 0;
				x[i][N-1] = 0;
			}
	    }
	}
}
