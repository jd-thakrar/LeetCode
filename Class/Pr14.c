
#include <stdio.h>

#define MAXN 50
#define MAXCAP 1000
#define INF 1000000000

int graph[MAXN][MAXN];
int dist[MAXN];
int visited[MAXN];

int population[MAXN], severity[MAXN], units[MAXN];
int reachable[MAXN];

long long dpValue[MAXN][MAXCAP + 1];
long long dpCost[MAXN][MAXCAP + 1];
int take[MAXN][MAXCAP + 1];

/* Practical 4: Max-Heap
   Higher severity gets higher priority. */
int higherPriority(int a, int b)
{
    if (severity[a] != severity[b])
        return severity[a] > severity[b];

    return population[a] > population[b];
}

void heapify(int heap[], int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < size &&
        higherPriority(heap[left], heap[largest]))
        largest = left;

    if (right < size &&
        higherPriority(heap[right], heap[largest]))
        largest = right;

    if (largest != i)
    {
        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        heapify(heap, size, largest);
    }
}

void buildMaxHeap(int heap[], int size)
{
    int i;

    for (i = size / 2 - 1; i >= 0; i--)
        heapify(heap, size, i);
}

/* Dijkstra: Find shortest safe routes
   from warehouse 0. */
void dijkstra(int n)
{
    int i, j, u, minDist;

    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[0] = 0;

    for (i = 0; i < n; i++)
    {
        u = -1;
        minDist = INF;

        for (j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < n; j++)
        {
            if (graph[u][j] != INF &&
                dist[u] != INF &&
                dist[u] + graph[u][j] < dist[j])
            {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }
}

int main()
{
    int n, m, capacity;
    int i, j, u, v, cost, damaged, weatherUnsafe;
    int heap[MAXN], heapSize = 0;
    int remaining;
    long long totalBenefit = 0, totalCost = 0;
    int totalUnits = 0, totalBeneficiaries = 0;

    printf("Enter locations including warehouse: ");
    scanf("%d", &n);

    if (n < 2 || n > MAXN)
    {
        printf("Invalid number of locations.\n");
        return 1;
    }

    printf("Enter number of roads: ");
    scanf("%d", &m);

    if (m < 0)
    {
        printf("Invalid number of roads.\n");
        return 1;
    }

    /* Initialize graph.
       Practical 13: Road reports are checked
       before adding safe roads to the graph. */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }

    printf("Enter each road as:\n");
    printf("from to cost damaged weatherUnsafe\n");
    printf("Use 0 = No and 1 = Yes.\n");
    printf("Locations are numbered 0 to %d.\n", n - 1);

    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d %d %d",
              &u, &v, &cost, &damaged, &weatherUnsafe);

        if (u < 0 || u >= n || v < 0 || v >= n ||
            u == v || cost <= 0 ||
            (damaged != 0 && damaged != 1) ||
            (weatherUnsafe != 0 && weatherUnsafe != 1))
        {
            printf("Invalid road data.\n");
            return 1;
        }

        /* Exclude damaged and weather-unsafe roads. */
        if (!damaged && !weatherUnsafe)
        {
            if (cost < graph[u][v])
            {
                graph[u][v] = cost;
                graph[v][u] = cost;
            }
        }
    }

    printf("Enter warehouse capacity (units, max %d): ",
           MAXCAP);
    scanf("%d", &capacity);

    if (capacity < 0 || capacity > MAXCAP)
    {
        printf("Invalid warehouse capacity.\n");
        return 1;
    }

    /* Read district information. */
    for (i = 1; i < n; i++)
    {
        printf("District %d: population severity(1-5) "
               "requiredUnits: ", i);

        scanf("%d %d %d",
              &population[i], &severity[i], &units[i]);

        if (population[i] <= 0 ||
            severity[i] < 1 || severity[i] > 5 ||
            units[i] <= 0)
        {
            printf("Invalid district data.\n");
            return 1;
        }
    }

    /* Practical 11/12 concepts:
       Dijkstra is used for actual shortest routes.
       Prim/Kruskal are alternative network algorithms. */
    dijkstra(n);

    for (i = 1; i < n; i++)
    {
        reachable[i] =
            (dist[i] != INF && units[i] <= capacity);
    }

    /* Practical 8: Dynamic Programming Knapsack.
       Benefit = population * severity.
       Tie-break: lower transport cost. */
    for (i = 0; i <= n - 1; i++)
    {
        for (j = 0; j <= capacity; j++)
        {
            dpValue[i][j] = 0;
            dpCost[i][j] = 0;
            take[i][j] = 0;
        }
    }

    for (i = 1; i < n; i++)
    {
        for (j = 0; j <= capacity; j++)
        {
            dpValue[i][j] = dpValue[i - 1][j];
            dpCost[i][j] = dpCost[i - 1][j];

            if (reachable[i] && units[i] <= j)
            {
                long long benefit =
                    1LL * population[i] * severity[i];

                long long transportCost =
                    1LL * dist[i] * units[i];

                long long newValue =
                    dpValue[i - 1][j - units[i]] + benefit;

                long long newCost =
                    dpCost[i - 1][j - units[i]]
                    + transportCost;

                if (newValue > dpValue[i][j] ||
                    (newValue == dpValue[i][j] &&
                     newCost < dpCost[i][j]))
                {
                    dpValue[i][j] = newValue;
                    dpCost[i][j] = newCost;
                    take[i][j] = 1;
                }
            }
        }
    }

    /* Recover selected districts. */
    remaining = capacity;

    for (i = n - 1; i >= 1; i--)
    {
        if (take[i][remaining])
        {
            heap[heapSize++] = i;
            remaining -= units[i];
        }
    }

    /* Practical 4: Build Max-Heap to process
       the selected districts by severity. */
    buildMaxHeap(heap, heapSize);

    printf("\n--- FLOOD RELIEF DISTRIBUTION ---\n");

    while (heapSize > 0)
    {
        int d = heap[0];
        int temp = heap[0];

        heap[0] = heap[heapSize - 1];
        heap[heapSize - 1] = temp;
        heapSize--;

        heapify(heap, heapSize, 0);

        printf("\nDistrict: %d\n", d);
        printf("Severity: %d\n", severity[d]);
        printf("Beneficiaries: %d\n", population[d]);
        printf("Resources allocated: %d units\n", units[d]);
        printf("Shortest safe route cost: %d\n", dist[d]);

        totalBeneficiaries += population[d];
        totalUnits += units[d];
        totalBenefit +=
            1LL * population[d] * severity[d];

        totalCost += 1LL * dist[d] * units[d];
    }

    printf("\n--- SUMMARY ---\n");
    printf("Total beneficiaries: %d\n", totalBeneficiaries);
    printf("Total resources used: %d\n", totalUnits);
    printf("Remaining capacity: %d\n", capacity - totalUnits);
    printf("Total weighted benefit: %lld\n", totalBenefit);
    printf("Estimated transportation cost: %lld\n", totalCost);

    printf("\n--- UNREACHABLE DISTRICTS ---\n");

    for (i = 1; i < n; i++)
    {
        if (dist[i] == INF)
            printf("District %d: No safe route available.\n", i);
    }

    return 0;
}
