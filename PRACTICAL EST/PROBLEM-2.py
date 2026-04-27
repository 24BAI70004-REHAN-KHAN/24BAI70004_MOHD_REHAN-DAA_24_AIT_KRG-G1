import heapq

def dijkstra(graph,start):
    n=len(graph)
    dist=[float('inf')]*n
    dist[start]=0
    pq=[(0,start)]

    while pq:
        current_dist,node=heapq.heappop(pq)
        if current_dist>dist[node]:
            continue
        for neighbor,weight in graph[node]:
            distance=current_dist+weight
            if distance<dist[neighbor]:
                dist[neighbor]=distance
                heapq.heappush(pq,(distance,neighbor))
    return dist

if __name__=="__main__":
    graph=[
        [(1,4),(2,1)],
        [(3,1)],
        [(1,2),(3,5)],
        []
    ]
    start_node=0
    distances=dijkstra(graph,start_node)
    print("Shortest distances from node",start_node,":",distances)
