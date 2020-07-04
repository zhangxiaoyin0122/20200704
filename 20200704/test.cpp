#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> test() {
	vector<vector<int>> ret;
	vector<int> v;
	for (int i = 0; i < 3; i++) {
		for (int i = 0; i < 2; i++) {
			v.push_back(i);
		}
	}
	return ret;
}

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> q;
		if (root == nullptr)
			return  {};
		q.push(root);
		vector<vector<int>> ret;

		while (!q.empty()) {
			int sz = q.size();
			vector<int> row;
			while (sz-- > 0) {
				TreeNode* t = q.front();
				q.pop();
				row.push_back(t->val);
				if (t->left)
					q.push(t->left);
				if (t->right)
					q.push(t->right);
			}
			ret.push_back(row);
		}
		return ret;
	}
};

class Solution {
public:
	int myAtoi(string str) {
		long long num;
		if (str.empty()) {
			return 0;
		}
		int i = 0;
		while (str[i] == ' ') {
			i++;
		}
		bool fushu = false;
		while (str[i] == '+' || str[i] == '-') {
			if (str[i] == '-') {
				fushu = true;
			}
			i++;
		}
		int flag = fushu ? -1 : 1;
		while (str[i] >= '0' && str[i] <= '9') {
			num = num * 10 + flag * (str[i] - '0');
			if (num > 0x7fffffff) {
				return INT_MAX;
			}
			if (num < 0x80000000) {
				return INT_MIN;
			}
			i++;
		}
		return num;
	}
};