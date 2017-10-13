/*class Graph {
    int V;
    list<int> *adj;
    queue<int> S;
    vector<int> L;
    int *indegree;
public:
    Graph(int vNum) {
        V = vNum;
        adj = new list<int>[V];
        indegree = new int [V];

        memset(indegree, 0, sizeof(indegree));
    }
    ~Graph() {
        delete [] adj;
        delete [] indegree;
    }
    void addEdge(int in, int out) {
        adj[in].push_back(out);
        ++indegree[out];
    }
    vector<int> topologicalSort() {
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                S.push(i);
            }
        }

        while (!S.empty()) {
            int v = S.front();
            S.pop();
            L.push_back(v);
            for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
                if (!(--indegree[v])) {
                    S.push(v);
                }
            }
        }
        return L;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        Graph g(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            g.addEdge(prerequisites[i].second, prerequisites[i].first);
        }   
        return g.topologicalSort();
    }
};*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> S;
        vector<int> L;

        vector<list<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); ++i) {
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
            ++indegree[prerequisites[i].first];
        }

        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                S.push_back(i);
            }
        }

        while (!S.empty()) {
            int v = S.back();
            S.pop_back();
            L.push_back(v);

            for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
                if (!(--indegree[*i])) {
                    S.push_back(*i);
                }
            }
        }

        if (L.size() == numCourses) {
            return L;
        }
        vector<int> emp;
        return emp;
    }
};