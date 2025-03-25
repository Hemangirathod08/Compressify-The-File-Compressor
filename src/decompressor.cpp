#include "../include/decompressor.h"
#include<iostream>
#include<unordered_map>
#include<string>
#include<bitset>
using namespace std;
void decompressFile(const string& inputFile , const string& outputFile)
{
    ifstream inFile(inputFile, ios::binary);
    if(!inFile)
    {
        cout<<"Error opening input file!"<<endl;
        return;
    }

    unordered_map<char , int>freqMap;
    size_t freqMapSize ;
    inFile.read(reinterpret_cast<char *>(&freqMapSize),sizeof(size_t));

    for(size_t i = 0 ; i < freqMapSize ; i++)
    {
        char ch;
        int freq;
        inFile.get(ch);
        inFile.read(reinterpret_cast<char *>(&freq),sizeof(freq));
        freqMap[ch] = freq;
    }

    int extraBits;
    inFile.read(reinterpret_cast<char *>(&extraBits),sizeof(extraBits));

    Node* root = buildHuffmanTree(freqMap);

    string bitString="";
    char byte;
    while(inFile.get(byte))
    {
        bitString+=bitset<8>(byte).to_string();
    }
    bitString = bitString.substr(0 , bitString.size()-extraBits);

    ofstream outfile(outputFile , ios::binary);
    Node* curr = root;
    for(char bit:bitString)
    {
        curr = (bit=='0') ? curr->left : curr->right;
        if(!curr->left && !curr->right)
        {
            outfile.put(curr->ch);
            curr=root;
        }
    }

    inFile.close();
    outfile.close();
    cout<<"File decompressed successfully!"<<endl;
}