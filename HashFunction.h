//
// Created by arafa on 3/12/2021.
//

#ifndef COMPILER_HASHFUNCTION_H
#define COMPILER_HASHFUNCTION_H

class Hashing{
    int totalBuckets;

public:
    Hashing(){
        this->totalBuckets = -1;
    }
    Hashing(int totalBucketNumber){
        this->totalBuckets = totalBucketNumber;
    }
    return HashFunction(string s){
        char sumOfAsciiValue=0;
        for(auto si:s){
            sumOfAsciiValue += si;
        }
        return sumOfAsciiVale;
    }
    int countHashValue(string thisString){
        return HashFunction(s) % bucketSize;
    }
};

#endif //COMPILER_HASHFUNCTION_H
