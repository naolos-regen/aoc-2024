use std::collections::HashMap;
use std::fs;
use std::path::PathBuf;

fn main() {
    let path = PathBuf::from("solve.txt");

    match fs::canonicalize(&path) {
        Ok(abs_path) => println!("Absolute path: {:?}", abs_path),
        Err(e) => {
            eprintln!("Error getting path: {:?}", e);
            return;
        }
    }

    let contents = fs::read_to_string(&path).expect("didn't work");

    let mut left_side = Vec::new();

    let mut right_side = Vec::new();

    for line in contents.lines() {
        if let Some((left, right)) = line.split_once(' ') {
            left_side.push(left.trim().parse::<i32>().unwrap_or_default());
            right_side.push(right.trim().parse::<i32>().unwrap_or_default());
        }
    }

    left_side.sort();
    right_side.sort();

    let total_diff: i64 = left_side
        .iter()
        .zip(right_side.iter())
        .map(|(left, right)| (left - right).abs() as i64)
        .sum();
    println!("total_diff = {}", total_diff);
    let total_sim: i32 = similarity(left_side, right_side);

    println!("total_sim = {}", total_sim);
}

fn similarity(left: Vec<i32>, right: Vec<i32>) -> i32 {
    let mut right_counts = HashMap::new();
    for &num in &right {
        *right_counts.entry(num).or_insert(0) += 1;
    }
    let mut similarity_score = 0;
    for &num in &left {
        if let Some(&count) = right_counts.get(&num) {
            similarity_score += num * count;
        }
    }
    similarity_score
}
