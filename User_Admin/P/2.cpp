#include <bits/stdc++.h>
using namespace std;

// Huffman Tree Node
class Node
{
public:
    char ch;
    int freq;
    Node *left;
    Node *right;

    Node(char ch, int freq)
    {
        this->ch = ch;
        this->freq = freq;
        this->left = nullptr;
        this->right = nullptr;
    }

    Node(char ch, int freq, Node *left, Node *right)
    {
        this->ch = ch;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};

// Custom comparator for priority queue
class Compare
{
public:
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq;
    }
};

// Huffman Coding Class
class HuffmanCoding
{
private:
    Node *root;
    unordered_map<char, string> huffmanCode;

    void buildFrequencyMap(string text, unordered_map<char, int> &freq)
    {
        for (char ch : text)
        {
            freq[ch]++;
        }
    }

    void buildHuffmanTree(string text)
    {
        unordered_map<char, int> freq;
        buildFrequencyMap(text, freq);

        priority_queue<Node *, vector<Node *>, Compare> pq;

        for (auto pair : freq)
        {
            pq.push(new Node(pair.first, pair.second));
        }

        while (pq.size() != 1)
        {
            Node *left = pq.top();
            pq.pop();
            Node *right = pq.top();
            pq.pop();

            int sum = left->freq + right->freq;
            pq.push(new Node('\0', sum, left, right));
        }

        root = pq.top();
    }

    void generateCodes(Node *node, string str)
    {
        if (node == nullptr)
        {
            return;
        }

        if (!node->left && !node->right)
        {
            huffmanCode[node->ch] = str;
        }

        generateCodes(node->left, str + "0");
        generateCodes(node->right, str + "1");
    }

public:
    HuffmanCoding()
    {
        root = nullptr;
    }

    void compress(string text)
    {
        buildHuffmanTree(text);
        generateCodes(root, "");

        cout << "\n Huffman Codes:\n";
        for (auto pair : huffmanCode)
        {
            cout << pair.first << " : " << pair.second << "\n";
        }

        cout << "\nOriginal String:\n" << text << "\n";

        string encodedString = "";
        for (char ch : text)
        {
            encodedString += huffmanCode[ch];
        }

        cout << "\nEncoded String:\n" << encodedString << "\n";

        decode(encodedString);
    }

    void decode(string encoded)
    {
        cout << "\n Decoded String:\n";
        Node *curr = root;
        for (char bit : encoded)
        {
            if (bit == '0')
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }

            if (!curr->left && !curr->right)
            {
                cout << curr->ch;
                curr = root;
            }
        }
        cout << "\n";
    }
};

// Menu-Driven Program
int main()
{
    int choice;
    do
    {
        cout << "\n=====  Delhi Metro System - Algorithm Simulator =====\n";
        cout << "1. Optimize Passenger Data Storage (Huffman Coding)\n";
        
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // To clear newline left by cin

        switch (choice)
        {
        case 1:
        {
            cout << "\nEnter the text to compress (passenger data simulation): ";
            string text;
            getline(cin, text);

            HuffmanCoding huffman;
            huffman.compress(text);
            break;
        }
      

        case 0:
            cout << "\nThank you! Exiting the system.\n";
            break;

        default:
            cout << "\n Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
