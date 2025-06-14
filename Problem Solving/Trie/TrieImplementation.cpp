#include <iostream>
#include <string>
using namespace std;

struct Node {
    Node* links[26];    // Links to next characters (only lowercase 'a' to 'z')
    bool flag;  // Indicates end of a complete word

    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
        flag = false;
    }

    // Checks if a link exists for a character
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    // Inserts a node reference for a character
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Returns the node reference for a character
    Node* getReference(char ch) {
        return links[ch - 'a'];
    }

    // Marks current node as the end of a word
    void setEnd() {
        flag = true;
    }

    // Checks if node marks end of a word
    bool isEnd() {
        return flag;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // Inserts a word into the Trie
    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->getReference(ch);
        }
        node->setEnd();
    }

    // Returns true if the exact word exists in the Trie
    bool search(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->getReference(ch);
        }
        return node->isEnd();
    }

    // Returns true if any word in the Trie starts with the given prefix
    bool startsWith(string prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->getReference(ch);
        }
        return true;
    }
};

// === 🧪 Example Main Function ===
int main() {
    Trie* trie = new Trie();

    trie->insert("apple");
    trie->insert("app");
    trie->insert("bat");

    cout << boolalpha; // to print true/false instead of 1/0

    cout << "Search 'apple': " << trie->search("apple") << endl;       // true
    cout << "Search 'app': " << trie->search("app") << endl;           // true
    cout << "Search 'appl': " << trie->search("appl") << endl;         // false
    cout << "StartsWith 'app': " << trie->startsWith("app") << endl;   // true
    cout << "StartsWith 'bat': " << trie->startsWith("bat") << endl;   // true
    cout << "Search 'batman': " << trie->search("batman") << endl;     // false

    delete trie;
    return 0;
}
