//DFS函数访问单个连通块，nowVisst为当前访问编号
//head为头目,numMember为成员编号,totalValue为连通块总边权,均为引用.
void DFS(int nowVisit,int& head,int  &numMember, int& totalValue){
    numMember++;
    vis[nowVisit] = true;
    if(weight[nowVisit] > weight[head]) head = nowVisit;   //更新头目
    for(int i = 0; i < numPerson; i++){
        if(G[nowVisit][i] > 0){
            totalValue += G[nowVisit][i];
            G[nowVisit][i] = G[i][nowVisit] = 0;
            if(vis[i] == false){
                DFS(i, head, numMember, totalValue);
            }
        
        }
    }
}