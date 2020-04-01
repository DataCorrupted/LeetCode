#[cfg(feature = "local_testing")]
struct Solution;

impl Solution {
    #[allow(dead_code)]
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        for i in 0..nums.len() {
        for j in i+1..nums.len() {
            if nums[j] == target - nums[i] {
                return vec![i as i32, j as i32];
            }
        }
        }
        Vec::new()
    }
}

#[cfg(test)]
mod test {
    use super::Solution;

    #[test]
    fn test_two_sum_1() {
        let target = 9;
        let nums = vec![2, 7, 11, 15];
        let ground_truth = vec![0, 1];
        assert_eq!(Solution::two_sum(nums, target), ground_truth);
    }
}