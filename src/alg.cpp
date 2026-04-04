// Copyright 2021 NNTU-CS
#include "alg.h"
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int leftCount = 1;
                int rightCount = 1;
                while (left + 1 < right && arr[left + 1] == arr[left]) {
                    leftCount++;
                    left++;
                }
                while (right - 1 > left && arr[right - 1] == arr[right]) {
                    rightCount++;
                    right--;
                }
                count += leftCount * rightCount;
                left++;
                right--;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}
int binarySearch(int *arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int i = 0;
    while (i < len) {
        int currentVal = arr[i];
        int currentCount = 1;
        while (i + 1 < len && arr[i + 1] == currentVal) {
            currentCount++;
            i++;
        }
        int target = value - currentVal;
        if (target > currentVal) {
            int pos = binarySearch(arr, i + 1, len - 1, target);
            if (pos != -1) {
                int targetCount = 1;
                int j = pos;
                while (j + 1 < len && arr[j + 1] == target) {
                    targetCount++;
                    j++;
                }
                count += currentCount * targetCount;
            }
        } else if (target == currentVal) {
            count += currentCount * (currentCount - 1) / 2;
            break;
        }
        i++;
    }
    return count;
}
