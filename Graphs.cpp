Q1) Reversing edge of graph st destination is reachable from source.
Link: https://www.codechef.com/problems/REVERSE

//Approach:
1) Think Greedily!
2) Make anothr edge into same graph of weight 1, that means reverse edge we created and weight of original edge=0
3) Apply Dijstra to find shortest path among them.
4) If distance is still inf, we can't reach that node, else return distance.
  
Trying....
//Code
https://www.codechef.com/viewsolution/68787528
(use 0-1 BFS for better time complexity than Dijstra).
(Everything about BFs in notes).
  
