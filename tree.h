#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include  <iostream>
#include  <fstream>
#include  <cstdlib>
#include <vector>

using namespace std;

struct Node{
char c;
std::vector<Node*> v;
};
int factorial(int number) {
	int F = 1;
	for (int i = 1; i <= number; i++)
		F = F * i;
	return F / number;
}
class Tree {
 private:
   std::vector<char> base;
   

 public:
  std::vector<Node*> enter;
  Tree(std::vector<char> in) {
    base = in;
	enter = std::vector<Node*>(base.size());
	MakeTree(&enter, -1, base);	
  }

  bool MakeTree(std::vector<Node*> *v, int del_i, std::vector<char> base){
	  if (base.size() == 1) {
		cout << endl;
		return true;
	  }
	  std::vector<char> ch(base);
	  if (del_i>=0)
		ch.erase(ch.begin() + del_i);
	  int len = ch.size();
	  for (int i = 0; i < len; i++) {
		  (*v)[i] = new Node{ ch[i],std::vector<Node*>(len - 1) };
		  cout << ch[i];
		  MakeTree(&((*v)[i]->v), i, ch);
	  }
		  return true;
  }	
};
#endif  // INCLUDE_TREE_H_