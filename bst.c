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


    result->value = val;
    result->left_child = NULL;
    result->right_child = NULL;

    return result;

}



void printtabs(int numtabs){
    for (int i = 0; i < numtabs; i++){
        printf("\t");
        
    }
    return;
}


void printtree_rec(struct treenode_t *root, int level){
    if (!root){
        printtabs(level);
        printf("--- empty tree ---\n");

        return;
    }

    printtabs(level);
    printf("Leaf = %d\n", root->value);
    printtabs(level);
    
    printf("left of %d\n", root->value);
    printtree_rec(root->left_child, level + 1);
    printtabs(level);

    printf("right of %d\n", root->value);
    printtree_rec(root->right_child, level + 1);
    printtabs(level);

    printf("\n");    

    //printf("good?\n");

}



void printtree(struct treenode_t *root){
    printtree_rec(root, 0);
}


bool insert_number(struct treenode_t **root, int val){
    struct treenode_t **tmp = root;

    if(!(*root)){
        *root = createnode(val);
        return true;
    }

    if(val == (**tmp).value){
        printf("Could not insert %d. Tree is full.\n", val);
        return false;
    }

    if(val < (*tmp)->value){
        return insert_number(&(**tmp).left_child, val);
    }

    if(val > (*tmp)->value){
        return insert_number(&(**tmp).right_child, val);
    }

}


bool find_number(struct treenode_t **root, int val){

    if(!(*root)){
        //printf("Tree is empty\n");
        return false;
    }

    if((*root)->value == val){
        return true;
    }

    if(val < (*root)->value){
        find_number(&(*root)->left_child, val);
    }

    if(val > (*root)->value){
        find_number(&(*root)->right_child, val);
    }
    
}


void in_order_printer(struct treenode_t *head){

    if(!head){
        return;
    }

    in_order_printer(head->left_child);
    printf("%d\n", head->value);
    in_order_printer(head->right_child);
    return;

}

void post_order_printer(struct treenode_t *head){

    if(!head){
        return;
    }

    post_order_printer(head->right_child);
    printf("%d\n", head->value);
    post_order_printer(head->left_child);
}

int main(){
    
    //int tabs = 1;
    struct treenode_t *new_node = NULL;

    insert_number(&new_node, 15);
    insert_number(&new_node, 11);
    insert_number(&new_node, 24);
    insert_number(&new_node, 5);
    insert_number(&new_node, 19);
    insert_number(&new_node, 16);

    /*
    if(find_number(&new_node, 19)){
        printf("19 is in the tree\n");
    }
    */
    printtree(new_node);

    in_order_printer(new_node);

    insert_number(&new_node, 48);

    printf("\n");
    post_order_printer(new_node);



}
