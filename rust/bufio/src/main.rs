use std::env;
use std::error::Error;
use std::fs::File;
use std::io::{self, BufReader};
use std::io::prelude::*;

fn stdin_grep(target: &str) -> io::Result<()> {
    let stdin = io::stdin();
    for line_result in stdin.lock().lines() {
        let line = line_result?;
        if line.contains(target) {
            println!("{}", line);
        }
    }
    Ok(())
}

fn grep<R>(target: &str, reader: R) -> io::Result<()>
    where R: BufRead
{
    for line_result in reader.lines() {
        let line = line_result?;
        if line.contains(target) {
            println!("{}", line);
        }
    }
    Ok(())
}

fn main() -> Result<(), Box<dyn Error>> {
    let args: Vec<String> = env::args().collect();
    if args.len() == 2 {
        let pattern = &args[1];
        println!("grepping {} from STDIN:", pattern);
        stdin_grep(pattern)?;
        return Ok(());
    } else if args.len() != 3 {
        eprintln!("Usage: {} PATTERN FILE", args[0]);
        std::process::exit(1);
    }

    let pattern = &args[1];
    let file = &args[2];
    let f = File::open(file)?;
    grep(&pattern, BufReader::new(f))?;
    Ok(())
}
