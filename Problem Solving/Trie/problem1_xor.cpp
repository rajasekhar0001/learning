/**
 * Problem link:
 * https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
 */

class Node {
    Node* links[2]; // Each node has 2 links: one for bit 0 and one for bit 1

public:
    Node() {
        links[0] = links[1] = nullptr;
    }

    // Check if there is a child node corresponding to the given bit (0 or 1)
    bool containsKey(int bit) {
        return (links[bit] != nullptr);
    }

    // Set a new node for the given bit
    void put(int bit, Node* node) {
        links[bit] = node;
    }

    // Get the next node for the given bit
    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node(); // Initialize the root of the trie
    }

    // Insert the 32-bit representation of a number into the trie
    void insert(int num) {
        Node* tRoot = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1; // Extract bit at position i
            if (!tRoot->containsKey(bit)) {
                tRoot->put(bit, new Node()); // Create node if not present
            }
            tRoot = tRoot->get(bit); // Move to the next bit
        }
    }

    // For a given number, find the maximum XOR it can achieve with any number in the trie
    int getMax(int num) {
        int maxNum = 0;
        Node* tRoot = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            // Prefer the opposite bit to maximize XOR
            if (tRoot->containsKey(1 - bit)) {
                maxNum |= (1 << i); // Set the i-th bit in the result
                tRoot = tRoot->get(1 - bit);
            } else {
                tRoot = tRoot->get(bit); // Fall back to the same bit if opposite doesn't exist
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        
        // Insert all numbers into the trie
        for (int num : nums) {
            trie->insert(num);
        }

        int maxXOR = 0;

        // For each number, compute max XOR with any other number using the trie
        for (int num : nums) {
            maxXOR = max(maxXOR, trie->getMax(num));
        }

        return maxXOR;
    }
};
