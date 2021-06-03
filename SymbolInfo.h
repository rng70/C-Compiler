
// Created by rng70

#ifndef COMPILER_SYMBOLINFO_H
#define COMPILER_SYMBOLINFO_H

class SymbolInfo {
    std::string name;
    std::string type;
    SymbolInfo *nextPointer;
public:
    ExtraSymbolInfo extraSymbolInfo;
    SymbolInfo() {
        this->name = "";
        this->type = "";
        this->nextPointer = 0;
        extraSymbolInfo.indexOfArray = "";
        extraSymbolInfo.sizeOfArray = "";
        extraSymbolInfo.typeOfID = "";
        extraSymbolInfo.typeOfVar = "";
        extraSymbolInfo.isFunction = false;
        extraSymbolInfo.isFunctionDefined = false;
        extraSymbolInfo.isFunctionDeclared = false;
        extraSymbolInfo.returnTypeOfFunction = "";
    }

    SymbolInfo(std::string symbolName, std::string symbolType, SymbolInfo *pointer = 0) {
        this->name = symbolName;
        this->type = symbolType;
        this->nextPointer = 0;
        extraSymbolInfo.indexOfArray = "";
        extraSymbolInfo.sizeOfArray = "";
        extraSymbolInfo.typeOfID = "";
        extraSymbolInfo.typeOfVar = "";
        extraSymbolInfo.isFunction = false;
        extraSymbolInfo.isFunctionDefined = false;
        extraSymbolInfo.isFunctionDeclared = false;
        extraSymbolInfo.returnTypeOfFunction = "";
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
