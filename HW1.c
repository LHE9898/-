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
    
    TreeNode *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8, *n9, *root;
    n1= (TreeNode *)malloc(sizeof(TreeNode));
    n2= (TreeNode *)malloc(sizeof(TreeNode));
    n3= (TreeNode *)malloc(sizeof(TreeNode));
    n4= (TreeNode *)malloc(sizeof(TreeNode));
    n5= (TreeNode *)malloc(sizeof(TreeNode));
    n6= (TreeNode *)malloc(sizeof(TreeNode));
    n7= (TreeNode *)malloc(sizeof(TreeNode));
    n8= (TreeNode *)malloc(sizeof(TreeNode));
    n9= (TreeNode *)malloc(sizeof(TreeNode));
    root = n9;
    
    n1->data = 3;   n1->left = NULL; n1->right = NULL;
    n2->data = 8;   n2->left = NULL; n2->right = NULL;
    n3->data = 2;   n3->left = NULL; n3->right = NULL;
    n4->data = '/'; n4->left = n2;   n4->right = n3;
    n5->data = 2;   n5->left = NULL; n5->right = NULL;
    n6->data = '/'; n6->left = n4;   n6->right = n5;
    n7->data = '*'; n7->left = n1;   n7->right = n6;
    n8->data = 4;   n8->left = NULL; n8->right = NULL;
    n9->data = '+'; n9->left = n7;   n9->right = n8;
    
    printf("전위표기식: ");  preorder(root);  printf("\n");
    printf("중위표기식: ");   inorder(root);   printf("\n");
    printf("후위표기식: "); postorder(root); printf("\n"); 
    printf("수식은 %d입니다. \n", evaluate(root));

    free(n1); free(n2); free(n3); 
    free(n4); free(n5); free(n6);
    free(n7); free(n8); free(n9);
   
    return 0;
}
