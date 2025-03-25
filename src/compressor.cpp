#include "../include/compressor.h"
#include<unordered_map>
#include<string>
#include<bitset>
using namespace std;

void  compressFile(const string& inputFile , const string& outputFile)
{
    ifstream inFile(inputFile, ios::binary);

    if(!inFile)
    {
        cout<<"Error : Not opening input file!"<<endl;
        return;
    }

    unordered_map<char , int> freqMap;
    char ch;
    while(inFile.get(ch))
    {
        freqMap[ch]++;
    }

    inFile.clear();
    inFile.seekg(0);

    Node* root = buildHuffmanTree(freqMap);

    unordered_map<char , string> huffmanCode;

    generateCode(root , "" , huffmanCode);

    ofstream outFile(outputFile,ios::binary);
    
    size_t freqSize = freqMap.size();
    outFile.write(reinterpret_cast<const char *>(&freqSize),sizeof(size_t));

    for(auto &pair:freqMap)
    {
        outFile.put(pair.first);
        outFile.write(reinterpret_cast<const char *>(&pair.second),sizeof(pair.second));
    }

    string encodedText = "";

    while(inFile.get(ch))
    {
        encodedText+=huffmanCode[ch];
    }
   
    int extraBits = 8-(encodedText.size()%8);
    for(int i = 0 ; i < extraBits ; i++)
    {
        encodedText+="0";
    }

    outFile.write(reinterpret_cast<const char *>(&extraBits) , sizeof(extraBits));

    for(size_t i = 0 ; i < encodedText.size(); i+=8)
    {
        bitset<8> byte(encodedText.substr(i,8));
        outFile.put(static_cast<unsigned char>(byte.to_ulong()));
    }

    inFile.close();
    outFile.close();
    cout<<"File compressed successfully!"<<endl;

}