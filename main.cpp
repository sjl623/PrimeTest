#include <gmpxx.h>
#include <iostream>

#include "MRPrime.h"

using namespace std;

int main(){
    vector<string> tmpBaseNumber{"2047","1373653","25326001","3215031751","2152302898747",
    "3474749660383","3825123056546413051","318665857834031151167461","	3317044064679887385961981"};

    initBaseNumber(tmpBaseNumber);

    mpz_class goal;
    
    while(cin>>goal){
        if(isPrime(goal)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}