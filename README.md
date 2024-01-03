Trie Data Structure Implementation

This C program implements a simple Trie data structure. Tries are tree-like structures used to efficiently store and search for a dynamic set of strings, making them useful for tasks like dictionary lookups or autocomplete functionalities.
Trie Structure

The struct Trie defines the basic structure of a Trie node, where each node represents a character in a word. It contains an integer count to store the number of occurrences of a specific word and an array children to link to the next characters in the word.

c

struct Trie {
    int count;
    struct Trie *children[26];  // Assuming only lowercase English letters
};

Functions
void insert(struct Trie **ppTrie, char *word)

This function inserts a word into the Trie. It traverses the Trie character by character, creating new nodes if necessary, and increments the count for the last character.
int numberOfOccurrences(struct Trie *pTrie, char *word)

Given a Trie and a word, this function returns the number of occurrences of that word in the Trie. It traverses the Trie character by character and returns the count for the last character.
struct Trie *deallocateTrie(struct Trie *pTrie)

This recursive function deallocates the memory used by the Trie, freeing each node and its children.
Example Usage

The main function provides a simple example of using the Trie. It initializes a Trie, inserts a set of words, prints the occurrences of each word, and then deallocates the Trie.

c

int main(void) {
    struct Trie *trie = calloc(1, sizeof(struct Trie));
    char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
    
    // Insert words into the Trie
    for (int i = 0; i < 5; i++) {
        insert(&trie, pWords[i]);
    }

    // Print the occurrences of each word
    for (int i = 0; i < 5; i++) {
        printf("\t%s : %d\n", pWords[i], numberOfOccurrences(trie, pWords[i]));
    }

    // Deallocate the Trie
    trie = deallocateTrie(trie);

    // Check for deallocation success
    if (trie != NULL) {
        printf("Error in Trie deallocation\n");
    }

    return 0;
}

Feel free to adapt and integrate this Trie implementation into your projects as needed.
