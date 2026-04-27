import math

def tsp(dist):
    n=len(dist)
    VISITED_ALL=(1<<n)-1
    dp=[[-1]*n for _ in range(1<<n)]

    def solve(mask,pos):
        if mask==VISITED_ALL:
            return dist[pos][0]
        if dp[mask][pos]!=-1:
            return dp[mask][pos]

        ans=math.inf
        for city in range(n):
            if (mask&(1<<city))==0:
                new_cost=dist[pos][city]+solve(mask|(1<<city),city)
                ans=min(ans,new_cost)

        dp[mask][pos]=ans
        return ans

    return solve(1,0)

if __name__=="__main__":
    dist=[
        [0,10,15,20],
        [10,0,35,25],
        [15,35,0,30],
        [20,25,30,0]
    ]
    print("Minimum TSP cost:",tsp(dist))
