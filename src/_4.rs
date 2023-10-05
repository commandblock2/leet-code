pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
    // essentially a double pointer
    let mut scan_index = 0usize;
    let mut valid_size = 0usize;
    while scan_index < nums.len() {
        let prev = nums.get(scan_index - 1);
        let this = nums[scan_index];
        let next = nums.get(scan_index + 1);

        // L Leetcode L
        // and 2ms is not even median?
        // if prev.is_some_and(|i| *i == this)
        // && next.is_some_and(|i| *i == this) {

        if prev.is_some() && *prev.unwrap() == this 
        && next.is_some() && *next.unwrap() == this {
        } else {
            nums[valid_size] = nums[scan_index];
            valid_size += 1;
        }

        scan_index += 1;
    }

    valid_size as i32
}