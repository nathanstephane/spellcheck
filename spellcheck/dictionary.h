#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

#define  LENGHT_W 45 //max lenght for a word

bool load();
unsigned int size(void);
bool check(const char* word);

//Gets rid of all the memory the program took up.
void unload();

#endif // !DICTIONARY_H
