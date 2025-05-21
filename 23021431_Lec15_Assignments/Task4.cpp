#include <bits/stdc++.h>
using namespace std;

void permute(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == nums.size()) {
        result.push_back(nums); // Thêm hoán vị vào kết quả
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]); // Hoán đổi
        permute(nums, start + 1, result); // Gọi đệ quy
        swap(nums[start], nums[i]); // Hoàn lại
    }
}

int main() {
    int n;
    cin >> n; // Nhập n
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1; // Tạo mảng 1, 2, ..., n
    }

    vector<vector<int>> result;
    permute(nums, 0, result); // Sinh hoán vị

    for (const auto& perm : result) {
        for (int x : perm) {
            cout << x; // In mỗi hoán vị
        }
        cout << endl;
    }

    return 0;
}
