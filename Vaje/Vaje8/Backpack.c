#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

bool SMO_ZE[2001][2001];

int* readToArray(int const n)
{
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    return arr;
}

//set resitev
int optimalna_cena(int stPredmetov, int* prostornine, int* cene, int vNah)
{
    int max_cena = 0;
    int st_mnozic = 1 << stPredmetov;

    for (int m = 0; m < st_mnozic;m++)
    {
        int mnozica = m;
        int cena = 0;
        int prostornina = 0;
        int i = 0;
        while (mnozica > 0)
        {
            if (mnozica % 2 == 1)
            {
                cena += cene[i];
                prostornina += prostornine[i];
            }
            i++;
            mnozica /= 2;
        }

        if (prostornina <= vNah && cena > max_cena)
            max_cena = cena;
    }

    return max_cena;
}

int** createTable(int const h, int const w)
{
    int** arr = (int**)(malloc(h*sizeof(int*)));
    if (arr == NULL) exit(1);
    for (int i = 0; i < h; i++)
        arr[i] = (int*)calloc(w,sizeof(int));
    return arr;
}

int*** create3DTable(int const h, int const w, int const d)
{
    int*** arr =(int***) malloc(h*sizeof(int**));
    if (arr == NULL) exit(1);
    for (int i = 0; i < h; i++)
    {
        arr[i] = (int**)calloc(w,sizeof(int*));
        if (arr[i] == NULL) exit(1);
        for (int j = 0; j < w; j++)
            arr[i][j] = (int*)calloc(d,sizeof(int));
    }
    return arr;
}

void dispose(int** arr, int const h)
{
    for (int i = 0; i < h; i++)
        free(arr[i]);
    free(arr);
}

void dispose3D(int*** arr, int const h, int const d)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < d; j++)
            free(arr[i][j]);
        free(arr[i]);
    }
    free(arr);
}

int search(int const no_pred, int* volumes, int* prices, int volume, int idx, int**memo)
{
    if (idx == no_pred)
        return 0;
    if (SMO_ZE[idx][volume] >0) return memo[idx][volume];

    int const brez = 0 + search(no_pred, volumes, prices, volume, idx + 1,memo);
    memo[idx][volume] = brez;

    if (volumes[idx] <= volume)
    {
        int const z = prices[idx] + search(no_pred, volumes, prices, volume - volumes[idx], idx + 1, memo);
        if (z > brez) memo[idx][volume] = z;
    }
    SMO_ZE[idx][volume] = true;
    return memo[idx][volume];
}

int optimal_rek(int const no_pred, int* volumes, int* prices, int const volume)
{
    int** memo = createTable(no_pred+1, volume + 1);
    int const n = search(no_pred, volumes, prices, volume,0,memo);
    dispose(memo, no_pred + 1);
    return n;
}



//Naloga 2
int search_odd(int const no_pred, int* volumes, int* prices, int odd,int volume, int idx, int***memo, int*** ze)
{
    if (idx == no_pred)
        return 0;
    if (ze[idx][odd][volume] >0) return memo[idx][odd][volume];

    int const brez = 0 + search_odd(no_pred, volumes, prices, volume,odd, idx + 1,memo,ze);
    memo[idx][odd][volume] = brez;

    if (volumes[idx] <= volume && (odd - (volumes[idx] % 2)) >= 0)
    {
        int const z = prices[idx] + search_odd(no_pred, volumes, prices, odd - (volumes[idx] % 2) ,volume - volumes[idx], idx + 1, memo, ze);
        if (z > brez) memo[idx][odd][volume] = z;
    }
    ze[idx][odd][volume] = true;
    return memo[idx][odd][volume];
}

int optimal_odd(int const no_pred, int* volumes, int* prices, int const odd, int const volume)
{
    int*** memo = create3DTable(no_pred+1,odd+1, volume + 1);
    int*** ze = create3DTable(no_pred+1,odd+1, volume + 1);
    int const n = search_odd(no_pred, volumes, prices, odd ,volume,0,memo,ze);
    dispose3D(memo, odd + 1,volume + 1);
    dispose3D(ze, no_pred + 1, volume + 1);
    return n;
}


int main()
{
    int volume, n, odd;
    scanf("%d %d %d", &volume, &n, &odd);
    int* volumes = readToArray(n);
    int* prices = readToArray(n);
    optimal_rek(n, volumes, prices, volume);

    free(volumes);
    free(prices);

}