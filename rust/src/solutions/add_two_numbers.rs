#[cfg(feature = "local_testing")]
type ListNode = crate::utils::ListNodeT<i32>;

#[cfg(feature = "local_testing")]
struct Solution;

impl Solution {
    #[allow(dead_code)]
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut p = l1;
        let mut q = l2;
        let mut carry = 0;
        let mut ret = vec![];
        while p.is_some() || q.is_some() {
            let x = p.unwrap_or(Box::new(ListNode::new(0)));
            let y = q.unwrap_or(Box::new(ListNode::new(0)));
            let sum = carry + x.val + y.val;
            carry = sum / 10;
            ret.push(sum % 10);
            p = x.next;
            q = y.next;
        }
        if carry > 0 {
            ret.push(carry);
        }

        // Copied from crate::list_node::ListNode::from_itearable
        let mut head = None;
        (&ret).into_iter().rev().for_each(|&val| {
            let mut node = Box::new(ListNode::new(val));
            std::mem::swap(&mut node.next, &mut head);
            head = Some(node);
        });
        head
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn test_add_two_numbers_0() {
        let l1 = ListNode::from_iterable(&[2, 4, 3]);
        let l2 = ListNode::from_iterable(&[5, 6, 4]);
        let ground_truth = ListNode::from_iterable(&[7, 0, 8]);
        assert!(Solution::add_two_numbers(l1, l2) == ground_truth);
    }
    #[test]
    fn test_add_two_numbers_1() {
        let l1 = ListNode::from_iterable(&[5]);
        let l2 = ListNode::from_iterable(&[5]);
        let ground_truth = ListNode::from_iterable(&[0, 1]);
        assert!(Solution::add_two_numbers(l1, l2) == ground_truth);
    }
}
