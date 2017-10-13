/*class Solution {
public:      
    struct Node
    {
        unordered_set<int> neighbor;
        bool isLeaf()const{return neighbor.size()==1;}
    };
    
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        
        vector<int> buffer1;
        vector<int> buffer2;
        vector<int>* pB1 = &buffer1;
        vector<int>* pB2 = &buffer2;
        if(n==1)
        {
            buffer1.insert(0);
            return buffer1;
        }
        if(n==2)
        {
            buffer1.insert(0);
            buffer1.insert(1);
            return buffer1;
        }
        
        // build the graph
        vector<Node> nodes(n);
        for(auto p:edges)
        {
            nodes[p.first].neighbor.insert(p.second);
            nodes[p.second].neighbor.insert(p.first);
        }
        
        // find all leaves
        for(int i=0; i<n; ++i)
        {
            if(nodes[i].isLeaf()) pB1->push_back(i);
        }

        // remove leaves layer-by-layer            
        while(1)
        {
            for(int i : *pB1)
            {
                for(auto n: nodes[i].neighbor)
                {
                    nodes[n].neighbor.erase(i);
                    if(nodes[n].isLeaf()) pB2->push_back(n);
                }
            }
            if(pB2->empty())
            {
                return *pB1;
            }
            pB1->clear();
            swap(pB1, pB2);
        }
        
    }
};*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> adj(n);

        vector<int> buf1;
        vector<int> buf2;
        vector<int> *pB1 = &buf1;
        vector<int> *pB2 = &buf2;

        for (auto p: edges) {
            adj[p.first].insert(p.second);
            adj[p.second].insert(p.first);
        }

        for (int i = 0; i < n; ++i) {
            if (adj[i].size() <= 1) {
                pB1->push_back(i);
            }
        }

        for (;;) {
            for (int i: *pB1) {
                for (int n: adj[i]) {
                    adj[n].erase(i);
                    if (adj[n].size() == 1) {
                        pB2->push_back(n);
                    }
                }
            }

            if (pB2->empty()) {
                return *pB1;
            }

            pB1->clear();
            swap(pB1, pB2);
        }
    }
};