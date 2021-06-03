// Created by rng70

#ifndef COMPILER_EXTRASYMBOLINFO_H
#define COMPILER_EXTRASYMBOLINFO_H

class ExtraSymbolInfo{
    public:
        std::string typeOfID;
        std::string typeOfVar;
        std::string returnTypeOfFunction;
        std::string sizeOfArray;
        std::string indexOfArray;
        std::string stringConcatenator;
        bool isFunction;
        bool isFunctionDefined;
        bool isFunctionDeclared;
        std::vector < pair<std::string,std::string> >functionParamList;

        std::string stringAdder(std::string addToStringConcatenator){
            return stringConcatenator.append(addToStringConcatenator);
        }

};

#endif