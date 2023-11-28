**Time complexity build heap:**
<hr>
Height of complete binary tree = log n 
<br /><br />
Time Complexity of heapify operation = O(log n)
<br /><br />
<strong>Time complexity to build a heap:</strong>
<br />
We call heapify operation for the lower half of the heap. So, the effective time complexity will be O(n/2 log n) or O(n log n). But if we were to derive the tighter bounds, we need to consider the fact that as we move up the tree the number of nodes reduce the factor of log n. Taking this into consideration for a very large value of n.

<br>
Number of nodes at height h:

$$\frac{n}{2^h + 1}$$

Running time for each node:

$$O(h)$$

Therefore running time is:

$$= \left( \sum_{h=0}^{log\;n} \frac{n}{2^h + 1} \right) \times O(h) $$

$$= O\left( n \sum_{h=0}^{log\;n} \frac{h}{2^h} \right)$$

$$ = O \left( n \sum_{h=0}^{∞} \frac{h}{2^h} \right)$$

$$ = O(n)$$