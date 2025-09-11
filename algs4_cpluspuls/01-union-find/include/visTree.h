#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode(int x) : val(x) {}
};

// 构建森林
vector<TreeNode*> buildForest(const vector<int>& parent) {
    int n = parent.size();
    vector<TreeNode*> nodes(n);
    
    // 创建所有节点
    for (int i = 0; i < n; i++) {
        nodes[i] = new TreeNode(i);
    }
    
    // 建立父子关系
    for (int i = 0; i < n; i++) {
        if (parent[i] != i) { // 如果不是根节点
            nodes[parent[i]]->children.push_back(nodes[i]);
        }
    }
    
    // 收集根节点（父节点等于自身的节点）
    vector<TreeNode*> roots;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i) {
            roots.push_back(nodes[i]);
        }
    }
    
    return roots;
}

// 可视化树（递归打印）
void printTree(TreeNode* root, int depth = 0, string prefix = "") {
    if (!root) return;
    
    // 打印当前节点
    string indent;
    for (int i = 0; i < depth; i++) {
        indent += "    ";
    }
    
    cout << indent << prefix << root->val << endl;
    
    // 递归打印所有子节点
    for (int i = 0; i < root->children.size(); i++) {
        string childPrefix = (i == root->children.size() - 1) ? "└── " : "├── ";
        printTree(root->children[i], depth + 1, childPrefix);
    }
}

// 可视化森林
void printForest(const vector<TreeNode*>& roots) {
    cout << "森林结构：" << endl;
    cout << "==========" << endl;
    
    for (int i = 0; i < roots.size(); i++) {
        cout << "树 " << i + 1 << ":" << endl;
        printTree(roots[i]);
        cout << endl;
    }
}