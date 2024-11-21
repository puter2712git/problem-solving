#include <iostream>
#include <vector>

int N, R, Q;
std::vector<std::vector<int>> graph;
std::vector<int> answers;
std::vector<bool> isVisited;

void Setup()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

void Input()
{
    std::cin >> N >> R >> Q;
    graph = std::vector<std::vector<int>>(N + 1, std::vector<int>());
    answers = std::vector<int>(N + 1, 0);
    isVisited = std::vector<bool>(N + 1, false);

    int U, V;
    for (int i = 0; i < N - 1; i++)
    {
        std::cin >> U >> V;
        graph[U].push_back(V);
        graph[V].push_back(U);
    }
}

int DFS(int root)
{
    if (answers[root] != 0)
    {
        return answers[root];
    }

    int ret = 1;
    isVisited[root] = true;

    for (int i = 0; i < (int)graph[root].size(); i++)
    {
        int vertex = graph[root][i];
        if (isVisited[vertex])
            continue;

        ret += DFS(vertex);
    }

    answers[root] = ret;
    return ret;
}

void Solve()
{
    answers[R] = DFS(R);

    int root;
    for (int i = 0; i < Q; i++)
    {
        std::cin >> root;
        std::cout << answers[root] << "\n";
    }
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}