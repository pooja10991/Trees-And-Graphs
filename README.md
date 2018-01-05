# Trees-And-Graphs
Different Tree and Graphs implementation

## Content
  ### Trees
  - #### BST
      Binary Search Treet.
      
  - #### AVL
      Balanced Binary Search Treet.
      
  ### Graphs
  - #### Dijkstra's Algorithm
      Find the Shortest Path in any given graph having non negative weights.  
      The implementation for Dijkstra's Algorithm takes matrix of the graph as the input and will give all the paths from source to all the destination with the cost.
      
  - #### Prim's Algorithm
      Find the Minimum Spanning Tree of any given Graph.  
      The implementation for Prim's Algorithm takes matrix of the graph as input and will output the matrix of MST with total weight of MST.  
    	The input matrix can be of the form as shown:   
	      0 1 4 9999   
	      1 0 5 2  
	      4 5 0 3  
	      9999 2 3 0   
	    where 9999 replace the infinity in algorithm. This means that there is no direct edge between the 2 vertex. 
      Also note that the ouput of the prims algorithm will be matrix form where no edges are represented by 0 and not 9999 (to make ouput more readable).
  
 ## Content of the folder.
1.	BST.h - header file that defines all the BST functions and BinNode attributes.
2.	BST.cpp – Contains definition of the functions defined in BST.h. Constains the implementation of BST as well as AVL trees.
3.	treetester.cpp – testing BST as well as AVL tree.
4.	DijkstrasAlgorithm.java - conains implementation for Dijkstra's Algorithm.
5.	PrimsAlgorithm.java - contains implementation for Prim's Algorithm.
6.	Vertex.java - used by prim's algorithm to maintaind the Priority Queue with vertex name and weight.
7.	PriorityQueue - used by Prim's algorithm and contains implementation of different operations used to maintain Priority Queue.
