#include <stdio.h>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

#define DEL(_x) {_x.pop_back();}
#define ADD(_x, _y) {_x += _y;}

int charToNum(char in){
    int out;
    if(in>='a' && in<='z') out = in-'a';
    else if(in>='A' && in<='Z') out = in-'A'+26;
    else if(in>='0' && in<='9') out = in-'0'+26+26;
    else out = -1;
    out %= 62;
    return out;
}

char numToChar(int in){
    in %= 62;
    if(in>='a'-'a' && in<='z'-'a') return in+'a';
    if(in>='A'-'A'+26 && in<='Z'-'A'+26) return in+'A'-26;
    if(in>='0'-'0'+26+26 && in<='9'-'0'+26+26) return in+'0'-26-26;
    return -1;
}

string execute_code(int N, vector<string> code){
    int aaaaa = 0;
    // WRITE YOUR CODE HERE
    vector<int> spaces;
    string out = "";
    string opcode, val, val2;
    int num;
    string prov;
    bool isDel;
    for(string current : code){
        aaaaa++;;
        isDel=1;
        spaces.clear();
        for(int i=0; i<current.length(); i++){
            if(current[i]==' '){
                spaces.push_back(i);
                isDel = 0;
            }
        }
        if(!isDel) opcode = current.substr(0, spaces[0]);
        else opcode = "del";
        //cout << "Opcode: \"" << opcode << "\"\t";
        if(opcode == "swap"){
            val = current.substr(spaces[0]+1, spaces[1]);
            val2 = current.substr(spaces[1]+1, current.length());
            for(int s=0; s<out.length(); s++){
                if(out[s]==val[0]) out[s] = val2[0];
                else if(out[s]==val2[0]) out[s] = val[0];
            }
        }
        if(opcode == "del"){
            if(!out.empty()) DEL(out);
        }
        if(opcode == "add"){
            val = current.substr(spaces[0]+1, current.length());
            ADD(out, val);
        }
        if(opcode == "rot"){
            val = current.substr(spaces[0]+1, current.length());
            num = stoi(val);
            for(int s=0; s<out.length(); s++){
                out[s] = numToChar((charToNum(out[s])+num)%62);
            }
        }
        //cout << "val and val2 are \""<< val << "\" and \"" << val2 << "\"\t";
        // cout << out << endl;
    }
    return out;
}

int main(){
    freopen("input.txt", "r", stdin); // DECOMMENT IF YOU WANT TO READ FROM FILE
    freopen("output.txt", "w", stdout); // DECOMMENT IF YOU WANT TO WRITE TO FILE

    int N;
    vector<string> code;
    cin >> N;

    string s;
    getline(cin, s);

    for(int i = 0; i < N; i++){
        getline(cin, s);
        code.push_back(s);
    }

    cout << execute_code(N, code);

    return 0;
}