#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node{
    public:
        int count;
        Node * alphabet[26];
        Node () {
            count = 0;
            for (int i = 0; i < 26; i++)
                alphabet[i] = NULL;        
        }

        Node * insert_element(Node * temp, char a) {
            if (temp->alphabet[a - 'a'] == NULL)
                temp->alphabet[a - 'a'] = new Node();
            temp->alphabet[a - 'a']->count += 1;
            return temp->alphabet[a - 'a'];
        }

        Node * insert(Node * head, string str) {
            Node * temp = head;
            for (char &a : str) {
                temp = insert_element(temp, a);
            }
            return head;
        }

        Node * find_element(Node * temp, char a) {
            if (temp->alphabet[a - 'a'] != NULL)
                return temp->alphabet[a - 'a'];
            else 
                return NULL;
        }

        int find(Node * head, string str) {
            Node * temp = head;
            for (char& a: str) {
                if (temp == NULL)
                    return 0;
                temp = find_element(temp, a);                
            }
            if (temp == NULL)
                return 0;
            return temp->count;
        }
};

int main() {
    Node * head;
    head = new Node();
    int N;
    cin >> N;
    string name, op;
    while (N-- > 0) {
        cin >> op >> name;
        if (op == "add") {
            head = head->insert(head, name);        
            head->count++;
        } else if (op == "find") {
            cout << head->find(head, name) << endl;
        }
    }
    return 0;
}
