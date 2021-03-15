
// Created by rng70

#ifndef COMPILER_SCOPETABLE_H
#define COMPILER_SCOPETABLE_H

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

    explicit ScopeTable(int tableSize) {
        this->size = tableSize;
        this->tableIdTracker = 0;
        this->Id = this->tableIdTracker + 1;

        // Set initial parent scope to 0 not null or nullptr
        this->parentScope = 0;

        // Allocate memory for hashtable
        HashTable = new SymbolInfo*[tableSize];
        for(int i=0;i<tableSize;i++){
            HashTable[i] = new SymbolInfo();
        }
    }

    void setTableIdTracker() {
        tableIdTracker--;
    }

    bool Insert(std::string s, std::string type) {
        int idx = HashFunc(s);

        // Case-1: Table is empty and so no-collision occurred
        if (HashTable[idx]->getName() == "") {
            HashTable[idx]->setName(s);
            HashTable[idx]->setType(type);

            // Successfully inserted
            cout<<"Inserted in ScopeTable# "<<Id<<" at position "<< idx <<", "<< "0"<<endl<<endl;
            return true;
        }
            // Case-2: Table is not empty and collision occurred
        else {
            SymbolInfo *root = HashTable[idx];
            while (root->getNextPointer() != 0) {
                // next pointer is not null, it is 0
                if (root->getName() == s) {
                    // Duplicate found
                    return false;
                }
                root = root->getNextPointer();
            }
            // if root is at level-0
            if (root->getNextPointer() == 0 && root->getName() == s) {
                // duplicate found at level 0
                return false;
            }

            // at that point we did not  find any instance of s in symbol table
            // redundant declaration
            root = HashTable[idx];
            int positionTracker = 0;

            SymbolInfo *newSymbolInfo = new SymbolInfo(s, type, 0);

            // set the appropriate data
//            newSymbolInfo->setName(s);
//            newSymbolInfo->setType(type);
//            newSymbolInfo->setNextPointer(0);

            while (root->getNextPointer() != 0) {
                root = root->getNextPointer();
                positionTracker++;
            }
            root->setNextPointer(newSymbolInfo);
            cout<<"Inserted in ScopeTable# "<<Id<<" at position "<< ++positionTracker <<", "<< "0"<<endl<<endl;
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

    [[nodiscard]] int HashFunc(std::string s) const {
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
                cout<<"Found in ScopeTable# "<<Id<<" at position "<<index<<", "<<positionTracker<<endl;
                cout<<endl;
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
        if (root == 0){
            cout<<"Not Found"<<endl<<endl;
            return false;
        }
        // Case-2: if only one index found and that does not contain the string
        if (root->getName() != s && root->getNextPointer() == 0) {
            cout<<"Not Found"<<endl<<endl;
            return false;
        }
            // Case-3: Table has one entity and that is the element want to remove
        else if (root->getName() == s && root->getNextPointer() == 0) {
            root->setName("");
            root->setType("");
            cout<<"Found in ScopeTable# "<<Id<<" at position "<<index<<" , 0"<<endl<<endl;
            cout<<"Deleted entry at "<<index<<" , 0"<<" from current ScopeTable"<<endl<<endl;
            // No need to set next pointer because it is already 0
            return true;
        }
            // Case-4: Table has a chain and it's first element is the element want to remove
        else if (HashTable[index]->getName() == s && HashTable[index]->getNextPointer() != 0) {
            temp = HashTable[index];
            HashTable[index] = HashTable[index]->getNextPointer();

            // show delete message
            cout<<"Found in ScopeTable# "<<Id<<" at position "<<index<<" , 0"<<endl<<endl;
            cout<<"Deleted entry at "<<index<<" , 0"<<" from current scope table"<<endl<<endl;

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
                cout<<"Found in ScopeTable# "<<Id<<" at position "<<index<<" , "<<++positionTracker<<endl<<endl;
                cout<<"Deleted entry at "<<index<<" , "<<++positionTracker<<" from current scope table"<<endl<<endl;
                return true;
            }
            // Show message that value not found at that point
            cout<<"Not Found"<<endl<<endl;
            return false;
        }
    }

    void print() {
        cout << "ScopeTable # " << Id << endl;
        for (int i = 0; i < size; i++) {
            cout << i << " --> ";
            if (HashTable[i]->getNextPointer() == 0) {
                if (HashTable[i]->getName() != "")
                    std::cout << "< " << HashTable[i]->getName() << " : " << HashTable[i]->getType() << " >";
            } else {
                SymbolInfo *temp = HashTable[i];
                while (temp != 0) {
                    std::cout << "< " << temp->getName() << " : " << temp->getType() << " >";
                    temp = temp->getNextPointer();
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    void OutOfScope() {
        for (int i = 0; i < size; i++) {
            SymbolInfo *temp = HashTable[i];

            while (temp->getName() != "") {
                Delete(temp->getName());
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

#endif //COMPILER_SCOPETABLE_H
