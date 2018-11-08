#include "MRPrime.h"
#include <cstdio>

vector<mpz_class> BaseNumber;

void initBaseNumber(vector<string> input){
    for(int i=0;i<input.size();i++){
        mpz_class nowInput(input[i]);
        //const char *nowInputStr=input[i].c_str();
        BaseNumber.push_back(nowInput);
    }
    return;
}

bool MillerRabbin(mpz_class goal,mpz_class base){
    mpz_class r(0);
    mpz_class s(goal-1);

    mpz_t tmp;
    mpz_init(tmp);
    mpz_mod(tmp,goal.get_mpz_t(),base.get_mpz_t());
    if(mpz_cmp(tmp,mpz_class(0).get_mpz_t())==0) return false;

    mpz_t tmpRes;
    mpz_init(tmpRes);
    while(true){
        mpz_and(tmpRes,s.get_mpz_t(),mpz_class(1).get_mpz_t());
        if(mpz_cmp(tmpRes,mpz_class(1).get_mpz_t())==0) break;
        r++;
        s>>=1;
    }

    mpz_t powRes1;
    mpz_init(powRes1);
    mpz_powm(powRes1,base.get_mpz_t(),s.get_mpz_t(),goal.get_mpz_t());

    mpz_class two(2);
    mpz_class one(1);

    for(mpz_class j=0;j<r;j++){
        mpz_t powRes2;
        mpz_init(powRes2);
        
        mpz_powm(powRes2,powRes1,two.get_mpz_t(),goal.get_mpz_t());
        if(mpz_class(powRes2)==one&&mpz_class(powRes1)!=one&&mpz_class(powRes1)!=mpz_class(goal-1)) return false;
        mpz_set(powRes1,powRes2);
    }
    if(mpz_class(powRes1)!=one) return false;
    else return true;
}

bool isPrime(mpz_class goal){
    for(int i=0;i<BaseNumber.size();i++){
        if(goal==BaseNumber[i]) return true;
        if(!MillerRabbin(goal,BaseNumber[i])) return false;
    }
    return true;
}