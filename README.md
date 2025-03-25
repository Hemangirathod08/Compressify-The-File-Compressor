# COMPRESSIFY - FILE COMPRESSOR & DECOMPRESSOR

**Compressify** is a **C++-based file compression and decompression tool** that utilizes **Huffman Coding**, an efficient lossless compression algorithm. It reduces the size of text files while ensuring accurate reconstruction of the original data.

## Project Description

Compressify is designed to efficiently compress and decompress text files using **Huffman Coding**, a widely used lossless data compression algorithm. The project takes an input text file and analyzes the frequency of each character appearing in the file. Based on these frequencies, a **Huffman Tree** is constructed where characters with higher occurrences get shorter binary codes, while less frequent characters receive longer codes. This tree is then used to encode the text into a compressed binary format that significantly reduces the file size.

During decompression, the compressed file is read, and the **Huffman Tree** is reconstructed from the metadata stored during compression. Using this tree, the encoded binary data is converted back into its original text format, ensuring that the decompressed file is identical to the original. The implementation is efficient and optimized to handle large text files while preserving accuracy. Compressify supports **cross-platform compatibility**, making it usable on Windows, macOS, and Linux systems.

## How to Run This Project

### Prerequisites

Ensure you have:

- **C++ Compiler** 

### Compile the Code

```bash
make compressify
./compressify
```

### Usage

When you run the program, you will be prompted to select an option:

```bash
Would you like to:
1 - Compress a file
2 - Decompress a file
Enter your selection (1 or 2):
```

If you choose **compression**, the program will ask for:

- The name of the file to compress (e.g., `input.txt`)
- The desired name for the compressed file (e.g., `compressed.bin`)

Example:

```bash
Enter the name of the file you want to compress (e.g., input.txt): input.txt
Enter the desired name for the compressed file (e.g., compressed.bin): compressed.bin
```

If you choose **decompression**, the program will ask for:

- The name of the compressed file (e.g., `compressed.bin`)
- The desired name for the decompressed output file (e.g., `output.txt`)

Example:

```bash
Enter the name of the compressed file (e.g., compressed.bin): compressed.bin
Enter the desired name for the decompressed file (e.g., output.txt): output.txt
```



