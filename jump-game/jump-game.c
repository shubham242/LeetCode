
bool canJump(int* A, int n){
    int i = 0;
    for (int reach = 0; i < n && i <= reach; ++i)
    {
        reach = i + A[i]> reach?i+A[i]:reach;
        if(reach>=n-1)
            return true;
    }
    return false;
}