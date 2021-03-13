//
// Created by arafa on 3/12/2021.
//

#ifndef COMPILER_SYMBOLINFO_H
#define COMPILER_SYMBOLINFO_H

class SymbolInfo{
    std::string name;
    std::string type;
    SymbolInfo * nextPointer;

public:
    SymbolInfo(){
        this->name = "";
        this->type = "";
        this->nextPointer = nullptr;
    }
    SymbolInfo(std::string symbolName, std::string symbolType){
        this->name = symbolName;
        this->type = symbolType;
    }
    void setName(std::string symbolName){
        this->name = symbolName;
    }
    void setType(std::string symbolType){
        this->type = symbolType;
    }
    void setNextPointer(SymbolInfo* nextChainingPointer){
        this->nextPointer = nextChainingPointer;
    }
    std::string getName(){
        return this->name;
    }
    std::string getType(){
        return this->type;
    }
    SymbolInfo* getNextPointer(){
        return this->nextPointer;
    }
};

#endif //COMPILER_SYMBOLINFO_H
