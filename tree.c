#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

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


bool find_path_sum(struct treenode_t **root, int sum){

    if(!(*root) && sum != 0){
        return false;
    }

    if((*root) && (sum == (**root).value)){
        printf("Path found, ending on leaf value = %d\n", (**root).value);
        return true;
    }

    find_path_sum(&(**root).left_child, sum - (**root).value);
    find_path_sum(&(**root).right_child, sum - (**root).value);

}


int main(){
    
    struct treenode_t *new_node = createnode(8);

    struct treenode_t *n2 = createnode(4);
    struct treenode_t *n3 = createnode(13);
    struct treenode_t *n4 = createnode(2);
    struct treenode_t *n5 = createnode(6);
    struct treenode_t *n6 = createnode(19);    

    new_node->left_child = n2;
    new_node->right_child = n3;

    n2->left_child = n4;
    n2->right_child = n5;

    n3->left_child = n6;

    //printtree(new_node);

    find_path_sum(&new_node, 18);


}