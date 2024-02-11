void func2(int *a, int *b){
        //PAss by reference
        int temp = *a;
        *a = *b;
        *b = temp;
    }