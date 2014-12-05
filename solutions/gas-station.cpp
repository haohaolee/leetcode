/*
 * https://oj.leetcode.com/problems/gas-station/
 * */

#include <vector>
#include <gtest/gtest.h>

namespace {

class Solution {
public:
    int canCompleteCircuit(std::vector<int> const &gas,
                        std::vector<int> const &cost) {
            int gas_left = 0;
            int gas_cost_sum = 0;
            std::size_t start_index = 0;
            for (std::size_t i = 0; i < gas.size(); ++i)
            {
                gas_left += gas[i] - cost[i];
                gas_cost_sum += gas[i] - cost[i];
                if (gas_left < 0)
                {
                    gas_left = 0;
                    start_index = i + 1;
                }
            }

            return gas_cost_sum < 0 ? -1: (int)start_index;
    }
};

}

TEST(gas_station, case1)
{
    std::vector<int> gas = { 3, 2, 4, 1 };
    std::vector<int> cost = { 4, 2, 3, 1 };

    Solution s;
    EXPECT_EQ(s.canCompleteCircuit(gas, cost), 1);
}

TEST(gas_station, case2)
{
    std::vector<int> gas = {1,2,3,4};
    std::vector<int> cost = {2,2,3,4};

    Solution s;
    EXPECT_EQ(s.canCompleteCircuit(gas, cost), -1);
}

