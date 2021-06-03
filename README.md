# plus_approximation

In their [paper](https://www.aumasson.jp/data/papers/AJN14a.pdf) about the cryptographic scheme NORX, the authors use a fast approximation of + by bitwise operations via a+b "=" a ^ b ^  ((a ^ b) << 1). This little piece of C code examines how well this approximation works in terms of the Hamming distance between a + b and  a ^ b ^ ((a & b) << 1).
