#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

#define CONTAIN(_x, _y) (_x.find(_y) != string::npos)
#define LOADWORDS(_vec, _fil, _len, _type) {_type _prv; for(int _i=0; _i<_len; _i++) {_fil>>_prv; _vec.push_back(_prv);}}
#define INPUTFILE(_x) ifstream in(_x);
#define OUTPUTFILE(_x) ofstream out(_x);

int main(){
    int Q, N;
    INPUTFILE(".\\input\\input-1-0.txt");
    OUTPUTFILE("output.txt")
    in >> Q >> N;
    vector<char> correct;
    LOADWORDS(correct, in, Q, char);
    vector<char> temp;
    int count;
    int j;
    for(int i=0; i<N; i++){
        LOADWORDS(temp, in, Q, char);
        count=0;
        for(j=0; j<Q; j++) {if(temp[j]==correct[j]) count++;
        cout<<temp[j]<<" "<<correct[j]<<" "<<count<<"\n";}
        out<<count<<"\n";
    }
    return 0;
}