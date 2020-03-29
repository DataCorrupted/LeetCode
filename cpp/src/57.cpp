#ifdef DEBUG
#include "IntervalG.hpp"
typedef IntervalG<int> Interval;
#endif
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
 private:
  bool intervalLe(Interval &lhs, Interval &rhs) {
    return lhs.start < rhs.start;
  }
  // The cmpFunc guarantees that the array can be converted to the form of
  // TTT...TTFF...FFF. This function will find the idx of the last T or return
  // l-1.
  int binarySearch(vector<Interval> &intervals, Interval target, int l, int r,
                   bool (Solution::*cmpFunc)(Interval &, Interval &)) {
    // However, there can be cases where only T or only F are present.
    // Test if the first is F, if so, return not found.
    if (!(this->*cmpFunc)(intervals[l], target)) {
      return l - 1;
    }
    // Test if the last is T, if so, return the last one.
    if ((this->*cmpFunc)(intervals[r], target)) {
      return r;
    }

    int m = 0;
    while (l + 1 < r) {
      m = (l + r) / 2;
      if ((this->*cmpFunc)(intervals[m], target)) {
        l = m;
      } else {
        r = m;
      }
    }
    // arr[l] = T, arr[r] = F.
    return l;
  }

 public:
  vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> result;
    for (Interval &intv : intervals) {
      if (result.size() == 0 || result.back().end < intv.start) {
        result.push_back(intv);
      } else {
        result.back().end = max(intv.end, result.back().end);
      }
    }
    return result;
  }
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    if (intervals.size() == 0) {
      return vector<Interval>({newInterval});
    }
    int idx = binarySearch(intervals, newInterval, 0, intervals.size() - 1,
                           &Solution::intervalLe);
    intervals.insert(intervals.begin() + (idx + 1), newInterval);
    return merge(intervals);
  }
};

#ifdef DEBUG
#include "DebugUtil.h"
REGISTER_TEST(empty) {
  vector<Interval> intervals;
  Interval newInterval(2, 5);
  vector<Interval> groundTruth = {Interval(2, 5)};
  return Solution().insert(intervals, newInterval) == groundTruth;
}
REGISTER_TEST(example_1) {
  vector<Interval> intervals = {Interval(1, 3), Interval(6, 9)};
  Interval newInterval(2, 5);
  vector<Interval> groundTruth = {Interval(1, 5), Interval(6, 9)};
  return Solution().insert(intervals, newInterval) == groundTruth;
}
REGISTER_TEST(example_2) {
  vector<Interval> intervals = {Interval(1, 2), Interval(3, 5), Interval(6, 7),
                                Interval(8, 10), Interval(12, 16)};
  Interval newInterval(4, 8);
  vector<Interval> groundTruth = {Interval(1, 2), Interval(3, 10),
                                  Interval(12, 16)};
  return Solution().insert(intervals, newInterval) == groundTruth;
}
REGISTER_TEST(example_3) {
  vector<Interval> intervals = {Interval(1, 2), Interval(3, 5), Interval(6, 7),
                                Interval(8, 10), Interval(12, 16)};
  Interval newInterval(0, 8);
  vector<Interval> groundTruth = {Interval(0, 10), Interval(12, 16)};
  return Solution().insert(intervals, newInterval) == groundTruth;
}
REGISTER_TEST(example_4) {
  vector<Interval> intervals = {Interval(1, 2), Interval(3, 5), Interval(6, 7),
                                Interval(8, 10), Interval(12, 16)};
  Interval newInterval(16, 17);
  vector<Interval> groundTruth = {Interval(1, 2), Interval(3, 5),
                                  Interval(6, 7), Interval(8, 10),
                                  Interval(12, 17)};
  return Solution().insert(intervals, newInterval) == groundTruth;
}
#endif