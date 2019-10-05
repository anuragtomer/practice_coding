/* Implements basic hashing.
 *
 * Note: not fully tested code.
 * 
 * Known Bugs:
 * - deletes whole list if multiple insertions have same key but different value, since
 *   they all get mapped to same bucket.
 * - Operator overloading not working. Commented.
 * - Memory might be leaking from keyvallist. Commented code.
 * 
 * Work pending:
 * - Fix known bugs.
 * - Would want hide (->next) from everywhere. Should make ++ work.
 **/

#include <iostream>
#include <cassert>

using namespace std;

struct keyVal{
    int key;
    int val;
    keyVal * next;
    keyVal() { keyVal(0, 0); }
    keyVal(int k, int v): key{k}, val{v}, next{nullptr} {};
    // operator overloading not working as of now.
    keyVal& operator++() {
        cout << "Correctly using ++\n";
        *this = *this->next;
        return *this;
    }
    keyVal operator++ (int) {  // postfix ++
        keyVal result(*this);   // make a copy for result
        ++(*this);              // Now use the prefix version to do the work
        return result;          // return the copy (the old) value.
    }
};

struct keyValList {
    keyVal * head = nullptr;
    void insert(int key, int val) {
        keyVal *kv = new keyVal(key, val);
        if (head == nullptr) {
            head = kv;
        } else {
            kv->next = head;
            head = kv;
        }
    }
    // ~keyValList() {
    //     keyVal *temp;
    //     while(head) {
    //         temp = head;
    //         head = head->next;
    //         delete temp;
    //     }
    // }
};

class myhash {
private:
    int capacity;        // Current capacity of hashtable.
    int size;            // No of current elements in hashtable.
    keyValList * hashTable; // Pointer to list of elements at different slots.
    const int MAX_LOAD_FACTOR = 5; // TODO: Some random no. Revisit later.
    int shiftFactor;
    void rehash();
    int hash(int key) {
    /* This is a private function used by the class to hash incoming entries into the table. Kept
     * private, not needed to expose this outside.
     * Possible hash functions:
     *  - mod capacity
     *  - fibonacci hashing <-- currently being used here.
     *  - Many others
     */
        return 11400714819323198485ull * key >> shiftFactor;
    }
public:
    myhash(): capacity{0}, size{0}, hashTable{nullptr} {
        shiftFactor = 59;
    };
    int insert(int key, int val);
    void erase(int key);
    int find(int key);
    void dump();
    ~myhash() {
        delete [] hashTable;
    }
};

void myhash::rehash() {
    int oldCapacity = capacity;
    capacity *= 2;
    shiftFactor -= 1; // Check what this means. Might need to revisit later.
    keyValList * newTable = new keyValList[capacity];
    for (int i = 0; i < oldCapacity; i++) {
        keyVal * temphead = hashTable[i].head;
        while(temphead) {
            int newIndex = hash(temphead->key);
            newTable[newIndex].insert(temphead->key, temphead->val);
            // ++temphead; Doesn't work. 
            temphead = temphead ->next;
        }
        hashTable[i].~keyValList();
    }
    hashTable = newTable;
}

int myhash::insert(int key, int val) {
    /* Should check for hash table full condition, and possibly expand.
     * Return value is int. 0 should indicate successful insertion, 1 otherwise. Kind of an error
     * code.
     * Should expand? rehash?
     */
    if (hashTable == nullptr) {
        capacity = 32;
        hashTable = new keyValList[capacity];
    }
    int index = hash(key);
    assert(index <= capacity);
    hashTable[index].insert(key, val);
    size++;
    if ((size/capacity) > MAX_LOAD_FACTOR)
        rehash();
    return 0;
}

void myhash::erase(int key) {
    /* Should erase the key-val pair for the given key. Should use hash(key) to locate the key.
     * Must indicate whether deletion was successful or not (via return value).
     * Also, need to check for empty condition. Not sure if this is needed. Should we reduce the
     * capacity of hash table if we expanded too much and came down?
     */
    int index = hash(key);
    assert(index < capacity);
    keyValList current = hashTable[index];
    if (current.head != nullptr) {
        keyVal *temp = current.head;
        keyVal *prev = nullptr;
        while(temp != nullptr && temp->key != key) {
            cout << temp->key << " did not match with " << key;
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "key: " << key << " not found in hash table.\n";
            return;
        }
        if (prev == nullptr && temp->key == key) {
            delete temp;
            hashTable[index].head = nullptr;
            return;
        }
        if (temp->key == key) {
            prev->next = temp->next;
            delete temp;
            return;
        }
    }
    cout << "key: " << key << " not found in hash table.\n";
    return;
}

int myhash::find(int key) {
    /* Should search for key in hashtable and return key. The return type of the function is of
     * the type of value. In future, if this class starts accepting template variables, then
     * this must be changed accordingly.
     */
    int index = hash(key);
    keyValList current = hashTable[index];
    if (current.head) {
        keyVal *temp = current.head;
        while(temp && temp->key != key) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "key: " << key << " not found in hash table.\n";
            return -1;
        }
        return temp->val;
    }
    cout << "key: " << key << " not found in hash table.\n";
    return -1;
}

void myhash::dump() {
    for (int i = 0; i < capacity; i++) {
        cout << endl;
        cout << i << ": ";
        keyVal * temphead = hashTable[i].head;
        while(temphead) {
            cout << temphead->key << ", " << temphead->val << "->";
            temphead = temphead->next;
        }
    }
}

int main() {
    myhash mh;
    int choice;
    cout << "1. Insert\n2. Delete\n3. Find\n4. Exit\n5. Dump hashtable\n";
    cin >> choice;
    do {
        switch(choice) {
            case 1: {
                int key, val;
                cout << "Enter key, val to insert: ";
                cin >> key >> val;
                mh.insert(key, val);
                break;
            }
            case 2: {
                int key;
                cout << "Enter key to delete: ";
                cin >> key;
                mh.erase(key);
                break;
            }
            case 3: {
                int key;
                cout << "Enter key to search: ";
                cin >> key;
                int val = mh.find(key);
                if (val != -1) {
                    cout << "\nVal: " << val << endl;
                }
                break;
            }
            case 5: {
                mh.dump();
                break;
            }
            default:
                break;
        }
        cout << "\n Choice: ";
        cin >> choice;
    } while(choice == 1 || choice == 2 || choice == 3 || choice == 5);
    return 0;
}