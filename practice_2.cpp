#include <iostream>
#include <ctime> 
#include <chrono>
#include <cmath>

using namespace std;
using namespace chrono;

void generateArrValue(int* arr, int len)
{
    cout << "Новые значения массива:\n";
    for (int i=0; i < len; i++)
    {
        arr[i] = rand() % 199 - 99;
        cout << arr[i] << ' ';
    }
    cout << "\n\n";
}

void quickSort(int* arr, int begin, int end)
{
    int mid, f = begin, l = end;
    mid = arr[(f+l)/2];
    while (f < l)
	{
		while (arr[f] < mid) f++;
		while (arr[l]> mid) l--;
		if (f <= l)
		{
			swap(arr[f], arr[l]);
			f++;
			l--;
		}
	}
	if (begin < l) quickSort(arr, l, begin);
	if (f < end) quickSort(arr, end, f);
}

void bubbleSort(int* arr, int len)
{
    auto start = steady_clock::now();
    for (int i=0; i < len; i++)
    {
        for (int j=0; j < len-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);
    cout << "Время сортировки пузырьком: " << result.count() << '\n';
}

int findMax(int* arr, int len, bool sort = false)
{
    int maxV = arr[0];
    auto start = steady_clock::now();
    if (sort)
    {
        maxV = arr[len-1];
    }
    else 
    {
        for (int i=1; i<len; i++)
        {
            maxV = max(maxV,arr[i]);
        }
    }
    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);
    cout << result.count() << '\n';
    return maxV;
}

int findMin(int* arr, int len, bool sort = false)
{
    int minV = arr[0];
    auto start = steady_clock::now();
    if (sort)
    {
        minV = arr[0];
    }
    else 
    {
        for (int i=1; i<len; i++)
        {
            minV = min(minV,arr[i]);
        }
    }
    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);
    cout << result.count() << '\n';
    return(minV);
}

int findNumber(int* arr, int len, int num)
{
    int leftB = 0, rightB = len-1, index;
    bool breakFlag = false;;
    auto start = steady_clock::now();
    while (arr[(rightB+leftB)/2]!=num)
    {
        if (rightB-leftB==1)
        {
            if (arr[rightB]==num)
            {
                index = rightB;
                breakFlag = true;
                break;
            }
            else 
            {
                index = -1;
                breakFlag = true;
                break;
            }
        }
        arr[(rightB+leftB)/2] < num ? leftB = (rightB+leftB)/2 : rightB = (rightB+leftB)/2;
    }
    if (!breakFlag)
    {
        index = (rightB+leftB)/2;
    }
    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end-start);
    cout << "Время бинарного поиска: " << result.count() << '\n';
    return index;
}

void swapNum(int* arr, int firstI, int secondI)
{
    int buf;
    auto start = steady_clock::now();
    buf = arr[firstI];
    arr[firstI] = arr[secondI]; 
    arr[secondI] = buf;
    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);
    cout << "Время смены индексов: " << result.count() << '\n';
}

void task4(int* arr, int len, bool sort = false)
{
    int maxV = arr[0], minV = arr[0];
    if (sort)
    {
        maxV = arr[len-1];
        minV = arr[0];
    }
    else 
    {
        for (int i=1; i<len; i++)
        {
            maxV = max(maxV,arr[i]);
            minV = min(minV,arr[i]);
        }
    }
    int middleV = round((maxV + minV)/2.0);
    
    cout << "Среднее значение: " << middleV << '\n';

    bool noMidV;
    auto start = steady_clock::now();
    if (sort)
    {   
        noMidV = false;
        int leftB = 0, rightB = len-1;
        while (arr[(leftB + rightB)/2] != middleV)
        {
            if (arr[(leftB + rightB)/2] > middleV)
                rightB = (leftB + rightB)/2;
            else
                leftB = (leftB + rightB)/2;
            if (rightB - leftB == 1)
            {
                noMidV = true;
                break;
            }
        }
        if (noMidV)  
        {
            cout << "Значений равных среднему нет\n";
        }
        else
        {
            leftB = (leftB + rightB)/2;
            rightB = leftB;
            while (arr[leftB] == middleV)
            {
                leftB--;
            }
            while (arr[rightB] == middleV)
            {
                rightB++;
            }
            for (int i = leftB+1; i<rightB; i++)
            {
                cout << i << ' ';
            }
            cout << '\n';
        }
    }
    else
    {
        noMidV = true;
        for (int i = 0; i<len; i++)
        {
            if (arr[i] == middleV)
            {
                cout << i << ' ';
                noMidV = false;
            }
        }
        if (noMidV)
            cout << "Значений равных среднему нет";
        cout << '\n';
    }
    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);
    cout << "Время нахождения индексов срзнач: " << result.count() << '\n';
}   

void task5(int* arr, int len, int a)
{
    int aIndex;
    int leftB = 0, rightB = len-1;
    while ((arr[(leftB + rightB)/2] != a) && (rightB - leftB != 1))
    {
        if (arr[(leftB + rightB)/2] < a)
        {
            leftB = (leftB + rightB)/2;
        }
        else
        {
            rightB = (leftB + rightB)/2;
        }
    }
    if (arr[(leftB + rightB)/2] == a)
    {
        aIndex = (leftB + rightB)/2;
    }
    else if (arr[leftB] == a)
    {
        aIndex = leftB;
    }
    else
    {
        aIndex = rightB;
    }

    cout << "Колличество элементов меньше " << a << ": " << aIndex << '\n';
}

void task6(int* arr, int len, int b)
{
    int bIndex;
    int leftB = 0, rightB = len-1;
    while ((arr[(leftB + rightB)/2] != b) && (rightB - leftB != 1))
    {
        if (arr[(leftB + rightB)/2] < b)
        {
            leftB = (leftB + rightB)/2;
        }
        else
        {
            rightB = (leftB + rightB)/2;
        }
    }
    if (arr[(leftB + rightB)/2] == b)
    {
        bIndex = (leftB + rightB)/2;
    }
    else if (arr[rightB] == b)
    {
        bIndex = rightB;
    }
    else
    {
        bIndex = leftB;
    }

    cout << "Колличество элементов больше " << b << ": " << (len - 1) - bIndex << '\n';
}

int main()
{
    setlocale(0,"RUS");
    srand(time(0));

    const int LEN = 100;
    int arr[LEN], sortArr[LEN];

    generateArrValue(arr, LEN);
    for (int i=0; i<LEN; i++)
    {
        sortArr[i] = arr[i];
    }
    bubbleSort(sortArr, LEN);
    cout << '\n';

    cout << "Задане №3 \n";
    cout << "Скорость нахождения максимума в не отсортированном массиве: ";
    int maxV = findMax(arr, LEN);
    cout << "Скорость нахождения максимума в отсортированном массиве: ";
    maxV = findMax(sortArr, LEN, 1);
    cout <<'\n';
    cout << "Скорость нахождения минимума в не отсортированном массиве: ";
    int minV = findMin(arr, LEN);
    cout << "Скорость нахождения минимума в отсортированном массиве: ";
    minV = findMin(sortArr, LEN, 1);
    cout << '\n';
    cout << "Максимум: " << maxV << "\n";
    cout << "Минимум: " << minV << "\n";
    cout << "\n\n";
    
    cout << "Задание №4\n";
    cout << "Отсортированный массив:\n";
    task4(sortArr, LEN, 1);
    cout << '\n';
    cout << "Не отсортированный массив:\n";
    task4(arr, LEN, 0);
    cout << "\n\n";

    cout << "Задание №5\n";
    cout << "Числа меньше какого вы хотите высести?\n";
    int a; cin >> a;
    task5(sortArr, LEN, a);

    cout << '\n';
    cout << "Задание №6\n";
    cout << "Числа больше какого вы хотите высести?\n";
    int b; cin >> b;
    task6(sortArr, LEN, b);
 
    cout << '\n';
    cout << "Задание №7\n";
    cout << "Введите число, которое хотите найти\n";
    int num; cin >> num;
    int index = findNumber(sortArr, LEN, num);

    auto start = steady_clock::now();
    for(int i=0; i<LEN; i++)
    {
        if (arr[i] == num)
        {
            break;
        }
    }
    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);
    cout << "Время поиска перебором: " << result.count() << '\n';
    if (index == -1)
    {
        cout << "Такого значения нет\n";
    }
    else
    {
        cout << "Индекс вашего значения: " << index << '\n';
    }

    cout << '\n';
    cout << "Задание №8\n";
    cout << "Исходный массив:\n";
    for (int i=0; i<LEN; i++)
    {
        cout << sortArr[i] << ' ';
    }
    cout << "\n\n";
    cout << "Введите индексы чисел, которые хотите поменять:\n";
    int firstI, secondI;
    cout << "Индекс первого числа: "; cin >> firstI;
    cout << "Индекс второго числа: "; cin >> secondI;
    cout << "\n\n";
    swapNum(sortArr, firstI, secondI);
    cout << "Изменённый массив:\n";
    for (int i=0; i<LEN; i++)
    {
        cout << sortArr[i] << ' ';
    }
    cout << "\n\n";
    return 0;
}