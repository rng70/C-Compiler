
// Created by rng70

#ifndef COMPILER_SYMBOLINFO_H
#define COMPILER_SYMBOLINFO_H

class SymbolInfo {
    std::string name;
    std::string type;
    SymbolInfo *nextPointer;
public:
    SymbolInfo() {
        this->name = "";
        this->type = "";
        this->nextPointer = 0;
    }

    SymbolInfo(std::string symbolName, std::string symbolType, SymbolInfo *pointer) {
        this->name = symbolName;
        this->type = symbolType;
        this->nextPointer = pointer;
    }

    void setName(std::string symbolName) {
        this->name = symbolName;
    }

    void setType(std::string symbolType) {
        this->type = symbolType;
    }

    void setNextPointer(SymbolInfo *nextChainingPointer) {
        this->nextPointer = nextChainingPointer;
    }

    std::string getName() {
        return this->name;
    }

    std::string getType() {
        return this->type;
    }

    SymbolInfo *getNextPointer() {
        return this->nextPointer;
    }
};

#endif //COMPILER_SYMBOLINFO_H
