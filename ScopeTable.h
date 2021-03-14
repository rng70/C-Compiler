
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

    ScopeTable(int tableSize) {
        this->size = tableSize;
        this->tableIdTracker = 0;
        this->Id = this->tableIdTracker + 1;
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
            return true;
        }
            // Case-2: Table is not empty and collision may occurred
        else {
            bool duplicateFound = false;
            SymbolInfo *root = HashTable[idx];
            while (root->getNextPointer() != 0) {
                // next pointer is not null, it is 0
                if (root->getName() == s) {
                    // Duplicate found
                    duplicateFound = true;
                    return false;
                }
                root = root->getNextPointer();
            }
            // if root is at level-0
            if (!duplicateFound && (root->getNextPointer == 0 && root->getName() == s)) {
                // duplicate found at level 0
                return false;
            }

            // at that point we did not  find any instance of s in symbol table
            // redundant declaration
            root = HashTable[idx];

            SymbolInfo *newSymbolInfo = new SymbolInfo;

            // set the appropriate data
            newSymbolInfo->setName(s);
            newSymbolInfo->setType(type);
            newSymbolInfo->setNextPointer(0);

            while (root->getNextPointer() != 0) {
                root = root->getNextPointer();
            }
            root->setNextPointer(newSymbolInfo);
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

    int HashFunc(std::string s) {
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

        // Search for the string
        if (head == 0) {
            return 0;
        }
        while (head != 0) {
            if (head->getName() == s) {
                // return the pointer where we found the string
                return head;
            }
            head = head->getNextPointer();
        }
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
        if (root == 0)
            return false;

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

            temp->setNextPointer(0);
            delete temp->getNextPointer();
            delete temp;

            // at that point return true
            return true;
        }
            // Case-5-7: element may be anywhere in the chain
        else {
            // keep track for a index and it's next index
            p = root;
            q = root->getNextPointer();

            // Check until we reached at the end of the chain
            while (q != 0 && q->getName() != s) {
                p = q;
                q = q->getNextPointer();
            }

            // if the element is found in the middle
            if (q != 0) {
                p->setNextPointer(q->getNextPointer());
                q->setNextPointer(0);
                delete q->getNextPointer();
                delete q;

                return true;
            }
            return false;
        }
    }

    void print() {
        std::cout << "ScopeTable # " << Id << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << i << " -> ";
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
            std::cout << std::endl;
        }
        std::cout << std::endl;
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
