/*-----------------------------Use This Class For TreeClass----------------------------------*/
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
	TreeNode<T>** children;
	int childCount;
    	int maxChildCount;
	public:
		T data;
		
		TreeNode(T data) {
			this->data = data;
			childCount = 0;
			children = new TreeNode<T>*[10];
		   	maxChildCount = 10;
        }	

		int numChildren() {
			return childCount;
		}

		void addChild(TreeNode<T>* child) {
			children[childCount] = child;
			childCount++;
            if(childCount == maxChildCount) {
	            TreeNode<T>** childrenNew = new TreeNode<T>*[2*maxChildCount];
        	    for(int i = 0; i < maxChildCount; i++) {
	                childrenNew[i] = children[i];
        	     }
	        	 maxChildCount *= 2;
        	        children = childrenNew;
	        }
		}

		TreeNode<T>* getChild(int index) {
			return children[index];
		}

		void setChild(int index, TreeNode<T>* child) {
			children[index] = child;
		}
    
    void removeChild(int i) {
        for(int j = i + 1; j < childCount; j++) {
            children[j - 1] = children[j];
        }
        childCount--;
    }
};

template <typename T>
class Queue {
	T* data;
	int capacity;
	int nextIndex;
	int firstIndex;
	int length;

	public:
		Queue() {
			capacity = 10;
			data = new T[capacity];
			length = 0;
			nextIndex = 0;
			firstIndex = -1;
		}
		
		int size() {
			return length;
		}

		bool isEmpty() {
			return length == 0;
		}

		T front() {
			if (length == 0) {
				return 0;
			}
			return data[firstIndex];
		}
		
		T dequeue() {
			if (length == 0) {
				return 0;
			}

			T output = data[firstIndex];
			length--;
			firstIndex = (firstIndex + 1)%capacity;
			if (length == 0) {
				firstIndex = -1;
				nextIndex = 0;
			}
			return output;
		}

		void enqueue(T element) {
			if (length == capacity) {
				T* temp = data;
				capacity = 2* capacity;
				data = new T[capacity];
				int k = 0;
				for (int i = firstIndex; i < length; i++) {
					data[k] = temp[i];
					k++;
				}
				for (int i = 0; i < firstIndex; i++) {
					data[k] = temp[i];
					k++;
				}
				delete [] temp;
				firstIndex = 0;
				nextIndex = length;
			}
			data[nextIndex] = element;
			length++;
			nextIndex = (nextIndex + 1) % capacity;
			if (firstIndex == -1) {
				firstIndex = 0;
			}
		}

		~Queue() {
			delete [] data;
		}


};

/*----------------------------------------------------------------------------------------*/


TreeNode<int>* removeLeafNodes(TreeNode<int>* root) {
	if(root == NULL) {
        return NULL;
    } else if (root -> numChildren() == 0) {
        return NULL;
    }
    
    for(int i = 0; i < root -> numChildren(); i++) {
        TreeNode<int> *temp = root -> getChild(i);
        if(temp -> numChildren() == 0) {
            int j = i;
			for(;j < root -> numChildren() - 1; j++) {
                root -> setChild(j, root -> getChild(j + 1)); 
            }
            root -> removeChild(j);
            i--;
        }
    }
    
    for(int i = 0; i < root -> numChildren(); i++) {
        TreeNode<int> *temp = removeLeafNodes(root -> getChild(i));
        root -> setChild(i,temp);
    }
    return root;
}

/*
Problem statement
Remove all leaf nodes from a given generic Tree. Leaf nodes are those nodes, 
which don't have any children.

Note : Root will also be a leaf node if it doesn't have any child. 
You don't need to print the tree, just remove all leaf nodes and return the updated root.

Detailed explanation ( Input/output format, Notes, Images )

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 

Sample Output 1 : (Level wise, each level in new line)
10
20
*/