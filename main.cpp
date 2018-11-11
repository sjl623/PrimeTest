#include <gmpxx.h>
#include <iostream>

#include "MRPrime.h"

using namespace std;

int main(){
    vector<string> tmpBaseNumber;
    tmpBaseNumber.push_back("2047");
    tmpBaseNumber.push_back("1373653");
    tmpBaseNumber.push_back("25326001");
    tmpBaseNumber.push_back("3215031751");
    tmpBaseNumber.push_back("2152302898747");
    tmpBaseNumber.push_back("3474749660383");
    tmpBaseNumber.push_back("3825123056546413051");
    tmpBaseNumber.push_back("318665857834031151167461");
    tmpBaseNumber.push_back("3317044064679887385961981");

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