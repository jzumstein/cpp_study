#pragma once
#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <fstream>
#include <bitset>

struct Node
{
	char character;
	int frequency;
	Node* left;
	Node* right;

	Node(char c, int f) : character(c), frequency(f), left(nullptr), right(nullptr) {}
};

struct Compare
{
	bool operator()(Node* left, Node* right)
		{
			return left->frequency > right->frequency;
		}
};

std::unordered_map<char, int> buildFrequencyTable(const std::string& filename);

Node* buildHuffmanTree(const std::unordered_map<char, int>& freqTable);

void generateCodes(Node* root, const std::string& code, std::unordered_map<char, std::string>& huffmanCodes);

void compressFile(const std::string& inputFile, const std::string& outputFile, const std::unordered_map<char, std::string>& huffmanCodes);

void decompressFile(const std::string& compressedFile, const std::string& decompressedFile, Node* root);

void freeHuffmanTree(Node* root);

#endif // HUFFMAN_H