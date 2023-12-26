/*
 *
There is a row of n coins whose values are some positive integers
c₁, c₂,...,cn, not necessarily distinct. The goal is to pick up the
maximum amount of money subject to the constraint that no two
coins adjacent in the initial row can be picked up.
 *
*/


#include <iostream>
# include <vector>
using namespace std;

int max_money(const vector<int>&coins){
    int n = coins.size(); //no. of coins in the row

    //base case
    if (n==0){
        return 0; //no coins
    }
    if (n==1){
        return coins[0]; //one coin
    }

    //dp initialization
    vector<int>M(n+1,0); //M stores amnt of money for each sub-problem, it is of size n+1 and its elements are initialized to 0
    M[1] = coins[0]; //set to the value of the first coin

    //iterate over the rest of the coins (wout the first one)
    for (int i = 2; i <= n ; ++i) {
        M[i] = max(M[i-1],M[i-2]+coins[i-1]);
    }

    return M[n];
}

int main(){
    vector<int> coins = {5,1,2,10,6,2};
    int result = max_money(coins);
    cout << "max amount of money to pick out: " << result << endl;
}