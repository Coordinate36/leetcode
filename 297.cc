#include <iostream>
#include <deque>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string rst;
		deque<TreeNode*> Q;
		Q.emplace_back(root);
		TreeNode* node;
		while (!Q.empty()) {
			node = Q.front();
			Q.pop_front();
			if (node != nullptr) {
				rst += to_string(node->val) + " ";
				Q.push_back(node->left);
				Q.push_back(node->right);
			} else {
				rst += "N ";
			}
		}
		return rst;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data[0] == 'N') {
			return nullptr;
		}
		deque<TreeNode*> Q;
		int sep = data.find_first_of(" ");
		TreeNode* root = new TreeNode(stoi(data.substr(0, sep)));
		Q.push_back(root);
		TreeNode* current;
		int begin = sep + 1;
		while (!Q.empty()) {
			current = Q.front();
			Q.pop_front();
			if (current == nullptr) {
				continue;
			}
			
			int next = data.find_first_of(" ", begin);
			TreeNode* node = (data[begin] == 'N') ? nullptr : (new TreeNode(stoi(data.substr(begin, next - begin))));
			Q.push_back(node);
			current->left = node;
			begin = next + 1;

			next = data.find_first_of(" ", begin);
			node = (data[begin] == 'N') ? nullptr : (new TreeNode(stoi(data.substr(begin, next - begin))));
			Q.push_back(node);
			current->right = node;
			begin = next + 1;
		}
		return root;
	}
};

int main() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	TreeNode* node = root->right;
	node->left = new TreeNode(4);
	node->right = new TreeNode(5);
	Codec codec;
	cout << codec.serialize(root);
	return 0;
}	
	// Your Codec object will be instantiated and called as such:
	// Codec codec;
	// codec.deserialize(codec.serialize(root));