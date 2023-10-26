#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, arr.begin());

    std::vector<int> cur_longest_subsequence = {arr[0]};
    std::vector<int> longest_subs_in_position(n, 1);

    for (int i = 1; i < arr.size(); ++i) {
        if (cur_longest_subsequence.back() < arr[i]) {
            cur_longest_subsequence.emplace_back(arr[i]);
            longest_subs_in_position[i] = cur_longest_subsequence.size();
        } else {
            auto it = std::lower_bound(cur_longest_subsequence.begin(),
                                       cur_longest_subsequence.end(), arr[i]);
            *it = arr[i];
            longest_subs_in_position[i] = std::distance(cur_longest_subsequence.begin(), it) + 1;
        }
    }

    int length_of_lis = (int)cur_longest_subsequence.size();

    // Print longest subsequence
    std::cout << length_of_lis << "\n";
    std::vector<int> longest_subsequence;

    for (int i = (int)arr.size() - 1; i >= 0; --i) {
        if (longest_subs_in_position[i] == length_of_lis) {
            longest_subsequence.push_back(arr[i]);
            length_of_lis--;
        }
    }

    std::reverse(longest_subsequence.begin(), longest_subsequence.end());

    for (const auto& elem : longest_subsequence) {
        std::cout << elem << " ";
    }

    std::cout << std::endl;

    return 0;
}
