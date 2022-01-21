#include <iostream>
#include <bits/stdc++.h>

const int ALPHABET_SIZE = 26;

using namespace std;

struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];
	bool isEndOfWord; //returns true if at the end of a word (meaning it is complete)
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode()
{
	struct TrieNode *pNode = new TrieNode;
	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}


void insert(struct TrieNode *root, string key)
{
	struct TrieNode *iterator = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!iterator->children[index])
			iterator->children[index] = getNode();

		iterator = iterator->children[index];
	}
	iterator->isEndOfWord = true;
}

// Searches word in trie
int search(struct TrieNode *root, string key)
{
	struct TrieNode *iterator = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!iterator->children[index]) return 0;

		iterator = iterator->children[index];
	}

	return(iterator->isEndOfWord);
}

int main()
{
	//inputs n and m
	int n, m;
	cin >> n >> m;


	string word;
	struct TrieNode *root = getNode();
	//Inserts n words into the tree
	//in this case just creates a tree with word=word
	for (int i = 0; i < n; i++) {
        cin >> word;
        insert(root, word);
	}

    //list of words to search
	string lista[m];
	for (int i = 0; i < m; i++) cin >> lista[i];

	//searches in the tree just made
	for (int i = 0; i < m; i++) cout << search(root, lista[i])<< endl;

	return 0;
}
