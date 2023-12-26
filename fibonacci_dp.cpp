#include <iostream>
using namespace std;
//
//const int max_size=100;
//long long memo[max_size]= {0};
//
//long long feb_memoize(int n){
//    long long result;
//
//    if (memo[n]!= 0){
//        return memo[n];
//    }
//    if(n==1 || n==2){
//        result = 1;
//    }
//    else{
//        result=(feb_memoize(n-1)+ feb_memoize(n-2));
//    }
//    memo[n]=result;
//    return result;
//}


long long fib_bottomUp(int n){
    if (n<=2){
        return 1;
    }
    long long* bottomUp;
    bottomUp = new long long[n + 1];

    bottomUp[1] = 1;
    bottomUp[2] = 1;

    for (int i = 3; i <= n; ++i) {
        bottomUp[i] = bottomUp[i-1]+bottomUp[i-2];
    }

    long long result = bottomUp[n];

    delete bottomUp;

    return result;
}
int main(){
    cout << fib_bottomUp(20)<<endl; //6765
    cout << fib_bottomUp(35)<<endl; //9227465
    cout << fib_bottomUp(100)<<endl;
}

