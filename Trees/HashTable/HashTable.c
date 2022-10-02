#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Length of the longest word
#define LENGTH 45

// Represents a node in the hash table
typedef struct node {
    char word[LENGTH + 1];
    struct node *next;
} node;

// Hash tables size
#define TABLE_SIZE 10000

// Hash table
node *table[TABLE_SIZE];

// Hash function for strings
unsigned int hash(char *str) {
	unsigned int hashval;

	for (hashval = 0; *str != '\0'; str++)
		hashval = *str + 31*hashval;

	return hashval % TABLE_SIZE;
}

// Prints the hash table
void print_table(void) {
	// Iterate over the hash table
	for (int i = 0; i < TABLE_SIZE; i++){

		// Print the index
		printf("Index %i: ", i);

		// If the head node is not empty print the linked list
		if (table[i] != NULL) {
			// Create a temporary cursor
			node *cursor = table[i];

			// While there is a next node
			while (cursor != NULL) {

				// Print the word in the current node
				printf("%s", cursor->word);

				// If there is a next node
				if (cursor->next != NULL) {
					// Print a comma
					printf(", ");
				}

				// Move the cursor to the next node
				cursor = cursor->next;
			}
		}
		// Print a new line after each iteration of the hash table
		printf("\n");
	}
}

// Adds a word to the hash table
void add_word(char *word) {
	// Allocate space for a new node
	node *new = malloc(sizeof(node));

	// Copy the given word to the new nodes word
	strcpy(new->word, word);

	// Get the hash of the word
	unsigned int word_hash = hash(word);

	// If there is no head node at that index
	if (table[word_hash] == NULL) {
		// Set the head node to be the new node
		table[word_hash] = new;
	}

	// If there is already a head node
	else {
		// Set the new node to point to what the head node is pointing
		new->next = table[word_hash]->next;

		// Set the head node to point to the new node
		table[word_hash]->next = new;
	}
}

// Removes a word from the hash table
bool remove_word(char *word) {
	// Get the hash of the word
	unsigned int word_hash = hash(word);

	// If there is no head node at that index
	if (table[word_hash] == NULL) {
		// Return false
		return false;
	}

	// If the head node contains the given word
	else if (strcmp(table[word_hash]->word, word) == 0) {
		// Create a temporary node that points to the head node
		node *temp = table[word_hash];

		// Set the head node to be the next node
		table[word_hash] = table[word_hash]->next;

		// Free the temporary node
		free(temp);

		// Return true
		return true;
	}

	// If there is a head node and the head node does not contain the given word
	else {
		// Create a temporary cursor
		node *cursor = table[word_hash];

		// Create two temporary nodes to link the nodes that come before and after the given word
		node *temp_back = NULL;
		node *temp_front = cursor->next;

		// While there is a next node
		while (cursor->next != NULL) {

			// Set the back temporary node to the cursor
			temp_back = cursor;

			// Move the cursor to the next node
			cursor = cursor->next;

			// Set the front temporary node to the node that comes after the cursor
			temp_front = cursor->next;

			// If the word is in the cursor node
			if (strcmp(cursor->word, word) == 0){
				// Free the cursor node
				free(cursor);

				// Set the back temporary node to point to the front temporary node
				temp_back->next = temp_front;
				
				// Return true
				return true;
			}
		}
	}

	// If the word is not in any nodes return false
	return false;
}

// Checks if the given word is in the hash table
bool check_word(char *word) {
	// Get the hash of the word
	unsigned int word_hash = hash(word);

	// If there is no head node at that index
	if (table[word_hash] == NULL) {
		// Return false
		return false;
	}
	
	// If there is a head node at that index
	else {
		// Create a temporary cursor
		node *cursor = table[word_hash];

		// While there is a next node
		while (cursor != NULL) {

			// If the word is in the current node
			if (strcmp(cursor->word, word) == 0){
				// Return true
				return true;
			}

			// Move the cursor to the next node
			cursor = cursor->next;
		}
	}

	// If the word is not in any nodes return false
	return false;
}

// Returns the number of words in the hash table
unsigned int get_size() {
	unsigned int count = 0;

	// For each index of the hash table
	for (int i = 0; i < TABLE_SIZE; i++) {
		// Create a temporary cursor
		node *cursor = table[i];

        // While there is a next node
        while (cursor != NULL) {
        	// Move the cursor to the next node
        	cursor = cursor->next;

        	// Increment the count
            count++;
        }
    }
    return count;
}

// Unloads all the allocated memory for the hash table
void unload_table(void) {
	// Iterate over the hash table
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        // Create a temporary cursor
        node *cursor = table[i];

        // While there is a next node
        while (cursor != NULL)
        {
            // Create a temporary node to free nodes
            node *temp = cursor;

            // Move the cursor to the next node
            cursor = cursor->next;

            // Free the temporary node
            free(temp);
        }

        // Set the head node to null
        table[i] = NULL;
    }
}
