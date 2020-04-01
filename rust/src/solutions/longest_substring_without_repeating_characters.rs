#[cfg(feature = "local_testing")]
struct Solution;

#[allow(dead_code)]
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut max = 0;
        let s_bytes = s.as_bytes();
        for start in 0..s.len() {
            let mut byte_used = [false; 256];
            let mut end = s.len();
            for j in start..s.len() {
                let idx = s_bytes[j] as usize;
                if byte_used[idx] {
                    end = j;
                    break;
                } else {
                    byte_used[idx] = true;
                }
            }
            max = if end - start > max { end - start } else { max };
            if s.len() - start < max {
                break;
            }
        }
        max as i32
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn test_length_of_longest_substring_0() {
        let s = String::from("abcabcbb");
        let ground_truth = 3;
        assert_eq!(Solution::length_of_longest_substring(s), ground_truth);
    }
    #[test]
    fn test_length_of_longest_substring_1() {
        let s = String::from("bbbbb");
        let ground_truth = 1;
        assert_eq!(Solution::length_of_longest_substring(s), ground_truth);
    }
    #[test]
    fn test_length_of_longest_substring_2() {
        let s = String::from("pwwkew");
        let ground_truth = 3;
        assert_eq!(Solution::length_of_longest_substring(s), ground_truth);
    }
}
