#include <stdio.h>

#define V 30
int n;

int map[V][V], visit[V];

void DFS(int v)
{
	int i;

	visit[v] = 1;

	for(i = 1; i <= n; i++) {
		if(map[v][i] == 1 && !visit[i]) {
			printf("%d -> %d\n", v, i);
			DFS(i);
		}
	}
}


int main()
{
	int start;
	int v1, v2;

	scanf("%d%d", &n, &start);

	while(1) {
		scanf("%d%d", &v1, &v2);
		if(v1 == -1 && v2 == -1) break;
		map[v1][v2] = map[v2][v1] = 1;
	}

	DFS(start);

	return 0;
}
