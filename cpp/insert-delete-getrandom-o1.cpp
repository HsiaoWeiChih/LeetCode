#include <iostream>
#include <set>
#include <optional>
#include <random>
#include <iterator>

using namespace std;

class RandomizedSet
{
private:
    set<optional<int>> mSet;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (mSet.find(val) != mSet.end())
            return false;
        else
        {
            mSet.insert(val);
            return true;
        }
    }

    bool remove(int val)
    {
        if (mSet.find(val) != mSet.end())
        {
            mSet.erase(val);
            return true;
        }
        else
            return false;
    }

    int getRandom()
    {
        // 產生隨機索引
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, mSet.size() - 1);
        int randomIndex = dis(gen);

        // 走到該位置
        auto it = mSet.begin();
        std::advance(it, randomIndex);
        if(it->has_value())
            return **it;
        else
            return NULL;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */