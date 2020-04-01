# LeetCode/cpp

Here are all passed codes for LeetCode written in rust.

## Status: 2/1397

Finished List:

	[1-2]

## Coding

Rust don't have the (messy) macro and macro guard as C/C++ do. 
However, it provides nice _feature_ that allows you to chose what code get to compile and what code don't.
Guard a piece of code with `#[cfg(feature = "local_testing")]` and it will not be compiled anywhere but locally.

## Testing

Rust have a nice test integration in the language. 
To register a test:
```rust
#[cfg(test)]
mod test {
	#[test]
	fn test_func() {
		// Test code
	}
}
```

and run:

```sh
cargo test
```

The test will ship itself automatically when compilation is done.