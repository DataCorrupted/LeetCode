// Definition for singly-linked list.
use std::iter::DoubleEndedIterator;

type ListNodePtr = Option<Box<ListNode>>;

#[derive(Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: ListNodePtr,
}

impl<'a> ListNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }

    #[allow(dead_code)]
    #[cfg(feature = "local_testing")]
    pub fn from_iterable<I>(iter: I) -> ListNodePtr
    where
        I: IntoIterator<Item = &'a i32>,
        <I as IntoIterator>::IntoIter: DoubleEndedIterator,
    {
        let mut head = None;
        iter.into_iter().rev().for_each(|&val| {
            let mut node = Box::new(ListNode::new(val));
            std::mem::swap(&mut node.next, &mut head);
            head = Some(node);
        });
        head
    }
}

#[allow(dead_code)]
#[cfg(feature = "local_testing")]
pub fn eq(mut lhs: ListNodePtr, mut rhs: ListNodePtr) -> bool {
    while lhs.is_some() || rhs.is_some() {
        // Different length
        if lhs.is_none() || rhs.is_none() {
            return false;
        }
        let lhs_node = lhs.clone().unwrap();
        let rhs_node = rhs.clone().unwrap();
        if lhs_node.val != rhs_node.val {
            return false;
        }
        lhs = lhs_node.next.clone();
        rhs = rhs_node.next.clone();
    }
    true
}

#[cfg(test)]
mod test {
    // See testing in crate::solutions::add_two_numbers
}