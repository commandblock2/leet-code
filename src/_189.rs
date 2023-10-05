pub fn rotate(nums: &mut Vec<i32>, k: i32) {
    let kei = k as usize % nums.len();

    let later = nums.iter().take(nums.len() - kei);
    let front = nums.iter().skip(nums.len() - kei);

    let mut new = front.chain(later).cloned().collect::<Vec<_>>();
    nums.swap_with_slice(& mut new);
    // a bit more of memory but very elegant I have to say
}