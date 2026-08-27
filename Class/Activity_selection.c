#include <stdio.h>

void sort(int n, int st_time[], int fin_time[], int act_id[])
{
    for (int i = 0; i < n -1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (fin_time[j + 1] < fin_time[j])
            {
                int temp = fin_time[j];
                fin_time[j] = fin_time[j + 1];
                fin_time[j + 1] = temp;

                temp = st_time[j];
                st_time[j] = st_time[j + 1];
                st_time[j + 1] = temp;

                temp = act_id[j];
                act_id[j] = act_id[j + 1];
                act_id[j + 1] = temp;
            }
        }
    }
}

int activity_selection(int n, int st_time[], int fin_time[], int act_id[], int ans[])
{

    sort(n, st_time, fin_time, act_id);

    int count = 1;
    ans[0] = act_id[0];
    int lt = fin_time[0];
    for(int i = 1; i<n; i++){
        if(st_time[i]>=lt){
            ans[count] = act_id[i];
            count++;
            lt = fin_time[i];
        }
    }
    return count;
}

int main()
{

    int n;
    printf("Enter number of Activity: ");
    scanf("%d", &n);
    int st_time[n], fin_time[n] , act_id[n], ans[n];
    
    printf("Enter start times:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &st_time[i]);
        act_id[i] = i+1;
    }
    printf("Enter finish times:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &fin_time[i]);
    }

    int nact = activity_selection(n, st_time, fin_time, act_id, ans);

    printf("\nSelected Activity Numbers:\n");
    for(int i = 0; i < nact; i++){
        printf(" %d", ans[i]);
    }
    return 0;
}