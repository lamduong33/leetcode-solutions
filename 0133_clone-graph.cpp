// #include <unordered_set>
// #include <vector>
// using std::vector;

// // Definition for a Node.
// class Node
// {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node()
//     {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val)
//     {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors)
//     {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution
{
    std::unordered_set<Node*> visited;

public:
    Node* cloneGraph(Node* node)
    {
        Node* copyGraph = nullptr;
        auto copy = copyGraph;
        DFClone(node, copy);
        return copyGraph;
    }

    void DFClone(Node* node, Node* copy)
    {
        if (!visited.count(node))
        {
            if (copy == nullptr)
            {
                copy = new Node(node->val);
            }
            else
            {
                auto newCopy = new Node(node->val);
                copy->neighbors.push_back(newCopy);
                newCopy->neighbors.push_back(copy);
                copy = newCopy;
            }
            visited.insert(copy);
            for (auto neighbor : node->neighbors)
            {
                DFClone(neighbor, copy);
            }
        }
    }
};
