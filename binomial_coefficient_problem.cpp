#include <iostream>
#include <vector>
using namespace std;

//int binomial_coeff(int n,int k){
//    if (k==0 || k==n){
//        return 1;
//    }
//    return binomial_coeff(n-1,k-1)+ binomial_coeff(n-1,k);
//}

int binomial_coeff2(int n,int k){
    //2d table to print the values
    int c[n+1][k+1];
    int i,j;
    //calculate the coefficients
    for (i = 0; i <= n; ++i) {
        for (j = 0; j <= min(i,k) ; ++j) {
            //base case
            if (j==0 || j==i){
                c[i][j]=1;
            }
            else{
                c[i][j] = c[i-1][j-1]+c[i-1][j];
            }
        }
    }
    return c[n][k];
}


int main() {
    //cout << binomial_coeff(5,2);
    cout << binomial_coeff2(4,2);
}
