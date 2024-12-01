use std::fs;
use std::path::PathBuf;

fn main() {
    let path = PathBuf::from("./src/solve.txt");

    match fs::canonicalize(&path){
        Ok(abs_path) => println!("Absolute path: {:?}", abs_path),
        Err(e) => {
            eprintln!("Error getting path: {:?}", e);
            return;
        }
    }

    let contents = fs::read_to_string(&path).expect("didn't work");

    let mut left_side = Vec::new();

    let mut right_side = Vec::new();

    for line in contents.lines(){
        if let Some((left, right)) = line.split_once(' '){
            left_side.push(left.trim().parse::<i32>().unwrap_or_default());
            right_side.push(right.trim().parse::<i32>().unwrap_or_default());
        }
    }

    left_side.sort();
    right_side.sort();

    let total_diff : i64 = left_side.iter().zip(right_side.iter()).map(|(left,right)| (left-right).abs() as i64).sum();

    println!("Left : {:#?}", left_side);
    println!("Right : {:#?}", right_side);
    println!("total_diff = {}", total_diff);
}

