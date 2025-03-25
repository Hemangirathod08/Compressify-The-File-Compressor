#include "../include/compressor.h"
#include "../include/decompressor.h"
#include<string>
using namespace std;

int main() {
    string inputFile;
    string compressedFile ;
    string decompressedFile;
    int choice;

    cout << "Would you like to:\n";
    cout << "1 - Compress a file\n";
    cout << "2 - Decompress a file\n";
    cout << "Enter your selection (1 or 2): ";    
    cin>>choice;

    if(choice==1)
    {
        cout << "You chose compression!" << endl;
        cout << "Enter the name of the file you want to compress (e.g., input.txt): ";
        cin >> inputFile;
        cout << "Enter the desired name for the compressed file (e.g., compressed.bin): ";
        cin >> compressedFile;

        compressFile(inputFile, compressedFile);
    }
    else if(choice==2)
    {
        cout << "You chose decompression!" << endl;
        cout << "Enter the name of the compressed file (e.g., compressed.bin): ";
        cin >> compressedFile;
        cout << "Enter the desired name for the decompressed file (e.g., output.txt): ";
        cin >> decompressedFile;

        decompressFile(compressedFile, decompressedFile);
    }
    else{
        cout<<"Enter valid choice!"<<endl;
    }
    return 0;
}