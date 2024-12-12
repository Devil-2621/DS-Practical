#include <stdio.h>
#include <stdlib.h>

#define MAX 3 // Maximum degree of B-tree

// Function declarations
struct BTreeNode *createNode(int leaf);
void splitChild(struct BTreeNode *parent, int i, struct BTreeNode *child);
void insertNonFull(struct BTreeNode *node, int key);
void insert(struct BTreeNode **root, int key);
void printLevel(struct BTreeNode *node, int level);
void displayTree(struct BTreeNode *root);

struct BTreeNode
{
    int keys[MAX - 1];
    struct BTreeNode *children[MAX];
    int n;    // Current number of keys
    int leaf; // Is true when node is leaf
};

struct BTreeNode *createNode(int leaf)
{
    struct BTreeNode *node = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    node->leaf = leaf;
    node->n = 0;
    return node;
}

void insertNonFull(struct BTreeNode *node, int key)
{
    int i = node->n - 1;

    if (node->leaf)
    {
        // Move all greater keys one place ahead
        while (i >= 0 && node->keys[i] > key)
        {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->n++;
    }
    else
    {
        // Find the child which is going to have the new key
        while (i >= 0 && node->keys[i] > key)
            i--;
        i++;

        if (node->children[i]->n == MAX - 1)
        {
            // Child is full, split it
            splitChild(node, i, node->children[i]);
            if (node->keys[i] < key)
                i++;
        }
        insertNonFull(node->children[i], key);
    }
}

void splitChild(struct BTreeNode *parent, int i, struct BTreeNode *child)
{
    struct BTreeNode *newNode = createNode(child->leaf);
    newNode->n = MAX / 2 - 1;

    // Copy the last (MAX/2-1) keys of child to newNode
    for (int j = 0; j < MAX / 2 - 1; j++)
        newNode->keys[j] = child->keys[j + MAX / 2];

    // If not leaf, copy the last MAX/2 children of child to newNode
    if (!child->leaf)
    {
        for (int j = 0; j < MAX / 2; j++)
            newNode->children[j] = child->children[j + MAX / 2];
    }

    child->n = MAX / 2 - 1;

    // Create space for new child in parent
    for (int j = parent->n; j >= i + 1; j--)
        parent->children[j + 1] = parent->children[j];

    parent->children[i + 1] = newNode;

    // Move keys in parent to create space for middle key
    for (int j = parent->n - 1; j >= i; j--)
        parent->keys[j + 1] = parent->keys[j];

    parent->keys[i] = child->keys[MAX / 2 - 1];
    parent->n++;
}

void insert(struct BTreeNode **root, int key)
{
    struct BTreeNode *r = *root;

    if (r->n == MAX - 1)
    {
        struct BTreeNode *newRoot = createNode(0);
        newRoot->children[0] = r;
        *root = newRoot;
        splitChild(newRoot, 0, r);
        insertNonFull(newRoot, key);
    }
    else
    {
        insertNonFull(r, key);
    }
}

int main()
{
    struct BTreeNode *root = createNode(1);

    // Insert values and display tree after each insertion
    printf("Inserting 10:\n");
    insert(&root, 10);
    displayTree(root);

    printf("Inserting 20:\n");
    insert(&root, 20);
    displayTree(root);

    printf("Inserting 5:\n");
    insert(&root, 5);
    displayTree(root);

    printf("Inserting 6:\n");
    insert(&root, 6);
    displayTree(root);

    printf("Insertion in B-tree completed successfully\n");
    return 0;
}

void printLevel(struct BTreeNode *node, int level)
{
    if (node == NULL)
        return;

    printf("Level %d: ", level);
    for (int i = 0; i < node->n; i++)
    {
        printf("%d ", node->keys[i]);
    }
    printf("\n");

    if (!node->leaf)
    {
        for (int i = 0; i <= node->n; i++)
        {
            printLevel(node->children[i], level + 1);
        }
    }
}

void displayTree(struct BTreeNode *root)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    printf("B-tree structure:\n");
    printLevel(root, 0);
}