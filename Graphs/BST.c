#include <stdio.h>

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

        while(true) {
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
    struct node *current, *parent;
    int x;

    if(root == NULL) {
        printf("Tree is empty\n");
        return;
    } else {
        printf("Enter the element to be deleted: ");
        scanf("%d", &x);

        current = root;
        parent = NULL;

        while(current != NULL) {
            if(current->data == x) {
                break;
            }

            parent = current;

            if(x < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if(current == NULL) {
            printf("Element not found\n");
            return;
        }

        if(current->left == NULL && current->right == NULL) {
            if(parent == NULL) {
                root = NULL;
            } else {
                if(parent->left == current) {
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
            }
        } else if(current->left != NULL && current->right == NULL) {
            if(parent == NULL) {
                root = current->left;
            } else {
                if(parent->left == current) {
                    parent->left = current->left;
                } else {
                    parent->right = current->left;
                }
            }
        } else if(current->left == NULL && current->right != NULL) {
            if(parent == NULL) {
                root = current->right;
            } else {
                if(parent->left == current) {
                    parent->left = current->right;
                } else {
                    parent->right = current->right;
                }
            }
        } else {
            struct node *successor, *parent_successor;

            successor = current->right;
            parent_successor = current;

            while(successor->left != NULL) {
                parent_successor = successor;
                successor = successor->left;
            }

            current->data = successor->data;

            if(parent_successor->left == successor) {
                parent_successor->left = successor->right;
            } else {
                parent_successor->right = successor->right;
            }
        }
    }
}