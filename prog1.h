// CS130A - Andrew Cizas - April 26, 2020
// prog1.h

#ifndef PROG1_H
#define PROG1_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>

class hashTable {
 public:
  // Default constructor
  hashTable();

  // Destructor
  ~hashTable();

  // Finds word and outputs word count (if found)
  int findHash(std::string word) const;

  // Increments the word's word count or adds it if not already in the list, then outputs word count
  int insertHash(std::string word);

  // Deletes word or simply decrements if word count is more than 1, then outputs word count
  int deleteHash(std::string word);

  // Outputs all words alphabetically between and including a and b
  void rangeSearchHash(std::string a, std::string b) const;
  
 private:
  // Capacity of the hash table
  const static size_t TABLESIZE = 10000;

  // Hash table array of vectors
  std::vector<std::pait<std::string, int> > table[TABLESIZE];

  // Hash function that returns an index for the hash table
  size_t hash(std::string word) const;

};

class BST {
 public:
  
  // Node structure 
  struct Node{
    std::string info;
    int count;
    Node *left, *right, *parent;
  Node(std::string v = "") : info(v), count(0), left(0), right(0), parent(0) { }
    };
  Node *root;

  // Default constructor
  BST();

  // Destructor
  ~BST();

   // Finds word and outputs word count (if found)
  int findBST(std::string word) const;

  // Increments the word's word count or adds it if not already in the list, then outputs word count
  bool insertBST(std::string word);

  // Deletes word and/or decrements the word count
  bool deleteBST(std::string word);

  // Helper function for deleteBST
  bool deleteBST(Node* n);

  // Returns minimum node on left (helper for deleteBST)
  

  // Retrieves the node of the successor to any given node (helper to deleteBST)
  Node* getSuccessor(Node *n) const;

  // Outputs all words alphabetically between and including a and b
  void rangeSearchBST(std::string a, std::string b) const;
    
 private:

  // Returns node for a given value
  Node* getNodeFor(int value, Node* n) const;

  // For destructor
  void clear(Node *n);

  bool insertBST(std::string word, Node *n) const;

  // For destructor
  void clear(Node *n);

  // Returns minimum node on left (helper for deleteBST)
  Node* min(Node *n) const;

  int insertBST(int value, node *n)
};

#endif
  


