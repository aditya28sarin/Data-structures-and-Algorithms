bool isIdentical(Node* a, Node* b)  
{  
    /*1. both empty */
    if (a == NULL && b == NULL)  
        return true;  
  
    /* 2. both non-empty -> compare them */
    if (a != NULL && b != NULL)  
    {  
        return
        (  
            a->data == b->data &&  
            isIdentical(a->left, b->left) &&  
            isIdentical(a->right, b->right)  
        );  
    }  
      
    /* 3. one empty, one not -> false */
    return 0;  
}  