#include<iostream>
#include<string>
#include<fstream>
#include<string>
#include<vector>

#define CONTAIN(x, y) x.find(y) != string::npos
#define LOADWORDS(vec, fil, len) for(int i=0; i<len; i++) {string prv; fil>>prv; vec.push_back(prv);}

using namespace std;

int main(){
    //*
    ifstream in(".\\input\\input3.txt");
    ofstream out("output.txt");
    vector<string> banned;
    vector<string> input;
    int N, M;
    in >> N >> M;
    LOADWORDS(banned, in, M);
    LOADWORDS(input, in, N);
    string check;
    for(string inp : input){
        for(string ban : banned){
            if(CONTAIN(inp, ban))
                check = "BANNED";
            else
                check = "SAFE";
            out << check << "\n";
        }
    }//*/
    return 0;
}