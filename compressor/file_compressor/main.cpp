#include <iostream>
#include <string>
#include "huffman.h"

void printUsage() {
    std::cout << "Usage: filecompressor [-c|-d] <inputfile> <outputfile>\n";
    std::cout << "  -c: Compress the input file\n";
    std::cout << "  -d: Decompress the input file\n";
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printUsage();
        return 1;
    }

    std::string option = argv[1];
    std::string inputFile = argv[2];
    std::string outputFile = argv[3];

    if (option == "-c") {
        // Compression mode
        std::unordered_map<char, int> freqTable = buildFrequencyTable(inputFile);
        if (freqTable.empty()) {
            std::cerr << "Error: Could not read input file for compression.\n";
            return 1;
        }

        Node* huffmanTree = buildHuffmanTree(freqTable);
        std::unordered_map<char, std::string> huffmanCodes;
        generateCodes(huffmanTree, "", huffmanCodes);

        compressFile(inputFile, outputFile, huffmanCodes);
        std::cout << "File successfully compressed to " << outputFile << std::endl;

        freeHuffmanTree(huffmanTree);
    }
    else if (option == "-d") {
        // Decompression mode
        std::unordered_map<char, int> freqTable = buildFrequencyTable(inputFile);  // Same frequency table needed for decompression
        if (freqTable.empty()) {
            std::cerr << "Error: Could not read input file for decompression.\n";
            return 1;
        }

        Node* huffmanTree = buildHuffmanTree(freqTable);
        decompressFile(inputFile, outputFile, huffmanTree);
        std::cout << "File successfully decompressed to " << outputFile << std::endl;

        freeHuffmanTree(huffmanTree);
    }
    else {
        std::cerr << "Invalid option: " << option << std::endl;
        printUsage();
        return 1;
    }

    return 0;
}