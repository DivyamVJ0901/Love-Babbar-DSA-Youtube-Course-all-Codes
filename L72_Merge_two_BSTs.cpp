#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->next = NULL;
    }
};

Node *SetDataForBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data)
        root->left = SetDataForBST(root->left, data);

    else
        root->right = SetDataForBST(root->right, data);

    return root;
}

void getData(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = SetDataForBST(root, data);
        cin >> data;
    }
}

void LevelOrderTraversal(Node *root)
{
    queue<Node *> cheems;
    cheems.push(root);
    cheems.push(NULL);

    while (!cheems.empty())
    {
        Node *temp = cheems.front();
        cheems.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!cheems.empty())
                cheems.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                cheems.push(temp->left);
            if (temp->right)
                cheems.push(temp->right);
        }
    }
}

// INORDER KO VECTOR ME STORE KRA LIYA
void Inorder(Node *root, vector<int> arr)
{
    if (root == NULL)
        return;

    Inorder(root->left, arr);
    arr.push_back(root->data);
    Inorder(root->right, arr);
}

// DO ARRAYS MERGE HO JAAYENGE
vector<int> mergedArray(vector<int> arr1, vector<int> arr2)
{
    int m = arr1.size(), n = arr2.size(), i = 0, j = 0;
    int k = 0;
    vector<int> arr3(m + n);
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    while (i < m)
        arr3[k++] = arr1[i++];

    while (j < n)
        arr3[k++] = arr2[j++];

    return arr3;
}

// INORDER TRAVERSAL SE BST BAN JAAYEGA
Node *InorderToBST(int s, int e, vector<int> &inToBST)
{
    if (s > e)
        return NULL;

    int mid = s + (e - s) / 2;

    Node *root = new Node(inToBST[mid]);

    root->left = InorderToBST(s, mid - 1, inToBST);
    root->right = InorderToBST(mid + 1, e, inToBST);

    return root;
}

Node *mergedBST(Node *root1, Node *root2)
{
    vector<int> bst1, bst2;
    Inorder(root1, bst1);
    Inorder(root2, bst2);
    vector<int> bst_merged = mergedArray(bst1, bst2);

    return InorderToBST(0, bst_merged.size() - 1, bst_merged);
}

// OPTIMISED APPROACH BY USING DOUBLY LINKED LIST
void ConvertBSTtoSortedDLL(Node *root, Node *head)
{
    if (root == NULL)
        return;

    // Yaha humne right subtree se LL bna li
    ConvertBSTtoSortedDLL(root->right, head);

    // DLL bnane ke liye ye steps follow kiye
    root->right = head;

    if (head != NULL)
        head->left = root;

    head = root;

    // Same kaam humne left subtree ke liye bhi kr liya
    ConvertBSTtoSortedDLL(root->left, head);
}

Node *mergeTwoSortedLL(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

int count(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

Node *BSTfromMergedSortedLL(Node *head, int n)
{
    if (n <= 0 || head == NULL)
        return NULL;

    Node *leftAns = BSTfromMergedSortedLL(head, n / 2);
    Node *root = head;
    root->left = leftAns;

    head = head->next;

    Node *rightAns = BSTfromMergedSortedLL(head, (n - 1 - n / 2));
    root->right = rightAns;

    return root;
}

Node *FinalBST(Node *root1, Node *root2)
{
    // STEP 1 : BSTs ko sorted LL me convert kr diya
    Node *head1 = NULL;
    ConvertBSTtoSortedDLL(root1, head1);
    Node *head2 = NULL;
    ConvertBSTtoSortedDLL(root2, head2);

    // STEP 2 : Merging two sorted LLs
    Node *merged = mergeTwoSortedLL(head1, head2);

    // STEP 3 : Convert sorted LL into BST
    return BSTfromMergedSortedLL(merged, count(merged));
}

int main()
{
    Node *root1 = NULL;
    cout << "Enter 1st BST : " << endl;
    getData(root1);
    LevelOrderTraversal(root1);

    Node *root2 = NULL;
    cout << "Enter 2nd BST : " << endl;
    getData(root2);
    LevelOrderTraversal(root2);

    Node *ans = mergedBST(root1, root2);
    LevelOrderTraversal(ans);

    Node *ans2 = FinalBST(root1, root2);
    LevelOrderTraversal(ans2);
    return 0;
}

// 50 30 60 20 40 70 80 -1
// 10 6 12 2 8 11 15 -1