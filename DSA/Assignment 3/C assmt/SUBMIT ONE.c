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

// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

void swap(struct Node **a, struct Node **b)
{
    struct Node *temp = *a;
    *a = *b;
    *b = temp;
}

// struct Heap *Create_Heap(struct Heap *p, int size)
// {
//     p = (struct Heap *)malloc(sizeof(struct Heap));
//     assert(p);
//     p->arr = (struct Node *)malloc((size + 1) * (sizeof(struct Node)));
//     assert(p->arr);
//     p->heap_len = size;
//     p->arr_len = size;
//     p->size = size;
//     return p;
// }

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
    // arr[n+1] = val;
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
    // printf("%d\n",p->arr[0]->freq);
    // printf("%d\n", i);
    // printf("in heapify_at\n");
    // printf("%d\n",i*2);
    int left = i * 2;
    // printf("%d\n", left);
    // printf("%d\n", p->arr[left]->freq);
    int right = left + 1;
    // printf("%d\n", right);
    int smallest = i;
    // printf("%d\n", smallest);

    if (left <= n && p->arr[left]->freq < p->arr[smallest]->freq)
    {
        // printf("gone in left check\n");
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
    // printf("Exit taken");
}

void min_heapify(struct Heap *p, int i, int n)
{
    // printf("%d\n",p->arr[0]->freq);
    // printf("%d\n", i);
    // printf("in min heapify\n");
    heapify_at(p, i, p->heap_len);
}

void build_min_heap(struct Heap *p)
{
    // printf("%d\n",p->heap_len);
    int mid = ((p->heap_len) / 2);
    // printf("value of mid %d\n", mid);
    for (int i = mid; i >= 1; i--)
    {
        // printf("%d\n", i);
        // printf("in build heap\n");
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

// void printArr(int arr[], int n)
// {
//     int i;
//     for (i = 0; i < n; ++i)
//         printf("%d", arr[i]);

//     printf("\n");
// }

// void printCodes(struct Node *root, int arr[],int top)
// {

//     // Assign 0 to left edge and recur
//     if (root->left)
//     {

//         arr[top] = 0;
//         printCodes(root->left, arr, top + 1);
//     }

//     // Assign 1 to right edge and recur
//     if (root->right)
//     {

//         arr[top] = 1;
//         printCodes(root->right, arr, top + 1);
//     }

//     // If this is a leaf node, then
//     // it contains one of the input
//     // characters, print the character
//     // and its code from arr[]
//     if ((root->left == NULL) && (root->right == NULL))
//     {

//         printf("%c: ", root->data);
//         printArr(arr, top);
//     }
// }

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
        fputc(root->data, wptr);
        // int tempArr[1] =
        fputc(':', wptr);
        for (int i = 0; i < head; i++)
        {
            printf("%d", array[i]);
            fputc(array[i], wptr);
        }
        printf("\n");
        fputc('\n', wptr);
        // for (int i = 0; i < root->freq; i++)
        // {
        //     for (int i = 0; i < head; i++)
        //     {
        //         fputc(array[i], wptr);
        //     }
        // }
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
            // printf("----%d\n",root->freq);
            for (int j = 0; j < head1; j++)
            {
                fputc(array1[j], wptr);
                // fwrite(array1[j],1,1,wptr);
                // printf("%d",array1[j]);
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
        // for (int i = 1; i < idx + 1; i++)
        // {
        //     printf("%c", arr[i]);
        // }

        // printf("\n");
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

        // for (int i = 0; i < idx1; i++)
        // {
        //     printf("%d ", arr1[i]);
        // }
        // for (int i = 1; i < idx + 1; i++)
        // {
        //     printf("%c", arr[i]);
        // }
        /*Doubt need to be ask that number same numberwould be given uptill frequency or random would be given do mail to them asking the TAs*/
        fclose(fp);
        // printf("%d",idx);
        struct Heap *H;
        H = Create_Heap(H, idx);
        // printf("the index is %d",idx);
        for (int i = 1; i <= idx; i++)
        {
            H->arr[i] = NodeCreate(arr[i], arr1[i - 1]);
        }
        // for (int i = 1; i < idx+1; i++)
        // {
        //     printf("%c %d\n", H->arr[i]->data, H->arr[i]->freq);
        // }
        // printf("going to the build function\n");
        // printf("%d\n",H->arr[3]->freq);
        build_min_heap(H);
        // printf("out from the build function\n");

        // for (int i = 1; i <= idx; i++)
        // {
        //     printf("%c %d\n", H->arr[i]->data, H->arr[i]->freq);
        // }
        // printf("%d",H->heap_len);
        // everytime a new node is constructed and goes to the heap
        //  merge sort
        //  struct Node *last;
        //  root =
        //  need to construct each node and need to insert and insert it every time in the array
        struct Node *root = buildHuff(H);
        // Inorder(root);
        // printf("%c %d\n", H->arr[1]->data, H->arr[1]->freq);
        int array[idx * 2], head = 0;
        // int entry2[idx];
        // char entry1[idx];
        // printf("start");
        FILE *wptr = NULL;
        // FILE *wbptr = NULL;
        wptr = fopen(f3, "wb");
        // wbptr = fopen("out.txt", "wb");
        codeGenerater(root, array, head, wptr);
        int array1[idx * 2], head1 = 0;
        codeWriter(root, array1, head1, wptr);
        // printf("out");
        // for (int i = 0; i < count; i++)
        // {
        //     /* code */
        // }

        fclose(wptr);
    }
    // FILE *wbptr = NULL;
    // // FILE *wbptr = NULL;
    // wbptr = fopen("f3.txt", "rb");
    // // char str[200];
    // // printf("%c",fgets(str,100,wbptr));
    // // printf("%d",fgetc(wbptr));

    // fclose(wbptr);

    // FILE *wbptr = NULL;
    // wbptr = fopen("out.txt", "rb");
    // wbptr = fopen("out.txt", "wb");
    // printf("ended");
    // fclose(wbptr);

    // Doing the deencryption of the file given in the text document
    // --------------decoding   -------------
    if (mod == 1)
    {
        char cr;
        FILE *deptr = NULL;
        // FILE *wbptr = NULL;
        deptr = fopen("f1", "rb");
        int countLines = 0;
        FILE *dewptr = NULL;
        dewptr = fopen("f3", "rb");

        while ((cr = fgetc(deptr)) != EOF)
        {
            // printf("%d", cr);
            if (cr == '\n')
            {
                countLines += 1;
            }
        }
        rewind(deptr);
        printf("\n");
        printf("The total number of lines in the file are: %d\n", countLines + 1);
        int idex = 0;
        char reArrCh[countLines];
        int reArr[countLines][countLines];
        for (int i = 0; i <= (countLines); i++)
        {
            cr = fgetc(deptr);
            if (countLines > 2)
            {
                reArrCh[idex] = cr;
                if ((cr = fgetc(deptr)) == ':')
                {
                    // int numArr[countLines];
                    int numeric = 0;
                    while ((cr = fgetc(deptr)) != '\n')
                    {
                        reArr[idex][numeric] = cr;
                        // printf("%d", cr);
                        // printf(" numeric:%d ", numeric);
                        numeric += 1;
                        // printf(" numeric:%d ", numeric);
                    }
                    // printf(" numeric:%d ", numeric);
                    reArr[idex][numeric] = 2;
                    // printf("%d", reArr[idex][numeric]);
                    // printf("\n");
                    // reArrCh[idex] = numArr;
                }

                if (cr == '\n')
                {
                    idex += 1;
                    continue;
                }
            }
        }
        // printf("%d", countLines);
        // for (int i = 0; i < countLines; i++)
        // labelJi:
        //     printf("\n");
        // {
        //     for (int j = 0; j < countLines; j++)
        //     // while (reArr[i][j] != '\0')
        //     // {

        //     {
        //         // if (i > countLines-1)
        //         // {
        //         //     goto exit;
        //         // }

        //         if (reArr[i][j] == 2)
        //         {
        //             i += 1;
        //             goto labelJi;
        //             continue;
        //         }
        //         if (reArr[i][j] == 2 && )
        //         {
        //             i += 1;
        //             goto labelJi;
        //             printf("%d ", reArr[i][j]);
        //             continue;
        //         }
        //     }
        //     printf("\n");
        //     // }
        // }
        int idexs[countLines];
        for (int i = 0; i < countLines; i++)
        {
            int countNum = 0;
            for (int j = 0; j < countLines; j++)
            {
                if ((reArr[i][j]) == 2)
                {
                    break;
                }
                countNum += 1;
                // printf("%d", reArr[i][j]);
            }
            idexs[i] = countNum;
            printf("\n");
        }
        
        while ((cr = fgetc(deptr)) != '\n')
        {
            printf("%d",cr);
            fputc(cr,dewptr);
        }
        
        
        for (int i = 0; i < countLines; i++)
        {
            printf("%d", idexs[i]);
        }
        printf("\n");

        for (int i = 0; i < countLines; i++)
        {
            printf("%c\n", reArrCh[i]);
            // reArrCh[i];
        }
        int min = idexs[0];
        int max = idexs[0];
        for (int i = 1; i < countLines; i++)
        {
            if (idexs[i] < min)
            {
                min = idexs[i];
            }
        }
        for (int i = 1; i < countLines; i++)
        {
            if (idexs[i] > max)
            {
                max = idexs[i];
            }
        }
        cr = fgetc(deptr);
        int check[max];
        printf("%d", cr);
        // printf("%d",min);
        // here need to check idexs time the number is coming or not push 2 items firdst then check if works empty and print else add one more element and then check and print till cr doesnt becomes EOF
        fclose(deptr);
        fclose(dewptr);
    }
    return 0;
}
// two pointer would be constructed and then the coding pasrt is needed to be done
