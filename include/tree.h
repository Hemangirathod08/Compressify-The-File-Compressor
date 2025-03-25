#ifndef TREE_H
#define TREE_H

#include<iostream>
#include<fstream>
#include<unordered_map>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c , int f,Node* l = nullptr , Node* r = nullptr)
    {
        ch = c;
        freq = f;
        left = l;
        right = r;
    }

};

struct comparator{
    bool operator()(Node* l , Node*r)
    {
        return l->freq>r->freq;
    }
};

Node* buildHuffmanTree(unordered_map<char , int> &freqMap);
void generateCode(Node* root, string code, unordered_map<char , string> &huffmanCode);
#endif