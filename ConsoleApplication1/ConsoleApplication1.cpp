#include <stdio.h>
#include <iostream>

#pragma region Methods
void printArray(int* arr, int size, int type)
{
    if (type == 0)
    {
        printf("Decreasing array: ");
        for (int i = size - 1; i >= 0; i--)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        printf("\n");
    }
    else if (type == 1)
    {
        printf("Increasing array: ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        printf("\n");
    }
    else if (type == 2)
    {
        printf("Random array: ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        printf("\n");
    }
}
void printQuickSortArray(int* arr, int size)
{
    printf("Array with quick sort: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int* createDecreasingArray(int size) //создание убывающего массива
{
    int* arr = new int[size];
    for (int i = size - 1; i >= 0; i--)
    {
        arr[i] = i;
    }
    return arr;
}
int* createIncreasingArray(int size) //создание возрастающего массива
{
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }
    return arr;
}
int* createRandomArray(int size) //создание массива случайных чисел
{
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        int r = rand() % size; //диапазон случайных между 0 и максимальным размером массива, при желании можно поменять на большее число
        arr[i] = r;
    }
    return arr;
}
void checkseries(int* arr, int size) //проверка числа серий в отсортированном массиве, она должна быть 1
{
    int series = 1;
    for (int i = 0; i < size-1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            series += 1;
        }
    }
    if (series == 1)
    {
        printf("The number of series in the array: 1. The array is sorted");
        printf("\n");
        printf("\n");
    }
    else
    {
        printf("The number of series in the array: %d. The array is not sorted", series);
        printf("\n");
        printf("\n");
    }
}
void checksums(int* arr1, int* arr2, int size) //проверка контрольной суммы первоначального и отсортированного массива
{
    int c = 0;
    for (int i = 0; i < size; i++)
    {
        c += arr1[i];
    }
    int d = 0;
    for (int i = 0; i < size; i++)
    {
        d += arr2[i];
    }
    if (c == d)
    {
        printf("Checksums are equal");
        printf("\n");
    }
    else
    {
        printf("Checksums are not equal");
        printf("\n");
    }
}
int* selectionSort(int* arr, int size) //сортировка прямым выбором
{
    int min, temp, m, c;
    m = 0;
    c = 0;
    for (int i = 0; i < size - 1; i++)
    {
        min = i; // запоминаем индекс текущего элемента
        for (int j = i + 1; j < size; j++) // ищем минимальный элемент чтобы поместить на место i-ого
        {
            if (arr[j] < arr[min]) min = j; // если элемент меньше минимального, запоминаем его индекс в min
            c++;
        }
        temp = arr[i]; // меняем местами i-ый и минимальный элементы
        arr[i] = arr[min];
        arr[min] = temp;
        m+=3;

    }
    printf("Array with selection sort: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n M = %d ", m);
    printf("C = %d ", c);
    printf("M + C = %d ", m + c);
    printf("\n");
    return arr;
}
int* shellSort(int* arr, int size) //сортировка Шелла
{
    int increment, temp, m, c;
    m = 0;
    c = 0;
    // шаг задаем с эмпирической последовательностью Марцина Циура (1, 4, 10, 23, 57, 132, 301, 701, 1750), является одним из лучших для сортировки массива до ~4000 элементов
    increment = 301;
    if (size < 301) increment = 132;
    if (size < 132) increment = 57;
    while (increment > 0)  // пока существует приращение
    {
        for (int i = 0; i < size; i++)  // для всех элементов массива
        {
            int j = i;          // сохраняем индекс и элемент
            temp = arr[i];
            m++;
            // просматриваем остальные элементы массива, отстоящие от j-ого на величину приращения
            while ((j >= increment) && (arr[j - increment] > temp))  // пока отстоящий элемент больше текущего
            {
                c++;
                arr[j] = arr[j - increment]; // перемещаем его на текущую позицию
                m++;
                j = j - increment;       // переходим к следующему отстоящему элементу
            }
            arr[j] = temp; // на выявленное место помещаем сохранённый элемент
            m++;
        }
        if (increment == 301) increment = 132;
        else if (increment == 132) increment = 57;
        else if (increment == 57) increment = 23;
        else if (increment == 23) increment = 10;
        else if (increment == 10) increment = 4;
        else if (increment == 4) increment = 1;
        else if (increment == 1) break;  //последний проход завершен, выходим из цикла
    }
    printf("Array with Shell sort: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n M = %d ", m);
    printf("C = %d ", c);
    printf("M + C = %d ", m + c);
    printf("\n");
    return arr;
}
int* quickSort(int* arr, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = arr[(left + right) / 2];
        do
        {
            while (arr[left] < middle) left++;
            while (arr[right] > middle) right--;
            if (left <= right)
            {
                int tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        quickSort(arr, first, right);
        quickSort(arr, left, last);
    }
    return arr;
}
int quickSortCount(int* arr, int first, int last, int &mc)
{
    if (first < last)
    {
        mc++;
        int left = first, right = last, middle = arr[(left + right) / 2];
        mc += 3;
        do
        {
            while (arr[left] < middle) left++; mc+=2;
            while (arr[right] > middle) right--; mc+=2;
            if (left <= right)
            {
                mc++;
                int tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;
                mc += 5;
            }
        } while (left <= right);
        quickSortCount(arr, first, right, mc);
        quickSortCount(arr, left, last, mc);
        mc++;
    }
    return mc;
}
#pragma endregion


int main()
{
    int mc;
#pragma region 100
    int* decArr_100 = createDecreasingArray(100);
    printArray(decArr_100, 100, 0);
    int* decArr_100_sorted = selectionSort(decArr_100, 100);
    checksums(decArr_100, decArr_100_sorted, 100);
    checkseries(decArr_100_sorted, 100);
    delete[] decArr_100_sorted;

    decArr_100 = createDecreasingArray(100);
    int* decArr_100_sorted_2 = shellSort(decArr_100, 100);
    checksums(decArr_100, decArr_100_sorted_2, 100);
    checkseries(decArr_100_sorted_2, 100);
    delete[] decArr_100_sorted_2;

    decArr_100 = createDecreasingArray(100);
    int* decArr_100_sorted_3 = quickSort(decArr_100, 0, 99);
    printQuickSortArray(decArr_100_sorted_3, 100);
    
    decArr_100 = createDecreasingArray(100);
    mc = 0;
    int count_100 = quickSortCount(decArr_100, 0, 99, mc);
    printf("M + C = %d ", count_100);
    printf("\n");
    checksums(decArr_100, decArr_100_sorted_3, 100);
    checkseries(decArr_100_sorted_3, 100);
    delete[] decArr_100_sorted_3;
    delete[] decArr_100;



    int* incArr_100 = createIncreasingArray(100);
    printArray(incArr_100, 100, 1);
    int* incArr_100_sorted = selectionSort(incArr_100, 100);
    checksums(incArr_100, incArr_100_sorted, 100);
    checkseries(incArr_100_sorted, 100);
    delete[] incArr_100_sorted;

    incArr_100 = createIncreasingArray(100);
    int* incArr_100_sorted_2 = shellSort(incArr_100, 100);
    checksums(incArr_100, incArr_100_sorted_2, 100);
    checkseries(incArr_100_sorted_2, 100);
    delete[] incArr_100_sorted_2;

    incArr_100 = createIncreasingArray(100);
    int* incArr_100_sorted_3 = quickSort(incArr_100, 0, 99);
    printQuickSortArray(incArr_100_sorted_3, 100);

    incArr_100 = createIncreasingArray(100);
    mc = 0;
    count_100 = quickSortCount(incArr_100, 0, 99, mc);
    printf("M + C = %d ", mc);
    printf("\n");
    checksums(incArr_100, incArr_100_sorted_3, 100);
    checkseries(incArr_100_sorted_3, 100);
    delete[] incArr_100_sorted_3;
    delete[] incArr_100;

    
    
    int* rndArr_100  = createRandomArray(100);
    printArray(rndArr_100, 100, 2);
    int* rndArr_100_sorted = selectionSort(rndArr_100, 100);
    checksums(rndArr_100, rndArr_100_sorted, 100);
    checkseries(rndArr_100_sorted, 100);
    delete[] rndArr_100_sorted;

    rndArr_100 = createRandomArray(100);
    int* rndArr_100_sorted_2 = shellSort(rndArr_100, 100);
    checksums(rndArr_100, rndArr_100_sorted_2, 100);
    checkseries(rndArr_100_sorted_2, 100);
    delete[] rndArr_100_sorted_2;

    rndArr_100 = createRandomArray(100);
    int* rndArr_100_sorted_3 = quickSort(rndArr_100, 0, 99);
    printQuickSortArray(rndArr_100_sorted_3, 100);
    checksums(rndArr_100, rndArr_100_sorted_3, 100);

    rndArr_100 = createRandomArray(100);
    mc = 0;
    count_100 = quickSortCount(rndArr_100, 0, 99, mc);
    printf("M + C = %d ", mc);
    printf("\n");
    checkseries(rndArr_100_sorted_3, 100);
    delete[] rndArr_100_sorted_3;
    delete[] rndArr_100;
#pragma endregion
#pragma region 200
    int* decArr_200 = createDecreasingArray(200);
    printArray(decArr_200, 200, 0);
    int* decArr_200_sorted = selectionSort(decArr_200, 200);
    checksums(decArr_200, decArr_200_sorted, 200);
    checkseries(decArr_200_sorted, 200);
    delete[] decArr_200_sorted;

    decArr_200 = createDecreasingArray(200);
    int* decArr_200_sorted_2 = shellSort(decArr_200, 200);
    checksums(decArr_200, decArr_200_sorted_2, 200);
    checkseries(decArr_200_sorted_2, 200);
    delete[] decArr_200_sorted_2;

    decArr_200 = createDecreasingArray(200);
    int* decArr_200_sorted_3 = quickSort(decArr_200, 0, 199);
    printQuickSortArray(decArr_200_sorted_3, 200);

    decArr_200 = createDecreasingArray(200);
    mc = 0;
    int count_200 = quickSortCount(decArr_200, 0, 199, mc);
    printf("M + C = %d ", count_200);
    printf("\n");
    checksums(decArr_200, decArr_200_sorted_3, 200);
    checkseries(decArr_200_sorted_3, 200);
    delete[] decArr_200_sorted_3;
    delete[] decArr_200;



    int* incArr_200 = createIncreasingArray(200);
    printArray(incArr_200, 200, 1);
    int* incArr_200_sorted = selectionSort(incArr_200, 200);
    checksums(incArr_200, incArr_200_sorted, 200);
    checkseries(incArr_200_sorted, 200);
    delete[] incArr_200_sorted;

    incArr_200 = createIncreasingArray(200);
    int* incArr_200_sorted_2 = shellSort(incArr_200, 200);
    checksums(incArr_200, incArr_200_sorted_2, 200);
    checkseries(incArr_200_sorted_2, 200);
    delete[] incArr_200_sorted_2;

    incArr_200 = createIncreasingArray(200);
    int* incArr_200_sorted_3 = quickSort(incArr_200, 0, 199);
    printQuickSortArray(incArr_200_sorted_3, 200);

    incArr_200 = createIncreasingArray(200);
    mc = 0;
    count_200 = quickSortCount(incArr_200, 0, 199, mc);
    printf("M + C = %d ", mc);
    printf("\n");
    checksums(incArr_200, incArr_200_sorted_3, 200);
    checkseries(incArr_200_sorted_3, 200);
    delete[] incArr_200_sorted_3;
    delete[] incArr_200;



    int* rndArr_200 = createRandomArray(200);
    printArray(rndArr_200, 200, 2);
    int* rndArr_200_sorted = selectionSort(rndArr_200, 200);
    checksums(rndArr_200, rndArr_200_sorted, 200);
    checkseries(rndArr_200_sorted, 200);
    delete[] rndArr_200_sorted;

    rndArr_200 = createRandomArray(200);
    int* rndArr_200_sorted_2 = shellSort(rndArr_200, 200);
    checksums(rndArr_200, rndArr_200_sorted_2, 200);
    checkseries(rndArr_200_sorted_2, 200);
    delete[] rndArr_200_sorted_2;

    rndArr_200 = createRandomArray(200);
    int* rndArr_200_sorted_3 = quickSort(rndArr_200, 0, 199);
    printQuickSortArray(rndArr_200_sorted_3, 200);
    checksums(rndArr_200, rndArr_200_sorted_3, 200);

    rndArr_200 = createRandomArray(200);
    mc = 0;
    count_200 = quickSortCount(rndArr_200, 0, 199, mc);
    printf("M + C = %d ", mc);
    printf("\n");
    checkseries(rndArr_200_sorted_3, 200);
    delete[] rndArr_200_sorted_3;
    delete[] rndArr_200;
#pragma endregion
#pragma region 300
    int* decArr_300 = createDecreasingArray(300);
    printArray(decArr_300, 300, 0);
    int* decArr_300_sorted = selectionSort(decArr_300, 300);
    checksums(decArr_300, decArr_300_sorted, 300);
    checkseries(decArr_300_sorted, 300);
    delete[] decArr_300_sorted;

    decArr_300 = createDecreasingArray(300);
    int* decArr_300_sorted_2 = shellSort(decArr_300, 300);
    checksums(decArr_300, decArr_300_sorted_2, 300);
    checkseries(decArr_300_sorted_2, 300);
    delete[] decArr_300_sorted_2;

    decArr_300 = createDecreasingArray(300);
    int* decArr_300_sorted_3 = quickSort(decArr_300, 0, 299);
    printQuickSortArray(decArr_300_sorted_3, 300);

    decArr_300 = createDecreasingArray(300);
    mc = 0;
    int count_300 = quickSortCount(decArr_300, 0, 299, mc);
    printf("M + C = %d ", count_300);
    printf("\n");
    checksums(decArr_300, decArr_300_sorted_3, 300);
    checkseries(decArr_300_sorted_3, 300);
    delete[] decArr_300_sorted_3;
    delete[] decArr_300;



    int* incArr_300 = createIncreasingArray(300);
    printArray(incArr_300, 300, 1);
    int* incArr_300_sorted = selectionSort(incArr_300, 300);
    checksums(incArr_300, incArr_300_sorted, 300);
    checkseries(incArr_300_sorted, 300);
    delete[] incArr_300_sorted;

    incArr_300 = createIncreasingArray(300);
    int* incArr_300_sorted_2 = shellSort(incArr_300, 300);
    checksums(incArr_300, incArr_300_sorted_2, 300);
    checkseries(incArr_300_sorted_2, 300);
    delete[] incArr_300_sorted_2;

    incArr_300 = createIncreasingArray(300);
    int* incArr_300_sorted_3 = quickSort(incArr_300, 0, 299);
    printQuickSortArray(incArr_300_sorted_3, 300);

    incArr_300 = createIncreasingArray(300);
    mc = 0;
    count_300 = quickSortCount(incArr_300, 0, 299, mc);
    printf("M + C = %d ", mc);
    printf("\n");
    checksums(incArr_300, incArr_300_sorted_3, 300);
    checkseries(incArr_300_sorted_3, 300);
    delete[] incArr_300_sorted_3;
    delete[] incArr_300;



    int* rndArr_300 = createRandomArray(300);
    printArray(rndArr_300, 300, 2);
    int* rndArr_300_sorted = selectionSort(rndArr_300, 300);
    checksums(rndArr_300, rndArr_300_sorted, 300);
    checkseries(rndArr_300_sorted, 300);
    delete[] rndArr_300_sorted;

    rndArr_300 = createRandomArray(300);
    int* rndArr_300_sorted_2 = shellSort(rndArr_300, 300);
    checksums(rndArr_300, rndArr_300_sorted_2, 300);
    checkseries(rndArr_300_sorted_2, 300);
    delete[] rndArr_300_sorted_2;

    rndArr_300 = createRandomArray(300);
    int* rndArr_300_sorted_3 = quickSort(rndArr_300, 0, 299);
    printQuickSortArray(rndArr_300_sorted_3, 300);
    checksums(rndArr_300, rndArr_300_sorted_3, 300);

    rndArr_300 = createRandomArray(300);
    mc = 0;
    count_300 = quickSortCount(rndArr_300, 0, 299, mc);
    printf("M + C = %d ", mc);
    printf("\n");
    checkseries(rndArr_300_sorted_3, 300);
    delete[] rndArr_300_sorted_3;
    delete[] rndArr_300;
#pragma endregion
#pragma region 400
    int* decArr_400 = createDecreasingArray(400);
    printArray(decArr_400, 400, 0);
    int* decArr_400_sorted = selectionSort(decArr_400, 400);
    checksums(decArr_400, decArr_400_sorted, 400);
    checkseries(decArr_400_sorted, 400);
    delete[] decArr_400_sorted;

    decArr_400 = createDecreasingArray(400);
    int* decArr_400_sorted_2 = shellSort(decArr_400, 400);
    checksums(decArr_400, decArr_400_sorted_2, 400);
    checkseries(decArr_400_sorted_2, 400);
    delete[] decArr_400_sorted_2;

    decArr_400 = createDecreasingArray(400);
    int* decArr_400_sorted_3 = quickSort(decArr_400, 0, 399);
    printQuickSortArray(decArr_400_sorted_3, 400);

    decArr_400 = createDecreasingArray(400);
    mc = 0;
    int count_400 = quickSortCount(decArr_400, 0, 399, mc);
    printf("M + C = %d ", count_400);
    printf("\n");
    checksums(decArr_400, decArr_400_sorted_3, 400);
    checkseries(decArr_400_sorted_3, 400);
    delete[] decArr_400_sorted_3;
    delete[] decArr_400;



    int* incArr_400 = createIncreasingArray(400);
    printArray(incArr_400, 400, 1);
    int* incArr_400_sorted = selectionSort(incArr_400, 400);
    checksums(incArr_400, incArr_400_sorted, 400);
    checkseries(incArr_400_sorted, 400);
    delete[] incArr_400_sorted;

    incArr_400 = createIncreasingArray(400);
    int* incArr_400_sorted_2 = shellSort(incArr_400, 400);
    checksums(incArr_400, incArr_400_sorted_2, 400);
    checkseries(incArr_400_sorted_2, 400);
    delete[] incArr_400_sorted_2;

    incArr_400 = createIncreasingArray(400);
    int* incArr_400_sorted_3 = quickSort(incArr_400, 0, 399);
    printQuickSortArray(incArr_400_sorted_3, 400);

    incArr_400 = createIncreasingArray(400);
    mc = 0;
    count_400 = quickSortCount(incArr_400, 0, 399, mc);
    printf("M + C = %d ", mc);
    printf("\n");
    checksums(incArr_400, incArr_400_sorted_3, 400);
    checkseries(incArr_400_sorted_3, 400);
    delete[] incArr_400_sorted_3;
    delete[] incArr_400;



    int* rndArr_400 = createRandomArray(400);
    printArray(rndArr_400, 400, 2);
    int* rndArr_400_sorted = selectionSort(rndArr_400, 400);
    checksums(rndArr_400, rndArr_400_sorted, 400);
    checkseries(rndArr_400_sorted, 400);
    delete[] rndArr_400_sorted;

    rndArr_400 = createRandomArray(400);
    int* rndArr_400_sorted_2 = shellSort(rndArr_400, 400);
    checksums(rndArr_400, rndArr_400_sorted_2, 400);
    checkseries(rndArr_400_sorted_2, 400);
    delete[] rndArr_400_sorted_2;

    rndArr_400 = createRandomArray(400);
    int* rndArr_400_sorted_3 = quickSort(rndArr_400, 0, 399);
    printQuickSortArray(rndArr_400_sorted_3, 400);
    checksums(rndArr_400, rndArr_400_sorted_3, 400);

    rndArr_400 = createRandomArray(400);
    mc = 0;
    count_400 = quickSortCount(rndArr_400, 0, 399, mc);
    printf("M + C = %d ", mc);
    printf("\n");
    checkseries(rndArr_400_sorted_3, 400);
    delete[] rndArr_400_sorted_3;
    delete[] rndArr_400;
#pragma endregion
#pragma region 500
    int* decArr_500 = createDecreasingArray(500);
    printArray(decArr_500, 500, 0);
    int* decArr_500_sorted = selectionSort(decArr_500, 500);
    checksums(decArr_500, decArr_500_sorted, 500);
    checkseries(decArr_500_sorted, 500);
    delete[] decArr_500_sorted;

    decArr_500 = createDecreasingArray(500);
    int* decArr_500_sorted_2 = shellSort(decArr_500, 500);
    checksums(decArr_500, decArr_500_sorted_2, 500);
    checkseries(decArr_500_sorted_2, 500);
    delete[] decArr_500_sorted_2;

    decArr_500 = createDecreasingArray(500);
    int* decArr_500_sorted_3 = quickSort(decArr_500, 0, 499);
    printQuickSortArray(decArr_500_sorted_3, 500);

    decArr_500 = createDecreasingArray(500);
    mc = 0;
    int count_500 = quickSortCount(decArr_500, 0, 499, mc);
    printf("M + C = %d ", count_500);
    printf("\n");
    checksums(decArr_500, decArr_500_sorted_3, 500);
    checkseries(decArr_500_sorted_3, 500);
    delete[] decArr_500_sorted_3;
    delete[] decArr_500;



    int* incArr_500 = createIncreasingArray(500);
    printArray(incArr_500, 500, 1);
    int* incArr_500_sorted = selectionSort(incArr_500, 500);
    checksums(incArr_500, incArr_500_sorted, 500);
    checkseries(incArr_500_sorted, 500);
    delete[] incArr_500_sorted;

    incArr_500 = createIncreasingArray(500);
    int* incArr_500_sorted_2 = shellSort(incArr_500, 500);
    checksums(incArr_500, incArr_500_sorted_2, 500);
    checkseries(incArr_500_sorted_2, 500);
    delete[] incArr_500_sorted_2;

    incArr_500 = createIncreasingArray(500);
    int* incArr_500_sorted_3 = quickSort(incArr_500, 0, 499);
    printQuickSortArray(incArr_500_sorted_3, 500);

    incArr_500 = createIncreasingArray(500);
    mc = 0;
    count_500 = quickSortCount(incArr_500, 0, 499, mc);
    printf("M + C = %d ", mc);
    printf("\n");
    checksums(incArr_500, incArr_500_sorted_3, 500);
    checkseries(incArr_500_sorted_3, 500);
    delete[] incArr_500_sorted_3;
    delete[] incArr_500;



    int* rndArr_500 = createRandomArray(500);
    printArray(rndArr_500, 500, 2);
    int* rndArr_500_sorted = selectionSort(rndArr_500, 500);
    checksums(rndArr_500, rndArr_500_sorted, 500);
    checkseries(rndArr_500_sorted, 500);
    delete[] rndArr_500_sorted;

    rndArr_500 = createRandomArray(500);
    int* rndArr_500_sorted_2 = shellSort(rndArr_500, 500);
    checksums(rndArr_500, rndArr_500_sorted_2, 500);
    checkseries(rndArr_500_sorted_2, 500);
    delete[] rndArr_500_sorted_2;

    rndArr_500 = createRandomArray(500);
    int* rndArr_500_sorted_3 = quickSort(rndArr_500, 0, 499);
    printQuickSortArray(rndArr_500_sorted_3, 500);
    checksums(rndArr_500, rndArr_500_sorted_3, 500);

    rndArr_500 = createRandomArray(500);
    mc = 0;
    count_500 = quickSortCount(rndArr_500, 0, 499, mc);
    printf("M + C = %d ", mc);
    printf("\n");
    checkseries(rndArr_500_sorted_3, 500);
    delete[] rndArr_500_sorted_3;
    delete[] rndArr_500;
#pragma endregion
}