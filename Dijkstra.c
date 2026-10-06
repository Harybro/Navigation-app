#include <stdio.h>
#include <limits.h>
#include <n = 5>

int navigate(int start, int end) 
    int graph[5][5] = { //adjacency matrtrix used for small dijkstras algorithm for scaled up will use adjaceny list
        {0, 4, 2, 0, 0},
        {4, 0, 0, 1, 0},
        {2, 0, 0, 3, 2},
        {0, 1, 3, 0, 0},
        {0, 0, 2, 0, 0},
    };

    int distance[5]; //shorets distance currently found to node i
    int visited[5]; //wether weve permently processed that node
    int previous[5]; //node we came from which lets us reconstruct the route later

    for (int i = 0; i < 5; i++) { //inisilising variables
        distance[i] = INT_MAX; //set all nodes to infinite(highest integer possible) 
        visited[i] = 0; //if node has been visited or not
        previous[i] = -1; //set to -1 because previous node is unkown
    }

    distance[start] = 0; //distance set to A(0) letters arent used just numbers 
    int destination = end;

    for (int count = 0; count < 5; count++) {

        int current = -1;
        int smallest = INT_MAX; //set to highest num so that when it checks the first node its always smaller and assigns to that

        for (int i = 0; i < 5; i++) { //loops through every node to find closest unvisited node
            if (!visited[i]&& distance[i] < smallest) { //checks if not is unvisited AND is its distance smaller than the smallest distance so far
                smallest = distance[i]; //sets smallest to current distance if True
                current = i;//current gets set to node thats smalllest distance
            }
        }

        visited[current] = 1; //current node is set to visited so its not selected again


        for (int i = 0; i < 5; i++) { //checks if current node has a edge to this node
            if(graph[current][i] != 0) { //checks if current node has an edge to node i
                int newDistance = distance[current] + graph[current][i]; // distance to current + edge from current to i = possible new distance to i

                if (newDistance < distance[i]) { //checks if the new route to node i is shorter than the best route currently known
                    distance[i] = newDistance; //if true is changes distances to just found shorter distance
                    previous[i] = current; //previous of i node set to current node 
                }
            }
        }
    }

    int current = destination; 

    //displays the shortest path from start to destination
    while (current != -1) { 
        printf("%c ", 'A' + current);
        current = previous[current];
    }

    printf("\n");

    printf("shortest distances from A:\n");

   for (int i = 0; i < 5; i++) {
       printf("A -> %c = %d\n", 'a' + i, distance[i]);
   }

    return 0;

}