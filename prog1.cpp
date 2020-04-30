// CS130A - Andrew Cizas - April 26, 2020
// prog1.cpp

#include "prog1.h";
#include <iostream>

using namespace std;

// Hash Table Methods

// Default Hash Table constructor
hashTable::hashTable() {}

// Hash Table Destructor
hashTable::~hashTable() {
  delete [] table;
}

// Hashing function
size_t hashTable::hash(std::string word) const {
  
 // Adds the ASCII values of each letter in the word and divides by table size
  size_t accumulator = 0;
  for (size_t i = 0; i < word.size(); i++) {
      accumulator += word.at(i);
    }
	 return accumulator % TABLESIZE;

}

// Finds the given word in the hash table if present and outputs word count
int hashTable::findHash(std::string word) const {

  int hashKey = hash(word);
  int wordCount = 0;

  // If the index at the hash key is empty, outputs wordCount = 0
  if (table[hashKey].empty()) {
    cout << word << " not found" << endl;
    return 0;
  }
  
  // If the index at the hash key is not empty, outputs word count 
  else {
    for (size_t i = 0; i < table{hashKey]; i++) {
      if (table[hashKey][i].first == word)
	wordCount = table[hashKey][i].second;
    }
    cout << word << " found, count = " << wordCount << endl;
    return 0;
  }
}

// Inserts the given word into the hash table and outputs word count
int hashTable::insertHash(std::string word){

  int wordCount = 0;
  int hashKey = hash(word);

  // Searches the index of the hash key to see if the word is already there
  for (size_t i = 0; i < table[hashKey].size(); i++){
      if (table[hashKey][i].first == word) {
	wordCount = table[hashKey][i].second + 1;
	table[hashKey][i].second += 1;
	cout << word << " inserted, new count = " << wordCount << endl;
	return 0;
      }
    }  
    // If word not found, adds a word pair in that index
    std::pair <std::string, int> newWord;
    newWord.first = validWord;
    newWord.second = 1;
    table[hashKey].push_back(newWord);
    wordCount = 1;
    // Returns a word count of 1
    cout << word << " inserted, new count = 1" << endl;
    return 0;
  }
}

// Deletes the given word from the hash table and outputs word count
int hashTable::deleteHash(std::string word){

  int wordCount = 0;
  int hashKey = hash(word);
  for (size_t i = 0; i < table[hashKey].size(); i++) {
      if (table[hashKey][i].first == word) {
	int number = table[hashKey][i].second;
	// If the word count is more than 1, removes 1 and returns word count
	if (number > 1) {
	  table[hashKey][i].second -= 1;
	  wordCount = table[hashKey][i].second;
	  cout << word << " deleted, new count = " << wordCount << endl;
	  return 0;
	}
	// If word count is 1, removes word from the table and returns 0
	else {
	  table[hashKey][i].second = 0;
	  wordCount = 0;
	  table[hashKey].erase(table[hashKey].begin()+i);
	  cout << word << " deleted, new count = 0" << endl;
	  return 0;
	}
      }
  }
}

// Outputs words alphabetically between the two given words
void hashTable::rangeSearchHash(std::string a, std::string b){

  // Creates a vector to store all words between a and b
  vector<std::pair<std::string, int>> temp;
  for (int i = 0; i < TABLESIZE; i++) {
    for (size_t j = 0; j < table[i].size(); j++) {
      // Compares the ASCII value of each word to those of a and b and adds it if it lies between them
      if (((table[i][j].first).compare(a) >= 0)||((table[i][j].first).compare(b) <= 0))
	temp.push_back(table[i][j]);
    }
  }
  // Sorts the vector of all words between a and b
  std::sort(temp.begin(), temp.end());
  for (int k = 0; k < temp.size(); k++){
    cout << temp[k].first << endl;
  }
}

// Binary Search Tree Methods

// Default Binary Search Tree Constructor
 BST::BST() : root(0){}

// Binary Search Tree Destructor
BST::~BST(){
  clear(root);
 }

// Finds the given word in the BST if present and outputs word count
void BST::findBST(std::string word){

  if (getNodeFor(word, root) != NULL)
   cout << word << " found, count = " << word << endl;
  
  else
    cout << word << " not found" << endl;
    
}

// Returns the node containing the given word or NULL if not present
BST::Node *BST::getNodeFor(std::string word, Node *n) const {

  if(n == NULL){
    return n;
  } else if (n->info < word) {
    return getNodeFor(word, n->right);
  } else {
    return getNodeFor(word, n->left);
  }
  
}

// Inserts the given word to the BST and outputs word count
bool BST::insertBST(std::string word, Node *n){

  if (word == n->info)
    return false;
  if (word < n->info) {
    if (n->left)
      return insertBST(word, n->left);
    else {
      n->left = new Node(word);
      n->left->parent = n;
      return true;
    }
  } else {
    if (n->right)
      return insertBST(word, n->right);
    else {
      n->right = new Node(word);
      n->right->parent = n;
      return true;
    }
  }
}

// Helper function for insertBST
bool BST::insertBST(std::string word) {
  // handle special case of empty tree first
  if (!root) {
    root = new Node(word);
    return true;
  }
  // otherwise use recursive helper
  return insertBST(word, root);
}

// Deletes word from BST
bool BST::deleteBST(std::string word) {
  
  Node* n = getNodeFor(value, root);
  return deleteBST(n);

}

// Helper function for deleteBST
bool BST::deleteBST(Node* n){

  if (n == NULL) return 0;
  if (n->left == NULL && n->right == NULL) {
    if (n == n->parent->left)
      n->parent->left = NULL;
    if (n == n->parent->right)
      n->parent->right = NULL;
    delete n;
    return 0;
  } else if (n->left == NULL) {
    if (n == n->parent->left) {
      n->parent->left = n->right;
    }
    if (n == n->parent->right) {
      n->parent->right = n->right;
    }
    n->right->parent = n->parent;
    delete n;
    return 0;
  } else if (n->right == NULL) {
    if (n == n->parent->left) {
      n->parent->left = n->left;
    }
    if (n == n->parent->right) {
      n->parent->right = n->left;
    }
    n->left->parent = n->parent;
    delete n;
    return 0;
  } else {
    Node *succ = getSuccessorNode(n);
    std::swap(n->info, succ->info);
    return deleteBST(succ);
  }
}

// Returns minimum value on left side 
BST::Node *BST::min(Node* n) const {
  
  if (n == NULL) return NULL;
  if (n->left == NULL) return n;
  return min(n->left);
  
}

// Obtains successor node from given node
BST::Node *BST::getSuccessorNode(Node *n) const {
  if (!n)
    return NULL;
  if (n->right != NULL) {
    return min(n->right);
  } else {
    while (n && n != root && n->parent->left != n) {
      n = n->parent;
    }
    if (!n || n == root)
      return NULL;
    else
      return n->parent;
  }
}




// Outputs words alphabetically between the two given words 
BST::rangeSearchBST(std::string a, std::string b){

  vector<std::string> values;
  
  

}
