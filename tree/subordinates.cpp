#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <cmath>
#include <chrono>
 
using namespace std;

class TreeNode {
public:    
    TreeNode(int val) : val(val) {}
    
    ~TreeNode()
    {
        for (auto &child: children) {
            delete child;
        }
    }

    inline int getVal() const {return val;}
    inline vector<TreeNode*> getChildren() const {return children;}

    void addChild(TreeNode* child)
    {
        children.push_back(child);
    }
private:
    int val;
    vector<TreeNode*> children;
    
};

TreeNode* buildTree(int n, vector<int>& parentsList)
{
    vector<TreeNode*> nodes; nodes.reserve(n);
    for (int i = 0; i < n; i++) {
        nodes.push_back(new TreeNode(i));
    }
    for (int i = 0; i < parentsList.size(); i++) {
        nodes[parentsList[i] - 1]->addChild(nodes[i + 1]);
    }
    return nodes[0];
}

int getNumChildren(TreeNode* root, unordered_map<int,int>& m)
{
    int val = root->getVal();
    auto it = m.find(val);
    if (it != m.end()) {
        return it->second;
    }
    vector<TreeNode*> children = root->getChildren();
    if (children.size() == 0) {
        m[val] = 0;
        return 0;
    }
    int numChildren = 0;
    for (auto &child: children) {
        numChildren += 1 + getNumChildren(child, m);
    }
    m[val] = numChildren;
    return numChildren;
}

void solve(int n, vector<int>& parentsList)
{
    // TreeNode* root = buildTree(n, parentsList);
    unique_ptr<TreeNode> root(buildTree(n, parentsList));
    unordered_map<int,int> m;
    int rsl = getNumChildren(root.get(), m);
    for (int i = 0; i < n; i++) {
        cout << m[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n; cin >> n;
    vector<int> a; a.reserve(n-1);
    for (int i = 1; i < n; i++) {
        int num; cin >> num; a.push_back(num);
    }
    solve(n, a);
    return 0;
}