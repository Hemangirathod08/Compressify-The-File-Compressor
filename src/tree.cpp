#include "../include/tree.h"
#include<queue>
#include<unordered_map>

Node *buildHuffmanTree(unordered_map<char, int> &freqMap) {
    priority_queue<Node *, vector<Node *>, comparator> pq;
    for (auto &pair : freqMap)
        pq.push(new Node(pair.first, pair.second));

    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *newNode = new Node('\0', left->freq + right->freq, left, right);
        pq.push(newNode);
    }
    return pq.top();
}

void generateCode(Node *root, string code, unordered_map<char, string> &huffmanCode) {
    if (!root)
        return;
    if (!root->left && !root->right)
        huffmanCode[root->ch] = code;

    generateCode(root->left, code + "0", huffmanCode);
    generateCode(root->right, code + "1", huffmanCode);

}