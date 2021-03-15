
// Created by rng70

#include <bits/stdc++.h>
//#include "SymbolInfo.h"
//#include "ScopeTable.h"
//#include "SymbolTable.h"

using namespace std;
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
class ScopeTable {
    int size, Id, tableIdTracker;

    /// Declare parent Scope to Store parent Scope of current Scope
    ScopeTable *parentScope;

    // HashTable to store information of symbol(s)
    SymbolInfo **HashTable;
public:
    ScopeTable() {
        this->size = -1;
        this->tableIdTracker = -1;
        this->Id = this->tableIdTracker;
    }

    explicit ScopeTable(int tableSize, int p = 0) {
        this->size = tableSize;
        this->tableIdTracker = 0;
        this->Id = p + 1;

        // Set initial parent scope to 0 not null or nullptr
        this->parentScope = 0;

        // Allocate memory for hashtable
        HashTable = new SymbolInfo *[tableSize];
        for (int i = 0; i < tableSize; i++) {
            HashTable[i] = new SymbolInfo();
        }
    }

    void setTableIdTracker() {
        tableIdTracker++;
    }

    int getTableIdTracker() {
        return this->tableIdTracker;
    }

    std::string getStringifyID() {
        std::string sID = std::to_string(this->Id);
        ScopeTable *tempParent = this->parentScope;

        while (tempParent != 0) {
            sID += "." + std::to_string(tempParent->getID());
            tempParent = tempParent->getParentScope();
        }
        reverse(sID.begin(), sID.end());
        return sID;
    }

    bool Insert(std::string s, std::string type) {
        int idx = HashFunc(s);

        // Case-1: Table is empty and so no-collision occurred
        if (HashTable[idx]->getName() == "") {
            HashTable[idx]->setName(s);
            HashTable[idx]->setType(type);

            // Successfully inserted
            std::cout << "Inserted in ScopeTable# " << this->getStringifyID() << " at position " << idx << ", " << "0"
                      << std::endl << std::endl;
            return true;
        }
            // Case-2: Table is not empty and collision occurred
        else {
            SymbolInfo *root = HashTable[idx];
            while (root->getNextPointer() != 0) {
                // next pointer is not null, it is 0
                if (root->getName() == s) {
                    // Duplicate found
                    std::cout << "<" << s << "," << type << "> already exists in current ScopeTable" << std::endl << std::endl;
                    return false;
                }
                root = root->getNextPointer();
            }
            // if root is at level-0
            if (root->getNextPointer() == 0 && root->getName() == s) {
                // duplicate found at level 0
                std::cout << "<" << s << "," << type << "> already exists in current ScopeTable" << std::endl << std::endl;
                return false;
            }

            // at that point we did not  find any instance of s in symbol table
            // redundant declaration
            root = HashTable[idx];
            int positionTracker = 0;

            SymbolInfo *newSymbolInfo = new SymbolInfo(s, type, 0);

            // set the appropriate data
            // newSymbolInfo->setName(s);
            // newSymbolInfo->setType(type);
            // newSymbolInfo->setNextPointer(0);

            while (root->getNextPointer() != 0) {
                root = root->getNextPointer();
                positionTracker++;
            }
            root->setNextPointer(newSymbolInfo);
            std::cout << "Inserted in ScopeTable# " << this->getStringifyID() << " at position " << idx << ", "
                      << ++positionTracker << std::endl
                      << std::endl;
            return true;
        }
        // At that point it is ensured that we must have inserted the item
        return true;
    }

    int getID() {
        return this->Id;
    }

    ScopeTable *getParentScope() {
        return this->parentScope;
    }

    void setParentScope(ScopeTable *parent) {
        this->parentScope = parent;
    }

    int HashFunc(std::string s) const {
        int sumOfAsciiValue = 0;
        for (auto si:s) {
            sumOfAsciiValue += si;
        }
        return abs(sumOfAsciiValue % size);
    }

    // Search the hashtable and return a symbol-info pointer
    SymbolInfo *LookUP(std::string s) {
        int index = HashFunc(s);
        SymbolInfo *head = HashTable[index];
        int positionTracker = 0;

        // Search for the string
        if (head == 0) {
            return 0;
        }
        while (head != 0) {
            if (head->getName() == s) {
                // return the pointer where we found the string
                std::cout << "Found in ScopeTable# " << this->getStringifyID() << " at position " << index << ", "
                          << positionTracker << std::endl;
                std::cout << std::endl;
                return head;
            }
            positionTracker++;
            head = head->getNextPointer();
        }
        return head;
    }

    bool Delete(std::string s) {
        // Case to Consider:
        /*
         * 1. Table is empty
         * 2. Table has one entity and that does not match with the string
         * 3. Table has one entity and that is the element want to remove
         * 4. Table has a chain and it's first element is the element want to remove
         * 5. Table has a chain and it's middle element is the element want to remove
         * 6. Table has a chain but does not contain the element
         * 7. Last element of the chain is the element
         */

        // Calculate the index to look for
        int index = HashFunc(s);

        // Initialize a symbol-info pointer to search for the keys
        SymbolInfo *root = HashTable[index];
        SymbolInfo *temp, *p, *q;

        // Case-1: return false if the index of the hashtable is empty
        // Things broke sometimes here but don't know why
        if (root == 0) {
            std::cout << "Not found" << std::endl << std::endl;
            return false;
        }
        // Case-2: if only one index found and that does not contain the string
        if (root->getName() != s && root->getNextPointer() == 0) {
            std::cout << "Not found" << std::endl << std::endl;
            return false;
        }
            // Case-3: Table has one entity and that is the element want to remove
        else if (root->getName() == s && root->getNextPointer() == 0) {
            root->setName("");
            root->setType("");
            std::cout << "Found in ScopeTable# " << this->getStringifyID() << " at position " << index << ", 0"
                      << std::endl
                      << std::endl;
            std::cout << "Deleted Entry " << index << ", 0" << " from current ScopeTable" << std::endl << std::endl;
            // No need to set next pointer because it is already 0
            return true;
        }
            // Case-4: Table has a chain and it's first element is the element want to remove
        else if (HashTable[index]->getName() == s && HashTable[index]->getNextPointer() != 0) {
            temp = HashTable[index];
            HashTable[index] = HashTable[index]->getNextPointer();

            // show delete message
            std::cout << "Found in ScopeTable# " << this->getStringifyID() << " at position " << index << ", 0"
                      << std::endl
                      << std::endl;
            std::cout << "Deleted Entry " << index << ", 0" << " from current ScopeTable" << std::endl << std::endl;

            temp->setNextPointer(0);
            delete temp->getNextPointer();
            delete temp;

            // at that point return true
            return true;
        }
            // Case-5-7: element may be anywhere in the chain [middle or end]
        else {
            // keep track for a index and it's next index
            p = root;
            q = root->getNextPointer();
            int positionTracker = 0;

            // Check until we reached at the end of the chain
            while (q != 0 && q->getName() != s) {
                p = q;
                q = q->getNextPointer();
                positionTracker++;
            }

            // if the element is found in the middle
            if (q != 0) {
                p->setNextPointer(q->getNextPointer());
                q->setNextPointer(0);
                delete q->getNextPointer();
                delete q;

                // Show message and return
                std::cout << "Found in ScopeTable# " << this->getStringifyID() << " at position " << index << ", "
                          << ++positionTracker << std::endl
                          << std::endl;
                std::cout << "Deleted Entry " << index << ", " << ++positionTracker << " from current ScopeTable"
                          << std::endl << std::endl;
                return true;
            }
            // Show message that value not found at that point
            std::cout << "Not found" << std::endl << std::endl;
            return false;
        }
    }

    void print() {
        std::cout << std::endl << "ScopeTable # " << this->getStringifyID() << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << i << " --> ";
            if (HashTable[i]->getNextPointer() == 0) {
                if (HashTable[i]->getName() != "")
                    std::cout << " < " << HashTable[i]->getName() << " : " << HashTable[i]->getType() << "> ";
            } else {
                SymbolInfo *temp = HashTable[i];
                while (temp != 0) {
                    std::cout << " < " << temp->getName() << " : " << temp->getType() << "> ";
                    temp = temp->getNextPointer();
                }
            }
            std::cout << " " << std::endl;
        }
        std::cout << std::endl;
    }

    bool copyOfDeleteFunction(std::string s) {
        // Case to Consider:
        /*
         * 1. Table is empty
         * 2. Table has one entity and that does not match with the string
         * 3. Table has one entity and that is the element want to remove
         * 4. Table has a chain and it's first element is the element want to remove
         * 5. Table has a chain and it's middle element is the element want to remove
         * 6. Table has a chain but does not contain the element
         * 7. Last element of the chain is the element
         */

        // Calculate the index to look for
        int index = HashFunc(s);

        // Initialize a symbol-info pointer to search for the keys
        SymbolInfo *root = HashTable[index];
        SymbolInfo *temp, *p, *q;

        // Case-1: return false if the index of the hashtable is empty
        // Things broke sometimes here but don't know why
        if (root == 0) {
            return false;
        }
        // Case-2: if only one index found and that does not contain the string
        if (root->getName() != s && root->getNextPointer() == 0) {
            return false;
        }
            // Case-3: Table has one entity and that is the element want to remove
        else if (root->getName() == s && root->getNextPointer() == 0) {
            root->setName("");
            root->setType("");
            // No need to set next pointer because it is already 0
            return true;
        }
            // Case-4: Table has a chain and it's first element is the element want to remove
        else if (HashTable[index]->getName() == s && HashTable[index]->getNextPointer() != 0) {
            temp = HashTable[index];
            HashTable[index] = HashTable[index]->getNextPointer();

            // show delete message

            temp->setNextPointer(0);
            delete temp->getNextPointer();
            delete temp;

            // at that point return true
            return true;
        }
            // Case-5-7: element may be anywhere in the chain [middle or end]
        else {
            // keep track for a index and it's next index
            p = root;
            q = root->getNextPointer();
            int positionTracker = 0;

            // Check until we reached at the end of the chain
            while (q != 0 && q->getName() != s) {
                p = q;
                q = q->getNextPointer();
                positionTracker++;
            }

            // if the element is found in the middle
            if (q != 0) {
                p->setNextPointer(q->getNextPointer());
                q->setNextPointer(0);
                delete q->getNextPointer();
                delete q;

                // Show message and return
                return true;
            }
            // Show message that value not found at that point
            return false;
        }
    }

    void OutOfScope() {
        for (int i = 0; i < size; i++) {
            SymbolInfo *temp = HashTable[i];

            while (temp->getName() != "") {
                copyOfDeleteFunction(temp->getName());
                temp = HashTable[i];
            }
        }
    }

    ~ScopeTable() {
        this->OutOfScope();
        for (int i = 0; i < size; i++) {
            delete HashTable[i]->getNextPointer();
            delete HashTable[i];
        }
        delete[] HashTable;
    }
};
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
        ScopeTable *newScopeTable = new ScopeTable(this->sizeOfTable, currentScope->getTableIdTracker());
        // Increment the table tracker value
        currentScope->setTableIdTracker();
        ScopeTable *parentScope = currentScope;
        currentScope = newScopeTable;
        currentScope->setParentScope(parentScope);
        std::cout << "New ScopeTable with id " << newScopeTable->getStringifyID() << " created" << std::endl
                  << std::endl;
    }

    void ExitScope() {
        //currentScope->setTableIdTracker();
        ScopeTable *temp = currentScope;
        currentScope = temp->getParentScope();
        std::cout << "ScopeTable with id " << temp->getStringifyID() << " removed" << std::endl << std::endl;
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
        std::cout << "Not found" << std::endl << std::endl;
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

void printSubMenu(std::string s, std::string s1) {
    cout << "Press " << s << " to " << s1 << endl;
}

void menu() {
    printSubMenu("I", " Insert in the current Scope Table");
    printSubMenu("L", " LookUp the current Scope Table");
    printSubMenu("D", " Delete from current Scope Table");
    printSubMenu("P", " Print Scope Table");
    printSubMenu("S", " Enter into a new Scope");
    printSubMenu("E", " Exit the current Scope Table");
    cout << endl;
}

void takeInput() {
    // For any normal text editor
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // Only for Clion absolute path is needed
    freopen("G://GitHub Repositories//C-Compiler//input.txt", "r", stdin);
    freopen("G://GitHub Repositories//C-Compiler//output.txt", "w", stdout);

    int n;
    cin >> n;

    // Initialize Symbol Table
    SymbolTable currentSymbolTable(n);

    char ch;
    string name, type;
    // Show operation menu in console input mode
    //menu();
    while (cin >> ch) {
        // Show operation menu each time
        // menu();
        // Take user choice for operation
        // cin >> ch;

        if (ch == 'I' || ch == 'i') {
            cin >> name >> type;
            cout << ch << " " << name << " " << type << endl << endl;
            currentSymbolTable.Insert(name, type);
        } else if (ch == 'L' || ch == 'l') {
            cin >> name;
            cout << ch << " " << name << endl << endl;
            currentSymbolTable.LookUp(name);
        } else if (ch == 'D' || ch == 'd') {
            cin >> name;
            cout << ch << " " << name << endl << endl;
            bool t = currentSymbolTable.Remove(name);
            if (!t) {
                cout << name << " not found" << endl << endl;
            }
        } else if (ch == 'P' || ch == 'p') {
            char cp;
            cin >> cp;
            cout << ch << " " << cp << endl << endl;
            if (cp == 'A')
                currentSymbolTable.printAllTable();
            else
                currentSymbolTable.printCurrentScopeTable();
        } else if (ch == 'S' || ch == 's') {
            cout << ch << endl << endl;
            currentSymbolTable.EnterScope();
        } else if (ch == 'E' || ch == 'e') {
            cout << ch << endl << endl;
            currentSymbolTable.ExitScope();
        } else {
            break;
        }
    }
}

int main() {
    takeInput();
    return 0;
}

