#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// binary tree implementation

struct treenode_t{
    int value; 
    struct treenode_t* left_child;
    struct treenode_t* right_child;
};


struct treenode_t* createnode(int val){
    struct treenode_t *result = NULL;
    result = malloc(sizeof(struct treenode_t));
    assert(result && "createnode failed");

    if(result != NULL){
        result->value = val;
        result->left_child = NULL;
        result->right_child = NULL;
    }
    return result;

}



void printtabs(int numtabs){
    for (int i = 0; i < numtabs; i++){
        printf("\t");
        
    }

    return;
}


void printtree_rec(struct treenode_t *root, int level){
    if (root == NULL){
        printtabs(level);
        printf("--- empty tree ---\n");

        return;
    }

    printtabs(level);
    printf("Leaf = %d\n", root->value);
    printtabs(level);
    printf("Left\n");
    
    printtree_rec(root->left_child, level + 1);
    printtabs(level);
    printf("Right\n");


    printtree_rec(root->right_child, level + 1);
    printtabs(level);

     

    printf("done\n");

}



void printtree(struct treenode_t *root){
    printtree_rec(root, 0);
}

int main(){
    
    //int tabs = 1;
    struct treenode_t *new_node = createnode(10);

    struct treenode_t *n2 = createnode(11);
    struct treenode_t *n3 = createnode(12);
    struct treenode_t *n4 = createnode(13);
    struct treenode_t *n5 = createnode(14);
    struct treenode_t *n6 = createnode(6);    

    new_node->left_child = n2;
    new_node->right_child = n3;

    n3->left_child = n4;
    n3->right_child = n5;

    n5->left_child = n6;

    printtree(new_node);

}