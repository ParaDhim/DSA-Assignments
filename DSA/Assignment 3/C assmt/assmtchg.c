#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Node
{

    struct Node *left;
    char data;
    int freq;
    struct Node *right;
};

struct Heap
{
    struct Node **arr;
    int heap_len;
    int arr_len;
    int size;
};

void swap(struct Node **a, struct Node **b)
{
    struct Node *temp = *a;
    *a = *b;
    *b = temp;
}

struct Node *NodeCreate(char data, int freq)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->left = p->right = NULL;
    p->data = data;
    p->freq = freq;
    return p;
}

struct Heap *Create_Heap(struct Heap *p, int size)
{
    p = (struct Heap *)malloc(sizeof(struct Heap));

    p->size = size;
    p->arr = (struct Node **)malloc((size + 1) * sizeof(struct Node *));
    p->heap_len = size;
    p->arr_len = size;
    return p;
}

void insert_at(struct Node *arr[], int idx, struct Node *q)
{
    if (idx == 1)
    {
        return;
    }
    int parent = idx / 2;

    if (arr[parent]->freq > arr[idx]->freq)
    {
        swap(&arr[parent], &arr[idx]);
        insert_at(arr, parent, q);
    }
}

void insert(struct Heap *p, struct Node *q)
{
    int n = p->heap_len;
    p->arr[n + 1] = q;
    insert_at(p->arr, n + 1, q);
    p->heap_len += 1;
}

void heapify_at(struct Heap *p, int i, int n)
{

    int left = i * 2;

    int right = left + 1;

    int smallest = i;

    if (left <= n && p->arr[left]->freq < p->arr[smallest]->freq)
    {

        smallest = left;
    }
    if (right <= n && p->arr[right]->freq < p->arr[smallest]->freq)
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(&p->arr[smallest], &p->arr[i]);
        heapify_at(p, smallest, n);
    }
}

void min_heapify(struct Heap *p, int i, int n)
{

    heapify_at(p, i, p->heap_len);
}

void build_min_heap(struct Heap *p)
{

    int mid = ((p->heap_len) / 2);

    for (int i = mid; i >= 1; i--)
    {

        min_heapify(p, i, p->heap_len);
    }
}

struct Node *HeapExtractMin(struct Heap *p)
{
    int last = p->heap_len;
    swap(&p->arr[last], &p->arr[1]);
    p->heap_len -= 1;
    min_heapify(p, 1, p->heap_len);
    return p->arr[last]; // here we were required to use p->arr[last] and the last in nithing but p->heap_len
}

void Heapsort(struct Heap *p)
{
    for (int i = 1; i <= p->arr_len; i++)
    {
        HeapExtractMin(p);
    }
}

void merge(int arr[], char arr1[], int low, int mid, int high, int n)
{
    int i, j, k;
    i = low;
    j = low;
    k = mid + 1;
    int temp[n];
    char temp1[n];

    while (i <= mid && k <= high)
    {
        if (arr[i] < arr[k])
        {
            temp[j] = arr[i];
            temp1[j] = arr1[i + 1];
            i++;
            j++;
        }
        else
        {
            temp[j] = arr[k];
            temp1[j] = arr1[k + 1];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[j] = arr[i];
        temp1[j] = arr1[i + 1];
        i++;
        j++;
    }
    while (k <= high)
    {
        temp[j] = arr[k];
        temp1[j] = arr1[k + 1];
        k++;
        j++;
    }

    for (int l = low; l <= high; l++)
    {
        arr[l] = temp[l];
        arr1[l + 1] = temp1[l];
    }
}

void mergesort(int arr[], char arr1[], int low, int high, int n)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mergesort(arr, arr1, low, mid, n);
    mergesort(arr, arr1, mid + 1, high, n);
    merge(arr, arr1, low, mid, high, n);
}

// The main function that builds a
// Huffman Tree and print codes by traversing
// the built Huffman Tree
int entryno = 0;

struct Node *buildHuff(struct Heap *p)
{
    struct Node *lchild, *rchild, *mainFreq;
    while (p->heap_len != 1)
    {
        lchild = HeapExtractMin(p);
        rchild = HeapExtractMin(p);

        mainFreq = NodeCreate('#', lchild->freq + rchild->freq);

        mainFreq->left = lchild;
        mainFreq->right = rchild;

        insert(p, mainFreq);
    }
    return (HeapExtractMin(p));
}

void Inorder(struct Node *p)
{
    if (p == NULL)
    {
        return;
    }
    printf("%d\n", p->freq);
    Inorder(p->left);
    Inorder(p->right);
}

void codeGenerater(struct Node *root, int array[], int head, FILE *wptr)
{
    if (root->left)
    {
        array[head] = 0;
        codeGenerater(root->left, array, head + 1, wptr);
    }
    if (root->right)
    {
        array[head] = 1;
        codeGenerater(root->right, array, head + 1, wptr);
    }

    if (root->left == NULL && root->right == NULL)
    {
        printf("%c ", root->data);
        fprintf(wptr, "%c %d\n", root->data, root->freq);

        for (int i = 0; i < head; i++)
        {
            printf("%d", array[i]);
        }
        printf("\n");
    }
}
void codeWriter(struct Node *root, int array1[], int head1, FILE *wptr)
{
    if (root->left)
    {
        array1[head1] = 0;
        codeWriter(root->left, array1, head1 + 1, wptr);
    }
    if (root->right)
    {
        array1[head1] = 1;
        codeWriter(root->right, array1, head1 + 1, wptr);
    }

    if (root->left == NULL && root->right == NULL)
    {
        for (int i = 0; i < root->freq; i++)
        {

            for (int j = 0; j < head1; j++)
            {
                fprintf(wptr, "%d", array1[j]);
            }
        }
    }
}

int main()
{
    FILE *fp = NULL;
    int count = 0;
    char ch;
    char f1[20];
    char f2[20];
    char f3[20];
    char arr[20];
    int mod;
    int idx = 0;
    printf("Enter the name of the input file\n");
    scanf("%s", &f1);
    printf("Enter the name of the output file\n");
    scanf("%s", &f3);
    printf("Enter mode -0 for compression, 1 for decompression\n");
    scanf("%d", &mod);
    if (mod == 0)
    {
        fp = fopen(f1, "r");
        if (fp == NULL)
        {
            printf("Error");
            exit(1);
        }

        while ((ch = fgetc(fp)) != EOF)
        {
            count += 1;
            if (idx == 0)
            {
                idx += 1;
                arr[idx] = fgetc(fp);
            }

            else if (ch != arr[idx])
            {
                idx += 1;
                arr[idx] = fgetc(fp);
            }
        }
        rewind(fp);

        int arr1[idx];
        int idx1 = 0;

        int i = 1;
        int count1 = 0;
    label:
        count1 = 0;

        while ((ch = fgetc(fp)) != EOF)
        {
            if (arr[i] == ch)
            {

                count1 += 1;
            }
            if (arr[i] != ch)
            {
                break;
            }
        }

        arr1[idx1] = count1;

        idx1 += 1;
        if (i < idx)
        {
            i += 1;

            goto label;
        }

        for (int i = 1; i < idx1; i++)
        {
            arr1[i] += 1;
        }

        int low = 0;
        int high = idx - 1;
        mergesort(arr1, arr, low, high, idx);

        fclose(fp);

        struct Heap *H;
        H = Create_Heap(H, idx);

        for (int i = 1; i <= idx; i++)
        {
            H->arr[i] = NodeCreate(arr[i], arr1[i - 1]);
        }

        build_min_heap(H);

        struct Node *root = buildHuff(H);

        int array[idx * 2], head = 0;

        FILE *wptr = NULL;

        wptr = fopen(f3, "wb");

        codeGenerater(root, array, head, wptr);
        int array1[idx * 2], head1 = 0;
        codeWriter(root, array1, head1, wptr);

        fclose(wptr);
    }

    // --------------decoding   -------------
    if (mod == 1)
    {
        char cr;

        FILE *deptr = NULL;

        deptr = fopen(f1, "rb");
        int countLines = 0;
        FILE *dewptr = NULL;
        dewptr = fopen(f3, "wb");

        while ((cr = fgetc(deptr)) != EOF)
        {
            if (cr == '\n')
            {
                countLines += 1;
            }
        }
        char cr1[countLines];
        char cr2[countLines];
        int p[countLines];
        printf("The total number of lines in the file are: %d\n", countLines + 1);
        rewind(deptr);
        for (int i = 0; i < countLines; i++)
        {
            if (fscanf(deptr, "%*s %d", &p[i]) == 1)
            {
            }
        }
        rewind(deptr);
        for (int i = 0; i < countLines; i++)
        {
            if (fscanf(deptr, "%s %*d", &cr1[i]) == 1)
            {
            }
        }
        for (int i = 0; i < countLines; i++)
        {

            printf("%c %d\n", cr1[i], p[i]);
        }
        printf("\n");
        struct Heap *H;
        H = Create_Heap(H, countLines);

        for (int i = 1; i <= countLines; i++)
        {
            H->arr[i] = NodeCreate(cr1[i - 1], p[i - 1]);
        }

        build_min_heap(H);

        struct Node *root = buildHuff(H);

        rewind(deptr);
        int count = 0;
        while ((cr = fgetc(deptr)) != EOF)
        {
            if (cr == '\n')
            {
                count += 1;
                if (count == countLines)
                {
                    break;
                }
            }
        }
        int c;
        struct Node *poin = root;
        while ((cr = fgetc(deptr)) != EOF)
        {
            if (cr == '0')
            {
                poin = poin->left;
            }
            if (cr == '1')
            {
                poin = poin->right;
            }
            if (poin->left == NULL && poin->right == NULL)
            {
                fprintf(dewptr, "%c", poin->data);
                poin = root;
            }
        }
        fclose(deptr);
        fclose(dewptr);
    }
    return 0;
}
