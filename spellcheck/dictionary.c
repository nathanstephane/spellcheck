#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#include "dictionary.h"

#define N 26

typedef struct node {
	bool isWord;
	struct node* children[N];

}node;

node* root;

bool load() {
	//Trie initialization
	root = malloc(sizeof(node));
	if (root ==NULL)
	{
		return false;
	}

	root->isWord = false;
	//children of root initialization as NULL
	for (size_t i = 0; i < N; i++)
	{
		root->children[i] = NULL;
		//Todo: Will be need as in the future we'll compare this to see if it's NULL
		//and if it's not set to anything then it'll throw an error.
	}

	//open dictionary file
	/**Load the correct dictonary words will be compared to*/
	FILE* file = fopen("words.txt", "r");
	if (file == NULL)
	{
		unload(); //free all memory prior to attempting file opening
		return false;
	}

	//buffer for each word
	char word[LENGHT_W + 1]; //+1 because of the terminary operator
	int indx;

	//insertion of each word into the trie
	while (fscanf(file,"%s", word) != EOF)
	{
		node* child = root; //because we always want to begin by the root node. :>
		for (int i = 0, len = strlen(word); i < len; i++)
		{
			indx = (int)word[i] - (int)'a';
			if (child->children == NULL) //node does not exist
			{	//create child
				child->children[indx] = malloc(sizeof(node));
				//if allocation failed
				if (child ->children[indx] == NULL) 
				{
					return false;
				}
				//
				child->children[indx]->isWord = false;
				for (int j = 0; j < N; j++)
				{
					child->children[indx]->children[j] = NULL;
				}

			}
		}
		child->isWord = true;
	}
}