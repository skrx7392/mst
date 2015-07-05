#include <iostream>
#include <stddef.h>

using namespace std;

class Graph {
private:
    int** adjacencyMatrix;
    int vertexCount;

public:
    Graph(int vertexCount) {
        this->vertexCount = vertexCount;
        adjacencyMatrix = new int *[vertexCount];
        for (int i=0; i<vertexCount; i++){
            adjacencyMatrix[i] = new int [vertexCount];
            for (int j=0; j<vertexCount; j++){
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    ~Graph() {
        for (int i=0; i<vertexCount; i++)
            delete[] adjacencyMatrix[i];
        delete[] adjacencyMatrix;
    }

    void addEdge(int, int, int);
    void removeEdge(int, int);
    int isEdge(int, int);
    void prim();
};

class queue_class{
public:
    int rear,front,a[10];

    queue_class()   // Constructor method
    {
        rear=0;
        front=0;
    }
    void insert(int s) // Function to add the elements to the queue
    {  if(rear==8)
        cout<<"queue is full";
       else
       { a[rear]=s;
        rear=rear+1;
       }
     }
    int remove()    //Function to remove elements from the queue
    {
        if(front==rear)
           return -1;
        else
          return a[front++];
   }
};

void Graph::addEdge(int i, int j, int k) {
    if (i>=0 && i<vertexCount && j>=0 && j<vertexCount) {
        adjacencyMatrix[i][j] = k;
        adjacencyMatrix[j][i] = k;
    }
}

void Graph::removeEdge (int i, int j) {
    if (i>=0 && i<vertexCount && j>=0 && j<vertexCount) {
        adjacencyMatrix[i][j] = 0;
        adjacencyMatrix[j][i] = 0;
    }
}

int Graph::isEdge (int i, int j) {
    if (i>=0 && i<vertexCount && j>=0 && j<vertexCount) {
        return adjacencyMatrix[i][j];
    }
    else
        return false;
}

void Graph::prim(){
    int mst[10]={0,0,0,0,0,0,0,0,0,0};
    queue_class mstqueue;
    mst[0]=1;
    int u=0,v=0,total=0;
    int mini;
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if(adjacencyMatrix[i][j] == 0){
                adjacencyMatrix[i][j]=999;
            }
        }
    }
    for(int counter=0; counter<9; counter++){
        mini=999;
        for(int i=0; i<10; i++){
            if(mst[i]==1){
                for(int j=0;j<10;j++){
                    if(mst[j]!=1){
                        if(mini>adjacencyMatrix[i][j]){
                            mini=adjacencyMatrix[i][j];
                            u=i;
                            v=j;
                        }
                    }
                }
            }
        }
        total=total+isEdge(u,v);
        mst[v]=1;
        cout << "\nEdge found: " << u << "-" << v << ": Weight: " << isEdge(u,v);
    }
    cout << "\n\nThe weight of the minimum spanning tree is: " << total;
}

int main() {

    Graph myGraph(10);

    myGraph.addEdge(0,1,2);
    myGraph.addEdge(0,3,9);
    myGraph.addEdge(0,4,4);
    myGraph.addEdge(0,6,1);
    myGraph.addEdge(1,2,3);
    myGraph.addEdge(1,6,7);
    myGraph.addEdge(1,9,5);
    myGraph.addEdge(2,5,6);
    myGraph.addEdge(2,6,6);
    myGraph.addEdge(3,5,3);
    myGraph.addEdge(3,9,5);
    myGraph.addEdge(4,7,8);
    myGraph.addEdge(4,8,6);
    myGraph.addEdge(5,7,9);
    myGraph.addEdge(6,8,7);
    myGraph.addEdge(7,9,8);

    int a, b;
    cout << endl;
    for(a=0; a<=9; a++){
        cout<<endl;
        for(b=0; b<=9; b++){
            cout << " " << myGraph.isEdge(a,b);
        }
    }
    cout << endl << endl;
    myGraph.prim();
    cout << endl;
    return 0;
}

