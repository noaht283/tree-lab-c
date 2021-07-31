// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include "TreeNode.h"
#include <stack>
using namespace std;

// Constructor
TreeCalc::TreeCalc() {
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
  cleanTree(expressionStack.top());
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
    if (tree == NULL){
    return;
  }
  else {
    cleanTree(tree->left);
    cleanTree(tree->right);
    delete tree;
  }  
}


// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
  TreeNode *node = new TreeNode(val);
  if (val=="+" || val=="-"||val=="*"||val=="/"){
    node->right = expressionStack.top();
    expressionStack.pop();
    node->left = expressionStack.top();
    expressionStack.pop();
    expressionStack.push(node);
  }
  
  else{
    expressionStack.push(node);
  }
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
  if (tree == NULL){
    return;
  }
  else {
    cout<< tree->value << " ";
    printPrefix(tree->left);
    printPrefix(tree->right);
  }
  
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
  string num = tree->value;
  if (tree == NULL){
    return;
  }
  else if (num== "+" || num=="-"|| num=="*" || num== "/") {
      cout<< "("<< " ";
      printInfix(tree->left);
      cout<< num<< " ";
      printInfix(tree->right);
      cout<< ")"<< " ";
    }
  else{
    cout<< num<< " ";
  }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
  if (tree == NULL){
    return;}
  else {
    printPostfix(tree->left);
    printPostfix(tree->right);
    cout <<tree->value<<" ";
  }
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
  string pointee = tree->value;
  int num = 0;
  if (tree->left != NULL) {
    int right1 = calculate(tree->right);
    int left1 = calculate(tree->left);
    if (pointee[0] == '-') {
      return (left1-right1);
    }
    else if (pointee[0]== '+') {
      return (left1 +right1);
    }
    else if (pointee[0]== '/'){
      return (left1 / right1);
    }
    else if (pointee[0]== '*'){
      return(left1 * right1);
    }}
  if (tree->left== NULL && tree->right==NULL){
    num += (atoi(pointee.c_str()));
    return num;}  ;// Traverse the tree and calculates the result
    return 0;
}

//Calls calculate, sets the stack back to a blank stack
 public calculate() method. Hides private data from user
 int TreeCalc::calculate() {
    // call private calculate method here
   calculate(expressionStack.top());
    return 0;
}
