//
// Created by arafa on 3/12/2021.
//

#ifndef COMPILER_SCOPETABLE_H
#define COMPILER_SCOPETABLE_H

class ScopeTable{
    int size, Id;

    /// Declare parent Scope to Store parent Scope of current Scope
    ScopeTable* parentScope;

    // HashTable to store information of symbol(s)
    SymbolInfo** HashTable;
     // Defining a hash function class
     Hashing hashFucntion;
public:
    ScopeTable(int tableSize, int tableId){
        this->size = tableSize;
        this->Id = tableId;

        Hashing newHash = new Hasing(this->size);
        this->hashFucntion = newHash;
    }
    bool Insert(string s){
        char hashValue = hashFucntion.countHashValue(s);

        return false;
    }
    void setID(int id){
        this->Id = id;
    }
    int getID(){
        return this->Id;
    }

    ScopeTable* getParentScope(){
        return this->parentScope;
    }

};

#endif //COMPILER_SCOPETABLE_H
