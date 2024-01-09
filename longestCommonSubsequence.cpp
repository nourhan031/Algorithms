#include <iostream>
using namespace std;

int longest_common_subseq(string s1, string s2){
    int cache[s1.length()+1][s2.length()+1]; // +1 to make room for space
    /*
     * cache[s1.length()][s2.length()]: original subproblem. Each entry in the table takes a substring
     * operation against whatever string is on the rows/columns.
     *
     * It goes from index 0 to s1Row and s2Col
     *
     * If s2 = "azb" and s2Col = 2, then substring 0 1 2 "a z b" is passed to the function
     *
     * "a z" (index 2: upper bound of the snippet is excluded)
     */
    for (int s1Row=0; s1Row<=s1.length(); s1Row++){
        for (int s2Col=0; s2Col<=s2.length(); s2Col++){
            if (s1Row==0 || s2Col==0){
                cache[s1Row][s2Col] = 0;
            }
            else if(s1[s1Row-1]==s2[s2Col-1]){
                cache[s1Row][s2Col] = cache[s1Row-1][s2Col-1]+1;
            }
            else{
                cache[s1Row][s2Col] = max(cache[s1Row-1][s2Col],
                                          cache[s1Row][s2Col-1]);
            }
        }
    }
    return cache[s1.length()][s2.length()];
}

int main() {
    string s1,s2;
    cin >> s1 >> s2;

    int result = longest_common_subseq(s1,s2);

    cout << "lcs: " << result << endl;
}
