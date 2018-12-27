#include<bits/stdc++.h> 
using namespace std; 
#define M 1000000007
class Node { 
  
public: 
    int key; 
    vector<Node*> child; 
    int count;
    Node(int data) 
    { 
        key = data; 
        count = 1;
    } 
}; 

// Creates a node with key as 'i'.  If i is root, then it changes 
// root.  If parent of i is not created, then it creates parent first 
void createNode(int parent[], int i, Node *created[], Node **root) 
{ 
    // If this node is already created 
    if (created[i] != NULL) 
        return; 
  
    // Create a new node and set created[i] 
    created[i] = new Node(i); 
  
    // If 'i' is root, change root pointer and return 
    if (parent[i] == -1) 
    { 
        *root = created[i]; 
        return; 
    } 
  
    // If parent is not created, then create parent first 
    if (created[parent[i]] == NULL) 
        createNode(parent, parent[i], created, root); 
  
    // Find parent pointer 
    Node *p = created[parent[i]]; 
    (p->child).push_back(created[i]);
} 
  
// Creates tree from parent[0..n-1] and returns root of the created tree 
Node *createTree(int parent[], int n) 
{ 
    // Create an array created[] to keep track 
    // of created nodes, initialize all entries 
    // as NULL 
    Node *created[n]; 
    for (int i=0; i<n; i++) 
        created[i] = NULL; 
  
    Node *root = NULL; 
    for (int i=0; i<n; i++) 
        createNode(parent, i, created, &root); 
  
    return root; 
} 

int fillCount(Node * root)
{
    if(root==NULL)
    return 0;
    for(int i=0;i<(root->child).size();i++)
    {
        root->count += fillCount(root->child[i]);
    }
    return root->count;
}

void LevelOrderTraversal(Node * root) 
{ 
    if (root==NULL) 
        return; 
   
    // Standard level order traversal code 
    // using queue 
    queue<Node *> q;  // Create a queue 
    q.push(root); // Enqueue root  
    while (!q.empty()) 
    { 
        int n = q.size(); 
  
        // If this node has children 
        while (n > 0) 
        { 
            // Dequeue an item from queue and print it 
            Node * p = q.front(); 
            q.pop(); 
            cout << p->key << " - "<<p->count<<" "; 
   
            // Enqueue all children of the dequeued item 
            for (int i=0; i<p->child.size(); i++) 
                q.push(p->child[i]); 
            n--; 
        } 
   
        cout << endl; // Print new line between two levels 
    } 
}
long long  power(long long  x, long long  y, long long  p) 
{ 
    long long  res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
  
// Returns n^(-1) mod p 
long long  modInverse(long long  n, long long  p) 
{ 
    return power(n, p-2, p); 
} 
  
// Returns nCr % p using Fermat's little 
// theorem. 
long long nCrModPFermat(long long n, long long  r, long long  p, long long  fac[]) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
}            
            
long long countInvites(Node* root, long long fac[])
{
    long long totCount = 1;
    long long  seats = root->count - 1;
    long long  leafNodes = 0;
    for(int i=0;i<(root->child).size();i++)
    {
        Node * p = root->child[i];
        if(p->count == 1)
        {
            leafNodes++;
        }
        else
        {
            totCount = (totCount%M * countInvites(p, fac)%M )%M;
        }
        totCount = (totCount%M * nCrModPFermat(seats, p->count,M, fac))%M ;
        seats -= p->count;
    }
    return totCount;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        int parent [n+1]={0};
        parent[0]=-1;
        
        for(int i=0;i<m;i++)
        {
            int p,c;
            cin>>p>>c;
            parent[c]=p;
        }
        Node *root = createTree(parent, n+1); 
        fillCount(root);
        
        long long fac[200001];
        fac[0] = 1; 
        for (int i=1 ; i<=n; i++) 
            fac[i] = fac[i-1]*i%M; 
        long long invites = countInvites(root, fac);
        cout<<invites<<endl;
    }
    
    return 0;
}
