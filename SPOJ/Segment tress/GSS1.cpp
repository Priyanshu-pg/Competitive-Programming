#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll a[50000];
ll seg[131017];

struct Node {
    ll maxPrefixSum;
    ll maxSuffixSum;
    ll totalSum;
    ll maxSubarraySum;

    Node()
    {
        maxPrefixSum = maxSuffixSum = maxSubarraySum = INT_MIN;
        totalSum = INT_MIN;
    }
};

// Returns Parent Node after merging its left and right child
Node merge(Node leftChild, Node rightChild)
{
    Node parentNode;
    parentNode.maxPrefixSum = max(leftChild.maxPrefixSum,
                                  leftChild.totalSum +
                                  rightChild.maxPrefixSum);

    parentNode.maxSuffixSum = max(rightChild.maxSuffixSum,
                                  rightChild.totalSum +
                                  leftChild.maxSuffixSum);

    parentNode.totalSum = leftChild.totalSum +
                          rightChild.totalSum;

    parentNode.maxSubarraySum = max({leftChild.maxSubarraySum,
                                     rightChild.maxSubarraySum,
                                     leftChild.maxSuffixSum +
                                     rightChild.maxPrefixSum});

    return parentNode;
}

// Builds the Segment tree recursively
void constructTreeUtil(Node* tree, ll arr[], ll start,
                                    ll end, ll index)
{

    /* Leaf Node */
    if (start == end) {

        // single element is covered under this range
        tree[index].totalSum = arr[start];
        tree[index].maxSuffixSum = arr[start];
        tree[index].maxPrefixSum = arr[start];
        tree[index].maxSubarraySum = arr[start];
        return;
    }

    // Recursively Build left and right children
    ll mid = (start + end) / 2;
    constructTreeUtil(tree, arr, start, mid, 2 * index);
    constructTreeUtil(tree, arr, mid + 1, end, 2 * index + 1);

    // Merge left and right child llo the Parent Node
    tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
}

/* Function to construct segment tree from given array.
   This function allocates memory for segment tree and
   calls constructTreeUtil() to fill the allocated
   memory */
Node* constructTree(ll arr[], ll n)
{
    // Allocate memory for segment tree
    ll x = (ll)(ceil(log2(n))); // Height of the tree

    // Maximum size of segment tree
    ll max_size = 2 * (ll)pow(2, x) - 1;
    Node* tree = new Node[max_size];

    // Fill the allocated memory tree
    constructTreeUtil(tree, arr, 0, n - 1, 1);

    // Return the constructed segment tree
    return tree;
}

/* A Recursive function to get the desired
   Maximum Sum Sub-Array,
The following are parameters of the function-

tree     --> Poller to segment tree
index --> Index of the segment tree Node
ss & se  --> Starting and ending indexes of the
             segment represented by
                 current Node, i.e., tree[index]
qs & qe  --> Starting and ending indexes of query range */
Node queryUtil(Node* tree, ll ss, ll se, ll qs,
                               ll qe, ll index)
{
    // No overlap
    if (ss > qe || se < qs) {

        // returns a Node for out of bounds condition
        Node nullNode;
        return nullNode;
    }

    // Complete overlap
    if (ss >= qs && se <= qe) {
        return tree[index];
    }

    // Partial Overlap Merge results of Left
    // and Right subtrees
    ll mid = (ss + se) / 2;
    Node left = queryUtil(tree, ss, mid, qs, qe,
                                     2 * index);
    Node right = queryUtil(tree, mid + 1, se, qs,
                              qe, 2 * index + 1);

    // merge left and right subtree query results
    Node res = merge(left, right);
    return res;
}

/* Returns the Maximum Subarray Sum between start and end
   It mainly uses queryUtil(). */
ll query(Node* tree, ll start, ll end, ll n)
{
    Node res = queryUtil(tree, 0, n - 1, start, end, 1);
    return res.maxSubarraySum;
}

int  main()
{
    std::ios::sync_with_stdio(0);
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>a[i];

    Node * tree = constructTree(a, n);

   /* for(ll i=0;i<7;i++)
    {
    cout<<seg[i]<<" ";
    }*/
    cout<<endl;
    ll m;
    cin>>m;
    while(m--)
    {
        ll l,r;
        cin>>l>>r;
        l--;r--;
        cout<<query(tree, l, r, n)<<endl;
    }
    return 0;
}
