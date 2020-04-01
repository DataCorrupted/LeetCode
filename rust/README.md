# LeetCode/cpp

Here are all passed codes for LeetCode written in rust.

## Status: 2/1397

Finished List:

	[1-2]

## Coding

Rust don't have the (messy) macro and macro guard as C/C++ do. 
However, it provides nice _feature_ that allows you to chose what code get to compile and what code don't.
Guard a piece of code with `#[cfg(feature = "local_testing")]` and it will not be compiled anywhere but locally.

### Windows

Download the installer [here](https://www.rust-lang.org/tools/install)

If you are coding on windows, please use `stable-x86_64-pc-windows-gnu` when installing rust, `stable-x86_64-pc-windows-msvc` will lead to link problems.

If somehow you (unfortunately) installed `msvc`, do the following:

```sh
rustup toolchain uninstall stable-x86_64-pc-windows-msvc
rustup toolchain install stable-x86_64-pc-windows-gnu
rustup default stable-gnu
```

### Ubuntu

Get a install script from [here](https://www.rust-lang.org/tools/install)

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

The test will ship itself automatically when the compilation is done.