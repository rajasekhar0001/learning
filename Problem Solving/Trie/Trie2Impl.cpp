#include <bits/stdc++.h>
using namespace std;

// Structure representing each node in the Trie
struct Node {
    Node* links[26];          // Pointers to child nodes (for 'a' to 'z')
    int prefixCount;          // Number of words sharing this prefix
    int endsWithCount;        // Number of words ending at this node

    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
        prefixCount = 0;
        endsWithCount = 0;
    }

    // Check if the node contains a link for a given character
    bool containsKey(char ch) {
        return (links[ch - 'a'] != nullptr);
    }

    // Create a link from current node to a new node for given character
    void putKey(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Get the next node linked by a character
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    // Increment the prefix count
    void incrementPrefixCount() {
        prefixCount++;
    }

    // Increment the end-of-word count
    void incrementEndsWithCount() {
        endsWithCount++;
    }

    // Decrement prefix count
    void decreasePrefixCount() {
        prefixCount--;
    }

    // Decrement end-of-word count
    void decreaseEndsWithCount() {
        endsWithCount--;
    }

    // Get number of words with this prefix
    int getPrefixCount() {
        return prefixCount;
    }

    // Get number of words ending at this node
    int getEndWithCount() {
        return endsWithCount;
    }
};

// Trie class that uses the Node structure
class Trie {
    Node* root;

    // Helper function to recursively delete nodes
    void deleteNode(Node* node) {
        if (node == nullptr) return;
        for (int i = 0; i < 26; ++i) {
            deleteNode(node->links[i]);
        }
        delete node;
    }

public:
    Trie() {
        root = new Node();
    }

    ~Trie() {
        deleteNode(root);  // Clean up memory when Trie is destroyed
    }

    // Insert a word into the Trie
    void insert(string word) {
        Node* tRoot = root;
        for (int i = 0; i < word.size(); i++) {
            if (!tRoot->containsKey(word[i])) {
                tRoot->putKey(word[i], new Node());
            }
            tRoot = tRoot->get(word[i]);
            tRoot->incrementPrefixCount();
        }
        tRoot->incrementEndsWithCount();
    }

    // Count how many times a word was inserted
    int countWordsEqualTo(string word) {
        Node* tRoot = root;
        for (int i = 0; i < word.size(); i++) {
            if (!tRoot->containsKey(word[i])) {
                return 0;
            }
            tRoot = tRoot->get(word[i]);
        }
        return tRoot->getEndWithCount();
    }

    // Count how many words share a given prefix
    int countWordsPrefixTo(string prefix) {
        Node* tRoot = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!tRoot->containsKey(prefix[i])) {
                return 0;
            }
            tRoot = tRoot->get(prefix[i]);
        }
        return tRoot->getPrefixCount();
    }

    // Erase a word from the Trie (only if it exists)
    void erase(string word) {
        Node* tRoot = root;

        // First check that the word exists
        Node* checkNode = root;
        for (char ch : word) {
            if (!checkNode->containsKey(ch)) {
                return; // Word not present, exit
            }
            checkNode = checkNode->get(ch);
        }
        if (checkNode->getEndWithCount() == 0) {
            return; // Word not present
        }

        // Safe to proceed with deletion
        tRoot = root;
        for (char ch : word) {
            tRoot = tRoot->get(ch);
            tRoot->decreasePrefixCount();
        }

        tRoot->decreaseEndsWithCount();
    }
};

// Main function to test the Trie
int main() {
    Trie trie;

    // Insert words
    trie.insert("apple");
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apex");

    // Count exact words
    cout << "Count of 'apple': " << trie.countWordsEqualTo("apple") << endl; // 2
    cout << "Count of 'app': " << trie.countWordsEqualTo("app") << endl;     // 1
    cout << "Count of 'apex': " << trie.countWordsEqualTo("apex") << endl;   // 1
    cout << "Count of 'ap': " << trie.countWordsEqualTo("ap") << endl;       // 0

    // Count prefixes
    cout << "Prefix 'ap': " << trie.countWordsPrefixTo("ap") << endl;        // 4
    cout << "Prefix 'app': " << trie.countWordsPrefixTo("app") << endl;      // 3
    cout << "Prefix 'appl': " << trie.countWordsPrefixTo("appl") << endl;    // 2
    cout << "Prefix 'apex': " << trie.countWordsPrefixTo("apex") << endl;    // 1

    // Erase one "apple"
    trie.erase("apple");

    cout << "After erasing one 'apple':" << endl;
    cout << "Count of 'apple': " << trie.countWordsEqualTo("apple") << endl; // 1
    cout << "Prefix 'app': " << trie.countWordsPrefixTo("app") << endl;      // 2

    // Erase remaining "apple"
    trie.erase("apple");

    cout << "After erasing all 'apple':" << endl;
    cout << "Count of 'apple': " << trie.countWordsEqualTo("apple") << endl; // 0
    cout << "Prefix 'app': " << trie.countWordsPrefixTo("app") << endl;      // 1

    return 0;
}
