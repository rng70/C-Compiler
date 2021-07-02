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
        std::string assm_code;
        std::string carr1;
        bool isFunction;
        bool isFunctionDefined;
        bool isFunctionDeclared;
        std::vector <std::pair<std::string, std::string>> functionParamList;
        std::vector <std::pair<std::string, std::string>> var_declared_list;
        std::vector <std::string> modfd_param_list;


        std::string stringAdder(std::string addToStringConcatenator){
            return stringConcatenator.append(addToStringConcatenator);
        }
};

#endif