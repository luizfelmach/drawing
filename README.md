<p align="center">
  <a href="https://github.com/luizfelmach/drawing">
    <img alt="drawing" src="./assets/banner.png">
  </a>
</p>

### Table of Content

  - [About](#about)
  - [How to Run](#how-to-run)
  - [Author](#author)
  - [License](#license)

<a name="About"></a>

---
### About

This is a repository to **improve** my C++ skills and have fun **drawing** on the screen.

<a name="How-to-Run"></a>

---
### How to Run

To draw on the screen it is **necessary** to install [libxd](https://bernhardfritz.github.io/libxd/#/) on your operating system.

```bash
git clone --recursive https://github.com/bernhardfritz/libxd.git
cd libxd
mkdir build
cd build
cmake ..
sudo make
```

After that, **clone** this repository and **build** the files.

```bash
git clone https://github.com/luizfelmach/drawing.git
cd drawing
make
./build/linux/x86_64/release/particles # run the example particles
```

<a name="Author"></a>

---
### Author

Luiz Felipe Machado.

<a name="license"></a>

---
### License

[MIT License](./LICENSE)