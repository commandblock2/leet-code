fn str_str(haystack: String, needle: String) -> i32 {
    // build a kmp array on it

    let pattern_length = needle.len();
    let mut prefix_function = vec![0; pattern_length];

    let mut prefix_length = 0usize;

    for current_position in 1..pattern_length {
        if prefix_length > 0
            && needle.as_bytes()[current_position] != needle.as_bytes()[prefix_length]
        {
            prefix_length = prefix_function[prefix_length - 1];
        }

        if needle.as_bytes()[current_position] == needle.as_bytes()[prefix_length] {
            prefix_length += 1;
        }

        prefix_function[current_position] = prefix_length;
    }

    let mut haystack_position = 0usize;
    let mut pattern_position = 0usize;

    while haystack_position != haystack.len() {
        if haystack.as_bytes()[haystack_position] == needle.as_bytes()[pattern_position] {
            haystack_position += 1;
            pattern_position += 1;
        } else if pattern_position == 0 {
            haystack_position += 1;
        } else {
            pattern_position = prefix_function[pattern_position - 1];
        }

        if pattern_position == pattern_length {
            return haystack_position as i32 - pattern_length as i32;
        }
    }

    return -1;
}
fn main() {
    print!("{}", str_str(String::from("abcabab abababaabac"), String::from("ababaaba")));
}
