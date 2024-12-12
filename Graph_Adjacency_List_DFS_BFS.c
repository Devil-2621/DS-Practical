#include <stdio.h>
#include <stdlib.h>

// Structure for adjacency list node
struct Node
{
    int data;
    struct Node *next;
};

// Structure for graph
struct Graph
{
    int vertices;
    struct Node **adjList;
    int *visited;
};

// Create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // Create adjacency list array
    graph->adjList = (struct Node **)malloc(vertices * sizeof(struct Node *));
    graph->visited = (int *)malloc(vertices * sizeof(int));

    // Initialize adjacency lists as empty
    for (int i = 0; i < vertices; i++)
    {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Add edge
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add edge from dest to src (undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// DFS implementation
void DFS(struct Graph *graph, int vertex)
{
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node *temp = graph->adjList[vertex];
    while (temp != NULL)
    {
        if (!graph->visited[temp->data])
        {
            DFS(graph, temp->data);
        }
        temp = temp->next;
    }
}

// BFS implementation
void BFS(struct Graph *graph, int startVertex)
{
    // Create a queue for BFS
    int queue[1000];
    int front = 0, rear = 0;

    // Reset visited array
    for (int i = 0; i < graph->vertices; i++)
    {
        graph->visited[i] = 0;
    }

    // Enqueue start vertex and mark it as visited
    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear)
    {
        // Dequeue a vertex and print it
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex
        struct Node *temp = graph->adjList[currentVertex];
        while (temp != NULL)
        {
            if (!graph->visited[temp->data])
            {
                graph->visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    // Create a graph with 6 vertices
    struct Graph *graph = createGraph(6);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);

    printf("Depth First Traversal (starting from vertex 0):\n");
    DFS(graph, 0);

    printf("\n\nBreadth First Traversal (starting from vertex 0):\n");
    BFS(graph, 0);

    return 0;
}