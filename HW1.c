#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

void print_type(TreeNode *root){
    if (root->data >=0 && root->data <=9){
        printf("%d", root->data );   
    }
    else{
        printf("%c", root->data );   
    }
}

// 전위순회
void preorder( TreeNode *root ){
    if ( root ){
        print_type(root);            // v
        preorder( root->left );      // L
        preorder( root->right );     // R
    }
}

// 중위순회
void inorder( TreeNode *root ){
    if ( root ){
        inorder( root->left );       // L
        print_type(root);            // v
        inorder( root->right );      // R
    }
}

// 후위순회
void postorder( TreeNode *root ){
    if ( root ){
        postorder( root->left );     // L
        postorder( root->right );    // R
        print_type(root);            // v
    }
}

int evaluate(TreeNode *root) {

    if( root == NULL) return 0;
    if( root->left == NULL && root->right == NULL)
        return root->data;
    else {
        int op1 = evaluate(root->left);
        int op2 = evaluate(root->right);

        printf("%d %c %d을 계산합니다.\n", op1, root->data, op2);

        switch(root->data){ // operator
            case '+': return op1 + op2;
            case '-': return op1 - op2;
            case '*': return op1 * op2;
            case '/': return op1 / op2;
        }
    }

    return 0;
}

int main(){
    
    TreeNode n1={3, NULL, NULL};
    TreeNode n2={8, NULL, NULL};
    TreeNode n3={2, NULL, NULL};
    TreeNode n4={'/', &n2, &n3};
    TreeNode n5={2, NULL, NULL};
    TreeNode n6={'/', &n4, &n5};
    TreeNode n7={'*', &n1, &n6};
    TreeNode n8={4, NULL, NULL};
    TreeNode n9={'+', &n7, &n8};
    TreeNode *root= &n9;
    
    preorder(root); printf("\n");
    inorder(root); printf("\n");
    postorder(root); printf("\n"); 
    printf("수식은 %d입니다. \n", evaluate(root));
   
    return 0;
}
