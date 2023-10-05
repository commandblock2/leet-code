pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
    let mut temp = nums
    .iter()
    .filter(|x| **x != val)
    .cloned()
    .collect::<Vec<_>>();
    nums.truncate(temp.len());
    nums.swap_with_slice(& mut temp);
    
    temp.len() as i32
    // although the expected should be swapping the element I believe
}