
// Created by rng70

#ifndef COMPILER_SYMBOLTABLE_H
#define COMPILER_SYMBOLTABLE_H

class SymbolTable {
    int sizeOfTable;
    ScopeTable *currentScope;
public:
    explicit SymbolTable(int size) {
        this->sizeOfTable = size;
        currentScope = new ScopeTable(sizeOfTable);
    }

    void setCurrentScope(ScopeTable *p) {
        this->currentScope = p;
    }

    ScopeTable *getCurrentScope() {
        return this->currentScope;
    }

    // required methods for offline
    void EnterScope() {
        ScopeTable *newScopeTable = new ScopeTable(this->sizeOfTable);
        ScopeTable *parentScope = currentScope;
        cout<<"New ScopeTable with Id "<<newScopeTable->getID()<<" created."<<endl<<endl;
        currentScope = newScopeTable;
        currentScope->setParentScope(parentScope);
    }

    void ExitScope() {
        currentScope->setTableIdTracker();
        ScopeTable *temp = currentScope;
        currentScope = temp->getParentScope();
        cout<<"ScopeTable with ID "<<temp->getID()<<" removed"<<endl<<endl;
        delete temp;
    }

    bool Insert(std::string s, std::string type) {
        if (currentScope->Insert(s, type))
            return true;
        return false;
    }

    bool Remove(std::string s) {
        if (currentScope->Delete(s))
            return true;
        return false;
    }

    SymbolInfo *LookUp(std::string s) {
        ScopeTable *temp = currentScope;
        SymbolInfo *yolo;

        while (temp != 0) {
            yolo = temp->LookUP(s);
            if (yolo != 0)
                return yolo;
            temp = temp->getParentScope();
        }
        cout<<"Not Found"<<endl<<endl;
        return 0;
    }

    void printCurrentScopeTable() {
        currentScope->print();
    }

    void printAllTable() {
        ScopeTable *recursive = currentScope;
        while (recursive != 0) {
            recursive->print();
            recursive = recursive->getParentScope();
        }
    }

    ~SymbolTable() {
        ScopeTable *child, *parent;
        child = currentScope;

        while (child != 0) {
            parent = child->getParentScope();
            delete child;
            //child->~ScopeTable();
            child = parent;
        }
        delete child;
        delete parent;
    }
};

#endif //COMPILER_SYMBOLTABLE_H
