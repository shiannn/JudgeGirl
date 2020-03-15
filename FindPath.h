#include <stdbool.h>
#define MaxRoad 10010

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