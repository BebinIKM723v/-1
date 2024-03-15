#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Сума елементiв у масиві
int sum(const vector<int>& arr) {
    int total = 0;
    for (int num : arr) {
        total += num;
    }
    return total;
}

// Мін і макс елементи у масиві
pair<int, int> minMax(const vector<int>& arr) {
    int min_val = *min_element(arr.begin(), arr.end());
    int max_val = *max_element(arr.begin(), arr.end());
    return make_pair(min_val, max_val);
}

// Середнє значення ел у масиві
double average(const vector<int>& arr) {
    int total = sum(arr);
    return static_cast<double>(total) / arr.size();
}

// Перевірка, чи міститься певний елемент у масиві
bool contains(const vector<int>& arr, int target) {
    return find(arr.begin(), arr.end(), target) != arr.end();
}

// Сортування елементів у масиві
void sortArray(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

// Підрахунок кількості парних та непарних чисел у масиві
pair<int, int> countEvenOdd(const vector<int>& arr) {
    int even_count = 0;
    int odd_count = 0;
    for (int num : arr) {
        if (num % 2 == 0)
            even_count++;
        else
            odd_count++;
    }
    return make_pair(even_count, odd_count);
}

// Пошук всіх повторюваних елементів у масиві
vector<int> findDuplicates(const vector<int>& arr) {
    unordered_map<int, int> freq;
    vector<int> duplicates;
    for (int num : arr) {
        freq[num]++;
        if (freq[num] == 2)
            duplicates.push_back(num);
    }
    return duplicates;
}

// Пошук всіх пар елементів у масиві, сума яких дорівнює заданому числ
vector<pair<int, int>> findPairsWithSum(const vector<int>& arr, int targetSum) {
    unordered_map<int, int> seen;
    vector<pair<int, int>> pairs;
    for (int num : arr) {
        int complement = targetSum - num;
        if (seen.find(complement) != seen.end()) {
            pairs.push_back(make_pair(complement, num));
        }
        seen[num]++;
    }
    return pairs;
}

int main() {
    vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };

    // Приклади використання функці
    cout << "Сума всіх елементів: " << sum(arr) << endl;

    auto minmax = minMax(arr);
    cout << "Мінімальний елемент: " << minmax.first << endl;
    cout << "Максимальний елемент: " << minmax.second << endl;

    cout << "Середнє значення елементів: " << average(arr) << endl;

    int target = 6;
    cout << "Елемент " << target << (contains(arr, target) ? " міститься " : " не міститься ") << "у масиві." << endl;

    sortArray(arr);
    cout << "Сортований масив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    auto evenOdd = countEvenOdd(arr);
    cout << "Кількість парних чисел: " << evenOdd.first << endl;
    cout << "Кількість непарних чисел: " << evenOdd.second << endl;

    vector<int> duplicates = findDuplicates(arr);
    cout << "Повторювані елементи: ";
    for (int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;

    int targetSum = 7;
    vector<pair<int, int>> pairs = findPairsWithSum(arr, targetSum);
    cout << "Пари елементів з сумою " << targetSum << ": ";
    for (auto pair : pairs) {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    cout << endl;

    return 0;
}