#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int>& nums)
{
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (nums[j] > nums[j+1])
            {
                swap(nums[j], nums[j+1]);
            }
        }
    }
}

// 不稳定排序 (7) 1 [7]下一次会变成1 (7) [7]
void select_sort(vector<int>& nums)
{
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        int min = nums[i];
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (min > nums[j])
            {
                min = nums[j];
                minIndex = j;
            }
        }

        swap(nums[i], nums[minIndex]);
    }
}

void insert_sort(vector<int>& nums)
{
    int size = nums.size();

    for (int i = 1; i < size; i++)
    {
        int j = i-1;
        int key = nums[i];
        for (; j >= 0; j--)
        {
            if (nums[j] > key)
            {
                nums[j+1] = nums[j];
            }
            else
            {
                break;
            }
        }
        nums[j+1] = key;
    }
}

void helper(vector<int>& nums, int left, int right)
{

    if (left >= right)
    {
        return;
    }

    int key = nums[left];
    int start = left;
    int end = right;
    while(left < right)
    {
        while (left < right && nums[right] > key)
        {
            right --;
        }

        if (left < right)
        {
            swap(nums[left], nums[right]);  // 5123467-> 4123567 交换以后left的值肯定是小于key的，无需比较，所以left++
            left ++;
        }

        while (left < right && nums[left] < key)
        {
            left++;
        }

        if (left < right)
        {
            swap(nums[left], nums[right]);
            right --;
        }
    }

    helper(nums, start, left-1);
    helper(nums, left + 1, end);

    // if (left >= right)
    // {
    //     return;
    // }

    // int mid = (right - left) / 2 + left;
    // int key = nums[mid];
    
    // int start = left;
    // int end = right;
    // while(start < end)
    // {   
    //     while(start <= end && key < nums[end])
    //     {
    //         end --;
    //     }

    //     while (start < end && key > nums[start])
    //     {
    //         start++;
    //     }

    //     if (start < end)
    //     {
    //         swap(nums[start], nums[end]);
    //         start++;
    //         end--;
    //     }
    // }

    // helper(nums, left, end);
    // helper(nums, start, right);


}

void quick_sort(vector<int>& nums)
{
    helper(nums, 0, nums.size() - 1);
}

void merge(vector<int>& nums, int start, int mid, int end, vector<int> &tmp)
{
    int left = start;
    int right = mid + 1;
    int index = left;

    while (left <= mid && right <= end)
    {
        if (nums[left] < nums[right])
        {
            tmp[index++] = nums[left++];
        }
        else
        {
            tmp[index++] = nums[right++];
        }
    }

    while (left <= mid)
    {
        tmp[index++] = nums[left++];
    }

    while (right <= end)
    {
        tmp[index++] = nums[right++];
    }


    for (int i = start; i <= end; i++)
    {
        nums[i] = tmp[i];
    }
}

void mergeHelper(vector<int>& nums, int left, int right, vector<int> &tmp)
{
    if (left >= right)
    {
        return;
    }

    int mid = (right - left) / 2 + left;
    
    mergeHelper(nums, left, mid, tmp);
    mergeHelper(nums, mid + 1, right, tmp);

    merge(nums, left, mid, right, tmp);
}

void merge_sort(vector<int>& nums)
{
    vector<int> tmp(nums.size(), 0);
    mergeHelper(nums, 0, nums.size()-1, tmp);
}

// 最大堆的性质就是根的值大于左右两边的值，递归定义
// 这个方法页叫做下沉
void adjustMaxHeap(vector<int>& nums, int start, int end)
{
    int fa = start;
    int son = fa * 2 + 1;

    while (son <= end)
    {
        if (son + 1 <= end && nums[son] < nums[son + 1])
        {
            son = son + 1;
        }

        if (nums[fa] > nums[son])
        {
            return;
        }
        else
        {
            swap(nums[fa], nums[son]);
            fa = son;
            son = son * 2 + 1;
        }
    }
}

void heap_sort(vector<int>& nums)
{
    int size = nums.size();
    // 从最后一个父节点开始调整堆
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        adjustMaxHeap(nums, i, size - 1);
    }

    for (int i = size - 1; i > 0 ; i--)
    {
        swap(nums[0], nums[i]);
        adjustMaxHeap(nums, 0, i-1);
    }
}

int main()
{
    vector<int> nums {3, 1, 6, 5, 7, 0, 2, 4, 9};

    heap_sort(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout  << endl;
}