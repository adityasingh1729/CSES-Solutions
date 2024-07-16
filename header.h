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
    int val;
    vector<TreeNode*> children;
    
    TreeNode(int val) : val(val) {}
    
    ~TreeNode()
    {
        for (auto &child: children) {
            delete child;
        }
    }

    void addChild(TreeNode* child)
    {
        children.push_back(child);
    }
    
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

template <typename T>
void printVector(vector<T> vec) {
  cout << "size = " << vec.size() << ": ";
  for (auto &elem: vec) {
    cout << elem << " ";
  }
  cout << endl;
}

template <typename T1, typename T2>
void printMap(unordered_map<T1, T2> m) {
  for (auto &elem: m) {
    cout << elem.first << " -> " << elem.second << endl;
  }
}

struct pair_hash {
  size_t operator()(const pair<int,int> p) const {
    auto hash1 = hash<int>{}(p.first);
    auto hash2 = hash<int>{}(p.second);
    return hash1 ^ (hash2 << 1);
  }
};

struct pair_equal {
  bool operator()(const pair<int,int> p1, const pair<int,int> p2) const {
    return p1.first == p2.first && p1.second == p2.second;
  }
};

vector<int> primeFactorization(int n)
 {
    vector<int> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 2) {
        factors.push_back(n);
    }
    return factors;
}

// auto start = std::chrono::high_resolution_clock::now();
// auto end = std::chrono::high_resolution_clock::now();
// auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
// std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;
