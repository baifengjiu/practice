//
// Created by xue on 2023/11/15.
//
/***********************
* 有一个连续的int数组，数组中的数据升序排序
* 数组中的数据不唯一，有重复
* 要求在数组中查找指定为target的数据
* 返回target最小的下标。没有找到，返回-1
* 要求：
* 时间复杂度：Olog（n），空间复杂度O（n）
************************/
#include <iostream>

int binarySearch(int arr[], int beginIndex, int endIndex, int target) {
    if (beginIndex < 0 || endIndex < 0 || beginIndex > endIndex) {
        return -1;
    }

    int midIndex = (beginIndex + endIndex) / 2;
    int mid = arr[midIndex];

    if (mid == target) {
        for (int i = midIndex; i > 0; i--) {
            if (arr[i] != mid) return i + 1;
        }
        return midIndex;
    } else if (mid > target) {
        return binarySearch(arr, beginIndex, midIndex - 1, target);
    } else if (mid < target){
       return binarySearch(arr, midIndex + 1, endIndex, target);
    }

    return -1;
}

void testBinarySearch() {
    int arr[] {0,1,1,3,3,5,6,9,10,10};
    int result = binarySearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 10);
    std::cout << "result:" << result <<"\n";
}