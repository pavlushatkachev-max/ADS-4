// Copyright 2021 NNTU-CS
#include <iostream>

int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len / 2 + 1; i++)
    for (int j = i+1; j < len; j++)
      if (arr[i] + arr[j] == value)
        count += 1;
  return count;
}
int binSearch(int* arr, int value, int l, int r) {
  if (l > r)
    return -1;
  else if (arr[(r + l) / 2] == value)
    return (r + l) / 2;
  else if (arr[(r + l) / 2] > value)
    return binSearch(arr, value, l, (r + l) / 2 - 1);
  else
    return binSearch(arr, value, (r + l) / 2 + 1, r);
}
int countPairs2(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len / 2 + 1; i++) {
    int chislo = value - arr[i];
    int bin = binSearch(arr, chislo, i + 1, len - 1);
    if (bin != -1) {
      int l = bin;
      while (l > i && arr[i] + arr[l] == value) {
        count += 1;
        l -= 1;
      }
      int r = bin + 1;
      while (r < len && arr[i] + arr[r] == value) {
        count += 1;
        r += 1;
      }
    }
  }
  return count;
}
int countPairs3(int* arr, int len, int value) {
  int count = 0,
    i = 0,
    j = len - 1;
  while (i < j) {
    if (arr[i] + arr[j] < value) {
       i++;
    } else if (arr[i] + arr[j] > value) {
      j--;
    } else {
      int l = 1, r = 1;
      if (arr[i] == arr[j]) {
        int n = j - i + 1;
        count += n * (n - 1) / 2;
        break;
      }
      while (arr[i] == arr[i + 1]) {
        l++;
        i++;
      }
      while (arr[j] == arr[j - 1]) {
        r++;
        j--;
      }
      count += r * l;
      i++;
      j--;
    }
  }
  return count;
}
