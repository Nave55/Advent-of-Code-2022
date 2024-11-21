use itertools::Itertools;

fn main() {
    let input = std::fs::read_to_string("../inputs/day1.txt").unwrap();
    let b = pt1(&input);
    let c = pt2(&input);
    println!("Part 1: {b}\nPart 2: {c}")
}

fn pt1(input: &str) -> u32 {
    input
        .split("\r\n\r\n")
        .map(|line| {
            line.lines()
                .filter_map(|s| s.parse::<u32>().ok())
                .sum::<u32>()
        })
        .max()
        .unwrap()
}

fn pt2(input: &str) -> u32 {
    input
        .split("\r\n\r\n")
        .map(|line| {
            line.lines()
                .filter_map(|s| s.parse::<u32>().ok())
                .sum::<u32>()
        })
        .sorted()
        .rev()
        .take(3)
        .sum::<u32>()
}
