#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(int task, vector<vector<int>> &graph, unordered_set<int> &visited)
{
	visited.insert(task); // 标记当前任务为已访问
	for (int dependency : graph[task])
	{
		if (visited.find(dependency) == visited.end())
		{									 // 如果依赖任务未被访问
			dfs(dependency, graph, visited); // 递归访问依赖任务
		}
	}
}

int main()
{
	int N;
	cin >> N; // 读取任务总数

	vector<vector<int>> graph(N + 1); // 构建图，任务编号从1开始

	// 读取每个任务的依赖项
	for (int i = 1; i <= N; ++i)
	{
		int Ci;
		cin >> Ci; // 读取当前任务的依赖项数量
		for (int j = 0; j < Ci; ++j)
		{
			int dependency;
			cin >> dependency;				// 读取依赖任务编号
			graph[i].push_back(dependency); // 添加依赖关系
		}
	}

	unordered_set<int> visited; // 用于记录访问过的任务
	dfs(1, graph, visited);		// 从任务1开始DFS

	cout << visited.size() << endl; // 输出访问过的任务数量

	return 0;
}