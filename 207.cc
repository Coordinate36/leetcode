/*class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> Map(numCourses + 1, 0);
        int len = prerequisites.size();
        for (int i = 0; i < len; ++i) {
            // cout << prerequisites[i].first << endl;
            int last = prerequisites[i].second + 1;
            while (Map[last] != 0) {
                if (Map[last] == prerequisites[i].first + 1) {
                    return false;
                }
                last = Map[last];
            }
            Map[prerequisites[i].first + 1] = prerequisites[i].second + 1;
        }
        return true;
    }
};*/

class Graph {
    int V;
    list<int> *adj; // adjacency list
    queue<int> q;   // set of edges with no incoming edges
    int *indegree;  // indegree of every vertex
public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];

        indegree = new int[V];
        for (int i = 0; i < V; ++i) {
            indegree[i] = 0;
        }
    }

    ~Graph() {
        delete [] adj;
        delete [] indegree;
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        ++indegree[w];
    }

    bool topological_sort() {
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            ++count;
            for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
                if (!(--indegree[*i])) {
                    q.push(*i);
                }
            }
        }

        if (count < V) {
            return false;
        }
        return true;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        Graph g(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            g.addEdge(prerequisites[i].second, prerequisites[i].first);
        }

        return g.topological_sort();
    }
};