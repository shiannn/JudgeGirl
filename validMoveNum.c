int validMoveNum(int r, int c, int n, int visited[100][100]){
    int dy[] = {-2,-1,1,2,2,1,-1,-2};
    int dx[] = {1,2,2,1,-1,-2,-2,-1};
    if(r<0||r>=n||c<0||c>=n||visited[r][c]!=0){
        return -1;
    }
    int sy,sx,valid=0;
    for(int i=0;i<8;i++){
        sy = r+dy[i];
        sx = c+dx[i];
        if(!(sy<0||sy>=n||sx<0||sx>=n||visited[sy][sx]!=0)){
            valid += 1;
        }
    }
    return valid;
}