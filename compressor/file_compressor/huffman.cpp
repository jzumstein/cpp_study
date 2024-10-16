#include "huffman.h"

// Build the frequency table from the input file
std::unordered_map<char, int> buildFrequencyTable(const std::string& filename) {
    std::unordered_map<char, int> freqTable;
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return freqTable;
    }
    char ch;
    while (file.get(ch)) {
        freqTable[ch]++;
    }
    file.close();
    return freqTable;
}

// Build the Huffman Tree from the frequency table
Node* buildHuffmanTree(const std::unordered_map<char, int>& freqTable) {
    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;

    // Create a leaf node for each character and push it to the priority queue
    for (const auto& entry : freqTable) {
        pq.push(new Node(entry.first, entry.second));
    }

    // Build the tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create a new internal node with the sum of the two smallest frequencies
        Node* combined = new Node('\0', left->frequency + right->frequency);
        combined->left = left;
        combined->right = right;
        pq.push(combined);
    }

    return pq.top(); // The remaining node is the root of the Huffman Tree
}

// Generate Huffman codes from the Huffman Tree
void generateCodes(Node* root, const std::string& code, std::unordered_map<char, std::string>& huffmanCodes) {
    if (!root) return;

    // If this is a leaf node, assign the code to the character
    if (root->character != '\0') {
        huffmanCodes[root->character] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Compress the file using Huffman encoding
void compressFile(const std::string& inputFile, const std::string& outputFile, const std::unordered_map<char, std::string>& huffmanCodes) {
    std::ifstream input(inputFile, std::ios::binary);
    std::ofstream output(outputFile, std::ios::binary);
    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Error: Could not open input or output file." << std::endl;
        return;
    }

    std::string encodedString;
    char ch;
    while (input.get(ch)) {
        encodedString += huffmanCodes.at(ch);
    }

    // Write binary data to the file
    for (size_t i = 0; i < encodedString.size(); i += 8) {
        std::bitset<8> byte(encodedString.substr(i, 8));
        output.put(static_cast<unsigned char>(byte.to_ulong()));
    }

    if (encodedString.size() % 8 != 0) {
        std::bitset<8> byte(encodedString.substr(encodedString.size() - (encodedString.size() % 8)));
        output.put(static_cast<unsigned char>(byte.to_ulong()));
    }

    input.close();
    output.close();
}

// Decompress the file using Huffman decoding
void decompressFile(const std::string& compressedFile, const std::string& decompressedFile, Node* root) {
    std::ifstream input(compressedFile, std::ios::binary);
    std::ofstream output(decompressedFile, std::ios::binary);
    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Error: Could not open compressed or decompressed file." << std::endl;
        return;
    }

    Node* current = root;
    char ch;
    while (input.get(ch)) {
        std::bitset<8> byte(ch);
        for (int i = 0; i < 8; ++i) {
            if (byte.test(7 - i)) { // If the bit is 1
                current = current->right;
            }
            else { // If the bit is 0
                current = current->left;
            }

            // If we've reached a leaf node, output the character
            if (!current->left && !current->right) {
                output.put(current->character);
                current = root;
            }
        }
    }

    input.close();
    output.close();
}

// Free the memory used by the Huffman Tree
void freeHuffmanTree(Node* root) {
    if (root) {
        freeHuffmanTree(root->left);
        freeHuffmanTree(root->right);
        delete root;
    }
}
