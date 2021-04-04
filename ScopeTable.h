
// Created by rng70

#ifndef COMPILER_SCOPETABLE_H
#define COMPILER_SCOPETABLE_H
std::FILE *logs;
std::FILE *tokens;

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
            // std::cout << "Inserted in ScopeTable# " << this->getStringifyID() << " at position " << idx << ", " << "0"
            //           << std::endl << std::endl;
            return true;
        }
            // Case-2: Table is not empty and collision occurred
        else {
            SymbolInfo *root = HashTable[idx];
            while (root->getNextPointer() != 0) {
                // next pointer is not null, it is 0
                if (root->getName() == s) {
                    // Duplicate found
                    // std::cout << "<" << s << "," << type << "> already exists in current ScopeTable" << std::endl << std::endl;
                  std::string foundMsg = s + " already exists in current ScopeTable\n";
                  fprintf(logs, "%s\n", foundMsg.c_str());
                    return false;
                }
                root = root->getNextPointer();
            }
            // if root is at level-0
            if (root->getNextPointer() == 0 && root->getName() == s) {
                // duplicate found at level 0
                // std::cout << "<" << s << "," << type << "> already exists in current ScopeTable" << std::endl << std::endl;
              std::string foundMsg = s + " already exists in current ScopeTable\n";
                  fprintf(logs, "%s\n", foundMsg.c_str());
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
            // std::cout << "Inserted in ScopeTable# " << this->getStringifyID() << " at position " << idx << ", "
            //           << ++positionTracker << std::endl
            //           << std::endl;
            return true;
        }
        // At that point it is ensured that we must have inserted the item
        return true;
    }

    void InsertAndPrintToFile(std::string s, std::string type) {
        
        if(Insert(s, type)){
          ScopeTable* temp = this;
          while(temp!=0){
          temp->printModified();
            // SymbolInfo* p;

        //     fprintf(logs,"ScopeTable # %s\n",this->getStringifyID().c_str());

        //     for(int i = 0; i<size; i++)
        // {
        //     if(HashTable[i]->getName()!="")
        //     {
        //         fprintf(logs," %d --> ",i);

        //         p = HashTable[i];

        //         while(p != 0)
        //         {
        //             fprintf(logs,"< %s : %s> ",p->getName().c_str(),p->getType().c_str());

        //             p = p->getNextPointer();
        //         }
        //         fprintf(logs,"\n");
        //     }
        // }
        //fprintf(logs,"\n");
        temp = temp->getParentScope();}
        }
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
                // std::cout << "Found in ScopeTable# " << this->getStringifyID() << " at position " << index << ", "
                //           << positionTracker << std::endl;
                // std::cout << std::endl;
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
            // std::cout << "Not found" << std::endl << std::endl;
            return false;
        }
        // Case-2: if only one index found and that does not contain the string
        if (root->getName() != s && root->getNextPointer() == 0) {
            // std::cout << "Not found" << std::endl << std::endl;
            return false;
        }
            // Case-3: Table has one entity and that is the element want to remove
        else if (root->getName() == s && root->getNextPointer() == 0) {
            root->setName("");
            root->setType("");
            // std::cout << "Found in ScopeTable# " << this->getStringifyID() << " at position " << index << ", 0"
            //           << std::endl
            //           << std::endl;
            // std::cout << "Deleted Entry " << index << ", 0" << " from current ScopeTable" << std::endl << std::endl;
            // No need to set next pointer because it is already 0
            return true;
        }
            // Case-4: Table has a chain and it's first element is the element want to remove
        else if (HashTable[index]->getName() == s && HashTable[index]->getNextPointer() != 0) {
            temp = HashTable[index];
            HashTable[index] = HashTable[index]->getNextPointer();

            // show delete message
            // std::cout << "Found in ScopeTable# " << this->getStringifyID() << " at position " << index << ", 0"
            //           << std::endl
            //           << std::endl;
            // std::cout << "Deleted Entry " << index << ", 0" << " from current ScopeTable" << std::endl << std::endl;

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
                // std::cout << "Found in ScopeTable# " << this->getStringifyID() << " at position " << index << ", "
                //           << ++positionTracker << std::endl
                //           << std::endl;
                // std::cout << "Deleted Entry " << index << ", " << ++positionTracker << " from current ScopeTable"
                //           << std::endl << std::endl;
                return true;
            }
            // Show message that value not found at that point
            // std::cout << "Not found" << std::endl << std::endl;
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
    void printModified() {
        fprintf(logs,"ScopeTable # %s\n",this->getStringifyID().c_str());
        for (int i = 0; i < size; i++) {
            if (HashTable[i]->getNextPointer() == 0) {
                if (HashTable[i]->getName() != ""){
                    fprintf(logs," %d --> ",i);
                    fprintf(logs,"< %s : %s> ",HashTable[i]->getName().c_str(),HashTable[i]->getType().c_str());
                    fprintf(logs, "\n");
                }
            } else {
                SymbolInfo *temp = HashTable[i];
                fprintf(logs, " %d --> ", i);
                while (temp != 0) {
                  //fprintf(logs," %d --> ",i);
                    fprintf(logs,"< %s : %s> ",temp->getName().c_str(),temp->getType().c_str());
                    temp = temp->getNextPointer();
                }
                fprintf(logs,"\n");
            }
        }
        fprintf(logs,"\n");
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

#endif //COMPILER_SCOPETABLE_H
