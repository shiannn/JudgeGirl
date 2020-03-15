#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#define MaxRoad 2*10010

typedef struct Road{
    int city1idx, city2idx;
}Road;

typedef struct _graph {
    // design your object here
    Road RoadsArray[MaxRoad];
    int Mroads;
} Graph;
typedef struct _map{
    // design your object here
    int cityNum;
    int cityidx[MaxRoad];
    Road* RoadptrArray[MaxRoad];
} Map;



void init(Graph *graph, int M); // initialize graph
void addRoad(Graph *graph, int city1, int city2); // add roads into graph
void normalized(Graph *graph, Map *map);  // sort the roads by indices and build the map. 
bool hasPath(Graph *graph, Map *map, int city1, int city2);// check if two cities are connected

bool dfs2(Graph *graph, Map *map, int st, int tar, int vis[]);
void dfs(Graph *graph, Map *map, int st, int vis[]);

void init(Graph *graph, int M){
    // initialize graph
    graph -> Mroads = M;
    for(int i=0;i<MaxRoad;i++){
        graph -> RoadsArray[i].city1idx = -1;
        graph -> RoadsArray[i].city2idx = -1;
    }
}

void addRoad(Graph *graph, int city1, int city2){
    // add roads into graph
    graph->RoadsArray[graph->Mroads].city1idx = city1;
    graph->RoadsArray[graph->Mroads].city2idx = city2;
    graph->Mroads += 1;

    graph->RoadsArray[graph->Mroads].city1idx = city2;
    graph->RoadsArray[graph->Mroads].city2idx = city1;
    graph->Mroads += 1;
}

int cmp(const void* ptr1, const void* ptr2){
    Road* R1 = (Road*)ptr1;
    Road* R2 = (Road*)ptr2;
    if(R1 -> city1idx > R2 -> city1idx){
        return 1;
    }
    else if(R1 -> city1idx < R2 -> city1idx){
        return -1;
    }
}

int cmpBS(const void* ptr1, const void* ptr2){
    return ( *(int*)ptr1 - *(int*)ptr2 );
}

void normalized(Graph *graph, Map *map){
    // sort the roads by indices and build the map. 
    qsort(graph->RoadsArray, graph->Mroads, sizeof(Road), cmp);
    // construct map
    //map = (Map*)malloc(sizeof(Map));
    map -> cityNum = 0;
    for(int i=0;i<graph->Mroads;i++){
        if(map -> cityNum == 0){
            map->cityidx[map -> cityNum] = graph->RoadsArray[i].city1idx;
            map->RoadptrArray[map -> cityNum] = &graph->RoadsArray[i];
            map -> cityNum += 1;
        }
        else{
            if(map->cityidx[map -> cityNum-1] != graph->RoadsArray[i].city1idx){
                map->cityidx[map -> cityNum] = graph->RoadsArray[i].city1idx;
                map->RoadptrArray[map -> cityNum] = &graph->RoadsArray[i];
                map -> cityNum += 1;
            }
        }
        
        
    }
}

int vis[MaxRoad]={0}; //vis will cause problem
bool hasPath(Graph *graph, Map *map, int city1, int city2){
    // check if two cities are connected
    for(int i=0;i<MaxRoad;i++){
        vis[i]=0;
    }
    vis[city1] = 1;
    dfs(graph, map, city1,vis);
    if(vis[city2]==1){
        return true;
    }
    else{
        return false;
    }
}


void dfs(Graph *graph, Map *map, int st, int vis[]){
    /*bsearch get st*/
    int *pos = bsearch(&st, map->cityidx, map->cityNum, sizeof(int), cmpBS);
    if(pos==NULL){
        return;
    }
    else{
        int idx = pos-map->cityidx;
        //printf("idx == %d\n",idx);
        Road* RoadStep = map->RoadptrArray[idx];
        while(RoadStep->city1idx == map->RoadptrArray[idx]->city1idx){
            if(vis[RoadStep->city2idx]==0){
                //printf("[dfs]city1idx==%d city2idx==%d\n",RoadStep->city1idx,RoadStep->city2idx);
                vis[RoadStep->city2idx] = 1;
                dfs(graph, map, RoadStep->city2idx, vis);
                //vis[RoadStep->city2idx] = 0;
            }
            RoadStep ++;
        }
        return;
    }
}

int main(){
    int Mroads;
    scanf("%d",&Mroads);
    Graph graph;
    init(&graph, 0);

    for(int i=0;i<Mroads;i++){
        int src,dst;
        scanf("%d%d",&src,&dst);
        addRoad(&graph,src,dst);
        //printf("std -99 %d\n",i);    
    }
    
    Map *map = (Map*)malloc(sizeof(Map));;
    normalized(&graph, map);

    #ifdef debug
    printf("Roads == %d\n",graph.Mroads);
    for(int i=0;i<graph.Mroads;i++){
        printf("%d %d\n",graph.RoadsArray[i].city1idx,graph.RoadsArray[i].city2idx);
    }
    #endif

    #ifdef debugMap

    for(int i=0;i<map->cityNum;i++){
        printf("map->cityidx[%d] == %d\n",i,map->cityidx[i]);
        Road* RoadStep = map->RoadptrArray[i];
        while(RoadStep->city1idx == map->RoadptrArray[i]->city1idx){
            printf("city1idx==%d city2idx==%d\n",RoadStep->city1idx,RoadStep->city2idx);
            RoadStep += 1;
        }
    }
    #endif
    int Q;
    scanf("%d",&Q);
    int Qsrc,Qdst;

    
    for(int i=0;i<Q;i++){
        scanf("%d%d",&Qsrc,&Qdst);
        //printf("Qsrc==%d Qdst==%d\n",Qsrc,Qdst);
        
        int ret = hasPath(&graph, map, Qsrc, Qdst);
        if(ret == true){
            printf("There is a path.\n");
        }
        else{
            printf("There is no path.\n");
        }
    }
    return 0;
}