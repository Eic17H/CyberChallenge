#include<iostream>
#include<vector>
#include<string>
#include<fstream>

#define CONTAIN(_x, _y) (_x.find(_y) != string::npos)
#define LOADWORDS(_vec, _fil, _len, _type) {for(int _i=0; _i<_len; _i++) {_type _prv; _fil>>_prv; _vec.push_back(_prv);}}
#define INPUTFILE(_x) ifstream in(_x);
#define OUTPUTFILE(_x) ofstream out(_x);