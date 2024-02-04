#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insert() {
    int x;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *current, *parent;

    printf("Enter the element to be inserted: ");
    scanf("%d", &x);

    ptr->data = x;
    ptr->left = NULL;
    ptr->right = NULL;

    if(root == NULL) {
        root = ptr;
    } else {
        current = root;
        parent = NULL;

        while(1) {
            parent = current;

            if(x < parent->data) {
                current = current->left;
                if(current == NULL) {
                    parent->left = ptr;
                    return;
                }
            } else {
                current = current->right;
                if(current == NULL) {
                    parent->right = ptr;
                    return;
                }
            }
        }
    }
}

void inorder(struct node *ptr) {
    if(ptr != NULL) {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

void preorder(struct node *ptr) {
    if(ptr != NULL) {
        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(struct node *ptr) {
    if(ptr != NULL) {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

void rev_inorder(struct node *ptr) {
    if(ptr != NULL) {
        rev_inorder(ptr->right);
        printf("%d ", ptr->data);
        rev_inorder(ptr->left);
    }
}

void rev_preorder(struct node *ptr) {
    if(ptr != NULL) {
        printf("%d ", ptr->data);
        rev_preorder(ptr->right);
        rev_preorder(ptr->left);
    }
}

void rev_postorder(struct node *ptr) {
    if(ptr != NULL) {
        rev_postorder(ptr->right);
        rev_postorder(ptr->left);
        printf("%d ", ptr->data);
    }
}

void delete() {
    if (root == NULL)  
        printf("Tree is Empty!!");
    else {
        int x;
        struct node *parent = NULL, *current = root; 
        
        printf("Enter the data to be deleted: ");
        scanf("%d", &x);

        while(current != NULL) {
            if (x == current->data)
                break;
            parent = current;
            if (x < current->data)
                current = current->left;
            else current = current->right;
        }

        if (current == NULL)
            printf("Element not found!!");
        else {
            if (current->left == NULL && current->right == NULL) {
                if (parent == NULL)
                    root = NULL;
                else if (parent->left == current)
                    parent->left = NULL;
                else parent->right = NULL;
            } else if (current->left != NULL && current->right == NULL) {
                if (parent == NULL)
                    root = current->left;
                else if (parent->left == current)
                    parent->left = current->left;
                else parent->right = current->left;
            
            } else if (current->left == NULL && current->right != NULL) {
                if (parent == NULL)
                    root = current->right;
                else if (parent->left == current)
                    parent->left = current->right;
                else parent->right = current->right;
            } else {
                struct node *successor, *parent_successor;
                parent_successor = current;
                successor = current->right;

                while (successor->left != NULL) {
                    parent_successor = successor;
                    successor = successor->left;
                }
                current->data = successor->data;

                if (parent_successor->left == successor)
                    parent_successor->left = successor->right;
                else parent_successor->right = successor->right;
            }
        }
    }
}

void search() {
    struct node *current;
    int x;

    if(root == NULL) {
        printf("Tree is empty\n");
        return;
    } else {
        printf("Enter the element to be searched: ");
        scanf("%d", &x);

        current = root;

        while(current != NULL) {
            if(current->data == x) {
                printf("Element found\n");
                return;
            }

            if(x < current->data) 
                current = current->left;
            else current = current->right;
        }

        printf("Element not found\n");
    }
}

int height(struct node *ptr) {
    if(ptr == NULL)
        return 0;
    else {
        int lheight = height(ptr->left);
        int rheight = height(ptr->right);
        if(lheight > rheight)
            return (lheight + 1);
        else return (rheight + 1);
    }
}

int totalnodes(struct node *ptr) {
    if(ptr == NULL)
        return 0;
    else return (totalnodes(ptr->left) + totalnodes(ptr->right) + 1);
}

int mirror(struct node *ptr) {
    if(ptr != NULL) {
        struct node *temp;
        mirror(ptr->left);
        mirror(ptr->right);
        temp = ptr->left;
        ptr->left = ptr->right;
        ptr->right = temp;
    }    
}

int main() {
    int c;
    do {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Inorder\n5. Preorder\n6. Postorder\n7. Reverse Inorder\n8. Reverse Preorder\n9. Reverse Postorder\n10. Total number of nodes\n11. Height of the tree\n12. Mirror Tree\n13. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &c) != 1) {
            fflush(stdin); 
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        switch(c) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: search(); break;
            case 4: inorder(root); printf("\n"); printf("%d\n", root->data); break;
            case 5: preorder(root); printf("\n"); break;
            case 6: postorder(root); printf("\n"); break;
            case 7: rev_inorder(root); printf("\n"); break;
            case 8: rev_preorder(root); printf("\n"); break;
            case 9: rev_postorder(root); printf("\n"); break;
            case 10: printf("Total Nodes are: %d", totalnodes(root)); break;
            case 11: printf("Height of the Tree is: %d", height(root)); break;
            case 12: mirror(root); printf("Mirrored Tree is: "); inorder(root); break;
            case 13: exit(0);
            default: printf("Invalid choice\n");
        }
    }while(c != 13);
    return 0;
}
