#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int sumOfDigits(const vector<int>& arr) 
{
    int total = 0;
    for (int num : arr) 
    {
        while (num) 
        {
            total += abs(num % 10);
            num /= 10;
        }
    }
    return total;
}

double averagePositive(const vector<int>& arr) 
{
    int sum = 0, count = 0;
    for (int num : arr) 
    {
        if (num > 0) 
        {
            sum += num;
            count++;
        }
    }
    return (count == 0) ? 0 : (double)sum / count;
}


pair<int, int> maxNegativeElement(const vector<int>& arr) 
{
    int maxNeg = INT_MIN, position = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0 && arr[i] > maxNeg) 
        {
            maxNeg = arr[i];
            position = i;
        }
    }
    return {maxNeg, position};
}

int mostFrequent(const vector<int>& arr) 
{
    unordered_map<int, int> freq;
    for (int num : arr) freq[num]++;
    int maxFreq = 0, mostFreqNum = arr[0];
    for (const auto& [num, count] : freq)
    {
        if (count > maxFreq) 
        {
            maxFreq = count;
            mostFreqNum = num;
        }
    }
    return mostFreqNum;
}

int maxOddIndexDivBy3(const vector<int>& arr) 
{
    int maxVal = INT_MIN;
    for (int i = 1; i < arr.size(); i += 2) 
    {
        if (arr[i] % 3 == 0 && arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}


void swapMaxEvenMinOdd(vector<int>& arr) 
{
    int maxEven = INT_MIN, minOdd = INT_MAX;
    int maxEvenIdx = -1, minOddIdx = -1;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0 && arr[i] > maxEven) 
        {
            maxEven = arr[i];
            maxEvenIdx = i;
        }
        if (arr[i] % 2 != 0 && arr[i] < minOdd) 
        {
            minOdd = arr[i];
            minOddIdx = i;
        }
    }

    if (maxEvenIdx != -1 && minOddIdx != -1) 
    {
        swap(arr[maxEvenIdx], arr[minOddIdx]);
    } else 
    {
        for (int& num : arr) num = 0;
    }
}


vector<int> commonElements(const vector<int>& arr1, const vector<int>& arr2) 
{
    unordered_map<int, int> freq;
    vector<int> result;
    for (int num : arr1) freq[num]++;
    for (int num : arr2) if (freq[num] > 0) result.push_back(num);
    return result;
}

vector<int> uniqueElements(const vector<int>& arr1, const vector<int>& arr2) 
{
    unordered_map<int, int> freq;
    vector<int> result;
    for (int num : arr1) freq[num]++;
    for (int num : arr2) freq[num]++;
    for (const auto& [num, count] : freq) {
        if (count == 1) result.push_back(num);
    }
    return result;
}

int main() {
    vector<int> arr = {12, 104, 81, -5, 3, -20, 15};
    vector<int> arr2 = {81, 15, 100, 12, -20};

    cout << "Sum of digits: " << sumOfDigits(arr) << endl;

    cout << "Average of positive elements: " << averagePositive(arr) << endl;

    auto [maxNeg, pos] = maxNegativeElement(arr);
    cout << "Max negative element: " << maxNeg << " at position " << pos << endl;

    cout << "Most frequent number: " << mostFrequent(arr) << endl;

    cout << "Max element at odd indices divisible by 3: " << maxOddIndexDivBy3(arr) << endl;

    swapMaxEvenMinOdd(arr);
    cout << "Array after swapping: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    vector<int> common = commonElements(arr, arr2);
    vector<int> unique = uniqueElements(arr, arr2);

    cout << "Common elements: ";
    for (int num : common) cout << num << " ";
    cout << endl;

    cout << "Unique elements: ";
    for (int num : unique) cout << num << " ";
    cout << endl;

    return 0;
}

