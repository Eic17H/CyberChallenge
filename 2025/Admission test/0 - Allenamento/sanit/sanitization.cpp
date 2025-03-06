#include <stdio.h>
#include <iostream>
#include <vector>
#include <array>

#define CONTAIN(_x, _y) (_x.find(_y) != string::npos)
#define LOADWORDS(_vec, _fil, _len, _type) {for(int _i=0; _i<_len; _i++) {_type _prv; _fil>>_prv; _vec.push_back(_prv);}}
#define INPUTFILE(_x) ifstream in(_x);
#define OUTPUTFILE(_x) ofstream out(_x);

using namespace std;

vector<string> sanitize(vector<string> words, vector<string> banned){
    vector<string> answers;
    string check;
    for(string inp : words){
        for(string ban : banned){
            if(CONTAIN(inp, ban))
                check = "BANNED";
            else
                check = "SAFE";
            answers.push_back(check);
        }
    }
    return answers;
}

int main()
{

    freopen("input.txt", "r", stdin); // DECOMMENTA QUA SE VUOI LEGGERE DA FILE
    freopen("output.txt", "w", stdout); // DECOMMENTA QUA SE VUOI SCRIVERE DA FILE

    int N, M;
    vector<string> words, banned, answers;
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        string s;
        cin >> s;
        banned.push_back(s);
    }

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        words.push_back(s);
    }

    answers = sanitize(words, banned);

    for(auto s : answers){
        cout << s << endl;
    }

    return 0;
}