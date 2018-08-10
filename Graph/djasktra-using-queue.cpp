// A C++ program for Dijkstra's single source shortest path algorithm.
#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 9

pair<int , int> solve(vector < pair<int , int> > q , bool sptSet[]){
        int minval = INT_MAX;
        int minint = 0;
        for(auto i : q){
                if(sptSet[i.first] == false) if(i.second < minval) minval = i.second , minint = i.first;
        }
        return make_pair(minint , minval);
}

void printSolution(int dist[], int n)
{
        printf("Vertex   Distance from Source\n");
        for (int i = 0; i < V; i++)
        printf("%d tt %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
        int dist[V];

        bool sptSet[V];

        for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
        dist[src] = 0;
        sptSet[src] = true;


        vector < pair <int , int> > q;

        for(int i = src ; i < V ; i++){
                if(graph[src][i] != 0)  dist[i] = graph[src][i] , q.push_back(make_pair(i , dist[i]));
        }

        int val = 0;
        while( val < V-1 ){
                //cout<<"oops"<<endl;
                pair<int , int> minvalue = solve(q , sptSet);
                int minint = minvalue.first;
                int minval = minvalue.second;
                sptSet[minint] = true;
                dist[minint] = minval;
                val++;
                for(auto i : q) if(i.first == minint) for(int i = 0 ; i < V ; i++ ) if(graph[minint][i] != 0) q.push_back(make_pair(i , graph[minint][i] + minval ) );
                for(auto i : q) if(i.first == minint) i.first = 0 , i.second = INT_MAX;
        }



        printSolution(dist, V);
}

// driver program to test above function
int main()
{
        /* Let us create the example graph discussed above */
        int graph[V][V] =                       {{0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
};

dijkstra(graph, 0);

return 0;
}
