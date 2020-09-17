
/*

In this coding exercise, you should implement the function IslandCount()
below, in C or C++.

IslandCount() takes three arguments that describe a "graph". A graph is a set
of "nodes" that are connected together by "edges". The ascii-art picture below
shows a graph with 8 nodes (numbered from 1..8) and 6 edges that are
represented by the horizontal and vertical lines.

    1---2---3   6    8
    |   |       |
    4---5       7

In this graph, nodes 1 and 2 are connected together by an edge, nodes 1 and 4
are connected, and so on. The arguments to IslandCount() that describe the
graph are
  * int N  - The number of nodes. Nodes are numbered consecutively from 1 to N.
             In the above example, N=8.
  * int M  - The number of edges. In the above example, N=6.
  * int *E - An integer array that contains pairs of elements that say which
             pairs of nodes are connected together.

For the above example the E array looks like this:

  E = {2, 3, 1, 2, 1, 4, 2, 5, 4, 5, 6, 7}

The first pair of elements is 2,3 which means that nodes 2 and 3 are connected
together. The second pair of elements is 1,2 which means that nodes 1 and 2 are
connected together. And so on. In total there are 2*M elements in the E array.

The goal of IslandCount() is to return the number of islands in the graph. An
island is a group of nodes that are connected only to themselves and not to any
of the other nodes in the graph. In the above example there are three islands.
The nodes 1,2,3,4,5 are connected only to themselves, so that's an island. The
nodes 6,7 are connected only to themselves, so that's an island. And node 8,
even though it's not connected to anything at all, is regarded as an island by
itself. In general, islands are distinct if there's no way to travel from one
to another by following the edges. Thus, in the above example IslandCount()
should return 3.

Some other things to note:

* Your goal is to write code that compiles and runs. Test cases are included at
  the bottom of this file, and you are finished when all of the test cases pass
  and "Success" is printed.
* Please add comments to your code to describe the approach you are taking.
* Your implementation should emphasize correctness, not speed. Don't worry
  at all about optimizing things.
* You can assume that all graphs are "well formed", so you don't need to check
  for weird error cases in the arguments.
* This HackerRank environment is set to C++, so you can use the C++ standard
  library, but if you are unfamiliar with C++ you can restrict yourself to basic
  C if you like.

Hints:

* The graph example above might suggest that nodes have positions in a two
  dimensional picture. But this is not the case.
* One common approach is to keep a record of the island that each node is in,
  then scan through pairs in the E array. Whenever you see that node X is
  connected to node Y, and we know the island of node X, then we also know the
  island of node Y.
* Another common approach is a depth (or breadth) first search, where you
  recursively jump from a node to its unvisited neighbors, to find all the
  nodes in an island.

*/

//---------------------------------------------------------------------------
// Here is where you should put your implementation.

#include <bits/stdc++.h>
using namespace std;

int IslandCount(int N, int M, int *E) {
    int islands = 0; // store number of islands
    // assume the graph is well-formed - an empty graph is still well-formed, so return 0 if N = 0 
    
    if(N == 0) return 0;
    
    // Going to use BFS and queue to iteratively search for islands
    // keeping in mind that the graph may not necessarily be two dimensional
    // let's store the connected nodes in a vector of pairs of ints
    // Now I think it might be better to store the connected nodes in a hashmap. This way, we could map all conected values in a vector to a single key 
    // for fast look-up.  Going to press on with vector implementation because I'm short on time.
    vector<pair<int, int>> connected;

    queue<int> temp_q;
    for(int i = 0; i < 2*M; i++)
    {
        temp_q.push(E[i]);
    }

    
    while(!temp_q.empty())
    {
        int first = temp_q.front(); temp_q.pop();
        int second = temp_q.front(); temp_q.pop();
        connected.push_back(make_pair(first, second));
    }
    
    // now that we know which nodes are connected, we need to keep track of which nodes are visited. 
    // let's use an array of bools. 
    // since each node is unique and numbered from 1 to N, let's create a boolean array of N+1 to map the value to the array index
    // index 0 will always be unused 
    vector<bool> visited;
    visited.reserve(N+1);
    for(auto i : visited)
    {
        i = false;
    }
    
    // going to loop through the connected nodes, if there exists a number < N that is not in the connected nodes, it's an island
    for(auto i: connected)
    {
        visited[i.first] = true;
        visited[i.second] = true;
    }
    
    
    for(int i = 1; i <= N; i++)
    {
        if(visited[i] == false)
        {
            islands++;
        }
        visited[i] = false; // set back to false now that we've counted lonely nodes
    }
    
    // now let's do a breadth first search, might be simpler than recursion here
    // set up a queue to store nodes
    // push the first and second value
    // mark as visited
    unordered_map <int, vector<int>> mp;
    for(auto i: connected)
    {
      if(mp.find(i.first) != mp.end())
      {
        
      } 
    }
    queue<pair<int,int>> nodes;
    vector<pair<int,int>>:: iterator it = connected.begin();
    nodes.push(*it);
    it++;
    
    // loop while there are still nodes to visit
    // I think this won't work because I don't have a way to loop through all nodes connected to one node. I should have made hashmap
    // or created a union-find data structure to keep track of my connections. 
    while(!nodes.empty()){
        int first = nodes.front().first; 
        int second = nodes.front().second;
        nodes.pop();
        visited[first] = true;
        
    }
    
    
    cout << islands << endl;
    return islands;
}



//----------------------------------------------------------------------------
// Here are the test cases for the IslandCount() function.

#include <stdio.h>


#define CHECK_EQ(a,b) if ((a) != (b)) { \
  printf("Check failed at line %d, %s != %s\n", __LINE__, #a, #b); \
  return 1; \
}

int main() {
  // The example graph:
  //   1---2---3   6    8
  //   |   |       |
  //   4---5       7
  int E1[] = {2, 3, 1, 2, 1, 4, 2, 5, 4, 5, 6, 7};
  CHECK_EQ(IslandCount(8, 6, E1), 3);

  // The example graph with node numbers reordered to try and trick IslandCount()
  // into prematurely counting islands.
  int E2[] = {1, 2, 3, 2, 6, 7, 4, 5, 2, 5, 4, 1};
  CHECK_EQ(IslandCount(8, 6, E2), 3);

  // No edges.
  CHECK_EQ(IslandCount(10, 0, NULL), 10);

  // Maximally connected.
  int E3[] = {1, 2, 2, 3, 3, 4, 4, 1, 1, 3, 2, 4};
  CHECK_EQ(IslandCount(4, 6, E3), 1);

  // No nodes or edges.
  CHECK_EQ(IslandCount(0, 0, NULL), 0);

  // Star configuration.
  int E4[] = {1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7};
  CHECK_EQ(IslandCount(7, 6, E4), 1);

  // Two maximally connected islands.
  int E5[] = {1, 2, 2, 3, 3, 4, 4, 1, 1, 3, 2, 4, 5, 6, 6, 7, 7, 8, 8, 5, 5, 7, 6, 8};
  CHECK_EQ(IslandCount(8, 12, E5), 2);

  // Two maximally connected islands with a single link between them.
  int E6[] = {1, 2, 2, 3, 3, 4, 4, 1, 1, 3, 2, 4, 5, 6, 6, 7, 7, 8, 8, 5, 5, 7, 6, 8, 1, 8};
  CHECK_EQ(IslandCount(8, 13, E6), 1);

  printf("Success!\n");
  return 0;
}

