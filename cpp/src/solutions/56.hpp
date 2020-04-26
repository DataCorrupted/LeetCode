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
 public:
  vector<Interval> merge(vector<Interval> &intervals) {
    std::sort(
        intervals.begin(), intervals.end(),
        [](Interval &lhs, Interval &rhs) { return lhs.start < rhs.start; });

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
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(empty) {
  vector<Interval> intervals;
  vector<Interval> groundTruth;
  return Solution().merge(intervals) == groundTruth;
}

REGISTER_TEST(exampe_1) {
  vector<Interval> intervals = {Interval(1, 3), Interval(2, 6), Interval(8, 10),
                                Interval(15, 18)};
  vector<Interval> groundTruth = {Interval(1, 6), Interval(8, 10),
                                  Interval(15, 18)};
  return Solution().merge(intervals) == groundTruth;
}
REGISTER_TEST(exampe_2) {
  vector<Interval> intervals = {Interval(1, 4), Interval(4, 5)};
  vector<Interval> groundTruth = {Interval(1, 5)};
  return Solution().merge(intervals) == groundTruth;
}
REGISTER_TEST(exampe_3) {
  vector<Interval> intervals = {Interval(1, 4), Interval(2, 3)};
  vector<Interval> groundTruth = {Interval(1, 4)};
  return Solution().merge(intervals) == groundTruth;
}

#endif