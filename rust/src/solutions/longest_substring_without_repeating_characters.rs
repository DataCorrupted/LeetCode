#[cfg(feature = "local_testing")]
struct Solution;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut max = 0;
        for start in 0..s.len() {
            let mut byte_used  = [0; 256];
            for j in 0..s.len() - start {
                let idx = s[i+j] as usize;
                if byte_used[idx] {
                    break
                } else {
                    byte_used[idx] = true;
                }
            }
            max = if (j > max) { j } else { max };
            if s.len() - start < max {
                break;
            }
        }
        max
    }
}

#[cfg(test)]
mod test {
    use super::*;

    fn test_length_of_longest_substring_0() {
        let s = String::from("abcabcbb");
        let ground_truth = 3;
        assert_eq!(Solution::length_of_longest_substring(s), ground_truth);
    }
    fn test_length_of_longest_substring_1() {
        let s = String::from("bbbbb");
        let ground_truth = 1;
        assert_eq!(Solution::length_of_longest_substring(s), ground_truth);
    }
    fn test_length_of_longest_substring_2() {
        let s = String::from("pwwkew");
        let ground_truth = 3;
        assert_eq!(Solution::length_of_longest_substring(s), ground_truth);
    }
}