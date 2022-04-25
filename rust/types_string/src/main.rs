fn main() {
    println!("Hello, world!");
    let location = format!("{} {:02}’{:02}”N", 24, 5, 23);
    println!("{}", location); // OK
    //println!(location); // NG: format argument must be a string literal.
    //println!("{}", *location); // NG: the size for values of type 'str' cannot be known at compile time.
    println!("{}", &location); // NG

    let s = "abcdefg".to_string();
    let string_slice: &str = &s[..]; // Take a full slice of the String.
    println!("string_slice: {}", string_slice); // OK
    let string_slice1: &str = &*s; // OK:
    // s: String
    // *s: str (via Deref<Target=str>)
    // &*s: &str
    println!("string_slice1: {}", string_slice1);
    println!("ref to deref of s: {}", &*s);
}
