#[cfg(feature = "local_testing")]
struct Solution;

impl Solution {
    fn dfs(
        curr: usize,
        curr_subset: &mut Vec<i32>,
        power_set: &mut Vec<Vec<i32>>,
        num_pairs: &Vec<(i32, i32)>,
    ) {
        if curr == num_pairs.len() {
            power_set.push(curr_subset.clone());
            return;
        }
        let (num, occ) = num_pairs[curr];
        for _ in 0..occ + 1 {
            Solution::dfs(curr + 1, curr_subset, power_set, num_pairs);
            curr_subset.push(num);
        }
        for _ in 0..occ + 1 {
            let _ = curr_subset.pop();
        }
    }
    #[allow(dead_code)]
    pub fn subsets_with_dup(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut num_pairs: Vec<(i32, i32)> = vec![];
        nums.sort();
        nums.iter().for_each(|&num| {
            let last_num = num_pairs.last().unwrap_or(&(-1, -1)).0;

            if last_num != num || num_pairs.last().is_none() {
                num_pairs.push((num, 1));
            } else {
                let p = num_pairs.last_mut().unwrap();
                *p = (p.0, p.1 + 1);
            }
        });
        let mut power_set = vec![];
        Solution::dfs(0, &mut vec![], &mut power_set, &num_pairs);
        power_set
    }
}

#[cfg(test)]
mod test {
    use super::Solution;

    #[test]
    fn test_subset_ii_sample() {
        let nums = vec![1, 2, 2];
        let ground_truth = vec![
            vec![],
            vec![2],
            vec![2, 2],
            vec![1],
            vec![1, 2],
            vec![1, 2, 2],
        ];
        assert_eq!(Solution::subsets_with_dup(nums), ground_truth);
    }

    #[test]
    fn test_subset_ii_empty() {
        let nums = vec![];
        let ground_truth = vec![vec![]];
        assert_eq!(Solution::subsets_with_dup(nums), ground_truth);
    }
    #[test]
    fn test_subset_ii_non_order() {
        let nums = vec![4, 1, 4, 4, 4];
        let ground_truth = vec![
            vec![],
            vec![4],
            vec![4, 4],
            vec![4, 4, 4],
            vec![4, 4, 4, 4],
            vec![1],
            vec![1, 4],
            vec![1, 4, 4],
            vec![1, 4, 4, 4],
            vec![1, 4, 4, 4, 4],
        ];
        assert_eq!(Solution::subsets_with_dup(nums), ground_truth);
    }
}
