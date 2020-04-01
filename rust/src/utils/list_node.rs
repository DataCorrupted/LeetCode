// Definition for singly-linked list.
use std::iter::DoubleEndedIterator;

type ListNodePtr<T> = Option<Box<ListNodeT<T>>>;

#[derive(PartialEq, Clone, Debug)]
pub struct ListNodeT<T: Clone + PartialEq> {
    pub val: T,
    pub next: ListNodePtr<T>,
}

impl<'a, T> ListNodeT<T>
where
    T: Clone + PartialEq,
{
    #[inline]
    pub fn new(val: T) -> Self {
        ListNodeT { next: None, val }
    }

    #[allow(dead_code)]
    #[cfg(feature = "local_testing")]
    pub fn from_iterable<I>(iter: I) -> ListNodePtr<T>
    where
        I: IntoIterator<Item = &'a T>,
        <I as IntoIterator>::IntoIter: DoubleEndedIterator,
        T: 'a,
    {
        let mut head = None;
        iter.into_iter().rev().for_each(|val| {
            let mut node = Box::new(ListNodeT::new(val.clone()));
            std::mem::swap(&mut node.next, &mut head);
            head = Some(node);
        });
        head
    }
}

#[cfg(test)]
mod test {
    // See testing in crate::solutions::add_two_numbers
}
