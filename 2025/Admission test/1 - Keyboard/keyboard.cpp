#include <stdio.h>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

string find_key(int L, string s){
    char x;
    string out;
    bool exists[26] = {0};
    for(int i=0; i<L; i++) exists[s[i] - 'a'] = 1;
    for(int i=0; i<26; i++) if(!exists[i]) x = i+'a';
    out = "";
    out += x;
    return out;
}

int main(){
    freopen("input.txt", "r", stdin); // DECOMMENT IF YOU WANT TO READ FROM FILE
    freopen("output.txt", "w", stdout); // DECOMMENT IF YOU WANT TO WRITE TO FILE

    int N;
    cin >> N;

    while(N--){
        int L;
        string s;

        cin >> L;
        cin >> s;
        cout << find_key(L, s) << endl;
    }

    return 0;
}