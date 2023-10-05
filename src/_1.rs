pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
    let l = nums1.len();
    let actual_nums1 = nums1.iter().take(m as usize).collect::<Vec<_>>();
    let mut new = vec![0; l];

    let mut left = 0usize;
    let mut right = 0usize;
    for i in 0..l {
        new[i] = if *actual_nums1.get(left).unwrap_or(&&i32::MAX) < 
        nums2.get(right).unwrap_or(&i32::MAX) {
            left += 1;
            *actual_nums1[left - 1]
        } else {
            right += 1;
            nums2[right - 1]
        };
    }

    nums1.swap_with_slice(&mut new);
}
