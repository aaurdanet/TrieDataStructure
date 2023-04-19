#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct Trie{
int count;
struct Trie  *children[26];

};

void insert(struct Trie **ppTrie, char *word) {
    if (ppTrie == NULL || word == NULL) {
        return;
    }
    struct Trie *pCurrent = *ppTrie;
    while (*word != '\0') {
        char c = tolower(*word);
        int index = c - 'a';
        if (pCurrent->children[index] == NULL) {
            pCurrent->children[index] = calloc(1, sizeof(struct Trie));
            pCurrent->children[index]->count = 0;
        }
        pCurrent = pCurrent->children[index];
        word++;
    }
    pCurrent->count++;
}


int numberOfOccurances(struct Trie *pTrie, char *word) {
    if (pTrie == NULL || word == NULL) {
        return 0;
    }
    struct Trie *pCurrent = pTrie;
    while (*word != '\0') {
        char c = tolower(*word);
        int index = c - 'a';
        if (pCurrent->children[index] == NULL) {
            return 0;
        }
        pCurrent = pCurrent->children[index];
        word++;
    }
    return pCurrent->count;
}

struct Trie *deallocateTrie(struct Trie *pTrie) {
    if (pTrie == NULL) {
        return NULL;
    }
    for (int i = 0; i < 26; i++) {
        pTrie->children[i] = deallocateTrie(pTrie->children[i]);
    }
    free(pTrie);
    return NULL;

}


int main(void) {
    //read the number of the words in the dictionary
    // parse line by line, and insert each word to the trie data structure
    struct Trie *trie = calloc(1, sizeof(struct Trie));
    char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
    for (int i = 0; i < 5; i++) {
        insert(&trie, pWords[i]);
    }
    for (int i = 0; i < 5; i++) {
        printf("\t%s : %d\n", pWords[i], numberOfOccurances(trie, pWords[i]));
    }
    trie = deallocateTrie(trie);
    if (trie != NULL) {
        printf("There is an error in this program\n");
    }
    return 0;
}