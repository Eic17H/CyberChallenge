#include <stdio.h>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

// Visto che è una sommatoria di somme non proprio iterative,
// probabilmente si può fare in "parallelo"
// Per esempio anziché mettere t[i] nel for, metterei N*t[i]
// Però non so come rendere "parallelo" quel T%t[i]
// Sicuramente c'è una cosa complicata in matematica discreta che non conosco
// Perdo 30 punti per la complessità ma non saprei neanche come cercare su google
// Sicuramente fatto quello diventa un problema lineare
// Sta andando da 15 minuti e non ha ancora finito l'ultima subtask, è troppo lunga
// N ed M sono 50756 e 939050, quindi se la rendessi lineare userebbe un 939050mo del tempo

long long find_sum_of_times(int N, int M, vector<int> t, vector<int> f, vector<int> emails){
    long long out = 0;
    long long T;
    for(int email : emails){
        T = email;
        for(int i=0; i<N; i++){
            //cout << "Server No. " << i << " received at minute " << T << "\n";
            if(T%t[i] != 0) T += t[i] - T%t[i];
            //cout << "Server No. " << i << " sent at minute " << T << "\n";
            T += f[i];
            //cout << "Server No. " << i << " processed at minute " << T << "\n";
        }
        //cout << "Total time is now: " << T << "\n";
        out += T;
    }
    return out;
}

int main(){
    freopen("input.txt", "r", stdin); // DECOMMENT IF YOU WANT TO READ FROM FILE
    freopen("output.txt", "w", stdout); // DECOMMENT IF YOU WANT TO WRITE TO FILE

    int N, M;
    cin >> N >> M;
    vector<int> t(N), f(N), emails(M);

    for(auto& x : t) cin >> x;
    for(auto& x : f) cin >> x;
    for(auto& x : emails) cin >> x;

    cout << find_sum_of_times(N, M, t, f, emails);

    return 0;
}