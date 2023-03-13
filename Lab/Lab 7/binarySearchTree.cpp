/*
 * Name: Grayson Whitaker
 * Date Submitted: 3/31/2023
 * Lab Section: 002
 * Assignment Name: Lab 7: Binary Search Tree
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <assert.h>

#include "binarySearchTree.h"

using namespace std;

void fix_size(Node *T)
{
  T->size = 1;
  if (T->left) T->size += T->left->size;
  if (T->right) T->size += T->right->size;
}

// insert key k into tree T, returning a pointer to the resulting tree
Node *insert(Node *T, int k)
{
  if (T == nullptr) return new Node(k);
  if (k < T->key) T->left = insert(T->left, k);
  else T->right = insert(T->right, k);
  fix_size(T);
  return T;
}

// returns a vector of key values corresponding to the inorder traversal of T (i.e., the contents of T in sorted order)
vector<int> inorder_traversal(Node *T)
{
  vector<int> inorder;
  vector<int> rhs;
  if (T == nullptr) return inorder;
  inorder=inorder_traversal(T->left);
  inorder.push_back(T->key);
  rhs=inorder_traversal(T->right);
  inorder.insert(inorder.end(), rhs.begin(), rhs.end());
  return inorder;
}

// return a pointer to the node with key k in tree T, or nullptr if it doesn't exist
Node *find(Node *T, int k)
{
  // if node doesn't exist, return nullptr
  if(!T) return nullptr;
  // if key is found, return T, else recurse left or right
  if(T->key == k) return T;
  if(T-> key < k) return find(T->right, k);
  return find(T->left, k);
}

// return pointer to node of rank r (with r'th largest key; e.g. r=0 is the minimum)
Node *select(Node *T, int r)
{
  assert(T!=nullptr && r>=0 && r<T->size);

  int leftSize = 0;
  if(T->left) leftSize = T->left->size;
  // if r is the size of the left subtree, return T
  if(r == leftSize) return T;
  // if r is less than the size of the left subtree, recurse left
  if(r < leftSize) return select(T->left, r);
  // else recurse right
  return select(T->right, r - leftSize - 1);
}

// Join trees L and R (with L containing keys all <= the keys in R)
// Return a pointer to the joined tree.  
Node *join(Node *L, Node *R)
{
  // choose either the root of L or the root of R to be the root of the joined tree
  // (where we choose with probabilities proportional to the sizes of L and R)
  
  int leftSize = 0;
  int rightSize = 0;

  if(L) leftSize = L->size;
  else return R;
  if(R) rightSize = R->size;
  else return L;

  // probability of choosing L is leftSize/(leftSize+rightSize), and probability of choosing R is rightSize/(leftSize+rightSize)
  if(rand() % (leftSize + rightSize) < leftSize){
    // join L's right subtree with R
    L->right = join(L->right, R);
    // fix size of L
    fix_size(L);
    // return L
    return L;
  }
  else{
    // join R's left subtree with L
    R->left = join(L, R->left);
    // fix size of R
    fix_size(R);
    // return R
    return R;
  }
}

// remove key k from T, returning a pointer to the resulting tree.
// it is required that k be present in T
Node *remove(Node *T, int k)
{
  assert(T != nullptr);
  // if k is less than the key of T, remove k from T's left subtree
  if(k < T->key){
    T->left = remove(T->left, k);
  }
  // if k is greater than the key of T, remove k from T's right subtree
  else if(k > T->key){
    T->right = remove(T->right, k);
  }
  // if k is equal to the key of T, join T's left and right subtrees if they exist
  else{
    Node *temp = T;
    if(T->left && T->right){
      T = join(T->left, T->right);
    }
    else if(T->left){
      T = T->left;
    }
    else if(T->right){
      T = T->right;
    }
    else{
      T = nullptr;
    }
    // delete node
    delete temp;
  }
  // fix size of T
  if(T) fix_size(T);
  // return T
  return T;
}

// Split tree T on key k into tree L (containing keys <= k) and a tree R (containing keys > k)
void split(Node *T, int k, Node **L, Node **R)
{
  // if T is empty, return empty trees L and R
  if(!T){
    *L = nullptr;
    *R = nullptr;
    return;
  }
  // if k is less than the key of T, split T's left subtree on k
  if(k < T->key){
    // split T's left subtree on k
    split(T->left, k, L, &T->left);
    // set R to T
    *R = T;
  }
  else{
    // split T's right subtree on k
    split(T->right, k, &T->right, R);
    // set L to T
    *L = T;
  }
  // fix size of T
  fix_size(T);

}

// insert key k into the tree T, returning a pointer to the resulting tree
Node *insert_random(Node *T, int k)
{
  // with probability 1/N, insert k at the root of T, otherwise, insert_random k recursively left or right of the root of T
  // if T is empty, create a new node with key k
  if(!T){
    T = new Node(k);
  }
  // with probability 1/N, insert k at the root of T
  else if(rand() % (T->size + 1) == 0){
    // split T on k
    Node *L, *R;
    split(T, k, &L, &R);
    // create new node with key k
    T = new Node(k);
    // set T's left and right subtrees to L and R
    T->left = L;
    T->right = R;
  }
  // insert_random k recursively left or right of the root of T
  else if(k < T->key){
    T->left = insert_random(T->left, k);
  }
  else{
    T->right = insert_random(T->right, k);
  }
  // fix size of T
  fix_size(T);

  // return T
  return T;
}

void printVector(vector<int> v)
{
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

// int main(void)
// {
//   vector<int> inorder;
//   vector<int> A(10,0);
  
//   // put 0..9 into A[0..9] in random order
//   for (int i=0; i<10; i++) A[i] = i;
//   for (int i=9; i>0; i--) swap(A[i], A[rand()%i]);
//   cout << "Contents of A (to be inserted into BST):\n";
//   printVector(A);
  
//   // insert contents of A into a BST
//   Node *T = nullptr;
//   for (int i=0; i<10; i++) T = insert(T, A[i]);
  
//   // print contents of BST (should be 0..9 in sorted order)
//   cout << "Contents of BST (should be 0..9 in sorted order):\n";
//   inorder=inorder_traversal(T);
//   printVector(inorder);

//   // test select
//   for (int i=0; i<10; i++) {
//     Node *result = select(T, i);
//     if (!result || result->key != i) cout << "Select test failed for select(" << i << ")!\n";
//     else cout << "Select test passed for select(" << i << ")\n";
//   }

//   // test find: Elements 0..9 should be found; 10 should not be found
//   cout << "Elements 0..9 should be found; 10 should not be found:\n";
//   for (int i=0; i<11; i++) 
//     if (find(T,i)) cout << i << " found\n";
//     else cout << i << " not found\n";

//   // test split
//   Node *L, *R;
//   split(T, 4, &L, &R);
//   cout << "Contents of left tree after split (should be 0..4):\n";
//   inorder=inorder_traversal(L);
//   printVector(inorder);
//   cout << "Left tree size " << L->size << "\n";
//   cout << "Contents of right tree after split (should be 5..9):\n";
//   inorder=inorder_traversal(R);
//   printVector(inorder);
//   cout << "Right tree size " << R->size << "\n";
    
//   // test join
//   T = join(L, R);
//   cout << "Contents of re-joined tree (should be 0..9)\n";
//   inorder=inorder_traversal(T);
//   printVector(inorder);
//   cout << "Tree size " << T->size << "\n";
  
//   // test remove
//   for (int i=0; i<10; i++) A[i] = i;
//   for (int i=9; i>0; i--) swap(A[i], A[rand()%i]);
//   for (int i=0; i<10; i++) {
//     T = remove(T, A[i]);
//     cout << "Contents of tree after removing " << A[i] << ":\n";
//     inorder=inorder_traversal(T);
//     printVector(inorder);
//     if (T != nullptr)
//       cout << "Tree size " << T->size << "\n";
//   }

//   // test insert_random
//   cout << "Inserting 1 million elements in order; this should be very fast...\n";
//   for (int i=0; i<1000000; i++) T = insert_random(T, i);
//   cout << "Tree size " << T->size << "\n";
//   cout << "Done\n";
  
//   return 0;
// }
