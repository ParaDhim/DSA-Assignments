#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

struct Heap
{
    int *arr;
    int heap_len;
    int arr_len;
    int size;
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct Heap *Create_Heap(struct Heap *p, int size)
{
    p = (struct Heap *)malloc(sizeof(struct Heap));
    assert(p);
    p->arr = (int *)malloc((size + 1) * (sizeof(int)));
    assert(p->arr);
    p->heap_len = size;
    p->arr_len = size;
    p->size = size;
    return p;
}

void insert_at(int arr[], int idx, int val)
{
    if (idx == 1)
    {
        return;
    }
    int parent = idx / 2;
    // arr[n+1] = val;
    if (arr[parent] > arr[idx])
    {
        swap(&arr[parent], &arr[idx]);
        insert_at(arr, parent, val);
    }
}

void insert(struct Heap *p, int val)
{
    int n = p->heap_len;
    p->arr[n + 1] = val;
    insert_at(p->arr, n + 1, val);
    p->heap_len += 1;
}

void heapify_at(int arr[], int i, int n)
{
    int left = 2 * i;
    int right = left + 1;
    int smallest = i;

    if (left <= n && arr[left] < arr[smallest])
    {
        smallest = left;
    }
    if (right <= n && arr[right] < arr[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(&arr[smallest], &arr[i]);
        heapify_at(arr, smallest, n);
    }
}

void min_heapify(struct Heap *p, int n)
{
    heapify_at(p->arr, n, p->heap_len);
}

void build_min_heap(struct Heap *p)
{
    int mid = (p->heap_len / 2);
    for (int i = mid; i >= 1; i--)
    {
        min_heapify(p, i);
    }
}

int HeapExtractMin(struct Heap *p)
{
    int last = p->heap_len;
    swap(&p->arr[last], &p->arr[1]);
    p->heap_len -= 1;
    min_heapify(p, 1);
    printf("%d\n",p->arr[last]);
    // return p->arr[last]; // here we were required to use p->arr[last] and the last in nithing but p->heap_len
}

void Heapsort(struct Heap *p)
{
    for (int i = 1; i <= p->arr_len; i++)
    {
        HeapExtractMin(p);
        // printf("%d ",HeapExtractMin(p));
    }
}

int main()
{
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);
    struct Heap *H;
    H = Create_Heap(H, size);
    for (int i = 1; i <= size; i++)
    {
        scanf("%d", &H->arr[i]);
    }

    // for (int i = 1; i <= H->arr_len; i++)
    // {
    //     printf("%d ", H->arr[i]);
    // }
    printf("\n");
    build_min_heap(H);
    // Heapsort(H);
    printf("\n");

    // printf("%d",H->arr_len);
    
    for (int i = 1; i <= H->arr_len; i++)
    {
        printf("%d ", H->arr[i]);
        // printf("%d",H->heap_len);
        
    }
    return 0;
}