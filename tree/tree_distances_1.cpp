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

template <typename T>
void printVector(vector<T> vec) {
  cout << "size = " << vec.size() << ": ";
  for (auto &elem: vec) {
    cout << elem << " ";
  }
  cout << endl;
}

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

int getMaxDepth(TreeNode* root)
{
    unordered_set<int> visited;
    visited.insert(root->getVal());
    queue<pair<TreeNode*,int>> q; q.push(pair<TreeNode*,int>(root, 0));
    int maxDepth = 0;
    while (!q.empty()) {
        TreeNode* currNode = q.front().first;
        int currDepth = q.front().second;
        maxDepth = max(currDepth, maxDepth);
        vector<TreeNode*> children = currNode->getChildren();
        q.pop();
        for (auto &child: children) {
            if (visited.find(child->getVal()) == visited.end()) {
                visited.insert(child->getVal());
                q.push(pair<TreeNode*, int>(child, currDepth + 1));
            }
        }
    }
    return maxDepth;
}

void solve(int n, vector<TreeNode*>& nodes)
{
    vector<int> maxDist; maxDist.reserve(n);
    for (auto &node: nodes) {
        cout << getMaxDepth(node) << " ";
    }
    cout << endl;
}

int main()
{
    int n; cin >> n;
    vector<TreeNode*> nodes; nodes.reserve(n);
    for (int i = 0; i < n; i++) {
        nodes.push_back(new TreeNode(i));
    }
    for (int i = 1; i < n; i++) {
        int node1, node2; cin >> node1 >> node2;
        nodes[node1 - 1]->addChild(nodes[node2 - 1]);
        nodes[node2 - 1]->addChild(nodes[node1 - 1]);
    }
    solve(n, nodes);
    return 0;
}